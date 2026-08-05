# Raw capture: FUN_005deda0

| Field | Value |
|---|---|
| **Stable ID** | `aa_005deda0` |
| **Module** | `autoassault.exe` |
| **Image base** | `0x400000` |
| **VA** | `0x005deda0` |
| **Canonical name** | `FUN_005deda0` |
| **System** | unknown |
| **Capture timestamp** | `2026-07-23` |
| **Tool** | Ghidra MCP `batch_decompile` |
| **Integrity** | Do not overwrite this raw body; append versioned sections only |

---

## Raw pseudocode (authoritative decompile)

```c
undefined4 * __thiscall FUN_005deda0(undefined4 *param_1,byte param_2)

{
  FUN_00632030();
  FUN_00632030();
  *param_1 = &PTR_LAB_009cc290;
  if ((param_2 & 1) != 0) {
    (**(code **)(*DAT_00b05060 + 0x14))(param_1,*(undefined2 *)(param_1 + 1),0x13);
  }
  return param_1;
}
```
