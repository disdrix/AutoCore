# Raw capture: FUN_0069bab0

| Field | Value |
|---|---|
| **Stable ID** | `aa_0069bab0` |
| **Module** | `autoassault.exe` |
| **Image base** | `0x400000` |
| **VA** | `0x0069bab0` |
| **Canonical name** | `FUN_0069bab0` |
| **System** | unknown |
| **Capture timestamp** | `2026-07-23` |
| **Tool** | Ghidra MCP `batch_decompile` |
| **Integrity** | Do not overwrite this raw body; append versioned sections only |

---

## Raw pseudocode (authoritative decompile)

```c
void __thiscall FUN_0069bab0(int param_1,int param_2)

{
  int iVar1;
  int *piVar2;
  uint uVar3;
  int local_4;
  
  iVar1 = *(int *)(param_2 + 4);
  local_4 = param_1;
  if ((iVar1 == 0) ||
     ((uint)(*(int *)(param_2 + 0xc) - iVar1 >> 2) <= (uint)(*(int *)(param_2 + 8) - iVar1 >> 2))) {
    FUN_00697f60(*(undefined4 *)(param_2 + 8),1,&local_4);
  }
  else {
    piVar2 = *(int **)(param_2 + 8);
    *piVar2 = param_1;
    *(int **)(param_2 + 8) = piVar2 + 1;
  }
  for (uVar3 = 0;
      (*(int *)(param_1 + 0xc) != 0 &&
      (uVar3 < (uint)((*(int *)(param_1 + 0x10) - *(int *)(param_1 + 0xc)) / 0xc)));
      uVar3 = uVar3 + 1) {
    FUN_0069bab0(param_2);
  }
  return;
}
```
