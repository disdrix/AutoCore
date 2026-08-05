# Annotated low-level: FUN_008ec6d0

| Field | Value |
|---|---|
| Stable ID | `aa_008ec6d0` |
| VA | `0x008ec6d0` |
| System | unknown |
| Date | 2026-07-23 |

## Machine-level notes

- Source: raw capture for `aa_008ec6d0`.
- Prefer assembly when decompiler conflicts.
- Recover types for still-generic parameters via callers/xrefs.
- Map DAT_* globals and FUN_* callees in follow-up waves.

## Pseudocode (annotated copy of raw)

```c
void FUN_008ec6d0(undefined4 param_1,undefined4 param_2,undefined4 param_3,undefined4 param_4)

{
  int *piVar1;
  int in_EAX;
  int unaff_EDI;
  
  piVar1 = *(int **)(unaff_EDI + 0x5ac);
  if (piVar1 != (int *)0x0) {
    piVar1[0x13f] = in_EAX;
    (**(code **)(*piVar1 + 0x444))();
    (**(code **)(*piVar1 + 0x34c))();
    FUN_008ec250(unaff_EDI,param_1,param_2,param_3,param_4);
    (**(code **)(**(int **)(unaff_EDI + 0x5ac) + 0xcc))(1);
    (**(code **)(**(int **)(unaff_EDI + 0x5ac) + 0x34c))();
    (**(code **)(**(int **)(unaff_EDI + 0x5ac) + 0x94))();
    FUN_0092f000();
  }
  return;
}
```

## Open questions

- Confirm calling convention and full signature against callers.
- Recover meaningful types for still-generic parameters.
