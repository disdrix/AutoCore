// =============================================================================
// UI_f_frame_friends
// -----------------------------------------------------------------------------
// Stable ID: aa_008da870
// Address:   0x008da870  (autoassault.exe, image base 0x400000)
// System:    unknown
// Generated: 2026-07-23 from raw capture (scaffold; refine for important units)
// Exactness: Behavior-preserving rewrite of decompiler control flow. Not modernization.
// Bit-for-bit vs retail EXE: DEFERRED (loaded image may differ slightly).
// =============================================================================

// PURPOSE (auto): Scaffold unit for UI_f_frame_friends @ 0x008da870
// Stable ID: aa_008da870
// Embedded strings (evidence for future rename):
//   - "i_d_f_2d_wnd_frame_friends.xml"
//   - "i_d_f_2d_wnd_frame_ignore.xml"
//   - "i_d_f_2d_wnd_bg_friends.xml"
//   - "i_d_f_2d_wnd_bg_ignore.xml"
//   - "i_d_f_2d_wnd_title.xml"
//   - "i_d_f_2d_wnd_label_friends.xml"
// Readability: control flow preserved from Ghidra decompile; types tentative.

// READABILITY (auto CF):
//  - Body size: ~250 non-empty decompiler lines.
//  - Control keywords: if×22, return×1.
//  - Notable callees: FUN_0079c860×8, FUN_007b5dd0×7, FUN_0078b6e0×3, FUN_0078f890×2, FUN_00795f20×2, FUN_007fbe50×2, FUN_00792600, UI_f_frame_friends.
//  - Strings: "i_d_f_2d_wnd_frame_friends.xml"; "i_d_f_2d_wnd_frame_ignore.xml"; "i_d_f_2d_wnd_bg_friends.xml"; "i_d_f_2d_wnd_bg_ignore.xml".
//  - Return sites: 1.

/*
 * Behavioral notes:
 * Plate-driven rename evidence: "i_d_f_2d_wnd_frame_friends.xml"
 * Domain alias of FUN_008da870 (FUN_* retained)
 *
 * - Derived from Ghidra decompile; names prefer Ghidra symbols / plate comments.
 * - Remaining FUN_* / DAT_* identifiers are unresolved pending type recovery.
 * - Runtime / differential verification: OPEN unless matrix says otherwise.
 *
 * Readability pass:
 * - undefinedN widths preserved as fixed-width integers where decompiler width is known.
 * - Control flow and call order preserved from authoritative raw.
 */

void __fastcall UI_f_frame_friends(int *param_1)



