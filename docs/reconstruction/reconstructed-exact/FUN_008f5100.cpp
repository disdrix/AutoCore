// =============================================================================
// FUN_008f5100
// -----------------------------------------------------------------------------
// Stable ID: aa_008f5100
// Address:   0x008f5100  (autoassault.exe, image base 0x400000)
// System:    unknown
// Generated: 2026-07-23 from raw capture (scaffold; refine for important units)
// Exactness: Behavior-preserving rewrite of decompiler control flow. Not modernization.
// Bit-for-bit vs retail EXE: DEFERRED (loaded image may differ slightly).
// =============================================================================

// PURPOSE (auto): Scaffold unit for FUN_008f5100 @ 0x008f5100
// Stable ID: aa_008f5100
// Embedded strings (evidence for future rename):
//   - "i_d_clan_2d_wnd_title.xml"
//   - "i_d_clan_2d_wnd_label_clan_name.xml"
//   - "i_d_clan_2d_wnd_frame_instructions.xml"
//   - "i_d_clan_2d_wnd_instructions.xml"
//   - "i_d_clan_2d_wnd_frame_members.xml"
//   - "i_d_clan_2d_wnd_bg_members.xml"
// Readability: control flow preserved from Ghidra decompile; types tentative.

// READABILITY (auto CF):
//  - Body size: ~229 non-empty decompiler lines.
//  - Control keywords: if×21, return×1.
//  - Notable callees: FUN_007b5dd0×11, FUN_0079c860×6, FUN_0078b6e0×2, FUN_004c22a0, FUN_0078f890, FUN_00792600, FUN_007fbe50, FUN_008f46c0.
//  - Strings: "i_d_clan_2d_wnd_title.xml"; "i_d_clan_2d_wnd_label_clan_name.xml"; "i_d_clan_2d_wnd_frame_instructions.xml"; "i_d_clan_2d_wnd_instructions.xml".
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

void __fastcall FUN_008f5100(int *param_1)



