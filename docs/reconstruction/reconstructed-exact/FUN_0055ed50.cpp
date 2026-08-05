// =============================================================================
// FUN_0055ed50
// -----------------------------------------------------------------------------
// Stable ID: aa_0055ed50
// Address:   0x0055ed50  (autoassault.exe, image base 0x400000)
// System:    unknown
// Generated: 2026-07-23 from raw capture (scaffold; refine for important units)
// Exactness: Behavior-preserving rewrite of decompiler control flow. Not modernization.
// Bit-for-bit vs retail EXE: DEFERRED (loaded image may differ slightly).
// =============================================================================

// PURPOSE (auto): Scaffold unit for FUN_0055ed50 @ 0x0055ed50
// Stable ID: aa_0055ed50
// No high-value strings recovered; name via xrefs/callers in follow-up.
// Readability: control flow preserved from Ghidra decompile; types tentative.

// READABILITY (auto CF):
//  - Body size: ~29 non-empty decompiler lines.
//  - Control keywords: if×4, do×2, while×2, return×1.
//  - Notable callees: FUN_0055e570×3, FUN_0055ed50.
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

void FUN_0055ed50(void)



{

  int *piVar1;

  int *unaff_ESI;

  int unaff_EDI;

  

  if (*(int *)(unaff_EDI + 0x2c) != 0) {

    FUN_0055e570(0,*(int *)(unaff_EDI + 0x2c) + 0x3c);

  }

  piVar1 = (int *)*unaff_ESI;

  if (*(int *)(*piVar1 + 0xc) == 0) {

    unaff_ESI[1] = unaff_ESI[1] + -1;

    *piVar1 = piVar1[unaff_ESI[1]];

  }

  piVar1 = *(int **)(unaff_EDI + 8);

  if (piVar1 != piVar1 + *(int *)(unaff_EDI + 0xc)) {

    do {

      FUN_0055e570(unaff_ESI[1],*piVar1 + 0x3c);

      piVar1 = piVar1 + 1;

    } while (piVar1 != (int *)(*(int *)(unaff_EDI + 8) + *(int *)(unaff_EDI + 0xc) * 4));

  }

  piVar1 = *(int **)(unaff_EDI + 0x14);

  if (piVar1 != piVar1 + *(int *)(unaff_EDI + 0x18)) {

    do {

      FUN_0055e570(unaff_ESI[1],*piVar1 + 0x3c);

      piVar1 = piVar1 + 1;

    } while (piVar1 != (int *)(*(int *)(unaff_EDI + 0x14) + *(int *)(unaff_EDI + 0x18) * 4));

  }

  return;

}
