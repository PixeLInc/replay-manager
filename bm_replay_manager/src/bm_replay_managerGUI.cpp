#include "pch.h"
#include "bm_replay_manager.h"

// The headers for the team table
const auto column_names = {
	"Player",
	"Score",
	"Goals",
	"Assists",
	"Saves",
	"Shots"
};

void RenderTeam(const TeamData& team)
{
	ImGui::Text("\n- %s -\n", team.name.c_str());
	ImGui::Columns(column_names.size(), team.name.c_str(), false);
	ImGui::SetColumnWidth(0, 150.0f);

	for (const auto& col_name : column_names)
	{
		ImGui::TextUnformatted(col_name);
		ImGui::NextColumn();
	}

	ImGui::Separator();

	for (const PlayerStats& stats : team.players)
	{
		ImGui::Text("%s", stats.name.c_str());
		ImGui::NextColumn();
		ImGui::Text("%d", stats.score);
		ImGui::NextColumn();
		ImGui::Text("%d", stats.goals);
		ImGui::NextColumn();
		ImGui::Text("%d", stats.assists);
		ImGui::NextColumn();
		ImGui::Text("%d", stats.saves);
		ImGui::NextColumn();
		ImGui::Text("%d", stats.shots);
		ImGui::NextColumn();
	}
	ImGui::Columns(1);
}

void RenderReplay(const Replay& replay)
{
	ImGui::BeginGroup();
	ImGui::Text("ID: %s", replay.id.c_str());
	ImGui::Text("Name: %s", replay.name.c_str());
	ImGui::Text("Date: %s", replay.date.c_str());
	ImGui::Text("Map: %s", replay.map_name.c_str());
	ImGui::Text("Match Type: %s", replay.match_type.c_str());
	ImGui::Text("Path: %s", replay.file_path.string().c_str());
	ImGui::Text("Record FPS: %.2f", replay.record_fps);
	ImGui::Text("Team Size: %d", replay.team_size);
	ImGui::EndGroup();

	ImGui::BeginGroup();

	RenderTeam(replay.teams[0]);
	ImGui::Spacing();
	RenderTeam(replay.teams[1]);

	ImGui::EndGroup();
}

void RenderTooltip(const char* desc)
{
    ImGui::TextDisabled("(?)");
    if (ImGui::IsItemHovered())
    {
        ImGui::BeginTooltip();
        ImGui::PushTextWrapPos(ImGui::GetFontSize() * 35.0f);
        ImGui::TextUnformatted(desc);
        ImGui::PopTextWrapPos();
        ImGui::EndTooltip();
    }
}

