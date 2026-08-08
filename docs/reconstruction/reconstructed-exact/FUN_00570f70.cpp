// =============================================================================
// FUN_00570f70  (scaffold twin → see named clean)
// -----------------------------------------------------------------------------
// Stable ID: aa_00570f70
// Address:   0x00570f70  (autoassault.exe, image base 0x400000)
// Named:     InventoryGrid_ClearItemsAndReEmptyCells_Inferred
// System:    inventory-transfer
// Wave:      MEGA-090 (2026-08-05) — supersedes 2026-07-23 scaffold
// Exactness: Behavior-preserving; prefer named clean for ports.
// =============================================================================

// Canonical implementation lives in:
//   InventoryGrid_ClearItemsAndReEmptyCells_Inferred.cpp
//
// This twin retains the Ghidra symbol for path stability with older indexes.

#include <cstdint>
#include <windows.h>

struct InventoryGrid;

void __fastcall List_TraversalLock(void* list);
unsigned __fastcall LockedList_TryAdvanceIterator_Inferred(
    void* list, int** cursor, int** outPayload);
void __fastcall List_RemoveAll(void* list);
void __fastcall InventoryGrid_AllocateCellArray_Inferred(void* grid);
void FUN_004d4790(int* item);

void __fastcall FUN_00570f70(void* param_1)
{
    int* piVar1;
    int iVar2;
    int* local_8;
    unsigned local_4;

    void* list = reinterpret_cast<std::uint8_t*>(param_1) + 0x2c;

    local_4 = 0;
    List_TraversalLock(list);
    iVar2 = static_cast<int>(
        LockedList_TryAdvanceIterator_Inferred(
            list,
            reinterpret_cast<int**>(&local_4),
            &local_8));
    piVar1 = local_8;
    while (local_8 = piVar1, iVar2 == 0) {
        if (piVar1 != nullptr) {
            (**(void(__thiscall***)(int*, int))(*piVar1 + 0x158))(piVar1, 0);
            if (piVar1[0x29] == 0) {
                (**(void(__thiscall***)(int*, int))(*piVar1))(piVar1, 1);
                local_8 = nullptr;
            } else {
                FUN_004d4790(piVar1);
            }
        }
        iVar2 = static_cast<int>(
            LockedList_TryAdvanceIterator_Inferred(
                list,
                reinterpret_cast<int**>(&local_4),
                &local_8));
        piVar1 = local_8;
    }
    if (*reinterpret_cast<char*>(reinterpret_cast<std::uint8_t*>(param_1) + 0x54) !=
        '\0') {
        *reinterpret_cast<std::uint8_t*>(
            reinterpret_cast<std::uint8_t*>(param_1) + 0x54) = 0;
        LeaveCriticalSection(reinterpret_cast<LPCRITICAL_SECTION>(
            reinterpret_cast<std::uint8_t*>(param_1) + 0x30));
    }
    List_RemoveAll(list);
    InventoryGrid_AllocateCellArray_Inferred(param_1);
}
