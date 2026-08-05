# Raw capture: FUN_004c2ef0

| Field | Value |
|---|---|
| **Stable ID** | `aa_004c2ef0` |
| **Module** | `autoassault.exe` |
| **Image base** | `0x400000` |
| **VA** | `0x004c2ef0` |
| **Canonical name** | `FUN_004c2ef0` |
| **System** | unknown |
| **Capture timestamp** | `2026-07-23` |
| **Tool** | Ghidra MCP `batch_decompile` |
| **Integrity** | Do not overwrite this raw body; append versioned sections only |

---

## Raw pseudocode (authoritative decompile)

```c
void __thiscall FUN_004c2ef0(int param_1,undefined2 param_2)

{
  *(undefined2 *)(param_1 + 0x13e) = param_2;
  return;
}
```
