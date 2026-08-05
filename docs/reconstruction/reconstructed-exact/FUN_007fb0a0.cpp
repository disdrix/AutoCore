// =============================================================================
// FUN_007fb0a0
// -----------------------------------------------------------------------------
// Stable ID: aa_007fb0a0
// Address:   0x007fb0a0  (autoassault.exe, image base 0x400000)
// System:    unknown
// Generated: 2026-07-23 from raw capture (scaffold; refine for important units)
// Exactness: Behavior-preserving rewrite of decompiler control flow. Not modernization.
// Bit-for-bit vs retail EXE: DEFERRED (loaded image may differ slightly).
// =============================================================================

// PURPOSE (auto): Scaffold unit for FUN_007fb0a0 @ 0x007fb0a0
// Stable ID: aa_007fb0a0
// No high-value strings recovered; name via xrefs/callers in follow-up.
// Readability: control flow preserved from Ghidra decompile; types tentative.

// READABILITY (auto CF):
//  - Body size: ~85 non-empty decompiler lines.
//  - Control keywords: return×1.
//  - Notable callees: FUN_007b5dd0, FUN_007fb0a0.
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

uint32_t /* width from decompiler */ * FUN_007fb0a0(uint32_t /* width from decompiler */ *param_1)



{

  void *local_c;

  uint8_t *puStack_8;

  uint32_t /* width from decompiler */ local_4;

  

  local_4 = 0xffffffff;

  puStack_8 = &LAB_009b32a0;

  local_c = ExceptionList;

  ExceptionList = &local_c;

  FUN_007b5dd0(param_1,0);

  *param_1 = &PTR_FUN_00a8467c;

  *(uint8_t *)((int)param_1 + 0x4e6) = 0xff;

  *(uint8_t *)((int)param_1 + 0x4e5) = 0xff;

  *(uint8_t *)(param_1 + 0x139) = 0xff;

  *(uint8_t *)((int)param_1 + 0x4e7) = 0xff;

  param_1[0x126] = 0;

  param_1[0x123] = 0;

  param_1[0x127] = 0;

  param_1[0x124] = 0;

  param_1[0x128] = 0;

  param_1[0x125] = 0;

  param_1[0x13d] = 0;

  param_1[0x145] = 0;

  param_1[0x129] = 0;

  param_1[0x12a] = 0;

  param_1[0x150] = 0;

  param_1[0x151] = 0;

  param_1[0x13e] = 0;

  param_1[0x146] = 0;

  param_1[299] = 0;

  param_1[300] = 0;

  param_1[0x152] = 0;

  param_1[0x153] = 0;

  param_1[0x13f] = 0;

  param_1[0x147] = 0;

  param_1[0x12d] = 0;

  param_1[0x12e] = 0;

  param_1[0x154] = 0;

  param_1[0x155] = 0;

  param_1[0x140] = 0;

  param_1[0x148] = 0;

  param_1[0x12f] = 0;

  param_1[0x130] = 0;

  param_1[0x156] = 0;

  param_1[0x157] = 0;

  param_1[0x141] = 0;

  param_1[0x149] = 0;

  param_1[0x131] = 0;

  param_1[0x132] = 0;

  param_1[0x158] = 0;

  param_1[0x159] = 0;

  param_1[0x142] = 0;

  param_1[0x14a] = 0;

  param_1[0x133] = 0;

  param_1[0x134] = 0;

  param_1[0x15a] = 0;

  param_1[0x15b] = 0;

  param_1[0x143] = 0;

  param_1[0x14b] = 0;

  param_1[0x135] = 0;

  param_1[0x136] = 0;

  param_1[0x15c] = 0;

  param_1[0x15d] = 0;

  param_1[0x144] = 0;

  param_1[0x14c] = 0;

  param_1[0x137] = 0;

  param_1[0x138] = 0;

  param_1[0x15e] = 0;

  param_1[0x15f] = 0;

  param_1[0x14d] = 0;

  param_1[0x14e] = 0;

  param_1[0x14f] = 0;

  param_1[0x160] = 0;

  param_1[0x161] = 0;

  param_1[0x162] = 0;

  param_1[0x163] = 0;

  param_1[0x13a] = 0;

  param_1[0x13b] = 0;

  param_1[0x13c] = DAT_00afa098;

  *(uint8_t *)(param_1 + 0x122) = 0;

  *(uint8_t *)((int)param_1 + 0x489) = 1;

  *(uint8_t *)((int)param_1 + 0x48a) = 0;

  ExceptionList = local_c;

  return param_1;

}
