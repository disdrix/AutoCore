// READABILITY (auto CF):
//  - Body size: ~215 non-empty decompiler lines.
//  - Control keywords: if×10, return×1.
//  - Notable callees: FUN_007a6de0×6, sprintf×4, FUN_00402d50×2, FUN_0052ad60×2, s×2, CONCAT22, FUN_0040f520, FUN_0052ada0.
//  - Strings: "i_w_skill_2d_wnd_name.xml"; "i_w_skill_2d_wnd_description.xml"; "i_d_item_2d_wnd_stats_full.xml"; "%s %s %d".
//  - Return sites: 1.

// =============================================================================
// Skill_i_w_skill_2d_wnd_description_xml_0084dc10
// -----------------------------------------------------------------------------
// Stable ID: aa_0084dc10
// Address:   0x0084dc10  (autoassault.exe, image base 0x400000)
// System:    unknown
// Generated: 2026-07-23 from raw capture (scaffold; refine for important units)
// Exactness: Behavior-preserving rewrite of decompiler control flow. Not modernization.
// Bit-for-bit vs retail EXE: DEFERRED (loaded image may differ slightly).
// =============================================================================

/*
 * Behavioral notes:
 * String-driven rename evidence: "i_w_skill_2d_wnd_description.xml"
 *
 * - Derived from Ghidra decompile; names prefer Ghidra symbols / plate comments.
 * - Remaining FUN_* / DAT_* identifiers are unresolved pending type recovery.
 * - Runtime / differential verification: OPEN unless matrix says otherwise.
 *
 * Readability pass:
 * - undefinedN widths preserved as fixed-width integers where decompiler width is known.
 * - Control flow and call order preserved from authoritative raw.
 */

void __fastcall Skill_i_w_skill_2d_wnd_description_xml_0084dc10(int *param_1)



