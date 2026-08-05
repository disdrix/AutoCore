# Raw capture: FUN_005cd3b0

| Field | Value |
|---|---|
| **Stable ID** | `aa_005cd3b0` |
| **Module** | `autoassault.exe` |
| **Image base** | `0x400000` |
| **VA** | `0x005cd3b0` |
| **Canonical name** | `FUN_005cd3b0` |
| **System** | unknown |
| **Capture timestamp** | `2026-07-23` |
| **Tool** | Ghidra MCP `batch_decompile` |
| **Integrity** | Do not overwrite this raw body; append versioned sections only |

---

## Raw pseudocode (authoritative decompile)

```c
/* WARNING: Globals starting with '_' overlap smaller symbols at the same address */



void __thiscall FUN_005cd3b0(int *param_1,float param_2)



{

  int *piVar1;

  undefined4 uVar2;

  bool bVar3;

  char cVar4;

  float *pfVar5;

  int iVar6;

  undefined4 *puVar7;

  void *pA;

  uint *puVar8;

  int iVar9;

  bool bVar10;

  float10 fVar11;

  float fVar12;

  float fVar13;

  float fVar14;

  byte *pB;

  float fStack_100;

  float fStack_f8;

  float fStack_f4;

  float fStack_e0;

  float fStack_dc;

  float fStack_d8;

  float fStack_d4;

  float fStack_cc;

  float fStack_c8;

  float fStack_c4;

  float fStack_c0;

  float fStack_bc;

  float fStack_b8;

  float fStack_b4;

  float fStack_b0;

  float fStack_ac;

  float fStack_a8;

  float fStack_a4;

  float local_a0;

  float local_9c;

  float local_98;

  float local_94;

  float fStack_88;

  float local_84;

  undefined4 uStack_80;

  float fStack_7c;

  float fStack_78;

  float fStack_74;

  undefined4 uStack_70;

  float fStack_6c;

  undefined4 uStack_68;

  float fStack_64;

  undefined4 uStack_60;

  float fStack_5c;

  undefined4 uStack_58;

  float fStack_54;

  float fStack_50;

  float fStack_4c;

  float fStack_48;

  float fStack_44;

  uint uStack_3c;

  undefined4 local_38;

  float fStack_34;

  undefined4 uStack_30;

  undefined4 uStack_2c;

  undefined4 uStack_28;

  undefined4 uStack_24;

  void *pvStack_1c;

  undefined1 *puStack_18;

  undefined4 local_14;

  

  local_14 = 0xffffffff;

  puStack_18 = &LAB_009a6f98;

  pvStack_1c = ExceptionList;

  local_38 = DAT_00d1f040;

  ExceptionList = &pvStack_1c;

  FUN_0076cf00();

  local_14 = 0;

  if (param_1[6] == 0) goto LAB_005ce963;

  if ((float)param_1[0xd] != 0.0) {

    fVar12 = (float)(int)g_dwClientTickMs;

    if ((int)g_dwClientTickMs < 0) {

      fVar12 = fVar12 + _DAT_00aaa5dc;

    }

    if (fVar12 * g_flMsToSeconds_Inferred - (float)param_1[0xe] < (float)param_1[0xd])

    goto LAB_005ce963;

  }

  piVar1 = (int *)param_1[0x19];

  if ((piVar1[0x94] != 0) &&

     (*(int *)(*(int *)(*(int *)(piVar1[1] + 4) + 0xac + (int)piVar1) + 0x38) != 0x14))

  goto LAB_005ce963;

  local_84 = *(float *)(*(int *)(*(int *)(*(int *)(piVar1[1] + 4) + 0xac + (int)piVar1) + 0x3c) +

                       0x4d4);

  fVar12 = g_flOne;

  if ((*(int *)(*(int *)(*(int *)(piVar1[1] + 4) + 0xac + (int)piVar1) + 0x38) == 0x14) ||

     (fVar12 = 0.0, ((uint)piVar1[0x80] >> 4 & 1) != 0)) {

    local_84 = fVar12;

  }

  if (piVar1[2] == 0) {

    pfVar5 = (float *)(*(int *)(piVar1[1] + 4) + 0x84 + (int)piVar1);

  }

  else {

    pfVar5 = (float *)(*(int *)(piVar1[2] + 0x3c) + 0xb0);

  }

  local_a0 = *pfVar5;

  local_9c = pfVar5[1];

  local_98 = pfVar5[2];

  local_94 = pfVar5[3];

  fVar11 = (float10)(**(code **)(*piVar1 + 0x58))(&local_a0,local_84);

  fStack_c8 = (float)fVar11;

  pfVar5 = (float *)FUN_004c3ac0();

  fStack_100 = *pfVar5;

  fVar12 = pfVar5[1];

  fStack_f8 = pfVar5[2];

  fStack_f4 = pfVar5[3];

  if (g_flMultiKillCountBlend < (fStack_c8 - *(float *)(param_1[0x19] + 0x120)) - local_9c) {

    local_9c = fStack_c8;

    FUN_0040d2a0();

    iVar6 = *(int *)(*(int *)(param_1[0x19] + 8) + 0x3c);

    fStack_c0 = *(float *)(iVar6 + 0x40);

    fStack_b8 = *(float *)(iVar6 + 0x48);

    fStack_b4 = *(float *)(iVar6 + 0x4c);

    fStack_bc = 0.0;

    CVOGPhysics_ApplyImpulseVector();

    if (*(char *)(param_1[0x19] + 0x308) != '\0') {

      *(undefined1 *)(param_1[0x19] + 0x308) = 0;

      (**(code **)(*(int *)param_1[0x19] + 100))(0xf,0x3e4ccccd,1,0xbf800000);

    }

  }

  fStack_b0 = ABS(fStack_100 - (float)g_abInferredDefaultAimPos._0_4_);

  fStack_ac = ABS(fVar12 - (float)g_abInferredDefaultAimPos._4_4_);

  fStack_a8 = ABS(fStack_f8 - (float)g_abInferredDefaultAimPos._8_4_);

  fStack_a4 = ABS(fStack_f4 - (float)g_abInferredDefaultAimPos._12_4_);

  if ((fStack_a8 <= g_flMultiKillCountBlend && fStack_ac <= g_flMultiKillCountBlend) &&

      fStack_b0 <= g_flMultiKillCountBlend) {

    fStack_100 = local_a0;

    fStack_f8 = local_98;

    fStack_f4 = local_94;

  }

  fVar11 = (float10)FUN_004c55e0();

  fStack_88 = (float)fVar11;

  if (((*(char *)(param_1[0x19] + 0x279) != '\0') && (g_flOne < fStack_88)) &&

     (fStack_88 = fStack_88 * DAT_00a0f298, fStack_88 < g_flOne)) {

    fStack_88 = g_flOne;

  }

  iVar6 = _isnan((double)fStack_100);

  if (((iVar6 == 0) && (iVar6 = _isnan((double)fStack_c8), iVar6 == 0)) &&

     (iVar6 = _isnan((double)fStack_f8), iVar6 == 0)) {

    fStack_ac = fStack_c8 - local_9c;

    fStack_b0 = fStack_100 - local_a0;

    fStack_a8 = fStack_f8 - local_98;

    fStack_a4 = fStack_f4 - local_94;

    iVar6 = _isnan((double)fStack_b0);

    if (((iVar6 == 0) && (iVar6 = _isnan((double)fStack_ac), iVar6 == 0)) &&

       (iVar6 = _isnan((double)fStack_a8), iVar6 == 0)) {

      fStack_34 = fStack_a8 * fStack_a8;

      fStack_c4 = fStack_b0 * fStack_b0;

      fVar12 = fStack_ac * fStack_ac + fStack_34 + fStack_c4;

      fStack_cc = SQRT(fVar12);

      iVar6 = _isnan((double)fStack_cc);

      if (iVar6 == 0) {

        iVar6 = param_1[0x19];

        puVar7 = (undefined4 *)FUN_0040cf70();

        uStack_70 = *puVar7;

        fStack_6c = (float)puVar7[1];

        uStack_68 = puVar7[2];

        fStack_64 = (float)puVar7[3];

        if (local_9c - fStack_c8 <= DAT_00a0f718) {

          if (*(char *)(iVar6 + 0x308) == '\0') {

            if (*(int *)(iVar6 + 0xb8) < 0) {

              iVar9 = 0;

            }

            else {

              iVar9 = *(int *)(iVar6 + 0x6c + *(int *)(iVar6 + 0xb8) * 4);

            }

            if (iVar9 != *(int *)(iVar6 + 0xa0)) goto LAB_005cda63;

          }

          *(undefined1 *)(iVar6 + 0x308) = 0;

          (**(code **)(*(int *)param_1[0x19] + 100))(0xf,0x3e4ccccd,1);

        }

        else {

          iVar6 = (**(code **)(*(int *)(*(int *)(*(int *)(iVar6 + 4) + 4) + 4 + iVar6) + 0x1dc))();

          if (iVar6 == 0) {

            iVar6 = 0;

          }

          else {

            iVar6 = *(int *)(*(int *)(iVar6 + 4) + 4) + 4 + iVar6;

          }

          piVar1 = (int *)param_1[0x19];

          if ((((*(int *)(*(int *)(*(int *)(piVar1[1] + 4) + 0xa8 + (int)piVar1) + 0xe8a0) != iVar6)

               && (g_flMultiKillCountBlend < local_9c - fStack_c8)) && (_DAT_009da8a4 < fStack_6c))

             && ((char)piVar1[0xc2] == '\0')) {

            if (piVar1[0x2e] < 0) {

              iVar6 = 0;

            }

            else {

              iVar6 = piVar1[piVar1[0x2e] + 0x1b];

            }

            if (iVar6 != piVar1[0x2a]) {

              (**(code **)(*piVar1 + 100))(0xd,0x3d4ccccd,1);

            }

          }

          iVar6 = FUN_004cdd90();

          fStack_6c = *(float *)(iVar6 + 4) * param_2 + fStack_6c;

          if (fStack_c8 <= fStack_6c * param_2 + local_9c) {

            if (fStack_6c < DAT_009da8a0) {

              *(undefined1 *)(param_1[0x19] + 0x308) = 1;

            }

          }

          else if (*(char *)(param_1[0x19] + 0x308) != '\0') {

            *(undefined1 *)(param_1[0x19] + 0x308) = 0;

            (**(code **)(*(int *)param_1[0x19] + 100))(0xf,0x3e4ccccd,1);

            CVOGPhysics_ApplyImpulseVector();

            goto LAB_005cda63;

          }

          CVOGPhysics_ApplyImpulseVector();

        }

LAB_005cda63:

        if ((*(char *)(param_1[0x19] + 0x304) != '\0') && (fStack_cc < g_flOne)) {

          uStack_70 = 0;

          uStack_68 = 0;

          iVar6 = *(int *)(*(int *)(param_1[0x19] + 8) + 0x3c);

          fStack_e0 = ABS(*(float *)(iVar6 + 0x40));

          fStack_dc = ABS(*(float *)(iVar6 + 0x44) - fStack_6c);

          fStack_d8 = ABS(*(float *)(iVar6 + 0x48));

          fStack_d4 = ABS(*(float *)(iVar6 + 0x4c) - fStack_64);

          uStack_3c = (uint)(g_flMsToSeconds_Inferred < fStack_d8) * 2 |

                      (uint)(g_flMsToSeconds_Inferred < fStack_dc) * 4 |

                      (uint)(g_flMsToSeconds_Inferred < fStack_e0) * -8 & 0xe;

          if (uStack_3c != 0) {

            CVOGPhysics_ApplyImpulseVector();

          }

          *(undefined1 *)(param_1[0x19] + 0x304) = 0;

        }

        fStack_c4 = fStack_34 + fStack_c4;

        fStack_50 = fStack_b0;

        fStack_48 = fStack_a8;

        fStack_44 = fStack_a4;

        fStack_4c = 0.0;

        if (_DAT_009da864 < SQRT(fStack_c4)) {

          if (fStack_c4 == 0.0) {

            fStack_44 = 0.0;

          }

          else {

            fStack_44 = g_flOne / SQRT(fStack_c4);

            fStack_c4 = fStack_44;

          }

          fStack_50 = fStack_44 * fStack_b0;

          fStack_4c = fStack_44 * 0.0;

          fStack_48 = fStack_44 * fStack_a8;

          fStack_44 = fStack_44 * fStack_a4;

        }

        if (_DAT_009da864 < fStack_cc) {

          if (fVar12 == 0.0) {

            fVar12 = 0.0;

          }

          else {

            fVar12 = g_flOne / SQRT(fVar12);

          }

          fStack_b0 = fVar12 * fStack_b0;

          fStack_ac = fVar12 * fStack_ac;

          fStack_a8 = fVar12 * fStack_a8;

          fStack_a4 = fVar12 * fStack_a4;

        }

        piVar1 = (int *)param_1[0x19];

        iVar6 = *(int *)(piVar1[2] + 0x3c);

        fStack_c0 = *(float *)(iVar6 + 0x40);

        fStack_bc = *(float *)(iVar6 + 0x44);

        fStack_b8 = *(float *)(iVar6 + 0x48);

        iVar6 = *(int *)(piVar1[1] + 4);

        bVar10 = *(int *)(*(int *)(iVar6 + 0xac + (int)piVar1) + 0x38) == 0x12;

        bVar3 = false;

        if (!bVar10) {

          if (piVar1 == (int *)0x0) {

            iVar9 = 0;

          }

          else {

            iVar9 = (int)piVar1 + iVar6 + 4;

          }

          bVar10 = iVar9 == *(int *)(*(int *)((int)piVar1 + iVar6 + 0xa8) + 0xe8a0);

        }

        if (((char)piVar1[4] != '\0') && (*(char *)((int)piVar1 + 0x279) == '\0')) {

          puVar7 = (undefined4 *)FUN_00404c90();

          uStack_80 = *puVar7;

          fStack_7c = (float)puVar7[1];

          fStack_78 = (float)puVar7[2];

          fStack_74 = (float)puVar7[3];

          pfVar5 = (float *)FUN_0040cf70();

          fStack_e0 = *pfVar5;

          fStack_dc = pfVar5[1];

          fStack_d8 = pfVar5[2];

          fStack_d4 = pfVar5[3];

          iVar6 = *(int *)(piVar1[2] + 0x3c);

          uStack_30 = *(undefined4 *)(iVar6 + 0x50);

          uStack_2c = *(undefined4 *)(iVar6 + 0x54);

          uStack_28 = *(undefined4 *)(iVar6 + 0x58);

          uStack_24 = *(undefined4 *)(iVar6 + 0x5c);

          puVar7 = (undefined4 *)FUN_00404a20();

          uStack_60 = *puVar7;

          fStack_5c = (float)puVar7[1];

          uStack_58 = puVar7[2];

          fStack_54 = (float)puVar7[3];

          cVar4 = (**(code **)(*piVar1 + 0x3c))

                            (param_2,&uStack_80,&fStack_e0,&uStack_30,&uStack_60,0x3e4ccccd,

                             0x3dcccccd);

          if (cVar4 == '\0') {

            *(undefined1 *)(param_1[0x19] + 0x304) = 0;

            iVar6 = FUN_0053e0b0();

            *(undefined4 *)(iVar6 + 0x20) = g_abInferredDefaultAimPos._0_4_;

            *(undefined4 *)(iVar6 + 0x24) = g_abInferredDefaultAimPos._4_4_;

            *(undefined4 *)(iVar6 + 0x28) = g_abInferredDefaultAimPos._8_4_;

            *(undefined4 *)(iVar6 + 0x2c) = g_abInferredDefaultAimPos._12_4_;

            CVOGPhysics_ApplyImpulseVector();

          }

          else {

            *(undefined1 *)(param_1[0x19] + 0x304) = 1;

            if (((fStack_dc < 0.0) && (fStack_dc < DAT_00af418c)) &&

               (*(int *)(*(int *)(*(int *)(*(int *)(param_1[0x19] + 4) + 4) + 0xac + param_1[0x19])

                        + 0x38) == 0x14)) {

              fStack_dc = fStack_dc - DAT_00af418c;

              iVar6 = FUN_0053e0b0();

              *(float *)(iVar6 + 0x24) = *(float *)(iVar6 + 0x24) - DAT_00af418c;

            }

            CVOGPhysics_ApplyImpulseVector();

            FUN_00404dc0();

            FUN_0040d040();

          }

          bVar3 = true;

        }

        if (bVar10) {

          iVar6 = param_1[0x19];

          if (((*(float *)(iVar6 + 0x120) == g_flZero) && (*(char *)(iVar6 + 0x304) != '\0')) &&

             (*(char *)(iVar6 + 0x306) == '\0')) {

            (**(code **)(*param_1 + 0x48))(param_2);

          }

          else {

            iVar6 = 0;

            if (*(int **)(param_1[6] + 0xa0) != (int *)0x0) {

              iVar6 = (**(code **)(**(int **)(param_1[6] + 0xa0) + 0x1c8))();

            }

            iVar9 = (**(code **)(*(int *)(*(int *)(*(int *)(param_1[0x19] + 4) + 4) + 4 +

                                         param_1[0x19]) + 0x1dc))();

            if ((iVar9 == 0) && (iVar6 != 0)) {

              pB = g_abTfidInvalid_9DA850;

              pA = (void *)FUN_004ba740(&uStack_80);

              iVar6 = TFID_EqualsObjectId(pA,pB);

              if ((char)iVar6 != '\0') {

                pfVar5 = (float *)FUN_00404c90();

                fStack_e0 = *pfVar5 - local_a0;

                fStack_d8 = pfVar5[2] - local_98;

                fVar12 = fStack_d8 * fStack_d8 + fStack_e0 * fStack_e0;

                fStack_d4 = pfVar5[3] - local_94;

                fStack_dc = 0.0;

                if (_DAT_009da864 < SQRT(fVar12)) {

                  if (fVar12 == 0.0) {

                    fVar12 = 0.0;

                  }

                  else {

                    fVar12 = g_flOne / SQRT(fVar12);

                  }

                  fStack_e0 = fVar12 * fStack_e0;

                  fStack_dc = fVar12 * 0.0;

                  fStack_d8 = fVar12 * fStack_d8;

                  fStack_d4 = fVar12 * fStack_d4;

                }

                (**(code **)(*param_1 + 0x48))(param_2);

                goto LAB_005ce1e6;

              }

            }

            if (fStack_cc < g_flOne) {

              iVar6 = *(int *)(*(int *)(param_1[0x19] + 8) + 0x3c);

              fStack_e0 = ABS(*(float *)(iVar6 + 0x50) - (float)g_abInferredDefaultAimPos._0_4_);

              fStack_dc = ABS(*(float *)(iVar6 + 0x54) - (float)g_abInferredDefaultAimPos._4_4_);

              fStack_d8 = ABS(*(float *)(iVar6 + 0x58) - (float)g_abInferredDefaultAimPos._8_4_);

              fStack_d4 = ABS(*(float *)(iVar6 + 0x5c) - (float)g_abInferredDefaultAimPos._12_4_);

              uStack_3c = (uint)(g_flMsToSeconds_Inferred < fStack_d8) * 2 |

                          (uint)(g_flMsToSeconds_Inferred < fStack_dc) * 4 |

                          (uint)(g_flMsToSeconds_Inferred < fStack_e0) * -8 & 0xe;

              if (uStack_3c != 0) {

                FUN_0040d040();

              }

            }

            else {

              (**(code **)(*param_1 + 0x48))(param_2);

            }

          }

        }

LAB_005ce1e6:

        if ((!bVar3) &&

           (((*(char *)(param_1[0x19] + 0x304) != '\0' ||

             (*(float *)(param_1[0x19] + 0x120) != g_flZero)) &&

            (fVar11 = (float10)FUN_004c55e0(), (float10)g_flZero < fVar11)))) {

          iVar6 = param_1[0x19];

          if (*(char *)(iVar6 + 0x314) == '\0') {

            if (((*(float *)(iVar6 + 0x120) == g_flZero) &&

                (*(int *)(*(int *)(*(int *)(*(int *)(iVar6 + 4) + 4) + 0xac + iVar6) + 0x38) != 0x14

                )) && ((cVar4 = FUN_0040b1b0(), cVar4 == '\0' &&

                       (puVar8 = (uint *)FUN_004ba740(), (*puVar8 & puVar8[1]) == 0xffffffff)))) {

              fStack_100 = fStack_100 - local_a0;

              fStack_78 = fStack_f8 - local_98;

              fStack_cc = fStack_100 * fStack_100 + fStack_78 * fStack_78;

              fStack_c4 = SQRT(fStack_c0 * fStack_c0 + fStack_bc * fStack_bc + fStack_b8 * fStack_b8

                              );

              fStack_54 = fStack_f4 - local_94;

              fVar14 = 0.0;

              fVar13 = fStack_100;

              fVar12 = fStack_78;

              if (_DAT_009da864 < SQRT(fStack_cc)) {

                if (fStack_cc == 0.0) {

                  fVar12 = 0.0;

                }

                else {

                  fVar12 = g_flOne / SQRT(fStack_cc);

                }

                fVar13 = fStack_100 * fVar12;

                fVar14 = fVar12 * 0.0;

                fVar12 = fStack_78 * fVar12;

              }

              fStack_b8 = fVar12 * fStack_88 - fStack_b8;

              fStack_c0 = fVar13 * fStack_88 - fStack_c0;

              fStack_bc = fVar14 * fStack_88 - fStack_bc;

              fVar12 = fStack_c0 * fStack_c0 + fStack_b8 * fStack_b8 + fStack_bc * fStack_bc;

              if (_DAT_009da864 < SQRT(fVar12)) {

                if (fVar12 == 0.0) {

                  fVar12 = 0.0;

                }

                else {

                  fVar12 = g_flOne / SQRT(fVar12);

                }

                fStack_c0 = fStack_c0 * fVar12;

                fStack_bc = fStack_bc * fVar12;

                fStack_b8 = fStack_b8 * fVar12;

              }

              fStack_bc = fStack_bc * fStack_88;

              fStack_c0 = fStack_c0 * fStack_88;

              fStack_b8 = fStack_b8 * fStack_88;

              fStack_5c = 0.0;

              fVar12 = fStack_78;

              if (_DAT_009da864 < SQRT(fStack_cc)) {

                if (fStack_cc == 0.0) {

                  fVar12 = 0.0;

                }

                else {

                  fVar12 = g_flOne / SQRT(fStack_cc);

                }

                fStack_100 = fStack_100 * fVar12;

                fStack_5c = fVar12 * 0.0;

                fStack_54 = fStack_54 * fVar12;

                fVar12 = fStack_78 * fVar12;

              }

              fStack_7c = (fStack_c0 * fVar12 + fStack_100 * DAT_00aaa668 * fStack_b8 +

                          fStack_bc * 0.0) * _DAT_00af4188 * 0.0;

              fStack_74 = fStack_7c;

              FUN_00404d10();

              FUN_00404d10();

              FUN_005d1ce0();

            }

            else {

              fStack_b8 = fStack_cc;

              if (fStack_88 < fStack_cc) {

                fStack_b8 = fStack_88;

              }

              fStack_c0 = fStack_b0 * fStack_b8;

              fStack_bc = fStack_b8 * fStack_ac;

              fStack_b4 = fStack_b8 * fStack_a4;

              fStack_b8 = fStack_b8 * fStack_a8;

              if (fStack_c8 < local_9c) {

                fStack_bc = *(float *)(*(int *)(*(int *)(iVar6 + 8) + 0x3c) + 0x44);

                iVar6 = FUN_004cdd90();

                fStack_bc = *(float *)(iVar6 + 4) * param_2 + fStack_bc;

              }

              CVOGPhysics_ApplyImpulseVector();

            }

          }

          else if (*(char *)(iVar6 + 0x10) != '\0') {

            puVar7 = (undefined4 *)FUN_0053e0b0();

            CVOGReaction_TeleportTarget((void *)param_1[0x19],puVar7);

            FUN_0053e0b0();

            CVOGPhysics_ApplyImpulseVector();

            *(undefined1 *)(param_1[0x19] + 0x314) = 0;

          }

        }

        iVar6 = param_1[0x19];

        if ((*(char *)(iVar6 + 0x10) == '\0') ||

           (0x18ff < g_dwClientTickMs - *(int *)(iVar6 + 0x14))) {

          if (*(char *)((int)param_1 + 0x96) != '\0') {

            *(undefined1 *)((int)param_1 + 0x96) = 0;

            iVar6 = *(int *)(*(int *)(iVar6 + 8) + 0x3c);

            fVar11 = (float10)CVOGMap_CastTerrainHeight

                                        (*(undefined4 *)(iVar6 + 0xb0),*(undefined4 *)(iVar6 + 0xb8)

                                         ,*(float *)(iVar6 + 0xb4) + DAT_00a110d8,0);

            iVar6 = *(int *)(*(int *)(param_1[0x19] + 8) + 0x3c);

            puVar7 = (undefined4 *)FUN_0053e0b0();

            uVar2 = *(undefined4 *)(iVar6 + 0xb0);

            puVar7[2] = *(undefined4 *)(iVar6 + 0xb8);

            puVar7[1] = (float)fVar11 + local_84;

            *puVar7 = uVar2;

            puVar7[3] = 0;

          }

        }

        else {

          *(undefined1 *)((int)param_1 + 0x96) = 1;

          pfVar5 = (float *)FUN_0053e0b0();

          iVar6 = FUN_0053e0b0();

          *pfVar5 = *(float *)(iVar6 + 0x20) * param_2 + *pfVar5;

          pfVar5[1] = *(float *)(iVar6 + 0x24) * param_2 + pfVar5[1];

          pfVar5[2] = *(float *)(iVar6 + 0x28) * param_2 + pfVar5[2];

          pfVar5[3] = *(float *)(iVar6 + 0x2c) * param_2 + pfVar5[3];

          iVar6 = FUN_0053e0b0();

          if (*(float *)(iVar6 + 4) <= fStack_c8 && fStack_c8 != *(float *)(iVar6 + 4)) {

            iVar6 = FUN_0053e0b0();

            *(float *)(iVar6 + 4) = fStack_c8;

          }

          FUN_004c3ac0();

          FUN_0053e0b0();

          FUN_004cb3e0();

        }

        goto LAB_005ce963;

      }

    }

  }

  FUN_007a4480(0,"VOG_DEBUG_STOP");

LAB_005ce963:

  local_14 = 0xffffffff;

  FUN_0076cef0();

  ExceptionList = pvStack_1c;

  return;

}
```

