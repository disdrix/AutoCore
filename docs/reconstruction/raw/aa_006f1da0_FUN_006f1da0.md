# Raw capture: FUN_006f1da0

| Field | Value |
|---|---|
| **Stable ID** | `aa_006f1da0` |
| **Module** | `autoassault.exe` |
| **Image base** | `0x400000` |
| **VA** | `0x006f1da0` |
| **Canonical name** | `FUN_006f1da0` |
| **System** | unknown |
| **Capture timestamp** | `2026-07-23` |
| **Tool** | Ghidra MCP `batch_decompile` |
| **Integrity** | Do not overwrite this raw body; append versioned sections only |

---

## Raw pseudocode (authoritative decompile)

```c
void __thiscall FUN_006f1da0(int param_1,undefined1 *param_2,int param_3,int *param_4)

{
  if ((0x15 < *(int *)(param_3 + 8)) && (*param_4 <= *(int *)(param_1 + 0x14))) {
    *param_2 = 0;
    return;
  }
  *param_2 = 1;
  return;
}
```
