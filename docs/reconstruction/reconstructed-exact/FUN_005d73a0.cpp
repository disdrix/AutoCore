// =============================================================================
// FUN_005d73a0
// -----------------------------------------------------------------------------
// Stable ID: aa_005d73a0
// Address:   0x005d73a0  (autoassault.exe, image base 0x400000)
// System:    unknown
// Generated: 2026-07-23 from raw capture (scaffold; refine for important units)
// Exactness: Behavior-preserving rewrite of decompiler control flow. Not modernization.
// Bit-for-bit vs retail EXE: DEFERRED (loaded image may differ slightly).
// =============================================================================

// PURPOSE (auto): Scaffold unit for FUN_005d73a0 @ 0x005d73a0
// Stable ID: aa_005d73a0
// No high-value strings recovered; name via xrefs/callers in follow-up.
// Readability: control flow preserved from Ghidra decompile; types tentative.

// READABILITY (auto CF):
//  - Body size: ~10 non-empty decompiler lines.
//  - Control keywords: return×1.
//  - Notable callees: CVOGHBAIFollowVehicle_FireWeapons, FUN_005cc560, FUN_005d73a0, VehicleEntity_PushDriveAxesToController, VehicleEntity_SetHandbrake, VehicleEntity_SetLongitudinalInput, VehicleEntity_SetSteerInput.
//  - Return sites: 1.

/*
 * Behavioral notes:
 * - Derived from Ghidra decompile; names prefer Ghidra symbols / plate comments.
 * - Remaining FUN_* / DAT_* identifiers are unresolved pending type recovery.
 * - Runtime / differential verification: OPEN unless matrix says otherwise.
 *
 * Readability pass:
 * - undefinedN widths preserved as fixed-width integers where decompiler width is known.
 * - Control flow and call order preserved from authoritative raw.
 */

void FUN_005d73a0(void)



{

  VehicleEntity_SetSteerInput(0);

  VehicleEntity_SetLongitudinalInput(0);

  VehicleEntity_SetHandbrake(1);

  CVOGHBAIFollowVehicle_FireWeapons(0,0);

  VehicleEntity_PushDriveAxesToController();

  FUN_005cc560();

  return;

}
