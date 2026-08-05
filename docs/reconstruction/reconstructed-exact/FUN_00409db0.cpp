// =============================================================================
// FUN_00409db0
// -----------------------------------------------------------------------------
// Stable ID: aa_00409db0
// Address:   0x00409db0  (autoassault.exe, image base 0x400000)
// System:    unknown
// Generated: 2026-07-23 from raw capture (scaffold; refine for important units)
// Exactness: Behavior-preserving rewrite of decompiler control flow. Not modernization.
// Bit-for-bit vs retail EXE: DEFERRED (loaded image may differ slightly).
// =============================================================================

// PURPOSE (auto): Scaffold unit for FUN_00409db0 @ 0x00409db0
// Stable ID: aa_00409db0
// No high-value strings recovered; name via xrefs/callers in follow-up.
// Readability: control flow preserved from Ghidra decompile; types tentative.

// READABILITY (auto CF):
//  - Body size: ~15 non-empty decompiler lines.
//  - Control keywords: for×1, return×1.
//  - Notable callees: FUN_00409db0, FUN_00409f50.
//  - Return sites: 1.

// READABILITY:
// Control-flow (from raw @ 0x00409db0; evidence only — no invented semantics):
//  - Entry: `void FUN_00409db0(undefined4 param_1,int param_2)`.
//  - Loops: for (; param_2 != 0; param_2 = param_2 + -1).
//  - Calls: FUN_00409f50().
//  - Returns (1 site(s)): `void`.




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

void FUN_00409db0(uint32_t /* width from decompiler */ param_1,int param_2)



{

  void *local_10;

  uint8_t *puStack_c;

  uint32_t /* width from decompiler */ local_8;

  

  puStack_c = &LAB_009bc620;

  local_10 = ExceptionList;

  local_8 = 0;

  ExceptionList = &local_10;

  for (; param_2 != 0; param_2 = param_2 + -1) {

    FUN_00409f50();

  }

  ExceptionList = local_10;

  return;

}
