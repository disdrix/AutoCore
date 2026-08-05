// =============================================================================
// FUN_007fb7f0
// -----------------------------------------------------------------------------
// Stable ID: aa_007fb7f0
// Address:   0x007fb7f0  (autoassault.exe, image base 0x400000)
// System:    unknown
// Generated: 2026-07-23 from raw capture (scaffold; refine for important units)
// Exactness: Behavior-preserving rewrite of decompiler control flow. Not modernization.
// Bit-for-bit vs retail EXE: DEFERRED (loaded image may differ slightly).
// =============================================================================

// PURPOSE (auto): Scaffold unit for FUN_007fb7f0 @ 0x007fb7f0
// Stable ID: aa_007fb7f0
// No high-value strings recovered; name via xrefs/callers in follow-up.
// Readability: control flow preserved from Ghidra decompile; types tentative.

// READABILITY (auto CF):
//  - Body size: ~30 non-empty decompiler lines.
//  - Control keywords: if×7, return×1.
//  - Notable callees: FUN_007fb7f0.
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

void FUN_007fb7f0(void)



{

  char cVar1;

  int in_EAX;

  int *piVar2;

  int unaff_EDI;

  

  piVar2 = *(int **)(unaff_EDI + 0x1124);

  if (in_EAX == 2) {

    piVar2 = *(int **)(unaff_EDI + 0x1128);

  }

  else if (in_EAX == 3) {

    piVar2 = *(int **)(unaff_EDI + 0x112c);

  }

  else if (in_EAX == 4) {

    piVar2 = *(int **)(unaff_EDI + 0x1130);

  }

  else if (in_EAX == 5) {

    piVar2 = *(int **)(unaff_EDI + 0x1134);

  }

  if ((*(int *)(unaff_EDI + 0xf40) != 0) && (piVar2 != (int *)0x0)) {

    cVar1 = (**(code **)(*piVar2 + 0x3d8))();

    if (cVar1 != '\0') {

      (**(code **)(*piVar2 + 0x440))();

      if (**(int **)(unaff_EDI + 0xf40) != 0) {

        (**(code **)(*(int *)**(int **)(unaff_EDI + 0xf40) + 0xb0))(piVar2);

      }

    }

  }

  return;

}
