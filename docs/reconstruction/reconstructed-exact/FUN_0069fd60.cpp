// =============================================================================
// FUN_0069fd60
// -----------------------------------------------------------------------------
// Stable ID: aa_0069fd60
// Address:   0x0069fd60  (autoassault.exe, image base 0x400000)
// System:    unknown
// Generated: 2026-07-23 from raw capture (scaffold; refine for important units)
// Exactness: Behavior-preserving rewrite of decompiler control flow. Not modernization.
// Bit-for-bit vs retail EXE: DEFERRED (loaded image may differ slightly).
// =============================================================================

// PURPOSE (auto): Scaffold unit for FUN_0069fd60 @ 0x0069fd60
// Stable ID: aa_0069fd60
// No high-value strings recovered; name via xrefs/callers in follow-up.
// Readability: control flow preserved from Ghidra decompile; types tentative.

// READABILITY (auto CF):
//  - Body size: ~28 non-empty decompiler lines.
//  - Control keywords: if×3, return×3.
//  - Notable callees: FUN_0069fd60.
//  - Return sites: 3.

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

void __thiscall FUN_0069fd60(int param_1,int param_2)



{

  int *piVar1;

  int *piVar2;

  

  piVar1 = *(int **)(param_2 + 8);

  *(int *)(param_2 + 8) = *piVar1;

  if (*(char *)(*piVar1 + 0x2d) == '\0') {

    *(int *)(*piVar1 + 4) = param_2;

  }

  piVar1[1] = *(int *)(param_2 + 4);

  if (param_2 == *(int *)(*(int *)(param_1 + 4) + 4)) {

    *(int **)(*(int *)(param_1 + 4) + 4) = piVar1;

    *piVar1 = param_2;

    *(int **)(param_2 + 4) = piVar1;

    return;

  }

  piVar2 = *(int **)(param_2 + 4);

  if (param_2 == *piVar2) {

    *piVar2 = (int)piVar1;

    *piVar1 = param_2;

    *(int **)(param_2 + 4) = piVar1;

    return;

  }

  piVar2[2] = (int)piVar1;

  *piVar1 = param_2;

  *(int **)(param_2 + 4) = piVar1;

  return;

}
