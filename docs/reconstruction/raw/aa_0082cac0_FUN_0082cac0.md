# Raw capture: FUN_0082cac0

| Field | Value |
|---|---|
| **Stable ID** | `aa_0082cac0` |
| **Module** | `autoassault.exe` |
| **Image base** | `0x400000` |
| **VA** | `0x0082cac0` |
| **Canonical name** | `FUN_0082cac0` |
| **System** | unknown |
| **Capture timestamp** | `2026-07-23` |
| **Tool** | Ghidra MCP `batch_decompile` |
| **Integrity** | Do not overwrite this raw body; append versioned sections only |

---

## Raw pseudocode (authoritative decompile)

```c
void __thiscall FUN_0082cac0(int *param_1,int param_2,int param_3)

{
  int iVar1;
  int *piVar2;
  int *piVar3;
  int iVar4;
  float *pfVar5;
  int iVar6;
  int iVar7;
  int *local_54;
  float local_50;
  int local_48;
  int local_44;
  int iStack_40;
  int local_3c;
  undefined1 auStack_38 [8];
  undefined1 auStack_30 [8];
  undefined1 auStack_28 [8];
  undefined1 auStack_20 [4];
  undefined1 auStack_1c [12];
  undefined1 auStack_10 [12];
  
  if (param_2 != 0) {
    local_50 = 0.0;
    local_54 = (int *)0x0;
    if ((param_3 < 0) ||
       (piVar2 = (int *)(**(code **)(*param_1 + 0x3cc))(param_3), piVar2 == (int *)0x0)) {
      local_48 = param_1[0x140];
      local_44 = param_1[0x141];
    }
    else {
      piVar3 = (int *)(**(code **)(*piVar2 + 0x120))(auStack_38,1,0);
      local_48 = *piVar3;
      local_44 = piVar3[1];
      if (param_1[0x14b] == 3) {
        piVar2 = (int *)(**(code **)(*piVar2 + 0x140))(auStack_38,1);
        local_48 = local_48 + param_1[0x144] + *piVar2;
      }
      else if (param_1[0x14b] == 1) {
        iVar7 = (**(code **)(*piVar2 + 0x140))(auStack_38,1);
        local_44 = local_44 + *(int *)(iVar7 + 4) + param_1[0x145];
      }
    }
    iVar7 = local_48;
    local_3c = local_44;
    FUN_004294f0();
    iVar4 = FUN_004113b0(param_2,&local_54);
    piVar2 = local_54;
    while (local_54 = piVar2, iVar4 == 0) {
      if (param_1[0x14b] == 2) {
        piVar3 = (int *)(**(code **)(*piVar2 + 0x140))(auStack_30,1);
        iVar7 = (local_48 - param_1[0x144]) - *piVar3;
      }
      else if (param_1[0x14b] == 0) {
        iVar4 = (**(code **)(*piVar2 + 0x140))(auStack_28,1);
        local_3c = (local_44 - param_1[0x145]) - *(int *)(iVar4 + 4);
      }
      iVar4 = (**(code **)(*piVar2 + 0x124))(auStack_20);
      local_50 = (float)DAT_00d1e81c * *(float *)(iVar4 + 4) * DAT_00aaa678;
      pfVar5 = (float *)(**(code **)(*piVar2 + 0x124))(auStack_1c);
      local_3c = (int)(float)local_54 + local_44;
      iStack_40 = (int)((float)DAT_00d1e818 * *pfVar5 * DAT_00aaa67c) + iVar7;
      (**(code **)(*piVar2 + 0x118))(&iStack_40);
      if ((char)param_1[0x13f] == '\0') {
        piVar2 = (int *)(**(code **)(*piVar2 + 0x140))(auStack_10,1);
        iVar4 = *piVar2;
        iVar6 = piVar2[1];
      }
      else {
        iVar4 = param_1[0x142];
        iVar6 = param_1[0x143];
      }
      iVar1 = param_1[0x14c];
      if (iVar1 == 1) {
        local_3c = local_3c + param_1[0x145] + iVar6;
      }
      else if (iVar1 == 2) {
        iVar7 = iVar7 - (param_1[0x144] + iVar4);
      }
      else if (iVar1 == 3) {
        iVar7 = iVar7 + param_1[0x144] + iVar4;
      }
      else {
        local_3c = local_3c - (param_1[0x145] + iVar6);
      }
      iVar4 = FUN_004113b0(param_2,&local_54);
      piVar2 = local_54;
    }
    if (*(char *)(param_2 + 0x28) != '\0') {
      *(undefined1 *)(param_2 + 0x28) = 0;
      LeaveCriticalSection((LPCRITICAL_SECTION)(param_2 + 4));
    }
  }
  return;
}
```
