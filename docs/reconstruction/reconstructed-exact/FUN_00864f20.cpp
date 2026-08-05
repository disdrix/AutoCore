// =============================================================================
// FUN_00864f20
// -----------------------------------------------------------------------------
// Stable ID: aa_00864f20
// Address:   0x00864f20  (autoassault.exe, image base 0x400000)
// System:    unknown
// Generated: 2026-07-23 from raw capture (scaffold; refine for important units)
// Exactness: Behavior-preserving rewrite of decompiler control flow. Not modernization.
// Bit-for-bit vs retail EXE: DEFERRED (loaded image may differ slightly).
// =============================================================================

// PURPOSE (auto): Scaffold unit for FUN_00864f20 @ 0x00864f20
// Stable ID: aa_00864f20
// No high-value strings recovered; name via xrefs/callers in follow-up.
// Readability: control flow preserved from Ghidra decompile; types tentative.

// READABILITY (auto CF):
//  - Body size: ~29 non-empty decompiler lines.
//  - Control keywords: return×1.
//  - Notable callees: FUN_007b5dd0, FUN_00864f20.
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

/* WARNING: Globals starting with '_' overlap smaller symbols at the same address */



uint32_t /* width from decompiler */ * FUN_00864f20(uint32_t /* width from decompiler */ *param_1)



{

  void *local_c;

  uint8_t *puStack_8;

  uint32_t /* width from decompiler */ local_4;

  

  local_4 = 0xffffffff;

  puStack_8 = &LAB_009b3861;

  local_c = ExceptionList;

  ExceptionList = &local_c;

  FUN_007b5dd0(param_1,0);

  param_1[0x128] = DAT_00aaa8fc;

  *param_1 = &PTR_FUN_00a61504;

  *(uint8_t *)((int)param_1 + 0xbf) = 0;

  *(uint8_t *)(param_1 + 0x122) = 0;

  *(uint8_t *)((int)param_1 + 0x489) = 1;

  param_1[0x125] = 0;

  param_1[0x126] = 0;

  param_1[0x127] = 0;

  param_1[0x129] = 0;

  param_1[0x12a] = (float)DAT_00d1e81c * _DAT_00aaab40;

  param_1[300] = g_nInferredThreatDefault;

  param_1[0x12d] = 0;

  param_1[299] = 0;

  param_1[0x12e] = 0;

  param_1[0x123] = 3;

  ExceptionList = local_c;

  return param_1;

}
