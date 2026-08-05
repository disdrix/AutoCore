// =============================================================================
// InventoryGrid_FindItemByCbid  (was FUN_005710c0)
// -----------------------------------------------------------------------------
// Address:  0x005710c0  (autoassault.exe, image base 0x400000)
// Stable:   aa_005710c0
// Systems:  inventory-transfer
//
// Purpose: First-fit walk of items on an inventory grid matching clonebase CBID
//          (*(item+0xA8)+0x34). Optional stack-capacity gate for merge-into-
//          existing. NOT instance-COID lookup (that is FUN_00571010).
//
// Flag bit 19 at item+0x17C (mask 0x80000) = Broken (cross-seal aa_005711c0):
//   when skipStackGate==0, broken stacks are skipped.
//
// Max stack (when skipStackGate==0):
//   clonebase+0x38 == 4 → load 999999, then compare uses (max & 0xFFFF) = 16959
//   else *(u16*)(*(clonebase+0x3C)+0x4BA); if 0 → 200
//   accept if qty(vtbl+0x25C) + addQty <= (max & 0xFFFF)
//
// Helpers: List_TraversalLock (FUN_004294f0) on grid+0x2C,
//          List_IterateNext (FUN_004022a0).
// Exactness: Ghidra decompile + read_memory 2026-07-29. Duals A/B + a_005710c0.md.
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
int* __thiscall InventoryGrid_FindItemByCbid(
    void* grid,
    int itemCbid,
    char skipStackGate,
    std::uint16_t addQty)
{
    int* item = nullptr;
    std::uint32_t iterCursor = 0;
    void* list = reinterpret_cast<char*>(grid) + 0x2C;

    FUN_004294f0(list);
    int done = static_cast<int>(
        FUN_004022a0(list, reinterpret_cast<void**>(&iterCursor), &item));

    do {
        if (done != 0) {
            InventoryGrid_TraversalUnlock(grid);
            return nullptr;
        }

        if (item != nullptr) {
            int cb = item[0x2a]; // item + 0xA8 → clonebase
            if (*(int*)(cb + 0x34) == itemCbid) {
                if (skipStackGate != '\0') {
                    InventoryGrid_TraversalUnlock(grid);
                    return item;
                }

                // Broken bit 19 @ item+0x17C (object[0x5f])
                if ((((std::uint32_t)item[0x5f] >> 0x13) & 1) == 0) {
                    std::uint32_t maxStack;
                    if (*(int*)(cb + 0x38) == 4) {
                        maxStack = 999999;
                    } else {
                        std::uint16_t field =
                            *reinterpret_cast<std::uint16_t*>(*(int*)(cb + 0x3c) + 0x4ba);
                        maxStack = field;
                        if (field == 0) {
                            maxStack = 200;
                        }
                    }

                    int qty = (**(int (**)())(*item + 0x25c))();
                    // asm: movzx edx, si  → maxStack & 0xFFFF (type-4 → 16959)
                    if ((int)(qty + (std::uint32_t)addQty) <= (int)(maxStack & 0xffff)) {
                        InventoryGrid_TraversalUnlock(grid);
                        return item;
                    }
                }
            }
        }

        done = static_cast<int>(
            FUN_004022a0(list, reinterpret_cast<void**>(&iterCursor), &item));
    } while (true);
}
