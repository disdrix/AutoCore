// SUPERSEDED 2026-07-29 W27-D: scaffold chain name rejected.
// Prefer ObjectMotion_SlotListTick_Inferred.cpp / FUN_005bb5e0.cpp
// =============================================================================
// Named_CalleeOf_Named_CalleeOf_Named_CalleeOf_Named_CalleeOf_Cli_005bb5e0
// -----------------------------------------------------------------------------
// Stable ID: aa_005bb5e0
// Callee of Named_CalleeOf_Named_CalleeOf_Named_CalleeOf_Client_Input_PollB
// Address:   0x005bb5e0  (autoassault.exe, image base 0x400000)
// System:    unknown
// Generated: 2026-07-23 from raw capture (scaffold; refine for important units)
// Exactness: Behavior-preserving rewrite of decompiler control flow. Not modernization.
// Bit-for-bit vs retail EXE: DEFERRED (loaded image may differ slightly).
// =============================================================================

// PURPOSE (auto): Called from Named_CalleeOf_Named_CalleeOf_Named_CalleeOf_Client_Input_PollB: input/binding helper with no high-value strings in clean/raw. Role inferred from parent name only; refine when decompile strings or xrefs improve.
// Readability: control flow preserved from Ghidra decompile; types tentative.

// READABILITY (auto CF):
//  - Body size: ~31 non-empty decompiler lines.
//  - Control keywords: if×3, return×2, do×1, while×1.
//  - Notable callees: FUN_004b4620, FUN_005bb5e0, FUN_005be2b0.
//  - Return sites: 2.

/*
 * Behavioral notes:
 * Callee of Named_CalleeOf_Named_CalleeOf_Named_CalleeOf_Client_Input_PollB
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

/* WARNING: Globals starting with '_' overlap smaller symbols at the same address */



uint32_t /* width from decompiler */ __thiscall Named_CalleeOf_Named_CalleeOf_Named_CalleeOf_Named_CalleeOf_Cli_005bb5e0(int param_1,uint32_t /* width from decompiler */ *param_2,uint32_t /* width from decompiler */ param_3)



{

  int iVar1;

  char cVar2;

  int *piVar3;

  int *piVar4;

  

  _DAT_00af3f68 = *param_2;

  piVar3 = (int *)**(int **)(param_1 + 0xa24);

  if (piVar3 != *(int **)(param_1 + 0xa24)) {

    do {

      iVar1 = piVar3[2];

      cVar2 = FUN_004b4620(param_3,*param_2);

      if (cVar2 == '\0') {

        FUN_005be2b0(iVar1);

        piVar4 = (int *)*piVar3;

        if (piVar3 != *(int **)(param_1 + 0xa24)) {

          *(int **)piVar3[1] = piVar4;

          *(int *)(*piVar3 + 4) = piVar3[1];

                    /* WARNING: Subroutine does not return */

          operator_delete(piVar3);

        }

      }

      else {

        piVar4 = (int *)*piVar3;

      }

      piVar3 = piVar4;

    } while (piVar4 != *(int **)(param_1 + 0xa24));

  }

  return *(uint32_t /* width from decompiler */ *)(param_1 + 0xa28);

}
