// =============================================================================
// FUN_00873270
// -----------------------------------------------------------------------------
// Stable ID: aa_00873270
// Address:   0x00873270  (autoassault.exe, image base 0x400000)
// System:    unknown
// Generated: 2026-07-23 from raw capture (scaffold; refine for important units)
// Exactness: Behavior-preserving rewrite of decompiler control flow. Not modernization.
// Bit-for-bit vs retail EXE: DEFERRED (loaded image may differ slightly).
// =============================================================================

// PURPOSE (auto): Scaffold unit for FUN_00873270 @ 0x00873270
// Stable ID: aa_00873270
// No high-value strings recovered; name via xrefs/callers in follow-up.
// Readability: control flow preserved from Ghidra decompile; types tentative.

// READABILITY (auto CF):
//  - Body size: ~41 non-empty decompiler lines.
//  - Control keywords: if×9, return×9.
//  - Notable callees: FUN_00873270.
//  - Return sites: 9.

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

uint32_t /* width from decompiler */ FUN_00873270(void)



{

  char cVar1;

  int unaff_ESI;

  

  if ((*(int *)(unaff_ESI + 0x63c) != 0) &&

     (cVar1 = (**(code **)(**(int **)(unaff_ESI + 0x63c) + 0x3bc))(), cVar1 != '\0')) {

    return 2;

  }

  if ((*(int *)(unaff_ESI + 0x640) != 0) &&

     (cVar1 = (**(code **)(**(int **)(unaff_ESI + 0x640) + 0x3bc))(), cVar1 != '\0')) {

    return 0;

  }

  if ((*(int *)(unaff_ESI + 0x644) != 0) &&

     (cVar1 = (**(code **)(**(int **)(unaff_ESI + 0x644) + 0x3bc))(), cVar1 != '\0')) {

    return 1;

  }

  if ((*(int *)(unaff_ESI + 0x648) != 0) &&

     (cVar1 = (**(code **)(**(int **)(unaff_ESI + 0x648) + 0x3bc))(), cVar1 != '\0')) {

    return 0;

  }

  if ((*(int *)(unaff_ESI + 0x64c) != 0) &&

     (cVar1 = (**(code **)(**(int **)(unaff_ESI + 0x64c) + 0x3bc))(), cVar1 != '\0')) {

    return 0;

  }

  if ((*(int *)(unaff_ESI + 0x650) != 0) &&

     (cVar1 = (**(code **)(**(int **)(unaff_ESI + 0x650) + 0x3bc))(), cVar1 != '\0')) {

    return 0;

  }

  if ((*(int *)(unaff_ESI + 0x654) != 0) &&

     (cVar1 = (**(code **)(**(int **)(unaff_ESI + 0x654) + 0x3bc))(), cVar1 != '\0')) {

    return 0;

  }

  if ((*(int *)(unaff_ESI + 0x658) != 0) &&

     (cVar1 = (**(code **)(**(int **)(unaff_ESI + 0x658) + 0x3bc))(), cVar1 != '\0')) {

    return 0;

  }

  if (*(int *)(unaff_ESI + 0x65c) != 0) {

    (**(code **)(**(int **)(unaff_ESI + 0x65c) + 0x3bc))();

  }

  return 0;

}
