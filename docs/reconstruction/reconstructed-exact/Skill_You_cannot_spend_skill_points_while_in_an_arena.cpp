// READABILITY (auto CF):
//  - Body size: ~115 non-empty decompiler lines.
//  - Control keywords: if×23, return×18, goto×1, while×1.
//  - Notable callees: FUN_008882d0×2, FUN_0040cf50, FUN_007fc970, FUN_007fd350, FUN_007fdfb0, FUN_0087b500, FUN_00897d40, ROUND.
//  - Strings: "You cannot spend skill points while in an arena!".
//  - Return sites: 18.

// =============================================================================
// Skill_You_cannot_spend_skill_points_while_in_an_arena
// -----------------------------------------------------------------------------
// Stable ID: aa_00897d40
// Address:   0x00897d40  (autoassault.exe, image base 0x400000)
// System:    unknown
// Generated: 2026-07-23 from raw capture (scaffold; refine for important units)
// Exactness: Behavior-preserving rewrite of decompiler control flow. Not modernization.
// Bit-for-bit vs retail EXE: DEFERRED (loaded image may differ slightly).
// =============================================================================

/*
 * Behavioral notes:
 * String-driven rename evidence: "You cannot spend skill points while in an arena!"
 *
 * - Derived from Ghidra decompile; names prefer Ghidra symbols / plate comments.
 * - Remaining FUN_* / DAT_* identifiers are unresolved pending type recovery.
 * - Runtime / differential verification: OPEN unless matrix says otherwise.
 *
 * Readability pass:
 * - undefinedN widths preserved as fixed-width integers where decompiler width is known.
 * - Control flow and call order preserved from authoritative raw.
 */

uint32_t /* width from decompiler */ __thiscall Skill_You_cannot_spend_skill_points_while_in_an_arena(int *param_1,int param_2,int param_3)



{

  char cVar1;

  uint8_t *puVar2;

  int *piVar3;

  int iVar4;

  uint32_t /* width from decompiler */ uVar5;

  float10 fVar6;

  uint8_t *puVar7;

  uint32_t /* width from decompiler */ uVar8;

  uint8_t auStack_38 [4];

  uint8_t auStack_34 [12];

  uint8_t auStack_28 [40];

  

  if ((0x9c45 < param_3) && (param_3 < 0x9c7c)) {

    if (param_2 == 5) {

      cVar1 = FUN_0040cf50();

      if (cVar1 != '\0') {

        return 1;

      }

      if (DAT_00d1b6d8 == 0) {

        return 1;

      }

      (**(code **)(*(int *)param_1[param_3 + -0x9aad] + 0x120))(auStack_38,1,1);

      (**(code **)(*(int *)param_1[param_3 + -0x9aad] + 0x140))(&stack0xffffffc4,1);

      uVar5 = 1;

      if ((int *)param_1[0x157] == (int *)0x0) {

        iVar4 = *param_1;

        puVar2 = auStack_34;

      }

      else {

        iVar4 = *(int *)param_1[0x157];

        puVar2 = &stack0xffffffc4;

      }

      (**(code **)(iVar4 + 0x120))(puVar2,1,1);

      uVar8 = 1;

      if ((int *)param_1[0x159] == (int *)0x0) {

        puVar7 = auStack_28;

        piVar3 = (int *)(**(code **)(*param_1 + 0x140))(puVar7,1);

        iVar4 = *piVar3;

      }

      else {

        puVar7 = (uint8_t *)0x1;

        piVar3 = (int *)(**(code **)(*(int *)param_1[0x159] + 0x120))(auStack_38,1);

        iVar4 = *piVar3;

        piVar3 = (int *)(**(code **)(*(int *)param_1[0x159] + 0x140))(&stack0xffffffc4,1);

        iVar4 = *piVar3 + (iVar4 - (int)puVar2);

      }

      FUN_007fd350(&DAT_00d1a840,puVar7,uVar8,iVar4,uVar5,0);

      return 1;

    }

    if (param_2 == 6) goto LAB_00897feb;

    if (param_2 == 8) {

      if (DAT_00d1b644 == 0) {

        return 1;

      }

      if (DAT_00d1b6d8 == 0) {

        return 1;

      }

      if (*(int *)(param_1[param_3 + -0x9aad] + 0x60c) == 0) {

        return 1;

      }

      if (*(char *)(DAT_00d1b644 + 0xf6) == '\0') {

        Client_SkillTrainUiRequest_INFERRED

                  (param_1,*(uint32_t /* width from decompiler */ *)(*(int *)(param_1[param_3 + -0x9aad] + 0x60c) + 0x5fc));

        return 1;

      }

      FUN_007fdfb0(&DAT_00d1a840,"You cannot spend skill points while in an arena!",0xffffffff,1,0);

      return 1;

    }

  }

  if (param_3 == 0x9c43) {

    if (param_2 == 0x1a) {

      if ((int *)param_1[0x1d4] == (int *)0x0) {

        return 1;

      }

      fVar6 = (float10)(**(code **)(*(int *)param_1[0x1d4] + 0x458))();

      DAT_00d178f8 = (float)fVar6;

      iVar4 = (int)ROUND((float)param_1[0x1d5] * DAT_00d178f8 + DAT_00aaa664);

      if (param_1[0x143] == iVar4) {

        return 1;

      }

      param_1[0x143] = iVar4;

      (**(code **)(*param_1 + 0x448))();

LAB_00897feb:

      FUN_007fc970();

      return 1;

    }

  }

  else if (param_3 == 0x9c44) {

    if (param_2 == 8) {

      if ((int *)param_1[0xac] == (int *)0x0) {

        return 1;

      }

      cVar1 = (**(code **)(*(int *)param_1[0xac] + 0x3d8))();

      if (cVar1 == '\0') {

        return 1;

      }

      FUN_008882d0(0);

      return 1;

    }

  }

  else if ((param_3 == 0x9c45) && (param_2 == 8)) {

    if ((int *)param_1[0xac] == (int *)0x0) {

      return 1;

    }

    cVar1 = (**(code **)(*(int *)param_1[0xac] + 0x3d8))();

    if (cVar1 == '\0') {

      return 1;

    }

    FUN_008882d0(0);

    return 1;

  }

  uVar5 = FUN_0087b500(param_2,param_3);

  return uVar5;

}
