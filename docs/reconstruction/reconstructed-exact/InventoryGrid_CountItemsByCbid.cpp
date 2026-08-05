// =============================================================================
// InventoryGrid_CountItemsByCbid  (was FUN_005711c0)
// -----------------------------------------------------------------------------
// Address:  0x005711c0  (autoassault.exe, image base 0x400000)
// Stable:   aa_005711c0
// Systems:  inventory-transfer; missions-progression (collect bridge)
//
// Purpose: Sum stack quantities of all grid items whose clonebase CBID matches.
// Collect objectives call this on cargo grid (char+0x250 → +0x2b0) with the
// requirement's item CBID (req+0x10) to compute progress vs NumToCollect (req+0x14).
//
// Flag bit 19 at item+0x17c (mask 0x80000) = Broken (sealed 2026-07-29 residual):
//   "Broken: " loot/UI prefix; i_g_2d_overlay_broken.dds; setter FUN_00513de0.
// When includeBroken==0 (all Collect/Deliver call sites), broken stacks are omitted.
//
// Helpers: List_TraversalLock (FUN_004294f0), List_IterateNext (FUN_004022a0).
// Exactness: Ghidra decompile 2026-07-29. Duals A/B + residual a_005711c0.md.
// =============================================================================

#include <cstdint>
#include <windows.h>

// List_TraversalLock @ 0x004294f0 — "List Error! TraversalLock Call Stack"
extern void FUN_004294f0();
// List_IterateNext @ 0x004022a0 — node walk under TraversalLock (0=more, 1=done)
extern int  FUN_004022a0(void* iterState, int** outObj);

// thiscall: ECX = InventoryGrid*
int __thiscall InventoryGrid_CountItemsByCbid(void* grid, int itemCbid, char includeBroken)
{
    int total = 0;
    int* pObj = nullptr;
    std::uint32_t iterState = 0;

    FUN_004294f0(); // List_TraversalLock
    int done = FUN_004022a0(&iterState, &pObj);
    while (done == 0) {
        // object[0x5f] == item+0x17c flags; bit 19 (>>0x13) = Broken
        if ((pObj != nullptr) &&
            (*(int*)(pObj[0x2a] + 0x34) == itemCbid) &&
            ((includeBroken != '\0') || ((((std::uint32_t)pObj[0x5f] >> 0x13) & 1) == 0)))
        {
            int qty = (**(int (**)())(*pObj + 0x25c))();
            total = total + qty;
        }
        done = FUN_004022a0(&iterState, &pObj);
    }

    // grid+0x54 lock held flag; CS at grid+0x30 (paired TraversalUnlock)
    if (*(char*)((int)grid + 0x54) != '\0') {
        *(char*)((int)grid + 0x54) = 0;
        LeaveCriticalSection((LPCRITICAL_SECTION)((int)grid + 0x30));
    }
    return total;
}
