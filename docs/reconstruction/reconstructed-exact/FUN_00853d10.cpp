// =============================================================================
// FUN_00853d10
// -----------------------------------------------------------------------------
// Stable ID: aa_00853d10
// Address:   0x00853d10  (autoassault.exe, image base 0x400000)
// System:    unknown
// Generated: 2026-07-23 from raw capture (scaffold; refine for important units)
// Exactness: Behavior-preserving rewrite of decompiler control flow. Not modernization.
// Bit-for-bit vs retail EXE: DEFERRED (loaded image may differ slightly).
// =============================================================================

// PURPOSE (auto): Scaffold unit for FUN_00853d10 @ 0x00853d10
// Stable ID: aa_00853d10
// Embedded strings (evidence for future rename):
//   - "i_d_q_2d_wnd_details_summary.xml"
//   - "i_d_q_2d_wnd_details_desc_label.xml"
//   - "i_d_q_2d_wnd_details_description.xml"
//   - "i_d_q_2d_wnd_details_rewards.xml"
//   - "i_d_q_2d_wnd_details_items_bg.xml"
//   - "i_d_q_2d_wnd_details_items_bg_icon.xml"
// Readability: control flow preserved from Ghidra decompile; types tentative.

// READABILITY (auto CF):
//  - Body size: ~181 non-empty decompiler lines.
//  - Control keywords: if×11, do×1, while×1, return×1.
//  - Notable callees: FUN_007b5dd0×11, FUN_00853210×11, FUN_00792600, FUN_00853d10.
//  - Strings: "i_d_q_2d_wnd_details_summary.xml"; "i_d_q_2d_wnd_details_desc_label.xml"; "i_d_q_2d_wnd_details_description.xml"; "i_d_q_2d_wnd_details_rewards.xml".
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

void __fastcall FUN_00853d10(int *param_1)



