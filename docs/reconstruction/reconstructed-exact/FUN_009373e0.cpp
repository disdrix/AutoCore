// =============================================================================
// FUN_009373e0
// -----------------------------------------------------------------------------
// Stable ID: aa_009373e0
// Address:   0x009373e0  (autoassault.exe, image base 0x400000)
// System:    unknown
// Generated: 2026-07-23 from raw capture (scaffold; refine for important units)
// Exactness: Behavior-preserving rewrite of decompiler control flow. Not modernization.
// Bit-for-bit vs retail EXE: DEFERRED (loaded image may differ slightly).
// =============================================================================

// PURPOSE (auto): Scaffold unit for FUN_009373e0 @ 0x009373e0
// Stable ID: aa_009373e0
// No high-value strings recovered; name via xrefs/callers in follow-up.
// Readability: control flow preserved from Ghidra decompile; types tentative.

// READABILITY (auto CF):
//  - Body size: ~17 non-empty decompiler lines.
//  - Control keywords: if×2, return×2.
//  - Notable callees: FUN_007fef20, FUN_008aa4b0, FUN_009373e0, VehicleEntity_SetHandbrake, VehicleEntity_SetLongitudinalInput, VehicleEntity_SetSteerInput.
//  - Return sites: 2.

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

void FUN_009373e0(void)



{

  int unaff_EDI;

  

  if ((*(int **)(unaff_EDI + 0xf40) != (int *)0x0) &&

     (**(int **)(unaff_EDI + 0xf40) == *(int *)(unaff_EDI + 0xf38))) {

    FUN_007fef20(10,0,0);

    FUN_008aa4b0();

    if ((*(int *)(unaff_EDI + 0xe98) != 0) && (*(int *)(*(int *)(unaff_EDI + 0xe98) + 0x250) != 0))

    {

      VehicleEntity_SetLongitudinalInput(0);

      VehicleEntity_SetSteerInput(0);

      VehicleEntity_SetHandbrake();

      return;

    }

  }

  return;

}
