# Raw capture: FUN_005bf1e0

| Field | Value |
|---|---|
| **Stable ID** | `aa_005bf1e0` |
| **Module** | `autoassault.exe` |
| **Image base** | `0x400000` |
| **VA** | `0x005bf1e0` |
| **Canonical name** | `FUN_005bf1e0` |
| **System** | unknown |
| **Capture timestamp** | `2026-07-23` |
| **Tool** | Ghidra MCP `batch_decompile` |
| **Integrity** | Do not overwrite this raw body; append versioned sections only |

---

## Raw pseudocode (authoritative decompile)

```c
undefined4 * __fastcall FUN_005bf1e0(undefined4 *param_1)

{
  FUN_00748960();
  *(undefined1 *)(param_1 + 0x31) = 0;
  param_1[0x32] = 0;
  *(undefined1 *)(param_1 + 0x35) = 0;
  *(undefined2 *)((int)param_1 + 0xea) = 0;
  param_1[0x38] = 0;
  param_1[0x39] = 0;
  param_1[0x36] = 0;
  param_1[0x37] = 0;
  *(undefined1 *)(param_1 + 0x3a) = 0;
  *param_1 = &PTR_LAB_009d9cbc;
  param_1[1] = &PTR_LAB_009d9cac;
  param_1[0x33] = 0xffffffff;
  param_1[0x34] = 0xffffffff;
  *(undefined2 *)(param_1 + 0x3b) = 0xffff;
  return param_1;
}
```
