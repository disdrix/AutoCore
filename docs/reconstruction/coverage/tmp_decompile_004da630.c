
/* WARNING: Removing unreachable block (ram,0x004dad5f) */
/* CVOGCombat_OnDeathAwardKillXp — death/loot → kill XP (docs/XP.md)
   
   Builds participation mult (XPPercent * share * convoy terms),
   loops up to 4 in-range convoy members, then
   CVOGCombat_CalculateAndAwardKillXP per recipient.
   
   INFERRED full convoy distance/share bookkeeping — see call sites.
   AutoCore: KillXpAward.TryAward on authoritative death.
   Returns: void (award side effects) */

void * __thiscall CVOGCombat_OnDeathAwardKillXp(int param_1,int *param_2,int *param_3)

{
  float fVar1;
  ushort uVar2;
  char cVar3;
  char cVar4;
  void *pvVar5;
  void *pvVar6;
  int iVar7;
  float *pfVar8;
  int iVar9;
  int *piVar10;
  int *piVar11;
  undefined4 uVar12;
  uint uVar13;
  int unaff_EDI;
  float10 fVar14;
  longlong lVar15;
  undefined8 uVar16;
  int nConvoyMemberCount;
  int local_80;
  int iStack_7c;
  int local_78;
  float local_74;
  float fStack_70;
  int iStack_6c;
  int iStack_68;
  undefined1 auStack_4c [4];
  int *piStack_48;
  int iStack_44;
  float fStack_40;
  int iStack_3c;
  float fStack_38;
  int iStack_34;
  int iStack_30;
  int iStack_2c;
  void *pvStack_28;
  int iStack_24;
  void *local_1c;
  undefined1 *puStack_18;
  undefined4 uStack_14;
  
  uStack_14 = 0xffffffff;
  puStack_18 = &LAB_009a22ad;
  local_1c = ExceptionList;
  if (param_2 == (int *)0x0) {
    return ExceptionList;
  }
  local_78 = 0;
  local_80 = 0;
  local_74 = g_flOne;
  ExceptionList = &local_1c;
  pvVar5 = (void *)(**(code **)(*param_2 + 0x210))(0);
  if (pvVar5 == (void *)0x0) {
    ExceptionList = local_1c;
    return (void *)0x0;
  }
  if (DAT_00b037e8 == 0) {
    pvVar6 = operator_new(0xbc);
    uStack_14 = 0;
    if (pvVar6 == (void *)0x0) {
      DAT_00b037e8 = 0;
    }
    else {
      DAT_00b037e8 = FUN_0050c1b0(DAT_00b041fc);
    }
    uStack_14 = 0xffffffff;
  }
  (**(code **)(*param_3 + 0x144))();
  fStack_40 = (float)param_3[0x20];
  iStack_3c = param_3[0x21];
  fStack_38 = (float)param_3[0x22];
  iStack_34 = param_3[0x23];
  iVar7 = (**(code **)(*param_3 + 0x210))(0);
  if (iVar7 != 0) {
    (**(code **)(*param_3 + 0x210))(0);
    fVar14 = (float10)FUN_0051f7b0();
    local_74 = (float)fVar14;
    if ((((*(char *)(param_1 + 0x100) != '\0') && (*(int *)(param_1 + 0x108) != -1)) &&
        (*(int *)(param_1 + 0xac) == 3)) &&
       ((iVar7 = (**(code **)(*param_3 + 0x210))(0), *(char *)(iVar7 + 0x529) != '\0' &&
        (pvVar6 = (void *)(**(code **)(*param_3 + 0x210))(0), pvVar5 != pvVar6)))) {
      if (*(int *)((int)pvVar5 + 0xcb0) == 0) {
        iVar7 = (**(code **)(*param_3 + 0x210))(0);
        if (iVar7 == 0) {
          iVar7 = 0;
        }
        else {
          iVar7 = *(int *)(*(int *)(iVar7 + 4) + 4) + 4 + iVar7;
        }
        FUN_004d31a0(*(int *)(*(int *)((int)pvVar5 + 4) + 4) + 4 + (int)pvVar5,iVar7);
      }
      else {
        fStack_70 = 0.0;
        do {
          iVar7 = FUN_00574760(fStack_70);
          if ((iVar7 != 0) &&
             (pfVar8 = (float *)(**(code **)(*(int *)(*(int *)(*(int *)(iVar7 + 4) + 4) + 4 + iVar7)
                                            + 0x1a0))(),
             SQRT((fStack_38 - pfVar8[2]) * (fStack_38 - pfVar8[2]) +
                  (fStack_40 - *pfVar8) * (fStack_40 - *pfVar8)) < DAT_00aaa8a8)) {
            iVar9 = (**(code **)(*param_3 + 0x210))(0);
            if (iVar9 != 0) {
              iVar9 = *(int *)(*(int *)(iVar9 + 4) + 4) + 4 + iVar9;
            }
            FUN_004d31a0(*(int *)(*(int *)(iVar7 + 4) + 4) + 4 + iVar7,iVar9);
          }
          fStack_70 = (float)((int)fStack_70 + 1);
        } while ((int)fStack_70 < 4);
      }
    }
  }
  if (*(int *)(param_3[0x2a] + 0x38) == 0xe) {
    local_80 = (**(code **)(*param_3 + 0x1d4))();
    iStack_7c = FUN_004f4e50();
    iVar7 = (**(code **)(*(int *)(*(int *)(*(int *)(local_80 + 4) + 4) + 4 + local_80) + 0x214))();
    iStack_6c = *(int *)(*(int *)(*(int *)(*(int *)(iVar7 + 4) + 4) + 0xac + iVar7) + 0x3c);
    (**(code **)(*(int *)(*(int *)(*(int *)(local_80 + 4) + 4) + 4 + local_80) + 0x214))();
    fVar14 = (float10)FUN_004c4b20();
    iVar7 = (**(code **)(*(int *)(*(int *)(*(int *)(local_80 + 4) + 4) + 4 + local_80) + 0x214))();
    cVar4 = *(char *)(iVar7 + 0x30a);
  }
  else {
    if (*(int *)(param_3[0x2a] + 0x38) != 0x12) goto LAB_004dae57;
    local_78 = (**(code **)(*param_3 + 0x214))();
    iStack_7c = (**(code **)(*(int *)(*(int *)(*(int *)(local_78 + 4) + 4) + 4 + local_78) + 0x27c))
                          ();
    cVar3 = FUN_004c4aa0();
    cVar4 = *(char *)(local_78 + 0x30a);
    iStack_6c = *(int *)(*(int *)(*(int *)(*(int *)(local_78 + 4) + 4) + 0xac + local_78) + 0x3c);
    fVar14 = (float10)FUN_004c4b20();
    if (cVar3 == '\0') goto LAB_004dae57;
  }
  fStack_70 = (float)fVar14;
  if (iStack_6c == 0) goto LAB_004dae57;
  if ((cVar4 == '\0') || (iVar7 = (**(code **)(*param_3 + 0x214))(), iVar7 == 0)) {
    if (*(int *)((int)pvVar5 + 0xcb0) == 0) {
      fStack_70 = *(float *)(iStack_6c + 0x500) * local_74 * fStack_70;
      nConvoyMemberCount = 0;
      iVar7 = iStack_7c;
      pvVar6 = pvVar5;
      iVar9 = (**(code **)(*(int *)(*(int *)(*(int *)((int)pvVar5 + 4) + 4) + 4 + (int)pvVar5) +
                          0x27c))();
      CVOGCombat_CalculateAndAwardKillXP(iVar9,iVar7,fStack_70,pvVar6,nConvoyMemberCount,unaff_EDI);
    }
    else {
      FUN_00574900();
      iVar7 = FUN_00574e60(pvVar5);
      iStack_68 = 0;
      do {
        pvVar6 = (void *)FUN_00574760(iStack_68);
        if (((pvVar6 != (void *)0x0) && (iVar9 = *(int *)((int)pvVar6 + 0x250), iVar9 != 0)) &&
           (cVar4 = (**(code **)(*(int *)(*(int *)(*(int *)(iVar9 + 4) + 4) + 4 + iVar9) + 0x198))()
           , cVar4 == '\0')) {
          iVar9 = (**(code **)(*(int *)(*(int *)(*(int *)((int)pvVar6 + 4) + 4) + 4 + (int)pvVar6) +
                              0x27c))();
          pfVar8 = (float *)(**(code **)(*(int *)(*(int *)(*(int *)((int)pvVar6 + 4) + 4) + 4 +
                                                 (int)pvVar6) + 0x1a0))();
          if (SQRT((fStack_38 - pfVar8[2]) * (fStack_38 - pfVar8[2]) +
                   (fStack_40 - *pfVar8) * (fStack_40 - *pfVar8)) < DAT_00aaa8a8) {
            CVOGCombat_CalculateAndAwardKillXP
                      (iVar9,iStack_7c,*(float *)(iStack_6c + 0x500) * local_74 * fStack_70,pvVar6,
                       iVar7,unaff_EDI);
          }
        }
        iStack_68 = iStack_68 + 1;
      } while (iStack_68 < 4);
      FUN_00574910();
    }
  }
  else {
    iVar7 = (**(code **)(*param_3 + 0x214))();
    piVar10 = *(int **)(iVar7 + 0x158);
    piVar11 = (int *)*piVar10;
    while (piVar11 != piVar10) {
      if (((0 < piVar11[8]) &&
          (piVar10 = Object_ResolveFromTFID((TFID_16 *)(piVar11 + 4)), piVar10 != (int *)0x0)) &&
         ((pvVar6 = (void *)(**(code **)(*piVar10 + 0x210))(0), pvVar6 != (void *)0x0 &&
          ((iVar9 = *(int *)((int)pvVar6 + 0x250), iVar9 != 0 &&
           (cVar4 = (**(code **)(*(int *)(*(int *)(*(int *)(iVar9 + 4) + 4) + 4 + iVar9) + 0x198))()
           , cVar4 == '\0')))))) {
        iVar9 = (**(code **)(*(int *)(*(int *)(*(int *)((int)pvVar6 + 4) + 4) + 4 + (int)pvVar6) +
                            0x27c))();
        pfVar8 = (float *)(**(code **)(*(int *)(*(int *)(*(int *)((int)pvVar6 + 4) + 4) + 4 +
                                               (int)pvVar6) + 0x1a0))();
        if (SQRT((fStack_38 - pfVar8[2]) * (fStack_38 - pfVar8[2]) +
                 (fStack_40 - *pfVar8) * (fStack_40 - *pfVar8)) < DAT_00aaa8a8) {
          CVOGCombat_CalculateAndAwardKillXP
                    (iVar9,iStack_7c,*(float *)(iStack_6c + 0x500) * local_74 * fStack_70,pvVar6,4,
                     unaff_EDI);
        }
      }
      FUN_004cb270();
      piVar10 = *(int **)(iVar7 + 0x158);
    }
  }
  pvVar6 = *(void **)(*(int *)(*(int *)((int)pvVar5 + 4) + 4) + 0xa8 + (int)pvVar5);
  if (*(char *)((int)pvVar6 + 0xf6) != '\0') {
    ExceptionList = local_1c;
    return pvVar6;
  }
  local_74 = -NAN;
  if (local_80 == 0) {
    if (local_78 != 0) {
      local_74 = *(float *)(*(int *)(*(int *)(*(int *)(*(int *)(local_78 + 4) + 4) + 0xac + local_78
                                             ) + 0x3c) + 0x514);
    }
  }
  else {
    iVar7 = FUN_005001f0();
    local_74 = *(float *)(iVar7 + 0x178);
  }
  iVar7 = (**(code **)(*(int *)(*(int *)(*(int *)((int)pvVar5 + 4) + 4) + 4 + (int)pvVar5) + 0x27c))
                    ();
  if (iVar7 - iStack_7c < 0xb) {
    if (local_78 == 0) {
      if (local_80 == 0) goto LAB_004dae57;
      piVar11 = *(int **)(*(int *)(*(int *)(local_80 + 4) + 4) + 0xb0 + local_80);
      if ((piVar11 == (int *)0x0) || (iVar7 = (**(code **)(*piVar11 + 0x1d8))(), iVar7 == 0))
      goto LAB_004dad8c;
    }
    lVar15 = FUN_00508e70(pvVar5,local_74);
    if (0 < lVar15) {
      uVar16 = FUN_00521510(&fStack_40);
      FUN_004d2750(lVar15,&fStack_40,0x41200000,1,uVar16);
    }
  }
LAB_004dad8c:
  if (local_80 == 0) {
    if (local_78 == 0) goto LAB_004dae57;
    piVar11 = (int *)FUN_00404c90();
    iStack_30 = *piVar11;
    iStack_2c = piVar11[1];
    pvStack_28 = (void *)piVar11[2];
    iStack_24 = piVar11[3];
    if (*(int *)(local_78 + 0x250) != 0) goto LAB_004dade2;
  }
  else {
LAB_004dade2:
    piVar11 = (int *)FUN_00404c90();
    iStack_30 = *piVar11;
    iStack_2c = piVar11[1];
    pvStack_28 = (void *)piVar11[2];
    iStack_24 = piVar11[3];
  }
  if (-1 < (int)local_74) {
    FUN_0050ac80(pvVar5,param_1,&iStack_30,iStack_7c,local_74,0,0);
  }
  FUN_004d4440(iStack_7c,pvVar5,&fStack_40,local_74,0,0);
LAB_004dae57:
  pvVar6 = *(void **)(*(int *)(*(int *)((int)pvVar5 + 4) + 4) + 0xa8 + (int)pvVar5);
  if (*(char *)((int)pvVar6 + 0xf6) == '\0') {
    if (DAT_00b037e8 != 0) {
      piStack_48 = (int *)FUN_0040fb90();
      iStack_44 = 0;
      uStack_14 = 1;
      if (param_3[0x2a] == 0) {
        uVar12 = 0xffffffff;
      }
      else {
        uVar12 = *(undefined4 *)(param_3[0x2a] + 0x34);
      }
      FUN_0050aa80(uVar12,param_3[0x29],
                   *(undefined1 *)
                    (*(int *)(*(int *)(*(int *)(*(int *)((int)pvVar5 + 4) + 4) + 0xac + (int)pvVar5)
                             + 0x3c) + 0x532),auStack_4c);
      if ((iStack_44 != 0) && (piVar11 = (int *)*piStack_48, piVar11 != piStack_48)) {
        do {
          if (local_80 == 0) {
LAB_004daf39:
            uVar16 = FUN_00521510(&fStack_40);
            *(undefined8 *)(piVar11[2] + 0x170) = uVar16;
            FUN_004d2820(piVar11[2],&fStack_40,0x3f800000,1);
          }
          else {
            iVar7 = *(int *)(*(int *)(local_80 + 4) + 4);
            iVar9 = (**(code **)(*(int *)piVar11[2] + 0x27c))();
            iVar7 = (**(code **)(*(int *)(iVar7 + 4 + local_80) + 0x27c))();
            if (iVar9 <= iVar7) goto LAB_004daf39;
          }
          piVar11 = (int *)*piVar11;
        } while (piVar11 != piStack_48);
      }
      FUN_00404060();
      FUN_00509010(param_3,*(undefined1 *)
                            (*(int *)(*(int *)(*(int *)(*(int *)((int)pvVar5 + 4) + 4) + 0xac +
                                              (int)pvVar5) + 0x3c) + 0x532),auStack_4c);
      if ((iStack_44 != 0) && (piVar11 = (int *)*piStack_48, piVar11 != piStack_48)) {
        do {
          uVar16 = FUN_00521510(&fStack_40);
          *(undefined8 *)(piVar11[2] + 0x170) = uVar16;
          FUN_004d2820(piVar11[2],&fStack_40,0x3f800000,1);
          piVar11 = (int *)*piVar11;
        } while (piVar11 != piStack_48);
      }
      uStack_14 = 0xffffffff;
      FUN_00403430();
    }
    pvVar6 = (void *)param_3[0x2a];
    fStack_70 = 0.0;
    if ((*(int *)((int)pvVar6 + 0x38) == 0x12) &&
       (pvVar6 = (void *)__RTDynamicCast(param_3,0,&CVOGClonedObjectBase::RTTI_Type_Descriptor,
                                         &CVOGCreature::RTTI_Type_Descriptor,0),
       pvVar6 != (void *)0x0)) {
      fStack_70 = *(float *)((int)pvVar6 + 600);
    }
    if ((*(int *)(param_3[0x2a] + 0x38) == 0xe) &&
       (pvVar6 = (void *)__RTDynamicCast(param_3,0,&CVOGClonedObjectBase::RTTI_Type_Descriptor,
                                         &CVOGVehicle::RTTI_Type_Descriptor,0),
       pvVar6 != (void *)0x0)) {
      fStack_70 = *(float *)((int)pvVar6 + 0x280);
    }
    if (fStack_70 != 0.0) {
      fVar1 = *(float *)((int)fStack_70 + 0x1a4);
      iVar7 = CVOGReaction_RandomUnitScalar();
      if (0xfffff < *(int *)(iVar7 + 0xc)) {
        *(undefined4 *)(iVar7 + 0xc) = 0;
      }
      uVar2 = *(ushort *)(*(int *)(iVar7 + 8) + *(int *)(iVar7 + 0xc) * 2);
      *(int *)(iVar7 + 0xc) = *(int *)(iVar7 + 0xc) + 1;
      uVar13 = (uint)uVar2;
      pvVar6 = (void *)(uVar13 / 100);
      if ((float)(uVar13 % 100) < fVar1) {
        iVar7 = __RTDynamicCast(param_3,0,&CVOGClonedObjectBase::RTTI_Type_Descriptor,
                                &CVOGPhysicsBase::RTTI_Type_Descriptor,0);
        pvVar6 = (void *)0x0;
        if (iVar7 != 0) {
          piVar11 = (int *)CVOGReaction_GiveItemByCbid(*(int *)((int)fStack_70 + 0x1a0));
          if (piVar11 != (int *)0x0) {
            (**(code **)(*piVar11 + 8))(*(undefined4 *)((int)fStack_70 + 0x1a0),param_1,1);
            uVar16 = FUN_00521510(auStack_4c);
            *(undefined8 *)(piVar11 + 0x5c) = uVar16;
            piVar10 = (int *)FUN_00404c90();
            iStack_3c = *piVar10;
            fStack_38 = (float)piVar10[1];
            iStack_34 = piVar10[2];
            iStack_30 = piVar10[3];
            pvVar5 = (void *)FUN_004d2820(piVar11,&iStack_3c,0,1);
            ExceptionList = pvStack_28;
            return pvVar5;
          }
          pvVar6 = (void *)FUN_007a4480(0,"allocatenewobjectfromcbid failed %d",
                                        *(undefined4 *)((int)fStack_70 + 0x1a0));
        }
      }
    }
  }
  ExceptionList = local_1c;
  return pvVar6;
}