{

  void *pvVar1;

  int iVar2;

  void *pvVar3;

  void *pvStack_c;

  uint8_t *puStack_8;

  uint32_t /* width from decompiler */ local_4;

  

  local_4 = 0xffffffff;

  puStack_8 = &LAB_009ba8f3;

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

  param_1[0x144] = iVar2;

  (**(code **)(*param_1 + 0xa8))(iVar2);

  (**(code **)(*(int *)param_1[0x144] + 0x28))("i_d_clan_2d_wnd_title.xml");

  pvVar1 = operator_new(0x488);

  pvStack_c = (void *)0x1;

  if (pvVar1 == (void *)0x0) {

    iVar2 = 0;

  }

  else {

    iVar2 = FUN_007b5dd0(pvVar1,0);

  }

  pvStack_c = (void *)0xffffffff;

  param_1[0x145] = iVar2;

  (**(code **)(*param_1 + 0xa8))(iVar2);

  (**(code **)(*(int *)param_1[0x145] + 0x28))("i_d_clan_2d_wnd_label_clan_name.xml");

  pvVar1 = operator_new(0x488);

  if (pvVar1 == (void *)0x0) {

    iVar2 = 0;

  }

  else {

    iVar2 = FUN_007b5dd0(pvVar1,0);

  }

  param_1[0x147] = iVar2;

  (**(code **)(*param_1 + 0xa8))(iVar2);

  (**(code **)(*(int *)param_1[0x147] + 0x28))("i_d_clan_2d_wnd_frame_instructions.xml");

  pvVar1 = operator_new(0x488);

  if (pvVar1 == (void *)0x0) {

    iVar2 = 0;

  }

  else {

    iVar2 = FUN_007b5dd0(pvVar1,0);

  }

  param_1[0x146] = iVar2;

  (**(code **)(*param_1 + 0xa8))(iVar2);

  (**(code **)(*(int *)param_1[0x146] + 0x28))("i_d_clan_2d_wnd_instructions.xml");

  pvVar1 = operator_new(0x488);

  if (pvVar1 == (void *)0x0) {

    iVar2 = 0;

  }

  else {

    iVar2 = FUN_007b5dd0(pvVar1,0);

  }

  param_1[0x149] = iVar2;

  (**(code **)(*param_1 + 0xa8))(iVar2);

  (**(code **)(*(int *)param_1[0x149] + 0x28))("i_d_clan_2d_wnd_frame_members.xml");

  pvVar1 = operator_new(0x488);

  if (pvVar1 == (void *)0x0) {

    iVar2 = 0;

  }

  else {

    iVar2 = FUN_007b5dd0(pvVar1,0);

  }

  param_1[0x148] = iVar2;

  (**(code **)(*param_1 + 0xa8))(iVar2);

  (**(code **)(*(int *)param_1[0x148] + 0x28))("i_d_clan_2d_wnd_bg_members.xml");

  pvVar1 = operator_new(0x488);

  if (pvVar1 == (void *)0x0) {

    iVar2 = 0;

  }

  else {

    iVar2 = FUN_007b5dd0(pvVar1,0);

  }

  param_1[0x14a] = iVar2;

  (**(code **)(*param_1 + 0xa8))(iVar2);

  (**(code **)(*(int *)param_1[0x14a] + 0x28))("i_d_clan_2d_wnd_label_members.xml");

  pvVar1 = operator_new(0x4cc);

  iVar2 = 0;

  if (pvVar1 != (void *)0x0) {

    iVar2 = FUN_0079c860();

  }

  param_1[0x14b] = iVar2;

  (**(code **)(*param_1 + 0xa8))(iVar2);

  (**(code **)(*(int *)param_1[0x14b] + 0x28))("i_d_clan_2d_btn_sort_members_name.xml");

  (**(code **)(*(int *)param_1[0x14b] + 0x74))(0x9c45);

  pvVar1 = operator_new(0x4cc);

  iVar2 = 0;

  if (pvVar1 != (void *)0x0) {

    iVar2 = FUN_0079c860();

  }

  param_1[0x14c] = iVar2;

  (**(code **)(*param_1 + 0xa8))(iVar2);

  (**(code **)(*(int *)param_1[0x14c] + 0x28))("i_d_clan_2d_btn_sort_members_online.xml");

  (**(code **)(*(int *)param_1[0x14c] + 0x74))(0x9c46);

  pvVar1 = operator_new(0x9a8);

  if (pvVar1 == (void *)0x0) {

    iVar2 = 0;

  }

  else {

    iVar2 = FUN_0078b6e0();

  }

  param_1[0x14d] = iVar2;

  (**(code **)(*param_1 + 0xa8))(iVar2);

  (**(code **)(*(int *)param_1[0x14d] + 0x28))("i_d_clan_2d_lb_members_name.xml");

  (**(code **)(*(int *)param_1[0x14d] + 0x474))(0x9c47);

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

  (**(code **)(*(int *)param_1[0x14e] + 0x28))("i_d_clan_2d_lb_members_online.xml");

  (**(code **)(*(int *)param_1[0x14e] + 0x474))(0x9c47);

  (**(code **)(*(int *)param_1[0x14e] + 0x43c))();

  pvVar1 = operator_new(0x954);

  if (pvVar1 == (void *)0x0) {

    iVar2 = 0;

  }

  else {

    iVar2 = FUN_0078f890();

  }

  param_1[0x14f] = iVar2;

  (**(code **)(*param_1 + 0xa8))(iVar2);

  (**(code **)(*(int *)param_1[0x14f] + 0x28))("i_d_clan_2d_sb_members.xml");

  (**(code **)(*(int *)param_1[0x14f] + 0x43c))();

  (**(code **)(*(int *)param_1[0x14f] + 0x74))(0x9c48);

  pvVar1 = operator_new(0x488);

  if (pvVar1 == (void *)0x0) {

    iVar2 = 0;

  }

  else {

    iVar2 = FUN_007b5dd0(pvVar1,0);

  }

  param_1[0x150] = iVar2;

  (**(code **)(*param_1 + 0xa8))(iVar2);

  (**(code **)(*(int *)param_1[0x150] + 0x28))("i_d_clan_2d_wnd_label_settings.xml");

  pvVar1 = operator_new(0x4cc);

  iVar2 = 0;

  if (pvVar1 != (void *)0x0) {

    iVar2 = FUN_0079c860();

  }

  param_1[0x151] = iVar2;

  (**(code **)(*param_1 + 0xa8))(iVar2);

  (**(code **)(*(int *)param_1[0x151] + 0x28))("i_d_clan_2d_btn_settings.xml");

  (**(code **)(*(int *)param_1[0x151] + 0x74))(0x9c41);

  pvVar1 = operator_new(0x488);

  if (pvVar1 == (void *)0x0) {

    iVar2 = 0;

  }

  else {

    iVar2 = FUN_007b5dd0(pvVar1,0);

  }

  param_1[0x152] = iVar2;

  (**(code **)(*param_1 + 0xa8))(iVar2);

  (**(code **)(*(int *)param_1[0x152] + 0x28))("i_d_clan_2d_wnd_label_details.xml");

  pvVar1 = operator_new(0x4cc);

  iVar2 = 0;

  if (pvVar1 != (void *)0x0) {

    iVar2 = FUN_0079c860();

  }

  param_1[0x153] = iVar2;

  (**(code **)(*param_1 + 0xa8))(iVar2);

  (**(code **)(*(int *)param_1[0x153] + 0x28))("i_d_clan_2d_btn_details.xml");

  (**(code **)(*(int *)param_1[0x153] + 0x74))(0x9c42);

  pvVar1 = operator_new(0x488);

  if (pvVar1 == (void *)0x0) {

    iVar2 = 0;

  }

  else {

    iVar2 = FUN_007b5dd0(pvVar1,0);

  }

  param_1[0x154] = iVar2;

  (**(code **)(*param_1 + 0xa8))(iVar2);

  (**(code **)(*(int *)param_1[0x154] + 0x28))("i_d_clan_2d_wnd_label_invite.xml");

  pvVar1 = operator_new(0x4cc);

  iVar2 = 0;

  if (pvVar1 != (void *)0x0) {

    iVar2 = FUN_0079c860();

  }

  param_1[0x155] = iVar2;

  (**(code **)(*param_1 + 0xa8))(iVar2);

  (**(code **)(*(int *)param_1[0x155] + 0x28))("i_d_clan_2d_btn_invite.xml");

  (**(code **)(*(int *)param_1[0x155] + 0x74))(0x9c43);

  pvVar1 = operator_new(0x488);

  if (pvVar1 == (void *)0x0) {

    pvVar1 = (void *)0x0;

  }

  else {

    pvVar1 = (void *)FUN_007b5dd0(pvVar1,0);

  }

  param_1[0x156] = (int)pvVar1;

  (**(code **)(*param_1 + 0xa8))();

  (**(code **)(*(int *)param_1[0x156] + 0x28))("i_d_clan_2d_wnd_label_disband.xml");

  pvVar3 = operator_new(0x4cc);

  iVar2 = 0;

  if (pvVar3 != (void *)0x0) {

    iVar2 = FUN_0079c860();

  }

  param_1[0x157] = iVar2;

  (**(code **)(*param_1 + 0xa8))(iVar2);

  (**(code **)(*(int *)param_1[0x157] + 0x28))("i_d_clan_2d_btn_disband.xml");

  (**(code **)(*(int *)param_1[0x157] + 0x74))(0x9c44);

  if ((DAT_00d1b6d8 != 0) && (*DAT_00d1da30 != -1)) {

    iVar2 = *(int *)(*(int *)(DAT_00d1b6d8 + 4) + 4);

    FUN_004c22a0(*(uint32_t /* width from decompiler */ *)(iVar2 + 0x164 + DAT_00d1b6d8),

                 *(uint32_t /* width from decompiler */ *)(iVar2 + 0x168 + DAT_00d1b6d8));

  }

  FUN_008f46c0();

  FUN_007fbe50();

  (**(code **)(*param_1 + 0x448))();

  (**(code **)(*param_1 + 0x34c))();

  ExceptionList = pvVar1;

  return;

}