void bm_replay_manager::RenderReplayManager()
{
	ImGui::SetNextWindowSize(ImVec2(1000, 800), ImGuiCond_FirstUseEver);
	ImGui::Begin("ReplayManagerWindow", &window_open_);
	ImGui::Text("Replays loaded: %zd", replay_manager_->parsed_replays.size());
	ImGui::Text("Replays shown: %d", replays_count_);

	if (replay_manager_->parsed_replays.empty())
	{
		if (ImGui::Button("Load demo folder"))
			replay_manager_->LoadDefaultDemoFolder();

		ImGui::End();
		return;
	}

	// top bar items
	static ImGuiTextFilter filter;
	filter.Draw("Filter (inc,-exc)", ImGui::GetWindowContentRegionWidth() / 4);
	ImGui::SameLine();
	RenderTooltip("Filters out replays by their label. You can use a minus sign to exclude certain words.\nfor example: `-double` would show replays without double in the label.");

	ImGui::SameLine();

	ImGui::SetNextItemWidth(150.0f);
	if (ImGui::BeginCombo("Filter Type", filter_types_[selected_filter_idx_].c_str()))
	{
		for (int i = 0; i < filter_types_.size(); i++)
		{
			const auto& label = filter_types_.at(i);
			if (ImGui::Selectable(label.c_str(), i == selected_filter_idx_))
				selected_filter_idx_ = i;

			if (i == selected_filter_idx_)
				ImGui::SetItemDefaultFocus();
		}

		ImGui::EndCombo();
	}

	ImGui::SameLine();

	ImGui::SetNextItemWidth(150.0f);
	if (ImGui::BeginCombo("Sort Type", sort_types_[selected_sort_idx_].c_str()))
	{
		for (int i = 0; i < sort_types_.size(); i++)
		{
			const auto& label = sort_types_.at(i);
			if (ImGui::Selectable(label.c_str(), i == selected_sort_idx_)) {
				selected_sort_idx_ = i;

				// We sort the vec here as to not sort it every frame, because that's not good.
				switch (selected_sort_idx_)
				{
				case 0: {
					// Default sort, Date.
					std::scoped_lock lock(replay_manager_->replays_mutex_);
					std::ranges::sort(replay_manager_->parsed_replays, std::ranges::greater{}, &Replay::date);
					break;
				}
				case 1: {
					// Name sort
					std::scoped_lock lock(replay_manager_->replays_mutex_);
					std::ranges::sort(replay_manager_->parsed_replays, [](const Replay& left, const Replay& right)
					{
						// Push all empty names to the back of the vec
						if (right.name.empty())
							return true;

						if (left.name.empty())
							return false;

						return right.name > left.name;
					});
					break;
				}
				default:
					break;
				}
			}

			if (i == selected_sort_idx_)
				ImGui::SetItemDefaultFocus();
		}

		ImGui::EndCombo();
	}

	// /end


	constexpr ImGuiWindowFlags window_flags = ImGuiWindowFlags_HorizontalScrollbar;
	const ImVec2 window_size = ImGui::GetContentRegionAvail();
	ImGui::PushStyleVar(ImGuiStyleVar_ChildRounding, 5.0f);
	ImGui::BeginChild("ChildL", ImVec2(ImGui::GetWindowContentRegionWidth() / 4, window_size.y), true, window_flags);

	int count = 0;
	for (std::vector<Replay>::size_type i = 0; i < replay_manager_->parsed_replays.size(); i++)
	{
		const auto& replay = replay_manager_->parsed_replays.at(i);

		if (selected_filter_idx_ != 0)
		{
			// Team Size filters (1s, 2s, 3s)
			if (selected_filter_idx_ <= 3 && replay.team_size != selected_filter_idx_)
				continue;

			// More specific filters (private match, online match)
			if (selected_filter_idx_ > 3)
			{
				switch (selected_filter_idx_)
				{
				case 4: // private matches
					if (replay.match_type != "Private")
						continue;
					break;
				case 5: // online matches
					if (replay.match_type != "Online")
						continue;
					break;
				default:
					break;
				}
			}
		}

		if (!filter.PassFilter(replay.imgui_label.c_str()))
			continue;

		count++;
		if (ImGui::Selectable(replay.imgui_label.c_str(), selected_replay_ == i))
			selected_replay_ = i;
	}
	replays_count_ = count;

	ImGui::EndChild();
	ImGui::PopStyleVar();

	ImGui::SameLine();

	if (selected_replay_ != -1 && replay_manager_->parsed_replays.size() >= selected_replay_)
	{
		ImGui::PushStyleVar(ImGuiStyleVar_ChildRounding, 5.0f);
		ImGui::BeginChild("ChildR", ImVec2(0, window_size.y), true, window_flags);

		const auto& replay = replay_manager_->parsed_replays.at(selected_replay_);
		RenderReplay(replay);

		ImGui::EndChild();
		ImGui::PopStyleVar();
	}

	ImGui::End();
}

void bm_replay_manager::RenderSettings()
{
	if (window_open_)
		RenderReplayManager();

	if (ImGui::Button("Open Replay Manager")) {
		window_open_ = !window_open_;
	}
}

std::string bm_replay_manager::GetPluginName()
{
	return "Replay Manager";
}

void bm_replay_manager::SetImGuiContext(uintptr_t ctx)
{
	ImGui::SetCurrentContext(reinterpret_cast<ImGuiContext*>(ctx));
}