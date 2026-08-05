// =============================================================================
// FUN_00940ed0
// -----------------------------------------------------------------------------
// Stable ID: aa_00940ed0
// Address:   0x00940ed0  (autoassault.exe, image base 0x400000)
// System:    unknown
// Generated: 2026-07-23 from raw capture (scaffold; refine for important units)
// Exactness: Behavior-preserving rewrite of decompiler control flow. Not modernization.
// Bit-for-bit vs retail EXE: DEFERRED (loaded image may differ slightly).
// =============================================================================

// PURPOSE (auto): Scaffold unit for FUN_00940ed0 @ 0x00940ed0
// Stable ID: aa_00940ed0
// No high-value strings recovered; name via xrefs/callers in follow-up.
// Readability: control flow preserved from Ghidra decompile; types tentative.

// READABILITY (auto CF):
//  - Body size: ~258 non-empty decompiler lines.
//  - Control keywords: if×25, return×5, goto×2, do×1, while×1.
//  - Notable callees: ROUND×5, CONCAT31×2, CVOGReaction_ResolveObjectTarget, FUN_00404c90, FUN_0040aef0, FUN_00415e90, FUN_004e88e0, FUN_005134e0.
//  - Return sites: 5.

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

void FUN_00940ed0(int param_1)



{

  float fVar1;

  float fVar2;

  float fVar3;

  int *piVar4;

  int iVar5;

  void *pvVar6;

  char cVar7;

  int *piVar8;

  int iVar9;

  int iVar10;

  uint32_t /* width from decompiler */ *puVar11;

  int iVar12;

  int *piVar13;

  uint32_t /* width from decompiler */ *puStack_d0;

  uint32_t /* width from decompiler */ uStack_cc;

  uint32_t /* width from decompiler */ uStack_c8;

  uint32_t /* width from decompiler */ uStack_c4;

  uint32_t /* width from decompiler */ uStack_c0;

  int *piStack_bc;

  float *pfStack_b8;

  float fStack_a0;

  int *local_9c;

  uint8_t uStack_68;

  int local_60;

  int iStack_5c;

  int iStack_4c;

  float local_48;

  float local_44;

  float local_40;

  uint8_t auStack_3c [12];

  uint32_t /* width from decompiler */ uStack_30;

  uint32_t /* width from decompiler */ uStack_2c;

  uint32_t /* width from decompiler */ uStack_28;

  uint32_t /* width from decompiler */ uStack_24;

  void *local_1c;

  uint8_t *puStack_18;

  uint32_t /* width from decompiler */ uStack_14;

  

  uStack_14 = 0xffffffff;

  puStack_18 = &LAB_009bb2ea;

  local_1c = ExceptionList;

  if ((*(int *)(param_1 + 0xe98) != 0) && (*(char *)(*(int *)(param_1 + 0xe98) + 0x4f1) != '\0')) {

    ExceptionList = &local_1c;

    FUN_00415e90();

    ExceptionList = local_1c;

    return;

  }

  pfStack_b8 = (float *)0x940f32;

  ExceptionList = &local_1c;

  FUN_0093ffb0();

  piVar4 = *(int **)(*(int *)(param_1 + 0xe04) + 0xe890);

  piVar13 = (int *)**(int **)(param_1 + 0xaac);

  fVar1 = *(float *)(DAT_00d09874 + 0x30);

  if (piVar13 != *(int **)(param_1 + 0xaac)) {

    do {

      iVar9 = piVar13[2];

      local_48 = *(float *)(iVar9 + 4);

      local_44 = *(float *)(iVar9 + 8);

      local_40 = *(float *)(iVar9 + 0xc);

      iVar9 = piVar13[2];

      if (((*(uint *)(iVar9 + 0x38) & *(uint *)(iVar9 + 0x3c)) != 0xffffffff) ||

         (*(char *)(iVar9 + 0x40) != '\0')) {

        pfStack_b8 = *(float **)(iVar9 + 0x38);

        piStack_bc = (int *)CONCAT31((int3)((uint)iVar9 >> 8),*(uint8_t *)(iVar9 + 0x40));

        uStack_c0 = 0x940fbf;

        piVar8 = (int *)CVOGReaction_ResolveObjectTarget();

        if (((piVar8 != (int *)0x0) && (cVar7 = FUN_005134e0(), cVar7 == '\0')) &&

           (((iVar9 = *(int *)(piVar8[0x2a] + 0x38), iVar9 == 0xe || (iVar9 == 0x12)) ||

            (iVar9 == 0x14)))) {

          iVar9 = (**(code **)(*piVar8 + 0x1d4))();

          if ((iVar9 == 0) || (*(int *)(*(int *)(*(int *)(iVar9 + 4) + 4) + 0xb0 + iVar9) == 0)) {

            iVar10 = (**(code **)(*piVar8 + 0x1d8))();

            if (iVar10 == 0) goto LAB_00941277;

            iVar12 = *(int *)(iVar10 + 0x250);

            if ((iVar12 == 0) || (*(char *)(iVar10 + 0x30c) == '\0')) {

              local_9c = *(int **)(iVar10 + 0x48);

              if (*(int *)(iVar10 + 8) == 0) {

                puVar11 = (uint32_t /* width from decompiler */ *)(*(int *)(*(int *)(iVar10 + 4) + 4) + 0x84 + iVar10);

              }

              else {

                puVar11 = (uint32_t /* width from decompiler */ *)(*(int *)(*(int *)(iVar10 + 8) + 0x3c) + 0xb0);

              }

            }

            else {

              local_9c = *(int **)(iVar12 + 0x48);

              puVar11 = (uint32_t /* width from decompiler */ *)FUN_00404c90();

              iVar9 = iVar12;

            }

          }

          else {

            iVar10 = (**(code **)(*(int *)(*(int *)(*(int *)(iVar9 + 4) + 4) + 4 + iVar9) + 0x214))

                               ();

            local_9c = *(int **)(iVar9 + 0x48);

            if (*(int *)(iVar9 + 8) == 0) {

              puVar11 = (uint32_t /* width from decompiler */ *)(*(int *)(*(int *)(iVar9 + 4) + 4) + 0x84 + iVar9);

            }

            else {

              puVar11 = (uint32_t /* width from decompiler */ *)(*(int *)(*(int *)(iVar9 + 8) + 0x3c) + 0xb0);

            }

          }

          uStack_30 = *puVar11;

          uStack_2c = puVar11[1];

          uStack_28 = puVar11[2];

          uStack_24 = puVar11[3];

          if (local_9c != (int *)0x0) {

            pfStack_b8 = (float *)auStack_3c;

            piStack_bc = (int *)0x941106;

            puVar11 = (uint32_t /* width from decompiler */ *)FUN_004e88e0();

            iVar12 = piVar13[2];

            *(uint32_t /* width from decompiler */ *)(iVar12 + 0x10) = *puVar11;

            *(uint32_t /* width from decompiler */ *)(iVar12 + 0x14) = puVar11[1];

            *(uint32_t /* width from decompiler */ *)(iVar12 + 0x18) = puVar11[2];

            iVar12 = (**(code **)(*local_9c + 0x54))();

            fStack_a0 = *(float *)(iVar12 + 0x24);

            if (iVar9 != 0) {

              fStack_a0 = fStack_a0 + g_flOne;

            }

            if (((iVar10 == 0) || (*(int **)(iVar10 + 0x284) == (int *)0x0)) ||

               (iVar12 = (**(code **)(**(int **)(iVar10 + 0x284) + 0x54))(),

               *(char *)(iVar12 + 0x2c) != '\0')) {

              if (((iVar9 != 0) && (*(int **)(iVar9 + 0x3a0) != (int *)0x0)) &&

                 (iVar12 = (**(code **)(**(int **)(iVar9 + 0x3a0) + 0x54))(),

                 *(char *)(iVar12 + 0x2c) == '\0')) {

                iVar9 = **(int **)(iVar9 + 0x3a0);

                goto LAB_0094118b;

              }

            }

            else {

              iVar9 = **(int **)(iVar10 + 0x284);

LAB_0094118b:

              iVar9 = (**(code **)(iVar9 + 0x54))();

              fStack_a0 = *(float *)(iVar9 + 0x24) + fStack_a0;

            }

            if (DAT_00aaa690 < fStack_a0) {

              fStack_a0 = DAT_00aaa690;

            }

            if (*(int *)(param_1 + 0xe98) != 0) {

              iVar9 = *(int *)(*(int *)(iVar10 + 4) + 4);

              iStack_4c = *(int *)(iVar9 + 0x168 + iVar10);

              iVar12 = *(int *)(param_1 + 0xe98);

              iVar5 = *(int *)(*(int *)(iVar12 + 4) + 4);

              if (((*(int *)(iVar9 + 0x164 + iVar10) == *(int *)(iVar5 + 0x164 + iVar12)) &&

                  (iStack_4c == *(int *)(iVar5 + 0x168 + iVar12))) &&

                 (g_flVehicleHpTechCoeff < fStack_a0)) {

                fStack_a0 = g_flVehicleHpTechCoeff;

              }

            }

            iVar9 = *(int *)(param_1 + 0xde8);

            fVar2 = *(float *)(iVar9 + 0x218);

            fVar3 = *(float *)(iVar9 + 0x214);

            iVar10 = piVar13[2];

            *(float *)(iVar10 + 0x10) =

                 *(float *)(iVar10 + 0x10) + *(float *)(iVar9 + 0x210) * fStack_a0;

            *(float *)(iVar10 + 0x14) = fVar3 * fStack_a0 + *(float *)(iVar10 + 0x14);

            *(float *)(iVar10 + 0x18) = fVar2 * fStack_a0 + *(float *)(iVar10 + 0x18);

          }

        }

LAB_00941277:

        iVar9 = piVar13[2];

        local_48 = *(float *)(iVar9 + 0x10) + local_48;

        local_44 = *(float *)(iVar9 + 0x14) + local_44;

        local_40 = *(float *)(iVar9 + 0x18) + local_40;

      }

      pfStack_b8 = &local_48;

      piStack_bc = (int *)0x9412c3;

      cVar7 = (**(code **)(*piVar4 + 4))();

      if (cVar7 != '\0') {

        iVar9 = piVar13[2];

        if (*(int *)(iVar9 + 0x5c) == 0) {

          if ((*(uint *)(iVar9 + 0x48) & 0x3fffffff) != 0x3fcb8608) {

            iStack_5c = iStack_5c + (int)ROUND(*(float *)(iVar9 + 0x50));

            pfStack_b8 = (float *)0x94138f;

            piVar8 = (int *)FUN_00755ab0();

            local_60 = local_60 -

                       (int)ROUND((float)*piVar8 * DAT_00a0f298 - *(float *)(piVar13[2] + 0x4c));

            puStack_d0 = (uint32_t /* width from decompiler */ *)piVar13[2];

            uStack_cc = *puStack_d0;

            pfStack_b8 = (float *)0x3f800000;

            piStack_bc = (int *)0x1;

            uStack_c0 = 0;

            uStack_c4 = 0;

            uStack_c8 = 0xffffffff;

            FUN_0040aef0(&puStack_d0);

            uStack_14 = 0xffffffff;

            FUN_00759730(*(uint32_t /* width from decompiler */ *)(*(int *)(param_1 + 0xde8) + 0x2c),&local_60,

                         piVar13[2] + 0x24);

          }

        }

        else {

          local_60 = local_60 -

                     (int)ROUND((float)DAT_00d1e818 * DAT_00a0f298 - *(float *)(iVar9 + 0x4c));

          iStack_5c = iStack_5c + (int)ROUND(*(float *)(piVar13[2] + 0x50));

          iVar9 = piVar13[2];

          uStack_c0 = *(uint32_t /* width from decompiler */ *)(iVar9 + 0x5c);

          uStack_c8 = CONCAT31((int3)((uint)iVar9 >> 8),*(uint8_t *)(iVar9 + 0x27));

          pfStack_b8 = (float *)0x0;

          piStack_bc = &local_60;

          uStack_c4 = 0;

          uStack_cc = 0x3f800000;

          puStack_d0 = (uint32_t /* width from decompiler */ *)0x0;

          FUN_007b4730(*(uint32_t /* width from decompiler */ *)(*(int *)(param_1 + 0xde8) + 0x2c));

        }

      }

      *(float *)(piVar13[2] + 0x1c) = *(float *)(piVar13[2] + 0x1c) - fVar1;

      puVar11 = (uint32_t /* width from decompiler */ *)piVar13[2];

      if (0.0 < (float)puVar11[7]) {

        puVar11[2] = (float)puVar11[0xb] * fVar1 + (float)puVar11[2];

        puVar11[3] = (float)puVar11[0xc] * fVar1 + (float)puVar11[3];

        puVar11[1] = (float)puVar11[1] + (float)puVar11[10] * fVar1;

        iVar9 = piVar13[2];

        *(float *)(iVar9 + 0x4c) = *(float *)(iVar9 + 0x54) * fVar1 + *(float *)(iVar9 + 0x4c);

        *(float *)(iVar9 + 0x50) = *(float *)(iVar9 + 0x58) * fVar1 + *(float *)(iVar9 + 0x50);

        iVar9 = piVar13[2];

        if (0.0 < *(float *)(iVar9 + 0x20)) {

          uStack_68 = (uint8_t)

                      (int)ROUND((*(float *)(iVar9 + 0x1c) / *(float *)(iVar9 + 0x20)) *

                                 DAT_00aaa6f8);

          *(uint8_t *)(piVar13[2] + 0x27) = uStack_68;

        }

        piVar8 = (int *)*piVar13;

      }

      else {

        if ((void *)*puVar11 != (void *)0x0) {

          pfStack_b8 = (float *)0x941456;

          operator_delete__((void *)*puVar11);

        }

        *(uint32_t /* width from decompiler */ *)piVar13[2] = 0;

        pvVar6 = *(void **)(piVar13[2] + 0x5c);

        if (pvVar6 != (void *)0x0) {

          pfStack_b8 = (float *)0x941472;

          FUN_00797d70();

                    /* WARNING: Subroutine does not return */

          pfStack_b8 = (float *)&UNK_00941478;

          operator_delete(pvVar6);

        }

        *(uint32_t /* width from decompiler */ *)(piVar13[2] + 0x5c) = 0;

        if ((void *)piVar13[2] != (void *)0x0) {

                    /* WARNING: Subroutine does not return */

          pfStack_b8 = (float *)&UNK_00941492;

          operator_delete((void *)piVar13[2]);

        }

        piVar13[2] = 0;

        piVar8 = (int *)*piVar13;

        if (piVar13 != *(int **)(param_1 + 0xaac)) {

          *(int **)piVar13[1] = piVar8;

          *(int *)(*piVar13 + 4) = piVar13[1];

                    /* WARNING: Subroutine does not return */

          pfStack_b8 = (float *)&UNK_009414b9;

          operator_delete(piVar13);

        }

      }

      piVar13 = piVar8;

    } while (piVar8 != *(int **)(param_1 + 0xaac));

  }

  ExceptionList = local_1c;

  return;

}
