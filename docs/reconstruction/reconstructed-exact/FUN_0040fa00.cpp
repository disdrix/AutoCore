// =============================================================================
// FUN_0040fa00
// -----------------------------------------------------------------------------
// Stable ID: aa_0040fa00
// Address:   0x0040fa00  (autoassault.exe, image base 0x400000)
// System:    unknown
// Generated: 2026-07-23 from raw capture (scaffold; refine for important units)
// Exactness: Behavior-preserving rewrite of decompiler control flow. Not modernization.
// Bit-for-bit vs retail EXE: DEFERRED (loaded image may differ slightly).
// =============================================================================

// PURPOSE (auto): Scaffold unit for FUN_0040fa00 @ 0x0040fa00
// Stable ID: aa_0040fa00
// No high-value strings recovered; name via xrefs/callers in follow-up.
// Readability: control flow preserved from Ghidra decompile; types tentative.

// READABILITY (auto CF):
//  - Body size: ~13 non-empty decompiler lines.
//  - Control keywords: return×1.
//  - Notable callees: FUN_0040fa00, FUN_0040fa50.
//  - Return sites: 1.

// READABILITY:
// Control-flow (from raw @ 0x0040fa00; evidence only — no invented semantics):
//  - Entry: `undefined4 FUN_0040fa00(undefined4 param_1)`.
//  - Calls: FUN_0040fa50(param_1).
//  - Returns (1 site(s)): `param_1`.
//  - Assign `local_c = ExceptionList`.




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

uint32_t /* width from decompiler */ FUN_0040fa00(uint32_t /* width from decompiler */ param_1)



{

  void *local_c;

  uint8_t *puStack_8;

  uint32_t /* width from decompiler */ uStack_4;

  

  uStack_4 = 0xffffffff;

  puStack_8 = &LAB_009beb59;

  local_c = ExceptionList;

  ExceptionList = &local_c;

  FUN_0040fa50(param_1);

  ExceptionList = local_c;

  return param_1;

}
