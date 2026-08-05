# Raw capture: FUN_005ebec0

| Field | Value |
|---|---|
| **Stable ID** | `aa_005ebec0` |
| **Module** | `autoassault.exe` |
| **Image base** | `0x400000` |
| **VA** | `0x005ebec0` |
| **Canonical name** | `FUN_005ebec0` |
| **System** | unknown |
| **Capture timestamp** | `2026-07-23` |
| **Tool** | Ghidra MCP `batch_decompile` |
| **Integrity** | Do not overwrite this raw body; append versioned sections only |

---

## Raw pseudocode (authoritative decompile)

```c
undefined4 * __thiscall FUN_005ebec0(undefined4 *param_1,undefined4 param_2)

{
  FUN_005eb210(param_2);
  *param_1 = &PTR_FUN_009dce90;
  param_1[0x30] = 0;
  param_1[0x31] = 0;
  param_1[0x32] = 0x80000000;
  return param_1;
}
```
