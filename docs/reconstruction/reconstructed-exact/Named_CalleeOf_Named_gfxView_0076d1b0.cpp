// =============================================================================
// Named_CalleeOf_Named_gfxView_0076d1b0
// -----------------------------------------------------------------------------
// Stable ID: aa_0076d1b0
// Callee of Named_gfxView (+13 other named callers)
// Address:   0x0076d1b0  (autoassault.exe, image base 0x400000)
// System:    unknown
// Generated: 2026-07-23 from raw capture (scaffold; refine for important units)
// Exactness: Behavior-preserving rewrite of decompiler control flow. Not modernization.
// Bit-for-bit vs retail EXE: DEFERRED (loaded image may differ slightly).
// =============================================================================

// PURPOSE (auto): Called from Named_gfxView: callee helper with no high-value strings in clean/raw. Role inferred from parent name only; refine when decompile strings or xrefs improve. Named_gfxView (+13 other named callers).
// Readability: control flow preserved from Ghidra decompile; types tentative.

// READABILITY (auto CF):
//  - Body size: ~37 non-empty decompiler lines.
//  - Control keywords: if×5, return×3, goto×1, do×1, while×1.
//  - Notable callees: FUN_0076d140×3, FUN_0076d020, FUN_0076d1b0.
//  - Return sites: 3.

/*
 * Behavioral notes:
 * Callee of Named_gfxView (+13 other named callers)
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

int Named_CalleeOf_Named_gfxView_0076d1b0(uint32_t /* width from decompiler */ param_1,uint32_t /* width from decompiler */ param_2)



{

  int *piVar1;

  int iVar2;

  int iVar3;

  int iVar4;

  int iVar5;

  int unaff_EDI;

  

  iVar5 = 0;

  iVar2 = FUN_0076d140();

  if (*(int *)(iVar2 + 8) == 0) {

    iVar5 = FUN_0076d020(param_2);

  }

  else {

    iVar2 = FUN_0076d140();

    iVar2 = **(int **)(iVar2 + 4);

    iVar3 = FUN_0076d140();

    iVar3 = *(int *)(iVar3 + 4);

    if (iVar3 == iVar2) goto LAB_0076d235;

    do {

      piVar1 = *(int **)(*(int *)(iVar3 + 4) + 8);

      if ((piVar1[1] <= unaff_EDI) &&

         (iVar4 = (**(code **)(*piVar1 + 4))(param_1,param_2), iVar5 < iVar4)) {

        iVar5 = iVar4;

      }

      iVar3 = *(int *)(iVar3 + 4);

    } while (iVar3 != iVar2);

  }

  if (1 < iVar5) {

    return iVar5;

  }

LAB_0076d235:

  if (unaff_EDI < 5) {

    return iVar5;

  }

  return 3;

}
