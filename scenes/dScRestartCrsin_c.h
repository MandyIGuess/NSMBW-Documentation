#pragma once
#include <game.h>
#include "dInfo_c.h"

/* RESTART_CRSIN
 - Actor ID 6

 - Profile Struct:	0x8098D3D0
 - Build Function:	0x80923970
 - Vtable:			0x8098D3D8
 - Constructor:		0x809239A0
 - Destructor:		0x809239E0
*/

// DRAW FUNCTION: N/A

// Size: 0x74
class dScRestartCrsin_c : public dScene_c {
public:
	dScRestartCrsin_c();  // 0x809239A0
	~dScRestartCrsin_c(); // 0x809239E0

	int onCreate();		 // 0x80923A40
	int beforeExecute(); // 0x80923AB0
	int onExecute();	 // 0x80923AE0 -- Runs dInfo_c::startGame using data from RESTART_CRSIN_LevelStartStruct
	int onDraw();		 // 0x80923B50
	int onDelete();		 // 0x80923B20 -- Resets FadeIn/FadeOutFrame to 30

	static void startTitle(bool isReplay, u32 sceneParam); // 0x801018E0 -- Begins the titlescreen (01-40) or a title replay. Formerly known as StartTitleScreenStage
	static void reStartPeachCastle();					   // 0x801019D0 -- Begins the Peach's Castle stage (01-41)

	static dInfo_c::StartGameInfo_s *m_startGameInfo; // 0x80374060
	static dScRestartCrsin_c *build();				  // 0x80923970
};