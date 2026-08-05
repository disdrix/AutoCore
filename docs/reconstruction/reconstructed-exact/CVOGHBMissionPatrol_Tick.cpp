// READABILITY (auto CF):
//  - Body size: ~51 non-empty decompiler lines.
//  - Control keywords: if×6, goto×3, return×2, do×1, while×1.
//  - Notable callees: FUN_00574760×2, FUN_00578b30×2, CVOGHBMissionPatrol_Tick, FUN_00578270, __RTDynamicCast.
//  - Return sites: 2.

// =============================================================================
// CVOGHBMissionPatrol_Tick
// -----------------------------------------------------------------------------
// Purpose:  Mission patrol heartbeat tick: advance patrol objective / path for mission
//           HB instances scheduled on the map list.
//
// Address:  0x00650f90  (autoassault.exe, image base 0x400000)
// Stable:   aa_00650f90
// System:   npc-ai / mission-patrol HB
//
// Virtual OnHeartBeat-style for mission patrol type.
// Ties to objective patrol requirements (missions-progression).
//
// Exactness: CF mirrors raw; names cleaned; no invented clamps.
// Bit-for-bit / runtime / differential: DEFERRED / OPEN.
// Human-refined plate: 2026-07-23 (AI managers readability)
// =============================================================================

void __fastcall CVOGHBMissionPatrol_Tick(int *param_1)
{
  int iVar1;
  int iVar2;
  int iVar3;
  int iVar4;
  int unaff_EBP;
  int iVar5;
  float fVar6;
  uint uVar7;
  
  iVar5 = 0;
  iVar1 = __RTDynamicCast(param_1[6],0,&CVOGClonedObjectBase::RTTI_Type_Descriptor,
                          &CVOGCharacter::RTTI_Type_Descriptor,0);
  iVar3 = *(int *)(iVar1 + 0xcb0);
  iVar2 = FUN_00578270();
  uVar7 = 0;
  if (iVar3 == 0) {
    if (param_1[6] == iVar2) {
LAB_00651046:
      (**(code **)(*param_1 + 0x50))();
      fVar6 = (float)unaff_EBP * (float)param_1[0x61] + (float)param_1[0x41];
      if (fVar6 != (float)param_1[0x1b0]) {
        *(float *)(iVar1 + 0xc54) = (fVar6 - (float)param_1[0x1b0]) + *(float *)(iVar1 + 0xc54);
        param_1[0x1b0] = (int)fVar6;
        FUN_00578b30(uVar7);
        return;
      }
      goto LAB_00650fd8;
    }
  }
  else {
    uVar7 = (uint)*(byte *)(iVar3 + 0x1d8);
    if (param_1[6] == iVar2) goto LAB_00651046;
    do {
      iVar3 = FUN_00574760(iVar5);
      if (iVar3 != 0) {
        iVar4 = FUN_00574760(iVar5);
        iVar2 = *(int *)(*(int *)(iVar4 + 4) + 4);
        iVar3 = iVar2 + 0x164 + iVar4;
        if (((*(int *)(iVar2 + 0x164 + iVar4) == param_1[0x196]) &&
            (*(int *)(iVar3 + 4) == param_1[0x197])) &&
           (*(char *)(iVar3 + 8) == (char)param_1[0x198])) goto LAB_00651046;
      }
      iVar5 = iVar5 + 1;
    } while (iVar5 < 4);
  }
  (**(code **)(*param_1 + 0x18))(1,1);
LAB_00650fd8:
  FUN_00578b30(uVar7);
  return;
}
