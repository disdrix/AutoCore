// =============================================================================
// UI_timer_timer_count_addon
// -----------------------------------------------------------------------------
// Stable ID: aa_008868a0
// Address:   0x008868a0  (autoassault.exe, image base 0x400000)
// System:    unknown
// Generated: 2026-07-23 from raw capture (scaffold; refine for important units)
// Exactness: Behavior-preserving rewrite of decompiler control flow. Not modernization.
// Bit-for-bit vs retail EXE: DEFERRED (loaded image may differ slightly).
// =============================================================================

// PURPOSE (auto): Scaffold unit for UI_timer_timer_count_addon @ 0x008868a0
// Stable ID: aa_008868a0
// Embedded strings (evidence for future rename):
//   - "i_d_timer_2d_wnd_timer_count_addon.xml"
//   - "i_d_timer_2d_wnd_money.xml"
//   - "i_d_timer_2d_wnd_money_sum.xml"
//   - "i_d_timer_2d_wnd_gogogo.xml"
//   - "i_d_timer_2d_wnd_stop_count.xml"
// Readability: control flow preserved from Ghidra decompile; types tentative.

// READABILITY (auto CF):
//  - Body size: ~186 non-empty decompiler lines.
//  - Control keywords: if×16, do×5, while×5, return×1.
//  - Notable callees: FUN_007b5dd0×7, FUN_00792600, UI_timer_timer_count_addon, FUN_0097ae30, FUN_0097af80, GetTickCount.
//  - Strings: "i_d_timer_2d_wnd_timer_count_addon.xml"; "i_d_timer_2d_wnd_money.xml"; "i_d_timer_2d_wnd_money_sum.xml"; "i_d_timer_2d_wnd_gogogo.xml".
//  - Return sites: 1.

/*
 * Behavioral notes:
 * Plate-driven rename evidence: "i_d_timer_2d_wnd_timer_count_addon.xml"
 * Domain alias of FUN_008868a0 (FUN_* retained)
 *
 * - Derived from Ghidra decompile; names prefer Ghidra symbols / plate comments.
 * - Remaining FUN_* / DAT_* identifiers are unresolved pending type recovery.
 * - Runtime / differential verification: OPEN unless matrix says otherwise.
 *
 * Readability pass:
 * - undefinedN widths preserved as fixed-width integers where decompiler width is known.
 * - Control flow and call order preserved from authoritative raw.
 */

void __fastcall UI_timer_timer_count_addon(int *param_1)



