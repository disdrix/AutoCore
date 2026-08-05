# Raw capture: FUN_006ef2a0

| Field | Value |
|---|---|
| **Stable ID** | `aa_006ef2a0` |
| **Module** | `autoassault.exe` |
| **Image base** | `0x400000` |
| **VA** | `0x006ef2a0` |
| **Canonical name** | `FUN_006ef2a0` |
| **System** | unknown |
| **Capture timestamp** | `2026-07-23` |
| **Tool** | Ghidra MCP `batch_decompile` |
| **Integrity** | Do not overwrite this raw body; append versioned sections only |

---

## Raw pseudocode (authoritative decompile)

```c
void __thiscall FUN_006ef2a0(int param_1,float *param_2,int param_3,undefined4 param_4)

{
  float *pfVar1;
  undefined4 *puVar2;
  float fVar3;
  float fVar4;
  float fVar5;
  int *local_b0;
  undefined4 local_ac;
  undefined4 *local_a8;
  int local_a4;
  float local_a0;
  float local_9c;
  float local_98;
  float local_94;
  float local_90;
  float local_8c;
  float local_88;
  float local_84;
  float local_80;
  float local_7c;
  undefined4 local_70;
  undefined4 local_6c;
  undefined4 local_68;
  undefined4 local_64;
  undefined4 local_60;
  undefined4 local_5c;
  undefined4 local_58;
  undefined4 local_54;
  
  local_94 = param_2[3];
  fVar3 = *param_2 - *(float *)(param_1 + 0x40);
  local_80 = param_2[8];
  fVar5 = param_2[1] - *(float *)(param_1 + 0x44);
  pfVar1 = (float *)(param_1 + 0x10);
  fVar4 = param_2[2] - *(float *)(param_1 + 0x48);
  local_84 = param_2[7];
  local_7c = param_2[9];
  local_a0 = fVar3 * *pfVar1 +
             fVar5 * *(float *)(param_1 + 0x14) + fVar4 * *(float *)(param_1 + 0x18);
  local_9c = fVar3 * *(float *)(param_1 + 0x20) +
             fVar5 * *(float *)(param_1 + 0x24) + fVar4 * *(float *)(param_1 + 0x28);
  local_98 = fVar3 * *(float *)(param_1 + 0x30) +
             fVar5 * *(float *)(param_1 + 0x34) + fVar4 * *(float *)(param_1 + 0x38);
  fVar3 = param_2[4] - *(float *)(param_1 + 0x40);
  fVar5 = param_2[5] - *(float *)(param_1 + 0x44);
  puVar2 = *(undefined4 **)(param_3 + 8);
  fVar4 = param_2[6] - *(float *)(param_1 + 0x48);
  local_90 = fVar3 * *pfVar1 +
             fVar5 * *(float *)(param_1 + 0x14) + fVar4 * *(float *)(param_1 + 0x18);
  local_8c = fVar3 * *(float *)(param_1 + 0x20) +
             fVar5 * *(float *)(param_1 + 0x24) + fVar4 * *(float *)(param_1 + 0x28);
  local_88 = fVar3 * *(float *)(param_1 + 0x30) +
             fVar5 * *(float *)(param_1 + 0x34) + fVar4 * *(float *)(param_1 + 0x38);
  local_70 = *puVar2;
  local_6c = puVar2[1];
  local_68 = puVar2[2];
  local_64 = puVar2[3];
  local_60 = puVar2[4];
  local_5c = puVar2[5];
  local_58 = puVar2[6];
  local_54 = puVar2[7];
  FUN_0063a190(*(int *)(param_3 + 8) + 0x20,pfVar1);
  local_b0 = *(int **)(param_1 + 0xc);
  local_a8 = &local_70;
  local_a4 = param_3;
  local_ac = *(undefined4 *)(param_3 + 4);
  (**(code **)(*local_b0 + 0x24))(&local_a0,&local_b0,param_4);
  return;
}
```
