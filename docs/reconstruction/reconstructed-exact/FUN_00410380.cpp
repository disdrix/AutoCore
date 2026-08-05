// =============================================================================
// FUN_00410380
// -----------------------------------------------------------------------------
// Stable ID: aa_00410380
// Address:   0x00410380  (autoassault.exe, image base 0x400000)
// System:    unknown
// Generated: 2026-07-23 from raw capture (scaffold; refine for important units)
// Exactness: Behavior-preserving rewrite of decompiler control flow. Not modernization.
// Bit-for-bit vs retail EXE: DEFERRED (loaded image may differ slightly).
// =============================================================================

// PURPOSE (auto): Scaffold unit for FUN_00410380 @ 0x00410380
// Stable ID: aa_00410380
// No high-value strings recovered; name via xrefs/callers in follow-up.
// Readability: control flow preserved from Ghidra decompile; types tentative.

// READABILITY (auto CF):
//  - Body size: ~6 non-empty decompiler lines.
//  - Control keywords: return×1.
//  - Notable callees: FUN_00410380, floor.
//  - Return sites: 1.

// READABILITY:
// Control-flow (from raw @ 0x00410380; evidence only — no invented semantics):
//  - Entry: `float10 FUN_00410380(float param_1)`.
//  - Returns (1 site(s)): `(float10)dVar1`.
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

float10 FUN_00410380(float param_1)



{

  double dVar1;

  

  dVar1 = floor((double)param_1);

  return (float10)dVar1;

}
