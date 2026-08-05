# Annotated low-level: CVOGReaction_AddExperience

| Field | Value |
|---|---|
| Stable ID | `aa_00533c30` |
| VA | `0x00533c30` |
| System | missions-progression |
| Date | 2026-07-23 |

## Machine-level notes

- Source: raw capture for `aa_00533c30`.
- Prefer assembly when decompiler conflicts (not re-checked in scaffold pass).
- Integer widths: trust decompiler until spot-checked; document corrections here.
- Side-effect order: preserve call and store order from raw pseudocode.
- Uncertainty: parameter meanings and object types often Probable/Tentative until cross-function validation.

## Pseudocode (annotated copy of raw)

```c
/* CVOGReaction_AddExperience — client XP apply kernel (docs/XP.md)

   

   Parameters:

     this        - Character* (INFERRED layout; offsets listed below)

     nAmount     - raw XP delta (may be negative)

     isKillPath  - XpIsKillPath: KillPath enables 5s spree + weapon bonus table

   

   Character field offsets (VERIFIED by use):

     +0x6b4  specialMode (int) — skips max-level soft cap when >0

     +0x6c8  nLevel (int)

     +0x6cc  wSkillPoints pool (short)  [LevelUp writes]

     +0x6ce  wAttributePoints pool (short)

     +0x730  nTotalExperience (int)

     +0x734  dwLastKillTick (DWORD)

     +0x738  cSpreeOrLevelHint (byte)

     +0xc50  nMaxLevel (int)

     +0xc54  flPersonalXpGain (float)

   

   Algorithm:

     1) if KillPath: update spree 0..5 within 5s window; optional weapon bonus scale

     2) scaled = (int)(nAmount * flPersonalXpGain)

     3) at max level (unless specialMode): clamp so total < threshold(level)

     4) if scaled==0 return false

     5) nTotalExperience += scaled

     6) level-up/down loops (guard 300) via LevelUp / LevelDown

   

   Returns: bool — false if no XP applied

   S2C GiveXP uses PacketOrNonKill (no spree). AutoCore: ExperienceService.GiveXp */



bool __thiscall CVOGReaction_AddExperience(void *this,int nAmount,XpIsKillPath isKillPath)



{

  char bWeaponBonusOk;

  ushort wLevel;

  DWORD nowTick;

  int nTmp;

  int nPlayerLevel;

  uint nThreshold;

  byte cSpreeClamped;

  int nLevelLoopGuard;

  int nScaledAmount;

  float aflSpreeBonusTable [4];

  undefined4 local_30;

  undefined4 local_2c;

  undefined4 local_28;

  undefined4 local_24;

  undefined4 local_20;

  undefined4 local_1c;

  undefined4 local_18;

  undefined4 local_14;

  undefined4 local_10;

  undefined4 local_c;

  undefined4 local_8;

  undefined4 local_4;

  

  nLevelLoopGuard = 0;

  if (isKillPath != PacketOrNonKill) {

    nowTick = GetTickCount();

    if (nowTick - *(int *)((int)this + 0x734) < 5000) {

      *(char *)((int)this + 0x738) = *(char *)((int)this + 0x738) + '\x01';

      cSpreeClamped = *(byte *)((int)this + 0x738);

      if (4 < cSpreeClamped) {

        cSpreeClamped = 5;

      }

      *(byte *)((int)this + 0x738) = cSpreeClamped;

    }

    else {

      *(undefined1 *)((int)this + 0x738) = 0;

    }

    *(DWORD *)((int)this + 0x734) = nowTick;

    bWeaponBonusOk = CVOGCharacter_WeaponAllowsKillXpBonus();

    if (bWeaponBonusOk != '\0') {

      nTmp = *(int *)(*(int *)(*(int *)(*(int *)((int)this + 4) + 4) + 0xa8 + (int)this) + 0xe818);

      aflSpreeBonusTable[0] = 0.0;

      aflSpreeBonusTable[1] = 0.0;

      aflSpreeBonusTable[2] = (float)DAT_00aaa7b8;

      aflSpreeBonusTable[3] = (float)DAT_00aaa8f4;

      local_30 = DAT_00aaa8f0;

      local_2c = DAT_00aaa8f0;

      local_28 = DAT_00aaa8f0;

      local_24 = DAT_00aaa8f0;

      local_20 = DAT_00aaa8f0;

      local_1c = DAT_00aaa8f0;

      local_18 = DAT_00aaa8f0;

      local_14 = DAT_00aaa8f0;

      local_10 = DAT_00aaa8f0;

      local_c = DAT_00aaa8f0;

      local_8 = DAT_00aaa8f0;

      local_4 = DAT_00aaa8f0;

      if (0xe < nTmp) {

        nTmp = 0xf;

      }

      nAmount = (int)ROUND((aflSpreeBonusTable[nTmp] + g_flOne) * (float)nAmount);

    }

  }

  nTmp = *(int *)((int)this + 0xc50);

  nScaledAmount = (int)((float)nAmount * *(float *)((int)this + 0xc54));

  nPlayerLevel = (**(code **)(*(int *)(*(int *)(*(int *)((int)this + 4) + 4) + 4 + (int)this) +

                             0x27c))();

  if ((nTmp < nPlayerLevel + 1) && (*(int *)((int)this + 0x6b4) < 1)) {

    nTmp = *(int *)((int)this + 0x730);

    wLevel = (**(code **)(*(int *)(*(int *)(*(int *)((int)this + 4) + 4) + 4 + (int)this) + 0x27c))

                       ();

    nThreshold = Experience_GetCumulativeThreshold(wLevel);

    nTmp = (nThreshold - nTmp) + -1;

    if (nTmp < nScaledAmount) {

      nScaledAmount = nTmp;

    }

  }

  if (nScaledAmount == 0) {

    return false;

  }

  *(int *)((int)this + 0x730) = *(int *)((int)this + 0x730) + nScaledAmount;

  if (*(char *)(*(int *)(*(int *)(*(int *)((int)this + 4) + 4) + 0xa8 + (int)this) + 0x7e) != '\0')

  {

    if (nScaledAmount < 1) {

      if (*(int *)((int)this + 0x6c8) < 2) {

        if (*(int *)((int)this + 0x730) < 0) {

          *(undefined4 *)((int)this + 0x730) = 0;

          return true;

        }

      }

      else {

        nThreshold = Experience_GetCumulativeThreshold(*(short *)((int)this + 0x6c8) - 1);

        if (*(int *)((int)this + 0x730) < (int)nThreshold) {

          do {

            nLevelLoopGuard = nLevelLoopGuard + 1;

            if (300 < nLevelLoopGuard) {

              return true;

            }

            nThreshold = Experience_GetCumulativeThreshold(*(ushort *)((int)this + 0x6c8));

            if (nThreshold == 0x7fffffff) {

              return true;

            }

            if (*(int *)((int)this + 0x6c8) < 1) {

              return true;

            }

            CVOGCharacter_LevelDown(this);

            nThreshold = Experience_GetCumulativeThreshold(*(short *)((int)this + 0x6c8) - 1);

          } while (*(int *)((int)this + 0x730) < (int)nThreshold);

        }

      }

    }

    else if ((*(int *)((int)this + 0xc50) < *(int *)((int)this + 0x6c8) + 1) &&

            (*(int *)((int)this + 0x6b4) < 1)) {

      nThreshold = Experience_GetCumulativeThreshold(*(ushort *)((int)this + 0x6c8));

      if ((int)nThreshold < *(int *)((int)this + 0x730)) {

        nThreshold = Experience_GetCumulativeThreshold(*(ushort *)((int)this + 0x6c8));

        *(uint *)((int)this + 0x730) = nThreshold - 1;

        return true;

      }

    }

    else {

      nThreshold = Experience_GetCumulativeThreshold(*(ushort *)((int)this + 0x6c8));

      if ((int)nThreshold <= *(int *)((int)this + 0x730)) {

        while ((((*(int *)((int)this + 0x6c8) < *(int *)((int)this + 0xc50) ||

                 (0 < *(int *)((int)this + 0x6b4))) &&

                (nLevelLoopGuard = nLevelLoopGuard + 1, nLevelLoopGuard < 0x12d)) &&

               (nThreshold = Experience_GetCumulativeThreshold(*(ushort *)((int)this + 0x6c8)),

               nThreshold != 0x7fffffff))) {

          CVOGCharacter_LevelUp(this,true);

          nThreshold = Experience_GetCumulativeThreshold(*(ushort *)((int)this + 0x6c8));

          if (*(int *)((int)this + 0x730) < (int)nThreshold) {

            return true;

          }

        }

      }

    }

  }

  return true;

}
```

## Open questions

- Confirm calling convention and full signature against callers.
- Recover meaningful types for still-generic parameters.
- Map DAT_* globals and FUN_* callees.
