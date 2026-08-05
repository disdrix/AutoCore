// =============================================================================
// Named_CalleeOf_Named_CalleeOf_Named_CalleeOf_Named_CalleeOf_Cli_00595230
// -----------------------------------------------------------------------------
// Stable ID: aa_00595230
// Callee of Named_CalleeOf_Named_CalleeOf_Named_CalleeOf_Client_Input_PollB
// Address:   0x00595230  (autoassault.exe, image base 0x400000)
// System:    unknown
// Generated: 2026-07-23 from raw capture (scaffold; refine for important units)
// Exactness: Behavior-preserving rewrite of decompiler control flow. Not modernization.
// Bit-for-bit vs retail EXE: DEFERRED (loaded image may differ slightly).
// =============================================================================

// PURPOSE (auto): Called from Named_CalleeOf_Named_CalleeOf_Named_CalleeOf_Client_Input_PollB: input/binding helper. Evidence string: "Time etc..". Supports parent flow (not a free-standing entry point).
// Embedded strings (evidence):
//   - "Time etc.."
//   - "Update Parent Pos"
//   - "Geo found at 0,0,0: %d %I64d"
// Readability: control flow preserved from Ghidra decompile; types tentative.

// READABILITY (auto CF):
//  - Body size: ~409 non-empty decompiler lines.
//  - Control keywords: if×33, return×7, do×2, while×2, goto×1.
//  - Notable callees: FUN_004e88e0×5, FUN_0076cef0×4, FUN_005b83e0×3, FUN_0076cf00×2, CVOGReaction_RandomUnitScalar, FUN_004b6960, FUN_004b6980, FUN_004e87d0.
//  - Strings: "Time etc.."; "Update Parent Pos"; "Geo found at 0,0,0: %d %I64d".
//  - Return sites: 7.

/*
 * Behavioral notes:
 * Callee of Named_CalleeOf_Named_CalleeOf_Named_CalleeOf_Client_Input_PollB
 * Xref/callee-driven rename (parent seed scan)
 *
 * - Derived from Ghidra decompile; names prefer Ghidra symbols / plate comments.
 * - Remaining FUN_* / DAT_* identifiers are unresolved pending type recovery.
 * - Runtime / differential verification: OPEN unless matrix says otherwise.
 *
 * Readability pass:
 * - undefinedN widths preserved as fixed-width integers where decompiler width is known.
 * - Control flow and call order preserved from authoritative raw.
 */

void __thiscall Named_CalleeOf_Named_CalleeOf_Named_CalleeOf_Named_CalleeOf_Cli_00595230(int param_1,float param_2,uint32_t /* width from decompiler */ param_3)



