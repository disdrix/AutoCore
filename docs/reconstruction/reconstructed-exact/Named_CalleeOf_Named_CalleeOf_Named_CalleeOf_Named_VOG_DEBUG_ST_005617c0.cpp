// =============================================================================
// Named_CalleeOf_Named_CalleeOf_Named_CalleeOf_Named_VOG_DEBUG_ST_005617c0
// -----------------------------------------------------------------------------
// Stable ID: aa_005617c0
// Callee of Named_CalleeOf_Named_CalleeOf_Named_VOG_DEBUG_STOP
// Address:   0x005617c0  (autoassault.exe, image base 0x400000)
// System:    unknown
// Generated: 2026-07-23 from raw capture (scaffold; refine for important units)
// Exactness: Behavior-preserving rewrite of decompiler control flow. Not modernization.
// Bit-for-bit vs retail EXE: DEFERRED (loaded image may differ slightly).
// =============================================================================

// PURPOSE (auto): Called from Named_CalleeOf_Named_CalleeOf_Named_VOG_DEBUG_STOP: callee helper with no high-value strings in clean/raw. Role inferred from parent name only; refine when decompile strings or xrefs improve.
// Readability: control flow preserved from Ghidra decompile; types tentative.

// READABILITY (auto CF):
//  - Body size: ~52 non-empty decompiler lines.
//  - Control keywords: if×4, do×2, while×2, return×1.
//  - Notable callees: FUN_005614f0, FUN_005617c0, FUN_005b3370.
//  - Return sites: 1.

/*
 * Behavioral notes:
 * Callee of Named_CalleeOf_Named_CalleeOf_Named_VOG_DEBUG_STOP
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

void __thiscall Named_CalleeOf_Named_CalleeOf_Named_CalleeOf_Named_VOG_DEBUG_ST_005617c0(int param_1,int param_2,int *param_3)



{

  int iVar1;

  int iVar2;

  int iVar3;

  int iVar4;

  int *piVar5;

  int iVar6;

  int *piVar7;

  int iVar8;

  int local_14;

  uint8_t local_10 [16];

  

  piVar5 = param_3;

  iVar3 = *(int *)(param_1 + 0x2c);

  iVar8 = 0;

  piVar7 = (int *)(iVar3 + 0x58);

  param_3[1] = 0;

  local_14 = param_1;

  if (0 < *(int *)(iVar3 + 0x5c)) {

    do {

      iVar4 = *(int *)(*piVar7 + iVar8 * 4);

      param_3 = (int *)(*piVar7 + iVar8 * 4);

      if ((*(int *)(iVar4 + 0xc) == param_2) || (*(int *)(iVar4 + 0x10) == param_2)) {

        if (piVar5[1] == (piVar5[2] & 0x7fffffffU)) {

          FUN_005b3370(piVar5,4);

        }

        *(int *)(*piVar5 + piVar5[1] * 4) = *param_3;

        piVar5[1] = piVar5[1] + 1;

        (**(code **)(**(int **)(*piVar7 + iVar8 * 4) + 0x28))(local_10);

        (**(code **)(**(int **)(param_1 + 0x2c) + 0xc))

                  (*(uint32_t /* width from decompiler */ *)(*piVar7 + iVar8 * 4),&local_14);

        iVar4 = *(int *)(param_1 + 0x2c);

        *(int *)(iVar4 + 0x5c) = *(int *)(iVar4 + 0x5c) + -1;

        iVar6 = iVar8;

        if (iVar8 < *(int *)(iVar4 + 0x5c)) {

          do {

            iVar2 = iVar6 * 4;

            iVar1 = iVar6 * 4;

            iVar6 = iVar6 + 1;

            *(uint32_t /* width from decompiler */ *)(*(int *)(iVar4 + 0x58) + iVar1) =

                 *(uint32_t /* width from decompiler */ *)(*(int *)(iVar4 + 0x58) + 4 + iVar2);

            param_1 = local_14;

          } while (iVar6 < *(int *)(iVar4 + 0x5c));

        }

        iVar8 = iVar8 + -1;

      }

      iVar8 = iVar8 + 1;

    } while (iVar8 < *(int *)(iVar3 + 0x5c));

  }

  FUN_005614f0(&param_2,param_2);

  return;

}
