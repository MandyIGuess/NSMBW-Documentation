// Heap Allocator used by some actors, add into your `g3dhax.h` file, below the `mHeapAllocator_c` class

// Size: 0x1C
class dHeapAllocator_c : public mHeapAllocator_c {
public:
	// Constructor:		0x80069020
	// Destructor:		0x80069060
	// Vtable:			0x8030F2F8

	void createFrmHeap(s32 size, void *heap, const char *name, int align); // 0x800690C0 - Newer calls this 'link'
	u32  adjustFrmHeap(); // 0x800690E0 - Newer calls this 'unlink'
};