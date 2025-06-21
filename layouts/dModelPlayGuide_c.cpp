/* MODEL_PLAY_GUIDE
 - Actor ID 733 [KR/TW: 735; CN: 737]
 - Sprite ID N/A
 - Settings Parameters:
	- N/A

 - Profile Struct:	0x80948B10
 - Build Function:	0x80794F90
 - Vtable:			0x80948B70
 - Constructor:		0x80794FC0
 - Destructor:		0x80795010
 - State Init:		N/A
 - Class Instance:	N/A
*/

// Size: 0x210
class dModelPlayGuide_c : public dBase_c {
public:
	m2d::EmbedLayout_c layout; // 0x070
	nw4r::lyt::Pane *rootPane; // 0x208

	bool layoutLoaded; // 0x20C
	u8   pad[3];	   // 0x20D


	int onCreate();		 // 0x80795080
	int beforeExecute(); // 0x807951C0
	int onExecute();	 // 0x80795200
	int onDraw();		 // 0x80795240
	int onDelete();		 // 0x80795280

	bool loadLayout(); // 0x80795100 -- Loads layout data
};