# Annotated low-level: FUN_005a4ea0

| Field | Value |
|---|---|
| Stable ID | `aa_005a4ea0` |
| VA | `0x005a4ea0` |
| System | unknown |
| Date | 2026-07-23 |

## Machine-level notes

- Source: raw capture for `aa_005a4ea0`.
- Prefer assembly when decompiler conflicts.
- Recover types for still-generic parameters via callers/xrefs.
- Map DAT_* globals and FUN_* callees in follow-up waves.

## Pseudocode (annotated copy of raw)

```c
int * __thiscall FUN_005a4ea0(int param_1,int param_2)

{
  int *piVar1;
  int *piVar2;
  int unaff_EBX;
  
  if (param_2 < 0x1001) {
    param_2 = 0x1000;
  }
  piVar2 = (int *)(**(code **)(*DAT_00b05060 + 0x10))(param_2 + 0x10,0x12);
  *piVar2 = *(int *)(param_1 + 8);
  piVar2[1] = *(int *)(param_1 + 0xc);
  piVar2[2] = *(int *)(param_1 + 0x10);
  piVar2[3] = *(int *)(param_1 + 0x14);
  piVar1 = piVar2 + 4;
  *(int *)(param_1 + 0xc) = param_2 - unaff_EBX;
  *(int **)(param_1 + 0x10) = piVar2;
  *(int **)(param_1 + 0x14) = piVar1;
  *(int *)(param_1 + 8) = (int)piVar1 + unaff_EBX;
  return piVar1;
}
```

## Open questions

- Confirm calling convention and full signature against callers.
- Recover meaningful types for still-generic parameters.
