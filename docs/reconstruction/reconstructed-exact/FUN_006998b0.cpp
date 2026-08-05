// =============================================================================
// FUN_006998b0
// -----------------------------------------------------------------------------
// Stable ID: aa_006998b0
// Address:   0x006998b0  (autoassault.exe, image base 0x400000)
// System:    unknown
// Generated: 2026-07-23 from raw capture (scaffold; refine for important units)
// Exactness: Behavior-preserving rewrite of decompiler control flow. Not modernization.
// Bit-for-bit vs retail EXE: DEFERRED (loaded image may differ slightly).
// =============================================================================

// PURPOSE (auto): Scaffold unit for FUN_006998b0 @ 0x006998b0
// Stable ID: aa_006998b0
// No high-value strings recovered; name via xrefs/callers in follow-up.
// Readability: control flow preserved from Ghidra decompile; types tentative.

// READABILITY (auto CF):
//  - Body size: ~15 non-empty decompiler lines.
//  - Control keywords: return×2, if×1.
//  - Notable callees: fsin×2, FUN_006998b0.
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



float10 __thiscall FUN_006998b0(float *param_1,float param_2)



{

  float10 fVar1;

  

  if (*(char *)(param_1 + 5) != '\0') {

    fVar1 = (float10)fsin((float10)_DAT_00d08ea4 * (float10)param_1[8] + (float10)*param_1 +

                          (float10)param_2);

    return ((float10)param_1[9] - -(float10)param_1[9]) *

           (fVar1 + (float10)g_flOne) * (float10)DAT_00a0f298 + -(float10)param_1[9];

  }

  fVar1 = (float10)fsin((float10)param_2);

  return ((float10)param_1[6] * (float10)DAT_00aaa8e8 - (float10)param_1[6] * (float10)_DAT_009eb444

         ) * (fVar1 + (float10)g_flOne) * (float10)DAT_00a0f298 +

         (float10)param_1[6] * (float10)_DAT_009eb444;

}
