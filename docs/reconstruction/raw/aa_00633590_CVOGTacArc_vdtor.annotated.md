# Annotated low-level: CVOGTacArc_vdtor

| Field | Value |
|---|---|
| Stable ID | `aa_00633590` |
| VA | `0x00633590` |
| System | unknown |
| Date | 2026-07-23 |

## Machine-level notes

- Source: raw capture for `aa_00633590`.
- Prefer assembly when decompiler conflicts.
- Recover types for still-generic parameters via callers/xrefs.
- Map DAT_* globals and FUN_* callees in follow-up waves.

## Pseudocode (annotated copy of raw)

```c
void * __thiscall CVOGTacArc_vdtor(void *param_1,byte param_2)

{
  CVOGTacArc_dtor_helper();
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
