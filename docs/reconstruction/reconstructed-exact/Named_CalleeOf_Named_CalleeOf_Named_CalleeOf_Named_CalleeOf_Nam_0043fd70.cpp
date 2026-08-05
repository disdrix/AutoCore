// =============================================================================
// Named_CalleeOf_Named_CalleeOf_Named_CalleeOf_Named_CalleeOf_Nam_0043fd70
// -----------------------------------------------------------------------------
// Stable ID: aa_0043fd70
// Callee of Named_CalleeOf_Named_CalleeOf_Named_CalleeOf_Named_gfxLightMana
// Address:   0x0043fd70  (autoassault.exe, image base 0x400000)
// System:    unknown
// Generated: 2026-07-23 from raw capture (scaffold; refine for important units)
// Exactness: Behavior-preserving rewrite of decompiler control flow. Not modernization.
// Bit-for-bit vs retail EXE: DEFERRED (loaded image may differ slightly).
// =============================================================================

// PURPOSE (auto): Called from Named_CalleeOf_Named_CalleeOf_Named_CalleeOf_Named_gfxLightMana: callee helper with no high-value strings in clean/raw. Role inferred from parent name only; refine when decompile strings or xrefs improve.
// Readability: control flow preserved from Ghidra decompile; types tentative.

// READABILITY (auto CF):
//  - Body size: ~31 non-empty decompiler lines.
//  - Control keywords: if×2, return×2, while×1.
//  - Notable callees: FUN_0043fd70.
//  - Return sites: 2.

/*
 * Behavioral notes:
 * Callee of Named_CalleeOf_Named_CalleeOf_Named_CalleeOf_Named_gfxLightMana
 * Xref/callee-driven rename (parent seed scan)
 *
 * - Derived from Ghidra decompile; names prefer Ghidra symbols / plate comments.
 * - Remaining FUN_* / DAT_* identifiers are unresolved pending type recovery.
 * - Runtime / differential verification: OPEN unless matrix says otherwise.
 *
 * Readability pass:
 * - undefinedN widths preserved as fixed-width integers where decompiler width is known.
 * - Control flow and call order preserved from authoritative raw.
 */

int * Named_CalleeOf_Named_CalleeOf_Named_CalleeOf_Named_CalleeOf_Nam_0043fd70(int *param_1)



{

  int iVar1;

  int *piVar2;

  int iVar3;

  uint uVar4;

  int *unaff_EBX;

  int unaff_EDI;

  

  uVar4 = param_1[2] & *(uint *)(unaff_EDI + 0x20);

  if (*(uint *)(unaff_EDI + 0x24) <= uVar4) {

    uVar4 = uVar4 + (-1 - (*(uint *)(unaff_EDI + 0x20) >> 1));

  }

  iVar3 = *(int *)(unaff_EDI + 0x14);

  iVar1 = uVar4 * 4;

  piVar2 = *(int **)(iVar1 + iVar3);

  while ((param_1 == piVar2 &&

         (*(uint32_t /* width from decompiler */ *)(iVar1 + iVar3) = **(uint32_t /* width from decompiler */ **)(iVar1 + iVar3), uVar4 != 0))) {

    iVar3 = *(int *)(unaff_EDI + 0x14);

    uVar4 = uVar4 - 1;

    iVar1 = uVar4 * 4;

    piVar2 = *(int **)(iVar1 + iVar3);

  }

  if (param_1 != *(int **)(unaff_EDI + 8)) {

    *(int *)param_1[1] = *param_1;

    *(int *)(*param_1 + 4) = param_1[1];

                    /* WARNING: Subroutine does not return */

    operator_delete(param_1);

  }

  *unaff_EBX = *param_1;

  return unaff_EBX;

}
