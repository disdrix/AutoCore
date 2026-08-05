// =============================================================================
// FUN_007144b0
// -----------------------------------------------------------------------------
// Stable ID: aa_007144b0
// Address:   0x007144b0  (autoassault.exe, image base 0x400000)
// System:    unknown
// Generated: 2026-07-23 from raw capture (scaffold; refine for important units)
// Exactness: Behavior-preserving rewrite of decompiler control flow. Not modernization.
// Bit-for-bit vs retail EXE: DEFERRED (loaded image may differ slightly).
// =============================================================================

// PURPOSE (auto): Scaffold unit for FUN_007144b0 @ 0x007144b0
// Stable ID: aa_007144b0
// No high-value strings recovered; name via xrefs/callers in follow-up.
// Readability: control flow preserved from Ghidra decompile; types tentative.

// READABILITY (auto CF):
//  - Body size: ~30 non-empty decompiler lines.
//  - Control keywords: for×2, return×1.
//  - Notable callees: FUN_007144b0.
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

float10 FUN_007144b0(float *param_1,float *param_2,int param_3)



{

  float *pfVar1;

  float *pfVar2;

  float *pfVar3;

  float *pfVar4;

  float10 fVar5;

  float10 fVar6;

  

  fVar6 = (float10)0;

  fVar5 = fVar6;

  for (; 5 < param_3; param_3 = param_3 + -6) {

    pfVar1 = param_2 + 1;

    pfVar2 = param_2 + 3;

    pfVar3 = param_2 + 4;

    pfVar4 = param_2 + 5;

    fVar6 = (float10)*param_1 * (float10)*param_2 + (float10)param_1[2] * (float10)param_2[2] +

            fVar5 + fVar6;

    param_2 = param_2 + 6;

    fVar5 = (float10)param_1[4] * (float10)*pfVar3 + (float10)param_1[1] * (float10)*pfVar1 +

            (float10)param_1[3] * (float10)*pfVar2 + (float10)param_1[5] * (float10)*pfVar4;

    param_1 = param_1 + 6;

  }

  for (; param_3 != 0; param_3 = param_3 + -1) {

    fVar6 = fVar5 + fVar6;

    fVar5 = (float10)*param_1 * (float10)*param_2;

    param_1 = param_1 + 1;

    param_2 = param_2 + 1;

  }

  return fVar5 + fVar6;

}