{

  void *pvVar1;

  int iVar2;

  void *pvVar3;

  void *pvStack_c;

  uint8_t *puStack_8;

  uint32_t /* width from decompiler */ local_4;

  

  local_4 = 0xffffffff;

  puStack_8 = &LAB_009ba3d1;

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

  (**(code **)(*(int *)param_1[0x148] + 0x28))("i_d_f_2d_wnd_frame_friends.xml");

  pvVar1 = operator_new(0x488);

  pvStack_c = (void *)0x1;

  if (pvVar1 == (void *)0x0) {

    iVar2 = 0;

  }

  else {

    iVar2 = FUN_007b5dd0(pvVar1,0);

  }

  pvStack_c = (void *)0xffffffff;

  param_1[0x149] = iVar2;

  (**(code **)(*param_1 + 0xa8))(iVar2);

  (**(code **)(*(int *)param_1[0x149] + 0x28))("i_d_f_2d_wnd_frame_ignore.xml");

  pvVar1 = operator_new(0x488);

  if (pvVar1 == (void *)0x0) {

    iVar2 = 0;

  }

  else {

    iVar2 = FUN_007b5dd0(pvVar1,0);

  }

  param_1[0x146] = iVar2;

  (**(code **)(*param_1 + 0xa8))(iVar2);

  (**(code **)(*(int *)param_1[0x146] + 0x28))("i_d_f_2d_wnd_bg_friends.xml");

  pvVar1 = operator_new(0x488);

  if (pvVar1 == (void *)0x0) {

    iVar2 = 0;

  }

  else {

    iVar2 = FUN_007b5dd0(pvVar1,0);

  }

  param_1[0x147] = iVar2;

  (**(code **)(*param_1 + 0xa8))(iVar2);

  (**(code **)(*(int *)param_1[0x147] + 0x28))("i_d_f_2d_wnd_bg_ignore.xml");

  pvVar1 = operator_new(0x488);

  if (pvVar1 == (void *)0x0) {

    iVar2 = 0;

  }

  else {

    iVar2 = FUN_007b5dd0(pvVar1,0);

  }

  param_1[0x143] = iVar2;

  (**(code **)(*param_1 + 0xa8))(iVar2);

  (**(code **)(*(int *)param_1[0x143] + 0x28))("i_d_f_2d_wnd_title.xml");

  pvVar1 = operator_new(0x488);

  if (pvVar1 == (void *)0x0) {

    iVar2 = 0;

  }

  else {

    iVar2 = FUN_007b5dd0(pvVar1,0);

  }

  param_1[0x144] = iVar2;

  (**(code **)(*param_1 + 0xa8))(iVar2);

  (**(code **)(*(int *)param_1[0x144] + 0x28))("i_d_f_2d_wnd_label_friends.xml");

  pvVar1 = operator_new(0x488);

  if (pvVar1 == (void *)0x0) {

    iVar2 = 0;

  }

  else {

    iVar2 = FUN_007b5dd0(pvVar1,0);

  }

  param_1[0x145] = iVar2;

  (**(code **)(*param_1 + 0xa8))(iVar2);

  (**(code **)(*(int *)param_1[0x145] + 0x28))("i_d_f_2d_wnd_label_ignore.xml");

  pvVar1 = operator_new(0x4cc);

  iVar2 = 0;

  if (pvVar1 != (void *)0x0) {

    iVar2 = FUN_0079c860();

  }

  param_1[0x14a] = iVar2;

  (**(code **)(*param_1 + 0xa8))(iVar2);

  (**(code **)(*(int *)param_1[0x14a] + 0x28))("i_d_f_2d_btn_sort_friends_name.xml");

  (**(code **)(*(int *)param_1[0x14a] + 0x74))(0x9c41);

  pvVar1 = operator_new(0x4cc);

  iVar2 = 0;

  if (pvVar1 != (void *)0x0) {

    iVar2 = FUN_0079c860();

  }

  param_1[0x14b] = iVar2;

  (**(code **)(*param_1 + 0xa8))(iVar2);

  (**(code **)(*(int *)param_1[0x14b] + 0x28))("i_d_f_2d_btn_sort_friends_online.xml");

  (**(code **)(*(int *)param_1[0x14b] + 0x74))(0x9c42);

  pvVar1 = operator_new(0x4cc);

  iVar2 = 0;

  if (pvVar1 != (void *)0x0) {

    iVar2 = FUN_0079c860();

  }

  param_1[0x14c] = iVar2;

  (**(code **)(*param_1 + 0xa8))(iVar2);

  (**(code **)(*(int *)param_1[0x14c] + 0x28))("i_d_f_2d_btn_sort_ignore_name.xml");

  (**(code **)(*(int *)param_1[0x14c] + 0x74))(0x9c43);

  pvVar1 = operator_new(0x9a8);

  if (pvVar1 == (void *)0x0) {

    iVar2 = 0;

  }

  else {

    iVar2 = FUN_0078b6e0();

  }

  param_1[0x14d] = iVar2;

  (**(code **)(*param_1 + 0xa8))(iVar2);

  (**(code **)(*(int *)param_1[0x14d] + 0x28))("i_d_f_2d_lb_friends_name.xml");

  (**(code **)(*(int *)param_1[0x14d] + 0x474))(0x9c4d);

  (**(code **)(*(int *)param_1[0x14d] + 0x43c))();

  pvVar1 = operator_new(0x9a8);

  if (pvVar1 == (void *)0x0) {

    iVar2 = 0;

  }

  else {

    iVar2 = FUN_0078b6e0();

  }

  param_1[0x14e] = iVar2;

  (**(code **)(*param_1 + 0xa8))(iVar2);

  (**(code **)(*(int *)param_1[0x14e] + 0x28))("i_d_f_2d_lb_friends_online.xml");

  (**(code **)(*(int *)param_1[0x14e] + 0x474))(0x9c4d);

  (**(code **)(*(int *)param_1[0x14e] + 0x43c))();

  pvVar1 = operator_new(0x9a8);

  if (pvVar1 == (void *)0x0) {

    iVar2 = 0;

  }

  else {

    iVar2 = FUN_0078b6e0();

  }

  param_1[0x14f] = iVar2;

  (**(code **)(*param_1 + 0xa8))(iVar2);

  (**(code **)(*(int *)param_1[0x14f] + 0x28))("i_d_f_2d_lb_ignore_name.xml");

  (**(code **)(*(int *)param_1[0x14f] + 0x474))(0x9c4e);

  (**(code **)(*(int *)param_1[0x14f] + 0x43c))();

  pvVar1 = operator_new(0x954);

  if (pvVar1 == (void *)0x0) {

    iVar2 = 0;

  }

  else {

    iVar2 = FUN_0078f890();

  }

  param_1[0x150] = iVar2;

  (**(code **)(*param_1 + 0xa8))(iVar2);

  (**(code **)(*(int *)param_1[0x150] + 0x28))("i_d_f_2d_sb_friends.xml");

  (**(code **)(*(int *)param_1[0x150] + 0x43c))();

  (**(code **)(*(int *)param_1[0x150] + 0x74))(0x9c4b);

  pvVar1 = operator_new(0x954);

  if (pvVar1 == (void *)0x0) {

    iVar2 = 0;

  }

  else {

    iVar2 = FUN_0078f890();

  }

  param_1[0x151] = iVar2;

  (**(code **)(*param_1 + 0xa8))(iVar2);

  (**(code **)(*(int *)param_1[0x151] + 0x28))("i_d_f_2d_sb_ignore.xml");

  (**(code **)(*(int *)param_1[0x151] + 0x43c))();

  (**(code **)(*(int *)param_1[0x151] + 0x74))(0x9c4c);

  pvVar1 = operator_new(0x4a4);

  iVar2 = 0;

  if (pvVar1 != (void *)0x0) {

    iVar2 = FUN_00795f20();

  }

  param_1[0x152] = iVar2;

  (**(code **)(*param_1 + 0xa8))(iVar2);

  (**(code **)(*(int *)param_1[0x152] + 0x28))("i_d_f_2d_wnd_edit_friends.xml");

  (**(code **)(*(int *)param_1[0x152] + 0x74))(0x9c44);

  (**(code **)(*(int *)param_1[0x152] + 0x1d0))(0x10);

  *(uint8_t *)(param_1[0x152] + 0x48c) = 1;

  *(uint8_t *)(param_1[0x152] + 0x48d) = 1;

  pvVar1 = operator_new(0x4a4);

  iVar2 = 0;

  if (pvVar1 != (void *)0x0) {

    iVar2 = FUN_00795f20();

  }

  param_1[0x153] = iVar2;

  (**(code **)(*param_1 + 0xa8))(iVar2);

  (**(code **)(*(int *)param_1[0x153] + 0x28))("i_d_f_2d_wnd_edit_ignore.xml");

  (**(code **)(*(int *)param_1[0x153] + 0x74))(0x9c45);

  (**(code **)(*(int *)param_1[0x153] + 0x1d0))(0x10);

  *(uint8_t *)(param_1[0x153] + 0x48c) = 1;

  *(uint8_t *)(param_1[0x153] + 0x48d) = 1;

  pvVar1 = operator_new(0x4cc);

  iVar2 = 0;

  if (pvVar1 != (void *)0x0) {

    iVar2 = FUN_0079c860();

  }

  param_1[0x154] = iVar2;

  (**(code **)(*param_1 + 0xa8))(iVar2);

  (**(code **)(*(int *)param_1[0x154] + 0x28))("i_d_f_2d_btn_details_friends.xml");

  (**(code **)(*(int *)param_1[0x154] + 0x74))(0x9c46);

  pvVar1 = operator_new(0x4cc);

  iVar2 = 0;

  if (pvVar1 != (void *)0x0) {

    iVar2 = FUN_0079c860();

  }

  param_1[0x155] = iVar2;

  (**(code **)(*param_1 + 0xa8))(iVar2);

  (**(code **)(*(int *)param_1[0x155] + 0x28))("i_d_f_2d_btn_add_friends.xml");

  (**(code **)(*(int *)param_1[0x155] + 0x74))(0x9c47);

  pvVar1 = operator_new(0x4cc);

  iVar2 = 0;

  if (pvVar1 != (void *)0x0) {

    iVar2 = FUN_0079c860();

  }

  param_1[0x156] = iVar2;

  (**(code **)(*param_1 + 0xa8))(iVar2);

  (**(code **)(*(int *)param_1[0x156] + 0x28))("i_d_f_2d_btn_add_ignore.xml");

  (**(code **)(*(int *)param_1[0x156] + 0x74))(0x9c48);

  pvVar1 = operator_new(0x4cc);

  pvVar3 = (void *)0x0;

  if (pvVar1 != (void *)0x0) {

    pvVar3 = (void *)FUN_0079c860();

  }

  param_1[0x157] = (int)pvVar3;

  (**(code **)(*param_1 + 0xa8))();

  (**(code **)(*(int *)param_1[0x157] + 0x28))("i_d_f_2d_btn_remove_friends.xml");

  (**(code **)(*(int *)param_1[0x157] + 0x74))(0x9c49);

  pvVar1 = operator_new(0x4cc);

  iVar2 = 0;

  if (pvVar1 != (void *)0x0) {

    iVar2 = FUN_0079c860();

  }

  param_1[0x158] = iVar2;

  (**(code **)(*param_1 + 0xa8))(iVar2);

  (**(code **)(*(int *)param_1[0x158] + 0x28))("i_d_f_2d_btn_remove_ignore.xml");

  (**(code **)(*(int *)param_1[0x158] + 0x74))(0x9c4a);

  FUN_007fbe50();

  FUN_007fbe50();

  (**(code **)(*param_1 + 0x448))();

  (**(code **)(*param_1 + 0x34c))();

  ExceptionList = pvVar3;

  return;

}
