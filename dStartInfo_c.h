#pragma once
#include <game.h>
#include "dCyuukan_c.h"

/* dStartInfo_c

 - Vtable:			N/A
 - Constructor:		0x800E3BA0
 - Destructor:		N/A
 - State Init:		N/A
 - Class Instance:	0x80359054 (dInfo_c::m_startInfo)
*/

// Size: 0x35
class dStartInfo_c : public dCyuukan_c {
public:
	bool switchFlag; // 0x34 -- Status of the W3 switch
};