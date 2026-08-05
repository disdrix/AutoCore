# Raw capture: FUN_008fbca0

| Field | Value |
|---|---|
| **Stable ID** | `aa_008fbca0` |
| **Module** | `autoassault.exe` |
| **Image base** | `0x400000` |
| **VA** | `0x008fbca0` |
| **Canonical name** | `FUN_008fbca0` |
| **System** | unknown |
| **Capture timestamp** | `2026-07-23` |
| **Tool** | Ghidra MCP `batch_decompile` |
| **Integrity** | Do not overwrite this raw body; append versioned sections only |

---

## Raw pseudocode (authoritative decompile)

```c
void __fastcall FUN_008fbca0(int *param_1)

{
  void *pvVar1;
  int iVar2;
  int *piVar3;
  int iVar4;
  int *piVar5;
  char *pcStack_1e4;
  int iStack_1dc;
  void *pvStack_1d8;
  char *pcStack_1d4;
  void *pvStack_d0;
  void *pvStack_c;
  undefined1 *puStack_8;
  undefined4 local_4;
  
  local_4 = 0xffffffff;
  puStack_8 = &LAB_009b7b0d;
  pvStack_c = ExceptionList;
  ExceptionList = &pvStack_c;
  FUN_00792600();
  pvVar1 = operator_new(0x488);
  piVar5 = (int *)0x0;
  local_4 = 0;
  if (pvVar1 != (void *)0x0) {
    piVar5 = (int *)FUN_007b5dd0();
  }
  local_4 = 0xffffffff;
  (**(code **)(*param_1 + 0xa8))();
  (**(code **)(*piVar5 + 0x28))();
  iVar4 = 1;
  (**(code **)(*piVar5 + 0xfc))();
  iVar2 = param_1[0x1a] + 1;
  param_1[0x143] = (int)piVar5;
  param_1[0x1a] = iVar2;
  param_1[0x1d] = (int)(float)-iVar2;
  if (param_1[0x1c] < iVar2) {
    param_1[0x1c] = iVar2;
  }
  (**(code **)(*param_1 + 0x3f4))();
  pvVar1 = operator_new(0x4bc);
  if (pvVar1 == (void *)0x0) {
    piVar5 = (int *)0x0;
  }
  else {
    piVar5 = (int *)FUN_00864f20();
  }
  (**(code **)(*param_1 + 0xa8))();
  (**(code **)(*piVar5 + 0x28))();
  (**(code **)(*piVar5 + 0xfc))();
  iVar2 = param_1[0x1a] + 1;
  param_1[0x145] = (int)piVar5;
  param_1[0x1a] = iVar2;
  param_1[0x1d] = (int)(float)-iVar2;
  if (param_1[0x1c] < iVar2) {
    param_1[0x1c] = iVar2;
  }
  (**(code **)(*param_1 + 0x3f4))();
  pvVar1 = operator_new(0x488);
  if (pvVar1 == (void *)0x0) {
    piVar5 = (int *)0x0;
  }
  else {
    piVar5 = (int *)FUN_007b5dd0();
  }
  (**(code **)(*param_1 + 0xa8))();
  (**(code **)(*piVar5 + 0x28))();
  (**(code **)(*piVar5 + 0xfc))();
  iVar2 = param_1[0x1a] + 1;
  param_1[0x144] = (int)piVar5;
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
  param_1[0x146] = iVar2;
  (**(code **)(*param_1 + 0xa8))();
  (**(code **)(*(int *)param_1[0x146] + 0x28))();
  (**(code **)(*(int *)param_1[0x146] + 0xfc))();
  iVar2 = param_1[0x1a] + 1;
  param_1[0x1a] = iVar2;
  param_1[0x1d] = (int)(float)-iVar2;
  if (param_1[0x1c] < iVar2) {
    param_1[0x1c] = iVar2;
  }
  (**(code **)(*param_1 + 0x3f4))();
  pvVar1 = operator_new(0x4cc);
  if (pvVar1 == (void *)0x0) {
    piVar5 = (int *)0x0;
  }
  else {
    piVar5 = (int *)FUN_0079c860();
  }
  (**(code **)(*param_1 + 0xa8))();
  (**(code **)(*piVar5 + 0x28))();
  (**(code **)(*piVar5 + 0x74))();
  (**(code **)(*piVar5 + 0xfc))();
  iVar2 = param_1[0x1a] + 1;
  param_1[0x141] = (int)piVar5;
  param_1[0x127] = 40000;
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
  param_1[0x147] = iVar2;
  (**(code **)(*param_1 + 0xa8))();
  (**(code **)(*(int *)param_1[0x147] + 0x28))();
  (**(code **)(*(int *)param_1[0x147] + 0xfc))();
  iVar2 = param_1[0x1a] + 1;
  param_1[0x1a] = iVar2;
  param_1[0x1d] = (int)(float)-iVar2;
  if (param_1[0x1c] < iVar2) {
    param_1[0x1c] = iVar2;
  }
  (**(code **)(*param_1 + 0x3f4))();
  pvVar1 = operator_new(0x4a4);
  if (pvVar1 == (void *)0x0) {
    piVar5 = (int *)0x0;
  }
  else {
    piVar5 = (int *)FUN_00795f20();
  }
  (**(code **)(*param_1 + 0xa8))();
  (**(code **)(*piVar5 + 0x28))();
  (**(code **)(*piVar5 + 0x74))();
  (**(code **)(*piVar5 + 0x1d0))();
  (**(code **)(*piVar5 + 0x98))();
  *(undefined1 *)((int)piVar5 + 0x48d) = 0;
  (**(code **)(*piVar5 + 0x1c4))();
  *(undefined1 *)((int)piVar5 + 0xba) = 1;
  iVar2 = param_1[0x1a] + 1;
  param_1[0x148] = (int)piVar5;
  param_1[0x1a] = iVar2;
  param_1[0x1d] = (int)(float)-iVar2;
  if (param_1[0x1c] < iVar2) {
    param_1[0x1c] = iVar2;
  }
  (**(code **)(*param_1 + 0x3f4))();
  pvVar1 = operator_new(0x4cc);
  if (pvVar1 == (void *)0x0) {
    piVar5 = (int *)0x0;
  }
  else {
    piVar5 = (int *)FUN_0079c860();
  }
  (**(code **)(*param_1 + 0xa8))();
  (**(code **)(*piVar5 + 0x28))();
  (**(code **)(*piVar5 + 0x74))();
  param_1[0x149] = (int)piVar5;
  pcStack_1d4 = (char *)0x8fc144;
  pcStack_1d4 = operator_new(0x488);
  if (pcStack_1d4 == (void *)0x0) {
    piVar5 = (int *)0x0;
  }
  else {
    pvStack_1d8 = (void *)0x8fc162;
    piVar5 = (int *)FUN_007b5dd0();
  }
  pcStack_1d4 = (char *)0x8fc17a;
  (**(code **)(*param_1 + 0xa8))();
  pcStack_1d4 = "i_d_bug_2d_wnd_title_desc.xml";
  pvStack_1d8 = (void *)0x8fc186;
  (**(code **)(*piVar5 + 0x28))();
  pvStack_1d8 = (void *)0x3f000000;
  (**(code **)(*piVar5 + 0xfc))();
  param_1[0x151] = (int)piVar5;
  pcStack_1e4 = (char *)0x8fc1a6;
  pcStack_1e4 = operator_new(0x488);
  if (pcStack_1e4 == (char *)0x0) {
    piVar5 = (int *)0x0;
  }
  else {
    piVar5 = (int *)FUN_007b5dd0();
  }
  pcStack_1e4 = (char *)0x8fc1dc;
  (**(code **)(*param_1 + 0xa8))();
  pcStack_1e4 = "i_d_bug_2d_wnd_title_type.xml";
  (**(code **)(*piVar5 + 0x28))();
  (**(code **)(*piVar5 + 0xfc))(1,0x3f000000);
  param_1[0x150] = (int)piVar5;
  piVar5 = param_1 + 0x152;
  iStack_1dc = 6;
  do {
    pvStack_1d8 = operator_new(0x4cc);
    if (pvStack_1d8 == (void *)0x0) {
      piVar3 = (int *)0x0;
    }
    else {
      piVar3 = (int *)FUN_0079c860();
    }
    (**(code **)(*param_1 + 0xa8))(piVar3);
    sprintf((char *)&pvStack_1d8,"i_d_bug_2d_btn_type_%i.xml",iVar4);
    (**(code **)(*piVar3 + 0x28))(&pvStack_1d8);
    (**(code **)(*piVar3 + 0x74))(iVar4 + 0x9c42);
    piVar5[-8] = (int)piVar3;
    pcStack_1e4 = operator_new(0x488);
    if (pcStack_1e4 == (char *)0x0) {
      piVar3 = (int *)0x0;
    }
    else {
      piVar3 = (int *)FUN_007b5dd0(pcStack_1e4,0);
    }
    (**(code **)(*param_1 + 0xa8))(piVar3);
    sprintf((char *)&pcStack_1e4,"i_d_bug_2d_wnd_type_%i.xml",iVar4);
    (**(code **)(*piVar3 + 0x28))(&pcStack_1e4);
    (**(code **)(*piVar3 + 0xfc))(1,0x3f000000);
    (**(code **)(*piVar3 + 0x74))(iVar4 + 0x9c48);
    *piVar5 = (int)piVar3;
    piVar5 = piVar5 + 1;
    iVar4 = iVar4 + 1;
    iStack_1dc = iStack_1dc + -1;
  } while (iStack_1dc != 0);
  param_1[0x199] = 3;
  FUN_008fb9d0(param_1);
  (**(code **)(*param_1 + 0x34c))();
  ExceptionList = pvStack_d0;
  return;
}
```
