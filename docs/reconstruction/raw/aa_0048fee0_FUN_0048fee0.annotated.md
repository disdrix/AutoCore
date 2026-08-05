# Annotated low-level: FUN_0048fee0

| Field | Value |
|---|---|
| Stable ID | `aa_0048fee0` |
| VA | `0x0048fee0` |
| System | unknown |
| Date | 2026-07-23 |

## Machine-level notes

- Source: raw capture for `aa_0048fee0`.
- Prefer assembly when decompiler conflicts.
- Recover types for still-generic parameters via callers/xrefs.
- Map DAT_* globals and FUN_* callees in follow-up waves.

## Pseudocode (annotated copy of raw)

```c
void __thiscall FUN_0048fee0(int param_1,undefined4 param_2,int *param_3)

{
  float fVar1;
  float fVar2;
  float fVar3;
  float fVar4;
  float fVar5;
  float fVar6;
  int *piVar7;
  int *piVar8;
  int iVar9;
  int iVar10;
  int iVar11;
  int *piVar12;
  
  if (*(char *)(param_1 + 0x82) != '\0') {
    FUN_0076c500(10000);
    fVar1 = *(float *)(*(int *)(*(int *)(param_1 + 0xb8) + 0xe898) + 0x80);
    fVar2 = *(float *)(*(int *)(param_1 + 0xb8) + 0xe7c0);
    fVar3 = *(float *)(*(int *)(*(int *)(param_1 + 0xb8) + 0xe898) + 0x7c);
    fVar4 = *(float *)(*(int *)(param_1 + 0xb8) + 0xe7c4);
    fVar5 = *(float *)(*(int *)(*(int *)(param_1 + 0xb8) + 0xe898) + 0x88);
    fVar6 = *(float *)(*(int *)(param_1 + 0xb8) + 0xe7c4);
    for (iVar11 = (int)ROUND(*(float *)(*(int *)(*(int *)(param_1 + 0xb8) + 0xe898) + 0x74) /
                             *(float *)(*(int *)(param_1 + 0xb8) + 0xe7c0));
        iVar9 = (int)ROUND(fVar3 / fVar4), iVar11 < (int)ROUND(fVar1 / fVar2); iVar11 = iVar11 + 1)
    {
      for (; iVar9 < (int)ROUND(fVar5 / fVar6); iVar9 = iVar9 + 1) {
        iVar10 = FUN_004cd330(iVar11,iVar9);
        if (((iVar10 != 0) && (piVar12 = *(int **)(iVar10 + 4), piVar12 != (int *)0x0)) &&
           (piVar7 = *(int **)(iVar10 + 8), (int)piVar7 - (int)piVar12 >> 2 != 0)) {
          for (; piVar12 != piVar7; piVar12 = piVar12 + 1) {
            piVar8 = (int *)*piVar12;
            if (piVar8 != (int *)0x0) {
              if (0 < *param_3) {
                thunk_FUN_0076c4d0();
                (**(code **)(*piVar8 + 0x50))();
                iVar10 = FUN_0076c3c0();
                *param_3 = *param_3 - iVar10;
              }
              (**(code **)(*piVar8 + 0x7c))(param_2);
            }
          }
        }
      }
    }
  }
  return;
}
```

## Open questions

- Confirm calling convention and full signature against callers.
- Recover meaningful types for still-generic parameters.
