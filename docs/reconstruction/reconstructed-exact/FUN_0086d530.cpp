// =============================================================================
// FUN_0086d530
// -----------------------------------------------------------------------------
// Stable ID: aa_0086d530
// Address:   0x0086d530  (autoassault.exe, image base 0x400000)
// System:    unknown
// Generated: 2026-07-23 from raw capture (scaffold; refine for important units)
// Exactness: Behavior-preserving rewrite of decompiler control flow. Not modernization.
// Bit-for-bit vs retail EXE: DEFERRED (loaded image may differ slightly).
// =============================================================================

// PURPOSE (auto): Scaffold unit for FUN_0086d530 @ 0x0086d530
// Stable ID: aa_0086d530
// No high-value strings recovered; name via xrefs/callers in follow-up.
// Readability: control flow preserved from Ghidra decompile; types tentative.

// READABILITY (auto CF):
//  - Body size: ~11 non-empty decompiler lines.
//  - Control keywords: if×1, return×1.
//  - Notable callees: FUN_00792490, FUN_0086d530.
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

void __fastcall FUN_0086d530(int *param_1)



{

  DAT_00d1d8f4 = 1;

  DAT_00d1d8f5 = 0;

  if (DAT_00d1d8dc != (int *)0x0) {

    (**(code **)(*DAT_00d1d8dc + 4))(0);

  }

  (**(code **)(*param_1 + 0x3ac))();

  FUN_00792490();

  return;

}
