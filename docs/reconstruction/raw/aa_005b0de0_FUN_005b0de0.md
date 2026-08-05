# Raw capture: FUN_005b0de0

| Field | Value |
|---|---|
| **Stable ID** | `aa_005b0de0` |
| **Module** | `autoassault.exe` |
| **Image base** | `0x400000` |
| **VA** | `0x005b0de0` |
| **Canonical name** | `FUN_005b0de0` |
| **System** | unknown |
| **Capture timestamp** | `2026-07-23` |
| **Tool** | Ghidra MCP `batch_decompile` |
| **Integrity** | Do not overwrite this raw body; append versioned sections only |

---

## Raw pseudocode (authoritative decompile)

```c
void __thiscall FUN_005b0de0(int param_1,char param_2)

{
  if (*(int *)(param_1 + 0x50) != 0) {
    if ((*(int *)(*(int *)(*(int *)(param_1 + 0x50) + 0xa8) + 0x38) == 3) && (param_2 != '\0')) {
      (**(code **)(**(int **)(param_1 + 0x50) + 700))(1);
    }
    else {
      (**(code **)(**(int **)(param_1 + 0x50) + 700))(0);
    }
  }
  if (*(int *)(param_1 + 0x34) != 0) {
    FUN_005a0470(param_1 + 0x40);
  }
  return;
}
```
