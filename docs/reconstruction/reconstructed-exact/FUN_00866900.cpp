// =============================================================================
// FUN_00866900
// -----------------------------------------------------------------------------
// Stable ID: aa_00866900
// Address:   0x00866900  (autoassault.exe, image base 0x400000)
// System:    unknown
// Generated: 2026-07-23 from raw capture (scaffold; refine for important units)
// Exactness: Behavior-preserving rewrite of decompiler control flow. Not modernization.
// Bit-for-bit vs retail EXE: DEFERRED (loaded image may differ slightly).
// =============================================================================

// PURPOSE (auto): Scaffold unit for FUN_00866900 @ 0x00866900
// Stable ID: aa_00866900
// Embedded strings (evidence for future rename):
//   - "i_w_say_2d_wnd_bg_texture.xml"
//   - "i_w_say_2d_edt_recipient.xml"
//   - "i_w_say_2d_edt_msg.xml"
//   - "i_w_say_2d_btn_ok.xml"
//   - "i_w_say_2d_btn_cancel.xml"
//   - "i_w_say_2d_btn_options.xml"
// Readability: control flow preserved from Ghidra decompile; types tentative.

// READABILITY (auto CF):
//  - Body size: ~113 non-empty decompiler lines.
//  - Control keywords: if×10, return×1.
//  - Notable callees: FUN_0079c860×3, FUN_00795f20×2, FUN_00792600, FUN_007b5dd0, FUN_00866900.
//  - Strings: "i_w_say_2d_wnd_bg_texture.xml"; "i_w_say_2d_edt_recipient.xml"; "i_w_say_2d_edt_msg.xml"; "i_w_say_2d_btn_ok.xml".
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

void __fastcall FUN_00866900(int *param_1)



{

  void *pvVar1;

  int iVar2;

  int *piVar3;

  void *pvStack_c;

  uint8_t *puStack_8;

  uint32_t /* width from decompiler */ local_4;

  

  local_4 = 0xffffffff;

  puStack_8 = &LAB_009b4b26;

  pvStack_c = ExceptionList;

  ExceptionList = &pvStack_c;

  FUN_00792600();

  if ((param_1[0x144] == 1) || (param_1[0x144] == 0)) {

    param_1[0x144] = 10;

  }

  pvVar1 = operator_new(0x488);

  piVar3 = (int *)0x0;

  local_4 = 0;

  if (pvVar1 != (void *)0x0) {

    piVar3 = (int *)FUN_007b5dd0(pvVar1,0);

  }

  local_4 = 0xffffffff;

  (**(code **)(*param_1 + 0xa8))(piVar3);

  (**(code **)(*piVar3 + 0x28))("i_w_say_2d_wnd_bg_texture.xml");

  iVar2 = param_1[0x1a] + 1;

  param_1[0x68a9] = (int)piVar3;

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

  (**(code **)(*param_1 + 0xa8))(piVar3);

  (**(code **)(*piVar3 + 0x74))(0xc351);

  (**(code **)(*piVar3 + 0x28))("i_w_say_2d_edt_recipient.xml");

  (**(code **)(*piVar3 + 0x1d0))(0x10);

  (**(code **)(*piVar3 + 0x98))(0);

  *(uint8_t *)(piVar3 + 0x122) = 1;

  param_1[0x68ad] = (int)piVar3;

  pvVar1 = operator_new(0x4a4);

  if (pvVar1 == (void *)0x0) {

    piVar3 = (int *)0x0;

  }

  else {

    piVar3 = (int *)FUN_00795f20();

  }

  (**(code **)(*param_1 + 0xa8))(piVar3);

  (**(code **)(*piVar3 + 0x74))(50000);

  (**(code **)(*piVar3 + 0x28))("i_w_say_2d_edt_msg.xml");

  (**(code **)(*piVar3 + 0x1d0))(0xff);

  (**(code **)(*piVar3 + 0x98))(1);

  *(uint8_t *)(piVar3 + 0x122) = 1;

  iVar2 = param_1[0x1a] + 1;

  param_1[0x68ae] = (int)piVar3;

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

  (**(code **)(*piVar3 + 0x74))(0xc352);

  (**(code **)(*piVar3 + 0x28))("i_w_say_2d_btn_ok.xml");

  param_1[0x68aa] = (int)piVar3;

  pvVar1 = operator_new(0x4cc);

  if (pvVar1 == (void *)0x0) {

    piVar3 = (int *)0x0;

  }

  else {

    piVar3 = (int *)FUN_0079c860();

  }

  (**(code **)(*param_1 + 0xa8))(piVar3);

  (**(code **)(*piVar3 + 0x74))();

  (**(code **)(*piVar3 + 0x28))("i_w_say_2d_btn_cancel.xml");

  param_1[0x68ab] = (int)piVar3;

  pvVar1 = operator_new(0x4cc);

  if (pvVar1 == (void *)0x0) {

    piVar3 = (int *)0x0;

  }

  else {

    piVar3 = (int *)FUN_0079c860();

  }

  (**(code **)(*param_1 + 0xa8))(piVar3);

  (**(code **)(*piVar3 + 0x74))(0xc35e);

  (**(code **)(*piVar3 + 0x28))("i_w_say_2d_btn_options.xml");

  param_1[0x1a] = param_1[0x1a] + 1;

  iVar2 = param_1[0x1a];

  param_1[0x68ac] = (int)piVar3;

  param_1[0x1d] = (int)(float)-iVar2;

  if (param_1[0x1c] < iVar2) {

    param_1[0x1c] = iVar2;

  }

  (**(code **)(*param_1 + 0x3f4))(1);

  (**(code **)(*param_1 + 0x444))();

  (**(code **)(*param_1 + 0x34c))();

  ExceptionList = (void *)0xc353;

  return;

}
