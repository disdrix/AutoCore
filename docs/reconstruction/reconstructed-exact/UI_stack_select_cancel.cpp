// =============================================================================
// UI_stack_select_cancel
// -----------------------------------------------------------------------------
// Stable ID: aa_0083ddf0
// Address:   0x0083ddf0  (autoassault.exe, image base 0x400000)
// System:    unknown
// Generated: 2026-07-23 from raw capture (scaffold; refine for important units)
// Exactness: Behavior-preserving rewrite of decompiler control flow. Not modernization.
// Bit-for-bit vs retail EXE: DEFERRED (loaded image may differ slightly).
// =============================================================================

// PURPOSE (auto): Scaffold unit for UI_stack_select_cancel @ 0x0083ddf0
// Stable ID: aa_0083ddf0
// Embedded strings (evidence for future rename):
//   - "i_d_stack_select_2d_wnd_bg_texture.xml"
//   - "i_d_stack_select_2d_wnd_cancel.xml"
//   - "i_d_stack_select_2d_wnd_zero.xml"
//   - "i_d_stack_select_2d_wnd_one.xml"
//   - "i_d_stack_select_2d_wnd_two.xml"
//   - "i_d_stack_select_2d_wnd_three.xml"
// Readability: control flow preserved from Ghidra decompile; types tentative.

// READABILITY (auto CF):
//  - Body size: ~211 non-empty decompiler lines.
//  - Control keywords: if×18, return×1.
//  - Notable callees: FUN_0079c860×14, FUN_00792600, FUN_00795f20, FUN_007b5dd0, UI_stack_select_cancel.
//  - Strings: "i_d_stack_select_2d_wnd_bg_texture.xml"; "i_d_stack_select_2d_wnd_cancel.xml"; "i_d_stack_select_2d_wnd_zero.xml"; "i_d_stack_select_2d_wnd_one.xml".
//  - Return sites: 1.

/*
 * Behavioral notes:
 * Plate-driven rename evidence: "i_d_stack_select_2d_wnd_cancel.xml"
 * Domain alias of FUN_0083ddf0 (FUN_* retained)
 *
 * - Derived from Ghidra decompile; names prefer Ghidra symbols / plate comments.
 * - Remaining FUN_* / DAT_* identifiers are unresolved pending type recovery.
 * - Runtime / differential verification: OPEN unless matrix says otherwise.
 *
 * Readability pass:
 * - undefinedN widths preserved as fixed-width integers where decompiler width is known.
 * - Control flow and call order preserved from authoritative raw.
 */

void __fastcall UI_stack_select_cancel(int *param_1)



