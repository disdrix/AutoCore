// =============================================================================
// FUN_006ea6f0
// -----------------------------------------------------------------------------
// Stable ID: aa_006ea6f0
// Address:   0x006ea6f0  (autoassault.exe, image base 0x400000)
// System:    unknown
// Generated: 2026-07-23 from raw capture (scaffold; refine for important units)
// Exactness: Behavior-preserving rewrite of decompiler control flow. Not modernization.
// Bit-for-bit vs retail EXE: DEFERRED (loaded image may differ slightly).
// =============================================================================

// PURPOSE (auto): Scaffold unit for FUN_006ea6f0 @ 0x006ea6f0
// Stable ID: aa_006ea6f0
// No high-value strings recovered; name via xrefs/callers in follow-up.
// Readability: control flow preserved from Ghidra decompile; types tentative.

// READABILITY (auto CF):
//  - Body size: ~329 non-empty decompiler lines.
//  - Control keywords: if×31, while×7, do×6, goto×4, return×2, for×2.
//  - Notable callees: ABS×10, CONCAT13×9, FUN_006cb7d0×3, FUN_005b3300×2, CONCAT31, FUN_0063a3f0, FUN_006ea4e0, FUN_006ea560.
//  - Return sites: 2.

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

void __thiscall FUN_006ea6f0(int param_1,uint32_t /* width from decompiler */ *param_2,int *param_3,int param_4,code *param_5)



