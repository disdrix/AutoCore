# Raw capture: FUN_006cec30

| Field | Value |
|---|---|
| **Stable ID** | `aa_006cec30` |
| **Module** | `autoassault.exe` |
| **Image base** | `0x400000` |
| **VA** | `0x006cec30` |
| **Canonical name** | `FUN_006cec30` |
| **System** | unknown |
| **Capture timestamp** | `2026-07-23` |
| **Tool** | Ghidra MCP `batch_decompile` |
| **Integrity** | Do not overwrite this raw body; append versioned sections only |

---

## Raw pseudocode (authoritative decompile)

```c
void FUN_006cec30(undefined4 *param_1)

{
  if (param_1 != (undefined4 *)0x0) {
    FUN_005edf20();
    *param_1 = 0;
    FUN_006380a0(param_1 + 1,&DAT_00a0e190,0x80);
  }
  return;
}
```
