# Raw capture: FUN_008db2d0

| Field | Value |
|---|---|
| **Stable ID** | `aa_008db2d0` |
| **Module** | `autoassault.exe` |
| **Image base** | `0x400000` |
| **VA** | `0x008db2d0` |
| **Canonical name** | `FUN_008db2d0` |
| **System** | unknown |
| **Capture timestamp** | `2026-07-23` |
| **Tool** | Ghidra MCP `batch_decompile` |
| **Integrity** | Do not overwrite this raw body; append versioned sections only |

---

## Raw pseudocode (authoritative decompile)

```c
void FUN_008db2d0(undefined4 param_1)

{
  int unaff_ESI;
  
  if (*(int *)(unaff_ESI + 0x578) != 0) {
    (**(code **)(**(int **)(unaff_ESI + 0x578) + 4))(param_1);
  }
  if (*(int *)(unaff_ESI + 0x574) != 0) {
    (**(code **)(**(int **)(unaff_ESI + 0x574) + 4))(param_1);
  }
  if (*(int *)(unaff_ESI + 0x504) != 0) {
    (**(code **)(**(int **)(unaff_ESI + 0x504) + 4))(param_1);
  }
  if (*(int *)(unaff_ESI + 0x57c) != 0) {
    (**(code **)(**(int **)(unaff_ESI + 0x57c) + 4))(param_1);
  }
  if (*(int *)(unaff_ESI + 0x580) != 0) {
    (**(code **)(**(int **)(unaff_ESI + 0x580) + 4))(param_1);
  }
  if (*(int *)(unaff_ESI + 0x598) != 0) {
    (**(code **)(**(int **)(unaff_ESI + 0x598) + 4))(param_1);
  }
  if (*(int *)(unaff_ESI + 0x59c) != 0) {
    (**(code **)(**(int **)(unaff_ESI + 0x59c) + 4))(param_1);
  }
  return;
}
```
