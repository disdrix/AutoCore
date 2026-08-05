// =============================================================================
// FUN_008b10d0
// -----------------------------------------------------------------------------
// Stable ID: aa_008b10d0
// Address:   0x008b10d0  (autoassault.exe, image base 0x400000)
// System:    unknown
// Generated: 2026-07-23 from raw capture (scaffold; refine for important units)
// Exactness: Behavior-preserving rewrite of decompiler control flow. Not modernization.
// Bit-for-bit vs retail EXE: DEFERRED (loaded image may differ slightly).
// =============================================================================

// PURPOSE (auto): Scaffold unit for FUN_008b10d0 @ 0x008b10d0
// Stable ID: aa_008b10d0
// No high-value strings recovered; name via xrefs/callers in follow-up.
// Readability: control flow preserved from Ghidra decompile; types tentative.

// READABILITY (auto CF):
//  - Body size: ~64 non-empty decompiler lines.
//  - Control keywords: if×19, return×1.
//  - Notable callees: FUN_008b10d0.
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

void FUN_008b10d0(void)



{

  char cVar1;

  int unaff_ESI;

  

  if (*(int *)(unaff_ESI + 0x504) != 0) {

    cVar1 = (**(code **)(**(int **)(unaff_ESI + 0x504) + 0xd0))();

    if (cVar1 != '\0') {

      (**(code **)(**(int **)(unaff_ESI + 0x504) + 0xfc))(0,0x3e800000);

    }

  }

  if (*(int *)(unaff_ESI + 0x528) != 0) {

    cVar1 = (**(code **)(**(int **)(unaff_ESI + 0x528) + 0xd0))();

    if (cVar1 != '\0') {

      (**(code **)(**(int **)(unaff_ESI + 0x528) + 0xfc))(0,0x3e800000);

    }

  }

  if (*(int *)(unaff_ESI + 0x52c) != 0) {

    cVar1 = (**(code **)(**(int **)(unaff_ESI + 0x52c) + 0xd0))();

    if (cVar1 != '\0') {

      (**(code **)(**(int **)(unaff_ESI + 0x52c) + 0xfc))(0,0x3e800000);

    }

  }

  if (*(int *)(unaff_ESI + 0x530) != 0) {

    cVar1 = (**(code **)(**(int **)(unaff_ESI + 0x530) + 0xd0))();

    if (cVar1 != '\0') {

      (**(code **)(**(int **)(unaff_ESI + 0x530) + 0xfc))(0,0x3e800000);

    }

  }

  if (*(int *)(unaff_ESI + 0x520) != 0) {

    cVar1 = (**(code **)(**(int **)(unaff_ESI + 0x520) + 0xd0))();

    if (cVar1 != '\0') {

      (**(code **)(**(int **)(unaff_ESI + 0x520) + 0xfc))(0,0x3e800000);

    }

  }

  if (*(int *)(unaff_ESI + 0x524) != 0) {

    cVar1 = (**(code **)(**(int **)(unaff_ESI + 0x524) + 0xd0))();

    if (cVar1 != '\0') {

      (**(code **)(**(int **)(unaff_ESI + 0x524) + 0xfc))(0,0x3e800000);

      cVar1 = (**(code **)(**(int **)(unaff_ESI + 0x524) + 0x490))();

      if (cVar1 != '\0') {

        (**(code **)(**(int **)(unaff_ESI + 0x524) + 0x48c))();

      }

    }

  }

  if (*(int *)(unaff_ESI + 0x514) != 0) {

    cVar1 = (**(code **)(**(int **)(unaff_ESI + 0x514) + 0xd0))();

    if (cVar1 != '\0') {

      (**(code **)(**(int **)(unaff_ESI + 0x514) + 0xfc))(0,0x3e800000);

    }

  }

  if (*(int *)(unaff_ESI + 0x518) != 0) {

    cVar1 = (**(code **)(**(int **)(unaff_ESI + 0x518) + 0xd0))();

    if (cVar1 != '\0') {

      (**(code **)(**(int **)(unaff_ESI + 0x518) + 0xfc))(0,0x3e800000);

    }

  }

  if (*(int *)(unaff_ESI + 0x51c) != 0) {

    cVar1 = (**(code **)(**(int **)(unaff_ESI + 0x51c) + 0xd0))();

    if (cVar1 != '\0') {

      (**(code **)(**(int **)(unaff_ESI + 0x51c) + 0xfc))(0,0x3e800000);

    }

  }

  return;

}
