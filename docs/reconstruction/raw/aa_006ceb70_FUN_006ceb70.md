# Raw capture: FUN_006ceb70

| Field | Value |
|---|---|
| **Stable ID** | `aa_006ceb70` |
| **Module** | `autoassault.exe` |
| **Image base** | `0x400000` |
| **VA** | `0x006ceb70` |
| **Canonical name** | `FUN_006ceb70` |
| **System** | unknown |
| **Capture timestamp** | `2026-07-23` |
| **Tool** | Ghidra MCP `batch_decompile` |
| **Integrity** | Do not overwrite this raw body; append versioned sections only |

---

## Raw pseudocode (authoritative decompile)

```c
void FUN_006ceb70(undefined4 *param_1)

{
  if (param_1 != (undefined4 *)0x0) {
    FUN_005edf20();
    *param_1 = 0;
    param_1[1] = 0;
    param_1[2] = 0x80000000;
  }
  return;
}
```
