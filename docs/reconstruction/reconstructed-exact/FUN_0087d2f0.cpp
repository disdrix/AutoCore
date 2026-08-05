// =============================================================================
// FUN_0087d2f0
// -----------------------------------------------------------------------------
// Stable ID: aa_0087d2f0
// Address:   0x0087d2f0  (autoassault.exe, image base 0x400000)
// System:    unknown
// Generated: 2026-07-23 from raw capture (scaffold; refine for important units)
// Exactness: Behavior-preserving rewrite of decompiler control flow. Not modernization.
// Bit-for-bit vs retail EXE: DEFERRED (loaded image may differ slightly).
// =============================================================================

// PURPOSE (auto): Scaffold unit for FUN_0087d2f0 @ 0x0087d2f0
// Stable ID: aa_0087d2f0
// No high-value strings recovered; name via xrefs/callers in follow-up.
// Readability: control flow preserved from Ghidra decompile; types tentative.

// READABILITY (auto CF):
//  - Body size: ~51 non-empty decompiler lines.
//  - Control keywords: if×13, return×3.
//  - Notable callees: FUN_0087d2f0.
//  - Return sites: 3.

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

void FUN_0087d2f0(char param_1)



{

  int unaff_ESI;

  

  if ((param_1 == '\0') || (*(int *)(unaff_ESI + 0x514) == 0)) {

    if (*(int *)(unaff_ESI + 0x5a0) != 0) {

      (**(code **)(**(int **)(unaff_ESI + 0x5a0) + 0xcc))(0);

    }

    if (*(int *)(unaff_ESI + 0x5a8) != 0) {

      (**(code **)(**(int **)(unaff_ESI + 0x5a8) + 0xcc))(0);

    }

    if (*(int *)(unaff_ESI + 0x5a4) != 0) {

      (**(code **)(**(int **)(unaff_ESI + 0x5a4) + 0xcc))(0);

    }

    if (*(int *)(unaff_ESI + 0x588) != 0) {

      (**(code **)(**(int **)(unaff_ESI + 0x588) + 0xcc))(0);

    }

    if (*(int *)(unaff_ESI + 0x58c) != 0) {

      (**(code **)(**(int **)(unaff_ESI + 0x58c) + 0xcc))(0);

    }

    if (*(int *)(unaff_ESI + 0x590) != 0) {

                    /* WARNING: Could not recover jumptable at 0x0087d43e. Too many branches */

                    /* WARNING: Treating indirect jump as call */

      (**(code **)(**(int **)(unaff_ESI + 0x590) + 0xcc))();

      return;

    }

  }

  else {

    if (*(int *)(unaff_ESI + 0x588) != 0) {

      (**(code **)(**(int **)(unaff_ESI + 0x588) + 0xcc))(1);

    }

    if (*(int *)(unaff_ESI + 0x58c) != 0) {

      (**(code **)(**(int **)(unaff_ESI + 0x58c) + 0xcc))(1);

    }

    if (*(int *)(unaff_ESI + 0x590) != 0) {

      (**(code **)(**(int **)(unaff_ESI + 0x590) + 0xcc))(1);

    }

    if (*(int *)(unaff_ESI + 0x5a0) != 0) {

      (**(code **)(**(int **)(unaff_ESI + 0x5a0) + 0xcc))(1);

    }

    if (*(int *)(unaff_ESI + 0x5a8) != 0) {

      (**(code **)(**(int **)(unaff_ESI + 0x5a8) + 0xcc))(1);

    }

    if (*(int *)(unaff_ESI + 0x5a4) != 0) {

                    /* WARNING: Could not recover jumptable at 0x0087d3a2. Too many branches */

                    /* WARNING: Treating indirect jump as call */

      (**(code **)(**(int **)(unaff_ESI + 0x5a4) + 0xcc))();

      return;

    }

  }

  return;

}
