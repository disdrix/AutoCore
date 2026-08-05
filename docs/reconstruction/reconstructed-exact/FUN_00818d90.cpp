// =============================================================================
// FUN_00818d90
// -----------------------------------------------------------------------------
// Stable ID: aa_00818d90
// Address:   0x00818d90  (autoassault.exe, image base 0x400000)
// System:    unknown
// Generated: 2026-07-23 from raw capture (scaffold; refine for important units)
// Exactness: Behavior-preserving rewrite of decompiler control flow. Not modernization.
// Bit-for-bit vs retail EXE: DEFERRED (loaded image may differ slightly).
// =============================================================================

// PURPOSE (auto): Scaffold unit for FUN_00818d90 @ 0x00818d90
// Stable ID: aa_00818d90
// No high-value strings recovered; name via xrefs/callers in follow-up.
// Readability: control flow preserved from Ghidra decompile; types tentative.

// READABILITY (auto CF):
//  - Body size: ~22 non-empty decompiler lines.
//  - Control keywords: return×1.
//  - Notable callees: FUN_0040fb90, FUN_00817dc0, FUN_00818d90.
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

uint32_t /* width from decompiler */ * FUN_00818d90(uint32_t /* width from decompiler */ *param_1)



{

  uint32_t /* width from decompiler */ uVar1;

  void *local_c;

  uint8_t *puStack_8;

  uint32_t /* width from decompiler */ local_4;

  

  local_4 = 0xffffffff;

  puStack_8 = &LAB_009b832d;

  local_c = ExceptionList;

  ExceptionList = &local_c;

  FUN_00817dc0(param_1);

  local_4 = 0;

  *param_1 = &PTR_FUN_00a7b55c;

  uVar1 = FUN_0040fb90();

  param_1[0x1c5] = uVar1;

  param_1[0x1c6] = 0;

  param_1[0x1c3] = 0xffffffff;

  *(uint8_t *)(param_1 + 0x181) = 0;

  param_1[0x1c2] = 0;

  ExceptionList = local_c;

  return param_1;

}
