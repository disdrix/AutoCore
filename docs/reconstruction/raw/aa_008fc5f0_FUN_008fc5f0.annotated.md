# Annotated low-level: FUN_008fc5f0

| Field | Value |
|---|---|
| Stable ID | `aa_008fc5f0` |
| VA | `0x008fc5f0` |
| System | unknown |
| Date | 2026-07-23 |

## Machine-level notes

- Source: raw capture for `aa_008fc5f0`.
- Prefer assembly when decompiler conflicts.
- Recover types for still-generic parameters via callers/xrefs.
- Map DAT_* globals and FUN_* callees in follow-up waves.

## Pseudocode (annotated copy of raw)

```c
void FUN_008fc5f0(char param_1)

{
  char cVar1;
  int unaff_ESI;
  
  if (*(int *)(unaff_ESI + 0x730) != 0) {
    cVar1 = (**(code **)(**(int **)(unaff_ESI + 0x730) + 0xd0))();
    if (param_1 == '\0') {
      if (cVar1 != '\0') {
                    /* WARNING: Could not recover jumptable at 0x008fc63c. Too many branches */
                    /* WARNING: Treating indirect jump as call */
        (**(code **)(**(int **)(unaff_ESI + 0x730) + 0xcc))();
        return;
      }
    }
    else if (cVar1 == '\0') {
                    /* WARNING: Could not recover jumptable at 0x008fc622. Too many branches */
                    /* WARNING: Treating indirect jump as call */
      (**(code **)(**(int **)(unaff_ESI + 0x730) + 0xcc))();
      return;
    }
  }
  return;
}
```

## Open questions

- Confirm calling convention and full signature against callers.
- Recover meaningful types for still-generic parameters.
