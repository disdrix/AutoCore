# Annotated low-level: FUN_006f3fd0

| Field | Value |
|---|---|
| Stable ID | `aa_006f3fd0` |
| VA | `0x006f3fd0` |
| System | unknown |
| Date | 2026-07-23 |

## Machine-level notes

- Source: raw capture for `aa_006f3fd0`.
- Prefer assembly when decompiler conflicts.
- Recover types for still-generic parameters via callers/xrefs.
- Map DAT_* globals and FUN_* callees in follow-up waves.

## Pseudocode (annotated copy of raw)

```c
void __thiscall FUN_006f3fd0(int param_1,int param_2,int *param_3,undefined4 param_4,int *param_5)

{
  int *piVar1;
  int iVar2;
  int unaff_EBX;
  int iVar3;
  int iVar4;
  float10 fVar5;
  float10 fVar6;
  int unaff_retaddr;
  float fStack_10;
  int iStack_c;
  
  piVar1 = *(int **)(param_1 + 0x20);
  iVar4 = *(int *)(*(int *)(param_1 + 8) + 0xc);
  fVar5 = (float10)(**(code **)(*piVar1 + 4))(param_5);
  iVar3 = **(int **)(unaff_EBX + 0xc);
  iVar4 = iVar4 >> 1;
  fStack_10 = 1e+07;
  param_4 = 0;
  if (iVar3 == 0) {
    iVar3 = (*(int **)(unaff_EBX + 0xc))[3];
    if (iVar3 != 0) {
      param_5[0xe] = *(int *)(iVar3 + 0xc);
      iVar3 = 0;
      while( true ) {
        param_5[0xc] = iVar3;
        param_5[0xd] = (param_5[1] - unaff_retaddr) + iVar3;
        fVar6 = (float10)(**(code **)(*piVar1 + 8))(param_5);
        fVar6 = fVar6 + (float10)(float)fVar5;
        if (fVar6 < (float10)fStack_10) {
          fStack_10 = (float)fVar6;
          *param_3 = iVar3;
          if (fVar6 < (float10)*(float *)(param_2 + 0xc4)) {
            *(float *)(param_2 + 0xc4) = (float)fVar6;
            *(int *)(param_2 + 0xb8) = param_5[9];
            *(int *)(param_2 + 0xbc) = param_5[8];
            *(int *)(param_2 + 0xc0) = param_5[0xe];
            iVar2 = iVar3 - iVar4;
            if ((iVar2 < param_4) && (param_4 = iVar2, iVar2 < 0)) {
              param_4 = 0;
            }
            (**(code **)(*piVar1 + 0x10))(param_5,param_2 + 200);
          }
        }
LAB_006f4076:
        iVar3 = iVar3 + -1;
        if (iVar3 < param_4) break;
        if (**(int **)(unaff_EBX + 0xc) < iVar3) {
          iVar2 = 0;
        }
        else {
          iVar2 = *(int *)((*(int **)(unaff_EBX + 0xc))[2] + iVar3 * 4);
        }
        param_5[0xe] = *(int *)(iVar2 + 0xc);
      }
      *param_3 = *param_3 + -1;
    }
  }
  else if ((float)fVar5 <= *(float *)(param_2 + 0xc4)) {
    if (iStack_c < 1) goto LAB_006f4076;
    iVar2 = *param_3 + iVar4;
    if (iVar3 < iVar2) {
      iVar2 = iVar3;
    }
    param_4 = *param_3 - iVar4;
    iVar3 = iVar2;
    if (-1 < param_4) goto LAB_006f4076;
    param_4 = 0;
    goto LAB_006f4076;
  }
  FUN_006f3d90(unaff_retaddr * 0x10 + *param_5);
  return;
}
```

## Open questions

- Confirm calling convention and full signature against callers.
- Recover meaningful types for still-generic parameters.
