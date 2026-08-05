// =============================================================================
// UI_con_details_level_class
// -----------------------------------------------------------------------------
// Stable ID: aa_00865580
// Address:   0x00865580  (autoassault.exe, image base 0x400000)
// System:    unknown
// Generated: 2026-07-23 from raw capture (scaffold; refine for important units)
// Exactness: Behavior-preserving rewrite of decompiler control flow. Not modernization.
// Bit-for-bit vs retail EXE: DEFERRED (loaded image may differ slightly).
// =============================================================================

// PURPOSE (auto): Scaffold unit for UI_con_details_level_class @ 0x00865580
// Stable ID: aa_00865580
// Embedded strings (evidence for future rename):
//   - "i_d_con_2d_wnd_details_bg.xml"
//   - "i_d_con_2d_wnd_details_name.xml"
//   - "i_d_con_2d_wnd_details_level_class.xml"
//   - "i_d_con_2d_wnd_details_hp.xml"
//   - "i_d_con_2d_wnd_details_pp.xml"
//   - "i_d_con_2d_wnd_details_shields.xml"
// Readability: control flow preserved from Ghidra decompile; types tentative.

// READABILITY (auto CF):
//  - Body size: ~112 non-empty decompiler lines.
//  - Control keywords: if×8, return×1.
//  - Notable callees: FUN_007b5dd0×6, FUN_00792600, UI_con_details_level_class.
//  - Strings: "i_d_con_2d_wnd_details_bg.xml"; "i_d_con_2d_wnd_details_name.xml"; "i_d_con_2d_wnd_details_level_class.xml"; "i_d_con_2d_wnd_details_hp.xml".
//  - Return sites: 1.

/*
 * Behavioral notes:
 * Plate-driven rename evidence: "i_d_con_2d_wnd_details_level_class.xml"
 * Domain alias of FUN_00865580 (FUN_* retained)
 *
 * - Derived from Ghidra decompile; names prefer Ghidra symbols / plate comments.
 * - Remaining FUN_* / DAT_* identifiers are unresolved pending type recovery.
 * - Runtime / differential verification: OPEN unless matrix says otherwise.
 *
 * Readability pass:
 * - undefinedN widths preserved as fixed-width integers where decompiler width is known.
 * - Control flow and call order preserved from authoritative raw.
 */

void __fastcall UI_con_details_level_class(int *param_1)



{

  int *piVar1;

  uint32_t /* width from decompiler */ uVar2;

  int iVar3;

  void *pvVar4;

  char *pcVar5;

  char *pcStack_28;

  int *piStack_24;

  void *pvStack_c;

  uint8_t *puStack_8;

  uint32_t /* width from decompiler */ local_4;

  

  local_4 = 0xffffffff;

  puStack_8 = &LAB_009b38ad;

  pvStack_c = ExceptionList;

  ExceptionList = &pvStack_c;

  FUN_00792600();

  piStack_24 = (int *)0x8655ab;

  piStack_24 = operator_new(0x488);

  local_4 = 0;

  if (piStack_24 == (void *)0x0) {

    piVar1 = (int *)0x0;

  }

  else {

    pcStack_28 = (char *)0x8655c6;

    piVar1 = (int *)FUN_007b5dd0();

  }

  local_4 = 0xffffffff;

  pcStack_28 = (char *)0x8655e0;

  piStack_24 = piVar1;

  (**(code **)(*param_1 + 0xa8))();

  pcStack_28 = "i_d_con_2d_wnd_details_bg.xml";

  (**(code **)(*piVar1 + 0x28))();

  iVar3 = *piVar1;

  uVar2 = (**(code **)(*param_1 + 0x140))(&stack0xffffffe4,1);

  (**(code **)(iVar3 + 0x138))(uVar2);

  pcStack_28 = (char *)0x0;

  piStack_24 = (int *)0x0;

  (**(code **)(*piVar1 + 0x118))(&pcStack_28);

  iVar3 = param_1[0x1a] + 1;

  param_1[0x142] = (int)piVar1;

  param_1[0x1a] = iVar3;

  param_1[0x1d] = (int)(float)-iVar3;

  if (param_1[0x1c] < iVar3) {

    param_1[0x1c] = iVar3;

  }

  (**(code **)(*param_1 + 0x3f4))(1);

  pvVar4 = operator_new(0x488);

  if (pvVar4 == (void *)0x0) {

    piVar1 = (int *)0x0;

  }

  else {

    piVar1 = (int *)FUN_007b5dd0(pvVar4,0);

  }

  (**(code **)(*param_1 + 0xa8))(piVar1);

  (**(code **)(*piVar1 + 0x28))("i_d_con_2d_wnd_details_name.xml");

  param_1[0x143] = (int)piVar1;

  pvVar4 = operator_new(0x488);

  pcStack_28 = (char *)0x2;

  if (pvVar4 == (void *)0x0) {

    piVar1 = (int *)0x0;

  }

  else {

    piVar1 = (int *)FUN_007b5dd0(pvVar4,0);

  }

  pcStack_28 = (char *)0xffffffff;

  (**(code **)(*param_1 + 0xa8))(piVar1);

  (**(code **)(*piVar1 + 0x28))("i_d_con_2d_wnd_details_level_class.xml");

  param_1[0x144] = (int)piVar1;

  pvVar4 = operator_new(0x488);

  if (pvVar4 == (void *)0x0) {

    piVar1 = (int *)0x0;

  }

  else {

    piVar1 = (int *)FUN_007b5dd0(pvVar4,0);

  }

  (**(code **)(*param_1 + 0xa8))(piVar1);

  pcVar5 = "i_d_con_2d_wnd_details_hp.xml";

  (**(code **)(*piVar1 + 0x28))();

  param_1[0x145] = (int)piVar1;

  pvVar4 = operator_new(0x488);

  if (pvVar4 == (void *)0x0) {

    piVar1 = (int *)0x0;

  }

  else {

    piVar1 = (int *)FUN_007b5dd0(pvVar4,0);

  }

  (**(code **)(*param_1 + 0xa8))(piVar1);

  (**(code **)(*piVar1 + 0x28))("i_d_con_2d_wnd_details_pp.xml");

  param_1[0x146] = (int)piVar1;

  pvVar4 = operator_new(0x488);

  if (pvVar4 == (void *)0x0) {

    piVar1 = (int *)0x0;

  }

  else {

    piVar1 = (int *)FUN_007b5dd0(pvVar4,0);

  }

  (**(code **)(*param_1 + 0xa8))(piVar1);

  (**(code **)(*piVar1 + 0x28))("i_d_con_2d_wnd_details_shields.xml");

  param_1[0x1a] = param_1[0x1a] + 1;

  iVar3 = param_1[0x1a];

  param_1[0x147] = (int)piVar1;

  param_1[0x1d] = (int)(float)-iVar3;

  if (param_1[0x1c] < iVar3) {

    param_1[0x1c] = iVar3;

  }

  (**(code **)(*param_1 + 0x3f4))(1);

  (**(code **)(*param_1 + 0x444))();

  (**(code **)(*param_1 + 0x34c))();

  ExceptionList = pcVar5;

  return;

}