{

  char cVar1;

  int iVar2;

  int iVar3;

  int *piVar4;

  uint32_t /* width from decompiler */ *puVar5;

  int iVar6;

  uint16_t in_FPUControlWord;

  uint32_t /* width from decompiler */ uStack_3e8;

  uint32_t /* width from decompiler */ uStack_3e4;

  uint32_t /* width from decompiler */ *puStack_3e0;

  uint32_t /* width from decompiler */ uStack_3dc;

  uint32_t /* width from decompiler */ uStack_3d8;

  uint32_t /* width from decompiler */ *puStack_3d4;

  uint8_t *puStack_3d0;

  uint32_t /* width from decompiler */ uStack_3cc;

  uint8_t *puStack_3c8;

  uint32_t /* width from decompiler */ uStack_3c4;

  uint32_t /* width from decompiler */ uStack_3c0;

  uint32_t /* width from decompiler */ uStack_3bc;

  char ***pppcStack_3b8;

  char **ppcStack_3b4;

  uint32_t /* width from decompiler */ uStack_3b0;

  uint32_t /* width from decompiler */ uStack_3ac;

  uint8_t *puStack_3a8;

  uint32_t /* width from decompiler */ uStack_3a4;

  char **ppcStack_3a0;

  int iStack_39c;

  uint32_t /* width from decompiler */ *puStack_398;

  char *pcStack_374;

  char *pcStack_370;

  char *pcStack_36c;

  uint8_t *puStack_330;

  uint8_t auStack_32c [128];

  char acStack_2ac [148];

  uint8_t local_218 [504];

  uint32_t /* width from decompiler */ uStack_20;

  void *local_14;

  uint8_t *puStack_10;

  uint32_t /* width from decompiler */ uStack_c;

  

  uStack_c = 0xffffffff;

  puStack_10 = &LAB_009ac54c;

  local_14 = ExceptionList;

  pcStack_36c = (char *)0x84dc3c;

  ExceptionList = &local_14;

  FUN_007a69d0();

  if ((((DAT_00d1b6d8 != 0) && (param_1[0x145] != 0)) && (param_1[0x147] != 0)) &&

     (param_1[0x148] != 0)) {

    pcStack_370 = (char *)param_1[0x142];

    pcStack_36c = local_218;

    pcStack_374 = (char *)0x84dc86;

    cVar1 = FUN_0052b040();

    if (cVar1 != '\0') {

      pcStack_36c = "i_w_skill_2d_wnd_name.xml";

      pcStack_370 = (char *)0x84dca1;

      (**(code **)(*(int *)param_1[0x145] + 0x28))();

      pcStack_370 = "i_w_skill_2d_wnd_description.xml";

      pcStack_374 = (char *)0x84dcb1;

      (**(code **)(*(int *)param_1[0x147] + 0x28))();

      pcStack_374 = "i_d_item_2d_wnd_stats_full.xml";

      (**(code **)(*(int *)param_1[0x148] + 0x28))();

      (**(code **)(*(int *)param_1[0x145] + 0x140))();

      *(uint32_t /* width from decompiler */ *)(param_1[0x145] + 0x214) = 1;

      iVar2 = FUN_0052ad60();

      FUN_0052ada0();

      if ((DAT_00d1b6d8 == 0) || (*(int *)(DAT_00d1b6d8 + 0x6b4) < 1)) {

        FUN_00402d50();

        if (iVar2 < 1) {

          uStack_20 = 3;

          FUN_007a6de0();

          sprintf(acStack_2ac,"%s");

        }

        else {

          uStack_20 = 2;

          FUN_007a6de0();

          FUN_007a6de0();

          sprintf(acStack_2ac,"%s %s %d");

        }

      }

      else {

        FUN_00402d50();

        if (iVar2 < 1) {

          uStack_20 = 1;

          FUN_007a6de0();

          sprintf(acStack_2ac,"%s(%d)");

        }

        else {

          uStack_20 = 0;

          FUN_007a6de0();

          FUN_007a6de0();

          puStack_398 = (uint32_t /* width from decompiler */ *)0x84dda3;

          sprintf(acStack_2ac,"%s(%d) %s %d");

        }

      }

      uStack_20 = 0xffffffff;

      if (puStack_330 != auStack_32c) {

        free(puStack_330);

      }

      (**(code **)(*(int *)param_1[0x145] + 0x1d8))();

      (**(code **)(*(int *)param_1[0x145] + 0x13c))();

      (**(code **)(*(int *)param_1[0x145] + 0x140))();

      if (0 < iVar2) {

        puStack_398 = (uint32_t /* width from decompiler */ *)0x84df1d;

        FUN_0040f520();

        pcStack_36c = (char *)CONCAT22(pcStack_36c._2_2_,in_FPUControlWord);

      }

      puStack_398 = (uint32_t /* width from decompiler */ *)0x84df59;

      (**(code **)(*(int *)param_1[0x146] + 300))();

      puStack_398 = (uint32_t /* width from decompiler */ *)0x84df67;

      (**(code **)(*(int *)param_1[0x145] + 0x94))();

      if (DAT_00d1b6d8 != 0) {

        puStack_398 = (uint32_t /* width from decompiler */ *)param_1[0x142];

        iStack_39c = 0x84df7d;

        cVar1 = FUN_0052b140();

        if (cVar1 == '\0') {

          puStack_398 = &DAT_00afdb24;

          iStack_39c = 1;

          ppcStack_3a0 = (char **)0x84df96;

          (**(code **)(*(int *)param_1[0x145] + 0x15c))();

        }

        else {

          puStack_398 = (uint32_t /* width from decompiler */ *)param_1[0x142];

          iStack_39c = 0x84dfaa;

          iVar2 = FUN_0052ad60();

          if (iVar2 == 0) {

            puStack_398 = &DAT_00afdb28;

            iStack_39c = 1;

            ppcStack_3a0 = (char **)0x84dfc3;

            (**(code **)(*(int *)param_1[0x145] + 0x15c))();

          }

          else {

            puStack_398 = &DAT_00afdb2c;

            iStack_39c = 1;

            ppcStack_3a0 = (char **)0x84dfd4;

            (**(code **)(*(int *)param_1[0x145] + 0x15c))();

          }

        }

      }

      piVar4 = (int *)param_1[0x145];

      puStack_398 = (uint32_t /* width from decompiler */ *)0x0;

      iStack_39c = 1;

      ppcStack_3a0 = &pcStack_370;

      uStack_3a4 = 0x84dfed;

      iVar3 = (**(code **)(*piVar4 + 0x120))();

      uStack_3a4 = 1;

      puStack_3a8 = &stack0xfffffca4;

      uStack_3ac = 0x84e000;

      iVar2 = (**(code **)(*piVar4 + 0x140))();

      iVar2 = *(int *)(iVar2 + 4);

      iVar3 = *(int *)(iVar3 + 4);

      uStack_3ac = 0;

      uStack_3b0 = 1;

      ppcStack_3b4 = &pcStack_374;

      pppcStack_3b8 = (char ***)0x84e021;

      piVar4 = (int *)(**(code **)(*(int *)param_1[0x147] + 0x120))();

      ppcStack_3a0 = (char **)*piVar4;

      pppcStack_3b8 = &ppcStack_3a0;

      uStack_3bc = 0x84e03e;

      iStack_39c = iVar3 + 1 + iVar2;

      (**(code **)(*(int *)param_1[0x147] + 0x110))();

      *(uint32_t /* width from decompiler */ *)(param_1[0x147] + 0x214) = 3;

      uStack_3bc = 1;

      uStack_3c0 = 0x84e05f;

      (**(code **)(*(int *)param_1[0x147] + 0x1c4))();

      uStack_3c0 = 0x84e071;

      FUN_0084da00();

      uStack_3c0 = 0x84e07f;

      (**(code **)(*(int *)param_1[0x147] + 0x13c))();

      uStack_3c0 = 0;

      uStack_3c4 = 1;

      puStack_3c8 = &stack0xfffffc78;

      uStack_3cc = 0x84e096;

      puVar5 = (uint32_t /* width from decompiler */ *)(**(code **)(*(int *)param_1[0x147] + 0x120))();

      iStack_39c = *puVar5;

      puStack_398 = (uint32_t /* width from decompiler */ *)puVar5[1];

      uStack_3cc = 1;

      puStack_3d0 = &stack0xfffffc6c;

      puStack_3d4 = (uint32_t /* width from decompiler */ *)0x84e0b8;

      iVar2 = (**(code **)(*(int *)param_1[0x147] + 0x140))();

      ppcStack_3a0 = (char **)((int)ppcStack_3a0 + *(int *)(iVar2 + 4) + 1);

      *(uint32_t /* width from decompiler */ *)(param_1[0x148] + 0x214) = 3;

      puStack_3d4 = &uStack_3a4;

      uStack_3d8 = 0x84e0e6;

      (**(code **)(*(int *)param_1[0x148] + 0x118))();

      uStack_3d8 = 1;

      uStack_3dc = 0x84e0f6;

      (**(code **)(*(int *)param_1[0x148] + 0x1c4))();

      uStack_3dc = 0;

      puStack_3e0 = (uint32_t /* width from decompiler */ *)0x84e10a;

      FUN_0084d220();

      uStack_3dc = 0x84e11b;

      (**(code **)(*(int *)param_1[0x148] + 0x13c))();

      uStack_3dc = 1;

      puStack_3e0 = &uStack_3a4;

      uStack_3e4 = 0x84e130;

      puVar5 = (uint32_t /* width from decompiler */ *)(**(code **)(*(int *)param_1[0x144] + 0x140))();

      uStack_3c4 = *puVar5;

      uStack_3c0 = puVar5[1];

      piVar4 = (int *)param_1[0x148];

      uStack_3e4 = 0;

      uStack_3e8 = 1;

      iVar2 = (**(code **)(*(int *)param_1[0x145] + 0x120))(&uStack_3ac);

      iVar3 = (**(code **)(*piVar4 + 0x120))(&puStack_3a8,1,0);

      iVar2 = *(int *)(iVar2 + 4);

      iVar3 = *(int *)(iVar3 + 4);

      iVar6 = (**(code **)(*piVar4 + 0x140))(&uStack_3e4,1);

      puStack_3e0 = (uint32_t /* width from decompiler */ *)(iVar2 + iVar3 + *(int *)(iVar6 + 4));

      (**(code **)(*(int *)param_1[0x144] + 8))(&uStack_3e4);

      (**(code **)(*param_1 + 8))(&uStack_3e8);

    }

  }

  ExceptionList = local_14;

  return;

}
