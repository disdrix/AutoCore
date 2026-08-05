# Raw capture: FUN_006ed0d0

| Field | Value |
|---|---|
| **Stable ID** | `aa_006ed0d0` |
| **Module** | `autoassault.exe` |
| **Image base** | `0x400000` |
| **VA** | `0x006ed0d0` |
| **Canonical name** | `FUN_006ed0d0` |
| **System** | unknown |
| **Capture timestamp** | `2026-07-23` |
| **Tool** | Ghidra MCP `batch_decompile` |
| **Integrity** | Do not overwrite this raw body; append versioned sections only |

---

## Raw pseudocode (authoritative decompile)

```c
undefined4 * __thiscall
FUN_006ed0d0(undefined4 *param_1,undefined4 *param_2,undefined4 *param_3,int *param_4,
            undefined4 param_5)

{
  int *piVar1;
  int *piVar2;
  float fVar3;
  float fVar4;
  float *pfVar5;
  float fVar6;
  float fVar7;
  int iVar8;
  int iVar9;
  int local_b0;
  undefined **local_a4;
  uint local_a0;
  float local_98;
  int local_94;
  undefined ***local_90;
  int local_8c;
  undefined1 *local_88;
  undefined4 *local_84;
  float local_80;
  float local_7c;
  undefined1 local_70 [32];
  float local_50;
  float local_4c;
  float local_48;
  float local_40;
  float local_3c;
  float local_38;
  float local_30;
  float local_2c;
  float local_28;
  float local_20;
  float local_1c;
  float local_18;
  undefined4 local_14;
  
  param_1[2] = param_5;
  *param_1 = &PTR_FUN_00a0e98c;
  piVar1 = param_1 + 3;
  *piVar1 = (int)(param_1 + 6);
  param_1[4] = 0;
  param_1[5] = 0x80000004;
  pfVar5 = (float *)*param_2;
  fVar6 = pfVar5[3];
  if ((int)(param_1[5] & 0x7fffffff) < (int)fVar6) {
    fVar7 = (float)((param_1[5] & 0x7fffffff) * 2);
    if ((int)fVar7 <= (int)fVar6) {
      fVar7 = fVar6;
    }
    FUN_005b3300(piVar1,fVar7,8);
  }
  FUN_006c7fa0(0);
  FUN_006e8880(param_2[2]);
  local_88 = local_70;
  local_84 = param_2;
  local_b0 = 0;
  if (0 < (int)fVar6) {
    do {
      fVar7 = pfVar5[4];
      iVar8 = param_2[2];
      fVar3 = pfVar5[5];
      fVar4 = pfVar5[6];
      local_80 = local_50 * fVar7 + local_40 * fVar3 + local_30 * fVar4;
      local_7c = local_4c * fVar7 + local_3c * fVar3 + local_2c * fVar4;
      local_20 = local_80 + *(float *)(iVar8 + 0x50);
      local_1c = local_7c + *(float *)(iVar8 + 0x54);
      local_18 = local_48 * fVar7 + local_38 * fVar3 + local_28 * fVar4 + *(float *)(iVar8 + 0x58);
      local_14 = *(undefined4 *)(iVar8 + 0x5c);
      local_98 = pfVar5[7];
      local_90 = &local_a4;
      local_94 = *param_4;
      local_8c = local_b0;
      iVar8 = (*(code *)local_a4[5])();
      iVar9 = (**(code **)(*(int *)*param_3 + 0x14))();
      iVar8 = (**(code **)(local_94 + 0x18c + (iVar8 * 0x20 + iVar9) * 4))
                        (&local_90,param_3,param_4,param_5);
      if (iVar8 != 0) {
        if (param_1[4] == (param_1[5] & 0x7fffffff)) {
          FUN_005b3370(piVar1,8);
        }
        piVar2 = (int *)(*piVar1 + param_1[4] * 8);
        param_1[4] = param_1[4] + 1;
        piVar2[1] = iVar8;
        *piVar2 = local_b0;
      }
      local_b0 = local_b0 + 1;
      pfVar5 = pfVar5 + 4;
    } while (local_b0 < (int)fVar6);
  }
  local_a4 = &PTR_FUN_009d81e8;
  if ((char)(local_a0 >> 8) < '\0') {
    local_a0 = local_a0 & 0xffff7fff;
    FUN_005ffdb0(0);
  }
  return param_1;
}
```
