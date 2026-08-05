// =============================================================================
// FUN_008cc930
// -----------------------------------------------------------------------------
// Stable ID: aa_008cc930
// Address:   0x008cc930  (autoassault.exe, image base 0x400000)
// System:    unknown
// Generated: 2026-07-23 from raw capture (scaffold; refine for important units)
// Exactness: Behavior-preserving rewrite of decompiler control flow. Not modernization.
// Bit-for-bit vs retail EXE: DEFERRED (loaded image may differ slightly).
// =============================================================================

// PURPOSE (auto): Scaffold unit for FUN_008cc930 @ 0x008cc930
// Stable ID: aa_008cc930
// Embedded strings (evidence for future rename):
//   - "i_g_2d_btn_generic"
//   - "i_g_2d_btn_generic_orange"
//   - "Mutant"
//   - "Biomek"
//   - "Human"
//   - "Level"
// Readability: control flow preserved from Ghidra decompile; types tentative.

// READABILITY (auto CF):
//  - Body size: ~242 non-empty decompiler lines.
//  - Control keywords: if×34, do×5, while×5, goto×3, for×3, return×1.
//  - Notable callees: FUN_007a69d0×3, FUN_007a6de0×3, FUN_008cc500, FUN_008cc7f0, FUN_008cc930, sprintf.
//  - Strings: "i_g_2d_btn_generic"; "i_g_2d_btn_generic_orange"; "Mutant"; "Biomek".
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

void __fastcall FUN_008cc930(int param_1)



