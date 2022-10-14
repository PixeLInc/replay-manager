#pragma once

#include "bakkesmod/plugin/bakkesmodplugin.h"
#include "bakkesmod/plugin/PluginSettingsWindow.h"
#

#include "version.h"

constexpr auto plugin_version = stringify(VERSION_MAJOR) "." stringify(VERSION_MINOR) "." stringify(VERSION_PATCH) "." stringify(VERSION_BUILD);

class bm_replay_manager : public BakkesMod::Plugin::BakkesModPlugin, public BakkesMod::Plugin::PluginSettingsWindow
{
private:
	void onLoad() override;
	void onUnload() override;

	std::shared_ptr<ReplayManager> replay_manager_;

	// imgui stuff

	bool window_open_ = false;
	std::vector<Replay>::size_type selected_replay_ = -1;

	const std::vector<std::string> filter_types_ = {
		"All",
		"1s",
		"2s",
		"3s",
		"Private Match",
		"Online Match"
	};
	int selected_filter_idx_ = 0;

	const std::vector<std::string> sort_types_ = {
		"Replay Date",
		"Replay Name",
	};
	int selected_sort_idx_ = 0;

	// How many replays are being shown in the list
	int replays_count_ = 0;


	void RenderSettings() override;
	void SetImGuiContext(uintptr_t ctx) override;
	std::string GetPluginName() override;

	// Renders the main window for the replay manager
	void RenderReplayManager();
};

