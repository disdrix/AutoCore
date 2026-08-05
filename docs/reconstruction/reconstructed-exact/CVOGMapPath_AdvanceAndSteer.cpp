// READABILITY (auto CF):
//  - Body size: ~191 non-empty decompiler lines.
//  - Control keywords: if×25, return×5, goto×4, for×1.
//  - Notable callees: ABS, CVOGReaction_ResolveObjectTarget, FUN_00788400, FUN_007a4480, SQRT, __RTDynamicCast.
//  - Strings: "Map Path has no points: CCOID:%I64d: %s\n".
//  - Return sites: 5.

// =============================================================================
// CVOGMapPath_AdvanceAndSteer
// -----------------------------------------------------------------------------
// Purpose:  Advance along a map path polyline (point stride 0x20): pick/advance index,
//           fire ReactionCoid in accept radius, output aim point / curvature
//           radius for driver steering.
//
// Address:  0x005df950  (autoassault.exe, image base 0x400000)
// Stable:   aa_005df950
// System:   npc-ai / map-path
//
// Args (thiscall): path*, pos*, pIndex, outAim*, ctx, pReverseFlag*, outR*, ...
// Control flow:
//   1) Empty points -> assert log; return 0
//   2) index out of range -> 0
//   3) index==-1 -> nearest-point scan (stride 0x20)
//   4) Else get point via vtbl+0x2c0
//   5) Outside accept radius (point[3]) -> steer helper vtbl+0x2c4
//   6) Inside: ResolveObjectTarget reaction COID; fire vtbl+0x114;
//      advance or reverse index (*pReverseFlag)
// Server design note: NpcVehiclePathFollower mirrors this accept/advance.
//
// Exactness: CF mirrors raw; names cleaned; no invented clamps.
// Bit-for-bit / runtime / differential: DEFERRED / OPEN.
// Human-refined plate: 2026-07-23 (AI managers readability)
// =============================================================================

/* WARNING: Globals starting with '_' overlap smaller symbols at the same address */
/* AutoCore Phase D: Map path advance. Point stride 0x20. Fires ReactionCoid on accept radius.
   ReverseDirection wraps path. Used by server NpcVehiclePathFollower design. */
