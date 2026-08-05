// =============================================================================
// Named_CalleeOf_Named_CalleeOf_Named_VOG_DEBUG_STOP_006caaa0
// -----------------------------------------------------------------------------
// Stable ID: aa_006caaa0
// Callee of Named_CalleeOf_Named_VOG_DEBUG_STOP (+1 other named callers)
// Address:   0x006caaa0  (autoassault.exe, image base 0x400000)
// System:    unknown
// Generated: 2026-07-23 from raw capture (scaffold; refine for important units)
// Exactness: Behavior-preserving rewrite of decompiler control flow. Not modernization.
// Bit-for-bit vs retail EXE: DEFERRED (loaded image may differ slightly).
// =============================================================================

// PURPOSE (auto): Called from Named_CalleeOf_Named_VOG_DEBUG_STOP: callee helper with no high-value strings in clean/raw. Role inferred from parent name only; refine when decompile strings or xrefs improve. Named_CalleeOf_Named_VOG_DEBUG_STOP (+1 other named callers).
// Readability: control flow preserved from Ghidra decompile; types tentative.

// READABILITY (auto CF):
//  - Body size: ~88 non-empty decompiler lines.
//  - Control keywords: if×12, do×3, while×3, return×1.
//  - Notable callees: FUN_006caaa0.
//  - Return sites: 1.

/*
 * Behavioral notes:
 * Callee of Named_CalleeOf_Named_VOG_DEBUG_STOP (+1 other named callers)
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

void __thiscall

Named_CalleeOf_Named_CalleeOf_Named_VOG_DEBUG_STOP_006caaa0(int param_1,int *param_2,int *param_3,int *param_4,int param_5,uint32_t /* width from decompiler */ *param_6)



{

  int *piVar1;

  uint uVar2;

  uint uVar3;

  int iVar4;

  char *pcVar5;

  int iVar6;

  uint32_t /* width from decompiler */ *puVar7;

  int *piVar8;

  int *piVar9;

  

  param_3 = param_2 + (int)param_3 * 2;

  piVar1 = param_4 + param_5 * 2;

  puVar7 = param_6;

  piVar8 = param_2;

  piVar9 = param_4;

  param_4 = piVar1;

  if (param_2 != param_3) {

    do {

      if (piVar9 == param_4) break;

      uVar2 = *(uint *)(*piVar8 + 4);

      uVar3 = *(uint *)(*piVar9 + 4);

      if ((uVar3 == uVar2) && (puVar7 = param_6, *(int *)(piVar9[1] + 4) == *(int *)(piVar8[1] + 4))

         ) {

        piVar8 = piVar8 + 2;

        piVar9 = piVar9 + 2;

      }

      else if ((uVar3 < uVar2) ||

              ((uVar3 == uVar2 && (*(uint *)(piVar9[1] + 4) < *(uint *)(piVar8[1] + 4))))) {

        (**(code **)(**(int **)(param_1 + (*(int *)(piVar9[1] + 8) + *(int *)(*piVar9 + 8) * 8) * 4)

                    + 8))(piVar9);

        piVar9 = piVar9 + 2;

      }

      else {

        if (*piVar8 == 0) {

          iVar6 = 0;

        }

        else {

          iVar6 = *piVar8 + -0x10;

        }

        if (piVar8[1] == 0) {

          iVar4 = 0;

        }

        else {

          iVar4 = piVar8[1] + -0x10;

        }

        pcVar5 = (char *)(**(code **)*puVar7)(&param_2,iVar6,iVar4);

        if (*pcVar5 != '\0') {

          (**(code **)(**(int **)(param_1 +

                                 (*(int *)(piVar8[1] + 8) + *(int *)(*piVar8 + 8) * 8) * 4) + 4))

                    (piVar8);

        }

        piVar8 = piVar8 + 2;

      }

    } while (piVar8 != param_3);

  }

  if (piVar8 < param_3) {

    do {

      if (*piVar8 == 0) {

        iVar6 = 0;

      }

      else {

        iVar6 = *piVar8 + -0x10;

      }

      if (piVar8[1] == 0) {

        iVar4 = 0;

      }

      else {

        iVar4 = piVar8[1] + -0x10;

      }

      pcVar5 = (char *)(**(code **)*puVar7)(&param_6,iVar6,iVar4);

      if (*pcVar5 != '\0') {

        (**(code **)(**(int **)(param_1 + (*(int *)(piVar8[1] + 8) + *(int *)(*piVar8 + 8) * 8) * 4)

                    + 4))(piVar8);

      }

      piVar8 = piVar8 + 2;

    } while (piVar8 < param_3);

  }

  if (piVar9 < param_4) {

    do {

      (**(code **)(**(int **)(param_1 + (*(int *)(piVar9[1] + 8) + *(int *)(*piVar9 + 8) * 8) * 4) +

                  8))(piVar9);

      piVar9 = piVar9 + 2;

    } while (piVar9 < param_4);

  }

  return;

}
