// =============================================================================
// FUN_00788ab0
// -----------------------------------------------------------------------------
// Stable ID: aa_00788ab0
// Address:   0x00788ab0  (autoassault.exe, image base 0x400000)
// System:    unknown
// Generated: 2026-07-23 from raw capture (scaffold; refine for important units)
// Exactness: Behavior-preserving rewrite of decompiler control flow. Not modernization.
// Bit-for-bit vs retail EXE: DEFERRED (loaded image may differ slightly).
// =============================================================================

// PURPOSE (auto): Scaffold unit for FUN_00788ab0 @ 0x00788ab0
// Stable ID: aa_00788ab0
// No high-value strings recovered; name via xrefs/callers in follow-up.
// Readability: control flow preserved from Ghidra decompile; types tentative.

// READABILITY (auto CF):
//  - Body size: ~32 non-empty decompiler lines.
//  - Control keywords: if×1, return×1.
//  - Notable callees: FUN_00788ab0, SQRT.
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

float10 FUN_00788ab0(float *param_1,float *param_2,float *param_3,float *param_4)



{

  float10 fVar1;

  float10 fVar2;

  float fVar3;

  float fVar4;

  float fVar5;

  float fVar6;

  

  fVar5 = param_3[2];

  fVar4 = *param_3;

  fVar6 = param_3[1];

  fVar3 = (fVar5 * (param_1[2] - param_2[2]) + fVar4 * (*param_1 - *param_2) +

          (param_1[1] - param_2[1]) * fVar6) / (fVar4 * fVar4 + fVar6 * fVar6 + fVar5 * fVar5);

  fVar4 = *param_2 + fVar4 * fVar3;

  fVar6 = fVar3 * fVar6 + param_2[1];

  fVar5 = param_2[2] + fVar5 * fVar3;

  if (param_4 == (float *)0x0) {

    fVar1 = (float10)fVar4 - (float10)*param_1;

    fVar2 = (float10)fVar6 - (float10)param_1[1];

  }

  else {

    *param_4 = fVar4;

    param_4[1] = fVar6;

    param_4[2] = fVar5;

    fVar1 = (float10)*param_4 - (float10)*param_1;

    fVar2 = (float10)param_4[1] - (float10)param_1[1];

    fVar5 = param_4[2];

  }

  return SQRT(fVar1 * fVar1 +

              fVar2 * fVar2 +

              ((float10)fVar5 - (float10)param_1[2]) * ((float10)fVar5 - (float10)param_1[2]));

}
