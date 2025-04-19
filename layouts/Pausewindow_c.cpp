/* PAUSEWINDOW
 - Actor ID 710 [KR/TW: 712; CN: 714]
 - Sprite ID N/A
 - Settings Parameters:
	- N/A

 - Profile Struct:	0x80327D24
 - Build Function:	0x8015A480
 - Vtable:			0x80328078
 - Constructor:		0x8015A4B0
 - Destructor:		0x8015A6C0
 - State Init:		0x8015B460
 - Class Instance:	0x8042A61C
*/

/* RELATED FILES:
 - PauseManager_c.cpp
*/

/* NOTES:
 - Button functionality is handled by PauseManager_c::handleInput (0x800D0DA0)
 - Window frame is colored with the assignPlayerColorToWindow() function (see general.h)
*/

// Size: 0x298
class Pausewindow_c : public dBase_c {
public:
	enum Animation {
		IN_WINDOW = 0,
		LOOP_WINDOW,
		OUT_WINDOW,
		ON_CONT_BUTTON,
		ON_EXIT_BUTTON,
		IDLE_CONT_BUTTON,
		IDLE_EXIT_BUTTON,
		OFF_CONT_BUTTON,
		OFF_EXIT_BUTTON,
		HIT_CONT_BUTTON,
		HIT_EXIT_BUTTON
	};

	m2d::EmbedLayout_c layout;			  // 0x70
	dStateWrapper_c<Pausewindow_c> state; // 0x208

	nw4r::lyt::Picture *P_SBBase_00;	  // 0x244
	nw4r::lyt::Picture *P_SBBase_02;	  // 0x248
	nw4r::lyt::Picture *P_shadowBlack;	  // 0x24C - Shown if Exit option is unavailable
	nw4r::lyt::Picture *P_coin_00;		  // 0x250
	nw4r::lyt::Pane    *W_N_pauseMenu_00; // 0x254
	nw4r::lyt::TextBox *T_tuzukeru_00;	  // 0x258
	nw4r::lyt::TextBox *T_tuzukeru_01;	  // 0x25C
	nw4r::lyt::TextBox *T_modoru_00;	  // 0x260
	nw4r::lyt::TextBox *T_modoru_01;	  // 0x264
	nw4r::lyt::TextBox *T_worldNum_00;	  // 0x268
	nw4r::lyt::TextBox *T_corseNum_00;	  // 0x26C
	nw4r::lyt::TextBox *T_corsePic_00;	  // 0x270
	nw4r::lyt::TextBox *T_osusumeText_00; // 0x274
	nw4r::lyt::Pane    *N_worldText_00;   // 0x278
	nw4r::lyt::Pane    *N_osusumeText_00; // 0x27C - Set invisible by setupLevelData()
	nw4r::lyt::Pane    *N_multiText_00;   // 0x280 - Set invisible by setupLevelData()

	int nextButton;    // 0x284
	int currentButton; // 0x288
	int windowColorID; // 0x28C - Determines what color will be assigned to W_N_pauseMenu_00 (character ID of the player opening the menu)

	bool layoutLoaded;		// 0x290
	bool visible;			// 0x291
	bool menuCancelled;		// 0x292
	bool buttonHit;			// 0x293
	bool animationActive;	// 0x294
	bool needsToSetStrings; // 0x295 - If true, BMG strings will be written to the buttons during the InitWait state
	u8  _296;				// 0x296
	u8  _297;				// 0x297


	int onCreate();  // 0x8015A750
	int onExecute(); // 0x8015A950
	int onDraw();	 // 0x8015A9D0
	int onDelete();  // 0x8015AA10

	void loadInfo();	   // 0x8015AA50 - Writes world number and level number/icon to the layout
	void setupLevelData(); // 0x8015AC60 - Hides some panes and runs loadInfo() if the game isn't in Coin Battle mode
	void updateCursor();   // 0x8015AD70 - Updates SelectCursor to target the selected button

	static Pausewindow_c *instance; // 0x8042A61C

	USING_STATES(Pausewindow_c);
	REF_NINTENDO_STATE(InitWait);
	REF_NINTENDO_STATE(OpenAnimeEndWait);
	REF_NINTENDO_STATE(ButtonChangeAnimeEndWait);
	REF_NINTENDO_STATE(PauseDisp);
	REF_NINTENDO_STATE(HitAnimeEndWait);
	REF_NINTENDO_STATE(ClouseAnimeEndWait);
};

/* Class State Info:
 - StateID_InitWait (0x80377480)
	Colors the menu frame and writes BMG strings to the buttons if needsToSetStrings is enabled
	- Begin:   0x8015ADA0
	- Execute: 0x8015ADB0
	- End:     0x8015AEB0

 - StateID_OpenAnimeEndWait (0x803774C0)
	Resets button animations and plays the IN_WINDOW animation, then sets some initial values
	- Begin:   0x8015AEC0
	- Execute: 0x8015AF30
	- End:     0x8015AF90

 - StateID_ButtonChangeAnimeEndWait (0x80377500)
	Toggles OFF_BUTTON animation for previous button, and ON_BUTTON animation for newly selected button
	- Begin:   0x8015AFB0
	- Execute: 0x8015B020
	- End:     0x8015B080

 - StateID_PauseDisp (0x80377540)
	Handles changing states depending on values of some class members, actual functionality is handled by PauseManager
	- Begin:   0x8015B090
	- Execute: 0x8015B0A0
	- End:     0x8015B160

 - StateID_HitAnimeEndWait (0x80377580)
	Toggles HIT_BUTTON animation for the selected button
	- Begin:   0x8015B170
	- Execute: 0x8015B190
	- End:     0x8015B1F0

 - StateID_ClouseAnimeEndWait (0x803775C0)
	Toggles OUT_WINDOW animation
	- Begin:   0x8015B200
	- Execute: 0x8015B220
	- End:     0x8015B280
*/