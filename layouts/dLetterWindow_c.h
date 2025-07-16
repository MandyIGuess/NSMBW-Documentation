#pragma once
#include <game.h>

/* LETTER_WINDOW
 - Actor ID 746 [KR/TW: 748; CN: 750]

 - Profile Struct:	0x80945560
 - Build Function:	0x80789BB0
 - Vtable:			0x809456A8
 - Constructor:		0x80789BE0
 - Destructor:		0x80789DF0
 - State Init:		0x8078A790
*/

// Size: 0x258
class dLetterWindow_c : public dBase_c {
public:
	enum Animation {
		IN_WINDOW = 0,
		IN_BTN,
		LOOP_BTN,
		HIT_BTN,
		OUT_WINDOW
	};

	dStateWrapper_c<dLetterWindow_c> state; // 0x70
	m2d::EmbedLayout_c layout;				// 0xAC

	nw4r::lyt::Pane *rootPane;		  // 0x244
	nw4r::lyt::TextBox *T_message_00; // 0x248
	nw4r::lyt::Picture *P_line_00;	  // 0x24C

	bool layoutLoaded; // 0x250
	bool visible;	   // 0x251
	bool animActive;   // 0x252
	u8   pad;		   // 0x253
	int playerCount;   // 0x254 -- Used to determine BMG message ID


	dLetterWindow_c();  // 0x80789BE0
	~dLetterWindow_c(); // 0x80789DF0

	int onCreate();		 // 0x80789E80
	int beforeExecute(); // 0x8078A000
	int onExecute();	 // 0x8078A040
	int onDraw();		 // 0x8078A0C0
	int onDelete();		 // 0x8078A100

	bool loadLayout(); // 0x80789F20

	static dLetterWindow_c *build(); // 0x80789BB0

	USING_STATES(dLetterWindow_c);
	REF_NINTENDO_STATE(StartWait);
	REF_NINTENDO_STATE(StartAnimeEndWait);
	REF_NINTENDO_STATE(ButtonOnStageAnimeEndWait);
	REF_NINTENDO_STATE(ButtonInputWait);
	REF_NINTENDO_STATE(HitAnimeEndWait);
	REF_NINTENDO_STATE(ExitAnimeEndWait);
};

/* Class State Info:
 - StateID_StartWait (0x80992B40)
	Waits for layout to be visible before changing state
	- Begin:   0x8078A110
	- Execute: 0x8078A120
	- End:     0x8078A150

 - StateID_StartAnimeEndWait (0x80992B80)
	Writes the appropriate message to the layout, and opens the window
	- Begin:   0x8078A160
	- Execute: 0x8078A250
	- End:     0x8078A2B0

 - StateID_ButtonOnStageAnimeEndWait (0x80992BC0)
	Toggles IN_BTN animation, then toggles the LOOP_BTN animation
	- Begin:   0x8078A2C0
	- Execute: 0x8078A300
	- End:     0x8078A360

 - StateID_ButtonInputWait (0x80992C00)
	Waits for the player to close the window with 2 or A
	- Begin:   0x8078A3A0
	- Execute: 0x8078A3B0
	- End:     0x8078A420

 - StateID_HitAnimeEndWait (0x80992C40)
	Toggles the HIT_BTN animation
	- Begin:   0x8078A430
	- Execute: 0x8078A490
	- End:     0x8078A4F0

 - StateID_ExitAnimeEndWait (0x80992C80)
	Plays OUT_WINDOW animation, disables layout visibility, and sets RootPane to invisible
	- Begin:   0x8078A500
	- Execute: 0x8078A540
	- End:     0x8078A5A0
*/