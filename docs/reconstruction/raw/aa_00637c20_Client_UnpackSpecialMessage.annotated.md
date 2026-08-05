# Annotated low-level: Client_UnpackSpecialMessage

| Field | Value |
|---|---|
| Stable ID | `aa_00637c20` |
| VA | `0x00637c20` |
| System | unknown |
| Date | 2026-07-23 |

## Machine-level notes

- Source: raw capture for `aa_00637c20`.
- Prefer assembly when decompiler conflicts.
- Recover types for still-generic parameters via callers/xrefs.
- Map DAT_* globals and FUN_* callees in follow-up waves.

## Pseudocode (annotated copy of raw)

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

## Open questions

- Confirm calling convention and full signature against callers.
- Recover meaningful types for still-generic parameters.
