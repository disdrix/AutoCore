# Annotated low-level: FUN_008ddb30

| Field | Value |
|---|---|
| Stable ID | `aa_008ddb30` |
| VA | `0x008ddb30` |
| System | unknown |
| Date | 2026-07-23 |

## Machine-level notes

- Source: raw capture for `aa_008ddb30`.
- Prefer assembly when decompiler conflicts.
- Recover types for still-generic parameters via callers/xrefs.
- Map DAT_* globals and FUN_* callees in follow-up waves.

## Pseudocode (annotated copy of raw)

```c
void __fastcall FUN_008ddb30(int *param_1)

{
  void *pvVar1;
  int iVar2;
  int iVar3;
  undefined4 uVar4;
  undefined4 uVar5;
  char *pcVar6;
  void *pvStack_c;
  undefined1 *puStack_8;
  undefined4 local_4;
  
  local_4 = 0xffffffff;
  puStack_8 = &LAB_009b39fa;
  pvStack_c = ExceptionList;
  ExceptionList = &pvStack_c;
  FUN_00792600();
  pvVar1 = operator_new(0x488);
  local_4 = 0;
  if (pvVar1 == (void *)0x0) {
    iVar2 = 0;
  }
  else {
    iVar2 = FUN_007b5dd0(pvVar1,0);
  }
  local_4 = 0xffffffff;
  param_1[0x143] = iVar2;
  (**(code **)(*param_1 + 0xa8))(iVar2);
  pcVar6 = "i_d_et_wnd_bg_texture.xml";
  (**(code **)(*(int *)param_1[0x143] + 0x28))("i_d_et_wnd_bg_texture.xml");
  uVar5 = 0x3f000000;
  (**(code **)(*(int *)param_1[0x143] + 0xfc))(1,0x3f000000);
  iVar2 = param_1[0x1a] + 1;
  param_1[0x1a] = iVar2;
  param_1[0x1d] = (int)(float)-iVar2;
  if (param_1[0x1c] < iVar2) {
    param_1[0x1c] = iVar2;
  }
  uVar4 = 1;
  (**(code **)(*param_1 + 0x3f4))(1);
  pvVar1 = operator_new(0x488);
  if (pvVar1 == (void *)0x0) {
    iVar2 = 0;
  }
  else {
    iVar2 = FUN_007b5dd0(pvVar1,0);
  }
  param_1[0x145] = iVar2;
  (**(code **)(*param_1 + 0xa8))(iVar2,uVar4,pvVar1,uVar5,pcVar6,0xffffffff);
  pcVar6 = "i_d_et_wnd_info.xml";
  (**(code **)(*(int *)param_1[0x145] + 0x28))("i_d_et_wnd_info.xml");
  uVar5 = 1;
  (**(code **)(*(int *)param_1[0x145] + 0xfc))(1,0x3f000000);
  pvVar1 = operator_new(0x488);
  if (pvVar1 == (void *)0x0) {
    iVar3 = 0;
  }
  else {
    iVar3 = FUN_007b5dd0(pvVar1,0);
  }
  param_1[0x144] = iVar3;
  (**(code **)(*param_1 + 0xa8))(iVar3,uVar5,pvVar1,pcVar6,iVar2,0xffffffff);
  (**(code **)(*(int *)param_1[0x144] + 0x28))("i_d_et_wnd_time.xml");
  (**(code **)(*(int *)param_1[0x144] + 0xfc))(1);
  param_1[0x1a] = param_1[0x1a] + 1;
  iVar2 = param_1[0x1a];
  param_1[0x1d] = (int)(float)-iVar2;
  if (param_1[0x1c] < iVar2) {
    param_1[0x1c] = iVar2;
  }
  (**(code **)(*param_1 + 0x3f4))(1);
  (**(code **)(*param_1 + 0x34c))();
  ExceptionList = (void *)0x3f000000;
  return;
}
```

## Open questions

- Confirm calling convention and full signature against callers.
- Recover meaningful types for still-generic parameters.
