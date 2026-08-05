// =============================================================================
// FUN_0066e480
// -----------------------------------------------------------------------------
// Stable ID: aa_0066e480
// Address:   0x0066e480  (autoassault.exe, image base 0x400000)
// System:    unknown
// Generated: 2026-07-23 from raw capture (scaffold; refine for important units)
// Exactness: Behavior-preserving rewrite of decompiler control flow. Not modernization.
// Bit-for-bit vs retail EXE: DEFERRED (loaded image may differ slightly).
// =============================================================================

// PURPOSE (auto): Scaffold unit for FUN_0066e480 @ 0x0066e480
// Stable ID: aa_0066e480
// No high-value strings recovered; name via xrefs/callers in follow-up.
// Readability: control flow preserved from Ghidra decompile; types tentative.

// READABILITY (auto CF):
//  - Body size: ~40 non-empty decompiler lines.
//  - Control keywords: if×1, return×1.
//  - Notable callees: FUN_00646af0, FUN_0066e480, SQRT.
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

void FUN_0066e480(float *param_1,float *param_2,float *param_3,float *param_4,float *param_5,

                 float *param_6)



{

  float fVar1;

  float fVar2;

  float10 fVar3;

  float fVar4;

  float fVar5;

  float fVar6;

  float fVar7;

  float fVar8;

  float fVar9;

  float fVar10;

  

  fVar5 = *param_1 + *param_2;

  fVar7 = param_1[1] + param_2[1];

  fVar9 = param_1[2] + param_2[2];

  fVar1 = param_1[3];

  fVar2 = param_2[3];

  fVar10 = fVar5 * fVar5 + fVar7 * fVar7 + fVar9 * fVar9;

  fVar4 = 0.0;

  if (fVar10 != 0.0) {

    fVar4 = g_flOne / SQRT(fVar10);

  }

  fVar9 = fVar4 * fVar9;

  fVar7 = fVar4 * fVar7;

  fVar5 = fVar4 * fVar5;

  fVar8 = param_4[2] * fVar7 - param_4[1] * fVar9;

  fVar10 = *param_4 * fVar9 - param_4[2] * fVar5;

  fVar6 = param_4[1] * fVar5 - *param_4 * fVar7;

  fVar3 = (float10)FUN_00646af0(*param_3 * fVar8 + fVar6 * param_3[2] + fVar10 * param_3[1],

                                *param_3 * (fVar10 * fVar9 - fVar6 * fVar7) +

                                (fVar6 * fVar5 - fVar8 * fVar9) * param_3[1] +

                                (fVar8 * fVar7 - fVar10 * fVar5) * param_3[2]);

  *param_6 = (float)fVar3;

  *param_5 = fVar5;

  param_5[1] = fVar7;

  param_5[2] = fVar9;

  param_5[3] = fVar4 * (fVar1 + fVar2);

  return;

}
