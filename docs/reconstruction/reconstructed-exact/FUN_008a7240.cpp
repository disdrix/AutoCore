// =============================================================================
// FUN_008a7240
// -----------------------------------------------------------------------------
// Stable ID: aa_008a7240
// Address:   0x008a7240  (autoassault.exe, image base 0x400000)
// System:    unknown
// Generated: 2026-07-23 from raw capture (scaffold; refine for important units)
// Exactness: Behavior-preserving rewrite of decompiler control flow. Not modernization.
// Bit-for-bit vs retail EXE: DEFERRED (loaded image may differ slightly).
// =============================================================================

// PURPOSE (auto): Scaffold unit for FUN_008a7240 @ 0x008a7240
// Stable ID: aa_008a7240
// Embedded strings (evidence for future rename):
//   - "i_d_pop_2d_wnd_blocker.xml"
//   - "i_d_pop_2d_wnd_bg_fill.xml"
//   - "i_d_pop_2d_wnd_bg_texture.xml"
//   - "i_d_pop_2d_wnd_bg_frame.xml"
//   - "i_d_pop_2d_wnd_message.xml"
//   - "i_d_pop_2d_btn_ok.xml"
// Readability: control flow preserved from Ghidra decompile; types tentative.

// READABILITY (auto CF):
//  - Body size: ~138 non-empty decompiler lines.
//  - Control keywords: if×13, return×1.
//  - Notable callees: FUN_007b5dd0×6, FUN_0079c860×2, FUN_00792600, FUN_00795f20, FUN_008a7240.
//  - Strings: "i_d_pop_2d_wnd_blocker.xml"; "i_d_pop_2d_wnd_bg_fill.xml"; "i_d_pop_2d_wnd_bg_texture.xml"; "i_d_pop_2d_wnd_bg_frame.xml".
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

void __fastcall FUN_008a7240(int *param_1)



{

  void *pvVar1;

  int *piVar2;

  int iVar3;

  void *pvStack_c;

  uint8_t *puStack_8;

  uint32_t /* width from decompiler */ local_4;

  

  local_4 = 0xffffffff;

  puStack_8 = &LAB_009b62df;

  pvStack_c = ExceptionList;

  ExceptionList = &pvStack_c;

  FUN_00792600();

  pvVar1 = operator_new(0x488);

  local_4 = 0;

  if (pvVar1 == (void *)0x0) {

    piVar2 = (int *)0x0;

  }

  else {

    piVar2 = (int *)FUN_007b5dd0(pvVar1,0);

  }

  local_4 = 0xffffffff;

  (**(code **)(*param_1 + 0xa8))(piVar2);

  (**(code **)(*piVar2 + 0x28))("i_d_pop_2d_wnd_blocker.xml");

  iVar3 = param_1[0x1a] + 1;

  param_1[0x14c] = (int)piVar2;

  param_1[0x1a] = iVar3;

  param_1[0x1d] = (int)(float)-iVar3;

  if (param_1[0x1c] < iVar3) {

    param_1[0x1c] = iVar3;

  }

  (**(code **)(*param_1 + 0x3f4))(1);

  pvVar1 = operator_new(0x488);

  if (pvVar1 == (void *)0x0) {

    piVar2 = (int *)0x0;

  }

  else {

    piVar2 = (int *)FUN_007b5dd0(pvVar1,0);

  }

  (**(code **)(*param_1 + 0xa8))(piVar2);

  (**(code **)(*piVar2 + 0x28))("i_d_pop_2d_wnd_bg_fill.xml");

  iVar3 = param_1[0x1a] + 1;

  param_1[0x14e] = (int)piVar2;

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

  (**(code **)(*param_1 + 0x3f4))(1);

  pvVar1 = operator_new(0x488);

  if (pvVar1 == (void *)0x0) {

    piVar2 = (int *)0x0;

  }

  else {

    piVar2 = (int *)FUN_007b5dd0(pvVar1,0);

  }

  (**(code **)(*param_1 + 0xa8))(piVar2);

  (**(code **)(*piVar2 + 0x28))("i_d_pop_2d_wnd_bg_texture.xml");

  param_1[0x14d] = (int)piVar2;

  pvVar1 = operator_new(0x488);

  if (pvVar1 == (void *)0x0) {

    piVar2 = (int *)0x0;

  }

  else {

    piVar2 = (int *)FUN_007b5dd0(pvVar1,0);

  }

  (**(code **)(*param_1 + 0xa8))(piVar2);

  (**(code **)(*piVar2 + 0x28))("i_d_pop_2d_wnd_bg_frame.xml");

  iVar3 = param_1[0x1a] + 1;

  param_1[0x150] = (int)piVar2;

  param_1[0x1a] = iVar3;

  param_1[0x1d] = (int)(float)-iVar3;

  if (param_1[0x1c] < iVar3) {

    param_1[0x1c] = iVar3;

  }

  (**(code **)(*param_1 + 0x3f4))(1);

  pvVar1 = operator_new(0x488);

  if (pvVar1 == (void *)0x0) {

    piVar2 = (int *)0x0;

  }

  else {

    piVar2 = (int *)FUN_007b5dd0(pvVar1,0);

  }

  (**(code **)(*param_1 + 0xa8))(piVar2);

  (**(code **)(*piVar2 + 0x28))("i_d_pop_2d_wnd_message.xml");

  param_1[0x151] = (int)piVar2;

  pvVar1 = operator_new(0x4cc);

  if (pvVar1 == (void *)0x0) {

    piVar2 = (int *)0x0;

  }

  else {

    piVar2 = (int *)FUN_0079c860();

  }

  (**(code **)(*param_1 + 0xa8))(piVar2);

  (**(code **)(*piVar2 + 0x28))("i_d_pop_2d_btn_ok.xml");

  param_1[0x154] = (int)piVar2;

  pvVar1 = operator_new(0x4cc);

  if (pvVar1 == (void *)0x0) {

    piVar2 = (int *)0x0;

  }

  else {

    piVar2 = (int *)FUN_0079c860();

  }

  (**(code **)(*param_1 + 0xa8))(piVar2);

  (**(code **)(*piVar2 + 0x28))("i_d_pop_2d_btn_cancel.xml");

  param_1[0x155] = (int)piVar2;

  pvVar1 = operator_new(0x488);

  if (pvVar1 == (void *)0x0) {

    piVar2 = (int *)0x0;

  }

  else {

    piVar2 = (int *)FUN_007b5dd0(pvVar1,0);

  }

  (**(code **)(*param_1 + 0xa8))(piVar2);

  (**(code **)(*piVar2 + 0x28))("i_d_pop_2d_wnd_edit_bg.xml");

  param_1[0x152] = (int)piVar2;

  (**(code **)(*piVar2 + 0xcc))();

  pvVar1 = operator_new(0x4a4);

  iVar3 = 0;

  if (pvVar1 != (void *)0x0) {

    iVar3 = FUN_00795f20();

  }

  param_1[0x153] = iVar3;

  (**(code **)(*param_1 + 0xa8))(iVar3);

  (**(code **)(*(int *)param_1[0x153] + 0x28))("i_d_pop_2d_wnd_edit.xml");

  (**(code **)(*(int *)param_1[0x153] + 0x1d0))(0x32);

  (**(code **)(*(int *)param_1[0x153] + 0xcc))(0);

  (**(code **)(*param_1 + 0x34c))();

  ExceptionList = (void *)0x0;

  return;

}
