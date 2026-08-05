# Raw capture: Vehicle_GetHpRegenRate

| Field | Value |
|---|---|
| **Stable ID** | `aa_004fb630` |
| **Module** | `autoassault.exe` |
| **Image base** | `0x400000` |
| **VA** | `0x004fb630` |
| **Canonical name** | `Vehicle_GetHpRegenRate` |
| **System** | unknown |
| **Capture timestamp** | `2026-07-23` |
| **Tool** | Ghidra MCP `batch_decompile` |
| **Integrity** | Do not overwrite this raw body; append versioned sections only |

---

## Raw pseudocode (authoritative decompile)

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
