// =============================================================================
// FUN_009bfa50
// -----------------------------------------------------------------------------
// Stable ID: aa_009bfa50
// Address:   0x009bfa50  (autoassault.exe, image base 0x400000)
// System:    unknown
// Generated: 2026-07-23 from raw capture (scaffold; refine for important units)
// Exactness: Behavior-preserving rewrite of decompiler control flow. Not modernization.
// Bit-for-bit vs retail EXE: DEFERRED (loaded image may differ slightly).
// =============================================================================

// PURPOSE (auto): Scaffold unit for FUN_009bfa50 @ 0x009bfa50
// Stable ID: aa_009bfa50
// No high-value strings recovered; name via xrefs/callers in follow-up.
// Readability: control flow preserved from Ghidra decompile; types tentative.

// READABILITY (auto CF):
//  - Body size: ~10 non-empty decompiler lines.
//  - Control keywords: return×1.
//  - Notable callees: FUN_009bfa50, QueryPerformanceFrequency.
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

/* WARNING: Globals starting with '_' overlap smaller symbols at the same address */



void FUN_009bfa50(void)



{

  BOOL BVar1;

  LARGE_INTEGER local_8;

  

  BVar1 = QueryPerformanceFrequency(&local_8);

  DAT_00d1eaa0 = BVar1 != 0;

  _DAT_00d1ea98 = _DAT_00aaa658 / (double)(longlong)local_8;

  return;

}
