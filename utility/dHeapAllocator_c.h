#pragma once
#include <game.h>

/* dHeapAllocator_c

 - Vtable:			0x8030F2F8
 - Constructor:		0x80069020
 - Destructor:		0x80069060
*/

// Size: 0x1C
class dHeapAllocator_c : public mHeapAllocator_c {
public:
	dHeapAllocator_c();			 // 0x80069020
	virtual ~dHeapAllocator_c(); // 0x80069060

	void createFrmHeap(s32 size, void *heap, const char *name, int align); // 0x800690C0
	u32  adjustFrmHeap();												   // 0x800690E0
};