// =============================================================================
// CSoundManager_TickHardKillAndRegions_Inferred
// -----------------------------------------------------------------------------
// Stable ID: aa_007252d0
// Address:   0x007252d0–0x0072589f  (autoassault.exe, image base 0x400000)
// System:    client audio / CSoundManager
// Generated: 2026-07-29 W18-F OWN dual seal (live Ghidra decompile + read_memory)
// Exactness: Behavior-preserving rewrite of decompiler control flow. Not modernization.
// Bit-for-bit vs retail EXE: DEFERRED (not run).
// =============================================================================

// PURPOSE:
//   Nested tick from UpdateSounds::updateSoundRegions (parent 0x00727440):
//   feature-gated hard-kill timer walk on this+0x28c and region walk on this+0x29c.
//
// ABI (sealed):
//   this in EBX (decompiler unaff_EBX); stack enableFlag, dt; RET 8

void CSoundManager_TickHardKillAndRegions_Inferred(int param_1,float param_2)



{

  ushort uVar1;

  bool bVar2;

  float fVar3;

  char cVar4;

  uint32_t /* width from decompiler */ *puVar5;

  int iVar6;

  uint *puVar7;

  char *pcVar8;

  uint32_t /* width from decompiler */ *puVar9;

  int unaff_EBX; // this (CSoundManager*) in EBX

  int *piVar10;

  float fVar11;

  char *pcVar12;

  uint32_t /* width from decompiler */ uVar13;

  char local_e9;

  int *local_e8;

  char *local_e4;

  char *local_e0 [2];

  uint32_t /* width from decompiler */ local_d8;

  uint32_t /* width from decompiler */ local_d4;

  uint32_t /* width from decompiler */ local_d0;

  uint32_t /* width from decompiler */ local_cc;

  uint32_t /* width from decompiler */ local_c8;

  uint32_t /* width from decompiler */ local_c4;

  uint8_t local_b4 [4];

  uint32_t /* width from decompiler */ local_b0 [4];

  uint8_t local_a0 [16];

  uint8_t local_90 [16];

  uint8_t local_80 [16];

  uint8_t local_70 [16];

  uint8_t local_60 [16];

  uint8_t local_50 [16];

  uint8_t local_40 [16];

  uint8_t local_30 [20];

  void *local_1c;

  uint8_t *puStack_18;

  uint32_t /* width from decompiler */ local_14;

  

  local_14 = 0xffffffff;

  puStack_18 = &LAB_009b10df;

  local_1c = ExceptionList;

  if ((DAT_00afa9b1 != '\0') &&

     ((((*(int *)(unaff_EBX + 0x28c) != 0 &&

        (local_e0[0] = (char *)(*(int *)(unaff_EBX + 0x290) - *(int *)(unaff_EBX + 0x28c) >> 2),

        local_e0[0] != (char *)0x0)) ||

       ((*(int *)(unaff_EBX + 0x29c) != 0 &&

        (local_e0[0] = (char *)(*(int *)(unaff_EBX + 0x2a0) - *(int *)(unaff_EBX + 0x29c) >> 2),

        local_e0[0] != (char *)0x0)))) && (param_1 != 0)))) {

    ExceptionList = &local_1c;

    local_d8 = FUN_004933f0();

    local_d4 = 0;

    local_14 = 0;

    param_2 = *(float *)(unaff_EBX + 0x284) + param_2;

    bVar2 = g_flZero <= param_2;

    *(float *)(unaff_EBX + 0x284) = param_2;

    if (bVar2) {

      piVar10 = *(int **)(unaff_EBX + 0x28c);

      if (piVar10 != *(int **)(unaff_EBX + 0x290)) {

        do {

          fVar3 = g_flZero;

          iVar6 = *piVar10;

          if (iVar6 == 0) {

            piVar10 = piVar10 + 1;

          }

          else {

            fVar11 = *(float *)(iVar6 + 0x13c) - *(float *)(unaff_EBX + 0x284);

            *(float *)(iVar6 + 0x13c) = fVar11;

            if (fVar11 <= fVar3) {

              local_e9 = '\0';

              cVar4 = FUN_004bbbc0(iVar6,&local_e9);

              if (cVar4 == '\0') {

                puVar5 = &local_d0;

                goto LAB_0072585a;

              }

              iVar6 = *piVar10;

              fVar3 = *(float *)(iVar6 + 0x18) - *(float *)(unaff_EBX + 0x228);

              fVar11 = *(float *)(iVar6 + 0x10) - *(float *)(unaff_EBX + 0x220);

              local_e8 = (int *)SQRT(fVar3 * fVar3 + fVar11 * fVar11);

              if ((float)local_e8 <= *(float *)(iVar6 + 4)) {

                if (*(char *)(unaff_EBX + 0x303) != '\0') {

                  *(uint32_t /* width from decompiler */ *)(iVar6 + 0x13c) = 0;

                }

                FUN_004406e0();

                puVar5 = (uint32_t /* width from decompiler */ *)FUN_00480310(local_e0,piVar10);

                piVar10 = (int *)*puVar5;

              }

              else {

                local_e4 = (char *)(((float)local_e8 - *(float *)(iVar6 + 4)) *

                                   g_flHardKillInterpolate);

                if (DAT_00aaa690 < (float)local_e4) {

                  local_e4 = (char *)DAT_00aaa690;

                }

                iVar6 = CVOGReaction_RandomUnitScalar();

                if (0xfffff < *(int *)(iVar6 + 0xc)) {

                  *(uint32_t /* width from decompiler */ *)(iVar6 + 0xc) = 0;

                }

                uVar1 = *(ushort *)(*(int *)(iVar6 + 8) + *(int *)(iVar6 + 0xc) * 2);

                *(int *)(iVar6 + 0xc) = *(int *)(iVar6 + 0xc) + 1;

                *(float *)(*piVar10 + 0x13c) = (float)uVar1 * DAT_00aaa638 + (float)local_e4;

                piVar10 = piVar10 + 1;

              }

            }

            else {

              piVar10 = piVar10 + 1;

            }

          }

        } while (piVar10 != *(int **)(unaff_EBX + 0x290));

      }

      *(uint32_t /* width from decompiler */ *)(unaff_EBX + 0x284) = 0;

    }

    if (((DAT_00afa9b2 != '\0') &&

        (local_e8 = *(int **)(unaff_EBX + 0x29c),

        g_flZero <

        SQRT(*(float *)(unaff_EBX + 0x220) * *(float *)(unaff_EBX + 0x220) +

             *(float *)(unaff_EBX + 0x228) * *(float *)(unaff_EBX + 0x228) +

             *(float *)(unaff_EBX + 0x224) * *(float *)(unaff_EBX + 0x224)))) &&

       (local_e8 != *(int **)(unaff_EBX + 0x2a0))) {

      do {

        piVar10 = local_e8;

        if (DAT_00afa9b4 != '\0') {

          pcVar12 = (char *)*local_e8;

          local_e0[0] = pcVar12;

          if (pcVar12 == (char *)0x0) {

            local_e8 = local_e8 + 1;

            goto LAB_00725841;

          }

          local_e9 = '\0';

          cVar4 = FUN_004bbbc0(pcVar12,&local_e9);

          if (cVar4 != '\0') {

            if (DAT_00afa9b5 == '\0') {

              local_e8 = piVar10 + 1;

            }

            else if (local_e9 == '\0') {

              fVar3 = *(float *)(pcVar12 + 0x18) - *(float *)(unaff_EBX + 0x228);

              fVar11 = *(float *)(pcVar12 + 0x10) - *(float *)(unaff_EBX + 0x220);

              local_e4 = (char *)SQRT(fVar3 * fVar3 + fVar11 * fVar11);

              if (((*(float *)(pcVar12 + 4) < (float)local_e4) || ((float)local_e4 < g_flZero)) ||

                 (DAT_00afa9b3 == '\0')) {

                pcVar12[0x144] = '\0';

                puVar5 = (uint32_t /* width from decompiler */ *)FUN_00480200(local_50);

                uVar13 = 0;

                pcVar12 = pcVar12 + 0x20;

                iVar6 = FUN_00480200(local_b0);

                FUN_00723b20(*puVar5,puVar5[1],*(uint8_t *)(iVar6 + 8),pcVar12,uVar13);

                FUN_004406e0();

                puVar5 = (uint32_t /* width from decompiler */ *)FUN_00480310(local_b4,local_e8);

                local_e8 = (int *)*puVar5;

              }

              else {

                if ((pcVar12[0x144] == '\0') ||

                   (puVar7 = (uint *)FUN_00480200(local_80), (*puVar7 & puVar7[1]) != 0xffffffff)) {

                  puVar5 = (uint32_t /* width from decompiler */ *)FUN_00480200(local_40);

                  cVar4 = FUN_007229f0(unaff_EBX,*puVar5,puVar5[1],pcVar12 + 0x20);

                  if ((cVar4 == '\0') &&

                     (local_e4 = (char *)FUN_007249c0(pcVar12 + 0x20,DAT_00d1a614),

                     local_e4 != (char *)0x0)) {

                    iVar6 = FUN_00480460();

                    if (iVar6 == 0) {

                      pcVar8 = (char *)0x0;

                    }

                    else {

                      pcVar8 = (char *)FUN_00480170();

                    }

                    local_e0[0] = pcVar8;

                    strncpy(pcVar8,local_e4,0x104);

                    puVar5 = (uint32_t /* width from decompiler */ *)FUN_00480200(local_60);

                    *(uint32_t /* width from decompiler */ *)(pcVar8 + 0x120) = *puVar5;

                    *(uint32_t /* width from decompiler */ *)(pcVar8 + 0x124) = puVar5[1];

                    *(uint32_t /* width from decompiler */ *)(pcVar8 + 0x128) = puVar5[2];

                    *(uint32_t /* width from decompiler */ *)(pcVar8 + 300) = puVar5[3];

                    pcVar8[0x10b] = '\x01';

                    pcVar8[0x131] = '\0';

                    *(uint32_t /* width from decompiler */ *)(pcVar8 + 0x104) = *(uint32_t /* width from decompiler */ *)(pcVar12 + 0x138);

                    pcVar8[0x150] = '\0';

                    pcVar8[0x151] = '\0';

                    pcVar8[0x152] = '\0';

                    pcVar8[0x153] = '\0';

                    *(float *)(pcVar8 + 0x118) = g_flLevelUpUiBase_Inferred;

                    *(float *)(pcVar8 + 0x154) = g_flOne;

                    *(uint32_t /* width from decompiler */ *)(pcVar8 + 0x110) = *(uint32_t /* width from decompiler */ *)pcVar12;

                    *(uint32_t /* width from decompiler */ *)(pcVar8 + 0x11c) = *(uint32_t /* width from decompiler */ *)(pcVar12 + 8);

                    *(uint32_t /* width from decompiler */ *)(pcVar8 + 0x114) = *(uint32_t /* width from decompiler */ *)(pcVar12 + 4);

                    FUN_00480350(unaff_EBX + 0x310);

                    pcVar12[0x144] = '\x01';

                  }

                }

                local_d0 = *(uint32_t /* width from decompiler */ *)(pcVar12 + 0x10);

                local_cc = *(uint32_t /* width from decompiler */ *)(pcVar12 + 0x14);

                local_c8 = *(uint32_t /* width from decompiler */ *)(pcVar12 + 0x18);

                local_c4 = 0;

                puVar9 = (uint32_t /* width from decompiler */ *)FUN_00480200(local_90);

                puVar5 = &local_d0;

                FUN_00480200(local_70);

                FUN_00723440(unaff_EBX,pcVar12 + 0x20,*puVar9,puVar9[1],puVar5);

                local_e8 = local_e8 + 1;

              }

            }

            else {

              puVar5 = (uint32_t /* width from decompiler */ *)FUN_00480200(local_a0);

              uVar13 = 0;

              pcVar8 = pcVar12 + 0x20;

              iVar6 = FUN_00480200(local_30);

              FUN_00723b20(*puVar5,puVar5[1],*(uint8_t *)(iVar6 + 8),pcVar8,uVar13);

              local_e8 = local_e8 + 1;

              pcVar12[0x144] = '\0';

            }

            goto LAB_00725841;

          }

          puVar5 = local_b0;

LAB_0072585a:

          puVar5 = (uint32_t /* width from decompiler */ *)FUN_00480200(puVar5);

          FUN_00722f20(*puVar5,puVar5[1],puVar5[2],puVar5[3]);

          break;

        }

        local_e8 = local_e8 + 1;

LAB_00725841:

      } while (local_e8 != *(int **)(unaff_EBX + 0x2a0));

    }

    FUN_00415d60();

  }

  ExceptionList = local_1c;

  return;

}
