// =============================================================================
// FUN_00410240
// -----------------------------------------------------------------------------
// Stable ID: aa_00410240
// Address:   0x00410240  (autoassault.exe, image base 0x400000)
// System:    unknown
// Generated: 2026-07-23 from raw capture (scaffold; refine for important units)
// Exactness: Behavior-preserving rewrite of decompiler control flow. Not modernization.
// Bit-for-bit vs retail EXE: DEFERRED (loaded image may differ slightly).
// =============================================================================

// PURPOSE (auto): Scaffold unit for FUN_00410240 @ 0x00410240
// Stable ID: aa_00410240
// No high-value strings recovered; name via xrefs/callers in follow-up.
// Readability: control flow preserved from Ghidra decompile; types tentative.

// READABILITY (auto CF):
//  - Body size: ~21 non-empty decompiler lines.
//  - Control keywords: return×1.
//  - Notable callees: CONCAT31, FUN_0040fb90, FUN_00410240, FUN_004133c0, FUN_007b5dd0.
//  - Return sites: 1.

// READABILITY:
// Control-flow (from raw @ 0x00410240; evidence only — no invented semantics):
//  - Entry: `undefined4 * FUN_00410240(undefined4 *param_1)`.
//  - Calls: FUN_007b5dd0(param_1,0); FUN_0040fb90(); FUN_004133c0(0).
//  - Writes: *param_1 = &PTR_FUN_00a42a3c; param_1[0x123] = uVar1; param_1[0x124] = 0.
//  - Returns (1 site(s)): `param_1`.




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

uint32_t /* width from decompiler */ * FUN_00410240(uint32_t /* width from decompiler */ *param_1)



{

  uint32_t /* width from decompiler */ uVar1;

  void *local_c;

  uint8_t *puStack_8;

  uint32_t /* width from decompiler */ local_4;

  

  local_4 = 0xffffffff;

  puStack_8 = &LAB_009bf0f5;

  local_c = ExceptionList;

  ExceptionList = &local_c;

  FUN_007b5dd0(param_1,0);

  local_4 = 0;

  *param_1 = &PTR_FUN_00a42a3c;

  uVar1 = FUN_0040fb90();

  param_1[0x123] = uVar1;

  param_1[0x124] = 0;

  local_4 = CONCAT31(local_4._1_3_,1);

  FUN_004133c0(0);

  ExceptionList = local_c;

  return param_1;

}
