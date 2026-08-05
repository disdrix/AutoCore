# Raw capture: Vehicle_GetShieldRegenRate

| Field | Value |
|---|---|
| **Stable ID** | `aa_004fb600` |
| **Module** | `autoassault.exe` |
| **Image base** | `0x400000` |
| **VA** | `0x004fb600` |
| **Canonical name** | `Vehicle_GetShieldRegenRate` |
| **System** | unknown |
| **Capture timestamp** | `2026-07-23` |
| **Tool** | Ghidra MCP `batch_decompile` |
| **Integrity** | Do not overwrite this raw body; append versioned sections only |

---

## Raw pseudocode (authoritative decompile)

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
