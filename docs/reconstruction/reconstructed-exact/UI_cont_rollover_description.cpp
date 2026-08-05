// =============================================================================
// UI_cont_rollover_description
// -----------------------------------------------------------------------------
// Stable ID: aa_008ef180
// Address:   0x008ef180  (autoassault.exe, image base 0x400000)
// System:    unknown
// Generated: 2026-07-23 from raw capture (scaffold; refine for important units)
// Exactness: Behavior-preserving rewrite of decompiler control flow. Not modernization.
// Bit-for-bit vs retail EXE: DEFERRED (loaded image may differ slightly).
// =============================================================================

// PURPOSE (auto): Scaffold unit for UI_cont_rollover_description @ 0x008ef180
// Stable ID: aa_008ef180
// Embedded strings (evidence for future rename):
//   - "i_d_cont_2d_wnd_rollover_bg_frame.xml"
//   - "i_d_cont_2d_wnd_rollover_name.xml"
//   - "i_d_cont_2d_wnd_rollover_description.xml"
// Readability: control flow preserved from Ghidra decompile; types tentative.

// READABILITY (auto CF):
//  - Body size: ~55 non-empty decompiler lines.
//  - Control keywords: if×3, return×1.
//  - Notable callees: FUN_007b5dd0×3, FUN_00792600, UI_cont_rollover_description.
//  - Strings: "i_d_cont_2d_wnd_rollover_bg_frame.xml"; "i_d_cont_2d_wnd_rollover_name.xml"; "i_d_cont_2d_wnd_rollover_description.xml".
//  - Return sites: 1.

/*
 * Behavioral notes:
 * Plate-driven rename evidence: "i_d_cont_2d_wnd_rollover_description.xml"
 * Domain alias of FUN_008ef180 (FUN_* retained)
 *
 * - Derived from Ghidra decompile; names prefer Ghidra symbols / plate comments.
 * - Remaining FUN_* / DAT_* identifiers are unresolved pending type recovery.
 * - Runtime / differential verification: OPEN unless matrix says otherwise.
 *
 * Readability pass:
 * - undefinedN widths preserved as fixed-width integers where decompiler width is known.
 * - Control flow and call order preserved from authoritative raw.
 */

void __fastcall UI_cont_rollover_description(int *param_1)



{

  void *pvVar1;

  int iVar2;

  void *pvVar3;

  char *pcVar4;

  char *pcVar5;

  void *pvStack_c;

  uint8_t *puStack_8;

  uint32_t /* width from decompiler */ local_4;

  

  local_4 = 0xffffffff;

  puStack_8 = &LAB_009b3a67;

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

  param_1[0x140] = iVar2;

  (**(code **)(*param_1 + 0xa8))(iVar2);

  pcVar5 = "i_d_cont_2d_wnd_rollover_bg_frame.xml";

  (**(code **)(*(int *)param_1[0x140] + 0x28))("i_d_cont_2d_wnd_rollover_bg_frame.xml");

  pvVar1 = operator_new(0x488);

  pvStack_c = (void *)0x1;

  if (pvVar1 == (void *)0x0) {

    iVar2 = 0;

  }

  else {

    iVar2 = FUN_007b5dd0(pvVar1,0);

  }

  pvStack_c = (void *)0xffffffff;

  param_1[0x141] = iVar2;

  (**(code **)(*param_1 + 0xa8))(iVar2,pcVar5,pvVar1);

  pcVar4 = "i_d_cont_2d_wnd_rollover_name.xml";

  (**(code **)(*(int *)param_1[0x141] + 0x28))();

  pvVar3 = operator_new(0x488);

  if (pvVar3 == (void *)0x0) {

    iVar2 = 0;

  }

  else {

    iVar2 = FUN_007b5dd0(pvVar3,0);

  }

  param_1[0x142] = iVar2;

  (**(code **)(*param_1 + 0xa8))(iVar2,pcVar4,pvVar3,pcVar5,pvVar1,0xffffffff);

  (**(code **)(*(int *)param_1[0x142] + 0x28))("i_d_cont_2d_wnd_rollover_description.xml");

  (**(code **)(*param_1 + 0x34c))();

  ExceptionList = pcVar4;

  return;

}
