# Raw capture: CVOGTacArc_ctor

| Field | Value |
|---|---|
| **Stable ID** | `aa_00632af0` |
| **Module** | `autoassault.exe` |
| **Image base** | `0x400000` |
| **VA** | `0x00632af0` |
| **Canonical name** | `CVOGTacArc_ctor` |
| **System** | unknown |
| **Capture timestamp** | `2026-07-23` |
| **Tool** | Ghidra MCP `batch_decompile` |
| **Integrity** | Do not overwrite this raw body; append versioned sections only |

---

## Raw pseudocode (authoritative decompile)

```c
undefined4 * __fastcall CVOGTacArc_ctor(undefined4 *param_1)

{
  void *local_c;
  undefined1 *puStack_8;
  undefined4 local_4;
  
  local_4 = 0xffffffff;
  puStack_8 = &LAB_009a8be1;
  local_c = ExceptionList;
  ExceptionList = &local_c;
  *param_1 = &PTR_CVOGTacArc_vdtor_009e3538;
  *(undefined1 *)((int)param_1 + 0x32) = 0xff;
  *(undefined1 *)((int)param_1 + 0x31) = 0xff;
  *(undefined1 *)(param_1 + 0xc) = 0xff;
  *(undefined1 *)((int)param_1 + 0x33) = 0xff;
  *(undefined1 *)((int)param_1 + 0x36) = 0xff;
  *(undefined1 *)((int)param_1 + 0x35) = 0xff;
  *(undefined1 *)(param_1 + 0xd) = 0xff;
  *(undefined1 *)((int)param_1 + 0x37) = 0xff;
  *(undefined1 *)((int)param_1 + 0x3a) = 0xff;
  *(undefined1 *)((int)param_1 + 0x39) = 0xff;
  *(undefined1 *)(param_1 + 0xe) = 0xff;
  *(undefined1 *)((int)param_1 + 0x3b) = 0xff;
  *(undefined1 *)((int)param_1 + 0x3e) = 0xff;
  *(undefined1 *)((int)param_1 + 0x3d) = 0xff;
  *(undefined1 *)(param_1 + 0xf) = 0xff;
  *(undefined1 *)((int)param_1 + 0x3f) = 0xff;
  FUN_0096ef70();
  local_4 = 0;
  FUN_0096ef70();
  local_4 = CONCAT31(local_4._1_3_,1);
  FUN_0096f530();
  param_1[2] = g_flOverheatCoolFrac;
  param_1[6] = 0;
  param_1[7] = 0;
  param_1[8] = 0;
  param_1[0xb] = 0;
  *(undefined1 *)(param_1 + 1) = 0;
  param_1[10] = 0x32;
  param_1[3] = 0;
  param_1[4] = 0;
  param_1[5] = 0;
  *(undefined1 *)(param_1 + 0xc) = 0xff;
  *(undefined1 *)((int)param_1 + 0x32) = 0;
  *(undefined1 *)((int)param_1 + 0x33) = 0x66;
  *(undefined1 *)((int)param_1 + 0x31) = 0x33;
  *(undefined1 *)(param_1 + 0xd) = 0x33;
  *(undefined1 *)((int)param_1 + 0x36) = 0xd;
  *(undefined1 *)((int)param_1 + 0x35) = 0;
  *(undefined1 *)((int)param_1 + 0x37) = 0x5a;
  *(undefined1 *)((int)param_1 + 0x3a) = 0x66;
  *(undefined1 *)((int)param_1 + 0x39) = 0x66;
  *(undefined1 *)(param_1 + 0xe) = 0x66;
  *(undefined1 *)((int)param_1 + 0x3b) = 0x66;
  *(undefined1 *)((int)param_1 + 0x3f) = 0x66;
  *(undefined1 *)((int)param_1 + 0x3e) = 0xcc;
  *(undefined1 *)((int)param_1 + 0x3d) = 0;
  *(undefined1 *)(param_1 + 0xf) = 0;
  param_1[0x14] = 0;
  *(undefined1 *)(param_1 + 0x10) = 0;
  param_1[0x11] = 0;
  param_1[0x12] = 0;
  param_1[0x13] = 0;
  ExceptionList = local_c;
  return param_1;
}
```
