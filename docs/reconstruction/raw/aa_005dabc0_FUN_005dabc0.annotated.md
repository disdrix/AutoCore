# Annotated low-level: FUN_005dabc0

| Field | Value |
|---|---|
| Stable ID | `aa_005dabc0` |
| VA | `0x005dabc0` |
| System | unknown |
| Date | 2026-07-23 |

## Machine-level notes

- Source: raw capture for `aa_005dabc0`.
- Prefer assembly when decompiler conflicts.
- Recover types for still-generic parameters via callers/xrefs.
- Map DAT_* globals and FUN_* callees in follow-up waves.

## Pseudocode (annotated copy of raw)

```c
undefined4 * __thiscall FUN_005dabc0(undefined4 *param_1,void *param_2,undefined4 param_3)

{
  CVOGHBBase_ctor(param_1);
  *param_1 = &PTR_FUN_009db56c;
  CVOGHBBase_SetPeriodAndCounter(param_1,-1000,true);
  param_1[2] = param_3;
  CVOGHBBase_AttachOwnerObject(param_1,param_2);
  return param_1;
}
```

## Open questions

- Confirm calling convention and full signature against callers.
- Recover meaningful types for still-generic parameters.
