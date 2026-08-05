// =============================================================================
// FUN_00893520
// -----------------------------------------------------------------------------
// Stable ID: aa_00893520
// Address:   0x00893520  (autoassault.exe, image base 0x400000)
// System:    unknown
// Generated: 2026-07-23 from raw capture (scaffold; refine for important units)
// Exactness: Behavior-preserving rewrite of decompiler control flow. Not modernization.
// Bit-for-bit vs retail EXE: DEFERRED (loaded image may differ slightly).
// =============================================================================

// PURPOSE (auto): Scaffold unit for FUN_00893520 @ 0x00893520
// Stable ID: aa_00893520
// No high-value strings recovered; name via xrefs/callers in follow-up.
// Readability: control flow preserved from Ghidra decompile; types tentative.

// READABILITY (auto CF):
//  - Body size: ~22 non-empty decompiler lines.
//  - Control keywords: if×2, return×2.
//  - Notable callees: FUN_00893520.
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

void FUN_00893520(void)



{

  int *piVar1;

  uint8_t in_AL;

  char cVar2;

  int *unaff_ESI;

  

  *(uint8_t *)(unaff_ESI + 0x145) = in_AL;

  cVar2 = (**(code **)(*unaff_ESI + 0x3d8))();

  if ((cVar2 != '\0') && (piVar1 = (int *)unaff_ESI[0x151], piVar1 != (int *)0x0)) {

    if ((char)unaff_ESI[0x145] == '\0') {

      (**(code **)(*piVar1 + 0x1d8))(&DAT_00a511ec,1,1);

    }

    else {

      (**(code **)(*piVar1 + 0x1d8))(&DAT_00a511f4);

    }

                    /* WARNING: Could not recover jumptable at 0x0089356f. Too many branches */

                    /* WARNING: Treating indirect jump as call */

    (**(code **)(*(int *)unaff_ESI[0x151] + 0x34c))();

    return;

  }

  return;

}
