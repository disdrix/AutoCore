# Annotated low-level: FUN_005e1ef0

| Field | Value |
|---|---|
| Stable ID | `aa_005e1ef0` |
| VA | `0x005e1ef0` |
| System | unknown |
| Date | 2026-07-23 |

## Machine-level notes

- Source: raw capture for `aa_005e1ef0`.
- Prefer assembly when decompiler conflicts.
- Recover types for still-generic parameters via callers/xrefs.
- Map DAT_* globals and FUN_* callees in follow-up waves.

## Pseudocode (annotated copy of raw)

```c
undefined4 * __thiscall FUN_005e1ef0(undefined4 *param_1,byte param_2)

{
  *param_1 = &PTR_FUN_009dc844;
  if ((void *)param_1[4] != (void *)0x0) {
    operator_delete__((void *)param_1[4]);
  }
  param_1[4] = 0;
  if ((param_2 & 1) != 0) {
                    /* WARNING: Subroutine does not return */
    operator_delete(param_1);
  }
  return param_1;
}
```

## Open questions

- Confirm calling convention and full signature against callers.
- Recover meaningful types for still-generic parameters.
