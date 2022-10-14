#include "pch.h"
#include "bm_replay_manager.h"


BAKKESMOD_PLUGIN(bm_replay_manager, "Manage your replays with ease", plugin_version, PLUGINTYPE_FREEPLAY)

std::shared_ptr<CVarManagerWrapper> _globalCvarManager;

void bm_replay_manager::onLoad()
{
	_globalCvarManager = cvarManager;
	cvarManager->registerCvar(
		"replay_manager_debug_logging",
		"0",
		"Toggles debug logging within the replay manager plugin (useful for seeing errors when parsing replays)",
		true,
		true,
		0,
		true,
		1,
		true
	);

	replay_manager_ = std::make_shared<ReplayManager>();
}

void bm_replay_manager::onUnload()
{
}