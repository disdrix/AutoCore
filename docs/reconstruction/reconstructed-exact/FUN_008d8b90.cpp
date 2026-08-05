// =============================================================================
// FUN_008d8b90
// -----------------------------------------------------------------------------
// Stable ID: aa_008d8b90
// Address:   0x008d8b90  (autoassault.exe, image base 0x400000)
// System:    unknown
// Generated: 2026-07-23 from raw capture (scaffold; refine for important units)
// Exactness: Behavior-preserving rewrite of decompiler control flow. Not modernization.
// Bit-for-bit vs retail EXE: DEFERRED (loaded image may differ slightly).
// =============================================================================

// PURPOSE (auto): Scaffold unit for FUN_008d8b90 @ 0x008d8b90
// Stable ID: aa_008d8b90
// No high-value strings recovered; name via xrefs/callers in follow-up.
// Readability: control flow preserved from Ghidra decompile; types tentative.

// READABILITY (auto CF):
//  - Body size: ~37 non-empty decompiler lines.
//  - Control keywords: return×1.
//  - Notable callees: FUN_0087b890, FUN_008d7420, FUN_008d8b90.
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

uint32_t /* width from decompiler */ * FUN_008d8b90(uint32_t /* width from decompiler */ *param_1,uint32_t /* width from decompiler */ param_2)



{

  void *local_c;

  undefined *puStack_8;

  uint32_t /* width from decompiler */ local_4;

  

  local_4 = 0xffffffff;

  puStack_8 = &DAT_009b6eb2;

  local_c = ExceptionList;

  ExceptionList = &local_c;

  FUN_0087b890(param_1,param_2);

  local_4 = 0;

  *param_1 = &PTR_FUN_00a3ee5c;

  param_1[0x143] = DAT_00d1a6c0;

  param_1[0x144] = DAT_00d1a6c4;

  param_1[0x145] = DAT_00d1a6c8;

  param_1[0x146] = DAT_00afdfec;

  param_1[0x147] = DAT_00afdff0;

  param_1[0x148] = DAT_00afdff4;

  param_1[0x149] = DAT_00afdff8;

  param_1[0x14a] = DAT_00d1a6c0;

  param_1[0x14b] = DAT_00d1a6c4;

  param_1[0x14c] = DAT_00d1a6c8;

  param_1[0x14d] = DAT_00afdfec;

  param_1[0x14e] = DAT_00afdff0;

  param_1[0x14f] = DAT_00afdff4;

  param_1[0x150] = DAT_00afdff8;

  *(uint8_t *)(param_1 + 0x15b) = 0;

  *(uint8_t *)((int)param_1 + 0x56d) = 0;

  param_1[0x15c] = 0;

  param_1[0x15d] = 0;

  param_1[0x13f] = 0xf;

  param_1[0x140] = 0;

  *(uint8_t *)((int)param_1 + 0xbf) = 0;

  FUN_008d7420();

  ExceptionList = local_c;

  return param_1;

}
