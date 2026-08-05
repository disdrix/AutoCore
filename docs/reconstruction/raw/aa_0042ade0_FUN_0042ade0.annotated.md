# Annotated low-level: FUN_0042ade0

| Field | Value |
|---|---|
| Stable ID | `aa_0042ade0` |
| VA | `0x0042ade0` |
| System | unknown |
| Date | 2026-07-23 |

## Machine-level notes

- Source: raw capture for `aa_0042ade0`.
- Prefer assembly when decompiler conflicts.
- Recover types for still-generic parameters via callers/xrefs.
- Map DAT_* globals and FUN_* callees in follow-up waves.

## Pseudocode (annotated copy of raw)

```c
undefined4 * __thiscall FUN_0042ade0(undefined4 *param_1,byte param_2)

{
  *param_1 = &PTR_FUN_00a9b1d0;
  if (param_1[1] != 0) {
    *(undefined4 *)(param_1[1] + 8) = param_1[2];
  }
  if (param_1[2] == 0) {
    DAT_00d17998 = param_1[1];
  }
  else {
    *(undefined4 *)(param_1[2] + 4) = param_1[1];
  }
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
