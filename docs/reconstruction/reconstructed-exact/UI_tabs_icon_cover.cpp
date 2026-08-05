// =============================================================================
// UI_tabs_icon_cover
// -----------------------------------------------------------------------------
// Stable ID: aa_008885d0
// Address:   0x008885d0  (autoassault.exe, image base 0x400000)
// System:    unknown
// Generated: 2026-07-23 from raw capture (scaffold; refine for important units)
// Exactness: Behavior-preserving rewrite of decompiler control flow. Not modernization.
// Bit-for-bit vs retail EXE: DEFERRED (loaded image may differ slightly).
// =============================================================================

// PURPOSE (auto): Scaffold unit for UI_tabs_icon_cover @ 0x008885d0
// Stable ID: aa_008885d0
// Embedded strings (evidence for future rename):
//   - "i_d_tabs_s_2d_wnd_bg_texture.xml"
//   - "i_d_tabs_s_2d_wnd_icon.xml"
//   - "i_d_tabs_s_2d_wnd_icon_cover.xml"
//   - "i_d_tabs_s_2d_btn_close.xml"
// Readability: control flow preserved from Ghidra decompile; types tentative.

// READABILITY (auto CF):
//  - Body size: ~76 non-empty decompiler lines.
//  - Control keywords: if×5, return×1.
//  - Notable callees: FUN_007b5dd0×3, FUN_00792600, FUN_0079c860, FUN_00864f20, FUN_008882d0, UI_tabs_icon_cover.
//  - Strings: "i_d_tabs_s_2d_wnd_bg_texture.xml"; "i_d_tabs_s_2d_wnd_icon.xml"; "i_d_tabs_s_2d_wnd_icon_cover.xml"; "i_d_tabs_s_2d_btn_close.xml".
//  - Return sites: 1.

/*
 * Behavioral notes:
 * Plate-driven rename evidence: "i_d_tabs_s_2d_wnd_icon_cover.xml"
 * Domain alias of FUN_008885d0 (FUN_* retained)
 *
 * - Derived from Ghidra decompile; names prefer Ghidra symbols / plate comments.
 * - Remaining FUN_* / DAT_* identifiers are unresolved pending type recovery.
 * - Runtime / differential verification: OPEN unless matrix says otherwise.
 *
 * Readability pass:
 * - undefinedN widths preserved as fixed-width integers where decompiler width is known.
 * - Control flow and call order preserved from authoritative raw.
 */

void __fastcall UI_tabs_icon_cover(int *param_1)



{

  void *pvVar1;

  int iVar2;

  void *pvVar3;

  void *pvStack_c;

  uint8_t *puStack_8;

  uint32_t /* width from decompiler */ local_4;

  

  local_4 = 0xffffffff;

  puStack_8 = &LAB_009b57e5;

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

  param_1[0x148] = iVar2;

  (**(code **)(*param_1 + 0xa8))();

  (**(code **)(*(int *)param_1[0x148] + 0x28))();

  pvVar1 = operator_new(0x4bc);

  pvStack_c = (void *)0x1;

  if (pvVar1 == (void *)0x0) {

    iVar2 = 0;

  }

  else {

    iVar2 = FUN_00864f20();

  }

  pvStack_c = (void *)0xffffffff;

  param_1[0x149] = iVar2;

  (**(code **)(*param_1 + 0xa8))();

  (**(code **)(*(int *)param_1[0x149] + 0x28))();

  pvVar1 = operator_new(0x488);

  if (pvVar1 == (void *)0x0) {

    iVar2 = 0;

  }

  else {

    iVar2 = FUN_007b5dd0(pvVar1);

  }

  param_1[0x147] = iVar2;

  (**(code **)(*param_1 + 0xa8))();

  (**(code **)(*(int *)param_1[0x147] + 0x28))("i_d_tabs_s_2d_wnd_bg_texture.xml");

  pvVar1 = operator_new(0x488);

  if (pvVar1 == (void *)0x0) {

    iVar2 = 0;

  }

  else {

    iVar2 = FUN_007b5dd0(pvVar1,0);

  }

  param_1[0x14a] = iVar2;

  (**(code **)(*param_1 + 0xa8))(iVar2);

  (**(code **)(*(int *)param_1[0x14a] + 0x28))("i_d_tabs_s_2d_wnd_icon.xml");

  (**(code **)(*param_1 + 0x404))(&stack0xffffffcc,"i_d_tabs_s_2d_wnd_icon_cover.xml",0xffffffff);

  (**(code **)(*param_1 + 0xa8))(param_1[0x143]);

  pvVar1 = (void *)param_1[0x144];

  (**(code **)(*param_1 + 0xa8))();

  pvVar3 = operator_new(0x4cc);

  iVar2 = 0;

  if (pvVar3 != (void *)0x0) {

    iVar2 = FUN_0079c860();

  }

  param_1[0x141] = iVar2;

  (**(code **)(*param_1 + 0xa8))(iVar2);

  (**(code **)(*(int *)param_1[0x141] + 0x28))("i_d_tabs_s_2d_btn_close.xml");

  (**(code **)(*(int *)param_1[0x141] + 0x74))(40000);

  FUN_008882d0(1);

  (**(code **)(*param_1 + 0xfc))(1,0x3f000000);

  (**(code **)(*param_1 + 0x34c))();

  ExceptionList = pvVar1;

  return;

}
