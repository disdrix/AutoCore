// =============================================================================
// FUN_00525cc0
// -----------------------------------------------------------------------------
// Stable ID: aa_00525cc0
// Address:   0x00525cc0  (autoassault.exe, image base 0x400000)
// System:    unknown
// Generated: 2026-07-23 from raw capture (scaffold; refine for important units)
// Exactness: Behavior-preserving rewrite of decompiler control flow. Not modernization.
// Bit-for-bit vs retail EXE: DEFERRED (loaded image may differ slightly).
// =============================================================================

// PURPOSE (auto): Scaffold unit for FUN_00525cc0 @ 0x00525cc0
// Stable ID: aa_00525cc0
// No high-value strings recovered; name via xrefs/callers in follow-up.
// Readability: control flow preserved from Ghidra decompile; types tentative.

// READABILITY (auto CF):
//  - Body size: ~57 non-empty decompiler lines.
//  - Control keywords: if×9, return×5, goto×2.
//  - Notable callees: CNDHash_LookupByKey×2, FUN_0040abd0×2, Skill_SetRankAndReevaluate×2, CVOGReaction_CastSkillOnTarget, FUN_00525cc0, Skill_LookupActiveCastBinding, TFID_NotEquals.
//  - Return sites: 5.

/*
 * Behavioral notes:
 * - Derived from Ghidra decompile; names prefer Ghidra symbols / plate comments.
 * - Remaining FUN_* / DAT_* identifiers are unresolved pending type recovery.
 * - Runtime / differential verification: OPEN unless matrix says otherwise.
 *
 * Readability pass:
 * - undefinedN widths preserved as fixed-width integers where decompiler width is known.
 * - Control flow and call order preserved from authoritative raw.
 */

uint32_t /* width from decompiler */ __thiscall FUN_00525cc0(int param_1,int param_2,char param_3)



{

  int iVar1;

  uint uVar2;

  void *pvVar3;

  void *pA;

  int iVar4;

  void *pvVar5;

  short unaff_DI;

  uint32_t /* width from decompiler */ *pB;

  uint8_t local_10 [16];

  

  if (((param_2 < -1) || (2 < param_2)) ||

     ((iVar4 = *(int *)(param_1 + 0xd64), iVar4 == param_2 && (param_3 != '\x01')))) {

    return 0;

  }

  iVar1 = *(int *)(*(int *)(param_1 + 4) + 4);

  if (*(char *)(*(int *)(iVar1 + 0xa8 + param_1) + 0x7e) == '\0') goto LAB_00525e21;

  if (iVar4 != -1) {

    uVar2 = FUN_0040abd0(iVar4);

    pvVar3 = CNDHash_LookupByKey(*(void **)(iVar1 + param_1 + 0x74),uVar2);

    if (pvVar3 != (void *)0x0) {

      pB = &DAT_009cee98;

      Skill_LookupActiveCastBinding(local_10,*(int *)((int)pvVar3 + 0x5fc));

      iVar4 = TFID_NotEquals(pA,pB);

      if ((char)iVar4 != '\0') {

        pvVar5 = (void *)(**(code **)(*(int *)(*(int *)(*(int *)(param_1 + 4) + 4) + 4 + param_1) +

                                     0x27c))();

        Skill_SetRankAndReevaluate(pvVar3,pvVar5,unaff_DI);

        iVar4 = *(int *)(*(int *)(param_1 + 4) + 4) + param_1 + 4;

        iVar4 = CVOGReaction_CastSkillOnTarget

                          (pvVar3,iVar4,iVar4,1,0,&DAT_00b045a0,0,0xffffffff,0,0);

        if (iVar4 != 0x11) goto LAB_00525db4;

      }

      *(uint32_t /* width from decompiler */ *)(param_1 + 0xd64) = 0xffffffff;

    }

  }

LAB_00525db4:

  if (param_2 == -1) {

    return 1;

  }

  iVar4 = *(int *)(param_1 + 4);

  uVar2 = FUN_0040abd0(param_2);

  pvVar3 = CNDHash_LookupByKey(*(void **)(*(int *)(iVar4 + 4) + 0x74 + param_1),uVar2);

  if (pvVar3 == (void *)0x0) {

    return 1;

  }

  pvVar5 = (void *)(**(code **)(*(int *)(*(int *)(iVar4 + 4) + 4 + param_1) + 0x27c))();

  Skill_SetRankAndReevaluate(pvVar3,pvVar5,unaff_DI);

  iVar4 = *(int *)(*(int *)(param_1 + 4) + 4) + param_1 + 4;

  iVar4 = CVOGReaction_CastSkillOnTarget(pvVar3,iVar4,iVar4,1,0,&DAT_00b045a0,0,0xffffffff,0,0);

  if (iVar4 != 0) {

    return 1;

  }

LAB_00525e21:

  *(int *)(param_1 + 0xd64) = param_2;

  return 1;

}
