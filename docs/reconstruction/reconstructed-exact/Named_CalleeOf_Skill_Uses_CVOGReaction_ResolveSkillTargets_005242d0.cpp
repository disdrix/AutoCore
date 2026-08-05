// =============================================================================
// Named_CalleeOf_Skill_Uses_CVOGReaction_ResolveSkillTargets_005242d0
// -----------------------------------------------------------------------------
// Stable ID: aa_005242d0
// Callee of Skill_Uses_CVOGReaction_ResolveSkillTargets
// Address:   0x005242d0  (autoassault.exe, image base 0x400000)
// System:    unknown
// Generated: 2026-07-23 from raw capture (scaffold; refine for important units)
// Exactness: Behavior-preserving rewrite of decompiler control flow. Not modernization.
// Bit-for-bit vs retail EXE: DEFERRED (loaded image may differ slightly).
// =============================================================================

// PURPOSE (auto): Called from Skill_Uses_CVOGReaction_ResolveSkillTargets: skill/cast helper with no high-value strings in clean/raw. Role inferred from parent name only; refine when decompile strings or xrefs improve.
// Readability: control flow preserved from Ghidra decompile; types tentative.

// READABILITY (auto CF):
//  - Body size: ~58 non-empty decompiler lines.
//  - Control keywords: if×8, return×3, goto×2.
//  - Notable callees: FUN_00404c90, FUN_004fb500, FUN_005242d0.
//  - Return sites: 3.

/*
 * Behavioral notes:
 * Callee of Skill_Uses_CVOGReaction_ResolveSkillTargets
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

uint32_t /* width from decompiler */ * __thiscall Named_CalleeOf_Skill_Uses_CVOGReaction_ResolveSkillTargets_005242d0(int param_1,uint32_t /* width from decompiler */ *param_2)



{

  int iVar1;

  int *piVar2;

  uint32_t /* width from decompiler */ *puVar3;

  

  iVar1 = *(int *)(*(int *)(param_1 + 4) + 4);

  if (*(char *)(*(int *)(iVar1 + 0xa8 + param_1) + 0xf5) == '\0') {

    if ((*(char *)(param_1 + 0x6b9) != '\0') &&

       (piVar2 = *(int **)(iVar1 + param_1 + 0xa4), piVar2 != (int *)0x0)) {

      iVar1 = (**(code **)(*piVar2 + 0x1c8))();

      if (iVar1 != 0) {

        iVar1 = (**(code **)(**(int **)(*(int *)(*(int *)(param_1 + 4) + 4) + 0xa4 + param_1) +

                            0x1c8))();

        if (*(int *)(iVar1 + 8) == 0) {

          (**(code **)(**(int **)(*(int *)(*(int *)(param_1 + 4) + 4) + 0xa4 + param_1) + 0x1c8))();

          puVar3 = (uint32_t /* width from decompiler */ *)FUN_00404c90();

          *param_2 = *puVar3;

          param_2[1] = puVar3[1];

          param_2[2] = puVar3[2];

          param_2[3] = puVar3[3];

          return param_2;

        }

        piVar2 = *(int **)(*(int *)(*(int *)(param_1 + 4) + 4) + 0xa4 + param_1);

        goto LAB_005243a0;

      }

    }

    if ((*(int *)(param_1 + 0x250) != 0) && (*(char *)(param_1 + 0x30c) != '\0')) {

      FUN_004fb500(param_2);

      return param_2;

    }

    puVar3 = (uint32_t /* width from decompiler */ *)(*(int *)(*(int *)(param_1 + 4) + 4) + 0x84 + param_1);

  }

  else {

    iVar1 = (**(code **)(*(int *)(*(int *)(*(int *)(param_1 + 4) + 4) + 4 + param_1) + 0x1c8))();

    if (iVar1 != 0) {

      iVar1 = (**(code **)(*(int *)(*(int *)(*(int *)(param_1 + 4) + 4) + 4 + param_1) + 0x1c8))();

      if (*(int *)(iVar1 + 8) != 0) {

        piVar2 = (int *)(*(int *)(*(int *)(param_1 + 4) + 4) + 4 + param_1);

LAB_005243a0:

        iVar1 = (**(code **)(*piVar2 + 0x1c8))();

        puVar3 = (uint32_t /* width from decompiler */ *)(*(int *)(*(int *)(iVar1 + 8) + 0x3c) + 0x70);

        goto LAB_0052441f;

      }

    }

    if (*(int *)(param_1 + 8) == 0) {

      puVar3 = (uint32_t /* width from decompiler */ *)(*(int *)(*(int *)(param_1 + 4) + 4) + 0x84 + param_1);

    }

    else {

      puVar3 = (uint32_t /* width from decompiler */ *)(*(int *)(*(int *)(param_1 + 8) + 0x3c) + 0xb0);

    }

  }

LAB_0052441f:

  *param_2 = *puVar3;

  param_2[1] = puVar3[1];

  param_2[2] = puVar3[2];

  param_2[3] = puVar3[3];

  return param_2;

}
