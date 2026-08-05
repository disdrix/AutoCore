# Raw capture: FUN_007fb0a0

| Field | Value |
|---|---|
| **Stable ID** | `aa_007fb0a0` |
| **Module** | `autoassault.exe` |
| **Image base** | `0x400000` |
| **VA** | `0x007fb0a0` |
| **Canonical name** | `FUN_007fb0a0` |
| **System** | unknown |
| **Capture timestamp** | `2026-07-23` |
| **Tool** | Ghidra MCP `batch_decompile` |
| **Integrity** | Do not overwrite this raw body; append versioned sections only |

---

## Raw pseudocode (authoritative decompile)

```c
undefined4 * FUN_007fb0a0(undefined4 *param_1)

{
  void *local_c;
  undefined1 *puStack_8;
  undefined4 local_4;
  
  local_4 = 0xffffffff;
  puStack_8 = &LAB_009b32a0;
  local_c = ExceptionList;
  ExceptionList = &local_c;
  FUN_007b5dd0(param_1,0);
  *param_1 = &PTR_FUN_00a8467c;
  *(undefined1 *)((int)param_1 + 0x4e6) = 0xff;
  *(undefined1 *)((int)param_1 + 0x4e5) = 0xff;
  *(undefined1 *)(param_1 + 0x139) = 0xff;
  *(undefined1 *)((int)param_1 + 0x4e7) = 0xff;
  param_1[0x126] = 0;
  param_1[0x123] = 0;
  param_1[0x127] = 0;
  param_1[0x124] = 0;
  param_1[0x128] = 0;
  param_1[0x125] = 0;
  param_1[0x13d] = 0;
  param_1[0x145] = 0;
  param_1[0x129] = 0;
  param_1[0x12a] = 0;
  param_1[0x150] = 0;
  param_1[0x151] = 0;
  param_1[0x13e] = 0;
  param_1[0x146] = 0;
  param_1[299] = 0;
  param_1[300] = 0;
  param_1[0x152] = 0;
  param_1[0x153] = 0;
  param_1[0x13f] = 0;
  param_1[0x147] = 0;
  param_1[0x12d] = 0;
  param_1[0x12e] = 0;
  param_1[0x154] = 0;
  param_1[0x155] = 0;
  param_1[0x140] = 0;
  param_1[0x148] = 0;
  param_1[0x12f] = 0;
  param_1[0x130] = 0;
  param_1[0x156] = 0;
  param_1[0x157] = 0;
  param_1[0x141] = 0;
  param_1[0x149] = 0;
  param_1[0x131] = 0;
  param_1[0x132] = 0;
  param_1[0x158] = 0;
  param_1[0x159] = 0;
  param_1[0x142] = 0;
  param_1[0x14a] = 0;
  param_1[0x133] = 0;
  param_1[0x134] = 0;
  param_1[0x15a] = 0;
  param_1[0x15b] = 0;
  param_1[0x143] = 0;
  param_1[0x14b] = 0;
  param_1[0x135] = 0;
  param_1[0x136] = 0;
  param_1[0x15c] = 0;
  param_1[0x15d] = 0;
  param_1[0x144] = 0;
  param_1[0x14c] = 0;
  param_1[0x137] = 0;
  param_1[0x138] = 0;
  param_1[0x15e] = 0;
  param_1[0x15f] = 0;
  param_1[0x14d] = 0;
  param_1[0x14e] = 0;
  param_1[0x14f] = 0;
  param_1[0x160] = 0;
  param_1[0x161] = 0;
  param_1[0x162] = 0;
  param_1[0x163] = 0;
  param_1[0x13a] = 0;
  param_1[0x13b] = 0;
  param_1[0x13c] = DAT_00afa098;
  *(undefined1 *)(param_1 + 0x122) = 0;
  *(undefined1 *)((int)param_1 + 0x489) = 1;
  *(undefined1 *)((int)param_1 + 0x48a) = 0;
  ExceptionList = local_c;
  return param_1;
}
```
