// =============================================================================
// RETIRED scaffold — Named_CalleeOf_Client_SendInventoryUnequip_004ce5c0
// -----------------------------------------------------------------------------
// Stable ID: aa_004ce5c0
// Address:   0x004ce5c0
// Retired:   2026-08-05 MEGA-118
// Reason:    Parent-seed name is incomplete (also called from FUN_008012f0 ×2).
// Canonical: Character_TownInventoryFallback_Inferred
//            docs/reconstruction/reconstructed-exact/Character_TownInventoryFallback_Inferred.cpp
// =============================================================================

#include <cstdint>

// Forward to sealed name (body identical to FUN_004ce5c0).
bool __thiscall Character_TownInventoryFallback_Inferred(int modeHost, int character);

bool __thiscall Named_CalleeOf_Client_SendInventoryUnequip_004ce5c0(int param_1, int param_2)
{
  return Character_TownInventoryFallback_Inferred(param_1, param_2);
}
