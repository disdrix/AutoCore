// =============================================================================
// FUN_006f75d0
// -----------------------------------------------------------------------------
// Stable ID: aa_006f75d0
// Address:   0x006f75d0  (autoassault.exe, image base 0x400000)
// System:    unknown
// Generated: 2026-07-23 from raw capture (scaffold; refine for important units)
// Exactness: Behavior-preserving rewrite of decompiler control flow. Not modernization.
// Bit-for-bit vs retail EXE: DEFERRED (loaded image may differ slightly).
// =============================================================================

// PURPOSE (auto): Scaffold unit for FUN_006f75d0 @ 0x006f75d0
// Stable ID: aa_006f75d0
// No high-value strings recovered; name via xrefs/callers in follow-up.
// Readability: control flow preserved from Ghidra decompile; types tentative.

// READABILITY (auto CF):
//  - Body size: ~78 non-empty decompiler lines.
//  - Control keywords: return×1.
//  - Notable callees: FUN_006f75d0.
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

void FUN_006f75d0(float *param_1,float *param_2,float *param_3,float *param_4)



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

  float fVar15;

  float fVar16;

  float fVar17;

  float fVar18;

  

  fVar10 = param_1[8] - param_1[4];

  fVar12 = param_1[9] - param_1[5];

  fVar14 = param_1[10] - param_1[6];

  fVar15 = *param_1 - param_1[8];

  fVar16 = param_1[1] - param_1[9];

  fVar17 = param_1[2] - param_1[10];

  fVar1 = param_1[4];

  fVar2 = *param_1;

  fVar3 = param_1[5];

  fVar4 = param_1[1];

  fVar5 = param_1[6];

  fVar6 = param_1[2];

  fVar8 = param_2[3];

  fVar11 = (fVar17 * fVar12 - fVar16 * fVar14) * fVar8;

  fVar13 = (fVar14 * fVar15 - fVar17 * fVar10) * fVar8;

  fVar18 = (fVar16 * fVar10 - fVar12 * fVar15) * fVar8;

  param_4[2] = fVar18;

  fVar8 = fVar8 * g_flZero;

  *param_4 = fVar11;

  param_4[1] = fVar13;

  param_4[3] = fVar8;

  fVar9 = *param_2;

  fVar8 = param_2[1];

  fVar7 = param_2[2];

  param_3[3] = 0.0;

  fVar1 = (fVar1 - fVar2) * fVar7;

  fVar2 = (fVar3 - fVar4) * fVar7;

  fVar7 = (fVar5 - fVar6) * fVar7;

  *param_3 = fVar18 * fVar12 * fVar9 - fVar13 * fVar14 * fVar9;

  param_3[1] = fVar14 * fVar9 * fVar11 - fVar18 * fVar9 * fVar10;

  param_3[2] = fVar13 * fVar9 * fVar10 - fVar12 * fVar9 * fVar11;

  param_3[7] = 0.0;

  param_3[4] = fVar18 * fVar16 * fVar8 - fVar13 * fVar17 * fVar8;

  param_3[5] = fVar17 * fVar8 * fVar11 - fVar18 * fVar15 * fVar8;

  param_3[6] = fVar13 * fVar15 * fVar8 - fVar16 * fVar8 * fVar11;

  param_3[0xb] = 0.0;

  param_3[8] = fVar18 * fVar2 - fVar13 * fVar7;

  param_3[9] = fVar7 * fVar11 - fVar18 * fVar1;

  param_3[10] = fVar13 * fVar1 - fVar2 * fVar11;

  fVar1 = param_3[4];

  param_3[4] = param_3[1];

  param_3[1] = fVar1;

  fVar1 = param_3[8];

  param_3[8] = param_3[2];

  param_3[2] = fVar1;

  fVar1 = param_3[9];

  param_3[9] = param_3[6];

  param_3[6] = fVar1;

  param_3[3] = *param_4;

  param_3[7] = param_4[1];

  param_3[0xb] = param_4[2];

  param_3[0xf] = 0.0;

  param_3[0xe] = 0.0;

  param_3[0xd] = 0.0;

  param_3[0xc] = 0.0;

  param_3[0xc] = -(param_2[4] * *param_2);

  return;

}
