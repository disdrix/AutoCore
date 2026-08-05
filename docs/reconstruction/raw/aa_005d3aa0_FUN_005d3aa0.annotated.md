# Annotated low-level: FUN_005d3aa0

| Field | Value |
|---|---|
| Stable ID | `aa_005d3aa0` |
| VA | `0x005d3aa0` |
| System | unknown |
| Date | 2026-07-23 |

## Machine-level notes

- Source: raw capture for `aa_005d3aa0`.
- Prefer assembly when decompiler conflicts.
- Recover types for still-generic parameters via callers/xrefs.
- Map DAT_* globals and FUN_* callees in follow-up waves.

## Pseudocode (annotated copy of raw)

```c
void * __thiscall FUN_005d3aa0(void *param_1,byte param_2)

{
  FUN_005d3a80();
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
