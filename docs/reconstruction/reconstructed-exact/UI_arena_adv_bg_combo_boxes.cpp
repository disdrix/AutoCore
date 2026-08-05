// =============================================================================
// UI_arena_adv_bg_combo_boxes
// -----------------------------------------------------------------------------
// Stable ID: aa_00879ea0
// Address:   0x00879ea0  (autoassault.exe, image base 0x400000)
// System:    unknown
// Generated: 2026-07-23 from raw capture (scaffold; refine for important units)
// Exactness: Behavior-preserving rewrite of decompiler control flow. Not modernization.
// Bit-for-bit vs retail EXE: DEFERRED (loaded image may differ slightly).
// =============================================================================

// PURPOSE (auto): Scaffold unit for UI_arena_adv_bg_combo_boxes @ 0x00879ea0
// Stable ID: aa_00879ea0
// Embedded strings (evidence for future rename):
//   - "i_d_arena/i_d_arena_adv_wnd_bg_fill.xml"
//   - "i_d_arena/i_d_arena_adv_wnd_fx.xml"
//   - "i_d_arena/i_d_arena_adv_wnd_bg_texture.xml"
//   - "i_d_arena/i_d_arena_adv_wnd_logo.xml"
//   - "i_d_arena/i_d_arena_adv_wnd_bg_ladder.xml"
//   - "i_d_arena/i_d_arena_adv_wnd_bg_combo_boxes.xml"
// Readability: control flow preserved from Ghidra decompile; types tentative.

// READABILITY (auto CF):
//  - Body size: ~626 non-empty decompiler lines.
//  - Control keywords: if×56, return×1.
//  - Notable callees: FUN_007b5dd0×33, FUN_00795f20×11, FUN_0079c860×6, FUN_00822cb0×3, FUN_008230b0×3, FUN_00756c90×2, FUN_0078e2f0×2, FUN_00792600.
//  - Strings: "i_d_arena/i_d_arena_adv_wnd_bg_fill.xml"; "i_d_arena/i_d_arena_adv_wnd_fx.xml"; "i_d_arena/i_d_arena_adv_wnd_bg_texture.xml"; "i_d_arena/i_d_arena_adv_wnd_logo.xml".
//  - Return sites: 1.

/*
 * Behavioral notes:
 * Plate-driven rename evidence: "i_d_arena/i_d_arena_adv_wnd_bg_combo_boxes.xml"
 * Domain alias of FUN_00879ea0 (FUN_* retained)
 *
 * - Derived from Ghidra decompile; names prefer Ghidra symbols / plate comments.
 * - Remaining FUN_* / DAT_* identifiers are unresolved pending type recovery.
 * - Runtime / differential verification: OPEN unless matrix says otherwise.
 *
 * Readability pass:
 * - undefinedN widths preserved as fixed-width integers where decompiler width is known.
 * - Control flow and call order preserved from authoritative raw.
 */

void __fastcall UI_arena_adv_bg_combo_boxes(int *param_1)



