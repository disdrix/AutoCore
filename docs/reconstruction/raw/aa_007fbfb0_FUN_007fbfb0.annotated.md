# Annotated low-level: FUN_007fbfb0

| Field | Value |
|---|---|
| Stable ID | `aa_007fbfb0` |
| VA | `0x007fbfb0` |
| System | unknown |
| Date | 2026-07-23 |

## Machine-level notes

- Source: raw capture for `aa_007fbfb0`.
- Prefer assembly when decompiler conflicts.
- Recover types for still-generic parameters via callers/xrefs.
- Map DAT_* globals and FUN_* callees in follow-up waves.

## Pseudocode (annotated copy of raw)

```c
void FUN_007fbfb0(int param_1)

{
  int *piVar1;
  int *piVar2;
  int unaff_ESI;
  
  piVar1 = (int *)**(int **)(unaff_ESI + 0x3c08);
  if (piVar1 != *(int **)(unaff_ESI + 0x3c08)) {
    do {
      if (piVar1[2] == param_1) {
        piVar2 = (int *)*piVar1;
        if (piVar1 != *(int **)(unaff_ESI + 0x3c08)) {
          *(int **)piVar1[1] = piVar2;
          *(int *)(*piVar1 + 4) = piVar1[1];
                    /* WARNING: Subroutine does not return */
          operator_delete(piVar1);
        }
      }
      else {
        piVar2 = (int *)*piVar1;
      }
      piVar1 = piVar2;
    } while (piVar2 != *(int **)(unaff_ESI + 0x3c08));
  }
  return;
}
```

## Open questions

- Confirm calling convention and full signature against callers.
- Recover meaningful types for still-generic parameters.
