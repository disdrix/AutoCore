// =============================================================================
// FUN_005b9740
// -----------------------------------------------------------------------------
// Stable ID: aa_005b9740
// Address:   0x005b9740  (autoassault.exe, image base 0x400000)
// System:    unknown
// Generated: 2026-07-23 from raw capture (scaffold; refine for important units)
// Exactness: Behavior-preserving rewrite of decompiler control flow. Not modernization.
// Bit-for-bit vs retail EXE: DEFERRED (loaded image may differ slightly).
// =============================================================================

// PURPOSE (auto): Scaffold unit for FUN_005b9740 @ 0x005b9740
// Stable ID: aa_005b9740
// No high-value strings recovered; name via xrefs/callers in follow-up.
// Readability: control flow preserved from Ghidra decompile; types tentative.

// READABILITY (auto CF):
//  - Body size: ~128 non-empty decompiler lines.
//  - Control keywords: if×10, for×1, goto×1, return×1.
//  - Notable callees: CVOGReaction_RandomUnitScalar×4, FUN_006a3db0×2, FUN_004a6be0, FUN_005b94e0, FUN_005b9740, FUN_006759b0, FUN_0076f5f0, SQRT.
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

/* WARNING: Removing unreachable block (ram,0x005b997f) */



void __thiscall FUN_005b9740(int *param_1,float *param_2)



