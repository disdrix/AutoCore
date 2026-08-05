// =============================================================================
// UI_arena_tournament_rewards_frame_rewards
// -----------------------------------------------------------------------------
// Stable ID: aa_0086db70
// Address:   0x0086db70  (autoassault.exe, image base 0x400000)
// System:    unknown
// Generated: 2026-07-23 from raw capture (scaffold; refine for important units)
// Exactness: Behavior-preserving rewrite of decompiler control flow. Not modernization.
// Bit-for-bit vs retail EXE: DEFERRED (loaded image may differ slightly).
// =============================================================================

// PURPOSE (auto): Scaffold unit for UI_arena_tournament_rewards_frame_rewards @ 0x0086db70
// Stable ID: aa_0086db70
// Embedded strings (evidence for future rename):
//   - "i_d_arena/i_d_arena_tournament_rewards_wnd_bg_fill.xml"
//   - "i_d_arena/i_d_arena_tournament_rewards_wnd_bg_texture.xml"
//   - "i_d_arena/i_d_arena_tournament_rewards_wnd_label_title.xml"
//   - "i_d_arena/i_d_arena_tournament_rewards_wnd_fx.xml"
//   - "i_d_arena/i_d_arena_tournament_rewards_btn_accept.xml"
//   - "i_d_arena/i_d_arena_tournament_rewards_wnd_frame_rewards.xml"
// Readability: control flow preserved from Ghidra decompile; types tentative.

// READABILITY (auto CF):
//  - Body size: ~318 non-empty decompiler lines.
//  - Control keywords: if×26, return×1.
//  - Notable callees: FUN_007b5dd0×23, FUN_0079c860×2, FUN_00792600, FUN_00864f20, UI_arena_tournament_rewards_frame_rewards.
//  - Strings: "i_d_arena/i_d_arena_tournament_rewards_wnd_bg_fill.xml"; "i_d_arena/i_d_arena_tournament_rewards_wnd_bg_texture.xml"; "i_d_arena/i_d_arena_tournament_rewards_wnd_label_title.xml"; "i_d_arena/i_d_arena_tournament_rewards_wnd_fx.xml".
//  - Return sites: 1.

/*
 * Behavioral notes:
 * Plate-driven rename evidence: "i_d_arena/i_d_arena_tournament_rewards_wnd_frame_rewards.xml"
 * Domain alias of FUN_0086db70 (FUN_* retained)
 *
 * - Derived from Ghidra decompile; names prefer Ghidra symbols / plate comments.
 * - Remaining FUN_* / DAT_* identifiers are unresolved pending type recovery.
 * - Runtime / differential verification: OPEN unless matrix says otherwise.
 *
 * Readability pass:
 * - undefinedN widths preserved as fixed-width integers where decompiler width is known.
 * - Control flow and call order preserved from authoritative raw.
 */

void __fastcall UI_arena_tournament_rewards_frame_rewards(int *param_1)



