// =============================================================================
// FUN_00836410
// -----------------------------------------------------------------------------
// Stable ID: aa_00836410
// Address:   0x00836410  (autoassault.exe, image base 0x400000)
// System:    unknown
// Generated: 2026-07-23 from raw capture (scaffold; refine for important units)
// Exactness: Behavior-preserving rewrite of decompiler control flow. Not modernization.
// Bit-for-bit vs retail EXE: DEFERRED (loaded image may differ slightly).
// =============================================================================

// PURPOSE (auto): Scaffold unit for FUN_00836410 @ 0x00836410
// Stable ID: aa_00836410
// Embedded strings (evidence for future rename):
//   - "<%s>"
//   - "*%s*"
//   - "[ %s%s ]"
//   - "%s%s"
//   - "%+d%%"
// Readability: control flow preserved from Ghidra decompile; types tentative.

// READABILITY (auto CF):
//  - Body size: ~535 non-empty decompiler lines.
//  - Control keywords: if×47, return×10, goto×4, do×1, while×1.
//  - Notable callees: CONCAT13×7, FUN_0040ada0×6, FUN_007a6de0×5, CONCAT22×4, FUN_0040aeb0×4, FUN_00413680×4, FUN_00755ab0×4, FUN_00759730×4.
//  - Strings: "<%s>"; "*%s*"; "[ %s%s ]"; "%s%s".
//  - Return sites: 10.

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



void __thiscall

FUN_00836410(int *param_1,int *param_2,char param_3,char param_4,char param_5,float param_6)



