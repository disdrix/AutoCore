# Annotated low-level: CVOGCharacter_SetAreaExploredBit

| Field | Value |
|---|---|
| Stable ID | `aa_005326b0` |
| VA | `0x005326b0` |
| System | missions-progression |
| Date | 2026-07-23 |

## Machine-level notes

- Source: raw capture for `aa_005326b0`.
- Prefer assembly when decompiler conflicts.
- Recover types for still-generic parameters via callers/xrefs.
- Map DAT_* globals and FUN_* callees in follow-up waves.

## Pseudocode (annotated copy of raw)

```c
/* Set/clear one explored-area bit on local character, LogicUI notify type 0x20.
   If no continent entry and map allows: UnlockContinentObject first.
   Called from Client_RecvUnlockRegion bit-diff path and Client_LocalDiscoveryTick. */

void __thiscall CVOGCharacter_SetAreaExploredBit(void *this,int continentId,char areaId,char setBit)

{
  int *piVar1;
  int *piVar2;
  void *pvVar3;
  int iVar4;
  uint uVar5;
  uint logicUiPayload [7];
  undefined4 logicUiType;
  
  if (('\0' < areaId) && (areaId < '!')) {
    uVar5 = 1 << (areaId - 1U & 0x1f);
    pvVar3 = CNDHash_LookupByKey(*(void **)((int)this + 0x534),continentId);
    if (pvVar3 == (void *)0x0) {
      if (*(char *)(*(int *)(*(int *)(*(int *)((int)this + 4) + 4) + 0xa8 + (int)this) + 0x7e) !=
          '\0') {
        CVOGReaction_UnlockContinentObject(this,continentId);
      }
    }
    else {
      if (setBit == '\0') {
        *(uint *)((int)pvVar3 + 8) = *(uint *)((int)pvVar3 + 8) & ~uVar5;
      }
      else {
        *(uint *)((int)pvVar3 + 8) = *(uint *)((int)pvVar3 + 8) | uVar5;
      }
      logicUiType = 0x20;
      logicUiPayload[0] = (int)areaId;
      Client_SendLogicUiPacket(logicUiPayload);
      if (*(char *)(*(int *)(*(int *)(*(int *)((int)this + 4) + 4) + 0xa8 + (int)this) + 0x7e) !=
          '\0') {
        iVar4 = FUN_00540060();
        piVar1 = *(int **)(iVar4 + 4);
        piVar2 = (int *)*piVar1;
        if (piVar2 != piVar1) {
          while ((piVar2[3] != continentId || ((uint)*(byte *)(piVar2 + 4) != (int)areaId))) {
            FUN_004e2060();
            if (piVar2 == piVar1) {
              return;
            }
          }
        }
      }
    }
  }
  return;
}
```

## Open questions

- Confirm calling convention and full signature against callers.
- Recover meaningful types for still-generic parameters.
