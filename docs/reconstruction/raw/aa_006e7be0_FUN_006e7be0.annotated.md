# Annotated low-level: FUN_006e7be0

| Field | Value |
|---|---|
| Stable ID | `aa_006e7be0` |
| VA | `0x006e7be0` |
| System | unknown |
| Date | 2026-07-23 |

## Machine-level notes

- Source: raw capture for `aa_006e7be0`.
- Prefer assembly when decompiler conflicts.
- Recover types for still-generic parameters via callers/xrefs.
- Map DAT_* globals and FUN_* callees in follow-up waves.

## Pseudocode (annotated copy of raw)

```c
undefined4 * __thiscall
FUN_006e7be0(undefined4 *param_1,int *param_2,undefined4 *param_3,int *param_4,undefined4 param_5)

{
  int *piVar1;
  int *piVar2;
  int iVar3;
  int *piVar4;
  int iVar5;
  int iVar6;
  char *pcVar7;
  int iVar8;
  int iVar9;
  undefined4 uVar10;
  int *piStack_10;
  int iStack_c;
  int local_8;
  int *local_4;
  
  param_1[2] = param_5;
  *param_1 = &PTR_FUN_00a0e818;
  piVar1 = param_1 + 3;
  *piVar1 = (int)(param_1 + 6);
  param_1[4] = 0;
  param_1[5] = 0x80000004;
  local_8 = param_2[2];
  piVar2 = (int *)*param_2;
  local_4 = param_2;
  iVar5 = (**(code **)(*piVar2 + 0x28))();
  if ((int)(param_1[5] & 0x7fffffff) < iVar5) {
    iVar6 = (param_1[5] & 0x7fffffff) * 2;
    if (iVar6 <= iVar5) {
      iVar6 = iVar5;
    }
    FUN_005b3300(piVar1,iVar6,4);
  }
  piVar4 = param_4;
  param_1[4] = iVar5;
  iVar5 = 0;
  if ((int)param_1[4] < 1) {
    return param_1;
  }
  do {
    piStack_10 = *(int **)(piVar2[3] + iVar5 * 8);
    iStack_c = iVar5;
    pcVar7 = (char *)(*(code *)**(undefined4 **)piVar4[1])
                               (&param_4,piVar4,param_3,param_2,piVar2,iVar5);
    if (*pcVar7 == '\0') {
      iVar6 = *piVar1;
      uVar10 = FUN_006cb7d0();
      *(undefined4 *)(iVar6 + iVar5 * 4) = uVar10;
    }
    else {
      iVar6 = *piVar4;
      iVar8 = (**(code **)(*piStack_10 + 0x14))();
      iVar9 = (**(code **)(*(int *)*param_3 + 0x14))();
      iVar3 = *piVar1;
      uVar10 = (**(code **)(iVar6 + 0x18c + (iVar8 * 0x20 + iVar9) * 4))
                         (&piStack_10,param_3,piVar4,param_5);
      *(undefined4 *)(iVar3 + iVar5 * 4) = uVar10;
    }
    iVar5 = iVar5 + 1;
  } while (iVar5 < (int)param_1[4]);
  return param_1;
}
```

## Open questions

- Confirm calling convention and full signature against callers.
- Recover meaningful types for still-generic parameters.
