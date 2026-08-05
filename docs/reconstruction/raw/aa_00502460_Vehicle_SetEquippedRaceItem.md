# Raw capture: Vehicle_SetEquippedRaceItem

| Field | Value |
|---|---|
| **Stable ID** | `aa_00502460` |
| **Module** | `autoassault.exe` |
| **Image base** | `0x400000` |
| **VA** | `0x00502460` |
| **Canonical name** | `Vehicle_SetEquippedRaceItem` |
| **System** | inventory-transfer |
| **Capture timestamp** | `2026-07-23` |
| **Tool** | Ghidra MCP `batch_decompile` |
| **Integrity** | Do not overwrite this raw body; append versioned sections only |

---

## Raw pseudocode (authoritative decompile)

```c
/* Vehicle_SetEquippedRaceItem — set race item@+0x270 and recalc pools.
   
   Parameters:
     this: vehicle; pRaceItem; ppOutPrevious (optional out); bSkipUnbind
   Returns: void.
   
   Algorithm:
     Optionally write previous to *ppOutPrevious; unbind old
     Expect type 6 / subtype 0xb; bind new; Vehicle_RecalcCombatPools
   Race item drives HP regen rate in CVOGHBRegeneration_OnHeartBeat. */

void __thiscall
Vehicle_SetEquippedRaceItem(void *this,void *pRaceItem,void **ppOutPrevious,char bSkipUnbind)

{
  int nCloneBase;
  
  FUN_00512670();
  if (ppOutPrevious != (void **)0x0) {
    *ppOutPrevious = *(void **)((int)this + 0x270);
  }
  nCloneBase = *(int *)((int)this + 0x270);
  if (nCloneBase != 0) {
    if (bSkipUnbind == '\0') {
      FUN_004fbb50(*(int *)(*(int *)(nCloneBase + 4) + 4) + 4 + nCloneBase);
    }
    (**(code **)(*(int *)(*(int *)(*(int *)(*(int *)((int)this + 0x270) + 4) + 4) + 4 +
                         *(int *)((int)this + 0x270)) + 0x158))(0);
  }
  *(void **)((int)this + 0x270) = pRaceItem;
  if (pRaceItem != (void *)0x0) {
    nCloneBase = *(int *)(*(int *)(*(int *)((int)pRaceItem + 4) + 4) + 0xac + (int)pRaceItem);
    if ((*(int *)(nCloneBase + 0x38) != 6) ||
       (*(short *)(*(int *)(nCloneBase + 0x3c) + 0x3f4) != 0xb)) {
      nCloneBase = *(int *)(*(int *)((int)pRaceItem + 4) + 4);
      FUN_007a4480(1,"Set race item of unhappy type: CBID:%d COID:%I64d",
                   *(undefined4 *)(*(int *)((int)pRaceItem + nCloneBase + 0xac) + 0x34),
                   *(undefined4 *)((int)pRaceItem + nCloneBase + 0x164),
                   *(undefined4 *)(nCloneBase + 0x168 + (int)pRaceItem));
    }
    (**(code **)(*(int *)(*(int *)(*(int *)((int)pRaceItem + 4) + 4) + 4 + (int)pRaceItem) + 0x158))
              (*(int *)(*(int *)((int)this + 4) + 4) + 4 + (int)this);
    nCloneBase = *(int *)((int)this + 0x270);
    if (nCloneBase != 0) {
      nCloneBase = *(int *)(*(int *)(nCloneBase + 4) + 4) + 4 + nCloneBase;
    }
    FUN_004fdcb0(nCloneBase);
    (**(code **)(*(int *)(*(int *)(*(int *)((int)pRaceItem + 4) + 4) + 4 + (int)pRaceItem) + 0x218))
              (*(undefined4 *)(*(int *)(*(int *)((int)this + 4) + 4) + 0xa8 + (int)this));
  }
  Vehicle_RecalcCombatPools(this);
  return;
}
```
