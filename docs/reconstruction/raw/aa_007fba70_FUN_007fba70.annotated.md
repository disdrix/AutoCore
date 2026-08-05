# Annotated low-level: FUN_007fba70

| Field | Value |
|---|---|
| Stable ID | `aa_007fba70` |
| VA | `0x007fba70` |
| System | unknown |
| Date | 2026-07-23 |

## Machine-level notes

- Source: raw capture for `aa_007fba70`.
- Prefer assembly when decompiler conflicts.
- Recover types for still-generic parameters via callers/xrefs.
- Map DAT_* globals and FUN_* callees in follow-up waves.

## Pseudocode (annotated copy of raw)

```c
undefined4 FUN_007fba70(void)

{
  char cVar1;
  int unaff_ESI;
  
  if (*(int *)(unaff_ESI + 0x30a0) != 0) {
    cVar1 = (**(code **)(**(int **)(unaff_ESI + 0x30a0) + 0x3d8))();
    if (cVar1 != '\0') {
      cVar1 = (**(code **)(**(int **)(unaff_ESI + 0x30a0) + 0xd0))();
      if (cVar1 != '\0') {
        return 1;
      }
    }
  }
  return 0;
}
```

## Open questions

- Confirm calling convention and full signature against callers.
- Recover meaningful types for still-generic parameters.