{

  int iVar1;

  void *pvVar2;

  int iVar3;

  int *piVar4;

  int *piVar5;

  DWORD DVar6;

  char *pcStack_5c;

  char *pcStack_40;

  void *pvStack_14;

  uint8_t *puStack_10;

  uint32_t /* width from decompiler */ uStack_c;

  

  pcStack_40 = &stack0xfffffffc;

  uStack_c = 0xffffffff;

  puStack_10 = &LAB_009b397a;

  pvStack_14 = ExceptionList;

  ExceptionList = &pvStack_14;

  FUN_00792600();

  iVar1 = param_1[0x1a] + 1;

  param_1[0x1a] = iVar1;

  param_1[0x1d] = (int)(float)-iVar1;

  if (param_1[0x1c] < iVar1) {

    param_1[0x1c] = iVar1;

  }

  (**(code **)(*param_1 + 0x3f4))();

  pvVar2 = operator_new(0x488);

  iVar1 = 0;

  puStack_10 = (uint8_t *)0x0;

  if (pvVar2 == (void *)0x0) {

    iVar3 = 0;

  }

  else {

    iVar3 = FUN_007b5dd0();

  }

  puStack_10 = (uint8_t *)0xffffffff;

  param_1[0x154] = iVar3;

  (**(code **)(*param_1 + 0xa8))();

  (**(code **)(*(int *)param_1[0x154] + 0x28))();

  pcStack_5c = (char *)0x88694b;

  pcStack_5c = operator_new(0x488);

  pcStack_40 = pcStack_5c;

  if (pcStack_5c == (char *)0x0) {

    iVar3 = 0;

  }

  else {

    iVar3 = FUN_007b5dd0();

  }

  param_1[0x155] = iVar3;

  pcStack_5c = (char *)0x88697e;

  (**(code **)(*param_1 + 0xa8))();

  pcStack_5c = "i_d_timer_2d_wnd_timer_count_addon.xml";

  (**(code **)(*(int *)param_1[0x155] + 0x28))();

  if (*(char *)((int)param_1 + 0x545) != '\0') {

    pvVar2 = operator_new(0x488);

    if (pvVar2 == (void *)0x0) {

      iVar3 = 0;

    }

    else {

      iVar3 = FUN_007b5dd0(pvVar2);

    }

    param_1[0x157] = iVar3;

    (**(code **)(*param_1 + 0xa8))();

    (**(code **)(*(int *)param_1[0x157] + 0x28))("i_d_timer_2d_wnd_money.xml");

    pvVar2 = operator_new(0x488);

    if (pvVar2 == (void *)0x0) {

      iVar3 = 0;

    }

    else {

      iVar3 = FUN_007b5dd0(pvVar2,0);

    }

    param_1[0x158] = iVar3;

    (**(code **)(*param_1 + 0xa8))(iVar3);

    (**(code **)(*(int *)param_1[0x158] + 0x28))("i_d_timer_2d_wnd_money_sum.xml");

    piVar5 = param_1 + 0x159;

    do {

      pvVar2 = operator_new(0x488);

      if (pvVar2 == (void *)0x0) {

        piVar4 = (int *)0x0;

      }

      else {

        piVar4 = (int *)FUN_007b5dd0(pvVar2);

      }

      *piVar5 = (int)piVar4;

      (**(code **)(*piVar4 + 0x28))();

      (**(code **)(*(int *)*piVar5 + 0x120))(&pcStack_40,1,0);

      piVar4 = (int *)(**(code **)(*(int *)*piVar5 + 0x140))(&stack0xffffffbc,1);

      pcStack_5c = pcStack_5c + -(*piVar4 * iVar1);

      (**(code **)(*(int *)*piVar5 + 0x114))(&pcStack_5c);

      (**(code **)(*param_1 + 0xa8))(*piVar5);

      iVar1 = iVar1 + 1;

      piVar5 = piVar5 + 1;

    } while (iVar1 < 9);

  }

  pvVar2 = operator_new(0x488);

  if (pvVar2 == (void *)0x0) {

    iVar1 = 0;

  }

  else {

    iVar1 = FUN_007b5dd0(pvVar2);

  }

  param_1[0x153] = iVar1;

  (**(code **)(*param_1 + 0xa8))();

  (**(code **)(*(int *)param_1[0x153] + 0x28))("i_d_timer_2d_wnd_gogogo.xml");

  pvVar2 = operator_new(0x488);

  if (pvVar2 == (void *)0x0) {

    iVar1 = 0;

  }

  else {

    iVar1 = FUN_007b5dd0(pvVar2,0);

  }

  param_1[0x156] = iVar1;

  (**(code **)(*param_1 + 0xa8))(iVar1);

  (**(code **)(*(int *)param_1[0x156] + 0x28))("i_d_timer_2d_wnd_stop_count.xml");

  if ((DAT_00d1b6d8 != 0) && (*(char *)(DAT_00d1b6d8 + 0x30c) == '\0')) {

    (**(code **)(*(int *)param_1[0x154] + 0x15c))(1,&DAT_00afdf00);

    (**(code **)(*(int *)param_1[0x153] + 0x15c))(1,&DAT_00afdefc);

    (**(code **)(*(int *)param_1[0x156] + 0x15c))(1,&DAT_00afdf00);

    if (*(char *)((int)param_1 + 0x545) != '\0') {

      (**(code **)(*(int *)param_1[0x157] + 0x15c))(1,&DAT_00afdf08);

      (**(code **)(*(int *)param_1[0x158] + 0x15c))(1,&DAT_00afdef4);

      piVar5 = param_1 + 0x159;

      iVar1 = 9;

      do {

        (**(code **)(*(int *)*piVar5 + 0x15c))(1,&DAT_00afdf00);

        piVar5 = piVar5 + 1;

        iVar1 = iVar1 + -1;

      } while (iVar1 != 0);

      if (param_1[0x162] != 0) {

        (**(code **)(*param_1 + 0xa8))(param_1[0x162]);

        (**(code **)(*(int *)param_1[0x162] + 0xcc))(1);

        FUN_0097ae30();

        iVar1 = param_1[0x162];

        piVar5 = (int *)**(int **)(iVar1 + 0x548);

        if (piVar5 != *(int **)(iVar1 + 0x548)) {

          do {

            FUN_0097af80(iVar1);

            piVar5 = (int *)*piVar5;

          } while (piVar5 != (int *)*(int *)(iVar1 + 0x548));

        }

      }

    }

  }

  if ((float)param_1[0x14c] <= g_flZero) {

    (**(code **)(*(int *)param_1[0x156] + 0xfc))(1,0x3f000000);

    (**(code **)(*(int *)param_1[0x153] + 0xcc))(0);

    (**(code **)(*(int *)param_1[0x154] + 0xfc))(1,0x3f000000);

    (**(code **)(*(int *)param_1[0x155] + 0xcc))(1);

    if (*(char *)((int)param_1 + 0x545) != '\0') {

      (**(code **)(*(int *)param_1[0x157] + 0xfc))(1,0x3f000000);

      (**(code **)(*(int *)param_1[0x158] + 0xfc))(1,0x3f000000);

      piVar5 = param_1 + 0x159;

      iVar1 = 9;

      do {

        (**(code **)(*(int *)*piVar5 + 0xcc))(1);

        piVar5 = piVar5 + 1;

        iVar1 = iVar1 + -1;

      } while (iVar1 != 0);

    }

  }

  else {

    (**(code **)(*(int *)param_1[0x153] + 0xfc))();

    (**(code **)(*(int *)param_1[0x154] + 0xcc))(0);

    (**(code **)(*(int *)param_1[0x154] + 0xcc))(0);

    (**(code **)(*(int *)param_1[0x156] + 0xcc))(0);

    if (*(char *)((int)param_1 + 0x545) != '\0') {

      (**(code **)(*(int *)param_1[0x157] + 0xcc))(0);

      (**(code **)(*(int *)param_1[0x158] + 0xcc))(0);

      piVar5 = param_1 + 0x159;

      iVar1 = 9;

      do {

        (**(code **)(*(int *)*piVar5 + 0xcc))(0);

        piVar5 = piVar5 + 1;

        iVar1 = iVar1 + -1;

      } while (iVar1 != 0);

      piVar5 = (int *)(**(code **)(*(int *)param_1[0x157] + 0x120))(&stack0xffffffa0,1,0);

      param_1[0x148] = *piVar5;

      param_1[0x149] = piVar5[1];

    }

  }

  DVar6 = GetTickCount();

  param_1[0x152] = DVar6;

  (**(code **)(*param_1 + 0x34c))();

  ExceptionList = (void *)0x1;

  return;

}
