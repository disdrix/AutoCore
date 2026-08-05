// =============================================================================
// Named_CalleeOf_Named_CalleeOf_Named_CalleeOf_Client_Input_PollB_007fdcc0
// -----------------------------------------------------------------------------
// Stable ID: aa_007fdcc0
// Callee of Named_CalleeOf_Named_CalleeOf_Client_Input_PollBoundActions
// Address:   0x007fdcc0  (autoassault.exe, image base 0x400000)
// System:    unknown
// Generated: 2026-07-23 from raw capture (scaffold; refine for important units)
// Exactness: Behavior-preserving rewrite of decompiler control flow. Not modernization.
// Bit-for-bit vs retail EXE: DEFERRED (loaded image may differ slightly).
// =============================================================================

// PURPOSE (auto): Called from Named_CalleeOf_Named_CalleeOf_Client_Input_PollBoundActions: input/binding helper with no high-value strings in clean/raw. Role inferred from parent name only; refine when decompile strings or xrefs improve.
// Readability: control flow preserved from Ghidra decompile; types tentative.

// READABILITY (auto CF):
//  - Body size: ~40 non-empty decompiler lines.
//  - Control keywords: if×6, while×1, return×1.
//  - Notable callees: FUN_00418690, FUN_007fdcc0, memmove.
//  - Return sites: 1.

/*
 * Behavioral notes:
 * Callee of Named_CalleeOf_Named_CalleeOf_Client_Input_PollBoundActions
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

void Named_CalleeOf_Named_CalleeOf_Named_CalleeOf_Client_Input_PollB_007fdcc0(int param_1)



{

  int *piVar1;

  int iVar2;

  int *_Dst;

  int *piVar3;

  char cVar4;

  

  if ((((*(int **)(param_1 + 0xf40) == (int *)0x0) ||

       (iVar2 = **(int **)(param_1 + 0xf40), iVar2 == 0)) ||

      (iVar2 = *(int *)(iVar2 + 0x4c0), iVar2 == 0)) || (*(char *)(iVar2 + 0x1d) == '\0')) {

    iVar2 = *(int *)(param_1 + 0x1148);

    if (((iVar2 != 0) && (*(int *)(iVar2 + 0x2b0) != 0)) && (*(int *)(param_1 + 0xf38) != 0)) {

      (**(code **)(**(int **)(param_1 + 0xf38) + 0xb0))(iVar2);

    }

    if ((*(int *)(param_1 + 0x3078) != 0) &&

       (*(int *)(param_1 + 0x307c) - *(int *)(param_1 + 0x3078) >> 2 != 0)) {

      _Dst = *(int **)(param_1 + 0x3078);

      piVar1 = *(int **)(param_1 + 0x307c);

      while (_Dst != piVar1) {

        piVar1 = (int *)*_Dst;

        if (piVar1 != (int *)0x0) {

          piVar3 = (int *)piVar1[0xac];

          cVar4 = (**(code **)(*piVar1 + 0x3d8))();

          if (cVar4 != '\0') {

            (**(code **)(*piVar1 + 0x440))();

          }

          if (piVar3 != (int *)0x0) {

            (**(code **)(*piVar3 + 0xb0))(piVar1);

          }

          (**(code **)*piVar1)(1);

        }

        memmove(_Dst,_Dst + 1,(*(int *)(param_1 + 0x307c) - (int)(_Dst + 1) >> 2) * 4);

        *(int *)(param_1 + 0x307c) = *(int *)(param_1 + 0x307c) + -4;

        piVar1 = *(int **)(param_1 + 0x307c);

      }

      FUN_00418690(0);

    }

  }

  return;

}
