// =============================================================================
// FUN_00636820
// -----------------------------------------------------------------------------
// Stable ID: aa_00636820
// Address:   0x00636820  (autoassault.exe, image base 0x400000)
// System:    unknown
// Generated: 2026-07-23 from raw capture (scaffold; refine for important units)
// Exactness: Behavior-preserving rewrite of decompiler control flow. Not modernization.
// Bit-for-bit vs retail EXE: DEFERRED (loaded image may differ slightly).
// =============================================================================

// PURPOSE (auto): Scaffold unit for FUN_00636820 @ 0x00636820
// Stable ID: aa_00636820
// No high-value strings recovered; name via xrefs/callers in follow-up.
// Readability: control flow preserved from Ghidra decompile; types tentative.

// READABILITY (auto CF):
//  - Body size: ~22 non-empty decompiler lines.
//  - Control keywords: return×1.
//  - Notable callees: FUN_00636820, FUN_00651b10, FUN_00651b60.
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

uint32_t /* width from decompiler */ * __thiscall FUN_00636820(uint32_t /* width from decompiler */ *param_1,uint32_t /* width from decompiler */ param_2,uint32_t /* width from decompiler */ param_3)



{

  void *local_c;

  uint8_t *puStack_8;

  uint32_t /* width from decompiler */ local_4;

  

  puStack_8 = &LAB_009a8c88;

  local_c = ExceptionList;

  ExceptionList = &local_c;

  *(uint16_t *)((int)param_1 + 6) = 1;

  param_1[2] = &PTR_LAB_009e3a68;

  param_1[5] = 0;

  param_1[4] = 0;

  param_1[3] = 0;

  param_1[6] = 0;

  local_4 = 0;

  *param_1 = &PTR_FUN_009e3ad4;

  param_1[2] = &PTR_LAB_009e3ac0;

  FUN_00651b10(param_2);

  FUN_00651b60(param_3);

  ExceptionList = local_c;

  return param_1;

}
