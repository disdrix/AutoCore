// =============================================================================
// FUN_00669bb0
// -----------------------------------------------------------------------------
// Stable ID: aa_00669bb0
// Address:   0x00669bb0  (autoassault.exe, image base 0x400000)
// System:    unknown
// Generated: 2026-07-23 from raw capture (scaffold; refine for important units)
// Exactness: Behavior-preserving rewrite of decompiler control flow. Not modernization.
// Bit-for-bit vs retail EXE: DEFERRED (loaded image may differ slightly).
// =============================================================================

// PURPOSE (auto): Scaffold unit for FUN_00669bb0 @ 0x00669bb0
// Stable ID: aa_00669bb0
// No high-value strings recovered; name via xrefs/callers in follow-up.
// Readability: control flow preserved from Ghidra decompile; types tentative.

// READABILITY (auto CF):
//  - Body size: ~119 non-empty decompiler lines.
//  - Control keywords: if×12, return×3, while×2, goto×2.
//  - Notable callees: SQRT×2, FUN_00646a60, FUN_00669bb0.
//  - Return sites: 3.

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

float10 __thiscall FUN_00669bb0(int *param_1,float param_2,float *param_3,float *param_4)



{

  int iVar1;

  int iVar2;

  float fVar3;

  int iVar4;

  int iVar5;

  int iVar6;

  int iVar7;

  float *pfVar8;

  float *pfVar9;

  float10 fVar10;

  float fVar11;

  float fVar12;

  float fVar13;

  float fVar14;

  float fVar15;

  float fVar16;

  float fVar17;

  float fVar18;

  float fVar19;

  float fVar20;

  float fVar21;

  float fVar22;

  int local_5c;

  

  if (param_2 < 0.0) {

    param_2 = 0.0;

  }

  iVar4 = FUN_00646a60(param_2);

  fVar3 = g_flOne;

  iVar1 = param_1[5];

  iVar7 = iVar4 + 1;

  if (iVar1 <= iVar7) {

    iVar7 = iVar1 + -1;

    iVar4 = iVar1 + -2;

  }

  iVar6 = param_1[4];

  local_5c = iVar7 + 1;

  iVar5 = iVar7 << 4;

  pfVar9 = (float *)(iVar6 + iVar4 * 0x10);

  pfVar8 = (float *)(iVar4 * 0x10 + iVar6);

  while( true ) {

    while( true ) {

      fVar16 = *(float *)(iVar5 + 4 + iVar6) - pfVar8[1];

      fVar17 = *(float *)(iVar5 + 8 + iVar6) - pfVar8[2];

      fVar15 = *(float *)(iVar5 + iVar6) - *pfVar8;

      fVar11 = ((param_3[2] - pfVar9[2]) * fVar17 + (param_3[1] - pfVar9[1]) * fVar16 +

               (*param_3 - *pfVar9) * fVar15) /

               (fVar17 * fVar17 + fVar16 * fVar16 + fVar15 * fVar15);

      if (0.0 <= fVar11) break;

      if (iVar4 == 0) goto LAB_00669edf;

      local_5c = local_5c + -1;

      iVar4 = iVar4 + -1;

      pfVar8 = pfVar8 + -4;

      pfVar9 = pfVar9 + -4;

      iVar7 = iVar7 + -1;

      iVar5 = iVar5 + -0x10;

    }

    fVar19 = param_3[1] - *(float *)(iVar5 + 4 + iVar6);

    fVar20 = *param_3 - *(float *)(iVar5 + iVar6);

    fVar14 = param_3[2] - *(float *)(iVar5 + 8 + iVar6);

    if ((fVar14 * fVar17 + fVar19 * fVar16 + fVar20 * fVar15 <= 0.0) || (iVar1 <= local_5c))

    goto LAB_00669edf;

    iVar2 = param_1[4];

    fVar12 = *(float *)(iVar5 + 0x10 + iVar2) - *(float *)(iVar5 + iVar2);

    fVar21 = *(float *)(iVar5 + 0x18 + iVar2) - *(float *)(iVar5 + 8 + iVar2);

    fVar13 = *(float *)(iVar5 + 0x14 + iVar2) - *(float *)(iVar5 + 4 + iVar2);

    if (fVar21 * fVar14 + fVar13 * fVar19 + fVar12 * fVar20 <= 0.0) break;

    local_5c = local_5c + 1;

    iVar4 = iVar4 + 1;

    pfVar8 = pfVar8 + 4;

    pfVar9 = pfVar9 + 4;

    iVar7 = iVar7 + 1;

    iVar5 = iVar5 + 0x10;

  }

  fVar11 = fVar17 * fVar17 + fVar16 * fVar16 + fVar15 * fVar15;

  if (fVar11 == 0.0) {

    fVar22 = 0.0;

  }

  else {

    fVar22 = g_flOne / SQRT(fVar11);

  }

  fVar11 = fVar21 * fVar21 + fVar13 * fVar13 + fVar12 * fVar12;

  if (fVar11 == 0.0) {

    fVar18 = 0.0;

  }

  else {

    fVar18 = g_flOne / SQRT(fVar11);

  }

  fVar11 = DAT_009c8354;

  if (0.0 - (fVar21 * fVar18 * fVar14 + fVar13 * fVar18 * fVar19 + fVar18 * fVar12 * fVar20) <=

      fVar14 * fVar22 * fVar17 + fVar19 * fVar22 * fVar16 + fVar20 * fVar22 * fVar15) {

    iVar4 = iVar4 + 1;

    iVar7 = iVar7 + 1;

    fVar11 = DAT_00a0f718;

  }

LAB_00669edf:

  iVar1 = param_1[4];

  iVar5 = iVar7 * 0x10 + iVar1;

  iVar6 = iVar4 * 0x10 + iVar1;

  fVar15 = g_flOne - fVar11;

  *param_4 = *(float *)(iVar4 * 0x10 + iVar1) * fVar15 + *(float *)(iVar7 * 0x10 + iVar1) * fVar11;

  param_4[1] = *(float *)(iVar6 + 4) * fVar15 + *(float *)(iVar5 + 4) * fVar11;

  param_4[2] = *(float *)(iVar6 + 8) * fVar15 + *(float *)(iVar5 + 8) * fVar11;

  param_4[3] = *(float *)(iVar6 + 0xc) * fVar15 + *(float *)(iVar5 + 0xc) * fVar11;

  fVar11 = (float)iVar4 + fVar11;

  if ((char)param_1[3] != '\0') {

    fVar15 = (float)(param_1[5] + -1);

    if (fVar11 < DAT_00a0f704) {

      fVar10 = (float10)(**(code **)(*param_1 + 0x18))(fVar15 - (fVar3 - fVar11),param_3,param_4);

      return fVar10;

    }

    if (fVar15 - DAT_00a0f704 < fVar11) {

      fVar10 = (float10)(**(code **)(*param_1 + 0x18))(fVar3 - (fVar15 - fVar11),param_3,param_4);

      return fVar10;

    }

  }

  return (float10)fVar11;

}