{

  void *pvVar1;

  int iVar2;

  void *pvVar3;

  int iVar4;

  int *piVar5;

  char *pcStack_44;

  void *pvStack_c;

  uint8_t *puStack_8;

  uint32_t /* width from decompiler */ local_4;

  

  local_4 = 0xffffffff;

  puStack_8 = &LAB_009b36cb;

  pvStack_c = ExceptionList;

  ExceptionList = &pvStack_c;

  FUN_00792600();

  pvVar1 = operator_new(0x488);

  local_4 = 0;

  if (pvVar1 == (void *)0x0) {

    iVar2 = 0;

  }

  else {

    iVar2 = FUN_007b5dd0();

  }

  local_4 = 0xffffffff;

  param_1[0x140] = iVar2;

  (**(code **)(*param_1 + 0xa8))();

  (**(code **)(*(int *)param_1[0x140] + 0x28))();

  (**(code **)(*(int *)param_1[0x140] + 0x24))();

  *(uint8_t *)(param_1[0x140] + 0xd8) = 1;

  FUN_00853210();

  pvVar1 = operator_new(0x488);

  if (pvVar1 == (void *)0x0) {

    iVar2 = 0;

  }

  else {

    iVar2 = FUN_007b5dd0();

  }

  param_1[0x141] = iVar2;

  (**(code **)(*param_1 + 0xa8))();

  (**(code **)(*(int *)param_1[0x141] + 0x28))();

  (**(code **)(*(int *)param_1[0x141] + 0x24))();

  *(uint8_t *)(param_1[0x141] + 0xd8) = 1;

  FUN_00853210();

  pcStack_44 = (char *)0x853e27;

  pcStack_44 = operator_new(0x488);

  if (pcStack_44 == (char *)0x0) {

    iVar2 = 0;

  }

  else {

    iVar2 = FUN_007b5dd0();

  }

  param_1[0x142] = iVar2;

  pcStack_44 = (char *)0x853e5b;

  (**(code **)(*param_1 + 0xa8))();

  pcStack_44 = "i_d_q_2d_wnd_details_summary.xml";

  (**(code **)(*(int *)param_1[0x142] + 0x28))();

  (**(code **)(*(int *)param_1[0x142] + 0x24))(1);

  *(uint8_t *)(param_1[0x142] + 0xd8) = 1;

  FUN_00853210();

  pvVar1 = operator_new(0x488);

  if (pvVar1 == (void *)0x0) {

    iVar2 = 0;

  }

  else {

    iVar2 = FUN_007b5dd0(pvVar1,0);

  }

  param_1[0x144] = iVar2;

  (**(code **)(*param_1 + 0xa8))(iVar2);

  (**(code **)(*(int *)param_1[0x144] + 0x28))("i_d_q_2d_wnd_details_summary.xml");

  (**(code **)(*(int *)param_1[0x144] + 0x24))(1);

  *(uint8_t *)(param_1[0x144] + 0xd8) = 1;

  pcStack_44 = (char *)0xfff5e664;

  (**(code **)(*(int *)param_1[0x144] + 0x15c))(1,&pcStack_44);

  FUN_00853210();

  pvVar1 = operator_new(0x488);

  if (pvVar1 == (void *)0x0) {

    iVar2 = 0;

  }

  else {

    iVar2 = FUN_007b5dd0(pvVar1,0);

  }

  param_1[0x143] = iVar2;

  (**(code **)(*param_1 + 0xa8))(iVar2);

  (**(code **)(*(int *)param_1[0x143] + 0x28))("i_d_q_2d_wnd_details_desc_label.xml");

  (**(code **)(*(int *)param_1[0x143] + 0x24))(1);

  *(uint8_t *)(param_1[0x143] + 0xd8) = 1;

  FUN_00853210();

  pvVar1 = operator_new(0x488);

  if (pvVar1 == (void *)0x0) {

    iVar2 = 0;

  }

  else {

    iVar2 = FUN_007b5dd0(pvVar1,0);

  }

  param_1[0x145] = iVar2;

  (**(code **)(*param_1 + 0xa8))(iVar2);

  (**(code **)(*(int *)param_1[0x145] + 0x28))("i_d_q_2d_wnd_details_description.xml");

  (**(code **)(*(int *)param_1[0x145] + 0x24))(1);

  *(uint8_t *)(param_1[0x145] + 0xd8) = 1;

  FUN_00853210();

  pvVar1 = operator_new(0x488);

  if (pvVar1 == (void *)0x0) {

    iVar2 = 0;

  }

  else {

    iVar2 = FUN_007b5dd0(pvVar1,0);

  }

  param_1[0x146] = iVar2;

  (**(code **)(*param_1 + 0xa8))(iVar2);

  (**(code **)(*(int *)param_1[0x146] + 0x28))("i_d_q_2d_wnd_details_rewards.xml");

  (**(code **)(*(int *)param_1[0x146] + 0x24))(1);

  *(uint8_t *)(param_1[0x146] + 0xd8) = 1;

  FUN_00853210();

  pvVar1 = (void *)0x0;

  piVar5 = param_1 + 0x147;

  do {

    pvVar3 = operator_new(0x488);

    if (pvVar3 == (void *)0x0) {

      iVar4 = 0;

    }

    else {

      iVar4 = FUN_007b5dd0(pvVar3,0);

    }

    *piVar5 = iVar4;

    (**(code **)(*param_1 + 0xa8))(iVar4);

    (**(code **)(*(int *)*piVar5 + 0x28))("i_d_q_2d_wnd_details_items_bg.xml");

    (**(code **)(*(int *)*piVar5 + 0x74))(iVar2 + 40000);

    (**(code **)(*(int *)*piVar5 + 0x24))(1);

    *(uint8_t *)(*piVar5 + 0xd8) = 1;

    (**(code **)(*(int *)*piVar5 + 0xcc))(0);

    FUN_00853210();

    pvVar3 = operator_new(0x488);

    if (pvVar3 == (void *)0x0) {

      iVar4 = 0;

    }

    else {

      iVar4 = FUN_007b5dd0(pvVar3,0);

    }

    piVar5[4] = iVar4;

    (**(code **)(*param_1 + 0xa8))(iVar4);

    (**(code **)(*(int *)piVar5[4] + 0x28))("i_d_q_2d_wnd_details_items_bg_icon.xml");

    (**(code **)(*(int *)piVar5[4] + 0x24))(1);

    *(uint8_t *)(piVar5[4] + 0xd8) = 1;

    (**(code **)(*(int *)piVar5[4] + 0xcc))(0);

    FUN_00853210();

    pvVar3 = operator_new(0x488);

    if (pvVar3 == (void *)0x0) {

      iVar4 = 0;

    }

    else {

      iVar4 = FUN_007b5dd0(pvVar3,0);

    }

    piVar5[8] = iVar4;

    (**(code **)(*param_1 + 0xa8))(iVar4);

    (**(code **)(*(int *)piVar5[8] + 0x28))("i_d_q_2d_wnd_details_items_icon.xml");

    (**(code **)(*(int *)piVar5[8] + 0x24))(1);

    *(uint8_t *)(piVar5[8] + 0xd8) = 1;

    (**(code **)(*(int *)piVar5[8] + 0xcc))(0);

    FUN_00853210();

    pvVar3 = operator_new(0x488);

    if (pvVar3 == (void *)0x0) {

      iVar4 = 0;

    }

    else {

      iVar4 = FUN_007b5dd0(pvVar3,0);

    }

    piVar5[0xc] = iVar4;

    (**(code **)(*param_1 + 0xa8))(iVar4);

    (**(code **)(*(int *)piVar5[0xc] + 0x28))("i_d_q_2d_wnd_details_items_text.xml");

    (**(code **)(*(int *)piVar5[0xc] + 0x24))(1);

    *(uint8_t *)(piVar5[0xc] + 0xd8) = 1;

    (**(code **)(*(int *)piVar5[0xc] + 0xcc))(0);

    FUN_00853210();

    pvVar1 = (void *)((int)pvVar1 + 1);

    piVar5 = piVar5 + 1;

  } while ((int)pvVar1 < 4);

  (**(code **)(*param_1 + 0xfc))(1,0x3f000000);

  ExceptionList = pvVar1;

  return;

}
