// READABILITY (auto CF):
//  - Body size: ~200 non-empty decompiler lines.
//  - Control keywords: if×19, return×1.
//  - Notable callees: FUN_007b5dd0×12, FUN_0079c860×2, FUN_00792600, FUN_00864f20, FUN_00894c40, FUN_008956e0.
//  - Strings: "i_d_skilltrainer_2d_wnd_title.xml"; "i_d_skilltrainer_2d_wnd_icon.xml"; "i_d_skilltrainer_2d_wnd_icon_cover.xml"; "i_d_skilltrainer_2d_btn_close.xml".
//  - Return sites: 1.

// =============================================================================
// Mission_i_d_skilltrainer_2d_wnd_npc_name_xml
// -----------------------------------------------------------------------------
// Stable ID: aa_008956e0
// Address:   0x008956e0  (autoassault.exe, image base 0x400000)
// System:    unknown
// Generated: 2026-07-23 from raw capture (scaffold; refine for important units)
// Exactness: Behavior-preserving rewrite of decompiler control flow. Not modernization.
// Bit-for-bit vs retail EXE: DEFERRED (loaded image may differ slightly).
// =============================================================================

/*
 * Behavioral notes:
 * String-driven rename evidence: "i_d_skilltrainer_2d_wnd_npc_name.xml"
 *
 * - Derived from Ghidra decompile; names prefer Ghidra symbols / plate comments.
 * - Remaining FUN_* / DAT_* identifiers are unresolved pending type recovery.
 * - Runtime / differential verification: OPEN unless matrix says otherwise.
 *
 * Readability pass:
 * - undefinedN widths preserved as fixed-width integers where decompiler width is known.
 * - Control flow and call order preserved from authoritative raw.
 */

void __fastcall Mission_i_d_skilltrainer_2d_wnd_npc_name_xml(int *param_1)



