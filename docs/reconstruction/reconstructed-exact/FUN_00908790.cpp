// =============================================================================
// FUN_00908790
// -----------------------------------------------------------------------------
// Stable ID: aa_00908790
// Address:   0x00908790  (autoassault.exe, image base 0x400000)
// System:    unknown
// Generated: 2026-07-23 from raw capture (scaffold; refine for important units)
// Exactness: Behavior-preserving rewrite of decompiler control flow. Not modernization.
// Bit-for-bit vs retail EXE: DEFERRED (loaded image may differ slightly).
// =============================================================================

// PURPOSE (auto): Scaffold unit for FUN_00908790 @ 0x00908790
// Stable ID: aa_00908790
// Embedded strings (evidence for future rename):
//   - "i_d_ah.xml"
// Readability: control flow preserved from Ghidra decompile; types tentative.

// READABILITY (auto CF):
//  - Body size: ~41 non-empty decompiler lines.
//  - Control keywords: for×1, return×1.
//  - Notable callees: FUN_0087b890, FUN_00907720, FUN_00908790, NDUIWindow_ReloadInterface.
//  - Strings: "i_d_ah.xml".
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

int * FUN_00908790(int *param_1)



{

  int iVar1;

  int *piVar2;

  void *local_c;

  uint8_t *puStack_8;

  uint32_t /* width from decompiler */ local_4;

  

  local_4 = 0xffffffff;

  puStack_8 = &LAB_009b7ca7;

  local_c = ExceptionList;

  ExceptionList = &local_c;

  FUN_0087b890(param_1,0);

  local_4 = 0;

  param_1[0x140] = 1;

  *(uint8_t *)(param_1 + 0x148) = 1;

  *param_1 = (int)&PTR_FUN_00a31624;

  param_1[0x13f] = 5;

  param_1[0x143] = 0;

  param_1[0x144] = 0;

  param_1[0x145] = 0;

  piVar2 = param_1 + 0x14a;

  for (iVar1 = 0x2e; iVar1 != 0; iVar1 = iVar1 + -1) {

    *piVar2 = 0;

    piVar2 = piVar2 + 1;

  }

  *(uint8_t *)((int)param_1 + 0x529) = 0xf;

  *(uint8_t *)(param_1 + 0x14a) = 0xf;

  param_1[0x14e] = 999999999;

  param_1[0x14f] = 0;

  *(uint8_t *)((int)param_1 + 0x52d) = 0xff;

  *(uint8_t *)(param_1 + 0x14b) = 0xff;

  *(uint8_t *)((int)param_1 + 0x52b) = 0x50;

  param_1[0x150] = -1;

  param_1[0x151] = -1;

  FUN_00907720();

  *(uint8_t *)(param_1 + 0x124) = 0;

  NDUIWindow_ReloadInterface("i_d_ah.xml");

  (**(code **)(*param_1 + 0x34c))();

  ExceptionList = local_c;

  return param_1;

}
