# Raw capture: FUN_005d6da0

| Field | Value |
|---|---|
| **Stable ID** | `aa_005d6da0` |
| **Module** | `autoassault.exe` |
| **Image base** | `0x400000` |
| **VA** | `0x005d6da0` |
| **Canonical name** | `FUN_005d6da0` |
| **System** | unknown |
| **Capture timestamp** | `2026-07-23` |
| **Tool** | Ghidra MCP `batch_decompile` |
| **Integrity** | Do not overwrite this raw body; append versioned sections only |

---

## Raw pseudocode (authoritative decompile)

```c
undefined4 * __thiscall FUN_005d6da0(undefined4 *param_1,undefined4 param_2)

{
  FUN_005d1990(param_2);
  *param_1 = &PTR_FUN_009daf0c;
  return param_1;
}
```
