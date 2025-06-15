/* WORLD_SELECT_GUIDE
 - Actor ID 690 [KR/TW: 690; CN: 692]
 - Sprite ID N/A
 - Settings Parameters:
	- N/A

 - Profile Struct:	0x8098E948
 - Build Function:	0x8092B3E0
 - Vtable:			0x8098EAF0
 - Constructor:		0x8092B410
 - Destructor:		0x8092B460
 - State Init:		N/A
 - Class Instance:	N/A
*/

// Size: 0x238
class dWorldSelectGuide_c : public dBase_c {
public:
	enum Animation {
		IN_WINDOW = 0,
		OUT_WINDOW
	};

	m2d::EmbedLayout_c layout; // 0x70

	nw4r::lyt::Pane    *rootPane;	   // 0x208
	nw4r::lyt::TextBox *T_worldNum_00; // 0x20C
	nw4r::lyt::Picture *P_pochi_00;    // 0x210 -- D-Pad right
	nw4r::lyt::Picture *P_pochi_01;    // 0x214 -- D-Pad left
	nw4r::lyt::Picture *P_pochi_02;    // 0x218 -- D-Pad up
	nw4r::lyt::Picture *P_pochi_03;    // 0x21C -- D-Pad down
	nw4r::lyt::Pane    *N_wCCGuide_00; // 0x220
	nw4r::lyt::Pane	   *N_title;	   // 0x224

	bool  layoutLoaded; // 0x228
	bool  visible;		// 0x229
	bool  updatePochi;  // 0x22A -- Determines if updatePochi() will return without doing anything
	bool  showPochiUp;  // 0x22B -- If true, P_pochi_02 will be made visible
	int   worldNum;		// 0x22C -- In-game world number, so 8 is World 8
	int   nextWorldNum; // 0x230 -- Also in-game world number
	float titleTransY;	// 0x234 -- Current Y translation of N_title


	int onCreate();		 // 0x8092B4D0
	int beforeExecute(); // 0x8092B6B0
	int onExecute();	 // 0x8092B6F0
	int onDraw();		 // 0x8092B760
	int onDelete();		 // 0x8092B7A0

	bool loadLayout();     // 0x8092B5A0 -- Sets up layout data and animations, gets panes in the class
	void updateWorldNum(); // 0x8092B7B0 -- Updates worldNum to nextWorldNum, then writes worldNum to T_textBox_00
	void updatePochi();    // 0x8092B7E0 -- If updatePochi is true, updates which P_pochi panes are visible
};