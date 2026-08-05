# Raw capture: CVOGReaction_MarkRepairStation

| Field | Value |
|---|---|
| **Stable ID** | `aa_00521e00` |
| **Module** | `autoassault.exe` |
| **Image base** | `0x400000` |
| **VA** | `0x00521e00` |
| **Canonical name** | `CVOGReaction_MarkRepairStation` |
| **System** | unknown |
| **Capture timestamp** | `2026-07-23` |
| **Tool** | Ghidra MCP `batch_decompile` |
| **Integrity** | Do not overwrite this raw body; append versioned sections only |

---

## Raw pseudocode (authoritative decompile)

```c
/* CVOGReaction_MarkRepairStation — reaction type 29.
   
   this = character (player).
   param2 = reaction GenericVar1 (station key, often small int like 3 — NOT map object COID).
   
   Stores on character:
     +0x740 = continent/map id from related object +0xfc  (LastStationMapId)
     +0x744 = GenericVar1                               (LastStationId)
     flags  +0x634 |= 1
   Calls CVOGReaction_UpdateRepairStationPosition(player TFID, stationKey).
   
   If related object missing: sets LastStationId=-1, fails.
   
   AutoCore: Reaction.HandleMarkRepairStation + Character.SetLastRepairStation
   Server also snapshots pad pose from map Objects / nearby graphics / trigger. */

uint __thiscall CVOGReaction_MarkRepairStation(int param_1,undefined4 param_2)

{
  int iVar1;
  undefined4 uVar2;
  uint uVar3;
  undefined4 local_8;
  undefined4 local_4;
  
  uVar3 = *(uint *)(param_1 + 4);
  iVar1 = *(int *)(*(int *)(uVar3 + 4) + 0xa8 + param_1);
  if (iVar1 != 0) {
    uVar2 = *(undefined4 *)(iVar1 + 0xfc);
    *(uint *)(param_1 + 0x634) = *(uint *)(param_1 + 0x634) | 1;
    *(undefined4 *)(param_1 + 0x740) = uVar2;
    *(undefined4 *)(param_1 + 0x744) = param_2;
    local_8 = *(undefined4 *)(*(int *)(uVar3 + 4) + 0x164 + param_1);
    local_4 = *(undefined4 *)(*(int *)(uVar3 + 4) + 0x168 + param_1);
    uVar3 = CVOGReaction_UpdateRepairStationPosition(&local_8,param_2);
    return uVar3;
  }
  *(uint *)(param_1 + 0x634) = *(uint *)(param_1 + 0x634) | 1;
  *(undefined4 *)(param_1 + 0x744) = 0xffffffff;
  return uVar3 & 0xffffff00;
}
```
