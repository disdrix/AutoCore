# Raw capture: VehicleAction_ctor

| Field | Value |
|---|---|
| **Stable ID** | `aa_00597f90` |
| **Module** | `autoassault.exe` |
| **Image base** | `0x400000` |
| **VA** | `0x00597f90` |
| **Canonical name** | `VehicleAction_ctor` |
| **System** | unknown |
| **Capture timestamp** | `2026-07-23` |
| **Tool** | Ghidra MCP `batch_decompile` |
| **Integrity** | Do not overwrite this raw body; append versioned sections only |

---

## Raw pseudocode (authoritative decompile)

```c
undefined4 * __thiscall
VehicleAction_ctor(undefined4 *param_1,undefined4 param_2,undefined4 param_3,undefined4 param_4,
                  int param_5)

{
  undefined4 uVar1;
  undefined4 uVar2;
  void *local_c;
  undefined1 *puStack_8;
  undefined4 local_4;
  
  local_4 = 0xffffffff;
  puStack_8 = &LAB_009a5acd;
  local_c = ExceptionList;
  ExceptionList = &local_c;
  FUN_00636370(param_3);
  uVar2 = DAT_009d54e0;
  uVar1 = DAT_009c7bc0;
  local_4 = 0;
  *(undefined1 *)(param_1 + 7) = 0;
  *(undefined1 *)(param_1 + 0xb) = 0;
  param_1[0xf] = 0;
  param_1[8] = uVar2;
  *param_1 = &PTR_FUN_009d54c4;
  param_1[2] = &PTR_LAB_009d54b0;
  param_1[9] = 0;
  param_1[10] = 0;
  param_1[0xc] = uVar1;
  param_1[0xd] = 0;
  param_1[0xe] = param_5;
  param_1[0x10] = param_4;
  param_1[0x11] = param_2;
  if (param_5 == 1) {
    FUN_00597ec0();
  }
  ExceptionList = local_c;
  return param_1;
}
```
