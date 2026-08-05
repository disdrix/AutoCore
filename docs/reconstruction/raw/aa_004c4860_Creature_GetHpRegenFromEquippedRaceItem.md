# Raw capture: Creature_GetHpRegenFromEquippedRaceItem

| Field | Value |
|---|---|
| **Stable ID** | `aa_004c4860` |
| **Module** | `autoassault.exe` |
| **Image base** | `0x400000` |
| **VA** | `0x004c4860` |
| **Canonical name** | `Creature_GetHpRegenFromEquippedRaceItem` |
| **System** | inventory-transfer |
| **Capture timestamp** | `2026-07-23` |
| **Tool** | Ghidra MCP `batch_decompile` |
| **Integrity** | Do not overwrite this raw body; append versioned sections only |

---

## Raw pseudocode (authoritative decompile)

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
