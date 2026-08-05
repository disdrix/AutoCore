# Raw capture: FUN_006eec10

| Field | Value |
|---|---|
| **Stable ID** | `aa_006eec10` |
| **Module** | `autoassault.exe` |
| **Image base** | `0x400000` |
| **VA** | `0x006eec10` |
| **Canonical name** | `FUN_006eec10` |
| **System** | unknown |
| **Capture timestamp** | `2026-07-23` |
| **Tool** | Ghidra MCP `batch_decompile` |
| **Integrity** | Do not overwrite this raw body; append versioned sections only |

---

## Raw pseudocode (authoritative decompile)

```c
void __thiscall
FUN_006eec10(int param_1,undefined4 param_2,int *param_3,undefined4 *param_4,undefined4 param_5,
            int param_6)

{
  undefined ***pppuVar1;
  undefined4 local_b0;
  int local_ac;
  int local_a8;
  int *local_a4;
  undefined4 local_a0;
  undefined4 local_9c;
  undefined4 local_98;
  undefined4 local_94;
  float local_90;
  float local_8c;
  float local_88;
  float local_84;
  undefined4 local_80;
  undefined4 local_7c;
  undefined **local_70;
  undefined4 local_6c;
  undefined4 local_60;
  undefined4 local_5c;
  undefined4 local_58;
  undefined4 local_54;
  undefined4 local_50;
  undefined **local_40;
  undefined4 local_3c;
  undefined4 local_30;
  undefined4 local_2c;
  undefined4 local_28;
  undefined4 local_24;
  int local_20;
  
  local_90 = -(float)param_4[4];
  local_a0 = *param_4;
  local_9c = param_4[1];
  local_8c = -(float)param_4[5];
  local_98 = param_4[2];
  local_88 = -(float)param_4[6];
  local_94 = param_4[3];
  local_80 = param_4[8];
  local_84 = -(float)param_4[7];
  local_7c = param_4[9];
  local_60 = param_4[4];
  local_5c = param_4[5];
  local_58 = param_4[6];
  local_54 = param_4[7];
  local_50 = param_5;
  local_6c = 0x7f7fffff;
  local_70 = &PTR_LAB_00a0e334;
  if (param_6 == 0) {
    local_a8 = param_3[2];
    local_ac = param_3[1];
    local_b0 = *(undefined4 *)(*param_3 + 0xc);
    pppuVar1 = (undefined ***)0x0;
  }
  else {
    local_40 = &PTR_LAB_00a0e334;
    local_30 = param_4[4];
    local_2c = param_4[5];
    local_28 = param_4[6];
    local_24 = param_4[7];
    local_20 = param_6;
    local_a8 = param_3[2];
    local_3c = 0x7f7fffff;
    local_ac = param_3[1];
    local_b0 = *(undefined4 *)(*param_3 + 0xc);
    pppuVar1 = &local_40;
  }
  local_a4 = param_3;
  (**(code **)(**(int **)(param_1 + 0xc) + 0xc))(&local_b0,param_2,&local_a0,&local_70,pppuVar1);
  return;
}
```
