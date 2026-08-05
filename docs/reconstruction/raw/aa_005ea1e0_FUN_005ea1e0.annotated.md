# Annotated low-level: FUN_005ea1e0

| Field | Value |
|---|---|
| Stable ID | `aa_005ea1e0` |
| VA | `0x005ea1e0` |
| System | unknown |
| Date | 2026-07-23 |

## Machine-level notes

- Source: raw capture for `aa_005ea1e0`.
- Prefer assembly when decompiler conflicts.
- Recover types for still-generic parameters via callers/xrefs.
- Map DAT_* globals and FUN_* callees in follow-up waves.

## Pseudocode (annotated copy of raw)

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

## Open questions

- Confirm calling convention and full signature against callers.
- Recover meaningful types for still-generic parameters.
