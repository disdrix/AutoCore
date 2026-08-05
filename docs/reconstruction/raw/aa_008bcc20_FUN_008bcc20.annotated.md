# Annotated low-level: FUN_008bcc20

| Field | Value |
|---|---|
| Stable ID | `aa_008bcc20` |
| VA | `0x008bcc20` |
| System | unknown |
| Date | 2026-07-23 |

## Machine-level notes

- Source: raw capture for `aa_008bcc20`.
- Prefer assembly when decompiler conflicts.
- Recover types for still-generic parameters via callers/xrefs.
- Map DAT_* globals and FUN_* callees in follow-up waves.

## Pseudocode (annotated copy of raw)

```c
void __fastcall FUN_008bcc20(int *param_1)

{
  void *pvVar1;
  int iVar2;
  void *pvVar3;
  char *pcVar4;
  undefined4 uVar5;
  char *pcVar6;
  undefined4 uVar7;
  undefined4 uVar8;
  void *pvStack_c;
  undefined1 *puStack_8;
  undefined4 local_4;
  
  local_4 = 0xffffffff;
  puStack_8 = &LAB_009b680f;
  pvStack_c = ExceptionList;
  ExceptionList = &pvStack_c;
  FUN_00792600();
  pvVar1 = operator_new(0x4f8);
  local_4 = 0;
  if (pvVar1 == (void *)0x0) {
    iVar2 = 0;
  }
  else {
    iVar2 = FUN_0097ffa0(pvVar1);
  }
  local_4 = 0xffffffff;
  param_1[0x149] = iVar2;
  (**(code **)(*param_1 + 0xa8))(iVar2);
  (**(code **)(*(int *)param_1[0x149] + 0x28))("i_d_kb_2d_gauge_bonus.xml");
  uVar8 = 0;
  (**(code **)(*(int *)param_1[0x149] + 0x3b0))(0);
  uVar7 = 0;
  (**(code **)(*(int *)param_1[0x149] + 0xcc))(0);
  pvVar1 = operator_new(0x488);
  if (pvVar1 == (void *)0x0) {
    iVar2 = 0;
  }
  else {
    iVar2 = FUN_007b5dd0(pvVar1,0);
  }
  param_1[0x148] = iVar2;
  (**(code **)(*param_1 + 0xa8))(iVar2,uVar7,uVar8,pvVar1);
  pcVar6 = "i_d_kb_2d_wnd_frame.xml";
  (**(code **)(*(int *)param_1[0x148] + 0x28))("i_d_kb_2d_wnd_frame.xml");
  uVar5 = 0;
  (**(code **)(*(int *)param_1[0x148] + 0xcc))(0);
  pvVar1 = operator_new(0x488);
  if (pvVar1 == (void *)0x0) {
    iVar2 = 0;
  }
  else {
    iVar2 = FUN_007b5dd0(pvVar1,0);
  }
  param_1[0x146] = iVar2;
  (**(code **)(*param_1 + 0xa8))(iVar2,uVar5,pcVar6,pvVar1,uVar7,uVar8,0xffffffff);
  pcVar4 = "i_d_kb_2d_wnd_label_kill_bonus.xml";
  (**(code **)(*(int *)param_1[0x146] + 0x28))("i_d_kb_2d_wnd_label_kill_bonus.xml");
  pvVar3 = (void *)0x0;
  (**(code **)(*(int *)param_1[0x146] + 0xcc))();
  pvVar1 = operator_new(0x488);
  if (pvVar1 == (void *)0x0) {
    iVar2 = 0;
  }
  else {
    iVar2 = FUN_007b5dd0(pvVar1,0);
  }
  param_1[0x147] = iVar2;
  (**(code **)(*param_1 + 0xa8))(iVar2,pvVar3,pcVar4,pvVar1,uVar5,pcVar6,0xffffffff);
  (**(code **)(*(int *)param_1[0x147] + 0x28))("i_d_kb_2d_wnd_xp_bonus.xml");
  (**(code **)(*(int *)param_1[0x147] + 0xcc))(0);
  FUN_008bc5c0();
  (**(code **)(*param_1 + 0x34c))();
  ExceptionList = pvVar3;
  return;
}
```

## Open questions

- Confirm calling convention and full signature against callers.
- Recover meaningful types for still-generic parameters.
