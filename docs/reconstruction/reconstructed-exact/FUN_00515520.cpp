// =============================================================================
// FUN_00515520
// -----------------------------------------------------------------------------
// Stable ID: aa_00515520
// Address:   0x00515520  (autoassault.exe, image base 0x400000)
// System:    object / combat-outcome virtual
// Generated: 2026-07-29 W27-M dual seal
// Exactness: Behavior-preserving rewrite of decompiler control flow. Not modernization.
// Bit-for-bit vs retail EXE: DEFERRED. Large function — unaff_* temps are decompiler noise.
// =============================================================================
// PURPOSE: Virtual CVOGObject method (26 vtable installs). Validates actors, gathers
// level/theory/linked inputs, rolls 6 short channels, optional reaction-list apply,
// returns clamped int. ABI: thiscall ret 0x28.
// Name: Ghidra FUN_00515520; inferred CVOGObject_ComputeOutcomeRolls_Inferred.
// WARNING: shared float pool names are not product multi-kill evidence.
//

/* WARNING: Globals starting with '_' overlap smaller symbols at the same address.
 * Decompiler reports unaff_* / float-as-pointer artifacts — preserve control flow.
 */

int __thiscall
FUN_00515520(int *param_1,int *param_2,char param_3,char param_4,uint32_t param_5,int param_6,
            int param_7)

