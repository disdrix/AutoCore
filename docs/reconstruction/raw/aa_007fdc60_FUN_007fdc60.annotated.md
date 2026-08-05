# Annotated low-level: FUN_007fdc60

| Field | Value |
|---|---|
| Stable ID | `aa_007fdc60` |
| VA | `0x007fdc60` |
| System | unknown |
| Date | 2026-07-23 |

## Machine-level notes

- Source: raw capture for `aa_007fdc60`.
- Prefer assembly when decompiler conflicts.
- Recover types for still-generic parameters via callers/xrefs.
- Map DAT_* globals and FUN_* callees in follow-up waves.

## Pseudocode (annotated copy of raw)

```c
void FUN_007fdc60(void)

{
  int *piVar1;
  int in_EAX;
  int *piVar2;
  
  piVar2 = (int *)**(int **)(in_EAX + 0x3c08);
  if (piVar2 != *(int **)(in_EAX + 0x3c08)) {
    do {
      FUN_007fca10();
      piVar1 = (int *)*piVar2;
      if (piVar2 != *(int **)(in_EAX + 0x3c08)) {
        *(int **)piVar2[1] = piVar1;
        *(int *)(*piVar2 + 4) = piVar2[1];
                    /* WARNING: Subroutine does not return */
        operator_delete(piVar2);
      }
      piVar2 = piVar1;
    } while (piVar1 != (int *)*(int *)(in_EAX + 0x3c08));
  }
  return;
}
```

## Open questions

- Confirm calling convention and full signature against callers.
- Recover meaningful types for still-generic parameters.
