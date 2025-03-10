/* OTASUKE_INFO
 - Actor ID 709 [KR/TW: 711; CN: 713]
 - Sprite ID N/A
 - Settings Parameters:
	- N/A

 - Profile Struct:	0x8098aa88
 - Build Function:	0x809160e0
 - Vtable:			0x8098acc0
 - Constructor:		0x80916110
 - Destructor:		0x80916310
 - State Init:		0x80917240
 - Class Instance:	N/A
*/

/* NOTES:
 - A pointer to this calss can be found at PauseManager_c::m_OtasukeInfo (0x8042A2BC)
 - The OK button cannot be pressed if mGameFlag & 4 (ReplayLoaded) is disabled
 - The following functions in general.h are used by functions in this class:
   - disablePauseForOtasukeInfo();
   - returnToPeachCastle();
*/

// Size: 0x270
class dOtasukeInfo_c : public dBase_c {
public:
	m2d::EmbedLayout_c layout;				// 0x70
	dStateWrapper_c<dOtasukeInfo_c> state;  // 0x208

	enum Animation {
		IN_WINDOW,
		IN_YES_BUTTON,
		IN_NO_BUTTON,
		ON_YES_BUTTON,
		ON_NO_BUTTON,
		IDLE_YES_BUTTON,
		IDLE_NO_BUTTON,
		HIT_YES_BUTTON,
		HIT_NO_BUTTON,
		OFF_YES_BUTTON,
		OFF_NO_BUTTON,
		OUT_WINDOW
	};

	nw4r::lyt::Pane *rootPane;	      // 0x244
	nw4r::lyt::TextBox *T_infoS_00;   // 0x248
	nw4r::lyt::TextBox *T_info_00;	  // 0x24C
	nw4r::lyt::TextBox *T_yes_00;	  // 0x250
	nw4r::lyt::TextBox *T_yes_01;	  // 0x254
	nw4r::lyt::TextBox *T_no_00;	  // 0x258
	nw4r::lyt::TextBox *T_no_00;	  // 0x25C
	nw4r::lyt::Picture *P_yesBase_00; // 0x260
	nw4r::lyt::Picture *P_noBase_00;  // 0x264

	bool layoutLoaded;   // 0x268
	bool visible;		 // 0x269
	u8 selection;		 // 0x26A - 0: No, 1: Yes
	bool disableInput;   // 0x26B - Enabling this skips the button input logic (the retail game never enables this)
	bool hideExitPrompt; // 0x26C - Enabling this will hide the Exit prompt on the level HUD
	bool willPause;		 // 0x26D - When enabled, the game will pause while the menu is active
	u8 pad[2];			 // 0x26E


	int onCreate();		 // 0x809163A0
	int beforeExecute(); // 0x80916510
	int onExecute();	 // 0x809165B0
	int onDraw();		 // 0x80916630
	int onDelete();		 // 0x80916670

	bool loadLayout();	  // 0x80916430 - Loads layout data and animations, gets panes in the class, calls setupStrings()
	void setupStrings();  // 0x809166A0 - Writes the proper message string to the T_infoS_00 and T_info_00 textboxes
	void updateCursor();  // 0x80916680 - Updates SelectCursor to target the selected button
	void disableReplay(); // 0x80916760 - Disables Super Guide replay, and gives the player control of Luigi
	void startReplay();   // 0x809167D0 - Sets state to OtehonCourseOutWait, and goes to the RESTART_CRSIN scene (restarting the level in Super Guide mode)

	USING_STATES(dOtasukeInfo_c);
	REF_NINTENDO_STATE(Initial);
	REF_NINTENDO_STATE(OpenAnimeEndWait);
	REF_NINTENDO_STATE(FirstButtonChangeAnimeEndWait);
	REF_NINTENDO_STATE(Select);
	REF_NINTENDO_STATE(ButtonChangeAnimeEndWait);
	REF_NINTENDO_STATE(HitAnimeEndWait);
	REF_NINTENDO_STATE(ClouseAnimeEndWait);
	REF_NINTENDO_STATE(OtehonCourseOutWait);
};

/* Class State Info:
 - StateID_Initial (0x809A12E0)
	Plays open anims and sets RootPane to visible
	- Begin:   0x80916890
	- Execute: 0x809168A0
	- End:     0x80916930

 - StateID_OpenAnimeEndWait (0x809A1320)
	Waits for open animations to complete, then plays the ON_NO_BUTTON anim
	- Begin:   0x80916960
	- Execute: 0x80916990
	- End:     0x80916A00

 - StateID_FirstButtonChangeAnimeEndWait (0x809A1360)
	Waits for previous animation to complete, then goes to the next state
	- Begin:   0x80916A10
	- Execute: 0x80916A20
	- End:     0x80916A80

 - StateID_Select (0x809A13A0)
	Handles player button inputs
	- Begin:   0x80916A90
	- Execute: 0x80916AA0
	- End:     0x80916C30

 - StateID_ButtonChangeAnimeEndWait (0x809A13E0)
	Plays OFF anim for the previously selected button, and the ON anim for the new button
	- Begin:   0x80916C40
	- Execute: 0x80916CE0
	- End:     0x80916D40

 - StateID_HitAnimeEndWait (0x809A1420)
	Plays the HIT anim for the selected button, and performs an action based on the screen type
	- Begin:   0x80916D50
	- Execute: 0x80916DB0
	- End:     0x80916EB0

 - StateID_ClouseAnimeEndWait (0x809A1460)
	Plays the OUT_WINDOW animation, and hides the Exit prompt on the level HUD if `hideExitPrompt` is enabled
	- Begin:   0x80916EC0
	- Execute: 0x80916F20
	- End:     0x80916FE0

 - StateID_OtehonCourseOutWait (0x809A14A0)
	Empty state used while the game restarts a stage in Super Guide mode, or returns to Peach's Castle
	- Begin:   0x80917040
	- Execute: 0x80917050
	- End:     0x80917060
*/