// =============================================================================
// InventoryGrid_RemoveItemAtXY  (FUN_00571db0)
// -----------------------------------------------------------------------------
// Purpose:  Bounds-check grid cell (x,y); load 8-byte COID stamp from cell array;
//           FindItemByCoid → InventoryGrid_RemoveItem(item, removeQty=1, forceFull=0).
//           OOB or missing stamp path returns null without calling remove.
//
// Address:  0x00571db0  (autoassault.exe, image base 0x400000)
// Stable:   aa_00571db0
// System:   inventory-transfer
// Body:     0x00571db0–0x00571e0e (94 B; pad CC after final RET)
//
// Convention: MSVC __thiscall (grid in ECX); callee RET 0x08 (2 stack args)
// Decompiler label: FUN_00571db0
//
// Signature (thiscall + stack) — sealed 2026-08-04 from read_memory:
//   ItemObject* InventoryGrid_RemoveItemAtXY(
//       InventoryGrid* this,  // ECX
//       uint8_t        x,     // stack0 (byte; full dword slot)
//       uint8_t        y);    // stack1
//
// Index (same family as Place/Remove footprint):
//   if x >= width(+0x08) or y >= height(+0x0c): return 0
//   index = height * x + y
//   coidLo = *(i32*)(cells + index*8)
//   coidHi = *(i32*)(cells + index*8 + 4)
//   item   = InventoryGrid_FindItemByCoid(this, coidLo, coidHi)  // 0x00571010
//   return InventoryGrid_RemoveItem(this, item, 1, /*forceFull=*/0)  // 0x00571b80
//
// Stack setup note (bytes): push forceFull=0, push removeQty=1 BEFORE FindItemByCoid;
// Find does RET 8 (cleans COID pair only); Remove does RET 0xC (item+qty+force).
//
// Related: FindItemByCoid 0x00571010, RemoveItem 0x00571b80,
//          RemoveByCoid sibling 0x00571d80 (no XY; forceFull from arg)
// Dual: reviews/A_aa_00571db0_InventoryGrid_RemoveItemAtXY.md
//       reviews/B_aa_00571db0_InventoryGrid_RemoveItemAtXY.md
// Exactness: CF + ABI + index formula sealed; 0 static call xrefs; runtime open.
// =============================================================================

#include <cstdint>

struct InventoryGrid;
struct ItemObject;

// thiscall; RET 8 — sealed sibling aa_00571010
extern "C" ItemObject* __thiscall InventoryGrid_FindItemByCoid(
    InventoryGrid* self, std::uint32_t coidLo, std::uint32_t coidHi);

// thiscall; RET 0xC — sealed sibling aa_00571b80
extern "C" ItemObject* __thiscall InventoryGrid_RemoveItem(
    InventoryGrid* self, ItemObject* item, int removeQty, char forceFull);

/// Remove the item occupying cell (x,y), peel-or-full via RemoveItem(...,1,0).
/// @return RemoveItem result (item* full remove; nullptr peel/gate/OOB).
ItemObject* __thiscall InventoryGrid_RemoveItemAtXY(InventoryGrid* self,
                                                    std::uint8_t x,
                                                    std::uint8_t y)
{
    auto* const grid = reinterpret_cast<std::uint8_t*>(self);
    const int width  = *reinterpret_cast<int*>(grid + 0x08);
    const int height = *reinterpret_cast<int*>(grid + 0x0c);

    if (static_cast<int>(x) >= width) {
        return nullptr;
    }
    if (static_cast<int>(y) >= height) {
        return nullptr;
    }

    const int index = height * static_cast<int>(x) + static_cast<int>(y);
    auto* const cells = *reinterpret_cast<std::uint8_t**>(grid + 0x28);
    const auto coidLo =
        *reinterpret_cast<std::uint32_t*>(cells + index * 8);
    const auto coidHi =
        *reinterpret_cast<std::uint32_t*>(cells + index * 8 + 4);

    ItemObject* item = InventoryGrid_FindItemByCoid(self, coidLo, coidHi);
    return InventoryGrid_RemoveItem(self, item, /*removeQty=*/1, /*forceFull=*/0);
}
