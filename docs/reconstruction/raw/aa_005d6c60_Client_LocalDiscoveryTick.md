# Raw capture: Client_LocalDiscoveryTick

| Field | Value |
|---|---|
| **Stable ID** | `aa_005d6c60` |
| **Module** | `autoassault.exe` |
| **Image base** | `0x400000` |
| **VA** | `0x005d6c60` |
| **Canonical name** | `Client_LocalDiscoveryTick` |
| **System** | unknown |
| **Capture timestamp** | `2026-07-23` |
| **Tool** | Ghidra MCP `batch_decompile` |
| **Integrity** | Do not overwrite this raw body; append versioned sections only |

---

## Raw pseudocode (authoritative decompile)

```c
/* Client-side discovery tick while driving (~5s). Samples CVOGTerrain_SampleExploredAreaId at
   player XZ;
   if area not yet explored, CVOGCharacter_SetAreaExploredBit. Server is authoritative for
   persistence (UnlockRegion / CreateCharacterExtended). */

undefined4 * __thiscall Client_LocalDiscoveryTick(void *this,undefined4 *pContext)

{
  int continentId;
  char cVar1;
  uchar areaId_00;
  bool bVar2;
  undefined1 areaId;
  int pObject;
  void *this_00;
  float *pfVar3;
  uint *pOutNextDelayMs;
  
  cVar1 = FUN_005cc630();
  if (cVar1 != '\0') {
    CVOGHBAICreatureBase_OnHeartBeat(this,pContext);
    return pContext;
  }
  pObject = *(int *)((int)this + 100);
  if (*(char *)(*(int *)(*(int *)(*(int *)(pObject + 4) + 4) + 0xa8 + pObject) + 0x7e) != '\0') {
    pObject = (**(code **)(*(int *)(*(int *)(*(int *)(pObject + 4) + 4) + 4 + pObject) + 0x1dc))();
    if (pObject != 0) {
      pObject = (**(code **)(*(int *)(*(int *)(*(int *)(*(int *)((int)this + 100) + 4) + 4) + 4 +
                                     *(int *)((int)this + 100)) + 0x1dc))();
      if (*(char *)(pObject + 0x4f1) == '\0') {
        this_00 = (void *)(**(code **)(*(int *)(*(int *)(*(int *)(*(int *)((int)this + 100) + 4) + 4
                                                        ) + 4 + *(int *)((int)this + 100)) + 0x1dc))
                                    ();
        pfVar3 = (float *)(**(code **)(*(int *)(*(int *)(*(int *)((int)this_00 + 4) + 4) + 4 +
                                               (int)this_00) + 0x1a0))();
        pObject = *(int *)(*(int *)(*(int *)((int)this_00 + 4) + 4) + 0xa8 + (int)this_00);
        continentId = *(int *)(pObject + 0xfc);
        areaId_00 = CVOGTerrain_SampleExploredAreaId(*(void **)(pObject + 0xe4f8),*pfVar3,pfVar3[2])
        ;
        bVar2 = CVOGCharacter_IsAreaExplored(this_00,continentId,areaId_00);
        if (!bVar2) {
          CVOGCharacter_SetAreaExploredBit(this_00,continentId,areaId_00,'\x01');
        }
      }
    }
  }
  *(undefined4 *)((int)this + 8) = 5000;
  areaId = FUN_005cc630();
  *(undefined1 *)(*(int *)((int)this + 100) + 0x307) = areaId;
  CVOGHBBase_RescheduleAfterFire(this,pOutNextDelayMs);
  return pContext;
}
```
