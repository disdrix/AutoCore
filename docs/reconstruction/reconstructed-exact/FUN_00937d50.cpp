// =============================================================================
// FUN_00937d50
// -----------------------------------------------------------------------------
// Stable ID: aa_00937d50
// Address:   0x00937d50  (autoassault.exe, image base 0x400000)
// System:    unknown
// Generated: 2026-07-23 from raw capture (scaffold; refine for important units)
// Exactness: Behavior-preserving rewrite of decompiler control flow. Not modernization.
// Bit-for-bit vs retail EXE: DEFERRED (loaded image may differ slightly).
// =============================================================================

// PURPOSE (auto): Scaffold unit for FUN_00937d50 @ 0x00937d50
// Stable ID: aa_00937d50
// No high-value strings recovered; name via xrefs/callers in follow-up.
// Readability: control flow preserved from Ghidra decompile; types tentative.

// READABILITY (auto CF):
//  - Body size: ~242 non-empty decompiler lines.
//  - Control keywords: if×20, return×6, do×2, while×2, goto×2.
//  - Notable callees: CONCAT31, FUN_00406320, FUN_0040aef0, FUN_005134e0, FUN_00755ab0, FUN_00759730, FUN_00797d70, FUN_007b3540.
//  - Return sites: 6.

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

void FUN_00937d50(int param_1)



