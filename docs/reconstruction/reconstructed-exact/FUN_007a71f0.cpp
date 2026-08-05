// =============================================================================
// FUN_007a71f0
// -----------------------------------------------------------------------------
// Stable ID: aa_007a71f0
// Address:   0x007a71f0  (autoassault.exe, image base 0x400000)
// System:    unknown
// Generated: 2026-07-23 from raw capture (scaffold; refine for important units)
// Exactness: Behavior-preserving rewrite of decompiler control flow. Not modernization.
// Bit-for-bit vs retail EXE: DEFERRED (loaded image may differ slightly).
// =============================================================================

// PURPOSE (auto): Scaffold unit for FUN_007a71f0 @ 0x007a71f0
// Stable ID: aa_007a71f0
// No high-value strings recovered; name via xrefs/callers in follow-up.
// Readability: control flow preserved from Ghidra decompile; types tentative.

// READABILITY (auto CF):
//  - Body size: ~8 non-empty decompiler lines.
//  - Control keywords: return×2, if×1.
//  - Notable callees: CONCAT44, FUN_007a71f0.
//  - Return sites: 2.

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

uint64_t FUN_007a71f0(int param_1,int param_2)



{

  if (DAT_00d17944 != 0) {

    return CONCAT44((int)(((float)param_2 * DAT_00aaa670) / (float)DAT_00d1e81c),

                    (int)(((float)param_1 * DAT_00aaa674) / (float)DAT_00d1e818));

  }

  return 0;

}
