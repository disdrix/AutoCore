# Annotated low-level: FUN_007fcc10

| Field | Value |
|---|---|
| Stable ID | `aa_007fcc10` |
| VA | `0x007fcc10` |
| System | unknown |
| Date | 2026-07-23 |

## Machine-level notes

- Source: raw capture for `aa_007fcc10`.
- Prefer assembly when decompiler conflicts.
- Recover types for still-generic parameters via callers/xrefs.
- Map DAT_* globals and FUN_* callees in follow-up waves.

## Pseudocode (annotated copy of raw)

```c
void __fastcall FUN_007fcc10(int *param_1)

{
  int iVar1;
  int iVar2;
  int *unaff_ESI;
  float10 fVar3;
  
  if ((param_1 != (int *)0x0) && (unaff_ESI != (int *)0x0)) {
    fVar3 = (float10)(**(code **)(*param_1 + 0x458))();
    iVar1 = (**(code **)(*unaff_ESI + 0x494))();
    iVar2 = (**(code **)(*unaff_ESI + 0x490))();
    iVar1 = (int)ROUND((float)(iVar2 - iVar1) * (float)fVar3);
    if (iVar1 < 0) {
      iVar1 = 0;
    }
    (**(code **)(*unaff_ESI + 0x498))(iVar1);
  }
  return;
}
```

## Open questions

- Confirm calling convention and full signature against callers.
- Recover meaningful types for still-generic parameters.
