// =============================================================================
// FUN_00764030
// -----------------------------------------------------------------------------
// Stable ID: aa_00764030
// Address:   0x00764030  (autoassault.exe, image base 0x400000)
// System:    unknown
// Generated: 2026-07-23 from raw capture (scaffold; refine for important units)
// Exactness: Behavior-preserving rewrite of decompiler control flow. Not modernization.
// Bit-for-bit vs retail EXE: DEFERRED (loaded image may differ slightly).
// =============================================================================

// PURPOSE (auto): Scaffold unit for FUN_00764030 @ 0x00764030
// Stable ID: aa_00764030
// No high-value strings recovered; name via xrefs/callers in follow-up.
// Readability: control flow preserved from Ghidra decompile; types tentative.

// READABILITY (auto CF):
//  - Body size: ~57 non-empty decompiler lines.
//  - Control keywords: return×1.
//  - Notable callees: FUN_00764030, FUN_0096b100, FUN_0096d830.
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

uint32_t /* width from decompiler */ * __fastcall FUN_00764030(uint32_t /* width from decompiler */ *param_1)



{

  float fVar1;

  void *local_c;

  uint8_t *puStack_8;

  uint32_t /* width from decompiler */ local_4;

  

  local_4 = 0xffffffff;

  puStack_8 = &LAB_009b0b12;

  local_c = ExceptionList;

  ExceptionList = &local_c;

  FUN_0096d830(param_1);

  local_4 = 0;

  *param_1 = &PTR_LAB_00a9da8c;

  param_1[0x23] = 0;

  param_1[0x24] = 0;

  param_1[0x25] = 0;

  FUN_0096b100();

  param_1[0x2e] = 0xffffffff;

  param_1[0x30] = 0;

  param_1[0x31] = 0;

  param_1[0x32] = 0;

  param_1[0x34] = 0;

  param_1[0x35] = 0;

  param_1[0x36] = 0;

  param_1[0x37] = 0;

  param_1[0x38] = 0;

  param_1[0x39] = 0;

  param_1[0x3b] = 0;

  param_1[0x3c] = 0;

  param_1[0x3d] = 0;

  param_1[0x3e] = 0;

  param_1[0x40] = 0xffffffff;

  *(uint8_t *)(param_1 + 0x3f) = 0;

  param_1[0x49] = 0;

  param_1[0x41] = 0;

  param_1[0x42] = 0;

  param_1[0x43] = 0;

  param_1[0x44] = 0;

  param_1[0x45] = 0;

  param_1[0x46] = 0;

  param_1[0x47] = 0;

  param_1[0x48] = 0;

  fVar1 = g_flOne;

  param_1[0x4b] = 0;

  param_1[0x4c] = 0;

  param_1[0x4d] = 0;

  *(uint8_t *)(param_1 + 0x4e) = 0;

  *(uint8_t *)((int)param_1 + 0x139) = 0;

  *(uint8_t *)((int)param_1 + 0x13a) = 0;

  param_1[0x50] = 0;

  param_1[0x52] = 0;

  param_1[0x37] = param_1[0x26];

  param_1[0x51] = fVar1;

  param_1[0x38] = param_1 + 1;

  ExceptionList = local_c;

  return param_1;

}
