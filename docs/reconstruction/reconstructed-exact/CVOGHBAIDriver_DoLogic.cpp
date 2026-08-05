// READABILITY (auto CF):
//  - Body size: ~177 non-empty decompiler lines.
//  - Control keywords: if×27, return×2, goto×2.
//  - Notable callees: FUN_005cc450×3, FUN_005cc980×3, FUN_005cedf0×3, NPC_TryCastSkillFromSet×3, AI_CheckSlotTimerReady×2, CVOGHBAIDriver_ReturnToNormalLocation×2, CVOGReaction_RandomUnitScalar×2, FUN_00540890×2.
//  - Strings: "CVOGHBAIDriver::DoLogic".
//  - Return sites: 2.

// =============================================================================
// CVOGHBAIDriver_DoLogic
// -----------------------------------------------------------------------------
// Purpose:  Main NPC vehicle-driver AI tick. State machine on owner+0x26c (idle / engage
//           / combat): cast skills, slot timer, leash via ReturnToNormalLocation
//           or pursue, always FireWeapons at end (weapons decoupled from drive).
//
// Address:  0x005d7750  (autoassault.exe, image base 0x400000)
// Stable:   aa_005d7750
// System:   npc-ai / HBAI
//
// Convention: __fastcall this = Driver HBAI*.
// Scoped string: "CVOGHBAIDriver::DoLogic".
//
// Control flow summary:
//   1) Bail if path/context this[0x2f] missing
//   2) Resolve profile params (attack/engage thresholds)
//   3) owner+0x26c == 0 (idle):
//        clear counter; NPC_TryCastSkillFromSet(0);
//        AI_CheckSlotTimerReady -> vtbl action if ready;
//        if target this[6]+0xa0: set state 2 via vtbl+0x2c
//        else leash: ReturnToNormalLocation / patrol helpers
//   4) state == 1 (engage): timer this[0x2d] vs profile; cast set(1);
//        promote to combat (2) or drop to idle (0)
//   5) state == 2 (combat): pursue + skills (see raw body tail)
//   6) Always: CVOGHBAIFollowVehicle_FireWeapons (weapon geometry masks)
//
// Related: ReturnToNormalLocation 0x005d6e80, DoVehiclePursue 0x005cfb60,
//   MapPath_AdvanceAndSteer 0x005df950, FireWeapons 0x005d7100.
//
// Exactness: CF mirrors raw; names cleaned; no invented clamps.
// Bit-for-bit / runtime / differential: DEFERRED / OPEN.
// Human-refined plate: 2026-07-23 (AI managers readability)
// =============================================================================

/* WARNING: Globals starting with '_' overlap smaller symbols at the same address */
/* AutoCore Phase D: NPC vehicle driver AI main tick. State machine on owner+0x26c (0 idle/patrol, 1
   engage, 2 combat). Calls ReturnToNormalLocation, DoVehiclePursue, FireWeapons. Client-side
   simulation. */
