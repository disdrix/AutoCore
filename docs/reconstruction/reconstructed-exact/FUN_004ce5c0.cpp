// =============================================================================
// FUN_004ce5c0  →  Character_TownInventoryFallback_Inferred
// -----------------------------------------------------------------------------
// Stable ID: aa_004ce5c0
// Address:   0x004ce5c0–0x004ce5e3  (autoassault.exe, image base 0x400000)
// System:    inventory-transfer
// Generated: 2026-08-05 MEGA-118 (scaffold twin of named clean)
// Exactness: Behavior-preserving rewrite of decompiler control flow.
// Bit-for-bit vs retail EXE: DEFERRED.
// =============================================================================
// Canonical named unit:
//   docs/reconstruction/reconstructed-exact/Character_TownInventoryFallback_Inferred.cpp
//

#include <cstdint>

bool __thiscall FUN_004ce5c0(int param_1, int param_2)
{
  if (param_2 == 0) {
    return false;
  }
  if (*(char *)(param_1 + 0xf5) != '\0') {
    return true;
  }
  return *(char *)(param_1 + 0x7e) != '\0';
}
