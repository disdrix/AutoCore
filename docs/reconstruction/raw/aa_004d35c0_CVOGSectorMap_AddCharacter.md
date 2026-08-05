# Raw capture: CVOGSectorMap_AddCharacter

| Field | Value |
|---|---|
| **Stable ID** | `aa_004d35c0` |
| **Module** | `autoassault.exe` |
| **Image base** | `0x400000` |
| **VA** | `0x004d35c0` |
| **Canonical name** | `CVOGSectorMap_AddCharacter` |
| **System** | unknown |
| **Capture timestamp** | `2026-07-23` |
| **Tool** | Ghidra MCP `batch_decompile` |
| **Integrity** | Do not overwrite this raw body; append versioned sections only |

---

## Raw pseudocode (authoritative decompile)

```c
/* CVOGSectorMap_AddCharacter: push character into sector list; maybe DoCreatorLoadTrigger once;
   always DoPlayerOnLoadTrigger. Invoked from character create path (FUN_00521310 /
   CreateFromPacket). */

void __thiscall CVOGSectorMap_AddCharacter(int param_1,undefined4 param_2)

{
  int iVar1;
  undefined4 *puVar2;
  undefined4 uVar3;
  bool bVar4;
  
  uVar3 = param_2;
  iVar1 = *(int *)(param_1 + 0xe75c);
  if ((iVar1 == 0) ||
     ((uint)(*(int *)(param_1 + 0xe764) - iVar1 >> 2) <=
      (uint)(*(int *)(param_1 + 0xe760) - iVar1 >> 2))) {
    FUN_004e39d0(*(undefined4 *)(param_1 + 0xe760),1,&param_2);
  }
  else {
    puVar2 = *(undefined4 **)(param_1 + 0xe760);
    *puVar2 = param_2;
    *(undefined4 **)(param_1 + 0xe760) = puVar2 + 1;
  }
  iVar1 = *(int *)(param_1 + 0xe75c);
  if (*(char *)(param_1 + 0xf6) == '\0') {
    if (iVar1 == 0) goto LAB_004d365d;
    bVar4 = *(int *)(param_1 + 0xe760) - iVar1 >> 2 == 1;
  }
  else if (iVar1 == 0) {
    bVar4 = *(int *)(*(int *)(param_1 + 0xe5d0) + 0xc) == 0;
  }
  else {
    bVar4 = *(int *)(param_1 + 0xe760) - iVar1 >> 2 == *(int *)(*(int *)(param_1 + 0xe5d0) + 0xc);
  }
  if (bVar4) {
    CVOGSectorMap_DoCreatorLoadTrigger(uVar3);
  }
LAB_004d365d:
  CVOGSectorMap_DoPlayerOnLoadTrigger(uVar3);
  return;
}
```
