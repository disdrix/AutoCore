# Raw capture: FUN_006effb0

| Field | Value |
|---|---|
| **Stable ID** | `aa_006effb0` |
| **Module** | `autoassault.exe` |
| **Image base** | `0x400000` |
| **VA** | `0x006effb0` |
| **Canonical name** | `FUN_006effb0` |
| **System** | unknown |
| **Capture timestamp** | `2026-07-23` |
| **Tool** | Ghidra MCP `batch_decompile` |
| **Integrity** | Do not overwrite this raw body; append versioned sections only |

---

## Raw pseudocode (authoritative decompile)

```c
void __thiscall FUN_006effb0(int param_1,float *param_2,undefined4 param_3,float *param_4)

{
  float fVar1;
  float fVar2;
  float fVar3;
  int iVar4;
  float *pfVar5;
  float *pfVar6;
  float *pfVar7;
  int iVar8;
  float *pfVar9;
  float local_250;
  float local_24c;
  float local_248;
  float local_244;
  float local_240;
  float local_23c;
  float local_238;
  uint local_224;
  float *local_220;
  int local_21c;
  int local_218;
  float local_210 [131];
  
  iVar4 = *(int *)(param_1 + 0x14);
  local_220 = local_210;
  local_21c = 0;
  local_218 = -0x7ffffff0;
  if (0x10 < iVar4) {
    iVar8 = 0x20;
    if (0x1f < iVar4) {
      iVar8 = iVar4;
    }
    FUN_005b3300(&local_220,iVar8,0x20);
  }
  pfVar6 = *(float **)(param_1 + 0x10);
  local_224 = *(int *)(param_1 + 0x14) * 2;
  iVar8 = local_224 - 1;
  pfVar9 = local_220;
  if (3 < (int)local_224) {
    local_224 = local_224 >> 2;
    iVar8 = iVar8 + local_224 * -4;
    pfVar5 = pfVar6;
    pfVar7 = local_220 + 6;
    do {
      fVar1 = *pfVar5;
      fVar2 = pfVar5[1];
      fVar3 = pfVar5[2];
      *pfVar9 = fVar1 * *param_2 + fVar2 * param_2[4] + fVar3 * param_2[8] + param_2[0xc];
      pfVar7[-5] = fVar2 * param_2[5] + fVar3 * param_2[9] + fVar1 * param_2[1] + param_2[0xd];
      pfVar7[-4] = fVar2 * param_2[6] + fVar3 * param_2[10] + fVar1 * param_2[2] + param_2[0xe];
      pfVar7[-3] = 0.0;
      fVar1 = pfVar5[4];
      fVar2 = pfVar5[5];
      fVar3 = pfVar5[6];
      pfVar7[-2] = fVar1 * *param_2 + fVar2 * param_2[4] + fVar3 * param_2[8] + param_2[0xc];
      pfVar7[-1] = fVar2 * param_2[5] + fVar3 * param_2[9] + fVar1 * param_2[1] + param_2[0xd];
      *pfVar7 = fVar2 * param_2[6] + fVar3 * param_2[10] + fVar1 * param_2[2] + param_2[0xe];
      pfVar7[1] = 0.0;
      fVar1 = pfVar5[8];
      fVar2 = pfVar5[9];
      fVar3 = pfVar5[10];
      pfVar7[2] = fVar1 * *param_2 + fVar2 * param_2[4] + fVar3 * param_2[8] + param_2[0xc];
      pfVar9 = pfVar9 + 0x10;
      pfVar6 = pfVar5 + 0x10;
      pfVar7[3] = fVar2 * param_2[5] + fVar3 * param_2[9] + fVar1 * param_2[1] + param_2[0xd];
      pfVar7[4] = fVar2 * param_2[6] + fVar3 * param_2[10] + fVar1 * param_2[2] + param_2[0xe];
      pfVar7[5] = 0.0;
      fVar1 = pfVar5[0xc];
      fVar2 = pfVar5[0xd];
      fVar3 = pfVar5[0xe];
      pfVar7[6] = fVar1 * *param_2 + fVar2 * param_2[4] + fVar3 * param_2[8] + param_2[0xc];
      pfVar7[7] = fVar2 * param_2[5] + fVar3 * param_2[9] + fVar1 * param_2[1] + param_2[0xd];
      pfVar7[8] = fVar2 * param_2[6] + fVar3 * param_2[10] + fVar1 * param_2[2] + param_2[0xe];
      pfVar7[9] = 0.0;
      local_224 = local_224 - 1;
      pfVar5 = pfVar6;
      pfVar7 = pfVar7 + 0x10;
    } while (local_224 != 0);
  }
  if (-1 < iVar8) {
    iVar8 = iVar8 + 1;
    do {
      fVar1 = *pfVar6;
      fVar2 = pfVar6[1];
      iVar8 = iVar8 + -1;
      fVar3 = pfVar6[2];
      *pfVar9 = fVar1 * *param_2 + fVar2 * param_2[4] + fVar3 * param_2[8] + param_2[0xc];
      pfVar9[1] = fVar2 * param_2[5] + fVar3 * param_2[9] + fVar1 * param_2[1] + param_2[0xd];
      pfVar9[2] = fVar2 * param_2[6] + fVar3 * param_2[10] + fVar1 * param_2[2] + param_2[0xe];
      pfVar9[3] = 0.0;
      pfVar6 = pfVar6 + 4;
      pfVar9 = pfVar9 + 4;
    } while (iVar8 != 0);
  }
  local_250 = 3.4028235e+38;
  local_24c = 3.4028235e+38;
  local_248 = 3.4028235e+38;
  local_244 = 3.4028235e+38;
  local_240 = -3.4028235e+38;
  local_23c = -3.4028235e+38;
  local_238 = -3.4028235e+38;
  fVar1 = DAT_00aaa63c;
  if (0 < iVar4) {
    pfVar6 = local_220 + 6;
    iVar8 = iVar4;
    do {
      if (pfVar6[-2] <= local_250) {
        local_250 = pfVar6[-2];
      }
      if (pfVar6[-1] <= local_24c) {
        local_24c = pfVar6[-1];
      }
      if (*pfVar6 <= local_248) {
        local_248 = *pfVar6;
      }
      if (pfVar6[1] <= local_244) {
        local_244 = pfVar6[1];
      }
      if (pfVar6[-6] <= local_250) {
        local_250 = pfVar6[-6];
      }
      if (pfVar6[-5] <= local_24c) {
        local_24c = pfVar6[-5];
      }
      if (pfVar6[-4] <= local_248) {
        local_248 = pfVar6[-4];
      }
      if (pfVar6[-3] <= local_244) {
        local_244 = pfVar6[-3];
      }
      if (local_240 <= pfVar6[-2]) {
        local_240 = pfVar6[-2];
      }
      if (local_23c <= pfVar6[-1]) {
        local_23c = pfVar6[-1];
      }
      if (local_238 <= *pfVar6) {
        local_238 = *pfVar6;
      }
      if (fVar1 <= pfVar6[1]) {
        fVar1 = pfVar6[1];
      }
      if (local_240 <= pfVar6[-6]) {
        local_240 = pfVar6[-6];
      }
      if (local_23c <= pfVar6[-5]) {
        local_23c = pfVar6[-5];
      }
      if (local_238 <= pfVar6[-4]) {
        local_238 = pfVar6[-4];
      }
      if (fVar1 <= pfVar6[-3]) {
        fVar1 = pfVar6[-3];
      }
      pfVar6 = pfVar6 + 8;
      iVar8 = iVar8 + -1;
    } while (iVar8 != 0);
  }
  *param_4 = local_250;
  param_4[1] = local_24c;
  param_4[2] = local_248;
  param_4[3] = local_244;
  param_4[7] = fVar1;
  param_4[4] = local_240;
  param_4[5] = local_23c;
  param_4[6] = local_238;
  if (-1 < local_218) {
    local_21c = iVar4;
    (**(code **)(*DAT_00b05060 + 0x14))(local_220,local_218 << 5,0x12);
  }
  return;
}
```
