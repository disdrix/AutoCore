// =============================================================================
// FUN_005ea1e0
// -----------------------------------------------------------------------------
// Stable ID: aa_005ea1e0
// Address:   0x005ea1e0  (autoassault.exe, image base 0x400000)
// System:    unknown
// Generated: 2026-07-23 from raw capture (scaffold; refine for important units)
// Exactness: Behavior-preserving rewrite of decompiler control flow. Not modernization.
// Bit-for-bit vs retail EXE: DEFERRED (loaded image may differ slightly).
// =============================================================================

// PURPOSE (auto): Scaffold unit for FUN_005ea1e0 @ 0x005ea1e0
// Stable ID: aa_005ea1e0
// No high-value strings recovered; name via xrefs/callers in follow-up.
// Readability: control flow preserved from Ghidra decompile; types tentative.

// READABILITY (auto CF):
//  - Body size: ~26 non-empty decompiler lines.
//  - Control keywords: return×1.
//  - Notable callees: FUN_005743e0, FUN_005ea1e0.
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

uint32_t /* width from decompiler */ * __fastcall FUN_005ea1e0(uint32_t /* width from decompiler */ *param_1)



{

  uint32_t /* width from decompiler */ uVar1;

  void *local_c;

  uint8_t *puStack_8;

  uint32_t /* width from decompiler */ local_4;

  

  puStack_8 = &LAB_009a77ab;

  local_c = ExceptionList;

  ExceptionList = &local_c;

  param_1[0x15] = 0;

  param_1[0x16] = 0;

  param_1[0x17] = 0;

  uVar1 = DAT_00aaa884;

  local_4 = 0;

  param_1[7] = 0xffffffff;

  param_1[6] = 0;

  *(uint8_t *)(param_1 + 8) = 0;

  param_1[5] = 0xffffffff;

  *param_1 = uVar1;

  param_1[1] = 0;

  param_1[2] = uVar1;

  param_1[3] = 0;

  FUN_005743e0(0,0,0);

  ExceptionList = local_c;

  return param_1;

}
