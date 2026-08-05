// =============================================================================
// FUN_005eced0
// -----------------------------------------------------------------------------
// Stable ID: aa_005eced0
// Address:   0x005eced0  (autoassault.exe, image base 0x400000)
// System:    unknown
// Generated: 2026-07-23 from raw capture (scaffold; refine for important units)
// Exactness: Behavior-preserving rewrite of decompiler control flow. Not modernization.
// Bit-for-bit vs retail EXE: DEFERRED (loaded image may differ slightly).
// =============================================================================

// PURPOSE (auto): Scaffold unit for FUN_005eced0 @ 0x005eced0
// Stable ID: aa_005eced0
// No high-value strings recovered; name via xrefs/callers in follow-up.
// Readability: control flow preserved from Ghidra decompile; types tentative.

// READABILITY (auto CF):
//  - Body size: ~606 non-empty decompiler lines.
//  - Control keywords: if×51, while×10, do×9, return×5, goto×5, for×2.
//  - Notable callees: free×17, CONCAT31×5, malloc×4, FUN_005c65e0×3, _eh_vector_destructor_iterator_×3, FUN_005eced0×2, _eh_vector_constructor_iterator_×2, FUN_005c65c0.
//  - Return sites: 5.

/*
 * Behavioral notes:
 * - Derived from Ghidra decompile; names prefer Ghidra symbols / plate comments.
 * - Remaining FUN_* / DAT_* identifiers are unresolved pending type recovery.
 * - Runtime / differential verification: OPEN unless matrix says otherwise.
 *
 * Readability pass:
 * - undefinedN widths preserved as fixed-width integers where decompiler width is known.
 * - Control flow and call order preserved from authoritative raw.
 */

void __thiscall FUN_005eced0(uint param_1,int param_2,int *param_3)



