# Raw capture: FUN_0069ada0

| Field | Value |
|---|---|
| **Stable ID** | `aa_0069ada0` |
| **Module** | `autoassault.exe` |
| **Image base** | `0x400000` |
| **VA** | `0x0069ada0` |
| **Canonical name** | `FUN_0069ada0` |
| **System** | unknown |
| **Capture timestamp** | `2026-07-23` |
| **Tool** | Ghidra MCP `batch_decompile` |
| **Integrity** | Do not overwrite this raw body; append versioned sections only |

---

## Raw pseudocode (authoritative decompile)

```c
/* WARNING: Globals starting with '_' overlap smaller symbols at the same address */

void __thiscall
FUN_0069ada0(int param_1,int param_2,float param_3,int param_4,int param_5,float *param_6,
            undefined4 param_7,undefined4 param_8,float param_9)

{
  float fVar1;
  float fVar2;
  float fVar3;
  int iVar4;
  uint uVar5;
  float10 fVar6;
  float10 fVar7;
  float local_50;
  float local_44;
  float local_40;
  float local_3c;
  float local_38;
  float local_34;
  float local_30;
  float local_2c;
  float local_28;
  float local_24;
  float local_20;
  float local_1c;
  float local_18;
  float local_14;
  float local_10;
  float local_c;
  float local_8;
  float local_4;
  
  iVar4 = param_2;
  fVar2 = g_flOne / (float)param_4;
  local_50 = 0.0;
  if (-1 < param_4) {
    fVar1 = param_3 + param_9;
    param_2 = param_4 + 1;
    do {
      fVar3 = DAT_00af55b4 * local_50;
      local_44 = param_3 * param_6[2] + local_50 * *param_6;
      local_40 = fVar1 * param_6[1];
      FUN_0068c910(&local_44,0xffffffff);
      fVar6 = (float10)fcos((float10)fVar3);
      fVar7 = (float10)fsin((float10)fVar3);
      local_3c = (float)(fVar6 * (float10)*(float *)(iVar4 + 0x28) +
                        fVar7 * (float10)*(float *)(iVar4 + 0x34));
      local_38 = (float)(fVar6 * (float10)*(float *)(iVar4 + 0x2c) +
                        fVar7 * (float10)*(float *)(iVar4 + 0x38));
      local_34 = (float)(fVar6 * (float10)*(float *)(iVar4 + 0x30) +
                        fVar7 * (float10)*(float *)(iVar4 + 0x3c));
      fVar6 = (float10)fcos((float10)_DAT_00af55ac + (float10)fVar3);
      fVar7 = (float10)fsin((float10)_DAT_00af55ac + (float10)fVar3);
      local_30 = (float)(fVar6 * (float10)*(float *)(iVar4 + 0x28) +
                        fVar7 * (float10)*(float *)(iVar4 + 0x34));
      local_2c = (float)(fVar6 * (float10)*(float *)(iVar4 + 0x2c) +
                        fVar7 * (float10)*(float *)(iVar4 + 0x38));
      local_28 = (float)(fVar6 * (float10)*(float *)(iVar4 + 0x30) +
                        fVar7 * (float10)*(float *)(iVar4 + 0x3c));
      FUN_0068cb80(&local_30);
      local_c = local_2c * local_34 - local_28 * local_38;
      local_8 = local_28 * local_3c - local_34 * local_30;
      local_4 = local_38 * local_30 - local_2c * local_3c;
      FUN_0068cc90(&local_c);
      param_9 = 0.0;
      for (uVar5 = 0;
          (*(int *)(param_1 + 0x34) != 0 &&
          (uVar5 < (uint)((*(int *)(param_1 + 0x38) - *(int *)(param_1 + 0x34)) / 0x18)));
          uVar5 = uVar5 + 1) {
        fVar6 = (float10)FUN_0069a580(fVar3,param_3);
        param_9 = (float)(fVar6 + (float10)param_9);
      }
      param_9 = param_9 + g_flOne;
      local_24 = local_3c * *(float *)(iVar4 + 0x18) + *(float *)(iVar4 + 0xc);
      local_20 = local_38 * *(float *)(iVar4 + 0x18) + *(float *)(iVar4 + 0x10);
      local_1c = local_34 * *(float *)(iVar4 + 0x18) + *(float *)(iVar4 + 0x14);
      if (param_9 != g_flOne) {
        local_24 = local_3c * *(float *)(iVar4 + 0x18) * param_9 + *(float *)(iVar4 + 0xc);
        local_20 = local_38 * *(float *)(iVar4 + 0x18) * param_9 + *(float *)(iVar4 + 0x10);
        local_1c = local_34 * *(float *)(iVar4 + 0x18) * param_9 + *(float *)(iVar4 + 0x14);
        local_18 = local_24;
        local_14 = local_20;
        local_10 = local_1c;
      }
      FUN_0068c6f0(&local_24);
      if (*(char *)(param_5 + 8) != '\0') {
        FUN_0068cac0(param_7,param_8);
      }
      local_50 = fVar2 + local_50;
      *(short *)(param_5 + 0x1a) = *(short *)(param_5 + 0x1a) + 1;
      param_2 = param_2 + -1;
    } while (param_2 != 0);
  }
  return;
}
```
