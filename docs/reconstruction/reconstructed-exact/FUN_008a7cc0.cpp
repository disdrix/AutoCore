// =============================================================================
// FUN_008a7cc0
// -----------------------------------------------------------------------------
// Stable ID: aa_008a7cc0
// Address:   0x008a7cc0  (autoassault.exe, image base 0x400000)
// System:    unknown
// Generated: 2026-07-23 from raw capture (scaffold; refine for important units)
// Exactness: Behavior-preserving rewrite of decompiler control flow. Not modernization.
// Bit-for-bit vs retail EXE: DEFERRED (loaded image may differ slightly).
// =============================================================================

// PURPOSE (auto): Scaffold unit for FUN_008a7cc0 @ 0x008a7cc0
// Stable ID: aa_008a7cc0
// Embedded strings (evidence for future rename):
//   - "i_d_objstat_2d_wnd_status.xml"
// Readability: control flow preserved from Ghidra decompile; types tentative.

// READABILITY (auto CF):
//  - Body size: ~43 non-empty decompiler lines.
//  - Control keywords: if×1, return×1.
//  - Notable callees: FUN_00792600, FUN_007b5dd0, FUN_008a7cc0.
//  - Strings: "i_d_objstat_2d_wnd_status.xml".
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

void __fastcall FUN_008a7cc0(int *param_1)



{

  int iVar1;

  int *piVar2;

  void *pvStack_24;

  char *pcStack_20;

  void *pvStack_c;

  uint8_t *puStack_8;

  uint32_t /* width from decompiler */ local_4;

  

  local_4 = 0xffffffff;

  puStack_8 = &LAB_009b39a5;

  pvStack_c = ExceptionList;

  ExceptionList = &pvStack_c;

  param_1[0x143] = -1;

  param_1[0x144] = 0;

  param_1[0x145] = 0;

  FUN_00792600();

  pcStack_20 = (char *)0x8a7d08;

  pcStack_20 = operator_new(0x488);

  local_4 = 0;

  if (pcStack_20 == (void *)0x0) {

    iVar1 = 0;

  }

  else {

    pvStack_24 = (void *)0x8a7d23;

    iVar1 = FUN_007b5dd0();

  }

  local_4 = 0xffffffff;

  param_1[0x14a] = iVar1;

  pcStack_20 = (char *)0x8a7d40;

  (**(code **)(*param_1 + 0xa8))();

  pcStack_20 = "i_d_objstat_2d_wnd_status.xml";

  pvStack_24 = (void *)0x8a7d50;

  (**(code **)(*(int *)param_1[0x14a] + 0x28))();

  pvStack_24 = (void *)0x3f000000;

  (**(code **)(*(int *)param_1[0x14a] + 0xfc))(1);

  piVar2 = (int *)(**(code **)(*(int *)param_1[0x14a] + 0x140))(&pvStack_24,1);

  param_1[0x146] = *piVar2;

  param_1[0x147] = piVar2[1];

  (**(code **)(*param_1 + 0x34c))();

  ExceptionList = pvStack_24;

  return;

}
