# Annotated low-level: FUN_0055cdf0

| Field | Value |
|---|---|
| Stable ID | `aa_0055cdf0` |
| VA | `0x0055cdf0` |
| System | unknown |
| Date | 2026-07-23 |

## Machine-level notes

- Source: raw capture for `aa_0055cdf0`.
- Prefer assembly when decompiler conflicts.
- Recover types for still-generic parameters via callers/xrefs.
- Map DAT_* globals and FUN_* callees in follow-up waves.

## Pseudocode (annotated copy of raw)

```c
void __fastcall FUN_0055cdf0(undefined4 *param_1)

{
  void *pvVar1;
  
  if (*(char *)(param_1 + 8) != '\0') {
    (**(code **)(**(int **)(DAT_00d1f058 + 0x2c) + 0xc))(*(undefined4 *)(param_1[4] + 0xa0));
    (**(code **)(*(int *)param_1[4] + 0x10))();
    FUN_007567b0(0,0);
    *(undefined4 *)(param_1[4] + 0xc0) = 3;
    *(undefined1 *)(param_1 + 8) = 0;
  }
  FUN_00988860(param_1[4]);
  FUN_00988860(param_1[5]);
  FUN_00988860(param_1[6]);
  FUN_00988860(param_1[7]);
  FUN_00988860(param_1[4]);
  FUN_007567b0(0,0);
  FUN_007567b0(0,0);
  FUN_007567b0(0,0);
  FUN_007567b0(0,0);
  pvVar1 = (void *)*param_1;
  if (pvVar1 != (void *)0x0) {
    FUN_00988710();
                    /* WARNING: Subroutine does not return */
    operator_delete(pvVar1);
  }
  *param_1 = 0;
  pvVar1 = (void *)param_1[1];
  if (pvVar1 != (void *)0x0) {
    FUN_00988710();
                    /* WARNING: Subroutine does not return */
    operator_delete(pvVar1);
  }
  param_1[1] = 0;
  pvVar1 = (void *)param_1[2];
  if (pvVar1 != (void *)0x0) {
    FUN_00988710();
                    /* WARNING: Subroutine does not return */
    operator_delete(pvVar1);
  }
  param_1[2] = 0;
  pvVar1 = (void *)param_1[3];
  if (pvVar1 != (void *)0x0) {
    FUN_00988710();
                    /* WARNING: Subroutine does not return */
    operator_delete(pvVar1);
  }
  param_1[3] = 0;
  if ((undefined4 *)param_1[4] != (undefined4 *)0x0) {
    (*(code *)**(undefined4 **)param_1[4])(1);
  }
  param_1[4] = 0;
  if ((undefined4 *)param_1[5] != (undefined4 *)0x0) {
    (*(code *)**(undefined4 **)param_1[5])(1);
  }
  param_1[5] = 0;
  if ((undefined4 *)param_1[6] != (undefined4 *)0x0) {
    (*(code *)**(undefined4 **)param_1[6])(1);
  }
  param_1[6] = 0;
  if ((undefined4 *)param_1[7] != (undefined4 *)0x0) {
    (*(code *)**(undefined4 **)param_1[7])(1);
  }
  param_1[7] = 0;
  return;
}
```

## Open questions

- Confirm calling convention and full signature against callers.
- Recover meaningful types for still-generic parameters.
