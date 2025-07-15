#pragma once
#include <game.h>

/* STOCK_ITEM_SHADOW
 - Actor ID 696 [KR/TW: 696; CN: 697]
 - Sprite ID N/A
 - Settings Parameters:
	- N/A

 - Profile Struct:	0x809501B0
 - Build Function:	0x807B2030
 - Vtable:			0x809503D8
 - Constructor:		0x807B2060
 - Destructor:		0x807B20B0
 - State Init:		N/A
 - Class Instance:	N/A
*/

// Size: 0x280
class dStockItemShadow_c : public dBase_c {
public:
	m2d::EmbedLayout_c layout;    // 0x070
	nw4r::lyt::Pane    *rootPane; // 0x208

	nw4r::lyt::TextBox *T_itemRest_00; // 0x20C -- Item Textboxes
	nw4r::lyt::TextBox *T_itemRest_01; // 0x210
	nw4r::lyt::TextBox *T_itemRest_02; // 0x214
	nw4r::lyt::TextBox *T_itemRest_06; // 0x218
	nw4r::lyt::TextBox *T_itemRest_04; // 0x21C
	nw4r::lyt::TextBox *T_itemRest_05; // 0x220
	nw4r::lyt::TextBox *T_itemRest_03; // 0x224
	nw4r::lyt::TextBox *T_itemRest_07; // 0x228 -- "x" Textboxes
	nw4r::lyt::TextBox *T_itemRest_08; // 0x22C
	nw4r::lyt::TextBox *T_itemRest_09; // 0x230
	nw4r::lyt::TextBox *T_itemRest_10; // 0x234
	nw4r::lyt::TextBox *T_itemRest_11; // 0x238
	nw4r::lyt::TextBox *T_itemRest_12; // 0x23C
	nw4r::lyt::TextBox *T_itemRest_13; // 0x240

	nw4r::lyt::Picture *P_buttonBaseS_00; // 0x244
	nw4r::lyt::Picture *P_buttonBaseS_01; // 0x248
	nw4r::lyt::Picture *P_buttonBaseS_02; // 0x24C
	nw4r::lyt::Picture *P_buttonBaseS_03; // 0x250
	nw4r::lyt::Picture *P_buttonBaseS_04; // 0x254
	nw4r::lyt::Picture *P_buttonBaseS_05; // 0x258
	nw4r::lyt::Picture *P_buttonBaseS_06; // 0x25C

	bool layoutLoaded;	   // 0x260
	bool visible;		   // 0x261
	bool needsUpdate;	   // 0x262 -- Determines if update() should do anything
	u8   pad;			   // 0x263
	int  powerupCounts[7]; // 0x264 -- These are set by dStockItem_c::storeCountToShadow() (0x807B0340)


	int onCreate();		 // 0x807B2120
	int beforeExecute(); // 0x807B2280
	int onExecute();	 // 0x807B22C0
	int onDraw();		 // 0x807B2320
	int onDelete();		 // 0x807B2360

	bool loadLayout(); // 0x807B21B0 -- Sets up layout data and gets panes in the class
	void update();	   // 0x807B2370 -- Updates powerup count textboxes if needsUpdate is true
};