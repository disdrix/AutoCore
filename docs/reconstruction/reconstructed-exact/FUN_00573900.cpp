// =============================================================================
// FUN_00573900  (scaffold twin of InventoryGrid_SetSecondaryOwner_Inferred)
// -----------------------------------------------------------------------------
// Stable ID: aa_00573900
// Address:   0x00573900–0x00573909 inclusive (10 B / 0x0A)
// Preferred: InventoryGrid_SetSecondaryOwner_Inferred
// Generated: 2026-08-05 MEGA-092
// =============================================================================

#include <cstdint>

extern "C" void __thiscall FUN_00573900(void* self, void* secondaryOwner)
{
  *reinterpret_cast<void**>(reinterpret_cast<std::uint8_t*>(self) + 0x58) =
      secondaryOwner;
}
