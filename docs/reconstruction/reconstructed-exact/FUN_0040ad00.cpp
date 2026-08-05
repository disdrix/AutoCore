// =============================================================================
// FUN_0040ad00
// -----------------------------------------------------------------------------
// Stable ID: aa_0040ad00
// Address:   0x0040ad00  (autoassault.exe, image base 0x400000)
// System:    unknown
// Generated: 2026-07-23 from raw capture (scaffold; refine for important units)
// Exactness: Behavior-preserving rewrite of decompiler control flow. Not modernization.
// Bit-for-bit vs retail EXE: DEFERRED (loaded image may differ slightly).
// =============================================================================

// PURPOSE (auto): Scaffold unit for FUN_0040ad00 @ 0x0040ad00
// Stable ID: aa_0040ad00
// No high-value strings recovered; name via xrefs/callers in follow-up.
// Readability: control flow preserved from Ghidra decompile; types tentative.

// READABILITY (auto CF):
//  - Body size: ~5 non-empty decompiler lines.
//  - Control keywords: return×1.
//  - Notable callees: FUN_0040ad00.
//  - Return sites: 1.

// READABILITY:
// Control-flow (from raw @ 0x0040ad00; evidence only — no invented semantics):
//  - Entry: `void FUN_0040ad00(int param_1)`.
//  - Returns (1 site(s)): `void`.
//  - Sparse CF in raw; see body.




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

void FUN_0040ad00(int param_1)



{

  (**(code **)(*DAT_00b05060 + 0x14))(param_1,*(uint16_t *)(param_1 + 4),0x2c);

  return;

}
