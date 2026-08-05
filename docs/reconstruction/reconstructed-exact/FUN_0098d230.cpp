// =============================================================================
// FUN_0098d230
// -----------------------------------------------------------------------------
// Stable ID: aa_0098d230
// Address:   0x0098d230  (autoassault.exe, image base 0x400000)
// System:    unknown
// Generated: 2026-07-23 from raw capture (scaffold; refine for important units)
// Exactness: Behavior-preserving rewrite of decompiler control flow. Not modernization.
// Bit-for-bit vs retail EXE: DEFERRED (loaded image may differ slightly).
// =============================================================================

// PURPOSE (auto): Scaffold unit for FUN_0098d230 @ 0x0098d230
// Stable ID: aa_0098d230
// No high-value strings recovered; name via xrefs/callers in follow-up.
// Readability: control flow preserved from Ghidra decompile; types tentative.

// READABILITY (auto CF):
//  - Body size: ~20 non-empty decompiler lines.
//  - Control keywords: return×1.
//  - Notable callees: FUN_0046d4e0, FUN_0098d230.
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

uint32_t /* width from decompiler */ * FUN_0098d230(uint32_t /* width from decompiler */ *param_1,uint32_t /* width from decompiler */ param_2)



{

  void *local_c;

  undefined *puStack_8;

  uint32_t /* width from decompiler */ local_4;

  

  puStack_8 = &DAT_009ad459;

  local_c = ExceptionList;

  ExceptionList = &local_c;

  param_1[1] = param_2;

  *param_1 = &PTR_FUN_00aa72e4;

  param_1[3] = 0;

  param_1[4] = 0;

  param_1[5] = 0;

  local_4 = 1;

  param_1[6] = 0;

  param_1[7] = 0xffffffff;

  FUN_0046d4e0();

  ExceptionList = local_c;

  return param_1;

}
