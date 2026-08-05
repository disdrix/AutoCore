// =============================================================================
// FUN_0092cef0
// -----------------------------------------------------------------------------
// Stable ID: aa_0092cef0
// Address:   0x0092cef0  (autoassault.exe, image base 0x400000)
// System:    unknown
// Generated: 2026-07-23 from raw capture (scaffold; refine for important units)
// Exactness: Behavior-preserving rewrite of decompiler control flow. Not modernization.
// Bit-for-bit vs retail EXE: DEFERRED (loaded image may differ slightly).
// =============================================================================

// PURPOSE (auto): Scaffold unit for FUN_0092cef0 @ 0x0092cef0
// Stable ID: aa_0092cef0
// No high-value strings recovered; name via xrefs/callers in follow-up.
// Readability: control flow preserved from Ghidra decompile; types tentative.

// READABILITY (auto CF):
//  - Body size: ~24 non-empty decompiler lines.
//  - Control keywords: if×4, return×2.
//  - Notable callees: FUN_0090d390, FUN_0092cef0.
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

void FUN_0092cef0(void)



{

  char cVar1;

  int *piVar2;

  int unaff_ESI;

  

  piVar2 = *(int **)(unaff_ESI + 0xf40);

  if ((piVar2 != (int *)0x0) && (*piVar2 != 0)) {

    (**(code **)(*(int *)*piVar2 + 0x94))();

    if (*(int *)(unaff_ESI + 0x1138) != 0) {

      cVar1 = (**(code **)(**(int **)(unaff_ESI + 0x1138) + 0x3d8))();

      if (cVar1 != '\0') {

        (**(code **)(**(int **)(unaff_ESI + 0x1138) + 0x94))();

      }

    }

    piVar2 = (int *)FUN_0090d390();

    if (piVar2 != (int *)0x0) {

                    /* WARNING: Could not recover jumptable at 0x0092cf3f. Too many branches */

                    /* WARNING: Treating indirect jump as call */

      (**(code **)(*piVar2 + 0x94))();

      return;

    }

  }

  return;

}
