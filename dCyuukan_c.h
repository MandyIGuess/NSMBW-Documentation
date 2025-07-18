#pragma once
#include <game.h>

/* dCyuukan_c

 - Vtable:			0x80311130
 - Constructor:		0x8008ED70
 - Destructor:		0x8008F0D0
*/

// Size: 0x34
class dCyuukan_c {
public:
	int checkpointID;		 // 0x04 -- ID of the checkpoint (0 = First, 1 = Second). Default value is -1
	Vec playerSpawnPos;		 // 0x08 -- Position of entrance linked to the checkpoint. This does not update if the entrance is moved after getting the checkpoint.
	int direction;			 // 0x14
	u8  currentWorld;		 // 0x18
	u8  currentLevel;		 // 0x19
	u8  currentArea;		 // 0x1A
	u8  currentEntrance;	 // 0x1B
	u8  spawnRescueToad;	 // 0x1C -- Checkpoint was activated during Toad Rescue, with the Toad outside of the block. If true, a (small) Toad will be spawned
	u8  pad[3];				 // 0x1D
	u32 starCoinStatus[3];	 // 0x20 -- CharID of the player who collected a Star Coin. Default value is 4
	u32 checkpointCharID[2]; // 0x2C -- CharID of the player who collected a checkpoint. Default value is 4


	dCyuukan_c();		   // 0x8008ED70
	virtual ~dCyuukan_c(); // 0x8008F0D0

	void clear();			  // 0x8008EDB0 -- Resets all data back to the default values
	bool checkEntry();		  // 0x8008EEC0 -- Checks if the players in the checkpointCharID array are in the game
	void courseIN();		  // 0x8008EE00 -- Runs clear() if the stored data doesn't match the current level data (besides level slots 26 to 32, and 40)
	int  getPlrNo(int index); // 0x8008F070 -- Returns the ID of the player value in checkpointCharID[index]

	bool isCyuukanStart(int playerID, int world, int level);					  // 0x8008F000 -- Checks if the arguments match the stored data, and returns true/false based on that
	void setCyuukanData(int checkpointID, u8 entrance, u8 charID, int direction); // 0x8008EF30 -- Sets data for a given level. This will only work correctly while in the STAGE scene
};