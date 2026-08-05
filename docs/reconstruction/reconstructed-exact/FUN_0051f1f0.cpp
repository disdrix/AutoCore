// =============================================================================
// FUN_0051f1f0
// -----------------------------------------------------------------------------
// Stable ID: aa_0051f1f0
// Address:   0x0051f1f0  (autoassault.exe, image base 0x400000)
// System:    unknown
// Generated: 2026-07-23 from raw capture (scaffold; refine for important units)
// Exactness: Behavior-preserving rewrite of decompiler control flow. Not modernization.
// Bit-for-bit vs retail EXE: DEFERRED (loaded image may differ slightly).
// =============================================================================

// PURPOSE (auto): Scaffold unit for FUN_0051f1f0 @ 0x0051f1f0
// Stable ID: aa_0051f1f0
// No high-value strings recovered; name via xrefs/callers in follow-up.
// Readability: control flow preserved from Ghidra decompile; types tentative.

// READABILITY (auto CF):
//  - Body size: ~14 non-empty decompiler lines.
//  - Control keywords: if×3, return×2.
//  - Notable callees: FUN_00570f50×3, FUN_0051f1f0.
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

void __fastcall FUN_0051f1f0(int param_1)



{

  if (*(int *)(param_1 + -0xc0) != 0) {

    FUN_00570f50();

  }

  if (*(int *)(param_1 + -0xe4) != 0) {

    FUN_00570f50();

  }

  if (*(int *)(param_1 + -0xe0) != 0) {

    FUN_00570f50();

    return;

  }

  return;

}