{

  float fVar1;

  int *piVar2;

  uint32_t /* width from decompiler */ *puVar3;

  void *pvVar4;

  int *piVar5;

  void **ppvVar6;

  char cVar7;

  uint uVar8;

  int *piVar9;

  int iVar10;

  int iVar11;

  float *pfVar12;

  int iVar13;

  uint32_t /* width from decompiler */ extraout_ECX;

  uint uVar14;

  float fVar15;

  uint32_t /* width from decompiler */ uStack_b4;

  uint32_t /* width from decompiler */ uStack_b0;

  uint32_t /* width from decompiler */ uStack_ac;

  int iStack_a8;

  int iStack_a4;

  int *piStack_a0;

  float *pfStack_9c;

  int *local_84;

  uint local_80;

  uint32_t /* width from decompiler */ uStack_6c;

  int iStack_68;

  int iStack_64;

  int iStack_60;

  int local_5c;

  int iStack_58;

  int iStack_54;

  int iStack_50;

  float fStack_4c;

  float fStack_48;

  float fStack_44;

  int *local_30;

  int local_2c;

  uint32_t /* width from decompiler */ local_28;

  uint32_t /* width from decompiler */ uStack_24;

  uint32_t /* width from decompiler */ uStack_20;

  uint32_t /* width from decompiler */ uStack_1c;

  uint32_t /* width from decompiler */ uStack_18;

  uint32_t /* width from decompiler */ uStack_14;

  int iStack_10;

  void *local_c;

  uint8_t *puStack_8;

  uint local_4;

  

  puStack_8 = &LAB_009b2ce5;

  local_c = ExceptionList;

  fVar1 = *(float *)(DAT_00d09874 + 0x68);

  piVar2 = *(int **)(*(int *)(param_1 + 0xe04) + 0xe890);

  local_30 = (int *)0x0;

  local_2c = 0;

  local_28 = 0;

  local_4 = 0;

  local_84 = (int *)**(int **)(param_1 + 0xac4);

  ExceptionList = &local_c;

  ppvVar6 = &local_c;

  if (local_84 != *(int **)(param_1 + 0xac4)) {

    do {

      ExceptionList = ppvVar6;

      uVar14 = 0;

      puVar3 = (uint32_t /* width from decompiler */ *)local_84[2];

      fVar15 = (float)puVar3[7] - fVar1;

      puVar3[7] = fVar15;

      if (0.0 < fVar15) {

        if (local_30 == (int *)0x0) {

          uVar8 = 0;

        }

        else {

          uVar8 = (local_2c - (int)local_30) / 0x18;

        }

        local_80 = 0;

        piVar9 = local_30;

        if (uVar8 != 0) {

          do {

            if (((*piVar9 == puVar3[0xe]) && (piVar9[1] == puVar3[0xf])) &&

               (local_80 = uVar14, (char)piVar9[2] == *(char *)(puVar3 + 0x10))) break;

            uVar14 = uVar14 + 1;

            piVar9 = piVar9 + 6;

            local_80 = uVar14;

          } while (uVar14 < uVar8);

        }

        if (local_80 == uVar8) {

          piVar9 = (int *)FUN_0092ff00();

          if (((piVar9 != (int *)0x0) && (iVar10 = (**(code **)(*piVar9 + 0x19c))(), iVar10 != 0))

             && (piVar9 = (int *)(*(int *)(*(int *)(iVar10 + 4) + 4) + 4 + iVar10),

                piVar9 != (int *)0x0)) {

            iVar10 = (**(code **)(*piVar9 + 0x1cc))();

            if ((iVar10 == 0) || (*(int *)(iVar10 + 8) == 0)) {

              piVar9 = (int *)*local_84;

              goto LAB_00938276;

            }

            iVar11 = (**(code **)(*piVar9 + 0x1c8))();

            piVar5 = *(int **)(iVar10 + 8);

            (**(code **)(*piVar5 + 0x54))();

            pfStack_9c = (float *)0x937f39;

            (**(code **)(*piVar5 + 0xc))();

            pfStack_9c = (float *)0x937f42;

            pfVar12 = (float *)FUN_00972fa0();

            fStack_4c = *pfVar12;

            fStack_48 = pfVar12[1];

            fStack_44 = pfVar12[2];

            fVar15 = g_flOne;

            if (iVar11 != 0) {

              fVar15 = *(float *)(*(int *)(*(int *)(iVar11 + 4) + 4) + 0xbc + iVar11);

            }

            piVar5 = *(int **)(iVar10 + 8);

            iVar11 = (**(code **)(*piVar5 + 0x54))();

            iVar13 = (**(code **)(*piVar5 + 0x54))();

            iVar10 = *(int *)(param_1 + 0xde8);

            fVar15 = (*(float *)(iVar11 + 0x24) * DAT_00a0f298 + *(float *)(iVar13 + 0xc)) * fVar15

                     * DAT_00a0f298;

            fStack_4c = *(float *)(iVar10 + 0x210) * fVar15 + fStack_4c;

            fStack_48 = fStack_48 + *(float *)(iVar10 + 0x214) * fVar15;

            fStack_44 = fStack_44 + *(float *)(iVar10 + 0x218) * fVar15;

            pfStack_9c = &fStack_4c;

            piStack_a0 = (int *)0x938029;

            cVar7 = (**(code **)(*piVar2 + 4))();

            if (cVar7 == '\0') {

              uStack_6c = 0xffffffff;

            }

            if (((uint)piVar9[0x61] >> 1 & 1) != 0) {

              iStack_68 = iStack_68 - (int)(float)piVar9[0x46];

            }

            cVar7 = FUN_005134e0();

            if ((cVar7 != '\0') || (cVar7 = (**(code **)(*piVar9 + 0x198))(), cVar7 != '\0')) {

              uStack_6c = 0xffffffff;

            }

            uStack_24 = puVar3[0xe];

            uStack_1c = puVar3[0x10];

            uStack_20 = puVar3[0xf];

            uStack_18 = puVar3[0x11];

            iStack_10 = iStack_68;

            uStack_14 = uStack_6c;

            FUN_00406320();

            goto LAB_009380ba;

          }

        }

        else {

LAB_009380ba:

          piVar9 = local_30;

          if ((-1 < local_30[local_80 * 6 + 4]) && (-1 < local_30[local_80 * 6 + 5])) {

            iVar10 = local_30[local_80 * 6 + 5];

            iVar11 = local_30[local_80 * 6 + 4];

            if (puVar3[0x17] == 0) {

              pfStack_9c = (float *)0x9381cc;

              FUN_00755ab0();

              iVar10 = (iVar10 + -6) - iStack_50;

              pfStack_9c = (float *)0x3f800000;

              piStack_a0 = (int *)0x1;

              iStack_a4 = 0;

              iStack_a8 = 0;

              iStack_64 = iVar11 - iStack_54 / 2;

              uStack_b0 = *puVar3;

              uStack_ac = 0xffffffff;

              uStack_b4 = extraout_ECX;

              iStack_60 = iVar10;

              FUN_0040aef0(&uStack_b4);

              local_4 = local_4 & 0xffffff00;

              FUN_00759730(*(uint32_t /* width from decompiler */ *)(*(int *)(param_1 + 0xde8) + 0x2c),&iStack_64,puVar3 + 9);

            }

            else {

              pfStack_9c = (float *)&local_5c;

              piStack_a0 = (int *)0x9380f8;

              FUN_007b3540();

              iStack_64 = iVar11 - (int)((float)(*(int *)(param_1 + 0xacc) / 2) *

                                         (float)DAT_00d1e818 * DAT_00aaa67c);

              iStack_a4 = (iVar10 + -6) - iStack_58;

              pfStack_9c = (float *)(iStack_58 + iStack_a4);

              piStack_a0 = (int *)(piVar9[local_80 * 6 + 4] + local_5c / 2);

              iStack_a8 = piVar9[local_80 * 6 + 4] - local_5c / 2;

              uStack_ac = 0x938170;

              iStack_60 = iStack_a4;

              FUN_0092d600();

              pfStack_9c = (float *)0x0;

              iStack_a4 = puVar3[0x17];

              piStack_a0 = &iStack_64;

              uStack_ac = CONCAT31((int3)((uint)piStack_a0 >> 8),*(uint8_t *)((int)puVar3 + 0x27)

                                  );

              iStack_a8 = 0;

              uStack_b0 = 0x3f800000;

              uStack_b4 = 0;

              FUN_007b4730(*(uint32_t /* width from decompiler */ *)(*(int *)(param_1 + 0xde8) + 0x2c));

              iVar10 = iStack_60;

            }

            piVar9[local_80 * 6 + 5] = iVar10;

          }

          if ((float)puVar3[7] <= g_flOne) {

            *(char *)((int)puVar3 + 0x27) = (char)(int)((float)puVar3[7] * DAT_00aaa6f8);

          }

        }

        piVar9 = (int *)*local_84;

      }

      else {

        pvVar4 = *(void **)(local_84[2] + 0x5c);

        if (pvVar4 != (void *)0x0) {

          pfStack_9c = (float *)0x937dfd;

          FUN_00797d70();

                    /* WARNING: Subroutine does not return */

          pfStack_9c = (float *)&UNK_00937e03;

          operator_delete(pvVar4);

        }

        *(uint32_t /* width from decompiler */ *)(local_84[2] + 0x5c) = 0;

        if (*(void **)local_84[2] != (void *)0x0) {

                    /* WARNING: Subroutine does not return */

          pfStack_9c = (float *)&UNK_00937e1b;

          operator_delete(*(void **)local_84[2]);

        }

        *(uint32_t /* width from decompiler */ *)local_84[2] = 0;

        if ((void *)local_84[2] != (void *)0x0) {

                    /* WARNING: Subroutine does not return */

          pfStack_9c = (float *)&UNK_00937e30;

          operator_delete((void *)local_84[2]);

        }

        local_84[2] = 0;

        piVar9 = (int *)*local_84;

        if (local_84 != *(int **)(param_1 + 0xac4)) {

          *(int **)local_84[1] = (int *)*local_84;

          *(int *)(*local_84 + 4) = local_84[1];

                    /* WARNING: Subroutine does not return */

          pfStack_9c = (float *)&UNK_00937e53;

          operator_delete(local_84);

        }

      }

LAB_00938276:

      local_84 = piVar9;

      ppvVar6 = ExceptionList;

    } while (local_84 != *(int **)(param_1 + 0xac4));

  }

  local_4 = 0xffffffff;

  if (local_30 == (int *)0x0) {

    ExceptionList = local_c;

    return;

  }

                    /* WARNING: Subroutine does not return */

  pfStack_9c = (float *)&UNK_009382a1;

  operator_delete(local_30);

}
