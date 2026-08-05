# Raw capture: CVOGVehicle_GetWeaponSlotTransform

| Field | Value |
|---|---|
| **Stable ID** | `aa_005fb6a0` |
| **Module** | `autoassault.exe` |
| **Image base** | `0x400000` |
| **VA** | `0x005fb6a0` |
| **Canonical name** | `CVOGVehicle_GetWeaponSlotTransform` |
| **System** | inventory-transfer |
| **Capture timestamp** | `2026-07-23` |
| **Tool** | Ghidra MCP `batch_decompile` |
| **Integrity** | Do not overwrite this raw body; append versioned sections only |

---

## Raw pseudocode (authoritative decompile)

```c
void __thiscall
CVOGVehicle_GetWeaponSlotTransform
          (int param_1,int param_2,int param_3,uint param_4,float *param_5,float *param_6)

{
  int iVar1;
  bool bVar2;
  uint uVar3;
  int iVar4;
  float *pfVar5;
  bool bVar6;
  float fVar7;
  float fVar8;
  float fVar9;
  float fVar10;
  float fVar11;
  float fVar12;
  float fVar13;
  float fVar14;
  float local_54;
  float local_50;
  float local_4c;
  float local_48;
  float local_44;
  float local_40;
  float local_3c;
  float local_38;
  float local_34;
  undefined4 local_30;
  float local_2c;
  undefined4 local_28;
  undefined4 local_24;
  float local_20;
  float local_1c;
  float local_18;
  float local_14;
  
  iVar4 = param_4 * 0xc0 + *(int *)(param_1 + 0x80);
  if (2 < *(int *)(param_1 + 0xc)) {
    uVar3 = param_4 & 0x80000001;
    bVar6 = uVar3 == 0;
    if ((int)uVar3 < 0) {
      bVar6 = (uVar3 - 1 | 0xfffffffe) == 0xffffffff;
    }
    bVar2 = true;
    if (bVar6) goto LAB_005fb6e3;
  }
  bVar2 = false;
LAB_005fb6e3:
  local_40 = *(float *)(iVar4 + 0x40);
  local_3c = *(float *)(iVar4 + 0x44);
  local_38 = *(float *)(iVar4 + 0x48);
  local_34 = *(float *)(iVar4 + 0x4c);
  if (bVar2) {
    local_40 = local_40 * DAT_00aaa668;
    local_3c = local_3c * DAT_00aaa668;
    local_38 = local_38 * DAT_00aaa668;
    local_34 = local_34 * DAT_00aaa668;
  }
  FUN_00567ce0(&local_40,0.0 - *(float *)(iVar4 + 0x90));
  iVar1 = *(int *)(param_2 + 0x3c);
  fVar10 = *(float *)(iVar4 + 0x70);
  fVar12 = *(float *)(iVar4 + 0x74);
  fVar13 = *(float *)(iVar4 + 0x78);
  local_54 = *(float *)(iVar4 + 0x7c);
  pfVar5 = (float *)(iVar1 + 0x30);
  if (bVar2) {
    local_30 = 0;
    local_2c = DAT_00aaa668;
    local_28 = 0;
    local_24 = 0;
    FUN_00567ce0(&local_30,0x40490fdb);
    fVar7 = local_18 * fVar12;
    fVar14 = fVar12 * local_20;
    fVar11 = local_1c * fVar10;
    fVar9 = local_20 * fVar10;
    fVar8 = local_1c * fVar12;
    fVar12 = local_14 * fVar12 + local_1c * local_54 + (fVar13 * local_20 - local_18 * fVar10);
    fVar10 = local_14 * fVar10 + local_54 * local_20 + (fVar7 - local_1c * fVar13);
    fVar7 = local_18 * fVar13;
    fVar13 = local_14 * fVar13 + local_18 * local_54 + (fVar11 - fVar14);
    local_54 = local_14 * local_54 - (fVar7 + fVar8 + fVar9);
  }
  fVar7 = *(float *)(iVar1 + 0x3c);
  fVar11 = *pfVar5 * local_54 +
           fVar7 * fVar10 + (fVar13 * *(float *)(iVar1 + 0x34) - fVar12 * *(float *)(iVar1 + 0x38));
  fVar9 = *(float *)(iVar1 + 0x3c) * local_54 -
          (*pfVar5 * fVar10 + fVar13 * *(float *)(iVar1 + 0x38) + fVar12 * *(float *)(iVar1 + 0x34))
  ;
  fVar8 = local_54 * *(float *)(iVar1 + 0x38) +
          fVar13 * fVar7 + (*pfVar5 * fVar12 - *(float *)(iVar1 + 0x34) * fVar10);
  fVar10 = local_54 * *(float *)(iVar1 + 0x34) +
           fVar12 * fVar7 + (*(float *)(iVar1 + 0x38) * fVar10 - *pfVar5 * fVar13);
  *param_6 = (local_48 * fVar10 - local_4c * fVar8) + fVar9 * local_50 + local_44 * fVar11;
  param_6[1] = (fVar8 * local_50 - local_48 * fVar11) + local_4c * fVar9 + local_44 * fVar10;
  param_6[2] = (local_4c * fVar11 - fVar10 * local_50) + local_48 * fVar9 + local_44 * fVar8;
  param_6[3] = local_44 * fVar9 * g_flLevelUpUiBase_Inferred;
  param_6[3] = local_44 * fVar9 - (local_50 * fVar11 + local_48 * fVar8 + local_4c * fVar10);
  fVar10 = *(float *)(iVar4 + 0xb0);
  if (fVar10 < 0.0) {
    fVar10 = 0.0;
  }
  iVar1 = *(int *)(param_2 + 0x3c);
  pfVar5 = (float *)(param_4 * 0x10 + *(int *)(param_3 + 0x10));
  fVar12 = pfVar5[1];
  fVar13 = pfVar5[2];
  fVar7 = *pfVar5;
  *param_5 = *(float *)(iVar1 + 0xa0) * fVar13 + *(float *)(iVar1 + 0x90) * fVar12 +
             *(float *)(iVar1 + 0x80) * fVar7 + *(float *)(iVar1 + 0xb0);
  param_5[1] = *(float *)(iVar1 + 0xa4) * fVar13 + *(float *)(iVar1 + 0x94) * fVar12 +
               *(float *)(iVar1 + 0x84) * fVar7 + *(float *)(iVar1 + 0xb4);
  param_5[2] = *(float *)(iVar1 + 0xa8) * fVar13 + *(float *)(iVar1 + 0x98) * fVar12 +
               *(float *)(iVar1 + 0x88) * fVar7 + *(float *)(iVar1 + 0xb8);
  param_5[3] = 0.0;
  *param_5 = fVar10 * *(float *)(iVar4 + 0x50) + *param_5;
  param_5[1] = *(float *)(iVar4 + 0x54) * fVar10 + param_5[1];
  param_5[2] = *(float *)(iVar4 + 0x58) * fVar10 + param_5[2];
  param_5[3] = *(float *)(iVar4 + 0x5c) * fVar10 + param_5[3];
  return;
}
```
