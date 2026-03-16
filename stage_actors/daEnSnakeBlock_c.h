#pragma once
#include <game.h>
#include <utility/dHeapAllocator_c.h>

/* WARNING: All names are unofficial */

/* EN_SNAKEBLOCK
 - Actor ID 500 [KR/TW: 500; CN: 500]

 - Profile Struct:  0x80B090E0
 - Class Init:      0x80AA67E0
 - Vtable:          0x80B09138
 - Constructor:     0x80AA67E0
 - Destructor:      0x80AA8F20
 - Static Init:     0x80AA8FC0

 - Sprite ID 166
 - Sprite File Table: 0x80319D60
 - Sprite Param:
    - Nybble 5   & 4   : Behavior after reaching the end of the path
    - Nybble 7   & 1   : Unused flag
    - Nybble 8-9 & 0xF : Starting Node ID
    - Nybble 10  & 4   : Movement Speed
    - Nybble 11  & 0xF : Path ID
    - Nybble 12  & 0xF : Length of the snake block (including Head and Tail blocks)
*/

// Size: 0x2B40
class daEnSnakeBlock_c : public dEn_c {
public:
    // Size: 0x1B8
    class dBlock_c {
    public:
        nw4r::g3d::ResFile mResFile; // 0x04
        m3d::mdl_c mModel;           // 0x08
        m3d::anmClr_c mAnmClr;       // 0x48
        m3d::anmTexSrt_c mAnmTexSrt; // 0x74

        int _A0;      // 0xA0 -- Unused, set to 0 in the ctor
        Vec mPos;     // 0xA4 -- Position of the block
        Vec mSpeed;   // 0xB0 -- Used to calculate the new position
        Vec mLastPos; // 0xBC -- Previous block position

        Physics mBgCtr;            // 0xC8
        int mTravelInfoIdx;        // 0x1AC -- Index in the "travelInfo" that this block will read from
        daEnSnakeBlock_c *mpOwner; // 0x1B0

        short _1B4; // 0x1B4 -- Unused, set to 0 in the ctor
        u8 _pad[2];

        dBlock_c();          // 0x80AA6960
        virtual ~dBlock_c(); // 0x80AA6A20

        void createMdl(dHeapAllocator_c *alloc); // 0x80AA6B70
        void doDelete();                         // 0x80AA6D00 -- Removes the model and anims

        void calcAnm();                   // 0x80AA6D70 -- Processes CLR and SRT anims
        void setAnmClr(const char *name); // 0x80AA6DC0 -- Binds a new CLR anim

        void draw(Vec pos); // 0x80AA6E40

        void initBgCtr(daEnSnakeBlock_c *owner, Vec *blockPos); // 0x80AA6F10 -- Sets up the block collision
        void calcBgCtr();                                       // 0x80AA6FE0 -- Updates collision offset

        void setFallCollapse();             // 0x80AA7060 -- Increments the Y speed of the block as it falls
        void calcCollapse1(u8 *travelInfo); // 0x80AA7090 -- Updates the block position for Collapse1 behavior
    };

    // Size: 0x1BC
    class dCtrlBlock_c : public dBlock_c {
    public:
        Vec mSnakeSpeed; // 0x1B8 -- Movement speed from the Snake Block spritedata

        dCtrlBlock_c();          // 0x80aa6890
        virtual ~dCtrlBlock_c(); // 0x80aa6ac0

        bool calcPos(u8 *travelInfo);       // 0x80AA7320 -- Updates the position, returns true if the block has moved at least one tile
        bool calcTravelPos(u8 *travelInfo); // 0x80AA73E0 -- Updates the position based on the travelinfo
        
    };

    dHeapAllocator_c mAllocator; // 0x524

    dCtrlBlock_c mHead;   // 0x540 -- Head of the block chain
    dCtrlBlock_c mTail;   // 0x6FC -- Tail of the block chain
    dBlock_c mBlocks[20]; // 0x8B8 -- Inside blocks in the chain

    int mBlockNum;    // 0x2B18 -- Total number of blocks in the chain (spritedata value + 2)
    u8 *mpTravelInfo; // 0x2B1C -- Containing info about the Snake's path
    int mTravelLen;   // 0x2B20 -- Length of `mpTravelInfo`
    short mShakeTime; // 0x2B24 -- Duration of the `Shake` state. Set to 0x3C
    u8 _pad[2];

