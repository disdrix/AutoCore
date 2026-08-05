# Raw capture: FUN_0097ffa0

| Field | Value |
|---|---|
| **Stable ID** | `aa_0097ffa0` |
| **Module** | `autoassault.exe` |
| **Image base** | `0x400000` |
| **VA** | `0x0097ffa0` |
| **Canonical name** | `FUN_0097ffa0` |
| **System** | unknown |
| **Capture timestamp** | `2026-07-23` |
| **Tool** | Ghidra MCP `batch_decompile` |
| **Integrity** | Do not overwrite this raw body; append versioned sections only |

---

## Raw pseudocode (authoritative decompile)

```c
undefined4 * FUN_0097ffa0(undefined4 *param_1)

{
  void *local_c;
  undefined1 *puStack_8;
  undefined4 local_4;
  
  local_4 = 0xffffffff;
  puStack_8 = &LAB_009b4ab6;
  local_c = ExceptionList;
  ExceptionList = &local_c;
  FUN_00863f10(param_1);
  *param_1 = &PTR_FUN_00a61e44;
  *(undefined1 *)((int)param_1 + 0x4a9) = 0;
  param_1[299] = 0;
  param_1[0x12d] = 0;
  param_1[0x12e] = 0;
  param_1[0x12f] = 0;
  *(undefined1 *)(param_1 + 0x12a) = 1;
  *(undefined1 *)((int)param_1 + 0x4aa) = 1;
  *(undefined1 *)((int)param_1 + 0x4ab) = 1;
  param_1[300] = 1;
  param_1[0x130] = 0;
  param_1[0x131] = 0;
  param_1[0x136] = 0;
  param_1[0x137] = 0;
  param_1[0x132] = 0;
  param_1[0x133] = 0;
  param_1[0x138] = 0;
  param_1[0x139] = 0;
  param_1[0x134] = 0;
  param_1[0x135] = 0;
  param_1[0x13a] = 0;
  param_1[0x13b] = 0;
  param_1[0x13c] = 0;
  param_1[0x13d] = 0;
  ExceptionList = local_c;
  return param_1;
}
```
