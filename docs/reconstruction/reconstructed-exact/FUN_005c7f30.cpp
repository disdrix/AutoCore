// =============================================================================
// FUN_005c7f30
// -----------------------------------------------------------------------------
// Stable ID: aa_005c7f30
// Address:   0x005c7f30  (autoassault.exe, image base 0x400000)
// System:    unknown
// Generated: 2026-07-23 from raw capture (scaffold; refine for important units)
// Exactness: Behavior-preserving rewrite of decompiler control flow. Not modernization.
// Bit-for-bit vs retail EXE: DEFERRED (loaded image may differ slightly).
// =============================================================================

// PURPOSE (auto): Scaffold unit for FUN_005c7f30 @ 0x005c7f30
// Stable ID: aa_005c7f30
// No high-value strings recovered; name via xrefs/callers in follow-up.
// Readability: control flow preserved from Ghidra decompile; types tentative.

// READABILITY (auto CF):
//  - Body size: ~37 non-empty decompiler lines.
//  - Control keywords: if×1, return×1.
//  - Notable callees: FUN_00518940, FUN_00581330, FUN_005c7f30.
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

uint32_t /* width from decompiler */ * __thiscall FUN_005c7f30(uint32_t /* width from decompiler */ *param_1,int param_2)



{

  void *local_c;

  uint8_t *puStack_8;

  uint32_t /* width from decompiler */ local_4;

  

  local_4 = 0xffffffff;

  puStack_8 = &LAB_009a6ebf;

  local_c = ExceptionList;

  ExceptionList = &local_c;

  if (param_2 != 0) {

    ExceptionList = &local_c;

    param_1[1] = &DAT_009de468;

    FUN_00518940();

    local_4 = 0;

  }

  FUN_00581330(0);

  *param_1 = &PTR_FUN_009da3d0;

  *(undefined ***)(*(int *)(param_1[1] + 4) + 4 + (int)param_1) = &PTR_LAB_009da10c;

  *(int *)(*(int *)(param_1[1] + 4) + (int)param_1) = *(int *)(param_1[1] + 4) + -0xbc;

  param_1[0x1f] = 0;

  param_1[0x20] = 0;

  *(uint16_t *)(param_1 + 0x21) = 0;

  param_1[0x22] = 0;

  param_1[0x23] = 0;

  *(uint8_t *)(param_1 + 0x27) = 0;

  *(uint8_t *)((int)param_1 + 0x9d) = 0;

  *(uint8_t *)((int)param_1 + 0xa1) = 0;

  param_1[0x29] = 0;

  param_1[0x24] = 500;

  param_1[0x25] = 1;

  param_1[0x26] = 0xffffffff;

  *(uint8_t *)((int)param_1 + 0x9e) = 1;

  *(uint8_t *)((int)param_1 + 0x9f) = 1;

  *(uint8_t *)(param_1 + 0x28) = 1;

  ExceptionList = local_c;

  return param_1;

}
