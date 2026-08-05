// =============================================================================
// UI_tfield_text_field
// -----------------------------------------------------------------------------
// Stable ID: aa_008873c0
// Address:   0x008873c0  (autoassault.exe, image base 0x400000)
// System:    unknown
// Generated: 2026-07-23 from raw capture (scaffold; refine for important units)
// Exactness: Behavior-preserving rewrite of decompiler control flow. Not modernization.
// Bit-for-bit vs retail EXE: DEFERRED (loaded image may differ slightly).
// =============================================================================

// PURPOSE (auto): Scaffold unit for UI_tfield_text_field @ 0x008873c0
// Stable ID: aa_008873c0
// Embedded strings (evidence for future rename):
//   - "i_d_tfield_2d_wnd_bg_fill.xml"
//   - "i_d_tfield_2d_wnd_bg_texture.xml"
//   - "i_d_tfield_2d_wnd_text_field.xml"
//   - "i_d_tfield_2d_sb_text_field.xml"
//   - "i_d_tfield_2d_btn_close.xml"
// Readability: control flow preserved from Ghidra decompile; types tentative.

// READABILITY (auto CF):
//  - Body size: ~73 non-empty decompiler lines.
//  - Control keywords: if×5, return×1.
//  - Notable callees: FUN_007b5dd0×3, FUN_0078f890, FUN_00792600, FUN_0079c860, UI_tfield_text_field.
//  - Strings: "i_d_tfield_2d_wnd_bg_fill.xml"; "i_d_tfield_2d_wnd_bg_texture.xml"; "i_d_tfield_2d_wnd_text_field.xml"; "i_d_tfield_2d_sb_text_field.xml".
//  - Return sites: 1.

/*
 * Behavioral notes:
 * Plate-driven rename evidence: "i_d_tfield_2d_wnd_text_field.xml"
 * Domain alias of FUN_008873c0 (FUN_* retained)
 *
 * - Derived from Ghidra decompile; names prefer Ghidra symbols / plate comments.
 * - Remaining FUN_* / DAT_* identifiers are unresolved pending type recovery.
 * - Runtime / differential verification: OPEN unless matrix says otherwise.
 *
 * Readability pass:
 * - undefinedN widths preserved as fixed-width integers where decompiler width is known.
 * - Control flow and call order preserved from authoritative raw.
 */

void __fastcall UI_tfield_text_field(int *param_1)



{

  void *pvVar1;

  int iVar2;

  void *pvStack_c;

  uint8_t *puStack_8;

  uint32_t /* width from decompiler */ local_4;

  

  local_4 = 0xffffffff;

  puStack_8 = &LAB_009b933a;

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

  param_1[0x147] = iVar2;

  (**(code **)(*param_1 + 0xa8))(iVar2);

  (**(code **)(*(int *)param_1[0x147] + 0x28))("i_d_tfield_2d_wnd_bg_fill.xml");

  pvVar1 = operator_new(0x488);

  pvStack_c = (void *)0x1;

  if (pvVar1 == (void *)0x0) {

    iVar2 = 0;

  }

  else {

    iVar2 = FUN_007b5dd0(pvVar1,0);

  }

  pvStack_c = (void *)0xffffffff;

  param_1[0x148] = iVar2;

  (**(code **)(*param_1 + 0xa8))(iVar2);

  (**(code **)(*(int *)param_1[0x148] + 0x28))("i_d_tfield_2d_wnd_bg_texture.xml");

  pvVar1 = operator_new(0x488);

  if (pvVar1 == (void *)0x0) {

    iVar2 = 0;

  }

  else {

    iVar2 = FUN_007b5dd0(pvVar1,0);

  }

  param_1[0x149] = iVar2;

  (**(code **)(*param_1 + 0xa8))(iVar2);

  (**(code **)(*(int *)param_1[0x149] + 0x28))("i_d_tfield_2d_wnd_text_field.xml");

  pvVar1 = operator_new(0x954);

  if (pvVar1 == (void *)0x0) {

    iVar2 = 0;

  }

  else {

    iVar2 = FUN_0078f890();

  }

  param_1[0x14a] = iVar2;

  (**(code **)(*param_1 + 0xa8))(iVar2);

  (**(code **)(*(int *)param_1[0x14a] + 0x28))("i_d_tfield_2d_sb_text_field.xml");

  (**(code **)(*(int *)param_1[0x14a] + 0x43c))();

  (**(code **)(*(int *)param_1[0x14a] + 0x468))();

  (**(code **)(*(int *)param_1[0x14a] + 0x74))(0x9c41);

  pvVar1 = operator_new(0x4cc);

  iVar2 = 0;

  if (pvVar1 != (void *)0x0) {

    iVar2 = FUN_0079c860();

  }

  param_1[0x141] = iVar2;

  (**(code **)(*param_1 + 0xa8))(iVar2);

  (**(code **)(*(int *)param_1[0x141] + 0x28))("i_d_tfield_2d_btn_close.xml");

  (**(code **)(*(int *)param_1[0x141] + 0x74))(40000);

  (**(code **)(*param_1 + 0x448))();

  (**(code **)(*param_1 + 0x34c))();

  ExceptionList = (void *)0x1;

  return;

}
