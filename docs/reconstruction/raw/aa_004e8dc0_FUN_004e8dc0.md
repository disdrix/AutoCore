# Raw capture: FUN_004e8dc0

| Field | Value |
|---|---|
| **Stable ID** | `aa_004e8dc0` |
| **Module** | `autoassault.exe` |
| **Image base** | `0x400000` |
| **VA** | `0x004e8dc0` |
| **Canonical name** | `FUN_004e8dc0` |
| **System** | unknown |
| **Capture timestamp** | `2026-07-23` |
| **Tool** | Ghidra MCP `batch_decompile` |
| **Integrity** | Do not overwrite this raw body; append versioned sections only |

---

## Raw pseudocode (authoritative decompile)

```c
undefined4 FUN_004e8dc0(float *param_1,undefined4 *param_2)

{
  float fVar1;
  char *pcVar2;
  float fVar3;
  undefined1 local_65;
  float local_64;
  float local_60;
  float local_5c;
  float local_58;
  float local_54;
  undefined4 local_50;
  undefined4 local_4c;
  undefined4 local_48;
  undefined4 local_44;
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
  
  local_60 = DAT_00af1804 * param_1[2] - DAT_00af1808 * param_1[1];
  local_5c = *param_1 * DAT_00af1808 - DAT_00af1800 * param_1[2];
  local_58 = DAT_00af1800 * param_1[1] - *param_1 * DAT_00af1804;
  local_54 = 0.0;
  pcVar2 = (char *)FUN_005d6870(&local_65);
  if ((*pcVar2 != '\0') &&
     (fVar1 = local_58 * local_58 + local_60 * local_60 + local_5c * local_5c,
     DAT_00a0f718 <= SQRT(fVar1))) {
    fVar3 = 0.0;
    if (fVar1 != 0.0) {
      fVar3 = g_flOne / SQRT(fVar1);
    }
    local_54 = local_54 * fVar3;
    local_5c = fVar3 * local_5c;
    local_58 = fVar3 * local_58;
    local_60 = fVar3 * local_60;
    local_30 = local_58 * param_1[1] - local_5c * param_1[2];
    local_2c = local_60 * param_1[2] - *param_1 * local_58;
    local_28 = *param_1 * local_5c - local_60 * param_1[1];
    local_64 = local_28 * local_28 + local_2c * local_2c + local_30 * local_30;
    local_24 = 0.0;
    if (local_64 != 0.0) {
      local_24 = g_flOne / SQRT(local_64);
      local_64 = local_24;
    }
    local_2c = local_2c * local_24;
    local_20 = *param_1;
    local_1c = param_1[1];
    local_18 = param_1[2];
    local_30 = local_24 * local_30;
    local_28 = local_28 * local_24;
    local_24 = local_24 * g_flZero;
    local_14 = param_1[3];
    local_40 = local_60;
    local_3c = local_5c;
    local_38 = local_58;
    local_34 = local_54;
    FUN_00567d20(&local_40);
    *param_2 = local_50;
    param_2[1] = local_4c;
    param_2[2] = local_48;
    param_2[3] = local_44;
    return 1;
  }
  param_2[3] = 0;
  param_2[2] = 0;
  param_2[1] = 0;
  *param_2 = 0;
  param_2[3] = g_flOne;
  return 0;
}
```