{

  char cVar1;

  uint8_t *puVar2;

  uint32_t /* width from decompiler */ uVar3;

  char *pcVar4;

  char *pcVar5;

  uint uVar6;

  int iVar7;

  uint uVar8;

  int *piVar9;

  int iVar10;

  uint32_t /* width from decompiler */ *puVar11;

  uint32_t /* width from decompiler */ uVar12;

  int local_68c;

  char acStack_654 [64];

  uint8_t auStack_614 [256];

  char acStack_514 [255];

  char cStack_415;

  char acStack_414 [2];

  uint32_t /* width from decompiler */ auStack_412 [259];

  

  iVar10 = 0;

  local_68c = 0;

  piVar9 = (int *)(param_1 + 0x59c);

  do {

    if (*piVar9 != 0) {

      if ((DAT_00d1a980 == iVar10) && (*(int *)(((int)&DAT_00d1b140 - param_1) + (int)piVar9) != 0))

      {

        cVar1 = (**(code **)(*(int *)*piVar9 + 0x3bc))();

        if (cVar1 == '\0') {

          (**(code **)(*(int *)*piVar9 + 0x3c8))(1,1);

          (**(code **)(*(int *)*piVar9 + 0x34c))();

        }

      }

      else {

        cVar1 = (**(code **)(*(int *)*piVar9 + 0x3bc))();

        if (cVar1 != '\0') {

          (**(code **)(*(int *)*piVar9 + 0x3c8))(0,1);

          (**(code **)(*(int *)*piVar9 + 0x34c))();

        }

      }

    }

    if (*(int *)(((int)&DAT_00d1b140 - param_1) + (int)piVar9) != 0) {

      local_68c = local_68c + 1;

    }

    iVar10 = iVar10 + 1;

    piVar9 = piVar9 + 1;

  } while (iVar10 < 0xc);

  if (*(int *)(param_1 + 0x558) != 0) {

    iVar10 = (**(code **)(**(int **)(param_1 + 0x558) + 0x164))(0);

    *(uint8_t *)(iVar10 + 2) = 0xff;

    iVar10 = (**(code **)(**(int **)(param_1 + 0x558) + 0x164))(0);

    *(uint8_t *)(iVar10 + 1) = 0xff;

    puVar2 = (uint8_t *)(**(code **)(**(int **)(param_1 + 0x558) + 0x164))(0);

    *puVar2 = 0xff;

    if (&stack0x00000000 == (uint8_t *)0x10) {

      (**(code **)(**(int **)(param_1 + 0x558) + 0xd4))(0);

    }

    else {

      (**(code **)(**(int **)(param_1 + 0x558) + 0xd4))(1);

    }

    (**(code **)(**(int **)(param_1 + 0x558) + 0x34c))();

  }

  if (local_68c == 0) {

    if (*(int *)(param_1 + 0x590) != 0) {

      (**(code **)(**(int **)(param_1 + 0x590) + 0x3ac))("i_g_2d_btn_generic");

      (**(code **)(**(int **)(param_1 + 0x590) + 0xd4))(0);

      (**(code **)(**(int **)(param_1 + 0x590) + 0x34c))();

    }

    if (*(int *)(param_1 + 0x58c) != 0) {

      (**(code **)(**(int **)(param_1 + 0x58c) + 0xd4))(0);

      (**(code **)(**(int **)(param_1 + 0x58c) + 0x34c))();

    }

    if (*(int *)(param_1 + 0x560) != 0) {

      (**(code **)(**(int **)(param_1 + 0x560) + 4))(0);

    }

    if (*(int *)(param_1 + 0x564) != 0) {

      (**(code **)(**(int **)(param_1 + 0x564) + 4))(0);

    }

    if (*(int *)(param_1 + 0x54c) != 0) {

      (**(code **)(**(int **)(param_1 + 0x54c) + 4))(0);

    }

    if (*(int *)(param_1 + 0x558) == 0) goto LAB_008ccc5e;

    (**(code **)(**(int **)(param_1 + 0x558) + 0x3ac))("i_g_2d_btn_generic_orange");

    cVar1 = (**(code **)(**(int **)(param_1 + 0x558) + 0xd8))();

    iVar10 = **(int **)(param_1 + 0x558);

    if (cVar1 == '\0') {

      (**(code **)(iVar10 + 0xd4))();

      (**(code **)(**(int **)(param_1 + 0x558) + 0xd4))(0);

    }

    else {

LAB_008ccc4a:

      (**(code **)(iVar10 + 0xd4))(1);

    }

  }

  else {

    if (*(int *)(param_1 + 0x590) != 0) {

      (**(code **)(**(int **)(param_1 + 0x590) + 0x3ac))("i_g_2d_btn_generic_orange");

      (**(code **)(**(int **)(param_1 + 0x590) + 0xd4))(1);

      (**(code **)(**(int **)(param_1 + 0x590) + 0x34c))();

    }

    if (*(int *)(param_1 + 0x58c) != 0) {

      (**(code **)(**(int **)(param_1 + 0x58c) + 0xd4))(1);

      (**(code **)(**(int **)(param_1 + 0x58c) + 0x34c))();

    }

    if (*(int *)(param_1 + 0x560) != 0) {

      (**(code **)(**(int **)(param_1 + 0x560) + 4))(1);

    }

    if (*(int *)(param_1 + 0x564) != 0) {

      (**(code **)(**(int **)(param_1 + 0x564) + 4))(1);

    }

    if (*(int *)(param_1 + 0x54c) != 0) {

      (**(code **)(**(int **)(param_1 + 0x54c) + 4))(1);

    }

    if (*(int *)(param_1 + 0x558) == 0) goto LAB_008ccc5e;

    (**(code **)(**(int **)(param_1 + 0x558) + 0x3ac))("i_g_2d_btn_generic");

    cVar1 = (**(code **)(**(int **)(param_1 + 0x558) + 0xd8))();

    iVar10 = **(int **)(param_1 + 0x558);

    if (cVar1 != '\0') goto LAB_008ccc4a;

    (**(code **)(iVar10 + 0xd4))(1);

    (**(code **)(**(int **)(param_1 + 0x558) + 0xd4))(0);

  }

  (**(code **)(**(int **)(param_1 + 0x558) + 0x34c))();

LAB_008ccc5e:

  iVar10 = DAT_00d1a980;

  if ((*(int *)(param_1 + 0x62c) != 0) && (*(int *)(param_1 + 0x630) != 0)) {

    if ((DAT_00d1a980 < 0) || ((0xb < DAT_00d1a980 || ((&DAT_00d1b6dc)[DAT_00d1a980] == 0)))) {

      (**(code **)(**(int **)(param_1 + 0x62c) + 0x1d8))(0,1,1);

      (**(code **)(**(int **)(param_1 + 0x630) + 0x1d8))(0,1,1);

      if (*(int *)(param_1 + 0x63c) != 0) {

        (**(code **)(**(int **)(param_1 + 0x63c) + 4))(0);

      }

      if (*(int *)(param_1 + 0x634) != 0) {

        (**(code **)(**(int **)(param_1 + 0x634) + 4))(0);

      }

      if (*(int *)(param_1 + 0x638) != 0) {

        (**(code **)(**(int **)(param_1 + 0x638) + 4))(0);

      }

    }

    else {

      iVar7 = **(int **)(param_1 + 0x62c);

      uVar3 = (**(code **)(*(int *)(*(int *)(*(int *)((&DAT_00d1b6dc)[DAT_00d1a980] + 4) + 4) + 4 +

                                   (&DAT_00d1b6dc)[DAT_00d1a980]) + 0x160))(1,0);

      (**(code **)(iVar7 + 0x1d8))(uVar3);

      (**(code **)(**(int **)(param_1 + 0x62c) + 0x1f0))();

      acStack_414[0] = '\0';

      acStack_414[1] = '\0';

      puVar11 = auStack_412;

      for (iVar7 = 0xff; iVar7 != 0; iVar7 = iVar7 + -1) {

        *puVar11 = 0;

        puVar11 = puVar11 + 1;

      }

      *(uint16_t *)puVar11 = 0;

      FUN_008cc7f0();

      cVar1 = *(char *)(*(int *)(*(int *)(*(int *)(*(int *)((&DAT_00d1b6dc)[iVar10] + 4) + 4) + 0xac

                                         + (&DAT_00d1b6dc)[iVar10]) + 0x3c) + 0x532);

      if (cVar1 == '\x01') {

        pcVar4 = "Mutant";

      }

      else if (cVar1 == '\x02') {

        pcVar4 = "Biomek";

      }

      else {

        pcVar4 = "Human";

      }

      uVar3 = 0xffffffff;

      FUN_007a69d0(pcVar4,0xffffffff);

      pcVar5 = (char *)FUN_007a6de0(pcVar4,uVar3);

      pcVar4 = &stack0xfffff96c;

      do {

        cVar1 = *pcVar5;

        *pcVar4 = cVar1;

        pcVar5 = pcVar5 + 1;

        pcVar4 = pcVar4 + 1;

      } while (cVar1 != '\0');

      uVar12 = 0xffffffff;

      uVar3 = FUN_008cc500(0xffffffff);

      FUN_007a69d0(uVar3);

      pcVar5 = (char *)FUN_007a6de0(uVar3,uVar12);

      pcVar4 = acStack_654;

      do {

        cVar1 = *pcVar5;

        *pcVar4 = cVar1;

        pcVar5 = pcVar5 + 1;

        pcVar4 = pcVar4 + 1;

      } while (cVar1 != '\0');

      uVar3 = (**(code **)(*(int *)(*(int *)(*(int *)((&DAT_00d1b6dc)[iVar10] + 4) + 4) + 4 +

                                   (&DAT_00d1b6dc)[iVar10]) + 0x27c))

                        (&stack0xfffff96c,acStack_654,auStack_614);

      uVar12 = 0xffffffff;

      pcVar4 = "Level";

      FUN_007a69d0("Level",0xffffffff,uVar3);

      uVar3 = FUN_007a6de0(pcVar4,uVar12);

      sprintf(acStack_514,"%s %d %s %s\n%s",uVar3);

      pcVar4 = acStack_514;

      do {

        cVar1 = *pcVar4;

        pcVar4 = pcVar4 + 1;

      } while (cVar1 != '\0');

      uVar6 = (int)pcVar4 - (int)acStack_514;

      pcVar4 = &cStack_415;

      do {

        pcVar5 = pcVar4 + 1;

        pcVar4 = pcVar4 + 1;

      } while (*pcVar5 != '\0');

      pcVar5 = acStack_514;

      for (uVar8 = uVar6 >> 2; uVar8 != 0; uVar8 = uVar8 - 1) {

        *(uint32_t /* width from decompiler */ *)pcVar4 = *(uint32_t /* width from decompiler */ *)pcVar5;

        pcVar5 = pcVar5 + 4;

        pcVar4 = pcVar4 + 4;

      }

      for (uVar6 = uVar6 & 3; uVar6 != 0; uVar6 = uVar6 - 1) {

        *pcVar4 = *pcVar5;

        pcVar5 = pcVar5 + 1;

        pcVar4 = pcVar4 + 1;

      }

      (**(code **)(**(int **)(param_1 + 0x630) + 0x1d8))(acStack_414,1,1);

      (**(code **)(**(int **)(param_1 + 0x630) + 0x1f0))();

      if (*(int *)(param_1 + 0x63c) != 0) {

        (**(code **)(**(int **)(param_1 + 0x63c) + 4))(1);

      }

      if (*(int *)(param_1 + 0x634) != 0) {

        (**(code **)(**(int **)(param_1 + 0x634) + 4))(1);

      }

      if (*(int *)(param_1 + 0x638) != 0) {

        (**(code **)(**(int **)(param_1 + 0x638) + 4))(1);

      }

    }

    (**(code **)(**(int **)(param_1 + 0x62c) + 0x34c))();

    (**(code **)(**(int **)(param_1 + 0x630) + 0x34c))();

  }

  if ((DAT_00d1b77c != 0) && (*(int *)(param_1 + 0x598) != 0)) {

    if (*(int *)(DAT_00d1b77c + 0xab8) == -1) {

      (**(code **)(**(int **)(param_1 + 0x598) + 0x1d8))("-Unknown Server-");

    }

    else {

      (**(code **)(**(int **)(param_1 + 0x598) + 0x1d8))(DAT_00d1b77c + 0xac8,1,1);

    }

    (**(code **)(**(int **)(param_1 + 0x598) + 0x34c))();

  }

  return;

}
