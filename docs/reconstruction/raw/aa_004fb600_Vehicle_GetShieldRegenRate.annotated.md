# Annotated low-level: Vehicle_GetShieldRegenRate

| Field | Value |
|---|---|
| Stable ID | `aa_004fb600` |
| VA | `0x004fb600` |
| System | unknown |
| Date | 2026-07-23 |

## Machine-level notes

- Source: raw capture for `aa_004fb600`.
- Prefer assembly when decompiler conflicts.
- Recover types for still-generic parameters via callers/xrefs.
- Map DAT_* globals and FUN_* callees in follow-up waves.

## Pseudocode (annotated copy of raw)

```c
/* Vehicle_GetShieldRegenRate
   
   Parameters:
     pVehicle - vehicle; RaceItem* at +0x270
   
   Algorithm:
     if no race item: return 0
     walk raceItem object base -> clonebase+0x3C -> short at +0x4B6
   
   Returns: int shield points added each pulse (after empty-shield debounce).
   
   INFERRED: offset +0x4B6 is RaceShieldRegenRate on race-item clonebase. */

int __fastcall Vehicle_GetShieldRegenRate(VehicleCombatPools_Inferred *pVehicle)

{
  void *pRaceItem;
  
  pRaceItem = pVehicle->pRaceItem_Inferred;
  if (pRaceItem != (void *)0x0) {
    return (int)*(short *)(*(int *)(*(int *)(*(int *)(*(int *)((int)pRaceItem + 4) + 4) + 0xac +
                                            (int)pRaceItem) + 0x3c) + 0x4b6);
  }
  return 0;
}
```

## Open questions

- Confirm calling convention and full signature against callers.
- Recover meaningful types for still-generic parameters.
