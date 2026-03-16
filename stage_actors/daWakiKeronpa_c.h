#pragma once
#include <game.h>

/* WARNING: All names are unofficial */

/* WAKI_KERONPA
 - Actor ID 317 [KR/TW: 317; CN: 317]

 - Profile Struct:	0x8097E760
 - Build Function:	0x808B5A20
 - Vtable:			0x8097E76C
 - Constructor:		0x808B5A20
 - Destructor:		0x808B5EC0
 - State Init:		N/A

 - Sprite ID 217
 - Sprite File Table: 0x80428368
 - Sprite Param:
	- Nybble 10 & 1   : Unused flag, does nothing
	- Nybble 11 & 0xF : Delay until a new EN_KERONPA can be created. Each value is +60 frames
	- Nybble 12 & 0xF : Location ID that a player needs to occupy for the spawner to activate
*/

// Size: 0x3A0
class daWakiKeronpa_c : public dStageActor_c {
public:
	int locationID;		 // 0x394
	u32 keronpaUniqueID; // 0x398 -- Unique ID of the created EN_KERONPA actor
	short respawnTimer;  // 0x39C -- Set to `spawnDelay`, decremented while waiting to create a new actor
	short spawnDelay;	 // 0x39E -- Nybble 11 value, used to reset `respawnTimer`


	~daWakiKeronpa_c(); // 0x808B5EC0

	int onCreate();	 // 0x808B5A80
	int onExecute(); // 0x808B5AE0
	int onDraw();	 // 0x808B5B10
	int onDelete();	 // 0x808B5B30

	void actualExecute();  // 0x808B5B40 -- Called by onExecute(), calls processSpawning() or deletes itself, depending on what getPlayer() returns

	void processSpawning(dAcPy_c *player); // 0x808B5B90 -- Handles decrementing the timer, and calling the function to create an EN_KERONPA actor
	bool withinSpawnArea(dAcPy_c *player); // 0x808B5C50 -- Returns if a player is within the spawning Location
	dAcPy_c *getPlayer();				   // 0x808B5D60 -- Returns the first player that exists within the same zone as the actor

	int createKeronpa(); // 0x808B5DD0 -- Creates an EN_KERONPA actor, and returns its uniqueID

	static daWakiKeronpa_c *build(); // 0x808B5A20
};