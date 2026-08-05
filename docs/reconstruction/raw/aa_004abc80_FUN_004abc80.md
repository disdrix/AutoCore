# Raw capture: FUN_004abc80

| Field | Value |
|---|---|
| **Stable ID** | `aa_004abc80` |
| **Module** | `autoassault.exe` |
| **Image base** | `0x400000` |
| **VA** | `0x004abc80` |
| **Canonical name** | `FUN_004abc80` |
| **System** | unknown |
| **Capture timestamp** | `2026-07-23` |
| **Tool** | Ghidra MCP `batch_decompile` |
| **Integrity** | Do not overwrite this raw body; append versioned sections only |

---

## Raw pseudocode (authoritative decompile)

```c
void FUN_004abc80(int param_1,int param_2)

{
  undefined1 *puVar1;
  char cVar2;
  int iVar3;
  int iVar4;
  uint local_8;
  int local_4;
  
  iVar4 = 0;
  local_4 = 4;
  do {
    cVar2 = '\0';
    local_8 = local_8 & 0xffffff00;
    iVar3 = param_2;
    do {
      puVar1 = (undefined1 *)(*(int *)(param_1 + 4) + iVar4);
      FUN_004a8ec0(CONCAT31((int3)((uint)puVar1 >> 8),*puVar1),
                   CONCAT31((int3)((uint)*(int *)(param_1 + 4) >> 8),puVar1[1]),iVar3,local_8);
      cVar2 = cVar2 + '\x01';
      iVar3 = iVar3 + 0x20;
      local_8 = CONCAT31(local_8._1_3_,cVar2);
    } while (cVar2 < '\x04');
    param_2 = param_2 + 8;
    iVar4 = iVar4 + 2;
    local_4 = local_4 + -1;
  } while (local_4 != 0);
  return;
}
```
