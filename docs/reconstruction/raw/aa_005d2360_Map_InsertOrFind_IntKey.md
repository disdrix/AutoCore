# Raw capture: Map_InsertOrFind_IntKey

| Field | Value |
|---|---|
| **Stable ID** | `aa_005d2360` |
| **Module** | `autoassault.exe` |
| **Image base** | `0x400000` |
| **VA** | `0x005d2360` |
| **Canonical name** | `Map_InsertOrFind_IntKey` |
| **System** | unknown |
| **Capture timestamp** | `2026-07-23` |
| **Tool** | Ghidra MCP `batch_decompile` |
| **Integrity** | Do not overwrite this raw body; append versioned sections only |

---

## Raw pseudocode (authoritative decompile)

```c
void __thiscall Map_InsertOrFind_IntKey(void *this,void *pMap,void *pOutPair,int *pKey)

{
  undefined4 uVar1;
  bool bVar2;
  void *pvVar3;
  undefined4 *puVar4;
  undefined4 *puVar5;
  
  pvVar3 = pOutPair;
  puVar5 = *(undefined4 **)((int)this + 4);
  bVar2 = true;
  if (*(char *)((int)puVar5[1] + 0x15) == '\0') {
    puVar4 = (undefined4 *)puVar5[1];
    do {
      puVar5 = puVar4;
      bVar2 = *(int *)pOutPair < (int)puVar5[3];
      if (bVar2) {
        puVar4 = (undefined4 *)*puVar5;
      }
      else {
        puVar4 = (undefined4 *)puVar5[2];
      }
    } while (*(char *)((int)puVar4 + 0x15) == '\0');
  }
  pOutPair = puVar5;
  if (bVar2) {
    if (puVar5 == (undefined4 *)**(int **)((int)this + 4)) {
      puVar5 = (undefined4 *)FUN_005d20b0(&pOutPair,1,puVar5,pvVar3);
      uVar1 = *puVar5;
      *(undefined1 *)((int)pMap + 4) = 1;
      *(undefined4 *)pMap = uVar1;
      return;
    }
    FUN_005a2850();
  }
  if (*(int *)((int)pOutPair + 0xc) < *(int *)pvVar3) {
    puVar5 = (undefined4 *)FUN_005d20b0(&pOutPair,bVar2,puVar5,pvVar3);
    *(undefined4 *)pMap = *puVar5;
    *(undefined1 *)((int)pMap + 4) = 1;
    return;
  }
  *(undefined1 *)((int)pMap + 4) = 0;
  *(void **)pMap = pOutPair;
  return;
}
```
