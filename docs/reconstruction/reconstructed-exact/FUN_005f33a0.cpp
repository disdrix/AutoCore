// =============================================================================
// FUN_005f33a0
// -----------------------------------------------------------------------------
// Stable ID: aa_005f33a0
// Address:   0x005f33a0  (autoassault.exe, image base 0x400000)
// System:    unknown
// Generated: 2026-07-23 from raw capture (scaffold; refine for important units)
// Exactness: Behavior-preserving rewrite of decompiler control flow. Not modernization.
// Bit-for-bit vs retail EXE: DEFERRED (loaded image may differ slightly).
// =============================================================================

// PURPOSE (auto): Scaffold unit for FUN_005f33a0 @ 0x005f33a0
// Stable ID: aa_005f33a0
// No high-value strings recovered; name via xrefs/callers in follow-up.
// Readability: control flow preserved from Ghidra decompile; types tentative.

// READABILITY (auto CF):
//  - Body size: ~34 non-empty decompiler lines.
//  - Control keywords: if×1, return×1.
//  - Notable callees: FUN_00646980×3, FUN_005f33a0, SQRT.
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

void FUN_005f33a0(float *param_1,float *param_2)



{

  float fVar1;

  float fVar2;

  float fVar3;

  float fVar4;

  float fVar5;

  float fVar6;

  float fVar7;

  float10 fVar8;

  float fVar9;

  

  fVar8 = (float10)FUN_00646980();

  fVar5 = (float)(fVar8 - (float10)DAT_00a0f298);

  fVar8 = (float10)FUN_00646980();

  fVar6 = (float)(fVar8 - (float10)DAT_00a0f298);

  fVar8 = (float10)FUN_00646980();

  fVar7 = (float)(fVar8 - (float10)DAT_00a0f298);

  fVar9 = fVar7 * fVar7 + fVar6 * fVar6 + fVar5 * fVar5;

  if (fVar9 == 0.0) {

    fVar9 = 0.0;

  }

  else {

    fVar9 = g_flOne / SQRT(fVar9);

  }

  fVar1 = param_2[3];

  fVar2 = param_2[1];

  fVar3 = param_2[2];

  fVar4 = param_2[3];

  *param_1 = *param_2 + fVar1 * fVar9 * fVar7;

  param_1[1] = fVar2 + fVar1 * fVar9 * fVar6;

  param_1[2] = fVar3 + fVar9 * fVar5 * fVar1;

  param_1[3] = fVar4 + fVar9 * 0.0 * fVar1;

  return;

}
