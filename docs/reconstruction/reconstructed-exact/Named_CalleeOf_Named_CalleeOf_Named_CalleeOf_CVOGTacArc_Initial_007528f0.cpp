// =============================================================================
// Named_CalleeOf_Named_CalleeOf_Named_CalleeOf_CVOGTacArc_Initial_007528f0
// -----------------------------------------------------------------------------
// Stable ID: aa_007528f0
// Callee of Named_CalleeOf_Named_CalleeOf_CVOGTacArc_InitializeMesh
// Address:   0x007528f0  (autoassault.exe, image base 0x400000)
// System:    unknown
// Generated: 2026-07-23 from raw capture (scaffold; refine for important units)
// Exactness: Behavior-preserving rewrite of decompiler control flow. Not modernization.
// Bit-for-bit vs retail EXE: DEFERRED (loaded image may differ slightly).
// =============================================================================

// PURPOSE (auto): Called from Named_CalleeOf_Named_CalleeOf_CVOGTacArc_InitializeMesh: callee helper with no high-value strings in clean/raw. Role inferred from parent name only; refine when decompile strings or xrefs improve.
// Readability: control flow preserved from Ghidra decompile; types tentative.

// READABILITY (auto CF):
//  - Body size: ~47 non-empty decompiler lines.
//  - Control keywords: if×9, return×2.
//  - Notable callees: FUN_007528f0.
//  - Return sites: 2.

/*
 * Behavioral notes:
 * Callee of Named_CalleeOf_Named_CalleeOf_CVOGTacArc_InitializeMesh
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

uint32_t /* width from decompiler */ __thiscall Named_CalleeOf_Named_CalleeOf_Named_CalleeOf_CVOGTacArc_Initial_007528f0(int param_1,int param_2,int param_3)



{

  int *piVar1;

  int iVar2;

  int *piVar3;

  

  if (param_2 < 0) {

    return 0xffffffff;

  }

  piVar3 = (int *)((uint)*(ushort *)(*(int *)(*(int *)(param_1 + 8) + 0x10) + 4 + param_2 * 8) +

                  *(int *)(param_1 + 0xc));

  iVar2 = piVar3[1];

  if ((iVar2 != param_3) || ((param_3 != 0 && (*piVar3 != *(int *)(param_3 + 0x10))))) {

    if (iVar2 != 0) {

      piVar1 = (int *)(iVar2 + 8);

      *piVar1 = *piVar1 + -1;

      if (*piVar1 == 0) {

        (**(code **)(*(int *)(iVar2 + 4) + 8))();

      }

    }

    piVar1 = (int *)*piVar3;

    if (piVar1 != (int *)0x0) {

      (**(code **)(*piVar1 + 8))(piVar1);

    }

    piVar3[1] = param_3;

    if (param_3 == 0) {

      *piVar3 = 0;

    }

    else {

      *(int *)(param_3 + 8) = *(int *)(param_3 + 8) + 1;

      if (*(int *)(param_3 + 8) == 1) {

        (**(code **)(*(int *)(param_3 + 4) + 4))();

      }

      piVar1 = *(int **)(param_3 + 0x10);

      *piVar3 = (int)piVar1;

      if (piVar1 != (int *)0x0) {

        (**(code **)(*piVar1 + 4))(piVar1);

      }

    }

    if (DAT_00afe038 == *(int *)(param_1 + 0xc)) {

      piVar1 = *(int **)(*(int *)(param_1 + 8) + 0xc);

      (**(code **)(*piVar1 + 0xd0))

                (piVar1,*(uint32_t /* width from decompiler */ *)(*(int *)(*(int *)(param_1 + 8) + 0x10) + param_2 * 8),piVar3

                );

    }

  }

  return 0;

}
