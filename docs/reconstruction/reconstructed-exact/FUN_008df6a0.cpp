// =============================================================================
// FUN_008df6a0
// -----------------------------------------------------------------------------
// Stable ID: aa_008df6a0
// Address:   0x008df6a0  (autoassault.exe, image base 0x400000)
// System:    unknown
// Generated: 2026-07-23 from raw capture (scaffold; refine for important units)
// Exactness: Behavior-preserving rewrite of decompiler control flow. Not modernization.
// Bit-for-bit vs retail EXE: DEFERRED (loaded image may differ slightly).
// =============================================================================

// PURPOSE (auto): Scaffold unit for FUN_008df6a0 @ 0x008df6a0
// Stable ID: aa_008df6a0
// No high-value strings recovered; name via xrefs/callers in follow-up.
// Readability: control flow preserved from Ghidra decompile; types tentative.

// READABILITY (auto CF):
//  - Body size: ~25 non-empty decompiler lines.
//  - Control keywords: do×2, if×2, while×2, return×1.
//  - Notable callees: FUN_004133c0, FUN_008df6a0.
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

void FUN_008df6a0(void)



{

  int iVar1;

  int *piVar2;

  int *unaff_EDI;

  

  piVar2 = unaff_EDI + 0x177;

  iVar1 = 0x33;

  do {

    if (*piVar2 != 0) {

      (**(code **)(*unaff_EDI + 0xbc))(*piVar2);

    }

    *piVar2 = 0;

    piVar2 = piVar2 + 1;

    iVar1 = iVar1 + -1;

  } while (iVar1 != 0);

  piVar2 = *(int **)unaff_EDI[0x1ac];

  if (piVar2 != (int *)unaff_EDI[0x1ac]) {

    do {

      (**(code **)(*unaff_EDI + 0xbc))(piVar2[2]);

      piVar2 = (int *)*piVar2;

    } while (piVar2 != (int *)unaff_EDI[0x1ac]);

  }

  FUN_004133c0(0);

  return;

}
