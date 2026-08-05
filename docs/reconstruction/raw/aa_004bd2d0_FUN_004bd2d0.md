# Raw capture: FUN_004bd2d0

| Field | Value |
|---|---|
| **Stable ID** | `aa_004bd2d0` |
| **Module** | `autoassault.exe` |
| **Image base** | `0x400000` |
| **VA** | `0x004bd2d0` |
| **Canonical name** | `FUN_004bd2d0` |
| **System** | unknown |
| **Capture timestamp** | `2026-07-23` |
| **Tool** | Ghidra MCP `batch_decompile` |
| **Integrity** | Do not overwrite this raw body; append versioned sections only |

---

## Raw pseudocode (authoritative decompile)

```c
undefined4 * __thiscall FUN_004bd2d0(undefined4 *param_1,undefined4 param_2,int param_3)

{
  FUN_00764030();
  param_1[0x53] = param_2;
  param_1[0x54] = param_3;
  *param_1 = &PTR_FUN_009cb4d4;
  param_1[0x55] = 0;
  *(int *)(param_3 + 0x2c) = *(int *)(param_3 + 0x2c) + 1;
  return param_1;
}
```
