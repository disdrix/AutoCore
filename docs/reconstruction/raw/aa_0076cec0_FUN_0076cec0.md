# Raw capture: FUN_0076cec0

| Field | Value |
|---|---|
| **Stable ID** | `aa_0076cec0` |
| **Module** | `autoassault.exe` |
| **Image base** | `0x400000` |
| **VA** | `0x0076cec0` |
| **Canonical name** | `FUN_0076cec0` |
| **System** | unknown |
| **Capture timestamp** | `2026-07-23` |
| **Tool** | Ghidra MCP `batch_decompile` |
| **Integrity** | Do not overwrite this raw body; append versioned sections only |

---

## Raw pseudocode (authoritative decompile)

```c
undefined * FUN_0076cec0(undefined4 param_1,char *param_2)

{
  _vsnprintf(&DAT_00d19530,0x1000,param_2,&stack0x0000000c);
  return &DAT_00d19530;
}
```
