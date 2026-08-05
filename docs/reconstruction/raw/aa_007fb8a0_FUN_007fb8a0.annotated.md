# Annotated low-level: FUN_007fb8a0

| Field | Value |
|---|---|
| Stable ID | `aa_007fb8a0` |
| VA | `0x007fb8a0` |
| System | unknown |
| Date | 2026-07-23 |

## Machine-level notes

- Source: raw capture for `aa_007fb8a0`.
- Prefer assembly when decompiler conflicts.
- Recover types for still-generic parameters via callers/xrefs.
- Map DAT_* globals and FUN_* callees in follow-up waves.

## Pseudocode (annotated copy of raw)

```c
void FUN_007fb8a0(void)

{
  char cVar1;
  int unaff_ESI;
  
  if (*(int *)(unaff_ESI + 0x1164) != 0) {
    cVar1 = (**(code **)(**(int **)(unaff_ESI + 0x1164) + 0x3d8))();
    if (cVar1 != '\0') {
      (**(code **)(**(int **)(unaff_ESI + 0x1164) + 0x440))();
      if (*(int *)(unaff_ESI + 0xf38) != 0) {
        (**(code **)(**(int **)(unaff_ESI + 0xf38) + 0xb0))(*(undefined4 *)(unaff_ESI + 0x1164));
      }
    }
  }
  return;
}
```

## Open questions

- Confirm calling convention and full signature against callers.
- Recover meaningful types for still-generic parameters.