{

  void *pvVar1;

  int iVar2;

  void *pvVar3;

  void *pvStack_c;

  uint8_t *puStack_8;

  uint32_t /* width from decompiler */ local_4;

  

  local_4 = 0xffffffff;

  puStack_8 = &LAB_009b92cd;

  pvStack_c = ExceptionList;

  ExceptionList = &pvStack_c;

  *(uint8_t *)(param_1 + 0x149) = 0;

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

  param_1[0x158] = iVar2;

  (**(code **)(*param_1 + 0xa8))(iVar2);

  (**(code **)(*(int *)param_1[0x158] + 0x28))("i_d_arena/i_d_arena_adv_wnd_bg_fill.xml");

  pvVar1 = operator_new(0x4bc);

  pvStack_c = (void *)0x1;

  if (pvVar1 == (void *)0x0) {

    iVar2 = 0;

  }

  else {

    iVar2 = FUN_00864f20(pvVar1);

  }

  pvStack_c = (void *)0xffffffff;

  param_1[0x159] = iVar2;

  (**(code **)(*param_1 + 0xa8))(iVar2);

  (**(code **)(*(int *)param_1[0x159] + 0x28))("i_d_arena/i_d_arena_adv_wnd_fx.xml");

  pvVar1 = operator_new(0x488);

  if (pvVar1 == (void *)0x0) {

    iVar2 = 0;

  }

  else {

    iVar2 = FUN_007b5dd0(pvVar1,0);

  }

  param_1[0x15a] = iVar2;

  (**(code **)(*param_1 + 0xa8))(iVar2);

  (**(code **)(*(int *)param_1[0x15a] + 0x28))("i_d_arena/i_d_arena_adv_wnd_bg_texture.xml");

  pvVar1 = operator_new(0x488);

  if (pvVar1 == (void *)0x0) {

    iVar2 = 0;

  }

  else {

    iVar2 = FUN_007b5dd0(pvVar1,0);

  }

  param_1[0x15b] = iVar2;

  (**(code **)(*param_1 + 0xa8))(iVar2);

  (**(code **)(*(int *)param_1[0x15b] + 0x28))("i_d_arena/i_d_arena_adv_wnd_logo.xml");

  pvVar1 = operator_new(0x488);

  if (pvVar1 == (void *)0x0) {

    iVar2 = 0;

  }

  else {

    iVar2 = FUN_007b5dd0(pvVar1,0);

  }

  param_1[0x15c] = iVar2;

  (**(code **)(*param_1 + 0xa8))(iVar2);

  (**(code **)(*(int *)param_1[0x15c] + 0x28))("i_d_arena/i_d_arena_adv_wnd_bg_ladder.xml");

  pvVar1 = operator_new(0x488);

  if (pvVar1 == (void *)0x0) {

    iVar2 = 0;

  }

  else {

    iVar2 = FUN_007b5dd0(pvVar1,0);

  }

  param_1[0x15d] = iVar2;

  (**(code **)(*param_1 + 0xa8))(iVar2);

  (**(code **)(*(int *)param_1[0x15d] + 0x28))("i_d_arena/i_d_arena_adv_wnd_bg_combo_boxes.xml");

  pvVar1 = operator_new(0x488);

  if (pvVar1 == (void *)0x0) {

    iVar2 = 0;

  }

  else {

    iVar2 = FUN_007b5dd0(pvVar1,0);

  }

  param_1[0x15e] = iVar2;

  (**(code **)(*param_1 + 0xa8))(iVar2);

  (**(code **)(*(int *)param_1[0x15e] + 0x28))("i_d_arena/i_d_arena_adv_wnd_bg_values.xml");

  pvVar1 = operator_new(0x488);

  if (pvVar1 == (void *)0x0) {

    iVar2 = 0;

  }

  else {

    iVar2 = FUN_007b5dd0(pvVar1,0);

  }

  param_1[0x15f] = iVar2;

  (**(code **)(*param_1 + 0xa8))(iVar2);

  (**(code **)(*(int *)param_1[0x15f] + 0x28))("i_d_arena/i_d_arena_adv_wnd_bg_name.xml");

  pvVar1 = operator_new(0x4cc);

  iVar2 = 0;

  if (pvVar1 != (void *)0x0) {

    iVar2 = FUN_0079c860();

  }

  param_1[0x160] = iVar2;

  (**(code **)(*param_1 + 0xa8))(iVar2);

  (**(code **)(*(int *)param_1[0x160] + 0x28))("i_d_arena/i_d_arena_adv_btn_join_now.xml");

  (**(code **)(*(int *)param_1[0x160] + 0x74))(0x9c41);

  pvVar1 = operator_new(0x4cc);

  iVar2 = 0;

  if (pvVar1 != (void *)0x0) {

    iVar2 = FUN_0079c860();

  }

  param_1[0x161] = iVar2;

  (**(code **)(*param_1 + 0xa8))(iVar2);

  (**(code **)(*(int *)param_1[0x161] + 0x28))("i_d_arena/i_d_arena_adv_btn_spectate_now.xml");

  (**(code **)(*(int *)param_1[0x161] + 0x74))(0x9c42);

  pvVar1 = operator_new(0x4cc);

  iVar2 = 0;

  if (pvVar1 != (void *)0x0) {

    iVar2 = FUN_0079c860();

  }

  param_1[0x162] = iVar2;

  (**(code **)(*param_1 + 0xa8))(iVar2);

  (**(code **)(*(int *)param_1[0x162] + 0x28))("i_d_arena/i_d_arena_adv_btn_host_now.xml");

  (**(code **)(*(int *)param_1[0x162] + 0x74))(0x9c43);

  pvVar1 = operator_new(0x4a4);

  iVar2 = 0;

  if (pvVar1 != (void *)0x0) {

    iVar2 = FUN_00795f20();

  }

  param_1[0x167] = iVar2;

  (**(code **)(*param_1 + 0xa8))(iVar2);

  (**(code **)(*(int *)param_1[0x167] + 0x28))("i_d_arena/i_d_arena_adv_wnd_edit_level_maximum.xml")

  ;

  *(uint8_t *)(param_1[0x167] + 0x48b) = 1;

  (**(code **)(*(int *)param_1[0x167] + 0x1d0))(3);

  (**(code **)(*(int *)param_1[0x167] + 0x3ac))(&DAT_00a59fd0);

  pvVar1 = operator_new(0x488);

  if (pvVar1 == (void *)0x0) {

    iVar2 = 0;

  }

  else {

    iVar2 = FUN_007b5dd0(pvVar1,0);

  }

  param_1[0x168] = iVar2;

  (**(code **)(*param_1 + 0xa8))(iVar2);

  (**(code **)(*(int *)param_1[0x168] + 0x28))

            ("i_d_arena/i_d_arena_adv_wnd_label_level_maximum.xml");

  pvVar1 = operator_new(0x4a4);

  iVar2 = 0;

  if (pvVar1 != (void *)0x0) {

    iVar2 = FUN_00795f20();

  }

  param_1[0x169] = iVar2;

  (**(code **)(*param_1 + 0xa8))(iVar2);

  (**(code **)(*(int *)param_1[0x169] + 0x28))("i_d_arena/i_d_arena_adv_wnd_edit_match_name.xml");

  pvVar1 = operator_new(0x4a4);

  iVar2 = 0;

  if (pvVar1 != (void *)0x0) {

    iVar2 = FUN_00795f20();

  }

  param_1[0x16a] = iVar2;

  (**(code **)(*param_1 + 0xa8))(iVar2);

  (**(code **)(*(int *)param_1[0x16a] + 0x28))

            ("i_d_arena/i_d_arena_adv_wnd_edit_match_password.xml");

  (**(code **)(*(int *)param_1[0x16a] + 0x3ac))(&DAT_00a1419b);

  (**(code **)(*(int *)param_1[0x16a] + 0x1d0))(8);

  *(uint8_t *)(param_1[0x16a] + 0x48c) = 1;

  pvVar1 = operator_new(0x488);

  if (pvVar1 == (void *)0x0) {

    iVar2 = 0;

  }

  else {

    iVar2 = FUN_007b5dd0(pvVar1,0);

  }

  param_1[0x16b] = iVar2;

  (**(code **)(*param_1 + 0xa8))(iVar2);

  (**(code **)(*(int *)param_1[0x16b] + 0x28))("i_d_arena/i_d_arena_adv_wnd_label_match_name.xml");

  pvVar1 = operator_new(0x488);

  if (pvVar1 == (void *)0x0) {

    iVar2 = 0;

  }

  else {

    iVar2 = FUN_007b5dd0(pvVar1,0);

  }

  param_1[0x16c] = iVar2;

  (**(code **)(*param_1 + 0xa8))(iVar2);

  (**(code **)(*(int *)param_1[0x16c] + 0x28))

            ("i_d_arena/i_d_arena_adv_wnd_label_match_password.xml");

  pvVar1 = operator_new(0x488);

  if (pvVar1 == (void *)0x0) {

    iVar2 = 0;

  }

  else {

    iVar2 = FUN_007b5dd0(pvVar1,0);

  }

  param_1[0x16d] = iVar2;

  (**(code **)(*param_1 + 0xa8))(iVar2);

  (**(code **)(*(int *)param_1[0x16d] + 0x28))

            ("i_d_arena/i_d_arena_adv_wnd_label_match_password_size.xml");

  pvVar1 = operator_new(0x4cc);

  iVar2 = 0;

  if (pvVar1 != (void *)0x0) {

    iVar2 = FUN_0079c860();

  }

  param_1[0x16e] = iVar2;

  (**(code **)(*param_1 + 0xa8))(iVar2);

  (**(code **)(*(int *)param_1[0x16e] + 0x28))("i_d_arena/i_d_arena_adv_btn_radio_ladder.xml");

  (**(code **)(*(int *)param_1[0x16e] + 0x74))(0x9c44);

  (**(code **)(*(int *)param_1[0x16e] + 0x3b4))(1);

  *(uint32_t /* width from decompiler */ *)(param_1[0x16e] + 0x498) = 0;

  pvVar1 = operator_new(0x488);

  if (pvVar1 == (void *)0x0) {

    iVar2 = 0;

  }

  else {

    iVar2 = FUN_007b5dd0(pvVar1,0);

  }

  param_1[0x170] = iVar2;

  (**(code **)(*param_1 + 0xa8))(iVar2);

  (**(code **)(*(int *)param_1[0x170] + 0x28))("i_d_arena/i_d_arena_adv_wnd_label_radio_ladder.xml")

  ;

  pvVar1 = operator_new(0x4cc);

  iVar2 = 0;

  if (pvVar1 != (void *)0x0) {

    iVar2 = FUN_0079c860();

  }

  param_1[0x16f] = iVar2;

  (**(code **)(*param_1 + 0xa8))(iVar2);

  (**(code **)(*(int *)param_1[0x16f] + 0x28))("i_d_arena/i_d_arena_adv_btn_radio_practice.xml");

  (**(code **)(*(int *)param_1[0x16f] + 0x74))(0x9c45);

  (**(code **)(*(int *)param_1[0x16f] + 0x3b4))(1);

  *(uint32_t /* width from decompiler */ *)(param_1[0x16f] + 0x498) = 0;

  pvVar1 = operator_new(0x488);

  if (pvVar1 == (void *)0x0) {

    iVar2 = 0;

  }

  else {

    iVar2 = FUN_007b5dd0(pvVar1,0);

  }

  param_1[0x171] = iVar2;

  (**(code **)(*param_1 + 0xa8))(iVar2);

  (**(code **)(*(int *)param_1[0x171] + 0x28))

            ("i_d_arena/i_d_arena_adv_wnd_label_radio_practice.xml");

  (**(code **)(*(int *)param_1[0x16f] + 0xd4))(0);

  (**(code **)(*(int *)param_1[0x16e] + 0x3c8))(1,1);

  pvVar1 = operator_new(0x488);

  if (pvVar1 == (void *)0x0) {

    iVar2 = 0;

  }

  else {

    iVar2 = FUN_007b5dd0(pvVar1,0);

  }

  param_1[0x172] = iVar2;

  (**(code **)(*param_1 + 0xa8))(iVar2);

  (**(code **)(*(int *)param_1[0x172] + 0x28))("i_d_arena/i_d_arena_adv_wnd_label_entry_fee.xml");

  pvVar1 = operator_new(0x488);

  if (pvVar1 == (void *)0x0) {

    iVar2 = 0;

  }

  else {

    iVar2 = FUN_007b5dd0(pvVar1,0);

  }

  param_1[0x173] = iVar2;

  (**(code **)(*param_1 + 0xa8))(iVar2);

  (**(code **)(*(int *)param_1[0x173] + 0x28))("i_d_arena/i_d_arena_adv_wnd_label_entry_fee_b.xml");

  pvVar1 = operator_new(0x488);

  if (pvVar1 == (void *)0x0) {

    iVar2 = 0;

  }

  else {

    iVar2 = FUN_007b5dd0(pvVar1,0);

  }

  param_1[0x174] = iVar2;

  (**(code **)(*param_1 + 0xa8))(iVar2);

  (**(code **)(*(int *)param_1[0x174] + 0x28))("i_d_arena/i_d_arena_adv_wnd_label_entry_fee_m.xml");

  pvVar1 = operator_new(0x488);

  if (pvVar1 == (void *)0x0) {

    iVar2 = 0;

  }

  else {

    iVar2 = FUN_007b5dd0(pvVar1,0);

  }

  param_1[0x175] = iVar2;

  (**(code **)(*param_1 + 0xa8))(iVar2);

  (**(code **)(*(int *)param_1[0x175] + 0x28))("i_d_arena/i_d_arena_adv_wnd_label_entry_fee_k.xml");

  pvVar1 = operator_new(0x488);

  if (pvVar1 == (void *)0x0) {

    iVar2 = 0;

  }

  else {

    iVar2 = FUN_007b5dd0(pvVar1,0);

  }

  param_1[0x176] = iVar2;

  (**(code **)(*param_1 + 0xa8))(iVar2);

  (**(code **)(*(int *)param_1[0x176] + 0x28))("i_d_arena/i_d_arena_adv_wnd_label_entry_fee_c.xml");

  pvVar1 = operator_new(0x4a4);

  iVar2 = 0;

  if (pvVar1 != (void *)0x0) {

    iVar2 = FUN_00795f20();

  }

  param_1[0x177] = iVar2;

  (**(code **)(*param_1 + 0xa8))(iVar2);

  (**(code **)(*(int *)param_1[0x177] + 0x28))("i_d_arena/i_d_arena_adv_wnd_edit_entry_fee_b.xml");

  *(uint8_t *)(param_1[0x177] + 0x48b) = 1;

  (**(code **)(*(int *)param_1[0x177] + 0x1d0))(3);

  (**(code **)(*(int *)param_1[0x177] + 0x3ac))(&DAT_00a32460);

  pvVar1 = operator_new(0x4a4);

  iVar2 = 0;

  if (pvVar1 != (void *)0x0) {

    iVar2 = FUN_00795f20();

  }

  param_1[0x178] = iVar2;

  (**(code **)(*param_1 + 0xa8))(iVar2);

  (**(code **)(*(int *)param_1[0x178] + 0x28))("i_d_arena/i_d_arena_adv_wnd_edit_entry_fee_m.xml");

  *(uint8_t *)(param_1[0x178] + 0x48b) = 1;

  (**(code **)(*(int *)param_1[0x178] + 0x1d0))(3);

  (**(code **)(*(int *)param_1[0x178] + 0x3ac))(&DAT_00a32460);

  pvVar1 = operator_new(0x4a4);

  iVar2 = 0;

  if (pvVar1 != (void *)0x0) {

    iVar2 = FUN_00795f20();

  }

  param_1[0x179] = iVar2;

  (**(code **)(*param_1 + 0xa8))(iVar2);

  (**(code **)(*(int *)param_1[0x179] + 0x28))("i_d_arena/i_d_arena_adv_wnd_edit_entry_fee_k.xml");

  *(uint8_t *)(param_1[0x179] + 0x48b) = 1;

  (**(code **)(*(int *)param_1[0x179] + 0x1d0))(3);

  (**(code **)(*(int *)param_1[0x179] + 0x3ac))(&DAT_00a32460);

  pvVar1 = operator_new(0x4a4);

  iVar2 = 0;

  if (pvVar1 != (void *)0x0) {

    iVar2 = FUN_00795f20();

  }

  param_1[0x17a] = iVar2;

  (**(code **)(*param_1 + 0xa8))(iVar2);

  (**(code **)(*(int *)param_1[0x17a] + 0x28))("i_d_arena/i_d_arena_adv_wnd_edit_entry_fee_c.xml");

  *(uint8_t *)(param_1[0x17a] + 0x48b) = 1;

  (**(code **)(*(int *)param_1[0x17a] + 0x1d0))(3);

  (**(code **)(*(int *)param_1[0x17a] + 0x3ac))(&DAT_00a32460);

  pvVar1 = operator_new(0x488);

  if (pvVar1 == (void *)0x0) {

    iVar2 = 0;

  }

  else {

    iVar2 = FUN_007b5dd0(pvVar1,0);

  }

  param_1[0x17b] = iVar2;

  (**(code **)(*param_1 + 0xa8))(iVar2);

  (**(code **)(*(int *)param_1[0x17b] + 0x28))

            ("i_d_arena/i_d_arena_adv_wnd_label_value_maximum.xml");

  pvVar1 = operator_new(0x488);

  if (pvVar1 == (void *)0x0) {

    iVar2 = 0;

  }

  else {

    iVar2 = FUN_007b5dd0(pvVar1,0);

  }

  param_1[0x17c] = iVar2;

  (**(code **)(*param_1 + 0xa8))(iVar2);

  (**(code **)(*(int *)param_1[0x17c] + 0x28))

            ("i_d_arena/i_d_arena_adv_wnd_label_value_maximum_b.xml");

  pvVar1 = operator_new(0x488);

  if (pvVar1 == (void *)0x0) {

    iVar2 = 0;

  }

  else {

    iVar2 = FUN_007b5dd0(pvVar1,0);

  }

  param_1[0x17d] = iVar2;

  (**(code **)(*param_1 + 0xa8))(iVar2);

  (**(code **)(*(int *)param_1[0x17d] + 0x28))

            ("i_d_arena/i_d_arena_adv_wnd_label_value_maximum_m.xml");

  pvVar1 = operator_new(0x488);

  if (pvVar1 == (void *)0x0) {

    iVar2 = 0;

  }

  else {

    iVar2 = FUN_007b5dd0(pvVar1,0);

  }

  param_1[0x17e] = iVar2;

  (**(code **)(*param_1 + 0xa8))(iVar2);

  (**(code **)(*(int *)param_1[0x17e] + 0x28))

            ("i_d_arena/i_d_arena_adv_wnd_label_value_maximum_k.xml");

  pvVar1 = operator_new(0x488);

  if (pvVar1 == (void *)0x0) {

    iVar2 = 0;

  }

  else {

    iVar2 = FUN_007b5dd0(pvVar1,0);

  }

  param_1[0x17f] = iVar2;

  (**(code **)(*param_1 + 0xa8))(iVar2);

  (**(code **)(*(int *)param_1[0x17f] + 0x28))

            ("i_d_arena/i_d_arena_adv_wnd_label_value_maximum_c.xml");

  pvVar1 = operator_new(0x4a4);

  iVar2 = 0;

  if (pvVar1 != (void *)0x0) {

    iVar2 = FUN_00795f20();

  }

  param_1[0x180] = iVar2;

  (**(code **)(*param_1 + 0xa8))(iVar2);

  (**(code **)(*(int *)param_1[0x180] + 0x28))

            ("i_d_arena/i_d_arena_adv_wnd_edit_value_maximum_b.xml");

  *(uint8_t *)(param_1[0x180] + 0x48b) = 1;

  (**(code **)(*(int *)param_1[0x180] + 0x1d0))(3);

  (**(code **)(*(int *)param_1[0x180] + 0x3ac))(&DAT_00a59fd0);

  pvVar1 = operator_new(0x4a4);

  iVar2 = 0;

  if (pvVar1 != (void *)0x0) {

    iVar2 = FUN_00795f20();

  }

  param_1[0x181] = iVar2;

  (**(code **)(*param_1 + 0xa8))(iVar2);

  (**(code **)(*(int *)param_1[0x181] + 0x28))

            ("i_d_arena/i_d_arena_adv_wnd_edit_value_maximum_m.xml");

  *(uint8_t *)(param_1[0x181] + 0x48b) = 1;

  (**(code **)(*(int *)param_1[0x181] + 0x1d0))(3);

  (**(code **)(*(int *)param_1[0x181] + 0x3ac))(&DAT_00a59fd0);

  pvVar1 = operator_new(0x4a4);

  iVar2 = 0;

  if (pvVar1 != (void *)0x0) {

    iVar2 = FUN_00795f20();

  }

  param_1[0x182] = iVar2;

  (**(code **)(*param_1 + 0xa8))(iVar2);

  (**(code **)(*(int *)param_1[0x182] + 0x28))

            ("i_d_arena/i_d_arena_adv_wnd_edit_value_maximum_k.xml");

  *(uint8_t *)(param_1[0x182] + 0x48b) = 1;

  (**(code **)(*(int *)param_1[0x182] + 0x1d0))(3);

  (**(code **)(*(int *)param_1[0x182] + 0x3ac))(&DAT_00a59fd0);

  pvVar1 = operator_new(0x4a4);

  iVar2 = 0;

  if (pvVar1 != (void *)0x0) {

    iVar2 = FUN_00795f20();

  }

  param_1[0x183] = iVar2;

  (**(code **)(*param_1 + 0xa8))(iVar2);

  (**(code **)(*(int *)param_1[0x183] + 0x28))

            ("i_d_arena/i_d_arena_adv_wnd_edit_value_maximum_c.xml");

  *(uint8_t *)(param_1[0x183] + 0x48b) = 1;

  (**(code **)(*(int *)param_1[0x183] + 0x1d0))(3);

  (**(code **)(*(int *)param_1[0x183] + 0x3ac))(&DAT_00a59fd0);

  pvVar1 = operator_new(0x4cc);

  iVar2 = 0;

  if (pvVar1 != (void *)0x0) {

    iVar2 = FUN_0079c860();

  }

  param_1[0x141] = iVar2;

  (**(code **)(*param_1 + 0xa8))(iVar2);

  (**(code **)(*(int *)param_1[0x141] + 0x28))("i_d_arena/i_d_arena_adv_btn_close.xml");

  (**(code **)(*(int *)param_1[0x141] + 0x74))(40000);

  pvVar1 = operator_new(0x488);

  if (pvVar1 == (void *)0x0) {

    iVar2 = 0;

  }

  else {

    iVar2 = FUN_007b5dd0(pvVar1,0);

  }

  param_1[0x184] = iVar2;

  (**(code **)(*param_1 + 0xa8))(iVar2);

  (**(code **)(*(int *)param_1[0x184] + 0x28))("i_d_arena/i_d_arena_adv_wnd_label_inst_1.xml");

  pvVar1 = operator_new(0x488);

  if (pvVar1 == (void *)0x0) {

    iVar2 = 0;

  }

  else {

    iVar2 = FUN_007b5dd0(pvVar1,0);

  }

  param_1[0x185] = iVar2;

  (**(code **)(*param_1 + 0xa8))(iVar2);

  (**(code **)(*(int *)param_1[0x185] + 0x28))("i_d_arena/i_d_arena_adv_wnd_label_inst_2.xml");

  pvVar1 = operator_new(0x488);

  if (pvVar1 == (void *)0x0) {

    iVar2 = 0;

  }

  else {

    iVar2 = FUN_007b5dd0(pvVar1,0);

  }

  param_1[0x186] = iVar2;

  (**(code **)(*param_1 + 0xa8))(iVar2);

  (**(code **)(*(int *)param_1[0x186] + 0x28))("i_d_arena/i_d_arena_adv_wnd_label_inst_3.xml");

  pvVar1 = operator_new(0x488);

  if (pvVar1 == (void *)0x0) {

    iVar2 = 0;

  }

  else {

    iVar2 = FUN_007b5dd0(pvVar1,0);

  }

  param_1[0x187] = iVar2;

  (**(code **)(*param_1 + 0xa8))(iVar2);

  (**(code **)(*(int *)param_1[0x187] + 0x28))("i_d_arena/i_d_arena_adv_wnd_label_inst_4.xml");

  pvVar1 = operator_new(0x488);

  if (pvVar1 == (void *)0x0) {

    iVar2 = 0;

  }

  else {

    iVar2 = FUN_007b5dd0(pvVar1,0);

  }

  param_1[0x188] = iVar2;

  (**(code **)(*param_1 + 0xa8))(iVar2);

  (**(code **)(*(int *)param_1[0x188] + 0x28))("i_d_arena/i_d_arena_adv_wnd_divider_1.xml");

  pvVar1 = operator_new(0x488);

  if (pvVar1 == (void *)0x0) {

    iVar2 = 0;

  }

  else {

    iVar2 = FUN_007b5dd0(pvVar1,0);

  }

  param_1[0x189] = iVar2;

  (**(code **)(*param_1 + 0xa8))(iVar2);

  (**(code **)(*(int *)param_1[0x189] + 0x28))("i_d_arena/i_d_arena_adv_wnd_divider_2.xml");

  pvVar1 = operator_new(0x488);

  if (pvVar1 == (void *)0x0) {

    iVar2 = 0;

  }

  else {

    iVar2 = FUN_007b5dd0(pvVar1,0);

  }

  param_1[0x18a] = iVar2;

  (**(code **)(*param_1 + 0xa8))(iVar2);

  (**(code **)(*(int *)param_1[0x18a] + 0x28))("i_d_arena/i_d_arena_adv_wnd_divider_3.xml");

  pvVar1 = operator_new(0x488);

  if (pvVar1 == (void *)0x0) {

    iVar2 = 0;

  }

  else {

    iVar2 = FUN_007b5dd0(pvVar1,0);

  }

  param_1[0x18b] = iVar2;

  (**(code **)(*param_1 + 0xa8))(iVar2);

  (**(code **)(*(int *)param_1[0x18b] + 0x28))("i_d_arena/i_d_arena_adv_wnd_divider_4.xml");

  pvVar1 = operator_new(0x81c);

  if (pvVar1 == (void *)0x0) {

    iVar2 = 0;

  }

  else {

    iVar2 = FUN_008230b0(pvVar1);

  }

  param_1[0x18c] = iVar2;

  (**(code **)(*param_1 + 0xa8))(iVar2);

  (**(code **)(*(int *)param_1[0x18c] + 0x28))("i_d_arena/i_d_arena_adv_tab_console.xml");

  (**(code **)(*(int *)param_1[0x18c] + 0x43c))();

  (**(code **)(*(int *)param_1[0x18c] + 0x74))(0x9c48);

  FUN_00822cb0(1);

  FUN_00756c90();

  pvVar1 = operator_new(0x81c);

  if (pvVar1 == (void *)0x0) {

    iVar2 = 0;

  }

  else {

    iVar2 = FUN_008230b0(pvVar1);

  }

  param_1[0x18d] = iVar2;

  (**(code **)(*param_1 + 0xa8))(iVar2);

  (**(code **)(*(int *)param_1[0x18d] + 0x28))("i_d_arena/i_d_arena_adv_tab_tournament.xml");

  (**(code **)(*(int *)param_1[0x18d] + 0x43c))();

  (**(code **)(*(int *)param_1[0x18d] + 0x74))(0x9c49);

  FUN_00822cb0(1);

  FUN_00756c90();

  pvVar1 = operator_new(0x81c);

  if (pvVar1 == (void *)0x0) {

    iVar2 = 0;

  }

  else {

    iVar2 = FUN_008230b0(pvVar1);

  }

  param_1[0x18e] = iVar2;

  (**(code **)(*param_1 + 0xa8))(iVar2);

  (**(code **)(*(int *)param_1[0x18e] + 0x28))("i_d_arena/i_d_arena_adv_tab_advanced.xml");

  (**(code **)(*(int *)param_1[0x18e] + 0x43c))();

  (**(code **)(*(int *)param_1[0x18e] + 0x74))(0x9c4a);

  FUN_00822cb0(1);

  (**(code **)(*(int *)param_1[0x18e] + 0x94))();

  pvVar1 = operator_new(0x488);

  if (pvVar1 == (void *)0x0) {

    iVar2 = 0;

  }

  else {

    iVar2 = FUN_007b5dd0(pvVar1,0);

  }

  param_1[0x163] = iVar2;

  (**(code **)(*param_1 + 0xa8))(iVar2);

  (**(code **)(*(int *)param_1[0x163] + 0x28))("i_d_arena/i_d_arena_adv_wnd_label_match_size.xml");

  pvVar1 = operator_new(0x488);

  if (pvVar1 == (void *)0x0) {

    iVar2 = 0;

  }

  else {

    iVar2 = FUN_007b5dd0(pvVar1,0);

  }

  param_1[0x164] = iVar2;

  (**(code **)(*param_1 + 0xa8))(iVar2);

  (**(code **)(*(int *)param_1[0x164] + 0x28))("i_d_arena/i_d_arena_adv_wnd_label_match_type.xml");

  pvVar1 = operator_new(0x938);

  if (pvVar1 == (void *)0x0) {

    pvVar1 = (void *)0x0;

  }

  else {

    pvVar1 = (void *)FUN_0078e2f0();

  }

  param_1[0x166] = (int)pvVar1;

  (**(code **)(*param_1 + 0xa8))();

  (**(code **)(*(int *)param_1[0x166] + 0x28))("i_d_arena/i_d_arena_adv_cb_match_type.xml");

  (**(code **)(*(int *)param_1[0x166] + 0x43c))();

  (**(code **)(*(int *)param_1[0x166] + 0x74))(0x9c47);

  pvVar3 = operator_new(0x938);

  if (pvVar3 == (void *)0x0) {

    iVar2 = 0;

  }

  else {

    iVar2 = FUN_0078e2f0();

  }

  param_1[0x165] = iVar2;

  (**(code **)(*param_1 + 0xa8))(iVar2);

  (**(code **)(*(int *)param_1[0x165] + 0x28))("i_d_arena/i_d_arena_adv_cb_match_size.xml");

  (**(code **)(*(int *)param_1[0x165] + 0x43c))();

  (**(code **)(*(int *)param_1[0x165] + 0x74))(0x9c46);

  (**(code **)(*(int *)param_1[0x166] + 0x94))();

  (**(code **)(*(int *)param_1[0x165] + 0x94))();

  FUN_00879240();

  (**(code **)(*param_1 + 0x448))();

  (**(code **)(*param_1 + 0x34c))();

  ExceptionList = pvVar1;

  return;

}
