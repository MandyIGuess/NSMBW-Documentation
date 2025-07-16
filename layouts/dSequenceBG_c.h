#pragma once
#include <game.h>

/* SEQUENCE_BG
 - Actor ID 721 [KR/TW: 723; CN: 725]

 - Profile Struct:	0x8094EC40
 - Build Function:	0x807AD5F0
 - Vtable:			0x8094F088
 - Constructor:		0x807AD620
 - Destructor:		0x807AD670
*/

/* NOTES:
 - External textures are loaded from "/Layout/textures/sequenceBGTexture.arc"
*/

// Size: 0x280
class dSequenceBG_c : public dBase_c {
public:
	enum Animation {
		IN_WINDOW = 0,
		LOOP_BG_50,
		LOOP_BG_40,
		LOOP_BG_30,
		LOOP_BG_20,
		LOOP_BG_10,
		LOOP_BG_00,
		LOOP_CLOUD,
		OUT_WINDOW
	};

	u32 _70;				   // 0x70
	m2d::EmbedLayout_c layout; // 0x74

	nw4r::lyt::Pane    *rootPane;  // 0x20C
	nw4r::lyt::Picture *P_BG50;    // 0x210
	nw4r::lyt::Picture *P_BG51;    // 0x214
	nw4r::lyt::Picture *P_BG52;    // 0x218
	nw4r::lyt::Picture *P_BG40;    // 0x21C
	nw4r::lyt::Picture *P_BG41;    // 0x220
	nw4r::lyt::Picture *P_BG42;    // 0x224
	nw4r::lyt::Picture *P_BG30;    // 0x228
	nw4r::lyt::Picture *P_BG31;    // 0x22C
	nw4r::lyt::Picture *P_BG32;    // 0x230
	nw4r::lyt::Picture *P_BG20;    // 0x234
	nw4r::lyt::Picture *P_BG21;    // 0x238
	nw4r::lyt::Picture *P_BG22;    // 0x23C
	nw4r::lyt::Picture *P_BG23;    // 0x240
	nw4r::lyt::Picture *P_BG24;    // 0x244
	nw4r::lyt::Picture *P_BG25;    // 0x248
	nw4r::lyt::Picture *P_BG10;    // 0x24C
	nw4r::lyt::Picture *P_BG11;    // 0x250
	nw4r::lyt::Picture *P_BG12;    // 0x254
	nw4r::lyt::Picture *P_BG00;    // 0x258
	nw4r::lyt::Picture *P_BG01;    // 0x25C
	nw4r::lyt::Picture *P_BG02;    // 0x260

	nw4r::lyt::Picture *P_cloud00; // 0x264
	nw4r::lyt::Picture *P_cloud01; // 0x268
	nw4r::lyt::Picture *P_cloud02; // 0x26C
	nw4r::lyt::Picture *P_cloud03; // 0x270
	nw4r::lyt::Picture *P_cloud04; // 0x274
	nw4r::lyt::Picture *P_cloud05; // 0x278

	bool layoutLoaded; // 0x27C
	u8   pad[3];	   // 0x27D


	dSequenceBG_c();  // 0x807AD620
	~dSequenceBG_c(); // 0x807AD670

	int onCreate();	 // 0x807AD6E0
	int onExecute(); // 0x807AD9B0
	int onDraw();	 // 0x807ADA10
	int onDelete();	 // 0x807ADA50

	bool loadLayout();	 // 0x807AD800 -- Sets up layout data and animations, gets panes in the class
	void loadTextures(); // 0x807AD8C0 -- Loads external textures and binds them to layout panes

	static dSequenceBG_c *build(); // 0x807AD5F0
};