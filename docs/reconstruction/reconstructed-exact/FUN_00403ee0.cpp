// =============================================================================
// FUN_00403ee0
// -----------------------------------------------------------------------------
// Stable ID: aa_00403ee0
// Address:   0x00403ee0  (autoassault.exe, image base 0x400000)
// System:    unknown
// Generated: 2026-07-23 from raw capture (scaffold; refine for important units)
// Exactness: Behavior-preserving rewrite of decompiler control flow. Not modernization.
// Bit-for-bit vs retail EXE: DEFERRED (loaded image may differ slightly).
// =============================================================================

// PURPOSE (auto): Scaffold unit for FUN_00403ee0 @ 0x00403ee0
// Stable ID: aa_00403ee0
// No high-value strings recovered; name via xrefs/callers in follow-up.
// Readability: control flow preserved from Ghidra decompile; types tentative.

// READABILITY (auto CF):
//  - Body size: ~28 non-empty decompiler lines.
//  - Control keywords: if×3, return×3.
//  - Notable callees: FUN_00403ee0.
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

void __thiscall FUN_00403ee0(int *param_1,int param_2)



{

  int iVar1;

  int *piVar2;

  

  iVar1 = *param_1;

  *param_1 = *(int *)(iVar1 + 8);

  if (*(char *)(*(int *)(iVar1 + 8) + 0x31) == '\0') {

    *(int **)(*(int *)(iVar1 + 8) + 4) = param_1;

  }

  *(int *)(iVar1 + 4) = param_1[1];

  if (param_1 == *(int **)(*(int *)(param_2 + 4) + 4)) {

    *(int *)(*(int *)(param_2 + 4) + 4) = iVar1;

    *(int **)(iVar1 + 8) = param_1;

    param_1[1] = iVar1;

    return;

  }

  piVar2 = (int *)param_1[1];

  if (param_1 == (int *)piVar2[2]) {

    piVar2[2] = iVar1;

    *(int **)(iVar1 + 8) = param_1;

    param_1[1] = iVar1;

    return;

  }

  *piVar2 = iVar1;

  *(int **)(iVar1 + 8) = param_1;

  param_1[1] = iVar1;

  return;

}