uint32_t /* width from decompiler */ __thiscall
CVOGMapPath_AdvanceAndSteer
          (int *param_1,float *param_2,uint *param_3,float *param_4,uint32_t /* width from decompiler */ param_5,char *param_6
          ,float *param_7,float *param_8)
{
  int iVar1;
  int iVar2;
  float *pfVar3;
  uint32_t /* width from decompiler */ uVar4;
  int *piVar5;
  uint uVar6;
  float unaff_EBX;
  uint uVar7;
  uint uVar8;
  float10 fVar9;
  float fVar10;
  float fVar11;
  float fVar12;
  float fVar13;
  float fVar14;
  float fVar15;
  float fVar16;
  uint32_t /* width from decompiler */ uVar17;
  TypeDescriptor *pTVar18;
  TypeDescriptor *pTVar19;
  uint32_t /* width from decompiler */ uVar20;
  float afStack_40 [2];
  uint8_t auStack_38 [4];
  int local_34;
  uint8_t auStack_28 [36];
  
  if ((param_1[0x65] == 0) || (local_34 = param_1[0x66] - param_1[0x65] >> 5, local_34 == 0)) {
    FUN_007a4480(1,"Map Path has no points: CCOID:%I64d: %s\n",param_1[0x58],param_1[0x59],
                 param_1[0x29] + 0xb4);
    return 0;
  }
  if (param_1[0x65] == 0) {
    iVar2 = 0;
  }
  else {
    iVar2 = param_1[0x66] - param_1[0x65] >> 5;
  }
  uVar7 = *param_3;
  if (iVar2 <= (int)uVar7) {
    return 0;
  }
  pfVar3 = (float *)0x0;
  if (uVar7 == 0xffffffff) {
    iVar2 = 0;
    fVar12 = DAT_009dbb60;
    for (uVar7 = 0;
        (iVar1 = param_1[0x65], iVar1 != 0 && (uVar7 < (uint)(param_1[0x66] - iVar1 >> 5)));
        uVar7 = uVar7 + 1) {
      fVar10 = *param_2 - *(float *)(iVar1 + iVar2);
      fVar13 = param_2[1] - *(float *)(iVar1 + 4 + iVar2);
      fVar15 = param_2[2] - *(float *)(iVar1 + 8 + iVar2);
      fVar10 = fVar15 * fVar15 + fVar13 * fVar13 + fVar10 * fVar10;
      if (fVar10 < fVar12) {
        *param_3 = uVar7;
        pfVar3 = (float *)(iVar1 + iVar2);
        fVar12 = fVar10;
      }
      iVar2 = iVar2 + 0x20;
    }
  }
  else {
    pfVar3 = (float *)(**(code **)(*param_1 + 0x2c0))(uVar7);
  }
  if (pfVar3 == (float *)0x0) {
    return 0;
  }
  if (pfVar3[3] * pfVar3[3] <=
      (pfVar3[2] - param_2[2]) * (pfVar3[2] - param_2[2]) +
      (pfVar3[1] - param_2[1]) * (pfVar3[1] - param_2[1]) +
      (*pfVar3 - *param_2) * (*pfVar3 - *param_2)) {
    (**(code **)(*param_1 + 0x2c4))(*param_3,param_4);
  }
  else {
    uVar20 = 0;
    pTVar19 = &CVOGReaction::RTTI_Type_Descriptor;
    pTVar18 = &CVOGClonedObjectBase::RTTI_Type_Descriptor;
    uVar17 = 0;
    uVar4 = CVOGReaction_ResolveObjectTarget(0,pfVar3[4],pfVar3[5]);
    piVar5 = (int *)__RTDynamicCast(uVar4,uVar17,pTVar18,pTVar19,uVar20);
    if (piVar5 != (int *)0x0) {
      (**(code **)(*piVar5 + 0x114))(param_5);
    }
    if (*param_6 == '\0') {
      *param_3 = *param_3 + 1;
    }
    else {
      *param_3 = *param_3 - 1;
      if ((int)*param_3 < 0) {
        *param_6 = '\0';
        *param_3 = *param_3 + 2;
      }
    }
    if (param_1[0x65] == 0) {
      iVar2 = 0;
    }
    else {
      iVar2 = param_1[0x66] - param_1[0x65] >> 5;
    }
    if (iVar2 <= (int)*param_3) {
      if ((char)param_1[0x68] == '\0') {
        *param_3 = 0;
      }
      else {
        *param_6 = '\x01';
        if (param_1[0x65] == 0) {
          *param_3 = 0xfffffffe;
        }
        else {
          *param_3 = (param_1[0x66] - param_1[0x65] >> 5) - 2;
        }
      }
    }
    (**(code **)(*param_1 + 0x2c4))(*param_3,param_4);
  }
  uVar7 = *param_3 - 1;
  uVar6 = uVar7;
  if (-1 < (int)uVar7) goto LAB_005dfc48;
  iVar2 = param_1[0x65];
  if ((char)param_1[0x68] == '\0') {
    if (iVar2 == 0) {
      iVar2 = 0;
    }
    else {
      iVar2 = param_1[0x66] - iVar2 >> 5;
    }
    if (iVar2 != 1) {
      if (param_1[0x65] == 0) {
        uVar6 = 0xffffffff;
      }
      else {
        uVar6 = (param_1[0x66] - param_1[0x65] >> 5) - 1;
      }
      goto LAB_005dfc48;
    }
  }
  else {
    if ((iVar2 != 0) && (1 < (uint)(param_1[0x66] - iVar2 >> 5))) {
      uVar6 = 1;
      goto LAB_005dfc48;
    }
    if (param_1[0x65] != 0) {
      uVar6 = param_1[0x66] - param_1[0x65] >> 5;
      goto LAB_005dfc48;
    }
  }
  uVar6 = 0;
LAB_005dfc48:
  uVar8 = *param_3 + 1;
  if (param_1[0x65] == 0) {
    iVar2 = 0;
  }
  else {
    iVar2 = param_1[0x66] - param_1[0x65] >> 5;
  }
  if (iVar2 + -1 < (int)uVar8) {
    if ((char)param_1[0x68] == '\0') {
      uVar8 = 0;
    }
    else {
      uVar8 = ((int)uVar7 < 1) - 1 & uVar7;
    }
  }
  (**(code **)(*param_1 + 0x2c4))(uVar6,auStack_28);
  (**(code **)(*param_1 + 0x2c4))(uVar8,afStack_40);
  fVar9 = (float10)FUN_00788400(param_2,auStack_38,param_4);
  *param_7 = (float)fVar9;
  fVar12 = param_4[2];
  fVar10 = *param_4;
  fVar13 = *param_2;
  fVar15 = param_2[2];
  fVar14 = fVar12 * fVar12 + fVar10 * fVar10;
  fVar11 = ((fVar15 * fVar15 + fVar13 * fVar13) - fVar14) * DAT_00a0f298;
  fVar14 = ((fVar14 - unaff_EBX * unaff_EBX) - afStack_40[0] * afStack_40[0]) * DAT_00a0f298;
  fVar16 = (fVar13 - fVar10) * (fVar12 - afStack_40[0]) - (fVar15 - fVar12) * (fVar10 - unaff_EBX);
  if (_DAT_00a110e4 <= ABS(fVar16)) {
    fVar16 = g_flOne / fVar16;
    fVar12 = (fVar11 * (fVar12 - afStack_40[0]) - (fVar15 - fVar12) * fVar14) * fVar16 - fVar13;
    fVar15 = ((fVar13 - fVar10) * fVar14 - fVar11 * (fVar10 - unaff_EBX)) * fVar16 - fVar15;
    *param_8 = SQRT(fVar15 * fVar15 + fVar12 * fVar12);
    return 1;
  }
  *param_8 = DAT_00a0f520;
  return 1;
}
