# Raw capture: Client_UnpackSpecialMessage

| Field | Value |
|---|---|
| **Stable ID** | `aa_00637c20` |
| **Module** | `autoassault.exe` |
| **Image base** | `0x400000` |
| **VA** | `0x00637c20` |
| **Canonical name** | `Client_UnpackSpecialMessage` |
| **System** | unknown |
| **Capture timestamp** | `2026-07-23` |
| **Tool** | Ghidra MCP `batch_decompile` |
| **Integrity** | Do not overwrite this raw body; append versioned sections only |

---

## Raw pseudocode (authoritative decompile)

```c
undefined4 * Client_UnpackSpecialMessage(undefined4 *param_1,uint param_2,int *param_3)

{
  int *piVar1;
  void *local_c;
  undefined1 *puStack_8;
  uint local_4;
  
  puStack_8 = &LAB_009a8e13;
  local_c = ExceptionList;
  local_4 = 1;
  if (param_2 < 0x206d) {
    if (param_2 == 0x206c) {
      ExceptionList = &local_c;
      if (param_3 != (int *)0x0) {
        ExceptionList = &local_c;
        param_3[2] = param_3[2] + 1;
      }
      FUN_006374f0(param_1);
    }
    else {
      if (param_2 == 0x2005) {
        ExceptionList = &local_c;
        if (param_3 != (int *)0x0) {
          ExceptionList = &local_c;
          param_3[2] = param_3[2] + 1;
        }
        FUN_00637990(param_1);
        local_4 = local_4 & 0xffffff00;
        if (param_3 == (int *)0x0) {
          ExceptionList = local_c;
          return param_1;
        }
        piVar1 = param_3 + 2;
        *piVar1 = *piVar1 + -1;
        if (*piVar1 != 0) {
          ExceptionList = local_c;
          return param_1;
        }
        (**(code **)(*param_3 + 8))();
        ExceptionList = local_c;
        return param_1;
      }
      if (param_2 != 0x2023) goto LAB_00637d12;
      ExceptionList = &local_c;
      if (param_3 != (int *)0x0) {
        ExceptionList = &local_c;
        param_3[2] = param_3[2] + 1;
      }
      EMSG_Sector_Damage_Unpack(param_1);
    }
  }
  else {
    if (param_2 != 0x804d) {
LAB_00637d12:
      ExceptionList = &local_c;
      *param_1 = param_3;
      if (param_3 != (int *)0x0) {
        param_3[2] = param_3[2] + 1;
      }
      local_4 = 0;
      if (param_3 != (int *)0x0) {
        piVar1 = param_3 + 2;
        *piVar1 = *piVar1 + -1;
        if (*piVar1 == 0) {
          (**(code **)(*param_3 + 8))();
        }
      }
      ExceptionList = local_c;
      return param_1;
    }
    ExceptionList = &local_c;
    if (param_3 != (int *)0x0) {
      ExceptionList = &local_c;
      param_3[2] = param_3[2] + 1;
    }
    TNL_ByteBuffer_UnpackData(param_1);
  }
  local_4 = local_4 & 0xffffff00;
  if (param_3 != (int *)0x0) {
    piVar1 = param_3 + 2;
    *piVar1 = *piVar1 + -1;
    if (*piVar1 == 0) {
      (**(code **)(*param_3 + 8))();
    }
  }
  ExceptionList = local_c;
  return param_1;
}
```
