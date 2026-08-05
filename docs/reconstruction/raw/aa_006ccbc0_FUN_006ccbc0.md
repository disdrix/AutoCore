# Raw capture: FUN_006ccbc0

| Field | Value |
|---|---|
| **Stable ID** | `aa_006ccbc0` |
| **Module** | `autoassault.exe` |
| **Image base** | `0x400000` |
| **VA** | `0x006ccbc0` |
| **Canonical name** | `FUN_006ccbc0` |
| **System** | unknown |
| **Capture timestamp** | `2026-07-23` |
| **Tool** | Ghidra MCP `batch_decompile` |
| **Integrity** | Do not overwrite this raw body; append versioned sections only |

---

## Raw pseudocode (authoritative decompile)

```c
int __thiscall FUN_006ccbc0(int param_1,byte param_2)

{
  thunk_FUN_005ee650();
  if ((param_2 & 1) != 0) {
    (**(code **)(*DAT_00b05060 + 0x14))(param_1,*(undefined2 *)(param_1 + 4),0x22);
  }
  return param_1;
}
```
