# Annotated low-level: FUN_004fd9b0

| Field | Value |
|---|---|
| Stable ID | `aa_004fd9b0` |
| VA | `0x004fd9b0` |
| System | unknown |
| Date | 2026-07-23 |

## Machine-level notes

- Source: raw capture for `aa_004fd9b0`.
- Prefer assembly when decompiler conflicts.
- Recover types for still-generic parameters via callers/xrefs.
- Map DAT_* globals and FUN_* callees in follow-up waves.

## Pseudocode (annotated copy of raw)

```c
void __thiscall FUN_004fd9b0(int param_1,int param_2,undefined4 param_3)

{
  int iVar1;
  int *piVar2;
  int *piVar3;
  int iVar4;
  char cVar5;
  int *piVar6;
  int iVar7;
  uint uVar8;
  int iVar9;
  
  iVar4 = param_2;
  if (*(int *)(param_1 + 600) != 0) {
    FUN_005a9240(param_2);
  }
  cVar5 = '\0';
  do {
    iVar7 = *(int *)(param_1 + 0x340 + cVar5 * 4);
    if (iVar7 == 0) break;
    iVar9 = *(int *)(iVar4 + 4);
    param_2 = iVar7;
    if ((iVar9 == 0) ||
       ((uint)(*(int *)(iVar4 + 0xc) - iVar9 >> 2) <= (uint)(*(int *)(iVar4 + 8) - iVar9 >> 2))) {
      FUN_004507a0(*(undefined4 *)(iVar4 + 8),1,&param_2);
    }
    else {
      piVar6 = *(int **)(iVar4 + 8);
      *piVar6 = iVar7;
      *(int **)(iVar4 + 8) = piVar6 + 1;
    }
    cVar5 = cVar5 + '\x01';
  } while (cVar5 < '\x03');
  iVar7 = *(int *)(param_1 + 0x3a0);
  if (iVar7 != 0) {
    iVar9 = *(int *)(iVar4 + 4);
    param_2 = iVar7;
    if ((iVar9 == 0) ||
       ((uint)(*(int *)(iVar4 + 0xc) - iVar9 >> 2) <= (uint)(*(int *)(iVar4 + 8) - iVar9 >> 2))) {
      FUN_004507a0(*(undefined4 *)(iVar4 + 8),1,&param_2);
    }
    else {
      piVar6 = *(int **)(iVar4 + 8);
      *piVar6 = iVar7;
      *(int **)(iVar4 + 8) = piVar6 + 1;
    }
  }
  piVar6 = (int *)(param_1 + 0x34c);
  iVar7 = 8;
  do {
    iVar9 = *piVar6;
    if (iVar9 != 0) {
      iVar1 = *(int *)(iVar4 + 4);
      param_2 = iVar9;
      if ((iVar1 == 0) ||
         ((uint)(*(int *)(iVar4 + 0xc) - iVar1 >> 2) <= (uint)(*(int *)(iVar4 + 8) - iVar1 >> 2))) {
        FUN_004507a0(*(undefined4 *)(iVar4 + 8),1,&param_2);
      }
      else {
        piVar2 = *(int **)(iVar4 + 8);
        *piVar2 = iVar9;
        *(int **)(iVar4 + 8) = piVar2 + 1;
      }
    }
    piVar6 = piVar6 + 1;
    iVar7 = iVar7 + -1;
  } while (iVar7 != 0);
  if (((*(char *)(param_1 + 0x105) != '\0') &&
      (cVar5 = (**(code **)(*(int *)(*(int *)(*(int *)(param_1 + 4) + 4) + 4 + param_1) + 0x198))(),
      cVar5 == '\0')) &&
     ((iVar7 = (**(code **)(*(int *)(*(int *)(*(int *)(param_1 + 4) + 4) + 4 + param_1) + 0x210))(0)
      , iVar7 == 0 ||
      (iVar7 = (**(code **)(*(int *)(*(int *)(*(int *)(param_1 + 4) + 4) + 4 + param_1) + 0x210))(0)
      , *(char *)(iVar7 + 0x6b9) == '\0')))) {
    iVar9 = 0;
    iVar7 = 3;
    do {
      iVar1 = *(int *)(iVar9 + *(int *)(param_1 + 0x260));
      if (((iVar1 != 0) && (iVar1 = *(int *)(iVar1 + 0xc0), iVar1 != 0)) &&
         (piVar6 = *(int **)(iVar1 + 0x18), piVar6 != (int *)0x0)) {
        (**(code **)(*piVar6 + 0x3c))(param_3);
      }
      iVar9 = iVar9 + 4;
      iVar7 = iVar7 + -1;
    } while (iVar7 != 0);
  }
  iVar7 = *(int *)(param_1 + 0x3b8);
  if (((iVar7 != 0) && (piVar6 = *(int **)(iVar7 + 4), piVar6 != (int *)0x0)) &&
     (param_2 = *(int *)(iVar7 + 8) - (int)piVar6 >> 2, param_2 != 0)) {
    piVar2 = *(int **)(iVar7 + 8);
    for (; piVar6 != piVar2; piVar6 = piVar6 + 1) {
      if (((int *)*piVar6 != (int *)0x0) && (piVar3 = *(int **)*piVar6, piVar3 != (int *)0x0)) {
        (**(code **)(*piVar3 + 0x3c))(param_3);
        (**(code **)(**(int **)*piVar6 + 0x40))(param_2);
      }
    }
  }
  iVar7 = *(int *)(param_1 + 0x3a4);
  if ((iVar7 != 0) &&
     (*(char *)(*(int *)(*(int *)(*(int *)(*(int *)(param_1 + 4) + 4) + 0xa8 + param_1) + 0xe898) +
               0x52) != '\0')) {
    iVar9 = *(int *)(iVar4 + 4);
    param_2 = iVar7;
    if ((iVar9 == 0) ||
       ((uint)(*(int *)(iVar4 + 0xc) - iVar9 >> 2) <= (uint)(*(int *)(iVar4 + 8) - iVar9 >> 2))) {
      FUN_004507a0(*(undefined4 *)(iVar4 + 8),1,&param_2);
    }
    else {
      piVar6 = *(int **)(iVar4 + 8);
      *piVar6 = iVar7;
      *(int **)(iVar4 + 8) = piVar6 + 1;
    }
  }
  if (*(int *)(param_1 + 0x3ac) != 0) {
    uVar8 = 0;
    while( true ) {
      iVar4 = *(int *)(param_1 + 0x3ac);
      iVar7 = *(int *)(iVar4 + 4);
      if (iVar7 == 0) {
        return;
      }
      if ((uint)(*(int *)(iVar4 + 8) - iVar7 >> 2) <= uVar8) {
        return;
      }
      if ((iVar7 == 0) || ((uint)(*(int *)(iVar4 + 8) - iVar7 >> 2) <= uVar8)) break;
      if (*(int *)(iVar7 + uVar8 * 4) != 0) {
        if ((iVar7 == 0) || ((uint)(*(int *)(iVar4 + 8) - iVar7 >> 2) <= uVar8)) break;
        (**(code **)(**(int **)(iVar7 + uVar8 * 4) + 0x3c))(param_3);
      }
      uVar8 = uVar8 + 1;
    }
    FUN_005062a0();
  }
  return;
}
```

## Open questions

- Confirm calling convention and full signature against callers.
- Recover meaningful types for still-generic parameters.
