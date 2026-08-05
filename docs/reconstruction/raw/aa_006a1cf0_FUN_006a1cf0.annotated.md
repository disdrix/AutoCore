# Annotated low-level: FUN_006a1cf0

| Field | Value |
|---|---|
| Stable ID | `aa_006a1cf0` |
| VA | `0x006a1cf0` |
| System | unknown |
| Date | 2026-07-23 |

## Machine-level notes

- Source: raw capture for `aa_006a1cf0`.
- Prefer assembly when decompiler conflicts.
- Recover types for still-generic parameters via callers/xrefs.
- Map DAT_* globals and FUN_* callees in follow-up waves.

## Pseudocode (annotated copy of raw)

```c
undefined4 * __fastcall FUN_006a1cf0(undefined4 *param_1)

{
  void *pvVar1;
  undefined4 uVar2;
  void *local_c;
  undefined1 *puStack_8;
  undefined4 local_4;
  
  local_4 = 0xffffffff;
  puStack_8 = &LAB_009ab292;
  local_c = ExceptionList;
  ExceptionList = &local_c;
  *param_1 = 6;
  param_1[1] = 3;
  param_1[2] = 0x3e99999a;
  param_1[3] = 0x3f800000;
  param_1[4] = 0x3e99999a;
  param_1[5] = 0x3f800000;
  param_1[6] = 0x3f800000;
  *(undefined1 *)(param_1 + 7) = 1;
  *(undefined1 *)((int)param_1 + 0x1d) = 0;
  *(undefined1 *)((int)param_1 + 0x1e) = 0;
  param_1[8] = 0;
  param_1[9] = 0x3f800000;
  param_1[10] = 0;
  param_1[0xb] = 0x3f800000;
  param_1[0xc] = 0x41f00000;
  param_1[0xd] = 0x41200000;
  param_1[0xe] = 0x3f800000;
  param_1[0xf] = 0x3f000000;
  param_1[0x10] = 0x3e800000;
  param_1[0x11] = 0x3e99999a;
  param_1[0x12] = 0x3dcccccd;
  param_1[0x13] = 0x3f800000;
  param_1[0x14] = 0;
  param_1[0x15] = 0;
  param_1[0x16] = 0;
  param_1[0x17] = 0;
  param_1[0x18] = 0;
  param_1[0x19] = 0;
  param_1[0x1a] = 0;
  param_1[0x1b] = 0;
  param_1[0x1c] = 0;
  pvVar1 = operator_new(0x5c);
  local_4 = 0;
  if (pvVar1 == (void *)0x0) {
    uVar2 = 0;
  }
  else {
    uVar2 = FUN_006a1090();
  }
  local_4 = 0xffffffff;
  param_1[0x16] = uVar2;
  pvVar1 = operator_new(0x5c);
  local_4 = 1;
  if (pvVar1 == (void *)0x0) {
    uVar2 = 0;
  }
  else {
    uVar2 = FUN_006a1090();
  }
  local_4 = 0xffffffff;
  param_1[0x15] = uVar2;
  pvVar1 = operator_new(0x5c);
  local_4 = 2;
  if (pvVar1 == (void *)0x0) {
    uVar2 = 0;
  }
  else {
    uVar2 = FUN_006a1090();
  }
  local_4 = 0xffffffff;
  param_1[0x19] = uVar2;
  pvVar1 = operator_new(0x5c);
  local_4 = 3;
  if (pvVar1 == (void *)0x0) {
    uVar2 = 0;
  }
  else {
    uVar2 = FUN_006a1090();
  }
  local_4 = 0xffffffff;
  param_1[0x1b] = uVar2;
  pvVar1 = operator_new(0x5c);
  local_4 = 4;
  if (pvVar1 == (void *)0x0) {
    uVar2 = 0;
  }
  else {
    uVar2 = FUN_006a1090();
  }
  local_4 = 0xffffffff;
  param_1[0x1a] = uVar2;
  pvVar1 = operator_new(0x5c);
  local_4 = 5;
  if (pvVar1 != (void *)0x0) {
    uVar2 = FUN_006a1090();
    param_1[0x18] = uVar2;
    ExceptionList = local_c;
    return param_1;
  }
  param_1[0x18] = 0;
  ExceptionList = local_c;
  return param_1;
}
```

## Open questions

- Confirm calling convention and full signature against callers.
- Recover meaningful types for still-generic parameters.
