# Raw capture: FUN_0078bdc0

| Field | Value |
|---|---|
| **Stable ID** | `aa_0078bdc0` |
| **Module** | `autoassault.exe` |
| **Image base** | `0x400000` |
| **VA** | `0x0078bdc0` |
| **Canonical name** | `FUN_0078bdc0` |
| **System** | unknown |
| **Capture timestamp** | `2026-07-23` |
| **Tool** | Ghidra MCP `batch_decompile` |
| **Integrity** | Do not overwrite this raw body; append versioned sections only |

---

## Raw pseudocode (authoritative decompile)

```c
void __thiscall FUN_0078bdc0(int *param_1,undefined4 param_2)

{
  (**(code **)(*param_1 + 8))(param_2);
  (**(code **)(*param_1 + 0x3b0))();
  return;
}
```
