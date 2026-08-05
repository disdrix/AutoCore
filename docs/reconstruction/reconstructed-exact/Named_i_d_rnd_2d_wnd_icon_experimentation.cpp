// READABILITY (auto CF):
//  - Body size: ~127 non-empty decompiler lines.
//  - Control keywords: for×7, if×4, do×2, while×2, switch×1, return×1.
//  - Notable callees: FUN_007b6730, FUN_007b6a20, FUN_00824890, WARNING.
//  - Strings: "i_d_rnd_2d_wnd_icon_experimentation"; "i_d_rnd_2d_wnd_icon_reverse_engineering"; "i_d_rnd_2d_wnd_icon_memorization"; "i_d_rnd_2d_wnd_icon_gadgeting".
//  - Return sites: 1.

// =============================================================================
// Named_i_d_rnd_2d_wnd_icon_experimentation
// -----------------------------------------------------------------------------
// Stable ID: aa_00824890
// Address:   0x00824890  (autoassault.exe, image base 0x400000)
// System:    unknown
// Generated: 2026-07-23 from raw capture (scaffold; refine for important units)
// Exactness: Behavior-preserving rewrite of decompiler control flow. Not modernization.
// Bit-for-bit vs retail EXE: DEFERRED (loaded image may differ slightly).
// =============================================================================

/*
 * Behavioral notes:
 * String-driven rename evidence: "i_d_rnd_2d_wnd_icon_experimentation"
 *
 * - Derived from Ghidra decompile; names prefer Ghidra symbols / plate comments.
 * - Remaining FUN_* / DAT_* identifiers are unresolved pending type recovery.
 * - Runtime / differential verification: OPEN unless matrix says otherwise.
 *
 * Readability pass:
 * - undefinedN widths preserved as fixed-width integers where decompiler width is known.
 * - Control flow and call order preserved from authoritative raw.
 */

/* WARNING (jumptable): Unable to track spacebase fully for stack */



void __fastcall Named_i_d_rnd_2d_wnd_icon_experimentation(int param_1)



