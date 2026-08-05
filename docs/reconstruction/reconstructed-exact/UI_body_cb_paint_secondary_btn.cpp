// =============================================================================
// UI_body_cb_paint_secondary_btn
// -----------------------------------------------------------------------------
// Stable ID: aa_008ff5a0
// Address:   0x008ff5a0  (autoassault.exe, image base 0x400000)
// System:    unknown
// Generated: 2026-07-23 from raw capture (scaffold; refine for important units)
// Exactness: Behavior-preserving rewrite of decompiler control flow. Not modernization.
// Bit-for-bit vs retail EXE: DEFERRED (loaded image may differ slightly).
// =============================================================================

// PURPOSE (auto): Scaffold unit for UI_body_cb_paint_secondary_btn @ 0x008ff5a0
// Stable ID: aa_008ff5a0
// Embedded strings (evidence for future rename):
//   - "i_d_body_2d_cb_paint_primary_btn_element.xml"
//   - "i_d_body_2d_cb_paint_secondary_btn_element.xml"
// Readability: control flow preserved from Ghidra decompile; types tentative.

// READABILITY (auto CF):
//  - Body size: ~273 non-empty decompiler lines.
//  - Control keywords: if×37, while×2, return×2.
//  - Notable callees: FUN_00519d20×6, CONCAT11×4, CONCAT13×4, CONCAT22×4, CVOGReaction_FailMissionNotify×4, FUN_004022a0×4, FUN_0079c860×4, CONCAT31×2.
//  - Strings: "i_d_body_2d_cb_paint_primary_btn_element.xml"; "i_d_body_2d_cb_paint_secondary_btn_element.xml".
//  - Return sites: 2.

/*
 * Behavioral notes:
 * Plate-driven rename evidence: "i_d_body_2d_cb_paint_secondary_btn_element.xml"
 * Domain alias of FUN_008ff5a0 (FUN_* retained)
 *
 * - Derived from Ghidra decompile; names prefer Ghidra symbols / plate comments.
 * - Remaining FUN_* / DAT_* identifiers are unresolved pending type recovery.
 * - Runtime / differential verification: OPEN unless matrix says otherwise.
 *
 * Readability pass:
 * - undefinedN widths preserved as fixed-width integers where decompiler width is known.
 * - Control flow and call order preserved from authoritative raw.
 */

void UI_body_cb_paint_secondary_btn(void)



