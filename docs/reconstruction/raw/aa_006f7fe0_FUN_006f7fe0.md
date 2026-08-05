# Raw capture: FUN_006f7fe0

| Field | Value |
|---|---|
| **Stable ID** | `aa_006f7fe0` |
| **Module** | `autoassault.exe` |
| **Image base** | `0x400000` |
| **VA** | `0x006f7fe0` |
| **Canonical name** | `FUN_006f7fe0` |
| **System** | unknown |
| **Capture timestamp** | `2026-07-23` |
| **Tool** | Ghidra MCP `batch_decompile` |
| **Integrity** | Do not overwrite this raw body; append versioned sections only |

---

## Raw pseudocode (authoritative decompile)

```c
void FUN_006f7fe0(float *param_1,float *param_2,undefined4 *param_3)

{
  if (((*param_1 <= *param_2) && (param_1[1] <= *param_2)) && (param_1[2] <= *param_2)) {
    *param_3 = 0;
    return;
  }
  *param_3 = 1;
  return;
}
```
