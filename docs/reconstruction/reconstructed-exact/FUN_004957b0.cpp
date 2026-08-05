// =============================================================================
// FUN_004957b0
// -----------------------------------------------------------------------------
// Stable ID: aa_004957b0
// Address:   0x004957b0  (autoassault.exe, image base 0x400000)
// System:    unknown
// Generated: 2026-07-23 from raw capture (scaffold; refine for important units)
// Exactness: Behavior-preserving rewrite of decompiler control flow. Not modernization.
// Bit-for-bit vs retail EXE: DEFERRED (loaded image may differ slightly).
// =============================================================================

// PURPOSE (auto): Scaffold unit for FUN_004957b0 @ 0x004957b0
// Stable ID: aa_004957b0
// No high-value strings recovered; name via xrefs/callers in follow-up.
// Readability: control flow preserved from Ghidra decompile; types tentative.

// READABILITY (auto CF):
//  - Body size: ~33 non-empty decompiler lines.
//  - Control keywords: if×5, return×2, while×1.
//  - Notable callees: FUN_004957b0.
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

void __thiscall FUN_004957b0(int param_1,int param_2)



{

  int *piVar1;

  int *piVar2;

  int iVar3;

  int iVar4;

  

  piVar1 = *(int **)(param_1 + 0x1c);

  iVar4 = 0;

  piVar2 = piVar1;

  if (piVar1 != *(int **)(param_1 + 0x20)) {

    while (*piVar2 != param_2) {

      piVar2 = piVar2 + 1;

      iVar4 = iVar4 + 1;

      if (piVar2 == *(int **)(param_1 + 0x20)) {

        return;

      }

    }

    if (*(int *)(param_1 + 0x1c) == 0) {

      iVar3 = 0;

    }

    else {

      iVar3 = *(int *)(param_1 + 0x20) - *(int *)(param_1 + 0x1c) >> 2;

    }

    if (0 < iVar3 + -1) {

      piVar1[iVar4] = piVar1[iVar3 + -1];

    }

    if ((*(int *)(param_1 + 0x1c) != 0) &&

       (*(int *)(param_1 + 0x20) - *(int *)(param_1 + 0x1c) >> 2 != 0)) {

      *(int *)(param_1 + 0x20) = *(int *)(param_1 + 0x20) + -4;

    }

  }

  return;

}
