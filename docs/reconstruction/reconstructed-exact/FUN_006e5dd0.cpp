// =============================================================================
// FUN_006e5dd0
// -----------------------------------------------------------------------------
// Stable ID: aa_006e5dd0
// Address:   0x006e5dd0  (autoassault.exe, image base 0x400000)
// System:    unknown
// Generated: 2026-07-23 from raw capture (scaffold; refine for important units)
// Exactness: Behavior-preserving rewrite of decompiler control flow. Not modernization.
// Bit-for-bit vs retail EXE: DEFERRED (loaded image may differ slightly).
// =============================================================================

// PURPOSE (auto): Scaffold unit for FUN_006e5dd0 @ 0x006e5dd0
// Stable ID: aa_006e5dd0
// Embedded strings (evidence for future rename):
//   - "LtHeightField"
//   - "StgetSpheres"
//   - "Sttransform"
//   - "Stcollide"
//   - "Stexamine"
// Readability: control flow preserved from Ghidra decompile; types tentative.

// READABILITY (auto CF):
//  - Body size: ~261 non-empty decompiler lines.
//  - Control keywords: if×14, do×3, while×3, return×1.
//  - Notable callees: rdtsc×6, FUN_0063a3f0, FUN_006e5dd0.
//  - Strings: "LtHeightField"; "StgetSpheres"; "Sttransform"; "Stcollide".
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

void FUN_006e5dd0(uint32_t /* width from decompiler */ *param_1,int param_2,int param_3,int *param_4)



