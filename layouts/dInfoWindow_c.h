#pragma once
#include <game.h>

/* INFO_WINDOW
 - Actor ID 718 [KR/TW: 720; CN: 722]

 - Profile Struct:	0x80945418
 - Build Function:	0x80789810
 - Vtable:			0x80945510
 - Constructor:		0x80789840
 - Destructor:		0x80789890
*/

// Size: 0x224
class dInfoWindow_c : public dBase_c {
public:
	enum Animation {
		IN_INFO_WINDOW = 0,
		IN_SHADOW_BG,
		OUT_INFO_WINDOW,
		OUT_SHADOW_BG
	};

	m2d::EmbedLayout_c layout;			 // 0x70
	nw4r::lyt::Pane *rootPane;			 // 0x208
	nw4r::lyt::Pane *W_finishInfo_00;	 // 0x20C
	nw4r::lyt::TextBox *T_finishInfo_00; // 0x210
	nw4r::lyt::TextBox *T_finishInfo_01; // 0x214

	int action;		// 0x218 -- 0 = opening window, 2 = closing window, 4 = idle
	int actionCopy; // 0x21C -- Set to whatever action equals. Disables layout visibility if it equals 2

	bool layoutLoaded;	  // 0x220
	bool visible;		  // 0x221
	bool animationActive; // 0x222
	u8   pad;			  // 0x223


	dInfoWindow_c();  // 0x80789840
	~dInfoWindow_c(); // 0x80789890

	int onCreate();	 // 0x80789900
	int onExecute(); // 0x80789A70
	int onDraw();	 // 0x80789B60
	int onDelete();	 // 0x80789BA0

	bool loadLayout(); // 0x80789990

	static dInfoWindow_c *build(); // 0x80789810
};