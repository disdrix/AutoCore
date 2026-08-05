// =============================================================================
// FUN_00646980
// -----------------------------------------------------------------------------
// Stable ID: aa_00646980
// Address:   0x00646980  (autoassault.exe, image base 0x400000)
// System:    unknown
// Generated: 2026-07-23 from raw capture (scaffold; refine for important units)
// Exactness: Behavior-preserving rewrite of decompiler control flow. Not modernization.
// Bit-for-bit vs retail EXE: DEFERRED (loaded image may differ slightly).
// =============================================================================

// PURPOSE (auto): Scaffold unit for FUN_00646980 @ 0x00646980
// Stable ID: aa_00646980
// No high-value strings recovered; name via xrefs/callers in follow-up.
// Readability: control flow preserved from Ghidra decompile; types tentative.

// READABILITY (auto CF):
//  - Body size: ~7 non-empty decompiler lines.
//  - Control keywords: return×1.
//  - Notable callees: FUN_00646980, block.
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

/* WARNING: Removing unreachable block (ram,0x006469a8) */

/* WARNING: Globals starting with '_' overlap smaller symbols at the same address */



float10 FUN_00646980(void)



{

  DAT_00af509c = DAT_00af509c * -0x3e39b193 + 0x3039 & 0x7fffffff;

  return (float10)DAT_00af509c * (float10)_DAT_009e45b8;

}
