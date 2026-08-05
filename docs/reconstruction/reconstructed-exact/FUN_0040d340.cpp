// =============================================================================
// FUN_0040d340
// -----------------------------------------------------------------------------
// Stable ID: aa_0040d340
// Address:   0x0040d340  (autoassault.exe, image base 0x400000)
// System:    unknown
// Generated: 2026-07-23 from raw capture (scaffold; refine for important units)
// Exactness: Behavior-preserving rewrite of decompiler control flow. Not modernization.
// Bit-for-bit vs retail EXE: DEFERRED (loaded image may differ slightly).
// =============================================================================

// PURPOSE (auto): Scaffold unit for FUN_0040d340 @ 0x0040d340
// Stable ID: aa_0040d340
// No high-value strings recovered; name via xrefs/callers in follow-up.
// Readability: control flow preserved from Ghidra decompile; types tentative.

// READABILITY (auto CF):
//  - Body size: ~10 non-empty decompiler lines.
//  - Control keywords: if×2, return×1.
//  - Notable callees: FUN_0040d340.
//  - Return sites: 1.

// READABILITY:
// Control-flow (from raw @ 0x0040d340; evidence only — no invented semantics):
//  - Entry: `void FUN_0040d340(void)`.
//  - Branches: if (DAT_00afe010 != 0); if (DAT_00afe034 != 0).
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

void FUN_0040d340(void)



{

  if (DAT_00afe010 != 0) {

    (**(code **)(**(int **)(DAT_00afe010 + 0xc) + 0x104))(*(int **)(DAT_00afe010 + 0xc));

  }

  if (DAT_00afe034 != 0) {

    (**(code **)(**(int **)(DAT_00afe034 + 0xc) + 0x104))(*(int **)(DAT_00afe034 + 0xc));

  }

  return;

}
