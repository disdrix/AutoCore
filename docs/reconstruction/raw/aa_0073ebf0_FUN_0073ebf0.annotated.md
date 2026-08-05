# Annotated low-level: FUN_0073ebf0

| Field | Value |
|---|---|
| Stable ID | `aa_0073ebf0` |
| VA | `0x0073ebf0` |
| System | unknown |
| Date | 2026-07-23 |

## Machine-level notes

- Source: raw capture for `aa_0073ebf0`.
- Prefer assembly when decompiler conflicts.
- Recover types for still-generic parameters via callers/xrefs.
- Map DAT_* globals and FUN_* callees in follow-up waves.

## Pseudocode (annotated copy of raw)

```c
void FUN_0073ebf0(void)

{
  int *piVar1;
  int unaff_ESI;
  
  operator_delete__(*(void **)(unaff_ESI + 0xc));
  *(undefined4 *)(unaff_ESI + 0xc) = 0;
  operator_delete__(*(void **)(unaff_ESI + 0x10));
  piVar1 = *(int **)(unaff_ESI + 8);
  *(undefined4 *)(unaff_ESI + 0x10) = 0;
  if (piVar1 != (int *)0x0) {
    if (piVar1[-1] != 0) {
      (**(code **)(*piVar1 + 0x10))(3);
      *(undefined4 *)(unaff_ESI + 8) = 0;
      *(undefined4 *)(unaff_ESI + 0x14) = 0;
      return;
    }
    operator_delete__(piVar1 + -1);
  }
  *(undefined4 *)(unaff_ESI + 8) = 0;
  *(undefined4 *)(unaff_ESI + 0x14) = 0;
  return;
}
```

## Open questions

- Confirm calling convention and full signature against callers.
- Recover meaningful types for still-generic parameters.
