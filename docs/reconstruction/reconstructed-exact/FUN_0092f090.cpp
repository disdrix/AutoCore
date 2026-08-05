// =============================================================================
// FUN_0092f090
// -----------------------------------------------------------------------------
// Stable ID: aa_0092f090
// Address:   0x0092f090  (autoassault.exe, image base 0x400000)
// System:    unknown
// Generated: 2026-07-23 from raw capture (scaffold; refine for important units)
// Exactness: Behavior-preserving rewrite of decompiler control flow. Not modernization.
// Bit-for-bit vs retail EXE: DEFERRED (loaded image may differ slightly).
// =============================================================================

// PURPOSE (auto): Scaffold unit for FUN_0092f090 @ 0x0092f090
// Stable ID: aa_0092f090
// No high-value strings recovered; name via xrefs/callers in follow-up.
// Readability: control flow preserved from Ghidra decompile; types tentative.

// READABILITY (auto CF):
//  - Body size: ~10 non-empty decompiler lines.
//  - Control keywords: if×1, return×1.
//  - Notable callees: FUN_0092f090, VehicleEntity_SetHandbrake, VehicleEntity_SetLongitudinalInput, VehicleEntity_SetSteerInput.
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

void FUN_0092f090(void)



{

  int unaff_ESI;

  

  if ((*(int *)(unaff_ESI + 0xe98) != 0) && (*(int *)(*(int *)(unaff_ESI + 0xe98) + 0x250) != 0)) {

    VehicleEntity_SetLongitudinalInput(0);

    VehicleEntity_SetSteerInput(0);

    VehicleEntity_SetHandbrake(1);

  }

  return;

}
