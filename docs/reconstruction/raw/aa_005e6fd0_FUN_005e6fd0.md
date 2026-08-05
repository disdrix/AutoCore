# Raw capture: FUN_005e6fd0

| Field | Value |
|---|---|
| **Stable ID** | `aa_005e6fd0` |
| **Module** | `autoassault.exe` |
| **Image base** | `0x400000` |
| **VA** | `0x005e6fd0` |
| **Canonical name** | `FUN_005e6fd0` |
| **System** | unknown |
| **Capture timestamp** | `2026-07-23` |
| **Tool** | Ghidra MCP `batch_decompile` |
| **Integrity** | Do not overwrite this raw body; append versioned sections only |

---

## Raw pseudocode (authoritative decompile)

```c
void __thiscall FUN_005e6fd0(int param_1,int *param_2,undefined4 param_3,int param_4)

{
  int *piVar1;
  int iVar2;
  
  if ((**(int **)(param_1 + 0x14) == 0) && ((*(int **)(param_1 + 0x14))[1] == 0)) {
    iVar2 = (**(code **)(*param_2 + 0x1c))();
    if (iVar2 != 0) {
      iVar2 = (**(code **)(*param_2 + 0x1c))();
      if (*(int *)(*(int *)(iVar2 + 0x14) + 4) != 0) {
        **(undefined4 **)(param_1 + 0x14) = param_2;
        return;
      }
    }
  }
  iVar2 = *(int *)(param_1 + 0x14);
  piVar1 = (int *)(iVar2 + (param_4 - 1U & 1) * 4);
  if (*(int *)(iVar2 + param_4 * 4) == 0) {
    if (param_2 != (int *)*piVar1) {
      *(int **)(iVar2 + param_4 * 4) = param_2;
      return;
    }
  }
  else if ((*piVar1 == 0) && (param_2 != *(int **)(iVar2 + param_4 * 4))) {
    *piVar1 = (int)param_2;
  }
  return;
}
```
