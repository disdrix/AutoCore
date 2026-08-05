# Raw capture: FUN_004f2cc0

| Field | Value |
|---|---|
| **Stable ID** | `aa_004f2cc0` |
| **Module** | `autoassault.exe` |
| **Image base** | `0x400000` |
| **VA** | `0x004f2cc0` |
| **Canonical name** | `FUN_004f2cc0` |
| **System** | unknown |
| **Capture timestamp** | `2026-07-23` |
| **Tool** | Ghidra MCP `batch_decompile` |
| **Integrity** | Do not overwrite this raw body; append versioned sections only |

---

## Raw pseudocode (authoritative decompile)

```c
void __thiscall FUN_004f2cc0(int *param_1,undefined4 param_2)

{
  (**(code **)(*param_1 + 0x14))(param_2,0x50);
  return;
}
```
