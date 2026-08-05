// =============================================================================
// FUN_007fdc60
// -----------------------------------------------------------------------------
// Stable ID: aa_007fdc60
// Address:   0x007fdc60  (autoassault.exe, image base 0x400000)
// System:    unknown
// Generated: 2026-07-23 from raw capture (scaffold; refine for important units)
// Exactness: Behavior-preserving rewrite of decompiler control flow. Not modernization.
// Bit-for-bit vs retail EXE: DEFERRED (loaded image may differ slightly).
// =============================================================================

// PURPOSE (auto): Scaffold unit for FUN_007fdc60 @ 0x007fdc60
// Stable ID: aa_007fdc60
// No high-value strings recovered; name via xrefs/callers in follow-up.
// Readability: control flow preserved from Ghidra decompile; types tentative.

// READABILITY (auto CF):
//  - Body size: ~21 non-empty decompiler lines.
//  - Control keywords: if×2, return×2, do×1, while×1.
//  - Notable callees: FUN_007fca10, FUN_007fdc60.
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

void FUN_007fdc60(void)



{

  int *piVar1;

  int in_EAX;

  int *piVar2;

  

  piVar2 = (int *)**(int **)(in_EAX + 0x3c08);

  if (piVar2 != *(int **)(in_EAX + 0x3c08)) {

    do {

      FUN_007fca10();

      piVar1 = (int *)*piVar2;

      if (piVar2 != *(int **)(in_EAX + 0x3c08)) {

        *(int **)piVar2[1] = piVar1;

        *(int *)(*piVar2 + 4) = piVar2[1];

                    /* WARNING: Subroutine does not return */

        operator_delete(piVar2);

      }

      piVar2 = piVar1;

    } while (piVar1 != (int *)*(int *)(in_EAX + 0x3c08));

  }

  return;

}
