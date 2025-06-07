/* dStageTimer_c

 - Vtable:			0x8031B358
 - Constructor:		0x800E38E0
 - Destructor:		0x800E3910
 - State Init:		N/A
 - Class Instance:	0x8042A350
*/

/* NOTES:
 - The preciseTime works like so:
   - It takes the time and left-shifts it by 0xC, that way each time unit is now 4096 (adjusted value / original time = 4096)
   - Then, each frame that the timer is allowed to decrement, execute() will subtract 92 from preciseTime
   - After that, preciceTime is adjusted back into the in-game value (preciseTime + 4095 >> 0xC) (4095 is likely added to round it up)
   - This means that the in-game timer will visibly change every 44 frames

 - dStageTimer_c::execute() is called by dLastActorStage_c::execute() (0x80830720)
*/

// Size: 0x10
class dStageTimer_c {
public:
	void *vtable;	  // 0x00
	u32  preciseTime; // 0x04 -- Time value << 0xC
	u16  stageTime;	  // 0x08 -- Time value from the level data
	bool isAmbush;	  // 0x0A -- If enabled, the music will not speed up when the time is below 101 units
	bool isHurryUp;	  // 0x0B -- Set to true if the time is less than 101 units
	bool isPaused;	  // 0x0C -- If enabled, the timer won't be able to decrement
	u8   pad[3];	  // 0x0D

	dStageTimer_c(int time); // 0x800E38E0

	void setTimer(short time); // 0x800E3A00 -- Limits time to 999 units (if above), then sets the stageTime and preciseTime members
	void execute();			   // 0x800E3A20 -- Processes the timer if various conditions are met, triggers music speed-up as well as displaying Time Up layout
	void startTimeUPDisp();	   // 0x800E3B50 -- Displays the Time Up layout

	static dStageTimer_c *createInstance(void *EGG__Heap, int time); // 0x800E3960 -- Creates class, limits time to 999 (if above) units, and passes it to the ctor
	static dStageTimer_c *deleteInstance();							 // 0x800E39D0 -- Checks (twice) if the instance == 0x0, then runs the dtor if not
};