#include "pch.h"
#include "manager.h"

#include <ranges>
#include <ShlObj.h>
#pragma comment(lib, "shell32.lib")

Replay ReplayManager::ParseReplay(std::filesystem::path replay_path, bool parse_fully) const
{
	auto replay_file = CPPRP::ReplayFile(replay_path);
	if (!replay_file.Load())
	{
		DEBUG_LOG("Failed to load replay file: {}", replay_path);
		return Replay{.parsed = false};
	}

	if (!replay_file.VerifyCRC(CPPRP::CRC_Both))
	{
		DEBUG_LOG("Failed to verify CRC for: {}", replay_path);
		return Replay{.parsed = false};
	}

	Replay replay{};
	replay_file.DeserializeHeader();

	if (!replay_file.objectToId.contains("TAGame.PRI_TA"))
	{
		DEBUG_LOG("Failed to find PRI_TA object in: {}", replay_path);
		return replay;
	}

	const int32_t pri_id = replay_file.objectToId["TAGame.PRI_TA"];
	std::map<uint32_t, CPPRP::TAGame::PRI_TA> pris_last_update;
	if (parse_fully) {
		replay_file.updatedCallbacks.emplace_back([&](const CPPRP::ActorStateData& actor_state_data, ...)
		{
			if (const uint32_t class_id = actor_state_data.classNameId; pri_id == class_id)
			{
				const auto pri = std::dynamic_pointer_cast<CPPRP::TAGame::PRI_TA>(actor_state_data.actorObject);
				pris_last_update[actor_state_data.actorId] = *pri;
			}
		});

		replay_file.Parse();
	}

	auto try_get_prop = [&]<typename T>(const std::string& prop_name, T& val)
	{
		if (replay_file.HasProperty(prop_name))
			val = replay_file.GetProperty<T>(prop_name);
	};

	replay.file_path = replay_path;
	replay.teams[0].name = "Blue";
	replay.teams[1].name = "Orange";

	try_get_prop("ReplayName", replay.name);
	try_get_prop("Date", replay.date);
	try_get_prop("MatchType", replay.match_type);
	try_get_prop("Id", replay.id);
	try_get_prop("MapName", replay.map_name);
	try_get_prop("RecordFPS", replay.record_fps);
	try_get_prop("TeamSize", replay.team_size);

	replay.map_name = GetDisplayMapName(replay.map_name);

	std::string replay_name = replay.name;
	if (replay_name.empty())
		replay_name = replay.map_name;

	replay.imgui_label = fmt::format("{} ({})####{}", replay_name, replay.match_type, replay.id);

	for (auto& pri : pris_last_update | std::views::values)
	{
		if (!pri.Team.active)
			continue;

		const auto& team_object = replay_file.actorStates[pri.Team.actor_id];
		const auto team_ta = std::dynamic_pointer_cast<CPPRP::TAGame::Team_TA>(team_object.actorObject);
		if (!team_ta)
			continue;

		const auto& team_archetype = replay_file.replayFile->objects[team_object.typeId];
		ETeam team = team_archetype.ends_with("1") ? Orange : Blue;
		auto& player_team = replay.teams[team];

		player_team.name = team_ta->CustomTeamName.empty()
			                   ? team == Orange
				                     ? "Orange"
				                     : "Blue"
			                   : team_ta->CustomTeamName;
		player_team.goals = team_ta->Score;

		player_team.players.emplace_back(PlayerStats{
			.name = pri.PlayerName,
			.team = team,
			.score = pri.MatchScore,
			.goals = pri.MatchGoals,
			.assists = pri.MatchAssists,
			.saves = pri.MatchSaves,
			.shots = pri.MatchShots,
			.is_bot = pri.bBot
		});
	}

	std::ranges::sort(replay.teams[0].players, std::ranges::greater{}, &PlayerStats::score);
	std::ranges::sort(replay.teams[1].players, std::ranges::greater{}, &PlayerStats::score);
	replay.parsed = true;

	return replay;
}

void ReplayManager::LoadAndParseReplayAsync(const std::filesystem::path& replay_path)
{
	auto async_load_func = [this, replay_path]
	{
		if (const auto replay = ParseReplay(replay_path, true); replay.parsed)
			AddParsedReplay(replay);
	};

	replay_parsing_thread_pool_.submit(async_load_func);
}

void ReplayManager::AddParsedReplay(Replay replay)
{
	std::scoped_lock lock(replays_mutex_);
	parsed_replays.emplace_back(std::move(replay));
	std::ranges::sort(parsed_replays, std::ranges::greater{}, &Replay::date);
}

std::filesystem::path ReplayManager::ConvertRelativeDemoPathToAbsolute(const std::filesystem::path& path)
{
	const auto replay_folder_path = GetMyDocumentsPath() / "My Games" / "Rocket League" / "TAGame" / "Demos";
	return absolute(replay_folder_path / path);
}

std::filesystem::path ReplayManager::GetMyDocumentsPath()
{
	TCHAR my_documents[MAX_PATH];
	const HRESULT result = SHGetFolderPath(nullptr, CSIDL_PERSONAL, nullptr, SHGFP_TYPE_CURRENT, my_documents);

	if (result != S_OK)
	{
		LOG("Error: Failed to make the relative replay path into a absolute one");
		throw std::runtime_error("Failed to get the local user documents folder");
	}

	return my_documents;
}

void ReplayManager::LoadDefaultDemoFolder()
{
	const auto default_demo_folder = GetMyDocumentsPath() / "My Games" / "Rocket League" / "TAGame" / "Demos";
	LoadFolder(default_demo_folder);
}

void ReplayManager::LoadFolder(const std::filesystem::path& replay_folder)
{
	if (!exists(replay_folder))
	{
		LOG("Failed to find replay folder: {}", replay_folder);
		return;
	}

	int new_count = 0;
	for (const auto& directory_entry : std::filesystem::directory_iterator(replay_folder))
	{
		if (!directory_entry.is_regular_file())
			continue;

		if (auto& path = directory_entry.path(); path.extension().string() == ".replay")
		{
			new_count++;
			LoadAndParseReplayAsync(path);
		}
	}

	{
		std::scoped_lock lock(replays_mutex_);
		parsed_replays.reserve(parsed_replays.size() + new_count);
	}
}