{

  float *pfVar1;

  float fVar2;

  float fVar3;

  float fVar4;

  float fVar5;

  float fVar6;

  float fVar7;

  ushort uVar8;

  float *pfVar9;

  uint8_t uVar10;

  void *pvVar11;

  int *piVar12;

  int iVar13;

  int iVar14;

  int *piVar15;

  int *piVar16;

  

  pvVar11 = operator_new(0x17c);

  if (pvVar11 == (void *)0x0) {

    piVar12 = (int *)0x0;

  }

  else {

    piVar12 = (int *)FUN_005b94e0();

  }

  pfVar9 = param_2;

  piVar15 = param_1;

  piVar16 = piVar12;

  for (iVar14 = 0x5f; iVar14 != 0; iVar14 = iVar14 + -1) {

    *piVar16 = *piVar15;

    piVar15 = piVar15 + 1;

    piVar16 = piVar16 + 1;

  }

  *(byte *)((int)piVar12 + 0x179) = *(byte *)((int)piVar12 + 0x179) | 8;

  piVar16 = piVar12 + 0x24;

  *piVar16 = (int)piVar16;

  piVar12[0x25] = (int)piVar16;

  piVar15 = piVar12 + 2;

  piVar12[3] = (int)piVar15;

  *piVar15 = (int)piVar15;

  piVar12[0x4a] = 0;

  piVar12[0x4b] = 0;

  piVar12[0x4c] = 0;

  piVar12[0x31] = (int)piVar16;

  *piVar12 = 0;

  piVar12[1] = 0;

  piVar12[0x11] = piVar12[0x10];

  if ((*(byte *)(param_1 + 0x5e) & 0x40) != 0) {

    piVar12[0x12] = param_1[0x11];

  }

  piVar12[0x5e] = piVar12[0x5e] & 0xffffffdf;

  piVar12[0x41] = (int)*param_2;

  piVar12[0x42] = (int)param_2[1];

  piVar12[0x43] = (int)param_2[2];

  iVar14 = CVOGReaction_RandomUnitScalar();

  if (0xfffff < *(int *)(iVar14 + 0xc)) {

    *(uint32_t /* width from decompiler */ *)(iVar14 + 0xc) = 0;

  }

  uVar8 = *(ushort *)(*(int *)(iVar14 + 8) + *(int *)(iVar14 + 0xc) * 2);

  *(int *)(iVar14 + 0xc) = *(int *)(iVar14 + 0xc) + 1;

  pfVar1 = (float *)(piVar12 + 0x51);

  *pfVar1 = ((float)uVar8 * DAT_00aaa638 - DAT_00a0f298) * g_flLevelUpUiBase_Inferred;

  iVar14 = CVOGReaction_RandomUnitScalar();

  if (0xfffff < *(int *)(iVar14 + 0xc)) {

    *(uint32_t /* width from decompiler */ *)(iVar14 + 0xc) = 0;

  }

  uVar8 = *(ushort *)(*(int *)(iVar14 + 8) + *(int *)(iVar14 + 0xc) * 2);

  *(int *)(iVar14 + 0xc) = *(int *)(iVar14 + 0xc) + 1;

  piVar12[0x52] = (int)(((float)uVar8 * DAT_00aaa638 - DAT_00a0f298) * g_flLevelUpUiBase_Inferred);

  iVar14 = CVOGReaction_RandomUnitScalar();

  if (0xfffff < *(int *)(iVar14 + 0xc)) {

    *(uint32_t /* width from decompiler */ *)(iVar14 + 0xc) = 0;

  }

  uVar8 = *(ushort *)(*(int *)(iVar14 + 8) + *(int *)(iVar14 + 0xc) * 2);

  *(int *)(iVar14 + 0xc) = *(int *)(iVar14 + 0xc) + 1;

  piVar12[0x53] = (int)(((float)uVar8 * DAT_00aaa638 - DAT_00a0f298) * g_flLevelUpUiBase_Inferred);

  if ((*(byte *)(param_1 + 0x5e) & 0x10) == 0) {

    pfVar9 = (float *)((float)param_1[0x52] * (float)param_1[0x52] +

                      (float)param_1[0x51] * (float)param_1[0x51] +

                      (float)param_1[0x53] * (float)param_1[0x53]);

  }

  else {

    fVar2 = (float)param_1[0x42];

    fVar3 = pfVar9[1];

    fVar4 = (float)param_1[0x43];

    fVar5 = pfVar9[2];

    fVar6 = (float)param_1[0x52];

    fVar7 = (float)param_1[0x53];

    *pfVar1 = (float)param_1[0x51] + ((float)param_1[0x41] - *pfVar9);

    piVar12[0x52] = (int)(fVar6 + (fVar2 - fVar3));

    piVar12[0x53] = (int)(fVar7 + (fVar4 - fVar5));

    iVar14 = CVOGReaction_RandomUnitScalar();

    if (0xfffff < *(int *)(iVar14 + 0xc)) {

      *(uint32_t /* width from decompiler */ *)(iVar14 + 0xc) = 0;

    }

    uVar8 = *(ushort *)(*(int *)(iVar14 + 8) + *(int *)(iVar14 + 0xc) * 2);

    *(int *)(iVar14 + 0xc) = *(int *)(iVar14 + 0xc) + 1;

    if ((uVar8 & 7) == 0) goto LAB_005b9a1d;

    param_2 = (float *)((float)param_1[0x51] * (float)param_1[0x51] +

                        (float)param_1[0x52] * (float)param_1[0x52] +

                       (float)param_1[0x53] * (float)param_1[0x53]);

    FUN_0076f5f0(pfVar1,pfVar1);

    pfVar9 = param_2;

  }

  fVar2 = SQRT((float)pfVar9) * (float)param_1[0x58];

  *pfVar1 = fVar2 * *pfVar1;

  piVar12[0x52] = (int)(fVar2 * (float)piVar12[0x52]);

  piVar12[0x53] = (int)(fVar2 * (float)piVar12[0x53]);

LAB_005b9a1d:

  iVar14 = FUN_006a3db0();

  if (499 < iVar14) {

    iVar14 = 500;

  }

  param_2 = (float *)(uint)*(byte *)((int)piVar12 + 0x2f);

  piVar12[0x22] = iVar14;

  uVar10 = FUN_006a3db0();

  *(uint8_t *)((int)piVar12 + 0x2f) = uVar10;

  if (*param_1 != 0) {

    iVar14 = *(int *)(*param_1 + 0x210);

    param_2 = (float *)piVar12;

    iVar13 = FUN_006759b0(iVar14,*(uint32_t /* width from decompiler */ *)(iVar14 + 4),&param_2);

    FUN_004a6be0(1);

    *(int *)(iVar14 + 4) = iVar13;

    **(int **)(iVar13 + 4) = iVar13;

  }

  return;

}
