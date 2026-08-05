// =============================================================================
// FUN_008fa5f0
// -----------------------------------------------------------------------------
// Stable ID: aa_008fa5f0
// Address:   0x008fa5f0  (autoassault.exe, image base 0x400000)
// System:    unknown
// Generated: 2026-07-23 from raw capture (scaffold; refine for important units)
// Exactness: Behavior-preserving rewrite of decompiler control flow. Not modernization.
// Bit-for-bit vs retail EXE: DEFERRED (loaded image may differ slightly).
// =============================================================================

// PURPOSE (auto): Scaffold unit for FUN_008fa5f0 @ 0x008fa5f0
// Stable ID: aa_008fa5f0
// No high-value strings recovered; name via xrefs/callers in follow-up.
// Readability: control flow preserved from Ghidra decompile; types tentative.

// READABILITY (auto CF):
//  - Body size: ~11 non-empty decompiler lines.
//  - Control keywords: if×1, return×1.
//  - Notable callees: FUN_00792490, FUN_00855810, FUN_008fa5f0.
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

void __fastcall FUN_008fa5f0(int *param_1)



{

  if (param_1[0x536] != 0) {

    FUN_00855810(0);

    (**(code **)(*(int *)param_1[0x536] + 0xcc))(0);

    (**(code **)(*param_1 + 0xb0))(param_1[0x536]);

  }

  (**(code **)(*param_1 + 0x3ac))();

  FUN_00792490();

  return;

}
