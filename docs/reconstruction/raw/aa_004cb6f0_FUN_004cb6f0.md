# Raw capture: FUN_004cb6f0

| Field | Value |
|---|---|
| **Stable ID** | `aa_004cb6f0` |
| **Module** | `autoassault.exe` |
| **Image base** | `0x400000` |
| **VA** | `0x004cb6f0` |
| **Canonical name** | `FUN_004cb6f0` |
| **System** | unknown |
| **Capture timestamp** | `2026-07-23` |
| **Tool** | Ghidra MCP `batch_decompile` |
| **Integrity** | Do not overwrite this raw body; append versioned sections only |

---

## Raw pseudocode (authoritative decompile)

```c
void FUN_004cb6f0(undefined4 *param_1,int *param_2,int *param_3,int *param_4)

{
  if (param_2 == param_3) {
    *param_1 = param_2;
    return;
  }
  do {
    if (((*param_2 == *param_4) && (param_2[1] == param_4[1])) &&
       ((char)param_2[2] == (char)param_4[2])) break;
    param_2 = param_2 + 4;
  } while (param_2 != param_3);
  *param_1 = param_2;
  return;
}
```
