// =============================================================================
// FUN_00954140
// -----------------------------------------------------------------------------
// Stable ID: aa_00954140
// Address:   0x00954140  (autoassault.exe, image base 0x400000)
// System:    unknown
// Generated: 2026-07-23 from raw capture (scaffold; refine for important units)
// Exactness: Behavior-preserving rewrite of decompiler control flow. Not modernization.
// Bit-for-bit vs retail EXE: DEFERRED (loaded image may differ slightly).
// =============================================================================

// PURPOSE (auto): Scaffold unit for FUN_00954140 @ 0x00954140
// Stable ID: aa_00954140
// Embedded strings (evidence for future rename):
//   - "Current Location: (%0.2f, %0.2f, %0.2f)"
// Readability: control flow preserved from Ghidra decompile; types tentative.

// READABILITY (auto CF):
//  - Body size: ~15 non-empty decompiler lines.
//  - Control keywords: if×2, return×1.
//  - Notable callees: FUN_008f8200, FUN_00954140, Location:, sprintf.
//  - Strings: "Current Location: (%0.2f, %0.2f, %0.2f)".
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

uint32_t /* width from decompiler */ __fastcall FUN_00954140(int param_1)



{

  float *pfVar1;

  char acStack_d8 [212];

  

  if ((*(int *)(param_1 + 0xe98) != 0) && (*(int *)(param_1 + 0xf40) != 0)) {

    pfVar1 = (float *)(**(code **)(*(int *)(*(int *)(*(int *)(*(int *)(param_1 + 0xe98) + 4) + 4) +

                                            4 + *(int *)(param_1 + 0xe98)) + 0x1a0))();

    sprintf(acStack_d8,"Current Location: (%0.2f, %0.2f, %0.2f)",(double)*pfVar1,(double)pfVar1[1],

            (double)pfVar1[2]);

    if (DAT_00d1b8dc != 0) {

      FUN_008f8200();

    }

  }

  return 1;

}
