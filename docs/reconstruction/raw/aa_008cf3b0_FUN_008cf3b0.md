# Raw capture: FUN_008cf3b0

| Field | Value |
|---|---|
| **Stable ID** | `aa_008cf3b0` |
| **Module** | `autoassault.exe` |
| **Image base** | `0x400000` |
| **VA** | `0x008cf3b0` |
| **Canonical name** | `FUN_008cf3b0` |
| **System** | unknown |
| **Capture timestamp** | `2026-07-23` |
| **Tool** | Ghidra MCP `batch_decompile` |
| **Integrity** | Do not overwrite this raw body; append versioned sections only |

---

## Raw pseudocode (authoritative decompile)

```c
void FUN_008cf3b0(undefined4 param_1)

{
  int in_EAX;
  int iVar1;
  int *piVar2;
  
  if (*(int *)(in_EAX + 0x70c) != 0) {
    (**(code **)(**(int **)(in_EAX + 0x70c) + 4))(param_1);
  }
  if (*(int *)(in_EAX + 0x710) != 0) {
    (**(code **)(**(int **)(in_EAX + 0x710) + 4))(param_1);
  }
  if (*(int *)(in_EAX + 0x714) != 0) {
    (**(code **)(**(int **)(in_EAX + 0x714) + 4))(param_1);
  }
  if (*(int *)(in_EAX + 0x718) != 0) {
    (**(code **)(**(int **)(in_EAX + 0x718) + 4))(param_1);
  }
  if (*(int *)(in_EAX + 0x78c) != 0) {
    (**(code **)(**(int **)(in_EAX + 0x78c) + 4))(param_1);
  }
  if (*(int *)(in_EAX + 0x790) != 0) {
    (**(code **)(**(int **)(in_EAX + 0x790) + 4))(param_1);
  }
  if (*(int *)(in_EAX + 0x6b8) != 0) {
    (**(code **)(**(int **)(in_EAX + 0x6b8) + 4))(param_1);
  }
  if (*(int *)(in_EAX + 0x6b0) != 0) {
    (**(code **)(**(int **)(in_EAX + 0x6b0) + 4))(param_1);
  }
  if (*(int *)(in_EAX + 0x694) != 0) {
    (**(code **)(**(int **)(in_EAX + 0x694) + 4))(param_1);
  }
  if (*(int *)(in_EAX + 0x6a8) != 0) {
    (**(code **)(**(int **)(in_EAX + 0x6a8) + 4))(param_1);
  }
  if (*(int *)(in_EAX + 0x6a0) != 0) {
    (**(code **)(**(int **)(in_EAX + 0x6a0) + 4))(param_1);
  }
  if (*(int *)(in_EAX + 0x698) != 0) {
    (**(code **)(**(int **)(in_EAX + 0x698) + 4))(param_1);
  }
  piVar2 = (int *)(in_EAX + 0x774);
  iVar1 = 2;
  do {
    if (piVar2[-2] != 0) {
      (**(code **)(*(int *)piVar2[-2] + 4))(param_1);
    }
    if (*piVar2 != 0) {
      (**(code **)(*(int *)*piVar2 + 4))(param_1);
    }
    if (piVar2[2] != 0) {
      (**(code **)(*(int *)piVar2[2] + 4))(param_1);
    }
    if (piVar2[4] != 0) {
      (**(code **)(*(int *)piVar2[4] + 4))(param_1);
    }
    piVar2 = piVar2 + 1;
    iVar1 = iVar1 + -1;
  } while (iVar1 != 0);
  return;
}
```
