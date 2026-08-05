// =============================================================================
// InventoryGrid_ContainsItem  (FUN_00571b60)
// -----------------------------------------------------------------------------
// Stable ID: aa_00571b60
// Address:   0x00571b60  (autoassault.exe, image base 0x400000)
// System:    inventory-transfer
// Generated: 2026-07-29 dual A/B + read_memory byte seal
// Exactness: Behavior-preserving rewrite of sealed bytes. Not modernization.
// Bit-for-bit vs retail EXE: DEFERRED.
// =============================================================================

// PURPOSE:
//   Return whether item* is already present in this grid's embedded item list
//   at offset +0x2c. Thin null-check + tail into FUN_00415c00 (list contains).
//
//   NOT a cell-array occupancy / CanPlace check. Callers that need
//   "already at (X,Y)" combine this with item vfuncs +0x250/+0x254.

// ABI (MSVC thiscall, sealed from bytes at 0x00571b60):
//   ECX     = InventoryGrid* this
//   stack0  = ItemObject* item
//   returns AL bool (1 = found, 0 = null or not in list)
//   epilogue RET 4  (C2 04 00)

// BYTE BODY (read_memory 2026-07-29):
//   8B 44 24 04  85 C0  75 05  32 C0  C2 04 00
//   89 44 24 04  83 C1 2C  E9 87 40 EA FF   ; jmp FUN_00415c00

#include <cstdint>

// Forward: TraversalLock list membership (owned elsewhere; VA 0x00415c00).
// this = list subobject (grid+0x2c), stack arg = item pointer.
extern "C" std::uint8_t __thiscall FUN_00415c00(void* list, void* item);

// InventoryGrid layout fragment (from sibling duals):
//   +0x28  cell array base (8 B COID pairs) — NOT used here
//   +0x2c  embedded item list (FUN_00566f00 attach target; TraversalLock list)

extern "C" std::uint8_t __thiscall InventoryGrid_ContainsItem(
    void* grid,  // ECX
    void* item)  // [esp+4]
{
    if (item == nullptr) {
        return 0;
    }
    // Tail-equivalent: this = grid+0x2c, arg = item
    void* list = static_cast<char*>(grid) + 0x2c;
    return FUN_00415c00(list, item);
}

// Ghidra name alias
extern "C" std::uint8_t __thiscall FUN_00571b60(void* grid, void* item)
{
    return InventoryGrid_ContainsItem(grid, item);
}
