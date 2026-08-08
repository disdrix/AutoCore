// =============================================================================
// Character_SumCommodityTfidRowCost_Inferred
// -----------------------------------------------------------------------------
// Stable ID: aa_00522710
// Address:   0x00522710  (autoassault.exe, image base 0x400000)
// System:    inventory-transfer
// Ghidra:    FUN_00522710
// Generated: 2026-08-04 WQ8R-J dual seal (from raw + read_memory)
// Exactness: Behavior-preserving; not modernization.
// Bit-for-bit vs retail EXE: DEFERRED
// =============================================================================
//
// PURPOSE: Walk up to 5 COID/TFID slots on a row; resolve each via cargo
// InventoryGrid_FindItemByCoid; require CloneBase type Commodity (0x1A);
// accumulate slot cost = Σ(subblob[0x4C8] + index) with base accum=1.
// First missing or non-commodity item ends the walk early.
//
// ABI: __thiscall (ECX = Character*); two stack dwords; ret 8.
//      Stack arg0 is unused in the body (callers still pass tier/row index).
//
// REJECT: scaffold Named_CalleeOf_…_00522710

#include <cstdint>

// Forward decls (owned elsewhere)
struct Character;
struct InventoryGrid;
// InventoryGrid_FindItemByCoid @ 0x00571010 — thiscall grid, ret 8
extern "C" void* __thiscall InventoryGrid_FindItemByCoid(InventoryGrid* grid,
                                                        uint32_t coidLo,
                                                        uint32_t coidHi);

// CloneBaseObjectType.Commodity = 26 = 0x1A
static constexpr int kCloneTypeCommodity = 0x1A;

int __thiscall Character_SumCommodityTfidRowCost_Inferred(
    Character* self,
    uint32_t /*unused_arg*/,
    const uint32_t* tfidRow /* 5 × {lo, hi} */)
{
  int accum = 1;
  int i = 0;

  // grid = *(*(self + 0x250) + 0x2B0)
  auto* mid = *reinterpret_cast<uint8_t**>(reinterpret_cast<uint8_t*>(self) + 0x250);
  auto* grid = *reinterpret_cast<InventoryGrid**>(mid + 0x2B0);

  do {
    uint32_t lo = tfidRow[static_cast<size_t>(i) * 2u];
    uint32_t hi = tfidRow[static_cast<size_t>(i) * 2u + 1u];

    // null TFID sentinel: both dwords 0xFFFFFFFF ⇔ (lo & hi) == 0xFFFFFFFF
    if ((lo & hi) != 0xFFFFFFFFu) {
      void* item = InventoryGrid_FindItemByCoid(grid, lo, hi);
      if (item == nullptr) {
        return accum;
      }

      auto* def = *reinterpret_cast<uint8_t**>(reinterpret_cast<uint8_t*>(item) + 0xA8);
      if (*reinterpret_cast<int*>(def + 0x38) != kCloneTypeCommodity) {
        return accum;
      }

      auto* sub = *reinterpret_cast<uint8_t**>(def + 0x3C);
      uint8_t weight = *(sub + 0x4C8);
      accum += static_cast<int>(weight) + i;
    }

    ++i;
  } while (i <= 4);

  return accum;
}
