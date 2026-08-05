# Annotated low-level: Client_SkillTrainUiRequest_INFERRED

| Field | Value |
|---|---|
| **Stable ID** | `aa_00897170` |
| **VA** | `0x00897170` |
| **Module** | `autoassault.exe` @ image base `0x400000` |
| **System** | skills-abilities |
| **Source raw** | `aa_00897170_Client_SkillTrainUiRequest_INFERRED.md` |
| **Refine** | Human pass 2026-07-23 (named_hl keyword wave) |

This file is the **annotated** layer: packet/UI offsets, branch order, and decompiler corrections.

---

## 1. Purpose

Skill-train UI request. On first-rank train of active skill, auto-maps into first empty QuickBar slot, CVOGCharacter_SetQuickBarSkill, sends QuickBarUpdate 0x2062 + SkillIncrement 0x2059.

## 2. Corrected signature

```c
void Client_SkillTrainUiRequest_INFERRED(int *pUi, unsigned skillId);
```

## 3. Key offsets / packet fields

| Offset / symbol | Role |
|---|---|
| `skill+0x5f4` | max rank byte |
| `skill+0x5f6` | current rank short |
| `skill+0x5fb` | min level byte |
| `skill+0x02` | skill point cost short |
| `char+0x6cc` | available skill points |
| `opcodes` | 0x2062 QuickBarUpdate, 0x2059 SkillIncrement |

## 4. Machine-level notes

- FUN_0052dc20(skillId,0) availability gate; else hash lookup skill def.
- Rank gates: skill+0x5f6 current < max@+0x5f4 and < 0x32; level/skill-point checks.
- Empty QB slot: item COID both dwords 0xFFFFFFFF and skillId == -1 on current page.
- Toasts for unavailable / not enough skill points.

## 5. Pseudocode (authoritative raw, retained)

