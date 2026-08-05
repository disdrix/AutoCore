// =============================================================================
// FUN_006f7450
// -----------------------------------------------------------------------------
// Stable ID: aa_006f7450
// Address:   0x006f7450  (autoassault.exe, image base 0x400000)
// System:    unknown
// Generated: 2026-07-23 from raw capture (scaffold; refine for important units)
// Exactness: Behavior-preserving rewrite of decompiler control flow. Not modernization.
// Bit-for-bit vs retail EXE: DEFERRED (loaded image may differ slightly).
// =============================================================================

// PURPOSE (auto): Scaffold unit for FUN_006f7450 @ 0x006f7450
// Stable ID: aa_006f7450
// No high-value strings recovered; name via xrefs/callers in follow-up.
// Readability: control flow preserved from Ghidra decompile; types tentative.

// READABILITY (auto CF):
//  - Body size: ~55 non-empty decompiler lines.
//  - Control keywords: if×3, return×1.
//  - Notable callees: SQRT×4, FUN_006f7450.
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

void FUN_006f7450(float *param_1,float *param_2)



{

  float fVar1;

  float fVar2;

  float fVar3;

  float fVar4;

  float fVar5;

  float fVar6;

  float fVar7;

  float fVar8;

  float fVar9;

  float fVar10;

  float fVar11;

  float fVar12;

  float fVar13;

  float fVar14;

  

  fVar7 = param_1[8] - param_1[4];

  fVar8 = param_1[9] - param_1[5];

  fVar9 = param_1[10] - param_1[6];

  fVar10 = *param_1 - param_1[8];

  fVar11 = param_1[1] - param_1[9];

  fVar12 = param_1[2] - param_1[10];

  fVar1 = param_1[4];

  fVar2 = *param_1;

  fVar3 = param_1[5];

  fVar4 = param_1[1];

  fVar5 = param_1[6];

  fVar6 = param_1[2];

  fVar13 = fVar7 * fVar7 + fVar8 * fVar8 + fVar9 * fVar9;

  fVar14 = g_flZero;

  if (fVar13 != g_flZero) {

    fVar14 = g_flOne / SQRT(fVar13);

  }

  *param_2 = fVar14;

  fVar13 = fVar10 * fVar10 + fVar11 * fVar11 + fVar12 * fVar12;

  fVar14 = g_flZero;

  if (fVar13 != g_flZero) {

    fVar14 = g_flOne / SQRT(fVar13);

  }

  param_2[1] = fVar14;

  fVar1 = (fVar1 - fVar2) * (fVar1 - fVar2) +

          (fVar3 - fVar4) * (fVar3 - fVar4) + (fVar5 - fVar6) * (fVar5 - fVar6);

  fVar2 = g_flZero;

  if (fVar1 != g_flZero) {

    fVar2 = g_flOne / SQRT(fVar1);

  }

  param_2[2] = fVar2;

  fVar1 = fVar12 * fVar8 - fVar11 * fVar9;

  fVar3 = fVar9 * fVar10 - fVar12 * fVar7;

  fVar2 = fVar11 * fVar7 - fVar8 * fVar10;

  fVar1 = SQRT(fVar1 * fVar1 + fVar3 * fVar3 + fVar2 * fVar2);

  param_2[4] = fVar1;

  param_2[3] = g_flOne / fVar1;

  return;

}
