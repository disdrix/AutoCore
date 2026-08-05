# Annotated low-level: FUN_008aa4b0

| Field | Value |
|---|---|
| Stable ID | `aa_008aa4b0` |
| VA | `0x008aa4b0` |
| System | unknown |
| Date | 2026-07-23 |

## Machine-level notes

- Source: raw capture for `aa_008aa4b0`.
- Prefer assembly when decompiler conflicts.
- Recover types for still-generic parameters via callers/xrefs.
- Map DAT_* globals and FUN_* callees in follow-up waves.

## Pseudocode (annotated copy of raw)

```c
void FUN_008aa4b0(void)

{
  int *piVar1;
  int iVar2;
  int in_EAX;
  undefined4 uVar3;
  int unaff_ESI;
  
  piVar1 = *(int **)(unaff_ESI + 0x6d8);
  *(int *)(unaff_ESI + 0x644) = in_EAX;
  if (piVar1 != (int *)0x0) {
    if (in_EAX == 0) {
      (**(code **)(*piVar1 + 0x1d8))(&DAT_00a1419b,1,1);
    }
    else {
      iVar2 = *piVar1;
      uVar3 = (**(code **)(*(int *)(*(int *)(*(int *)(in_EAX + 4) + 4) + 4 + in_EAX) + 0x160))(1,1);
      (**(code **)(iVar2 + 0x1d8))(uVar3);
    }
                    /* WARNING: Could not recover jumptable at 0x008aa508. Too many branches */
                    /* WARNING: Treating indirect jump as call */
    (**(code **)(**(int **)(unaff_ESI + 0x6d8) + 0x34c))();
    return;
  }
  return;
}
```

## Open questions

- Confirm calling convention and full signature against callers.
- Recover meaningful types for still-generic parameters.