{

  void *pvVar1;

  int iVar2;

  char *pcVar3;

  void *pvStack_c;

  uint8_t *puStack_8;

  uint32_t /* width from decompiler */ local_4;

  

  local_4 = 0xffffffff;

  puStack_8 = &LAB_009b4d11;

  pvStack_c = ExceptionList;

  ExceptionList = &pvStack_c;

  param_1[0x13f] = 0xf;

  param_1[0x140] = 1;

  *(uint8_t *)((int)param_1 + 0xc5) = 0;

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

  (**(code **)(*(int *)param_1[0x158] + 0x28))

            ("i_d_arena/i_d_arena_tournament_rewards_wnd_bg_fill.xml");

  pvVar1 = operator_new(0x488);

  pvStack_c = (void *)0x1;

  if (pvVar1 == (void *)0x0) {

    iVar2 = 0;

  }

  else {

    iVar2 = FUN_007b5dd0(pvVar1,0);

  }

  pvStack_c = (void *)0xffffffff;

  param_1[0x159] = iVar2;

  (**(code **)(*param_1 + 0xa8))(iVar2);

  (**(code **)(*(int *)param_1[0x159] + 0x28))

            ("i_d_arena/i_d_arena_tournament_rewards_wnd_bg_texture.xml");

  pvVar1 = operator_new(0x488);

  if (pvVar1 == (void *)0x0) {

    iVar2 = 0;

  }

  else {

    iVar2 = FUN_007b5dd0(pvVar1,0);

  }

  param_1[0x15a] = iVar2;

  (**(code **)(*param_1 + 0xa8))(iVar2);

  (**(code **)(*(int *)param_1[0x15a] + 0x28))

            ("i_d_arena/i_d_arena_tournament_rewards_wnd_label_title.xml");

  pvVar1 = operator_new(0x4bc);

  if (pvVar1 == (void *)0x0) {

    iVar2 = 0;

  }

  else {

    iVar2 = FUN_00864f20(pvVar1);

  }

  param_1[0x15b] = iVar2;

  (**(code **)(*param_1 + 0xa8))(iVar2);

  (**(code **)(*(int *)param_1[0x15b] + 0x28))("i_d_arena/i_d_arena_tournament_rewards_wnd_fx.xml");

  pvVar1 = operator_new(0x4cc);

  iVar2 = 0;

  if (pvVar1 != (void *)0x0) {

    iVar2 = FUN_0079c860();

  }

  param_1[0x15c] = iVar2;

  (**(code **)(*param_1 + 0xa8))(iVar2);

  (**(code **)(*(int *)param_1[0x15c] + 0x28))

            ("i_d_arena/i_d_arena_tournament_rewards_btn_accept.xml");

  (**(code **)(*(int *)param_1[0x15c] + 0x74))(0x9c41);

  pvVar1 = operator_new(0x488);

  if (pvVar1 == (void *)0x0) {

    iVar2 = 0;

  }

  else {

    iVar2 = FUN_007b5dd0(pvVar1,0);

  }

  param_1[0x15f] = iVar2;

  (**(code **)(*param_1 + 0xa8))(iVar2);

  (**(code **)(*(int *)param_1[0x15f] + 0x28))

            ("i_d_arena/i_d_arena_tournament_rewards_wnd_frame_rewards.xml");

  pvVar1 = operator_new(0x488);

  if (pvVar1 == (void *)0x0) {

    iVar2 = 0;

  }

  else {

    iVar2 = FUN_007b5dd0(pvVar1,0);

  }

  param_1[0x15d] = iVar2;

  (**(code **)(*param_1 + 0xa8))(iVar2);

  (**(code **)(*(int *)param_1[0x15d] + 0x28))

            ("i_d_arena/i_d_arena_tournament_rewards_wnd_label_rewards.xml");

  pvVar1 = operator_new(0x488);

  if (pvVar1 == (void *)0x0) {

    iVar2 = 0;

  }

  else {

    iVar2 = FUN_007b5dd0(pvVar1,0);

  }

  param_1[0x15e] = iVar2;

  (**(code **)(*param_1 + 0xa8))(iVar2);

  (**(code **)(*(int *)param_1[0x15e] + 0x28))

            ("i_d_arena/i_d_arena_tournament_rewards_wnd_text_rewards.xml");

  pvVar1 = operator_new(0x488);

  if (pvVar1 == (void *)0x0) {

    iVar2 = 0;

  }

  else {

    iVar2 = FUN_007b5dd0(pvVar1,0);

  }

  param_1[0x160] = iVar2;

  (**(code **)(*param_1 + 0xa8))(iVar2);

  (**(code **)(*(int *)param_1[0x160] + 0x28))

            ("i_d_arena/i_d_arena_tournament_rewards_wnd_label_rewards_given.xml");

  pvVar1 = operator_new(0x488);

  if (pvVar1 == (void *)0x0) {

    iVar2 = 0;

  }

  else {

    iVar2 = FUN_007b5dd0(pvVar1,0);

  }

  param_1[0x162] = iVar2;

  (**(code **)(*param_1 + 0xa8))(iVar2);

  (**(code **)(*(int *)param_1[0x162] + 0x28))

            ("i_d_arena/i_d_arena_tournament_rewards_wnd_item_bg.xml");

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

            ("i_d_arena/i_d_arena_tournament_rewards_wnd_item_text.xml");

  (**(code **)(*(int *)param_1[0x16c] + 0x74))(0x9c42);

  pvVar1 = operator_new(0x488);

  if (pvVar1 == (void *)0x0) {

    iVar2 = 0;

  }

  else {

    iVar2 = FUN_007b5dd0(pvVar1,0);

  }

  param_1[0x167] = iVar2;

  (**(code **)(*param_1 + 0xa8))(iVar2);

  (**(code **)(*(int *)param_1[0x167] + 0x28))

            ("i_d_arena/i_d_arena_tournament_rewards_wnd_item.xml");

  (**(code **)(*(int *)param_1[0x167] + 0x74))(0x9c42);

  pvVar1 = operator_new(0x488);

  if (pvVar1 == (void *)0x0) {

    iVar2 = 0;

  }

  else {

    iVar2 = FUN_007b5dd0(pvVar1,0);

  }

  param_1[0x161] = iVar2;

  (**(code **)(*param_1 + 0xa8))(iVar2);

  (**(code **)(*(int *)param_1[0x161] + 0x28))

            ("i_d_arena/i_d_arena_tournament_rewards_wnd_label_rewards_choose.xml");

  pvVar1 = operator_new(0x488);

  if (pvVar1 == (void *)0x0) {

    iVar2 = 0;

  }

  else {

    iVar2 = FUN_007b5dd0(pvVar1,0);

  }

  param_1[0x163] = iVar2;

  (**(code **)(*param_1 + 0xa8))(iVar2);

  (**(code **)(*(int *)param_1[0x163] + 0x28))

            ("i_d_arena/i_d_arena_tournament_rewards_wnd_item_bg1.xml");

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

            ("i_d_arena/i_d_arena_tournament_rewards_wnd_item_text1.xml");

  (**(code **)(*(int *)param_1[0x16d] + 0x74))(0x9c43);

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

            ("i_d_arena/i_d_arena_tournament_rewards_wnd_item1.xml");

  (**(code **)(*(int *)param_1[0x168] + 0x74))(0x9c43);

  pvVar1 = operator_new(0x488);

  if (pvVar1 == (void *)0x0) {

    iVar2 = 0;

  }

  else {

    iVar2 = FUN_007b5dd0(pvVar1,0);

  }

  param_1[0x164] = iVar2;

  (**(code **)(*param_1 + 0xa8))(iVar2);

  (**(code **)(*(int *)param_1[0x164] + 0x28))

            ("i_d_arena/i_d_arena_tournament_rewards_wnd_item_bg2.xml");

  pvVar1 = operator_new(0x488);

  if (pvVar1 == (void *)0x0) {

    iVar2 = 0;

  }

  else {

    iVar2 = FUN_007b5dd0(pvVar1,0);

  }

  param_1[0x16e] = iVar2;

  (**(code **)(*param_1 + 0xa8))(iVar2);

  (**(code **)(*(int *)param_1[0x16e] + 0x28))

            ("i_d_arena/i_d_arena_tournament_rewards_wnd_item_text2.xml");

  (**(code **)(*(int *)param_1[0x16e] + 0x74))(0x9c44);

  pvVar1 = operator_new(0x488);

  if (pvVar1 == (void *)0x0) {

    iVar2 = 0;

  }

  else {

    iVar2 = FUN_007b5dd0(pvVar1,0);

  }

  param_1[0x169] = iVar2;

  (**(code **)(*param_1 + 0xa8))(iVar2);

  (**(code **)(*(int *)param_1[0x169] + 0x28))

            ("i_d_arena/i_d_arena_tournament_rewards_wnd_item2.xml");

  (**(code **)(*(int *)param_1[0x169] + 0x74))(0x9c44);

  pvVar1 = operator_new(0x488);

  if (pvVar1 == (void *)0x0) {

    iVar2 = 0;

  }

  else {

    iVar2 = FUN_007b5dd0(pvVar1,0);

  }

  param_1[0x165] = iVar2;

  (**(code **)(*param_1 + 0xa8))(iVar2);

  (**(code **)(*(int *)param_1[0x165] + 0x28))

            ("i_d_arena/i_d_arena_tournament_rewards_wnd_item_bg3.xml");

  pvVar1 = operator_new(0x488);

  if (pvVar1 == (void *)0x0) {

    iVar2 = 0;

  }

  else {

    iVar2 = FUN_007b5dd0(pvVar1,0);

  }

  param_1[0x16f] = iVar2;

  (**(code **)(*param_1 + 0xa8))(iVar2);

  (**(code **)(*(int *)param_1[0x16f] + 0x28))

            ("i_d_arena/i_d_arena_tournament_rewards_wnd_item_text3.xml");

  (**(code **)(*(int *)param_1[0x16f] + 0x74))(0x9c45);

  pvVar1 = operator_new(0x488);

  if (pvVar1 == (void *)0x0) {

    iVar2 = 0;

  }

  else {

    iVar2 = FUN_007b5dd0(pvVar1,0);

  }

  param_1[0x16a] = iVar2;

  (**(code **)(*param_1 + 0xa8))(iVar2);

  (**(code **)(*(int *)param_1[0x16a] + 0x28))

            ("i_d_arena/i_d_arena_tournament_rewards_wnd_item3.xml");

  (**(code **)(*(int *)param_1[0x16a] + 0x74))(0x9c45);

  pvVar1 = operator_new(0x488);

  if (pvVar1 == (void *)0x0) {

    iVar2 = 0;

  }

  else {

    iVar2 = FUN_007b5dd0(pvVar1,0);

  }

  param_1[0x166] = iVar2;

  (**(code **)(*param_1 + 0xa8))(iVar2);

  (**(code **)(*(int *)param_1[0x166] + 0x28))

            ("i_d_arena/i_d_arena_tournament_rewards_wnd_item_bg4.xml");

  pvVar1 = operator_new(0x488);

  if (pvVar1 == (void *)0x0) {

    iVar2 = 0;

  }

  else {

    iVar2 = FUN_007b5dd0(pvVar1,0);

  }

  param_1[0x170] = iVar2;

  (**(code **)(*param_1 + 0xa8))(iVar2);

  (**(code **)(*(int *)param_1[0x170] + 0x28))

            ("i_d_arena/i_d_arena_tournament_rewards_wnd_item_text4.xml");

  (**(code **)(*(int *)param_1[0x170] + 0x74))(0x9c46);

  pvVar1 = operator_new(0x488);

  if (pvVar1 == (void *)0x0) {

    iVar2 = 0;

  }

  else {

    iVar2 = FUN_007b5dd0(pvVar1,0);

  }

  param_1[0x16b] = iVar2;

  (**(code **)(*param_1 + 0xa8))(iVar2);

  pcVar3 = "i_d_arena/i_d_arena_tournament_rewards_wnd_item4.xml";

  (**(code **)(*(int *)param_1[0x16b] + 0x28))();

  (**(code **)(*(int *)param_1[0x16b] + 0x74))(0x9c46);

  pvVar1 = operator_new(0x4cc);

  iVar2 = 0;

  if (pvVar1 != (void *)0x0) {

    iVar2 = FUN_0079c860();

  }

  param_1[0x141] = iVar2;

  (**(code **)(*param_1 + 0xa8))(iVar2);

  (**(code **)(*(int *)param_1[0x141] + 0x28))

            ("i_d_arena/i_d_arena_tournament_rewards_btn_close.xml");

  (**(code **)(*(int *)param_1[0x141] + 0x74))(40000);

  (**(code **)(*param_1 + 0x448))();

  (**(code **)(*param_1 + 0x34c))();

  ExceptionList = pcVar3;

  return;

}
