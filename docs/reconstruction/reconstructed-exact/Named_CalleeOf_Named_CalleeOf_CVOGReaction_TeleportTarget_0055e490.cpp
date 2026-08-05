// =============================================================================
// Named_CalleeOf_Named_CalleeOf_CVOGReaction_TeleportTarget_0055e490
// -----------------------------------------------------------------------------
// Stable ID: aa_0055e490
// Callee of Named_CalleeOf_CVOGReaction_TeleportTarget
// Address:   0x0055e490  (autoassault.exe, image base 0x400000)
// System:    unknown
// Generated: 2026-07-23 from raw capture (scaffold; refine for important units)
// Exactness: Behavior-preserving rewrite of decompiler control flow. Not modernization.
// Bit-for-bit vs retail EXE: DEFERRED (loaded image may differ slightly).
// =============================================================================

// PURPOSE (auto): Called from Named_CalleeOf_CVOGReaction_TeleportTarget: spawn/transfer helper with no high-value strings in clean/raw. Role inferred from parent name only; refine when decompile strings or xrefs improve.
// Readability: control flow preserved from Ghidra decompile; types tentative.

// READABILITY (auto CF):
//  - Body size: ~33 non-empty decompiler lines.
//  - Control keywords: if×5, do×2, while×2, goto×1, return×1.
//  - Notable callees: FUN_0055e490.
//  - Return sites: 1.

/*
 * Behavioral notes:
 * Callee of Named_CalleeOf_CVOGReaction_TeleportTarget
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

void __thiscall Named_CalleeOf_Named_CalleeOf_CVOGReaction_TeleportTarget_0055e490(int param_1,uint32_t /* width from decompiler */ *param_2)



{

  int iVar1;

  int *piVar2;

  int iVar3;

  

  iVar3 = 0;

  if (0 < *(int *)(param_1 + 0x10c)) {

    do {

      if (*(uint32_t /* width from decompiler */ **)(*(int *)(param_1 + 0x108) + iVar3 * 4) == param_2) {

        iVar1 = 0;

        if (0 < *(int *)(param_1 + 0x10c)) {

          piVar2 = *(int **)(param_1 + 0x108);

          do {

            if ((uint32_t /* width from decompiler */ *)*piVar2 == param_2) goto LAB_0055e4e0;

            iVar1 = iVar1 + 1;

            piVar2 = piVar2 + 1;

          } while (iVar1 < *(int *)(param_1 + 0x10c));

        }

        iVar1 = -1;

LAB_0055e4e0:

        *(int *)(param_1 + 0x10c) = *(int *)(param_1 + 0x10c) + -1;

        *(uint32_t /* width from decompiler */ *)(*(int *)(param_1 + 0x108) + iVar1 * 4) =

             *(uint32_t /* width from decompiler */ *)(*(int *)(param_1 + 0x108) + *(int *)(param_1 + 0x10c) * 4);

        *(short *)((int)param_2 + 6) = *(short *)((int)param_2 + 6) + -1;

        if (*(short *)((int)param_2 + 6) == 0) {

          (**(code **)*param_2)(1);

        }

      }

      iVar3 = iVar3 + 1;

    } while (iVar3 < *(int *)(param_1 + 0x10c));

  }

  return;

}
