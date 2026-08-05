// =============================================================================
// FUN_00401b60
// -----------------------------------------------------------------------------
// Stable ID: aa_00401b60
// Address:   0x00401b60  (autoassault.exe, image base 0x400000)
// System:    unknown
// Generated: 2026-07-23 from raw capture (scaffold; refine for important units)
// Exactness: Behavior-preserving rewrite of decompiler control flow. Not modernization.
// Bit-for-bit vs retail EXE: DEFERRED (loaded image may differ slightly).
// =============================================================================

// PURPOSE (auto): Scaffold unit for FUN_00401b60 @ 0x00401b60
// Stable ID: aa_00401b60
// No high-value strings recovered; name via xrefs/callers in follow-up.
// Readability: control flow preserved from Ghidra decompile; types tentative.

// READABILITY (auto CF):
//  - Body size: ~14 non-empty decompiler lines.
//  - Control keywords: return×1.
//  - Notable callees: FUN_004019d0, FUN_00401b60.
//  - Return sites: 1.

// READABILITY:
// Control-flow (from raw @ 0x00401b60; evidence only — no invented semantics):
//  - Entry: `undefined4 * __thiscall FUN_00401b60(undefined4 *param_1,undefined4 param_2)`.
//  - Calls: FUN_004019d0(param_2).
//  - Writes: *param_1 = &PTR_FUN_009c7640.
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

uint32_t /* width from decompiler */ * __thiscall FUN_00401b60(uint32_t /* width from decompiler */ *param_1,uint32_t /* width from decompiler */ param_2)



{

  void *local_c;

  uint8_t *puStack_8;

  uint32_t /* width from decompiler */ local_4;

  

  local_4 = 0xffffffff;

  puStack_8 = &LAB_009bc828;

  local_c = ExceptionList;

  ExceptionList = &local_c;

  FUN_004019d0(param_2);

  *param_1 = &PTR_FUN_009c7640;

  ExceptionList = local_c;

  return param_1;

}