{

  float *pfVar1;

  char cVar2;

  uint32_t /* width from decompiler */ *puVar3;

  uint32_t /* width from decompiler */ *puVar4;

  uint32_t /* width from decompiler */ uVar5;

  uint32_t /* width from decompiler */ uVar6;

  uint uVar7;

  float *pfVar8;

  float *pfVar9;

  uint uVar10;

  float *pfVar11;

  int *piVar12;

  uint32_t /* width from decompiler */ *puVar13;

  uint32_t /* width from decompiler */ *puVar14;

  float *pfVar15;

  uint uVar16;

  int *piVar17;

  uint *puVar18;

  void *pvVar19;

  int iVar20;

  float fVar21;

  float fVar22;

  float fVar23;

  float fVar24;

  float fVar25;

  float fVar26;

  float fStack_148;

  float fStack_144;

  uint uStack_11c;

  uint uStack_118;

  float *pfStack_114;

  float *pfStack_110;

  float *pfStack_10c;

  uint32_t /* width from decompiler */ uStack_108;

  float local_104;

  uint uStack_100;

  float *pfStack_fc;

  void *pvStack_f8;

  uint32_t /* width from decompiler */ uStack_f4;

  uint32_t /* width from decompiler */ uStack_f0;

  float fStack_e8;

  void *pvStack_e4;

  uint32_t /* width from decompiler */ uStack_e0;

  uint32_t /* width from decompiler */ uStack_dc;

  void *pvStack_d0;

  int iStack_cc;

  uint32_t /* width from decompiler */ uStack_c8;

  uint local_b8;

  int iStack_b4;

  uint uStack_b0;

  float fStack_ac;

  float fStack_a8;

  float fStack_a4;

  float fStack_a0;

  int iStack_9c;

  uint uStack_98;

  uint uStack_94;

  uint uStack_90;

  uint *puStack_8c;

  float fStack_88;

  float fStack_84;

  int iStack_70;

  uint32_t /* width from decompiler */ uStack_6c;

  uint32_t /* width from decompiler */ uStack_68;

  uint32_t /* width from decompiler */ uStack_64;

  int iStack_60;

  uint32_t /* width from decompiler */ uStack_5c;

  uint32_t /* width from decompiler */ uStack_58;

  int aiStack_4c [8];

  float afStack_2c [2];

  uint8_t auStack_24 [4];

  float fStack_20;

  int iStack_1c;

  int iStack_14;

  void *local_c;

  uint8_t *puStack_8;

  uint32_t /* width from decompiler */ uStack_4;

  

  uStack_4 = 0xffffffff;

  puStack_8 = &LAB_009a78a6;

  local_c = ExceptionList;

  local_b8 = param_1;

  if (*(int *)(param_2 + 4) == 5) {

    if (*(int *)(param_2 + 0x68) != 0) {

      ExceptionList = &local_c;

      fStack_88 = (float)(**(code **)(**(int **)(param_2 + 0x68) + 4))();

      local_104 = 0.0;

      if (fStack_88 != 0.0) {

        do {

          fVar21 = local_104;

          uVar16 = (**(code **)(**(int **)(param_2 + 0x68) + 8))();

          local_b8 = uVar16;

          (**(code **)(**(int **)(param_2 + 0x68) + 0x10))();

          uStack_108 = 0;

          local_104 = 0.0;

          uStack_100 = 0;

          fStack_144 = 8.707166e-39;

          FUN_005ee270();

          uVar7 = uVar16;

          pfVar11 = pfStack_110;

          while (pfStack_110 = (float *)uVar7, pfStack_110 != (float *)0x0) {

            fStack_144 = 8.707191e-39;

            FUN_005ee310();

            pfVar11 = (float *)((int)pfStack_110 - 1);

            uVar7 = (uint)pfVar11;

          }

          iStack_14 = 0;

          fStack_148 = 8.707245e-39;

          fStack_144 = fVar21;

          pfStack_110 = pfVar11;

          uVar5 = (**(code **)(**(int **)((int)local_c + 0x68) + 8))();

          fStack_148 = 0.0;

          uVar6 = (**(code **)(**(int **)(iStack_14 + 0x68) + 0x10))(fVar21);

          FUN_005ee550(uVar6,uVar5,&uStack_118);

          auStack_24[0] = 1;

          uVar7 = (**(code **)(**(int **)(iStack_1c + 0x68) + 8))(fVar21,4);

          if ((uVar7 < 0x20) && (uVar16 < 0x20)) {

            if (*(uint *)(param_1 + 0x58) <= *(uint *)(param_1 + 0x54)) {

              iVar20 = *(int *)(param_1 + 0x50);

              uVar7 = ((int)(*(uint *)(param_1 + 0x54) - iVar20) >> 2) * 2 + 2;

              if (iVar20 == 0) {

                uVar16 = 0;

              }

              else {

                uVar16 = (int)(*(uint *)(param_1 + 0x58) - iVar20) >> 2;

              }

              if (uVar16 < uVar7) {

                fVar22 = (float)(uVar7 * 4);

                local_104 = fVar22;

                puVar3 = malloc((size_t)fVar22);

                puVar13 = *(uint32_t /* width from decompiler */ **)(param_1 + 0x54);

                puVar14 = puVar3;

                for (puVar4 = *(uint32_t /* width from decompiler */ **)(param_1 + 0x50); puVar4 != puVar13;

                    puVar4 = puVar4 + 1) {

                  *puVar14 = *puVar4;

                  puVar14 = puVar14 + 1;

                  fVar22 = local_104;

                }

                if (*(void **)(param_1 + 0x50) != (void *)0x0) {

                  free(*(void **)(param_1 + 0x50));

                }

                *(int *)(param_1 + 0x58) = (int)fVar22 + (int)puVar3;

                *(uint32_t /* width from decompiler */ **)(param_1 + 0x54) =

                     puVar3 + (*(int *)(param_1 + 0x54) - *(int *)(param_1 + 0x50) >> 2);

                *(uint32_t /* width from decompiler */ **)(param_1 + 0x50) = puVar3;

              }

            }

            **(int **)(param_1 + 0x54) = param_2;

            *(int *)(param_1 + 0x54) = *(int *)(param_1 + 0x54) + 4;

            if (pvStack_e4 != (void *)0x0) {

              free(pvStack_e4);

            }

            pvStack_e4 = (void *)0x0;

            uStack_e0 = 0;

            uStack_dc = 0;

            uStack_4 = 0xffffffff;

            if (pvStack_f8 != (void *)0x0) {

              free(pvStack_f8);

            }

          }

          else {

            *(int *)(param_1 + 0x68) = *(int *)(param_1 + 0x68) + 1;

            FUN_005ec770();

            uStack_4._0_1_ = 3;

            pfStack_114 = malloc(0x820);

            pfStack_10c = pfStack_114 + 0x208;

            uStack_98 = 0;

            uStack_100 = 0;

            uStack_11c = 0;

            uStack_94 = 0;

            iVar20 = iStack_cc - (int)pvStack_d0 >> 0x1f;

            pfStack_110 = pfStack_114;

            if ((iStack_cc - (int)pvStack_d0) / 0x1c + iVar20 == iVar20) {

LAB_005edca2:

              if (pfStack_114 != (float *)0x0) {

                free(pfStack_114);

              }

              if (pvStack_d0 != (void *)0x0) {

                free(pvStack_d0);

              }

              pvStack_d0 = (void *)0x0;

              iStack_cc = 0;

              uStack_c8 = 0;

              if (pvStack_e4 != (void *)0x0) {

                free(pvStack_e4);

              }

              pvStack_e4 = (void *)0x0;

              uStack_e0 = 0;

              uStack_dc = 0;

              if (pvStack_f8 == (void *)0x0) {

                ExceptionList = local_c;

                return;

              }

              free(pvStack_f8);

              ExceptionList = local_c;

              return;

            }

            iStack_b4 = 0;

            do {

              puVar18 = (uint *)(iStack_b4 + (int)pvStack_d0);

              uStack_118 = 0;

              fStack_144 = 8.707917e-39;

              puStack_8c = puVar18;

              _eh_vector_constructor_iterator_(afStack_2c,0x10,2,FUN_005edf20,FUN_0056f570);

              uStack_4 = CONCAT31(uStack_4._1_3_,4);

              FUN_005ec620();

              uStack_90 = 0;

              pfVar11 = pfStack_110;

              if (uStack_b0 != 0) {

                iStack_9c = 0;

                pvVar19 = pvStack_f8;

                do {

                  uVar7 = *puVar18;

                  if ((uStack_90 != uVar7) && (uVar16 = puVar18[1], uStack_90 != uVar16)) {

                    fVar22 = *(float *)(iStack_9c + 8 + (int)pvVar19) -

                             *(float *)((int)pvVar19 + uVar7 * 0xc + 8);

                    fVar21 = *(float *)(iStack_9c + 4 + (int)pvVar19) -

                             *(float *)((int)pvVar19 + uVar7 * 0xc + 4);

                    fVar24 = *(float *)((int)pvVar19 + uVar16 * 0xc + 8) -

                             *(float *)((int)pvVar19 + uVar7 * 0xc + 8);

                    fVar25 = *(float *)((int)pvVar19 + uVar16 * 0xc + 4) -

                             *(float *)((int)pvVar19 + uVar7 * 0xc + 4);

                    fVar26 = *(float *)((int)pvVar19 + uVar16 * 0xc) -

                             *(float *)((int)pvVar19 + uVar7 * 0xc);

                    fVar23 = *(float *)(iStack_9c + (int)pvVar19) -

                             *(float *)((int)pvVar19 + uVar7 * 0xc);

                    pfVar8 = (float *)((int)pvVar19 + uVar7 * 0xc);

                    fStack_ac = fVar22 * fVar25 - fVar21 * fVar24;

                    fStack_a4 = fVar21 * fVar26 - fVar23 * fVar25;

                    fStack_a8 = fVar23 * fVar24 - fVar22 * fVar26;

                    fStack_84 = fStack_a4 * fStack_a4 + fStack_a8 * fStack_a8 +

                                fStack_ac * fStack_ac;

                    fStack_e8 = SQRT(fStack_84);

                    if (fStack_e8 != g_flZero) {

                      fVar21 = g_flOne / fStack_e8;

                      fStack_ac = fStack_ac * fVar21;

                      fStack_a8 = fStack_a8 * fVar21;

                      fStack_a4 = fStack_a4 * fVar21;

                    }

                    uVar7 = 0;

                    fStack_a0 = 0.0 - (fStack_a8 * pfVar8[1] + *pfVar8 * fStack_ac +

                                      pfVar8[2] * fStack_a4);

                    if (uStack_118 != 0) {

                      pfVar8 = afStack_2c + 1;

                      do {

                        if (0.0 < pfVar8[1] * *(float *)(iStack_9c + 8 + (int)pvVar19) +

                                  pfVar8[-1] * *(float *)(iStack_9c + (int)pvVar19) +

                                  *pfVar8 * *(float *)(iStack_9c + 4 + (int)pvVar19) + pfVar8[2])

                        goto LAB_005ed6ab;

                        uVar7 = uVar7 + 1;

                        pfVar8 = pfVar8 + 4;

                      } while (uVar7 < uStack_118);

                    }

                    uVar7 = ((int)pfVar11 - (int)pfStack_114) / 0x34;

                    if (uStack_11c < uVar7) {

                      pfVar8 = pfStack_114 + uStack_11c * 0xd + 2;

                      uVar16 = uStack_11c;

                      do {

                        if (((pfVar8[-2] == fStack_ac) && (pfVar8[-1] == fStack_a8)) &&

                           (*pfVar8 == fStack_a4)) goto LAB_005ed6ab;

                        if (((pfVar8[-2] == 0.0 - fStack_ac) && (pfVar8[-1] == 0.0 - fStack_a8)) &&

                           (*pfVar8 == 0.0 - fStack_a4)) goto LAB_005ed6ab;

                        uVar16 = uVar16 + 1;

                        pfVar8 = pfVar8 + 0xd;

                      } while (uVar16 < uVar7);

                    }

                    pfVar9 = operator_new(0x34);

                    pfVar8 = (float *)0x0;

                    if (pfVar9 != (float *)0x0) {

                      pfVar9[7] = 0.0;

                      pfVar9[8] = 0.0;

                      pfVar9[9] = 0.0;

                      pfVar9[10] = 0.0;

                      pfVar9[0xb] = 0.0;

                      pfVar9[0xc] = 0.0;

                      pfVar8 = pfVar9;

                    }

                    *pfVar8 = fStack_ac;

                    pfVar8[1] = fStack_a8;

                    pfVar8[2] = fStack_a4;

                    pfVar8[3] = fStack_a0;

                    if (pfStack_10c <= pfVar11) {

                      uVar16 = uVar7 * 2 + 2;

                      if (pfStack_114 == (float *)0x0) {

                        uVar10 = 0;

                      }

                      else {

                        uVar10 = ((int)pfStack_10c - (int)pfStack_114) / 0x34;

                      }

                      if (uVar10 < uVar16) {

                        pfVar9 = malloc(uVar16 * 0x34);

                        if (pfStack_114 != pfStack_110) {

                          fStack_e8 = (float)((int)pfStack_114 - (int)pfVar9);

                          pfVar11 = pfVar9 + 6;

                          pfVar15 = pfStack_114 + 1;

                          do {

                            pfVar11[-6] = pfVar15[-1];

                            pfVar11[-5] = *pfVar15;

                            pfVar11[-4] = pfVar15[1];

                            pfVar11[-3] = pfVar15[2];

                            pfVar11[-2] = pfVar15[3];

                            pfVar11[-1] = pfVar15[4];

                            *pfVar11 = *(float *)((int)fStack_e8 + (int)pfVar11);

                            pfVar11[1] = pfVar15[6];

                            pfVar11[2] = pfVar15[7];

                            pfVar11[3] = pfVar15[8];

                            pfVar11[4] = pfVar15[9];

                            pfVar11[5] = pfVar15[10];

                            pfVar11[6] = pfVar15[0xb];

                            pfVar1 = pfVar15 + 0xc;

                            pfVar11 = pfVar11 + 0xd;

                            pfVar15 = pfVar15 + 0xd;

                          } while (pfVar1 != pfStack_110);

                        }

                        pfStack_fc = pfVar9;

                        if (pfStack_114 != (float *)0x0) {

                          free(pfStack_114);

                        }

                        pfStack_10c = pfVar9 + uVar16 * 0xd;

                        pfVar11 = pfVar9 + uVar7 * 0xd;

                        pfStack_114 = pfVar9;

                      }

                    }

                    *pfVar11 = *pfVar8;

                    pfVar11[1] = pfVar8[1];

                    pfVar11[2] = pfVar8[2];

                    pfVar11[3] = pfVar8[3];

                    pfVar11[4] = pfVar8[4];

                    pfVar11[5] = pfVar8[5];

                    pfVar11[6] = pfVar8[6];

                    pfVar11[7] = pfVar8[7];

                    pfVar11[8] = pfVar8[8];

                    pfVar11[9] = pfVar8[9];

                    pfVar11[10] = pfVar8[10];

                    pfVar11[0xb] = pfVar8[0xb];

                    pfVar11[0xc] = pfVar8[0xc];

                    pfVar11 = pfVar11 + 0xd;

                    pvVar19 = pvStack_f8;

                    pfStack_110 = pfVar11;

                  }

LAB_005ed6ab:

                  uStack_90 = uStack_90 + 1;

                  iStack_9c = iStack_9c + 0xc;

                  puVar18 = puStack_8c;

                } while (uStack_90 < uStack_b0);

              }

              uVar7 = ((int)pfVar11 - (int)pfStack_114) / 0x34;

              if (uStack_11c < uVar7) {

                pfVar11 = pfStack_114 + uStack_11c * 0xd + 0xb;

                iVar20 = uVar7 - uStack_11c;

                do {

                  fStack_148 = pfVar11[-0xb];

                  pfStack_fc = &fStack_148;

                  fStack_144 = pfVar11[-10];

                  FUN_005ec1d0();

                  fStack_148 = pfVar11[-0xb];

                  pfStack_fc = &fStack_148;

                  fStack_144 = pfVar11[-10];

                  FUN_005edf30();

                  pfVar11 = pfVar11 + 0xd;

                  iVar20 = iVar20 + -1;

                } while (iVar20 != 0);

              }

              uStack_118 = uStack_11c;

              if (uStack_11c < uVar7) {

                pfVar11 = pfStack_114 + uStack_11c * 0xd + 8;

                do {

                  fVar21 = *pfVar11;

                  if ((fVar21 != 0.0) && (pfVar11[1] != 0.0)) {

                    uVar16 = (iStack_cc - (int)pvStack_d0) / 0x1c;

                    if (10 < (uint)fVar21) {

                      fVar21 = 1.4013e-44;

                    }

                    fVar22 = pfVar11[1];

                    if (10 < (uint)fVar22) {

                      fVar22 = 1.4013e-44;

                    }

                    uVar16 = ((uVar16 - (int)pfVar11[3]) * 1000) / uVar16 +

                             (uint)((int)pfVar11[-1] * 1000) / uStack_b0 +

                             (uint)((int)pfVar11[2] * 1000) / uVar16 +

                             (uint)((int)fVar22 * (int)fVar21 * 1000) / 100;

                    if (uStack_100 < uVar16) {

                      uStack_98 = uStack_118;

                      uStack_100 = uVar16;

                    }

                  }

                  uStack_118 = uStack_118 + 1;

                  pfVar11 = pfVar11 + 0xd;

                } while (uStack_118 < uVar7);

              }

              *(int *)(local_b8 + 100) = *(int *)(local_b8 + 100) + (uVar7 - uStack_11c);

              uStack_4._0_1_ = 3;

              _eh_vector_destructor_iterator_(afStack_2c,0x10,2,FUN_0056f570);

              iStack_b4 = iStack_b4 + 0x1c;

              uStack_94 = uStack_94 + 1;

              uStack_11c = uVar7;

            } while (uStack_94 < (uint)((iStack_cc - (int)pvStack_d0) / 0x1c));

            if (uStack_100 == 0) goto LAB_005edca2;

            pfVar11 = pfStack_114 + uStack_98 * 0xd;

            pfStack_fc = (float *)&stack0xfffffec4;

            FUN_005ecbc0();

            fStack_144 = 8.710509e-39;

            _eh_vector_constructor_iterator_(aiStack_4c,0x10,2,FUN_005ee160,FUN_005ee000);

            fStack_144 = *pfVar11;

            pfStack_fc = &fStack_144;

            uStack_4._0_1_ = 5;

            fStack_148 = 8.710599e-39;

            FUN_005ee400();

            iVar20 = 0;

            piVar17 = aiStack_4c;

            do {

              iStack_60 = *piVar17;

              iStack_70 = (piVar17[1] - *piVar17) / 0xc;

              uStack_6c = 0;

              uStack_64 = 0;

              uStack_5c = 0;

              uStack_68 = 0xc;

              uStack_58 = 4;

              FUN_005c65c0();

              uStack_4._0_1_ = 6;

              piVar12 = (int *)NxGetCookingLib();

              (**(code **)(*piVar12 + 0xc))();

              cVar2 = (**(code **)(*piVar12 + 0x18))();

              if (cVar2 == '\0') {

                uStack_4 = CONCAT31(uStack_4._1_3_,5);

                FUN_005c65e0();

LAB_005edd4c:

                uStack_4 = CONCAT31(uStack_4._1_3_,3);

                _eh_vector_destructor_iterator_(aiStack_4c,0x10,2,FUN_005ee000);

                if (pfStack_114 != (float *)0x0) {

                  free(pfStack_114);

                }

                if (pvStack_d0 != (void *)0x0) {

                  free(pvStack_d0);

                }

                pvStack_d0 = (void *)0x0;

                iStack_cc = 0;

                uStack_c8 = 0;

                if (pvStack_e4 != (void *)0x0) {

                  free(pvStack_e4);

                }

                pvStack_e4 = (void *)0x0;

                uStack_e0 = 0;

                uStack_dc = 0;

                if (pvStack_f8 == (void *)0x0) {

                  ExceptionList = local_c;

                  return;

                }

                free(pvStack_f8);

                ExceptionList = local_c;

                return;

              }

              (**(code **)(*piVar12 + 0x10))();

              puVar13 = operator_new(0x70);

              fVar21 = g_flOne;

              if (puVar13 == (uint32_t /* width from decompiler */ *)0x0) {

                puVar13 = (uint32_t /* width from decompiler */ *)0x0;

              }

              else {

                puVar13[1] = 5;

                puVar13[0xd] = 0;

                puVar13[0xc] = 0;

                puVar13[0xb] = 0;

                puVar13[3] = 0;

                puVar13[4] = 0;

                puVar13[5] = 0;

                puVar13[7] = 0;

                puVar13[8] = 0;

                puVar13[9] = 0;

                puVar13[2] = fVar21;

                puVar13[6] = fVar21;

                puVar13[10] = fVar21;

                puVar13[3] = 0;

                puVar13[4] = 0;

                puVar13[5] = 0;

                puVar13[7] = 0;

                puVar13[8] = 0;

                puVar13[9] = 0;

                puVar13[2] = fVar21;

                puVar13[6] = fVar21;

                puVar13[10] = fVar21;

                puVar13[0xd] = 0;

                puVar13[0xc] = 0;

                puVar13[0xb] = 0;

                *puVar13 = &PTR_FUN_009cb228;

                puVar13[3] = 0;

                puVar13[4] = 0;

                puVar13[5] = 0;

                puVar13[7] = 0;

                puVar13[8] = 0;

                puVar13[9] = 0;

                puVar13[2] = fVar21;

                puVar13[6] = fVar21;

                puVar13[10] = fVar21;

                puVar13[0xd] = 0;

                puVar13[0xc] = 0;

                puVar13[0xb] = 0;

                uVar5 = DAT_00aaa668;

                puVar13[0xe] = 8;

                *(uint16_t *)(puVar13 + 0xf) = 0;

                *(uint16_t *)((int)puVar13 + 0x3e) = 0;

                puVar13[0x10] = 0;

                puVar13[0x13] = uVar5;

                puVar13[0x11] = fVar21;

                puVar13[0x12] = uVar5;

                puVar13[0x14] = 0;

                puVar13[0x15] = 0;

                puVar13[0x16] = 0;

                puVar13[0x17] = 0;

                puVar13[0x18] = 0;

                puVar13[0x19] = 0;

                puVar13[0x1a] = 0;

                puVar13[0x1b] = 0;

              }

              FUN_005c6610();

              uStack_4._0_1_ = 7;

              uVar5 = (**(code **)(*param_3 + 0x3c))();

              puVar13[0x1a] = uVar5;

              uStack_4._0_1_ = 6;

              FUN_005c6630();

              if (puVar13[0x1a] == 0) {

                uStack_4 = CONCAT31(uStack_4._1_3_,5);

                FUN_005c65e0();

                goto LAB_005edd4c;

              }

              FUN_005eced0();

              uStack_4._0_1_ = 5;

              FUN_005c65e0();

              iVar20 = iVar20 + 1;

              piVar17 = piVar17 + 4;

            } while (iVar20 < 2);

            uStack_4 = CONCAT31(uStack_4._1_3_,3);

            _eh_vector_destructor_iterator_(aiStack_4c,0x10,2,FUN_005ee000);

            if (pfStack_114 != (float *)0x0) {

              free(pfStack_114);

            }

            pfStack_114 = (float *)0x0;

            pfStack_110 = (float *)0x0;

            pfStack_10c = (float *)0x0;

            if (pvStack_d0 != (void *)0x0) {

              free(pvStack_d0);

            }

            pvStack_d0 = (void *)0x0;

            iStack_cc = 0;

            uStack_c8 = 0;

            if (pvStack_e4 != (void *)0x0) {

              free(pvStack_e4);

            }

            pvStack_e4 = (void *)0x0;

            uStack_e0 = 0;

            uStack_dc = 0;

            uStack_4 = 0xffffffff;

            fVar21 = local_104;

            param_1 = local_b8;

            if (pvStack_f8 != (void *)0x0) {

              free(pvStack_f8);

              fVar21 = local_104;

              param_1 = local_b8;

            }

          }

          local_104 = (float)((int)fVar21 + 1);

          pvStack_f8 = (void *)0x0;

          uStack_f4 = 0;

          uStack_f0 = 0;

        } while ((uint)local_104 < (uint)fStack_88);

      }

    }

  }

  else {

    if (*(uint *)(param_1 + 0x58) <= *(uint *)(param_1 + 0x54)) {

      iVar20 = *(int *)(param_1 + 0x50);

      uVar7 = ((int)(*(uint *)(param_1 + 0x54) - iVar20) >> 2) * 2 + 2;

      if (iVar20 == 0) {

        uVar16 = 0;

      }

      else {

        uVar16 = (int)(*(uint *)(param_1 + 0x58) - iVar20) >> 2;

      }

      if (uVar16 < uVar7) {

        fVar21 = (float)(uVar7 * 4);

        ExceptionList = &local_c;

        local_104 = fVar21;

        puVar3 = malloc((size_t)fVar21);

        puVar13 = *(uint32_t /* width from decompiler */ **)(param_1 + 0x54);

        puVar14 = puVar3;

        for (puVar4 = *(uint32_t /* width from decompiler */ **)(param_1 + 0x50); puVar4 != puVar13; puVar4 = puVar4 + 1) {

          *puVar14 = *puVar4;

          puVar14 = puVar14 + 1;

          fVar21 = local_104;

        }

        if (*(void **)(param_1 + 0x50) != (void *)0x0) {

          free(*(void **)(param_1 + 0x50));

        }

        *(int *)(param_1 + 0x58) = (int)puVar3 + (int)fVar21;

        *(uint32_t /* width from decompiler */ **)(param_1 + 0x54) =

             puVar3 + (*(int *)(param_1 + 0x54) - *(int *)(param_1 + 0x50) >> 2);

        *(uint32_t /* width from decompiler */ **)(param_1 + 0x50) = puVar3;

      }

    }

    **(int **)(param_1 + 0x54) = param_2;

    *(int *)(param_1 + 0x54) = *(int *)(param_1 + 0x54) + 4;

  }

  ExceptionList = local_c;

  return;

}
