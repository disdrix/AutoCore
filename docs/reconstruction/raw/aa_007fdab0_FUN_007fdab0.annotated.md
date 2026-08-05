# Annotated low-level: FUN_007fdab0

| Field | Value |
|---|---|
| Stable ID | `aa_007fdab0` |
| VA | `0x007fdab0` |
| System | unknown |
| Date | 2026-07-23 |

## Machine-level notes

- Source: raw capture for `aa_007fdab0`.
- Prefer assembly when decompiler conflicts.
- Recover types for still-generic parameters via callers/xrefs.
- Map DAT_* globals and FUN_* callees in follow-up waves.

## Pseudocode (annotated copy of raw)

```c
void FUN_007fdab0(int param_1)

{
  void *pvVar1;
  int *piVar2;
  int *piVar3;
  int unaff_EDI;
  
  piVar2 = (int *)**(int **)(unaff_EDI + 0x3124);
  if (piVar2 != *(int **)(unaff_EDI + 0x3124)) {
    do {
      pvVar1 = (void *)piVar2[2];
      if (*(int *)((int)pvVar1 + 0x20) == param_1) {
        if (pvVar1 != (void *)0x0) {
                    /* WARNING: Subroutine does not return */
          operator_delete(pvVar1);
        }
        piVar2[2] = 0;
        piVar3 = (int *)*piVar2;
        if (piVar2 != *(int **)(unaff_EDI + 0x3124)) {
          *(int **)piVar2[1] = piVar3;
          *(int *)(*piVar2 + 4) = piVar2[1];
                    /* WARNING: Subroutine does not return */
          operator_delete(piVar2);
        }
      }
      else {
        piVar3 = (int *)*piVar2;
      }
      piVar2 = piVar3;
    } while (piVar3 != *(int **)(unaff_EDI + 0x3124));
  }
  return;
}
```

## Open questions

- Confirm calling convention and full signature against callers.
- Recover meaningful types for still-generic parameters.
