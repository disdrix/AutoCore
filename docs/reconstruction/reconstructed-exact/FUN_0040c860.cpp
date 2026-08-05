// =============================================================================
// FUN_0040c860
// -----------------------------------------------------------------------------
// Stable ID: aa_0040c860
// Address:   0x0040c860  (autoassault.exe, image base 0x400000)
// System:    unknown
// Generated: 2026-07-23 from raw capture (scaffold; refine for important units)
// Exactness: Behavior-preserving rewrite of decompiler control flow. Not modernization.
// Bit-for-bit vs retail EXE: DEFERRED (loaded image may differ slightly).
// =============================================================================

// PURPOSE (auto): Scaffold unit for FUN_0040c860 @ 0x0040c860
// Stable ID: aa_0040c860
// No high-value strings recovered; name via xrefs/callers in follow-up.
// Readability: control flow preserved from Ghidra decompile; types tentative.

// READABILITY (auto CF):
//  - Body size: ~4 non-empty decompiler lines.
//  - Control keywords: return×1.
//  - Notable callees: FUN_0040c860.
//  - Return sites: 1.

// READABILITY:
// Control-flow (from raw @ 0x0040c860; evidence only — no invented semantics):
//  - Entry: `undefined1 __fastcall FUN_0040c860(int param_1)`.
//  - Returns (1 site(s)): `*(param_1 + 0x492)`.
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

uint8_t __fastcall FUN_0040c860(int param_1)



{

  return *(uint8_t *)(param_1 + 0x492);

}
