# Raw capture: FUN_0054cac0

| Field | Value |
|---|---|
| **Stable ID** | `aa_0054cac0` |
| **Module** | `autoassault.exe` |
| **Image base** | `0x400000` |
| **VA** | `0x0054cac0` |
| **Canonical name** | `FUN_0054cac0` |
| **System** | unknown |
| **Capture timestamp** | `2026-07-23` |
| **Tool** | Ghidra MCP `batch_decompile` |
| **Integrity** | Do not overwrite this raw body; append versioned sections only |

---

## Raw pseudocode (authoritative decompile)

```c
void FUN_0054cac0(int param_1,undefined4 param_2,undefined4 param_3)

{
  if (*(float *)(param_1 + 0xe0) != g_flZero) {
    FUN_005781b0(param_3,param_2,"conversion_percent] (item converts to %% sell value)\n",1);
  }
  FUN_00578190(param_1,param_2,param_3);
  return;
}
```
