# Raw capture: FUN_004cd7d0

| Field | Value |
|---|---|
| **Stable ID** | `aa_004cd7d0` |
| **Module** | `autoassault.exe` |
| **Image base** | `0x400000` |
| **VA** | `0x004cd7d0` |
| **Canonical name** | `FUN_004cd7d0` |
| **System** | unknown |
| **Capture timestamp** | `2026-07-23` |
| **Tool** | Ghidra MCP `batch_decompile` |
| **Integrity** | Do not overwrite this raw body; append versioned sections only |

---

## Raw pseudocode (authoritative decompile)

```c
void __thiscall FUN_004cd7d0(int param_1,undefined4 param_2)

{
  *(undefined4 *)(param_1 + 0xe4e8) = param_2;
  if (*(int *)(param_1 + 0xe894) != 0) {
    *(undefined4 *)(*(int *)(param_1 + 0xe894) + 0xbc) = param_2;
  }
  return;
}
```
