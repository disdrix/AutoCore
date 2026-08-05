# Annotated low-level: FUN_0092cef0

| Field | Value |
|---|---|
| Stable ID | `aa_0092cef0` |
| VA | `0x0092cef0` |
| System | unknown |
| Date | 2026-07-23 |

## Machine-level notes

- Source: raw capture for `aa_0092cef0`.
- Prefer assembly when decompiler conflicts.
- Recover types for still-generic parameters via callers/xrefs.
- Map DAT_* globals and FUN_* callees in follow-up waves.

## Pseudocode (annotated copy of raw)

```c
void FUN_0092cef0(void)

{
  char cVar1;
  int *piVar2;
  int unaff_ESI;
  
  piVar2 = *(int **)(unaff_ESI + 0xf40);
  if ((piVar2 != (int *)0x0) && (*piVar2 != 0)) {
    (**(code **)(*(int *)*piVar2 + 0x94))();
    if (*(int *)(unaff_ESI + 0x1138) != 0) {
      cVar1 = (**(code **)(**(int **)(unaff_ESI + 0x1138) + 0x3d8))();
      if (cVar1 != '\0') {
        (**(code **)(**(int **)(unaff_ESI + 0x1138) + 0x94))();
      }
    }
    piVar2 = (int *)FUN_0090d390();
    if (piVar2 != (int *)0x0) {
                    /* WARNING: Could not recover jumptable at 0x0092cf3f. Too many branches */
                    /* WARNING: Treating indirect jump as call */
      (**(code **)(*piVar2 + 0x94))();
      return;
    }
  }
  return;
}
```

## Open questions

- Confirm calling convention and full signature against callers.
- Recover meaningful types for still-generic parameters.
