# Raw capture: FUN_005adb20

| Field | Value |
|---|---|
| **Stable ID** | `aa_005adb20` |
| **Module** | `autoassault.exe` |
| **Image base** | `0x400000` |
| **VA** | `0x005adb20` |
| **Canonical name** | `FUN_005adb20` |
| **System** | unknown |
| **Capture timestamp** | `2026-07-23` |
| **Tool** | Ghidra MCP `batch_decompile` |
| **Integrity** | Do not overwrite this raw body; append versioned sections only |

---

## Raw pseudocode (authoritative decompile)

```c
undefined4 * __thiscall FUN_005adb20(undefined4 *param_1,undefined4 param_2)

{
  undefined4 uVar1;
  int iVar2;
  void *local_c;
  undefined1 *puStack_8;
  undefined4 local_4;
  
  local_4 = 0xffffffff;
  puStack_8 = &LAB_009a6650;
  local_c = ExceptionList;
  ExceptionList = &local_c;
  FUN_00637da0(param_2);
  *param_1 = &PTR_FUN_009d92ac;
  param_1[5] = 0;
  param_1[6] = 0;
  param_1[7] = 0;
  param_1[9] = 0;
  param_1[10] = 0;
  param_1[0xb] = 0;
  param_1[0xd] = 0;
  param_1[0xe] = 0;
  param_1[0xf] = 0;
  param_1[0x13] = 0;
  param_1[0x14] = 0;
  param_1[0x15] = 0;
  local_4._0_1_ = 4;
  local_4._1_3_ = 0;
  iVar2 = FUN_005ae270();
  param_1[0x1d] = iVar2;
  *(undefined1 *)(iVar2 + 0x21) = 1;
  *(undefined4 *)(param_1[0x1d] + 4) = param_1[0x1d];
  *(undefined4 *)param_1[0x1d] = param_1[0x1d];
  *(undefined4 *)(param_1[0x1d] + 8) = param_1[0x1d];
  param_1[0x1e] = 0;
  local_4._0_1_ = 5;
  iVar2 = FUN_005ae270();
  param_1[0x20] = iVar2;
  *(undefined1 *)(iVar2 + 0x21) = 1;
  *(undefined4 *)(param_1[0x20] + 4) = param_1[0x20];
  *(undefined4 *)param_1[0x20] = param_1[0x20];
  *(undefined4 *)(param_1[0x20] + 8) = param_1[0x20];
  param_1[0x21] = 0;
  local_4 = CONCAT31(local_4._1_3_,6);
  iVar2 = FUN_005ae2b0();
  uVar1 = DAT_00a110d8;
  param_1[0x23] = iVar2;
  *(undefined1 *)(iVar2 + 0x19) = 1;
  *(undefined4 *)(param_1[0x23] + 4) = param_1[0x23];
  *(undefined4 *)param_1[0x23] = param_1[0x23];
  *(undefined4 *)(param_1[0x23] + 8) = param_1[0x23];
  param_1[0x24] = 0;
  param_1[3] = 0xe;
  param_1[0x11] = 0xffffffff;
  param_1[0x16] = 0;
  param_1[0x17] = uVar1;
  *(undefined1 *)((int)param_1 + 0x6d) = 0;
  *(undefined1 *)(param_1 + 0x1b) = 0;
  *(undefined1 *)(param_1 + 0x19) = 0;
  param_1[0x18] = uVar1;
  param_1[0x25] = 0xffffffff;
  param_1[0x26] = 0;
  param_1[0x28] = 0;
  ExceptionList = local_c;
  return param_1;
}
```
