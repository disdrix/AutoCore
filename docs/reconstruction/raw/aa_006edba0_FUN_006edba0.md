# Raw capture: FUN_006edba0

| Field | Value |
|---|---|
| **Stable ID** | `aa_006edba0` |
| **Module** | `autoassault.exe` |
| **Image base** | `0x400000` |
| **VA** | `0x006edba0` |
| **Canonical name** | `FUN_006edba0` |
| **System** | unknown |
| **Capture timestamp** | `2026-07-23` |
| **Tool** | Ghidra MCP `batch_decompile` |
| **Integrity** | Do not overwrite this raw body; append versioned sections only |

---

## Raw pseudocode (authoritative decompile)

```c
void __thiscall FUN_006edba0(int param_1,int *param_2,undefined4 *param_3,int *param_4)

{
  undefined8 uVar1;
  int iVar2;
  int iVar3;
  undefined4 uVar4;
  char unaff_SI;
  undefined4 unaff_retaddr;
  undefined **local_18;
  uint local_14;
  undefined4 local_10;
  int local_c;
  int local_8;
  int *local_4;
  
  if (DAT_00bc5644 < DAT_00bc5648) {
    *DAT_00bc5644 = "LthkBvAgent";
    uVar1 = rdtsc();
    DAT_00bc5644[1] = (int)uVar1;
    DAT_00bc5644 = DAT_00bc5644 + 3;
  }
  local_8 = param_2[2];
  iVar2 = *param_2;
  local_4 = param_2;
  local_c = param_2[1];
  local_10 = *(undefined4 *)(iVar2 + 0xc);
  local_18 = &PTR_LAB_00a0e9d0;
  local_14 = local_14 & 0xffffff00;
  (**(code **)(**(int **)(param_1 + 0xc) + 4))(&local_10,param_3,param_4,&local_18);
  if (unaff_SI == '\0') {
    if (*(int **)(param_1 + 0x10) != (int *)0x0) {
      (**(code **)(**(int **)(param_1 + 0x10) + 0x14))();
      *(undefined4 *)(param_1 + 0x10) = 0;
    }
  }
  else {
    if (DAT_00bc5644 < DAT_00bc5648) {
      *DAT_00bc5644 = "Stchild";
      uVar1 = rdtsc();
      local_c = (int)uVar1;
      DAT_00bc5644[1] = local_c;
      DAT_00bc5644 = DAT_00bc5644 + 3;
    }
    if (*(int *)(param_1 + 0x10) == 0) {
      local_4 = *(int **)(param_1 + 8);
      local_c = *param_4;
      iVar2 = (**(code **)(**(int **)(iVar2 + 0x10) + 0x14))();
      iVar3 = (**(code **)(*(int *)*param_3 + 0x14))();
      uVar4 = (**(code **)(local_c + 0x18c + (iVar2 * 0x20 + iVar3) * 4))
                        (&stack0xffffffe0,param_3,param_4,local_4);
      *(undefined4 *)(param_1 + 0x10) = uVar4;
    }
    (**(code **)(**(int **)(param_1 + 0x10) + 8))(&stack0xffffffe0,param_3,param_4,unaff_retaddr);
  }
  if (DAT_00bc5644 < DAT_00bc5648) {
    *DAT_00bc5644 = &DAT_009d282c;
    uVar1 = rdtsc();
    DAT_00bc5644[1] = (int)uVar1;
    DAT_00bc5644 = DAT_00bc5644 + 3;
  }
  return;
}
```
