# Annotated low-level: FUN_007fc0b0

| Field | Value |
|---|---|
| Stable ID | `aa_007fc0b0` |
| VA | `0x007fc0b0` |
| System | unknown |
| Date | 2026-07-23 |

## Machine-level notes

- Source: raw capture for `aa_007fc0b0`.
- Prefer assembly when decompiler conflicts.
- Recover types for still-generic parameters via callers/xrefs.
- Map DAT_* globals and FUN_* callees in follow-up waves.

## Pseudocode (annotated copy of raw)

```c
undefined1 * FUN_007fc0b0(void)

{
  char cVar1;
  int unaff_ESI;
  undefined1 *apuStack_c [3];
  
  if (*(int *)(unaff_ESI + 0xc78) != 0) {
    cVar1 = (**(code **)(**(int **)(unaff_ESI + 0xc78) + 8))();
    if (cVar1 != '\0') {
      (**(code **)(**(int **)(unaff_ESI + 0xc78) + 0x54))();
      if ((apuStack_c < apuStack_c[0]) && ((undefined1 *)0x1770 < apuStack_c[0])) {
        return apuStack_c[0];
      }
      return (undefined1 *)apuStack_c;
    }
  }
  return (undefined1 *)0x0;
}
```

## Open questions

- Confirm calling convention and full signature against callers.
- Recover meaningful types for still-generic parameters.
