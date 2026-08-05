// =============================================================================
// FUN_00645230
// -----------------------------------------------------------------------------
// Stable ID: aa_00645230
// Address:   0x00645230  (autoassault.exe, image base 0x400000)
// System:    unknown
// Generated: 2026-07-23 from raw capture (scaffold; refine for important units)
// Exactness: Behavior-preserving rewrite of decompiler control flow. Not modernization.
// Bit-for-bit vs retail EXE: DEFERRED (loaded image may differ slightly).
// =============================================================================

// PURPOSE (auto): Scaffold unit for FUN_00645230 @ 0x00645230
// Stable ID: aa_00645230
// No high-value strings recovered; name via xrefs/callers in follow-up.
// Readability: control flow preserved from Ghidra decompile; types tentative.

// READABILITY (auto CF):
//  - Body size: ~14 non-empty decompiler lines.
//  - Control keywords: return×2, if×1.
//  - Notable callees: ABS×9, FUN_00645230.
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

void __thiscall FUN_00645230(float *param_1,uint8_t *param_2,float *param_3,float param_4)



{

  if ((((ABS(param_1[2] - param_3[2]) <= param_4 && ABS(param_1[1] - param_3[1]) <= param_4) &&

        ABS(*param_1 - *param_3) <= param_4) &&

      ((ABS(param_1[6] - param_3[6]) <= param_4 && ABS(param_1[5] - param_3[5]) <= param_4) &&

       ABS(param_1[4] - param_3[4]) <= param_4)) &&

     ((ABS(param_1[10] - param_3[10]) <= param_4 && ABS(param_1[9] - param_3[9]) <= param_4) &&

      ABS(param_1[8] - param_3[8]) <= param_4)) {

    *param_2 = 1;

    return;

  }

  *param_2 = 0;

  return;

}