{

  void *pvVar1;

  int iVar2;

  int *piVar3;

  int *piVar4;

  void *pvStack_c;

  uint8_t *puStack_8;

  uint32_t /* width from decompiler */ local_4;

  

  local_4 = 0xffffffff;

  puStack_8 = &LAB_009b470a;

  pvStack_c = ExceptionList;

  ExceptionList = &pvStack_c;

  FUN_00792600();

  pvVar1 = operator_new(0x488);

  piVar3 = (int *)0x0;

  local_4 = 0;

  if (pvVar1 != (void *)0x0) {

    piVar3 = (int *)FUN_007b5dd0(pvVar1,0);

  }

  local_4 = 0xffffffff;

  (**(code **)(*param_1 + 0xa8))(piVar3);

  (**(code **)(*piVar3 + 0x28))("i_d_stack_select_2d_wnd_bg_texture.xml");

  iVar2 = param_1[0x1a] + 1;

  param_1[0x141] = (int)piVar3;

  param_1[0x1a] = iVar2;

  param_1[0x1d] = (int)(float)-iVar2;

  if (param_1[0x1c] < iVar2) {

    param_1[0x1c] = iVar2;

  }

  (**(code **)(*param_1 + 0x3f4))(1);

  pvVar1 = operator_new(0x4cc);

  if (pvVar1 == (void *)0x0) {

    piVar3 = (int *)0x0;

  }

  else {

    piVar3 = (int *)FUN_0079c860();

  }

  (**(code **)(*param_1 + 0xa8))(piVar3);

  (**(code **)(*piVar3 + 0x28))("i_d_stack_select_2d_wnd_cancel.xml");

  (**(code **)(*piVar3 + 0x74))(0x9c4f);

  param_1[0x145] = (int)piVar3;

  pvVar1 = operator_new(0x4cc);

  if (pvVar1 == (void *)0x0) {

    piVar3 = (int *)0x0;

  }

  else {

    piVar3 = (int *)FUN_0079c860();

  }

  (**(code **)(*param_1 + 0xa8))(piVar3);

  (**(code **)(*piVar3 + 0x28))("i_d_stack_select_2d_wnd_zero.xml");

  (**(code **)(*piVar3 + 0x74))(40000);

  param_1[0x146] = (int)piVar3;

  pvVar1 = operator_new(0x4cc);

  if (pvVar1 == (void *)0x0) {

    piVar3 = (int *)0x0;

  }

  else {

    piVar3 = (int *)FUN_0079c860();

  }

  (**(code **)(*param_1 + 0xa8))(piVar3);

  (**(code **)(*piVar3 + 0x28))("i_d_stack_select_2d_wnd_one.xml");

  (**(code **)(*piVar3 + 0x74))(0x9c41);

  param_1[0x147] = (int)piVar3;

  pvVar1 = operator_new(0x4cc);

  if (pvVar1 == (void *)0x0) {

    piVar3 = (int *)0x0;

  }

  else {

    piVar3 = (int *)FUN_0079c860();

  }

  (**(code **)(*param_1 + 0xa8))(piVar3);

  (**(code **)(*piVar3 + 0x28))("i_d_stack_select_2d_wnd_two.xml");

  (**(code **)(*piVar3 + 0x74))(0x9c42);

  param_1[0x148] = (int)piVar3;

  pvVar1 = operator_new(0x4cc);

  if (pvVar1 == (void *)0x0) {

    piVar3 = (int *)0x0;

  }

  else {

    piVar3 = (int *)FUN_0079c860();

  }

  (**(code **)(*param_1 + 0xa8))(piVar3);

  (**(code **)(*piVar3 + 0x28))("i_d_stack_select_2d_wnd_three.xml");

  (**(code **)(*piVar3 + 0x74))(0x9c43);

  param_1[0x149] = (int)piVar3;

  pvVar1 = operator_new(0x4cc);

  if (pvVar1 == (void *)0x0) {

    piVar3 = (int *)0x0;

  }

  else {

    piVar3 = (int *)FUN_0079c860();

  }

  (**(code **)(*param_1 + 0xa8))(piVar3);

  (**(code **)(*piVar3 + 0x28))("i_d_stack_select_2d_wnd_four.xml");

  (**(code **)(*piVar3 + 0x74))(0x9c44);

  param_1[0x14a] = (int)piVar3;

  pvVar1 = operator_new(0x4cc);

  if (pvVar1 == (void *)0x0) {

    piVar3 = (int *)0x0;

  }

  else {

    piVar3 = (int *)FUN_0079c860();

  }

  (**(code **)(*param_1 + 0xa8))(piVar3);

  (**(code **)(*piVar3 + 0x28))("i_d_stack_select_2d_wnd_five.xml");

  (**(code **)(*piVar3 + 0x74))(0x9c45);

  param_1[0x14b] = (int)piVar3;

  pvVar1 = operator_new(0x4cc);

  if (pvVar1 == (void *)0x0) {

    piVar3 = (int *)0x0;

  }

  else {

    piVar3 = (int *)FUN_0079c860();

  }

  (**(code **)(*param_1 + 0xa8))(piVar3);

  (**(code **)(*piVar3 + 0x28))("i_d_stack_select_2d_wnd_six.xml");

  (**(code **)(*piVar3 + 0x74))(0x9c46);

  param_1[0x14c] = (int)piVar3;

  pvVar1 = operator_new(0x4cc);

  if (pvVar1 == (void *)0x0) {

    piVar3 = (int *)0x0;

  }

  else {

    piVar3 = (int *)FUN_0079c860();

  }

  (**(code **)(*param_1 + 0xa8))(piVar3);

  (**(code **)(*piVar3 + 0x28))("i_d_stack_select_2d_wnd_seven.xml");

  (**(code **)(*piVar3 + 0x74))(0x9c47);

  param_1[0x14d] = (int)piVar3;

  pvVar1 = operator_new(0x4cc);

  if (pvVar1 == (void *)0x0) {

    piVar3 = (int *)0x0;

  }

  else {

    piVar3 = (int *)FUN_0079c860();

  }

  (**(code **)(*param_1 + 0xa8))(piVar3);

  (**(code **)(*piVar3 + 0x28))("i_d_stack_select_2d_wnd_eight.xml");

  (**(code **)(*piVar3 + 0x74))(0x9c48);

  param_1[0x14e] = (int)piVar3;

  pvVar1 = operator_new(0x4cc);

  if (pvVar1 == (void *)0x0) {

    piVar3 = (int *)0x0;

  }

  else {

    piVar3 = (int *)FUN_0079c860();

  }

  (**(code **)(*param_1 + 0xa8))(piVar3);

  (**(code **)(*piVar3 + 0x28))("i_d_stack_select_2d_wnd_nine.xml");

  (**(code **)(*piVar3 + 0x74))(0x9c49);

  param_1[0x14f] = (int)piVar3;

  pvVar1 = operator_new(0x4cc);

  if (pvVar1 == (void *)0x0) {

    piVar3 = (int *)0x0;

  }

  else {

    piVar3 = (int *)FUN_0079c860();

  }

  (**(code **)(*param_1 + 0xa8))(piVar3);

  (**(code **)(*piVar3 + 0x28))("i_d_stack_select_2d_wnd_minus.xml");

  (**(code **)(*piVar3 + 0x74))(0x9c4b);

  param_1[0x151] = (int)piVar3;

  pvVar1 = operator_new(0x4cc);

  if (pvVar1 == (void *)0x0) {

    piVar3 = (int *)0x0;

  }

  else {

    piVar3 = (int *)FUN_0079c860();

  }

  (**(code **)(*param_1 + 0xa8))(piVar3);

  (**(code **)(*piVar3 + 0x28))("i_d_stack_select_2d_wnd_ok.xml");

  (**(code **)(*piVar3 + 0x74))(0x9c4c);

  param_1[0x153] = (int)piVar3;

  pvVar1 = operator_new(0x4cc);

  if (pvVar1 == (void *)0x0) {

    piVar3 = (int *)0x0;

  }

  else {

    piVar3 = (int *)FUN_0079c860();

  }

  (**(code **)(*param_1 + 0xa8))(piVar3);

  (**(code **)(*piVar3 + 0x28))("i_d_stack_select_2d_wnd_reset.xml");

  (**(code **)(*piVar3 + 0x74))(0x9c4d);

  iVar2 = param_1[0x1a] + 1;

  param_1[0x152] = (int)piVar3;

  param_1[0x1a] = iVar2;

  param_1[0x1d] = (int)(float)-iVar2;

  if (param_1[0x1c] < iVar2) {

    param_1[0x1c] = iVar2;

  }

  (**(code **)(*param_1 + 0x3f4))(1);

  pvVar1 = operator_new(0x4a4);

  if (pvVar1 == (void *)0x0) {

    piVar3 = (int *)0x0;

  }

  else {

    piVar3 = (int *)FUN_00795f20();

  }

  piVar4 = piVar3;

  (**(code **)(*param_1 + 0xa8))();

  (**(code **)(*piVar3 + 0x28))("i_d_stack_select_2d_wnd_count.xml");

  (**(code **)(*piVar3 + 0x74))(0x9c4e);

  (**(code **)(*piVar3 + 0x98))(0);

  (**(code **)(*piVar3 + 0x1d0))(5);

  *(uint8_t *)((int)piVar3 + 0x48b) = 1;

  param_1[0x144] = (int)piVar3;

  (**(code **)(*param_1 + 0x34c))();

  ExceptionList = piVar4;

  return;

}
