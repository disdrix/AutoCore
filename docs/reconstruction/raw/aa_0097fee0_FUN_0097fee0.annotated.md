# Annotated low-level: FUN_0097fee0

| Field | Value |
|---|---|
| Stable ID | `aa_0097fee0` |
| VA | `0x0097fee0` |
| System | unknown |
| Date | 2026-07-23 |

## Machine-level notes

- Source: raw capture for `aa_0097fee0`.
- Prefer assembly when decompiler conflicts.
- Recover types for still-generic parameters via callers/xrefs.
- Map DAT_* globals and FUN_* callees in follow-up waves.

## Pseudocode (annotated copy of raw)

```c
void __fastcall FUN_0097fee0(undefined4 *param_1)

{
  void *pvVar1;
  void *local_c;
  undefined1 *puStack_8;
  undefined4 local_4;
  
  puStack_8 = &LAB_009b4aa4;
  local_c = ExceptionList;
  ExceptionList = &local_c;
  *param_1 = &PTR_FUN_00a61e44;
  local_4 = 0;
  pvVar1 = (void *)param_1[0x12d];
  if (pvVar1 != (void *)0x0) {
    FUN_0096efd0();
                    /* WARNING: Subroutine does not return */
    operator_delete(pvVar1);
  }
  pvVar1 = (void *)param_1[0x12e];
  param_1[0x12d] = 0;
  if (pvVar1 != (void *)0x0) {
    FUN_0096efd0();
                    /* WARNING: Subroutine does not return */
    operator_delete(pvVar1);
  }
  pvVar1 = (void *)param_1[0x12f];
  param_1[0x12e] = 0;
  if (pvVar1 != (void *)0x0) {
    FUN_0096efd0();
                    /* WARNING: Subroutine does not return */
    operator_delete(pvVar1);
  }
  param_1[0x12f] = 0;
  *param_1 = &PTR_FUN_00a61a1c;
  local_4 = 0xffffffff;
  FUN_007b5be0();
  ExceptionList = local_c;
  return;
}
```

## Open questions

- Confirm calling convention and full signature against callers.
- Recover meaningful types for still-generic parameters.