{

  void *pvVar1;

  int iVar2;

  void *pvVar3;

  void *pvStack_c;

  uint8_t *puStack_8;

  uint32_t /* width from decompiler */ local_4;

  

  local_4 = 0xffffffff;

  puStack_8 = &LAB_009b5d6e;

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

  param_1[0x14d] = iVar2;

  (**(code **)(*param_1 + 0xa8))();

  (**(code **)(*(int *)param_1[0x14d] + 0x28))();

  iVar2 = param_1[0x1a] + 1;

  param_1[0x1a] = iVar2;

  param_1[0x1d] = (int)(float)-iVar2;

  if (param_1[0x1c] < iVar2) {

    param_1[0x1c] = iVar2;

  }

  (**(code **)(*param_1 + 0x3f4))();

  pvVar1 = operator_new(0x4bc);

  if (pvVar1 == (void *)0x0) {

    iVar2 = 0;

  }

  else {

    iVar2 = FUN_00864f20();

  }

  param_1[0x14e] = iVar2;

  (**(code **)(*param_1 + 0xa8))();

  (**(code **)(*(int *)param_1[0x14e] + 0x28))();

  iVar2 = param_1[0x1a] + 1;

  param_1[0x1a] = iVar2;

  param_1[0x1d] = (int)(float)-iVar2;

  if (param_1[0x1c] < iVar2) {

    param_1[0x1c] = iVar2;

  }

  (**(code **)(*param_1 + 0x3f4))();

  pvVar1 = operator_new(0x488);

  if (pvVar1 == (void *)0x0) {

    iVar2 = 0;

  }

  else {

    iVar2 = FUN_007b5dd0();

  }

  param_1[0x14f] = iVar2;

  (**(code **)(*param_1 + 0xa8))();

  (**(code **)(*(int *)param_1[0x14f] + 0x28))();

  iVar2 = param_1[0x1a] + 1;

  param_1[0x1a] = iVar2;

  param_1[0x1d] = (int)(float)-iVar2;

  if (param_1[0x1c] < iVar2) {

    param_1[0x1c] = iVar2;

  }

  (**(code **)(*param_1 + 0x3f4))();

  pvVar1 = operator_new(0x488);

  if (pvVar1 == (void *)0x0) {

    iVar2 = 0;

  }

  else {

    iVar2 = FUN_007b5dd0(pvVar1);

  }

  param_1[0x150] = iVar2;

  (**(code **)(*param_1 + 0xa8))();

  (**(code **)(*(int *)param_1[0x150] + 0x28))("i_d_skilltrainer_2d_wnd_title.xml");

  pvVar1 = operator_new(0x488);

  if (pvVar1 == (void *)0x0) {

    iVar2 = 0;

  }

  else {

    iVar2 = FUN_007b5dd0(pvVar1,0);

  }

  param_1[0x151] = iVar2;

  (**(code **)(*param_1 + 0xa8))(iVar2);

  (**(code **)(*(int *)param_1[0x151] + 0x28))("i_d_skilltrainer_2d_wnd_icon.xml");

  (**(code **)(*param_1 + 0x404))

            (&stack0xffffffb8,"i_d_skilltrainer_2d_wnd_icon_cover.xml",0xffffffff);

  iVar2 = param_1[0x1a] + 1;

  param_1[0x1a] = iVar2;

  param_1[0x1d] = (int)(float)-iVar2;

  if (param_1[0x1c] < iVar2) {

    param_1[0x1c] = iVar2;

  }

  (**(code **)(*param_1 + 0x3f4))(1);

  pvVar1 = operator_new(0x4cc);

  iVar2 = 0;

  if (pvVar1 != (void *)0x0) {

    iVar2 = FUN_0079c860();

  }

  param_1[0x15b] = iVar2;

  (**(code **)(*param_1 + 0xa8))(iVar2);

  (**(code **)(*(int *)param_1[0x15b] + 0x28))("i_d_skilltrainer_2d_btn_close.xml");

  (**(code **)(*(int *)param_1[0x15b] + 0x74))(40000);

  pvVar1 = operator_new(0x488);

  if (pvVar1 == (void *)0x0) {

    iVar2 = 0;

  }

  else {

    iVar2 = FUN_007b5dd0(pvVar1,0);

  }

  param_1[0x152] = iVar2;

  (**(code **)(*param_1 + 0xa8))(iVar2);

  (**(code **)(*(int *)param_1[0x152] + 0x28))("i_d_skilltrainer_2d_wnd_bg_train.xml");

  pvVar1 = operator_new(0x488);

  if (pvVar1 == (void *)0x0) {

    iVar2 = 0;

  }

  else {

    iVar2 = FUN_007b5dd0(pvVar1,0);

  }

  param_1[0x153] = iVar2;

  (**(code **)(*param_1 + 0xa8))(iVar2);

  (**(code **)(*(int *)param_1[0x153] + 0x28))("i_d_skilltrainer_2d_wnd_npc_name.xml");

  pvVar1 = operator_new(0x488);

  if (pvVar1 == (void *)0x0) {

    iVar2 = 0;

  }

  else {

    iVar2 = FUN_007b5dd0(pvVar1,0);

  }

  param_1[0x154] = iVar2;

  (**(code **)(*param_1 + 0xa8))(iVar2);

  (**(code **)(*(int *)param_1[0x154] + 0x28))("i_d_skilltrainer_2d_wnd_discipline_name.xml");

  pvVar1 = operator_new(0x488);

  if (pvVar1 == (void *)0x0) {

    iVar2 = 0;

  }

  else {

    iVar2 = FUN_007b5dd0(pvVar1,0);

  }

  param_1[0x155] = iVar2;

  (**(code **)(*param_1 + 0xa8))(iVar2);

  (**(code **)(*(int *)param_1[0x155] + 0x28))("i_d_skilltrainer_2d_wnd_discipline_desc.xml");

  pvVar1 = operator_new(0x488);

  if (pvVar1 == (void *)0x0) {

    iVar2 = 0;

  }

  else {

    iVar2 = FUN_007b5dd0(pvVar1,0);

  }

  param_1[0x156] = iVar2;

  (**(code **)(*param_1 + 0xa8))(iVar2);

  (**(code **)(*(int *)param_1[0x156] + 0x28))("i_d_skilltrainer_2d_wnd_train_max.xml");

  pvVar1 = operator_new(0x488);

  if (pvVar1 == (void *)0x0) {

    iVar2 = 0;

  }

  else {

    iVar2 = FUN_007b5dd0(pvVar1,0);

  }

  param_1[0x157] = iVar2;

  (**(code **)(*param_1 + 0xa8))(iVar2);

  (**(code **)(*(int *)param_1[0x157] + 0x28))("i_d_skilltrainer_2d_wnd_player_current.xml");

  pvVar1 = operator_new(0x488);

  if (pvVar1 == (void *)0x0) {

    iVar2 = 0;

  }

  else {

    iVar2 = FUN_007b5dd0(pvVar1,0);

  }

  param_1[0x158] = iVar2;

  (**(code **)(*param_1 + 0xa8))(iVar2);

  (**(code **)(*(int *)param_1[0x158] + 0x28))("i_d_skilltrainer_2d_wnd_cost.xml");

  pvVar1 = operator_new(0x488);

  if (pvVar1 == (void *)0x0) {

    iVar2 = 0;

  }

  else {

    iVar2 = FUN_007b5dd0(pvVar1,0);

  }

  param_1[0x159] = iVar2;

  (**(code **)(*param_1 + 0xa8))(iVar2);

  (**(code **)(*(int *)param_1[0x159] + 0x28))("i_d_skilltrainer_2d_wnd_are_you_sure.xml");

  pvVar1 = operator_new(0x4cc);

  pvVar3 = (void *)0x0;

  if (pvVar1 != (void *)0x0) {

    pvVar3 = (void *)FUN_0079c860();

  }

  param_1[0x15a] = (int)pvVar3;

  (**(code **)(*param_1 + 0xa8))();

  (**(code **)(*(int *)param_1[0x15a] + 0x28))("i_d_skilltrainer_2d_btn_train.xml");

  (**(code **)(*(int *)param_1[0x15a] + 0x74))(0x9c41);

  (**(code **)(*(int *)param_1[0x15a] + 0xd4))(0);

  FUN_00894c40();

  (**(code **)(*param_1 + 0xfc))(1,0x3f000000);

  (**(code **)(*param_1 + 0x34c))();

  ExceptionList = pvVar3;

  return;

}
