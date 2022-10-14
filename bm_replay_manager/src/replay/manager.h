#pragma once
#include <map>
#include "replay.h"
#include "thread_pool.hpp"

// Manages the parsing, loading and storing of replay files.
// Huge thanks to Martinn for the base and help.
class ReplayManager {
public:
	std::vector<Replay> parsed_replays{};
	std::mutex replays_mutex_;

	// Loads and parses a replay file from disk.
	// If parse_fully is false, only deserializes the header and fetches basic data.
	[[nodiscard]] Replay ParseReplay(std::filesystem::path replay_path, bool parse_fully = false) const;

	// Creates an async task which calls `ParseReplay` and pushes it into the thread pool to be executed.
	void LoadAndParseReplayAsync(const std::filesystem::path& replay_path);

	// Adds the parsed replay file to the `parsed_replays` vector and re-sorts the vector by date.
	void AddParsedReplay(Replay replay);

	// Reads every replay file in the passed `replay_folder` and queues them to be parsed.
	void LoadFolder(const std::filesystem::path& replay_folder);

	// Gets the default Demos folder and calls `LoadFolder`
	void LoadDefaultDemoFolder();
private:
	thread_pool replay_parsing_thread_pool_;

	static std::filesystem::path ConvertRelativeDemoPathToAbsolute(const std::filesystem::path& path);
	static std::filesystem::path GetMyDocumentsPath();

	// Returns a prettified map name converted from rl's internal map string
	// This will return the original string if it could not be converted.
	[[nodiscard]] std::string GetDisplayMapName(const std::string& str) const {
		const auto iter = MAPS.find(str);
		if (iter == MAPS.end())
			return str;

		return iter->second;
	}

	// A map of internal -> display map names
	const std::map<std::string, std::string> MAPS{
		{"ARC_Darc_P", "Starbase ARC (Aftermath)"},
		{"ARC_P", "ARCtagon"},
		{"arc_standard_p", "Starbase ARC"},
		{"beach_night_p", "Salty Shores (Night)"},
		{"beach_P", "Salty Shores"},
		{"CHN_Stadium_Day_P", "Forbidden Temple (Day)"},
		{"CHN_Stadium_P", "Forbidden Temple"},
		{"cs_day_p", "Champions Field (Day)"},
		{"cs_hw_p", "Rivals Arena"},
		{"cs_p", "Champions Field"},
		{"EuroStadium_Night_P", "Mannfield (Night)"},
		{"EuroStadium_P", "Mannfield"},
		{"EuroStadium_Rainy_P", "Mannfield (Stormy)"},
		{"eurostadium_snownight_p", "Mannfield (Snowy)"},
		{"Farm_Night_P", "Farmstead (Night)"},
		{"farm_p", "Farmstead"},
		{"Labs_CirclePillars_P", "Pillars"},
		{"Labs_Cosmic_V4_P", "Cosmic"},
		{"Labs_DoubleGoal_V2_P", "Double Goal"},
		{"Labs_Octagon_02_P", "Octagon"},
		{"Labs_Underpass_P", "Underpass"},
		{"Labs_Utopia_P", "Utopia Retro"},
		{"music_p", "Neon Fields"},
		{"NeoTokyo_P", "Tokyo Underpass"},
		{"NeoTokyo_Standard_P", "Neo Tokyo"},
		{"NeoTokyo_Toon_p", "Neo Tokyo (Comic)"},
		{"outlaw_p", "Deadeye Canyon"},
		{"Park_Night_P", "Beckwith Park (Midnight)"},
		{"Park_P", "Beckwith Park"},
		{"Park_Rainy_P", "Beckwith Park (Stormy)"},
		{"Park_Snowy_P", "Beckwith Park (Snowy)"},
		{"stadium_day_p", "DFH Stadium (Day)"},
		{"Stadium_Foggy_P", "DFH Stadium (Stormy)"},
		{"Stadium_P", "DFH Stadium"},
		{"Stadium_Race_Day_p", "DFH Stadium (Circuit)"},
		{"Stadium_Winter_P", "DFH Stadium (Snowy)"},
		{"throwbackstadium_P", "Throwback Stadium"},
		{"TrainStation_Dawn_P", "Urban Central (Dawn)"},
		{"TrainStation_Night_P", "Urban Central (Night)"},
		{"TrainStation_P", "Urban Central"},
		{"Underwater_P", "AquaDome"},
		{"UtopiaStadium_Dusk_P", "Utopia Coliseum (Dusk)"},
		{"UtopiaStadium_Lux_P", "Utopia Coliseum (Gilded)"},
		{"UtopiaStadium_P", "Utopia Coliseum"},
		{"UtopiaStadium_Snow_P", "Utopia Coliseum (Snowy)"},
		{"Wasteland_Night_P", "Badlands (Night)"},
		{"wasteland_Night_S_P", "Wasteland (Night)"},
		{"Wasteland_P", "Badlands"},
		{"wasteland_s_p", "Wasteland"},
	};
};
