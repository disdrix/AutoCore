// READABILITY (auto CF):
//  - Body size: ~77 non-empty decompiler lines.
//  - Control keywords: if×7, return×1.
//  - Notable callees: CVOGHBAIFollowVehicle_FireWeapons, FUN_005021d0, FUN_0053e510, FUN_0076cef0, FUN_0076cf00, SQRT.
//  - Strings: "CVOGHBAIFollowVehicle::FireWeapons".
//  - Return sites: 1.

// =============================================================================
// CVOGHBAIFollowVehicle_FireWeapons
// -----------------------------------------------------------------------------
// Purpose:  Geometry-gated weapon fire for follow/driver AI: build front/turret/rear
//           fire masks from relative target angles; independent of drive state.
//
// Address:  0x005d7100  (autoassault.exe, image base 0x400000)
// Stable:   aa_005d7100
// System:   npc-ai / HBAI
//
// Convention: thiscall; param_2 = may-fire flag (DoLogic always calls).
// Scoped string: "CVOGHBAIFollowVehicle::FireWeapons".
// Uses target pos (vtbl+0x1a0) vs self; sets fire mask local_3c family.
// Decoupled: idle drivers still fire when may-fire and target geometry ok.
//
// Exactness: CF mirrors raw; names cleaned; no invented clamps.
// Bit-for-bit / runtime / differential: DEFERRED / OPEN.
// Human-refined plate: 2026-07-23 (AI managers readability)
// =============================================================================

void __thiscall CVOGHBAIFollowVehicle_FireWeapons(int param_1,char param_2)
{
  int iVar1;
  int *piVar2;
  float *pfVar3;
  float *pfVar4;
  uint32_t /* width from decompiler */ uVar5;
  float10 fVar6;
  float fVar7;
  float fVar8;
  float fVar9;
  float fVar10;
  float fVar11;
  uint local_3c;
  void *pvStack_1c;
  uint8_t *puStack_18;
  uint32_t /* width from decompiler */ local_14;
  
  local_14 = 0xffffffff;
  puStack_18 = &LAB_009a716a;
  pvStack_1c = ExceptionList;
  ExceptionList = &pvStack_1c;
  FUN_0076cf00("CVOGHBAIFollowVehicle::FireWeapons");
  local_14 = 0;
  local_3c = 0;
  if (param_2 != '\0') {
    pfVar3 = (float *)(**(code **)(**(int **)(*(int *)(param_1 + 0x18) + 0xa0) + 0x1a0))();
    iVar1 = *(int *)(param_1 + 0xbc);
    if (*(int *)(iVar1 + 8) == 0) {
      pfVar4 = (float *)(*(int *)(*(int *)(iVar1 + 4) + 4) + 0x84 + iVar1);
    }
    else {
      pfVar4 = (float *)(*(int *)(*(int *)(iVar1 + 8) + 0x3c) + 0xb0);
    }
    fVar7 = pfVar3[1] - pfVar4[1];
    fVar8 = pfVar3[2] - pfVar4[2];
    fVar11 = *pfVar3 - *pfVar4;
    fVar9 = fVar8 * fVar8 + fVar7 * fVar7 + fVar11 * fVar11;
    if (fVar9 == 0.0) {
      fVar9 = 0.0;
    }
    else {
      fVar9 = g_flOne / SQRT(fVar9);
    }
    uVar5 = (**(code **)(**(int **)(*(int *)(param_1 + 0x18) + 0xa0) + 0x19c))();
    fVar6 = (float10)FUN_0053e510(uVar5);
    piVar2 = *(int **)(*(int *)(param_1 + 0xbc) + 0x260);
    fVar10 = 0.0;
    if ((*piVar2 != 0) || (piVar2[2] != 0)) {
      pfVar3 = (float *)(**(code **)(*(int *)(*(int *)(*(int *)(*(int *)(param_1 + 0xbc) + 4) + 4) +
                                              4 + *(int *)(param_1 + 0xbc)) + 0x1a4))();
      fVar10 = pfVar3[1];
      fVar10 = fVar8 * fVar9 *
               (g_flOne - (*pfVar3 * *pfVar3 + fVar10 * fVar10) * g_flLevelUpUiBase_Inferred) +
               fVar7 * fVar9 *
               (pfVar3[2] * fVar10 - *pfVar3 * pfVar3[3]) * g_flLevelUpUiBase_Inferred +
               (pfVar3[2] * *pfVar3 + pfVar3[3] * pfVar3[1]) * g_flLevelUpUiBase_Inferred *
               fVar9 * fVar11;
    }
    piVar2 = *(int **)(*(int *)(param_1 + 0xbc) + 0x260);
    iVar1 = *piVar2;
    if (((iVar1 != 0) && (*(float *)(iVar1 + 0xdc) <= fVar10)) &&
       ((float)fVar6 < *(float *)(iVar1 + 0xe8))) {
      local_3c = 1;
    }
    if ((piVar2[1] != 0) && ((float)fVar6 < *(float *)(piVar2[1] + 0xe8))) {
      local_3c = local_3c | 2;
    }
    if ((piVar2[2] != 0) && (fVar10 < *(float *)(piVar2[2] + 0xdc) * DAT_00aaa668)) {
      local_3c = local_3c | 4;
    }
  }
  FUN_005021d0(local_3c);
  local_14 = 0xffffffff;
  FUN_0076cef0();
  ExceptionList = pvStack_1c;
  return;
}
