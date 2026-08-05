// READABILITY (auto CF):
//  - Body size: ~177 non-empty decompiler lines.
//  - Control keywords: if×14, return×3.
//  - Notable callees: FUN_004024d0×2, FUN_00404c90×2, CONCAT22, CVOGHBBase_Start, CVOGHBList_Enqueue, CVOGMap_CastTerrainHeight, FUN_00404a20, FUN_00404c30.
//  - Strings: "Skill %d had invalid template %d.".
//  - Return sites: 3.

// =============================================================================
// Skill_Skill_d_had_invalid_template_d
// -----------------------------------------------------------------------------
// Stable ID: aa_00620480
// Address:   0x00620480  (autoassault.exe, image base 0x400000)
// System:    unknown
// Generated: 2026-07-23 from raw capture (scaffold; refine for important units)
// Exactness: Behavior-preserving rewrite of decompiler control flow. Not modernization.
// Bit-for-bit vs retail EXE: DEFERRED (loaded image may differ slightly).
// =============================================================================

/*
 * Behavioral notes:
 * String-driven rename evidence: "Skill %d had invalid template %d."
 *
 * - Derived from Ghidra decompile; names prefer Ghidra symbols / plate comments.
 * - Remaining FUN_* / DAT_* identifiers are unresolved pending type recovery.
 * - Runtime / differential verification: OPEN unless matrix says otherwise.
 *
 * Readability pass:
 * - undefinedN widths preserved as fixed-width integers where decompiler width is known.
 * - Control flow and call order preserved from authoritative raw.
 */

uint32_t /* width from decompiler */

Skill_Skill_d_had_invalid_template_d(int *param_1,int param_2,int param_3,uint32_t /* width from decompiler */ param_4,uint32_t /* width from decompiler */ param_5,

            uint32_t /* width from decompiler */ param_6)



