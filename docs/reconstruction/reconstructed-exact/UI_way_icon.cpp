// =============================================================================
// UI_way_icon
// -----------------------------------------------------------------------------
// Stable ID: aa_0087d080
// Address:   0x0087d080  (autoassault.exe, image base 0x400000)
// System:    unknown
// Generated: 2026-07-23 from raw capture (scaffold; refine for important units)
// Exactness: Behavior-preserving rewrite of decompiler control flow. Not modernization.
// Bit-for-bit vs retail EXE: DEFERRED (loaded image may differ slightly).
// =============================================================================

// PURPOSE (auto): Scaffold unit for UI_way_icon @ 0x0087d080
// Stable ID: aa_0087d080
// Embedded strings (evidence for future rename):
//   - "i_d_way_wnd_icon.xml"
//   - "i_d_map_2d_icon_player.dds"
//   - "i_d_way_wnd_text.xml"
// Readability: control flow preserved from Ghidra decompile; types tentative.

// READABILITY (auto CF):
//  - Body size: ~62 non-empty decompiler lines.
//  - Control keywords: if×4, return×1.
//  - Notable callees: FUN_007b5dd0×2, FUN_00792600, FUN_00833010, UI_way_icon, FUN_0096f3e0, FUN_00989e00.
//  - Strings: "i_d_way_wnd_icon.xml"; "i_d_map_2d_icon_player.dds"; "i_d_way_wnd_text.xml".
//  - Return sites: 1.

/*
 * Behavioral notes:
 * Plate-driven rename evidence: "i_d_way_wnd_icon.xml"
 * Domain alias of FUN_0087d080 (FUN_* retained)
 *
 * - Derived from Ghidra decompile; names prefer Ghidra symbols / plate comments.
 * - Remaining FUN_* / DAT_* identifiers are unresolved pending type recovery.
 * - Runtime / differential verification: OPEN unless matrix says otherwise.
 *
 * Readability pass:
 * - undefinedN widths preserved as fixed-width integers where decompiler width is known.
 * - Control flow and call order preserved from authoritative raw.
 */

void __fastcall UI_way_icon(int *param_1)



{

  void *pvVar1;

  int iVar2;

  uint32_t /* width from decompiler */ *puVar3;

  void *pvVar4;

  char *pcVar5;

  void *pvStack_c;

  uint8_t *puStack_8;

  uint32_t /* width from decompiler */ local_4;

  

  local_4 = 0xffffffff;

  puStack_8 = &LAB_009b390e;

  pvStack_c = ExceptionList;

  ExceptionList = &pvStack_c;

  FUN_00792600();

  pvVar1 = operator_new(0x4a8);

  local_4 = 0;

  if (pvVar1 == (void *)0x0) {

    iVar2 = 0;

  }

  else {

    iVar2 = FUN_00833010();

  }

  local_4 = 0xffffffff;

  param_1[0x13f] = iVar2;

  (**(code **)(*param_1 + 0xa8))();

  (**(code **)(*(int *)param_1[0x13f] + 0x28))("i_d_way_wnd_icon.xml");

  (**(code **)(*(int *)param_1[0x13f] + 0xcc))(1);

  puVar3 = operator_new(4);

  if (puVar3 == (uint32_t /* width from decompiler */ *)0x0) {

    puVar3 = (uint32_t /* width from decompiler */ *)0x0;

  }

  else {

    *puVar3 = 0;

  }

  *(uint32_t /* width from decompiler */ **)(param_1[0x13f] + 0x488) = puVar3;

  FUN_00989e00(&stack0xffffffe4,"i_d_map_2d_icon_player.dds");

  FUN_0096f3e0(&stack0xffffffe4,0);

  pvVar1 = operator_new(0x488);

  if (pvVar1 == (void *)0x0) {

    pvVar1 = (void *)0x0;

  }

  else {

    pvVar1 = (void *)FUN_007b5dd0(pvVar1,0);

  }

  param_1[0x140] = (int)pvVar1;

  (**(code **)(*param_1 + 0xa8))();

  pcVar5 = "i_d_way_wnd_text.xml";

  (**(code **)(*(int *)param_1[0x140] + 0x28))("i_d_way_wnd_text.xml");

  pvVar4 = operator_new(0x488);

  if (pvVar4 == (void *)0x0) {

    iVar2 = 0;

  }

  else {

    iVar2 = FUN_007b5dd0(pvVar4,0);

  }

  param_1[0x141] = iVar2;

  (**(code **)(*param_1 + 0xa8))(iVar2,pcVar5,pvVar1,pvVar4);

  (**(code **)(*(int *)param_1[0x141] + 0x28))("i_d_way_wnd_text.xml");

  ExceptionList = pvVar1;

  return;

}
