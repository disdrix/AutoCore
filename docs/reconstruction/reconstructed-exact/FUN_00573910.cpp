// =============================================================================
// FUN_00573910  (scaffold twin of InventoryGrid_ScalarDeletingDtor)
// -----------------------------------------------------------------------------
// Stable ID: aa_00573910
// Address:   0x00573910–0x0057392d exclusive (29 B / 0x1D)
// Preferred: InventoryGrid_ScalarDeletingDtor
// Generated: 2026-08-04 WQ8R-E (upgraded from 2026-07-23 scaffold)
// =============================================================================

#include <cstdint>

extern "C" void __thiscall FUN_005725a0(void* self);
extern "C" void operator_delete(void* p);

extern "C" void* __thiscall FUN_00573910(void* self, uint8_t flags)
{
  FUN_005725a0(self);
  if ((flags & 1u) != 0u) {
    operator_delete(self);
  }
  return self;
}
