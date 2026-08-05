// =============================================================================
// CVOGObjectiveRequirement_Collect_Action  (was FUN_00611f20)
// -----------------------------------------------------------------------------
// Address:  0x00611f20
// Stable:   aa_00611f20
// System:   missions-progression
//
// eventType (param_4):
//   0 / null: on-death optional loot (OptionalDropPercent) → GiveItemByCbid
//   1: inventory change signal using live cargo count
//
// Cargo: character+0x250 vehicle; grid at vehicle+0x2b0 (same type-1 cargo).
// Count: InventoryGrid_CountItemsByCbid @ 0x005711c0 (thiscall on grid).
// Decompiler often flattens ECX — raw shows FUN_005711c0(cbid, 0) with grid in ECX.
//
// Exactness: branch structure from Ghidra 2026-07-29. Full convoy/template edges
// remain in raw capture; this clean documents the sealed cargo bridge + dual events.
// Dual: reviews/A|B_aa_00611f20_CVOGObjectiveRequirement_Collect_Action.md
// =============================================================================

#include <cstdint>

extern int __thiscall InventoryGrid_CountItemsByCbid(void* grid, int cbid, char includeFlagged);
extern int* CVOGReaction_GiveItemByCbid(int cbid);
extern unsigned FUN_004d2820(void* item, void* pos, int a, int b);
extern unsigned FUN_007a4480(int level, const char* fmt, ...);
extern void* CNDHash_LookupByKey(void* hash, unsigned key);
extern float g_flZero;

static void* cargo_grid(int character)
{
    int vehicle = *(int*)(character + 0x250);
    if (vehicle == 0) {
        return nullptr;
    }
    int grid = *(int*)(vehicle + 0x2b0);
    return grid ? (void*)grid : nullptr;
}

// Returns low-byte 1 when inventory-event progress should fire; kill path returns 0-ish
// after side effects (matches decompiler masking patterns).
unsigned __thiscall CVOGObjectiveRequirement_Collect_Action(
    int* req,
    int character,
    unsigned /*p3*/,
    int eventType,
    float eventArgA,
    float eventArgB,
    unsigned /*p7*/,
    int* actor)
{
    void* grid = cargo_grid(character);
    int itemCbid = req[4];
    int numToCollect = req[5];

    // ----- Inventory-change event (param_4 == 1) -----
    if (eventType == 1) {
        if (grid == nullptr) {
            return 0;
        }
        int count = InventoryGrid_CountItemsByCbid(grid, itemCbid, 0);
        int remaining = count - (int)eventArgB;
        // eventArgA carries item id on this path; must match collect CBID
        if (((int)eventArgA == itemCbid) && (remaining < numToCollect)) {
            return 1;
        }
        return 0;
    }

    // ----- Death / loot event -----
    // Observable gates (full CF in raw):
    //  - optional level range req[0x17..0x18] when flag req[0x16]
    //  - TargetIsPlayer (+0x19) race/class bitmasks vs actor
    //  - optional target CBID list [req+8) count req[7]
    //  - skip spawn if CountItemsByCbid already >= need
    //  - OptionalDropPercent float at req[0x12] vs random table
    //  - GiveItemByCbid(itemCbid) + FUN_004d2820 place; convoy loop if flag
    if (grid != nullptr) {
        int held = InventoryGrid_CountItemsByCbid(grid, itemCbid, 0);
        if (held >= numToCollect) {
            return 0;
        }
    }
    (void)actor;
    (void)g_flZero;
    (void)CVOGReaction_GiveItemByCbid;
    (void)FUN_004d2820;
    (void)FUN_007a4480;
    (void)CNDHash_LookupByKey;
    // Full spawn/convoy body: see raw aa_00611f20_FUN_00611f20.md (immutable industrial).
    return 0;
}
