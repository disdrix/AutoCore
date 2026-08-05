# Annotated low-level: FUN_004bff90

| Field | Value |
|---|---|
| Stable ID | `aa_004bff90` |
| VA | `0x004bff90` |
| System | unknown |
| Date | 2026-07-23 |

## Machine-level notes

- Source: raw capture for `aa_004bff90`.
- Prefer assembly when decompiler conflicts.
- Recover types for still-generic parameters via callers/xrefs.
- Map DAT_* globals and FUN_* callees in follow-up waves.

## Pseudocode (annotated copy of raw)

```c
undefined4
FUN_004bff90(void *param_1,undefined4 param_2,undefined4 param_3,undefined4 param_4,
            undefined4 param_5,undefined4 param_6)

{
  int iVar1;
  undefined4 uVar2;
  void *local_c;
  undefined1 *puStack_8;
  undefined4 local_4;
  
  iVar1 = (int)param_1;
  local_4 = 0xffffffff;
  puStack_8 = &LAB_009a1962;
  local_c = ExceptionList;
  uVar2 = 0;
  if ((param_1 == (void *)0x0) || (*(char *)((int)param_1 + 0xf) != '\0')) {
    return 0;
  }
  ExceptionList = &local_c;
  param_1 = operator_new(0x80);
  local_4 = 0;
  if (param_1 != (void *)0x0) {
    uVar2 = FUN_005c6b40(iVar1,param_2,param_3,param_4,param_5,param_6);
  }
  local_4 = 0xffffffff;
  param_1 = (void *)uVar2;
  iVar1 = FUN_004bfb60(iVar1);
  if (DAT_00af0ae0 < *(uint *)(iVar1 + 8)) {
    FUN_004c0530(&param_1);
    ExceptionList = local_c;
    return uVar2;
  }
  FUN_004c0570(&param_1);
  ExceptionList = local_c;
  return uVar2;
}
```

## Open questions

- Confirm calling convention and full signature against callers.
- Recover meaningful types for still-generic parameters.
