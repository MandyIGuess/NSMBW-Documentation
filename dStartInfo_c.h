#pragma once
#include <game.h>
#include "dCyuukan_c.h"

/* dStartInfo_c

 - Constructor:		0x800E3BA0
 - Class Instance:	0x80359054 (dInfo_c::m_startInfo)
*/

// Size: 0x35
class dStartInfo_c : public dCyuukan_c {
public:
	bool switchFlag; // 0x34 -- Status of the W3 switch


	dStartInfo_c(); // 0x800E3BA0

	static dStartInfo_c *instance; // 0x80359054 -- dInfo_c::m_startInfo
};