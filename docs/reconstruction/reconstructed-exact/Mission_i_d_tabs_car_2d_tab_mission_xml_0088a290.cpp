// READABILITY (auto CF):
//  - Body size: ~88 non-empty decompiler lines.
//  - Control keywords: if×6, return×1.
//  - Notable callees: FUN_007b5dd0×2, FUN_008230b0×2, FUN_00792600, FUN_0079c860, FUN_00864f20, FUN_00889fb0, FUN_0088a290.
//  - Strings: "i_d_tabs_car_2d_wnd_bg_fill.xml"; "i_d_tabs_car_2d_wnd_fx.xml"; "i_d_tabs_car_2d_wnd_bg_texture.xml"; "i_d_tabs_car_2d_tab_cargo.xml".
//  - Return sites: 1.

// =============================================================================
// Mission_i_d_tabs_car_2d_tab_mission_xml_0088a290
// -----------------------------------------------------------------------------
// Stable ID: aa_0088a290
// Address:   0x0088a290  (autoassault.exe, image base 0x400000)
// System:    unknown
// Generated: 2026-07-23 from raw capture (scaffold; refine for important units)
// Exactness: Behavior-preserving rewrite of decompiler control flow. Not modernization.
// Bit-for-bit vs retail EXE: DEFERRED (loaded image may differ slightly).
// =============================================================================

/*
 * Behavioral notes:
 * String-driven rename evidence: "i_d_tabs_car_2d_tab_mission.xml"
 *
 * - Derived from Ghidra decompile; names prefer Ghidra symbols / plate comments.
 * - Remaining FUN_* / DAT_* identifiers are unresolved pending type recovery.
 * - Runtime / differential verification: OPEN unless matrix says otherwise.
 *
 * Readability pass:
 * - undefinedN widths preserved as fixed-width integers where decompiler width is known.
 * - Control flow and call order preserved from authoritative raw.
 */

void __fastcall Mission_i_d_tabs_car_2d_tab_mission_xml_0088a290(int *param_1)



{

  void *pvVar1;

  int iVar2;

  void *pvVar3;

  void *pvStack_c;

  uint8_t *puStack_8;

  uint32_t /* width from decompiler */ local_4;

  

  local_4 = 0xffffffff;

  puStack_8 = &LAB_009b5922;

  pvStack_c = ExceptionList;

  ExceptionList = &pvStack_c;

  FUN_00792600();

  pvVar1 = operator_new(0x488);

  local_4 = 0;

  if (pvVar1 == (void *)0x0) {

    iVar2 = 0;

  }

  else {

    iVar2 = FUN_007b5dd0(pvVar1,0);

  }

  local_4 = 0xffffffff;

  param_1[0x148] = iVar2;

  (**(code **)(*param_1 + 0xa8))(iVar2);

  (**(code **)(*(int *)param_1[0x148] + 0x28))("i_d_tabs_car_2d_wnd_bg_fill.xml");

  pvVar1 = operator_new(0x4bc);

  pvStack_c = (void *)0x1;

  if (pvVar1 == (void *)0x0) {

    iVar2 = 0;

  }

  else {

    iVar2 = FUN_00864f20(pvVar1);

  }

  pvStack_c = (void *)0xffffffff;

  param_1[0x149] = iVar2;

  (**(code **)(*param_1 + 0xa8))(iVar2);

  (**(code **)(*(int *)param_1[0x149] + 0x28))("i_d_tabs_car_2d_wnd_fx.xml");

  pvVar1 = operator_new(0x488);

  if (pvVar1 == (void *)0x0) {

    iVar2 = 0;

  }

  else {

    iVar2 = FUN_007b5dd0(pvVar1,0);

  }

  param_1[0x147] = iVar2;

  (**(code **)(*param_1 + 0xa8))(iVar2);

  (**(code **)(*(int *)param_1[0x147] + 0x28))("i_d_tabs_car_2d_wnd_bg_texture.xml");

  pvVar1 = operator_new(0x81c);

  if (pvVar1 == (void *)0x0) {

    iVar2 = 0;

  }

  else {

    iVar2 = FUN_008230b0(pvVar1);

  }

  param_1[0x145] = iVar2;

  (**(code **)(*param_1 + 0xa8))(iVar2);

  (**(code **)(*(int *)param_1[0x145] + 0x28))("i_d_tabs_car_2d_tab_cargo.xml");

  (**(code **)(*(int *)param_1[0x145] + 0x43c))();

  (**(code **)(*(int *)param_1[0x145] + 0x74))(0x9c42);

  pvVar1 = operator_new(0x81c);

  if (pvVar1 == (void *)0x0) {

    iVar2 = 0;

  }

  else {

    iVar2 = FUN_008230b0(pvVar1);

  }

  param_1[0x146] = iVar2;

  (**(code **)(*param_1 + 0xa8))(iVar2);

  (**(code **)(*(int *)param_1[0x146] + 0x28))("i_d_tabs_car_2d_tab_mission.xml");

  (**(code **)(*(int *)param_1[0x146] + 0x43c))();

  (**(code **)(*(int *)param_1[0x146] + 0x74))(0x9c43);

  (**(code **)(*param_1 + 0xa8))(param_1[0x143]);

  (**(code **)(*param_1 + 0xa8))(param_1[0x144]);

  pvVar1 = operator_new(0x4cc);

  pvVar3 = (void *)0x0;

  if (pvVar1 != (void *)0x0) {

    pvVar3 = (void *)FUN_0079c860();

  }

  param_1[0x141] = (int)pvVar3;

  (**(code **)(*param_1 + 0xa8))();

  (**(code **)(*(int *)param_1[0x141] + 0x28))("i_d_tabs_s_2d_btn_close.xml");

  (**(code **)(*(int *)param_1[0x141] + 0x74))(40000);

  FUN_00889fb0(param_1,1);

  (**(code **)(*param_1 + 0xfc))(1,0x3f000000);

  (**(code **)(*param_1 + 0x34c))();

  ExceptionList = pvVar3;

  return;

}