{

  int iVar1;

  int *piVar2;

  uint uVar3;

  uint32_t /* width from decompiler */ uVar4;

  int iVar5;

  uint16_t uVar6;

  uint uVar8;

  uint unaff_ESI;

  int unaff_EDI;

  uint local_4c;

  int iStack_48;

  int iStack_44;

  int iStack_40;

  void *pvStack_3c;

  undefined **ppuStack_38;

  _RTL_CRITICAL_SECTION _Stack_34;

  void *pvStack_10;

  void *local_c;

  uint8_t *puStack_8;

  uint32_t /* width from decompiler */ uStack_4;

  uint uVar7;

  

  uStack_4 = 0xffffffff;

  puStack_8 = &LAB_009b7bbf;

  local_c = ExceptionList;

  if ((DAT_00d1b6d8 != 0) && (*(int *)(DAT_00d1b6d8 + 0x250) != 0)) {

    ExceptionList = &local_c;

    if (*(int *)(unaff_EDI + 0x7c8) == -1) {

      ExceptionList = &local_c;

      *(uint32_t /* width from decompiler */ *)(unaff_EDI + 0x7c8) = *(uint32_t /* width from decompiler */ *)(*(int *)(DAT_00d1b6d8 + 0x250) + 0x1a8);

    }

    if (*(int *)(unaff_EDI + 0x7e0) == -1) {

      *(uint32_t /* width from decompiler */ *)(unaff_EDI + 0x7e0) = *(uint32_t /* width from decompiler */ *)(*(int *)(DAT_00d1b6d8 + 0x250) + 0x1ac);

    }

    if (*(int *)(unaff_EDI + 0x7b4) != 0) {

      local_4c = 0xffffffff;

      local_4c = FUN_00519d20(*(uint32_t /* width from decompiler */ *)(unaff_EDI + 0x7c8));

      local_4c = local_4c | 0xff000000;

      if (*(int *)(*(int *)(unaff_EDI + 0x7b4) + 0x930) != 0) {

        (**(code **)(**(int **)(*(int *)(unaff_EDI + 0x7b4) + 0x930) + 0x15c))(0,&local_4c);

      }

      (**(code **)(**(int **)(unaff_EDI + 0x7b4) + 0x450))();

      FUN_00410420(0,0);

      pvStack_3c = operator_new(0x4cc);

      uStack_4 = 0;

      if (pvStack_3c == (void *)0x0) {

        piVar2 = (int *)0x0;

      }

      else {

        piVar2 = (int *)FUN_0079c860();

      }

      uStack_4 = 0xffffffff;

      (**(code **)(*piVar2 + 0x28))("i_d_body_2d_cb_paint_primary_btn_element.xml");

      FUN_00519d20(*(uint32_t /* width from decompiler */ *)(*(int *)(DAT_00d1b6d8 + 0x250) + 0x1a8));

      (**(code **)(*piVar2 + 0x15c))(0,&stack0xffffffac);

      uVar3 = (unaff_ESI & 0xff) + 0x28;

      if (0xfe < uVar3) {

        uVar3 = 0xff;

      }

      uVar8 = (unaff_ESI >> 8 & 0xff) + 0x28;

      if (0xfe < uVar8) {

        uVar8 = 0xff;

      }

      uVar7 = (unaff_ESI >> 0x10 & 0xff) + 0x28;

      uVar6 = (uint16_t)uVar7;

      if (0xfe < uVar7) {

        uVar6 = 0xff;

      }

      unaff_ESI = CONCAT13(0xff,(int3)CONCAT22(uVar6,CONCAT11((char)uVar8,(char)uVar3)));

      piVar2[0x12a] = unaff_ESI;

      piVar2[0x129] = unaff_ESI;

      piVar2[0x44] = *(int *)(*(int *)(DAT_00d1b6d8 + 0x250) + 0x1a8);

      iStack_40 = (**(code **)(**(int **)(unaff_EDI + 0x7b4) + 0x44c))(piVar2);

      CVOGReaction_FailMissionNotify(&iStack_40);

      if (*(int *)(unaff_EDI + 0x7c8) == piVar2[0x44]) {

        iVar1 = **(int **)(unaff_EDI + 0x7b4);

        uVar4 = (**(code **)(*piVar2 + 0x78))();

        (**(code **)(iVar1 + 0x45c))(uVar4);

      }

      if (*(int *)(*(int *)(DAT_00d1b6d8 + 0x250) + 0x2b0) != 0) {

        iStack_44 = 0;

        FUN_0040db00();

        uStack_4 = 1;

        iVar1 = *(int *)(*(int *)(DAT_00d1b6d8 + 0x250) + 0x2b0);

        iStack_40 = iVar1 + 0x2c;

        iStack_48 = 0;

        if (*(int *)(iVar1 + 0x50) != 0) {

          FUN_004294f0();

          iVar5 = FUN_004022a0(&iStack_44,&iStack_48);

          iVar1 = iStack_48;

          while (iStack_48 = iVar1, iVar5 == 0) {

            if (((iVar1 != 0) && (*(short *)(*(int *)(*(int *)(iVar1 + 0xa8) + 0x3c) + 0x3f4) == 8))

               && (iVar5 = (**(code **)(**(int **)(unaff_EDI + 0x7b4) + 0x478))

                                     (*(uint32_t /* width from decompiler */ *)(iVar1 + 200)), iVar5 == 0)) {

              pvStack_3c = operator_new(0x4cc);

              uStack_4._0_1_ = 2;

              if (pvStack_3c == (void *)0x0) {

                piVar2 = (int *)0x0;

              }

              else {

                piVar2 = (int *)FUN_0079c860();

              }

              uStack_4 = CONCAT31(uStack_4._1_3_,1);

              (**(code **)(*piVar2 + 0x28))("i_d_body_2d_cb_paint_primary_btn_element.xml");

              FUN_00519d20(*(uint32_t /* width from decompiler */ *)(iVar1 + 200));

              (**(code **)(*piVar2 + 0x15c))(0,&stack0xffffffac);

              uVar3 = (unaff_ESI & 0xff) + 0x28;

              if (0xfe < uVar3) {

                uVar3 = 0xff;

              }

              uVar8 = (unaff_ESI >> 8 & 0xff) + 0x28;

              if (0xfe < uVar8) {

                uVar8 = 0xff;

              }

              uVar7 = (unaff_ESI >> 0x10 & 0xff) + 0x28;

              uVar6 = (uint16_t)uVar7;

              if (0xfe < uVar7) {

                uVar6 = 0xff;

              }

              unaff_ESI = CONCAT13(0xff,(int3)CONCAT22(uVar6,CONCAT11((char)uVar8,(char)uVar3)));

              piVar2[0x12a] = unaff_ESI;

              piVar2[0x129] = unaff_ESI;

              piVar2[0x44] = *(uint *)(iVar1 + 200) & ((int)*(uint *)(iVar1 + 200) < 0) - 1;

              pvStack_3c = (void *)(**(code **)(**(int **)(unaff_EDI + 0x7b4) + 0x44c))(piVar2);

              CVOGReaction_FailMissionNotify(&pvStack_3c);

              if (*(int *)(unaff_EDI + 0x7c8) == piVar2[0x44]) {

                iVar1 = **(int **)(unaff_EDI + 0x7b4);

                uVar4 = (**(code **)(*piVar2 + 0x78))();

                (**(code **)(iVar1 + 0x45c))(uVar4);

              }

            }

            iVar5 = FUN_004022a0(&iStack_44,&iStack_48);

            iVar1 = iStack_48;

          }

          FUN_0040c700();

        }

        uStack_4 = 0xffffffff;

        ppuStack_38 = &PTR_FUN_00a34140;

        FUN_0040dc40();

        DeleteCriticalSection(&_Stack_34);

      }

    }

    if (*(int *)(unaff_EDI + 0x7cc) != 0) {

      local_4c = 0xffffffff;

      local_4c = FUN_00519d20(*(uint32_t /* width from decompiler */ *)(unaff_EDI + 0x7e0));

      local_4c = local_4c | 0xff000000;

      if (*(int *)(*(int *)(unaff_EDI + 0x7cc) + 0x930) != 0) {

        (**(code **)(**(int **)(*(int *)(unaff_EDI + 0x7cc) + 0x930) + 0x15c))(0,&local_4c);

      }

      (**(code **)(**(int **)(unaff_EDI + 0x7cc) + 0x450))();

      FUN_00410420(0,0);

      pvStack_3c = operator_new(0x4cc);

      uStack_4 = 3;

      if (pvStack_3c == (void *)0x0) {

        piVar2 = (int *)0x0;

      }

      else {

        piVar2 = (int *)FUN_0079c860();

      }

      uStack_4 = 0xffffffff;

      (**(code **)(*piVar2 + 0x28))("i_d_body_2d_cb_paint_secondary_btn_element.xml");

      FUN_00519d20(*(uint32_t /* width from decompiler */ *)(*(int *)(DAT_00d1b6d8 + 0x250) + 0x1ac));

      (**(code **)(*piVar2 + 0x15c))(0,&stack0xffffffac);

      uVar3 = (unaff_ESI & 0xff) + 0x28;

      if (0xfe < uVar3) {

        uVar3 = 0xff;

      }

      uVar8 = (unaff_ESI >> 8 & 0xff) + 0x28;

      if (0xfe < uVar8) {

        uVar8 = 0xff;

      }

      uVar7 = (unaff_ESI >> 0x10 & 0xff) + 0x28;

      uVar6 = (uint16_t)uVar7;

      if (0xfe < uVar7) {

        uVar6 = 0xff;

      }

      uVar3 = CONCAT13(0xff,(int3)CONCAT22(uVar6,CONCAT11((char)uVar8,(char)uVar3)));

      piVar2[0x12a] = uVar3;

      piVar2[0x129] = uVar3;

      piVar2[0x44] = *(int *)(*(int *)(DAT_00d1b6d8 + 0x250) + 0x1ac);

      pvStack_3c = (void *)(**(code **)(**(int **)(unaff_EDI + 0x7cc) + 0x44c))(piVar2);

      CVOGReaction_FailMissionNotify(&pvStack_3c);

      if (*(int *)(unaff_EDI + 0x7e0) == piVar2[0x44]) {

        iVar1 = **(int **)(unaff_EDI + 0x7cc);

        uVar4 = (**(code **)(*piVar2 + 0x78))();

        (**(code **)(iVar1 + 0x45c))(uVar4);

      }

      if (*(int *)(*(int *)(DAT_00d1b6d8 + 0x250) + 0x2b0) != 0) {

        iStack_40 = 0;

        FUN_0040db00();

        uStack_4 = 4;

        iVar1 = *(int *)(*(int *)(DAT_00d1b6d8 + 0x250) + 0x2b0);

        iStack_44 = iVar1 + 0x2c;

        iStack_48 = 0;

        if (*(int *)(iVar1 + 0x50) != 0) {

          FUN_004294f0();

          iVar5 = FUN_004022a0(&iStack_40,&iStack_48);

          iVar1 = iStack_48;

          while (iStack_48 = iVar1, iVar5 == 0) {

            if (((iVar1 != 0) && (*(short *)(*(int *)(*(int *)(iVar1 + 0xa8) + 0x3c) + 0x3f4) == 8))

               && (iVar5 = (**(code **)(**(int **)(unaff_EDI + 0x7cc) + 0x478))

                                     (*(uint32_t /* width from decompiler */ *)(iVar1 + 200)), iVar5 == 0)) {

              pvStack_3c = operator_new(0x4cc);

              uStack_4._0_1_ = 5;

              if (pvStack_3c == (void *)0x0) {

                piVar2 = (int *)0x0;

              }

              else {

                piVar2 = (int *)FUN_0079c860();

              }

              uStack_4 = CONCAT31(uStack_4._1_3_,4);

              (**(code **)(*piVar2 + 0x28))("i_d_body_2d_cb_paint_secondary_btn_element.xml");

              FUN_00519d20(*(uint32_t /* width from decompiler */ *)(iVar1 + 200));

              (**(code **)(*piVar2 + 0x15c))(0,&stack0xffffffac);

              uVar8 = (uVar3 & 0xff) + 0x28;

              if (0xfe < uVar8) {

                uVar8 = 0xff;

              }

              uVar7 = (uVar3 >> 8 & 0xff) + 0x28;

              if (0xfe < uVar7) {

                uVar7 = 0xff;

              }

              uVar3 = (uVar3 >> 0x10 & 0xff) + 0x28;

              uVar6 = (uint16_t)uVar3;

              if (0xfe < uVar3) {

                uVar6 = 0xff;

              }

              uVar3 = CONCAT13(0xff,(int3)CONCAT22(uVar6,CONCAT11((char)uVar7,(char)uVar8)));

              piVar2[0x12a] = uVar3;

              piVar2[0x129] = uVar3;

              piVar2[0x44] = *(uint *)(iVar1 + 200) & ((int)*(uint *)(iVar1 + 200) < 0) - 1;

              pvStack_3c = (void *)(**(code **)(**(int **)(unaff_EDI + 0x7cc) + 0x44c))(piVar2);

              CVOGReaction_FailMissionNotify(&pvStack_3c);

              if (*(int *)(unaff_EDI + 0x7e0) == piVar2[0x44]) {

                iVar1 = **(int **)(unaff_EDI + 0x7cc);

                uVar4 = (**(code **)(*piVar2 + 0x78))();

                (**(code **)(iVar1 + 0x45c))(uVar4);

              }

            }

            iVar5 = FUN_004022a0(&iStack_40,&iStack_48);

            iVar1 = iStack_48;

          }

          FUN_0040c700();

        }

        uStack_4 = 0xffffffff;

        ppuStack_38 = &PTR_FUN_00a34140;

        FUN_0040dc40();

        DeleteCriticalSection(&_Stack_34);

      }

    }

    piVar2 = *(int **)(unaff_EDI + 0x778);

    if (piVar2 != (int *)0x0) {

      if (*(int *)(unaff_EDI + 0x7c8) == *(int *)(*(int *)(DAT_00d1b6d8 + 0x250) + 0x1a8)) {

        (**(code **)(*piVar2 + 4))();

      }

      else {

        (**(code **)(*piVar2 + 4))();

      }

    }

    piVar2 = *(int **)(unaff_EDI + 0x77c);

    if (piVar2 != (int *)0x0) {

      if (*(int *)(unaff_EDI + 0x7e0) == *(int *)(*(int *)(DAT_00d1b6d8 + 0x250) + 0x1ac)) {

        (**(code **)(*piVar2 + 4))();

        ExceptionList = pvStack_10;

        return;

      }

      (**(code **)(*piVar2 + 4))();

    }

  }

  ExceptionList = local_c;

  return;

}
