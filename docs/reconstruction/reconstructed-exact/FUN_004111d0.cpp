// =============================================================================
// FUN_004111d0
// -----------------------------------------------------------------------------
// Stable ID: aa_004111d0
// Address:   0x004111d0  (autoassault.exe, image base 0x400000)
// System:    unknown
// Generated: 2026-07-23 from raw capture (scaffold; refine for important units)
// Exactness: Behavior-preserving rewrite of decompiler control flow. Not modernization.
// Bit-for-bit vs retail EXE: DEFERRED (loaded image may differ slightly).
// =============================================================================

// PURPOSE (auto): Scaffold unit for FUN_004111d0 @ 0x004111d0
// Stable ID: aa_004111d0
// No high-value strings recovered; name via xrefs/callers in follow-up.
// Readability: control flow preserved from Ghidra decompile; types tentative.

// READABILITY (auto CF):
//  - Body size: ~7 non-empty decompiler lines.
//  - Control keywords: return×1.
//  - Notable callees: Experience_GetCumulativeThreshold, FUN_004111d0.
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

int FUN_004111d0(void)



{

  uint uVar1;

  int unaff_ESI;

  

  uVar1 = Experience_GetCumulativeThreshold(*(ushort *)(unaff_ESI + 0xc50));

  return (uVar1 - *(int *)(unaff_ESI + 0x730)) + -1;

}
