# Raw capture: FUN_006ce6c0

| Field | Value |
|---|---|
| **Stable ID** | `aa_006ce6c0` |
| **Module** | `autoassault.exe` |
| **Image base** | `0x400000` |
| **VA** | `0x006ce6c0` |
| **Canonical name** | `FUN_006ce6c0` |
| **System** | unknown |
| **Capture timestamp** | `2026-07-23` |
| **Tool** | Ghidra MCP `batch_decompile` |
| **Integrity** | Do not overwrite this raw body; append versioned sections only |

---

## Raw pseudocode (authoritative decompile)

```c
void __fastcall FUN_006ce6c0(int param_1)

{
  if (-1 < (int)*(uint *)(param_1 + 0x28)) {
    (**(code **)(*DAT_00b05060 + 0x14))
              (*(undefined4 *)(param_1 + 0x20),*(uint *)(param_1 + 0x28) & 0x7fffffff,0x12);
  }
  if (-1 < *(int *)(param_1 + 0x1c)) {
    (**(code **)(*DAT_00b05060 + 0x14))
              (*(undefined4 *)(param_1 + 0x14),*(int *)(param_1 + 0x1c) << 4,0x12);
  }
  if (-1 < *(int *)(param_1 + 0x10)) {
    (**(code **)(*DAT_00b05060 + 0x14))
              (*(undefined4 *)(param_1 + 8),*(int *)(param_1 + 0x10) << 2,0x12);
  }
  return;
}
```
