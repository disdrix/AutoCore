// =============================================================================
// Named_CalleeOf_Named_CalleeOf_Named_CalleeOf_CVOGReaction_Telep_0062a6c0
// -----------------------------------------------------------------------------
// Stable ID: aa_0062a6c0
// Callee of Named_CalleeOf_Named_CalleeOf_CVOGReaction_TeleportTarget
// Address:   0x0062a6c0  (autoassault.exe, image base 0x400000)
// System:    unknown
// Generated: 2026-07-23 from raw capture (scaffold; refine for important units)
// Exactness: Behavior-preserving rewrite of decompiler control flow. Not modernization.
// Bit-for-bit vs retail EXE: DEFERRED (loaded image may differ slightly).
// =============================================================================

// PURPOSE (auto): Called from Named_CalleeOf_Named_CalleeOf_CVOGReaction_TeleportTarget: spawn/transfer helper with no high-value strings in clean/raw. Role inferred from parent name only; refine when decompile strings or xrefs improve.
// Readability: control flow preserved from Ghidra decompile; types tentative.

// READABILITY (auto CF):
//  - Body size: ~46 non-empty decompiler lines.
//  - Control keywords: while×5, if×4, do×2, return×1.
//  - Notable callees: FUN_005fff20, FUN_0062a6c0.
//  - Return sites: 1.

/*
 * Behavioral notes:
 * Callee of Named_CalleeOf_Named_CalleeOf_CVOGReaction_TeleportTarget
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

void Named_CalleeOf_Named_CalleeOf_Named_CalleeOf_CVOGReaction_Telep_0062a6c0(int param_1,int param_2)



{

  int iVar1;

  int iVar2;

  int *piVar3;

  int iVar4;

  int iVar5;

  int iVar6;

  int *piVar7;

  

  iVar6 = *(int *)(param_1 + 0x7c);

  while (iVar6 = iVar6 + -1, -1 < iVar6) {

    piVar7 = *(int **)(*(int *)(param_1 + 0x78) + iVar6 * 4);

    if (piVar7 != (int *)0x0) {

      (**(code **)(*piVar7 + 4))(param_2);

    }

  }

  FUN_005fff20();

  iVar6 = 0;

  if (0 < *(int *)(param_2 + 0x40)) {

    do {

      iVar1 = *(int *)(*(int *)(param_2 + 0x3c) + iVar6 * 4);

      iVar2 = *(int *)(iVar1 + 0x74);

      piVar7 = (int *)(iVar1 + 0x70);

      while (iVar2 = iVar2 + -1, -1 < iVar2) {

        piVar3 = *(int **)(*piVar7 + iVar2 * 4);

        if (piVar3 != (int *)0x0) {

          (**(code **)(*piVar3 + 8))(*(uint32_t /* width from decompiler */ *)(*(int *)(param_2 + 0x3c) + iVar6 * 4));

        }

      }

      iVar2 = *(int *)(iVar1 + 0x74);

      while (iVar2 = iVar2 + -1, -1 < iVar2) {

        if ((*(int *)(*piVar7 + iVar2 * 4) == 0) &&

           (*(int *)(iVar1 + 0x74) = *(int *)(iVar1 + 0x74) + -1, iVar4 = iVar2,

           iVar2 < *(int *)(iVar1 + 0x74))) {

          do {

            iVar5 = iVar4 + 1;

            *(uint32_t /* width from decompiler */ *)(*piVar7 + iVar4 * 4) = *(uint32_t /* width from decompiler */ *)(*piVar7 + 4 + iVar4 * 4);

            iVar4 = iVar5;

          } while (iVar5 < *(int *)(iVar1 + 0x74));

        }

      }

      iVar6 = iVar6 + 1;

    } while (iVar6 < *(int *)(param_2 + 0x40));

  }

  return;

}
