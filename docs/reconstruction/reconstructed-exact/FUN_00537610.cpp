// =============================================================================
// FUN_00537610
// -----------------------------------------------------------------------------
// Stable ID: aa_00537610
// Address:   0x00537610  (autoassault.exe, image base 0x400000)
// System:    unknown
// Generated: 2026-07-23 from raw capture (scaffold; refine for important units)
// Exactness: Behavior-preserving rewrite of decompiler control flow. Not modernization.
// Bit-for-bit vs retail EXE: DEFERRED (loaded image may differ slightly).
// =============================================================================

// PURPOSE (auto): Scaffold unit for FUN_00537610 @ 0x00537610
// Stable ID: aa_00537610
// No high-value strings recovered; name via xrefs/callers in follow-up.
// Readability: control flow preserved from Ghidra decompile; types tentative.

// READABILITY (auto CF):
//  - Body size: ~11 non-empty decompiler lines.
//  - Control keywords: while×1, return×1.
//  - Notable callees: FUN_00537610.
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

void FUN_00537610(int *param_1)



{

  char cVar1;

  

  param_1 = (int *)*param_1;

  cVar1 = *(char *)((int)param_1 + 0x20d);

  while (cVar1 == '\0') {

    param_1 = (int *)*param_1;

    cVar1 = *(char *)((int)param_1 + 0x20d);

  }

  return;

}