    dStateBase_c *mpStopState; // 0x2B28 -- Determines the stopping behavior
    int _2B2C;                 // 0x2B2C -- Unused flag read from spritedata. Might've determined if the Snake was icy?
    int mCollapse2Idx;         // 0x2B30 -- mBlockNum << 3
    int mCreateAnmBlockIdx;    // 0x2B34 -- Index of the block currently receiving the "create" anim
    int mCreateAnmBlockNum;    // 0x2B38 -- Total number of blocks that can have "create" anim
    u8 _pad[4];

    daEnSnakeBlock_c();  // 0x80AA67E0
    ~daEnSnakeBlock_c(); // 0x80AA8F20

    int onCreate();  // 0x80AA7470
    int onDelete();  // 0x80AA7670
    int onExecute(); // 0x80AA7520
    int onDraw();    // 0x80AA75A0

    void willBeDeleted(); // 0x80AA7660 -- Dummy

    void initBlock();     // 0x80AA76D0 -- Calls `createMdl()` and `initTravelInfo()`
    void initBlockPath(); // 0x80AA7730 -- Sets Snake onto the path and inits other data

    void calcAnm();     // 0x80AA7930 -- Processes all block anims
    void createMdl();   // 0x80AA79A0 -- Calls `createMdl()` for all blocks
    void deleteBlock(); // 0x80aa7a20 -- Calls `doDelete()` for all blocks

    void setStopState(); // 0x80AA7A90 -- Sets `mpStopState` to a indexed value from `sc_stopStates`

    void calcBgCtr();      // 0x80AA7AB0 -- Updates block collision
    void initTravelInfo(); // 0x80AA7B30 -- Initializes `mpTravelInfo`

    void setBlockPos(); // 0x80AA8170 -- Updates block positions
    void setActorPos(); // 0x80aa8270 -- Sets position of the actor to the Head block position

    bool chkCollapseDelete(); // 0x80AA82C0 -- Returns if the Tail is below the screen edge (meaning the collapse has ended, and the actor can be deleted)
    bool chkOffScreen();      // 0x80AA8310 -- Returns if the Snake Block is far past the right edge of the screen (used to delete it)

    static void callBackF(dStageActor_c *, dStageActor_c *); // 0x80AA7220 -- Foot collision callback, begins moving the Snake if standing on it
    static void callBackH(dStageActor_c *, dStageActor_c *); // 0x80AA7300 -- Dummy
    static void callBackW(dStageActor_c *, dStageActor_c *); // 0x80AA7310 -- Dummy

    static float sc_snakeSpeeds[4];     // 0x80AD4724 -- Movement speeds for the Snake Block
    static dStateBase_c *sc_stopStates; // 0x80B09120 -- Array of different stopping behavior states
    static Vec2 sc_ctrlPosMods[5];      // 0x80B1B380 -- Pos modifiers for the Head/Tail blocks. Indexed by a byte from `mpTravelInfo`
    static int sc_glbSnakeNum;          // 0x80B1B3A8 -- Total number of initialized Snake Blocks
    static Vec2 sc_collapseSpeeds[5];   // 0x80B1B570 -- Falling speeds for blocks during the Collapse1 behavior

    USING_STATES(daEnSnakeBlock_c);
    REF_NINTENDO_STATE(Wait);      // 0x80B1B3B8 -- Initialize: 0x80AA83B0; Execute: 0x80AA83D0; Finalize: 0x80AA83C0
    REF_NINTENDO_STATE(Move);      // 0x80B1B3F8 -- Initialize: 0x80AA83E0; Execute: 0x80AA8540; Finalize: 0x80AA8530
    REF_NINTENDO_STATE(Shake);     // 0x80B1B438 -- Initialize: 0x80AA8720; Execute: 0x80AA87F0; Finalize: 0x80AA87E0
    REF_NINTENDO_STATE(Collapse1); // 0x80B1B478 -- Initialize: 0x80AA88F0; Execute: 0x80AA8A90; Finalize: 0x80AA8A80
    REF_NINTENDO_STATE(Collapse2); // 0x80B1B4B8 -- Initialize: 0x80AA8B30; Execute: 0x80AA8BA0; Finalize: 0x80AA8B90
    REF_NINTENDO_STATE(Collapse3); // 0x80B1B4F8 -- Initialize: 0x80AA8D50; Execute: 0x80AA8DC0; Finalize: 0x80AA8DB0
    REF_NINTENDO_STATE(Stop);      // 0x80B1B538 -- Initialize: 0x80AA8820; Execute: 0x80AA88E0; Finalize: 0x80AA88D0
};