{

  uint *puVar1;

  byte bVar2;

  uint32_t /* width from decompiler */ uVar3;

  byte bVar4;

  uint8_t *puVar5;

  char cVar6;

  uint8_t uVar7;

  int iVar8;

  int iVar9;

  int iVar10;

  uint32_t /* width from decompiler */ *puVar11;

  void *pA;

  int *piVar12;

  char *pcVar13;

  uint8_t **extraout_ECX;

  int extraout_ECX_00;

  float fVar14;

  uint unaff_EBX;

  uint8_t *puVar15;

  uint8_t *puVar16;

  uint unaff_EBP;

  uint uVar17;

  float10 fVar18;

  int *piStack_1f0;

  uint8_t **ppuStack_1ec;

  uint8_t **ppuStack_1e8;

  uint8_t **ppuStack_1e4;

  uint8_t **ppuStack_1e0;

  undefined *pB;

  char cStack_1b1;

  uint32_t /* width from decompiler */ uStack_1b0;

  uint32_t /* width from decompiler */ uStack_1ac;

  uint32_t /* width from decompiler */ uStack_1a8;

  uint32_t /* width from decompiler */ uStack_1a4;

  uint32_t /* width from decompiler */ uStack_1a0;

  uint8_t *puStack_19c;

  uint8_t *puStack_198;

  uint8_t *puStack_194;

  uint8_t *puStack_190;

  uint8_t *puStack_18c;

  uint8_t *puStack_188;

  uint8_t *puStack_184;

  uint8_t *puStack_180;

  uint8_t *puStack_17c;

  uint8_t *puStack_178;

  uint8_t *puStack_174;

  uint8_t *puStack_170;

  uint8_t *puStack_16c;

  float fStack_168;

  int iStack_164;

  uint8_t *puStack_160;

  uint8_t *puStack_15c;

  uint8_t *puStack_158;

  uint8_t *puStack_154;

  int iStack_150;

  int iStack_14c;

  int iStack_148;

  float fStack_144;

  uint8_t *puStack_140;

  int iStack_13c;

  uint8_t *puStack_138;

  uint8_t *puStack_134;

  int iStack_130;

  int iStack_12c;

  int iStack_128;

  int iStack_124;

  uint8_t *apuStack_120 [2];

  uint8_t *puStack_118;

  uint8_t *puStack_114;

  uint8_t auStack_110 [4];

  uint8_t *apuStack_10c [63];

  uint32_t /* width from decompiler */ uStack_10;

  void *local_c;

  uint8_t *puStack_8;

  uint32_t /* width from decompiler */ uStack_4;

  

  uStack_4 = 0xffffffff;

  puStack_8 = &LAB_009b29fb;

  local_c = ExceptionList;

  if (param_1 == (int *)0x0) {

    return;

  }

  ExceptionList = &local_c;

  iVar8 = (**(code **)(*param_1 + 0x1d8))();

  if (((iVar8 == 0) || (iVar8 = (**(code **)(*param_1 + 0x1d8))(), *(char *)(iVar8 + 0x30c) == '\0')

      ) || (iVar8 = (**(code **)(*param_1 + 0x1d8))(), *(int *)(iVar8 + 0x250) == 0)) {

    iVar8 = (**(code **)(*param_1 + 0x1c8))();

  }

  else {

    iVar8 = (**(code **)(*param_1 + 0x1d8))();

    iVar8 = (**(code **)(*(int *)(*(int *)(*(int *)(*(int *)(iVar8 + 0x250) + 4) + 4) + 4 +

                                 *(int *)(iVar8 + 0x250)) + 0x1c8))();

  }

  if (iVar8 == 0) {

    ExceptionList = local_c;

    return;

  }

  if ((*(uint *)(*(int *)(*(int *)(iVar8 + 4) + 4) + 0x188 + iVar8) >> 1 & 1) != 0) {

    ExceptionList = local_c;

    return;

  }

  iStack_164 = iVar8;

  uStack_1a0 = (uint8_t *)FUN_007a69d0();

  puVar1 = (uint *)(*(int *)(*(int *)(iVar8 + 4) + 4) + 0x188 + iVar8);

  *puVar1 = *puVar1 | 2;

  *(uint32_t /* width from decompiler */ *)(*(int *)(*(int *)(iVar8 + 4) + 4) + iVar8 + 0x11c) = 0;

  iVar9 = (**(code **)(*param_1 + 0x210))();

  if ((iVar9 != DAT_00d1b6d8) && (iVar9 = (**(code **)(*param_1 + 0x19c))(), iVar9 != 0)) {

    (**(code **)(*param_1 + 0x19c))();

    cVar6 = FUN_005134e0();

    if (cVar6 != '\0') {

      ExceptionList = local_c;

      return;

    }

  }

  FUN_00936210();

  cVar6 = (**(code **)(**(int **)(DAT_00d1b644 + 0xe890) + 4))();

  if (cVar6 == '\0') {

    ExceptionList = local_c;

    return;

  }

  iVar10 = (int)((float)*(int *)(*(int *)(DAT_00d17944 + 0x2c) + 0x84) * _DAT_00aaab68);

  puStack_170 = (uint8_t *)((int)puStack_170 - iVar10);

  iVar9 = *(int *)(*(int *)(iVar8 + 4) + 4);

  *(float *)(iVar9 + iVar8 + 0x11c) = (float)iVar10 + *(float *)(iVar9 + 0x11c + iVar8);

  if ((param_4 != '\0') && (*(char *)(DAT_00d1b644 + 0xf5) == '\0')) {

    uStack_1ac = (uint8_t *)0xffffffff;

    uStack_1a4 = (uint8_t *)0xffffffff;

    puStack_194 = (uint8_t *)(**(code **)(*param_1 + 0x1ac))();

    if ((0 < (int)puStack_194) && (((uint)param_1[0x5f] >> 10 & 1) == 0)) {

      uStack_1a8 = (uint8_t *)(int)((float)DAT_00d1e818 * _DAT_00aaab64);

      uStack_1b0 = (int *)(int)((float)DAT_00d1e81c * _DAT_00aaab60);

      puStack_170 = puStack_170 + (-1 - (int)uStack_1b0);

      puStack_198 = puStack_170 + 1;

      puStack_18c = puStack_174;

      cVar6 = (**(code **)(*param_1 + 0x198))();

      if (cVar6 == '\0') {

        iVar8 = (**(code **)(*param_1 + 0x1b0))();

      }

      else {

        iVar8 = 0;

      }

      fStack_168 = (float)iVar8 / (float)(int)puStack_194;

      cVar6 = FUN_00838ad0();

      if (cVar6 == '\0') {

        puVar11 = (uint32_t /* width from decompiler */ *)FUN_004c77b0();

        uStack_1ac = (uint8_t *)*puVar11;

      }

      else {

        uStack_1ac = (uint8_t *)CONCAT13(uStack_1ac._3_1_,0xa80000);

        uStack_1ac = (uint8_t *)CONCAT22(uStack_1ac._2_2_,0xa800);

        uStack_1ac = (uint8_t *)CONCAT31(uStack_1ac._1_3_,0xa8);

      }

      cStack_1b1 = FUN_006a3db0();

      uVar3 = uStack_1ac;

      bVar2 = (byte)uStack_1ac;

      bVar4 = uStack_1ac._1_1_;

      uStack_1ac = (uint8_t *)CONCAT13(cStack_1b1,(undefined3)uStack_1ac);

      uStack_1a4._0_2_ = CONCAT11(bVar4 >> 3,bVar2 >> 3);

      uStack_1a4 = (uint8_t *)

                   (CONCAT13(cStack_1b1,

                             (int3)CONCAT22((ushort)((uint)uVar3 >> 0x13),(uint16_t)uStack_1a4)) &

                   0xff1fffff);

      if (param_2[0x123] == 0) {

        puStack_178 = puStack_198 + (int)uStack_1b0;

        puStack_190 = puStack_18c + (int)uStack_1a8 / 2;

        puStack_184 = puStack_18c + -((int)uStack_1a8 / 2);

        ppuStack_1e0 = (uint8_t **)&DAT_00d1ec78;

        ppuStack_1e4 = &puStack_184;

        puStack_180 = puStack_198;

        puStack_17c = puStack_190;

      }

      else {

        puStack_154 = puStack_198 + (int)uStack_1b0;

        puStack_180 = (uint8_t *)0x1;

        puStack_17c = (uint8_t *)0x5d;

        puStack_178 = (uint8_t *)0xe;

        puStack_184 = (uint8_t *)((iVar8 * 0x5c) / (int)puStack_194 + 1);

        puStack_190 = puStack_18c + (int)uStack_1a8 / 2;

        ppuStack_1e4 = &puStack_160;

        puStack_160 = puStack_18c +

                      ((iVar8 * (int)uStack_1a8) / (int)puStack_194 - (int)uStack_1a8 / 2);

        puStack_15c = puStack_198;

        ppuStack_1e0 = (uint8_t **)param_2[0x123];

        puStack_158 = puStack_190;

      }

      puStack_19c = puStack_198 + (int)uStack_1b0;

      iVar9 = (int)uStack_1a8 / 2;

      ppuStack_1e8 = (uint8_t **)0x836825;

      FUN_00413680();

      FUN_0040ada0();

      if (param_2[0x123] == 0) {

        puStack_178 = puStack_19c + -2;

        puStack_180 = puStack_198 + 1;

        ppuStack_1e0 = (uint8_t **)&DAT_00d1ec78;

        ppuStack_1e4 = &puStack_184;

        puStack_17c = puStack_18c +

                      (((int)(uStack_1a8 + -2) * iVar8) / (int)puStack_194 - iVar9) + 1;

        puVar15 = puStack_18c + -iVar9;

        puStack_184 = puVar15 + 1;

      }

      else {

        puStack_184 = (uint8_t *)0x1;

        puStack_180 = (uint8_t *)0x1;

        puStack_178 = (uint8_t *)0xe;

        puStack_17c = (uint8_t *)((iVar8 * 0x5c) / (int)puStack_194 + 1);

        puStack_15c = puStack_198;

        puStack_158 = puStack_18c + ((iVar8 * (int)uStack_1a8) / (int)puStack_194 - iVar9);

        puStack_154 = puStack_19c;

        ppuStack_1e0 = (uint8_t **)param_2[0x123];

        puVar15 = puStack_18c + -iVar9;

        ppuStack_1e4 = &puStack_160;

        puStack_160 = puVar15;

      }

      ppuStack_1e8 = (uint8_t **)0x836925;

      FUN_00413680();

      FUN_0040ada0();

      if ((uint8_t **)param_2[0x124] != (uint8_t **)0x0) {

        puStack_158 = puStack_190;

        puStack_15c = puStack_198;

        puStack_154 = puStack_19c;

        uStack_1a8 = (uint8_t *)CONCAT13(cStack_1b1,0xff0000);

        uStack_1a8 = (uint8_t *)CONCAT22(uStack_1a8._2_2_,0xff00);

        uStack_1a8 = (uint8_t *)CONCAT31(uStack_1a8._1_3_,0xff);

        ppuStack_1e4 = &puStack_160;

        puStack_184 = (uint8_t *)0x1;

        puStack_180 = (uint8_t *)0x1;

        puStack_17c = (uint8_t *)0x5d;

        puStack_178 = (uint8_t *)0xe;

        ppuStack_1e8 = (uint8_t **)0x8369b4;

        ppuStack_1e0 = (uint8_t **)param_2[0x124];

        puStack_160 = puVar15;

        FUN_00413680();

        FUN_0040ada0();

      }

      iVar8 = *(int *)(*(int *)(iStack_164 + 4) + 4);

      *(float *)(iStack_164 + iVar8 + 0x11c) =

           (float)(int)((int)uStack_1b0 + 1) + *(float *)(iStack_164 + 0x11c + iVar8);

    }

  }

  puVar15 = puStack_170;

  puStack_19c = puStack_170;

  if (param_3 != '\0') {

    iVar8 = (**(code **)(*param_1 + 0x210))();

    if (iVar8 == 0) {

      iVar8 = (**(code **)(*param_1 + 0x1d8))();

      if (iVar8 != 0) {

        (**(code **)(*param_1 + 0x1d8))();

        cVar6 = FUN_0040b1b0();

        if (cVar6 != '\0') {

          FUN_00402d50();

          local_c = (void *)0x0;

          pcVar13 = (char *)FUN_007a6de0();

          local_c = (void *)0xffffffff;

          if (puStack_114 != auStack_110) {

            free(puStack_114);

          }

          goto LAB_00836b52;

        }

      }

      cVar6 = FUN_00838ad0();

      if (cVar6 != '\0') {

        pcVar13 = (char *)FUN_007a6de0();

        goto LAB_00836b52;

      }

      iVar8 = (**(code **)(*param_1 + 0x214))();

      if (iVar8 != 0) {

        pB = &DAT_00a1e770;

        (**(code **)(*param_1 + 0x214))();

        pA = (void *)FUN_0040aff0();

        iVar8 = TFID_NotEquals(pA,pB);

        if ((char)iVar8 != '\0') {

          (**(code **)(*param_1 + 0x214))();

          FUN_0040aff0();

          iVar8 = FUN_004bb0d0();

          if (iVar8 != 0) {

            pcVar13 = (char *)(**(code **)(*(int *)(*(int *)(*(int *)(iVar8 + 4) + 4) + 4 + iVar8) +

                                          0x160))();

            goto LAB_00836b52;

          }

        }

      }

    }

    else {

      iVar8 = (**(code **)(*param_1 + 0x210))();

      pcVar13 = (char *)(iVar8 + 0xcfc);

LAB_00836b52:

      if (((pcVar13 != (char *)0x0) && (*pcVar13 != '\0')) && (DAT_00d1e7ec != 0)) {

        sprintf((char *)&puStack_114,"<%s>");

        piVar12 = (int *)FUN_00755ab0();

        puVar15 = puVar15 + -*(int *)(DAT_00d1e7ec + 0x7c);

        puStack_194 = puStack_17c + -(*piVar12 / 2);

        ppuStack_1e0 = (uint8_t **)0x836bec;

        uStack_1a4 = puVar15;

        puStack_190 = puVar15;

        FUN_00930fc0();

        ppuStack_1ec = (uint8_t **)(unaff_EBX >> 0x18);

        ppuStack_1e0 = (uint8_t **)0x0;

        ppuStack_1e4 = (uint8_t **)0xffffffff;

        ppuStack_1e8 = &puStack_114;

        puStack_174 = (uint8_t *)&ppuStack_1ec;

        piStack_1f0 = (int *)&ppuStack_1ec;

        FUN_0040aeb0();

        local_c = (void *)0xffffffff;

        piStack_1f0 = (int *)&stack0xfffffe48;

        FUN_00759730(param_2,&puStack_194);

      }

    }

    iVar8 = (**(code **)(*param_1 + 0x210))();

    if ((iVar8 != 0) && (iVar8 = (**(code **)(*param_1 + 0x210))(), *(int *)(iVar8 + 0x250) != 0)) {

      iVar8 = (**(code **)(*param_1 + 0x210))();

      pcVar13 = (char *)(*(int *)(iVar8 + 0x250) + 0x1b0);

      if ((pcVar13 != (char *)0x0) && (*pcVar13 != '\0')) {

        ppuStack_1e0 = (uint8_t **)0x836cb4;

        sprintf((char *)&puStack_118,"*%s*");

        piVar12 = (int *)FUN_00755ab0();

        puVar15 = puVar15 + -*(int *)(DAT_00d1e7ec + 0x7c);

        puStack_198 = puStack_180 + -(*piVar12 / 2);

        ppuStack_1e0 = (uint8_t **)&DAT_00d1a840;

        ppuStack_1e4 = (uint8_t **)0x836d1c;

        uStack_1a8 = puVar15;

        puStack_194 = puVar15;

        FUN_00930fc0();

        piStack_1f0 = (int *)(unaff_EBP >> 0x18);

        ppuStack_1e0 = (uint8_t **)0x0;

        ppuStack_1e4 = (uint8_t **)0x0;

        ppuStack_1e8 = (uint8_t **)0xffffffff;

        ppuStack_1ec = &puStack_118;

        puStack_178 = (uint8_t *)&piStack_1f0;

        FUN_0040aeb0(&piStack_1f0);

        uStack_10 = 0xffffffff;

        FUN_00759730(param_2,&puStack_198,&stack0xfffffe44);

      }

    }

    (**(code **)(*param_1 + 0x15c))();

    pcVar13 = (char *)FUN_007a6de0();

    iVar8 = (**(code **)(*param_1 + 0x210))();

    if (iVar8 != 0) {

      iVar8 = (**(code **)(*param_1 + 0x210))();

      pcVar13 = (char *)(**(code **)(*(int *)(*(int *)(*(int *)(iVar8 + 4) + 4) + 4 + iVar8) + 0x160

                                    ))();

      iVar8 = (**(code **)(*param_1 + 0x210))();

      cStack_1b1 = 0 < *(int *)(iVar8 + 0x6b4);

    }

    if (((pcVar13 != (char *)0x0) && (*pcVar13 != '\0')) &&

       (iVar8 = (**(code **)(*param_2 + 0x1b8))(), iVar8 != 0)) {

      if (DAT_00d1d888 == param_1) {

        if (cStack_1b1 == '\0') {

          pcVar13 = "[ %s%s ]";

        }

        else {

          FUN_007a6de0();

          pcVar13 = "[ %s%s ]";

        }

      }

      else {

        if (cStack_1b1 != '\0') {

          FUN_007a6de0();

        }

        pcVar13 = "%s%s";

      }

      sprintf((char *)apuStack_10c,pcVar13);

      (**(code **)(*param_2 + 0x1b8))();

      piVar12 = (int *)FUN_00755ab0();

      iVar8 = *piVar12;

      piVar12 = (int *)(**(code **)(*param_2 + 0x1b8))();

      puVar15 = puVar15 + -*(int *)(*piVar12 + 0x7c);

      puStack_18c = puStack_174 + -(iVar8 / 2);

      puStack_19c = puVar15;

      puStack_188 = puVar15;

      FUN_00930fc0();

      ppuStack_1e0 = apuStack_10c;

      uStack_1b0 = (int *)CONCAT13((char)(int)((float)((uint)uStack_1b0 >> 0x18) * param_6),

                                   (undefined3)uStack_1b0);

      ppuStack_1e4 = (uint8_t **)0x836f36;

      (**(code **)(*param_2 + 0x1b8))();

      puStack_16c = (uint8_t *)&ppuStack_1e4;

      ppuStack_1e8 = (uint8_t **)&ppuStack_1e4;

      ppuStack_1ec = (uint8_t **)0x836f45;

      ppuStack_1e4 = extraout_ECX;

      FUN_0040aeb0();

      uStack_4 = 0xffffffff;

      ppuStack_1e8 = (uint8_t **)&uStack_1b0;

      ppuStack_1ec = &puStack_18c;

      piStack_1f0 = param_2;

      FUN_00759730();

    }

    FUN_0040ada0();

    iVar8 = *(int *)(*(int *)(iStack_164 + 4) + 4);

    *(float *)(iStack_164 + iVar8 + 0x11c) =

         (float)((int)puStack_170 - (int)puVar15) + *(float *)(iStack_164 + 0x11c + iVar8);

  }

  if (param_5 == '\0') {

    ExceptionList = local_c;

    return;

  }

  if (param_2[0x122] == 0) {

    ExceptionList = local_c;

    return;

  }

  if (*(char *)(DAT_00d1b644 + 0xf5) != '\0') {

    ExceptionList = local_c;

    return;

  }

  uStack_1b0 = param_1;

  iVar8 = (**(code **)(*param_1 + 0x1d4))();

  if ((iVar8 != 0) && (piVar12 = (int *)param_1[0x2b], piVar12 != (int *)0x0)) {

    param_1 = piVar12;

    uStack_1b0 = piVar12;

  }

  iStack_14c = FUN_00835190();

  if (iStack_14c < 1) {

    ExceptionList = local_c;

    return;

  }

  iStack_150 = (int)((float)DAT_00d1e818 * DAT_00aaa8fc);

  iStack_148 = (int)(*(int *)(*(int *)param_2[0x122] + 0x20) +

                    (*(int *)(*(int *)param_2[0x122] + 0x20) >> 0x1f & 0x3fU)) >> 6;

  puVar15 = (uint8_t *)(int)((float)DAT_00d1e81c * DAT_00aaa8f4);

  uStack_1a0 = (uint8_t *)CONCAT13(uStack_1a0._3_1_,0xff0000);

  uStack_1a0 = (uint8_t *)CONCAT22(uStack_1a0._2_2_,0xff00);

  uStack_1a0 = (uint8_t *)CONCAT31(uStack_1a0._1_3_,0xff);

  puStack_194 = puVar15;

  uVar7 = FUN_006a3db0();

  uVar17 = param_1[0x2d];

  uStack_1a0 = (uint8_t *)CONCAT13(uVar7,(undefined3)uStack_1a0);

  uStack_1a8 = (uint8_t *)uVar17;

  puStack_198 = puVar15;

  if (((uVar17 & 0x1000) == 0) && (iVar8 = (**(code **)(*param_1 + 0x1d8))(), iVar8 != 0)) {

    (**(code **)(*param_1 + 0x1d8))();

    fVar18 = (float10)FUN_004c4e20();

    if (fVar18 < (float10)DAT_00aaa6b4) {

      uVar17 = uVar17 | 0x1000;

      uStack_1a8 = (uint8_t *)uVar17;

      goto LAB_008370ed;

    }

  }

  if (((uVar17 & 0x4000) == 0) && (iVar8 = (**(code **)(*param_1 + 0x1d8))(), iVar8 != 0)) {

    (**(code **)(*param_1 + 0x1d8))();

    fVar18 = (float10)FUN_004c4e20();

    if ((float10)DAT_00aaa664 < fVar18) {

      uVar17 = uVar17 | 0x4000;

      uStack_1a8 = (uint8_t *)uVar17;

    }

  }

LAB_008370ed:

  if (((uVar17 & 0x1000) != 0) && ((uVar17 & 0x4000) != 0)) {

    uStack_1a8 = (uint8_t *)(uVar17 & 0xffffbfff);

  }

  fStack_168 = 0.0;

  puVar15 = (uint8_t *)0x0;

  do {

    uVar17 = 1 << (SUB41(fStack_168,0) & 0x1f);

    fVar14 = fStack_168;

    puVar16 = puVar15;

    if ((((uint)uStack_1a8 & uVar17) != 0) &&

       (iVar8 = FUN_008350a0(), fVar14 = (float)extraout_ECX_00, -1 < iVar8)) {

      iStack_130 = (iVar8 / iStack_148) * 0x40;

      iStack_128 = iStack_130 + 0x40;

      iStack_12c = (iVar8 % iStack_148) * 0x40;

      iStack_124 = iStack_12c + 0x40;

      puStack_16c = puVar15 + iStack_150;

      iVar8 = (iStack_150 * iStack_14c) / 2;

      puStack_138 = puStack_174 + ((int)puStack_16c - iVar8);

      puStack_140 = puStack_174 + ((int)puVar15 - iVar8);

      iStack_13c = (int)puStack_19c - (int)puStack_194;

      puStack_134 = puStack_19c;

      ppuStack_1e0 = (uint8_t **)param_2[0x122];

      ppuStack_1e4 = &puStack_140;

      ppuStack_1e8 = (uint8_t **)0x8371db;

      FUN_00413680();

      fVar14 = fStack_168;

      puVar16 = puStack_16c;

      if (((uVar17 == 0x1000) || (uVar17 == 0x4000)) &&

         ((DAT_00d1e800 != 0 &&

          (iVar9 = (**(code **)(*uStack_1b0 + 0x1d8))(), piVar12 = uStack_1b0, fVar14 = fStack_168,

          puVar16 = puStack_16c, iVar9 != 0)))) {

        iVar9 = (**(code **)(*uStack_1b0 + 0x1d8))();

        uStack_1a4 = DAT_00a0f710;

        if (*(char *)(iVar9 + 0x30c) == '\0') {

          uStack_1a4 = (uint8_t *)g_flOverheatCoolFrac;

        }

        iVar9 = (**(code **)(*piVar12 + 0x1d8))();

        uStack_1ac = DAT_00aaa68c;

        if (*(char *)(iVar9 + 0x30c) == '\0') {

          uStack_1ac = DAT_00aaab3c;

        }

        (**(code **)(*piVar12 + 0x1d8))();

        fVar18 = (float10)FUN_004c4e20();

        puStack_190 = (uint8_t *)(float)fVar18;

        puVar16 = uStack_1a4;

        if (((piVar12[0x2d] & 0x1000U) != 0) ||

           (fStack_144 = (float)puStack_190, puVar16 = uStack_1ac, (piVar12[0x2d] & 0x4000U) != 0))

        {

          fStack_144 = ((float)puVar16 - g_flOne) + (float)puStack_190 * (float)puVar16;

        }

        fStack_144 = fStack_144 * DAT_00aaa7ac;

        puStack_18c = (uint8_t *)(int)ROUND(fStack_144);

        sprintf((char *)apuStack_120,"%+d%%");

        FUN_00755ab0();

        FUN_0040ada0();

        ppuStack_1e4 = apuStack_120;

        puStack_190 = (uint8_t *)&ppuStack_1e4;

        ppuStack_1e8 = (uint8_t **)&ppuStack_1e4;

        ppuStack_1ec = (uint8_t **)0x837341;

        ppuStack_1e0 = ppuStack_1e4;

        FUN_0040aeb0();

        puVar5 = puStack_15c;

        puStack_180 = puStack_19c + (-(int)puStack_194 - (int)puStack_15c);

        puStack_184 = puVar15 + ((iStack_150 - (int)puStack_160) / 2 - iVar8) + (int)puStack_174;

        uStack_4 = 0xffffffff;

        ppuStack_1e8 = (uint8_t **)&uStack_1a0;

        ppuStack_1ec = &puStack_184;

        piStack_1f0 = param_2;

        FUN_00759730();

        FUN_0040ada0();

        fVar14 = fStack_168;

        puVar16 = puStack_16c;

        if ((int)puStack_198 <= (int)(puVar5 + (int)puStack_194)) {

          puStack_198 = puVar5 + (int)puStack_194;

        }

      }

    }

    fStack_168 = (float)((int)fVar14 + 1);

    puVar15 = puVar16;

  } while ((int)fStack_168 < 0x20);

  iVar8 = *(int *)(*(int *)(iStack_164 + 4) + 4);

  *(float *)(iVar8 + 0x11c + iStack_164) =

       (float)(int)puStack_198 + *(float *)(iVar8 + 0x11c + iStack_164);

  ExceptionList = local_c;

  return;

}