void __fastcall CVOGHBAIDriver_DoLogic(int *this)
{
  float *pfVar1;
  ushort uVar2;
  float fVar3;
  int *piVar4;
  char cVar5;
  int iVar6;
  uint uVar7;
  uint32_t /* width from decompiler */ uVar8;
  int *piVar9;
  uint unaff_EBP;
  int **ppiVar10;
  uint *puVar11;
  int *local_18;
  uint local_14;
  uint32_t /* width from decompiler */ local_10;
  void *local_c;
  uint8_t *puStack_8;
  uint32_t /* width from decompiler */ local_4;
  
  local_4 = 0xffffffff;
  puStack_8 = &LAB_009a7199;
  local_c = ExceptionList;
  local_10 = DAT_00d1f040;
  ExceptionList = &local_c;
  FUN_0076cf00("CVOGHBAIDriver::DoLogic");
  local_4 = 0;
  if ((this[0x2f] == 0) || (*(int *)(this[0x2f] + 8) == 0)) {
    local_4 = 0xffffffff;
    FUN_0076cef0();
    ExceptionList = local_c;
    return;
  }
  local_14 = *(uint *)(*(int *)(*(int *)(*(int *)(*(int *)(this[0x19] + 4) + 4) + 0xac + this[0x19])
                               + 0x3c) + 0x4dc);
  puVar11 = &local_14;
  ppiVar10 = &local_18;
  FUN_00540890(0);
  FUN_004cbd50(ppiVar10,puVar11);
  iVar6 = FUN_00540890(0);
  piVar4 = local_18;
  if (local_18 == *(int **)(iVar6 + 4)) goto LAB_005d7800;
  local_14 = local_14 & 0xffffff00;
  if (*(char *)(this[0x19] + 0x26c) == '\0') {
    *(uint8_t *)(this + 0x2e) = 0;
    NPC_TryCastSkillFromSet(this,0);
    uVar7 = AI_CheckSlotTimerReady(this,(void *)0x0,unaff_EBP);
    if ((char)uVar7 != '\0') {
      (**(code **)(*this + 0x1c))();
    }
    if (*(int *)(this[6] + 0xa0) != 0) {
      (**(code **)(*this + 0x2c))(2);
    }
    if (*(char *)(this[0x19] + 0x305) == '\0') {
      FUN_005cedf0();
      if ((char)this[0x18] == '\0') {
        cVar5 = FUN_005cc980();
        if ((cVar5 == '\0') && (cVar5 = CVOGHBAIDriver_ReturnToNormalLocation(), cVar5 == '\0')) {
          iVar6 = *this;
          uVar8 = (**(code **)(*(int *)this[6] + 0x1a0))(1);
          (**(code **)(iVar6 + 0x4c))(uVar8);
        }
      }
      else {
        FUN_005cc450();
      }
    }
  }
  else if (*(char *)(this[0x19] + 0x26c) == '\x01') {
    if (this[0x2d] == 0) {
      *(char *)(this + 0x2e) = (char)this[0x2e] + '\x01';
      this[0x2d] = g_dwClientTickMs;
    }
    NPC_TryCastSkillFromSet(this,1);
    piVar9 = (int *)(g_dwClientTickMs - this[0x2d]);
    fVar3 = (float)(int)piVar9;
    if ((int)piVar9 < 0) {
      fVar3 = fVar3 + _DAT_00aaa5dc;
    }
    pfVar1 = (float *)(local_18 + 5);
    local_18 = piVar9;
    if (*pfVar1 < fVar3) {
LAB_005d7a53:
      this[0x2d] = 0;
      if (*(int *)(this[6] + 0xa0) == 0) {
        (**(code **)(*this + 0x2c))(0);
      }
      else {
        (**(code **)(*this + 0x2c))(2);
      }
    }
    else {
      piVar9 = (int *)this[6];
      local_18 = piVar9;
      iVar6 = (**(code **)(*piVar9 + 0x1b0))();
      local_18 = (int *)(float)iVar6;
      iVar6 = (**(code **)(*piVar9 + 0x1ac))();
      if ((float)piVar4[6] <= (float)local_18 / (float)iVar6) goto LAB_005d7a53;
    }
    FUN_005cedf0();
    if ((char)this[0x18] == '\0') {
      cVar5 = FUN_005cc980();
      if (cVar5 == '\0') {
        FUN_005ccbd0();
      }
    }
    else {
      FUN_005cc450();
    }
  }
  else {
    NPC_TryCastSkillFromSet(this,2);
    uVar7 = AI_CheckSlotTimerReady(this,(void *)0x0,unaff_EBP);
    if ((char)uVar7 != '\0') {
      piVar9 = (int *)this[6];
      local_18 = piVar9;
      iVar6 = (**(code **)(*piVar9 + 0x1b0))();
      local_18 = (int *)(float)iVar6;
      iVar6 = (**(code **)(*piVar9 + 0x1ac))();
      local_18 = (int *)((float)local_18 / (float)iVar6);
      iVar6 = CVOGReaction_RandomUnitScalar();
      if (0xfffff < *(int *)(iVar6 + 0xc)) {
        *(uint32_t /* width from decompiler */ *)(iVar6 + 0xc) = 0;
      }
      uVar2 = *(ushort *)(*(int *)(iVar6 + 8) + *(int *)(iVar6 + 0xc) * 2);
      *(int *)(iVar6 + 0xc) = *(int *)(iVar6 + 0xc) + 1;
      if (((float)uVar2 * DAT_00aaa638 < (float)piVar4[9]) && ((float)local_18 <= (float)piVar4[10])
         ) {
        FUN_00638cd0(piVar4[0xb]);
      }
      iVar6 = CVOGReaction_RandomUnitScalar();
      if (0xfffff < *(int *)(iVar6 + 0xc)) {
        *(uint32_t /* width from decompiler */ *)(iVar6 + 0xc) = 0;
      }
      uVar2 = *(ushort *)(*(int *)(iVar6 + 8) + *(int *)(iVar6 + 0xc) * 2);
      *(int *)(iVar6 + 0xc) = *(int *)(iVar6 + 0xc) + 1;
      if (((float)uVar2 * DAT_00aaa638 < (float)piVar4[8] / (float)(*(byte *)(this + 0x2e) + 1)) &&
         ((float)local_18 <= (float)piVar4[7])) {
        (**(code **)(*this + 0x2c))(1);
      }
    }
    if (*(int *)(this[6] + 0xa0) == 0) {
      (**(code **)(*this + 0x2c))(0);
    }
    if (*(char *)(this[0x19] + 0x305) == '\0') {
      FUN_005cedf0();
      if (*(int *)(this[6] + 0xa0) != 0) {
        local_14 = CONCAT31(local_14._1_3_,1);
      }
      if ((char)this[0x18] == '\0') {
        cVar5 = FUN_005cc980();
        if (((cVar5 == '\0') && (cVar5 = CVOGHBAIDriver_ReturnToNormalLocation(), cVar5 == '\0')) &&
           (*(int *)(this[6] + 0xa0) != 0)) {
          CVOGHBAICreatureBase_DoVehiclePursue(this);
        }
      }
      else {
        FUN_005cc450();
      }
    }
  }
  if (*(char *)(*(int *)(*(int *)(*(int *)(this[0x2f] + 4) + 4) + 0xa8 + this[0x2f]) + 0x7e) != '\0'
     ) {
    FUN_005d73f0();
  }
  CVOGHBAIFollowVehicle_FireWeapons(local_14,0);
  FUN_005d6de0(0x40000000,0,0x41700000);
LAB_005d7800:
  local_4 = 0xffffffff;
  FUN_0076cef0();
  ExceptionList = local_c;
  return;
}