{

  int iVar1;

  uint32_t /* width from decompiler */ *puVar2;

  void *pvVar3;

  int iVar4;

  int *piVar5;

  int iVar6;

  CVOGHBBase *pAction;

  uint16_t extraout_var;

  uint16_t extraout_var_00;

  uint16_t uVar7;

  uint32_t /* width from decompiler */ *puVar8;

  uint32_t /* width from decompiler */ uStack_90;

  uint32_t /* width from decompiler */ uStack_8c;

  uint32_t /* width from decompiler */ uStack_88;

  uint32_t /* width from decompiler */ uStack_84;

  uint32_t /* width from decompiler */ uStack_80;

  uint32_t /* width from decompiler */ uStack_7c;

  float fStack_78;

  uint32_t /* width from decompiler */ uStack_74;

  uint32_t /* width from decompiler */ uStack_70;

  uint32_t /* width from decompiler */ uStack_6c;

  uint32_t /* width from decompiler */ uStack_68;

  uint32_t /* width from decompiler */ uStack_64;

  uint32_t /* width from decompiler */ uStack_60;

  uint32_t /* width from decompiler */ uStack_50;

  uint32_t /* width from decompiler */ uStack_4c;

  uint32_t /* width from decompiler */ uStack_48;

  uint32_t /* width from decompiler */ uStack_44;

  uint32_t /* width from decompiler */ uStack_40;

  uint32_t /* width from decompiler */ uStack_3c;

  uint32_t /* width from decompiler */ uStack_38;

  uint32_t /* width from decompiler */ uStack_34;

  uint32_t /* width from decompiler */ uStack_30;

  uint32_t /* width from decompiler */ uStack_2c;

  uint32_t /* width from decompiler */ uStack_28;

  uint32_t /* width from decompiler */ uStack_24;

  void *local_1c;

  uint8_t *puStack_18;

  uint32_t /* width from decompiler */ uStack_14;

  

  uStack_14 = 0xffffffff;

  puStack_18 = &LAB_009a88fc;

  local_1c = ExceptionList;

  if (((*(char *)(param_3 + 0x7e) != '\0') && (param_1 != (int *)0x0)) &&

     (ExceptionList = &local_1c, iVar1 = (**(code **)(*param_1 + 0x214))(), iVar1 != 0)) {

    puVar8 = (uint32_t /* width from decompiler */ *)0x0;

    if (*(int *)(iVar1 + 0x250) == 0) {

      puVar2 = (uint32_t /* width from decompiler */ *)FUN_00404c90();

    }

    else {

      puVar2 = (uint32_t /* width from decompiler */ *)FUN_00404c90();

    }

    uStack_90 = *puVar2;

    uStack_8c = puVar2[1];

    uStack_88 = puVar2[2];

    uStack_84 = puVar2[3];

    puVar2 = (uint32_t /* width from decompiler */ *)FUN_00404a20();

    uStack_80 = *puVar2;

    uStack_7c = puVar2[1];

    fStack_78 = (float)puVar2[2];

    uStack_74 = puVar2[3];

    if (*(char *)(param_2 + 0x22) == '\0') {

      pvVar3 = operator_new(0x690);

      uStack_14 = 0;

      if (pvVar3 == (void *)0x0) {

        iVar4 = 0;

      }

      else {

        iVar4 = FUN_004c9aa0(1);

      }

      uStack_14 = 0xffffffff;

      (**(code **)(*(int *)(*(int *)(*(int *)(iVar4 + 4) + 4) + 4 + iVar4) + 8))

                (*(uint32_t /* width from decompiler */ *)(param_2 + 0x14c),param_3,1);

    }

    else {

      piVar5 = (int *)FUN_0058bf50(*(uint32_t /* width from decompiler */ *)(param_2 + 0x14c),param_2,param_1);

      if (piVar5 == (int *)0x0) {

        FUN_007a4480(1,"Skill %d had invalid template %d.",*(uint32_t /* width from decompiler */ *)(param_2 + 0x5fc),

                     *(uint32_t /* width from decompiler */ *)(param_2 + 0x14c));

        ExceptionList = local_1c;

        return 0;

      }

      puVar8 = (uint32_t /* width from decompiler */ *)(**(code **)(*piVar5 + 0x1d4))();

      FUN_00404c60(&uStack_90);

      FUN_00404c30(&uStack_80);

      (**(code **)*puVar8)(param_3,&uStack_90,&uStack_80,0);

      iVar4 = (**(code **)(**(int **)(*(int *)(puVar8[1] + 4) + 0xb0 + (int)puVar8) + 0x1d8))();

    }

    uStack_64 = DAT_00aaa688;

    *(uint8_t *)(iVar4 + 0x309) = 0;

    uStack_6c = 0;

    uStack_68 = 0;

    uStack_60 = 0;

    FUN_004e8bf0(&stack0xffffff64,&uStack_8c,&uStack_6c,&uStack_7c);

    uStack_90 = uStack_70;

    CVOGMap_CastTerrainHeight(uStack_7c,uStack_74,fStack_78 + DAT_00aaa7ac,0);

    if (puVar8 == (uint32_t /* width from decompiler */ *)0x0) {

      FUN_0058a1b0(*(int *)(*(int *)(iVar4 + 4) + 4) + 4 + iVar4,param_3,&stack0xffffff64,&uStack_8c

                   ,1);

    }

    FUN_004ca910(*(int *)(*(int *)(iVar1 + 4) + 4) + 0x164 + iVar1,1);

    iVar6 = (**(code **)(*(int *)(*(int *)(*(int *)(iVar1 + 4) + 4) + 4 + iVar1) + 0x210))(0);

    *(bool *)(iVar4 + 0x206) = iVar6 != 0;

    if (*(int *)(param_2 + 0x154) != 0) {

      Skill_EnsureLoadedInTree

                ((void *)(*(int *)(*(int *)(iVar4 + 4) + 4) + 4 + iVar4),*(int *)(param_2 + 0x154),1

                );

    }

    if (*(int *)(param_2 + 0x158) != 0) {

      Skill_EnsureLoadedInTree

                ((void *)(*(int *)(*(int *)(iVar4 + 4) + 4) + 4 + iVar4),*(int *)(param_2 + 0x158),1

                );

    }

    if (*(int *)(param_2 + 0x15c) != 0) {

      Skill_EnsureLoadedInTree

                ((void *)(*(int *)(*(int *)(iVar4 + 4) + 4) + 4 + iVar4),*(int *)(param_2 + 0x15c),1

                );

    }

    FUN_004e8a40(&uStack_90,&stack0xffffff60);

    (**(code **)(*(int *)(*(int *)(*(int *)(iVar4 + 4) + 4) + 4 + iVar4) + 0x2a4))

              (*(uint32_t /* width from decompiler */ *)(*(int *)(*(int *)(*(int *)(iVar1 + 4) + 4) + 0xa8 + iVar1) + 0xe4e8))

    ;

    FUN_004024d0(*(int *)(*(int *)(iVar4 + 4) + 4) + iVar4 + 4);

    if (puVar8 != (uint32_t /* width from decompiler */ *)0x0) {

      FUN_004024d0(*(int *)(puVar8[1] + 4) + 4 + (int)puVar8);

    }

    (**(code **)(*(int *)(*(int *)(*(int *)(iVar4 + 0x44) + 4) + 0x44 + iVar4) + 0x28))();

    pvVar3 = operator_new(0x6c0);

    uStack_14 = 1;

    if (pvVar3 == (void *)0x0) {

      pAction = (CVOGHBBase *)0x0;

    }

    else {

      pAction = (CVOGHBBase *)

                FUN_006202f0(param_1,param_2,param_3,*(int *)(*(int *)(iVar4 + 4) + 4) + 4 + iVar4,

                             param_5,param_6);

    }

    uStack_14 = 0xffffffff;

    if (pAction->pOwnerObject == (void *)0x0) {

      (**(code **)pAction->pVTable)(1);

      uVar7 = extraout_var_00;

    }

    else {

      CVOGHBList_Enqueue(*(void **)(param_3 + 0xe4ec),pAction);

      CVOGHBBase_Start(pAction);

      uVar7 = extraout_var;

    }

    if (*(void **)(param_2 + 0x150) != (void *)0x0) {

      puVar2 = CVOGReaction_ResolveSkillTargets

                         (*(void **)(param_2 + 0x150),

                          CONCAT22(uVar7,*(uint16_t *)(param_2 + 0x5f6)));

      puVar8 = (uint32_t /* width from decompiler */ *)(*(int *)(*(int *)(iVar4 + 4) + 4) + 0x164 + iVar4);

      uStack_40 = *puVar8;

      uStack_3c = puVar8[1];

      uStack_38 = puVar8[2];

      uStack_34 = puVar8[3];

      uStack_2c = DAT_009e2e7c;

      uStack_30 = DAT_009e2e78;

      uStack_28 = DAT_009e2e80;

      uStack_24 = DAT_009e2e84;

      uStack_50 = DAT_00d02b00;

      uStack_4c = DAT_00d02b04;

      uStack_48 = DAT_00d02b08;

      uStack_44 = DAT_00d02b0c;

      FUN_005538a0(param_1,param_3,&uStack_40,&uStack_50,param_6);

      if (puVar2 != (uint32_t /* width from decompiler */ *)0x0) {

                    /* WARNING: Subroutine does not return */

        operator_delete(puVar2);

      }

    }

  }

  ExceptionList = local_1c;

  return 1;

}
