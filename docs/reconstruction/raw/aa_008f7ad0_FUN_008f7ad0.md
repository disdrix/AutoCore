# Raw capture: FUN_008f7ad0

| Field | Value |
|---|---|
| **Stable ID** | `aa_008f7ad0` |
| **Module** | `autoassault.exe` |
| **Image base** | `0x400000` |
| **VA** | `0x008f7ad0` |
| **Canonical name** | `FUN_008f7ad0` |
| **System** | unknown |
| **Capture timestamp** | `2026-07-23` |
| **Tool** | Ghidra MCP `batch_decompile` |
| **Integrity** | Do not overwrite this raw body; append versioned sections only |

---

## Raw pseudocode (authoritative decompile)

```c
void __thiscall FUN_008f7ad0(int *param_1,undefined4 param_2)

{
  int iVar1;
  char cVar2;
  int iVar3;
  
  FUN_007916e0(param_2);
  if (((char)param_2 != '\0') && (cVar2 = (**(code **)(*param_1 + 0x3d8))(), cVar2 != '\0')) {
    (**(code **)(*param_1 + 0x450))();
    if ((param_1[0x141] != 0) &&
       (cVar2 = (**(code **)(*(int *)param_1[0x141] + 0xd0))(), cVar2 != '\0')) {
      (**(code **)(*(int *)param_1[0x141] + 4))(0);
    }
    if ((param_1[0x14c] != 0) &&
       (cVar2 = (**(code **)(*(int *)param_1[0x14c] + 0xd0))(), cVar2 != '\0')) {
      (**(code **)(*(int *)param_1[0x14c] + 4))(0);
    }
    if ((param_1[0x14b] != 0) &&
       (cVar2 = (**(code **)(*(int *)param_1[0x14b] + 0xd0))(), cVar2 != '\0')) {
      (**(code **)(*(int *)param_1[0x14b] + 4))(0);
    }
    if ((param_1[0x14d] != 0) &&
       (cVar2 = (**(code **)(*(int *)param_1[0x14d] + 0xd0))(), cVar2 != '\0')) {
      (**(code **)(*(int *)param_1[0x14d] + 4))(0);
    }
    if ((param_1[0x142] != 0) &&
       (cVar2 = (**(code **)(*(int *)param_1[0x142] + 0xd0))(), cVar2 != '\0')) {
      (**(code **)(*(int *)param_1[0x142] + 4))(0);
    }
    if ((param_1[0x152] != 0) &&
       (cVar2 = (**(code **)(*(int *)param_1[0x152] + 0xd0))(), cVar2 != '\0')) {
      (**(code **)(*(int *)param_1[0x152] + 4))(0);
    }
    param_1 = param_1 + 0x150;
    iVar3 = 2;
    do {
      iVar1 = *param_1;
      if (((iVar1 != 0) && (*(int *)(iVar1 + 0xe80) != 0)) &&
         (cVar2 = (**(code **)(**(int **)(iVar1 + 0xe80) + 0xd0))(), cVar2 != '\0')) {
        (**(code **)(**(int **)(*param_1 + 0xe80) + 4))(0);
      }
      param_1 = param_1 + 1;
      iVar3 = iVar3 + -1;
    } while (iVar3 != 0);
  }
  return;
}
```
