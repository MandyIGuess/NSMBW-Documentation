#pragma once
#include <game.h>

/* COURSE_SELECT_MENU
 - Actor ID 693 [KR/TW: 693; CN: 695]
 - Sprite ID N/A
 - Settings Parameters:
	- N/A

 - Profile Struct:	0x809412C0
 - Build Function:	0x8077A750
 - Vtable:			0x809415D8
 - Constructor:		0x8077A780
 - Destructor:		0x8077A980
 - State Init:		0x8077B4E0
 - Class Instance:	N/A
*/

/* NOTES:
 - Button functionality is handled by dCourseSelectManager_c::executeState_PushAnimeEndWait (0x8092FC30)
*/

// Size: 0x278
class dCourseSelectMenu_c : public dBase_c {
public:
	enum Animation {
		IN_WINDOW = 0,
		LOOP_WINDOW,
		ON_BUTTON,
		IDLE_BUTTON = 6,
		HIT_BUTTON = 10,
		OFF_BUTTON = 14,
		OUT_WINDOW = 18
	};

	m2d::EmbedLayout_c layout;					// 0x70
	dStateWrapper_c<dCourseSelectMenu_c> state;	// 0x208

	nw4r::lyt::Pane	   *rootPane;		  // 0x244
	nw4r::lyt::Picture *P_SBBase_01;	  // 0x248
	nw4r::lyt::Picture *P_SBBase_02;	  // 0x24C
	nw4r::lyt::Picture *P_SBBase_03;	  // 0x250
	nw4r::lyt::Picture *P_SBBase_04;	  // 0x254
	nw4r::lyt::Picture *P_back;			  // 0x258 - Shown if the game is in widescreen mode
	nw4r::lyt::Picture *P_backWhite;	  // 0x25C - Shown if the game is in 4:3 mode
	nw4r::lyt::TextBox *T_corseSelectS03; // 0x260
	nw4r::lyt::TextBox *T_corseSelect_03; // 0x264

	int  currentSelection;	// 0x268
	int  previousSelection;	// 0x26C
	bool layoutLoaded;		// 0x270
	bool visible;			// 0x271
	bool choiceWasMade;		// 0x272 - If true, dCourseSelectManager_c will run the code to open the relevant menu
	bool disableInput;		// 0x273 - Enabling this will skip the button input logic (retail game never enables this)
	bool _274;				// 0x274 - Serves no purpose? Set to true in PauseDisp state, set to 0 if it already equals 0 in updateCursor();
	u8	 pad[3];			// 0x275 - Pad to next multiple of 4


	int onCreate();		 // 0x8077AA10
	int beforeExecute(); // 0x8077AC60
	int onExecute();	 // 0x8077ACA0
	int onDraw();		 // 0x8077AD20
	int onDelete();		 // 0x8077AD60

	bool loadLayout();	 // 0x8077AB70 - Sets up layout data and animations, gets panes in the class
	// Cursor will target P_SBBase_0X panes
	// Layout uses cursor ID 4
	void updateCursor(); // 0x8077AD70 - Updates SelectCursor to target the selected button

	USING_STATES(dCourseSelectMenu_c);
	REF_NINTENDO_STATE(InitWait);
	REF_NINTENDO_STATE(OpenAnimeEndWait);
	REF_NINTENDO_STATE(ButtonChangeAnimeEndWait);
	REF_NINTENDO_STATE(PauseDisp);
	REF_NINTENDO_STATE(HitAnimeEndWait);
	REF_NINTENDO_STATE(ClouseAnimeEndWait);
};

/* Class State Info:
 - StateID_InitWait (0x809915D0)
	Resets animations, plays IN_WINDOW animation and sets RootPane to visible
	- Begin:   0x8077ADB0
	- Execute: 0x8077ADC0
	- End:     0x8077AE70

 - StateID_OpenAnimeEndWait (0x80991610)
	Waits for IN_WINDOW animation to complete
	- Begin:   0x8077AE80
	- Execute: 0x8077AE90
	- End:     0x8077AEF0

 - StateID_ButtonChangeAnimeEndWait (0x80991650)
	Toggles OFF_BUTTON animation for previous button, and ON_BUTTON animation for newly selected button
	- Begin:   0x8077AF10
	- Execute: 0x8077AF90
	- End:     0x8077AFF0

 - StateID_PauseDisp (0x80991690)
	Waits for player inputs
	- Begin:   0x8077B000
	- Execute: 0x8077B010
	- End:     0x8077B190

 - StateID_HitAnimeEndWait (0x809916D0)
	Toggles HIT_BUTTON animation for current button, and waits for it to complete
	- Begin:   0x8077B1A0
	- Execute: 0x8077B1C0
	- End:     0x8077B220

 - StateID_ClouseAnimeEndWait (0x80991710)
	Plays OUT_WINDOW animation, disables layout visibility, and sets RootPane to invisible
	- Begin:   0x8077B230
	- Execute: 0x8077B290
	- End:     0x8077B300
*/