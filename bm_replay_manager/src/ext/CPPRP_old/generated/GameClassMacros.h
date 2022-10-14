
#define xstr(a) DEFINESTR(a)
#define DEFINESTR(a) #a		

#ifndef GAMECLASS
#define GAMECLASS(...)
#endif

#ifndef GAMEFIELD
#define GAMEFIELD(...)
#endif

GAMECLASS(Engine, Actor);
GAMEFIELD(Engine, Actor, DrawScale, float);
GAMEFIELD(Engine, Actor, bCollideActors, bool);
GAMEFIELD(Engine, Actor, bCollideWorld, bool);
GAMEFIELD(Engine, Actor, bNetOwner, bool);
GAMEFIELD(Engine, Actor, Base, struct ActorBase);
GAMEFIELD(Engine, Actor, bBlockActors, bool);
GAMEFIELD(Engine, Actor, bHidden, bool);
GAMEFIELD(Engine, Actor, bTearOff, bool);
GAMEFIELD(Engine, Actor, Location, struct Vector3I);
GAMEFIELD(Engine, Actor, Rotation, struct Rotator);
GAMEFIELD(Engine, Actor, Physics, uint8_t);
GAMEFIELD(Engine, Actor, RemoteRole, uint8_t);
GAMEFIELD(Engine, Actor, Role, uint8_t);
GAMEFIELD(Engine, Actor, ReplicatedCollisionType, uint8_t);
GAMEFIELD(Engine, Actor, Owner, ActiveActor);
GAMEFIELD(Engine, Actor, bHardAttach, bool);
GAMEFIELD(Engine, Actor, Instigator, ActiveActor);
GAMEFIELD(Engine, Actor, RelativeLocation, Vector3I);
GAMEFIELD(Engine, Actor, RelativeRotation, Rotator);
GAMEFIELD(Engine, Actor, bRootMotionFromInterpCurve, bool);
GAMECLASS(Engine, ReplicatedActor_ORS);
GAMEFIELD(Engine, ReplicatedActor_ORS, ReplicatedOwner, ActiveActor);
GAMECLASS(Engine, Info);
GAMECLASS(Engine, ReplicationInfo);
GAMECLASS(Engine, GameReplicationInfo);
GAMEFIELD(Engine, GameReplicationInfo, ServerName, std::string);
GAMEFIELD(Engine, GameReplicationInfo, GameClass, struct ObjectTarget);
GAMEFIELD(Engine, GameReplicationInfo, bStopCountDown, bool);
GAMEFIELD(Engine, GameReplicationInfo, bMatchIsOver, bool);
GAMEFIELD(Engine, GameReplicationInfo, bMatchHasBegun, bool);
GAMEFIELD(Engine, GameReplicationInfo, RemainingTime, int);
GAMEFIELD(Engine, GameReplicationInfo, ElapsedTime, int);
GAMEFIELD(Engine, GameReplicationInfo, RemainingMinute, int);
GAMEFIELD(Engine, GameReplicationInfo, GoalScore, int);
GAMEFIELD(Engine, GameReplicationInfo, TimeLimit, int);
GAMEFIELD(Engine, GameReplicationInfo, winner, ActiveActor);
GAMECLASS(Engine, Pawn);
GAMEFIELD(Engine, Pawn, PlayerReplicationInfo, struct ActiveActor);
GAMEFIELD(Engine, Pawn, HealthMax, uint32_t);
GAMEFIELD(Engine, Pawn, bIsCrouched, bool);
GAMEFIELD(Engine, Pawn, bIsWalking, bool);
GAMEFIELD(Engine, Pawn, bSimulateGravity, bool);
GAMEFIELD(Engine, Pawn, bCanSwatTurn, bool);
GAMEFIELD(Engine, Pawn, bUsedByMatinee, bool);
GAMEFIELD(Engine, Pawn, bRootMotionFromInterpCurve, bool);
GAMEFIELD(Engine, Pawn, bFastAttachedMove, bool);
GAMEFIELD(Engine, Pawn, RemoteViewPitch, uint8_t);
GAMEFIELD(Engine, Pawn, GroundSpeed, float);
GAMEFIELD(Engine, Pawn, AirSpeed, float);
GAMEFIELD(Engine, Pawn, AccelRate, float);
GAMEFIELD(Engine, Pawn, JumpZ, float);
GAMEFIELD(Engine, Pawn, AirControl, float);
GAMEFIELD(Engine, Pawn, RootMotionInterpRate, float);
GAMEFIELD(Engine, Pawn, RootMotionInterpCurrentTime, float);
GAMEFIELD(Engine, Pawn, RootMotionInterpCurveLastValue, Vector3I);
GAMECLASS(Engine, PlayerReplicationInfo);
GAMEFIELD(Engine, PlayerReplicationInfo, Team, struct ActiveActor);
GAMEFIELD(Engine, PlayerReplicationInfo, bReadyToPlay, bool);
GAMEFIELD(Engine, PlayerReplicationInfo, PlayerName, std::string);
GAMEFIELD(Engine, PlayerReplicationInfo, RemoteUserData, std::string);
GAMEFIELD(Engine, PlayerReplicationInfo, bWaitingPlayer, bool);
GAMEFIELD(Engine, PlayerReplicationInfo, Score, uint32_t);
GAMEFIELD(Engine, PlayerReplicationInfo, PlayerID, uint32_t);
GAMEFIELD(Engine, PlayerReplicationInfo, bBot, bool);
GAMEFIELD(Engine, PlayerReplicationInfo, bIsSpectator, bool);
GAMEFIELD(Engine, PlayerReplicationInfo, bTimedOut, bool);
GAMEFIELD(Engine, PlayerReplicationInfo, bAdmin, bool);
GAMEFIELD(Engine, PlayerReplicationInfo, bIsInactive, bool);
GAMEFIELD(Engine, PlayerReplicationInfo, bOnlySpectator, bool);
GAMEFIELD(Engine, PlayerReplicationInfo, Ping, uint8_t);
GAMEFIELD(Engine, PlayerReplicationInfo, UniqueId, OnlineID);
GAMEFIELD(Engine, PlayerReplicationInfo, Deaths, uint32_t);
GAMEFIELD(Engine, PlayerReplicationInfo, TTSSpeaker, uint8_t);
GAMEFIELD(Engine, PlayerReplicationInfo, bOutOfLives, bool);
GAMEFIELD(Engine, PlayerReplicationInfo, bFromPreviousLevel, bool);
GAMECLASS(Engine, TeamInfo);
GAMEFIELD(Engine, TeamInfo, Score, uint32_t);
GAMECLASS(Engine, WorldInfo);
GAMEFIELD(Engine, WorldInfo, WorldGravityZ, float);
GAMEFIELD(Engine, WorldInfo, TimeDilation, float);
GAMEFIELD(Engine, WorldInfo, bHighPriorityLoading, bool);
GAMEFIELD(Engine, WorldInfo, Pauser, ActiveActor);
GAMECLASS(Engine, DynamicSMActor);
GAMEFIELD(Engine, DynamicSMActor, ReplicatedMesh, ObjectTarget);
GAMEFIELD(Engine, DynamicSMActor, ReplicatedMaterial0, ObjectTarget);
GAMEFIELD(Engine, DynamicSMActor, ReplicatedMaterial1, ObjectTarget);
GAMEFIELD(Engine, DynamicSMActor, ReplicatedMaterial2, ObjectTarget);
GAMEFIELD(Engine, DynamicSMActor, ReplicatedMaterial3, ObjectTarget);
GAMEFIELD(Engine, DynamicSMActor, bForceStaticDecals, bool);
GAMEFIELD(Engine, DynamicSMActor, ReplicatedMeshTranslation, Vector3);
GAMEFIELD(Engine, DynamicSMActor, ReplicatedMeshRotation, Rotator);
GAMEFIELD(Engine, DynamicSMActor, ReplicatedMeshScale3D, Vector3);
GAMECLASS(Engine, KActor);
GAMEFIELD(Engine, KActor, bWakeOnLevelStart, bool);
GAMEFIELD(Engine, KActor, RBState, RigidBodyState);
GAMEFIELD(Engine, KActor, ReplicatedDrawScale3D, Vector3);
GAMECLASS(ProjectX, GRI_X);
GAMEFIELD(ProjectX, GRI_X, MatchGUID, std::string);
GAMEFIELD(ProjectX, GRI_X, ReplicatedGameMutatorIndex, int);
GAMEFIELD(ProjectX, GRI_X, bGameStarted, bool);
GAMEFIELD(ProjectX, GRI_X, ReplicatedGamePlaylist, uint32_t);
GAMEFIELD(ProjectX, GRI_X, GameServerID, uint64_t);
GAMEFIELD(ProjectX, GRI_X, Reservations, struct Reservation);
GAMECLASS(ProjectX, NetModeReplicator_X);
GAMECLASS(ProjectX, Pawn_X);
GAMECLASS(ProjectX, PRI_X);
GAMECLASS(TAGame, PRI_TA);
GAMEFIELD(TAGame, PRI_TA, MatchShots, uint32_t);
GAMEFIELD(TAGame, PRI_TA, PersistentCamera, struct ActiveActor);
GAMEFIELD(TAGame, PRI_TA, SkillTier, struct SkillTier);
GAMEFIELD(TAGame, PRI_TA, bUsingBehindView, bool);
GAMEFIELD(TAGame, PRI_TA, MatchAssists, uint32_t);
GAMEFIELD(TAGame, PRI_TA, RespawnTimeRemaining, int);
GAMEFIELD(TAGame, PRI_TA, bOnlineLoadoutSet, bool);
GAMEFIELD(TAGame, PRI_TA, MatchGoals, uint32_t);
GAMEFIELD(TAGame, PRI_TA, ReplicatedGameEvent, struct ActiveActor);
GAMEFIELD(TAGame, PRI_TA, TotalXP, uint32_t);
GAMEFIELD(TAGame, PRI_TA, MatchScore, uint32_t);
GAMEFIELD(TAGame, PRI_TA, MatchSaves, uint32_t);
GAMEFIELD(TAGame, PRI_TA, Title, uint32_t);
GAMEFIELD(TAGame, PRI_TA, ClubID, uint64_t);
GAMEFIELD(TAGame, PRI_TA, MaxTimeTillItem, int);
GAMEFIELD(TAGame, PRI_TA, PickupTimer, ActiveActor);
GAMEFIELD(TAGame, PRI_TA, MatchBreakoutDamage, uint32_t);
GAMEFIELD(TAGame, PRI_TA, BotProductName, uint32_t);
GAMEFIELD(TAGame, PRI_TA, BotBannerProductID, uint32_t);
GAMEFIELD(TAGame, PRI_TA, bReady, bool);
GAMEFIELD(TAGame, PRI_TA, SpectatorShortcut, uint32_t);
GAMEFIELD(TAGame, PRI_TA, bUsingSecondaryCamera, bool);
GAMEFIELD(TAGame, PRI_TA, PlayerHistoryValid, bool);
GAMEFIELD(TAGame, PRI_TA, bIsInSplitScreen, bool);
GAMEFIELD(TAGame, PRI_TA, bMatchMVP, bool);
GAMEFIELD(TAGame, PRI_TA, RepStatTitles, struct RepStatTitle);
GAMEFIELD(TAGame, PRI_TA, bOnlineLoadoutsSet, bool);
GAMEFIELD(TAGame, PRI_TA, bUsingItems, bool);
GAMEFIELD(TAGame, PRI_TA, PrimaryTitle, struct ReplicatedTitle);
GAMEFIELD(TAGame, PRI_TA, bMatchAdmin, bool);
GAMEFIELD(TAGame, PRI_TA, bBusy, bool);
GAMEFIELD(TAGame, PRI_TA, bVoteToForfeitDisabled, bool);
GAMEFIELD(TAGame, PRI_TA, bUsingFreecam, bool);
GAMEFIELD(TAGame, PRI_TA, ClientLoadoutOnline, struct OnlineLoadout);
GAMEFIELD(TAGame, PRI_TA, CameraYaw, uint8_t);
GAMEFIELD(TAGame, PRI_TA, CameraPitch, uint8_t);
GAMEFIELD(TAGame, PRI_TA, PawnType, uint8_t);
GAMEFIELD(TAGame, PRI_TA, ReplicatedWorstNetQualityBeyondLatency, uint8_t);
GAMEFIELD(TAGame, PRI_TA, SteeringSensitivity, float);
GAMEFIELD(TAGame, PRI_TA, PartyLeader, struct PartyLeader);
GAMEFIELD(TAGame, PRI_TA, TimeTillItem, int);
GAMEFIELD(TAGame, PRI_TA, ClientLoadoutsOnline, struct ClientLoadoutsOnline);
GAMEFIELD(TAGame, PRI_TA, ClientLoadouts, struct ClientLoadouts);
GAMEFIELD(TAGame, PRI_TA, ClientLoadout, struct ClientLoadout);
GAMEFIELD(TAGame, PRI_TA, CameraSettings, struct CameraSettings);
GAMEFIELD(TAGame, PRI_TA, SecondaryTitle, struct ReplicatedTitle);
GAMEFIELD(TAGame, PRI_TA, PlayerHistoryKey, struct HistoryKey);
GAMEFIELD(TAGame, PRI_TA, bIsDistracted, bool);
GAMEFIELD(TAGame, PRI_TA, ReplacingBotPRI, ActiveActor);
GAMECLASS(TAGame, RBActor_TA);
GAMEFIELD(TAGame, RBActor_TA, ReplicatedRBState, struct ReplicatedRBState);
GAMEFIELD(TAGame, RBActor_TA, bReplayActor, bool);
GAMEFIELD(TAGame, RBActor_TA, bFrozen, bool);
GAMEFIELD(TAGame, RBActor_TA, WeldedInfo, struct WeldedInfo);
GAMEFIELD(TAGame, RBActor_TA, bIgnoreSyncing, bool);
GAMEFIELD(TAGame, RBActor_TA, MaxLinearSpeed, float);
GAMEFIELD(TAGame, RBActor_TA, MaxAngularSpeed, float);
GAMEFIELD(TAGame, RBActor_TA, TeleportCounter, uint8_t);
GAMECLASS(TAGame, CarComponent_TA);
GAMEFIELD(TAGame, CarComponent_TA, Vehicle, struct ActiveActor);
GAMEFIELD(TAGame, CarComponent_TA, ReplicatedActive, uint8_t);
GAMEFIELD(TAGame, CarComponent_TA, ReplicatedActivityTime, float);
GAMECLASS(TAGame, CarComponent_AirActivate_TA);
GAMEFIELD(TAGame, CarComponent_AirActivate_TA, AirActivateCount, int);
GAMECLASS(TAGame, CarComponent_Jump_TA);
GAMECLASS(TAGame, CarComponent_DoubleJump_TA);
GAMEFIELD(TAGame, CarComponent_DoubleJump_TA, DoubleJumpImpulse, struct Vector3I);
GAMECLASS(TAGame, CarComponent_Boost_TA);
GAMEFIELD(TAGame, CarComponent_Boost_TA, RechargeDelay, float);
GAMEFIELD(TAGame, CarComponent_Boost_TA, bUnlimitedBoost, bool);
GAMEFIELD(TAGame, CarComponent_Boost_TA, UnlimitedBoostRefCount, uint32_t);
GAMEFIELD(TAGame, CarComponent_Boost_TA, bNoBoost, bool);
GAMEFIELD(TAGame, CarComponent_Boost_TA, ReplicatedBoostAmount, uint8_t);
GAMEFIELD(TAGame, CarComponent_Boost_TA, RechargeRate, float);
GAMEFIELD(TAGame, CarComponent_Boost_TA, BoostModifier, float);
GAMEFIELD(TAGame, CarComponent_Boost_TA, StartBoostAmount, float);
GAMEFIELD(TAGame, CarComponent_Boost_TA, CurrentBoostAmount, float);
GAMEFIELD(TAGame, CarComponent_Boost_TA, bRechargeGroundOnly, bool);
GAMECLASS(TAGame, CarComponent_Dodge_TA);
GAMEFIELD(TAGame, CarComponent_Dodge_TA, DodgeTorque, struct Vector3I);
GAMEFIELD(TAGame, CarComponent_Dodge_TA, DodgeImpulse, struct Vector3I);
GAMECLASS(TAGame, CarComponent_FlipCar_TA);
GAMEFIELD(TAGame, CarComponent_FlipCar_TA, bFlipRight, bool);
GAMEFIELD(TAGame, CarComponent_FlipCar_TA, FlipCarTime, float);
GAMECLASS(TAGame, Ball_TA);
GAMEFIELD(TAGame, Ball_TA, GameEvent, struct ActiveActor);
GAMEFIELD(TAGame, Ball_TA, ReplicatedPhysMatOverride, struct ObjectTarget);
GAMEFIELD(TAGame, Ball_TA, ReplicatedBallGravityScale, float);
GAMEFIELD(TAGame, Ball_TA, ReplicatedBallScale, float);
GAMEFIELD(TAGame, Ball_TA, HitTeamNum, unsigned char);
GAMEFIELD(TAGame, Ball_TA, ReplicatedWorldBounceScale, float);
GAMEFIELD(TAGame, Ball_TA, ReplicatedAddedCarBounceScale, float);
GAMEFIELD(TAGame, Ball_TA, ReplicatedExplosionData, struct ReplicatedExplosionData);
GAMEFIELD(TAGame, Ball_TA, ReplicatedBallMaxLinearSpeedScale, float);
GAMEFIELD(TAGame, Ball_TA, ReplicatedExplosionDataExtended, struct ReplicatedExplosionDataExtended);
GAMEFIELD(TAGame, Ball_TA, MagnusCoefficient, Vector3I);
GAMEFIELD(TAGame, Ball_TA, bEndOfGameHidden, bool);
GAMECLASS(TAGame, Team_TA);
GAMEFIELD(TAGame, Team_TA, LogoData, struct LogoData);
GAMEFIELD(TAGame, Team_TA, GameEvent, struct ActiveActor);
GAMEFIELD(TAGame, Team_TA, CustomTeamName, std::string);
GAMEFIELD(TAGame, Team_TA, ClubID, uint64_t);
GAMEFIELD(TAGame, Team_TA, Difficulty, int32_t);
GAMEFIELD(TAGame, Team_TA, ClubColors, struct ClubColors);
GAMECLASS(TAGame, Team_Soccar_TA);
GAMEFIELD(TAGame, Team_Soccar_TA, GameScore, uint32_t);
GAMECLASS(TAGame, BreakOutActor_Platform_TA);
GAMEFIELD(TAGame, BreakOutActor_Platform_TA, DamageState, struct DamageState);
GAMECLASS(TAGame, SpecialPickup_TA);
GAMECLASS(TAGame, SpecialPickup_Targeted_TA);
GAMEFIELD(TAGame, SpecialPickup_Targeted_TA, Targeted, struct ActiveActor);
GAMECLASS(TAGame, SpecialPickup_Tornado_TA);
GAMECLASS(TAGame, SpecialPickup_HauntedBallBeam_TA);
GAMECLASS(TAGame, SpecialPickup_BallVelcro_TA);
GAMEFIELD(TAGame, SpecialPickup_BallVelcro_TA, bHit, bool);
GAMEFIELD(TAGame, SpecialPickup_BallVelcro_TA, bBroken, bool);
GAMEFIELD(TAGame, SpecialPickup_BallVelcro_TA, AttachTime, float);
GAMEFIELD(TAGame, SpecialPickup_BallVelcro_TA, BreakTime, float);
GAMECLASS(TAGame, SpecialPickup_Rugby_TA);
GAMEFIELD(TAGame, SpecialPickup_Rugby_TA, bBallWelded, bool);
GAMECLASS(TAGame, SpecialPickup_BallFreeze_TA);
GAMEFIELD(TAGame, SpecialPickup_BallFreeze_TA, RepOrigSpeed, float);
GAMECLASS(TAGame, SpecialPickup_Spring_TA);
GAMECLASS(TAGame, SpecialPickup_BallCarSpring_TA);
GAMECLASS(TAGame, SpecialPickup_BallGravity_TA);
GAMECLASS(TAGame, SpecialPickup_GrapplingHook_TA);
GAMECLASS(TAGame, SpecialPickup_BallLasso_TA);
GAMECLASS(TAGame, SpecialPickup_BoostOverride_TA);
GAMECLASS(TAGame, SpecialPickup_Batarang_TA);
GAMECLASS(TAGame, SpecialPickup_HitForce_TA);
GAMECLASS(TAGame, SpecialPickup_Swapper_TA);
GAMECLASS(TAGame, SpecialPickup_Football_TA);
GAMEFIELD(TAGame, SpecialPickup_Football_TA, WeldedBall, struct ActiveActor);
GAMECLASS(TAGame, CrowdManager_TA);
GAMEFIELD(TAGame, CrowdManager_TA, GameEvent, struct ActiveActor);
GAMEFIELD(TAGame, CrowdManager_TA, ReplicatedGlobalOneShotSound, struct ObjectTarget);
GAMECLASS(TAGame, CrowdActor_TA);
GAMEFIELD(TAGame, CrowdActor_TA, GameEvent, struct ActiveActor);
GAMEFIELD(TAGame, CrowdActor_TA, ReplicatedOneShotSound, struct ObjectTarget);
GAMEFIELD(TAGame, CrowdActor_TA, ReplicatedRoundCountDownNumber, uint32_t);
GAMEFIELD(TAGame, CrowdActor_TA, ReplicatedCountDownNumber, uint32_t);
GAMEFIELD(TAGame, CrowdActor_TA, ModifiedNoise, float);
GAMECLASS(TAGame, InMapScoreboard_TA);
GAMECLASS(TAGame, Vehicle_TA);
GAMEFIELD(TAGame, Vehicle_TA, ReplicatedThrottle, unsigned char);
GAMEFIELD(TAGame, Vehicle_TA, bReplicatedHandbrake, bool);
GAMEFIELD(TAGame, Vehicle_TA, bDriving, bool);
GAMEFIELD(TAGame, Vehicle_TA, ReplicatedSteer, unsigned char);
GAMEFIELD(TAGame, Vehicle_TA, bPodiumMode, bool);
GAMECLASS(TAGame, Car_TA);
GAMEFIELD(TAGame, Car_TA, AttachedPickup, struct ActiveActor);
GAMEFIELD(TAGame, Car_TA, RumblePickups, struct ActiveActor);
GAMEFIELD(TAGame, Car_TA, AddedCarForceMultiplier, float);
GAMEFIELD(TAGame, Car_TA, ReplicatedCarScale, float);
GAMEFIELD(TAGame, Car_TA, AddedBallForceMultiplier, float);
GAMEFIELD(TAGame, Car_TA, TeamPaint, struct TeamPaint);
GAMEFIELD(TAGame, Car_TA, ReplicatedDemolish, struct ReplicatedDemolish);
GAMEFIELD(TAGame, Car_TA, ReplicatedDemolish_CustomFX, struct ReplicatedDemolish2);
GAMEFIELD(TAGame, Car_TA, ReplicatedDemolishGoalExplosion, struct DemolishDataGoalExplosion);
GAMEFIELD(TAGame, Car_TA, ClubColors, struct ClubColors);
GAMECLASS(TAGame, Car_Season_TA);
GAMECLASS(TAGame, CameraSettingsActor_TA);
GAMEFIELD(TAGame, CameraSettingsActor_TA, PRI, struct ActiveActor);
GAMEFIELD(TAGame, CameraSettingsActor_TA, bMouseCameraToggleEnabled, bool);
GAMEFIELD(TAGame, CameraSettingsActor_TA, bUsingSecondaryCamera, bool);
GAMEFIELD(TAGame, CameraSettingsActor_TA, bUsingBehindView, bool);
GAMEFIELD(TAGame, CameraSettingsActor_TA, ProfileSettings, struct CameraSettings);
GAMEFIELD(TAGame, CameraSettingsActor_TA, bUsingSwivel, bool);
GAMEFIELD(TAGame, CameraSettingsActor_TA, bUsingFreecam, bool);
GAMEFIELD(TAGame, CameraSettingsActor_TA, bHoldMouseCamera, bool);
GAMEFIELD(TAGame, CameraSettingsActor_TA, bResetCamera, bool);
GAMEFIELD(TAGame, CameraSettingsActor_TA, CameraPitch, uint8_t);
GAMEFIELD(TAGame, CameraSettingsActor_TA, CameraYaw, uint8_t);
GAMECLASS(TAGame, GRI_TA);
GAMEFIELD(TAGame, GRI_TA, NewDedicatedServerIP, std::string);
GAMECLASS(TAGame, Ball_Breakout_TA);
GAMEFIELD(TAGame, Ball_Breakout_TA, DamageIndex, uint32_t);
GAMEFIELD(TAGame, Ball_Breakout_TA, AppliedDamage, struct AppliedDamage);
GAMEFIELD(TAGame, Ball_Breakout_TA, LastTeamTouch, unsigned char);
GAMECLASS(TAGame, Ball_God_TA);
GAMEFIELD(TAGame, Ball_God_TA, TargetSpeed, float);
GAMECLASS(TAGame, VehiclePickup_TA);
GAMEFIELD(TAGame, VehiclePickup_TA, bNoPickup, bool);
GAMEFIELD(TAGame, VehiclePickup_TA, ReplicatedPickupData, struct ReplicatedPickupData);
GAMEFIELD(TAGame, VehiclePickup_TA, NewReplicatedPickupData, struct ReplicatedPickupData2);
GAMECLASS(TAGame, VehiclePickup_Boost_TA);
GAMECLASS(TAGame, Ball_Haunted_TA);
GAMEFIELD(TAGame, Ball_Haunted_TA, DeactivatedGoalIndex, unsigned char);
GAMEFIELD(TAGame, Ball_Haunted_TA, bIsBallBeamed, bool);
GAMEFIELD(TAGame, Ball_Haunted_TA, ReplicatedBeamBrokenValue, unsigned char);
GAMEFIELD(TAGame, Ball_Haunted_TA, LastTeamTouch, unsigned char);
GAMEFIELD(TAGame, Ball_Haunted_TA, TotalActiveBeams, unsigned char);
GAMECLASS(TAGame, GameEvent_TA);
GAMEFIELD(TAGame, GameEvent_TA, ReplicatedRoundCountDownNumber, uint32_t);
GAMEFIELD(TAGame, GameEvent_TA, ActivatorCar, struct ActiveActor);
GAMEFIELD(TAGame, GameEvent_TA, ReplicatedGameStateTimeRemaining, uint32_t);
GAMEFIELD(TAGame, GameEvent_TA, ReplicatedStateName, uint32_t);
GAMEFIELD(TAGame, GameEvent_TA, MatchTypeClass, struct ObjectTarget);
GAMEFIELD(TAGame, GameEvent_TA, BotSkill, float);
GAMEFIELD(TAGame, GameEvent_TA, bHasLeaveMatchPenalty, bool);
GAMEFIELD(TAGame, GameEvent_TA, bCanVoteToForfeit, bool);
GAMEFIELD(TAGame, GameEvent_TA, bAllowReadyUp, bool);
GAMEFIELD(TAGame, GameEvent_TA, GameMode, struct GameMode);
GAMEFIELD(TAGame, GameEvent_TA, ReplicatedStateIndex, struct ReplicatedStateIndex);
GAMEFIELD(TAGame, GameEvent_TA, GameOwner, struct ActiveActor);
GAMEFIELD(TAGame, GameEvent_TA, bIsBotMatch, bool);
GAMECLASS(TAGame, GameEvent_Team_TA);
GAMEFIELD(TAGame, GameEvent_Team_TA, MaxTeamSize, uint32_t);
GAMEFIELD(TAGame, GameEvent_Team_TA, bForfeit, bool);
GAMEFIELD(TAGame, GameEvent_Team_TA, bDisableMutingOtherTeam, bool);
GAMECLASS(TAGame, GameEvent_Soccar_TA);
GAMEFIELD(TAGame, GameEvent_Soccar_TA, bOverTime, bool);
GAMEFIELD(TAGame, GameEvent_Soccar_TA, GameTime, uint32_t);
GAMEFIELD(TAGame, GameEvent_Soccar_TA, MVP, struct ActiveActor);
GAMEFIELD(TAGame, GameEvent_Soccar_TA, MatchWinner, struct ActiveActor);
GAMEFIELD(TAGame, GameEvent_Soccar_TA, GameWinner, struct ActiveActor);
GAMEFIELD(TAGame, GameEvent_Soccar_TA, SubRulesArchetype, struct ObjectTarget);
GAMEFIELD(TAGame, GameEvent_Soccar_TA, SecondsRemaining, uint32_t);
GAMEFIELD(TAGame, GameEvent_Soccar_TA, RoundNum, uint32_t);
GAMEFIELD(TAGame, GameEvent_Soccar_TA, SeriesLength, uint32_t);
GAMEFIELD(TAGame, GameEvent_Soccar_TA, ReplicatedMusicStinger, struct ReplicatedMusicStringer);
GAMEFIELD(TAGame, GameEvent_Soccar_TA, bBallHasBeenHit, bool);
GAMEFIELD(TAGame, GameEvent_Soccar_TA, bUnlimitedTime, bool);
GAMEFIELD(TAGame, GameEvent_Soccar_TA, ReplicatedStatEvent, struct ReplicatedStatEvent);
GAMEFIELD(TAGame, GameEvent_Soccar_TA, bShowIntroScene, bool);
GAMEFIELD(TAGame, GameEvent_Soccar_TA, bClubMatch, bool);
GAMEFIELD(TAGame, GameEvent_Soccar_TA, ReplicatedScoredOnTeam, unsigned char);
GAMEFIELD(TAGame, GameEvent_Soccar_TA, bMatchEnded, bool);
GAMEFIELD(TAGame, GameEvent_Soccar_TA, ReplicatedServerPerformanceState, unsigned char);
GAMEFIELD(TAGame, GameEvent_Soccar_TA, MaxScore, uint32_t);
GAMECLASS(TAGame, GameEvent_Breakout_TA);
GAMECLASS(TAGame, GameEvent_Football_TA);
GAMECLASS(TAGame, GameEvent_GodBall_TA);
GAMECLASS(TAGame, GameEvent_Season_TA);
GAMECLASS(TAGame, GameEvent_SoccarPrivate_TA);
GAMEFIELD(TAGame, GameEvent_SoccarPrivate_TA, MatchSettings, struct PrivateMatchSettings);
GAMECLASS(TAGame, GameEvent_SoccarSplitscreen_TA);
GAMECLASS(TAGame, GameEvent_Tutorial_TA);
GAMECLASS(TAGame, GameEvent_Tutorial_Goalie_TA);
GAMECLASS(TAGame, GameEvent_Tutorial_Striker_TA);
GAMECLASS(TAGame, GameEvent_GameEditor_TA);
GAMECLASS(TAGame, GameEditor_Pawn_TA);
GAMECLASS(TAGame, GameEvent_TrainingEditor_TA);
GAMECLASS(TAGame, HauntedBallTrapTrigger_TA);
GAMECLASS(TAGame, MaxTimeWarningData_TA);
GAMEFIELD(TAGame, MaxTimeWarningData_TA, EndGameEpochTime, uint64_t);
GAMEFIELD(TAGame, MaxTimeWarningData_TA, EndGameWarningEpochTime, uint64_t);
GAMECLASS(TAGame, RumblePickups_TA);
GAMEFIELD(TAGame, RumblePickups_TA, AttachedPickup, ActiveActor);
GAMEFIELD(TAGame, RumblePickups_TA, ConcurrentItemCount, int);
GAMEFIELD(TAGame, RumblePickups_TA, PickupInfo, PickupInfo_TA);
GAMECLASS(TAGame, PickupTimer_TA);
GAMEFIELD(TAGame, PickupTimer_TA, TimeTillItem, int);
GAMEFIELD(TAGame, PickupTimer_TA, MaxTimeTillItem, int);
GAMECLASS(TAGame, Cannon_TA);
GAMEFIELD(TAGame, Cannon_TA, Pitch, float);
GAMEFIELD(TAGame, Cannon_TA, FireCount, uint8_t);
