// =============================================================================
// FUN_004252e0
// -----------------------------------------------------------------------------
// Stable ID: aa_004252e0
// Address:   0x004252e0  (autoassault.exe, image base 0x400000)
// System:    unknown
// Generated: 2026-07-23 from raw capture (scaffold; refine for important units)
// Exactness: Behavior-preserving rewrite of decompiler control flow. Not modernization.
// Bit-for-bit vs retail EXE: DEFERRED (loaded image may differ slightly).
// =============================================================================

// PURPOSE (auto): Scaffold unit for FUN_004252e0 @ 0x004252e0
// Stable ID: aa_004252e0
// No high-value strings recovered; name via xrefs/callers in follow-up.
// Readability: control flow preserved from Ghidra decompile; types tentative.

// READABILITY (auto CF):
//  - Body size: ~37 non-empty decompiler lines.
//  - Control keywords: if×6, return×2.
//  - Notable callees: FUN_0040b290×2, FUN_004252e0, free.
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

void FUN_004252e0(void)



{

  int *piVar1;

  int *piVar2;

  int unaff_ESI;

  

  FUN_0040b290();

  free(*(void **)(unaff_ESI + 0x5c));

  FUN_0040b290();

  piVar2 = *(int **)(unaff_ESI + 0x28);

  if (piVar2 != (int *)0x0) {

    piVar1 = piVar2 + 2;

    *piVar1 = *piVar1 + -1;

    if (*piVar1 == 0) {

      (**(code **)(*piVar2 + 8))();

    }

  }

  piVar2 = *(int **)(unaff_ESI + 0x24);

  if (piVar2 != (int *)0x0) {

    piVar1 = piVar2 + 2;

    *piVar1 = *piVar1 + -1;

    if (*piVar1 == 0) {

      (**(code **)(*piVar2 + 8))();

    }

  }

  piVar2 = *(int **)(unaff_ESI + 0x20);

  if (piVar2 != (int *)0x0) {

    piVar1 = piVar2 + 2;

    *piVar1 = *piVar1 + -1;

    if (*piVar1 == 0) {

                    /* WARNING: Could not recover jumptable at 0x00425330. Too many branches */

                    /* WARNING: Treating indirect jump as call */

      (**(code **)(*piVar2 + 8))();

      return;

    }

  }

  return;

}
