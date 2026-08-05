# Raw capture: FUN_006eda50

| Field | Value |
|---|---|
| **Stable ID** | `aa_006eda50` |
| **Module** | `autoassault.exe` |
| **Image base** | `0x400000` |
| **VA** | `0x006eda50` |
| **Canonical name** | `FUN_006eda50` |
| **System** | unknown |
| **Capture timestamp** | `2026-07-23` |
| **Tool** | Ghidra MCP `batch_decompile` |
| **Integrity** | Do not overwrite this raw body; append versioned sections only |

---

## Raw pseudocode (authoritative decompile)

```c
void FUN_006eda50(int *param_1,undefined4 *param_2,int *param_3,undefined4 param_4,
                 undefined4 param_5)

{
  undefined8 uVar1;
  int iVar2;
  int iVar3;
  int iVar4;
  int *local_50;
  int local_4c;
  int local_48;
  int *local_44;
  undefined **ppuStack_40;
  undefined4 uStack_3c;
  char cStack_38;
  undefined4 uStack_24;
  
  if (DAT_00bc5644 < DAT_00bc5648) {
    *DAT_00bc5644 = "LthkBvAgent";
    uVar1 = rdtsc();
    DAT_00bc5644[1] = (int)uVar1;
    DAT_00bc5644 = DAT_00bc5644 + 3;
  }
  local_48 = param_1[2];
  iVar4 = *param_1;
  local_44 = param_1;
  local_50 = *(int **)(iVar4 + 0xc);
  local_4c = param_1[1];
  iVar2 = (**(code **)(*local_50 + 0x14))();
  iVar3 = (**(code **)(*(int *)*param_2 + 0x14))();
  ppuStack_40 = &PTR_LAB_00a0e9d8;
  cStack_38 = '\0';
  uStack_24 = 0x7f7fffff;
  uStack_3c = 0x7f7fffff;
  (**(code **)(*param_3 + 0x318c + (iVar2 * 0x20 + iVar3) * 4))
            (&local_50,param_2,param_3,&ppuStack_40,&ppuStack_40);
  if (cStack_38 != '\0') {
    if (DAT_00bc5644 < DAT_00bc5648) {
      *DAT_00bc5644 = "Stchild";
      uVar1 = rdtsc();
      DAT_00bc5644[1] = (int)uVar1;
      DAT_00bc5644 = DAT_00bc5644 + 3;
    }
    local_50 = *(int **)(iVar4 + 0x10);
    local_4c = local_44[1];
    iVar4 = (**(code **)(*local_50 + 0x14))();
    (**(code **)(*param_3 + 0x318c + (iVar4 * 0x20 + iVar3) * 4))
              (&local_50,param_2,param_3,param_4,param_5);
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
