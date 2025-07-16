#pragma once
#include <game.h>
#include "layouts/Pausewindow_c.h"
#include "layouts/dOtasukeInfo_c.h"

/* PauseManager_c

 - Vtable:			0x80317D78
 - Constructor:		0x800D0A90
 - Destructor:		0x800D0AC0
 - State Init:		N/A
 - Class Instance:	0x8042A2B8
*/

/* PTMF Structs:
  - [0] 0x802F1498
  - [1] 0x802F14A4
  - [2] 0x802F14B0
  - [3] 0x802F14BC
  - [4] 0x802F14C8
  - [5] 0x802F14D4
  - [6] 0x802F14E0
*/

/* NOTES:
 - Newer's headers have this class labelled as "StageC4"
*/

// Size: 0x20
class PauseManager_c {
public:
	int currentState;	// 0x04 -- Sets the current PTMF state
	int selection;		// 0x08
	int playerNum;		// 0x0C
	int _10;			// 0x10 -- Unused? Set to 0 when initialized, never set anywhere else
	int yesNoSelection; // 0x14 -- Selection for the course exit prompt

	/* Flags:
	 * 1: Game is currently paused
	 * 2: Game can be paused
	 * 4: Pauses game
	*/
	u8 flags; // 0x18

	bool buttonAnimPlaying; // 0x19
	bool exitingMenu;		// 0x1A
	bool willDisplay;		// 0x1B
	bool isGuideActive;		// 0x1C -- Set to true if the Super Guide replay is active
	bool disablePause;		// 0x1D -- Disables pausing the game
	u8 pad[2];				// 0x1E


	PauseManager_c();			// 0x800D0A90
	virtual ~PauseManager_c();	// 0x800D0AC0

	void initialize(); // 0x800D0B30
	void execute();    // 0x800D0B60

	void CourseHoinitialize();	 // 0x800D0B10 -- Sets m_OtasukeAfter to true if the screen type is 1, and sets disablePause to false
	void setPauseEnable(bool);	 // 0x800D0C10 -- Sets if the player can pause the game
	bool isDisable();			 // 0x800D0C40 -- Returns if (flag >> 1 & 1) is true or not
	void SelectSoundSet();		 // 0x800D0CF0 -- Called by handleInput()
	void handleInput();			 // 0x800D0DA0 -- [Unofficial name] Handles button inputs for the menu
	void ProcMainPauseOffInit(); // 0x800D0F80 -- Unpauses the game, sets next state to 3
	void PauseSetUp(int player); // 0x800D12E0 -- Parameter is used to determine the color of the border, and which player controls the menu
	void setPause();			 // 0x800D1350 -- Runs through different conditions to see if the game can be paused
	void onDispOtasukeWindow();	 // 0x800D15A0 -- Displays OtasukeInfo layout when the Super Guide block is hit
	bool isOtasukePause();		 // 0x800D15D0 -- Returns if OtasukeInfo is active

	// PTMF States:
	void ProcMainInit(); 					// 0x800D0C50 -- Opens the menu, sets next state to 1
	void ProcMainPauseOn(); 				// 0x800D0CE0 -- Sets next state to 2
	void ProcMainPause(); 		  			// 0x800D0F40 -- Calls handleInput()
	void ProcMainPauseOff(); 				// 0x800D1010 -- Closes menu and opens the Yes-No Window if the Exit button was hit (sets next state to 0, or 5 if Exit button was hit)
	void OtasukeDisp();						// 0x800D1280 -- Handles pausing for OtasukeInfo (prompt in Replays), opens pause menu if Luigi's Replay is disabled, sets next state to 0
	void CourseOutConfirmation();			// 0x800D10D0 -- Handles button functionality for the Yes-No Window, sets next state to 6
	void ConfirmationSelectDecisionWait();	// 0x800D11F0 -- Returns to the World Map/Course-Select, or re-opens the pause menu (setting the state to 0)

	static PauseManager_c *instance;		// 0x8042A2B8
	static dOtasukeInfo_c *m_OtasukeInfo_p; // 0x8042A2BC -- Pointer to dOtasukeInfo_c
	static bool m_Pause;					// 0x8042A2C0 -- Determines if the game is currently paused
	static bool m_Created;					// 0x8042A2C1 -- Set to true in initialize()
	static bool m_OtasukeAfter;				// 0x8042A2C2 -- Handles showing Exit prompt on level HUD, set to true if player has taken control of Super Guide Luigi
};