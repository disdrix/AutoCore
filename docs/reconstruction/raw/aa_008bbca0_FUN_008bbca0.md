# Raw capture: FUN_008bbca0

| Field | Value |
|---|---|
| **Stable ID** | `aa_008bbca0` |
| **Module** | `autoassault.exe` |
| **Image base** | `0x400000` |
| **VA** | `0x008bbca0` |
| **Canonical name** | `FUN_008bbca0` |
| **System** | unknown |
| **Capture timestamp** | `2026-07-23` |
| **Tool** | Ghidra MCP `batch_decompile` |
| **Integrity** | Do not overwrite this raw body; append versioned sections only |

---

## Raw pseudocode (authoritative decompile)

```c
void __fastcall FUN_008bbca0(int *param_1)

{
  void *pvVar1;
  int *piVar2;
  int iVar3;
  void *pvVar4;
  undefined4 uStack_94;
  undefined4 uStack_90;
  char *pcStack_8c;
  void *pvStack_c;
  undefined1 *puStack_8;
  undefined4 local_4;
  
  local_4 = 0xffffffff;
  puStack_8 = &LAB_009b6791;
  pvStack_c = ExceptionList;
  ExceptionList = &pvStack_c;
  FUN_00792600();
  pvVar1 = operator_new(0x488);
  local_4 = 0;
  if (pvVar1 == (void *)0x0) {
    piVar2 = (int *)0x0;
  }
  else {
    piVar2 = (int *)FUN_007b5dd0();
  }
  local_4 = 0xffffffff;
  (**(code **)(*param_1 + 0xa8))();
  (**(code **)(*piVar2 + 0x28))();
  iVar3 = param_1[0x1a] + 1;
  param_1[0x159] = (int)piVar2;
  param_1[0x1a] = iVar3;
  param_1[0x1d] = (int)(float)-iVar3;
  if (param_1[0x1c] < iVar3) {
    param_1[0x1c] = iVar3;
  }
  (**(code **)(*param_1 + 0x3f4))();
  pvVar1 = operator_new(0x488);
  if (pvVar1 == (void *)0x0) {
    piVar2 = (int *)0x0;
  }
  else {
    piVar2 = (int *)FUN_007b5dd0();
  }
  (**(code **)(*param_1 + 0xa8))();
  (**(code **)(*piVar2 + 0x28))();
  (**(code **)(*piVar2 + 0xfc))();
  iVar3 = param_1[0x1a] + 1;
  param_1[0x158] = (int)piVar2;
  param_1[0x1a] = iVar3;
  param_1[0x1d] = (int)(float)-iVar3;
  if (param_1[0x1c] < iVar3) {
    param_1[0x1c] = iVar3;
  }
  (**(code **)(*param_1 + 0x3f4))();
  pvVar1 = operator_new(0x488);
  if (pvVar1 == (void *)0x0) {
    piVar2 = (int *)0x0;
  }
  else {
    piVar2 = (int *)FUN_007b5dd0();
  }
  (**(code **)(*param_1 + 0xa8))();
  (**(code **)(*piVar2 + 0x28))();
  (**(code **)(*piVar2 + 0xfc))();
  iVar3 = param_1[0x1a] + 1;
  param_1[0x157] = (int)piVar2;
  param_1[0x1a] = iVar3;
  param_1[0x1d] = (int)(float)-iVar3;
  if (param_1[0x1c] < iVar3) {
    param_1[0x1c] = iVar3;
  }
  (**(code **)(*param_1 + 0x3f4))();
  pvVar1 = operator_new(0x4f8);
  if (pvVar1 == (void *)0x0) {
    iVar3 = 0;
  }
  else {
    iVar3 = FUN_0097ffa0();
  }
  param_1[0x164] = iVar3;
  (**(code **)(*param_1 + 0xa8))();
  (**(code **)(*(int *)param_1[0x164] + 0x28))();
  (**(code **)(*(int *)param_1[0x164] + 0xfc))();
  pvVar1 = operator_new(0x488);
  if (pvVar1 == (void *)0x0) {
    piVar2 = (int *)0x0;
  }
  else {
    piVar2 = (int *)FUN_007b5dd0();
  }
  (**(code **)(*param_1 + 0xa8))();
  (**(code **)(*piVar2 + 0x28))();
  (**(code **)(*piVar2 + 0xfc))();
  param_1[0x15d] = (int)piVar2;
  pvVar1 = operator_new(0x488);
  if (pvVar1 == (void *)0x0) {
    piVar2 = (int *)0x0;
  }
  else {
    piVar2 = (int *)FUN_007b5dd0();
  }
  (**(code **)(*param_1 + 0xa8))();
  (**(code **)(*piVar2 + 0x28))();
  (**(code **)(*piVar2 + 0xfc))();
  param_1[0x15c] = (int)piVar2;
  pcStack_8c = (char *)0x8bbf6e;
  pcStack_8c = operator_new(0x488);
  if (pcStack_8c == (void *)0x0) {
    piVar2 = (int *)0x0;
  }
  else {
    uStack_90 = 0x8bbf89;
    piVar2 = (int *)FUN_007b5dd0();
  }
  pcStack_8c = (char *)0x8bbf9e;
  (**(code **)(*param_1 + 0xa8))();
  pcStack_8c = "i_d_ls_2d_wnd_preview.xml";
  uStack_90 = 0x8bbfaa;
  (**(code **)(*piVar2 + 0x28))();
  uStack_90 = 0x3f000000;
  uStack_94 = 1;
  (**(code **)(*piVar2 + 0xfc))();
  param_1[0x15b] = (int)piVar2;
  piVar2 = (int *)(**(code **)(*piVar2 + 0x120))(&stack0xffffff78,1,0);
  iVar3 = piVar2[1];
  param_1[0x14a] = *piVar2;
  param_1[0x14b] = iVar3;
  piVar2 = (int *)(**(code **)(*(int *)param_1[0x15b] + 0x140))(&uStack_94,1);
  param_1[0x148] = *piVar2;
  iVar3 = param_1[0x1a] + 1;
  param_1[0x149] = piVar2[1];
  param_1[0x1a] = iVar3;
  param_1[0x1d] = (int)(float)-iVar3;
  if (param_1[0x1c] < iVar3) {
    param_1[0x1c] = iVar3;
  }
  (**(code **)(*param_1 + 0x3f4))(1);
  pvVar1 = operator_new(0x488);
  uStack_90 = 7;
  if (pvVar1 == (void *)0x0) {
    piVar2 = (int *)0x0;
  }
  else {
    piVar2 = (int *)FUN_007b5dd0(pvVar1,0);
  }
  uStack_90 = 0xffffffff;
  (**(code **)(*param_1 + 0xa8))(piVar2);
  (**(code **)(*piVar2 + 0x28))("i_d_ls_2d_wnd_bg_texture.xml");
  (**(code **)(*piVar2 + 0xfc))(1,0x3f000000);
  iVar3 = param_1[0x1a] + 1;
  param_1[0x15a] = (int)piVar2;
  param_1[0x1a] = iVar3;
  param_1[0x1d] = (int)(float)-iVar3;
  if (param_1[0x1c] < iVar3) {
    param_1[0x1c] = iVar3;
  }
  (**(code **)(*param_1 + 0x3f4))(1);
  pvVar1 = operator_new(0x488);
  if (pvVar1 == (void *)0x0) {
    piVar2 = (int *)0x0;
  }
  else {
    piVar2 = (int *)FUN_007b5dd0(pvVar1,0);
  }
  (**(code **)(*param_1 + 0xa8))(piVar2);
  (**(code **)(*piVar2 + 0x28))("i_d_ls_2d_wnd_mapname.xml");
  (**(code **)(*piVar2 + 0xfc))(1,0x3f000000);
  param_1[0x15e] = (int)piVar2;
  pvVar1 = operator_new(0x488);
  if (pvVar1 == (void *)0x0) {
    piVar2 = (int *)0x0;
  }
  else {
    piVar2 = (int *)FUN_007b5dd0(pvVar1,0);
  }
  (**(code **)(*param_1 + 0xa8))(piVar2);
  (**(code **)(*piVar2 + 0x28))("i_d_ls_2d_wnd_mapdesc.xml");
  (**(code **)(*piVar2 + 0xfc))(1,0x3f000000);
  param_1[0x15f] = (int)piVar2;
  pvVar1 = operator_new(0x488);
  if (pvVar1 == (void *)0x0) {
    piVar2 = (int *)0x0;
  }
  else {
    piVar2 = (int *)FUN_007b5dd0(pvVar1,0);
  }
  (**(code **)(*param_1 + 0xa8))(piVar2);
  (**(code **)(*piVar2 + 0x28))("i_d_ls_2d_wnd_layername.xml");
  (**(code **)(*piVar2 + 0xfc))(1,0x3f000000);
  param_1[0x160] = (int)piVar2;
  pvVar1 = operator_new(0x488);
  if (pvVar1 == (void *)0x0) {
    piVar2 = (int *)0x0;
  }
  else {
    piVar2 = (int *)FUN_007b5dd0(pvVar1,0);
  }
  (**(code **)(*param_1 + 0xa8))(piVar2);
  (**(code **)(*piVar2 + 0x28))("i_d_ls_2d_wnd_layerdesc.xml");
  pvVar4 = (void *)0x1;
  (**(code **)(*piVar2 + 0xfc))(1,0x3f000000);
  param_1[0x161] = (int)piVar2;
  pvVar1 = operator_new(0x488);
  if (pvVar1 == (void *)0x0) {
    piVar2 = (int *)0x0;
  }
  else {
    piVar2 = (int *)FUN_007b5dd0(pvVar1,0);
  }
  (**(code **)(*param_1 + 0xa8))(piVar2);
  (**(code **)(*piVar2 + 0x28))("i_d_ls_2d_wnd_loading_msgs.xml");
  (**(code **)(*piVar2 + 0xfc))(1,0x3f000000);
  param_1[0x1a] = param_1[0x1a] + 1;
  iVar3 = param_1[0x1a];
  param_1[0x162] = (int)piVar2;
  param_1[0x1d] = (int)(float)-iVar3;
  if (param_1[0x1c] < iVar3) {
    param_1[0x1c] = iVar3;
  }
  (**(code **)(*param_1 + 0x3f4))(1);
  FUN_008bb180();
  *(undefined1 *)(param_1 + 0x144) = 0;
  (**(code **)(*param_1 + 0x448))();
  (**(code **)(*param_1 + 0x34c))();
  ExceptionList = pvVar4;
  return;
}
```
