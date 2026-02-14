#pragma once
#include <game.h>
#include "dStartInfo_c.h"

/* dInfo_c

 - Vtable:			0x80315EA0
 - Constructor:		0x800BB0E0
 - Destructor:		0x800BB130
 - Static Init:		0x800BBCE0
 - Class Instance:	0x8042A25C
*/

enum WmPlayerMovementType_e {
	STANDING = 0,	// Player is already standing on the destination mode
	WALKING,		// Player walks/runs to the destination node
	AIRSHIP,		// Player rides on an airship and jumps out to the destination node (unused)
	CANNON			// Player falls from the sky onto the destination node
};

// This controls the clear status frames on the Multi Course Select buttons
enum MultiModeClearType_e {
	NONE = 0,		// No border is shown
	NOW_CLEAR,		// Cleared by some (but not all) players (Free Mode), will play anim and show grey border
	CLEARED,		// Already cleared, grey border is already present
	NOW_TEAM_CLEAR,	// Cleared by all players (or cleared in Coin Battle), will play anim and show gold border
	TEAM_CLEARED	// Already team cleared, gold border is already present
};

enum FukidashiObjectType_e {
	PROPELLER_SUIT = 1,
	PROPELLER_BLOCK = 3,
	GLOW_BLOCK,
	POW_BLOCK,
	BARREL,
	GRAB_ICE_BLOCK,
	RESCUE_TOAD,
	ENEMY_ICE_BLOCK = 17,
	SPRING_BOARD,
};

enum GameFlag_e {
	DISABLE_ACTOR_SPAWNING		 = 0x1,
	IS_STOPPED					 = 0x2,		   // Enables player state change freeze
	REPLAY_LOADED				 = 0x4,		   // Toggled if a Super Guide replay file exists for the current stage
	DISABLE_SWITCH_BGM			 = 0x8,
	MULTI_MODE					 = 0x10,	   // The game is in a multiplayer mode, the next two bits specify the mode
	FREE_MODE					 = 0x20,
	COIN_BATTLE					 = 0x40,
	SKIP_BOOT_SCREENS			 = 0x80000,    // Automatically skips WiiStrap and ControllerInformation screens
	SKIP_TRANSITIONS			 = 0x4000000,  // Sets all transitions to "FADE", and duration to 1 frame
	SKIP_PREGAME_BATTERY		 = 0x40000000, // Skips the battery warning on the PreGame screen
	SHOW_GAME_DISPLAY_COLLECTION = 0x80000000, // Forces Star Coins to be shown on the HUD, also skips PreGame battery warning
};

enum StartKinokoType_e {
	KIND_NONE = 0,
	KIND_STAR,
	KIND_RED,
	KIND_GREEN,
	KIND_STAR_SINGLE_PLAYER,
	KIND_RED_SINGLE_PLAYER,
	KIND_GREEN_SINGLE_PLAYER,
};

// Timer digits required to get a certain type of Start Node Toad House
enum ZoromeTimeType_e {
	TYPE_SINGLE_PLAYER_1UP = 0,
	TYPE_1UP = 1,
	// Value 2 is also 1-Up
	TYPE_RED = 3,
	// Values 4 - 8 are also Red
	TYPE_STAR = 9,
};

// These are mainly changed by the Character Select screen
// dGameCom::PlayerEnterCheck() checks if a player state is == 3
enum PlayerEnterState_e {
	STATE_INACTIVE = 0,	// Player is not in-game
	STATE_SETUP,		// Player has a connected controller, but is not fully joined (Remocon is being setup)
	STATE_ACTIVE = 3,	// Player is actively in-game
};

// Size: 0xB5C
class dInfo_c {
public:
	u32  _04;			// 0x04 -- Seems to be unused
	dCyuukan_c cyuukan; // 0x08 -- Checkpoint data manager. Formerly known as "GMgr8"

