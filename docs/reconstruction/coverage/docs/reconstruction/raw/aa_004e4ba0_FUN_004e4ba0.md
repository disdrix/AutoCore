# Raw capture: FUN_004e4ba0

| Field | Value |
|---|---|
| **Stable ID** | `aa_004e4ba0` |
| **Module** | `autoassault.exe` |
| **Image base** | `0x400000` |
| **VA** | `0x004e4ba0` |
| **Canonical name** | `FUN_004e4ba0` |
| **System** | unknown |
| **Capture timestamp** | `2026-07-23` |
| **Tool** | Ghidra MCP `batch_decompile` |
| **Integrity** | Do not overwrite this raw body; append versioned sections only |

---

## Raw pseudocode (authoritative decompile)

```c
int __thiscall FUN_004e4ba0(undefined4 param_1,int param_2,int param_3,undefined4 param_4)

{
  FUN_004e2eb0(param_2,param_3,param_4,param_1,param_4);
  return param_3 * 0x40 + param_2;
}
```
