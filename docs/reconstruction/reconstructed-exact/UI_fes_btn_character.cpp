// =============================================================================
// UI_fes_btn_character
// -----------------------------------------------------------------------------
// Stable ID: aa_008cd200
// Address:   0x008cd200  (autoassault.exe, image base 0x400000)
// System:    unknown
// Generated: 2026-07-23 from raw capture (scaffold; refine for important units)
// Exactness: Behavior-preserving rewrite of decompiler control flow. Not modernization.
// Bit-for-bit vs retail EXE: DEFERRED (loaded image may differ slightly).
// =============================================================================

// PURPOSE (auto): Scaffold unit for UI_fes_btn_character @ 0x008cd200
// Stable ID: aa_008cd200
// Embedded strings (evidence for future rename):
//   - "i_d_fes_2d_btn_character.xml"
//   - "i_d_fes_2d_wnd_icon_empty.xml"
//   - "i_d_fes_2d_wnd_icon_human.xml"
//   - "i_d_fes_2d_wnd_icon_mutant.xml"
//   - "i_d_fes_2d_wnd_icon_biomek.xml"
//   - "Create Character"
// Readability: control flow preserved from Ghidra decompile; types tentative.

// READABILITY (auto CF):
//  - Body size: ~361 non-empty decompiler lines.
//  - Control keywords: if×24, do×5, while×5, goto×2, return×1.
//  - Notable callees: FUN_007a6910×5, FUN_007a6de0×5, _atexit×5, FUN_007b5dd0×2, FUN_0079c860, FUN_008cc500, FUN_008cc7f0, FUN_008cd070.
//  - Strings: "i_d_fes_2d_btn_character.xml"; "i_d_fes_2d_wnd_icon_empty.xml"; "i_d_fes_2d_wnd_icon_human.xml"; "i_d_fes_2d_wnd_icon_mutant.xml".
//  - Return sites: 1.

/*
 * Behavioral notes:
 * Plate-driven rename evidence: "i_d_fes_2d_btn_character.xml"
 * Domain alias of FUN_008cd200 (FUN_* retained)
 *
 * - Derived from Ghidra decompile; names prefer Ghidra symbols / plate comments.
 * - Remaining FUN_* / DAT_* identifiers are unresolved pending type recovery.
 * - Runtime / differential verification: OPEN unless matrix says otherwise.
 *
 * Readability pass:
 * - undefinedN widths preserved as fixed-width integers where decompiler width is known.
 * - Control flow and call order preserved from authoritative raw.
 */

void UI_fes_btn_character(int *param_1)