	// World Map data
	int wmCurrentWorld;		// 0x3C
	int wmCurrentSubmap;	// 0x40
	int wmCurrentPathNode;	// 0x44 -- Current node of any type, used to position the player when returning to the World Map
	int wmCurrentLevelNode;	// 0x48 -- Current level node, doesn't update for other types
	u32 _4C;				// 0x4C -- Seems to be unused, set to 0 in CourseSelectInit()
	int currentWorldNum;	// 0x50 -- This and `currentLevelNum` are only set when entering a level from the World Map
	int currentLevelNum;	// 0x54
	int lastAmbushStage;	// 0x58 -- Lase cleared ambush level number, used to avoid randomly selecting the same ambush again
	int startKinokoKind;	// 0x5C -- Starting Toad House type. See `StartKinokoKind_e` enum
	int lastLevelClearType; // 0x60 -- Related to course completion

	int  zoromeTime;		// 0x64 -- "Double numbers" value (timer digits), determines the Start Node Toad House type. See `ZoromeTimeType_e` enum
	int  fireworksActive;	// 0x68 -- Set to 1 if fireworks will be played during the Course Clear sequence
	bool rescueToadExists;	// 0x6C -- Set to true if a Rescue Toad has been released from a block
	bool isSuperGuide;		// 0x6D -- Set to true during course completion if the game mode is Super Guide
	u8   pad[2];			// 0x6E

	// More World Map data
	int currentAmbushStage[10]; // 0x70 -- Level number of the active ambush enemy for each world
	u8  _98;					// 0x98 -- Seems to be unused, set to 0 in CourseSelectInit()
	u8  pad2[3];				// 0x99
	int lastAmbushEnemy;		// 0x9C -- Index of the most recent ambush enemy that was fought

	struct enemy_s {
		int submapID; // 0x00
		int pathNode; // 0x04
		int reverse;  // 0x08
		u8  _0C;	  // 0x0C
		u8  pad[3];	  // 0x0D
	};
	enemy_s ambushData[10][4]; // 0xA0  -- Formerly known as "GMgrA0"
	int wmIbaraNow[10];		   // 0x320
	int wmIbaraOld[10];		   // 0x348
	int wmPlayerMovementType;  // 0x370 -- See `WmPlayerMovementType_e` enum
	int _374;				   // 0x374 -- Seems to be unused, set to 0 in CourseSelectInit()
	int treasureShipSubmap;	   // 0x378 -- Submap that WM_TREASURESHIP is located in
	int treasureShipPathNode;  // 0x37C -- Path node that WM_TREASURESHIP is located at

	bool redSwitchActive; // 0x380 -- Toggles whether or not the W3 switch is active. Newer refers to this as `switchPalaceFlag`
	u8   pad3[3];		  // 0x381
	int  playerState[4];  // 0x384 -- Current player entry state (see `PlayerEnterState_e` enum). Index 0 is always inited as 3, others inited as 0

	// If false: World Map/MovieDemo actors will draw/execute, as well as effects
	// If true:  SpecialDraw models (stuff like StockItem models and 2D players) will be drawn instead, and the main World Map actors will not be drawn/executed
	bool renderMode;			// 0x394 -- Controls drawing for World Map/MovieDemo models, as well as effects
	u8 currentRescueStage[10];  // 0x395
	u8 previousRescueStage[10]; // 0x39F -- Previous Toad Rescue level, used to avoid randomly selecting the same level
	u8 toadRescueCountdown[10]; // 0x3A9 -- Countdown until another Toad Rescue can be created
	bool clearCyuukanOnEntry;	// 0x3B3 -- If true, cyuukan data will be cleared when entering a level. Used for the back entrance to 7-Castle

