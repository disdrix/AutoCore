// =============================================================================
// FUN_0084f2a0
// -----------------------------------------------------------------------------
// Stable ID: aa_0084f2a0
// Address:   0x0084f2a0  (autoassault.exe, image base 0x400000)
// System:    unknown
// Generated: 2026-07-23 from raw capture (scaffold; refine for important units)
// Exactness: Behavior-preserving rewrite of decompiler control flow. Not modernization.
// Bit-for-bit vs retail EXE: DEFERRED (loaded image may differ slightly).
// =============================================================================

// PURPOSE (auto): Scaffold unit for FUN_0084f2a0 @ 0x0084f2a0
// Stable ID: aa_0084f2a0
// Embedded strings (evidence for future rename):
//   - "i_w_a_2d_wnd_frame.xml"
//   - "i_w_a_2d_wnd_name.xml"
//   - "i_w_a_2d_wnd_description.xml"
//   - "i_w_a_2d_wnd_stats_full.xml"
//   - "i_w_a_2d_wnd_progress.xml"
//   - "i_w_a_2d_wnd_progress_bar_bg.xml"
// Readability: control flow preserved from Ghidra decompile; types tentative.

// READABILITY (auto CF):
//  - Body size: ~41 non-empty decompiler lines.
//  - Control keywords: if×1, return×1.
//  - Notable callees: FUN_00792600, FUN_0084f2a0, FUN_0097ffa0.
//  - Strings: "i_w_a_2d_wnd_frame.xml"; "i_w_a_2d_wnd_name.xml"; "i_w_a_2d_wnd_description.xml"; "i_w_a_2d_wnd_stats_full.xml".
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

void __fastcall FUN_0084f2a0(int *param_1)



{

  void *pvVar1;

  int iVar2;

  int *piVar3;

  uint32_t /* width from decompiler */ uVar4;

  int *piVar5;

  void *pvStack_c;

  uint8_t *puStack_8;

  uint32_t /* width from decompiler */ uStack_4;

  

  uStack_4 = 0xffffffff;

  puStack_8 = &LAB_009b8656;

  pvStack_c = ExceptionList;

  ExceptionList = &pvStack_c;

  FUN_00792600();

  (**(code **)(*param_1 + 0x404))(param_1 + 0x145,"i_w_a_2d_wnd_frame.xml",0xffffffff);

  (**(code **)(*param_1 + 0x404))(param_1 + 0x146,"i_w_a_2d_wnd_name.xml",0xffffffff);

  (**(code **)(*param_1 + 0x404))(param_1 + 0x147,"i_w_a_2d_wnd_description.xml",0xffffffff);

  (**(code **)(*param_1 + 0x404))(param_1 + 0x148,"i_w_a_2d_wnd_stats_full.xml",0xffffffff);

  piVar5 = param_1 + 0x149;

  (**(code **)(*param_1 + 0x404))(piVar5,"i_w_a_2d_wnd_progress.xml",0xffffffff);

  uVar4 = 0xffffffff;

  piVar3 = param_1 + 0x14a;

  (**(code **)(*param_1 + 0x404))(piVar3,"i_w_a_2d_wnd_progress_bar_bg.xml",0xffffffff);

  pvVar1 = operator_new(0x4f8);

  if (pvVar1 == (void *)0x0) {

    iVar2 = 0;

  }

  else {

    iVar2 = FUN_0097ffa0(pvVar1);

  }

  param_1[0x14b] = iVar2;

  (**(code **)(*param_1 + 0xa8))(iVar2,piVar3,pvVar1,uVar4,piVar5,0xffffffff);

  (**(code **)(*(int *)param_1[0x14b] + 0x28))("i_w_a_2d_wnd_progress_bar.xml");

  (**(code **)(*param_1 + 0x404))(param_1 + 0x14c,"i_w_a_2d_wnd_progress_bar_cover.xml");

  *(uint8_t *)(param_1 + 0x143) = 1;

  (**(code **)(*param_1 + 0x444))();

  (**(code **)(*param_1 + 0x34c))();

  ExceptionList = (void *)0xffffffff;

  return;

}
