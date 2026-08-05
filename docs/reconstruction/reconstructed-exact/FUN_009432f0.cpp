// =============================================================================
// FUN_009432f0
// -----------------------------------------------------------------------------
// Stable ID: aa_009432f0
// Address:   0x009432f0  (autoassault.exe, image base 0x400000)
// System:    unknown
// Generated: 2026-07-23 from raw capture (scaffold; refine for important units)
// Exactness: Behavior-preserving rewrite of decompiler control flow. Not modernization.
// Bit-for-bit vs retail EXE: DEFERRED (loaded image may differ slightly).
// =============================================================================

// PURPOSE (auto): Scaffold unit for FUN_009432f0 @ 0x009432f0
// Stable ID: aa_009432f0
// No high-value strings recovered; name via xrefs/callers in follow-up.
// Readability: control flow preserved from Ghidra decompile; types tentative.

// READABILITY (auto CF):
//  - Body size: ~14 non-empty decompiler lines.
//  - Control keywords: if×1, return×1.
//  - Notable callees: FUN_007fc150, FUN_007fc840, FUN_00920050, FUN_009301b0, FUN_00937560, FUN_0093bac0, FUN_009423b0, FUN_009432f0.
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

void FUN_009432f0(void)



{

  int in_EAX;

  

  FUN_009423b0(in_EAX,0,0);

  FUN_009301b0();

  FUN_007fc840();

  FUN_0093bac0(in_EAX,0);

  FUN_007fc150();

  FUN_00937560(in_EAX);

  if (*(int *)(in_EAX + 0xf38) != 0) {

    FUN_00920050();

  }

  return;

}
