# Annotated low-level: FUN_005ffbd0

| Field | Value |
|---|---|
| Stable ID | `aa_005ffbd0` |
| VA | `0x005ffbd0` |
| System | unknown |
| Date | 2026-07-23 |

## Machine-level notes

- Source: raw capture for `aa_005ffbd0`.
- Prefer assembly when decompiler conflicts.
- Recover types for still-generic parameters via callers/xrefs.
- Map DAT_* globals and FUN_* callees in follow-up waves.

## Pseudocode (annotated copy of raw)

```c
/* TimedAction_CreateTokenFlagAction — enter-world action with period DAT_00af0c6c (300000).
   Sets character token/flag via FUN_005ffc20 / mask 0x100. NOT combat pools. */

undefined4 * __thiscall
TimedAction_CreateTokenFlagAction(undefined4 *param_1,int param_2,undefined4 param_3)

{
  CVOGHBBase_ctor(param_1);
  *param_1 = &PTR_FUN_009dde2c;
  CVOGHBBase_SetPeriodAndCounter(param_1,1,true);
  param_1[2] = param_3;
  if (param_2 == 0) {
    CVOGHBBase_AttachOwnerObject(param_1,(void *)0x0);
    return param_1;
  }
  CVOGHBBase_AttachOwnerObject(param_1,(void *)(*(int *)(*(int *)(param_2 + 4) + 4) + 4 + param_2));
  return param_1;
}
```

## Open questions

- Confirm calling convention and full signature against callers.
- Recover meaningful types for still-generic parameters.
