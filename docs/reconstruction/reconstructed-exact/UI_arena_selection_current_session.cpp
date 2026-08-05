// =============================================================================
// UI_arena_selection_current_session
// -----------------------------------------------------------------------------
// Stable ID: aa_0086f3b0
// Address:   0x0086f3b0  (autoassault.exe, image base 0x400000)
// System:    unknown
// Generated: 2026-07-23 from raw capture (scaffold; refine for important units)
// Exactness: Behavior-preserving rewrite of decompiler control flow. Not modernization.
// Bit-for-bit vs retail EXE: DEFERRED (loaded image may differ slightly).
// =============================================================================

// PURPOSE (auto): Scaffold unit for UI_arena_selection_current_session @ 0x0086f3b0
// Stable ID: aa_0086f3b0
// Embedded strings (evidence for future rename):
//   - "i_d_arena/i_d_arena_selection_wnd_bg_fill.xml"
//   - "i_d_arena/i_d_arena_selection_wnd_fx.xml"
//   - "i_d_arena/i_d_arena_selection_wnd_bg_texture.xml"
//   - "i_d_arena/i_d_arena_selection_wnd_current_session.xml"
//   - "i_d_arena/i_d_arena_selection_wnd_name_selected.xml"
//   - "i_d_arena/i_d_arena_selection_wnd_edit_password.xml"
// Readability: control flow preserved from Ghidra decompile; types tentative.

// READABILITY (auto CF):
//  - Body size: ~335 non-empty decompiler lines.
//  - Control keywords: if×28, return×1.
//  - Notable callees: FUN_0079c860×12, FUN_0078b6e0×8, FUN_007b5dd0×5, FUN_0078f890, FUN_00792600, FUN_00795f20, FUN_00864f20, FUN_0086e7e0.
//  - Strings: "i_d_arena/i_d_arena_selection_wnd_bg_fill.xml"; "i_d_arena/i_d_arena_selection_wnd_fx.xml"; "i_d_arena/i_d_arena_selection_wnd_bg_texture.xml"; "i_d_arena/i_d_arena_selection_wnd_current_session.xml".
//  - Return sites: 1.

/*
 * Behavioral notes:
 * Plate-driven rename evidence: "i_d_arena/i_d_arena_selection_wnd_current_session.xml"
 * Domain alias of FUN_0086f3b0 (FUN_* retained)
 *
 * - Derived from Ghidra decompile; names prefer Ghidra symbols / plate comments.
 * - Remaining FUN_* / DAT_* identifiers are unresolved pending type recovery.
 * - Runtime / differential verification: OPEN unless matrix says otherwise.
 *
 * Readability pass:
 * - undefinedN widths preserved as fixed-width integers where decompiler width is known.
 * - Control flow and call order preserved from authoritative raw.
 */

void __fastcall UI_arena_selection_current_session(int *param_1)