{

  int *piVar1;

  int *piVar2;

  float fVar3;

  int iVar4;

  int iVar5;

  uint uVar6;

  int iVar7;

  char *pcVar8;

  uint *puVar9;

  uint *puVar10;

  uint32_t /* width from decompiler */ uVar11;

  uint uVar12;

  uint32_t /* width from decompiler */ *puVar13;

  uint *puVar14;

  uint *puVar15;

  uint32_t /* width from decompiler */ *unaff_EDI;

  int iVar16;

  uint32_t /* width from decompiler */ *puVar17;

  uint *puVar18;

  uint uStack_401;

  uint8_t uStack_3fd;

  uint *puStack_3fc;

  uint *local_3f4;

  uint *puStack_3f0;

  float fStack_3ec;

  float fStack_3e4;

  float fStack_3e0;

  int *piStack_3d0;

  uint *puStack_3cc;

  uint uStack_3c8;

  float fStack_3bc;

  float fStack_3b8;

  float fStack_3b4;

  float local_3b0;

  float fStack_3ac;

  float fStack_3a8;

  float fStack_3a4;

  float fStack_3a0;

  uint32_t /* width from decompiler */ uStack_39c;

  uint32_t /* width from decompiler */ uStack_398;

  int *piStack_394;

  uint8_t auStack_390 [8];

  int iStack_388;

  int *piStack_384;

  uint8_t auStack_374 [256];

  uint *puStack_274;

  uint *puStack_270;

  uint8_t *puStack_26c;

  uint32_t /* width from decompiler */ uStack_268;

  uint32_t /* width from decompiler */ uStack_264;

  uint8_t auStack_260 [528];

  uint8_t local_50 [76];

  

  FUN_0063a3f0(param_3[2] + 0x20,param_2[2] + 0x20);

  local_3f4 = (uint *)(*(float *)(param_4 + 8) * DAT_00a0f298);

  (**(code **)(*(int *)*param_2 + 0x18))

            (local_50,(float)local_3f4 + *(float *)(param_4 + 8),&local_3b0);

  if (DAT_00af58b8 != '\0') {

    fStack_3ec = ABS(*(float *)(param_1 + 0x30) - fStack_3ac);

    fStack_3e4 = ABS(*(float *)(param_1 + 0x38) - fStack_3a4);

    fStack_3e0 = ABS(*(float *)(param_1 + 0x3c) - fStack_3a0);

    if ((fStack_3e4 <= (float)CONCAT13(uStack_3fd,uStack_401._1_3_) &&

        ABS(*(float *)(param_1 + 0x34) - fStack_3a8) <= (float)CONCAT13(uStack_3fd,uStack_401._1_3_)

        ) && fStack_3ec <= (float)CONCAT13(uStack_3fd,uStack_401._1_3_)) {

      fStack_3ec = ABS(*(float *)(param_1 + 0x20) - fStack_3bc);

      fStack_3e4 = ABS(*(float *)(param_1 + 0x28) - fStack_3b4);

      fStack_3e0 = ABS(*(float *)(param_1 + 0x2c) - local_3b0);

      fVar3 = (float)CONCAT13(uStack_3fd,uStack_401._1_3_);

      uStack_401 = CONCAT31(uStack_401._1_3_,1);

      if (ABS(*(float *)(param_1 + 0x24) - fStack_3b8) <=

          (float)CONCAT13(uStack_3fd,uStack_401._1_3_)) {

        uStack_401 = (uint)uStack_401._1_3_ << 8;

      }

      if ((fStack_3e4 <= (float)CONCAT13(uStack_3fd,uStack_401._1_3_) && (uStack_401 & 0xff) == 0)

          && fStack_3ec <= fVar3) {

        return;

      }

    }

  }

  *(float *)(param_1 + 0x20) = fStack_3bc;

  *(float *)(param_1 + 0x28) = fStack_3b4;

  *(float *)(param_1 + 0x2c) = local_3b0;

  *(float *)(param_1 + 0x24) = fStack_3b8;

  *(float *)(param_1 + 0x34) = fStack_3a8;

  *(float *)(param_1 + 0x30) = fStack_3ac;

  puStack_26c = auStack_260;

  *(float *)(param_1 + 0x38) = fStack_3a4;

  *(float *)(param_1 + 0x3c) = fStack_3a0;

  piVar1 = (int *)*param_3;

  uStack_268 = 0;

  uStack_264 = 0x80000080;

  (**(code **)(*piVar1 + 0x30))(&fStack_3bc,&puStack_26c);

  piStack_394 = (int *)piVar1[3];

  iStack_388 = param_3[2];

  piStack_384 = param_3;

  if (DAT_00d09691 != '\0') {

    uStack_398 = *(uint32_t /* width from decompiler */ *)(param_1 + 8);

    puVar9 = *(uint **)(param_1 + 0xc);

    piVar1 = (int *)(param_1 + 0xc);

    puStack_3fc = puVar9 + *(int *)(param_1 + 0x10) * 3;

    puVar14 = puStack_274 + (int)puStack_270;

    puVar15 = puStack_274;

    puVar18 = puStack_274;

    if (puVar9 != puStack_3fc) {

      do {

        if ((puVar18 == puVar14) || (*puVar9 != *puVar18)) {

          puVar18 = puVar15;

          if (puVar15 != puVar14) {

            do {

              if (*puVar9 == *puVar18) {

                puVar18 = puVar18 + 1;

                goto LAB_006eaa67;

              }

              puVar18 = puVar18 + 1;

            } while (puVar18 != puVar14);

          }

          (**(code **)(*(int *)puVar9[2] + 0x14))();

          *(int *)(param_1 + 0x10) = *(int *)(param_1 + 0x10) + -1;

          iVar4 = ((int)puVar9 - *piVar1) / 0xc;

          if (iVar4 < *(int *)(param_1 + 0x10)) {

            uVar12 = iVar4 * 0xc;

            uStack_3fd = (uint8_t)(uVar12 >> 0x18);

            uVar6 = uVar12;

            do {

              puVar13 = (uint32_t /* width from decompiler */ *)(uVar12 + *piVar1);

              *puVar13 = puVar13[3];

              puVar13[1] = puVar13[4];

              puVar13[2] = puVar13[5];

              uStack_401._1_3_ = (uint3)uVar6;

              iVar4 = iVar4 + 1;

              uVar12 = CONCAT13(uStack_3fd,uStack_401._1_3_) + 0xc;

              uVar6 = uVar12 & 0xffffff;

              uStack_3fd = (uint8_t)(uVar12 >> 0x18);

            } while (iVar4 < *(int *)(param_1 + 0x10));

          }

          puVar9 = puVar9 + -3;

          puStack_3fc = puStack_3fc + -3;

          puVar15 = puStack_274;

        }

        else {

          puVar18 = puVar18 + 1;

        }

LAB_006eaa67:

        puVar9 = puVar9 + 3;

      } while (puVar9 != puStack_3fc);

    }

    puVar9 = *(uint **)(param_1 + 0x10);

    puVar14 = puVar15;

    if (puStack_270 != puVar9) {

      puVar18 = (uint *)*piVar1;

      puStack_3cc = puVar15 + (int)puStack_270;

      uStack_401._1_3_ = (uint3)(puVar18 + (int)puVar9 * 3);

      uStack_3fd = (uint8_t)((uint)(puVar18 + (int)puVar9 * 3) >> 0x18);

      if (puVar15 != puStack_3cc) {

        do {

          if ((puVar18 == (uint *)CONCAT13(uStack_3fd,uStack_401._1_3_)) || (*puVar18 != *puVar15))

          {

            iVar4 = (int)puVar9 + 1;

            iVar16 = (int)puVar15 - (int)puVar14 >> 2;

            iVar5 = (int)puVar9 - iVar16;

            uVar6 = *(uint *)(param_1 + 0x14) & 0x7fffffff;

            if ((int)uVar6 < iVar4) {

              iVar7 = uVar6 * 2;

              if (iVar7 <= iVar4) {

                iVar7 = iVar4;

              }

              FUN_005b3300(piVar1,iVar7,0xc);

            }

            iVar16 = iVar16 * 0xc;

            iVar7 = *piVar1 + iVar16;

            uStack_3c8 = iVar7 + 0xc;

            if (-1 < iVar5 + -1) {

              puVar13 = (uint32_t /* width from decompiler */ *)(uStack_3c8 + (iVar5 + -1) * 0xc);

              uStack_401._1_3_ = (uint3)iVar5;

              uStack_3fd = (uint8_t)((uint)iVar5 >> 0x18);

              do {

                puVar17 = (uint32_t /* width from decompiler */ *)((iVar7 - uStack_3c8) + (int)puVar13);

                *puVar13 = *puVar17;

                puVar13[1] = puVar17[1];

                puVar13[2] = puVar17[2];

                puVar13 = puVar13 + -3;

                iVar5 = CONCAT13(uStack_3fd,uStack_401._1_3_) + -1;

                uStack_401._1_3_ = (uint3)iVar5;

                uStack_3fd = (uint8_t)((uint)iVar5 >> 0x18);

              } while (iVar5 != 0);

            }

            *(int *)(param_1 + 0x10) = iVar4;

            piVar2 = (int *)*puVar15;

            puVar18 = (uint *)(*piVar1 + iVar16);

            uStack_398 = (**(code **)(*piStack_394 + 0x34))(piVar2,auStack_374);

            piStack_394 = piVar2;

            pcVar8 = (char *)(**(code **)**(uint32_t /* width from decompiler */ **)(param_4 + 4))

                                       (&stack0xfffffbef,param_4,param_2,&uStack_398,uStack_39c,

                                        *unaff_EDI);

            if (*pcVar8 == '\0') {

              uVar6 = FUN_006cb7d0();

            }

            else {

              uVar6 = (*param_5)(param_2,auStack_390,param_4,uStack_398);

            }

            puVar18[2] = uVar6;

            *puVar18 = *puVar15;

            puVar9 = *(uint **)(param_1 + 0x10);

            iVar4 = *piVar1 + (int)puVar9 * 0xc;

            uStack_401._1_3_ = (uint3)iVar4;

            uStack_3fd = (uint8_t)((uint)iVar4 >> 0x18);

            puVar14 = puStack_274;

          }

          puVar15 = puVar15 + 1;

          puVar18 = puVar18 + 3;

        } while (puVar15 != puStack_3cc);

      }

    }

    goto LAB_006eaf2d;

  }

  puStack_3cc = (uint *)((uint)puStack_3cc & 0xffffff00);

  if (1 < (int)puStack_270) {

    FUN_006ea4e0(puStack_274,0,(int)puStack_270 + -1,puStack_3cc);

  }

  puVar18 = puStack_274;

  uVar11 = *(uint32_t /* width from decompiler */ *)(param_1 + 8);

  puVar15 = *(uint **)(param_1 + 0xc);

  puVar14 = puVar15 + *(int *)(param_1 + 0x10) * 3;

  puVar9 = puStack_274 + (int)puStack_270;

  FUN_006ea560(puStack_270);

  puStack_3cc = puStack_270;

  puStack_3f0 = puStack_270;

  puVar10 = local_3f4;

  if ((int)ABS(fStack_3ec) < (int)puStack_270) {

    puVar10 = (uint *)((int)ABS(fStack_3ec) * 2);

    if ((int)puVar10 <= (int)puStack_270) {

      puVar10 = puStack_270;

    }

    FUN_005b3300(&local_3f4,puVar10,0xc);

    puStack_3f0 = puStack_3cc;

    puVar10 = local_3f4;

  }

  while (puVar15 != puVar14) {

    if (puVar18 == puVar9) goto joined_r0x006eadd3;

    uStack_3c8 = *puVar18;

    if (uStack_3c8 == *puVar15) {

      *puVar10 = *puVar15;

      puVar10[1] = puVar15[1];

      puVar10[2] = puVar15[2];

      puVar10 = puVar10 + 3;

      puVar15 = puVar15 + 3;

      puVar18 = puVar18 + 1;

    }

    else if (uStack_3c8 < *puVar15) {

      uStack_398 = (**(code **)(*piStack_394 + 0x34))(uStack_3c8,auStack_374);

      piStack_394 = piStack_3d0;

      pcVar8 = (char *)(**(code **)**(uint32_t /* width from decompiler */ **)(param_4 + 4))

                                 (&stack0xfffffbef,param_4,param_2,&uStack_398,uStack_39c,*puVar18);

      if (*pcVar8 == '\0') {

        uVar6 = FUN_006cb7d0();

        puVar10[2] = uVar6;

      }

      else {

        uVar6 = (*param_5)(param_2,auStack_390,param_4,uVar11);

        puVar10[2] = uVar6;

      }

      *puVar10 = *puVar18;

      puVar10 = puVar10 + 3;

      puVar18 = puVar18 + 1;

    }

    else {

      if ((int *)puVar15[2] != (int *)0x0) {

        (**(code **)(*(int *)puVar15[2] + 0x14))();

      }

      puVar15 = puVar15 + 3;

    }

  }

joined_r0x006eadf2:

  for (; puVar18 != puVar9; puVar18 = puVar18 + 1) {

    piVar1 = (int *)*puVar18;

    uStack_398 = (**(code **)(*piStack_394 + 0x34))(piVar1,auStack_374);

    piStack_394 = piVar1;

    pcVar8 = (char *)(**(code **)**(uint32_t /* width from decompiler */ **)(param_4 + 4))

                               (&stack0xfffffbef,param_4,param_2,&uStack_398,uStack_39c,*puVar18);

    if (*pcVar8 == '\0') {

      uVar6 = FUN_006cb7d0();

      puVar10[2] = uVar6;

    }

    else {

      uVar6 = (*param_5)(param_2,auStack_390,param_4,uVar11);

      puVar10[2] = uVar6;

    }

    *puVar10 = *puVar18;

    puVar10 = puVar10 + 3;

  }

  uVar6 = *(uint *)(param_1 + 0x14) & 0x7fffffff;

  if ((int)uVar6 < (int)puStack_3f0) {

    if (-1 < (int)*(uint *)(param_1 + 0x14)) {

      (**(code **)(*DAT_00b05060 + 0x14))(*(uint32_t /* width from decompiler */ *)(param_1 + 0xc),uVar6 * 0xc,0x12);

    }

    uVar11 = (**(code **)(*DAT_00b05060 + 0x10))((int)puStack_3f0 * 0xc,0x12);

    *(uint32_t /* width from decompiler */ *)(param_1 + 0xc) = uVar11;

    *(uint **)(param_1 + 0x14) = puStack_3f0;

  }

  puVar14 = *(uint **)(param_1 + 0xc);

  *(uint **)(param_1 + 0x10) = puStack_3f0;

  puVar9 = local_3f4;

  puVar15 = puStack_3f0;

  if (0 < (int)puStack_3f0) {

    do {

      *puVar14 = *puVar9;

      puVar14[1] = puVar9[1];

      puVar15 = (uint *)((int)puVar15 + -1);

      puVar14[2] = puVar9[2];

      puVar9 = puVar9 + 3;

      puVar14 = puVar14 + 3;

    } while (puVar15 != (uint *)0x0);

  }

  FUN_006ea5d0();

  puVar14 = puStack_274;

LAB_006eaf2d:

  if (-1 < (int)puStack_26c) {

    (**(code **)(*DAT_00b05060 + 0x14))(puVar14,(int)puStack_26c << 2,0x12);

  }

  return;

joined_r0x006eadd3:

  for (; puVar15 != puVar14; puVar15 = puVar15 + 3) {

    if ((int *)puVar15[2] != (int *)0x0) {

      (**(code **)(*(int *)puVar15[2] + 0x14))();

    }

  }

  goto joined_r0x006eadf2;

}
