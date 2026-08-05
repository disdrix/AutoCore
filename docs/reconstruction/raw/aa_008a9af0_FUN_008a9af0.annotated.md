# Annotated low-level: FUN_008a9af0

| Field | Value |
|---|---|
| Stable ID | `aa_008a9af0` |
| VA | `0x008a9af0` |
| System | unknown |
| Date | 2026-07-23 |

## Machine-level notes

- Source: raw capture for `aa_008a9af0`.
- Prefer assembly when decompiler conflicts.
- Recover types for still-generic parameters via callers/xrefs.
- Map DAT_* globals and FUN_* callees in follow-up waves.

## Pseudocode (annotated copy of raw)

```c
void __fastcall FUN_008a9af0(int *param_1)

{
  void *pvVar1;
  int iVar2;
  int *piVar3;
  undefined4 uVar4;
  undefined4 *puVar5;
  undefined4 uVar6;
  undefined4 uStack_48;
  undefined4 uStack_44;
  undefined4 uStack_40;
  char *pcStack_3c;
  void *pvStack_c;
  undefined1 *puStack_8;
  undefined4 local_4;
  
  local_4 = 0xffffffff;
  puStack_8 = &LAB_009b639c;
  pvStack_c = ExceptionList;
  ExceptionList = &pvStack_c;
  FUN_00792600();
  pvVar1 = operator_new(0x488);
  local_4 = 0;
  if (pvVar1 == (void *)0x0) {
    iVar2 = 0;
  }
  else {
    iVar2 = FUN_007b5dd0();
  }
  local_4 = 0xffffffff;
  param_1[0x19f] = iVar2;
  (**(code **)(*param_1 + 0xa8))();
  (**(code **)(*(int *)param_1[0x19f] + 0x28))();
  (**(code **)(*(int *)param_1[0x19f] + 0xfc))();
  pcStack_3c = (char *)0x8a9b81;
  pcStack_3c = operator_new(0x488);
  if (pcStack_3c == (void *)0x0) {
    iVar2 = 0;
  }
  else {
    uStack_40 = 0x8a9b9c;
    iVar2 = FUN_007b5dd0();
  }
  param_1[0x1a2] = iVar2;
  pcStack_3c = (char *)0x8a9bb5;
  (**(code **)(*param_1 + 0xa8))();
  pcStack_3c = "i_d_obj_exp_wnd_text.xml";
  uStack_40 = 0x8a9bc5;
  (**(code **)(*(int *)param_1[0x1a2] + 0x28))();
  uStack_40 = 0x3f000000;
  uStack_44 = 1;
  uStack_48 = 0x8a9bda;
  (**(code **)(*(int *)param_1[0x1a2] + 0xfc))();
  uStack_48 = 1;
  (**(code **)(*(int *)param_1[0x1a2] + 0x1d8))("No Objective",1);
  uVar6 = 1;
  puVar5 = &uStack_48;
  piVar3 = (int *)(**(code **)(*(int *)param_1[0x1a2] + 0x120))(puVar5,1,0);
  param_1[399] = *piVar3;
  param_1[400] = piVar3[1];
  pvVar1 = operator_new(0x488);
  pcStack_3c = (char *)0x2;
  if (pvVar1 == (void *)0x0) {
    iVar2 = 0;
  }
  else {
    iVar2 = FUN_007b5dd0(pvVar1,0);
  }
  pcStack_3c = (char *)0xffffffff;
  param_1[0x1a5] = iVar2;
  (**(code **)(*param_1 + 0xa8))(iVar2,puVar5,uVar6,pvVar1);
  (**(code **)(*(int *)param_1[0x1a5] + 0x28))("i_d_obj_exp_wnd_distance.xml");
  (**(code **)(*(int *)param_1[0x1a5] + 0xfc))(1,0x3f000000);
  uVar6 = 0;
  (**(code **)(*(int *)param_1[0x1a5] + 0x1d8))(0,1,1);
  iVar2 = param_1[0x1a] + 1;
  param_1[0x1a] = iVar2;
  param_1[0x1d] = (int)(float)-iVar2;
  if (param_1[0x1c] < iVar2) {
    param_1[0x1c] = iVar2;
  }
  uVar4 = 1;
  (**(code **)(*param_1 + 0x3f4))(1);
  pvVar1 = operator_new(0x4fc);
  if (pvVar1 == (void *)0x0) {
    iVar2 = 0;
  }
  else {
    iVar2 = FUN_0078caf0(pvVar1,0,1);
  }
  param_1[0x1a4] = iVar2;
  (**(code **)(*param_1 + 0xa8))(iVar2,uVar4,uVar6,pvVar1);
  (**(code **)(*(int *)param_1[0x1a4] + 0x28))("i_d_obj_exp_wnd_arrow.xml");
  pvVar1 = operator_new(0x488);
  if (pvVar1 == (void *)0x0) {
    iVar2 = 0;
  }
  else {
    iVar2 = FUN_007b5dd0(pvVar1,0);
  }
  param_1[0x1a3] = iVar2;
  (**(code **)(*param_1 + 0xa8))(iVar2);
  (**(code **)(*(int *)param_1[0x1a3] + 0x28))("i_d_obj_exp_wnd_context.xml");
  (**(code **)(*(int *)param_1[0x1a3] + 0xcc))(0);
  uVar6 = DAT_00aaa8e0;
  iVar2 = param_1[0x1a4];
  if (iVar2 != 0) {
    *(undefined4 *)(iVar2 + 0x490) = 0;
    uVar4 = DAT_00a0f698;
    *(undefined4 *)(iVar2 + 0x494) = uVar6;
    *(undefined4 *)(iVar2 + 0x498) = uVar4;
    FUN_0078be40();
    pvVar1 = (void *)g_flOne;
    iVar2 = param_1[0x1a4];
    *(float *)(iVar2 + 0x4b8) = g_flOne;
    *(void **)(iVar2 + 0x4bc) = pvVar1;
    *(void **)(iVar2 + 0x4c0) = pvVar1;
    *(void **)(iVar2 + 0x4c4) = pvVar1;
  }
  if ((int *)param_1[0x1a4] != (int *)0x0) {
    iVar2 = (**(code **)(*(int *)param_1[0x1a4] + 0x290))();
    if (iVar2 != 0) {
      (**(code **)(*(int *)param_1[0x1a4] + 0x290))();
      FUN_0096f840("MatDiffuse",param_1 + 0x1ab);
      (**(code **)(*(int *)param_1[0x1a4] + 0x290))();
      FUN_0096f840("MatAmbient",param_1 + 0x1a7);
      (**(code **)(*(int *)param_1[0x1a4] + 0x290))();
      FUN_0096f840("MatEmissive",param_1 + 0x1af);
    }
  }
  (**(code **)(*param_1 + 0x448))();
  (**(code **)(*param_1 + 0x450))(1);
  (**(code **)(*param_1 + 0x34c))();
  ExceptionList = pvVar1;
  return;
}
```

## Open questions

- Confirm calling convention and full signature against callers.
- Recover meaningful types for still-generic parameters.
