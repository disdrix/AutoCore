// =============================================================================
// FUN_00734170
// -----------------------------------------------------------------------------
// Stable ID: aa_00734170
// Address:   0x00734170  (autoassault.exe, image base 0x400000)
// System:    unknown
// Generated: 2026-07-23 from raw capture (scaffold; refine for important units)
// Exactness: Behavior-preserving rewrite of decompiler control flow. Not modernization.
// Bit-for-bit vs retail EXE: DEFERRED (loaded image may differ slightly).
// =============================================================================

// PURPOSE (auto): Scaffold unit for FUN_00734170 @ 0x00734170
// Stable ID: aa_00734170
// No high-value strings recovered; name via xrefs/callers in follow-up.
// Readability: control flow preserved from Ghidra decompile; types tentative.

// READABILITY (auto CF):
//  - Body size: ~26 non-empty decompiler lines.
//  - Control keywords: return×1.
//  - Notable callees: FUN_00734100, FUN_00734170.
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

uint32_t /* width from decompiler */ * FUN_00734170(uint32_t /* width from decompiler */ *param_1,uint32_t /* width from decompiler */ param_2)



{

  void *local_c;

  uint8_t *puStack_8;

  uint32_t /* width from decompiler */ local_4;

  

  puStack_8 = &LAB_009b183e;

  local_c = ExceptionList;

  ExceptionList = &local_c;

  param_1[1] = param_2;

  *param_1 = &PTR_FUN_00aa5e58;

  param_1[3] = 0;

  param_1[4] = 0;

  param_1[5] = 0;

  param_1[6] = 0;

  *(uint8_t *)(param_1 + 7) = 0;

  *(uint8_t *)((int)param_1 + 0x1d) = 0;

  *(uint8_t *)((int)param_1 + 0x1e) = 0;

  param_1[8] = 0;

  *(uint8_t *)(param_1 + 9) = 0;

  *(uint8_t *)((int)param_1 + 0x25) = 0;

  *(uint8_t *)((int)param_1 + 0x26) = 0;

  local_4 = 3;

  FUN_00734100();

  ExceptionList = local_c;

  return param_1;

}
