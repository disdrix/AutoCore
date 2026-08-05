// =============================================================================
// FUN_00522710  (clean twin → Character_SumCommodityTfidRowCost_Inferred)
// -----------------------------------------------------------------------------
// Stable ID: aa_00522710
// Address:   0x00522710  (autoassault.exe, image base 0x400000)
// System:    inventory-transfer
// Generated: 2026-08-04 WQ8R-J (supersedes 2026-07-23 scaffold paste)
// Canonical: Character_SumCommodityTfidRowCost_Inferred.cpp
// =============================================================================

#include <cstdint>

struct Character;
struct InventoryGrid;
extern "C" void* __thiscall FUN_00571010(InventoryGrid* grid, uint32_t lo, uint32_t hi);

// __thiscall; ret 8; stack arg0 unused
int __thiscall FUN_00522710(Character* self, uint32_t /*param_1_unused*/, int param_2)
{
  auto* tfidRow = reinterpret_cast<const uint32_t*>(static_cast<uintptr_t>(param_2));
  int accum = 1;
  int i = 0;

  auto* mid = *reinterpret_cast<uint8_t**>(reinterpret_cast<uint8_t*>(self) + 0x250);
  auto* grid = *reinterpret_cast<InventoryGrid**>(mid + 0x2B0);

  do {
    uint32_t lo = tfidRow[static_cast<size_t>(i) * 2u];
    uint32_t hi = tfidRow[static_cast<size_t>(i) * 2u + 1u];
    if ((lo & hi) != 0xFFFFFFFFu) {
      void* item = FUN_00571010(grid, lo, hi);
      if (item == nullptr) {
        return accum;
      }
      auto* def = *reinterpret_cast<uint8_t**>(reinterpret_cast<uint8_t*>(item) + 0xA8);
      if (*reinterpret_cast<int*>(def + 0x38) != 0x1A) {
        return accum;
      }
      auto* sub = *reinterpret_cast<uint8_t**>(def + 0x3C);
      accum += static_cast<int>(*(sub + 0x4C8)) + i;
    }
    ++i;
  } while (i <= 4);

  return accum;
}
