// =============================================================================
// FUN_0075d200
// -----------------------------------------------------------------------------
// Stable ID: aa_0075d200
// Address:   0x0075d200  (autoassault.exe, image base 0x400000)
// System:    unknown
// Generated: 2026-07-23 from raw capture (scaffold; refine for important units)
// Exactness: Behavior-preserving rewrite of decompiler control flow. Not modernization.
// Bit-for-bit vs retail EXE: DEFERRED (loaded image may differ slightly).
// =============================================================================

// PURPOSE (auto): Scaffold unit for FUN_0075d200 @ 0x0075d200
// Stable ID: aa_0075d200
// No high-value strings recovered; name via xrefs/callers in follow-up.
// Readability: control flow preserved from Ghidra decompile; types tentative.

// READABILITY (auto CF):
//  - Body size: ~13 non-empty decompiler lines.
//  - Control keywords: if×2, return×1.
//  - Notable callees: FUN_0075d200.
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

int * __thiscall FUN_0075d200(int param_1,uint32_t /* width from decompiler */ param_2)



{

  int *piVar1;

  

  piVar1 = *(int **)(param_1 + 100);

  *(uint32_t /* width from decompiler */ *)(param_1 + 100) = param_2;

  if (piVar1 != (int *)0x0) {

    (**(code **)(*piVar1 + 4))(0);

  }

  if (*(int **)(param_1 + 100) != (int *)0x0) {

    (**(code **)(**(int **)(param_1 + 100) + 4))(1);

  }

  return piVar1;

}
