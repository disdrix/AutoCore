# Raw capture: FUN_0065acb0

| Field | Value |
|---|---|
| **Stable ID** | `aa_0065acb0` |
| **Module** | `autoassault.exe` |
| **Image base** | `0x400000` |
| **VA** | `0x0065acb0` |
| **Canonical name** | `FUN_0065acb0` |
| **System** | unknown |
| **Capture timestamp** | `2026-07-23` |
| **Tool** | Ghidra MCP `batch_decompile` |
| **Integrity** | Do not overwrite this raw body; append versioned sections only |

---

## Raw pseudocode (authoritative decompile)

```c
undefined4 __thiscall FUN_0065acb0(int *param_1,int param_2)

{
  return *(undefined4 *)(*param_1 + 4 + (param_1[2] + param_2) * 4);
}
```