{

  short sVar1;

  int *piVar2;

  char cVar3;

  byte bVar4;

  int iVar5;

  char *pcVar6;

  char *pcVar7;

  uint32_t /* width from decompiler */ *puVar8;

  uint32_t /* width from decompiler */ *puVar9;

  uint8_t *puVar10;

  uint32_t /* width from decompiler */ uVar11;

  uint8_t uStack_118;

  uint8_t uStack_117;

  uint8_t uStack_116;

  uint8_t uStack_115;

  uint8_t uStack_111;

  uint8_t local_110 [2];

  uint32_t /* width from decompiler */ uStack_10e;

  

  if (((DAT_00d1b6d8 != 0) && (*(int *)(param_1 + 0x508) != 0)) && (*(int *)(param_1 + 0x50c) != 0))

  {

    local_110 = (uint8_t  [2])0x0;

    puVar8 = (uint32_t /* width from decompiler */ *)(local_110 + 2);

    for (iVar5 = 0x40; iVar5 != 0; iVar5 = iVar5 + -1) {

      *puVar8 = 0;

      puVar8 = puVar8 + 1;

    }

    *(uint16_t *)puVar8 = 0;

    sVar1 = *(short *)(DAT_00d1b6d8 + 0x580);

    bVar4 = 0;

    switch(*(uint32_t /* width from decompiler */ *)(param_1 + 0x504)) {

    case 0:

      pcVar6 = "i_d_rnd_2d_wnd_icon_experimentation";

      puVar8 = (uint32_t /* width from decompiler */ *)local_110;

      for (iVar5 = 9; iVar5 != 0; iVar5 = iVar5 + -1) {

        *puVar8 = *(uint32_t /* width from decompiler */ *)pcVar6;

        pcVar6 = pcVar6 + 4;

        puVar8 = puVar8 + 1;

      }

      bVar4 = *(byte *)(DAT_00d1b6d8 + 0x599);

      break;

    case 1:

      pcVar6 = "i_d_rnd_2d_wnd_icon_reverse_engineering";

      puVar8 = (uint32_t /* width from decompiler */ *)local_110;

      for (iVar5 = 10; iVar5 != 0; iVar5 = iVar5 + -1) {

        *puVar8 = *(uint32_t /* width from decompiler */ *)pcVar6;

        pcVar6 = pcVar6 + 4;

        puVar8 = puVar8 + 1;

      }

      bVar4 = *(byte *)(DAT_00d1b6d8 + 0x598);

      break;

    case 2:

      pcVar6 = "i_d_rnd_2d_wnd_icon_memorization";

      pcVar7 = local_110;

      for (iVar5 = 8; iVar5 != 0; iVar5 = iVar5 + -1) {

        *(uint32_t /* width from decompiler */ *)pcVar7 = *(uint32_t /* width from decompiler */ *)pcVar6;

        pcVar6 = pcVar6 + 4;

        pcVar7 = pcVar7 + 4;

      }

      *pcVar7 = *pcVar6;

      bVar4 = *(byte *)(DAT_00d1b6d8 + 0x59a);

      break;

    case 3:

      pcVar6 = "i_d_rnd_2d_wnd_icon_gadgeting";

      puVar8 = (uint32_t /* width from decompiler */ *)local_110;

      for (iVar5 = 7; iVar5 != 0; iVar5 = iVar5 + -1) {

        *puVar8 = *(uint32_t /* width from decompiler */ *)pcVar6;

        pcVar6 = pcVar6 + 4;

        puVar8 = puVar8 + 1;

      }

      *(uint16_t *)puVar8 = *(uint16_t *)pcVar6;

      bVar4 = *(byte *)(DAT_00d1b6d8 + 0x59b);

    }

    puVar8 = (uint32_t /* width from decompiler */ *)&uStack_111;

    do {

      pcVar6 = (char *)((int)puVar8 + 1);

      puVar8 = (uint32_t /* width from decompiler */ *)((int)puVar8 + 1);

    } while (*pcVar6 != '\0');

    *puVar8 = DAT_00a540cc;

    puVar8 = (uint32_t /* width from decompiler */ *)&uStack_111;

    do {

      puVar9 = puVar8;

      puVar8 = (uint32_t /* width from decompiler */ *)((int)puVar9 + 1);

    } while (*(char *)((int)puVar9 + 1) != '\0');

    *(uint32_t /* width from decompiler */ *)((int)puVar9 + 1) = DAT_00a2c53c;

    piVar2 = *(int **)(param_1 + 0x508);

    *(uint8_t *)((int)puVar9 + 5) = DAT_00a2c540;

    if (bVar4 < 10) {

      (**(code **)(*piVar2 + 0x15c))(0,param_1 + 0x500);

      if ((sVar1 < 1) && (*(int *)(DAT_00d1b6d8 + 0x6b4) < 1)) {

        (**(code **)(**(int **)(param_1 + 0x508) + 0xd4))(0);

      }

      else {

        (**(code **)(**(int **)(param_1 + 0x508) + 0xd4))(1);

      }

    }

    else {

      (**(code **)(*piVar2 + 0xd4))(0);

      uStack_116 = 0xff;

      uStack_117 = 0xff;

      uStack_118 = 0x80;

      uStack_115 = 0xff;

      (**(code **)(**(int **)(param_1 + 0x508) + 0x15c))(0,&uStack_118);

    }

    (**(code **)(**(int **)(param_1 + 0x50c) + 0x15c))(0,&DAT_00afdf0c);

    puVar10 = &stack0xfffffedc;

    uVar11 = 0xffffffff;

    FUN_007b6a20(puVar10,0xffffffff);

    cVar3 = FUN_007b6730(puVar10,uVar11);

    if (cVar3 == '\0') {

      pcVar6 = "i_d_s_2d_wnd_icon_default.dds";

      puVar8 = (uint32_t /* width from decompiler */ *)&stack0xfffffedc;

      for (iVar5 = 7; iVar5 != 0; iVar5 = iVar5 + -1) {

        *puVar8 = *(uint32_t /* width from decompiler */ *)pcVar6;

        pcVar6 = pcVar6 + 4;

        puVar8 = puVar8 + 1;

      }

      *(uint16_t *)puVar8 = *(uint16_t *)pcVar6;

    }

    iVar5 = **(int **)(param_1 + 0x50c);

    uVar11 = (**(code **)(**(int **)(param_1 + 0x50c) + 0x2c8))(0);

    (**(code **)(iVar5 + 0x50))(&stack0xfffffedc,uVar11);

  }

  return;

}
