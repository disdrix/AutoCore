# Raw capture: FUN_0049bfb0

| Field | Value |
|---|---|
| **Stable ID** | `aa_0049bfb0` |
| **Module** | `autoassault.exe` |
| **Image base** | `0x400000` |
| **VA** | `0x0049bfb0` |
| **Canonical name** | `FUN_0049bfb0` |
| **System** | unknown |
| **Capture timestamp** | `2026-07-23` |
| **Tool** | Ghidra MCP `batch_decompile` |
| **Integrity** | Do not overwrite this raw body; append versioned sections only |

---

## Raw pseudocode (authoritative decompile)

```c
void FUN_0049bfb0(undefined4 *param_1,int *param_2,int *param_3,int *param_4,int *param_5)

{
  int *piVar1;
  
  if (param_2 == param_3) {
    *param_1 = param_4;
    return;
  }
  do {
    piVar1 = param_4;
    if (*param_2 != *param_5) {
      piVar1 = param_4 + 1;
      *param_4 = *param_2;
    }
    param_2 = param_2 + 1;
    param_4 = piVar1;
  } while (param_2 != param_3);
  *param_1 = piVar1;
  return;
}
```
