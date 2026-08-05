# Annotated low-level: FUN_007ab4e0

| Field | Value |
|---|---|
| Stable ID | `aa_007ab4e0` |
| VA | `0x007ab4e0` |
| System | unknown |
| Date | 2026-07-23 |

## Machine-level notes

- Source: raw capture for `aa_007ab4e0`.
- Prefer assembly when decompiler conflicts.
- Recover types for still-generic parameters via callers/xrefs.
- Map DAT_* globals and FUN_* callees in follow-up waves.

## Pseudocode (annotated copy of raw)

```c
void __thiscall FUN_007ab4e0(int param_1,int *param_2,char param_3,char param_4)

{
  int *piVar1;
  int iVar2;
  int iVar3;
  int iVar4;
  float fVar5;
  undefined1 local_8 [8];
  
  iVar3 = *(int *)(param_1 + 0x78);
  iVar4 = *(int *)(param_1 + 0x7c);
  if ((param_4 != '\0') && (*(int *)(param_1 + 0x2b0) != 0)) {
    piVar1 = (int *)(**(code **)(**(int **)(param_1 + 0x2b0) + 0x120))(local_8,1,1);
    iVar3 = iVar3 + *piVar1;
    iVar2 = (**(code **)(**(int **)(param_1 + 0x2b0) + 0x120))(&stack0xffffffec,1,1);
    iVar4 = iVar4 + *(int *)(iVar2 + 4);
  }
  if (param_3 == '\0') {
    if (*(char *)(param_1 + 0x1c9) == '\0') {
      if (DAT_00d17944 != 0) {
        fVar5 = ((float)iVar3 * DAT_00aaa674) / (float)DAT_00d1e818;
        iVar3 = DAT_00d1e81c;
        goto LAB_007ab59c;
      }
    }
    else if (DAT_00d17944 != 0) {
      fVar5 = ((float)iVar3 * DAT_00aaa674) / (float)*(int *)(*(int *)(DAT_00d17944 + 0x2c) + 0x80);
      iVar3 = *(int *)(*(int *)(DAT_00d17944 + 0x2c) + 0x84);
LAB_007ab59c:
      param_2[1] = (int)(((float)iVar4 * DAT_00aaa670) / (float)iVar3);
      *param_2 = (int)fVar5;
      return;
    }
    iVar3 = 0;
    iVar4 = 0;
  }
  param_2[1] = iVar4;
  *param_2 = iVar3;
  return;
}
```

## Open questions

- Confirm calling convention and full signature against callers.
- Recover meaningful types for still-generic parameters.
