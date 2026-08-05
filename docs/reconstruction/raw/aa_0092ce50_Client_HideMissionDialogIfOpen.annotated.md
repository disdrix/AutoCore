# Annotated low-level: Client_HideMissionDialogIfOpen

| Field | Value |
|---|---|
| Stable ID | `aa_0092ce50` |
| VA | `0x0092ce50` |
| System | missions-progression |
| Date | 2026-07-23 |

## Machine-level notes

- Source: raw capture for `aa_0092ce50`.
- Prefer assembly when decompiler conflicts.
- Recover types for still-generic parameters via callers/xrefs.
- Map DAT_* globals and FUN_* callees in follow-up waves.

## Pseudocode (annotated copy of raw)

```c
/* Client_HideMissionDialogIfOpen
   
   If mission dialog root at game+0x107c is visible (vtable+0x3d8), hide it (+0x448)
   and refresh layout (+0x34c). */

void Client_HideMissionDialogIfOpen(void)

{
  char cVar1;
  int unaff_ESI;
  
  if (*(int *)(unaff_ESI + 0x107c) != 0) {
    cVar1 = (**(code **)(**(int **)(unaff_ESI + 0x107c) + 0x3d8))();
    if (cVar1 != '\0') {
      (**(code **)(**(int **)(unaff_ESI + 0x107c) + 0x448))();
                    /* WARNING: Could not recover jumptable at 0x0092ce81. Too many branches */
                    /* WARNING: Treating indirect jump as call */
      (**(code **)(**(int **)(unaff_ESI + 0x107c) + 0x34c))();
      return;
    }
  }
  return;
}
```

## Open questions

- Confirm calling convention and full signature against callers.
- Recover meaningful types for still-generic parameters.
