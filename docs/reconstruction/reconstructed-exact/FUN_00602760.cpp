// =============================================================================
// FUN_00602760
// -----------------------------------------------------------------------------
// Stable ID: aa_00602760
// Address:   0x00602760  (autoassault.exe, image base 0x400000)
// System:    unknown
// Generated: 2026-07-23 from raw capture (scaffold; refine for important units)
// Exactness: Behavior-preserving rewrite of decompiler control flow. Not modernization.
// Bit-for-bit vs retail EXE: DEFERRED (loaded image may differ slightly).
// =============================================================================

// PURPOSE (auto): Scaffold unit for FUN_00602760 @ 0x00602760
// Stable ID: aa_00602760
// No high-value strings recovered; name via xrefs/callers in follow-up.
// Readability: control flow preserved from Ghidra decompile; types tentative.

// READABILITY (auto CF):
//  - Body size: ~94 non-empty decompiler lines.
//  - Control keywords: if×16, return×2.
//  - Notable callees: FUN_00602760.
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

void FUN_00602760(int *param_1,int *param_2,int *param_3)



{

  int iVar1;

  int iVar2;

  int *piVar3;

  int *piVar4;

  

  iVar1 = (int)param_3 - (int)param_1 >> 2;

  if (iVar1 < 0x29) {

    iVar1 = *param_2;

    if (iVar1 < *param_1) {

      *param_2 = *param_1;

      *param_1 = iVar1;

    }

    iVar1 = *param_3;

    if (iVar1 < *param_2) {

      *param_3 = *param_2;

      *param_2 = iVar1;

    }

    iVar1 = *param_2;

    if (iVar1 < *param_1) {

      *param_2 = *param_1;

      *param_1 = iVar1;

      return;

    }

  }

  else {

    iVar1 = iVar1 + 1;

    iVar2 = (int)(iVar1 + (iVar1 >> 0x1f & 7U)) >> 3;

    iVar1 = param_1[iVar2];

    if (iVar1 < *param_1) {

      param_1[iVar2] = *param_1;

      *param_1 = iVar1;

    }

    iVar1 = param_1[iVar2 * 2];

    if (iVar1 < param_1[iVar2]) {

      param_1[iVar2 * 2] = param_1[iVar2];

      param_1[iVar2] = iVar1;

    }

    iVar1 = param_1[iVar2];

    if (iVar1 < *param_1) {

      param_1[iVar2] = *param_1;

      *param_1 = iVar1;

    }

    iVar1 = *param_2;

    piVar3 = param_2 + -iVar2;

    if (iVar1 < *piVar3) {

      *param_2 = *piVar3;

      *piVar3 = iVar1;

    }

    iVar1 = param_2[iVar2];

    if (iVar1 < *param_2) {

      param_2[iVar2] = *param_2;

      *param_2 = iVar1;

    }

    iVar1 = *param_2;

    if (iVar1 < *piVar3) {

      *param_2 = *piVar3;

      *piVar3 = iVar1;

    }

    piVar3 = param_3 + -iVar2;

    piVar4 = param_3 + iVar2 * -2;

    iVar1 = *piVar3;

    if (iVar1 < *piVar4) {

      *piVar3 = *piVar4;

      *piVar4 = iVar1;

    }

    iVar1 = *param_3;

    if (iVar1 < *piVar3) {

      *param_3 = *piVar3;

      *piVar3 = iVar1;

    }

    iVar1 = *piVar3;

    if (iVar1 < *piVar4) {

      *piVar3 = *piVar4;

      *piVar4 = iVar1;

    }

    iVar1 = *param_2;

    if (iVar1 < param_1[iVar2]) {

      *param_2 = param_1[iVar2];

      param_1[iVar2] = iVar1;

    }

    iVar1 = *piVar3;

    if (iVar1 < *param_2) {

      *piVar3 = *param_2;

      *param_2 = iVar1;

    }

    iVar1 = *param_2;

    if (iVar1 < param_1[iVar2]) {

      *param_2 = param_1[iVar2];

      param_1[iVar2] = iVar1;

    }

  }

  return;

}
