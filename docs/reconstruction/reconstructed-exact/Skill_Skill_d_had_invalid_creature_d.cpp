// READABILITY (auto CF):
//  - Body size: ~451 non-empty decompiler lines.
//  - Control keywords: if×41, return×4, do×2, while×2.
//  - Notable callees: CONCAT31×3, CVOGReaction_RandomUnitScalar×3, NAN×3, ABS×2, CONCAT21×2, FUN_004024d0×2, FUN_004ca910×2, FUN_004e8dc0×2.
//  - Strings: "Skill %d had invalid creature %d."; "Skill %d had invalid template %d.".
//  - Return sites: 4.

// =============================================================================
// Skill_Skill_d_had_invalid_creature_d
// -----------------------------------------------------------------------------
// Stable ID: aa_00615020
// Address:   0x00615020  (autoassault.exe, image base 0x400000)
// System:    unknown
// Generated: 2026-07-23 from raw capture (scaffold; refine for important units)
// Exactness: Behavior-preserving rewrite of decompiler control flow. Not modernization.
// Bit-for-bit vs retail EXE: DEFERRED (loaded image may differ slightly).
// =============================================================================

/*
 * Behavioral notes:
 * String-driven rename evidence: "Skill %d had invalid creature %d."
 *
 * - Derived from Ghidra decompile; names prefer Ghidra symbols / plate comments.
 * - Remaining FUN_* / DAT_* identifiers are unresolved pending type recovery.
 * - Runtime / differential verification: OPEN unless matrix says otherwise.
 *
 * Readability pass:
 * - undefinedN widths preserved as fixed-width integers where decompiler width is known.
 * - Control flow and call order preserved from authoritative raw.
 */

/* WARNING: Globals starting with '_' overlap smaller symbols at the same address */



int Skill_Skill_d_had_invalid_creature_d(int *param_1,int param_2,int param_3,uint32_t /* width from decompiler */ param_4,uint32_t /* width from decompiler */ param_5,

                uint32_t /* width from decompiler */ param_6)



