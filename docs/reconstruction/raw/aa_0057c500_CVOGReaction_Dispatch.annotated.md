# Annotated low-level: CVOGReaction_Dispatch

| Field | Value |
|---|---|
| Stable ID | a_0057c500 |
| VA | 0x0057c500 |
| System | missions-progression |
| Date | 2026-07-23 |
| Refined | manager-pass industrial |

## Purpose (manager refine)

Central reaction type dispatcher (this+0x1d1 type byte). Gate via vcall +0x2c4 before effects.

## Plate / prior RE notes

`
WARNING: Globals starting with '_' overlap smaller symbols at the same address
`

## Switch cases observed

- 0
- 1
- 2
- 3
- 6
- 7
- 8
- 9
- 10
- 0xc
- 0xd
- 0xe
- 0xf
- 0x10
- 0x11
- 0x12
- 0x13
- 0x14
- 0x15
- 0x16
- 0x17
- 0x18
- 0x19
- 0x1a
- 0x1b
- 0x1c
- 0x1d
- 0x1e
- 0x1f
- 0x20
- 0x21
- 0x22
- 0x23
- 0x24
- 0x25
- 0x26
- 0x27
- 0x28
- 0x29
- 0x2a
- 0x2b
- 0x2c
- 0x2d
- 0x2e
- 0x2f
- 0x30
- 0x31
- 0x32
- 0x33
- 0x34
- 0x35
- 0x36
- 0x37
- 0x38
- 0x39
- 0x3a
- 0x3b
- 0x3c
- 0x3d
- 0x3e
- 0x3f
- 0x40
- 0x41
- 0x42
- 0x43
- 0x44
- 0x45
- 0x46
- 0x47
- 0x48
- 0x49
- 0x4a
- 0x4b
- 0x4c
- 0x4d
- 0x4e
- 0x4f
- 0x50
- 0x51
- 0x52
- 0x53
- 0x54
- 0x55
- 0x56
- 0x57

## Named callees (decompiler)

- CVOGReaction_Dispatch
- FUN_004d3ae0
- FUN_0040fb90
- CVOGReaction_ResolveObjectTarget
- CVOGReaction_SpawnObject
- CVOGReaction_FireNestedReactions
- CVOGReaction_RemoveObject
- FUN_0076cec0
- FUN_004cd300
- CVOGReaction_TransferMap
- CVOGReaction_ResolveSkillTargets
- Skill_ValidateTargetForSkill
- CVOGReaction_CastSkillOnTarget
- FUN_004023f0
- FUN_00404060
- Object_ResolveFromTFID
- FUN_00403430
- FUN_007a4480
- CVOGMap_LookupVariable
- CVOGMap_SetVariable
- FUN_00419170
- CVOGReaction_ShowDialog
- CVOGReaction_BuildTextParams
- CVOGReaction_ShowScreenText
- FUN_004294f0

## Machine-level notes

- Source: raw capture for a_0057c500.
- Prefer assembly when decompiler conflicts.
- Recover types for still-generic parameters via callers/xrefs.
- Map DAT_* globals and FUN_* callees in follow-up waves.
- Manager refine: case table + callees extracted; full dual review still open.

## Pseudocode (annotated copy of raw)