{
  short *psVar1;
  char cVar2;
  short sVar3;
  int iVar4;
  float fVar5;
  void *pA;
  TFID_16 *pTfid;
  int *piVar6;
  int iVar7;
  uint32_t *puVar8;
  int iVar9;
  uint uVar10;
  ushort uVar11;
  int *piVar12;
  int *piVar13;
  uint unaff_EBP;
  uint32_t unaff_ESI;
  int iVar14;
  short sVar15;
  short sVar16;
  uint32_t unaff_EDI;
  int *piVar17;
  bool bVar18;
  float fVar19;
  double dVar20;
  uint32_t *unaff_retaddr;
  float in_stack_00000028;
  byte *pB;
  uint8_t *puVar21;
  char cVar22;
  int *piStack_c0;
  int iStack_bc;
  uint uStack_b8;
  int *piStack_b4;
  int iStack_b0;
  int *piStack_ac;
  float fStack_a8;
  float fStack_a4;
  ushort *puStack_a0;
  short asStack_9c [2];
  uint32_t uStack_98;
  uint32_t uStack_94;
  uint32_t uStack_90;
  uint32_t uStack_8c;
  uint32_t uStack_88;
  uint32_t uStack_84;
  uint32_t uStack_80;
  uint32_t uStack_7c;
  uint32_t local_78;
  float fStack_74;
  int iStack_70;
  int iStack_6c;
  int iStack_68;
  int iStack_64;
  uint32_t local_60;
  uint32_t uStack_5c;
  int iStack_58;
  short asStack_54 [8];
  uint32_t uStack_44;
  uint32_t uStack_40;
  uint32_t uStack_3c;
  uint32_t uStack_38;
  uint32_t uStack_34;
  float fStack_30;
  float fStack_2c;
  float fStack_28;
  int iStack_24;
  int iStack_20;
  short asStack_1c [2];
  uint8_t auStack_18 [16];
  int *piStack_8;
  
  cVar22 = (char)((uint)unaff_ESI >> 8);
  iVar14 = 0;
  local_60 = 0;
  local_78 = param_1;
  if (param_2 != (int *)0x0) {
    if (((int *)param_2[0x2b] != (int *)0x0) &&
       (iVar4 = (**(code **)(*(int *)param_2[0x2b] + 0x1d4))(), iVar4 != 0)) {
      (**(code **)(*(int *)param_2[0x2b] + 0x1d4))();
      (**(code **)(*(int *)param_2[0x2b] + 0x1d4))();
      FUN_004f4e50();
    }
    iVar4 = (**(code **)(*param_2 + 0x214))();
    if (iVar4 == 0) {
      local_60 = (**(code **)(*param_2 + 0x27c))();
    }
    else {
      (**(code **)(*param_2 + 0x214))();
      iVar4 = (**(code **)(*param_2 + 0x214))();
      local_60 = (**(code **)(*(int *)(*(int *)(*(int *)(iVar4 + 4) + 4) + 4 + iVar4) + 0x27c))();
      (**(code **)(*param_2 + 0x214))();
    }
    cVar2 = (**(code **)(*param_2 + 0x198))();
    if (cVar2 != '\0') {
      return 0;
    }
    iVar4 = (**(code **)(*param_2 + 0x210))(0);
    if (iVar4 != 0) {
      iVar4 = (**(code **)(*param_2 + 0x210))(0);
      cVar2 = (**(code **)(*(int *)(*(int *)(*(int *)(iVar4 + 4) + 4) + 4 + iVar4) + 0x198))();
      if (cVar2 != '\0') {
        return 0;
      }
    }
  }
  uStack_5c = (**(code **)(*param_1 + 0x27c))();
  iVar4 = (**(code **)(*param_1 + 0x214))();
  if (iVar4 != 0) {
    (**(code **)(*param_1 + 0x214))();
    iVar4 = (**(code **)(*param_1 + 0x214))();
    uStack_5c = (**(code **)(*(int *)(*(int *)(*(int *)(iVar4 + 4) + 4) + 4 + iVar4) + 0x27c))();
  }
  iVar4 = (**(code **)(*param_1 + 0x1d4))();
  if (iVar4 != 0) {
    (**(code **)(*param_1 + 0x1d4))();
    (**(code **)(*param_1 + 0x1d4))();
    uStack_5c = FUN_004f4e50();
  }
  if (param_2 == (int *)0x0) {
    fVar5 = 0.0;
  }
  else {
    fVar5 = (float)(**(code **)(*param_2 + 0x1e0))();
  }
  piStack_ac = (int *)(int)in_stack_00000028;
  asStack_9c[0] = 0;
  asStack_9c[1] = 0;
  piStack_b4 = (int *)0x0;
  iStack_b0 = 0;
  fStack_a8 = 0.0;
  iStack_68 = 0;
  piStack_c0 = (int *)((uint)piStack_c0 & 0xffffff);
  uStack_b8 = uStack_b8 & 0xffffff;
  piStack_c0._0_2_ = (ushort)(byte)piStack_c0;
  if ((*(byte *)(param_1 + 0x2d) & 1) != 0) {
    return 0;
  }
  fStack_a4 = fVar5;
  if (fVar5 != 0.0) {
    iStack_68 = FUN_0056add0();
  }
  iVar4 = (**(code **)(*param_1 + 0x1d4))();
  if (((iVar4 == 0) || (iVar4 = (**(code **)(*param_1 + 0x1d4))(), *(int *)(iVar4 + 0x254) == 0)) ||
     (iVar4 = (**(code **)(*param_1 + 0x1d4))(),
     *(int *)(*(int *)(*(int *)(*(int *)(*(int *)(iVar4 + 0x254) + 4) + 4) + 0xac +
                      *(int *)(iVar4 + 0x254)) + 0x3c) == 0)) {
    iVar4 = (**(code **)(*param_1 + 0x1d8))();
    if (iVar4 != 0) {
      iVar4 = (**(code **)(*param_1 + 0x1d8))();
      iStack_b0 = (int)*(float *)(iVar4 + 0x268);
    }
  }
  else {
    iVar4 = (**(code **)(*param_1 + 0x1d4))();
    iStack_b0 = *(int *)(*(int *)(*(int *)(*(int *)(*(int *)(*(int *)(iVar4 + 0x254) + 4) + 4) +
                                           0xac + *(int *)(iVar4 + 0x254)) + 0x3c) + 0x4c0);
  }
  iVar4 = (**(code **)(*param_1 + 0x210))(0);
  if (iVar4 != 0) {
    iVar4 = (**(code **)(*param_1 + 0x210))(0);
    piStack_b4 = (int *)((int)piStack_b4 + (int)*(float *)(iVar4 + 0x268));
  }
  if (fVar5 == 0.0) {
    iVar4 = (**(code **)(*param_1 + 0x1d8))();
    if (iVar4 != 0) {
      iVar4 = (**(code **)(*param_1 + 0x1d8))();
      iStack_b0 = iStack_b0 + (int)*(float *)(iVar4 + 0x264);
    }
  }
  else {
    iVar4 = *(int *)(*(int *)(*(int *)((int)fVar5 + 4) + 4) + 0xac + (int)fVar5);
    if (iVar4 == 0) {
      iVar4 = 0;
    }
    else {
      iVar4 = *(int *)(iVar4 + 0x3c);
    }
    iStack_b0 = *(short *)((int)fVar5 + 0x118) + iStack_b0 + (int)*(short *)(iVar4 + 0x530);
  }
  if (((param_2 != (int *)0x0) && (iVar4 = (**(code **)(*param_2 + 0x210))(0), iVar4 != 0)) &&
     (iVar4 = (**(code **)(*param_1 + 0x210))(0), iVar4 != 0)) {
    unaff_EBP = unaff_EBP & 0xffff0000;
  }
  iVar4 = (**(code **)(*param_1 + 0x210))(0);
  if (iVar4 == 0) {
LAB_005158ea:
    if (((param_2 != (int *)0x0) && (iVar4 = (**(code **)(*param_2 + 0x210))(0), iVar4 != 0)) &&
       (piStack_ac != (int *)0x0)) {
      iVar4 = (**(code **)(*param_2 + 0x210))(0);
      piStack_b4 = (int *)((int)piStack_b4 + (int)*(float *)(iVar4 + 0x264));
    }
  }
  else if (param_2 != (int *)0x0) {
    iVar4 = (**(code **)(*param_2 + 0x1d8))();
    if (iVar4 != 0) {
      pB = g_abTfidInvalid_9CDF88;
      (**(code **)(*param_2 + 0x1d8))();
      pA = (void *)FUN_0040aff0();
      iVar4 = TFID_NotEquals(pA,pB);
      if ((char)iVar4 != '\0') {
        puVar21 = auStack_18;
        (**(code **)(*param_2 + 0x1d8))(puVar21);
        pTfid = (TFID_16 *)FUN_0040aff0(puVar21);
        piVar6 = Object_ResolveFromTFID(pTfid);
        if ((piVar6 != (int *)0x0) && (iVar4 = (**(code **)(*piVar6 + 0x1dc))(), iVar4 != 0)) {
          cVar22 = '\x01';
        }
      }
    }
    goto LAB_005158ea;
  }
  fStack_a8 = g_flOne;
  if (param_2 != (int *)0x0) {
    fVar19 = (float)(iStack_64 - iStack_68) * g_flMultiKillCountBlend;
    fVar5 = fVar19;
    if (fVar19 <= 0.0) {
      fVar5 = 0.0;
    }
    fStack_a8 = DAT_00af1b70;
    if (DAT_00af1b70 < g_flOne - fVar5) {
      if (fVar19 <= 0.0) {
        fVar19 = 0.0;
      }
      fStack_a8 = g_flOne - fVar19;
    }
  }
  if (cVar22 != '\0') {
    fVar5 = (float)(int)uStack_b8 * fStack_a8;
    if (0.0 <= fVar5) {
      fVar5 = fVar5 + g_flMissionXpRoundBias;
    }
    else {
      fVar5 = fVar5 - g_flMissionXpRoundBias;
    }
    uStack_b8 = (uint)fVar5;
  }
  if ((param_2 != (int *)0x0) && (iVar4 = (**(code **)(*param_2 + 0x214))(), iVar4 != 0)) {
    (**(code **)(*param_2 + 0x214))();
    sVar3 = FUN_004c4140();
    iStack_b0 = (int)sVar3;
  }
  local_60 = 0;
  uStack_44 = 0;
  uStack_38 = 0;
  uStack_5c = 0;
  uStack_40 = 0;
  uStack_34 = 0;
  iStack_58 = 0;
  uStack_3c = 0;
  fStack_30 = 0.0;
  uStack_8c = *unaff_retaddr;
  asStack_54[2] = 0;
  asStack_54[3] = 0;
  asStack_54[4] = 0;
  asStack_54[5] = 0;
  asStack_54[6] = 0;
  asStack_54[7] = 0;
  uStack_88 = unaff_retaddr[1];
  uStack_84 = (int *)unaff_retaddr[2];
  uStack_98 = *param_2;
  uStack_94 = param_2[1];
  uStack_90 = param_2[2];
  iVar4 = *(int *)(param_1[0x2a] + 0x3c);
  uStack_7c = *(uint32_t *)(iVar4 + 0x48c);
  local_78 = *(int **)(iVar4 + 0x490);
  fStack_74 = *(float *)(iVar4 + 0x494);
  if (param_2 != (int *)0x0) {
    iVar14 = (**(code **)(*param_2 + 0x210))(0);
    if (((iVar14 != 0) && (iStack_b0 != 0)) &&
       (*(short *)(*(int *)(*(int *)(*(int *)(*(int *)(iStack_b0 + 4) + 4) + 0xac + iStack_b0) +
                           0x3c) + 0x3f4) == 0)) {
      iVar14 = 0;
      do {
        sVar3 = *(short *)((int)&uStack_90 + iVar14);
        if ((0 < sVar3) || (0 < *(short *)((int)asStack_9c + iVar14))) {
          iStack_70 = *(int *)(param_1[0x29] + 0xe83c);
          uVar10 = 0;
          iVar4 = (**(code **)(*param_2 + 0x210))();
          fVar5 = (float)(int)sVar3 *
                  *(float *)(&DAT_009cdf9c +
                            (uint)*(byte *)(*(int *)(*(int *)(*(int *)(*(int *)(iVar4 + 4) + 4) +
                                                              0xac + iVar4) + 0x3c) + 0x531) * 4) *
                  fStack_74;
          if (0.0 <= fVar5) {
            fVar5 = fVar5 + g_flMissionXpRoundBias;
          }
          else {
            fVar5 = fVar5 - g_flMissionXpRoundBias;
          }
          iVar4 = *param_2;
          fStack_a4 = *(float *)(param_1[0x29] + 0xe83c);
          *(short *)((int)&uStack_94 + iVar14) = (short)(int)fVar5;
          iVar4 = (**(code **)(iVar4 + 0x210))((ulonglong)uVar10 << 0x20);
          fVar19 = (float)(int)*(short *)((int)asStack_9c + iVar14) *
                   *(float *)(&DAT_009cdf9c +
                             (uint)*(byte *)(*(int *)(*(int *)(*(int *)(*(int *)(iVar4 + 4) + 4) +
                                                               0xac + iVar4) + 0x3c) + 0x531) * 4) *
                   (float)puStack_a0;
          if (0.0 <= fVar19) {
            fVar19 = fVar19 + g_flMissionXpRoundBias;
          }
          else {
            fVar19 = fVar19 - g_flMissionXpRoundBias;
          }
          *(short *)((int)asStack_9c + iVar14) = (short)(int)fVar19;
          if ((short)(int)fVar5 < 1) {
            *(uint16_t *)((int)&uStack_90 + iVar14) = 1;
          }
          if ((short)(int)fVar19 < 2) {
            *(uint16_t *)((int)asStack_9c + iVar14) = 2;
          }
        }
        iVar14 = iVar14 + 2;
      } while (iVar14 < 0xc);
    }
    iVar14 = (**(code **)(*param_2 + 0x214))();
  }
  if ((param_3 != '\0') && (iVar14 != 0)) {
    uStack_8c = CONCAT22(uStack_8c._2_2_ + *(short *)(iVar14 + 0x196),
                         (short)uStack_8c + *(short *)(iVar14 + 0x194));
    uStack_98 = CONCAT22(uStack_98._2_2_ + *(short *)(iVar14 + 0x17e),
                         (short)uStack_98 + *(short *)(iVar14 + 0x17c));
    uStack_88 = CONCAT22(uStack_88._2_2_ + *(short *)(iVar14 + 0x19a),
                         (short)uStack_88 + *(short *)(iVar14 + 0x198));
    uStack_94 = CONCAT22(uStack_94._2_2_ + *(short *)(iVar14 + 0x182),
                         (short)uStack_94 + *(short *)(iVar14 + 0x180));
    uStack_84 = (int *)CONCAT22(uStack_84._2_2_ + *(short *)(iVar14 + 0x19e),
                                (short)uStack_84 + *(short *)(iVar14 + 0x19c));
    uStack_90 = CONCAT22(uStack_90._2_2_ + *(short *)(iVar14 + 0x186),
                         (short)uStack_90 + *(short *)(iVar14 + 0x184));
    uStack_44 = *(uint32_t *)(iVar14 + 0x1a0);
    uStack_38 = *(uint32_t *)(iVar14 + 0x188);
    uStack_40 = *(uint32_t *)(iVar14 + 0x1a4);
    uStack_34 = *(uint32_t *)(iVar14 + 0x18c);
    uStack_3c = *(uint32_t *)(iVar14 + 0x1a8);
    fStack_30 = *(float *)(iVar14 + 400);
  }
  if (((piStack_ac != (int *)0x0) && (iVar7 = FUN_0056b340(), iVar4 = iStack_70, 0 < iVar7)) &&
     (iStack_70 < 6)) {
    psVar1 = (short *)((int)&uStack_8c + iStack_70 * 2);
    *psVar1 = *psVar1 + (short)iVar7;
    psVar1 = (short *)((int)&uStack_98 + iVar4 * 2);
    *psVar1 = *psVar1 + (short)iVar7;
  }
  iVar4 = (**(code **)(*param_1 + 0x214))();
  if (((iVar4 != 0) &&
      (((*(byte *)(*(int *)(*(int *)(iVar4 + 4) + 4) + 0xb8 + iVar4) & 1) != 0 ||
       ((iVar7 = *(int *)(iVar4 + 0x250), iVar7 != 0 &&
        ((*(byte *)(*(int *)(*(int *)(iVar7 + 4) + 4) + 0xb8 + iVar7) & 1) != 0)))))) ||
     ((iStack_6c = iVar4, iVar7 = (**(code **)(*param_1 + 0x210))(0), iVar7 != 0 &&
      (iVar7 = (**(code **)(*param_1 + 0x210))(), *(char *)(iVar7 + 0x501) != '\0')))) {
    return 0;
  }
  if (iVar4 != 0) {
    iVar7 = (**(code **)(*param_1 + 0x1d4))();
    if ((iVar7 != 0) && (iVar7 = (**(code **)(*param_1 + 0x1d4))(), *(int *)(iVar7 + 0x254) != 0)) {
      iVar7 = (**(code **)(*param_1 + 0x1d4))();
      puVar8 = (uint32_t *)(**(code **)(**(int **)(iVar7 + 0x254) + 0x38))();
      uStack_80 = *puVar8;
      uStack_7c = puVar8[1];
      local_78 = (int *)puVar8[2];
    }
    if (0 < *(short *)(iVar4 + 0x1ac)) {
      uStack_80 = CONCAT22(uStack_80._2_2_,(short)uStack_80 + *(short *)(iVar4 + 0x1ac));
    }
    if (0 < *(short *)(iVar4 + 0x1ae)) {
      uStack_80 = CONCAT22((short)((uint)uStack_80 >> 0x10) + *(short *)(iVar4 + 0x1ae),
                           (short)uStack_80);
    }
    if (0 < *(short *)(iVar4 + 0x1b0)) {
      uStack_7c = CONCAT22(uStack_7c._2_2_,(short)uStack_7c + *(short *)(iVar4 + 0x1b0));
    }
    if (0 < *(short *)(iVar4 + 0x1b2)) {
      uStack_7c = CONCAT22((short)((uint)uStack_7c >> 0x10) + *(short *)(iVar4 + 0x1b2),
                           (short)uStack_7c);
    }
    if (0 < *(short *)(iVar4 + 0x1b4)) {
      local_78 = (int *)CONCAT22(local_78._2_2_,(short)local_78 + *(short *)(iVar4 + 0x1b4));
    }
    if (0 < *(short *)(iVar4 + 0x1b6)) {
      local_78 = (int *)CONCAT22(local_78._2_2_ + *(short *)(iVar4 + 0x1b6),(short)local_78);
    }
  }
  fVar5 = 0.0;
  puStack_a0 = (ushort *)(param_6 + 0x18);
  uVar10 = CONCAT13((char)((uint)unaff_EDI >> 0x18),(uint3)(ushort)unaff_EDI);
  do {
    if ((iStack_b0 != 0) && (fVar5 == fStack_74)) {
      psVar1 = (short *)((int)&uStack_90 + (int)fVar5 * 2);
      *psVar1 = *psVar1 + asStack_54[(int)fVar5 + 6];
      asStack_9c[(int)fVar5] = asStack_9c[(int)fVar5] + *(short *)((int)&uStack_3c + (int)fVar5 * 2)
      ;
    }
    sVar3 = asStack_9c[(int)fVar5];
    sVar16 = *(short *)((int)&uStack_90 + (int)fVar5 * 2);
    *(short *)((int)&iStack_64 + (int)fVar5 * 2) = sVar16;
    sVar15 = sVar3 - sVar16;
    asStack_1c[(int)fVar5] = sVar15;
    if (0 < sVar3) {
      if (param_7 != 0) {
        *(uint8_t *)(param_7 + (int)fVar5) = 1;
      }
      if (0 < sVar15) {
        if (param_6 == 0) {
          iVar4 = CVOGReaction_RandomUnitScalar();
          if (0xfffff < *(int *)(iVar4 + 0xc)) {
            *(uint32_t *)(iVar4 + 0xc) = 0;
          }
          uVar11 = *(ushort *)(*(int *)(iVar4 + 8) + *(int *)(iVar4 + 0xc) * 2);
          *(int *)(iVar4 + 0xc) = *(int *)(iVar4 + 0xc) + 1;
        }
        else {
          uVar11 = puStack_a0[-0xc];
        }
        *(short *)((int)&iStack_64 + (int)fVar5 * 2) =
             (short)((longlong)(ulonglong)uVar11 % (longlong)(sVar15 + 1)) + sVar16;
      }
    }
    if (((fVar5 == fStack_74) && (iStack_bc < (int)uStack_b8)) &&
       (sVar3 = *(short *)((int)&iStack_64 + (int)fVar5 * 2), 0 < sVar3)) {
      piStack_c0 = (int *)(uStack_b8 - iStack_bc);
      if ((int)sVar3 <= (int)(uStack_b8 - iStack_bc)) {
        piStack_c0 = (int *)(int)sVar3;
      }
      *(short *)((int)&iStack_64 + (int)fVar5 * 2) = sVar3 - (short)piStack_c0;
    }
    sVar3 = *(short *)((int)&iStack_64 + (int)fVar5 * 2);
    bVar18 = false;
    if (sVar3 < 0) {
      *(uint16_t *)((int)&iStack_64 + (int)fVar5 * 2) = 0;
      sVar3 = *(short *)((int)&iStack_64 + (int)fVar5 * 2);
      bVar18 = sVar3 < 0;
    }
    if (sVar3 != 0 && !bVar18) {
      sVar3 = *(short *)((int)&uStack_80 + (int)fVar5 * 2);
      fStack_a4 = (float)(int)sVar3;
      fStack_28 = (float)(int)fStack_a4;
      dVar20 = ceil((double)(fStack_28 * g_flMultiKillCountBlend));
      iStack_24 = (int)ROUND((float)dVar20);
      sVar16 = (short)(int)ROUND((float)dVar20);
      asStack_1c[(int)fVar5] = sVar16;
      if (0 < sVar3) {
        if (sVar16 < 1) {
          asStack_54[(int)fVar5] = 0;
        }
        else if (sVar16 < 1000) {
          if (param_6 == 0) {
            iVar4 = CVOGReaction_RandomUnitScalar();
            if (0xfffff < *(int *)(iVar4 + 0xc)) {
              *(uint32_t *)(iVar4 + 0xc) = 0;
            }
            uVar11 = *(ushort *)(*(int *)(iVar4 + 8) + *(int *)(iVar4 + 0xc) * 2);
            *(int *)(iVar4 + 0xc) = *(int *)(iVar4 + 0xc) + 1;
          }
          else {
            uVar11 = puStack_a0[-6];
          }
          sVar3 = (short)((longlong)(ulonglong)uVar11 % (longlong)(int)sVar16) + 1;
          iVar4 = (int)sVar3;
          fVar19 = (float)iVar4 * (float)(int)piStack_b4 * _DAT_009cdf80;
          asStack_54[(int)fVar5] = sVar3;
          if ((char)(uVar10 >> 8) == '\0') {
            asStack_54[(int)fVar5] = sVar3 - (short)(int)fVar19;
          }
          else {
            fStack_30 = (float)iVar4;
            dVar20 = ceil((double)(fStack_30 * (float)piStack_ac));
            iStack_20 = (int)ROUND((float)dVar20);
            iVar7 = iVar4 - (int)fVar19;
            if (iVar7 <= (int)ROUND((float)dVar20)) {
              fStack_2c = (float)iVar4;
              dVar20 = ceil((double)(fStack_2c * (float)piStack_ac));
              iVar7 = (int)ROUND((float)dVar20);
              iStack_58 = iVar7;
            }
            asStack_54[(int)fVar5] = (short)iVar7;
          }
          if (asStack_54[(int)fVar5] < 0) {
            asStack_54[(int)fVar5] = 0;
          }
        }
        else {
          if (fVar5 == fStack_74) {
            piStack_c0 = (int *)0x0;
            uVar10 = (uint)CONCAT12(1,(short)uVar10);
          }
          uVar10 = CONCAT13(1,(int3)uVar10);
          *(uint16_t *)((int)&iStack_64 + (int)fVar5 * 2) = 0;
        }
        dVar20 = ceil((double)((float)(int)fStack_a4 * g_flMultiKillCountBlend +
                              (float)(int)(iStack_bc - uStack_b8) * g_flMultiKillCountBlend));
        fStack_a4 = (float)dVar20;
        if (param_6 == 0) {
          iVar4 = CVOGReaction_RandomUnitScalar();
          if (0xfffff < *(int *)(iVar4 + 0xc)) {
            *(uint32_t *)(iVar4 + 0xc) = 0;
          }
          uVar11 = *(ushort *)(*(int *)(iVar4 + 8) + *(int *)(iVar4 + 0xc) * 2);
          *(int *)(iVar4 + 0xc) = *(int *)(iVar4 + 0xc) + 1;
        }
        else {
          uVar11 = *puStack_a0;
        }
        if (fStack_a4 < (float)((uint)uVar11 % 100)) {
          if (0 < asStack_54[(int)fVar5]) {
            psVar1 = (short *)((int)&iStack_64 + (int)fVar5 * 2);
            *psVar1 = *psVar1 - asStack_54[(int)fVar5];
            unaff_EBP = 0x1000000;
          }
        }
        else {
          uVar10 = CONCAT13(1,(int3)uVar10);
          *(uint16_t *)((int)&iStack_64 + (int)fVar5 * 2) = 0;
        }
      }
    }
    iVar4 = iStack_70;
    fVar19 = (float)(int)*(short *)((int)&iStack_64 + (int)fVar5 * 2);
    if (fVar19 < 0.0) {
      fVar19 = 0.0;
    }
    puStack_a0 = puStack_a0 + 1;
    fStack_a8 = fVar19 + fStack_a8;
    fVar5 = (float)((int)fVar5 + 1);
  } while ((int)fVar5 < 6);
  if ((iStack_70 != 0) && (iVar14 != 0)) {
    piVar6 = (int *)(*(int *)(*(int *)(iStack_70 + 4) + 4) + 4 + iStack_70);
    iVar7 = (**(code **)(*(int *)(*(int *)(*(int *)(iVar14 + 4) + 4) + 4 + iVar14) + 0x27c))();
    iVar9 = (**(code **)(*piVar6 + 0x27c))();
    if (iVar7 < iVar9) {
      (**(code **)(*(int *)(*(int *)(*(int *)(iVar4 + 4) + 4) + 4 + iVar4) + 0x27c))();
      (**(code **)(*(int *)(*(int *)(*(int *)(iVar14 + 4) + 4) + 4 + iVar14) + 0x27c))();
    }
  }
  cVar22 = (char)(uVar10 >> 0x10);
  if ((iStack_bc < (int)uStack_b8) && (cVar22 == '\0')) {
    if (g_flZero < (float)(int)piStack_c0) {
      fStack_a8 = (float)(int)piStack_c0 + fStack_a8;
    }
  }
  else if (((int)uStack_b8 < iStack_bc) && (cVar22 == '\0')) {
    fStack_a8 = fStack_a8 - (float)(int)(iStack_bc - uStack_b8);
  }
  dVar20 = ceil((double)fStack_a8);
  piVar6 = uStack_84;
  fStack_a4 = (float)dVar20;
  iVar4 = (int)ROUND(fStack_a4);
  piVar17 = piStack_8;
  iStack_58 = iVar4;
  if (param_3 != '\0') {
    if ((char)uStack_84[8] == '\0') {
LAB_0051636f:
      iVar7 = iStack_70;
      piVar17 = piStack_8;
      if (iStack_70 != 0) {
        if (*(char *)(*(int *)(*(int *)(iStack_70 + 4) + 4) + 0x24 + iStack_70) != '\0') {
          piStack_c0 = (int *)0x0;
          CNDDoubleList_InvokePredicateAndRemove_Inferred(&LAB_00512fa0,&piStack_c0,0);
          piVar12 = piStack_c0;
          if (piStack_c0 != (int *)0x0) goto LAB_005163f5;
        }
        iVar7 = *(int *)(iVar7 + 0x250);
        piVar17 = piStack_8;
        if ((iVar7 != 0) && (*(char *)(*(int *)(*(int *)(iVar7 + 4) + 4) + 0x24 + iVar7) != '\0')) {
          piStack_ac = (int *)0x0;
          CNDDoubleList_InvokePredicateAndRemove_Inferred(&LAB_00512fa0,&piStack_ac,0);
          piVar12 = piStack_ac;
          piVar17 = piStack_8;
          if (piStack_ac != (int *)0x0) goto LAB_005163f5;
        }
      }
    }
    else {
      piStack_b4 = (int *)0x0;
      CNDDoubleList_InvokePredicateAndRemove_Inferred(&LAB_00512fa0,&piStack_b4,0);
      piVar12 = piStack_b4;
      if (piStack_b4 == (int *)0x0) goto LAB_0051636f;
LAB_005163f5:
      piVar17 = uStack_84;
      piVar13 = piStack_8;
      if (iVar14 != 0) {
        piVar13 = (int *)(*(int *)(*(int *)(iVar14 + 4) + 4) + 4 + iVar14);
      }
      iVar4 = (**(code **)(*piVar12 + 0x54))(piVar13,uStack_84,iVar4,piVar6[0x29] + 0xe650);
      piVar6 = piVar17;
      piVar17 = piStack_8;
    }
  }
  if ((param_4 != '\0') && (piVar17 != (int *)0x0)) {
    if (*(char *)((int)piVar17 + 0x21) == '\0') {
LAB_0051647a:
      if (iVar14 != 0) {
        if (*(char *)(*(int *)(*(int *)(iVar14 + 4) + 4) + 0x25 + iVar14) != '\0') {
          uStack_84 = (int *)0x0;
          CNDDoubleList_InvokePredicateAndRemove_Inferred(&LAB_00512fe0,&uStack_84,0);
          piVar12 = uStack_84;
          if (uStack_84 != (int *)0x0) goto LAB_005164fc;
        }
        iVar14 = *(int *)(iVar14 + 0x250);
        if ((iVar14 != 0) && (*(char *)(*(int *)(*(int *)(iVar14 + 4) + 4) + 0x25 + iVar14) != '\0')
           ) {
          piStack_c0 = (int *)0x0;
          CNDDoubleList_InvokePredicateAndRemove_Inferred(&LAB_00512fe0,&piStack_c0,0);
          piVar12 = piStack_c0;
          if (piStack_c0 != (int *)0x0) goto LAB_005164fc;
        }
      }
    }
    else {
      piStack_b4 = (int *)0x0;
      CNDDoubleList_InvokePredicateAndRemove_Inferred(&LAB_00512fe0,&piStack_b4,0);
      piVar12 = piStack_b4;
      if (piStack_b4 == (int *)0x0) goto LAB_0051647a;
LAB_005164fc:
      iVar4 = (**(code **)(*piVar12 + 0x54))(piVar17,piVar6,iVar4,piVar6[0x29] + 0xe650);
    }
  }
  if (iVar4 < 1) {
    if (((char)(uVar10 >> 0x18) == '\0') && ((char)(unaff_EBP >> 0x18) == '\0')) {
      iVar4 = 0;
      if (param_7 == 0) goto LAB_00516565;
      *(uint8_t *)(param_7 + 7) = 1;
    }
    else {
      iVar4 = 0;
      if (param_7 == 0) goto LAB_00516565;
      *(uint8_t *)(param_7 + 6) = 1;
    }
  }
  if (((param_7 != 0) && (iVar4 < 1)) && (*(char *)(param_7 + 7) == '\0')) {
    iVar4 = 0;
    *(uint8_t *)(param_7 + 6) = 1;
  }
LAB_00516565:
  uVar10 = iStack_6c - iStack_68;
  if ((((piVar17 != (int *)0x0) && (iVar14 = (**(code **)(*piVar17 + 0x210))(), iVar14 == 0)) &&
      ((iVar14 = (**(code **)(*piVar17 + 0x214))(), iVar14 == 0 ||
       (iVar14 = (**(code **)(*piVar17 + 0x214))(), *(char *)(iVar14 + 0x206) == '\0')))) &&
     (uVar10 != 0)) {
    switch((uVar10 ^ (int)uVar10 >> 0x1f) - ((int)uVar10 >> 0x1f)) {
    default:
      fVar5 = DAT_00a10e78;
      break;
    case 2:
      fVar5 = g_flMultiKillCountBlend;
      break;
    case 3:
      fVar5 = DAT_00a0f704;
      break;
    case 4:
      fVar5 = DAT_00a0f298;
      break;
    case 5:
      fVar5 = DAT_00a0f698;
      break;
    case 6:
      fVar5 = DAT_009ce14c;
    }
    if (6 < (int)uVar10) {
      fVar5 = DAT_009ce14c;
    }
    fVar5 = (float)(int)((uint)(-1 < (int)uVar10) * 2 + -1) * (float)iVar4 * fVar5;
    if (0.0 <= fVar5) {
      fVar5 = fVar5 + g_flMissionXpRoundBias;
    }
    else {
      fVar5 = fVar5 - g_flMissionXpRoundBias;
    }
    iVar4 = iVar4 + (int)fVar5;
  }
  if (iVar4 < 1) {
    iVar4 = 0;
  }
  if (((piVar17 != (int *)0x0) && (iVar14 = (**(code **)(*piVar17 + 0x214))(), iVar14 != 0)) &&
     (iVar14 = (**(code **)(*piVar17 + 0x210))(), iVar14 == 0)) {
    if (iStack_b0 == 0) {
      fVar5 = *(float *)(piVar6[0x29] + 0xe838);
    }
    else {
      fVar5 = *(float *)(piVar6[0x29] + 0xe844);
    }
    iVar4 = (int)((float)iVar4 * fVar5);
  }
  iVar14 = iStack_70;
  if ((((*(char *)(piVar6[0x29] + 0x7e) != '\0') && (iStack_70 != 0)) &&
      (iVar7 = (**(code **)(*(int *)(*(int *)(*(int *)(iStack_70 + 4) + 4) + 4 + iStack_70) + 0x1dc)
               )(), iVar7 != 0)) && (0 < iVar4)) {
    (**(code **)(*(int *)(*(int *)(*(int *)(iVar14 + 4) + 4) + 4 + iVar14) + 0x1dc))();
    FUN_00535ed0();
  }
  return iVar4;
}

