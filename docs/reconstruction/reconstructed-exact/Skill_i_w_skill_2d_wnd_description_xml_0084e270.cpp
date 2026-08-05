// READABILITY (auto CF):
//  - Body size: ~79 non-empty decompiler lines.
//  - Control keywords: if×6, return×1.
//  - Notable callees: FUN_007b5dd0×5, FUN_00792600, FUN_0084e270.
//  - Strings: "i_w_skill_2d_wnd_frame.xml"; "i_w_skill_2d_wnd_name.xml"; "i_w_skill_2d_wnd_progress.xml"; "i_w_skill_2d_wnd_description.xml".
//  - Return sites: 1.

// =============================================================================
// Skill_i_w_skill_2d_wnd_description_xml_0084e270
// -----------------------------------------------------------------------------
// Stable ID: aa_0084e270
// Address:   0x0084e270  (autoassault.exe, image base 0x400000)
// System:    unknown
// Generated: 2026-07-23 from raw capture (scaffold; refine for important units)
// Exactness: Behavior-preserving rewrite of decompiler control flow. Not modernization.
// Bit-for-bit vs retail EXE: DEFERRED (loaded image may differ slightly).
// =============================================================================

/*
 * Behavioral notes:
 * String-driven rename evidence: "i_w_skill_2d_wnd_description.xml"
 *
 * - Derived from Ghidra decompile; names prefer Ghidra symbols / plate comments.
 * - Remaining FUN_* / DAT_* identifiers are unresolved pending type recovery.
 * - Runtime / differential verification: OPEN unless matrix says otherwise.
 *
 * Readability pass:
 * - undefinedN widths preserved as fixed-width integers where decompiler width is known.
 * - Control flow and call order preserved from authoritative raw.
 */

void __fastcall Skill_i_w_skill_2d_wnd_description_xml_0084e270(int *param_1)



{

  void *pvVar1;

  int *piVar2;

  int iVar3;

  char *pcVar4;

  void *pvStack_c;

  uint8_t *puStack_8;

  uint32_t /* width from decompiler */ local_4;

  

  local_4 = 0xffffffff;

  puStack_8 = &LAB_009b3648;

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

  (**(code **)(*piVar2 + 0x28))("i_w_skill_2d_wnd_frame.xml");

  iVar3 = param_1[0x1a] + 1;

  param_1[0x144] = (int)piVar2;

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

  (**(code **)(*piVar2 + 0x28))("i_w_skill_2d_wnd_name.xml");

  param_1[0x145] = (int)piVar2;

  pvVar1 = operator_new(0x488);

  if (pvVar1 == (void *)0x0) {

    piVar2 = (int *)0x0;

  }

  else {

    piVar2 = (int *)FUN_007b5dd0(pvVar1,0);

  }

  (**(code **)(*param_1 + 0xa8))(piVar2);

  pcVar4 = "i_w_skill_2d_wnd_progress.xml";

  (**(code **)(*piVar2 + 0x28))();

  param_1[0x146] = (int)piVar2;

  pvVar1 = operator_new(0x488);

  if (pvVar1 == (void *)0x0) {

    piVar2 = (int *)0x0;

  }

  else {

    piVar2 = (int *)FUN_007b5dd0(pvVar1,0);

  }

  (**(code **)(*param_1 + 0xa8))(piVar2);

  (**(code **)(*piVar2 + 0x28))("i_w_skill_2d_wnd_description.xml");

  param_1[0x147] = (int)piVar2;

  pvVar1 = operator_new(0x488);

  if (pvVar1 == (void *)0x0) {

    piVar2 = (int *)0x0;

  }

  else {

    piVar2 = (int *)FUN_007b5dd0(pvVar1,0);

  }

  (**(code **)(*param_1 + 0xa8))(piVar2);

  (**(code **)(*piVar2 + 0x28))("i_d_item_2d_wnd_stats_full.xml");

  param_1[0x148] = (int)piVar2;

  (**(code **)(*param_1 + 0x444))();

  (**(code **)(*param_1 + 0x34c))();

  ExceptionList = pcVar4;

  return;

}