{

  byte bVar1;

  ushort uVar2;

  char cVar3;

  uint32_t /* width from decompiler */ *puVar4;

  float *pfVar5;

  uint32_t /* width from decompiler */ uVar6;

  int *piVar7;

  uint32_t /* width from decompiler */ uVar8;

  int iVar9;

  uint32_t /* width from decompiler */ uVar10;

  int iVar11;

  float fVar12;

  float fVar13;

  float fVar14;

  float fVar15;

  float fVar16;

  float fVar17;

  uint32_t /* width from decompiler */ local_60;

  float fStack_58;

  float fStack_54;

  float fStack_50;

  float fStack_4c;

  float fStack_48;

  float fStack_44;

  float fStack_40;

  float fStack_3c;

  float fStack_38;

  float fStack_34;

  float fStack_30;

  float fStack_2c;

  float fStack_28;

  float fStack_24;

  void *local_1c;

  uint8_t *puStack_18;

  uint32_t /* width from decompiler */ local_14;

  

  local_14 = 0xffffffff;

  puStack_18 = &LAB_009a5a54;

  local_1c = ExceptionList;

  if (*(char *)(param_1 + 0x911) == '\0') {

    ExceptionList = &local_1c;

    *(int *)(DAT_00d17958 + 0x14c) = *(int *)(DAT_00d17958 + 0x14c) + 1;

  }

  else {

    ExceptionList = &local_1c;

    *(int *)(DAT_00d17958 + 0x150) = *(int *)(DAT_00d17958 + 0x150) + 1;

  }

  if ((*(byte *)(param_1 + 0x90d) & 2) != 0) {

    if (*(int *)(param_1 + 0x1c4) == 0) {

      iVar9 = 0;

    }

    else {

      iVar9 = *(int *)(param_1 + 0x1c8) - *(int *)(param_1 + 0x1c4) >> 2;

    }

    iVar11 = 0;

    if (0 < iVar9) {

      do {

        FUN_00634c50();

        iVar11 = iVar11 + 1;

      } while (iVar11 < iVar9);

    }

  }

  local_60 = 0;

  FUN_0076cf00("Time etc..");

  fVar12 = *(float *)(param_1 + 0x788) - param_2;

  local_14 = 0;

  *(float *)(param_1 + 0x788) = fVar12;

  if (fVar12 <= 0.0) {

    local_60 = 1;

    if (((*(byte *)(*(int *)(param_1 + 0x28) + 0x2ef) & 1) != 0) && (*(int *)(param_1 + 0x14) != 0))

    {

      FUN_004b6980();

    }

    puVar4 = *(uint32_t /* width from decompiler */ **)(*(int *)(param_1 + 0x28) + 0x2f4);

    *(uint32_t /* width from decompiler */ **)(param_1 + 0x28) = puVar4;

    if ((puVar4 == (uint32_t /* width from decompiler */ *)(param_1 + 0x3bc)) && ((*(byte *)(param_1 + 0x90e) & 0x10) == 0)) {

      *(byte *)(param_1 + 0x90e) = *(byte *)(param_1 + 0x90e) | 1;

      local_14 = 0xffffffff;

      FUN_0076cef0();

      ExceptionList = local_1c;

      return;

    }

    *(uint32_t /* width from decompiler */ *)(param_1 + 0x788) = *puVar4;

    if ((*(byte *)(*(int *)(param_1 + 0x28) + 0x1e4) & 4) != 0) {

      iVar9 = CVOGReaction_RandomUnitScalar();

      if (0xfffff < *(int *)(iVar9 + 0xc)) {

        *(uint32_t /* width from decompiler */ *)(iVar9 + 0xc) = 0;

      }

      uVar2 = *(ushort *)(*(int *)(iVar9 + 8) + *(int *)(iVar9 + 0xc) * 2);

      *(int *)(iVar9 + 0xc) = *(int *)(iVar9 + 0xc) + 1;

      *(float *)(param_1 + 0x788) =

           (float)uVar2 * *(float *)(*(int *)(param_1 + 0x28) + 4) * DAT_00aaa638 +

           *(float *)(param_1 + 0x788);

    }

    *(uint32_t /* width from decompiler */ *)(param_1 + 0x78c) = *(uint32_t /* width from decompiler */ *)(param_1 + 0x788);

  }

  bVar1 = *(byte *)(param_1 + 0x90e);

  if ((bVar1 & 0x10) != 0) {

    iVar9 = *(int *)(param_1 + 0x14);

    if (iVar9 == 0) {

      *(float *)(param_1 + 0x790) = *(float *)(param_1 + 0x790) - param_2;

    }

    else {

      *(float *)(param_1 + 0x790) = *(float *)(param_1 + 0x790) - *(float *)(iVar9 + 0x34) * param_2

      ;

    }

    fVar12 = *(float *)(param_1 + 0x790) - param_2;

    *(float *)(param_1 + 0x790) = fVar12;

    if (fVar12 <= 0.0) {

      *(byte *)(param_1 + 0x90e) = bVar1 | 1;

      if (iVar9 != 0) {

        FUN_004b6960(param_1,1);

      }

      goto LAB_0059544d;

    }

  }

  if ((*(char *)(param_1 + 0x911) == '\0') || ((bVar1 & 8) != 0)) {

    local_14 = 0xffffffff;

    FUN_0076cef0();

    FUN_005b83e0();

    FUN_0076cf00("Update Parent Pos");

    local_14 = 1;

    if ((((*(int *)(param_1 + 0x14) == 0) ||

         (piVar7 = *(int **)(*(int *)(param_1 + 0x14) + 0x10), piVar7 == (int *)0x0)) ||

        (((uint)piVar7[0x5f] >> 6 & 1) == 0)) || ((*(byte *)(param_1 + 0x90c) & 2) != 0)) {

      if ((*(int **)(param_1 + 0x914) != (int *)0x0) && ((*(byte *)(param_1 + 0x90e) & 8) == 0)) {

        iVar9 = (**(code **)(**(int **)(param_1 + 0x914) + 0xc))();

        *(uint32_t /* width from decompiler */ *)(param_1 + 0x824) = *(uint32_t /* width from decompiler */ *)(iVar9 + 0x90);

        *(uint32_t /* width from decompiler */ *)(param_1 + 0x828) = *(uint32_t /* width from decompiler */ *)(iVar9 + 0x94);

        *(uint32_t /* width from decompiler */ *)(param_1 + 0x82c) = *(uint32_t /* width from decompiler */ *)(iVar9 + 0x98);

        iVar9 = (**(code **)(**(int **)(param_1 + 0x914) + 0xc))();

        fStack_50 = (*(float *)(iVar9 + 0x80) * *(float *)(iVar9 + 0x88) -

                    *(float *)(iVar9 + 0x84) * *(float *)(iVar9 + 0x8c)) *

                    g_flLevelUpUiBase_Inferred;

        fStack_54 = (*(float *)(iVar9 + 0x8c) * *(float *)(iVar9 + 0x88) +

                    *(float *)(iVar9 + 0x84) * *(float *)(iVar9 + 0x80)) *

                    g_flLevelUpUiBase_Inferred;

        fStack_58 = g_flOne - (*(float *)(iVar9 + 0x88) * *(float *)(iVar9 + 0x88) +

                              *(float *)(iVar9 + 0x84) * *(float *)(iVar9 + 0x84)) *

                              g_flLevelUpUiBase_Inferred;

        *(float *)(param_1 + 0x83c) = fStack_58;

        *(float *)(param_1 + 0x840) = fStack_54;

        *(float *)(param_1 + 0x844) = fStack_50;

        iVar9 = (**(code **)(**(int **)(param_1 + 0x914) + 0xc))();

        fStack_50 = g_flLevelUpUiBase_Inferred;

        fVar12 = *(float *)(iVar9 + 0x80);

        fVar13 = *(float *)(iVar9 + 0x8c);

        fVar14 = *(float *)(iVar9 + 0x84);

        fVar15 = *(float *)(iVar9 + 0x88);

        fStack_54 = g_flOne - (*(float *)(iVar9 + 0x80) * *(float *)(iVar9 + 0x80) +

                              *(float *)(iVar9 + 0x88) * *(float *)(iVar9 + 0x88)) *

                              g_flLevelUpUiBase_Inferred;

        fStack_58 = (*(float *)(iVar9 + 0x84) * *(float *)(iVar9 + 0x80) -

                    *(float *)(iVar9 + 0x88) * *(float *)(iVar9 + 0x8c)) *

                    g_flLevelUpUiBase_Inferred;

        *(float *)(param_1 + 0x848) = fStack_58;

        fStack_50 = (fVar12 * fVar13 + fVar14 * fVar15) * fStack_50;

        *(float *)(param_1 + 0x84c) = fStack_54;

        *(float *)(param_1 + 0x850) = fStack_50;

        iVar9 = (**(code **)(**(int **)(param_1 + 0x914) + 0xc))();

        fVar12 = *(float *)(iVar9 + 0x84);

        fStack_50 = g_flOne - (*(float *)(iVar9 + 0x80) * *(float *)(iVar9 + 0x80) + fVar12 * fVar12

                              ) * g_flLevelUpUiBase_Inferred;

        fStack_58 = (*(float *)(iVar9 + 0x88) * *(float *)(iVar9 + 0x80) +

                    *(float *)(iVar9 + 0x84) * *(float *)(iVar9 + 0x8c)) *

                    g_flLevelUpUiBase_Inferred;

        fStack_54 = (fVar12 * *(float *)(iVar9 + 0x88) -

                    *(float *)(iVar9 + 0x8c) * *(float *)(iVar9 + 0x80)) *

                    g_flLevelUpUiBase_Inferred;

        *(float *)(param_1 + 0x830) = fStack_58;

        *(float *)(param_1 + 0x834) = fStack_54;

        *(float *)(param_1 + 0x838) = fStack_50;

        iVar9 = (**(code **)(**(int **)(param_1 + 0x914) + 0xc))();

        *(uint32_t /* width from decompiler */ *)(param_1 + 0x894) = *(uint32_t /* width from decompiler */ *)(iVar9 + 0x80);

        *(uint32_t /* width from decompiler */ *)(param_1 + 0x898) = *(uint32_t /* width from decompiler */ *)(iVar9 + 0x84);

        *(uint32_t /* width from decompiler */ *)(param_1 + 0x89c) = *(uint32_t /* width from decompiler */ *)(iVar9 + 0x88);

        *(uint32_t /* width from decompiler */ *)(param_1 + 0x8a0) = *(uint32_t /* width from decompiler */ *)(iVar9 + 0x8c);

        if (*(float *)(param_1 + 0x8d8) == 0.0) {

          *(float *)(param_1 + 0x8d8) = g_flOne;

        }

      }

    }

    else {

      iVar11 = (**(code **)(*piVar7 + 0x1cc))();

      iVar9 = *(int *)(*(int *)(iVar11 + 4) + 4);

      if (*(int *)(iVar11 + 8) == 0) {

        puVar4 = (uint32_t /* width from decompiler */ *)FUN_004e88e0(&fStack_4c,iVar9 + 0x84 + iVar11);

        *(uint32_t /* width from decompiler */ *)(param_1 + 0x824) = *puVar4;

        *(uint32_t /* width from decompiler */ *)(param_1 + 0x828) = puVar4[1];

        *(uint32_t /* width from decompiler */ *)(param_1 + 0x82c) = puVar4[2];

        puVar4 = (uint32_t /* width from decompiler */ *)

                 FUN_004e87d0(&fStack_40,*(int *)(*(int *)(iVar11 + 4) + 4) + 0x94 + iVar11);

        *(uint32_t /* width from decompiler */ *)(param_1 + 0x894) = *puVar4;

        *(uint32_t /* width from decompiler */ *)(param_1 + 0x898) = puVar4[1];

        *(uint32_t /* width from decompiler */ *)(param_1 + 0x89c) = puVar4[2];

        *(uint32_t /* width from decompiler */ *)(param_1 + 0x8a0) = puVar4[3];

        FUN_004e8ad0(*(int *)(*(int *)(iVar11 + 4) + 4) + 0x94 + iVar11,&fStack_30);

        puVar4 = (uint32_t /* width from decompiler */ *)FUN_004e88e0(&fStack_4c,&fStack_30);

        *(uint32_t /* width from decompiler */ *)(param_1 + 0x83c) = *puVar4;

        *(uint32_t /* width from decompiler */ *)(param_1 + 0x840) = puVar4[1];

        *(uint32_t /* width from decompiler */ *)(param_1 + 0x844) = puVar4[2];

        FUN_004e8a40(*(int *)(*(int *)(iVar11 + 4) + 4) + 0x94 + iVar11,&fStack_30);

        puVar4 = (uint32_t /* width from decompiler */ *)FUN_004e88e0(&fStack_4c,&fStack_30);

        *(uint32_t /* width from decompiler */ *)(param_1 + 0x830) = *puVar4;

        *(uint32_t /* width from decompiler */ *)(param_1 + 0x834) = puVar4[1];

        *(uint32_t /* width from decompiler */ *)(param_1 + 0x838) = puVar4[2];

        FUN_004e8b60(*(int *)(*(int *)(iVar11 + 4) + 4) + 0x94 + iVar11,&fStack_30);

        puVar4 = (uint32_t /* width from decompiler */ *)FUN_004e88e0(&fStack_4c,&fStack_30);

        *(uint32_t /* width from decompiler */ *)(param_1 + 0x848) = *puVar4;

        *(uint32_t /* width from decompiler */ *)(param_1 + 0x84c) = puVar4[1];

        *(uint32_t /* width from decompiler */ *)(param_1 + 0x850) = puVar4[2];

        fVar12 = g_flOne;

        if ((*(byte *)(param_1 + 0x90f) & 0x80) == 0) {

          fVar12 = *(float *)(*(int *)(*(int *)(iVar11 + 4) + 4) + 0xbc + iVar11);

        }

        *(float *)(param_1 + 0x8d8) = fVar12;

      }

      else {

        pfVar5 = (float *)(param_1 + 0x894);

        (**(code **)(*(int *)(iVar9 + 4 + iVar11) + 0x108))

                  (*(uint32_t /* width from decompiler */ *)(param_1 + 0x904),param_1 + 0x824,pfVar5,

                   *(uint32_t /* width from decompiler */ *)(param_1 + 0x908));

        fStack_50 = g_flLevelUpUiBase_Inferred;

        fStack_54 = g_flOne;

        fVar13 = (*(float *)(param_1 + 0x89c) * *(float *)(param_1 + 0x8a0) +

                 *(float *)(param_1 + 0x898) * *pfVar5) * g_flLevelUpUiBase_Inferred;

        fVar12 = (*(float *)(param_1 + 0x89c) * *pfVar5 -

                 *(float *)(param_1 + 0x898) * *(float *)(param_1 + 0x8a0)) *

                 g_flLevelUpUiBase_Inferred;

        *(float *)(param_1 + 0x83c) =

             g_flOne - (*(float *)(param_1 + 0x898) * *(float *)(param_1 + 0x898) +

                       *(float *)(param_1 + 0x89c) * *(float *)(param_1 + 0x89c)) *

                       g_flLevelUpUiBase_Inferred;

        *(float *)(param_1 + 0x840) = fVar13;

        *(float *)(param_1 + 0x844) = fVar12;

        fVar12 = *(float *)(param_1 + 0x898);

        *(float *)(param_1 + 0x830) =

             (*pfVar5 * *(float *)(param_1 + 0x89c) +

             *(float *)(param_1 + 0x898) * *(float *)(param_1 + 0x8a0)) * fStack_50;

        *(float *)(param_1 + 0x834) =

             (fVar12 * *(float *)(param_1 + 0x89c) - *pfVar5 * *(float *)(param_1 + 0x8a0)) *

             fStack_50;

        *(float *)(param_1 + 0x838) = fStack_54 - (*pfVar5 * *pfVar5 + fVar12 * fVar12) * fStack_50;

        fStack_58 = (*pfVar5 * *(float *)(param_1 + 0x898) -

                    *(float *)(param_1 + 0x89c) * *(float *)(param_1 + 0x8a0)) * fStack_50;

        fStack_54 = fStack_54 -

                    (*pfVar5 * *pfVar5 + *(float *)(param_1 + 0x89c) * *(float *)(param_1 + 0x89c))

                    * fStack_50;

        *(float *)(param_1 + 0x848) = fStack_58;

        fStack_50 = (*(float *)(param_1 + 0x89c) * *(float *)(param_1 + 0x898) +

                    *(float *)(param_1 + 0x8a0) * *pfVar5) * fStack_50;

        *(float *)(param_1 + 0x84c) = fStack_54;

        *(float *)(param_1 + 0x850) = fStack_50;

        if ((*(byte *)(param_1 + 0x90f) & 0x80) == 0) {

          iVar9 = (**(code **)(**(int **)(iVar11 + 8) + 0xc))();

          fVar12 = *(float *)(iVar9 + 0x9c);

          *(float *)(param_1 + 0x8d8) = fVar12;

          *(float *)(param_1 + 0x860) = *(float *)(param_1 + 0x860) * fVar12;

          *(float *)(param_1 + 0x864) = fVar12 * *(float *)(param_1 + 0x864);

          *(float *)(param_1 + 0x868) = fVar12 * *(float *)(param_1 + 0x868);

        }

      }

    }

    if ((*(float *)(param_1 + 0x824) * *(float *)(param_1 + 0x824) +

         *(float *)(param_1 + 0x828) * *(float *)(param_1 + 0x828) +

         *(float *)(param_1 + 0x82c) * *(float *)(param_1 + 0x82c) < DAT_009d51d8) &&

       (DAT_00b03e64 == '\0')) {

      uVar6 = 0;

      uVar8 = 0;

      uVar10 = 0;

      if ((*(int *)(param_1 + 0x14) != 0) &&

         (iVar9 = *(int *)(*(int *)(param_1 + 0x14) + 0x10), iVar9 != 0)) {

        uVar6 = *(uint32_t /* width from decompiler */ *)(iVar9 + 0x160);

        uVar8 = *(uint32_t /* width from decompiler */ *)(iVar9 + 0x164);

        uVar10 = *(uint32_t /* width from decompiler */ *)(*(int *)(iVar9 + 0xa8) + 0x34);

      }

      DAT_00b04ea8 = DAT_00b04ea8 + '\x01';

      if (DAT_00b04ea8 == '\0') {

        FUN_007a4480(0xffffffff,"Geo found at 0,0,0: %d %I64d",uVar10,uVar6,uVar8);

      }

    }

    if ((((*(int *)(param_1 + 0x14) == 0) ||

         (piVar7 = *(int **)(*(int *)(param_1 + 0x14) + 0x10), piVar7 == (int *)0x0)) ||

        ((((uint)piVar7[0x5f] >> 5 & 1) == 0 &&

         ((piVar7 = (int *)piVar7[0x2b], piVar7 == (int *)0x0 ||

          (((uint)piVar7[0x5f] >> 5 & 1) == 0)))))) ||

       (iVar9 = (**(code **)(*piVar7 + 0x1c8))(), *(int *)(iVar9 + 8) == 0)) {

      *(uint32_t /* width from decompiler */ *)(param_1 + 0x854) = 0;

      *(uint32_t /* width from decompiler */ *)(param_1 + 0x858) = 0;

      *(uint32_t /* width from decompiler */ *)(param_1 + 0x85c) = 0;

    }

    else {

      *(uint32_t /* width from decompiler */ *)(param_1 + 0x854) =

           *(uint32_t /* width from decompiler */ *)(*(int *)(*(int *)(iVar9 + 8) + 0x3c) + 0x40);

      *(uint32_t /* width from decompiler */ *)(param_1 + 0x858) =

           *(uint32_t /* width from decompiler */ *)(*(int *)(*(int *)(iVar9 + 8) + 0x3c) + 0x44);

      *(uint32_t /* width from decompiler */ *)(param_1 + 0x85c) =

           *(uint32_t /* width from decompiler */ *)(*(int *)(*(int *)(iVar9 + 8) + 0x3c) + 0x48);

    }

    local_14 = 0xffffffff;

    FUN_0076cef0();

    if ((*(byte *)(param_1 + 0x90e) & 8) != 0) {

      if (g_flZero < *(float *)(param_1 + 0xbc)) {

        *(float *)(param_1 + 0xbc) = *(float *)(param_1 + 0xbc) - param_2;

        if (*(int *)(param_1 + 0xdc) == 0) {

          ExceptionList = local_1c;

          return;

        }

        iVar9 = FUN_00787260();

        if (iVar9 == 0) {

          ExceptionList = local_1c;

          return;

        }

        *(float *)(param_1 + 0x824) = *(float *)(iVar9 + 0x824);

        *(uint32_t /* width from decompiler */ *)(param_1 + 0x828) = *(uint32_t /* width from decompiler */ *)(iVar9 + 0x828);

        *(uint32_t /* width from decompiler */ *)(param_1 + 0x82c) = *(uint32_t /* width from decompiler */ *)(iVar9 + 0x82c);

        ExceptionList = local_1c;

        return;

      }

      cVar3 = FUN_005911b0(0);

      if (cVar3 == '\0') {

        ExceptionList = local_1c;

        return;

      }

      local_60 = 1;

    }

    if (*(int *)(param_1 + 0x914) != 0) {

      bVar1 = *(byte *)(param_1 + 0x90f);

      if (((bVar1 & 4) != 0) &&

         (fVar12 = *(float *)(param_1 + 0x8ec) - param_2, *(float *)(param_1 + 0x8ec) = fVar12,

         fVar12 <= 0.0)) {

        *(byte *)(param_1 + 0x90f) = (~(bVar1 >> 4) << 4 ^ bVar1) & 0x10 ^ bVar1;

        *(uint32_t /* width from decompiler */ *)(param_1 + 0x8ec) = *(uint32_t /* width from decompiler */ *)(param_1 + 0x8e8);

      }

      FUN_005b83e0();

      iVar9 = param_1 + 0x3bc;

      do {

        FUN_005b83e0();

        iVar9 = *(int *)(iVar9 + 0x2f4);

      } while (iVar9 != param_1 + 0x3bc);

      FUN_005942d0(local_60,param_3);

      if ((*(byte *)(param_1 + 0x90f) & 0x20) == 0) {

        FUN_00593240(local_60,&param_2);

        iVar9 = (**(code **)(**(int **)(param_1 + 0x914) + 0xc))();

        fVar12 = *(float *)(iVar9 + 0x90);

        fVar13 = *(float *)(iVar9 + 0x94);

        fVar14 = *(float *)(iVar9 + 0x98);

        if ((*(byte *)(param_1 + 0x90e) & 8) == 0) {

          pfVar5 = (float *)(param_1 + 0x87c);

          *pfVar5 = fVar12 - *(float *)(param_1 + 0x888);

          *(float *)(param_1 + 0x880) = fVar13 - *(float *)(param_1 + 0x88c);

          param_2 = g_flOne / param_2;

          *(float *)(param_1 + 0x884) = fVar14 - *(float *)(param_1 + 0x890);

          *pfVar5 = *pfVar5 * param_2;

          *(float *)(param_1 + 0x880) = *(float *)(param_1 + 0x880) * param_2;

          *(float *)(param_1 + 0x884) = *(float *)(param_1 + 0x884) * param_2;

        }

        *(float *)(param_1 + 0x888) = fVar12;

        *(float *)(param_1 + 0x88c) = fVar13;

        *(float *)(param_1 + 0x890) = fVar14;

      }

      else {

        FUN_004e9530(&fStack_40,param_1 + 0x860);

        iVar9 = (**(code **)(**(int **)(param_1 + 0x914) + 0xc))();

        FUN_004e96e0(&fStack_30,iVar9 + 0x80);

        fVar12 = (fStack_38 * fStack_28 + fStack_3c * fStack_2c + fStack_40 * fStack_30) *

                 g_flLevelUpUiBase_Inferred;

        fVar14 = fStack_24 * fStack_24 * g_flLevelUpUiBase_Inferred - g_flOne;

        fVar13 = fStack_24 * g_flLevelUpUiBase_Inferred;

        fVar15 = fStack_28 * fStack_40;

        fVar16 = fStack_3c * fStack_30;

        fVar17 = fStack_2c * fStack_40;

        fStack_40 = (fStack_38 * fStack_2c - fStack_28 * fStack_3c) * fVar13 +

                    fStack_30 * fVar12 + fStack_40 * fVar14;

        fStack_3c = (fVar15 - fStack_38 * fStack_30) * fVar13 +

                    fStack_2c * fVar12 + fStack_3c * fVar14;

        fStack_38 = (fVar16 - fVar17) * fVar13 + fStack_28 * fVar12 + fStack_38 * fVar14;

        fStack_34 = fVar13 * g_flZero + fStack_24 * fVar12 + fStack_34 * fVar14;

        pfVar5 = (float *)FUN_004e88e0(&fStack_58,&fStack_40);

        fStack_4c = *(float *)(param_1 + 0x824) + *pfVar5;

        fStack_48 = *(float *)(param_1 + 0x828) + pfVar5[1];

        fStack_44 = *(float *)(param_1 + 0x82c) + pfVar5[2];

        iVar9 = (**(code **)(**(int **)(param_1 + 0x914) + 0x10))(3);

        *(uint32_t /* width from decompiler */ *)(iVar9 + 0xbc) = 0xffffffff;

        *(int *)(iVar9 + 0xb4) = *(int *)(iVar9 + 0xb4) + 1;

        *(float *)(iVar9 + 0x90) = fStack_50;

        *(float *)(iVar9 + 0x94) = fStack_4c;

        *(float *)(iVar9 + 0x98) = fStack_48;

        iVar9 = (**(code **)(**(int **)(param_1 + 0x914) + 0x10))(3);

        *(uint32_t /* width from decompiler */ *)(iVar9 + 0xbc) = 0xffffffff;

        *(int *)(iVar9 + 0xb4) = *(int *)(iVar9 + 0xb4) + 1;

        *(uint32_t /* width from decompiler */ *)(iVar9 + 0x80) = *(uint32_t /* width from decompiler */ *)(param_1 + 0x894);

        *(uint32_t /* width from decompiler */ *)(iVar9 + 0x84) = *(uint32_t /* width from decompiler */ *)(param_1 + 0x898);

        *(uint32_t /* width from decompiler */ *)(iVar9 + 0x88) = *(uint32_t /* width from decompiler */ *)(param_1 + 0x89c);

        *(uint32_t /* width from decompiler */ *)(iVar9 + 0x8c) = *(uint32_t /* width from decompiler */ *)(param_1 + 0x8a0);

        (**(code **)(**(int **)(param_1 + 0x914) + 0xc))();

      }

      *(byte *)(param_1 + 0x90e) = *(byte *)(param_1 + 0x90e) & 0xf7;

    }

    ExceptionList = local_1c;

    return;

  }

LAB_0059544d:

  local_14 = 0xffffffff;

  FUN_0076cef0();

  ExceptionList = local_1c;

  return;

}
