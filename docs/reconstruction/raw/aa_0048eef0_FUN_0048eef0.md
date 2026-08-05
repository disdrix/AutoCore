# Raw capture: FUN_0048eef0

| Field | Value |
|---|---|
| **Stable ID** | `aa_0048eef0` |
| **Module** | `autoassault.exe` |
| **Image base** | `0x400000` |
| **VA** | `0x0048eef0` |
| **Canonical name** | `FUN_0048eef0` |
| **System** | unknown |
| **Capture timestamp** | `2026-07-23` |
| **Tool** | Ghidra MCP `batch_decompile` |
| **Integrity** | Do not overwrite this raw body; append versioned sections only |

---

## Raw pseudocode (authoritative decompile)

```c
void __thiscall FUN_0048eef0(int param_1,undefined4 param_2)

{
  if (*(int *)(param_1 + 0xb8) == 0) {
    DAT_00b04820 = (undefined1)param_2;
    return;
  }
  if (*(int *)(*(int *)(param_1 + 0xb8) + 0xe89c) != 0) {
    FUN_0079db80(param_2);
    DAT_00b04820 = (undefined1)param_2;
    return;
  }
  DAT_00b04820 = (undefined1)param_2;
  return;
}
```
