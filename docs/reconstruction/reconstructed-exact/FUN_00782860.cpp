// =============================================================================
// FUN_00782860
// -----------------------------------------------------------------------------
// Stable ID: aa_00782860
// Address:   0x00782860  (autoassault.exe, image base 0x400000)
// System:    unknown
// Generated: 2026-07-23 from raw capture (scaffold; refine for important units)
// Exactness: Behavior-preserving rewrite of decompiler control flow. Not modernization.
// Bit-for-bit vs retail EXE: DEFERRED (loaded image may differ slightly).
// =============================================================================

// PURPOSE (auto): Scaffold unit for FUN_00782860 @ 0x00782860
// Stable ID: aa_00782860
// No high-value strings recovered; name via xrefs/callers in follow-up.
// Readability: control flow preserved from Ghidra decompile; types tentative.

// READABILITY (auto CF):
//  - Body size: ~20 non-empty decompiler lines.
//  - Control keywords: if×3, while×2, return×2.
//  - Notable callees: FUN_00782860.
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

int * FUN_00782860(void)



{

  int *piVar1;

  int in_EAX;

  int iVar2;

  

  piVar1 = *(int **)(in_EAX + 4);

  while( true ) {

    while( true ) {

      if (piVar1 == (int *)0x0) {

        return (int *)0x0;

      }

      iVar2 = (**(code **)(*piVar1 + 4))();

      if (iVar2 < 1) break;

      piVar1 = (int *)piVar1[3];

    }

    if (-1 < iVar2) break;

    piVar1 = (int *)piVar1[2];

  }

  return piVar1;

}
