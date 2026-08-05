// =============================================================================
// UI_itemsub_stats_enhancements
// -----------------------------------------------------------------------------
// Stable ID: aa_008445f0
// Address:   0x008445f0  (autoassault.exe, image base 0x400000)
// System:    unknown
// Generated: 2026-07-23 from raw capture (scaffold; refine for important units)
// Exactness: Behavior-preserving rewrite of decompiler control flow. Not modernization.
// Bit-for-bit vs retail EXE: DEFERRED (loaded image may differ slightly).
// =============================================================================

// PURPOSE (auto): Scaffold unit for UI_itemsub_stats_enhancements @ 0x008445f0
// Stable ID: aa_008445f0
// Embedded strings (evidence for future rename):
//   - "i_d_itemsub_2d_wnd_debug.xml"
//   - "i_d_itemsub_2d_wnd_frame.xml"
//   - "i_d_itemsub_2d_wnd_name.xml"
//   - "i_d_itemsub_2d_wnd_subtitle.xml"
//   - "i_d_itemsub_2d_wnd_stats.xml"
//   - "i_d_itemsub_2d_wnd_stats_enhancements.xml"
// Readability: control flow preserved from Ghidra decompile; types tentative.

// READABILITY (auto CF):
//  - Body size: ~131 non-empty decompiler lines.
//  - Control keywords: if×10, return×1.
//  - Notable callees: FUN_007b5dd0×8, FUN_00792600, UI_itemsub_stats_enhancements.
//  - Strings: "i_d_itemsub_2d_wnd_debug.xml"; "i_d_itemsub_2d_wnd_frame.xml"; "i_d_itemsub_2d_wnd_name.xml"; "i_d_itemsub_2d_wnd_subtitle.xml".
//  - Return sites: 1.

/*
 * Behavioral notes:
 * Plate-driven rename evidence: "i_d_itemsub_2d_wnd_stats_enhancements.xml"
 * Domain alias of FUN_008445f0 (FUN_* retained)
 *
 * - Derived from Ghidra decompile; names prefer Ghidra symbols / plate comments.
 * - Remaining FUN_* / DAT_* identifiers are unresolved pending type recovery.
 * - Runtime / differential verification: OPEN unless matrix says otherwise.
 *
 * Readability pass:
 * - undefinedN widths preserved as fixed-width integers where decompiler width is known.
 * - Control flow and call order preserved from authoritative raw.
 */

void __fastcall UI_itemsub_stats_enhancements(int *param_1)



