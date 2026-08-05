# Annotated low-level: FUN_008bff90

| Field | Value |
|---|---|
| Stable ID | `aa_008bff90` |
| VA | `0x008bff90` |
| System | unknown |
| Date | 2026-07-23 |

## Machine-level notes

- Source: raw capture for `aa_008bff90`.
- Prefer assembly when decompiler conflicts.
- Recover types for still-generic parameters via callers/xrefs.
- Map DAT_* globals and FUN_* callees in follow-up waves.

## Pseudocode (annotated copy of raw)

```c
void __thiscall FUN_008bff90(int param_1,int param_2)

{
  int iVar1;
  int iVar2;
  int iVar3;
  
  iVar3 = 0;
  iVar1 = *(int *)(param_1 + 0x560);
  while( true ) {
    if (*(int *)(param_1 + 0x568) == 0) {
      iVar2 = 0;
    }
    else {
      iVar2 = *(int *)(param_1 + 0x56c) - *(int *)(param_1 + 0x568) >> 2;
    }
    if ((iVar2 <= iVar1) || (*(int *)(param_1 + 0x530) + *(int *)(param_1 + 0x560) <= iVar1)) break;
    if ((*(int *)(*(int *)(param_1 + 0x568) + iVar1 * 4) == param_2) &&
       (*(int *)(iVar3 + *(int *)(param_1 + 0x598)) != 0)) {
                    /* WARNING: Could not recover jumptable at 0x008c0014. Too many branches */
                    /* WARNING: Treating indirect jump as call */
      (**(code **)(**(int **)(*(int *)(param_1 + 0x598) + (iVar1 - *(int *)(param_1 + 0x560)) * 4) +
                  0xd4))();
      return;
    }
    iVar1 = iVar1 + 1;
    iVar3 = iVar3 + 4;
  }
  return;
}
```

## Open questions

- Confirm calling convention and full signature against callers.
- Recover meaningful types for still-generic parameters.
