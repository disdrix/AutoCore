# Annotated low-level: FUN_005dfe70

| Field | Value |
|---|---|
| Stable ID | `aa_005dfe70` |
| VA | `0x005dfe70` |
| System | unknown |
| Date | 2026-07-23 |

## Machine-level notes

- Source: raw capture for `aa_005dfe70`.
- Prefer assembly when decompiler conflicts.
- Recover types for still-generic parameters via callers/xrefs.
- Map DAT_* globals and FUN_* callees in follow-up waves.

## Pseudocode (annotated copy of raw)

```c
void __fastcall FUN_005dfe70(undefined4 *param_1)

{
  *param_1 = &PTR_FUN_009dbbfc;
  if ((void *)param_1[0x65] != (void *)0x0) {
                    /* WARNING: Subroutine does not return */
    operator_delete((void *)param_1[0x65]);
  }
  param_1[0x65] = 0;
  param_1[0x66] = 0;
  param_1[0x67] = 0;
  FUN_00518ec0();
  return;
}
```

## Open questions

- Confirm calling convention and full signature against callers.
- Recover meaningful types for still-generic parameters.
