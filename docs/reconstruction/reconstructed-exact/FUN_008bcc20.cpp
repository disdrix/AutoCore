// =============================================================================
// FUN_008bcc20
// -----------------------------------------------------------------------------
// Stable ID: aa_008bcc20
// Address:   0x008bcc20  (autoassault.exe, image base 0x400000)
// System:    unknown
// Generated: 2026-07-23 from raw capture (scaffold; refine for important units)
// Exactness: Behavior-preserving rewrite of decompiler control flow. Not modernization.
// Bit-for-bit vs retail EXE: DEFERRED (loaded image may differ slightly).
// =============================================================================

// PURPOSE (auto): Scaffold unit for FUN_008bcc20 @ 0x008bcc20
// Stable ID: aa_008bcc20
// Embedded strings (evidence for future rename):
//   - "i_d_kb_2d_gauge_bonus.xml"
//   - "i_d_kb_2d_wnd_frame.xml"
//   - "i_d_kb_2d_wnd_label_kill_bonus.xml"
//   - "i_d_kb_2d_wnd_xp_bonus.xml"
// Readability: control flow preserved from Ghidra decompile; types tentative.

// READABILITY (auto CF):
//  - Body size: ~76 non-empty decompiler lines.
//  - Control keywords: if×4, return×1.
//  - Notable callees: FUN_007b5dd0×3, FUN_00792600, FUN_008bc5c0, FUN_008bcc20, FUN_0097ffa0.
//  - Strings: "i_d_kb_2d_gauge_bonus.xml"; "i_d_kb_2d_wnd_frame.xml"; "i_d_kb_2d_wnd_label_kill_bonus.xml"; "i_d_kb_2d_wnd_xp_bonus.xml".
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

void __fastcall FUN_008bcc20(int *param_1)



{

  void *pvVar1;

  int iVar2;

  void *pvVar3;

  char *pcVar4;

  uint32_t /* width from decompiler */ uVar5;

  char *pcVar6;

  uint32_t /* width from decompiler */ uVar7;

  uint32_t /* width from decompiler */ uVar8;

  void *pvStack_c;

  uint8_t *puStack_8;

  uint32_t /* width from decompiler */ local_4;

  

  local_4 = 0xffffffff;

  puStack_8 = &LAB_009b680f;

  pvStack_c = ExceptionList;

  ExceptionList = &pvStack_c;

  FUN_00792600();

  pvVar1 = operator_new(0x4f8);

  local_4 = 0;

  if (pvVar1 == (void *)0x0) {

    iVar2 = 0;

  }

  else {

    iVar2 = FUN_0097ffa0(pvVar1);

  }

  local_4 = 0xffffffff;

  param_1[0x149] = iVar2;

  (**(code **)(*param_1 + 0xa8))(iVar2);

  (**(code **)(*(int *)param_1[0x149] + 0x28))("i_d_kb_2d_gauge_bonus.xml");

  uVar8 = 0;

  (**(code **)(*(int *)param_1[0x149] + 0x3b0))(0);

  uVar7 = 0;

  (**(code **)(*(int *)param_1[0x149] + 0xcc))(0);

  pvVar1 = operator_new(0x488);

  if (pvVar1 == (void *)0x0) {

    iVar2 = 0;

  }

  else {

    iVar2 = FUN_007b5dd0(pvVar1,0);

  }

  param_1[0x148] = iVar2;

  (**(code **)(*param_1 + 0xa8))(iVar2,uVar7,uVar8,pvVar1);

  pcVar6 = "i_d_kb_2d_wnd_frame.xml";

  (**(code **)(*(int *)param_1[0x148] + 0x28))("i_d_kb_2d_wnd_frame.xml");

  uVar5 = 0;

  (**(code **)(*(int *)param_1[0x148] + 0xcc))(0);

  pvVar1 = operator_new(0x488);

  if (pvVar1 == (void *)0x0) {

    iVar2 = 0;

  }

  else {

    iVar2 = FUN_007b5dd0(pvVar1,0);

  }

  param_1[0x146] = iVar2;

  (**(code **)(*param_1 + 0xa8))(iVar2,uVar5,pcVar6,pvVar1,uVar7,uVar8,0xffffffff);

  pcVar4 = "i_d_kb_2d_wnd_label_kill_bonus.xml";

  (**(code **)(*(int *)param_1[0x146] + 0x28))("i_d_kb_2d_wnd_label_kill_bonus.xml");

  pvVar3 = (void *)0x0;

  (**(code **)(*(int *)param_1[0x146] + 0xcc))();

  pvVar1 = operator_new(0x488);

  if (pvVar1 == (void *)0x0) {

    iVar2 = 0;

  }

  else {

    iVar2 = FUN_007b5dd0(pvVar1,0);

  }

  param_1[0x147] = iVar2;

  (**(code **)(*param_1 + 0xa8))(iVar2,pvVar3,pcVar4,pvVar1,uVar5,pcVar6,0xffffffff);

  (**(code **)(*(int *)param_1[0x147] + 0x28))("i_d_kb_2d_wnd_xp_bonus.xml");

  (**(code **)(*(int *)param_1[0x147] + 0xcc))(0);

  FUN_008bc5c0();

  (**(code **)(*param_1 + 0x34c))();

  ExceptionList = pvVar3;

  return;

}
