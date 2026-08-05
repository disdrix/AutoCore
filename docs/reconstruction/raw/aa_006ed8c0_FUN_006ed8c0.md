# Raw capture: FUN_006ed8c0

| Field | Value |
|---|---|
| **Stable ID** | `aa_006ed8c0` |
| **Module** | `autoassault.exe` |
| **Image base** | `0x400000` |
| **VA** | `0x006ed8c0` |
| **Canonical name** | `FUN_006ed8c0` |
| **System** | unknown |
| **Capture timestamp** | `2026-07-23` |
| **Tool** | Ghidra MCP `batch_decompile` |
| **Integrity** | Do not overwrite this raw body; append versioned sections only |

---

## Raw pseudocode (authoritative decompile)

```c
void __thiscall
FUN_006ed8c0(int param_1,int *param_2,undefined4 *param_3,int *param_4,undefined4 param_5,
            undefined4 param_6)

{
  int iVar1;
  undefined8 uVar2;
  int iVar3;
  int iVar4;
  undefined4 uVar5;
  int *piStack_64;
  undefined4 uStack_60;
  int local_58;
  undefined4 local_50;
  int local_4c;
  int local_48;
  int *local_44;
  undefined **local_40;
  undefined4 local_3c;
  undefined1 local_38;
  undefined4 local_24;
  
  if (DAT_00bc5644 < DAT_00bc5648) {
    *DAT_00bc5644 = "LthkBvAgent";
    uVar2 = rdtsc();
    local_58 = (int)uVar2;
    DAT_00bc5644[1] = local_58;
    DAT_00bc5644 = DAT_00bc5644 + 3;
  }
  local_48 = param_2[2];
  iVar1 = *param_2;
  local_44 = param_2;
  local_4c = param_2[1];
  local_50 = *(undefined4 *)(iVar1 + 0xc);
  local_40 = &PTR_LAB_00a0e9d8;
  local_38 = 0;
  local_24 = 0x7f7fffff;
  local_3c = 0x7f7fffff;
  (**(code **)(**(int **)(param_1 + 0xc) + 0xc))(&local_50,param_3,param_4,&local_40,&local_40);
  if ((char)local_4c == '\0') {
    if (*(int **)(param_1 + 0x10) != (int *)0x0) {
      (**(code **)(**(int **)(param_1 + 0x10) + 0x14))();
      *(undefined4 *)(param_1 + 0x10) = 0;
    }
  }
  else {
    if (DAT_00bc5644 < DAT_00bc5648) {
      *DAT_00bc5644 = "Stchild";
      uVar2 = rdtsc();
      DAT_00bc5644[1] = (int)uVar2;
      DAT_00bc5644 = DAT_00bc5644 + 3;
    }
    uStack_60 = *(undefined4 *)(local_58 + 4);
    piStack_64 = *(int **)(iVar1 + 0x10);
    if (*(int *)(param_1 + 0x10) == 0) {
      uVar5 = *(undefined4 *)(param_1 + 8);
      iVar1 = *param_4;
      iVar3 = (**(code **)(*piStack_64 + 0x14))();
      iVar4 = (**(code **)(*(int *)*param_3 + 0x14))();
      uVar5 = (**(code **)(iVar1 + 0x18c + (iVar3 * 0x20 + iVar4) * 4))
                        (&piStack_64,param_3,param_4,uVar5);
      *(undefined4 *)(param_1 + 0x10) = uVar5;
    }
    (**(code **)(**(int **)(param_1 + 0x10) + 0xc))(&piStack_64,param_3,param_4,param_5,param_6);
  }
  if (DAT_00bc5644 < DAT_00bc5648) {
    *DAT_00bc5644 = &DAT_009d282c;
    uVar2 = rdtsc();
    DAT_00bc5644[1] = (int)uVar2;
    DAT_00bc5644 = DAT_00bc5644 + 3;
  }
  return;
}
```
