// =============================================================================
// FUN_008cdae0
// -----------------------------------------------------------------------------
// Stable ID: aa_008cdae0
// Address:   0x008cdae0  (autoassault.exe, image base 0x400000)
// System:    unknown
// Generated: 2026-07-23 from raw capture (scaffold; refine for important units)
// Exactness: Behavior-preserving rewrite of decompiler control flow. Not modernization.
// Bit-for-bit vs retail EXE: DEFERRED (loaded image may differ slightly).
// =============================================================================

// PURPOSE (auto): Scaffold unit for FUN_008cdae0 @ 0x008cdae0
// Stable ID: aa_008cdae0
// Embedded strings (evidence for future rename):
//   - "i_d_fec_2d_wnd_drag_rotate.xml"
//   - "i_d_fes_2d_wnd_frame_fill.xml"
//   - "i_d_fes_2d_wnd_frame_bg.xml"
//   - "i_d_fes_2d_wnd_frame_server.xml"
//   - "i_d_fes_2d_wnd_frame_characters.xml"
//   - "i_d_fes_2d_wnd_frame_buttons.xml"
// Readability: control flow preserved from Ghidra decompile; types tentative.

// READABILITY (auto CF):
//  - Body size: ~273 non-empty decompiler lines.
//  - Control keywords: if×25, do×1, goto×1, while×1, return×1.
//  - Notable callees: FUN_007b5dd0×11, FUN_0079c860×6, FUN_00792600, FUN_008aab00, FUN_008cd200, FUN_008cdae0.
//  - Strings: "i_d_fec_2d_wnd_drag_rotate.xml"; "i_d_fes_2d_wnd_frame_fill.xml"; "i_d_fes_2d_wnd_frame_bg.xml"; "i_d_fes_2d_wnd_frame_server.xml".
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

void __fastcall FUN_008cdae0(int *param_1)



