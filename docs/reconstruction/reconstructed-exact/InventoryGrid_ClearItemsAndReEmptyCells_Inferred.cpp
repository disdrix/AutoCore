// =============================================================================
// InventoryGrid_ClearItemsAndReEmptyCells_Inferred
// -----------------------------------------------------------------------------
// Purpose:  Tear down every item held in the grid's embedded TraversalLock list,
//           unlock/drain that list, then re-allocate a fully empty cell occupancy
//           buffer (via InventoryGrid_AllocateCellArray_Inferred).
//
// Address:  0x00570f70 – 0x0057100d  (158 B / 0x9E)
// Stable:   aa_00570f70
// Ghidra:   FUN_00570f70
// System:   inventory-transfer
// Wave:     MEGA-090 OWN-ONLY dual (2026-08-05)
//
// Convention: MSVC __fastcall  (InventoryGrid* in ECX); void; bare RET
// Name:       INFERRED — partition hint FreeCellArray is incomplete (body
//             re-allocates empty cells after item teardown; retail symbol open).
//
// Layout:
//   grid+0x28  cell array*          (rewritten by Allocate)
//   grid+0x2c  embedded List host   (TraversalLock family)
//   grid+0x30  List CS  (= list+4)
//   grid+0x54  List lock flag (= list+0x28)
//
// Item payload (IterateNext out-param):
//   vtbl+0x158(0)  detach before destroy
//   +0xa4 == 0  → scalar-deleting dtor (*vtbl)(1)
//   +0xa4 != 0  → FUN_004d4790 queue-for-delete
//
// Twin thin path (no item walk): FUN_00570f50 = RemoveAll + Allocate only.
// Parent complete-dtor: FUN_005725a0 calls this then operator_delete(grid+0x28).
//
// Exactness: Control-flow-preserving rewrite of live decompile + assembly-sealed
//            ECX/EDI split. Not modernization. Runtime/bit-exact: DEFERRED.
// =============================================================================

#include <cstdint>
#include <windows.h>

struct InventoryGrid;
struct ListHost;
struct GridItem;

// Shared list family (dualed / named elsewhere)
void __fastcall List_TraversalLock(ListHost* list);                         // 0x004294f0
// Returns 0=element, 1=end, 0x80070005=lock fail. cursor in/out; payload out.
unsigned __fastcall LockedList_TryAdvanceIterator_Inferred(
    ListHost* list, int** cursor, GridItem** outPayload);                   // 0x004022a0
void __fastcall List_RemoveAll(ListHost* list);                             // 0x004bc580
void __fastcall InventoryGrid_AllocateCellArray_Inferred(InventoryGrid* g); // 0x00570720
void FUN_004d4790(GridItem* item);                                          // queue-for-delete

static constexpr std::uintptr_t kOffEmbeddedList = 0x2c;
static constexpr std::uintptr_t kOffListCs       = 0x04; // relative to list
static constexpr std::uintptr_t kOffListLock     = 0x28; // relative to list
static constexpr std::uintptr_t kOffItemGateA4   = 0xa4;
static constexpr std::uintptr_t kVtblDetach      = 0x158;

/// Clear all grid items and re-empty the cell occupancy array.
/// @param grid  InventoryGrid* (retail this / ECX).
void __fastcall InventoryGrid_ClearItemsAndReEmptyCells_Inferred(InventoryGrid* grid)
{
    auto* const gridBytes = reinterpret_cast<std::uint8_t*>(grid);
    auto* const list = reinterpret_cast<ListHost*>(gridBytes + kOffEmbeddedList);

    int* cursor = nullptr;
    GridItem* item = nullptr;

    List_TraversalLock(list);

    unsigned status =
        LockedList_TryAdvanceIterator_Inferred(list, &cursor, &item);

    while (status == 0) {
        if (item != nullptr) {
            auto* vtbl = *reinterpret_cast<void***>(item);
            // Detach / unbind (arg 0).
            auto detach = reinterpret_cast<void(__thiscall*)(GridItem*, int)>(
                vtbl[kVtblDetach / sizeof(void*)]);
            detach(item, 0);

            const auto gate =
                *reinterpret_cast<std::int32_t*>(
                    reinterpret_cast<std::uint8_t*>(item) + kOffItemGateA4);
            if (gate != 0) {
                FUN_004d4790(item);
            } else {
                auto scalarDtor =
                    reinterpret_cast<void(__thiscall*)(GridItem*, int)>(vtbl[0]);
                scalarDtor(item, 1);
                item = nullptr;
            }
        }
        status = LockedList_TryAdvanceIterator_Inferred(list, &cursor, &item);
    }

    // Inline TraversalUnlock (pair of List_TraversalLock; same as 0x0040c700).
    auto* const listBytes = reinterpret_cast<std::uint8_t*>(list);
    if (*reinterpret_cast<std::uint8_t*>(listBytes + kOffListLock) != 0) {
        *reinterpret_cast<std::uint8_t*>(listBytes + kOffListLock) = 0;
        LeaveCriticalSection(
            reinterpret_cast<LPCRITICAL_SECTION>(listBytes + kOffListCs));
    }

    List_RemoveAll(list);
    InventoryGrid_AllocateCellArray_Inferred(grid);
}
