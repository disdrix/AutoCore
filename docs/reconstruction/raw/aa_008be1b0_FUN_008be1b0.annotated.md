# Annotated low-level: FUN_008be1b0

| Field | Value |
|---|---|
| Stable ID | `aa_008be1b0` |
| VA | `0x008be1b0` |
| System | unknown |
| Date | 2026-07-23 |

## Machine-level notes

- Source: raw capture for `aa_008be1b0`.
- Prefer assembly when decompiler conflicts.
- Recover types for still-generic parameters via callers/xrefs.
- Map DAT_* globals and FUN_* callees in follow-up waves.

## Pseudocode (annotated copy of raw)

```c
void __fastcall FUN_008be1b0(int *param_1)

{
  void *pvVar1;
  int iVar2;
  int *piVar3;
  int iVar4;
  undefined4 *puVar5;
  undefined4 uStack_1b0;
  undefined4 *puStack_1ac;
  undefined4 uStack_1a8;
  undefined4 uStack_1a4;
  undefined1 *puStack_1a0;
  int *piStack_19c;
  undefined4 uStack_198;
  undefined4 uStack_194;
  char **ppcStack_190;
  int iStack_18c;
  undefined4 uStack_188;
  char **ppcStack_184;
  undefined4 *puStack_180;
  undefined4 uStack_17c;
  undefined4 uStack_178;
  undefined1 *puStack_174;
  undefined4 uStack_170;
  undefined4 uStack_16c;
  char *pcStack_168;
  char *pcStack_160;
  char *pcStack_158;
  int iStack_128;
  char *pcStack_124;
  undefined4 uStack_11c;
  undefined4 uStack_118;
  undefined4 uStack_114;
  undefined4 *puStack_110;
  char *pcStack_10c;
  void *pvStack_108;
  undefined4 uStack_104;
  undefined4 uStack_100;
  undefined4 *puStack_fc;
  int *piStack_f8;
  undefined4 uStack_f4;
  undefined4 uStack_f0;
  undefined4 uStack_ec;
  char *pcStack_e8;
  undefined4 uStack_d8;
  char *pcStack_d4;
  void *pvStack_a0;
  void *pvStack_14;
  undefined1 *puStack_10;
  undefined4 local_c;
  
  local_c = 0xffffffff;
  puStack_10 = &LAB_009b9d35;
  pvStack_14 = ExceptionList;
  ExceptionList = &pvStack_14;
  FUN_00792600();
  FUN_00410420();
  pvVar1 = operator_new(0x488);
  local_c = 0;
  if (pvVar1 == (void *)0x0) {
    iVar2 = 0;
  }
  else {
    iVar2 = FUN_007b5dd0();
  }
  local_c = 0xffffffff;
  param_1[0x14e] = iVar2;
  (**(code **)(*param_1 + 0xa8))();
  (**(code **)(*(int *)param_1[0x14e] + 0x28))();
  pvVar1 = operator_new(0x488);
  pvStack_14 = (void *)0x1;
  if (pvVar1 == (void *)0x0) {
    iVar2 = 0;
  }
  else {
    iVar2 = FUN_007b5dd0();
  }
  pvStack_14 = (void *)0xffffffff;
  param_1[0x14f] = iVar2;
  (**(code **)(*param_1 + 0xa8))();
  (**(code **)(*(int *)param_1[0x14f] + 0x28))();
  iVar2 = param_1[0x1a] + 1;
  param_1[0x1a] = iVar2;
  param_1[0x1d] = (int)(float)-iVar2;
  if (param_1[0x1c] < iVar2) {
    param_1[0x1c] = iVar2;
  }
  (**(code **)(*param_1 + 0x3f4))();
  pvVar1 = operator_new(0x488);
  if (pvVar1 == (void *)0x0) {
    iVar2 = 0;
  }
  else {
    iVar2 = FUN_007b5dd0();
  }
  param_1[0x150] = iVar2;
  (**(code **)(*param_1 + 0xa8))();
  (**(code **)(*(int *)param_1[0x150] + 0x28))();
  param_1[0x147] = *(int *)(param_1[0x150] + 0x170);
  param_1[0x148] = *(int *)(param_1[0x150] + 0x174);
  param_1[0x144] = -1;
  param_1[0x145] = -1;
  pcStack_d4 = (char *)0x8be341;
  pcStack_d4 = operator_new(0x488);
  if (pcStack_d4 == (void *)0x0) {
    iVar2 = 0;
  }
  else {
    uStack_d8 = 0x8be35e;
    iVar2 = FUN_007b5dd0();
  }
  param_1[0x14d] = iVar2;
  pcStack_d4 = (char *)0x8be37a;
  (**(code **)(*param_1 + 0xa8))();
  pcStack_d4 = "i_d_invmis_2d_wnd_title.xml";
  uStack_d8 = 0x8be38a;
  (**(code **)(*(int *)param_1[0x14d] + 0x28))();
  uStack_d8 = 0x3f000000;
  (**(code **)(*(int *)param_1[0x14d] + 0xfc))();
  iVar2 = param_1[0x1a] + 1;
  param_1[0x1a] = iVar2;
  param_1[0x1d] = (int)(float)-iVar2;
  if (param_1[0x1c] < iVar2) {
    param_1[0x1c] = iVar2;
  }
  (**(code **)(*param_1 + 0x3f4))();
  pcStack_e8 = (char *)0x8be3d3;
  pcStack_e8 = operator_new(0x488);
  if (pcStack_e8 == (void *)0x0) {
    piVar3 = (int *)0x0;
  }
  else {
    uStack_ec = 0x8be3f0;
    piVar3 = (int *)FUN_007b5dd0();
  }
  param_1[0x14a] = (int)piVar3;
  pcStack_e8 = (char *)0x8be40c;
  (**(code **)(*param_1 + 0xa8))();
  pcStack_e8 = "i_d_invmis_2d_wnd_icon.xml";
  uStack_ec = 0x8be41c;
  (**(code **)(*(int *)param_1[0x14a] + 0x28))();
  uStack_ec = 0x3f000000;
  uStack_f0 = 1;
  uStack_f4 = 0x8be431;
  (**(code **)(*(int *)param_1[0x14a] + 0xfc))();
  uStack_f4 = 0xffffffff;
  piStack_f8 = (int *)0xa459d0;
  puStack_fc = &uStack_d8;
  uStack_d8 = 0;
  uStack_100 = 0x8be44a;
  (**(code **)(*param_1 + 0x404))();
  uStack_100 = 0x3f000000;
  uStack_104 = 1;
  pvStack_108 = (void *)0x8be45d;
  (**(code **)(*piVar3 + 0xfc))();
  pvStack_108 = (void *)0xffffffff;
  pcStack_10c = "i_d_invmis_2d_wnd_title_cover.xml";
  puStack_110 = &uStack_ec;
  uStack_114 = 0x8be472;
  (**(code **)(*param_1 + 0x404))();
  uStack_114 = 0x3f000000;
  uStack_118 = 1;
  uStack_11c = 0x8be485;
  (**(code **)(*piStack_f8 + 0xfc))();
  iVar2 = param_1[0x1a] + 1;
  param_1[0x1a] = iVar2;
  param_1[0x1d] = (int)(float)-iVar2;
  if (param_1[0x1c] < iVar2) {
    param_1[0x1c] = iVar2;
  }
  uStack_11c = 1;
  (**(code **)(*param_1 + 0x3f4))();
  pcStack_124 = (char *)0x8be4b9;
  pvStack_108 = operator_new(0x954);
  if (pvStack_108 == (void *)0x0) {
    iVar2 = 0;
  }
  else {
    iVar2 = FUN_0078f890();
  }
  param_1[0x151] = iVar2;
  pcStack_124 = (char *)0x8be4f2;
  (**(code **)(*param_1 + 0xa8))();
  pcStack_124 = "i_d_invmis_2d_sb_inv.xml";
  iStack_128 = 0x8be502;
  (**(code **)(*(int *)param_1[0x151] + 0x28))();
  iStack_128 = 0x9c42;
  (**(code **)(*(int *)param_1[0x151] + 0x74))();
  (**(code **)(*(int *)param_1[0x151] + 0x43c))();
  (**(code **)(*(int *)param_1[0x151] + 0x468))();
  (**(code **)(*(int *)param_1[0x151] + 0x454))();
  (**(code **)(*(int *)param_1[0x151] + 0x460))();
  (**(code **)(*(int *)param_1[0x151] + 0xd4))();
  iStack_128 = 0;
  piVar3 = param_1 + 0x157;
  do {
    iVar2 = iStack_128;
    pvVar1 = operator_new(0x488);
    if (pvVar1 == (void *)0x0) {
      iVar4 = 0;
    }
    else {
      iVar4 = FUN_007b5dd0();
    }
    *piVar3 = iVar4;
    (**(code **)(*param_1 + 0xa8))();
    (**(code **)(*(int *)*piVar3 + 0x28))();
    (**(code **)(*(int *)*piVar3 + 0x74))();
    pvVar1 = operator_new(0x488);
    if (pvVar1 == (void *)0x0) {
      iVar4 = 0;
    }
    else {
      iVar4 = FUN_007b5dd0();
    }
    piVar3[4] = iVar4;
    (**(code **)(*param_1 + 0xa8))();
    (**(code **)(*(int *)piVar3[4] + 0x28))();
    pcStack_158 = (char *)0x8be627;
    pcStack_158 = operator_new(0x488);
    if (pcStack_158 == (char *)0x0) {
      iVar4 = 0;
    }
    else {
      iVar4 = FUN_007b5dd0();
    }
    piVar3[8] = iVar4;
    pcStack_158 = (char *)0x8be65e;
    (**(code **)(*param_1 + 0xa8))();
    pcStack_158 = "i_d_invmis_2d_wnd_item_name.xml";
    (**(code **)(*(int *)piVar3[8] + 0x28))();
    pcStack_160 = (char *)0x8be675;
    pcStack_160 = operator_new(0x488);
    if (pcStack_160 == (char *)0x0) {
      iVar4 = 0;
    }
    else {
      iVar4 = FUN_007b5dd0();
    }
    piVar3[0xc] = iVar4;
    pcStack_160 = (char *)0x8be6ac;
    (**(code **)(*param_1 + 0xa8))();
    pcStack_160 = "i_d_invmis_2d_wnd_item_icon_bg.xml";
    (**(code **)(*(int *)piVar3[0xc] + 0x28))();
    pcStack_168 = (char *)0x8be6c3;
    pcStack_168 = operator_new(0x488);
    if (pcStack_168 == (void *)0x0) {
      iVar4 = 0;
    }
    else {
      uStack_16c = 0x8be6e1;
      iVar4 = FUN_007b5dd0();
    }
    piVar3[0x10] = iVar4;
    pcStack_168 = (char *)0x8be6fa;
    (**(code **)(*param_1 + 0xa8))();
    pcStack_168 = "i_d_invmis_2d_wnd_item_icon.xml";
    uStack_16c = 0x8be707;
    (**(code **)(*(int *)piVar3[0x10] + 0x28))();
    uStack_16c = 0;
    uStack_170 = 1;
    puStack_174 = &stack0xfffffee0;
    iVar2 = (int)((float)DAT_00d1e81c * DAT_00aaac1c) * iVar2;
    uStack_178 = 0x8be731;
    (**(code **)(*(int *)*piVar3 + 0x120))();
    uStack_178 = 0;
    uStack_17c = 1;
    puStack_180 = &uStack_11c;
    ppcStack_184 = (char **)0x8be749;
    puVar5 = (undefined4 *)(**(code **)(*(int *)*piVar3 + 0x120))();
    pcStack_160 = (char *)*puVar5;
    ppcStack_184 = &pcStack_160;
    uStack_188 = 0x8be762;
    (**(code **)(*(int *)*piVar3 + 0x110))();
    uStack_188 = 0;
    iStack_18c = 1;
    ppcStack_190 = &pcStack_10c;
    uStack_194 = 0x8be779;
    iVar4 = (**(code **)(*(int *)piVar3[4] + 0x120))();
    iVar4 = *(int *)(iVar4 + 4);
    uStack_194 = 0;
    uStack_198 = 1;
    piStack_19c = &iStack_128;
    puStack_1a0 = (undefined1 *)0x8be792;
    (**(code **)(*(int *)piVar3[4] + 0x120))();
    puStack_1a0 = &stack0xfffffe9c;
    uStack_1a4 = 0x8be7ac;
    pcStack_160 = (char *)(iVar4 + iVar2);
    (**(code **)(*(int *)piVar3[4] + 0x110))();
    uStack_1a4 = 0;
    uStack_1a8 = 1;
    puStack_1ac = &uStack_118;
    uStack_1b0 = 0x8be7c3;
    iVar4 = (**(code **)(*(int *)piVar3[8] + 0x120))();
    iVar4 = *(int *)(iVar4 + 4);
    uStack_1b0 = 0;
    puVar5 = (undefined4 *)(**(code **)(*(int *)piVar3[8] + 0x120))(&stack0xfffffea4,1);
    ppcStack_190 = (char **)*puVar5;
    iStack_18c = iVar4 + iVar2;
    (**(code **)(*(int *)piVar3[8] + 0x110))(&ppcStack_190);
    iVar4 = (**(code **)(*(int *)piVar3[0xc] + 0x120))(&stack0xfffffea4,1,0);
    iVar4 = *(int *)(iVar4 + 4);
    puVar5 = (undefined4 *)(**(code **)(*(int *)piVar3[0xc] + 0x120))(&pcStack_158,1,0);
    uStack_1a4 = *puVar5;
    puStack_1a0 = (undefined1 *)(iVar4 + iVar2);
    (**(code **)(*(int *)piVar3[0xc] + 0x110))(&uStack_1a4);
    iVar4 = (**(code **)(*(int *)piVar3[0x10] + 0x120))(&pcStack_158,1,0);
    iVar4 = *(int *)(iVar4 + 4);
    puVar5 = (undefined4 *)(**(code **)(*(int *)piVar3[0x10] + 0x120))(&stack0xfffffeac,1,0);
    uStack_1b0 = *puVar5;
    puStack_1ac = (undefined4 *)(iVar4 + iVar2);
    (**(code **)(*(int *)piVar3[0x10] + 0x110))(&uStack_1b0);
    iStack_128 = iStack_128 + 1;
    piVar3 = piVar3 + 1;
  } while (iStack_128 < 4);
  if ((DAT_00d1b644 != 0) && (*(char *)(DAT_00d1b644 + 0xf6) != '\0')) {
    (**(code **)(*param_1 + 0x404))();
  }
  FUN_008bdb10();
  (**(code **)(*param_1 + 0x448))();
  (**(code **)(*param_1 + 0x34c))();
  ExceptionList = pvStack_a0;
  return;
}
```

## Open questions

- Confirm calling convention and full signature against callers.
- Recover meaningful types for still-generic parameters.