{

  byte bVar1;

  void *pvVar2;

  int iVar3;

  int *piVar4;

  void *pvStack_c;

  uint8_t *puStack_8;

  uint32_t /* width from decompiler */ local_4;

  

  local_4 = 0xffffffff;

  puStack_8 = &LAB_009b6e86;

  pvStack_c = ExceptionList;

  ExceptionList = &pvStack_c;

  FUN_00792600();

  pvVar2 = operator_new(0x488);

  local_4 = 0;

  if (pvVar2 == (void *)0x0) {

    iVar3 = 0;

  }

  else {

    iVar3 = FUN_007b5dd0(pvVar2,0);

  }

  local_4 = 0xffffffff;

  param_1[0x154] = iVar3;

  (**(code **)(*param_1 + 0xa8))(iVar3);

  (**(code **)(*(int *)param_1[0x154] + 0x28))("i_d_fec_2d_wnd_drag_rotate.xml");

  (**(code **)(*(int *)param_1[0x154] + 0x74))(0x9c42);

  pvVar2 = operator_new(0x488);

  if (pvVar2 == (void *)0x0) {

    iVar3 = 0;

  }

  else {

    iVar3 = FUN_007b5dd0(pvVar2,0);

  }

  param_1[0x161] = iVar3;

  (**(code **)(*param_1 + 0xa8))(iVar3);

  (**(code **)(*(int *)param_1[0x161] + 0x28))("i_d_fes_2d_wnd_frame_fill.xml");

  (**(code **)(*(int *)param_1[0x161] + 0xfc))(1,0x3f000000);

  iVar3 = param_1[0x1a] + 1;

  param_1[0x1a] = iVar3;

  param_1[0x1d] = (int)(float)-iVar3;

  if (param_1[0x1c] < iVar3) {

    param_1[0x1c] = iVar3;

  }

  (**(code **)(*param_1 + 0x3f4))(1);

  pvVar2 = operator_new(0x488);

  if (pvVar2 == (void *)0x0) {

    iVar3 = 0;

  }

  else {

    iVar3 = FUN_007b5dd0(pvVar2,0);

  }

  param_1[0x162] = iVar3;

  (**(code **)(*param_1 + 0xa8))(iVar3);

  (**(code **)(*(int *)param_1[0x162] + 0x28))("i_d_fes_2d_wnd_frame_bg.xml");

  (**(code **)(*(int *)param_1[0x162] + 0xfc))(1,0x3f000000);

  iVar3 = param_1[0x1a] + 1;

  param_1[0x1a] = iVar3;

  param_1[0x1d] = (int)(float)-iVar3;

  if (param_1[0x1c] < iVar3) {

    param_1[0x1c] = iVar3;

  }

  (**(code **)(*param_1 + 0x3f4))(1);

  pvVar2 = operator_new(0x488);

  if (pvVar2 == (void *)0x0) {

    piVar4 = (int *)0x0;

  }

  else {

    piVar4 = (int *)FUN_007b5dd0(pvVar2,0);

  }

  (**(code **)(*param_1 + 0xa8))(piVar4);

  (**(code **)(*piVar4 + 0x28))("i_d_fes_2d_wnd_frame_server.xml");

  (**(code **)(*piVar4 + 0xfc))(1,0x3f000000);

  pvVar2 = operator_new(0x488);

  if (pvVar2 == (void *)0x0) {

    piVar4 = (int *)0x0;

  }

  else {

    piVar4 = (int *)FUN_007b5dd0(pvVar2,0);

  }

  (**(code **)(*param_1 + 0xa8))(piVar4);

  (**(code **)(*piVar4 + 0x28))("i_d_fes_2d_wnd_frame_characters.xml");

  (**(code **)(*piVar4 + 0xfc))(1,0x3f000000);

  pvVar2 = operator_new(0x488);

  if (pvVar2 == (void *)0x0) {

    piVar4 = (int *)0x0;

  }

  else {

    piVar4 = (int *)FUN_007b5dd0(pvVar2,0);

  }

  (**(code **)(*param_1 + 0xa8))(piVar4);

  (**(code **)(*piVar4 + 0x28))("i_d_fes_2d_wnd_frame_buttons.xml");

  (**(code **)(*piVar4 + 0xfc))(1,0x3f000000);

  pvVar2 = operator_new(0x488);

  if (pvVar2 == (void *)0x0) {

    piVar4 = (int *)0x0;

  }

  else {

    piVar4 = (int *)FUN_007b5dd0(pvVar2,0);

  }

  (**(code **)(*param_1 + 0xa8))(piVar4);

  (**(code **)(*piVar4 + 0x28))("i_d_fes_2d_wnd_frame_btn_back.xml");

  (**(code **)(*piVar4 + 0xfc))(1,0x3f000000);

  (**(code **)(*param_1 + 0x404))(param_1 + 399,"i_d_fes_2d_wnd_info_bg.xml",0xffffffff);

  (**(code **)(*param_1 + 0x404))(param_1 + 0x18b,"i_d_fes_2d_wnd_info_name.xml",0xffffffff);

  (**(code **)(*param_1 + 0x404))(param_1 + 0x18c,"i_d_fes_2d_wnd_info_stats.xml",0xffffffff);

  (**(code **)(*param_1 + 0x404))(param_1 + 0x18d,"i_d_fes_2d_wnd_info_front.xml",0xffffffff);

  (**(code **)(*param_1 + 0x404))(param_1 + 0x18e,"i_d_fes_2d_wnd_info_label.xml",0xffffffff);

  (**(code **)(*(int *)param_1[399] + 0xcc))(0);

  (**(code **)(*(int *)param_1[0x18d] + 0xcc))(0);

  (**(code **)(*(int *)param_1[0x18e] + 0xcc))(0);

  pvVar2 = operator_new(0x488);

  if (pvVar2 == (void *)0x0) {

    iVar3 = 0;

  }

  else {

    iVar3 = FUN_007b5dd0(pvVar2,0);

  }

  param_1[0x153] = iVar3;

  (**(code **)(*param_1 + 0xa8))(iVar3);

  (**(code **)(*(int *)param_1[0x153] + 0x28))("i_d_fes_2d_wnd_rotate_base.xml");

  (**(code **)(*(int *)param_1[0x153] + 0xfc))(1,0x3f000000);

  iVar3 = param_1[0x1a] + 1;

  param_1[0x1a] = iVar3;

  param_1[0x1d] = (int)(float)-iVar3;

  if (param_1[0x1c] < iVar3) {

    param_1[0x1c] = iVar3;

  }

  (**(code **)(*param_1 + 0x3f4))(1);

  (**(code **)(*param_1 + 0x404))(param_1 + 0x191,"i_d_fes_2d_wnd_news_frame_fill.xml",0xffffffff);

  (**(code **)(*param_1 + 0x404))(param_1 + 400,"i_d_fes_2d_wnd_news_frame_bg.xml",0xffffffff);

  (**(code **)(*param_1 + 0x404))(param_1 + 0x192,"i_d_fes_2d_wnd_news_frame_inner.xml",0xffffffff);

  (**(code **)(*param_1 + 0x404))

            (param_1 + 0x193,"i_d_fes_2d_wnd_news_frame_inner_top.xml",0xffffffff);

  (**(code **)(*param_1 + 0x404))(param_1 + 0x194,"i_d_fes_2d_wnd_news_title.xml",0xffffffff);

  (**(code **)(*param_1 + 0x404))(param_1 + 0x195,"i_d_fes_2d_wnd_news_message.xml",0xffffffff);

  FUN_008aab00(param_1[0x195]);

  pvVar2 = operator_new(0x488);

  if (pvVar2 == (void *)0x0) {

    iVar3 = 0;

  }

  else {

    iVar3 = FUN_007b5dd0(pvVar2,0);

  }

  param_1[0x155] = iVar3;

  (**(code **)(*param_1 + 0xa8))(iVar3);

  (**(code **)(*(int *)param_1[0x155] + 0x28))("i_d_fes_2d_wnd_logo.xml");

  (**(code **)(*(int *)param_1[0x155] + 0xfc))(1,0x3f000000);

  iVar3 = param_1[0x1a] + 1;

  param_1[0x1a] = iVar3;

  param_1[0x1d] = (int)(float)-iVar3;

  if (param_1[0x1c] < iVar3) {

    param_1[0x1c] = iVar3;

  }

  (**(code **)(*param_1 + 0x3f4))(1);

  pvVar2 = operator_new(0x488);

  if (pvVar2 == (void *)0x0) {

    iVar3 = 0;

  }

  else {

    iVar3 = FUN_007b5dd0(pvVar2,0);

  }

  param_1[0x165] = iVar3;

  (**(code **)(*param_1 + 0xa8))(iVar3);

  (**(code **)(*(int *)param_1[0x165] + 0x28))("i_d_fes_2d_wnd_label_current_server.xml");

  (**(code **)(*(int *)param_1[0x165] + 0xfc))(1,0x3f000000);

  pvVar2 = operator_new(0x488);

  if (pvVar2 == (void *)0x0) {

    iVar3 = 0;

  }

  else {

    iVar3 = FUN_007b5dd0(pvVar2,0);

  }

  param_1[0x166] = iVar3;

  (**(code **)(*param_1 + 0xa8))(iVar3);

  (**(code **)(*(int *)param_1[0x166] + 0x28))("i_d_fes_2d_wnd_label_server_name.xml");

  (**(code **)(*(int *)param_1[0x166] + 0xfc))(1,0x3f000000);

  iVar3 = param_1[0x1a] + 1;

  param_1[0x1a] = iVar3;

  param_1[0x1d] = (int)(float)-iVar3;

  if (param_1[0x1c] < iVar3) {

    param_1[0x1c] = iVar3;

  }

  (**(code **)(*param_1 + 0x3f4))(1);

  pvVar2 = operator_new(0x4cc);

  iVar3 = 0;

  if (pvVar2 != (void *)0x0) {

    iVar3 = FUN_0079c860();

  }

  param_1[0x156] = iVar3;

  (**(code **)(*param_1 + 0xa8))(iVar3);

  (**(code **)(*(int *)param_1[0x156] + 0x28))("i_d_fes_2d_btn_create.xml");

  (**(code **)(*(int *)param_1[0x156] + 0x74))(40000);

  (**(code **)(*(int *)param_1[0x156] + 0xfc))(1,0x3f000000);

  pvVar2 = operator_new(0x4cc);

  iVar3 = 0;

  if (pvVar2 != (void *)0x0) {

    iVar3 = FUN_0079c860();

  }

  param_1[0x163] = iVar3;

  (**(code **)(*param_1 + 0xa8))(iVar3);

  (**(code **)(*(int *)param_1[0x163] + 0x28))("i_d_fes_2d_btn_delete.xml");

  (**(code **)(*(int *)param_1[0x163] + 0x74))(0x9c46);

  (**(code **)(*(int *)param_1[0x163] + 0xfc))(1,0x3f000000);

  pvVar2 = operator_new(0x4cc);

  iVar3 = 0;

  if (pvVar2 != (void *)0x0) {

    iVar3 = FUN_0079c860();

  }

  param_1[0x157] = iVar3;

  (**(code **)(*param_1 + 0xa8))(iVar3);

  (**(code **)(*(int *)param_1[0x157] + 0x28))("i_d_fes_2d_btn_back.xml");

  (**(code **)(*(int *)param_1[0x157] + 0x74))(0x9c41);

  (**(code **)(*(int *)param_1[0x157] + 0xfc))(1,0x3f000000);

  pvVar2 = operator_new(0x4cc);

  iVar3 = 0;

  if (pvVar2 != (void *)0x0) {

    iVar3 = FUN_0079c860();

  }

  param_1[0x158] = iVar3;

  (**(code **)(*param_1 + 0xa8))(iVar3);

  (**(code **)(*(int *)param_1[0x158] + 0x28))("i_d_fes_2d_btn_rotate_cw.xml");

  (**(code **)(*(int *)param_1[0x158] + 0x74))(0x9c43);

  pvVar2 = operator_new(0x4cc);

  iVar3 = 0;

  if (pvVar2 != (void *)0x0) {

    iVar3 = FUN_0079c860();

  }

  param_1[0x159] = iVar3;

  (**(code **)(*param_1 + 0xa8))(iVar3);

  (**(code **)(*(int *)param_1[0x159] + 0x28))("i_d_fes_2d_btn_rotate_ccw.xml");

  (**(code **)(*(int *)param_1[0x159] + 0x74))(0x9c44);

  iVar3 = param_1[0x1a] + 1;

  param_1[0x1a] = iVar3;

  param_1[0x1d] = (int)(float)-iVar3;

  if (param_1[0x1c] < iVar3) {

    param_1[0x1c] = iVar3;

  }

  (**(code **)(*param_1 + 0x3f4))(1);

  iVar3 = param_1[0x1a] + 1;

  param_1[0x1a] = iVar3;

  param_1[0x1d] = (int)(float)-iVar3;

  if (param_1[0x1c] < iVar3) {

    param_1[0x1c] = iVar3;

  }

  (**(code **)(*param_1 + 0x3f4))();

  pvVar2 = operator_new(0x4cc);

  iVar3 = 0;

  if (pvVar2 != (void *)0x0) {

    iVar3 = FUN_0079c860();

  }

  param_1[0x164] = iVar3;

  (**(code **)(*param_1 + 0xa8))(iVar3);

  (**(code **)(*(int *)param_1[0x164] + 0x28))("i_d_fes_2d_btn_play.xml");

  (**(code **)(*(int *)param_1[0x164] + 0x74))(0x9c45);

  (**(code **)(*(int *)param_1[0x164] + 0xfc))(1,0x3f000000);

  FUN_008cd200(param_1);

  piVar4 = &DAT_00d1b6dc;

  do {

    if (*piVar4 != 0) {

      bVar1 = 1;

      goto LAB_008ce406;

    }

    piVar4 = piVar4 + 1;

  } while ((int)piVar4 < 0xd1b70c);

  bVar1 = 0;

LAB_008ce406:

  param_1[0x127] = 0x9c41;

  param_1[0x126] = (-(uint)bVar1 & 5) + 40000;

  (**(code **)(*param_1 + 0x34c))();

  ExceptionList = (void *)0x1;

  return;

}
