# Annotated low-level: FUN_0044fdd0

| Field | Value |
|---|---|
| Stable ID | `aa_0044fdd0` |
| VA | `0x0044fdd0` |
| System | unknown |
| Date | 2026-07-23 |

## Machine-level notes

- Source: raw capture for `aa_0044fdd0`.
- Prefer assembly when decompiler conflicts.
- Recover types for still-generic parameters via callers/xrefs.
- Map DAT_* globals and FUN_* callees in follow-up waves.

## Pseudocode (annotated copy of raw)

```c
void FUN_0044fdd0(void)

{
  int *piVar1;
  int unaff_EDI;
  
  piVar1 = *(int **)(unaff_EDI + 0x10);
  if (piVar1 != *(int **)(unaff_EDI + 0x14)) {
    do {
      if ((undefined4 *)*piVar1 != (undefined4 *)0x0) {
        (*(code *)**(undefined4 **)*piVar1)(1);
      }
      piVar1 = piVar1 + 1;
    } while (piVar1 != *(int **)(unaff_EDI + 0x14));
  }
  FUN_0044fe70(0);
  return;
}
```

## Open questions

- Confirm calling convention and full signature against callers.
- Recover meaningful types for still-generic parameters.
