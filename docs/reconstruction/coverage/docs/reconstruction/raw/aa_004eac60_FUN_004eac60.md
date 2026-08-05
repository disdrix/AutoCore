# Raw capture: FUN_004eac60

| Field | Value |
|---|---|
| **Stable ID** | `aa_004eac60` |
| **Module** | `autoassault.exe` |
| **Image base** | `0x400000` |
| **VA** | `0x004eac60` |
| **Canonical name** | `FUN_004eac60` |
| **System** | unknown |
| **Capture timestamp** | `2026-07-23` |
| **Tool** | Ghidra MCP `batch_decompile` |
| **Integrity** | Do not overwrite this raw body; append versioned sections only |

---

## Raw pseudocode (authoritative decompile)

```c
undefined4 __thiscall FUN_004eac60(undefined4 param_1,byte param_2)

{
  FUN_004e82f0();
  if ((param_2 & 1) != 0) {
    (**(code **)(*DAT_00b05060 + 0x14))(param_1,8,0x1a);
  }
  return param_1;
}
```
