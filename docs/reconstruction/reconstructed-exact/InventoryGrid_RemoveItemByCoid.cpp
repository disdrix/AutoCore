// =============================================================================
// InventoryGrid_RemoveItemByCoid  (FUN_00571d80)
// -----------------------------------------------------------------------------
// Purpose:  Resolve an item in this inventory grid by instance COID
//           (lo/hi dwords), then remove it via InventoryGrid_RemoveItem with
//           removeQty hard-coded to 1 and forceFull taken from the caller.
//
// Address:  0x00571d80  (autoassault.exe, image base 0x400000)
// Stable:   aa_00571d80
// System:   inventory-transfer
// Body:     0x00571d80 – 0x00571da6 (39 bytes)
//
// Convention: MSVC __thiscall (grid in ECX); callee RET 0x0C (3 stack args)
// Decompiler label: FUN_00571d80 (typed void — understates EAX return)
//
// Signature (thiscall + stack) — sealed 2026-08-04 from read_memory:
//   ItemObject* InventoryGrid_RemoveItemByCoid(
//       InventoryGrid* this,   // ECX
//       int32_t        coidLo, // stack0
//       int32_t        coidHi, // stack1
//       int            forceFull); // stack2 → RemoveItem forceFull
//
// Callees (rel32 Confirmed):
//   InventoryGrid_FindItemByCoid  0x00571010
//   InventoryGrid_RemoveItem      0x00571b80  (qty=1, forceFull pass-through)
//
// Callers (sample): Client_RecvInventoryUseItemResponse (force 0),
//   FUN_00810170 (force 1), FUN_00810670 (force from packet flag), FUN_004f8e00.
// Dual: reviews/A|B_aa_00571d80_InventoryGrid_RemoveItemByCoid.md
// Exactness: CF + ABI + rel32 sealed; runtime/diff open.
// =============================================================================

#include <cstdint>

struct InventoryGrid;
struct ItemObject;

// Forward decls of sealed callees
extern "C" ItemObject* __fastcall InventoryGrid_FindItemByCoid(
    InventoryGrid* grid, int32_t coidLo, int32_t coidHi);
extern "C" ItemObject* __fastcall InventoryGrid_RemoveItem(
    InventoryGrid* grid, ItemObject* item, int removeQty, int forceFull);

extern "C" ItemObject* __fastcall InventoryGrid_RemoveItemByCoid(
    InventoryGrid* grid, /*stack*/ int32_t coidLo, int32_t coidHi, int forceFull)
{
    // push 1 @ 0x00571d90 — removeQty is NOT a formal
    ItemObject* item = InventoryGrid_FindItemByCoid(grid, coidLo, coidHi);
    return InventoryGrid_RemoveItem(grid, item, /*removeQty=*/1, forceFull);
}
