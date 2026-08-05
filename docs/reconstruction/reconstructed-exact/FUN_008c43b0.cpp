// =============================================================================
// FUN_008c43b0
// -----------------------------------------------------------------------------
// Stable ID: aa_008c43b0
// Address:   0x008c43b0  (autoassault.exe, image base 0x400000)
// System:    unknown
// Generated: 2026-07-23 from raw capture (scaffold; refine for important units)
// Exactness: Behavior-preserving rewrite of decompiler control flow. Not modernization.
// Bit-for-bit vs retail EXE: DEFERRED (loaded image may differ slightly).
// =============================================================================

// PURPOSE (auto): Scaffold unit for FUN_008c43b0 @ 0x008c43b0
// Stable ID: aa_008c43b0
// Embedded strings (evidence for future rename):
//   - "i_d_help_2d_wnd_icon.xml"
//   - "i_d_help_2d_wnd_icon_cover.xml"
//   - "i_d_help_2d_wnd_title.xml"
//   - "i_d_help_2d_wnd_status.xml"
//   - "i_d_help_2d_btn_tips.xml"
//   - "i_d_help_2d_btn_close.xml"
// Readability: control flow preserved from Ghidra decompile; types tentative.

// READABILITY (auto CF):
//  - Body size: ~142 non-empty decompiler lines.
//  - Control keywords: if×12, return×1.
//  - Notable callees: FUN_007b5dd0×5, FUN_0079c860×2, FUN_00792600, FUN_00800e60, FUN_008c43b0.
//  - Strings: "i_d_help_2d_wnd_icon.xml"; "i_d_help_2d_wnd_icon_cover.xml"; "i_d_help_2d_wnd_title.xml"; "i_d_help_2d_wnd_status.xml".
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

void __fastcall FUN_008c43b0(int *param_1)



{

  void *pvVar1;

  int iVar2;

  int *piVar3;

  int *unaff_EBX;

  int *unaff_ESI;

  void *pvVar4;

  char *pcVar5;

  void *pvStack_c;

  uint8_t *puStack_8;

  uint32_t /* width from decompiler */ local_4;

  

  local_4 = 0xffffffff;

  puStack_8 = &LAB_009b9f29;

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

  (**(code **)(*param_1 + 0xa8))();

  (**(code **)(*unaff_EBX + 0x28))();

  (**(code **)(*unaff_ESI + 0xfc))();

  param_1[0x143] = iVar2;

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

  (**(code **)(*param_1 + 0xa8))();

  (**(code **)(iRam3f000000 + 0x28))();

  (**(code **)(iRam00000001 + 0xfc))();

  param_1[0x145] = iVar2;

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

  (**(code **)(*param_1 + 0xa8))();

  (**(code **)(iRam3f000000 + 0x28))("i_d_help_2d_wnd_icon.xml");

  (**(code **)(iRam00000001 + 0xfc))(1,0x3f000000);

  param_1[0x148] = iVar2;

  pcVar5 = "i_d_help_2d_wnd_icon_cover.xml";

  piVar3 = (int *)&stack0xffffffb4;

  (**(code **)(*param_1 + 0x404))(piVar3,"i_d_help_2d_wnd_icon_cover.xml",0xffffffff);

  iVar2 = param_1[0x1a] + 1;

  param_1[0x1a] = iVar2;

  param_1[0x1d] = (int)(float)-iVar2;

  if (param_1[0x1c] < iVar2) {

    param_1[0x1c] = iVar2;

  }

  (**(code **)(*param_1 + 0x3f4))(1);

  pvVar1 = operator_new(0x488);

  if (pvVar1 == (void *)0x0) {

    iVar2 = 0;

  }

  else {

    iVar2 = FUN_007b5dd0(pvVar1,0);

  }

  (**(code **)(*param_1 + 0xa8))();

  (**(code **)(*(int *)pcVar5 + 0x28))("i_d_help_2d_wnd_title.xml");

  (**(code **)(*piVar3 + 0xfc))();

  param_1[0x146] = iVar2;

  iVar2 = param_1[0x1a] + 1;

  param_1[0x1a] = iVar2;

  param_1[0x1d] = (int)(float)-iVar2;

  if (param_1[0x1c] < iVar2) {

    param_1[0x1c] = iVar2;

  }

  (**(code **)(*param_1 + 0x3f4))(1);

  pvVar1 = operator_new(0x488);

  if (pvVar1 == (void *)0x0) {

    iVar2 = 0;

  }

  else {

    iVar2 = FUN_007b5dd0(pvVar1,0);

  }

  (**(code **)(*param_1 + 0xa8))();

  (**(code **)(iRam3f000000 + 0x28))("i_d_help_2d_wnd_status.xml");

  (**(code **)(iRam00000001 + 0xfc))(1,0x3f000000);

  param_1[0x147] = iVar2;

  iVar2 = param_1[0x1a] + 1;

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

  (**(code **)(*piVar3 + 0x28))("i_d_help_2d_btn_tips.xml");

  (**(code **)(*piVar3 + 0x74))(0x9c41);

  pvVar4 = (void *)0x1;

  (**(code **)(*piVar3 + 0xfc))(1,0x3f000000);

  param_1[0x149] = (int)piVar3;

  pvVar1 = operator_new(0x4cc);

  if (pvVar1 == (void *)0x0) {

    piVar3 = (int *)0x0;

  }

  else {

    piVar3 = (int *)FUN_0079c860();

  }

  (**(code **)(*param_1 + 0xa8))(piVar3);

  (**(code **)(*piVar3 + 0x28))("i_d_help_2d_btn_close.xml");

  (**(code **)(*piVar3 + 0x74))(40000);

  (**(code **)(*piVar3 + 0xfc))(1,0x3f000000);

  param_1[0x141] = (int)piVar3;

  (**(code **)(*param_1 + 0x34c))();

  FUN_00800e60();

  ExceptionList = pvVar4;

  return;

}
