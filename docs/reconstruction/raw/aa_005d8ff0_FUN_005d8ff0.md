# Raw capture: FUN_005d8ff0

| Field | Value |
|---|---|
| **Stable ID** | `aa_005d8ff0` |
| **Module** | `autoassault.exe` |
| **Image base** | `0x400000` |
| **VA** | `0x005d8ff0` |
| **Canonical name** | `FUN_005d8ff0` |
| **System** | unknown |
| **Capture timestamp** | `2026-07-23` |
| **Tool** | Ghidra MCP `batch_decompile` |
| **Integrity** | Do not overwrite this raw body; append versioned sections only |

---

## Raw pseudocode (authoritative decompile)

```c
undefined4 __thiscall FUN_005d8ff0(undefined4 param_1,byte param_2)

{
  FUN_005d8e30();
  if ((param_2 & 1) != 0) {
    (**(code **)(*DAT_00b05060 + 0x14))(param_1,0x68,0xc);
  }
  return param_1;
}
```