---

## Version: 2026-07-29 dual W16-I (live re-decompile + image seal)

| Field | Value |
|---|---|
| **Capture timestamp** | `2026-07-29` |
| **Tool** | Ghidra MCP `decompile_function` + `read_memory` (no `disassemble_bytes`) |
| **Body span** | `005cd3b0` – `005ce989` (`get_function_by_address`) |
| **Product string** | `0x009da8a8` = `CVOGHBAICreatureBase::DoMovement` |
| **Integrity** | Append-only; original 2026-07-23 body retained above |

### Live re-decompile

Re-ran `decompile_function` @ `0x005cd3b0` (2026-07-29). Body matches 2026-07-23 scaffold shape (large thiscall movement tick, SEH, VOG_DEBUG_STOP NaN path). Full listing preserved in:

- `docs/reconstruction/tmp/decomp_005cd3b0.txt`
- clean `docs/reconstruction/reconstructed-exact/CVOGHBAICreatureBase_DoMovement.cpp`

### Live prologue bytes (`read_memory` @ `0x005cd3b0`, 128 B)

```
55 8b ec 83 e4 f0 6a ff 68 98 6f 9a 00 64 a1 00 00 00 00 50 64 89 25 00 00 00 00
81 ec e8 00 00 00 53 56 57 8b 3d 40 f0 d1 00 8b f1 68 a8 a8 9d 00 8b cf ...
; call FUN_0076cf00
83 7e 18 00       ; cmp dword [esi+0x18], 0
0f 84 .. .. .. .. ; je cleanup
```

Push imm `0x009da8a8` = product scope name string. `mov esi, ecx` seals thiscall.

### Epilogue region (`read_memory` @ `0x005ce960`)

Cleanup sets SEH state `0xffffffff`, calls `FUN_0076cef0`, restores ExceptionList, returns.

### Xrefs

DATA only (vtables): `009da9b4`, `009daf3c`, `009db0bc`, `009db11c`, `009db17c` — each dword `0x005cd3b0`.

