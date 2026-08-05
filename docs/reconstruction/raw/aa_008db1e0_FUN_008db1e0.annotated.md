# Annotated low-level: FUN_008db1e0

| Field | Value |
|---|---|
| Stable ID | `aa_008db1e0` |
| VA | `0x008db1e0` |
| System | unknown |
| Date | 2026-07-23 |

## Machine-level notes

- Source: raw capture for `aa_008db1e0`.
- Prefer assembly when decompiler conflicts.
- Recover types for still-generic parameters via callers/xrefs.
- Map DAT_* globals and FUN_* callees in follow-up waves.

## Pseudocode (annotated copy of raw)

```c
void FUN_008db1e0(void)

{
  int unaff_ESI;
  char local_20 [32];
  
  if (*(char *)(unaff_ESI + 0x518) == '\0') {
    if (*(int *)(unaff_ESI + 0x5a4) != 0) {
      (**(code **)(**(int **)(unaff_ESI + 0x5a4) + 4))(0);
    }
  }
  else if (*(int *)(unaff_ESI + 0x5a4) != 0) {
    if (*(int *)(unaff_ESI + 0x544) != 0) {
      sprintf(local_20,"%d",*(int *)(unaff_ESI + 0x544) + 1);
      (**(code **)(**(int **)(unaff_ESI + 0x5a4) + 0x1d8))(local_20,1,1);
      (**(code **)(**(int **)(unaff_ESI + 0x5a4) + 0xcc))(1);
      (**(code **)(**(int **)(unaff_ESI + 0x5a4) + 0x34c))();
      return;
    }
    (**(code **)(**(int **)(unaff_ESI + 0x5a4) + 4))(0);
    return;
  }
  return;
}
```

## Open questions

- Confirm calling convention and full signature against callers.
- Recover meaningful types for still-generic parameters.