	// BMG escape sequence data
	int layoutWorldNum;				// 0x3B4 -- Current world number + 1, used by sequences that print current world
	int layoutLevelNum;				// 0x3B8 -- Current level number + 1, used by sequences that print current level
	int totalStarCoinCount; 		// 0x3BC
	int currentSaveFile;			// 0x3C0
	int _3C4;						// 0x3C4 -- Printed by (unused) sequence 0xB, unknown what this 
	int scissorInfoIdx;				// 0x3C8 -- Determines which TagProcessor_c scissor info struct is used for sequence 0x9
	int playerCount;				// 0x3CC
	int msgCategory;				// 0x3D0 -- Used for debug sequence 0xD
	int msgID;						// 0x3D4 -- Used for debug sequence 0xD
	u8  _3D8;						// 0x3D8 -- Unused
	u8  currentControllerType;		// 0x3D9 -- P1's controller type, 0 is a sideways Wii Remote, 1 is a Nunchuk
	bool layoutShadowFlag;			// 0x3DA -- Enabled for TextBox panes that have a "shadow" userdata entry. If true, any icons printed through the BMG will be black and transparent
	u8  pad4;						// 0x3DB
	nw4r::lyt::Pane *N_scissor_00;  // 0x3DC -- Used for sequence 0x9, defines clipping bounds for the text
	nw4r::lyt::DrawInfo *drawInfo;	// 0x3E0 -- Used for sequence 0x9, DrawInfo data of the layout containing the TextBox being clipped

	// Multi Mode info
	int multiModeCurrentPage;	 // 0x3E4 -- Selected page in the multiplayer course select, used when returning from a level. `0` is the Recommended page, and `10` is the Favorites
	int multiModeCurrentButton;  // 0x3E8 -- Selected button in the multiplayer course select, used when returning from a level
	int coinBattleWinCounts[4];  // 0x3EC -- Number of times each player got 1st place in Coin Battle
	int _3FC;					 // 0x3FC -- Unused

	struct MultiModeCourseData {
		u8 worldNum;	// 0x00
		u8 levelNum;	// 0x01
		u8 pad[2];		// 0x02
		int clearType;  // 0x04 -- See `MultiModeClearType_e` enum
	};
	MultiModeCourseData coinBattleCourses[100];	 // 0x400
	MultiModeCourseData coinBattleFavorites[10]; // 0x720
	MultiModeCourseData freeModeCourses[100];	 // 0x770
	MultiModeCourseData freeModeFavorites[10];	 // 0xA90
	bool availableMultiWorlds[11];				 // 0xAE0 -- Available world pages for the multiplayer course select. `0` is the Recommended page, and `10` is the Favorites
	u8   pad5;									 // 0xAEB

	int  modelPlayCurrentPage;   	 // 0xAEC -- Selected page in the Hint Movies window, used to auto-select the correct button after a Hint Movie
	int  modelPlayCurrentButton;	 // 0xAF0 -- Selected button in the Hint Movies window, used to auto-select the correct button after a Hint Movie
	int  checkpointID;				 // 0xAF4 -- Collected checkpoint ID from cyuukan data. Set to -1 if a checkpoint hasn't been obtained
	int  stockItemSelection;		 // 0xAF8 -- Last used item in the Items menu, used to auto-select that button when the menu is opened again
	bool changeEffectDraw;			 // 0xAFC -- Allows effects to render above drawing scenes 1/2 in some game scenes, used to draw effects on StockItem and World Select
	u8   _AFD;						 // 0xAFD -- Seems to no longer serve a purpose, set to false at 0x80918FA4 and 0x8092F714
	bool fukidashiHidePrompt[4][22]; // 0xAFE -- If true, the HUD for picking up/carrying certain objects won't be shown for a player. See `FukidashiObjectType_e` enum
	bool fukidashiHidePropeller[4];  // 0xB56 -- Set to true when shaking with a Propeller Suit for the first time, then set to false when the shake prompt is hidden
	bool otehonClearDisablePause;	 // 0xB5A -- Disables the Pause Menu from opening when enabled. Enabled by dOtehonClear_c
	bool easyPairingActive;			 // 0xB5B -- Allows the Easy Pairing window to start pairing controllers

