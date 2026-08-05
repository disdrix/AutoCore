// =============================================================================
// FUN_008690f0
// -----------------------------------------------------------------------------
// Stable ID: aa_008690f0
// Address:   0x008690f0  (autoassault.exe, image base 0x400000)
// System:    unknown
// Generated: 2026-07-23 from raw capture (scaffold; refine for important units)
// Exactness: Behavior-preserving rewrite of decompiler control flow. Not modernization.
// Bit-for-bit vs retail EXE: DEFERRED (loaded image may differ slightly).
// =============================================================================

// PURPOSE (auto): Scaffold unit for FUN_008690f0 @ 0x008690f0
// Stable ID: aa_008690f0
// Embedded strings (evidence for future rename):
//   - "i_w_boss_2d_wnd_bg.xml"
//   - "i_w_boss_2d_wnd_gauge_hp.xml"
//   - "i_w_boss_2d_wnd_cover.xml"
//   - "i_w_boss_2d_wnd_frame.xml"
//   - "i_w_boss_2d_wnd_frame_clamp_left.xml"
//   - "i_w_boss_2d_wnd_frame_clamp_right.xml"
// Readability: control flow preserved from Ghidra decompile; types tentative.

// READABILITY (auto CF):
//  - Body size: ~115 non-empty decompiler lines.
//  - Control keywords: if×7, do×1, while×1, return×1.
//  - Notable callees: FUN_007b5dd0×6, FUN_00792600, FUN_008690f0, FUN_0097ffa0.
//  - Strings: "i_w_boss_2d_wnd_bg.xml"; "i_w_boss_2d_wnd_gauge_hp.xml"; "i_w_boss_2d_wnd_cover.xml"; "i_w_boss_2d_wnd_frame.xml".
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

void __fastcall FUN_008690f0(int *param_1)



{

  void *pvVar1;

  int iVar2;

  int iVar3;

  int *piVar4;

  char *pcVar5;

  void *pvStack_c;

  uint8_t *puStack_8;

  uint32_t /* width from decompiler */ local_4;

  

  local_4 = 0xffffffff;

  puStack_8 = &LAB_009b4bc5;

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

  param_1[0x141] = iVar2;

  (**(code **)(*param_1 + 0xa8))(iVar2);

  (**(code **)(*(int *)param_1[0x141] + 0x28))("i_w_boss_2d_wnd_bg.xml");

  (**(code **)(*(int *)param_1[0x141] + 0xfc))(1,0x3f8ccccd);

  pvVar1 = operator_new(0x4f8);

  if (pvVar1 == (void *)0x0) {

    iVar2 = 0;

  }

  else {

    iVar2 = FUN_0097ffa0(pvVar1);

  }

  param_1[0x13f] = iVar2;

  (**(code **)(*param_1 + 0xa8))(iVar2);

  (**(code **)(*(int *)param_1[0x13f] + 0x28))("i_w_boss_2d_wnd_gauge_hp.xml");

  (**(code **)(*(int *)param_1[0x13f] + 0x74))(40000);

  (**(code **)(*(int *)param_1[0x13f] + 0x3b0))(0x3f800000);

  (**(code **)(*(int *)param_1[0x13f] + 0xfc))(1,0x3f8ccccd);

  pvVar1 = operator_new(0x488);

  if (pvVar1 == (void *)0x0) {

    iVar2 = 0;

  }

  else {

    iVar2 = FUN_007b5dd0(pvVar1,0);

  }

  param_1[0x142] = iVar2;

  (**(code **)(*param_1 + 0xa8))(iVar2);

  (**(code **)(*(int *)param_1[0x142] + 0x28))("i_w_boss_2d_wnd_cover.xml");

  (**(code **)(*(int *)param_1[0x142] + 0xfc))(1,0x3f8ccccd);

  pvVar1 = operator_new(0x488);

  if (pvVar1 == (void *)0x0) {

    iVar2 = 0;

  }

  else {

    iVar2 = FUN_007b5dd0(pvVar1,0);

  }

  param_1[0x140] = iVar2;

  (**(code **)(*param_1 + 0xa8))(iVar2);

  (**(code **)(*(int *)param_1[0x140] + 0x28))("i_w_boss_2d_wnd_frame.xml");

  (**(code **)(*(int *)param_1[0x140] + 0xfc))(1,0x3f8ccccd);

  (**(code **)(*param_1 + 0x404))(param_1 + 0x144,"i_w_boss_2d_wnd_frame_clamp_left.xml",0xffffffff)

  ;

  (**(code **)(*(int *)param_1[0x144] + 0xcc))(0);

  (**(code **)(*param_1 + 0x404))

            (param_1 + 0x145,"i_w_boss_2d_wnd_frame_clamp_right.xml",0xffffffff);

  (**(code **)(*(int *)param_1[0x145] + 0xcc))(0);

  pvVar1 = operator_new(0x488);

  if (pvVar1 == (void *)0x0) {

    iVar2 = 0;

  }

  else {

    iVar2 = FUN_007b5dd0(pvVar1,0);

  }

  param_1[0x143] = iVar2;

  (**(code **)(*param_1 + 0xa8))(iVar2);

  (**(code **)(*(int *)param_1[0x143] + 0x28))("i_w_boss_2d_wnd_label.xml");

  (**(code **)(*(int *)param_1[0x143] + 0x74))(0x9c41);

  (**(code **)(*(int *)param_1[0x143] + 0xcc))(0);

  pvVar1 = operator_new(0x488);

  if (pvVar1 == (void *)0x0) {

    iVar2 = 0;

  }

  else {

    iVar2 = FUN_007b5dd0(pvVar1,0);

  }

  param_1[0x146] = iVar2;

  (**(code **)(*param_1 + 0xa8))(iVar2);

  pcVar5 = "i_w_boss_2d_wnd_name.xml";

  (**(code **)(*(int *)param_1[0x146] + 0x28))();

  (**(code **)(*(int *)param_1[0x146] + 0xcc))(0);

  (**(code **)(*param_1 + 0x404))(param_1 + 0x147,"i_w_boss_2d_wnd_level.xml",0xffffffff);

  (**(code **)(*(int *)param_1[0x147] + 0xcc))(0);

  piVar4 = param_1 + 0x148;

  iVar2 = 8;

  do {

    pvVar1 = operator_new(0x488);

    if (pvVar1 == (void *)0x0) {

      iVar3 = 0;

    }

    else {

      iVar3 = FUN_007b5dd0(pvVar1,0);

    }

    *piVar4 = iVar3;

    (**(code **)(*param_1 + 0xa8))(iVar3);

    (**(code **)(*(int *)*piVar4 + 0x28))("i_w_boss_2d_wnd_resist_icon.xml");

    (**(code **)(*(int *)*piVar4 + 0xcc))(0);

    piVar4 = piVar4 + 1;

    iVar2 = iVar2 + -1;

  } while (iVar2 != 0);

  ExceptionList = pcVar5;

  return;

}
