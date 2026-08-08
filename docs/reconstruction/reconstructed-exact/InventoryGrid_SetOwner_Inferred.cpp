// =============================================================================
// InventoryGrid_SetOwner_Inferred
// -----------------------------------------------------------------------------
// Stable ID: aa_005718a0
// Address:   0x005718a0  (autoassault.exe, image base 0x400000)
// System:    inventory-transfer
// Generated: 2026-08-04 WQ8R-A dual A/B (supersedes scaffold FUN_005718a0.cpp)
// Exactness: Behavior-preserving rewrite of live decompile + read_memory CF.
// Bit-for-bit vs retail EXE: DEFERRED.
// Terminal:  false (no runtime Confirmed)
// =============================================================================
//
// PURPOSE:
//   InventoryGrid vtbl+0x18: bind owner object pointer at grid+0x24, then walk
//   the embedded item list (grid+0x2c) under TraversalLock and call each item's
//   vtbl+0x158(owner) so occupants rebind to the new owner. Unlocks list CS.
//
// ABI (byte-sealed):
//   __thiscall  ECX = InventoryGrid*
//   stack: ownerObject*
//   ret 0x04
//   return void (EAX undefined at RET — decompiler void is display-only)
//
// SEALED formulas / offsets:
//   *(grid+0x24) = owner
//   list = grid+0x2c; CS = grid+0x30; lockFlag = grid+0x54
//   for each item in list: item->vtbl[0x158/4](item, *(grid+0x24))
//
// ODD (preserve): Ghidra reuses the owner stack slot as the list item cursor
// after the store; clean uses a separate cursor — store-before-walk is sealed.
//
// Dual: reviews/A_aa_005718a0_InventoryGrid_SetOwner_Inferred.md
//       reviews/B_aa_005718a0_InventoryGrid_SetOwner_Inferred.md
// =============================================================================

#include <cstdint>
#include <windows.h>

struct InventoryGrid;
struct InventoryItem;

// Embedded list at grid+0x2c — TraversalLock family
extern "C" void __fastcall FUN_004294f0(void* list); // BeginTraversal / EnterCS
extern "C" unsigned __thiscall FUN_004022a0(
    void* list, int* iterState, void** outItem); // 0 = more, non-0 = end

using ItemBindOwner_t = void(__thiscall*)(InventoryItem* self, void* owner);

void __thiscall InventoryGrid_SetOwner_Inferred(
    InventoryGrid* self,
    void* ownerObject)
{
    auto* base = reinterpret_cast<std::uint8_t*>(self);

    // Store owner first (cargo create + MergeStackQty owner dirty path).
    *reinterpret_cast<void**>(base + 0x24) = ownerObject;

    void* list = base + 0x2c;
    int iterState = 0;
    void* itemCursor = nullptr;

    FUN_004294f0(list);

    // decompiler: FUN_004022a0(&local_4, &param_2) reusing owner stack slot
    unsigned done = FUN_004022a0(list, &iterState, &itemCursor);
    while (done == 0) {
        auto* item = reinterpret_cast<InventoryItem*>(itemCursor);
        void** vtbl = *reinterpret_cast<void***>(item);
        auto bind = reinterpret_cast<ItemBindOwner_t>(vtbl[0x158 / 4]);
        void* owner = *reinterpret_cast<void**>(base + 0x24);
        bind(item, owner);
        done = FUN_004022a0(list, &iterState, &itemCursor);
    }

    if (*reinterpret_cast<char*>(base + 0x54) != 0) {
        *reinterpret_cast<char*>(base + 0x54) = 0;
        LeaveCriticalSection(
            reinterpret_cast<LPCRITICAL_SECTION>(base + 0x30));
    }
}
