# Annotated low-level: FUN_0043bcc0

| Field | Value |
|---|---|
| Stable ID | `aa_0043bcc0` |
| VA | `0x0043bcc0` |
| System | unknown |
| Date | 2026-07-23 |

## Machine-level notes

- Source: raw capture for `aa_0043bcc0`.
- Prefer assembly when decompiler conflicts.
- Recover types for still-generic parameters via callers/xrefs.
- Map DAT_* globals and FUN_* callees in follow-up waves.

## Pseudocode (annotated copy of raw)

```c
int * FUN_0043bcc0(int *param_1,int *param_2)

{
  int iVar1;
  int *piVar2;
  uint uVar3;
  int iVar4;
  uint uVar5;
  int unaff_EDI;
  
  uVar3 = *(uint *)(unaff_EDI + 0x20);
  uVar5 = FUN_0043b870();
  uVar5 = uVar5 & uVar3;
  if (*(uint *)(unaff_EDI + 0x24) <= uVar5) {
    uVar5 = uVar5 + (-1 - (uVar3 >> 1));
  }
  iVar4 = *(int *)(unaff_EDI + 0x14);
  iVar1 = uVar5 * 4;
  piVar2 = *(int **)(iVar1 + iVar4);
  while ((param_2 == piVar2 &&
         (*(undefined4 *)(iVar1 + iVar4) = **(undefined4 **)(iVar1 + iVar4), uVar5 != 0))) {
    iVar4 = *(int *)(unaff_EDI + 0x14);
    uVar5 = uVar5 - 1;
    iVar1 = uVar5 * 4;
    piVar2 = *(int **)(iVar1 + iVar4);
  }
  if (param_2 == *(int **)(unaff_EDI + 8)) {
    *param_1 = *param_2;
    return param_1;
  }
  *(int *)param_2[1] = *param_2;
  *(int *)(*param_2 + 4) = param_2[1];
                    /* WARNING: Subroutine does not return */
  operator_delete(param_2);
}
```

## Open questions

- Confirm calling convention and full signature against callers.
- Recover meaningful types for still-generic parameters.
