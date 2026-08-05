// =============================================================================
// FUN_00404490
// -----------------------------------------------------------------------------
// Stable ID: aa_00404490
// Address:   0x00404490  (autoassault.exe, image base 0x400000)
// System:    unknown
// Generated: 2026-07-23 from raw capture (scaffold; refine for important units)
// Exactness: Behavior-preserving rewrite of decompiler control flow. Not modernization.
// Bit-for-bit vs retail EXE: DEFERRED (loaded image may differ slightly).
// =============================================================================

// PURPOSE (auto): Scaffold unit for FUN_00404490 @ 0x00404490
// Stable ID: aa_00404490
// No high-value strings recovered; name via xrefs/callers in follow-up.
// Readability: control flow preserved from Ghidra decompile; types tentative.

// READABILITY (auto CF):
//  - Body size: ~5 non-empty decompiler lines.
//  - Control keywords: return×1.
//  - Notable callees: FUN_00404490, FUN_00404560.
//  - Return sites: 1.

// READABILITY:
// Control-flow (from raw @ 0x00404490; evidence only — no invented semantics):
//  - Entry: `void FUN_00404490(undefined4 param_1,undefined4 param_2,undefined4 param_3,undefined4 param_4)`.
//  - Calls: FUN_00404560(param_1,param_2,param_3,param_4,param_4).
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

void FUN_00404490(uint32_t /* width from decompiler */ param_1,uint32_t /* width from decompiler */ param_2,uint32_t /* width from decompiler */ param_3,uint32_t /* width from decompiler */ param_4)



{

  FUN_00404560(param_1,param_2,param_3,param_4,param_4);

  return;

}
