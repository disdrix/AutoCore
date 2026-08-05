// =============================================================================
// FUN_00605940
// -----------------------------------------------------------------------------
// Stable ID: aa_00605940
// Address:   0x00605940  (autoassault.exe, image base 0x400000)
// System:    unknown
// Generated: 2026-07-23 from raw capture (scaffold; refine for important units)
// Exactness: Behavior-preserving rewrite of decompiler control flow. Not modernization.
// Bit-for-bit vs retail EXE: DEFERRED (loaded image may differ slightly).
// =============================================================================

// PURPOSE (auto): Scaffold unit for FUN_00605940 @ 0x00605940
// Stable ID: aa_00605940
// No high-value strings recovered; name via xrefs/callers in follow-up.
// Readability: control flow preserved from Ghidra decompile; types tentative.

// READABILITY (auto CF):
//  - Body size: ~33 non-empty decompiler lines.
//  - Control keywords: if×1, return×1.
//  - Notable callees: FUN_00518940, FUN_005c7f30, FUN_00605940.
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

uint32_t /* width from decompiler */ * __thiscall FUN_00605940(uint32_t /* width from decompiler */ *param_1,int param_2)



{

  uint32_t /* width from decompiler */ *puVar1;

  uint32_t /* width from decompiler */ uVar2;

  void *local_c;

  uint8_t *puStack_8;

  uint32_t /* width from decompiler */ local_4;

  

  local_4 = 0xffffffff;

  puStack_8 = &LAB_009a80df;

  local_c = ExceptionList;

  ExceptionList = &local_c;

  if (param_2 != 0) {

    ExceptionList = &local_c;

    param_1[1] = &DAT_009de778;

    FUN_00518940();

    local_4 = 0;

  }

  FUN_005c7f30(0);

  uVar2 = DAT_00aaa884;

  *param_1 = &PTR_FUN_009de73c;

  *(undefined ***)(*(int *)(param_1[1] + 4) + 4 + (int)param_1) = &PTR_LAB_009de474;

  *(int *)(*(int *)(param_1[1] + 4) + (int)param_1) = *(int *)(param_1[1] + 4) + -0xcc;

  puVar1 = (uint32_t /* width from decompiler */ *)(*(int *)(param_1[1] + 4) + 0x84 + (int)param_1);

  *puVar1 = uVar2;

  puVar1[1] = 0;

  puVar1[2] = uVar2;

  puVar1[3] = 0;

  *(uint8_t *)(param_1 + 0x2c) = 0xff;

  param_1[0x2d] = 0xffffffff;

  *(uint8_t *)(param_1 + 0x2e) = 0;

  ExceptionList = local_c;

  return param_1;

}
