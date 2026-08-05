# Raw capture: FUN_008f7cf0

| Field | Value |
|---|---|
| **Stable ID** | `aa_008f7cf0` |
| **Module** | `autoassault.exe` |
| **Image base** | `0x400000` |
| **VA** | `0x008f7cf0` |
| **Canonical name** | `FUN_008f7cf0` |
| **System** | unknown |
| **Capture timestamp** | `2026-07-23` |
| **Tool** | Ghidra MCP `batch_decompile` |
| **Integrity** | Do not overwrite this raw body; append versioned sections only |

---

## Raw pseudocode (authoritative decompile)

```c
void FUN_008f7cf0(int *param_1,int param_2,char param_3,char param_4,char param_5,char param_6)

{
  int *piVar1;
  undefined4 uVar2;
  char *pcVar3;
  int iVar4;
  int *piVar5;
  int unaff_EDI;
  undefined4 *puVar6;
  char *pcVar7;
  bool bVar8;
  int iVar9;
  undefined4 uVar10;
  int iStack_13c;
  void *local_138;
  int iStack_134;
  int local_130;
  int *local_12c;
  int iStack_128;
  undefined4 local_124;
  char local_120;
  undefined4 local_11f;
  void *pvStack_1c;
  void *local_14;
  undefined1 *puStack_10;
  int *local_c;
  
  local_c = (int *)0xffffffff;
  puStack_10 = &LAB_009b792d;
  local_14 = ExceptionList;
  piVar1 = (int *)param_1[param_2 + 0x3a2];
  piVar5 = param_1 + (param_2 + 0x52) * 4;
  local_12c = piVar5;
  if (param_1[(param_2 + 0x52) * 4 + 3] == 0) {
    if (piVar1 == (int *)0x0) {
      return;
    }
    if (piVar1[0x14c] == 0) {
      return;
    }
    ExceptionList = &local_14;
    (**(code **)(*(int *)piVar1[0x14c] + 0x1d8))(0,1,1);
    (**(code **)(*(int *)piVar1[0x14c] + 0x34c))();
    ExceptionList = local_14;
    return;
  }
  local_124 = *(undefined4 *)(&DAT_00d1e4a0 + param_1[(param_2 + 0x52) * 4 + 3] * 4);
  local_130 = 0;
  if (piVar1 == (int *)0x0) {
    ExceptionList = &local_14;
    local_138 = operator_new(0x53c);
    if (local_138 != (void *)0x0) {
      local_c = piVar1;
      piVar1 = (int *)FUN_008678c0(local_138);
    }
    local_c = (int *)0xffffffff;
    (**(code **)(*param_1 + 0xa8))(piVar1);
    (**(code **)(*piVar1 + 0x28))("i_d_chatlog_2d_wnd_chat.xml");
    (**(code **)(*piVar1 + 0x43c))();
    param_1[param_2 + 0x3a2] = (int)piVar1;
    piVar5 = local_12c;
  }
  else {
    ExceptionList = &local_14;
    if (param_6 == '\0') {
      ExceptionList = &local_14;
      iVar4 = (**(code **)(*piVar1 + 0x140))(&local_138,1);
      local_130 = *(int *)(iVar4 + 4);
    }
  }
  if (piVar1[0x14c] != 0) {
    local_120 = '\0';
    puVar6 = &local_11f;
    for (iVar4 = 0x40; iVar4 != 0; iVar4 = iVar4 + -1) {
      *puVar6 = 0;
      puVar6 = puVar6 + 1;
    }
    *(undefined2 *)puVar6 = 0;
    *(undefined1 *)((int)puVar6 + 2) = 0;
    local_138 = (void *)FUN_007a69d0();
    pcVar3 = (char *)piVar5[1];
    if ((pcVar3 != (char *)0x0) && (*pcVar3 != '\0')) {
      iStack_128 = piVar5[3];
      uVar2 = FUN_007a6de0(pcVar3,0xffffffff);
      uVar10 = 0xffffffff;
      uVar2 = FUN_008f6030(0xffffffff,uVar2);
      pcVar3 = (char *)FUN_007a6de0(uVar2,uVar10);
      sprintf(&local_120,pcVar3);
    }
    (**(code **)(*(int *)piVar1[0x14c] + 0x1d8))(0,1,1);
    iVar4 = local_130;
    (**(code **)(*(int *)piVar1[0x14c] + 0x224))(&local_12c,local_130);
    iStack_13c = iVar4;
    (**(code **)(*(int *)piVar1[0x14c] + 0x15c))(1,&iStack_13c);
    iVar4 = 9;
    bVar8 = true;
    pcVar3 = (char *)piVar5[1];
    pcVar7 = "NetDevil";
    do {
      if (iVar4 == 0) break;
      iVar4 = iVar4 + -1;
      bVar8 = *pcVar3 == *pcVar7;
      pcVar3 = pcVar3 + 1;
      pcVar7 = pcVar7 + 1;
    } while (bVar8);
    if (bVar8) {
      iVar4 = *(int *)piVar1[0x14c];
      uVar2 = FUN_007a6de0(*(undefined4 *)(unaff_EDI + 8),0xffffffff);
      (**(code **)(iVar4 + 0x278))(uVar2);
    }
    else {
      (**(code **)(*(int *)piVar1[0x14c] + 0x278))(*(undefined4 *)(unaff_EDI + 8));
    }
  }
  if ((int *)piVar1[0x14e] != (int *)0x0) {
    (**(code **)(*(int *)piVar1[0x14e] + 0x160))(0,local_124);
  }
  local_138 = (void *)(param_1[0x43a] - param_1[0x438]);
  iStack_134 = param_1[0x43b] - param_1[0x439];
  (**(code **)(*piVar1 + 300))(&local_138);
  (**(code **)(*piVar1 + 0x13c))();
  (**(code **)(*piVar1 + 0x34c))();
  iVar4 = local_130;
  if (param_3 != '\0') {
    iVar9 = DAT_00aaa668;
    if (*(int *)(param_1[0xac] + 0x50c) == 1) {
      iVar9 = 0;
      *(undefined1 *)(piVar1 + 0x147) = 1;
      if (0.0 < (float)piVar1[0x143] || (float)piVar1[0x143] == 0.0) goto LAB_008f7f6c;
    }
    piVar1[0x143] = iVar9;
  }
LAB_008f7f6c:
  if (param_4 != '\0') {
    if ((local_130 == 0) ||
       (param_1[0x43b] - param_1[0x439] < (param_1[0x43c] - local_130) - param_1[0x43d])) {
      iVar9 = (**(code **)(*piVar1 + 0x140))(&local_138,1);
      if (param_1[0x43d] <= *(int *)(iVar9 + 4)) goto LAB_008f7fe6;
      iVar9 = (**(code **)(*piVar1 + 0x140))(&local_138,1);
      iVar9 = *(int *)(iVar9 + 4);
    }
    else {
      iVar9 = (**(code **)(*piVar1 + 0x140))(&local_138,1);
      iVar9 = *(int *)(iVar9 + 4) - iVar4;
    }
    param_1[0x43d] = param_1[0x43d] + iVar9;
  }
LAB_008f7fe6:
  if (param_5 == '\0') {
    ExceptionList = local_14;
    return;
  }
  iVar9 = (**(code **)(*piVar1 + 0x140))(&local_138,1);
  param_1[0x43c] = param_1[0x43c] + (*(int *)(iVar9 + 4) - iVar4);
  ExceptionList = pvStack_1c;
  return;
}
```
