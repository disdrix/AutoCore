# Raw capture: Vehicle_EquipPowerPlant

| Field | Value |
|---|---|
| **Stable ID** | `aa_004fe1b0` |
| **Module** | `autoassault.exe` |
| **Image base** | `0x400000` |
| **VA** | `0x004fe1b0` |
| **Canonical name** | `Vehicle_EquipPowerPlant` |
| **System** | inventory-transfer |
| **Capture timestamp** | `2026-07-23` |
| **Tool** | Ghidra MCP `batch_decompile` |
| **Integrity** | Do not overwrite this raw body; append versioned sections only |

---

## Raw pseudocode (authoritative decompile)

```c
/* Vehicle_EquipPowerPlant — swap PowerPlant hardpoint (+0x268).
   
   Recalculates MaxHeat via Vehicle_CalcHeatMaximum → stores at vehicle+0x244.
   Also updates powerplant TFID at +0x620/+0x624 and attaches item to vehicle. */

void __thiscall
Vehicle_EquipPowerPlant
          (void *this,void *pNewPowerPlant,void **ppOutPrevious,bool bKeepPreviousAttached)

{
  int iVar1;
  int *piVar2;
  int iVar3;
  int iVar4;
  
  if ((pNewPowerPlant == *(void **)((int)this + 0x268)) && (pNewPowerPlant != (void *)0x0)) {
    FUN_007a4480(0,"Tried to equip same powerplant %d",
                 *(undefined4 *)
                  (*(int *)(*(int *)(*(int *)((int)pNewPowerPlant + 4) + 4) + 0xac +
                           (int)pNewPowerPlant) + 0x34));
    return;
  }
  FUN_00512670();
  if (ppOutPrevious != (void **)0x0) {
    *ppOutPrevious = *(void **)((int)this + 0x268);
  }
  iVar4 = *(int *)((int)this + 0x268);
  if (iVar4 != 0) {
    if (!bKeepPreviousAttached) {
      FUN_004fbb50(*(int *)(*(int *)(iVar4 + 4) + 4) + 4 + iVar4);
    }
    (**(code **)(*(int *)(*(int *)(*(int *)(*(int *)((int)this + 0x268) + 4) + 4) + 4 +
                         *(int *)((int)this + 0x268)) + 0x158))(0);
  }
  *(void **)((int)this + 0x268) = pNewPowerPlant;
  piVar2 = *(int **)(*(int *)(*(int *)((int)this + 4) + 4) + 0xb0 + (int)this);
  if (piVar2 != (int *)0x0) {
    piVar2 = (int *)(**(code **)(*piVar2 + 0x1dc))();
    if (piVar2 != (int *)0x0) {
      (**(code **)(*piVar2 + 0x5c))();
    }
  }
  if (pNewPowerPlant != (void *)0x0) {
    iVar4 = *(int *)((int)this + 0x268);
    if (*(int *)(*(int *)(*(int *)(*(int *)(iVar4 + 4) + 4) + 0xac + iVar4) + 0x38) != 10) {
      iVar1 = *(int *)(*(int *)(iVar4 + 4) + 4);
      iVar3 = iVar4 + iVar1;
      FUN_007a4480(1,"Set powerplant of unhappy type: CBID:%d COID:%I64d",
                   *(undefined4 *)(*(int *)(iVar3 + 0xac) + 0x34),*(undefined4 *)(iVar3 + 0x164),
                   *(undefined4 *)(iVar4 + 0x168 + iVar1));
    }
    iVar4 = *(int *)(*(int *)((int)pNewPowerPlant + 4) + 4);
    *(undefined4 *)((int)this + 0x620) = *(undefined4 *)(iVar4 + 0x164 + (int)pNewPowerPlant);
    *(undefined4 *)((int)this + 0x624) = *(undefined4 *)(iVar4 + 0x168 + (int)pNewPowerPlant);
    (**(code **)(*(int *)(*(int *)(*(int *)(*(int *)((int)this + 0x268) + 4) + 4) + 4 +
                         *(int *)((int)this + 0x268)) + 0x158))
              (*(int *)(*(int *)((int)this + 4) + 4) + 4 + (int)this);
    iVar4 = *(int *)((int)this + 0x268);
    if (iVar4 != 0) {
      iVar4 = *(int *)(*(int *)(iVar4 + 4) + 4) + 4 + iVar4;
    }
    FUN_004fdcb0(iVar4);
    (**(code **)(*(int *)(*(int *)(*(int *)(*(int *)((int)this + 0x268) + 4) + 4) + 4 +
                         *(int *)((int)this + 0x268)) + 0x218))
              (*(undefined4 *)(*(int *)(*(int *)((int)this + 4) + 4) + 0xa8 + (int)this));
    iVar4 = Vehicle_CalcHeatMaximum(this);
    *(int *)((int)this + 0x244) = iVar4;
    return;
  }
  *(undefined4 *)((int)this + 0x620) = 0xffffffff;
  *(undefined4 *)((int)this + 0x624) = 0xffffffff;
  iVar4 = Vehicle_CalcHeatMaximum(this);
  *(int *)((int)this + 0x244) = iVar4;
  return;
}
```
