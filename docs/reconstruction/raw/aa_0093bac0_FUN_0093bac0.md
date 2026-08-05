# Raw capture: FUN_0093bac0

| Field | Value |
|---|---|
| **Stable ID** | `aa_0093bac0` |
| **Module** | `autoassault.exe` |
| **Image base** | `0x400000` |
| **VA** | `0x0093bac0` |
| **Canonical name** | `FUN_0093bac0` |
| **System** | unknown |
| **Capture timestamp** | `2026-07-23` |
| **Tool** | Ghidra MCP `batch_decompile` |
| **Integrity** | Do not overwrite this raw body; append versioned sections only |

---

## Raw pseudocode (authoritative decompile)

```c
void FUN_0093bac0(int param_1,char param_2)

{
  int iVar1;
  int *piVar2;
  bool bVar3;
  int in_EAX;
  undefined4 uVar4;
  undefined4 uVar5;
  undefined1 local_8;
  undefined1 local_7;
  undefined1 local_6;
  undefined1 local_5;
  undefined4 local_4;
  
  iVar1 = *(int *)(param_1 + 0x30c0);
  bVar3 = false;
  if ((in_EAX != iVar1) &&
     (((((iVar1 == 5 || (iVar1 == 4)) || (iVar1 == 0)) || ((in_EAX == 5 || (in_EAX == 4)))) ||
      (in_EAX == 0)))) {
    bVar3 = true;
  }
  FUN_007a69d0();
  *(char *)(param_1 + 0x30c4) = param_2;
  local_4 = *(undefined4 *)(param_1 + 0x30c4);
  *(int *)(param_1 + 0x30c0) = in_EAX;
  switch(in_EAX) {
  case 0:
    iVar1 = *(int *)(param_1 + 0x1168);
    *(undefined4 *)(iVar1 + 0x4e8) = 0;
    *(undefined4 *)(iVar1 + 0x4ec) = 10;
    if (*(int *)(iVar1 + 0x4f0) == DAT_00afa0c0) goto LAB_0093bc9d;
    break;
  default:
    piVar2 = *(int **)(param_1 + 0x1168);
    if (*(char *)((int)piVar2 + 0x489) == '\0') {
      local_6 = 0xff;
      local_5 = 0xff;
      local_7 = 0;
      local_8 = 0;
      (**(code **)(*piVar2 + 0x15c))(0,&local_8);
      (**(code **)(*piVar2 + 0x34c))();
    }
    piVar2[0x13a] = 0;
    piVar2[0x13b] = 5;
    if (piVar2[0x13c] == DAT_00afa0ac) goto LAB_0093bc9d;
    break;
  case 2:
    iVar1 = *(int *)(param_1 + 0x1168);
    *(undefined4 *)(iVar1 + 0x4e8) = 0;
    *(undefined4 *)(iVar1 + 0x4ec) = 6;
    if (*(int *)(iVar1 + 0x4f0) == DAT_00afa0b0) goto LAB_0093bc9d;
    break;
  case 3:
    iVar1 = *(int *)(param_1 + 0x1168);
    *(undefined4 *)(iVar1 + 0x4e8) = 0;
    *(undefined4 *)(iVar1 + 0x4ec) = 7;
    if (*(int *)(iVar1 + 0x4f0) == DAT_00afa0b4) goto LAB_0093bc9d;
    break;
  case 4:
    iVar1 = *(int *)(param_1 + 0x1168);
    *(undefined4 *)(iVar1 + 0x4e8) = 0;
    *(undefined4 *)(iVar1 + 0x4ec) = 8;
    if (*(int *)(iVar1 + 0x4f0) == DAT_00afa0b8) goto LAB_0093bc9d;
    break;
  case 5:
    iVar1 = *(int *)(param_1 + 0x1168);
    *(undefined4 *)(iVar1 + 0x4e8) = 0;
    *(undefined4 *)(iVar1 + 0x4ec) = 9;
    if (*(int *)(iVar1 + 0x4f0) == DAT_00afa0bc) goto LAB_0093bc9d;
    break;
  case -1:
    FUN_007f9df0();
    goto LAB_0093bc9d;
  }
  FUN_007f9cc0();
LAB_0093bc9d:
  if ((param_2 != '\0') && (*(int *)(param_1 + 0x109c) != 0)) {
    uVar5 = 0;
    uVar4 = FUN_007a6de0("Select a target for this skill, or press ESC to cancel.",0xffffffff);
    FUN_008f8200(*(undefined4 *)(param_1 + 0x109c),6,&DAT_00a156cc,uVar4,uVar5);
  }
  if (bVar3) {
    Client_RefreshOpenMissionUiWindows(param_1);
  }
  return;
}
```