{

  int *piVar1;

  float fVar2;

  float fVar3;

  float fVar4;

  int *piVar5;

  uint64_t uVar6;

  float fVar7;

  float fVar8;

  int *piVar9;

  float *pfVar10;

  float *pfVar11;

  float *pfVar12;

  float *pfVar13;

  uint uVar14;

  int iVar15;

  uint uVar16;

  float fVar17;

  int unaff_EDI;

  int iVar18;

  float *pfVar19;

  float *pfStack_c4;

  uint local_c0;

  float *pfStack_b0;

  uint8_t local_ac [4];

  float fStack_a8;

  float fStack_a4;

  float local_a0;

  float fStack_98;

  float fStack_94;

  float fStack_90;

  float fStack_88;

  float fStack_84;

  float fStack_80;

  float fStack_78;

  float fStack_74;

  float fStack_70;

  float fStack_68;

  float fStack_60;

  int iStack_5c;

  float *pfStack_58;

  uint uStack_54;

  float fStack_50;

  float fStack_4c;

  float fStack_48;

  float fStack_44;

  float fStack_40;

  float fStack_3c;

  float fStack_38;

  uint32_t /* width from decompiler */ uStack_34;

  uint32_t /* width from decompiler */ *puStack_30;

  int iStack_2c;

  

  if (DAT_00bc5644 < DAT_00bc5648) {

    *DAT_00bc5644 = "LtHeightField";

    uVar6 = rdtsc();

    local_c0 = (uint)uVar6;

    DAT_00bc5644[1] = local_c0;

    DAT_00bc5644 = DAT_00bc5644 + 3;

  }

  piVar5 = (int *)*param_1;

  FUN_0063a3f0(*(int *)(param_2 + 8) + 0x20,param_1[2] + 0x20);

  (**(code **)(*piVar5 + 0x28))(local_ac);

  piVar9 = DAT_00b05060;

  piVar1 = DAT_00b05060 + 3;

  iStack_5c = (int)pfStack_b0 * 0x10;

  if (*piVar1 < iStack_5c) {

    pfVar10 = (float *)(**(code **)(*DAT_00b05060 + 0x24))(iStack_5c);

  }

  else {

    pfVar10 = (float *)DAT_00b05060[2];

    DAT_00b05060[2] = (int)(pfVar10 + (int)pfStack_b0 * 4);

    piVar9[3] = *piVar1 + (int)pfStack_b0 * -0x10;

  }

  if (DAT_00bc5644 < DAT_00bc5648) {

    *DAT_00bc5644 = "StgetSpheres";

    uVar6 = rdtsc();

    pfStack_c4 = (float *)uVar6;

    DAT_00bc5644[1] = pfStack_c4;

    DAT_00bc5644 = DAT_00bc5644 + 3;

  }

  pfVar11 = (float *)(**(code **)(*piVar5 + 0x2c))(pfVar10);

  if (DAT_00bc5644 < DAT_00bc5648) {

    *DAT_00bc5644 = "Sttransform";

    uVar6 = rdtsc();

    DAT_00bc5644[1] = (int)uVar6;

    DAT_00bc5644 = DAT_00bc5644 + 3;

  }

  iVar15 = local_c0 - 1;

  pfVar19 = pfVar10;

  if (3 < (int)local_c0) {

    iVar18 = (int)pfVar11 - (int)pfStack_b0;

    uVar16 = local_c0 >> 2;

    iVar15 = iVar15 + uVar16 * -4;

    pfVar12 = pfVar10 + 6;

    pfVar13 = pfVar11;

    do {

      fVar17 = pfVar13[3];

      fVar2 = *pfVar13;

      fVar3 = pfVar13[1];

      fVar4 = pfVar13[2];

      *pfVar10 = fStack_a8 * fVar2 + fStack_98 * fVar3 + fStack_88 * fVar4 + fStack_78;

      pfVar12[-5] = fStack_a4 * fVar2 + fStack_94 * fVar3 + fStack_84 * fVar4 + fStack_74;

      pfVar12[-4] = local_a0 * fVar2 + fStack_90 * fVar3 + fStack_80 * fVar4 + fStack_70;

      pfVar12[-3] = 0.0;

      pfVar12[-3] = fVar17;

      fVar17 = pfVar13[7];

      fVar2 = pfVar13[4];

      fVar3 = pfVar13[5];

      fVar4 = *(float *)(iVar18 + (int)pfVar12);

      pfVar12[-2] = fStack_a8 * fVar2 + fStack_98 * fVar3 + fStack_88 * fVar4 + fStack_78;

      pfVar12[-1] = fStack_a4 * fVar2 + fStack_94 * fVar3 + fStack_84 * fVar4 + fStack_74;

      *pfVar12 = local_a0 * fVar2 + fStack_90 * fVar3 + fStack_80 * fVar4 + fStack_70;

      pfVar12[1] = 0.0;

      pfVar12[1] = fVar17;

      fVar17 = pfVar13[0xb];

      fVar2 = pfVar13[8];

      fVar3 = pfVar13[9];

      pfVar10 = pfVar10 + 0x10;

      fVar4 = pfVar13[10];

      pfVar11 = pfVar13 + 0x10;

      uVar16 = uVar16 - 1;

      pfVar12[2] = fStack_a8 * fVar2 + fStack_98 * fVar3 + fStack_88 * fVar4 + fStack_78;

      pfVar12[3] = fStack_a4 * fVar2 + fStack_94 * fVar3 + fStack_84 * fVar4 + fStack_74;

      pfVar12[4] = local_a0 * fVar2 + fStack_90 * fVar3 + fStack_80 * fVar4 + fStack_70;

      pfVar12[5] = 0.0;

      pfVar12[5] = fVar17;

      fVar17 = pfVar13[0xf];

      fVar2 = pfVar13[0xc];

      fVar3 = pfVar13[0xd];

      fVar4 = pfVar13[0xe];

      pfVar12[6] = fStack_a8 * fVar2 + fStack_98 * fVar3 + fStack_88 * fVar4 + fStack_78;

      pfVar12[7] = fStack_a4 * fVar2 + fStack_94 * fVar3 + fStack_84 * fVar4 + fStack_74;

      pfVar12[8] = local_a0 * fVar2 + fStack_90 * fVar3 + fStack_80 * fVar4 + fStack_70;

      pfVar12[9] = 0.0;

      pfVar12[9] = fVar17;

      pfVar12 = pfVar12 + 0x10;

      pfVar13 = pfVar11;

      pfVar19 = pfStack_b0;

      iStack_5c = iVar15;

    } while (uVar16 != 0);

  }

  if (-1 < iVar15) {

    iVar15 = iVar15 + 1;

    do {

      fVar17 = pfVar11[3];

      fVar2 = *pfVar11;

      iVar15 = iVar15 + -1;

      fVar3 = pfVar11[1];

      fVar4 = pfVar11[2];

      *pfVar10 = fStack_a8 * fVar2 + fStack_98 * fVar3 + fStack_88 * fVar4 + fStack_78;

      pfVar10[1] = fStack_a4 * fVar2 + fStack_94 * fVar3 + fStack_84 * fVar4 + fStack_74;

      pfVar10[2] = local_a0 * fVar2 + fStack_90 * fVar3 + fStack_80 * fVar4 + fStack_70;

      pfVar10[3] = 0.0;

      pfVar10[3] = fVar17;

      pfVar11 = pfVar11 + 4;

      pfVar10 = pfVar10 + 4;

    } while (iVar15 != 0);

  }

  if (DAT_00bc5644 < DAT_00bc5648) {

    *DAT_00bc5644 = "Stcollide";

    uVar6 = rdtsc();

    iStack_5c = (int)uVar6;

    DAT_00bc5644[1] = iStack_5c;

    DAT_00bc5644 = DAT_00bc5644 + 3;

  }

  piVar5 = DAT_00b05060;

  piVar1 = DAT_00b05060 + 3;

  fVar17 = (float)((int)fStack_60 + 0xfU & 0xfffffff0);

  fStack_60 = fVar17;

  if (*piVar1 < (int)fVar17) {

    uVar16 = (**(code **)(*DAT_00b05060 + 0x24))(fVar17);

  }

  else {

    uVar16 = DAT_00b05060[2];

    DAT_00b05060[2] = (int)fVar17 + uVar16;

    piVar5[3] = *piVar1 - (int)fVar17;

  }

  fStack_50 = *(float *)(param_3 + 8);

  uStack_54 = local_c0;

  pfStack_58 = pfVar19;

  (**(code **)((int)*pfStack_c4 + 0x28))(&pfStack_58,uVar16);

  if (DAT_00bc5644 < DAT_00bc5648) {

    *DAT_00bc5644 = "Stexamine";

    uVar6 = rdtsc();

    DAT_00bc5644[1] = (int)uVar6;

    DAT_00bc5644 = DAT_00bc5644 + 3;

  }

  fVar2 = *(float *)(param_3 + 8);

  uVar14 = uVar16;

  if (-1 < unaff_EDI) {

    pfVar10 = (float *)(uVar16 + 0xc);

    pfVar11 = pfVar19 + 2;

    iVar15 = unaff_EDI + 1;

    do {

      if (*pfVar10 < fVar2 != (*pfVar10 == fVar2)) {

        pfStack_58 = (float *)*pfVar11;

        puStack_30 = param_1;

        fVar17 = -pfVar11[1] - *pfVar10;

        iStack_2c = param_2;

        iVar18 = *(int *)(param_2 + 8);

        fStack_60 = fVar17 * pfVar10[-3] + pfVar11[-2];

        fVar7 = fVar17 * pfVar10[-2] + pfVar11[-1];

        fVar8 = fVar17 * *(float *)((uVar16 - (int)pfStack_c4) + (int)pfVar11) + (float)pfStack_58;

        fVar17 = pfVar10[-3];

        fVar3 = pfVar10[-2];

        fVar4 = *(float *)((uVar16 - (int)pfStack_c4) + (int)pfVar11);

        fStack_40 = fVar17 * *(float *)(iVar18 + 0x20) +

                    fVar3 * *(float *)(iVar18 + 0x30) + fVar4 * *(float *)(iVar18 + 0x40);

        fStack_3c = fVar17 * *(float *)(iVar18 + 0x24) +

                    fVar3 * *(float *)(iVar18 + 0x34) + fVar4 * *(float *)(iVar18 + 0x44);

        uStack_34 = 0;

        fStack_38 = fVar17 * *(float *)(iVar18 + 0x28) +

                    fVar3 * *(float *)(iVar18 + 0x38) + fVar4 * *(float *)(iVar18 + 0x48);

        fStack_50 = fStack_60 * *(float *)(iVar18 + 0x20) +

                    fVar7 * *(float *)(iVar18 + 0x30) + fVar8 * *(float *)(iVar18 + 0x40) +

                    *(float *)(iVar18 + 0x50);

        fStack_4c = fVar7 * *(float *)(iVar18 + 0x34) +

                    fVar8 * *(float *)(iVar18 + 0x44) + fStack_60 * *(float *)(iVar18 + 0x24) +

                    *(float *)(iVar18 + 0x54);

        fStack_44 = *pfVar10;

        fStack_48 = fVar7 * *(float *)(iVar18 + 0x38) +

                    fVar8 * *(float *)(iVar18 + 0x48) + fStack_60 * *(float *)(iVar18 + 0x28) +

                    *(float *)(iVar18 + 0x58);

        (**(code **)(*param_4 + 4))(&fStack_50);

      }

      pfVar11 = pfVar11 + 4;

      pfVar10 = pfVar10 + 4;

      iVar15 = iVar15 + -1;

      uVar14 = local_c0;

      fVar17 = fStack_68;

      pfVar19 = pfStack_c4;

    } while (iVar15 != 0);

  }

  piVar1 = DAT_00b05060;

  if ((fVar17 == 0.0) || ((uVar14 != DAT_00b05060[5] && (DAT_00b05060[5] != 0)))) {

    piVar5 = DAT_00b05060 + 3;

    DAT_00b05060[2] = DAT_00b05060[2] - (int)fVar17;

    piVar1[3] = *piVar5 + (int)fVar17;

  }

  else {

    (**(code **)(*DAT_00b05060 + 0x28))(uVar14,fVar17);

  }

  piVar1 = DAT_00b05060;

  if ((fVar17 == 0.0) ||

     ((pfVar19 != (float *)DAT_00b05060[5] && ((float *)DAT_00b05060[5] != (float *)0x0)))) {

    piVar5 = DAT_00b05060 + 3;

    DAT_00b05060[2] = DAT_00b05060[2] - (int)fVar17;

    piVar1[3] = *piVar5 + (int)fVar17;

  }

  else {

    (**(code **)(*DAT_00b05060 + 0x28))(pfVar19,fVar17);

  }

  if (DAT_00bc5644 < DAT_00bc5648) {

    *DAT_00bc5644 = &DAT_009d282c;

    uVar6 = rdtsc();

    DAT_00bc5644[1] = (int)uVar6;

    DAT_00bc5644 = DAT_00bc5644 + 3;

  }

  return;

}