{

  float fVar1;

  uint3 uVar2;

  ushort *puVar3;

  char cVar4;

  float *pfVar5;

  int *piVar6;

  uint16_t *puVar7;

  int iVar8;

  uint16_t extraout_var;

  int iVar9;

  uint32_t /* width from decompiler */ uVar10;

  uint32_t /* width from decompiler */ *puVar11;

  CVOGHBBase *pAction;

  uint *puVar12;

  void *pvVar13;

  uint uVar14;

  float10 fVar15;

  int *piVar16;

  int iStack_134;

  float local_130;

  float local_12c;

  float local_128;

  float local_124;

  int iStack_120;

  int local_11c;

  void *local_114;

  float local_110;

  float local_10c;

  float local_108;

  float local_104;

  ushort *local_fc;

  void *pvStack_f8;

  int local_f4;

  int local_f0;

  int local_ec;

  int local_e8;

  int local_e4;

  int local_d8;

  int iStack_d4;

  int local_d0;

  int local_cc;

  int local_c8;

  int local_c4;

  void *pvStack_bc;

  uint uStack_b8;

  uint local_b4;

  float fStack_b0;

  float fStack_ac;

  float fStack_a8;

  float fStack_a4;

  float fStack_9c;

  float fStack_98;

  int *local_94;

  float fStack_90;

  float fStack_88;

  uint16_t *local_84;

  uint32_t /* width from decompiler */ uStack_80;

  uint32_t /* width from decompiler */ uStack_7c;

  void *pvStack_78;

  uint32_t /* width from decompiler */ uStack_74;

  TFID_16 TStack_70;

  float fStack_60;

  float fStack_5c;

  float fStack_58;

  float fStack_54;

  float fStack_50;

  float fStack_4c;

  float fStack_48;

  float fStack_44;

  uint8_t auStack_40 [16];

  uint8_t auStack_30 [20];

  void *local_1c;

  uint8_t *puStack_18;

  uint32_t /* width from decompiler */ uStack_14;

  

  uStack_14 = 0xffffffff;

  puStack_18 = &LAB_009a8660;

  local_1c = ExceptionList;

  ExceptionList = &local_1c;

  local_11c = __RTDynamicCast(param_1,0,&CVOGClonedObjectBase::RTTI_Type_Descriptor,

                              &CVOGCreature::RTTI_Type_Descriptor,0);

  if ((*(char *)(param_3 + 0x7e) != '\0') && (local_11c != 0)) {

    iVar8 = *(int *)(local_11c + 0x250);

    if (iVar8 == 0) {

      iVar8 = *(int *)(local_11c + 8);

      if (iVar8 == 0) {

        pfVar5 = (float *)(*(int *)(*(int *)(local_11c + 4) + 4) + 0x84 + local_11c);

      }

      else {

        pfVar5 = (float *)(*(int *)(iVar8 + 0x3c) + 0xb0);

      }

      local_130 = *pfVar5;

      local_12c = pfVar5[1];

      local_128 = pfVar5[2];

      local_104 = pfVar5[3];

      if (iVar8 == 0) {

        piVar6 = (int *)(*(int *)(*(int *)(local_11c + 4) + 4) + 0x94 + local_11c);

      }

      else {

        piVar6 = (int *)(*(int *)(iVar8 + 0x3c) + 0x30);

      }

      local_f0 = *piVar6;

      local_114 = *(void **)(local_11c + 0x34);

      local_ec = piVar6[1];

      local_e8 = piVar6[2];

      local_e4 = piVar6[3];

    }

    else {

      if (*(int *)(iVar8 + 8) == 0) {

        pfVar5 = (float *)(*(int *)(*(int *)(iVar8 + 4) + 4) + 0x84 + iVar8);

      }

      else {

        pfVar5 = (float *)(*(int *)(*(int *)(iVar8 + 8) + 0x3c) + 0xb0);

      }

      local_130 = *pfVar5;

      local_12c = pfVar5[1];

      local_128 = pfVar5[2];

      local_104 = pfVar5[3];

      if (*(int *)(iVar8 + 8) == 0) {

        piVar6 = (int *)(*(int *)(*(int *)(iVar8 + 4) + 4) + 0x94 + iVar8);

      }

      else {

        piVar6 = (int *)(*(int *)(*(int *)(iVar8 + 8) + 0x3c) + 0x30);

      }

      local_f0 = *piVar6;

      local_ec = piVar6[1];

      local_e8 = piVar6[2];

      local_e4 = piVar6[3];

      local_114 = *(void **)(iVar8 + 0x34);

    }

    local_124 = local_104;

    local_110 = local_130;

    local_10c = local_12c;

    local_108 = local_128;

    local_d0 = local_f0;

    local_cc = local_ec;

    local_c8 = local_e8;

    local_c4 = local_e4;

    puVar7 = (uint16_t *)FUN_0058ab60(param_6);

    uVar14 = 1;

    if (*(byte *)(param_2 + 0xde) != 0) {

      uVar14 = (uint)*(byte *)(param_2 + 0xde);

    }

    local_f4 = *(int *)(param_2 + 0xe4);

    local_d8 = 0;

    local_b4 = uVar14;

    local_84 = puVar7;

    cVar4 = FUN_00589b80(local_f4,*puVar7);

    if ((cVar4 == '\0') && (local_f4 = 0, uVar14 != 0)) {

      local_fc = puVar7 + 1;

      do {

        local_130 = local_110;

        local_12c = local_10c;

        local_128 = local_108;

        local_124 = local_104;

        local_f0 = local_d0;

        local_ec = local_cc;

        local_e8 = local_c8;

        local_e4 = local_c4;

        iVar8 = (**(code **)(*local_94 + 0x1c))(param_1,param_2);

        if (iVar8 == 0) {

          local_d8 = local_d8 + 1;

          if (*(float *)(param_2 + 0x160) == 0.0) {

            CVOGReaction_RandomUnitScalar();

            puVar3 = local_fc;

            fStack_98 = ((float)*local_fc * _DAT_009cc4a8 - g_flOne) * DAT_00a110d8;

            CVOGReaction_RandomUnitScalar();

            fStack_b0 = ((float)*puVar3 * _DAT_009cc4a8 - g_flOne) * DAT_00a110d8;

            local_fc = puVar3 + 2;

            fStack_ac = 0.0;

            fStack_a4 = 0.0;

            if (0.0 <= fStack_b0) {

              fStack_b0 = fStack_b0 + (float)local_114;

            }

            else {

              fStack_b0 = fStack_b0 - (float)local_114;

            }

            if (0.0 <= fStack_98) {

              fStack_a8 = fStack_98 + (float)local_114;

            }

            else {

              fStack_a8 = fStack_98 - (float)local_114;

            }

            local_130 = fStack_b0 + local_130;

            local_128 = fStack_a8 + local_128;

          }

          else {

            pvStack_bc = local_114;

            if (*(float *)(param_2 + 0x160) < 0.0) {

              pvStack_bc = (void *)((float)local_114 * DAT_00aaa668);

            }

            pvStack_78 = pvStack_bc;

            if (ABS((float)pvStack_bc) < ABS(*(float *)(param_2 + 0x160))) {

              pvStack_78 = *(void **)(param_2 + 0x160);

            }

            uStack_80 = 0;

            uStack_7c = 0;

            uStack_74 = 0;

            FUN_004e8bf0(&local_110,&local_d0,&uStack_80,&fStack_b0);

            local_130 = fStack_b0;

            local_128 = fStack_a8;

            local_12c = fStack_ac;

            local_124 = fStack_a4;

          }

          puVar3 = local_fc;

          fVar15 = (float10)CVOGMap_CastTerrainHeight

                                      (local_130,local_128,local_12c + DAT_00a0f524,0);

          local_12c = (float)fVar15;

          iVar8 = (int)*(float *)(param_2 + 0x168);

          if (iVar8 == 1) {

            CVOGReaction_RandomUnitScalar();

            FUN_00567ce0(&DAT_00af4bc0,(float)*puVar3 * _DAT_009e1cb4);

            local_fc = puVar3 + 1;

          }

          else if (iVar8 == 2) {

            fStack_4c = local_12c - local_10c;

            fStack_48 = local_128 - local_108;

            fStack_50 = local_130 - local_110;

            fStack_88 = fStack_48 * fStack_48 + fStack_4c * fStack_4c + fStack_50 * fStack_50;

            if (fStack_88 == 0.0) {

              fStack_44 = 0.0;

            }

            else {

              fStack_44 = g_flOne / SQRT(fStack_88);

            }

            fStack_50 = fStack_44 * fStack_50;

            fStack_4c = fStack_4c * fStack_44;

            fStack_48 = fStack_48 * fStack_44;

            fStack_44 = (local_124 - local_104) * fStack_44;

            FUN_004e8dc0(&fStack_50,&local_f0);

          }

          else if (iVar8 == 3) {

            fStack_5c = local_10c - local_12c;

            fStack_58 = local_108 - local_128;

            fStack_60 = local_110 - local_130;

            fStack_90 = fStack_58 * fStack_58 + fStack_5c * fStack_5c + fStack_60 * fStack_60;

            if (fStack_90 == 0.0) {

              fStack_54 = 0.0;

            }

            else {

              fStack_54 = g_flOne / SQRT(fStack_90);

            }

            fStack_60 = fStack_54 * fStack_60;

            fStack_5c = fStack_5c * fStack_54;

            fStack_58 = fStack_58 * fStack_54;

            fStack_54 = (local_104 - local_124) * fStack_54;

            FUN_004e8dc0(&fStack_60,&local_f0);

          }

          FUN_004e8ad0(&local_f0,auStack_40);

          FUN_005a5970(auStack_30,local_130,local_128);

          FUN_004e9060(auStack_30,auStack_40,&local_f0);

          if (*(char *)(param_2 + 0x22) == '\0') {

            piVar6 = (int *)FUN_0058be30();

            if (piVar6 == (int *)0x0) {

              FUN_007a4480(1,"Skill %d had invalid creature %d.",*(uint32_t /* width from decompiler */ *)(param_2 + 0x5fc),

                           *(uint32_t /* width from decompiler */ *)(param_2 + 0x14c));

              ExceptionList = local_1c;

              return 0;

            }

            iVar8 = (**(code **)(*piVar6 + 0x1d8))();

            if ((*(uint *)(iVar8 + 0x200) >> 4 & 1) == 0) {

              local_12c = local_12c + *(float *)(iVar8 + 0x120) +

                          *(float *)(*(int *)(*(int *)(*(int *)(*(int *)(iVar8 + 4) + 4) + 0xac +

                                                      iVar8) + 0x3c) + 0x4d4) + g_flOverheatCoolFrac

              ;

            }

            FUN_0058a1b0(piVar6,param_3,&local_130,&local_f0,1);

            fVar1 = *(float *)(param_2 + 0x16c);

            uVar2 = CONCAT21(extraout_var,

                             (fVar1 == g_flZero) << 6 | (NAN(fVar1) || NAN(g_flZero)) << 2 | 2U |

                             fVar1 < g_flZero);

            if (fVar1 == g_flZero) {

              iVar9 = CONCAT31(uVar2,1);

            }

            else {

              iVar9 = (uint)uVar2 << 8;

            }

            FUN_004ca910(*(int *)(*(int *)(local_11c + 4) + 4) + 0x164 + local_11c,iVar9);

            iVar9 = (**(code **)(*(int *)(*(int *)(*(int *)(local_11c + 4) + 4) + 4 + local_11c) +

                                0x210))(0);

            *(bool *)(iVar8 + 0x206) = iVar9 != 0;

            FUN_004c3c80(1);

            if ((*(float *)(param_2 + 0x16c) == DAT_00aaaaa0) &&

               (piVar16 = *(int **)(*(int *)(*(int *)(*(int *)(iVar8 + 4) + 4) + 0xac + iVar8) +

                                   0x3c), piVar16 != (int *)0x0)) {

              uVar10 = (**(code **)(*piVar16 + 0x14))();

              FUN_00512460(uVar10);

            }

            if (*(float *)(param_2 + 0x30) != 0.0) {

              *(float *)(iVar8 + 0x310) = *(float *)(param_2 + 0x30);

            }

            if (*(float *)(param_2 + 0x28) != 0.0) {

              *(float *)(iVar8 + 0x270) = *(float *)(param_2 + 0x28);

            }

            (**(code **)(*(int *)(*(int *)(*(int *)(iVar8 + 0x44) + 4) + 0x44 + iVar8) + 0x28))();

          }

          else {

            piVar6 = (int *)FUN_0058bf50(*(uint32_t /* width from decompiler */ *)(param_2 + 0x14c),param_2,param_1);

            if (piVar6 == (int *)0x0) {

              FUN_007a4480(1,"Skill %d had invalid template %d.",*(uint32_t /* width from decompiler */ *)(param_2 + 0x5fc),

                           *(uint32_t /* width from decompiler */ *)(param_2 + 0x14c));

              ExceptionList = local_1c;

              return 0;

            }

            puVar11 = (uint32_t /* width from decompiler */ *)(**(code **)(*piVar6 + 0x1d4))();

            iVar8 = *(int *)(puVar11[1] + 4);

            *(float *)(iVar8 + 0x84 + (int)puVar11) = local_130;

            *(float *)(iVar8 + 0x88 + (int)puVar11) = local_12c;

            *(float *)(iVar8 + 0x8c + (int)puVar11) = local_128;

            *(float *)((int)puVar11 + iVar8 + 0x90) = local_124;

            iVar8 = *(int *)(puVar11[1] + 4);

            *(int *)((int)puVar11 + iVar8 + 0x94) = local_f0;

            *(int *)((int)puVar11 + iVar8 + 0x98) = local_ec;

            *(int *)((int)puVar11 + iVar8 + 0x9c) = local_e8;

            *(int *)((int)puVar11 + iVar8 + 0xa0) = local_e4;

            piVar16 = &local_f0;

            (**(code **)*puVar11)(param_3,&local_130,piVar16,0);

            fStack_b0 = *(float *)(param_2 + 0x30);

            uVar14 = (**(code **)(**(int **)(*(int *)(puVar11[1] + 4) + 0xb0 + (int)puVar11) + 0x1d8

                                 ))();

            if (fStack_b0 != 0.0) {

              *(float *)(uVar14 + 0x310) = fStack_b0;

            }

            uVar14 = uVar14 & 0xffff0000;

            if (*(float *)(param_2 + 0x28) != 0.0) {

              fStack_9c = *(float *)(param_2 + 0x28);

              iVar8 = (**(code **)(**(int **)(*(int *)(puVar11[1] + 4) + 0xb0 + (int)puVar11) +

                                  0x1d8))();

              *(float *)(iVar8 + 0x274) = fStack_9c;

              fStack_ac = *(float *)(param_2 + 0x28);

              uVar14 = (**(code **)(**(int **)(*(int *)(puVar11[1] + 4) + 0xb0 + (int)puVar11) +

                                   0x1d8))();

              *(float *)(uVar14 + 0x270) = fStack_ac;

            }

            fVar1 = *(float *)(param_2 + 0x16c);

            uVar2 = CONCAT21((short)(uVar14 >> 0x10),

                             (fVar1 == 0.0) << 6 | NAN(fVar1) << 2 | 2U | fVar1 < 0.0);

            if (fVar1 == 0.0) {

              iVar8 = CONCAT31(uVar2,1);

            }

            else {

              iVar8 = (uint)uVar2 << 8;

            }

            iVar9 = *(int *)(*(int *)((int)local_12c + 4) + 4) + 0x164 + (int)local_12c;

            (**(code **)(**(int **)(*(int *)(puVar11[1] + 4) + 0xb0 + (int)puVar11) + 0x1d8))

                      (iVar9,iVar8);

            FUN_004ca910(iVar9,iVar8);

            uVar10 = *(uint32_t /* width from decompiler */ *)(*(int *)(puVar11[1] + 4) + 0xb0 + (int)puVar11);

            iVar8 = (**(code **)(*(int *)(*(int *)(*(int *)((int)local_12c + 4) + 4) + 4 +

                                         (int)local_12c) + 0x210))(0);

            local_12c = (float)CONCAT31(local_12c._1_3_,iVar8 != 0);

            iVar8 = (**(code **)(*piVar16 + 0x1d8))();

            *(uint8_t *)(iVar8 + 0x206) = (uint8_t)local_11c;

            if ((*(float *)(param_2 + 0x16c) == DAT_00aaaaa0) &&

               (iVar8 = (**(code **)(**(int **)(*(int *)(puVar11[1] + 4) + 0xb0 + (int)puVar11) +

                                    0x1d8))(uVar10),

               *(int *)(*(int *)(*(int *)(*(int *)(iVar8 + 4) + 4) + 0xac + iVar8) + 0x3c) != 0)) {

              iVar8 = (**(code **)(**(int **)(*(int *)(puVar11[1] + 4) + 0xb0 + (int)puVar11) +

                                  0x1d8))();

              (**(code **)(**(int **)(*(int *)(puVar11[1] + 4) + 0xb0 + (int)puVar11) + 0x1d8))();

              uVar10 = (**(code **)(**(int **)(*(int *)(*(int *)(*(int *)(iVar8 + 4) + 4) + 0xac +

                                                       iVar8) + 0x3c) + 0x14))();

              FUN_00512460(uVar10);

            }

          }

          pvStack_bc = operator_new(0x6d0);

          puStack_18 = (uint8_t *)0x0;

          if (pvStack_bc == (void *)0x0) {

            pAction = (CVOGHBBase *)0x0;

          }

          else {

            pAction = (CVOGHBBase *)FUN_00614dc0(param_1,param_2,param_3,piVar6,param_5,param_6);

          }

          puStack_18 = (uint8_t *)0xffffffff;

          if (pAction->pOwnerObject == (void *)0x0) {

            (**(code **)pAction->pVTable)(1);

          }

          else {

            CVOGHBList_Enqueue(*(void **)(param_3 + 0xe4ec),pAction);

            CVOGHBBase_Start(pAction);

          }

          iVar8 = iStack_120;

          if ((int *)piVar6[0x2b] != (int *)0x0) {

            (**(code **)(*(int *)piVar6[0x2b] + 0x2a4))

                      (*(uint32_t /* width from decompiler */ *)

                        (*(int *)(*(int *)(*(int *)(iStack_120 + 4) + 4) + 0xa8 + iStack_120) +

                        0xe4e8));

          }

          (**(code **)(*piVar6 + 0x2a4))

                    (*(uint32_t /* width from decompiler */ *)

                      (*(int *)(*(int *)(*(int *)(iVar8 + 4) + 4) + 0xa8 + iVar8) + 0xe4e8));

          if (*(char *)(piVar6[0x29] + 0x7e) != '\0') {

            if (piVar6[0x2b] != 0) {

              FUN_004024d0(piVar6[0x2b]);

            }

            FUN_004024d0(piVar6);

          }

          if ((*(float *)(param_2 + 0x16c) == DAT_00aaa7ac) &&

             (iVar8 = (**(code **)(*param_1 + 0x210))(0), iVar8 != 0)) {

            uVar14 = 0;

            uVar10 = 1;

            pvStack_f8 = (void *)0x0;

            (**(code **)(*param_1 + 0x210))(0,1);

            uStack_b8 = FUN_004c3f10(uVar10);

            iStack_134 = 0;

            if (uStack_b8 != 0) {

              iStack_d4 = 0;

              do {

                iVar9 = (**(code **)(*param_1 + 0x210))(0);

                iVar8 = *(int *)(iVar9 + 0x1bc);

                if ((iVar8 == 0) || ((uint)(*(int *)(iVar9 + 0x1c0) - iVar8 >> 4) <= uVar14)) {

                  puVar12 = &DAT_009e1c58;

                }

                else {

                  puVar12 = (uint *)(iVar8 + iStack_d4);

                }

                TStack_70.dwCoidLo = *puVar12;

                TStack_70.dwCoidHi = puVar12[1];

                TStack_70._8_4_ = puVar12[2];

                TStack_70._12_4_ = puVar12[3];

                pvVar13 = Object_ResolveFromTFID(&TStack_70);

                if (((*(int *)(*(int *)((int)pvVar13 + 0xa8) + 0x34) == *(int *)(param_2 + 0x14c))

                    && ((*(byte *)((int)pvVar13 + 0x17c) & 1) == 0)) &&

                   (iStack_134 = iStack_134 + 1, pvStack_f8 == (void *)0x0)) {

                  pvStack_f8 = pvVar13;

                }

                iStack_d4 = iStack_d4 + 0x10;

                uVar14 = uVar14 + 1;

              } while (uVar14 < uStack_b8);

            }

            if (((int)(uint)*(byte *)(param_2 + 0xda) < iStack_134) && (pvStack_f8 != (void *)0x0))

            {

              *(uint32_t /* width from decompiler */ *)((int)pvStack_f8 + 0xcc) = 2;

              FUN_004d0e90(pvStack_f8);

            }

          }

        }

        local_f4 = local_f4 + 1;

        puVar7 = local_84;

      } while (local_f4 < (int)local_b4);

    }

    operator_delete__(puVar7);

    ExceptionList = local_1c;

    return local_d8;

  }

  ExceptionList = local_1c;

  return 1;

}
