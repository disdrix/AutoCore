// =============================================================================
// FUN_0090c390
// -----------------------------------------------------------------------------
// Stable ID: aa_0090c390
// Address:   0x0090c390  (autoassault.exe, image base 0x400000)
// System:    unknown
// Generated: 2026-07-23 from raw capture (scaffold; refine for important units)
// Exactness: Behavior-preserving rewrite of decompiler control flow. Not modernization.
// Bit-for-bit vs retail EXE: DEFERRED (loaded image may differ slightly).
// =============================================================================

// PURPOSE (auto): Scaffold unit for FUN_0090c390 @ 0x0090c390
// Stable ID: aa_0090c390
// Embedded strings (evidence for future rename):
//   - "i_d_announce_wnd_label.xml"
// Readability: control flow preserved from Ghidra decompile; types tentative.

// READABILITY (auto CF):
//  - Body size: ~56 non-empty decompiler lines.
//  - Control keywords: if×3, return×1.
//  - Notable callees: FUN_00792600, FUN_007b5dd0, FUN_0090c390, FUN_0097c720.
//  - Strings: "i_d_announce_wnd_label.xml".
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

void __fastcall FUN_0090c390(int *param_1)



{

  void *pvVar1;

  int iVar2;

  int *piVar3;

  char *pcVar4;

  void *pvStack_c;

  uint8_t *puStack_8;

  uint32_t /* width from decompiler */ local_4;

  

  local_4 = 0xffffffff;

  puStack_8 = &LAB_009b7cc7;

  pvStack_c = ExceptionList;

  ExceptionList = &pvStack_c;

  FUN_00792600();

  pvVar1 = operator_new(0x560);

  local_4 = 0;

  if (pvVar1 == (void *)0x0) {

    iVar2 = 0;

  }

  else {

    iVar2 = FUN_0097c720();

  }

  local_4 = 0xffffffff;

  param_1[0x140] = iVar2;

  (**(code **)(*param_1 + 0xa8))();

  (**(code **)(*(int *)param_1[0x140] + 0xcc))();

  (**(code **)(*(int *)param_1[0x140] + 0x28))();

  piVar3 = (int *)(**(code **)(*(int *)param_1[0x140] + 0x140))();

  param_1[0x149] = *piVar3;

  iVar2 = param_1[0x1a] + 1;

  param_1[0x14a] = piVar3[1];

  param_1[0x1a] = iVar2;

  param_1[0x1d] = (int)(float)-iVar2;

  if (param_1[0x1c] < iVar2) {

    param_1[0x1c] = iVar2;

  }

  (**(code **)(*param_1 + 0x3f4))();

  pvVar1 = operator_new(0x488);

  if (pvVar1 == (void *)0x0) {

    iVar2 = 0;

  }

  else {

    iVar2 = FUN_007b5dd0(pvVar1);

  }

  param_1[0x13f] = iVar2;

  (**(code **)(*param_1 + 0xa8))();

  pcVar4 = "i_d_announce_wnd_label.xml";

  (**(code **)(*(int *)param_1[0x13f] + 0x28))();

  piVar3 = (int *)(**(code **)(*(int *)param_1[0x13f] + 0x140))(&stack0xffffffcc,1);

  param_1[0x147] = *piVar3;

  param_1[0x148] = piVar3[1];

  (**(code **)(*param_1 + 0xcc))(0);

  (**(code **)(*param_1 + 0x34c))();

  ExceptionList = pcVar4;

  return;

}
