// =============================================================================
// FUN_008eaf00
// -----------------------------------------------------------------------------
// Stable ID: aa_008eaf00
// Address:   0x008eaf00  (autoassault.exe, image base 0x400000)
// System:    unknown
// Generated: 2026-07-23 from raw capture (scaffold; refine for important units)
// Exactness: Behavior-preserving rewrite of decompiler control flow. Not modernization.
// Bit-for-bit vs retail EXE: DEFERRED (loaded image may differ slightly).
// =============================================================================

// PURPOSE (auto): Scaffold unit for FUN_008eaf00 @ 0x008eaf00
// Stable ID: aa_008eaf00
// Embedded strings (evidence for future rename):
//   - "i_d_con_2d_wnd_reveal_frame.xml"
//   - "i_d_con_2d_wnd_bg_texture.xml"
//   - "i_d_con_2d_wnd_lfg_frame.xml"
//   - "i_d_con_2d_btn_lfg.xml"
//   - "i_d_con_2d_btn_options.xml"
// Readability: control flow preserved from Ghidra decompile; types tentative.

// READABILITY (auto CF):
//  - Body size: ~119 non-empty decompiler lines.
//  - Control keywords: if×11, return×1.
//  - Notable callees: FUN_007b5dd0×3, FUN_0079c860×2, FUN_00792600, FUN_008e88f0, FUN_008e9df0, FUN_008ea880, FUN_008eaf00.
//  - Strings: "i_d_con_2d_wnd_reveal_frame.xml"; "i_d_con_2d_wnd_bg_texture.xml"; "i_d_con_2d_wnd_lfg_frame.xml"; "i_d_con_2d_btn_lfg.xml".
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

void __fastcall FUN_008eaf00(int *param_1)



{

  void *pvVar1;

  int iVar2;

  int *piVar3;

  int *piVar4;

  void *pvStack_c;

  uint8_t *puStack_8;

  uint32_t /* width from decompiler */ local_4;

  

  local_4 = 0xffffffff;

  puStack_8 = &LAB_009ba6c4;

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

  (**(code **)(*piVar3 + 0x28))("i_d_con_2d_wnd_reveal_frame.xml");

  (**(code **)(*piVar3 + 0x74))(0x9c51);

  (**(code **)(*piVar3 + 0xfc))(1,0x3f000000);

  iVar2 = param_1[0x1a] + 1;

  param_1[0x16b] = (int)piVar3;

  param_1[0x1a] = iVar2;

  param_1[0x1d] = (int)(float)-iVar2;

  if (param_1[0x1c] < iVar2) {

    param_1[0x1c] = iVar2;

  }

  (**(code **)(*param_1 + 0x3f4))(1);

  FUN_008e9df0();

  iVar2 = param_1[0x1a] + 1;

  param_1[0x1a] = iVar2;

  param_1[0x1d] = (int)(float)-iVar2;

  if (param_1[0x1c] < iVar2) {

    param_1[0x1c] = iVar2;

  }

  (**(code **)(*param_1 + 0x3f4))(1);

  pvVar1 = operator_new(0x488);

  if (pvVar1 == (void *)0x0) {

    piVar3 = (int *)0x0;

  }

  else {

    piVar3 = (int *)FUN_007b5dd0(pvVar1,0);

  }

  (**(code **)(*param_1 + 0xa8))(piVar3);

  (**(code **)(*piVar3 + 0x28))("i_d_con_2d_wnd_bg_texture.xml");

  (**(code **)(*piVar3 + 0xcc))(0);

  iVar2 = param_1[0x1a] + 1;

  param_1[0x16a] = (int)piVar3;

  param_1[0x1a] = iVar2;

  param_1[0x1d] = (int)(float)-iVar2;

  if (param_1[0x1c] < iVar2) {

    param_1[0x1c] = iVar2;

  }

  (**(code **)(*param_1 + 0x3f4))(1);

  pvVar1 = operator_new(0x488);

  if (pvVar1 == (void *)0x0) {

    piVar3 = (int *)0x0;

  }

  else {

    piVar3 = (int *)FUN_007b5dd0(pvVar1,0);

  }

  (**(code **)(*param_1 + 0xa8))(piVar3);

  (**(code **)(*piVar3 + 0x28))("i_d_con_2d_wnd_lfg_frame.xml");

  (**(code **)(*piVar3 + 0xfc))(1,0x3f000000);

  param_1[0x16c] = (int)piVar3;

  pvVar1 = operator_new(0x4cc);

  if (pvVar1 == (void *)0x0) {

    piVar3 = (int *)0x0;

  }

  else {

    piVar3 = (int *)FUN_0079c860();

  }

  (**(code **)(*param_1 + 0xa8))(piVar3);

  (**(code **)(*piVar3 + 0x28))("i_d_con_2d_btn_lfg.xml");

  (**(code **)(*piVar3 + 0x74))(0x9c50);

  (**(code **)(*piVar3 + 0x3b4))(1);

  (**(code **)(*piVar3 + 0x3c8))(DAT_00d1775e,1);

  (**(code **)(*piVar3 + 0xfc))(1,0x3f000000);

  iVar2 = param_1[0x1a] + 1;

  param_1[0x16d] = (int)piVar3;

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

  piVar4 = piVar3;

  (**(code **)(*param_1 + 0xa8))();

  (**(code **)(*piVar3 + 0x28))("i_d_con_2d_btn_options.xml");

  (**(code **)(*piVar3 + 0x74))(0x9c41);

  (**(code **)(*piVar3 + 0xcc))(0);

  param_1[0x1a] = param_1[0x1a] + 1;

  iVar2 = param_1[0x1a];

  param_1[0x142] = (int)piVar3;

  param_1[0x1d] = (int)(float)-iVar2;

  if (param_1[0x1c] < iVar2) {

    param_1[0x1c] = iVar2;

  }

  (**(code **)(*param_1 + 0x3f4))(1);

  FUN_008e88f0();

  if (((DAT_00d1b780 != (int *)0x0) && (*DAT_00d1b780 == DAT_00d1b778)) && (DAT_00d1b6d8 != 0)) {

    FUN_008ea880();

  }

  (**(code **)(*param_1 + 0x34c))();

  ExceptionList = piVar4;

  return;

}
