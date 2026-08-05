# Annotated low-level: FUN_007fe2c0

| Field | Value |
|---|---|
| Stable ID | `aa_007fe2c0` |
| VA | `0x007fe2c0` |
| System | unknown |
| Date | 2026-07-23 |

## Machine-level notes

- Source: raw capture for `aa_007fe2c0`.
- Prefer assembly when decompiler conflicts.
- Recover types for still-generic parameters via callers/xrefs.
- Map DAT_* globals and FUN_* callees in follow-up waves.

## Pseudocode (annotated copy of raw)

```c
void FUN_007fe2c0(void)

{
  int *piVar1;
  int unaff_EDI;
  
  piVar1 = (int *)**(int **)(unaff_EDI + 0x3124);
  if (piVar1 != *(int **)(unaff_EDI + 0x3124)) {
    do {
      if ((void *)piVar1[2] != (void *)0x0) {
                    /* WARNING: Subroutine does not return */
        operator_delete((void *)piVar1[2]);
      }
      piVar1[2] = 0;
      piVar1 = (int *)*piVar1;
    } while (piVar1 != (int *)*(int *)(unaff_EDI + 0x3124));
  }
  FUN_004133c0(0);
  return;
}
```

## Open questions

- Confirm calling convention and full signature against callers.
- Recover meaningful types for still-generic parameters.
