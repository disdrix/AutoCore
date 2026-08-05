// =============================================================================
// FUN_00862270
// -----------------------------------------------------------------------------
// Stable ID: aa_00862270
// Address:   0x00862270  (autoassault.exe, image base 0x400000)
// System:    unknown
// Generated: 2026-07-23 from raw capture (scaffold; refine for important units)
// Exactness: Behavior-preserving rewrite of decompiler control flow. Not modernization.
// Bit-for-bit vs retail EXE: DEFERRED (loaded image may differ slightly).
// =============================================================================

// PURPOSE (auto): Scaffold unit for FUN_00862270 @ 0x00862270
// Stable ID: aa_00862270
// Embedded strings (evidence for future rename):
//   - "i_d_gm_2d_wnd_message.xml"
// Readability: control flow preserved from Ghidra decompile; types tentative.

// READABILITY (auto CF):
//  - Body size: ~37 non-empty decompiler lines.
//  - Control keywords: if×2, return×1.
//  - Notable callees: FUN_00792600, FUN_007b5dd0, FUN_00862270.
//  - Strings: "i_d_gm_2d_wnd_message.xml".
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

void __fastcall FUN_00862270(int *param_1)



{

  void *pvVar1;

  int *piVar2;

  int *piVar3;

  void *pvStack_c;

  uint8_t *puStack_8;

  uint32_t /* width from decompiler */ uStack_4;

  

  uStack_4 = 0xffffffff;

  puStack_8 = &LAB_009b37f5;

  pvStack_c = ExceptionList;

  ExceptionList = &pvStack_c;

  FUN_00792600();

  if ((uint32_t /* width from decompiler */ *)param_1[0x13f] != (uint32_t /* width from decompiler */ *)0x0) {

    (*(code *)**(uint32_t /* width from decompiler */ **)param_1[0x13f])(1);

  }

  param_1[0x13f] = 0;

  pvVar1 = operator_new(0x488);

  uStack_4 = 0;

  if (pvVar1 == (void *)0x0) {

    piVar2 = (int *)0x0;

  }

  else {

    piVar2 = (int *)FUN_007b5dd0(pvVar1,0);

  }

  uStack_4 = 0xffffffff;

  piVar3 = piVar2;

  (**(code **)(*param_1 + 0xa8))();

  (**(code **)(*piVar2 + 0x28))("i_d_gm_2d_wnd_message.xml");

  param_1[0x13f] = (int)piVar2;

  (**(code **)(*piVar2 + 0xcc))(0);

  piVar2 = (int *)(**(code **)(*(int *)param_1[0x13f] + 0x164))(1);

  param_1[0x144] = *piVar2;

  (**(code **)(*param_1 + 0x34c))();

  ExceptionList = piVar3;

  return;

}
