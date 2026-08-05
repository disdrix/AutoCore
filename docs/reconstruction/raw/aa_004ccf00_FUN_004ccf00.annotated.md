# Annotated low-level: FUN_004ccf00

| Field | Value |
|---|---|
| Stable ID | `aa_004ccf00` |
| VA | `0x004ccf00` |
| System | unknown |
| Date | 2026-07-23 |

## Machine-level notes

- Source: raw capture for `aa_004ccf00`.
- Prefer assembly when decompiler conflicts.
- Recover types for still-generic parameters via callers/xrefs.
- Map DAT_* globals and FUN_* callees in follow-up waves.

## Pseudocode (annotated copy of raw)

```c
int __thiscall FUN_004ccf00(int param_1,uint param_2)

{
  if ((*(int *)(param_1 + 4) != 0) &&
     (param_2 < (uint)(*(int *)(param_1 + 8) - *(int *)(param_1 + 4) >> 2))) {
    return *(int *)(param_1 + 4) + param_2 * 4;
  }
                    /* WARNING: Subroutine does not return */
  FUN_004ccf30();
}
```

## Open questions

- Confirm calling convention and full signature against callers.
- Recover meaningful types for still-generic parameters.