	// Size: 0x10
	struct StartGameInfo_s {
		enum MovieType_e {
			SUPER_SKILLS = 0,
			ENDLESS_1UPS,
			STAR_COIN,
			SECRET_GOAL
		};
		enum GameMode_e {
			NONE = 0,
			SUPER_GUIDE,
			TITLE_SCREEN,
			TITLE_REPLAY,
			HINT_MOVIE
		};

		int  replayDuration; // 0x00
		u8   movieType;		 // 0x04
		u8   entrance;		 // 0x05
		u8   area;			 // 0x06
		bool isReplay;		 // 0x07
		int  gameMode;		 // 0x08 -- Mode that the stage is in, see `GameMode_e` enum
		u8   world1;		 // 0x0C
		u8   world2;		 // 0x0D -- Determines the actual course archive that is loaded
		u8   level1;		 // 0x0E
		u8   level2;		 // 0x0F -- Determines the actual course archive that is loaded
	};

	enum IbaraMode_e {
		NONE = 0,
		UNK_01 = 1,
		UNK_02 = 2,
		UNK_03 = 3,
	};


	dInfo_c();			// 0x800BB0E0
	virtual ~dInfo_c(); // 0x800BB130

	u8 getWorldNo();  // 0x800B2350 -- Returns world from m_startGameInfo
	u8 getCourseNo(); // 0x800B2360 -- Returns level from m_startGameInfo

	void PlayerStateInit();  // 0x800BB180 -- Initialized player types (char IDs) and entry states to default values
	void CourseSelectInit(); // 0x800BB1C0 -- Initializes all data for the World Maps to default values

	void addStockItem(int item);	   // 0x800BB330 -- Increments the specified item by 1
	void subStockItem(int item);	   // 0x800BB380 -- Decrements the specified item by 1
	int  getStockItem(int item) const; // 0x800BB3D0 -- Returns the amount of the specified item
	void clsStockItem(int item);	   // 0x800BB410 -- Resets the specified item count to 0

	void initGame();	  // 0x800BB450 -- Initializes most of the class data, calls CourseSelectInit() and initMultiMode()
	void initMultiMode(); // 0x800BB5B0 -- Initializes the Multi Mode data (win counts and course arrays)

	void startGame(const StartGameInfo_s *info); // 0x800BB7D0 -- Begins a stage with the information in `info`
	void startStaffCredit();					 // 0x800BB8D0 -- Begins the credits stage (01-40)

	void initStage(); // 0x800BB940 -- Initializes class data related to stages and backs up some data

	void SetWorldMapEnemy(int world, int enemyIdx, const dInfo_c::enemy_s *enemyStruct); // 0x800BBBC0
	dInfo_c::enemy_s *GetWorldMapEnemy(int world, int enemyIdx);						 // 0x800BBC00
	void SetMapEnemyInfo(int world, int enemyIdx, int submapID, int pathNode);			 // 0x800BBC20
	void SetMapEnemyReverse(int world, int enemyIdx, int value);						 // 0x800BBC40 -- Unofficial name
	void GetMapEnemyInfo(int world, int enemyIdx, dInfo_c::enemy_s *out);				 // 0x800BBC60 -- Puts data from enemy into `out`

	void SetIbaraNow(int world, IbaraMode_e value); // 0x800BBCA0
	void SetIbaraOld(int world, IbaraMode_e value); // 0x800BBCB0

	int  GetIbaraNow(int world); // 0x800BBCC0
	int  GetIbaraOld(int world); // 0x800BBCD0

	static StartGameInfo_s m_startGameInfo; // 0x80315E90 -- Contains the info used when entering the current level
	static dStartInfo_c    m_startInfo;		// 0x80359054
	static dInfo_c *m_instance;				// 0x8042A25C
	static u32 mGameFlag;			   		// 0x8042A260 -- Bitfield controlling various aspects of the game. See the `GameFlag_e` enum
};