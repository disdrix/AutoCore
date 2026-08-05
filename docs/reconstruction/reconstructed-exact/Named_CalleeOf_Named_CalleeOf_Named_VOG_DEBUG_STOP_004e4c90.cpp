// =============================================================================
// Named_CalleeOf_Named_CalleeOf_Named_VOG_DEBUG_STOP_004e4c90
// -----------------------------------------------------------------------------
// Stable ID: aa_004e4c90
// Callee of Named_CalleeOf_Named_VOG_DEBUG_STOP
// Address:   0x004e4c90  (autoassault.exe, image base 0x400000)
// System:    unknown
// Generated: 2026-07-23 from raw capture (scaffold; refine for important units)
// Exactness: Behavior-preserving rewrite of decompiler control flow. Not modernization.
// Bit-for-bit vs retail EXE: DEFERRED (loaded image may differ slightly).
// =============================================================================

// PURPOSE (auto): Called from Named_CalleeOf_Named_VOG_DEBUG_STOP: callee helper with no high-value strings in clean/raw. Role inferred from parent name only; refine when decompile strings or xrefs improve.
// Readability: control flow preserved from Ghidra decompile; types tentative.

// READABILITY (auto CF):
//  - Body size: ~50 non-empty decompiler lines.
//  - Control keywords: if×3, while×3, return×2.
//  - Notable callees: FUN_00406750, FUN_004e3bb0, FUN_004e4c90.
//  - Return sites: 2.

/*
 * Behavioral notes:
 * Callee of Named_CalleeOf_Named_VOG_DEBUG_STOP
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

void __thiscall Named_CalleeOf_Named_CalleeOf_Named_VOG_DEBUG_STOP_004e4c90(int param_1,uint32_t /* width from decompiler */ *param_2,int *param_3,int *param_4)



{

  char cVar1;

  int *piVar2;

  int *piVar3;

  int *piVar4;

  int *piVar5;

  int *piVar6;

  

  piVar4 = param_4;

  piVar6 = *(int **)(param_1 + 4);

  piVar3 = param_3;

  if ((param_3 == (int *)*piVar6) && (param_4 == piVar6)) {

    FUN_00406750(piVar6[1]);

    *(int *)(*(int *)(param_1 + 4) + 4) = *(int *)(param_1 + 4);

    *(uint32_t /* width from decompiler */ *)(param_1 + 8) = 0;

    *(uint32_t /* width from decompiler */ *)*(uint32_t /* width from decompiler */ *)(param_1 + 4) = *(uint32_t /* width from decompiler */ *)(param_1 + 4);

    *(int *)(*(int *)(param_1 + 4) + 8) = *(int *)(param_1 + 4);

    *param_2 = **(uint32_t /* width from decompiler */ **)(param_1 + 4);

    return;

  }

  while (piVar3 != piVar4) {

    piVar6 = piVar3;

    if (*(char *)((int)piVar3 + 0x15) == '\0') {

      piVar6 = (int *)piVar3[2];

      if (*(char *)((int)piVar6 + 0x15) == '\0') {

        cVar1 = *(char *)(*piVar6 + 0x15);

        piVar2 = (int *)*piVar6;

        while (cVar1 == '\0') {

          cVar1 = *(char *)(*piVar2 + 0x15);

          piVar6 = piVar2;

          piVar2 = (int *)*piVar2;

        }

      }

      else {

        cVar1 = *(char *)(piVar3[1] + 0x15);

        piVar5 = (int *)piVar3[1];

        piVar2 = piVar3;

        while ((piVar6 = piVar5, cVar1 == '\0' && (piVar2 == (int *)piVar6[2]))) {

          cVar1 = *(char *)(piVar6[1] + 0x15);

          piVar5 = (int *)piVar6[1];

          piVar2 = piVar6;

        }

      }

    }

    FUN_004e3bb0(&param_3,piVar3);

    piVar3 = piVar6;

  }

  *param_2 = piVar3;

  return;

}
