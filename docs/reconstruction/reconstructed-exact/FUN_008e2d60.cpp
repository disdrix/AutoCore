// =============================================================================
// FUN_008e2d60  (machine twin)
// -----------------------------------------------------------------------------
// Stable ID: aa_008e2d60
// Address:   0x008e2d60  (autoassault.exe, image base 0x400000)
// System:    inventory-transfer
//
// Canonical named reconstruction:
//   Client_UI_CraftHost_ResetRecipePanel_Inferred.cpp
//
// This twin keeps the Ghidra symbol for tooling; prefer the named unit for port.
// Dual: MEGA-085 2026-08-05
// =============================================================================

#include <cstdint>

// Forward to named body (identical ABI).
void __stdcall Client_UI_CraftHost_ResetRecipePanel_Inferred(void* host);

void __stdcall FUN_008e2d60(void* host) {
  Client_UI_CraftHost_ResetRecipePanel_Inferred(host);
}
