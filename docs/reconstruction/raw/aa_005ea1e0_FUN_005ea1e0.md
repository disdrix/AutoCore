# Raw capture: FUN_005ea1e0

| Field | Value |
|---|---|
| **Stable ID** | `aa_005ea1e0` |
| **Module** | `autoassault.exe` |
| **Image base** | `0x400000` |
| **VA** | `0x005ea1e0` |
| **Canonical name** | `FUN_005ea1e0` |
| **System** | unknown |
| **Capture timestamp** | `2026-07-23` |
| **Tool** | Ghidra MCP `batch_decompile` |
| **Integrity** | Do not overwrite this raw body; append versioned sections only |

---

## Raw pseudocode (authoritative decompile)

```c
undefined4 * __fastcall FUN_005ea1e0(undefined4 *param_1)

{
  undefined4 uVar1;
  void *local_c;
  undefined1 *puStack_8;
  undefined4 local_4;
  
  puStack_8 = &LAB_009a77ab;
  local_c = ExceptionList;
  ExceptionList = &local_c;
  param_1[0x15] = 0;
  param_1[0x16] = 0;
  param_1[0x17] = 0;
  uVar1 = DAT_00aaa884;
  local_4 = 0;
  param_1[7] = 0xffffffff;
  param_1[6] = 0;
  *(undefined1 *)(param_1 + 8) = 0;
  param_1[5] = 0xffffffff;
  *param_1 = uVar1;
  param_1[1] = 0;
  param_1[2] = uVar1;
  param_1[3] = 0;
  FUN_005743e0(0,0,0);
  ExceptionList = local_c;
  return param_1;
}
```
