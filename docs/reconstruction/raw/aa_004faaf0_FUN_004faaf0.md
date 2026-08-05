# Raw capture: FUN_004faaf0

| Field | Value |
|---|---|
| **Stable ID** | `aa_004faaf0` |
| **Module** | `autoassault.exe` |
| **Image base** | `0x400000` |
| **VA** | `0x004faaf0` |
| **Canonical name** | `FUN_004faaf0` |
| **System** | unknown |
| **Capture timestamp** | `2026-07-23` |
| **Tool** | Ghidra MCP `batch_decompile` |
| **Integrity** | Do not overwrite this raw body; append versioned sections only |

---

## Raw pseudocode (authoritative decompile)

```c
void __thiscall FUN_004faaf0(int param_1,undefined4 param_2)

{
  *(undefined4 *)(param_1 + 0x1a8) = param_2;
  if (DAT_00b042b8 < 1) {
    FUN_00519a30();
  }
  if (*(int *)(param_1 + 0x1a8) < 0) {
    *(undefined4 *)(param_1 + 0x1a8) = 0;
    return;
  }
  if (DAT_00b042b8 <= *(int *)(param_1 + 0x1a8)) {
    *(int *)(param_1 + 0x1a8) = DAT_00b042b8;
  }
  return;
}
```
