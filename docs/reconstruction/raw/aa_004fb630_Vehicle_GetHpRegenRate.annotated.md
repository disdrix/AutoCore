# Annotated low-level: Vehicle_GetHpRegenRate

| Field | Value |
|---|---|
| Stable ID | `aa_004fb630` |
| VA | `0x004fb630` |
| System | unknown |
| Date | 2026-07-23 |

## Machine-level notes

- Source: raw capture for `aa_004fb630`.
- Prefer assembly when decompiler conflicts.
- Recover types for still-generic parameters via callers/xrefs.
- Map DAT_* globals and FUN_* callees in follow-up waves.

## Pseudocode (annotated copy of raw)

```c
/* Vehicle_GetHpRegenRate
   
   Parameters:
     pVehicle - vehicle; RaceItem* at +0x270
   
   Algorithm:
     if no race item: return 0
     walk raceItem object base -> clonebase+0x3C -> short at +0x3FA
   
   Returns: int HP added each pulse.
   
   INFERRED: offset +0x3FA is RaceRegenRate (HP) on race-item clonebase.
   OnTick also adds Creature_GetHpRegenFromEquippedRaceItem. */

int __fastcall Vehicle_GetHpRegenRate(RE_VehicleCombatPoolFields *pVehicle)

{
  void *pRaceItem;
  
  pRaceItem = pVehicle->pRaceItem_Inferred;
  if (pRaceItem != (void *)0x0) {
    return (int)*(short *)(*(int *)(*(int *)(*(int *)(*(int *)((int)pRaceItem + 4) + 4) + 0xac +
                                            (int)pRaceItem) + 0x3c) + 0x3fa);
  }
  return 0;
}
```

## Open questions

- Confirm calling convention and full signature against callers.
- Recover meaningful types for still-generic parameters.
