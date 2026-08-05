# Raw capture: FUN_0067aca0

| Field | Value |
|---|---|
| **Stable ID** | `aa_0067aca0` |
| **Module** | `autoassault.exe` |
| **Image base** | `0x400000` |
| **VA** | `0x0067aca0` |
| **Canonical name** | `FUN_0067aca0` |
| **System** | unknown |
| **Capture timestamp** | `2026-07-23` |
| **Tool** | Ghidra MCP `batch_decompile` |
| **Integrity** | Do not overwrite this raw body; append versioned sections only |

---

## Raw pseudocode (authoritative decompile)

```c
void FUN_0067aca0(int param_1,int param_2,int param_3,int param_4,int param_5,int param_6,
                 int param_7,int param_8,undefined4 param_9)

{
  if ((param_2 != 0) && (3 < *(uint *)(param_1 + 0xc))) {
    FUN_00680c80(param_2,4);
  }
  if ((param_3 != 0) && (*(int *)(param_1 + 0xc) != 0)) {
    FUN_00680c80(param_3,1);
  }
  if ((param_4 != 0) && (*(int *)(param_1 + 0xc) != 0)) {
    FUN_00680c80(param_4,1);
  }
  if ((param_5 != 0) && (*(int *)(param_1 + 0xc) != 0)) {
    FUN_00680c80(param_5,1);
  }
  if ((param_6 != 0) && (*(int *)(param_1 + 0xc) != 0)) {
    FUN_00680c80(param_6,1);
  }
  if ((param_7 != 0) && (*(int *)(param_1 + 0xc) != 0)) {
    FUN_00680c80(param_7,1);
  }
  if ((param_8 != 0) && (*(int *)(param_1 + 0xc) != 0)) {
    FUN_00680c80(param_8,1);
  }
  FUN_006811a0(param_9);
  return;
}
```
