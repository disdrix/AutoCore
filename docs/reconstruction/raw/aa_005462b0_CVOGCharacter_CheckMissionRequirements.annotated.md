# Annotated low-level: CVOGCharacter_CheckMissionRequirements

| Field | Value |
|---|---|
| Stable ID | `aa_005462b0` |
| VA | `0x005462b0` |
| System | missions-progression |
| Date | 2026-07-23 |

## Machine-level notes

- Source: raw capture for `aa_005462b0`.
- Prefer assembly when decompiler conflicts (not re-checked in scaffold pass).
- Integer widths: trust decompiler until spot-checked; document corrections here.
- Side-effect order: preserve call and store order from raw pseudocode.
- Uncertainty: parameter meanings and object types often Probable/Tentative until cross-function validation.

## Pseudocode (annotated copy of raw)

```c
/* CheckMissionRequirements

   

   Validates whether a character meets all requirements for a mission.

   Called from SearchAutoMissions to determine if a candidate mission should be auto-awarded.

   

   Checks performed:

   1. Race: mission +0x90 (ushort) vs character +0x532 (byte), 0xffff = no restriction

   2. Faction: mission +0x92 (ushort) vs character +0x531 (byte), 0xffff = no restriction

   3. Min level: character level (vtable +0x27c) >= mission min level (+0x94)

   4. Max level: character level (vtable +0x27c) <= mission max level (+0x98, 0 = no max)

   5. Currency: FUN_0052ada0 checks required currency at mission +0x104 >= threshold +0x108

   6. Flag check: FUN_005405e0 at mission +0x118 (0xffffffff = skip)

   7. Prerequisites: up to 4 prereq missions at +0x9c, each checked via FUN_0052aa20

   

   Returns:

     -1 if any requirement fails

      0 if all requirements pass

     uMissionID of the first blocking prerequisite (if prereqs checked and one fails) */



int __thiscall CVOGCharacter_CheckMissionRequirements(void *this,int *pMissionDef,int *pCharacter)



{

  bool bVar1;

  int *this_00;

  char cVar2;

  bool bVar3;

  int iVar4;

  int iVar5;

  uint *puVar6;

  byte bStack_9;

  uint uStack_8;

  int iStack_4;

  

  this_00 = pMissionDef;

                    /* // Check race restriction (mission +0x90 vs character +0x532) */

                    /* // Check faction restriction (mission +0x92 vs character +0x531) */

  if (((*(ushort *)((int)this + 0x90) != 0xffff) &&

      ((ushort)*(byte *)(*(int *)(*(int *)(*(int *)(pMissionDef[1] + 4) + 0xac + (int)pMissionDef) +

                                 0x3c) + 0x532) != *(ushort *)((int)this + 0x90))) ||

     ((*(ushort *)((int)this + 0x92) != 0xffff &&

      ((ushort)*(byte *)(*(int *)(*(int *)(*(int *)(pMissionDef[1] + 4) + 0xac + (int)pMissionDef) +

                                 0x3c) + 0x531) != *(ushort *)((int)this + 0x92))))) {

                    /* // Requirement failed, return -1 */

    return -1;

  }

                    /* // Check character level >= mission min level (+0x94) */

  iVar4 = (**(code **)(*(int *)(*(int *)(pMissionDef[1] + 4) + 4 + (int)pMissionDef) + 0x27c))();

  if (iVar4 < *(int *)((int)this + 0x94)) {

    return -1;

  }

                    /* // Check character level <= mission max level (+0x98, 0 = no max) */

  if ((0 < *(int *)((int)this + 0x98)) &&

     (iVar4 = (**(code **)(*(int *)(*(int *)(pMissionDef[1] + 4) + 4 + (int)pMissionDef) + 0x27c))()

     , *(int *)((int)this + 0x98) < iVar4)) {

    return -1;

  }

                    /* // Check required currency (FUN_0052ada0 at mission +0x104) */

  if ((-1 < *(int *)((int)this + 0x104)) &&

     (iVar4 = *(int *)((int)this + 0x108), iVar5 = FUN_0052ada0(*(int *)((int)this + 0x104)),

     iVar5 < iVar4)) {

    return -1;

  }

                    /* // Check flag condition (FUN_005405e0 at mission +0x118) */

  if ((*(int *)((int)this + 0x118) != -1) &&

     (cVar2 = FUN_005405e0(*(int *)((int)this + 0x118)), cVar2 == '\0')) {

    return -1;

  }

                    /* // Check prerequisite missions (up to 4 at mission +0x9c) */

  bVar1 = false;

  pMissionDef = (int *)0x1;

  bStack_9 = 0;

  uStack_8 = 0xffffffff;

  puVar6 = (uint *)((int)this + 0x9c);

  iStack_4 = 4;

  do {

    if (*puVar6 != 0xffffffff) {

                    /* // Check if each prereq is satisfied (FUN_0052aa20) */

      bVar1 = true;

      bVar3 = CVOGCharacter_HasCompletedMission(this_00,*puVar6);

      pMissionDef = (int *)(uint)((byte)pMissionDef & bVar3);

      bStack_9 = bStack_9 | bVar3;

      if ((!bVar3) && (uStack_8 == 0xffffffff)) {

        uStack_8 = *puVar6;

      }

    }

    puVar6 = puVar6 + 1;

    iStack_4 = iStack_4 + -1;

  } while (iStack_4 != 0);

                    /* // Evaluate prereq satisfaction flags against mission rules (+0x124, +0x120)

                        */

  if (bVar1) {

    if (*(int *)((int)this + 0x124) == 0) {

      if (((byte)pMissionDef == '\0') && ((*(int *)((int)this + 0x120) == 0 || (bStack_9 == 0)))) {

        return uStack_8;

      }

    }

    else if (((byte)pMissionDef != '\0') || ((*(int *)((int)this + 0x120) != 0 && (bStack_9 != 0))))

    {

      return -1;

    }

  }

                    /* // All requirements satisfied, return 0 */

  return 0;

}
```

## Open questions

- Confirm calling convention and full signature against callers.
- Recover meaningful types for still-generic parameters.
- Map DAT_* globals and FUN_* callees.
