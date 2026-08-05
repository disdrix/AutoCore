// =============================================================================
// FUN_0088ccd0
// -----------------------------------------------------------------------------
// Stable ID: aa_0088ccd0
// Address:   0x0088ccd0  (autoassault.exe, image base 0x400000)
// System:    unknown
// Generated: 2026-07-23 from raw capture (scaffold; refine for important units)
// Exactness: Behavior-preserving rewrite of decompiler control flow. Not modernization.
// Bit-for-bit vs retail EXE: DEFERRED (loaded image may differ slightly).
// =============================================================================

// PURPOSE (auto): Scaffold unit for FUN_0088ccd0 @ 0x0088ccd0
// Stable ID: aa_0088ccd0
// No high-value strings recovered; name via xrefs/callers in follow-up.
// Readability: control flow preserved from Ghidra decompile; types tentative.

// READABILITY (auto CF):
//  - Body size: ~25 non-empty decompiler lines.
//  - Control keywords: if×4, return×2.
//  - Notable callees: FUN_0088ccd0.
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

void __fastcall FUN_0088ccd0(int param_1)



{

  if (*(int *)(param_1 + 0x5e0) != 0) {

    if (*(int *)(param_1 + 0x558) < *(int *)(param_1 + 0x55c) + -1) {

      (**(code **)(**(int **)(param_1 + 0x5e0) + 0xd4))(1);

    }

    else {

      (**(code **)(**(int **)(param_1 + 0x5e0) + 0xd4))(0);

    }

    (**(code **)(**(int **)(param_1 + 0x5e0) + 0x34c))();

  }

  if (*(int *)(param_1 + 0x5e4) != 0) {

    if (*(int *)(param_1 + 0x558) < 1) {

      (**(code **)(**(int **)(param_1 + 0x5e4) + 0xd4))(0);

    }

    else {

      (**(code **)(**(int **)(param_1 + 0x5e4) + 0xd4))(1);

    }

                    /* WARNING: Could not recover jumptable at 0x0088cd4e. Too many branches */

                    /* WARNING: Treating indirect jump as call */

    (**(code **)(**(int **)(param_1 + 0x5e4) + 0x34c))();

    return;

  }

  return;

}