{

  char cVar1;

  uint uVar2;

  int iVar3;

  void *pvVar4;

  int iVar5;

  int iVar6;

  uint32_t /* width from decompiler */ *puVar7;

  int *piVar8;

  int *piVar9;

  uint32_t /* width from decompiler */ uVar10;

  char *pcVar11;

  char **ppcVar12;

  int unaff_EBX;

  int *piVar13;

  char *pcVar14;

  int iVar15;

  uint32_t /* width from decompiler */ uVar16;

  uint32_t /* width from decompiler */ uVar17;

  int *piStack_39c;

  uint8_t *puStack_398;

  uint32_t /* width from decompiler */ uStack_394;

  uint32_t /* width from decompiler */ uStack_390;

  uint8_t *puStack_38c;

  uint32_t /* width from decompiler */ uStack_388;

  uint32_t /* width from decompiler */ uStack_384;

  void **ppvStack_380;

  uint32_t /* width from decompiler */ uStack_37c;

  uint32_t /* width from decompiler */ uStack_378;

  float *pfStack_374;

  int iStack_370;

  int iStack_36c;

  char **ppcStack_368;

  uint8_t *puStack_364;

  uint32_t /* width from decompiler */ uStack_360;

  uint32_t /* width from decompiler */ uStack_35c;

  uint8_t *puStack_358;

  uint32_t /* width from decompiler */ uStack_354;

  uint32_t /* width from decompiler */ uStack_350;

  uint8_t *puStack_34c;

  uint8_t *puStack_348;

  char *pcStack_344;

  float fStack_330;

  char *pcStack_32c;

  uint8_t auStack_314 [4];

  int iStack_310;

  void *apvStack_30c [2];

  char acStack_304 [4];

  uint8_t auStack_300 [60];

  char acStack_2c4 [8];

  uint8_t auStack_2bc [496];

  uint32_t /* width from decompiler */ uStack_cc;

  uint32_t /* width from decompiler */ uStack_c0;

  uint32_t /* width from decompiler */ uStack_bc;

  uint32_t /* width from decompiler */ uStack_1c;

  int *piStack_14;

  void *pvStack_c;

  uint8_t *puStack_8;

  uint32_t /* width from decompiler */ uStack_4;

  

  uStack_4 = 0xffffffff;

  puStack_8 = &LAB_009b6dc1;

  pvStack_c = ExceptionList;

  piVar13 = param_1 + 0x173;

  iVar15 = 0xc;

  ExceptionList = &pvStack_c;

  do {

    if (piVar13[-0xc] != 0) {

      pcStack_32c = (char *)0x8cd245;

      (**(code **)(*param_1 + 0xb0))();

    }

    if ((uint32_t /* width from decompiler */ *)piVar13[-0xc] != (uint32_t /* width from decompiler */ *)0x0) {

      pcStack_32c = (char *)0x8cd252;

      (*(code *)**(uint32_t /* width from decompiler */ **)piVar13[-0xc])();

    }

    piVar13[-0xc] = 0;

    if (*piVar13 != 0) {

      pcStack_32c = (char *)0x8cd266;

      (**(code **)(*param_1 + 0xb0))();

      if ((uint32_t /* width from decompiler */ *)*piVar13 != (uint32_t /* width from decompiler */ *)0x0) {

        pcStack_32c = (char *)0x8cd272;

        (*(code *)**(uint32_t /* width from decompiler */ **)*piVar13)();

      }

    }

    *piVar13 = 0;

    if (piVar13[0xc] != 0) {

      pcStack_32c = (char *)0x8cd286;

      (**(code **)(*param_1 + 0xb0))();

    }

    if ((uint32_t /* width from decompiler */ *)piVar13[0xc] != (uint32_t /* width from decompiler */ *)0x0) {

      pcStack_32c = (char *)0x8cd293;

      (*(code *)**(uint32_t /* width from decompiler */ **)piVar13[0xc])();

    }

    piVar13[0xc] = 0;

    piVar13 = piVar13 + 1;

    iVar15 = iVar15 + -1;

  } while (iVar15 != 0);

  iStack_310 = 0;

  piVar13 = param_1 + 0x167;

  iVar15 = (int)&DAT_00d1b140 - (int)param_1;

  do {

    pcStack_32c = (char *)0x8cd2ca;

    apvStack_30c[0] = operator_new(0x4cc);

    iVar3 = 0;

    uStack_4 = 0;

    if (apvStack_30c[0] != (void *)0x0) {

      iVar3 = FUN_0079c860();

    }

    uStack_4 = 0xffffffff;

    *piVar13 = iVar3;

    pcStack_32c = (char *)0x8cd2fc;

    (**(code **)(*param_1 + 0xa8))();

    pcStack_32c = "i_d_fes_2d_btn_character.xml";

    fStack_330 = 1.2932673e-38;

    (**(code **)(*(int *)*piVar13 + 0x28))();

    fStack_330 = (float)(unaff_EBX + 0x9c47);

    (**(code **)(*(int *)*piVar13 + 0x74))();

    (**(code **)(*(int *)*piVar13 + 0x3b4))();

    pvVar4 = operator_new(0x488);

    piStack_14 = (int *)0x1;

    if (pvVar4 == (void *)0x0) {

      iVar3 = 0;

    }

    else {

      iVar3 = FUN_007b5dd0();

    }

    piStack_14 = (int *)0xffffffff;

    piVar13[0xc] = iVar3;

    (**(code **)(*param_1 + 0xa8))();

    (**(code **)(*(int *)piVar13[0xc] + 0x28))();

    pcStack_344 = (char *)0x8cd37d;

    pcStack_344 = operator_new(0x488);

    uStack_1c = 2;

    if (pcStack_344 == (char *)0x0) {

      iVar5 = 0;

    }

    else {

      puStack_348 = (uint8_t *)0x8cd39c;

      iVar5 = FUN_007b5dd0();

    }

    uStack_1c = 0xffffffff;

    piVar13[0x18] = iVar5;

    pcStack_344 = (char *)0x8cd3ba;

    (**(code **)(*piStack_14 + 0xa8))();

    iVar5 = *(int *)((int)piVar13 + iVar15);

    if (iVar5 == 0) {

LAB_008cd440:

      pcStack_344 = "i_d_fes_2d_wnd_icon_empty.xml";

      puStack_348 = (uint8_t *)0x8cd44d;

      (**(code **)(*(int *)piVar13[0x18] + 0x28))();

    }

    else if (*(char *)(*(int *)(*(int *)(*(int *)(*(int *)(iVar5 + 4) + 4) + 0xac + iVar5) + 0x3c) +

                      0x532) == '\0') {

      pcStack_344 = "i_d_fes_2d_wnd_icon_human.xml";

      puStack_348 = (uint8_t *)0x8cd3e7;

      (**(code **)(*(int *)piVar13[0x18] + 0x28))();

    }

    else {

      if (iVar5 == 0) goto LAB_008cd440;

      if (*(char *)(*(int *)(*(int *)(*(int *)(*(int *)(iVar5 + 4) + 4) + 0xac + iVar5) + 0x3c) +

                   0x532) == '\x01') {

        pcStack_344 = "i_d_fes_2d_wnd_icon_mutant.xml";

        puStack_348 = (uint8_t *)0x8cd413;

        (**(code **)(*(int *)piVar13[0x18] + 0x28))();

      }

      else {

        if ((iVar5 == 0) ||

           (*(char *)(*(int *)(*(int *)(*(int *)(*(int *)(iVar5 + 4) + 4) + 0xac + iVar5) + 0x3c) +

                     0x532) != '\x02')) goto LAB_008cd440;

        pcStack_344 = "i_d_fes_2d_wnd_icon_biomek.xml";

        puStack_348 = (uint8_t *)0x8cd43e;

        (**(code **)(*(int *)piVar13[0x18] + 0x28))();

      }

    }

    piVar8 = (int *)*piVar13;

    puStack_348 = auStack_2bc;

    puStack_34c = (uint8_t *)0x8cd462;

    iVar5 = (**(code **)(*(int *)piVar13[0xc] + 0x134))();

    puStack_34c = auStack_300;

    uStack_350 = 0x8cd473;

    iVar6 = (**(code **)(*piVar8 + 0x134))();

    uStack_350 = 0;

    uStack_354 = 1;

    puStack_358 = auStack_2bc;

    fStack_330 = (float)DAT_00d1e81c *

                 (*(float *)(iVar5 + 4) + *(float *)(iVar6 + 4)) * (float)iVar3 * DAT_00aaa678;

    uStack_35c = 0x8cd4b7;

    (**(code **)(*(int *)*piVar13 + 0x120))();

    uStack_35c = 0;

    uStack_360 = 1;

    puStack_364 = auStack_300;

    ppcStack_368 = (char **)0x8cd4d3;

    puVar7 = (uint32_t /* width from decompiler */ *)(**(code **)(*(int *)*piVar13 + 0x120))();

    pcStack_344 = (char *)*puVar7;

    ppcStack_368 = &pcStack_344;

    iStack_36c = 0x8cd4ec;

    (**(code **)(*(int *)*piVar13 + 0x110))();

    piVar8 = (int *)*piVar13;

    iStack_36c = 0;

    iStack_370 = 1;

    pfStack_374 = &fStack_330;

    uStack_378 = 0x8cd502;

    iVar3 = (**(code **)(*(int *)piVar13[0xc] + 0x120))();

    uStack_378 = 0;

    uStack_37c = 1;

    ppvStack_380 = apvStack_30c;

    uStack_384 = 0x8cd517;

    iVar5 = (**(code **)(*piVar8 + 0x120))();

    iVar3 = *(int *)(iVar3 + 4);

    iVar5 = *(int *)(iVar5 + 4);

    uStack_384 = 0;

    uStack_388 = 1;

    puStack_38c = auStack_300;

    uStack_390 = 0x8cd534;

    piVar8 = (int *)(**(code **)(*(int *)piVar13[0xc] + 0x120))();

    uStack_390 = 0;

    uStack_394 = 1;

    puStack_398 = auStack_314;

    piStack_39c = (int *)0x8cd54c;

    piVar9 = (int *)(**(code **)(*(int *)*piVar13 + 0x120))();

    iStack_370 = *piVar8 + *piVar9;

    piStack_39c = &iStack_370;

    iStack_36c = iVar3 + iVar5;

    (**(code **)(*(int *)piVar13[0xc] + 0x110))();

    piVar8 = (int *)*piVar13;

    iVar3 = (**(code **)(*(int *)piVar13[0x18] + 0x120))(&uStack_35c,1,0);

    iVar5 = (**(code **)(*piVar8 + 0x120))(&puStack_358,1,0);

    iVar3 = *(int *)(iVar3 + 4);

    iVar5 = *(int *)(iVar5 + 4);

    piVar8 = (int *)(**(code **)(*(int *)piVar13[0x18] + 0x120))(&uStack_354,1,0);

    piVar9 = (int *)(**(code **)(*(int *)*piVar13 + 0x120))(&uStack_350,1,0);

    piStack_39c = (int *)(*piVar8 + *piVar9);

    puStack_398 = (uint8_t *)(iVar3 + iVar5);

    (**(code **)(*(int *)piVar13[0x18] + 0x110))(&piStack_39c);

    if (*(int *)((int)piVar13 + iVar15) == 0) {

      iVar3 = (**(code **)(*(int *)*piVar13 + 0x164))(0);

      *(uint8_t *)(iVar3 + 3) = 0x80;

      iVar3 = (**(code **)(*(int *)*piVar13 + 0x164))(1);

      *(uint8_t *)(iVar3 + 3) = 0x80;

      *(uint8_t *)(*piVar13 + 0x49f) = 0x80;

      *(uint8_t *)(*piVar13 + 0x4a3) = 0x80;

      iVar3 = 0x4b4;

      do {

        *(uint8_t *)(iVar3 + *piVar13 + -0xd) = 0x80;

        iVar5 = *piVar13 + iVar3;

        iVar3 = iVar3 + 4;

        *(uint8_t *)(iVar5 + 3) = 0x80;

      } while (iVar3 < 0x4c4);

      iVar3 = (**(code **)(*(int *)piVar13[0xc] + 0x164))(1);

      *(uint8_t *)(iVar3 + 3) = 0x80;

      iVar3 = (**(code **)(*(int *)piVar13[0x18] + 0x164))(0);

      uVar2 = DAT_00d1f728 & 1;

      *(uint8_t *)(iVar3 + 3) = 0xb0;

      if (uVar2 == 0) {

        DAT_00d1f728 = DAT_00d1f728 | 1;

        uStack_c0 = 6;

        FUN_007a6910(&DAT_00d1f660);

        _atexit((_func_4879 *)&LAB_009c30b0);

        uStack_c0 = 0xffffffff;

      }

      iVar3 = *(int *)*piVar13;

      uVar16 = 1;

      uVar17 = 1;

      uVar10 = FUN_007a6de0("Create Character",0xffffffff);

      (**(code **)(iVar3 + 0x1d8))(uVar10,uVar17,uVar16);

      if ((DAT_00d1f728 & 1) == 0) {

        DAT_00d1f728 = DAT_00d1f728 | 1;

        uStack_cc = 7;

        FUN_007a6910(&DAT_00d1f660);

        _atexit((_func_4879 *)&LAB_009c30b0);

        uStack_cc = 0xffffffff;

      }

      iVar3 = *(int *)piVar13[0xc];

      uVar16 = 1;

      uVar17 = 1;

      uVar10 = FUN_007a6de0("Empty",0xffffffff);

      (**(code **)(iVar3 + 0x1d8))(uVar10,uVar17,uVar16);

    }

    else {

      iVar3 = *(int *)*piVar13;

      uVar10 = (**(code **)(*(int *)(*(int *)(*(int *)(*(int *)((int)piVar13 + iVar15) + 4) + 4) + 4

                                    + *(int *)((int)piVar13 + iVar15)) + 0x160))(1);

      (**(code **)(iVar3 + 0x1d8))(uVar10);

      FUN_008cc7f0();

      cVar1 = *(char *)(*(int *)(*(int *)(*(int *)(*(int *)(*(int *)((int)piVar13 + iVar15) + 4) + 4

                                                  ) + 0xac + *(int *)((int)piVar13 + iVar15)) + 0x3c

                                ) + 0x532);

      if (cVar1 == '\x01') {

        pcVar14 = "Mutant";

      }

      else if (cVar1 == '\x02') {

        pcVar14 = "Biomek";

      }

      else {

        pcVar14 = "Human";

      }

      if ((DAT_00d1f728 & 1) == 0) {

        DAT_00d1f728 = DAT_00d1f728 | 1;

        uStack_bc = 3;

        FUN_007a6910(&DAT_00d1f660);

        _atexit((_func_4879 *)&LAB_009c30b0);

        uStack_bc = 0xffffffff;

      }

      pcVar11 = (char *)FUN_007a6de0(pcVar14,0xffffffff);

      pcVar14 = acStack_304;

      do {

        cVar1 = *pcVar11;

        *pcVar14 = cVar1;

        pcVar11 = pcVar11 + 1;

        pcVar14 = pcVar14 + 1;

      } while (cVar1 != '\0');

      if ((DAT_00d1f728 & 1) == 0) {

        DAT_00d1f728 = DAT_00d1f728 | 1;

        uStack_bc = 4;

        FUN_007a6910(&DAT_00d1f660);

        _atexit((_func_4879 *)&LAB_009c30b0);

        uStack_bc = 0xffffffff;

      }

      uVar17 = 0xffffffff;

      uVar10 = FUN_008cc500(0xffffffff);

      pcVar14 = (char *)FUN_007a6de0(uVar10,uVar17);

      ppcVar12 = &pcStack_344;

      do {

        cVar1 = *pcVar14;

        *(char *)ppcVar12 = cVar1;

        pcVar14 = pcVar14 + 1;

        ppcVar12 = (char **)((int)ppcVar12 + 1);

      } while (cVar1 != '\0');

      if ((DAT_00d1f728 & 1) == 0) {

        DAT_00d1f728 = DAT_00d1f728 | 1;

        uStack_bc = 5;

        FUN_007a6910(&DAT_00d1f660);

        _atexit((_func_4879 *)&LAB_009c30b0);

        uStack_bc = 0xffffffff;

      }

      uVar10 = (**(code **)(*(int *)(*(int *)(*(int *)(*(int *)((int)piVar13 + iVar15) + 4) + 4) + 4

                                    + *(int *)((int)piVar13 + iVar15)) + 0x27c))(&pcStack_344);

      uVar17 = FUN_007a6de0("Level",0xffffffff);

      sprintf(acStack_2c4,"%s %d %s",uVar17,uVar10);

      (**(code **)(*(int *)piVar13[0xc] + 0x1d8))(acStack_2c4,1,1);

    }

    (**(code **)(*(int *)*piVar13 + 0xfc))(1,0x3f000000);

    (**(code **)(*(int *)piVar13[0xc] + 0xfc))(1,0x3f000000);

    (**(code **)(*(int *)*piVar13 + 0x34c))();

    (**(code **)(*(int *)piVar13[0xc] + 0x34c))();

    iStack_310 = iStack_310 + 1;

    piVar13 = piVar13 + 1;

    if (0xb < iStack_310) {

      if ((iStack_310 == 0) || (iStack_310 <= DAT_00d1a980)) {

        DAT_00d1a980 = 0;

        FUN_008cd070();

        (**(code **)(*param_1 + 0x444))();

      }

      else {

        (**(code **)(*param_1 + 0x444))();

      }

      ExceptionList = pvStack_c;

      return;

    }

  } while( true );

}
