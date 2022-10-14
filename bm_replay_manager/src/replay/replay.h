#pragma once
#include <string>
#include <vector>
#include <filesystem>

enum ETeam : int
{
	Blue = 0,
	Orange = 1,
	End = 2
};

struct PlayerStats
{
	std::string name;
	ETeam team = End;
	unsigned int score = 0;
	unsigned int goals = 0;
	unsigned int assists = 0;
	unsigned int saves = 0;
	unsigned int shots = 0;
	bool is_bot = false;
};

struct TeamData
{
	std::string name;
	uint32_t goals = 0;
	std::vector<PlayerStats> players;
};

struct Replay
{
	std::string name;
	std::string id;
	std::string date;
	std::string map_name;
	std::string match_type;
	float record_fps = 30.0f;
	TeamData teams[2];
	int team_size = 0;
	std::filesystem::path file_path;
	bool parsed = false;

	std::string imgui_label;
};