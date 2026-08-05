# Annotated low-level: CVOGCharacter_LevelUp

| Field | Value |
|---|---|
| Stable ID | `aa_00532d30` |
| VA | `0x00532d30` |
| System | unknown |
| Date | 2026-07-23 |

## Machine-level notes

- Source: raw capture for `aa_00532d30`.
- Prefer assembly when decompiler conflicts (not re-checked in scaffold pass).
- Integer widths: trust decompiler until spot-checked; document corrections here.
- Side-effect order: preserve call and store order from raw pseudocode.
- Uncertainty: parameter meanings and object types often Probable/Tentative until cross-function validation.

## Pseudocode (annotated copy of raw)

```c
/* CVOGCharacter_LevelUp — grant one level + pools (docs/XP.md)

   

   Parameters:

     this      - Character*

     bNotifyUi - if true, send LogicUI type 0x2D

   

   On map row found for current level:

     - dirty flags at object+0x180 |= 0x80

     - nLevel (+0x6c8)++

     - skill/attrib shorts at +0x6cc/+0x6ce from row+0x14 (packed)

     - research short from row+0x18 (INFERRED packing)

     - skill HB refresh passes, attribute refresh helpers

     - CVOGCharacter_SearchAutoMissions if local player bit

   

   Row layout: ExperienceLevelMapEntry_INFERRED (+0x10 XP, +0x14 skill/attrib, +0x18 research)

   Returns: void */



void __thiscall CVOGCharacter_LevelUp(void *this,bool bNotifyUi)



{

  void *pvVar1;

  int *piVar2;

  short sVar3;

  int *extraout_EAX;

  int iVar4;

  int iVar5;

  uint uVar6;

  uint uVar7;

  int iVar8;

  int nHpDelta_INFERRED;

  int local_16c;

  void *local_168;

  undefined4 local_164 [2];

  void *pSkillVec;

  int local_158;

  undefined4 local_154;

  undefined4 nRowExperience;

  undefined4 nSkillAttribPacked;

  undefined4 nResearchGrant;

  undefined4 uStack_144;

  int iStack_140;

  int iStack_13c;

  undefined4 uStack_128;

  undefined4 uStack_124;

  undefined4 uStack_120;

  void *local_c;

  undefined1 *puStack_8;

  undefined4 local_4;

  byte *pbDirtyFlags;

  

  local_4 = 0xffffffff;

  puStack_8 = &LAB_009a3cb6;

  local_c = ExceptionList;

  nHpDelta_INFERRED = *(int *)((int)this + 0x6c8) + 1;

  uVar7 = 0;

  ExceptionList = &local_c;

  if (g_nExperienceLevelTableReady == 0) {

    ExceptionList = &local_c;

    Experience_EnsureLevelTableLoaded_INFERRED();

  }

  StdMap_LowerBoundByIntKey_INFERRED(&g_pExperienceLevelMap_INFERRED,&local_168,&nHpDelta_INFERRED);

  pvVar1 = (void *)*extraout_EAX;

  if (g_nExperienceLevelTableReady == 0) {

    Experience_EnsureLevelTableLoaded_INFERRED();

  }

  if (pvVar1 != g_pExperienceLevelMapEnd) {

    nRowExperience = *(undefined4 *)((int)pvVar1 + 0x10);

    nSkillAttribPacked = *(undefined4 *)((int)pvVar1 + 0x14);

    nResearchGrant = *(undefined4 *)((int)pvVar1 + 0x18);

    pbDirtyFlags = (byte *)(*(int *)(*(int *)((int)this + 4) + 4) + 0x180 + (int)this);

    *pbDirtyFlags = *pbDirtyFlags | 0x80;

    *(int *)((int)this + 0x6c8) = *(int *)((int)this + 0x6c8) + 1;

    *(short *)((int)this + 0x6cc) = *(short *)((int)this + 0x6cc) + (short)nSkillAttribPacked;

    *(short *)((int)this + 0x6ce) =

         *(short *)((int)this + 0x6ce) + (short)((uint)nSkillAttribPacked >> 0x10);

    nHpDelta_INFERRED = 0;

    pSkillVec = (void *)0x0;

    local_158 = 0;

    local_154 = 0;

    local_4 = 0;

    iVar8 = 0;

    do {

      if (iVar8 == 0) {

        iVar5 = *(int *)(*(int *)(*(int *)((int)this + 4) + 4) + 0xb4 + (int)this);

LAB_00532e2f:

        if (iVar5 != 0) {

          local_16c = 0;

          local_164[0] = 0;

          FUN_004294f0();

          iVar4 = FUN_004022a0(local_164,&local_16c);

          while (iVar4 == 0) {

            if ((((local_16c != 0) && (*(int *)(local_16c + 0x1c) == 1)) &&

                (local_168 = (void *)__RTDynamicCast(local_16c,0,&CVOGHBBase::RTTI_Type_Descriptor,

                                                     &CVOGHBSkillBase::RTTI_Type_Descriptor),

                local_168 != (void *)0x0)) &&

               (((*(byte *)((int)local_168 + 0x639) & 1) != 0 &&

                (iVar4 = __RTDynamicCast(local_168,0,&CVOGHBSkillBase::RTTI_Type_Descriptor,

                                         &CVOGHBSkill_AddSkillLevels::RTTI_Type_Descriptor),

                iVar4 != 0)))) {

              FUN_0053a820();

            }

            iVar4 = FUN_004022a0(local_164,&local_16c);

          }

          if (*(char *)(iVar5 + 0x28) != '\0') {

            *(undefined1 *)(iVar5 + 0x28) = 0;

            LeaveCriticalSection((LPCRITICAL_SECTION)(iVar5 + 4));

          }

        }

      }

      else if ((iVar8 == 1) && (iVar5 = *(int *)((int)this + 0x250), iVar5 != 0)) {

        iVar5 = *(int *)(*(int *)(*(int *)(iVar5 + 4) + 4) + 0xb4 + iVar5);

        goto LAB_00532e2f;

      }

      iVar8 = iVar8 + 1;

    } while (iVar8 < 2);

    if (pSkillVec == (void *)0x0) {

      uVar6 = 0;

    }

    else {

      uVar6 = local_158 - (int)pSkillVec >> 2;

    }

    if (uVar6 != 0) {

      do {

        piVar2 = *(int **)((int)pSkillVec + uVar7 * 4);

        (**(code **)(*piVar2 + 0x14))();

        (**(code **)(*piVar2 + 4))();

        uVar7 = uVar7 + 1;

      } while (uVar7 < uVar6);

    }

    *(short *)((int)this + 0x580) = *(short *)((int)this + 0x580) + (short)nResearchGrant;

    FUN_004c2ef0();

    FUN_004c2ee0();

    FUN_004c2f00();

    FUN_004c2f10();

    iVar8 = *(int *)((int)this + 0x250);

    if (iVar8 != 0) {

      iVar8 = (**(code **)(*(int *)(*(int *)(*(int *)(iVar8 + 4) + 4) + 4 + iVar8) + 0x244))();

      Vehicle_RecalcCombatPools(*(void **)((int)this + 0x250));

      nHpDelta_INFERRED =

           (**(code **)(*(int *)(*(int *)(*(int *)(*(int *)((int)this + 0x250) + 4) + 4) + 4 +

                                *(int *)((int)this + 0x250)) + 0x244))();

      nHpDelta_INFERRED = nHpDelta_INFERRED - iVar8;

    }

    (**(code **)(*(int *)this + 0x5c))();

    *(undefined2 *)((int)this + 300) = *(undefined2 *)((int)this + 0x12e);

    ceil((double)(g_flLevelUpUiRace_Inferred

                  [*(byte *)(*(int *)(*(int *)(*(int *)(*(int *)((int)this + 4) + 4) + 0xac +

                                              (int)this) + 0x3c) + 0x531)] +

                 g_flLevelUpUiBase_Inferred));

    sVar3 = FUN_006a3db0();

    *(undefined1 *)((int)this + 0x4f2) = 1;

    if (*(char *)(*(int *)(*(int *)(*(int *)((int)this + 4) + 4) + 0xa8 + (int)this) + 0x7e) != '\0'

       ) {

      CVOGCharacter_SearchAutoMissions(this);

    }

    FUN_00531330();

    FUN_00523e60();

    if (bNotifyUi) {

      iVar8 = *(int *)(*(int *)((int)this + 4) + 4);

      uStack_124 = *(undefined4 *)(iVar8 + 0x164 + (int)this);

      uStack_120 = *(undefined4 *)((int)this + iVar8 + 0x168);

      uStack_144 = *(undefined4 *)((int)this + 0x6c8);

      iStack_140 = nHpDelta_INFERRED;

      iStack_13c = (int)sVar3;

      uStack_128 = 0x2d;

      Client_SendLogicUiPacket();

    }

    if (pSkillVec != (void *)0x0) {

                    /* WARNING: Subroutine does not return */

      operator_delete(pSkillVec);

    }

  }

  ExceptionList = local_c;

  return;

}
```

## Open questions

- Confirm calling convention and full signature against callers.
- Recover meaningful types for still-generic parameters.
- Map DAT_* globals and FUN_* callees.
