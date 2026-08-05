# Raw capture: FUN_005d5cc0

| Field | Value |
|---|---|
| **Stable ID** | `aa_005d5cc0` |
| **Module** | `autoassault.exe` |
| **Image base** | `0x400000` |
| **VA** | `0x005d5cc0` |
| **Canonical name** | `FUN_005d5cc0` |
| **System** | unknown |
| **Capture timestamp** | `2026-07-23` |
| **Tool** | Ghidra MCP `batch_decompile` |
| **Integrity** | Do not overwrite this raw body; append versioned sections only |

---

## Raw pseudocode (authoritative decompile)

```c
/* WARNING: Globals starting with '_' overlap smaller symbols at the same address */

void __fastcall FUN_005d5cc0(int param_1)

{
  int iVar1;
  void *pvVar2;
  int iVar3;
  float *pfVar4;
  undefined4 *puVar5;
  int *piVar6;
  float10 fVar7;
  float fVar8;
  float fVar9;
  float local_68;
  float local_60;
  float local_5c;
  float local_58;
  float local_54;
  float local_50;
  float local_4c;
  float local_48;
  float local_44;
  undefined1 local_40 [4];
  undefined4 *local_3c;
  undefined4 *local_38;
  undefined4 local_34;
  float local_30;
  float fStack_2c;
  float fStack_28;
  void *local_1c;
  undefined1 *puStack_18;
  undefined4 local_14;
  
  local_14 = 0xffffffff;
  puStack_18 = &LAB_009a7110;
  local_1c = ExceptionList;
  ExceptionList = &local_1c;
  FUN_0076cf00("CVOGWaypoint::DoFollowObjectShortcutsUpdate");
  local_14 = 0;
  pvVar2 = Object_ResolveFromTFID((TFID_16 *)(param_1 + 0x30));
  if ((pvVar2 == (void *)0x0) || ((*(uint *)((int)pvVar2 + 0x17c) >> 5 & 1) == 0)) {
    *(undefined1 *)(param_1 + 0x52) = 0;
    goto LAB_005d62e5;
  }
  *(undefined1 *)(param_1 + 0x52) = 1;
  iVar3 = __RTDynamicCast(pvVar2,0,&CVOGClonedObjectBase::RTTI_Type_Descriptor,
                          &CVOGPhysicsBase::RTTI_Type_Descriptor,0);
  if (*(int *)(iVar3 + 8) == 0) {
    pfVar4 = (float *)(*(int *)(*(int *)(iVar3 + 4) + 4) + 0x84 + iVar3);
  }
  else {
    pfVar4 = (float *)(*(int *)(*(int *)(iVar3 + 8) + 0x3c) + 0xb0);
  }
  local_50 = *pfVar4;
  iVar1 = *(int *)(param_1 + 0x10);
  local_4c = pfVar4[1];
  local_48 = pfVar4[2];
  local_44 = pfVar4[3];
  if (*(int *)(iVar1 + 8) == 0) {
    pfVar4 = (float *)(*(int *)(*(int *)(iVar1 + 4) + 4) + 0x84 + iVar1);
  }
  else {
    pfVar4 = (float *)(*(int *)(*(int *)(iVar1 + 8) + 0x3c) + 0xb0);
  }
  local_60 = *pfVar4;
  local_5c = pfVar4[1];
  local_58 = pfVar4[2];
  local_54 = pfVar4[3];
  fVar7 = (float10)FUN_0053e510(iVar3);
  fVar9 = (float)fVar7;
  if ((float10)*(float *)(param_1 + 0x4c) <= fVar7) {
    *(undefined1 *)(param_1 + 0x53) = 0;
  }
  else {
    *(undefined1 *)(param_1 + 0x53) = 1;
  }
  if (fVar9 < g_flOne) {
    *(float *)(param_1 + 0x20) = local_50;
    *(float *)(param_1 + 0x24) = local_4c;
    *(float *)(param_1 + 0x28) = local_48;
    *(float *)(param_1 + 0x2c) = local_44;
    goto LAB_005d62e5;
  }
  if ((*(uint *)(param_1 + 0x40) & *(uint *)(param_1 + 0x44)) != 0xffffffff) {
    FUN_005d5960();
    pfVar4 = (float *)FUN_00404c90();
    local_4c = local_4c - pfVar4[1];
    local_48 = local_48 - pfVar4[2];
    local_50 = local_50 - *pfVar4;
    fVar8 = local_48 * local_48 + local_4c * local_4c + local_50 * local_50;
    fVar9 = 0.0;
    if (fVar8 != 0.0) {
      fVar9 = g_flOne / SQRT(fVar8);
    }
    local_4c = local_4c * fVar9;
    local_60 = *(float *)(param_1 + 0x20);
    local_5c = *(float *)(param_1 + 0x24);
    local_58 = *(float *)(param_1 + 0x28);
    local_54 = *(float *)(param_1 + 0x2c);
    local_50 = fVar9 * local_50;
    local_48 = local_48 * fVar9;
    pfVar4 = (float *)FUN_00404c90();
    local_60 = local_60 - *pfVar4;
    local_5c = local_5c - pfVar4[1];
    local_58 = local_58 - pfVar4[2];
    fVar8 = local_58 * local_58 + local_5c * local_5c + local_60 * local_60;
    fVar9 = 0.0;
    if (fVar8 != 0.0) {
      fVar9 = g_flOne / SQRT(fVar8);
    }
    local_58 = local_58 * fVar9;
    local_5c = local_5c * fVar9;
    local_60 = fVar9 * local_60;
    local_54 = (local_54 - pfVar4[3]) * fVar9;
    if (local_58 * local_48 + local_5c * local_4c + local_60 * local_50 < DAT_00a0f70c) {
      *(undefined4 *)(param_1 + 0x40) = 0xffffffff;
      *(undefined4 *)(param_1 + 0x44) = 0xffffffff;
      *(undefined4 *)(param_1 + 0x48) = 0xffffffff;
      puVar5 = (undefined4 *)FUN_00404c90();
      *(undefined4 *)(param_1 + 0x20) = *puVar5;
      *(undefined4 *)(param_1 + 0x24) = puVar5[1];
      *(undefined4 *)(param_1 + 0x28) = puVar5[2];
      *(undefined4 *)(param_1 + 0x2c) = puVar5[3];
    }
    goto LAB_005d62e5;
  }
  pfVar4 = (float *)FUN_00404c90();
  local_60 = *pfVar4;
  local_5c = pfVar4[1];
  local_58 = pfVar4[2];
  local_54 = pfVar4[3];
  local_3c = (undefined4 *)0x0;
  local_38 = (undefined4 *)0x0;
  local_34 = 0;
  local_68 = _DAT_009dace0;
  local_14 = CONCAT31(local_14._1_3_,1);
  FUN_004d5910(&local_60,local_40);
  if (local_3c == local_38) {
LAB_005d6285:
    *(float *)(param_1 + 0x20) = local_50;
    *(float *)(param_1 + 0x24) = local_4c;
    *(float *)(param_1 + 0x28) = local_48;
    *(float *)(param_1 + 0x2c) = local_44;
  }
  else {
    piVar6 = (int *)0x0;
    puVar5 = local_3c;
    do {
      (**(code **)(*(int *)*puVar5 + 0x2c))(&local_30);
      fVar8 = (local_48 - fStack_28) * (local_48 - fStack_28) +
              (local_4c - fStack_2c) * (local_4c - fStack_2c) +
              (local_50 - local_30) * (local_50 - local_30);
      if (((fVar8 <= fVar9 * fVar9) &&
          ((fStack_28 - local_58) * (fStack_28 - local_58) +
           (fStack_2c - local_5c) * (fStack_2c - local_5c) +
           (local_30 - local_60) * (local_30 - local_60) <= fVar9 * fVar9)) && (fVar8 < local_68)) {
        piVar6 = (int *)*puVar5;
        local_68 = fVar8;
      }
      puVar5 = puVar5 + 1;
    } while (puVar5 != local_38);
    if (piVar6 == (int *)0x0) goto LAB_005d6285;
    local_4c = local_5c - local_4c;
    local_48 = local_58 - local_48;
    iVar3 = piVar6[0x4d];
    local_50 = local_60 - local_50;
    fVar9 = local_48 * local_48 + local_4c * local_4c + local_50 * local_50;
    *(int *)(param_1 + 0x40) = iVar3;
    *(int *)(param_1 + 0x44) = iVar3 >> 0x1f;
    if (fVar9 == 0.0) {
      fVar9 = 0.0;
    }
    else {
      fVar9 = g_flOne / SQRT(fVar9);
    }
    local_50 = fVar9 * local_50;
    local_4c = local_4c * fVar9;
    local_48 = local_48 * fVar9;
    local_44 = (local_54 - local_44) * fVar9;
    iVar3 = (**(code **)(*piVar6 + 0x10))(0xffffffff,&local_50);
    if (iVar3 == 0) {
      *(undefined4 *)(param_1 + 0x48) = 0xffffffff;
      (**(code **)(*piVar6 + 0x2c))(param_1 + 0x20);
    }
    else {
      *(undefined4 *)(param_1 + 0x48) = *(undefined4 *)(iVar3 + 0x134);
      (**(code **)(*piVar6 + 0x2c))(param_1 + 0x20);
    }
  }
  if (local_3c != (undefined4 *)0x0) {
                    /* WARNING: Subroutine does not return */
    operator_delete(local_3c);
  }
  local_3c = (undefined4 *)0x0;
  local_38 = (undefined4 *)0x0;
  local_34 = 0;
LAB_005d62e5:
  local_14 = 0xffffffff;
  FUN_0076cef0();
  ExceptionList = local_1c;
  return;
}
```