{

  void *pvVar1;

  int iVar2;

  void *pvStack_c;

  uint8_t *puStack_8;

  uint32_t /* width from decompiler */ local_4;

  

  local_4 = 0xffffffff;

  puStack_8 = &LAB_009b8c39;

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

  (**(code **)(*(int *)param_1[0x148] + 0x28))("i_d_arena/i_d_arena_selection_wnd_bg_fill.xml");

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

  (**(code **)(*(int *)param_1[0x149] + 0x28))("i_d_arena/i_d_arena_selection_wnd_fx.xml");

  pvVar1 = operator_new(0x488);

  if (pvVar1 == (void *)0x0) {

    iVar2 = 0;

  }

  else {

    iVar2 = FUN_007b5dd0(pvVar1,0);

  }

  param_1[0x14a] = iVar2;

  (**(code **)(*param_1 + 0xa8))(iVar2);

  (**(code **)(*(int *)param_1[0x14a] + 0x28))("i_d_arena/i_d_arena_selection_wnd_bg_texture.xml");

  pvVar1 = operator_new(0x488);

  if (pvVar1 == (void *)0x0) {

    iVar2 = 0;

  }

  else {

    iVar2 = FUN_007b5dd0(pvVar1,0);

  }

  param_1[0x14b] = iVar2;

  (**(code **)(*param_1 + 0xa8))(iVar2);

  (**(code **)(*(int *)param_1[0x14b] + 0x28))

            ("i_d_arena/i_d_arena_selection_wnd_current_session.xml");

  (**(code **)(*(int *)param_1[0x14b] + 0x1d8))(&DAT_00a1419b,1,1);

  pvVar1 = operator_new(0x488);

  if (pvVar1 == (void *)0x0) {

    iVar2 = 0;

  }

  else {

    iVar2 = FUN_007b5dd0(pvVar1,0);

  }

  param_1[0x14c] = iVar2;

  (**(code **)(*param_1 + 0xa8))(iVar2);

  (**(code **)(*(int *)param_1[0x14c] + 0x28))

            ("i_d_arena/i_d_arena_selection_wnd_name_selected.xml");

  pvVar1 = operator_new(0x4a4);

  iVar2 = 0;

  if (pvVar1 != (void *)0x0) {

    iVar2 = FUN_00795f20();

  }

  param_1[0x150] = iVar2;

  (**(code **)(*param_1 + 0xa8))(iVar2);

  (**(code **)(*(int *)param_1[0x150] + 0x28))

            ("i_d_arena/i_d_arena_selection_wnd_edit_password.xml");

  (**(code **)(*(int *)param_1[0x150] + 0x3ac))(&DAT_00a1419b);

  (**(code **)(*(int *)param_1[0x150] + 0x1d0))(8);

  (**(code **)(*(int *)param_1[0x150] + 0xcc))(0);

  pvVar1 = operator_new(0x488);

  if (pvVar1 == (void *)0x0) {

    iVar2 = 0;

  }

  else {

    iVar2 = FUN_007b5dd0(pvVar1,0);

  }

  param_1[0x151] = iVar2;

  (**(code **)(*param_1 + 0xa8))(iVar2);

  (**(code **)(*(int *)param_1[0x151] + 0x28))

            ("i_d_arena/i_d_arena_selection_wnd_label_password.xml");

  (**(code **)(*(int *)param_1[0x151] + 0xcc))(0);

  pvVar1 = operator_new(0x4cc);

  iVar2 = 0;

  if (pvVar1 != (void *)0x0) {

    iVar2 = FUN_0079c860();

  }

  param_1[0x14d] = iVar2;

  (**(code **)(*param_1 + 0xa8))(iVar2);

  (**(code **)(*(int *)param_1[0x14d] + 0x28))("i_d_arena/i_d_arena_selection_btn_console.xml");

  (**(code **)(*(int *)param_1[0x14d] + 0x74))(0x9c41);

  pvVar1 = operator_new(0x4cc);

  iVar2 = 0;

  if (pvVar1 != (void *)0x0) {

    iVar2 = FUN_0079c860();

  }

  param_1[0x14e] = iVar2;

  (**(code **)(*param_1 + 0xa8))(iVar2);

  (**(code **)(*(int *)param_1[0x14e] + 0x28))

            ("i_d_arena/i_d_arena_selection_btn_join_selected.xml");

  (**(code **)(*(int *)param_1[0x14e] + 0x74))(0x9c42);

  pvVar1 = operator_new(0x4cc);

  iVar2 = 0;

  if (pvVar1 != (void *)0x0) {

    iVar2 = FUN_0079c860();

  }

  param_1[0x14f] = iVar2;

  (**(code **)(*param_1 + 0xa8))(iVar2);

  (**(code **)(*(int *)param_1[0x14f] + 0x28))("i_d_arena/i_d_arena_selection_btn_refresh.xml");

  (**(code **)(*(int *)param_1[0x14f] + 0x74))(0x9c43);

  pvVar1 = operator_new(0x4cc);

  iVar2 = 0;

  if (pvVar1 != (void *)0x0) {

    iVar2 = FUN_0079c860();

  }

  param_1[0x152] = iVar2;

  (**(code **)(*param_1 + 0xa8))(iVar2);

  (**(code **)(*(int *)param_1[0x152] + 0x28))

            ("i_d_arena/i_d_arena_selection_btn_sort_max_rank.xml");

  (**(code **)(*(int *)param_1[0x152] + 0x74))(0x9c45);

  pvVar1 = operator_new(0x4cc);

  iVar2 = 0;

  if (pvVar1 != (void *)0x0) {

    iVar2 = FUN_0079c860();

  }

  param_1[0x153] = iVar2;

  (**(code **)(*param_1 + 0xa8))(iVar2);

  (**(code **)(*(int *)param_1[0x153] + 0x28))

            ("i_d_arena/i_d_arena_selection_btn_sort_event_title.xml");

  (**(code **)(*(int *)param_1[0x153] + 0x74))(0x9c46);

  pvVar1 = operator_new(0x4cc);

  iVar2 = 0;

  if (pvVar1 != (void *)0x0) {

    iVar2 = FUN_0079c860();

  }

  param_1[0x154] = iVar2;

  (**(code **)(*param_1 + 0xa8))(iVar2);

  (**(code **)(*(int *)param_1[0x154] + 0x28))

            ("i_d_arena/i_d_arena_selection_btn_sort_restrictions.xml");

  (**(code **)(*(int *)param_1[0x154] + 0x74))(0x9c47);

  pvVar1 = operator_new(0x4cc);

  iVar2 = 0;

  if (pvVar1 != (void *)0x0) {

    iVar2 = FUN_0079c860();

  }

  param_1[0x155] = iVar2;

  (**(code **)(*param_1 + 0xa8))(iVar2);

  (**(code **)(*(int *)param_1[0x155] + 0x28))

            ("i_d_arena/i_d_arena_selection_btn_sort_victory_conditions.xml");

  (**(code **)(*(int *)param_1[0x155] + 0x74))(0x9c48);

  pvVar1 = operator_new(0x4cc);

  iVar2 = 0;

  if (pvVar1 != (void *)0x0) {

    iVar2 = FUN_0079c860();

  }

  param_1[0x156] = iVar2;

  (**(code **)(*param_1 + 0xa8))(iVar2);

  (**(code **)(*(int *)param_1[0x156] + 0x28))

            ("i_d_arena/i_d_arena_selection_btn_sort_current_players.xml");

  (**(code **)(*(int *)param_1[0x156] + 0x74))(0x9c49);

  pvVar1 = operator_new(0x4cc);

  iVar2 = 0;

  if (pvVar1 != (void *)0x0) {

    iVar2 = FUN_0079c860();

  }

  param_1[0x157] = iVar2;

  (**(code **)(*param_1 + 0xa8))(iVar2);

  (**(code **)(*(int *)param_1[0x157] + 0x28))

            ("i_d_arena/i_d_arena_selection_btn_sort_spectators.xml");

  (**(code **)(*(int *)param_1[0x157] + 0x74))(0x9c4a);

  pvVar1 = operator_new(0x4cc);

  iVar2 = 0;

  if (pvVar1 != (void *)0x0) {

    iVar2 = FUN_0079c860();

  }

  param_1[0x158] = iVar2;

  (**(code **)(*param_1 + 0xa8))(iVar2);

  (**(code **)(*(int *)param_1[0x158] + 0x28))

            ("i_d_arena/i_d_arena_selection_btn_sort_arena_start.xml");

  (**(code **)(*(int *)param_1[0x158] + 0x74))(0x9c4b);

  pvVar1 = operator_new(0x4cc);

  iVar2 = 0;

  if (pvVar1 != (void *)0x0) {

    iVar2 = FUN_0079c860();

  }

  param_1[0x159] = iVar2;

  (**(code **)(*param_1 + 0xa8))(iVar2);

  (**(code **)(*(int *)param_1[0x159] + 0x28))

            ("i_d_arena/i_d_arena_selection_btn_sort_password.xml");

  (**(code **)(*(int *)param_1[0x159] + 0x74))(0x9c4c);

  pvVar1 = operator_new(0x9a8);

  if (pvVar1 == (void *)0x0) {

    iVar2 = 0;

  }

  else {

    iVar2 = FUN_0078b6e0();

  }

  param_1[0x15a] = iVar2;

  (**(code **)(*param_1 + 0xa8))(iVar2);

  (**(code **)(*(int *)param_1[0x15a] + 0x28))("i_d_arena/i_d_arena_selection_lb_max_rank.xml");

  (**(code **)(*(int *)param_1[0x15a] + 0x474))(0x9c4d);

  (**(code **)(*(int *)param_1[0x15a] + 0x43c))();

  (**(code **)(*(int *)param_1[0x15a] + 0xfc))(1,0x3f000000);

  pvVar1 = operator_new(0x9a8);

  if (pvVar1 == (void *)0x0) {

    iVar2 = 0;

  }

  else {

    iVar2 = FUN_0078b6e0();

  }

  param_1[0x15b] = iVar2;

  (**(code **)(*param_1 + 0xa8))(iVar2);

  (**(code **)(*(int *)param_1[0x15b] + 0x28))("i_d_arena/i_d_arena_selection_lb_event_title.xml");

  (**(code **)(*(int *)param_1[0x15b] + 0x474))(0x9c4d);

  (**(code **)(*(int *)param_1[0x15b] + 0x43c))();

  (**(code **)(*(int *)param_1[0x15b] + 0xfc))(1,0x3f000000);

  pvVar1 = operator_new(0x9a8);

  if (pvVar1 == (void *)0x0) {

    iVar2 = 0;

  }

  else {

    iVar2 = FUN_0078b6e0();

  }

  param_1[0x15c] = iVar2;

  (**(code **)(*param_1 + 0xa8))(iVar2);

  (**(code **)(*(int *)param_1[0x15c] + 0x28))("i_d_arena/i_d_arena_selection_lb_restrictions.xml");

  (**(code **)(*(int *)param_1[0x15c] + 0x474))(0x9c4d);

  (**(code **)(*(int *)param_1[0x15c] + 0x43c))();

  (**(code **)(*(int *)param_1[0x15c] + 0xfc))(1,0x3f000000);

  pvVar1 = operator_new(0x9a8);

  if (pvVar1 == (void *)0x0) {

    iVar2 = 0;

  }

  else {

    iVar2 = FUN_0078b6e0();

  }

  param_1[0x15d] = iVar2;

  (**(code **)(*param_1 + 0xa8))(iVar2);

  (**(code **)(*(int *)param_1[0x15d] + 0x28))

            ("i_d_arena/i_d_arena_selection_lb_victory_conditions.xml");

  (**(code **)(*(int *)param_1[0x15d] + 0x474))(0x9c4d);

  (**(code **)(*(int *)param_1[0x15d] + 0x43c))();

  (**(code **)(*(int *)param_1[0x15d] + 0xfc))(1,0x3f000000);

  pvVar1 = operator_new(0x9a8);

  if (pvVar1 == (void *)0x0) {

    iVar2 = 0;

  }

  else {

    iVar2 = FUN_0078b6e0();

  }

  param_1[0x15e] = iVar2;

  (**(code **)(*param_1 + 0xa8))(iVar2);

  (**(code **)(*(int *)param_1[0x15e] + 0x28))

            ("i_d_arena/i_d_arena_selection_lb_current_players.xml");

  (**(code **)(*(int *)param_1[0x15e] + 0x474))(0x9c4d);

  (**(code **)(*(int *)param_1[0x15e] + 0x43c))();

  (**(code **)(*(int *)param_1[0x15e] + 0xfc))(1,0x3f000000);

  pvVar1 = operator_new(0x9a8);

  if (pvVar1 == (void *)0x0) {

    iVar2 = 0;

  }

  else {

    iVar2 = FUN_0078b6e0();

  }

  param_1[0x15f] = iVar2;

  (**(code **)(*param_1 + 0xa8))(iVar2);

  (**(code **)(*(int *)param_1[0x15f] + 0x28))("i_d_arena/i_d_arena_selection_lb_spectators.xml");

  (**(code **)(*(int *)param_1[0x15f] + 0x474))(0x9c4d);

  (**(code **)(*(int *)param_1[0x15f] + 0x43c))();

  (**(code **)(*(int *)param_1[0x15f] + 0xfc))(1,0x3f000000);

  pvVar1 = operator_new(0x9a8);

  if (pvVar1 == (void *)0x0) {

    iVar2 = 0;

  }

  else {

    iVar2 = FUN_0078b6e0();

  }

  param_1[0x160] = iVar2;

  (**(code **)(*param_1 + 0xa8))(iVar2);

  (**(code **)(*(int *)param_1[0x160] + 0x28))("i_d_arena/i_d_arena_selection_lb_arena_start.xml");

  (**(code **)(*(int *)param_1[0x160] + 0x474))(0x9c4d);

  (**(code **)(*(int *)param_1[0x160] + 0x43c))();

  (**(code **)(*(int *)param_1[0x160] + 0xfc))(1,0x3f000000);

  pvVar1 = operator_new(0x9a8);

  if (pvVar1 == (void *)0x0) {

    iVar2 = 0;

  }

  else {

    iVar2 = FUN_0078b6e0();

  }

  param_1[0x161] = iVar2;

  (**(code **)(*param_1 + 0xa8))(iVar2);

  (**(code **)(*(int *)param_1[0x161] + 0x28))("i_d_arena/i_d_arena_selection_lb_password.xml");

  (**(code **)(*(int *)param_1[0x161] + 0x474))(0x9c4d);

  (**(code **)(*(int *)param_1[0x161] + 0x43c))();

  (**(code **)(*(int *)param_1[0x161] + 0xfc))(1,0x3f000000);

  pvVar1 = operator_new(0x954);

  if (pvVar1 == (void *)0x0) {

    iVar2 = 0;

  }

  else {

    iVar2 = FUN_0078f890();

  }

  param_1[0x162] = iVar2;

  (**(code **)(*param_1 + 0xa8))(iVar2);

  (**(code **)(*(int *)param_1[0x162] + 0x28))();

  (**(code **)(*(int *)param_1[0x162] + 0x74))(0x9c44);

  (**(code **)(*(int *)param_1[0x162] + 0x43c))();

  pvVar1 = operator_new(0x4cc);

  iVar2 = 0;

  if (pvVar1 != (void *)0x0) {

    iVar2 = FUN_0079c860();

  }

  param_1[0x141] = iVar2;

  (**(code **)(*param_1 + 0xa8))(iVar2);

  (**(code **)(*(int *)param_1[0x141] + 0x28))("i_d_arena/i_d_arena_selection_btn_close.xml");

  (**(code **)(*(int *)param_1[0x141] + 0x74))(40000);

  FUN_0086e7e0();

  (**(code **)(*param_1 + 0x448))();

  (**(code **)(*param_1 + 0x34c))();

  FUN_0086efc0();

  ExceptionList = s_i_d_arena_i_d_arena_selection_sb_00a5d8b0;

  return;

}
