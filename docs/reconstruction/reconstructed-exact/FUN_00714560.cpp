// =============================================================================
// FUN_00714560
// -----------------------------------------------------------------------------
// Stable ID: aa_00714560
// Address:   0x00714560  (autoassault.exe, image base 0x400000)
// System:    unknown
// Generated: 2026-07-23 from raw capture (scaffold; refine for important units)
// Exactness: Behavior-preserving rewrite of decompiler control flow. Not modernization.
// Bit-for-bit vs retail EXE: DEFERRED (loaded image may differ slightly).
// =============================================================================

// PURPOSE (auto): Scaffold unit for FUN_00714560 @ 0x00714560
// Stable ID: aa_00714560
// No high-value strings recovered; name via xrefs/callers in follow-up.
// Readability: control flow preserved from Ghidra decompile; types tentative.

// READABILITY (auto CF):
//  - Body size: ~14 non-empty decompiler lines.
//  - Control keywords: if×1, do×1, while×1, return×1.
//  - Notable callees: FUN_00714560.
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

void FUN_00714560(float *param_1,int param_2,float param_3,float *param_4)



{

  float fVar1;

  

  if (0 < param_2) {

    do {

      fVar1 = *param_1;

      param_1 = param_1 + 1;

      param_2 = param_2 + -1;

      *param_4 = param_3 * fVar1;

      param_4 = param_4 + 1;

    } while (param_2 != 0);

  }

  return;

}