{

  void *pvVar1;

  int iVar2;

  void *pvVar3;

  int iVar4;

  int iVar5;

  void *pvVar6;

  void *pvVar7;

  char *pcVar8;

  uint32_t /* width from decompiler */ uVar9;

  char *pcVar10;

  uint32_t /* width from decompiler */ uVar11;

  uint32_t /* width from decompiler */ uVar12;

  void *pvStack_c;

  uint8_t *puStack_8;

  uint32_t /* width from decompiler */ local_4;

  

  local_4 = 0xffffffff;

  puStack_8 = &LAB_009b3607;

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

  param_1[0x146] = iVar2;

  (**(code **)(*param_1 + 0xa8))(iVar2);

  (**(code **)(*(int *)param_1[0x146] + 0x28))("i_d_itemsub_2d_wnd_debug.xml");

  uVar12 = 0;

  (**(code **)(*(int *)param_1[0x146] + 0xcc))(0);

  iVar2 = param_1[0x1a] + 1;

  param_1[0x1a] = iVar2;

  param_1[0x1d] = (int)(float)-iVar2;

  if (param_1[0x1c] < iVar2) {

    param_1[0x1c] = iVar2;

  }

  uVar11 = 1;

  (**(code **)(*param_1 + 0x3f4))(1);

  pvVar1 = operator_new(0x488);

  if (pvVar1 == (void *)0x0) {

    iVar2 = 0;

  }

  else {

    iVar2 = FUN_007b5dd0(pvVar1,0);

  }

  param_1[0x13f] = iVar2;

  (**(code **)(*param_1 + 0xa8))(iVar2,uVar11,uVar12,pvVar1);

  pcVar10 = "i_d_itemsub_2d_wnd_frame.xml";

  (**(code **)(*(int *)param_1[0x13f] + 0x28))("i_d_itemsub_2d_wnd_frame.xml");

  iVar2 = param_1[0x1a] + 1;

  param_1[0x1a] = iVar2;

  param_1[0x1d] = (int)(float)-iVar2;

  if (param_1[0x1c] < iVar2) {

    param_1[0x1c] = iVar2;

  }

  uVar9 = 1;

  (**(code **)(*param_1 + 0x3f4))(1);

  pvVar1 = operator_new(0x488);

  if (pvVar1 == (void *)0x0) {

    iVar2 = 0;

  }

  else {

    iVar2 = FUN_007b5dd0(pvVar1,0);

  }

  param_1[0x140] = iVar2;

  (**(code **)(*param_1 + 0xa8))(iVar2,uVar9,pcVar10,pvVar1,uVar11,uVar12,0xffffffff);

  pcVar8 = "i_d_itemsub_2d_wnd_name.xml";

  (**(code **)(*(int *)param_1[0x140] + 0x28))("i_d_itemsub_2d_wnd_name.xml");

  pvVar3 = operator_new(0x488);

  if (pvVar3 == (void *)0x0) {

    iVar4 = 0;

  }

  else {

    iVar4 = FUN_007b5dd0(pvVar3,0);

  }

  param_1[0x141] = iVar4;

  (**(code **)(*param_1 + 0xa8))(iVar4,pcVar8,iVar2,pvVar3,pcVar10,pvVar1,0xffffffff);

  pcVar10 = "i_d_itemsub_2d_wnd_subtitle.xml";

  (**(code **)(*(int *)param_1[0x141] + 0x28))("i_d_itemsub_2d_wnd_subtitle.xml");

  pvVar1 = operator_new(0x488);

  if (pvVar1 == (void *)0x0) {

    iVar5 = 0;

  }

  else {

    iVar5 = FUN_007b5dd0(pvVar1,0);

  }

  param_1[0x142] = iVar5;

  (**(code **)(*param_1 + 0xa8))(iVar5,pcVar10,iVar4,pvVar1,iVar2,pvVar3,0xffffffff);

  pcVar10 = "i_d_itemsub_2d_wnd_stats.xml";

  (**(code **)(*(int *)param_1[0x142] + 0x28))("i_d_itemsub_2d_wnd_stats.xml");

  pvVar3 = operator_new(0x488);

  if (pvVar3 == (void *)0x0) {

    iVar2 = 0;

  }

  else {

    iVar2 = FUN_007b5dd0(pvVar3,0);

  }

  param_1[0x143] = iVar2;

  (**(code **)(*param_1 + 0xa8))(iVar2,pcVar10,iVar5,pvVar3,iVar4,pvVar1,0xffffffff);

  (**(code **)(*(int *)param_1[0x143] + 0x28))("i_d_itemsub_2d_wnd_stats_enhancements.xml");

  pvVar1 = operator_new(0x488);

  if (pvVar1 == (void *)0x0) {

    pvVar6 = (void *)0x0;

  }

  else {

    pvVar6 = (void *)FUN_007b5dd0(pvVar1,0);

  }

  uVar12 = 0xffffffff;

  param_1[0x144] = (int)pvVar6;

  (**(code **)(*param_1 + 0xa8))();

  pcVar10 = "i_d_itemsub_2d_wnd_requirements.xml";

  (**(code **)(*(int *)param_1[0x144] + 0x28))("i_d_itemsub_2d_wnd_requirements.xml");

  pvVar7 = operator_new(0x488);

  if (pvVar7 == (void *)0x0) {

    iVar4 = 0;

  }

  else {

    iVar4 = FUN_007b5dd0(pvVar7,0);

  }

  param_1[0x145] = iVar4;

  (**(code **)(*param_1 + 0xa8))(iVar4,pcVar10,pvVar6,pvVar7,iVar2,pvVar1,0xffffffff,pvVar3,uVar12);

  (**(code **)(*(int *)param_1[0x145] + 0x28))("i_d_itemsub_2d_wnd_value.xml");

  ExceptionList = pvVar6;

  return;

}
