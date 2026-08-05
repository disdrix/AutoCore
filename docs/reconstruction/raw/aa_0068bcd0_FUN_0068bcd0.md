# Raw capture: FUN_0068bcd0

| Field | Value |
|---|---|
| **Stable ID** | `aa_0068bcd0` |
| **Module** | `autoassault.exe` |
| **Image base** | `0x400000` |
| **VA** | `0x0068bcd0` |
| **Canonical name** | `FUN_0068bcd0` |
| **System** | unknown |
| **Capture timestamp** | `2026-07-23` |
| **Tool** | Ghidra MCP `batch_decompile` |
| **Integrity** | Do not overwrite this raw body; append versioned sections only |

---

## Raw pseudocode (authoritative decompile)

```c
void __thiscall FUN_0068bcd0(int param_1,undefined4 *param_2)

{
  undefined4 *puVar1;
  int iVar2;
  uint uVar3;
  int iVar4;
  undefined4 *puVar5;
  uint local_50;
  undefined4 local_48;
  undefined4 local_44;
  undefined4 local_40;
  undefined1 local_3c [48];
  void *local_c;
  undefined1 *puStack_8;
  undefined4 local_4;
  
  local_4 = 0xffffffff;
  puStack_8 = &LAB_009aa328;
  local_c = ExceptionList;
  if (*(int *)(param_1 + 100) == 0) {
    uVar3 = 0;
  }
  else {
    uVar3 = *(int *)(param_1 + 0x68) - *(int *)(param_1 + 100) >> 2;
  }
  local_50 = uVar3 / 3 & 0xffff;
  if (local_50 != 0) {
    iVar4 = 0;
    ExceptionList = &local_c;
    do {
      iVar2 = *(int *)(param_1 + 100);
      local_40 = *(undefined4 *)(iVar4 + 8 + iVar2);
      local_44 = *(undefined4 *)(iVar4 + 4 + iVar2);
      local_48 = *(undefined4 *)(iVar4 + iVar2);
      puVar1 = (undefined4 *)FUN_0069f950(local_3c,&local_48);
      puVar5 = param_2;
      for (iVar2 = 0xc; iVar2 != 0; iVar2 = iVar2 + -1) {
        *puVar5 = *puVar1;
        puVar1 = puVar1 + 1;
        puVar5 = puVar5 + 1;
      }
      local_4 = 0;
      FUN_0056f570();
      local_4 = 0xffffffff;
      FUN_0056f570();
      iVar4 = iVar4 + 0xc;
      local_50 = local_50 - 1;
    } while (local_50 != 0);
  }
  ExceptionList = local_c;
  return;
}
```