```c
/* WARNING: Globals starting with '_' overlap smaller symbols at the same address */

/* Skill-train UI request path (partially RE'd for QuickBar this session).

   

   On successful first-rank train of an active skill, auto-maps into the first empty

   QuickBar slot on the current page (item COID both dwords == 0xFFFFFFFF and skillId == -1),

   calls CVOGCharacter_SetQuickBarSkill, then sends:

     EMSG_Sector_QuickBarUpdate (0x2062)  — slot, isItem=0, skillId as int64

     EMSG_Sector_SkillIncrement (0x2059)  — skillId

   

   Full prereq/level/UI refresh logic outside QuickBar surface is not fully documented.

   Tag: quickbar. Session: AutoCore 2026-07. */



void Client_SkillTrainUiRequest_INFERRED(int *param_1,uint param_2)



{

  float fVar1;

  short sVar2;

  void *pvVar3;

  char cVar4;

  void *pvVar5;

  uint uVar6;

  int iVar7;

  byte bVar8;

  int *piVar9;

  char *pcVar10;

  undefined4 uVar11;

  undefined4 uStack_10;

  uint uStack_c;

  uint uStack_8;

  int iStack_4;

  

  if (DAT_00d1b6d8 == (void *)0x0) {

    return;

  }

  cVar4 = FUN_0052dc20(param_2,0);

  pvVar3 = DAT_00d1b6d8;

  if (cVar4 == '\0') {

    pvVar5 = CNDHash_LookupByKey(*(void **)(*(int *)(*(int *)((int)DAT_00d1b6d8 + 4) + 4) + 0x74 +

                                           (int)DAT_00d1b6d8),param_2);

    if (pvVar5 == (void *)0x0) {

      pcVar10 = "That skill is unavailable!";

    }

    else if ((*(short *)((int)pvVar5 + 0x5f6) < (short)(ushort)*(byte *)((int)pvVar5 + 0x5f4)) &&

            (*(short *)((int)pvVar5 + 0x5f6) < 0x32)) {

      bVar8 = *(byte *)((int)pvVar5 + 0x5fb);

      iVar7 = (**(code **)(*(int *)(*(int *)(*(int *)((int)pvVar3 + 4) + 4) + 4 + (int)pvVar3) +

                          0x27c))();

      if (((int)(uint)bVar8 <= iVar7) &&

         ((fVar1 = *(float *)((int)pvVar5 + 4), fVar1 <= g_flZero ||

          (sVar2 = *(short *)((int)pvVar5 + 0x5f6), bVar8 = *(byte *)((int)pvVar5 + 0x5fb),

          iVar7 = (**(code **)(*(int *)(*(int *)(*(int *)((int)DAT_00d1b6d8 + 4) + 4) + 4 +

                                       (int)DAT_00d1b6d8) + 0x27c))(),

          sVar2 < (short)(int)((float)(int)(iVar7 - (uint)bVar8) * fVar1 + _DAT_00aaac14))))) {

        if (*(short *)((int)DAT_00d1b6d8 + 0x6cc) < *(short *)((int)pvVar5 + 2)) {

          FUN_007fdfb0(&DAT_00d1a840,"You do not have enough skill points to train in this skill!",

                       0xffffffff,1,0);

          return;

        }

        FUN_007fdfb0(&DAT_00d1a840,"You have not met enough prerequisites to train in this skill!",

                     0xffffffff,1,0);

        return;

      }

      pcVar10 = "You are not a high enough level to train in this skill!";

    }

    else {

      pcVar10 = "You cannot train any further in this skill!";

    }

    FUN_007fdfb0(&DAT_00d1a840,pcVar10,0xffffffff,1,0);

    return;

  }

  if (DAT_00d1b8f0 != (int *)0x0) {

    cVar4 = (**(code **)(*DAT_00d1b8f0 + 0x3d8))();

    if (cVar4 != '\0') {

      FUN_008a05a0();

    }

    if (DAT_00d1b8f0 != (int *)0x0) {

      (**(code **)(*DAT_00d1b8f0 + 0x448))();

    }

  }

  piVar9 = DAT_00d1b8f0;

  pvVar3 = DAT_00d1b6d8;

  pvVar5 = CNDHash_LookupByKey(*(void **)(*(int *)(*(int *)((int)DAT_00d1b6d8 + 4) + 4) + 0x74 +

                                         (int)DAT_00d1b6d8),param_2);

  if (pvVar5 == (void *)0x0) goto LAB_008972e7;

  if (*(short *)((int)pvVar5 + 0x5f6) == 1) {

    if ((*(byte *)((int)pvVar5 + 0x615) & 1) == 0) {

      iVar7 = 0;

      cVar4 = (char)piVar9[0x143] * '\n';

      do {

        uVar6 = (uint)(byte)(cVar4 + (char)iVar7);

        if (((*(uint *)((int)pvVar3 + uVar6 * 8 + 0x930) &

             *(uint *)((int)pvVar3 + uVar6 * 8 + 0x934)) == 0xffffffff) &&

           (*(int *)((int)pvVar3 + uVar6 * 4 + 0x74c) == -1)) {

          bVar8 = cVar4 + (char)iVar7;

          CVOGCharacter_SetQuickBarSkill(pvVar3,bVar8,param_2);

          iStack_4 = (int)param_2 >> 0x1f;

          uStack_8 = param_2;

          uStack_10 = 0x2062;

          uStack_c._0_2_ = (ushort)bVar8;

          Client_SendSectorPacket(&DAT_00d1a840,0x10,&uStack_10);

          break;

        }

        iVar7 = iVar7 + 1;

      } while (iVar7 < 10);

      FUN_008a0ed0();

      cVar4 = FUN_0089fe40();

      if (cVar4 == '\0') {

        FUN_008a0210(1);

      }

      goto LAB_008972ce;

    }

LAB_008972db:

    uVar11 = 0x1e;

  }

  else {

LAB_008972ce:

    if ((*(byte *)((int)pvVar5 + 0x615) & 1) != 0) goto LAB_008972db;

    uVar11 = 0xc;

  }

  Client_MaybeShowFirstTimeTip(uVar11);

LAB_008972e7:

  if ((1 < DAT_00d178f4) && (DAT_00d1b87c != 0)) {

    if (param_1[0x147] == 2) {

      piVar9 = *(int **)(DAT_00d1b87c + 0x510);

    }

    else {

      piVar9 = *(int **)(DAT_00d1b87c + 0x50c);

    }

    if (piVar9 != (int *)0x0) {

      (**(code **)(*piVar9 + 0x448))();

      (**(code **)(*piVar9 + 0x34c))();

    }

  }

  (**(code **)(*param_1 + 0x448))();

  (**(code **)(*param_1 + 0x34c))();

  if ((DAT_00d1d8e0 != (int *)0x0) && (cVar4 = (**(code **)(*DAT_00d1d8e0 + 0xd0))(), cVar4 != '\0')

     ) {

    FUN_0083ee40(0);

  }

  uStack_10 = 0x2059;

  uStack_c = param_2;

  if (g_pSectorNetConnection_INFERRED == (void *)0x0) {

    return;

  }

  (**(code **)(*(int *)g_pSectorNetConnection_INFERRED + 0x18))(0xffffffff,&uStack_10,8,0);

  return;

}
```

## 6. Open questions

- Document full prereq tree beyond QuickBar auto-map path.
