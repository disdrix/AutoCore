// =============================================================================
// FUN_0079a0d0
// -----------------------------------------------------------------------------
// Stable ID: aa_0079a0d0
// Address:   0x0079a0d0  (autoassault.exe, image base 0x400000)
// System:    unknown
// Generated: 2026-07-23 from raw capture (scaffold; refine for important units)
// Exactness: Behavior-preserving rewrite of decompiler control flow. Not modernization.
// Bit-for-bit vs retail EXE: DEFERRED (loaded image may differ slightly).
// =============================================================================

// PURPOSE (auto): Scaffold unit for FUN_0079a0d0 @ 0x0079a0d0
// Stable ID: aa_0079a0d0
// No high-value strings recovered; name via xrefs/callers in follow-up.
// Readability: control flow preserved from Ghidra decompile; types tentative.

// READABILITY (auto CF):
//  - Body size: ~12 non-empty decompiler lines.
//  - Control keywords: return×1.
//  - Notable callees: CONCAT44, FUN_0079a0d0, QueryPerformanceCounter.
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

void FUN_0079a0d0(void)



{

  int unaff_ESI;

  LARGE_INTEGER local_8;

  

  QueryPerformanceCounter(&local_8);

  *(float *)(unaff_ESI + 0x238) =

       (float)CONCAT44((local_8.s.HighPart - *(int *)(unaff_ESI + 0x234)) -

                       (uint)(local_8.s.LowPart < *(uint *)(unaff_ESI + 0x230)),

                       local_8.s.LowPart - *(uint *)(unaff_ESI + 0x230)) *

       *(float *)(unaff_ESI + 0x14);

  return;

}
