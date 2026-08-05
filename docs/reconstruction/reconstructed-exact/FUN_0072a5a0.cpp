// =============================================================================
// FUN_0072a5a0
// -----------------------------------------------------------------------------
// Stable ID: aa_0072a5a0
// Address:   0x0072a5a0  (autoassault.exe, image base 0x400000)
// System:    unknown
// Generated: 2026-07-23 from raw capture (scaffold; refine for important units)
// Exactness: Behavior-preserving rewrite of decompiler control flow. Not modernization.
// Bit-for-bit vs retail EXE: DEFERRED (loaded image may differ slightly).
// =============================================================================

// PURPOSE (auto): Scaffold unit for FUN_0072a5a0 @ 0x0072a5a0
// Stable ID: aa_0072a5a0
// No high-value strings recovered; name via xrefs/callers in follow-up.
// Readability: control flow preserved from Ghidra decompile; types tentative.

// READABILITY (auto CF):
//  - Body size: ~21 non-empty decompiler lines.
//  - Control keywords: return×1.
//  - Notable callees: FUN_0046d4e0, FUN_0072a5a0.
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

uint32_t /* width from decompiler */ * FUN_0072a5a0(uint32_t /* width from decompiler */ *param_1)



{

  void *local_c;

  uint8_t *puStack_8;

  uint32_t /* width from decompiler */ local_4;

  

  puStack_8 = &LAB_009abe5f;

  local_c = ExceptionList;

  ExceptionList = &local_c;

  *param_1 = &PTR_FUN_00aa71c8;

  *(uint8_t *)((int)param_1 + 9) = 0;

  param_1[4] = 0;

  param_1[5] = 0;

  param_1[6] = 0;

  local_4 = 1;

  param_1[7] = 0;

  FUN_0046d4e0();

  param_1[1] = 0;

  *(uint8_t *)(param_1 + 2) = 0;

  ExceptionList = local_c;

  return param_1;

}
