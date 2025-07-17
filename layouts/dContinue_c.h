#pragma once
#include <game.h>

/* CONTINUE
 - Actor ID 726 [KR/TW: 728; CN: 730]

 - Profile Struct:	0x80940388
 - Build Function:	0x807775E0
 - Vtable:			0x80940770
 - Constructor:		0x80777610
 - Destructor:		0x80777810
 - State Init:		0x80778D00
*/

// Size: 0x2E4
class dContinue_c : public dBase_c {
public:
	enum Animation {
		IN_WINDOW = 0,
		COUNT_CONTINUE,
		ZANKI_RECOVER,
		COLOR_RECOVER,
		OUT_WINDOW,
		IN_BG,
		OUT_BG
	};

	m2d::EmbedLayout_c layout;			// 0x70
	dStateWrapper_c<dContinue_c> state; // 0x208

	nw4r::lyt::Pane *rootPane;			  // 0x244
	nw4r::lyt::Picture *P_bg_PContinue;   // 0x248
	nw4r::lyt::Pane *N_4P_Pos_0X[4];	  // 0x24C
	nw4r::lyt::Pane *N_3P_Pos_0X[3];	  // 0x25C
	nw4r::lyt::Pane *N_2P_Pos_0X[2];	  // 0x268
	nw4r::lyt::Pane *N_1P_Pos_0X;		  // 0x270
	nw4r::lyt::Pane *N_dateFile_0XP[4];   // 0x274
	nw4r::lyt::TextBox *T_conTime_0X[4];  // 0x284
	nw4r::lyt::TextBox *T_playerZanki_04; // 0x294
	nw4r::lyt::TextBox *T_playerZanki_05; // 0x298
	nw4r::lyt::TextBox *T_playerZanki_06; // 0x29C
	nw4r::lyt::TextBox *T_playerZanki_07; // 0x2A0

	int playerCount;	 // 0x2A4 -- Number of players that get a continue
	int continues[4];	 // 0x2A8 -- Current number of continues for each player
	int lives[4];		 // 0x2B8 -- Current number of lives for each player
	int newLivesCounter; // 0x2C8 -- Incremented by 1 for each new life added to revived players
	int countdown;		 // 0x2CC
	int exitCountdown;	 // 0x2D0 -- Countdown until the player can exit the screen

	bool layoutLoaded;		 // 0x2D4
	bool visible;			 // 0x2D5
	bool willOpen;			 // 0x2D6 -- Enabled by dScGameOver_c/dCourseSelectManager_c
	bool willClose;			 // 0x2D7
	bool willGetContinue[4]; // 0x2D8 -- Enabled for players that need a continue, determines which player cards are shown

	u32  _2DC;		 // 0x2DC -- Unused
	bool isGameOver; // 0x2E0 -- Enabled if the Continue screen is being activated from the GAME_OVER scene
	u8   pad[3];	 // 0x2E1


	dContinue_c();  // 0x80777610
	~dContinue_c(); // 0x80777810

	int onCreate();		 // 0x807778A0
	int beforeExecute(); // 0x80777AE0
	int onExecute();	 // 0x80777B40
	int onDraw();		 // 0x80777BD0
	int onDelete();		 // 0x80777C10

	bool loadLayout();				  // 0x807779D0
	int  getPosPaneIdx(int playerID); // 0x80777C20
	void positionCards();			  // 0x80777C50

	void updateContinues(); // 0x80777DA0
	void updateLives();		// 0x80777E30
	void setPlayerInfo();	// 0x80777EC0

	void playContinueEffect(int playerID, int numLength); // 0x80777FD0 -- `numLength` is the length of the continue count, used to position the effect

	USING_STATES(dContinue_c);
	REF_NINTENDO_STATE(StartWait);				// 0x809911C0 -- Initialize: 0x80778150; Execute: 0x80778160; Finalize: 0x80778220
	REF_NINTENDO_STATE(BlackInAnimeEndWait);	// 0x80991200 -- Initialize: 0x80778230; Execute: 0x80778240; Finalize: 0x807782A0
	REF_NINTENDO_STATE(OpenAnimeEndWait);		// 0x80991240 -- Initialize: 0x807782B0; Execute: 0x80778310; Finalize: 0x80778370
	REF_NINTENDO_STATE(ContinueCountUpWait);	// 0x80991280 -- Initialize: 0x80778380; Execute: 0x80778390; Finalize: 0x807783D0
	REF_NINTENDO_STATE(ContinueCountUp);		// 0x809912C0 -- Initialize: 0x807783E0; Execute: 0x807784C0; Finalize: 0x80778520
	REF_NINTENDO_STATE(RestCountUpWait);		// 0x80991300 -- Initialize: 0x80778530; Execute: 0x80778540; Finalize: 0x80778580
	REF_NINTENDO_STATE(RestCountUp);			// 0x80991340 -- Initialize: 0x80778590; Execute: 0x807785A0; Finalize: 0x807786A0
	REF_NINTENDO_STATE(ColorRecover);			// 0x80991380 -- Initialize: 0x807787C0; Execute: 0x807787D0; Finalize: 0x80778830
	REF_NINTENDO_STATE(EndWait);				// 0x809913C0 -- Initialize: 0x80778840; Execute: 0x80778860; Finalize: 0x807789B0
	REF_NINTENDO_STATE(ExitAnimeEndWait);		// 0x80991400 -- Initialize: 0x80778A30; Execute: 0x80778A40; Finalize: 0x80778AA0
	REF_NINTENDO_STATE(BlackExitAnimeEndWait);  // 0x80991440 -- Initialize: 0x80778Ab0; Execute: 0x80778AC0; Finalize: 0x80778B20
};