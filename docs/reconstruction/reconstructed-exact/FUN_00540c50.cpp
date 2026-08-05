// =============================================================================
// FUN_00540c50
// -----------------------------------------------------------------------------
// Stable ID: aa_00540c50
// Address:   0x00540c50  (autoassault.exe, image base 0x400000)
// System:    unknown
// Generated: 2026-07-23 from raw capture (scaffold; refine for important units)
// Exactness: Behavior-preserving rewrite of decompiler control flow. Not modernization.
// Bit-for-bit vs retail EXE: DEFERRED (loaded image may differ slightly).
// =============================================================================

// PURPOSE (auto): Scaffold unit for FUN_00540c50 @ 0x00540c50
// Stable ID: aa_00540c50
// No high-value strings recovered; name via xrefs/callers in follow-up.
// Readability: control flow preserved from Ghidra decompile; types tentative.

// READABILITY (auto CF):
//  - Body size: ~14 non-empty decompiler lines.
//  - Control keywords: if×2, return×2, while×1.
//  - Notable callees: CVOGReaction_FailMissionNotify, FUN_00540c50.
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

void FUN_00540c50(int param_1)



{

  int *piVar1;

  

  piVar1 = DAT_00b04718;

  while( true ) {

    if (piVar1 == DAT_00b0471c) {

      CVOGReaction_FailMissionNotify(&param_1);

      return;

    }

    if (*piVar1 == param_1) break;

    piVar1 = piVar1 + 1;

  }

  return;

}
