// =============================================================================
// FUN_00873180
// -----------------------------------------------------------------------------
// Stable ID: aa_00873180
// Address:   0x00873180  (autoassault.exe, image base 0x400000)
// System:    unknown
// Generated: 2026-07-23 from raw capture (scaffold; refine for important units)
// Exactness: Behavior-preserving rewrite of decompiler control flow. Not modernization.
// Bit-for-bit vs retail EXE: DEFERRED (loaded image may differ slightly).
// =============================================================================

// PURPOSE (auto): Scaffold unit for FUN_00873180 @ 0x00873180
// Stable ID: aa_00873180
// No high-value strings recovered; name via xrefs/callers in follow-up.
// Readability: control flow preserved from Ghidra decompile; types tentative.

// READABILITY (auto CF):
//  - Body size: ~33 non-empty decompiler lines.
//  - Control keywords: if×7, return×7.
//  - Notable callees: FUN_00873180.
//  - Return sites: 7.

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

uint32_t /* width from decompiler */ FUN_00873180(void)



{

  char cVar1;

  int unaff_ESI;

  

  if ((*(int *)(unaff_ESI + 0x654) != 0) &&

     (cVar1 = (**(code **)(**(int **)(unaff_ESI + 0x654) + 0x3bc))(), cVar1 != '\0')) {

    return 6;

  }

  if ((*(int *)(unaff_ESI + 0x608) != 0) &&

     (cVar1 = (**(code **)(**(int **)(unaff_ESI + 0x608) + 0x3bc))(), cVar1 != '\0')) {

    return 0;

  }

  if ((*(int *)(unaff_ESI + 0x60c) != 0) &&

     (cVar1 = (**(code **)(**(int **)(unaff_ESI + 0x60c) + 0x3bc))(), cVar1 != '\0')) {

    return 1;

  }

  if ((*(int *)(unaff_ESI + 0x610) != 0) &&

     (cVar1 = (**(code **)(**(int **)(unaff_ESI + 0x610) + 0x3bc))(), cVar1 != '\0')) {

    return 2;

  }

  if ((*(int *)(unaff_ESI + 0x614) == 0) ||

     (cVar1 = (**(code **)(**(int **)(unaff_ESI + 0x614) + 0x3bc))(), cVar1 == '\0')) {

    if ((*(int *)(unaff_ESI + 0x618) != 0) &&

       (cVar1 = (**(code **)(**(int **)(unaff_ESI + 0x618) + 0x3bc))(), cVar1 != '\0')) {

      return 4;

    }

    if ((*(int *)(unaff_ESI + 0x61c) != 0) &&

       (cVar1 = (**(code **)(**(int **)(unaff_ESI + 0x61c) + 0x3bc))(), cVar1 != '\0')) {

      return 5;

    }

  }

  return 3;

}
