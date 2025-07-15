#pragma once
#include <game.h>

// Miscellaneous and General functions/documentation
// Take whatever you need and put it into your game.h file

// Colors the frame of a Window Pane based on the value passed to the charID param
// 0 = Mario, 1 = Luigi, 2 = Blue Toad, and 3 = Yellow Toad
void assignPlayerColorToWindow(nw4r::lyt::Pane *window, int charID); // 0x800B3C50

// Called by dOtasukeInfo_c::executeState_ClouseAnimeEndWait(), if the current screen type is 4 (Hint Movie)
// Sets PauseManager_c::m_Pause to false
void disablePauseForOtasukeInfo(); // 0x80916FE0

// Sends the player to the 01-41 stage, without showing the PreGame
void returnToPeachCastle(); // 0x801019D0

// Current status of the Star Coins in a level, a value of 4 means the coin is uncollected
// Otherwise, the value is the CharID of the player that collected it
u32 StarCoinStatusArray[3]; // 0x803744B0