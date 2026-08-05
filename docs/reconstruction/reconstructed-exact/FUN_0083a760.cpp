// =============================================================================
// FUN_0083a760
// -----------------------------------------------------------------------------
// Stable ID: aa_0083a760
// Address:   0x0083a760  (autoassault.exe, image base 0x400000)
// System:    unknown
// Generated: 2026-07-23 from raw capture (scaffold; refine for important units)
// Exactness: Behavior-preserving rewrite of decompiler control flow. Not modernization.
// Bit-for-bit vs retail EXE: DEFERRED (loaded image may differ slightly).
// =============================================================================

// PURPOSE (auto): Scaffold unit for FUN_0083a760 @ 0x0083a760
// Stable ID: aa_0083a760
// No high-value strings recovered; name via xrefs/callers in follow-up.
// Readability: control flow preserved from Ghidra decompile; types tentative.

// READABILITY (auto CF):
//  - Body size: ~20 non-empty decompiler lines.
//  - Control keywords: return×1.
//  - Notable callees: FUN_007b5dd0, FUN_0083a760.
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

uint32_t /* width from decompiler */ * FUN_0083a760(uint32_t /* width from decompiler */ *param_1)



{

  void *local_c;

  uint8_t *puStack_8;

  uint32_t /* width from decompiler */ local_4;

  

  local_4 = 0xffffffff;

  puStack_8 = &LAB_009b34b3;

  local_c = ExceptionList;

  ExceptionList = &local_c;

  FUN_007b5dd0(param_1,0);

  *param_1 = &PTR_FUN_00a6dbc4;

  param_1[0x122] = 0;

  param_1[0x123] = 0;

  param_1[0x124] = 0;

  param_1[0x125] = 0;

  *(uint8_t *)(param_1 + 0x126) = 0;

  *(uint8_t *)((int)param_1 + 0x4ca) = 0;

  ExceptionList = local_c;

  return param_1;

}
