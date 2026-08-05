# Raw capture: FUN_005ebf70

| Field | Value |
|---|---|
| **Stable ID** | `aa_005ebf70` |
| **Module** | `autoassault.exe` |
| **Image base** | `0x400000` |
| **VA** | `0x005ebf70` |
| **Canonical name** | `FUN_005ebf70` |
| **System** | unknown |
| **Capture timestamp** | `2026-07-23` |
| **Tool** | Ghidra MCP `batch_decompile` |
| **Integrity** | Do not overwrite this raw body; append versioned sections only |

---

## Raw pseudocode (authoritative decompile)

```c
int __thiscall FUN_005ebf70(int param_1,byte param_2)

{
  FUN_005ebf00();
  if ((param_2 & 1) != 0) {
    (**(code **)(*DAT_00b05060 + 0x14))(param_1,*(undefined2 *)(param_1 + 4),0x2c);
  }
  return param_1;
}
```
