// =============================================================================
// InventoryGrid_FindItemByCoid  (was FUN_00571010)
// -----------------------------------------------------------------------------
// Address:  0x00571010  (autoassault.exe, image base 0x400000)
// Stable:   aa_00571010
// Systems:  inventory-transfer
//
// Purpose: First-fit walk of items on an inventory grid matching instance COID
//          (item+0x160 lo, item+0x164 hi). NOT clonebase-CBID lookup
//          (that is InventoryGrid_FindItemByCbid @ 0x005710c0).
//
// No Broken filter, no stack-capacity gate, no inventory mutation.
//
// Helpers: List_TraversalLock (FUN_004294f0) on grid+0x2C,
//          List_IterateNext (FUN_004022a0).
// Exactness: Ghidra decompile + read_memory 2026-07-29. Duals A/B + a_00571010.md.
// =============================================================================

#include <cstdint>
#include <windows.h>

// List_TraversalLock @ 0x004294f0
// this = list subobject (grid+0x2C); EnterCS(list+4); list+0x28 = held flag
extern void __fastcall FUN_004294f0(void* list);

// List_IterateNext @ 0x004022a0 — 0 = more, nonzero = done / error
// Decompiler often collapses list ECX; raw shows thiscall on list with
// (iterCursor*, outObj*).
extern std::uint32_t __thiscall FUN_004022a0(void* list, void** iterCursor, int** outObj);

static void InventoryGrid_TraversalUnlock(void* grid)
{
    if (*reinterpret_cast<char*>(reinterpret_cast<char*>(grid) + 0x54) != '\0') {
        *reinterpret_cast<char*>(reinterpret_cast<char*>(grid) + 0x54) = 0;
        LeaveCriticalSection(
            reinterpret_cast<LPCRITICAL_SECTION>(reinterpret_cast<char*>(grid) + 0x30));
    }
}

// thiscall: ECX = InventoryGrid*
// ret 0x08 — two stack dwords (coidLo, coidHi)
int* __thiscall InventoryGrid_FindItemByCoid(
    void* grid,
    int coidLo,
    int coidHi)
{
    int* item = nullptr;
    std::uint32_t iterCursor = 0;
    void* list = reinterpret_cast<char*>(grid) + 0x2C;

    FUN_004294f0(list);
    int done = static_cast<int>(
        FUN_004022a0(list, reinterpret_cast<void**>(&iterCursor), &item));

    while (true) {
        if (done != 0) {
            InventoryGrid_TraversalUnlock(grid);
            return nullptr;
        }

        if (item != nullptr
            && item[0x160 / 4] == coidLo
            && item[0x164 / 4] == coidHi) {
            break;
        }

        done = static_cast<int>(
            FUN_004022a0(list, reinterpret_cast<void**>(&iterCursor), &item));
    }

    InventoryGrid_TraversalUnlock(grid);
    return item;
}
