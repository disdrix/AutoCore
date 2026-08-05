// =============================================================================
// FUN_00713620
// -----------------------------------------------------------------------------
// Stable ID: aa_00713620
// Address:   0x00713620  (autoassault.exe, image base 0x400000)
// System:    unknown
// Generated: 2026-07-23 from raw capture (scaffold; refine for important units)
// Exactness: Behavior-preserving rewrite of decompiler control flow. Not modernization.
// Bit-for-bit vs retail EXE: DEFERRED (loaded image may differ slightly).
// =============================================================================

// PURPOSE (auto): Scaffold unit for FUN_00713620 @ 0x00713620
// Stable ID: aa_00713620
// No high-value strings recovered; name via xrefs/callers in follow-up.
// Readability: control flow preserved from Ghidra decompile; types tentative.

// READABILITY (auto CF):
//  - Body size: ~38 non-empty decompiler lines.
//  - Control keywords: if×8, goto×2, return×2.
//  - Notable callees: ABS, FUN_00713620.
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

/* WARNING: Globals starting with '_' overlap smaller symbols at the same address */



float10 FUN_00713620(float param_1,float param_2,float param_3,float param_4,float *param_5)



{

  float10 fVar1;

  

  if (*param_5 < g_flMultiKillCountBlend) {

    *param_5 = 0.1;

  }

  if (param_3 < g_flMultiKillCountBlend) {

    param_3 = 0.1;

  }

  if ((float)_DAT_00a10e30 <= ABS(param_2 - param_1)) {

    if (DAT_00a0f728 <= param_4) {

      if (param_1 < param_2) {

        fVar1 = ((float10)param_2 * (float10)param_4) / (float10)param_3;

        goto LAB_007136c4;

      }

    }

    else if (param_2 <= param_1) {

      fVar1 = ((float10)param_2 * (float10)param_4) / (float10)param_3;

      goto LAB_007136c4;

    }

    fVar1 = ((float10)param_1 * (float10)param_4) / (float10)*param_5;

  }

  else {

    fVar1 = ((float10)param_1 + (float10)param_2) * (float10)DAT_00a0f298;

  }

LAB_007136c4:

  if (fVar1 < (float10)g_flZero) {

    fVar1 = (float10)g_flZero;

    *param_5 = param_3;

    return fVar1;

  }

  if ((float10)g_flOne < fVar1) {

    fVar1 = (float10)g_flOne;

  }

  *param_5 = param_3;

  return fVar1;

}