`c
/* WARNING: Globals starting with '_' overlap smaller symbols at the same address */

undefined4 __thiscall CVOGReaction_Dispatch(int *param_1,int *param_2)

{
  uint *puVar1;
  float fVar2;
  float fVar3;
  ushort uVar4;
  byte bVar5;
  undefined1 uVar6;
  char cVar7;
  int *piVar8;
  RACE_ID_INFERRED RVar9;
  uint uVar10;
  undefined4 *puVar11;
  uint uVar12;
  int iVar13;
  float *pfVar14;
  uint3 extraout_var;
  uint3 uVar21;
  void *pvVar15;
  int iVar16;
  int iVar17;
  char *pcVar18;
  float *pfVar19;
  undefined4 uVar20;
  undefined2 extraout_var_00;
  undefined2 extraout_var_01;
  float10 fVar22;
  float fVar23;
  undefined8 uVar24;
  undefined4 uVar25;
  TFID_16 *pTVar26;
  TypeDescriptor *pTVar27;
  int iVar28;
  TypeDescriptor *pTVar29;
  undefined4 uVar30;
  undefined4 uVar31;
  undefined4 uVar32;
  float *pfStack_834;
  int iStack_830;
  float *pfStack_82c;
  undefined4 *puStack_828;
  float *local_824;
  float *pfStack_820;
  undefined1 local_81c [4];
  float *local_818;
  int local_814;
  float local_810;
  float *pfStack_80c;
  float *pfStack_808;
  byte bStack_801;
  float *pfStack_800;
  int *piStack_7fc;
  int iStack_7f8;
  int iStack_7f4;
  float fStack_7f0;
  float fStack_7ec;
  float *pfStack_7e8;
  float fStack_7e4;
  float fStack_7e0;
  float fStack_7dc;
  float fStack_7d8;
  undefined4 uStack_7d4;
  uint uStack_7c8;
  uint uStack_7c4;
  uint uStack_7c0;
  uint uStack_7bc;
  int iStack_7b8;
  int iStack_7b4;
  int iStack_798;
  float fStack_794;
  int iStack_790;
  int iStack_78c;
  undefined4 uStack_77c;
  int iStack_778;
  int iStack_774;
  int iStack_770;
  int iStack_76c;
  int iStack_768;
  int iStack_764;
  char acStack_760 [244];
  TFID_16 aTStack_66c [100];
  undefined1 uStack_20;
  void *pvStack_1c;
  undefined1 *puStack_18;
  undefined4 local_14;
  
  local_14 = 0xffffffff;
  puStack_18 = &LAB_009a535d;
  pvStack_1c = ExceptionList;
  ExceptionList = &pvStack_1c;
  if (*(char *)(param_1[0x29] + 0x7e) == '\0') {
    ExceptionList = &pvStack_1c;
    FUN_004d3ae0(param_1,param_2);
  }
  local_818 = (float *)FUN_0040fb90();
  local_814 = 0;
  pfVar19 = (float *)param_1[0x76];
  local_14 = 0;
  local_824 = (float *)param_1[0x77];
  switch((int)*(char *)((int)param_1 + 0x1d1)) {
  case 0:
    cVar7 = (**(code **)(*param_1 + 0x2c4))(param_2);
    if ((cVar7 != '\0') && (pfVar19 != local_824)) {
      do {
        piVar8 = (int *)CVOGReaction_ResolveObjectTarget(0,*pfVar19,pfVar19[1]);
        if (piVar8 != (int *)0x0) {
          (**(code **)(*piVar8 + 0x114))(param_2);
        }
        pfVar19 = pfVar19 + 2;
      } while (pfVar19 != local_824);
    }
    break;
  case 1:
    cVar7 = (**(code **)(*param_1 + 0x2c4))(param_2);
    pfVar14 = local_824;
    if (cVar7 != '\0') {
      for (; pfVar19 != pfVar14; pfVar19 = pfVar19 + 2) {
        piVar8 = (int *)CVOGReaction_ResolveObjectTarget(0,*pfVar19,pfVar19[1]);
        if (piVar8 != (int *)0x0) {
          (**(code **)(*piVar8 + 0x118))();
        }
      }
    }
    break;
  case 2:
    cVar7 = (**(code **)(*param_1 + 0x2c4))(param_2);
    if (cVar7 != '\0') {
      if (pfVar19 != local_824) {
        do {
          CVOGReaction_SpawnObject((void *)param_1[0x29],*pfVar19,pfVar19[1]);
          pfVar19 = pfVar19 + 2;
        } while (pfVar19 != local_824);
      }
      CVOGReaction_FireNestedReactions(param_1,param_2,0,1);
    }
    break;
  case 3:
    cVar7 = (**(code **)(*param_1 + 0x2c4))(param_2);
    if (cVar7 != '\0') {
      if (pfVar19 != local_824) {
        do {
          CVOGReaction_RemoveObject((void *)param_1[0x29],(uint)*pfVar19,pfVar19[1],'\0');
          pfVar19 = pfVar19 + 2;
        } while (pfVar19 != local_824);
      }
      CVOGReaction_FireNestedReactions(param_1,param_2,0,0);
    }
    break;
  default:
    uVar20 = FUN_0076cec0(&local_810,"Unknown or invalid reaction type. COID:%I64d Type:%d",
                          param_1[0x58],param_1[0x59],(int)*(char *)((int)param_1 + 0x1d1));
    vog_LogMessage("C:\\vog\\1_code\\vog_14_117_branch\\libVOG\\VOGReaction.cpp",0x8ab,3,uVar20);
    break;
  case 6:
    cVar7 = (**(code **)(*param_1 + 0x2c4))(param_2);
    if (cVar7 != '\0') {
      if (pfVar19 != local_824) {
        do {
          piVar8 = (int *)CVOGReaction_ResolveObjectTarget(0,*pfVar19,pfVar19[1]);
          if (piVar8 != (int *)0x0) {
            (**(code **)(*piVar8 + 0x1bc))(1);
          }
          pfVar19 = pfVar19 + 2;
        } while (pfVar19 != local_824);
      }
      CVOGReaction_FireNestedReactions(param_1,param_2,0,1);
    }
    break;
  case 7:
    cVar7 = (**(code **)(*param_1 + 0x2c4))(param_2);
    if (cVar7 != '\0') {
      if (pfVar19 != local_824) {
        do {
          piVar8 = (int *)CVOGReaction_ResolveObjectTarget(0,*pfVar19,pfVar19[1]);
          if (piVar8 != (int *)0x0) {
            (**(code **)(*piVar8 + 0x1bc))(0);
          }
          pfVar19 = pfVar19 + 2;
        } while (pfVar19 != local_824);
      }
      CVOGReaction_FireNestedReactions(param_1,param_2,0,1);
    }
    break;
  case 8:
    cVar7 = (**(code **)(*param_1 + 0x2c4))(param_2);
    if (cVar7 != '\0') {
      if (pfVar19 != local_824) {
        do {
          CVOGReaction_RemoveObject((void *)param_1[0x29],(uint)*pfVar19,pfVar19[1],'\x01');
          pfVar19 = pfVar19 + 2;
        } while (pfVar19 != local_824);
      }
      CVOGReaction_FireNestedReactions(param_1,param_2,0,0);
    }
    break;
  case 9:
    cVar7 = (**(code **)(*param_1 + 0x2c4))(param_2);
    if (cVar7 != '\0') {
      FUN_004cd300(param_2,param_1[0x97]);
    }
    break;
  case 10:
    cVar7 = (**(code **)(*param_1 + 0x2c4))(param_2);
    if (cVar7 != '\0') {
      CVOGReaction_TransferMap(param_2,0,param_1[0x7f],param_1[0x97]);
    }
    break;
  case 0xc:
    cVar7 = (**(code **)(*param_1 + 0x2c4))(param_2);
    if ((((cVar7 != '\0') && (*(char *)(param_1[0x29] + 0x7e) != '\0')) && (0 < param_1[0x97])) &&
       (0 < param_1[0x99])) {
      pfVar19 = (float *)CVOGReaction_ResolveSkillTargets
                                   ((void *)param_1[0x97],
                                    CONCAT22(extraout_var_00,(ushort)*(byte *)(param_1 + 0x99)));
      pfStack_820 = pfVar19;
      if (pfVar19 != (float *)0x0) {
        (**(code **)(*param_1 + 0x2d0))(param_2,local_81c,1);
        if (pfStack_820 == (float *)0x1) {
          iVar16 = Skill_ValidateTargetForSkill(pfVar19,*(void **)((int)*local_824 + 8),(void *)0x0)
          ;
          if ((char)iVar16 != '\0') {
            CVOGReaction_CastSkillOnTarget
                      (pfVar19,param_1,*(int *)((int)*local_824 + 8),0,0,
                       *(int *)((int)*local_824 + 8) + 0x80,0,0xffffffff,0,0);
                    /* WARNING: Subroutine does not return */
            operator_delete(pfVar19);
          }
        }
        else if (pfStack_820 != (float *)0x0) {
          FUN_004023f0();
          pfStack_834 = (float *)*local_824;
          uStack_20 = 1;
          iStack_830 = 0;
          if (pfStack_834 != local_824) {
            do {
              FUN_00404060();
              (**(code **)(*(int *)pfStack_834[2] + 0x124))(&fStack_7ec);
              pfVar19 = (float *)*pfStack_7e8;
              if (pfVar19 != pfStack_7e8) {
                pTVar26 = aTStack_66c + iStack_830;
                do {
                  if (0x62 < iStack_830) goto LAB_0057ca98;
                  iVar16 = Skill_ValidateTargetForSkill
                                     (pfStack_82c,*(void **)((int)*local_824 + 8),(void *)0x0);
                  if ((char)iVar16 != '\0') {
                    fVar23 = pfVar19[2];
                    iStack_830 = iStack_830 + 1;
                    pTVar26->dwCoidLo = *(uint *)((int)fVar23 + 0x160);
                    pTVar26->dwCoidHi = *(uint *)((int)fVar23 + 0x164);
                    uVar20 = *(undefined4 *)((int)fVar23 + 0x168);
                    pTVar26->bGlobal = (char)uVar20;
                    pTVar26->bPad0 = (char)((uint)uVar20 >> 8);
                    pTVar26->bPad1 = (char)((uint)uVar20 >> 0x10);
                    pTVar26->bPad2 = (char)((uint)uVar20 >> 0x18);
                    uVar20 = *(undefined4 *)((int)fVar23 + 0x16c);
                    pTVar26->bPad3 = (char)uVar20;
                    pTVar26->bPad4 = (char)((uint)uVar20 >> 8);
                    pTVar26->bPad5 = (char)((uint)uVar20 >> 0x10);
                    pTVar26->bPad6 = (char)((uint)uVar20 >> 0x18);
                    pTVar26 = pTVar26 + 1;
                  }
                  pfVar19 = (float *)*pfVar19;
                } while (pfVar19 != pfStack_7e8);
              }
            } while ((iStack_830 < 99) &&
                    (pfStack_834 = (float *)*pfStack_834, pfStack_834 != local_824));
          }
LAB_0057ca98:
          aTStack_66c[iStack_830].dwCoidLo = DAT_009d4058;
          aTStack_66c[iStack_830].dwCoidHi = DAT_009d405c;
          uVar32 = 0;
          uVar31 = 0;
          pTVar26 = aTStack_66c + iStack_830;
          pTVar26->bGlobal = (undefined1)DAT_009d4060;
          pTVar26->bPad0 = DAT_009d4060._1_1_;
          pTVar26->bPad1 = DAT_009d4060._2_1_;
          pTVar26->bPad2 = DAT_009d4060._3_1_;
          uVar30 = 0xffffffff;
          pTVar26 = aTStack_66c + iStack_830;
          pTVar26->bPad3 = (undefined1)DAT_009d4064;
          pTVar26->bPad4 = DAT_009d4064._1_1_;
          pTVar26->bPad5 = DAT_009d4064._2_1_;
          pTVar26->bPad6 = DAT_009d4064._3_1_;
          uVar20 = 0;
          if (iStack_830 == 1) {
            iVar16 = *(int *)((int)*local_824 + 8) + 0x80;
            pTVar26 = (TFID_16 *)0x0;
            uVar25 = 0;
            pvVar15 = Object_ResolveFromTFID(aTStack_66c);
          }
          else {
            iVar16 = *(int *)((int)*local_824 + 8) + 0x80;
            pTVar26 = aTStack_66c;
            uVar25 = 0;
            pvVar15 = (void *)0x0;
          }
          CVOGReaction_CastSkillOnTarget
                    (pfStack_82c,param_1,pvVar15,uVar25,pTVar26,iVar16,uVar20,uVar30,uVar31,uVar32);
          FUN_00403430();
          pfVar19 = pfStack_82c;
        }
                    /* WARNING: Subroutine does not return */
        operator_delete(pfVar19);
      }
      FUN_007a4480(1,"Invalid reaction skill cast for skill %d, map: %s",param_1[0x97],
                   param_1[0x29] + 0xb4);
    }
    break;
  case 0xd:
    cVar7 = (**(code **)(*param_1 + 0x2c4))(param_2);
    if ((cVar7 != '\0') &&
       (cVar7 = CVOGMap_LookupVariable(param_1[0x99],&pfStack_80c,param_2), cVar7 != '\0')) {
      CVOGMap_SetVariable(param_1[0x97],pfStack_80c,param_2);
    }
    break;
  case 0xe:
    cVar7 = (**(code **)(*param_1 + 0x2c4))(param_2);
    if (((cVar7 == '\0') ||
        (cVar7 = CVOGMap_LookupVariable(param_1[0x97],&pfStack_808,param_2), cVar7 == '\0')) ||
       (cVar7 = CVOGMap_LookupVariable(param_1[0x99],&pfStack_80c,param_2), cVar7 == '\0')) break;
    fVar23 = (float)pfStack_80c + (float)pfStack_808;
    goto LAB_0057ee86;
  case 0xf:
    cVar7 = (**(code **)(*param_1 + 0x2c4))(param_2);
    if (((cVar7 == '\0') ||
        (cVar7 = CVOGMap_LookupVariable(param_1[0x97],&pfStack_80c,param_2), cVar7 == '\0')) ||
       (cVar7 = CVOGMap_LookupVariable(param_1[0x99],&pfStack_808,param_2), cVar7 == '\0')) break;
    fVar23 = (float)pfStack_80c - (float)pfStack_808;
    goto LAB_0057ee86;
  case 0x10:
    cVar7 = (**(code **)(*param_1 + 0x2c4))(param_2);
    if (cVar7 != '\0') {
      if (pfVar19 != local_824) {
        do {
          piVar8 = (int *)CVOGReaction_ResolveObjectTarget(0,*pfVar19,pfVar19[1]);
          if (piVar8 != (int *)0x0) {
            (**(code **)(*piVar8 + 0x11c))();
          }
          pfVar19 = pfVar19 + 2;
        } while (pfVar19 != local_824);
      }
      CVOGReaction_FireNestedReactions(param_1,param_2,0,1);
    }
    break;
  case 0x11:
    cVar7 = (**(code **)(*param_1 + 0x2c4))(param_2);
    if (cVar7 != '\0') {
      if (pfVar19 != local_824) {
        do {
          piVar8 = (int *)CVOGReaction_ResolveObjectTarget(0,*pfVar19,pfVar19[1]);
          if (piVar8 != (int *)0x0) {
            (**(code **)(*piVar8 + 0x120))();
          }
          pfVar19 = pfVar19 + 2;
        } while (pfVar19 != local_824);
      }
      CVOGReaction_FireNestedReactions(param_1,param_2,0,1);
    }
    break;
  case 0x12:
    if (param_1[0x96] != 0) {
      (**(code **)(*param_1 + 0x2d0))(param_2,local_81c,0);
      iVar16 = FUN_00419170();
      pfVar19 = (float *)*local_818;
      if (iVar16 == 0) {
        if (pfVar19 != local_818) {
          do {
            iVar16 = (**(code **)(*(int *)pfVar19[2] + 0x210))(0);
            if ((iVar16 != 0) &&
               (*(int *)(*(int *)(iVar16 + 4) + 4) + 4 + iVar16 == *(int *)(param_1[0x29] + 0xe8a0))
               ) {
              CVOGReaction_ShowDialog(param_2);
              iStack_7b8 = param_1[0x58];
              iStack_7b4 = param_1[0x59];
              if (param_2 == (int *)0x0) {
                uStack_7c8 = DAT_009d4058;
                uStack_7c4 = DAT_009d405c;
                uStack_7c0 = DAT_009d4060;
                uStack_7bc = DAT_009d4064;
              }
              else {
                puVar1 = (uint *)(*(int *)(*(int *)(iVar16 + 4) + 4) + 0x164 + iVar16);
                uStack_7c8 = *puVar1;
                uStack_7c4 = puVar1[1];
                uStack_7c0 = puVar1[2];
                uStack_7bc = puVar1[3];
              }
              CVOGReaction_BuildTextParams(&uStack_7c8);
              goto LAB_0057cd3e;
            }
            pfVar19 = (float *)*pfVar19;
          } while (pfVar19 != local_818);
          CVOGReaction_FireNestedReactions(param_1,param_2,0,0);
          break;
        }
      }
      else if (pfVar19 != local_818) {
        do {
          piVar8 = (int *)pfVar19[2];
          iVar16 = (**(code **)(*piVar8 + 0x1ec))();
          if (iVar16 == 0) {
            CVOGReaction_ShowScreenText(piVar8);
          }
          else {
            FUN_004294f0();
            local_824 = (float *)0x0;
            iVar16 = FUN_004022a0(&local_824,&pfStack_820);
            while (iVar16 == 0) {
              CVOGReaction_ShowScreenText(pfStack_820);
              iVar16 = FUN_004022a0(&local_824,&pfStack_820);
            }
            FUN_0040c700();
          }
          pfVar19 = (float *)*pfVar19;
        } while (pfVar19 != local_818);
        CVOGReaction_FireNestedReactions(param_1,param_2,0,0);
        break;
      }
    }
LAB_0057cd3e:
    CVOGReaction_FireNestedReactions(param_1,param_2,0,0);
    break;
  case 0x13:
    cVar7 = (**(code **)(*param_1 + 0x2c4))(param_2);
    pfVar14 = local_824;
    if (cVar7 != '\0') {
      for (; pfVar19 != pfVar14; pfVar19 = pfVar19 + 2) {
        uVar31 = 0;
        pTVar29 = &CVOGTrigger::RTTI_Type_Descriptor;
        pTVar27 = &CVOGClonedObjectBase::RTTI_Type_Descriptor;
        uVar30 = 0;
        uVar20 = CVOGReaction_ResolveObjectTarget(0,*pfVar19,pfVar19[1]);
        piVar8 = (int *)__RTDynamicCast(uVar20,uVar30,pTVar27,pTVar29,uVar31);
        if (piVar8 != (int *)0x0) {
          (**(code **)(*piVar8 + 0x5c))();
        }
      }
    }
    break;
  case 0x14:
    if (param_2 != (int *)0x0) {
      (**(code **)(*param_1 + 0x2d0))(param_2,local_81c,0);
      local_824 = (float *)*local_818;
      if (local_824 != local_818) {
        do {
          piVar8 = (int *)local_824[2];
          if (*(int *)(piVar8[0x2a] + 0x38) == 0x36) {
            (**(code **)(*piVar8 + 0x1ec))();
            FUN_004294f0();
            piStack_7fc = (int *)0x0;
            iVar16 = FUN_004022a0(&piStack_7fc,&pfStack_820);
            while (iVar16 == 0) {
              if ((pfStack_820 != (float *)0x0) &&
                 (cVar7 = (**(code **)(*param_1 + 0x2c4))(piVar8), cVar7 != '\0')) {
                RVar9 = Object_GetRootRaceId(param_2);
                FUN_00512460(RVar9);
                (**(code **)((int)*pfStack_820 + 0x288))(0,1);
                FUN_005172d0(0);
              }
              iVar16 = FUN_004022a0(&piStack_7fc,&pfStack_820);
            }
            FUN_0040c700();
          }
          iVar16 = (**(code **)(*piVar8 + 0x210))(0);
          if (iVar16 == 0) {
            RVar9 = Object_GetRootRaceId(param_2);
            FUN_00512460(RVar9);
            FUN_005172d0(0);
          }
          local_824 = (float *)*local_824;
        } while (local_824 != local_818);
      }
      CVOGReaction_FireNestedReactions(param_1,param_2,0,1);
    }
    break;
  case 0x15:
    (**(code **)(*param_1 + 0x2d0))(param_2,local_81c,0);
    pfVar19 = (float *)*local_818;
    if (pfVar19 != local_818) {
      do {
        pfStack_800 = (float *)pfVar19[2];
        if (*(int *)((int)pfStack_800[0x2a] + 0x38) == 0x36) {
          iVar16 = (**(code **)((int)*pfStack_800 + 0x1ec))();
          local_824 = (float *)(iVar16 + 0xb4);
          FUN_004294f0();
          pfStack_820 = (float *)0x0;
          iVar16 = FUN_004022a0(&pfStack_820,&piStack_7fc);
          piVar8 = piStack_7fc;
          while (piStack_7fc = piVar8, iVar16 == 0) {
            if ((piVar8 != (int *)0x0) &&
               (cVar7 = (**(code **)(*param_1 + 0x2c4))(pfStack_800), cVar7 != '\0')) {
              uVar20 = (**(code **)(*piVar8 + 0x284))();
              FUN_00512460(uVar20);
              (**(code **)(*piVar8 + 0x288))(0,1);
              FUN_005172d0(0);
            }
            iVar16 = FUN_004022a0(&pfStack_820,&piStack_7fc);
            piVar8 = piStack_7fc;
          }
          FUN_0040c700();
        }
        uVar20 = (**(code **)((int)*pfStack_800 + 0x284))();
        FUN_00512460(uVar20);
        FUN_005172d0(0);
        pfVar19 = (float *)*pfVar19;
      } while (pfVar19 != local_818);
    }
    CVOGReaction_FireNestedReactions(param_1,param_2,0,1);
    break;
  case 0x16:
    (**(code **)(*param_1 + 0x2d0))(param_2,local_81c,0);
    pfVar19 = (float *)*local_818;
    if (pfVar19 != local_818) {
      do {
        pfStack_808 = (float *)pfVar19[2];
        if (*(int *)((int)pfStack_808[0x2a] + 0x38) == 0x36) {
          iVar16 = (**(code **)((int)*pfStack_808 + 0x1ec))();
          local_824 = (float *)(iVar16 + 0xb4);
          FUN_004294f0();
          pfStack_820 = (float *)0x0;
          iVar16 = FUN_004022a0(&pfStack_820,&piStack_7fc);
          piVar8 = piStack_7fc;
          while (piStack_7fc = piVar8, iVar16 == 0) {
            if (((piVar8 != (int *)0x0) &&
                (cVar7 = (**(code **)(*param_1 + 0x2c4))(pfStack_808), cVar7 != '\0')) &&
               (cVar7 = CVOGMap_LookupVariable(param_1[0x97],&pfStack_800,piVar8), cVar7 != '\0')) {
              fStack_7e0 = (float)(int)ROUND((float)pfStack_800);
              FUN_00512460(fStack_7e0);
              (**(code **)(*piVar8 + 0x288))(0,1);
              FUN_005172d0(0);
            }
            iVar16 = FUN_004022a0(&pfStack_820,&piStack_7fc);
            piVar8 = piStack_7fc;
          }
          FUN_0040c700();
        }
        pfVar14 = pfStack_808;
        iVar16 = (**(code **)((int)*pfStack_808 + 0x210))(0);
        if ((iVar16 == 0) &&
           (cVar7 = CVOGMap_LookupVariable(param_1[0x97],&pfStack_80c,pfVar14), cVar7 != '\0')) {
          local_810 = (float)(int)ROUND((float)pfStack_80c);
          FUN_00512460(local_810);
          FUN_005172d0(0);
        }
        pfVar19 = (float *)*pfVar19;
      } while (pfVar19 != local_818);
    }
    CVOGReaction_FireNestedReactions(param_1,param_2,0,1);
    break;
  case 0x17:
    (**(code **)(*param_1 + 0x2d0))(param_2,local_81c,1);
    pfVar19 = (float *)*local_818;
    if (pfVar19 != local_818) {
      do {
        cVar7 = CVOGMap_LookupVariable(param_1[0x97],&local_810,pfVar19[2]);
        if (cVar7 != '\0') {
          iVar16 = (**(code **)(*(int *)pfVar19[2] + 0x244))();
          (**(code **)(*(int *)pfVar19[2] + 0x240))((int)((float)iVar16 * local_810));
        }
        pfVar19 = (float *)*pfVar19;
      } while (pfVar19 != local_818);
    }
    CVOGReaction_FireNestedReactions(param_1,param_2,0,0);
    break;
  case 0x18:
    (**(code **)(*param_1 + 0x2d0))(param_2,local_81c,0);
    pfVar19 = (float *)*local_818;
    pfStack_80c = pfVar19;
    if (pfVar19 != local_818) {
      do {
        pfStack_80c = pfVar19;
        cVar7 = CVOGMap_LookupVariable(param_1[0x97],&pfStack_800,pfVar19[2]);
        if (((cVar7 != '\0') && (fVar23 = pfVar19[2], fVar23 != 0.0)) &&
           (((*(uint *)((int)fVar23 + 0x17c) >> 5 & 1) != 0 &&
            ((piVar8 = (int *)__RTDynamicCast(fVar23,0,&CVOGClonedObjectBase::RTTI_Type_Descriptor,
                                              &CVOGPhysicsBase::RTTI_Type_Descriptor,0),
             piVar8 != (int *)0x0 && (piVar8[2] != 0)))))) {
          iVar16 = *(int *)(piVar8[2] + 0x3c);
          fVar23 = *(float *)(iVar16 + 0x40);
          fVar2 = *(float *)(iVar16 + 0x44);
          pfVar19 = *(float **)(iVar16 + 0x48);
          local_810 = (float)pfVar19 * (float)pfVar19 + fVar2 * fVar2 + fVar23 * fVar23;
          fVar3 = *(float *)(iVar16 + 0x4c);
          fStack_7f0 = fVar23;
          fStack_7ec = fVar2;
          pfStack_7e8 = pfVar19;
          fStack_7e4 = fVar3;
          if (SQRT(local_810) < g_flMsToSeconds_Inferred) break;
          if (local_810 == 0.0) {
            pfVar14 = (float *)0x0;
          }
          else {
            pfVar14 = (float *)(g_flOne / SQRT(local_810));
            pfStack_808 = pfVar14;
          }
          fStack_7f0 = (float)pfStack_800 * (float)pfVar14 * fVar23;
          fStack_7ec = (float)pfStack_800 * fVar2 * (float)pfVar14;
          pfStack_7e8 = (float *)((float)pfStack_800 * (float)pfVar19 * (float)pfVar14);
          fStack_7e4 = (float)pfStack_800 * fVar3 * (float)pfVar14;
          if (param_1[0x99] == -1) {
            fStack_7f0 = fStack_7f0 + fVar23;
            fStack_7ec = fVar2 + fStack_7ec;
            pfStack_7e8 = (float *)((float)pfVar19 + (float)pfStack_7e8);
            fStack_7e4 = fVar3 + fStack_7e4;
          }
          fStack_7e0 = local_810;
          CVOGPhysics_ApplyImpulseVector(&fStack_7f0);
          (**(code **)(*piVar8 + 0x40))();
        }
        pfVar19 = (float *)*pfStack_80c;
        pfStack_80c = pfVar19;
      } while (pfVar19 != local_818);
    }
    CVOGReaction_FireNestedReactions(param_1,param_2,0,0);
    break;
  case 0x19:
    cVar7 = (**(code **)(*param_1 + 0x2c4))(param_2);
    if ((((cVar7 != '\0') && (*(char *)(param_1[0x29] + 0x7e) != '\0')) && (param_2 != (int *)0x0))
       && ((iVar16 = *(int *)(param_2[0x2a] + 0x38), iVar16 == 0xe || (iVar16 == 0x14)))) {
      if (iVar16 == 0x14) {
        iVar16 = __RTDynamicCast(param_2,0,&CVOGClonedObjectBase::RTTI_Type_Descriptor,
                                 &CVOGCharacter::RTTI_Type_Descriptor,0);
        iVar16 = *(int *)(iVar16 + 0x250);
        if (iVar16 == 0) break;
      }
      else {
        iVar16 = __RTDynamicCast(param_2,0,&CVOGClonedObjectBase::RTTI_Type_Descriptor,
                                 &CVOGVehicle::RTTI_Type_Descriptor,0);
      }
      if (iVar16 != 0) {
        CVOGReaction_RemoveInventoryItem(param_1[0x97],param_1[0x99]);
      }
    }
    break;
  case 0x1a:
    cVar7 = (**(code **)(*param_1 + 0x2c4))(param_2);
    if ((((cVar7 == '\0') ||
         (cVar7 = CVOGMap_LookupVariable(param_1[0x97],&pfStack_80c,param_2), cVar7 == '\0')) ||
        (param_2 == (int *)0x0)) || (iVar16 = (**(code **)(*param_2 + 0x210))(0), iVar16 == 0))
    break;
    local_810 = (float)(int)ROUND((float)pfStack_80c);
    iVar17 = (int)local_810 >> 0x1f;
    fVar23 = local_810;
    if ((-1 < iVar17) && (((int)local_810 < 0 || (500000 < (uint)local_810)))) {
      fVar23 = 0.0;
      iVar17 = 0;
    }
    uVar10 = (int)fVar23 - (int)*(float *)(iVar16 + 0x728);
    iVar13 = uVar10 + *(uint *)(iVar16 + 0x720);
    iVar17 = ((iVar17 - *(int *)(iVar16 + 0x72c)) -
             (uint)((uint)fVar23 < (uint)*(float *)(iVar16 + 0x728))) + *(int *)(iVar16 + 0x724) +
             (uint)CARRY4(uVar10,*(uint *)(iVar16 + 0x720));
    if ((iVar17 < 1) && (iVar17 < 0)) {
      iVar13 = 0;
      iVar17 = 0;
    }
    *(int *)(iVar16 + 0x720) = iVar13;
    *(int *)(iVar16 + 0x724) = iVar17;
    goto LAB_0057f8f6;
  case 0x1b:
    cVar7 = (**(code **)(*param_1 + 0x2c4))(param_2);
    if ((cVar7 == '\0') ||
       (cVar7 = CVOGMap_LookupVariable(param_1[0x97],&pfStack_820,param_2), cVar7 == '\0')) break;
    if ((float)pfStack_820 <= 0.0) {
      pfStack_820 = (float *)0x0;
    }
    if ((param_2 == (int *)0x0) || (iVar16 = (**(code **)(*param_2 + 0x210))(0), iVar16 == 0))
    break;
    local_810 = (float)(int)ROUND((float)pfStack_820);
    CVOGCharacter_AddAttributePoints((ushort)local_810._0_1_ + *(short *)(iVar16 + 0x6cc));
    goto LAB_0057f8f6;
  case 0x1c:
    (**(code **)(*param_1 + 0x2d0))(param_2,local_81c,0);
    pfVar19 = (float *)*local_818;
    pfVar14 = local_818;
    if (pfVar19 != local_818) {
      do {
        pfVar14 = (float *)CVOGMap_LookupVariable(param_1[0x97],&pfStack_820,pfVar19[2]);
        if ((char)pfVar14 != '\0') {
          if ((float)pfStack_820 <= 0.0) {
            pfStack_820 = (float *)0x0;
          }
          pvVar15 = (void *)(**(code **)(*(int *)pfVar19[2] + 0x210))(0);
          pfVar14 = (float *)0x0;
          if (pvVar15 != (void *)0x0) {
            local_810 = (float)(int)ROUND((float)pfStack_820);
            CVOGReaction_AddExperience(pvVar15,(int)local_810,PacketOrNonKill);
            pfVar14 = (float *)((uint)extraout_var << 8);
          }
        }
        pfVar19 = (float *)*pfVar19;
      } while (pfVar19 != local_818);
    }
    uVar21 = (uint3)((uint)pfVar14 >> 8);
    if (((char)param_1[0x7d] == '\0') && (*(char *)((int)param_1 + 0x1f6) == '\0')) {
      CVOGReaction_FireNestedReactions(param_1,param_2,CONCAT31(uVar21,1),0);
    }
    else {
      CVOGReaction_FireNestedReactions(param_1,param_2,(uint)uVar21 << 8,0);
    }
    break;
  case 0x1d:
    cVar7 = (**(code **)(*param_1 + 0x2c4))(param_2);
    if ((((cVar7 == '\0') || (param_2 == (int *)0x0)) ||
        (iVar16 = (**(code **)(*param_2 + 0x210))(0), iVar16 == 0)) ||
       (cVar7 = CVOGReaction_MarkRepairStation(param_1[0x97]), cVar7 == '\0')) break;
    goto LAB_0057f8f6;
  case 0x1e:
    (**(code **)(*param_1 + 0x2d0))(param_2,local_81c,0);
    pfVar19 = (float *)*local_818;
    if (pfVar19 != local_818) {
      do {
        iVar16 = (**(code **)(*(int *)pfVar19[2] + 0x210))(0);
        if (iVar16 != 0) {
          CVOGReaction_GiveMission(param_1[0x97]);
          CVOGReaction_FireNestedReactions
                    (param_1,*(int *)(*(int *)(iVar16 + 4) + 4) + 4 + iVar16,1,0);
        }
        pfVar19 = (float *)*pfVar19;
      } while (pfVar19 != local_818);
    }
    break;
  case 0x1f:
    cVar7 = CVOGCharacter_WeaponAllowsKillXpBonus();
    if (cVar7 != '\0') {
      *(undefined1 *)(param_1 + 0x7d) = 1;
    }
    (**(code **)(*param_1 + 0x2d0))(param_2,local_81c,0);
    pfVar19 = (float *)*local_818;
    bStack_801 = 0;
    if (pfVar19 != local_818) {
      do {
        iVar16 = (**(code **)(*(int *)pfVar19[2] + 0x210))(0);
        if (iVar16 != 0) {
          bVar5 = CVOGReaction_CompleteObjective(param_1[0x97],0xffffffff,0xffffffff,1);
          bStack_801 = bStack_801 | bVar5;
        }
        pfVar19 = (float *)*pfVar19;
      } while (pfVar19 != local_818);
      if (bStack_801 != 0) {
        CVOGReaction_FireNestedReactions(param_1,param_2,0,0);
      }
    }
    break;
  case 0x20:
    (**(code **)(*param_1 + 0x2d0))(param_2,local_81c,0);
    pfVar19 = (float *)*local_818;
    if (pfVar19 != local_818) {
      do {
        pvVar15 = (void *)(**(code **)(*(int *)pfVar19[2] + 0x210))(1);
        if (pvVar15 != (void *)0x0) {
          CVOGReaction_UnlockContinentObject(pvVar15,param_1[0x97]);
        }
        pfVar19 = (float *)*pfVar19;
      } while (pfVar19 != local_818);
    }
    CVOGReaction_FireNestedReactions(param_1,param_2,0,0);
    break;
  case 0x21:
    cVar7 = (**(code **)(*param_1 + 0x2c4))(param_2);
    if (cVar7 != '\0') {
      FUN_004dbbb0(param_1[0x97],param_1[0x99]);
      CVOGReaction_FireNestedReactions(param_1,param_2,0,1);
    }
    break;
  case 0x22:
    cVar7 = (**(code **)(*param_1 + 0x2c4))(param_2);
    if (cVar7 != '\0') {
      FUN_004d2e30(param_1[0x97],param_1[0x99]);
      CVOGReaction_FireNestedReactions(param_1,param_2,0,1);
    }
    break;
  case 0x23:
    (**(code **)(*param_1 + 0x2d0))(param_2,local_81c,0);
    pfVar19 = (float *)*local_818;
    if (pfVar19 == local_818) {
LAB_0057e463:
      CVOGReaction_FireNestedReactions(param_1,param_2,0,1);
    }
    else {
      do {
        iVar16 = (**(code **)(*(int *)pfVar19[2] + 0x210))(0);
        if ((iVar16 != 0) &&
           (*(int *)(*(int *)(iVar16 + 4) + 4) + 4 + iVar16 == *(int *)(param_1[0x29] + 0xe8a0))) {
          FUN_00531d50(param_1[0x97],param_1[0x58],param_1[0x59]);
          goto LAB_0057e463;
        }
        pfVar19 = (float *)*pfVar19;
      } while (pfVar19 != local_818);
      CVOGReaction_FireNestedReactions(param_1,param_2,0,1);
    }
    break;
  case 0x24:
    (**(code **)(*param_1 + 0x2d0))(param_2,local_81c,0);
    pfVar19 = (float *)*local_818;
    if (pfVar19 == local_818) {
LAB_0057e4ea:
      CVOGReaction_FireNestedReactions(param_1,param_2,0,1);
    }
    else {
      do {
        iVar16 = (**(code **)(*(int *)pfVar19[2] + 0x210))(0);
        if ((iVar16 != 0) &&
           (*(int *)(*(int *)(iVar16 + 4) + 4) + 4 + iVar16 == *(int *)(param_1[0x29] + 0xe8a0))) {
          FUN_0052a240(param_1[0x97]);
          goto LAB_0057e4ea;
        }
        pfVar19 = (float *)*pfVar19;
      } while (pfVar19 != local_818);
      CVOGReaction_FireNestedReactions(param_1,param_2,0,1);
    }
    break;
  case 0x25:
    cVar7 = (**(code **)(*param_1 + 0x2c4))(param_2);
    if (((cVar7 != '\0') && (*(char *)(param_1[0x29] + 0x7e) != '\0')) && (param_2 != (int *)0x0)) {
      iStack_7b8 = param_1[0x58];
      iStack_7b4 = param_1[0x59];
      uStack_7c8 = param_2[0x58];
      uStack_7c4 = param_2[0x59];
      uStack_7c0 = param_2[0x5a];
      uStack_7bc = param_2[0x5b];
      CVOGReaction_BuildTextParams(&uStack_7c8);
    }
    break;
  case 0x26:
  case 0x27:
    if (((*(char *)(param_1[0x29] + 0x7e) != '\0') && (param_2 != (int *)0x0)) &&
       (param_1[0x97] != -1)) {
      (**(code **)(*param_1 + 0x2d0))(param_2,local_81c,1);
      pfVar19 = (float *)*local_818;
      pfStack_808 = pfVar19;
      if (pfVar19 != local_818) {
        do {
          pfStack_808 = pfVar19;
          local_810 = (float)(**(code **)(*(int *)pfVar19[2] + 0x210))(0);
          if ((local_810 != 0.0) && (pfStack_80c = (float *)0x0, 0 < param_1[0x99])) {
            do {
              piVar8 = (int *)CVOGReaction_GiveItemByCbid(param_1[0x97]);
              if (piVar8 == (int *)0x0) {
                FUN_007a4480(0,"allocatenewobjectfromcbid failed %d",param_1[0x97]);
              }
              else {
                (**(code **)(*piVar8 + 8))(param_1[0x97],param_1[0x29],1);
                iVar16 = param_1[0x29];
                fStack_7ec = *(float *)(iVar16 + 0xe6e0);
                iVar17 = *(int *)(iVar16 + 0xe6e4);
                *(uint *)(iVar16 + 0xe6e4) = iVar17 + (uint)(0xfffffffe < (uint)fStack_7ec);
                *(int *)(iVar16 + 0xe6e0) = (int)fStack_7ec + 1;
                FUN_00512160(fStack_7ec,iVar17,1);
                (**(code **)(*piVar8 + 0x2a4))(*(undefined4 *)(param_1[0x29] + 0xe4e8));
                Client_SendInventoryAddItem(piVar8,1);
                pfVar19 = pfStack_808;
              }
              pfStack_80c = (float *)((int)pfStack_80c + 1);
            } while ((int)pfStack_80c < param_1[0x99]);
          }
          pfVar19 = (float *)*pfVar19;
          pfStack_808 = pfVar19;
        } while (pfVar19 != local_818);
      }
    }
    break;
  case 0x28:
    cVar7 = (**(code **)(*param_1 + 0x2c4))(param_2);
    if (cVar7 != '\0') {
      uStack_77c = 1;
      iStack_798 = 1;
      Client_SendLogicUiPacket(&iStack_798);
      CVOGReaction_FireNestedReactions(param_1,param_2,1,0);
    }
    break;
  case 0x29:
    cVar7 = (**(code **)(*param_1 + 0x2c4))(param_2);
    if (cVar7 == '\0') break;
    uStack_77c = 2;
    goto LAB_0057f8d2;
  case 0x2a:
    cVar7 = (**(code **)(*param_1 + 0x2c4))(param_2);
    if (cVar7 == '\0') break;
    uStack_77c = 0;
    goto LAB_0057f8d2;
  case 0x2b:
    (**(code **)(*param_1 + 0x2d0))(param_2,local_81c,0);
    pfVar19 = (float *)*local_818;
    if (pfVar19 != local_818) {
      do {
        iStack_7f8 = param_1[0x97];
        iStack_7f4 = iStack_7f8 >> 0x1f;
        (**(code **)(*(int *)pfVar19[2] + 0x14c))(&iStack_7f8);
        pfVar19 = (float *)*pfVar19;
      } while (pfVar19 != local_818);
    }
    CVOGReaction_FireNestedReactions(param_1,param_2,0,0);
    break;
  case 0x2c:
    cVar7 = CVOGMap_LookupVariable(param_1[0x97],&pfStack_80c,param_2);
    if (cVar7 != '\0') {
      (**(code **)(*param_1 + 0x2d0))(param_2,local_81c,1);
      pfVar19 = (float *)*local_818;
      if (pfVar19 != local_818) {
        do {
          piVar8 = (int *)pfVar19[2];
          if (*(int *)(piVar8[0x2a] + 0x38) == 0x12) {
            iVar16 = (**(code **)(*piVar8 + 0x214))();
            *(float **)(*(int *)(iVar16 + 0xf8) + 0x4c) = pfStack_80c;
          }
          else if (*(int *)(piVar8[0x2a] + 0x38) == 0xe) {
            iVar16 = (**(code **)(*piVar8 + 0x1d4))();
            *(float **)(*(int *)(iVar16 + 0xf8) + 0x4c) = pfStack_80c;
          }
          pfVar19 = (float *)*pfVar19;
        } while (pfVar19 != local_818);
      }
      CVOGReaction_FireNestedReactions(param_1,param_2,0,0);
    }
    break;
  case 0x2d:
    iVar16 = FUN_004baec0(0,param_1[0x97],param_1[0x97] >> 0x1f);
    if (iVar16 != 0) {
      pfVar19 = (float *)FUN_00404c90();
      fStack_7f0 = *pfVar19;
      fStack_7ec = pfVar19[1];
      pfStack_7e8 = (float *)pfVar19[2];
      (**(code **)(*param_1 + 0x2d0))(param_2,local_81c,1);
      pfStack_820 = (float *)*local_818;
      if (pfStack_820 != local_818) {
        do {
          piVar8 = (int *)pfStack_820[2];
          puStack_828 = (undefined4 *)(**(code **)(*piVar8 + 0x19c))();
          if (((puStack_828 != (void *)0x0) ||
              (puStack_828 = (undefined4 *)(**(code **)(*piVar8 + 0x1c8))(),
              puStack_828 != (void *)0x0)) && (*(int *)((int)puStack_828 + 8) != 0)) {
            iVar16 = CVOGReaction_RandomUnitScalar();
            if (0xfffff < *(int *)(iVar16 + 0xc)) {
              *(undefined4 *)(iVar16 + 0xc) = 0;
            }
            uVar4 = *(ushort *)(*(int *)(iVar16 + 8) + *(int *)(iVar16 + 0xc) * 2);
            *(int *)(iVar16 + 0xc) = *(int *)(iVar16 + 0xc) + 1;
            local_810 = (float)uVar4 * (float)param_1[0x98] * _DAT_009cc4a8 - (float)param_1[0x98];
            iVar16 = CVOGReaction_RandomUnitScalar();
            if (0xfffff < *(int *)(iVar16 + 0xc)) {
              *(undefined4 *)(iVar16 + 0xc) = 0;
            }
            uVar4 = *(ushort *)(*(int *)(iVar16 + 8) + *(int *)(iVar16 + 0xc) * 2);
            fStack_7e0 = fStack_7f0 + local_810;
            *(int *)(iVar16 + 0xc) = *(int *)(iVar16 + 0xc) + 1;
            fStack_7dc = fStack_7ec;
            fStack_7d8 = ((float)uVar4 * (float)param_1[0x98] * _DAT_009cc4a8 - (float)param_1[0x98]
                         ) + (float)pfStack_7e8;
            uStack_7d4 = 0;
            CVOGReaction_TeleportTarget(puStack_828,&fStack_7e0);
          }
          pfStack_820 = (float *)*pfStack_820;
        } while (pfStack_820 != local_818);
      }
      CVOGReaction_FireNestedReactions(param_1,param_2,0,0);
    }
    break;
  case 0x2e:
    (**(code **)(*param_1 + 0x2d0))(param_2,local_81c,1);
    if (local_814 != 0) {
      FUN_004d3360(param_1[0x99]);
      uVar10 = param_1[0x97];
      FUN_005a5190((float)(int)((uVar10 ^ (int)uVar10 >> 0x1f) - ((int)uVar10 >> 0x1f)),
                   -1 < (int)uVar10,0,0,1,0);
      if (param_1[0x8b] != 0) {
        FUN_00418870(param_1[0x8b]);
      }
      pfVar19 = (float *)*local_818;
      if (pfVar19 != local_818) {
        do {
          iVar16 = (**(code **)(*(int *)pfVar19[2] + 0x210))(0);
          if (iVar16 != 0) {
            iVar16 = *(int *)(*(int *)(iVar16 + 4) + 4) + 4 + iVar16;
          }
          CVOGReaction_FireNestedReactions(param_1,iVar16,1,0);
          pfVar19 = (float *)*pfVar19;
        } while (pfVar19 != local_818);
      }
    }
    break;
  case 0x2f:
    (**(code **)(*param_1 + 0x2d0))(param_2,local_81c,1);
    if ((local_814 != 0) && (iVar16 = FUN_004d2a20(param_1[0x99]), iVar16 != 0)) {
      FUN_005a5160();
      if (param_1[0x8b] != 0) {
        FUN_00418870(param_1[0x8b]);
      }
      pfVar19 = (float *)*local_818;
      if (pfVar19 != local_818) {
        do {
          iVar16 = (**(code **)(*(int *)pfVar19[2] + 0x210))(0);
          if (iVar16 != 0) {
            CVOGReaction_FireNestedReactions
                      (param_1,*(int *)(*(int *)(iVar16 + 4) + 4) + 4 + iVar16,1,0);
          }
          pfVar19 = (float *)*pfVar19;
        } while (pfVar19 != local_818);
      }
    }
    break;
  case 0x30:
    cVar7 = (**(code **)(*param_1 + 0x2c4))(param_2);
    if (cVar7 != '\0') {
      iVar16 = CVOGReaction_RandomUnitScalar();
      iVar16 = (*(uint *)(iVar16 + 0x10) >> 1) + _DAT_00b04854;
      CVOGReaction_RandomUnitScalar(iVar16);
      fVar22 = (float10)FUN_007a4170(iVar16);
      local_810 = (float)fVar22;
      _DAT_00b04854 = _DAT_00b04854 + 1;
      CVOGMap_SetVariable(param_1[0x97],local_810,param_2);
      CVOGReaction_FireNestedReactions(param_1,param_2,0,1);
    }
    break;
  case 0x31:
    cVar7 = (**(code **)(*param_1 + 0x2c4))(param_2);
    if (((cVar7 == '\0') ||
        (cVar7 = CVOGMap_LookupVariable(param_1[0x97],&fStack_7e0,param_2), cVar7 == '\0')) ||
       (cVar7 = CVOGMap_LookupVariable(param_1[0x99],&local_810,param_2), cVar7 == '\0')) break;
    fVar23 = local_810 * fStack_7e0;
    goto LAB_0057ee86;
  case 0x32:
    cVar7 = (**(code **)(*param_1 + 0x2c4))(param_2);
    if ((((cVar7 == '\0') ||
         (cVar7 = CVOGMap_LookupVariable(param_1[0x97],&fStack_7e0,param_2), cVar7 == '\0')) ||
        (cVar7 = CVOGMap_LookupVariable(param_1[0x99],&local_810,param_2), cVar7 == '\0')) ||
       (local_810 == g_flZero)) break;
    fVar23 = fStack_7e0 / local_810;
LAB_0057ee86:
    CVOGMap_SetVariable(param_1[0x97],fVar23,param_2);
    break;
  case 0x33:
    (**(code **)(*param_1 + 0x2d0))(param_2,local_81c,0);
    pfVar19 = (float *)*local_818;
    if (pfVar19 != local_818) {
      do {
        iVar16 = (**(code **)(*(int *)pfVar19[2] + 0x210))(0);
        if (iVar16 != 0) {
          FUN_00530550(param_1[0x97]);
        }
        pfVar19 = (float *)*pfVar19;
      } while (pfVar19 != local_818);
    }
    goto LAB_0057f8f6;
  case 0x34:
    cVar7 = (**(code **)(*param_1 + 0x2c4))(param_2);
    if (cVar7 == '\0') break;
    iStack_778 = param_1[0x97];
    iStack_774 = iStack_778 >> 0x1f;
    uStack_77c = 3;
    goto LAB_0057f8d2;
  case 0x35:
    (**(code **)(*param_1 + 0x2d0))(param_2,local_81c,0);
    pfStack_800 = (float *)*local_818;
    if (pfStack_800 != local_818) {
      do {
        pfVar19 = (float *)pfStack_800[2];
        pfStack_808 = pfVar19;
        if (*(int *)((int)pfVar19[0x2a] + 0x38) == 0x36) {
          (**(code **)((int)*pfVar19 + 0x1ec))();
          FUN_004294f0();
          pfStack_80c = (float *)0x0;
          iVar16 = FUN_004022a0(&pfStack_80c,&pfStack_820);
          while (iVar16 == 0) {
            if ((pfStack_820 != (float *)0x0) &&
               (cVar7 = (**(code **)(*param_1 + 0x2c4))(pfVar19), cVar7 != '\0')) {
              fVar23 = *pfStack_820;
              uVar20 = (**(code **)(*param_2 + 0x290))(1);
              (**(code **)((int)fVar23 + 0x288))(uVar20);
              pfVar19 = pfStack_808;
              FUN_005172d0(0);
            }
            iVar16 = FUN_004022a0(&pfStack_80c,&pfStack_820);
          }
          FUN_0040c700();
        }
        local_810 = *pfVar19;
        uVar20 = (**(code **)(*param_2 + 0x290))(1);
        (**(code **)((int)local_810 + 0x288))(uVar20);
        FUN_005172d0(0);
        pfStack_800 = (float *)*pfStack_800;
      } while (pfStack_800 != local_818);
    }
    CVOGReaction_FireNestedReactions(param_1,param_2,0,1);
    break;
  case 0x36:
    (**(code **)(*param_1 + 0x2d0))(param_2,local_81c,0);
    local_824 = (float *)*local_818;
    if (local_824 != local_818) {
      do {
        piVar8 = (int *)local_824[2];
        if (*(int *)(piVar8[0x2a] + 0x38) == 0x36) {
          (**(code **)(*piVar8 + 0x1ec))();
          FUN_004294f0();
          pfStack_80c = (float *)0x0;
          iVar16 = FUN_004022a0(&pfStack_80c,&pfStack_820);
          while (iVar16 == 0) {
            if ((pfStack_820 != (float *)0x0) &&
               (cVar7 = (**(code **)(*param_1 + 0x2c4))(piVar8), cVar7 != '\0')) {
              (**(code **)((int)*pfStack_820 + 0x288))(0,1);
              FUN_005172d0(0);
            }
            iVar16 = FUN_004022a0(&pfStack_80c,&pfStack_820);
          }
          FUN_0040c700();
        }
        (**(code **)(*piVar8 + 0x288))(0,1);
        FUN_005172d0(0);
        local_824 = (float *)*local_824;
      } while (local_824 != local_818);
    }
    CVOGReaction_FireNestedReactions(param_1,param_2,0,1);
    break;
  case 0x37:
    (**(code **)(*param_1 + 0x2d0))(param_2,local_81c,0);
    pfVar19 = (float *)*local_818;
    if (pfVar19 != local_818) {
      do {
        local_824 = (float *)pfVar19[2];
        if (*(int *)((int)local_824[0x2a] + 0x38) == 0x36) {
          iVar16 = (**(code **)((int)*local_824 + 0x1ec))();
          piStack_7fc = (int *)(iVar16 + 0xb4);
          FUN_004294f0();
          pfStack_800 = (float *)0x0;
          iVar16 = FUN_004022a0(&pfStack_800,&pfStack_808);
          pfVar14 = pfStack_808;
          while (pfStack_808 = pfVar14, iVar16 == 0) {
            if (((pfVar14 != (float *)0x0) &&
                (cVar7 = (**(code **)(*param_1 + 0x2c4))(local_824), cVar7 != '\0')) &&
               (cVar7 = CVOGMap_LookupVariable(param_1[0x97],&pfStack_80c,pfVar14), cVar7 != '\0'))
            {
              local_810 = (float)(int)ROUND((float)pfStack_80c);
              (**(code **)((int)*pfVar14 + 0x288))(local_810,1);
              FUN_005172d0(0);
            }
            iVar16 = FUN_004022a0(&pfStack_800,&pfStack_808);
            pfVar14 = pfStack_808;
          }
          FUN_0040c700();
        }
        pfVar14 = local_824;
        cVar7 = CVOGMap_LookupVariable(param_1[0x97],&pfStack_820,local_824);
        if (cVar7 != '\0') {
          fStack_7e0 = (float)(int)ROUND((float)pfStack_820);
          (**(code **)((int)*pfVar14 + 0x288))(fStack_7e0,1);
          FUN_005172d0(0);
        }
        pfVar19 = (float *)*pfVar19;
      } while (pfVar19 != local_818);
    }
    CVOGReaction_FireNestedReactions(param_1,param_2,0,1);
    break;
  case 0x38:
    if (param_1[0x99] == 0) {
      (**(code **)(*param_1 + 0x2d0))(param_2,local_81c,1);
      pfVar19 = (float *)*local_818;
      if (pfVar19 != local_818) {
        do {
          iVar16 = (**(code **)(*(int *)pfVar19[2] + 0x210))(0);
          if (iVar16 != 0) {
            FUN_00530710(CONCAT22(extraout_var_01,(short)param_1[0x97]));
          }
          pfVar19 = (float *)*pfVar19;
        } while (pfVar19 != local_818);
      }
      CVOGReaction_FireNestedReactions(param_1,param_2,0,0);
    }
    else {
      cVar7 = (**(code **)(*param_1 + 0x2c4))(param_2);
      if (cVar7 != '\0') {
        local_810 = (float)param_1[0x99];
        piVar8 = (int *)FUN_0053b040(&local_810);
        if (param_1[0x97] + *piVar8 < 0) {
          local_810 = (float)param_1[0x99];
          puVar11 = (undefined4 *)FUN_0053b040(&local_810);
          *puVar11 = 0;
          CVOGReaction_FireNestedReactions(param_1,param_2,0,0);
        }
        else {
          local_810 = (float)param_1[0x99];
          piVar8 = (int *)FUN_0053b040(&local_810);
          *piVar8 = *piVar8 + param_1[0x97];
          CVOGReaction_FireNestedReactions(param_1,param_2,0,0);
        }
      }
    }
    break;
  case 0x39:
    if (param_1[0x97] == -1) {
      uVar10 = 0;
      iVar16 = FUN_004024b0();
      if (iVar16 != 0) {
        do {
          *(undefined2 *)(*(int *)(*(int *)(param_1[0x29] + 0xe75c) + uVar10 * 4) + 0x60c) = 0;
          uVar10 = uVar10 + 1;
          uVar12 = FUN_004024b0();
        } while (uVar10 < uVar12);
      }
      FUN_004058f0();
    }
    else {
      if (param_1[0x97] != 0) {
        puStack_828 = (undefined4 *)0x0;
        iVar16 = FUN_004024b0();
        if (iVar16 != 0) {
          do {
            iVar16 = *(int *)(*(int *)(param_1[0x29] + 0xe75c) + (int)puStack_828 * 4);
            iVar16 = (**(code **)(*(int *)(*(int *)(*(int *)(iVar16 + 4) + 4) + 4 + iVar16) + 0x28c)
                     )();
            if (iVar16 == param_1[0x97]) {
              *(undefined2 *)
               (*(int *)(*(int *)(param_1[0x29] + 0xe75c) + (int)puStack_828 * 4) + 0x60c) = 0;
            }
            puStack_828 = (undefined4 *)((int)puStack_828 + 1);
            uVar10 = FUN_004024b0();
          } while (puStack_828 < uVar10);
        }
        local_810 = (float)param_1[0x97];
        puVar11 = (undefined4 *)FUN_0053b040(&local_810);
        *puVar11 = 0;
        CVOGReaction_FireNestedReactions(param_1,param_2,0,0);
        break;
      }
      (**(code **)(*param_1 + 0x2d0))(param_2,local_81c,1);
      pfVar19 = (float *)*local_818;
      if (pfVar19 != local_818) {
        do {
          iVar16 = (**(code **)(*(int *)pfVar19[2] + 0x210))(0);
          if (iVar16 != 0) {
            local_810 = (float)(**(code **)(*(int *)(*(int *)(*(int *)(iVar16 + 4) + 4) + 4 + iVar16
                                                    ) + 0x28c))();
            piVar8 = (int *)FUN_0053b040(&local_810);
            *piVar8 = *piVar8 - (uint)*(ushort *)(iVar16 + 0x60c);
            *(undefined2 *)(iVar16 + 0x60c) = 0;
          }
          pfVar19 = (float *)*pfVar19;
        } while (pfVar19 != local_818);
        CVOGReaction_FireNestedReactions(param_1,param_2,0,0);
        break;
      }
    }
    CVOGReaction_FireNestedReactions(param_1,param_2,0,0);
    break;
  case 0x3a:
    cVar7 = (**(code **)(*param_1 + 0x2c4))(param_2);
    if (cVar7 == '\0') break;
    uStack_77c = 0xb;
    goto LAB_0057f8d2;
  case 0x3b:
    cVar7 = (**(code **)(*param_1 + 0x2c4))(param_2);
    if (cVar7 == '\0') break;
    uStack_77c = 0x10;
    goto LAB_0057f8d2;
  case 0x3c:
    cVar7 = (**(code **)(*param_1 + 0x2c4))(param_2);
    if (cVar7 != '\0') {
      (**(code **)(*param_1 + 0x2d0))(param_2,local_81c,1);
      pfVar19 = (float *)*local_818;
      if (pfVar19 != local_818) {
        do {
          iVar16 = (**(code **)(*(int *)pfVar19[2] + 0x210))(0);
          if (iVar16 != 0) {
            CVOGReaction_FireNestedReactions
                      (param_1,*(int *)(*(int *)(iVar16 + 4) + 4) + 4 + iVar16,1,0);
            if ((*(int **)(param_1[0x29] + 0xe8a0) != (int *)0x0) &&
               (iVar17 = (**(code **)(**(int **)(param_1[0x29] + 0xe8a0) + 0x210))(0),
               iVar16 == iVar17)) {
              iStack_778 = param_1[0x99];
              iStack_798 = param_1[0x97];
              iStack_774 = iStack_778 >> 0x1f;
              uStack_77c = 0x12;
              Client_SendLogicUiPacket(&iStack_798);
            }
          }
          pfVar19 = (float *)*pfVar19;
        } while (pfVar19 != local_818);
      }
    }
    break;
  case 0x3d:
    cVar7 = (**(code **)(*param_1 + 0x2c4))(param_2);
    if ((cVar7 != '\0') && (*(char *)(param_1[0x29] + 0x7e) != '\0')) {
      if (*(char *)((int)param_1 + 0x205) == '\0') {
        *(undefined1 *)((int)param_1 + 0x205) = 1;
        iVar16 = (**(code **)(*param_2 + 0x210))(0);
        if (iVar16 != 0) {
          uVar6 = CVOGReaction_RecordFirstTimeEvent(param_1);
          *(undefined1 *)((int)param_1 + 0x205) = uVar6;
        }
      }
      FUN_00403430();
      ExceptionList = pvStack_1c;
      return 0;
    }
    break;
  case 0x3e:
    (**(code **)(*param_1 + 0x2d0))(param_2,local_81c,1);
    pfVar19 = (float *)*local_818;
    if (pfVar19 != local_818) {
      do {
        fVar23 = pfVar19[2];
        iStack_798 = param_1[0x97];
        fStack_794 = (float)param_1[0x99];
        iStack_770 = *(int *)((int)fVar23 + 0x160);
        iStack_790 = (int)(float)param_1[0x98];
        iStack_76c = *(int *)((int)fVar23 + 0x164);
        iStack_768 = *(int *)((int)fVar23 + 0x168);
        iStack_764 = *(int *)((int)fVar23 + 0x16c);
        uStack_77c = 0x15;
        Client_SendLogicUiPacket(&iStack_798);
        pfVar19 = (float *)*pfVar19;
      } while (pfVar19 != local_818);
    }
    CVOGReaction_FireNestedReactions(param_1,param_2,0,0);
    break;
  case 0x3f:
    (**(code **)(*param_1 + 0x2d0))(param_2,local_81c,1);
    pfVar19 = (float *)*local_818;
    if (pfVar19 != local_818) {
      do {
        fVar23 = pfVar19[2];
        iStack_798 = param_1[0x97];
        fStack_794 = (float)param_1[0x99];
        iStack_790 = (int)(float)param_1[0x98];
        iStack_770 = *(int *)((int)fVar23 + 0x160);
        iStack_76c = *(int *)((int)fVar23 + 0x164);
        iStack_768 = *(int *)((int)fVar23 + 0x168);
        iStack_764 = *(int *)((int)fVar23 + 0x16c);
        uStack_77c = 0x16;
        Client_SendLogicUiPacket(&iStack_798);
        pfVar19 = (float *)*pfVar19;
      } while (pfVar19 != local_818);
    }
    goto LAB_0057f140;
  case 0x40:
    cVar7 = (**(code **)(*param_1 + 0x2c4))(param_2);
    if (cVar7 == '\0') break;
    iStack_798 = param_1[0x97];
    uStack_77c = 0x19;
    if (param_1[0x94] == 0) {
      acStack_760[0] = '\0';
    }
    else {
      FUN_00793aa0(acStack_760,param_1[0x94],0x100);
    }
    goto LAB_0057f12f;
  case 0x41:
    cVar7 = (**(code **)(*param_1 + 0x2c4))(param_2);
    if (cVar7 == '\0') break;
    iStack_798 = param_1[0x97];
    fStack_794 = (float)param_1[0x99];
    iStack_78c = param_1[0x98];
    uStack_77c = 0x1b;
    if (param_1[0x94] == 0) {
      acStack_760[0] = '\0';
    }
    else {
      FUN_00793aa0(acStack_760,param_1[0x94],0x100);
    }
    goto LAB_0057f12f;
  case 0x42:
    cVar7 = (**(code **)(*param_1 + 0x2c4))(param_2);
    if (cVar7 == '\0') break;
    iStack_798 = param_1[0x97];
    uStack_77c = 0x1c;
    goto LAB_0057f12f;
  case 0x43:
    cVar7 = (**(code **)(*param_1 + 0x2c4))(param_2);
    if (cVar7 == '\0') break;
    iStack_798 = param_1[0x97];
    uStack_77c = 0x1a;
    goto LAB_0057f12f;
  case 0x44:
    cVar7 = (**(code **)(*param_1 + 0x2c4))(param_2);
    if (cVar7 == '\0') break;
    uStack_77c = 0x17;
    goto LAB_0057f3b3;
  case 0x45:
    cVar7 = (**(code **)(*param_1 + 0x2c4))(param_2);
    if (cVar7 == '\0') break;
    uStack_77c = 0x18;
LAB_0057f3b3:
    iStack_798 = param_1[0x97];
    iStack_770 = param_2[0x58];
    iStack_76c = param_2[0x59];
    iStack_768 = param_2[0x5a];
    iStack_764 = param_2[0x5b];
    goto LAB_0057f12f;
  case 0x46:
    (**(code **)(*param_1 + 0x2d0))(param_2,local_81c,0);
    pfVar19 = (float *)*local_818;
    if (pfVar19 != local_818) {
      do {
        iVar16 = (**(code **)(*(int *)pfVar19[2] + 0x210))(0);
        if (iVar16 != 0) {
          CVOGReaction_RelockContinentObject(param_1[0x97]);
        }
        pfVar19 = (float *)*pfVar19;
      } while (pfVar19 != local_818);
    }
    CVOGReaction_FireNestedReactions(param_1,param_2,0,0);
    break;
  case 0x47:
    cVar7 = (**(code **)(*param_1 + 0x2c4))(param_2);
    if ((cVar7 == '\0') || (iVar16 = (**(code **)(*param_2 + 0x1dc))(), iVar16 == 0)) break;
    iVar16 = (**(code **)(*param_2 + 0x1dc))();
    if (iVar16 != 0) {
      iVar16 = (**(code **)(*param_2 + 0x1dc))();
      *(int *)(iVar16 + 0x590) = param_1[0x97];
      *(int *)(iVar16 + 0x594) = param_1[0x99];
    }
    iStack_798 = param_1[0x97];
    local_810 = (float)param_1[0x98];
    uStack_77c = 0x1d;
    fStack_7e0 = (float)(int)ROUND(local_810);
    iStack_790 = param_1[0x99];
    fStack_794 = fStack_7e0;
    goto LAB_0057f8e5;
  case 0x48:
    cVar7 = CVOGCharacter_WeaponAllowsKillXpBonus();
    if (cVar7 != '\0') {
      *(undefined1 *)(param_1 + 0x7d) = 1;
    }
    (**(code **)(*param_1 + 0x2d0))(param_2,local_81c,0);
    pfVar19 = (float *)*local_818;
    if (pfVar19 != local_818) {
      do {
        iVar16 = (**(code **)(*(int *)pfVar19[2] + 0x210))(0);
        if (iVar16 != 0) {
          CVOGReaction_FailMission(param_1[0x97]);
          CVOGReaction_FireNestedReactions
                    (param_1,*(int *)(*(int *)(iVar16 + 4) + 4) + 4 + iVar16,1,0);
        }
        pfVar19 = (float *)*pfVar19;
      } while (pfVar19 != local_818);
    }
    break;
  case 0x49:
    if (pfVar19 != local_824) {
      do {
        piVar8 = (int *)CVOGReaction_ResolveObjectTarget(0,*pfVar19,pfVar19[1]);
        if ((piVar8 != (int *)0x0) && (iVar16 = (**(code **)(*piVar8 + 0x1ec))(), iVar16 != 0)) {
          uVar20 = 0;
          (**(code **)(*piVar8 + 0x1ec))(0);
          FUN_00566a60(uVar20);
        }
        pfVar19 = pfVar19 + 2;
      } while (pfVar19 != local_824);
    }
    break;
  case 0x4a:
    cVar7 = (**(code **)(*param_1 + 0x2c4))(param_2);
    if (cVar7 == '\0') break;
    iStack_798 = param_1[0x97];
    uStack_77c = 0x24;
    goto LAB_0057f8e5;
  case 0x4b:
    cVar7 = (**(code **)(*param_1 + 0x2c4))(param_2);
    if (cVar7 == '\0') break;
    iStack_798 = param_1[0x97];
    uStack_77c = 0x25;
    goto LAB_0057f8e5;
  case 0x4c:
    pcVar18 = (char *)param_1[0x8b];
    if (pcVar18 != (char *)0x0) {
      uStack_77c = 0x27;
      iVar16 = -(int)pcVar18;
      do {
        cVar7 = *pcVar18;
        pcVar18[(int)(acStack_760 + iVar16)] = cVar7;
        pcVar18 = pcVar18 + 1;
      } while (cVar7 != '\0');
      goto LAB_0057f8e5;
    }
    goto LAB_0057f8f6;
  case 0x4d:
    if (param_1[0x8b] != 0) {
      (**(code **)(*param_1 + 0x2d0))(param_2,local_81c,0);
      pfVar19 = (float *)*local_818;
      if (pfVar19 != local_818) {
        do {
          iVar16 = (**(code **)(*(int *)pfVar19[2] + 0x210))(0);
          if (iVar16 != 0) {
            if ((*(int *)(param_1[0x29] + 0xe8a0) != 0) &&
               (iVar17 = TFID_EqualsObjectId((void *)(*(int *)(*(int *)(iVar16 + 4) + 4) + 0x164 +
                                                     iVar16),
                                             (void *)(*(int *)(param_1[0x29] + 0xe8a0) + 0x160)),
               (char)iVar17 != '\0')) {
              pcVar18 = (char *)param_1[0x8b];
              uStack_77c = 0x28;
              iVar17 = -(int)pcVar18;
              do {
                cVar7 = *pcVar18;
                pcVar18[(int)(acStack_760 + iVar17)] = cVar7;
                pcVar18 = pcVar18 + 1;
              } while (cVar7 != '\0');
              iStack_798 = param_1[0x97];
              Client_SendLogicUiPacket(&iStack_798);
            }
            CVOGReaction_FireNestedReactions
                      (param_1,*(int *)(*(int *)(iVar16 + 4) + 4) + 4 + iVar16,1,0);
          }
          pfVar19 = (float *)*pfVar19;
        } while (pfVar19 != local_818);
      }
    }
    break;
  case 0x4e:
    iVar16 = FUN_004bb2e0(0,param_1[0x97],param_1[0x97] >> 0x1f);
    if (iVar16 != 0) {
      FUN_006082e0(param_2);
    }
    break;
  case 0x4f:
    cVar7 = (**(code **)(*param_1 + 0x2c4))(param_2);
    if (((cVar7 != '\0') && (param_2 != (int *)0x0)) &&
       (pvVar15 = (void *)(**(code **)(*param_2 + 0x210))(0), pvVar15 != (void *)0x0)) {
      iVar16 = (**(code **)(*(int *)(*(int *)(*(int *)((int)pvVar15 + 4) + 4) + 4 + (int)pvVar15) +
                           0x27c))();
      iVar16 = Experience_XpToReachRelativeLevel(pvVar15,param_1[0x97] - iVar16);
      if (0 < iVar16) {
        CVOGReaction_AddExperience(pvVar15,iVar16,PacketOrNonKill);
      }
    }
    break;
  case 0x50:
    cVar7 = (**(code **)(*param_1 + 0x2c4))(param_2);
    if (cVar7 == '\0') break;
    uStack_77c = 0x2e;
    goto LAB_0057f8d2;
  case 0x51:
    if ((((param_2 != (int *)0x0) && (iVar16 = (**(code **)(*param_2 + 0x210))(0), iVar16 != 0)) &&
        (*(int *)(*(int *)(*(int *)(iVar16 + 4) + 4) + 0xa8 + iVar16) != 0)) &&
       (cVar7 = (**(code **)(*param_1 + 0x2c4))(param_2), cVar7 != '\0')) {
      iVar17 = param_1[0x97];
      pfVar19 = (float *)(**(code **)(*(int *)(*(int *)(*(int *)(iVar16 + 4) + 4) + 4 + iVar16) +
                                     0x1a0))();
      fStack_7f0 = *pfVar19;
      fStack_7ec = pfVar19[1];
      pfStack_7e8 = (float *)pfVar19[2];
      fStack_7e4 = pfVar19[3];
      uVar31 = 0;
      uVar30 = 0;
      pfVar19 = &fStack_7f0;
      iVar13 = iVar16;
      iVar28 = iVar17;
      uVar20 = (**(code **)(*(int *)(*(int *)(*(int *)(iVar16 + 4) + 4) + iVar16 + 4) + 0x27c))
                         (iVar16,pfVar19,iVar17,0,0);
      FUN_004d4440(uVar20,iVar13,pfVar19,iVar28,uVar30,uVar31);
      iVar13 = *(int *)(*(int *)(iVar16 + 4) + 4);
      uVar20 = *(undefined4 *)(iVar13 + 0xa8 + iVar16);
      uVar32 = 0;
      uVar31 = 0;
      uVar30 = (**(code **)(*(int *)(iVar13 + iVar16 + 4) + 0x27c))(iVar17,0,0);
      pfVar19 = &fStack_7f0;
      FUN_004ce940(iVar16,uVar20,pfVar19,uVar30);
      FUN_0050ac80(iVar16,uVar20,pfVar19,uVar30,iVar17,uVar31,uVar32);
    }
    break;
  case 0x52:
    (**(code **)(*param_1 + 0x2d0))(param_2,local_81c,1);
    if ((local_814 != 0) && (iVar16 = FUN_004d2a20(param_1[0x99]), iVar16 != 0)) {
      FUN_005a5130(0);
      if (param_1[0x8b] != 0) {
        FUN_00418870(param_1[0x8b]);
      }
      pfVar19 = (float *)*local_818;
      if (pfVar19 != local_818) {
        do {
          iVar16 = (**(code **)(*(int *)pfVar19[2] + 0x210))(0);
          if (iVar16 != 0) {
            CVOGReaction_FireNestedReactions
                      (param_1,*(int *)(*(int *)(iVar16 + 4) + 4) + 4 + iVar16,1,0);
          }
          pfVar19 = (float *)*pfVar19;
        } while (pfVar19 != local_818);
      }
    }
    break;
  case 0x53:
    (**(code **)(*param_1 + 0x2d0))(param_2,local_81c,0);
    local_824 = (float *)*local_818;
    if (local_824 != local_818) {
      do {
        pfVar19 = (float *)(**(code **)(*(int *)local_824[2] + 0x210))(0);
        pfStack_80c = pfVar19;
        if ((((pfVar19 != (float *)0x0) &&
             (pfStack_820 = CNDHash_LookupByKey((void *)pfVar19[0x152],(uint)pfVar19[0x35c]),
             pfVar19[0x35b] == 1.4013e-45)) && (pfStack_820 != (float *)0x0)) &&
           (puStack_828 = (undefined4 *)pfStack_820[0x56],
           puStack_828 != (undefined4 *)pfStack_820[0x57])) {
          do {
            piVar8 = (int *)*puStack_828;
            iVar16 = (**(code **)(*piVar8 + 0x50))();
            if (iVar16 == 0xe) {
              iVar16 = __RTDynamicCast(piVar8,0,&CVOGObjectiveRequirement::RTTI_Type_Descriptor,
                                       &CVOGObjectiveRequirement_CrazyTaxi::RTTI_Type_Descriptor,0);
              local_810 = *(float *)(*(int *)(*(int *)((int)pfStack_80c[1] + 4) + 0xa8 +
                                             (int)pfStack_80c) + 0xe4e8);
              uVar24 = FUN_0057fd00(*(undefined4 *)(iVar16 + 0x94));
              local_810 = (float)FUN_004bb1c0(0,uVar24);
              if ((local_810 != 0.0) && (*(char *)(iVar16 + 0xa9) != '\0')) {
                pfVar19 = (float *)(**(code **)(*param_2 + 0x1a0))();
                fStack_7f0 = *pfVar19;
                fStack_7ec = pfVar19[1];
                pfStack_7e8 = (float *)pfVar19[2];
                FUN_00567020(&fStack_7e0);
                if (((fStack_7f0 - fStack_7e0) * (fStack_7f0 - fStack_7e0) +
                     ((float)pfStack_7e8 - fStack_7d8) * ((float)pfStack_7e8 - fStack_7d8) +
                     (fStack_7ec - fStack_7dc) * (fStack_7ec - fStack_7dc) <=
                     *(float *)(iVar16 + 0x60) * *(float *)(iVar16 + 0x60)) &&
                   (pfVar19 = (float *)(**(code **)(*param_2 + 0x1a8))(),
                   SQRT(pfVar19[2] * pfVar19[2] + pfVar19[1] * pfVar19[1] + *pfVar19 * *pfVar19) <=
                   *(float *)(iVar16 + 0x5c))) {
                  fStack_794 = *(float *)(iVar16 + 0x98);
                  iStack_798 = *(int *)(iVar16 + 0x94);
                  iStack_78c = *(int *)(iVar16 + 0xa0);
                  uStack_77c = 0x2f;
                  Client_SendLogicUiPacket(&iStack_798);
                  *(undefined4 *)(iVar16 + 0xa4) = *(undefined4 *)(iVar16 + 0xa0);
                  *(undefined1 *)(iVar16 + 0xa9) = 0;
                  *(undefined4 *)(iVar16 + 0x94) = 0xffffffff;
                }
              }
            }
            puStack_828 = puStack_828 + 1;
          } while (puStack_828 != (undefined4 *)pfStack_820[0x57]);
        }
        local_824 = (float *)*local_824;
      } while (local_824 != local_818);
    }
    goto LAB_0057f8f6;
  case 0x54:
    iVar16 = (**(code **)(*param_2 + 0x210))(0);
    if (iVar16 != 0) {
      uStack_77c = 0x33;
      iVar16 = (**(code **)(*param_2 + 0x210))(0);
      piVar8 = (int *)(*(int *)(*(int *)(iVar16 + 4) + 4) + 0x164 + iVar16);
      iStack_770 = *piVar8;
      iStack_76c = piVar8[1];
      iStack_768 = piVar8[2];
      iStack_764 = piVar8[3];
      iStack_798 = param_1[0x97];
      iStack_790 = param_1[0x99];
      goto LAB_0057f12f;
    }
    goto LAB_0057f140;
  case 0x55:
    uStack_77c = 0x35;
LAB_0057f12f:
    Client_SendLogicUiPacket(&iStack_798);
LAB_0057f140:
    CVOGReaction_FireNestedReactions(param_1,param_2,0,0);
    break;
  case 0x56:
    cVar7 = (**(code **)(*param_1 + 0x2c4))(param_2);
    if (cVar7 == '\0') break;
    uStack_77c = 0x36;
    iStack_798 = 1;
    goto LAB_0057f8e5;
  case 0x57:
    cVar7 = (**(code **)(*param_1 + 0x2c4))(param_2);
    if (cVar7 == '\0') break;
    uStack_77c = 0x37;
LAB_0057f8d2:
    iStack_798 = 1;
LAB_0057f8e5:
    Client_SendLogicUiPacket(&iStack_798);
LAB_0057f8f6:
    CVOGReaction_FireNestedReactions(param_1,param_2,1,0);
  }
  FUN_00403430();
  ExceptionList = pvStack_1c;
  return 1;
}
`

## Open questions

- Confirm calling convention and full signature against callers.
- Recover meaningful types for still-generic parameters.
- Dual independent reconstruction review for this manager unit.
