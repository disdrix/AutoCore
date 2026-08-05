# Annotated low-level: Creature_GetHpRegenFromEquippedRaceItem

| Field | Value |
|---|---|
| Stable ID | `aa_004c4860` |
| VA | `0x004c4860` |
| System | inventory-transfer |
| Date | 2026-07-23 |

## Machine-level notes

- Source: raw capture for `aa_004c4860`.
- Prefer assembly when decompiler conflicts.
- Recover types for still-generic parameters via callers/xrefs.
- Map DAT_* globals and FUN_* callees in follow-up waves.

## Pseudocode (annotated copy of raw)

```c
/* Creature_GetHpRegenFromEquippedRaceItem — if creature has a vehicle (+0x250),
   delegates to Vehicle_GetHpRegenRate; else returns 1.
   
   Used by VehicleCombatPool_OnTick for the owner-creature HP regen path. */

int __fastcall Creature_GetHpRegenFromEquippedRaceItem(void *pCreature)

{
  int iVar1;
  
  if (*(RE_VehicleCombatPoolFields **)((int)pCreature + 0x250) != (RE_VehicleCombatPoolFields *)0x0)
  {
    iVar1 = Vehicle_GetHpRegenRate(*(RE_VehicleCombatPoolFields **)((int)pCreature + 0x250));
    return iVar1;
  }
  return 1;
}
```

## Open questions

- Confirm calling convention and full signature against callers.
- Recover meaningful types for still-generic parameters.
