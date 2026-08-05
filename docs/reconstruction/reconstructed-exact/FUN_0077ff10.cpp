// =============================================================================
// FUN_0077ff10
// -----------------------------------------------------------------------------
// Stable ID: aa_0077ff10
// Address:   0x0077ff10  (autoassault.exe, image base 0x400000)
// System:    unknown
// Generated: 2026-07-23 from raw capture (scaffold; refine for important units)
// Exactness: Behavior-preserving rewrite of decompiler control flow. Not modernization.
// Bit-for-bit vs retail EXE: DEFERRED (loaded image may differ slightly).
// =============================================================================

// PURPOSE (auto): Scaffold unit for FUN_0077ff10 @ 0x0077ff10
// Stable ID: aa_0077ff10
// No high-value strings recovered; name via xrefs/callers in follow-up.
// Readability: control flow preserved from Ghidra decompile; types tentative.

// READABILITY (auto CF):
//  - Body size: ~19 non-empty decompiler lines.
//  - Control keywords: if×2, return×2, while×1.
//  - Notable callees: FUN_0077ff10.
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

void FUN_0077ff10(void)



{

  int iVar1;

  int *piVar2;

  int *unaff_EDI;

  

  iVar1 = *unaff_EDI;

  while( true ) {

    if (iVar1 == 0) {

      return;

    }

    piVar2 = (int *)*unaff_EDI;

    iVar1 = *piVar2;

    if (piVar2 != (int *)0x0) break;

    *unaff_EDI = iVar1;

  }

  operator_delete__((void *)piVar2[1]);

                    /* WARNING: Subroutine does not return */

  operator_delete(piVar2);

}
