# Annotated low-level: FUN_008dfc60

| Field | Value |
|---|---|
| Stable ID | `aa_008dfc60` |
| VA | `0x008dfc60` |
| System | unknown |
| Date | 2026-07-23 |

## Machine-level notes

- Source: raw capture for `aa_008dfc60`.
- Prefer assembly when decompiler conflicts.
- Recover types for still-generic parameters via callers/xrefs.
- Map DAT_* globals and FUN_* callees in follow-up waves.

## Pseudocode (annotated copy of raw)

```c
void FUN_008dfc60(int *param_1,int param_2,int param_3,char param_4)

{
  int iVar1;
  int iVar2;
  char cVar3;
  void *pvVar4;
  int iVar5;
  int *piVar6;
  int unaff_retaddr;
  int *piStack_28;
  int iStack_24;
  int *piStack_20;
  int iStack_18;
  void *pvStack_c;
  undefined1 *puStack_8;
  int iStack_4;
  
  iStack_4 = 0xffffffff;
  puStack_8 = &LAB_009b3a24;
  pvStack_c = ExceptionList;
  ExceptionList = &pvStack_c;
  cVar3 = (**(code **)(*param_1 + 0x3d8))();
  if (cVar3 == '\0') {
    ExceptionList = pvStack_c;
    return;
  }
  pvVar4 = operator_new(0x4e0);
  piVar6 = (int *)0x0;
  iStack_4 = 0;
  if (pvVar4 != (void *)0x0) {
    piVar6 = (int *)FUN_00834940(pvVar4);
  }
  iStack_4 = 0xffffffff;
  piStack_28 = piVar6;
  (**(code **)(*param_1 + 0xa8))(piVar6);
  (**(code **)(*piVar6 + 0x28))("i_d_dt_2d_wnd_tree_branch.xml");
  iVar1 = param_1[0x146];
  iStack_18 = (((int)pvVar4 * 2 + 1) * param_1[0x147]) / 2 + param_1[0x145];
  iVar5 = param_1[0x144];
  piStack_28 = (int *)(((param_3 * 2 + 1) * param_1[0x147]) / 2 + param_1[0x145]);
  FUN_00415d80(0,0);
  iVar2 = piVar6[0x124];
  piStack_20 = (int *)iStack_18;
  iStack_24 = ((unaff_retaddr * 2 + 1) * iVar1) / 2 + iVar5;
  iStack_4 = FUN_00415ed0(iVar2,*(undefined4 *)(iVar2 + 4));
  FUN_00416010();
  *(int *)(iVar2 + 4) = iStack_4;
  **(int **)(iStack_4 + 4) = iStack_4;
  iVar2 = piVar6[0x124];
  piStack_20 = piStack_28;
  iStack_24 = ((param_2 * 2 + 1) * iVar1) / 2 + iVar5;
  iStack_4 = FUN_00415ed0(iVar2,*(undefined4 *)(iVar2 + 4));
  FUN_00416010();
  *(int *)(iVar2 + 4) = iStack_4;
  **(int **)(iStack_4 + 4) = iStack_4;
  if (DAT_00d1b6d8 == 0) {
LAB_008dfe42:
    iStack_4 = DAT_00afdf0c;
  }
  else {
    cVar3 = *(char *)(*(int *)(*(int *)(*(int *)(*(int *)(DAT_00d1b6d8 + 4) + 4) + 0xac +
                                       DAT_00d1b6d8) + 0x3c) + 0x532);
    if (cVar3 == '\0') {
      iStack_4 = -0xe2af01;
    }
    else if (cVar3 == '\x01') {
      iStack_4 = -0x9400c0;
    }
    else {
      if (cVar3 != '\x02') goto LAB_008dfe42;
      iStack_4 = -0x482f6;
    }
  }
  piVar6[0x136] = iStack_4;
  if (DAT_00d1b6d8 != 0) {
    cVar3 = *(char *)(*(int *)(*(int *)(*(int *)(*(int *)(DAT_00d1b6d8 + 4) + 4) + 0xac +
                                       DAT_00d1b6d8) + 0x3c) + 0x532);
    if (cVar3 == '\0') {
      iStack_4 = -0xf5e19e;
      goto LAB_008dfece;
    }
    if (cVar3 == '\x01') {
      iStack_4 = -0xd49be6;
      goto LAB_008dfece;
    }
    if (cVar3 == '\x02') {
      iStack_4 = -0x9bd5fb;
      goto LAB_008dfece;
    }
  }
  iStack_4 = DAT_00afdf00;
LAB_008dfece:
  piVar6[0x137] = iStack_4;
  *(char *)(piVar6 + 0x122) = param_4;
  if (param_4 == '\0') {
    (**(code **)(*piVar6 + 0x15c))(0,piVar6 + 0x137);
  }
  else {
    (**(code **)(*piVar6 + 0x15c))(0,piVar6 + 0x136);
  }
  (**(code **)(*piVar6 + 0x34c))();
  iVar1 = param_1[0x1ac];
  iVar5 = FUN_00418700(iVar1,*(undefined4 *)(iVar1 + 4),&piStack_28);
  FUN_00418790();
  *(int *)(iVar1 + 4) = iVar5;
  **(int **)(iVar5 + 4) = iVar5;
  ExceptionList = pvStack_c;
  return;
}
```

## Open questions

- Confirm calling convention and full signature against callers.
- Recover meaningful types for still-generic parameters.
