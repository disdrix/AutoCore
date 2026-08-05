# Annotated low-level: FUN_008e9df0

| Field | Value |
|---|---|
| Stable ID | `aa_008e9df0` |
| VA | `0x008e9df0` |
| System | unknown |
| Date | 2026-07-23 |

## Machine-level notes

- Source: raw capture for `aa_008e9df0`.
- Prefer assembly when decompiler conflicts.
- Recover types for still-generic parameters via callers/xrefs.
- Map DAT_* globals and FUN_* callees in follow-up waves.

## Pseudocode (annotated copy of raw)

```c
void FUN_008e9df0(void)

{
  int *piVar1;
  void *pvVar2;
  int iVar3;
  int iVar4;
  int iVar5;
  int *piVar6;
  int *unaff_EDI;
  float fVar7;
  int iStack_40;
  int local_30;
  undefined1 auStack_24 [4];
  undefined4 uStack_20;
  undefined4 uStack_18;
  undefined4 uStack_14;
  undefined4 uStack_10;
  void *local_c;
  undefined1 *puStack_8;
  undefined4 uStack_4;
  
  uStack_4 = 0xffffffff;
  puStack_8 = &LAB_009b74bd;
  local_c = ExceptionList;
  if (unaff_EDI[0x130] != 0) {
    ExceptionList = &local_c;
    *(undefined1 *)(unaff_EDI + 0x14f) = 1;
    piVar6 = unaff_EDI + 0x16e;
    local_30 = 4;
    do {
      iStack_40 = *piVar6;
      (**(code **)(*unaff_EDI + 0xbc))();
      pvVar2 = operator_new(0x520);
      puStack_8 = (undefined1 *)0x0;
      if (pvVar2 == (void *)0x0) {
        iVar3 = 0;
      }
      else {
        iVar3 = FUN_00865870();
      }
      puStack_8 = (undefined1 *)0xffffffff;
      *piVar6 = iVar3;
      (**(code **)(*unaff_EDI + 0xa8))();
      (**(code **)(*(int *)*piVar6 + 0x43c))();
      (**(code **)(*(int *)*piVar6 + 0x118))();
      (**(code **)(*(int *)*piVar6 + 0xcc))();
      piVar1 = (int *)*piVar6;
      *(undefined1 *)(piVar1 + 0x13f) = 0;
      piVar1[0x141] = 0;
      (**(code **)(*piVar1 + 0x444))();
      (**(code **)(*piVar1 + 0x34c))();
      piVar6 = piVar6 + 1;
      local_30 = local_30 + -1;
    } while (local_30 != 0);
    iVar3 = unaff_EDI[0x1a] + 1;
    unaff_EDI[0x1a] = iVar3;
    unaff_EDI[0x1d] = (int)(float)-iVar3;
    if (unaff_EDI[0x1c] < iVar3) {
      unaff_EDI[0x1c] = iVar3;
    }
    iStack_40 = 1;
    (**(code **)(*unaff_EDI + 0x3f4))();
    iVar5 = 0;
    piVar6 = unaff_EDI + 0x176;
    iVar3 = 4;
    do {
      (**(code **)(*unaff_EDI + 0xbc))();
      pvVar2 = operator_new(0x520);
      local_c = (void *)0x1;
      if (pvVar2 == (void *)0x0) {
        iVar4 = 0;
      }
      else {
        iVar4 = FUN_00856490();
      }
      local_c = (void *)0xffffffff;
      *piVar6 = iVar4;
      (**(code **)(*unaff_EDI + 0xa8))();
      (**(code **)(*(int *)*piVar6 + 0x28))();
      (**(code **)(*(int *)*piVar6 + 8))();
      iVar4 = *piVar6;
      *(int *)(iVar4 + 0x234) = unaff_EDI[0x157];
      *(int *)(iVar4 + 0x238) = unaff_EDI[0x158];
      *(int *)(iVar4 + 0x23c) = unaff_EDI[0x159];
      *(int *)(*piVar6 + 0x138) = unaff_EDI[0x154];
      iStack_40 = (int)((float)DAT_00d1e81c *
                        (float)((unaff_EDI[0x165] + unaff_EDI[0x167]) * iVar5 + unaff_EDI[0x163]) *
                       DAT_00aaa678);
      (**(code **)(*(int *)*piVar6 + 0x118))();
      (**(code **)(*(int *)*piVar6 + 0x1a0))();
      FUN_0040cf90();
      iVar4 = *piVar6;
      iVar5 = iVar5 + 1;
      piVar6 = piVar6 + 1;
      iVar3 = iVar3 + -1;
      *(undefined4 *)(iVar4 + 0x488) = 0;
    } while (iVar3 != 0);
    iVar3 = unaff_EDI[0x1a] + 1;
    unaff_EDI[0x1a] = iVar3;
    unaff_EDI[0x1d] = (int)(float)-iVar3;
    if (unaff_EDI[0x1c] < iVar3) {
      unaff_EDI[0x1c] = iVar3;
    }
    (**(code **)(*unaff_EDI + 0x3f4))();
    piVar6 = unaff_EDI + 0x18a;
    do {
      (**(code **)(*unaff_EDI + 0xbc))();
      pvVar2 = operator_new(0x4f8);
      uStack_10 = 2;
      if (pvVar2 == (void *)0x0) {
        iVar3 = 0;
      }
      else {
        iVar3 = FUN_0097ffa0();
      }
      uStack_10 = 0xffffffff;
      piVar6[-8] = iVar3;
      (**(code **)(*unaff_EDI + 0xa8))();
      (**(code **)(*(int *)piVar6[-8] + 0x28))();
      fVar7 = (float)DAT_00d1e818 * (float)(unaff_EDI[0x162] + unaff_EDI[0x15a]) * DAT_00aaa67c;
      (**(code **)(*(int *)piVar6[-8] + 0x118))();
      (**(code **)(*unaff_EDI + 0xbc))(*piVar6);
      pvVar2 = operator_new(0x488);
      uStack_20 = 3;
      if (pvVar2 == (void *)0x0) {
        iVar3 = 0;
      }
      else {
        iVar3 = FUN_007b5dd0(pvVar2,0);
      }
      uStack_20 = 0xffffffff;
      *piVar6 = iVar3;
      (**(code **)(*unaff_EDI + 0xa8))(iVar3);
      (**(code **)(*(int *)*piVar6 + 0x28))("i_d_con_2d_wnd_shields.xml");
      iStack_40 = (int)((float)DAT_00d1e818 * (float)(unaff_EDI[0x162] + unaff_EDI[0x15c]) *
                       DAT_00aaa67c);
      (**(code **)(*(int *)*piVar6 + 0x118))(&iStack_40);
      piVar6 = piVar6 + 1;
    } while ((int)fVar7 != 1);
    iVar3 = unaff_EDI[0x1a] + 1;
    unaff_EDI[0x1a] = iVar3;
    unaff_EDI[0x1d] = (int)(float)-iVar3;
    if (unaff_EDI[0x1c] < iVar3) {
      unaff_EDI[0x1c] = iVar3;
    }
    (**(code **)(*unaff_EDI + 0x3f4))();
    piVar6 = unaff_EDI + 0x186;
    iVar3 = 4;
    do {
      (**(code **)(*unaff_EDI + 0xbc))();
      pvVar2 = operator_new(0x4f8);
      uStack_14 = 4;
      if (pvVar2 == (void *)0x0) {
        iVar5 = 0;
      }
      else {
        iVar5 = FUN_0097ffa0();
      }
      uStack_14 = 0xffffffff;
      *piVar6 = iVar5;
      (**(code **)(*unaff_EDI + 0xa8))();
      (**(code **)(*(int *)*piVar6 + 0x28))();
      (**(code **)(*(int *)*piVar6 + 0x118))(&stack0xffffffcc);
      piVar6 = piVar6 + 1;
      iVar3 = iVar3 + -1;
    } while (iVar3 != 0);
    iVar3 = unaff_EDI[0x1a] + 1;
    unaff_EDI[0x1a] = iVar3;
    unaff_EDI[0x1d] = (int)(float)-iVar3;
    if (unaff_EDI[0x1c] < iVar3) {
      unaff_EDI[0x1c] = iVar3;
    }
    (**(code **)(*unaff_EDI + 0x3f4))();
    iVar3 = 0;
    piVar6 = unaff_EDI + 0x17a;
    iStack_40 = 4;
    do {
      (**(code **)(*unaff_EDI + 0xbc))();
      *piVar6 = 0;
      pvVar2 = operator_new(0x4cc);
      uStack_18 = 5;
      iVar5 = 0;
      if (pvVar2 != (void *)0x0) {
        iVar5 = FUN_0079c860();
      }
      uStack_18 = 0xffffffff;
      *piVar6 = iVar5;
      (**(code **)(*unaff_EDI + 0xa8))();
      (**(code **)(*(int *)*piVar6 + 0x28))("i_d_con_2d_btn_portrait.xml");
      (**(code **)(*(int *)*piVar6 + 0x74))(iVar3 + 0x9c46);
      (**(code **)(*(int *)*piVar6 + 0x120))(&stack0xffffffbc,0,0);
      (**(code **)(*(int *)*piVar6 + 0x120))(&iStack_40,0,0);
      (**(code **)(*(int *)*piVar6 + 0x118))(&stack0xffffffac);
      iVar3 = iVar3 + 1;
      piVar6 = piVar6 + 1;
      iStack_40 = iStack_40 + -1;
    } while (iStack_40 != 0);
    iVar3 = unaff_EDI[0x1a] + 1;
    unaff_EDI[0x1a] = iVar3;
    unaff_EDI[0x1d] = (int)(float)-iVar3;
    if (unaff_EDI[0x1c] < iVar3) {
      unaff_EDI[0x1c] = iVar3;
    }
    (**(code **)(*unaff_EDI + 0x3f4))();
    iVar3 = 0;
    piVar6 = unaff_EDI + 0x17e;
    local_30 = 4;
    do {
      iStack_40 = *piVar6;
      (**(code **)(*unaff_EDI + 0xbc))();
      *piVar6 = 0;
      pvVar2 = operator_new(0x4cc);
      puStack_8 = (undefined1 *)0x6;
      iVar5 = 0;
      if (pvVar2 != (void *)0x0) {
        iVar5 = FUN_0079c860();
      }
      puStack_8 = (undefined1 *)0xffffffff;
      *piVar6 = iVar5;
      (**(code **)(*unaff_EDI + 0xa8))();
      (**(code **)(*(int *)*piVar6 + 0x28))();
      (**(code **)(*(int *)*piVar6 + 0x74))();
      (**(code **)(*(int *)*piVar6 + 0x120))(auStack_24);
      iVar5 = (**(code **)(*(int *)*piVar6 + 0x120))(&iStack_40,0,0);
      iStack_40 = (int)((float)DAT_00d1e81c *
                        (float)(*(int *)(iVar5 + 4) + (unaff_EDI[0x165] + unaff_EDI[0x167]) * iVar3
                               + unaff_EDI[0x163]) * DAT_00aaa678);
      (**(code **)(*(int *)*piVar6 + 0x118))(&stack0xffffffbc);
      (**(code **)(*(int *)*piVar6 + 0xcc))(0);
      iVar3 = iVar3 + 1;
      piVar6 = piVar6 + 1;
      local_30 = local_30 + -1;
      *(undefined1 *)(unaff_EDI + 0x14f) = 0;
    } while (local_30 != 0);
  }
  ExceptionList = local_c;
  return;
}
```

## Open questions

- Confirm calling convention and full signature against callers.
- Recover meaningful types for still-generic parameters.
