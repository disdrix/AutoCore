// =============================================================================
// FUN_0043bcc0
// -----------------------------------------------------------------------------
// Stable ID: aa_0043bcc0
// Address:   0x0043bcc0  (autoassault.exe, image base 0x400000)
// System:    unknown
// Generated: 2026-07-23 from raw capture (scaffold; refine for important units)
// Exactness: Behavior-preserving rewrite of decompiler control flow. Not modernization.
// Bit-for-bit vs retail EXE: DEFERRED (loaded image may differ slightly).
// =============================================================================

// PURPOSE (auto): Scaffold unit for FUN_0043bcc0 @ 0x0043bcc0
// Stable ID: aa_0043bcc0
// No high-value strings recovered; name via xrefs/callers in follow-up.
// Readability: control flow preserved from Ghidra decompile; types tentative.

// READABILITY (auto CF):
//  - Body size: ~33 non-empty decompiler lines.
//  - Control keywords: if×2, return×2, while×1.
//  - Notable callees: FUN_0043b870, FUN_0043bcc0.
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

int * FUN_0043bcc0(int *param_1,int *param_2)



{

  int iVar1;

  int *piVar2;

  uint uVar3;

  int iVar4;

  uint uVar5;

  int unaff_EDI;

  

  uVar3 = *(uint *)(unaff_EDI + 0x20);

  uVar5 = FUN_0043b870();

  uVar5 = uVar5 & uVar3;

  if (*(uint *)(unaff_EDI + 0x24) <= uVar5) {

    uVar5 = uVar5 + (-1 - (uVar3 >> 1));

  }

  iVar4 = *(int *)(unaff_EDI + 0x14);

  iVar1 = uVar5 * 4;

  piVar2 = *(int **)(iVar1 + iVar4);

  while ((param_2 == piVar2 &&

         (*(uint32_t /* width from decompiler */ *)(iVar1 + iVar4) = **(uint32_t /* width from decompiler */ **)(iVar1 + iVar4), uVar5 != 0))) {

    iVar4 = *(int *)(unaff_EDI + 0x14);

    uVar5 = uVar5 - 1;

    iVar1 = uVar5 * 4;

    piVar2 = *(int **)(iVar1 + iVar4);

  }

  if (param_2 == *(int **)(unaff_EDI + 8)) {

    *param_1 = *param_2;

    return param_1;

  }

  *(int *)param_2[1] = *param_2;

  *(int *)(*param_2 + 4) = param_2[1];

                    /* WARNING: Subroutine does not return */

  operator_delete(param_2);

}
