# Raw capture: FUN_006edd10

| Field | Value |
|---|---|
| **Stable ID** | `aa_006edd10` |
| **Module** | `autoassault.exe` |
| **Image base** | `0x400000` |
| **VA** | `0x006edd10` |
| **Canonical name** | `FUN_006edd10` |
| **System** | unknown |
| **Capture timestamp** | `2026-07-23` |
| **Tool** | Ghidra MCP `batch_decompile` |
| **Integrity** | Do not overwrite this raw body; append versioned sections only |

---

## Raw pseudocode (authoritative decompile)

```c
void FUN_006edd10(int *param_1,undefined4 *param_2,int *param_3,undefined4 param_4)

{
  undefined8 uVar1;
  int iVar2;
  int iVar3;
  int iVar4;
  undefined **local_18;
  char cStack_14;
  int *local_10;
  int local_c;
  int local_8;
  int *local_4;
  
  if (DAT_00bc5644 < DAT_00bc5648) {
    *DAT_00bc5644 = "LthkBvAgent";
    uVar1 = rdtsc();
    local_18 = (undefined **)uVar1;
    DAT_00bc5644[1] = local_18;
    DAT_00bc5644 = DAT_00bc5644 + 3;
  }
  local_8 = param_1[2];
  iVar4 = *param_1;
  local_4 = param_1;
  local_10 = *(int **)(iVar4 + 0xc);
  local_c = param_1[1];
  iVar2 = (**(code **)(*local_10 + 0x14))();
  iVar3 = (**(code **)(*(int *)*param_2 + 0x14))();
  local_18 = &PTR_LAB_00a0e9d0;
  cStack_14 = '\0';
  (**(code **)(*param_3 + 0x118c + (iVar2 * 0x20 + iVar3) * 4))(&local_10,param_2,param_3,&local_18)
  ;
  if (cStack_14 != '\0') {
    if (DAT_00bc5644 < DAT_00bc5648) {
      *DAT_00bc5644 = "Stchild";
      uVar1 = rdtsc();
      DAT_00bc5644[1] = (int)uVar1;
      DAT_00bc5644 = DAT_00bc5644 + 3;
    }
    local_10 = *(int **)(iVar4 + 0x10);
    local_c = local_4[1];
    iVar4 = (**(code **)(*local_10 + 0x14))();
    (**(code **)(*param_3 + 0x218c + (iVar4 * 0x20 + iVar3) * 4))(&local_10,param_2,param_3,param_4)
    ;
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
