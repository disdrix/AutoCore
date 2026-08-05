// =============================================================================
// FUN_0062b590
// -----------------------------------------------------------------------------
// Stable ID: aa_0062b590
// Address:   0x0062b590  (autoassault.exe, image base 0x400000)
// System:    unknown
// Generated: 2026-07-23 from raw capture (scaffold; refine for important units)
// Exactness: Behavior-preserving rewrite of decompiler control flow. Not modernization.
// Bit-for-bit vs retail EXE: DEFERRED (loaded image may differ slightly).
// =============================================================================

// PURPOSE (auto): Scaffold unit for FUN_0062b590 @ 0x0062b590
// Stable ID: aa_0062b590
// No high-value strings recovered; name via xrefs/callers in follow-up.
// Readability: control flow preserved from Ghidra decompile; types tentative.

// READABILITY (auto CF):
//  - Body size: ~54 non-empty decompiler lines.
//  - Control keywords: if×4, while×4, do×2, return×1.
//  - Notable callees: FUN_0062b590.
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

int __thiscall FUN_0062b590(uint32_t /* width from decompiler */ *param_1,int param_2,int param_3)



{

  int *piVar1;

  int iVar2;

  int iVar3;

  int iVar4;

  

  piVar1 = (int *)*param_1;

  iVar2 = *(int *)(*piVar1 + param_2 * 4);

  iVar3 = iVar2;

  if (-1 < iVar2) {

    do {

      iVar4 = iVar3;

      iVar3 = *(int *)(*piVar1 + iVar4 * 4);

    } while (-1 < iVar3);

    while (-1 < iVar2) {

      piVar1 = (int *)(*piVar1 + param_2 * 4);

      param_2 = *piVar1;

      *piVar1 = iVar4;

      piVar1 = (int *)*param_1;

      iVar2 = *(int *)(*piVar1 + param_2 * 4);

    }

  }

  piVar1 = (int *)*param_1;

  iVar2 = *(int *)(*piVar1 + param_3 * 4);

  iVar3 = iVar2;

  if (-1 < iVar2) {

    do {

      iVar4 = iVar3;

      iVar3 = *(int *)(*piVar1 + iVar4 * 4);

    } while (-1 < iVar3);

    while (-1 < iVar2) {

      piVar1 = (int *)(*piVar1 + param_3 * 4);

      param_3 = *piVar1;

      *piVar1 = iVar4;

      piVar1 = (int *)*param_1;

      iVar2 = *(int *)(*piVar1 + param_3 * 4);

    }

  }

  if (param_2 != param_3) {

    iVar3 = *(int *)*param_1;

    if (param_2 < param_3) {

      piVar1 = (int *)(iVar3 + param_2 * 4);

      *piVar1 = *piVar1 + *(int *)(iVar3 + param_3 * 4);

      *(int *)(*(int *)*param_1 + param_3 * 4) = param_2;

      param_3 = param_2;

    }

    else {

      piVar1 = (int *)(iVar3 + param_3 * 4);

      *piVar1 = *piVar1 + *(int *)(iVar3 + param_2 * 4);

      *(int *)(*(int *)*param_1 + param_2 * 4) = param_3;

    }

  }

  return param_3;

}
