#pragma once
#include <game.h>

/* RESTART_CRSIN
 - Actor ID 6
 - Sprite ID N/A
 - Settings Parameters:
	- N/A

 - Profile Struct:	0x8098D3D0
 - Build Function:	0x80923970
 - Vtable:			0x8098D3D8
 - Constructor:		0x809239A0
 - Destructor:		0x809239E0
 - State Init:		N/A
 - Class Instance:	N/A
*/

// DRAW FUNCTION: N/A

// Size: 0x74
class dScRestartCrsin_c : public dScene_c {
public:
	int onCreate();		 // 0x80923A40
	int beforeExecute(); // 0x80923AB0
	int onExecute();	 // 0x80923AE0 -- Runs dInfo_c::startGame using data from RESTART_CRSIN_LevelStartStruct
	int onDraw();		 // 0x80923B50
	int onDelete();		 // 0x80923B20 -- Resets FadeIn/FadeOutFrame to 30
};