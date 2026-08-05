# Raw capture: FUN_0065afe0

| Field | Value |
|---|---|
| **Stable ID** | `aa_0065afe0` |
| **Module** | `autoassault.exe` |
| **Image base** | `0x400000` |
| **VA** | `0x0065afe0` |
| **Canonical name** | `FUN_0065afe0` |
| **System** | unknown |
| **Capture timestamp** | `2026-07-23` |
| **Tool** | Ghidra MCP `batch_decompile` |
| **Integrity** | Do not overwrite this raw body; append versioned sections only |

---

## Raw pseudocode (authoritative decompile)

```c
void FUN_0065afe0(float *param_1,float *param_2,float param_3,int param_4)

{
  int iVar1;
  char *pcVar2;
  float *pfVar3;
  float10 fVar4;
  float fVar5;
  float fVar6;
  float fVar7;
  undefined4 uStack_38;
  float fStack_34;
  float local_30;
  float local_2c;
  float local_28;
  float local_24;
  float fStack_20;
  float fStack_1c;
  float fStack_18;
  
  iVar1 = *(int *)(param_4 + 0x3c);
  fVar7 = param_2[3] * param_2[3] * g_flLevelUpUiBase_Inferred - g_flOne;
  fVar5 = (*(float *)(iVar1 + 0x28) * param_2[2] + param_2[1] * *(float *)(iVar1 + 0x24) +
          *param_2 * *(float *)(iVar1 + 0x20)) * g_flLevelUpUiBase_Inferred;
  fVar6 = param_2[3] * g_flLevelUpUiBase_Inferred;
  local_30 = ((*param_1 +
              (*(float *)(iVar1 + 0x28) * param_2[1] - *(float *)(iVar1 + 0x24) * param_2[2]) *
              fVar6 + *param_2 * fVar5 + fVar7 * *(float *)(iVar1 + 0x20)) -
             *(float *)(iVar1 + 0x70)) * param_3;
  local_2c = ((param_1[1] +
              (param_2[2] * *(float *)(iVar1 + 0x20) - *(float *)(iVar1 + 0x28) * *param_2) * fVar6
              + param_2[1] * fVar5 + *(float *)(iVar1 + 0x24) * fVar7) - *(float *)(iVar1 + 0x74)) *
             param_3;
  local_28 = ((param_1[2] +
              (*(float *)(iVar1 + 0x24) * *param_2 - param_2[1] * *(float *)(iVar1 + 0x20)) * fVar6
              + fVar5 * param_2[2] + *(float *)(iVar1 + 0x28) * fVar7) - *(float *)(iVar1 + 0x78)) *
             param_3;
  local_24 = ((param_1[3] + fVar6 * g_flZero + fVar5 * param_2[3] + *(float *)(iVar1 + 0x2c) * fVar7
              ) - *(float *)(iVar1 + 0x7c)) * param_3;
  pcVar2 = (char *)FUN_005070b0((int)&uStack_38 + 3);
  if ((*pcVar2 == '\0') && (*(int *)(param_4 + 0x44) != 0)) {
    FUN_005070d0();
  }
  (**(code **)(**(int **)(param_4 + 0x3c) + 0x50))(&local_30);
  iVar1 = *(int *)(param_4 + 0x3c);
  pfVar3 = (float *)(iVar1 + 0x30);
  fVar6 = 0.0 - param_2[3];
  fVar5 = *(float *)(iVar1 + 0x3c);
  local_24 = *param_2 * fVar5 +
             fVar6 * *pfVar3 +
             (*(float *)(iVar1 + 0x34) * param_2[2] - *(float *)(iVar1 + 0x38) * param_2[1]);
  fStack_1c = fVar5 * param_2[2] +
              *(float *)(iVar1 + 0x38) * fVar6 +
              (param_2[1] * *pfVar3 - *param_2 * *(float *)(iVar1 + 0x34));
  fStack_18 = *(float *)(iVar1 + 0x38) * param_2[2] + *param_2 * *pfVar3 +
              *(float *)(iVar1 + 0x3c) * param_2[3] + param_2[1] * *(float *)(iVar1 + 0x34);
  fStack_20 = param_2[1] * fVar5 +
              *(float *)(iVar1 + 0x34) * fVar6 +
              (*(float *)(iVar1 + 0x38) * *param_2 - *(float *)(iVar1 + 0x30) * param_2[2]);
  fVar5 = fStack_18 * fStack_18 + fStack_1c * fStack_1c + fStack_20 * fStack_20 +
          local_24 * local_24;
  if (fVar5 == 0.0) {
    uStack_38 = 0.0;
  }
  else {
    uStack_38 = g_flOne / SQRT(fVar5);
  }
  fStack_18 = fStack_18 * uStack_38;
  local_24 = uStack_38 * local_24;
  fStack_20 = fStack_20 * uStack_38;
  fStack_1c = fStack_1c * uStack_38;
  uStack_38 = ABS(fStack_18);
  if (ABS(uStack_38) < g_flOne) {
    fVar4 = (float10)_CIacos();
    fVar5 = (float)fVar4;
  }
  else {
    fVar5 = 0.0;
    if (uStack_38 <= 0.0) {
      fVar5 = DAT_009e5ee8;
    }
  }
  uStack_38 = fVar5 * g_flLevelUpUiBase_Inferred;
  if (g_flMsToSeconds_Inferred <= uStack_38) {
    FUN_005d1c00(&fStack_34);
    param_3 = uStack_38 * param_3;
    fStack_34 = param_3 * fStack_34;
    local_30 = local_30 * param_3;
    local_2c = local_2c * param_3;
    local_28 = local_28 * param_3;
  }
  else {
    local_28 = 0.0;
    local_2c = 0.0;
    local_30 = 0.0;
    fStack_34 = 0.0;
  }
  pcVar2 = (char *)FUN_005070b0(&stack0xffffffc7);
  if ((*pcVar2 == '\0') && (*(int *)(param_4 + 0x44) != 0)) {
    FUN_005070d0();
  }
  (**(code **)(**(int **)(param_4 + 0x3c) + 0x54))(&fStack_34);
  return;
}
```
