// =============================================================================
// FUN_0070b470
// -----------------------------------------------------------------------------
// Stable ID: aa_0070b470
// Address:   0x0070b470  (autoassault.exe, image base 0x400000)
// System:    unknown
// Generated: 2026-07-23 from raw capture (scaffold; refine for important units)
// Exactness: Behavior-preserving rewrite of decompiler control flow. Not modernization.
// Bit-for-bit vs retail EXE: DEFERRED (loaded image may differ slightly).
// =============================================================================

// PURPOSE (auto): Scaffold unit for FUN_0070b470 @ 0x0070b470
// Stable ID: aa_0070b470
// No high-value strings recovered; name via xrefs/callers in follow-up.
// Readability: control flow preserved from Ghidra decompile; types tentative.

// READABILITY (auto CF):
//  - Body size: ~688 non-empty decompiler lines.
//  - Control keywords: if×51, do×44, while×44, for×7, goto×3, return×1.
//  - Notable callees: FUN_00702bb0, FUN_0070b470, FUN_0070e910, FUN_00710190, FUN_007103c0.
//  - Return sites: 1.

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

/* WARNING: Globals starting with '_' overlap smaller symbols at the same address */



void FUN_0070b470(int param_1,uint32_t /* width from decompiler */ param_2,uint32_t /* width from decompiler */ param_3,uint32_t /* width from decompiler */ param_4,int *param_5,

                 uint32_t /* width from decompiler */ param_6,int param_7,int param_8,int param_9,uint32_t /* width from decompiler */ param_10,

                 int param_11,int param_12)



{

  char *pcVar1;

  char *pcVar2;

  char *pcVar3;

  float fVar4;

  float fVar5;

  int iVar6;

  uint32_t /* width from decompiler */ uVar7;

  int iVar8;

  int iVar9;

  uint32_t /* width from decompiler */ *puVar10;

  int iVar11;

  float *pfVar12;

  int iVar13;

  int iVar14;

  int iVar15;

  float *pfVar16;

  int *piVar17;

  uint32_t /* width from decompiler */ *puVar18;

  int *piVar19;

  int *piVar20;

  int iVar21;

  float *pfVar22;

  int iVar23;

  float *pfVar24;

  int iVar25;

  int *piVar26;

  uint32_t /* width from decompiler */ *puVar27;

  uint32_t /* width from decompiler */ *puVar28;

  int *piVar29;

  int iVar30;

  int iVar31;

  int iVar32;

  int iVar33;

  int iVar34;

  int iVar35;

  int iVar36;

  int iVar37;

  int local_74;

  int local_70;

  int local_6c;

  int *local_64;

  int local_60;

  int *local_54;

  float *local_44;

  int local_2c;

  float *local_28;

  int local_24;

  int local_20;

  int local_14;

  

  local_74 = param_12;

  if (10 < param_12) {

    local_74 = 10;

  }

  iVar34 = local_74 * 4;

  param_11 = param_11 + (-param_11 & 3U) + iVar34;

  local_54 = (int *)(param_11 + local_74 * -4);

  param_11 = param_11 + (-param_11 & 3U) + iVar34;

  iVar35 = param_11 + (-param_11 & 3U) + iVar34;

  piVar19 = (int *)(iVar35 + local_74 * -4);

  iVar35 = iVar35 + (-iVar35 & 3U) + iVar34;

  local_64 = (int *)(param_11 + local_74 * -4);

  piVar20 = (int *)(iVar35 + local_74 * -4);

  iVar34 = *param_5;

  iVar30 = param_5[1];

  iVar31 = 1 << ((byte)param_5[3] & 0x1f);

  iVar6 = param_5[2];

  iVar37 = param_5[4];

  iVar35 = iVar35 + (-iVar35 & 3U) + iVar31 * iVar34 * 4;

  iVar21 = iVar35 + iVar31 * iVar34 * -4;

  iVar8 = param_7 * 4;

  iVar35 = iVar35 + (-iVar35 & 3U) + iVar8;

  iVar36 = iVar35 + (-iVar35 & 3U) + iVar8;

  pfVar22 = (float *)(iVar36 + param_7 * -4);

  iVar35 = iVar35 + param_7 * -4;

  iVar36 = iVar36 + (-iVar36 & 3U) + iVar8;

  iVar23 = iVar36 + param_7 * -4;

  iVar36 = iVar36 + (-iVar36 & 3U) + iVar31 * 4;

  pfVar24 = (float *)(iVar36 + iVar31 * -4);

  iVar36 = iVar36 + (-iVar36 & 3U) + iVar30 * 4;

  iVar25 = iVar36 + iVar30 * -4;

  iVar36 = iVar36 + (-iVar36 & 3U) + local_74 * param_7 * 8;

  iVar32 = iVar36 + local_74 * param_7 * -8;

  if (0 < local_74) {

    piVar26 = local_64;

    local_24 = local_74;

    do {

      *(int *)(((int)local_54 - (int)local_64) + (int)piVar26) = iVar32;

      *piVar26 = iVar32 + iVar8;

      iVar32 = iVar32 + iVar8 + iVar8;

      piVar26 = piVar26 + 1;

      local_24 = local_24 + -1;

    } while (local_24 != 0);

  }

  iVar8 = local_74 * 4;

  iVar36 = iVar36 + (-iVar36 & 3U) + iVar8;

  piVar26 = (int *)(iVar36 + local_74 * -4);

  iVar36 = iVar36 + (-iVar36 & 3U) + iVar8;

  iVar32 = iVar36 + local_74 * -4;

  iVar36 = iVar36 + (-iVar36 & 3U) + iVar8;

  puVar27 = (uint32_t /* width from decompiler */ *)(iVar36 + local_74 * -4);

  iVar36 = iVar36 + (-iVar36 & 3U) + iVar8;

  puVar28 = (uint32_t /* width from decompiler */ *)(iVar36 + local_74 * -4);

  iVar36 = iVar36 + (-iVar36 & 3U) + iVar30 * local_74 * 8;

  iVar8 = iVar36 + iVar30 * local_74 * -8;

  if (0 < local_74) {

    piVar29 = piVar20;

    local_28 = (float *)local_74;

    do {

      *piVar29 = iVar8;

      iVar8 = iVar8 + iVar30 * 4;

      *(int *)(((int)piVar19 - (int)piVar20) + (int)piVar29) = iVar8;

      iVar8 = iVar8 + iVar30 * 4;

      iVar9 = 0;

      if (0 < iVar30) {

        do {

          *(uint32_t /* width from decompiler */ *)(*(int *)(((int)piVar19 - (int)piVar20) + (int)piVar29) + iVar9 * 4) =

               0xffffffff;

          *(uint32_t /* width from decompiler */ *)(*piVar29 + iVar9 * 4) = 0xffffffff;

          iVar9 = iVar9 + 1;

        } while (iVar9 < iVar30);

      }

      piVar29 = piVar29 + 1;

      local_28 = (float *)((int)local_28 + -1);

    } while (local_28 != (float *)0x0);

  }

  iVar8 = 0;

  if (3 < param_7) {

    puVar18 = (uint32_t /* width from decompiler */ *)(param_1 + 0xc);

    iVar9 = (param_7 - 4U >> 2) + 1;

    iVar8 = iVar9 * 4;

    puVar10 = (uint32_t /* width from decompiler */ *)(iVar35 + 4);

    do {

      puVar10[-1] = puVar18[-3];

      *puVar10 = *(uint32_t /* width from decompiler */ *)((param_1 - iVar35) + (int)puVar10);

      puVar10[1] = puVar18[-1];

      puVar10[2] = *puVar18;

      puVar10 = puVar10 + 4;

      puVar18 = puVar18 + 4;

      iVar9 = iVar9 + -1;

    } while (iVar9 != 0);

  }

  if (iVar8 < param_7) {

    puVar18 = (uint32_t /* width from decompiler */ *)(iVar35 + iVar8 * 4);

    iVar8 = param_7 - iVar8;

    do {

      *puVar18 = *(uint32_t /* width from decompiler */ *)((int)puVar18 + (param_1 - iVar35));

      puVar18 = puVar18 + 1;

      iVar8 = iVar8 + -1;

    } while (iVar8 != 0);

  }

  if (0 < local_74) {

    local_44 = (float *)local_74;

    piVar29 = local_54;

    do {

      iVar8 = 0;

      if (3 < param_7) {

        iVar9 = (param_7 - 4U >> 2) + 1;

        iVar8 = iVar9 * 4;

        local_2c = 8;

        puVar18 = (uint32_t /* width from decompiler */ *)(iVar35 + 8);

        do {

          *(uint32_t /* width from decompiler */ *)((int)puVar18 + *piVar29 + (-8 - iVar35)) = puVar18[-2];

          *(uint32_t /* width from decompiler */ *)((int)puVar18 + *piVar29 + 4 + (-8 - iVar35)) = puVar18[-1];

          *(uint32_t /* width from decompiler */ *)(local_2c + *piVar29) = *puVar18;

          *(uint32_t /* width from decompiler */ *)(*piVar29 + (4 - iVar35) + (int)puVar18) = puVar18[1];

          local_2c = local_2c + 0x10;

          puVar18 = puVar18 + 4;

          iVar9 = iVar9 + -1;

        } while (iVar9 != 0);

      }

      for (; iVar8 < param_7; iVar8 = iVar8 + 1) {

        *(uint32_t /* width from decompiler */ *)(*piVar29 + iVar8 * 4) = *(uint32_t /* width from decompiler */ *)(iVar35 + iVar8 * 4);

      }

      piVar29 = piVar29 + 1;

      local_44 = (float *)((int)local_44 + -1);

    } while (local_44 != (float *)0x0);

  }

  pfVar16 = pfVar24;

  iVar8 = iVar6;

  local_60 = iVar21;

  local_24 = iVar31;

  if (0 < iVar31) {

    do {

      iVar9 = 0;

      if (0 < iVar34) {

        local_44 = (float *)(param_9 + -8);

        do {

          iVar11 = 0;

          pfVar12 = local_44;

          fVar4 = g_flZero;

          if (3 < iVar9 + 1) {

            do {

              pcVar1 = (char *)(iVar8 + iVar11);

              pcVar2 = (char *)(iVar8 + 1 + iVar11);

              pcVar3 = (char *)(iVar8 + 2 + iVar11);

              iVar11 = iVar11 + 4;

              fVar4 = (float)(int)*(char *)(iVar8 + -1 + iVar11) * pfVar12[-1] +

                      (float)(int)*pcVar3 * *pfVar12 +

                      (float)(int)*pcVar2 * pfVar12[1] + (float)(int)*pcVar1 * pfVar12[2] + fVar4;

              pfVar12 = pfVar12 + -4;

            } while (iVar11 <= iVar9 + -3);

          }

          if (iVar11 <= iVar9) {

            pfVar12 = (float *)(param_9 + (iVar9 - iVar11) * 4);

            do {

              pcVar1 = (char *)(iVar8 + iVar11);

              iVar11 = iVar11 + 1;

              fVar4 = (float)(int)*pcVar1 * *pfVar12 + fVar4;

              pfVar12 = pfVar12 + -1;

            } while (iVar11 <= iVar9);

          }

          iVar9 = iVar9 + 1;

          *(float *)(local_60 + -4 + iVar9 * 4) = fVar4 * (float)_DAT_00a0f258;

          local_44 = local_44 + 1;

        } while (iVar9 < iVar34);

      }

      iVar9 = 0;

      *pfVar16 = 0.0;

      if (3 < iVar34) {

        iVar11 = (iVar34 - 4U >> 2) + 1;

        iVar9 = iVar11 * 4;

        pfVar12 = (float *)(local_60 + 8);

        do {

          iVar11 = iVar11 + -1;

          fVar4 = pfVar12[-2] * pfVar12[-2] + *pfVar16;

          *pfVar16 = fVar4;

          fVar4 = pfVar12[-1] * pfVar12[-1] + fVar4;

          *pfVar16 = fVar4;

          fVar4 = *pfVar12 * *pfVar12 + fVar4;

          *pfVar16 = fVar4;

          *pfVar16 = pfVar12[1] * pfVar12[1] + fVar4;

          pfVar12 = pfVar12 + 4;

        } while (iVar11 != 0);

      }

      for (; iVar9 < iVar34; iVar9 = iVar9 + 1) {

        fVar4 = *(float *)(local_60 + iVar9 * 4);

        *pfVar16 = fVar4 * fVar4 + *pfVar16;

      }

      local_24 = local_24 + -1;

      pfVar16 = pfVar16 + 1;

      iVar8 = iVar8 + iVar34;

      local_60 = local_60 + iVar34 * 4;

    } while (local_24 != 0);

  }

  iVar8 = local_74;

  puVar18 = puVar28;

  if (0 < local_74) {

    for (; iVar8 != 0; iVar8 = iVar8 + -1) {

      *puVar18 = 0;

      puVar18 = puVar18 + 1;

    }

  }

  local_70 = 0;

  if (0 < iVar30) {

    do {

      piVar29 = local_54;

      iVar8 = local_74;

      puVar18 = puVar27;

      if (0 < local_74) {

        for (; iVar8 != 0; iVar8 = iVar8 + -1) {

          *puVar18 = 0xc0000000;

          puVar18 = puVar18 + 1;

        }

      }

      local_6c = 0;

      if (0 < local_74) {

        iVar8 = local_70 * iVar34;

        iVar9 = (local_70 + 1) * iVar34;

        do {

          iVar11 = local_54[local_6c] + iVar8 * 4;

          if (iVar37 == 0) {

            FUN_00710190(iVar11,iVar21,iVar34,iVar31,pfVar24,local_74,piVar26,iVar32);

          }

          else {

            FUN_007103c0(iVar11,iVar21,iVar34,iVar31,pfVar24,local_74,piVar26,iVar32);

          }

          local_14 = local_74;

          local_44 = (float *)piVar26;

          do {

            iVar14 = local_54[local_6c];

            iVar11 = iVar8;

            if (3 < iVar9 - iVar8) {

              puVar18 = (uint32_t /* width from decompiler */ *)(iVar14 + 0xc + iVar8 * 4);

              iVar13 = ((iVar9 - iVar8) - 4U >> 2) + 1;

              puVar10 = (uint32_t /* width from decompiler */ *)(iVar35 + 4 + iVar8 * 4);

              iVar11 = iVar8 + iVar13 * 4;

              do {

                puVar10[-1] = puVar18[-3];

                *puVar10 = *(uint32_t /* width from decompiler */ *)((iVar14 - iVar35) + (int)puVar10);

                puVar10[1] = puVar18[-1];

                puVar10[2] = *puVar18;

                puVar10 = puVar10 + 4;

                puVar18 = puVar18 + 4;

                iVar13 = iVar13 + -1;

              } while (iVar13 != 0);

            }

            if (iVar11 < iVar9) {

              puVar18 = (uint32_t /* width from decompiler */ *)(iVar35 + iVar11 * 4);

              iVar11 = iVar9 - iVar11;

              do {

                *puVar18 = *(uint32_t /* width from decompiler */ *)((int)puVar18 + (iVar14 - iVar35));

                puVar18 = puVar18 + 1;

                iVar11 = iVar11 + -1;

              } while (iVar11 != 0);

            }

            iVar11 = (int)*local_44;

            fVar4 = g_flOne;

            if (iVar31 <= iVar11) {

              iVar11 = iVar11 - iVar31;

              fVar4 = DAT_00aaa668;

            }

            iVar11 = iVar21 + iVar11 * iVar34 * 4;

            iVar13 = 0;

            if (fVar4 <= g_flZero) {

              if (3 < iVar34) {

                iVar33 = (iVar34 - 4U >> 2) + 1;

                iVar13 = iVar33 * 4;

                pfVar16 = (float *)(iVar8 * 4 + iVar35);

                pfVar12 = (float *)(iVar11 + 8);

                do {

                  iVar33 = iVar33 + -1;

                  *pfVar16 = pfVar12[-2] + *pfVar16;

                  pfVar16[1] = pfVar12[-1] + pfVar16[1];

                  pfVar16[2] = *pfVar12 + pfVar16[2];

                  pfVar16[3] = pfVar12[1] + pfVar16[3];

                  pfVar16 = pfVar16 + 4;

                  pfVar12 = pfVar12 + 4;

                } while (iVar33 != 0);

              }

              if (iVar13 < iVar34) {

                pfVar16 = (float *)(iVar35 + (iVar8 + iVar13) * 4);

                do {

                  iVar33 = iVar13 * 4;

                  iVar13 = iVar13 + 1;

                  *pfVar16 = *(float *)(iVar11 + iVar33) + *pfVar16;

                  pfVar16 = pfVar16 + 1;

                } while (iVar13 < iVar34);

              }

            }

            else {

              if (3 < iVar34) {

                iVar33 = (iVar34 - 4U >> 2) + 1;

                iVar13 = iVar33 * 4;

                pfVar16 = (float *)(iVar8 * 4 + iVar35);

                pfVar12 = (float *)(iVar11 + 8);

                do {

                  iVar33 = iVar33 + -1;

                  *pfVar16 = *pfVar16 - pfVar12[-2];

                  pfVar16[1] = pfVar16[1] - pfVar12[-1];

                  pfVar16[2] = pfVar16[2] - *pfVar12;

                  pfVar16[3] = pfVar16[3] - pfVar12[1];

                  pfVar16 = pfVar16 + 4;

                  pfVar12 = pfVar12 + 4;

                } while (iVar33 != 0);

              }

              if (iVar13 < iVar34) {

                pfVar16 = (float *)(iVar35 + (iVar8 + iVar13) * 4);

                do {

                  iVar13 = iVar13 + 1;

                  *pfVar16 = *pfVar16 - *(float *)(iVar11 + -4 + iVar13 * 4);

                  pfVar16 = pfVar16 + 1;

                } while (iVar13 < iVar34);

              }

            }

            fVar4 = (float)puVar28[local_6c];

            iVar11 = iVar8;

            if (3 < iVar9 - iVar8) {

              iVar13 = ((iVar9 - iVar8) - 4U >> 2) + 1;

              iVar11 = iVar8 + iVar13 * 4;

              pfVar16 = (float *)(iVar35 + 8 + iVar8 * 4);

              do {

                iVar13 = iVar13 + -1;

                fVar4 = pfVar16[1] * pfVar16[1] +

                        *pfVar16 * *pfVar16 +

                        pfVar16[-1] * pfVar16[-1] + pfVar16[-2] * pfVar16[-2] + fVar4;

                pfVar16 = pfVar16 + 4;

              } while (iVar13 != 0);

            }

            for (; iVar11 < iVar9; iVar11 = iVar11 + 1) {

              fVar5 = *(float *)(iVar35 + iVar11 * 4);

              fVar4 = fVar5 * fVar5 + fVar4;

            }

            if ((fVar4 < (float)puVar27[local_74 + -1]) ||

               ((float)puVar27[local_74 + -1] < DAT_00aaa668)) {

              iVar13 = param_7 - iVar9;

              iVar11 = iVar9;

              if (3 < iVar13) {

                puVar18 = (uint32_t /* width from decompiler */ *)(iVar14 + 0xc + iVar9 * 4);

                iVar33 = ((param_7 - iVar9) - 4U >> 2) + 1;

                puVar10 = (uint32_t /* width from decompiler */ *)(iVar35 + 4 + iVar9 * 4);

                iVar11 = iVar9 + iVar33 * 4;

                do {

                  puVar10[-1] = puVar18[-3];

                  *puVar10 = *(uint32_t /* width from decompiler */ *)((int)puVar10 + (iVar14 - iVar35));

                  puVar10[1] = puVar18[-1];

                  puVar10[2] = *puVar18;

                  puVar10 = puVar10 + 4;

                  puVar18 = puVar18 + 4;

                  iVar33 = iVar33 + -1;

                } while (iVar33 != 0);

              }

              if (iVar11 < param_7) {

                puVar18 = (uint32_t /* width from decompiler */ *)(iVar35 + iVar11 * 4);

                iVar11 = param_7 - iVar11;

                do {

                  *puVar18 = *(uint32_t /* width from decompiler */ *)((int)puVar18 + (iVar14 - iVar35));

                  puVar18 = puVar18 + 1;

                  iVar11 = iVar11 + -1;

                } while (iVar11 != 0);

              }

              local_2c = 0;

              if (0 < iVar34) {

                local_28 = (float *)(param_9 + 8 + iVar34 * 4);

                iVar11 = iVar34;

                do {

                  iVar14 = (int)*local_44;

                  fVar5 = g_flOne;

                  if (iVar31 <= iVar14) {

                    iVar14 = iVar14 - iVar31;

                    fVar5 = DAT_00aaa668;

                  }

                  fVar5 = (float)(int)*(char *)(iVar14 * iVar34 + local_2c + iVar6) * fVar5 *

                          (float)_DAT_00a0f258;

                  iVar33 = iVar9;

                  iVar14 = iVar11;

                  if (3 < iVar13) {

                    iVar15 = ((param_7 - iVar9) - 4U >> 2) + 1;

                    iVar14 = iVar15 * 4 + iVar11;

                    iVar33 = iVar9 + iVar15 * 4;

                    pfVar16 = (float *)(iVar35 + 8 + iVar9 * 4);

                    pfVar12 = local_28;

                    do {

                      iVar15 = iVar15 + -1;

                      pfVar16[-2] = pfVar16[-2] - fVar5 * pfVar12[-2];

                      pfVar16[-1] = pfVar16[-1] - fVar5 * pfVar12[-1];

                      *pfVar16 = *pfVar16 - fVar5 * *pfVar12;

                      pfVar16[1] = pfVar16[1] - fVar5 * pfVar12[1];

                      pfVar16 = pfVar16 + 4;

                      pfVar12 = pfVar12 + 4;

                    } while (iVar15 != 0);

                  }

                  if (iVar33 < param_7) {

                    pfVar16 = (float *)(param_9 + iVar14 * 4);

                    do {

                      iVar33 = iVar33 + 1;

                      *(float *)(iVar35 + -4 + iVar33 * 4) =

                           *(float *)(iVar35 + -4 + iVar33 * 4) - fVar5 * *pfVar16;

                      pfVar16 = pfVar16 + 1;

                    } while (iVar33 < param_7);

                  }

                  local_2c = local_2c + 1;

                  local_28 = local_28 + -1;

                  iVar11 = iVar11 + -1;

                } while (local_2c < iVar34);

              }

              iVar11 = 0;

LAB_0070bf18:

              if (((float)puVar27[iVar11] <= fVar4) && (DAT_00aaa668 <= (float)puVar27[iVar11]))

              goto code_r0x0070bf3a;

              iVar14 = local_74 + -1;

              if (iVar11 < iVar14) {

                piVar17 = local_64 + local_74 + -2;

                puVar18 = puVar27 + iVar14;

                local_28 = (float *)(iVar14 - iVar11);

                do {

                  iVar14 = iVar9;

                  if (3 < iVar13) {

                    do {

                      *(uint32_t /* width from decompiler */ *)(piVar17[1] + iVar14 * 4) =

                           *(uint32_t /* width from decompiler */ *)(*piVar17 + iVar14 * 4);

                      *(uint32_t /* width from decompiler */ *)(piVar17[1] + 4 + iVar14 * 4) =

                           *(uint32_t /* width from decompiler */ *)(*piVar17 + 4 + iVar14 * 4);

                      *(uint32_t /* width from decompiler */ *)(piVar17[1] + 8 + iVar14 * 4) =

                           *(uint32_t /* width from decompiler */ *)(*piVar17 + 8 + iVar14 * 4);

                      *(uint32_t /* width from decompiler */ *)(piVar17[1] + 0xc + iVar14 * 4) =

                           *(uint32_t /* width from decompiler */ *)(*piVar17 + 0xc + iVar14 * 4);

                      iVar14 = iVar14 + 4;

                    } while (iVar14 < param_7 + -3);

                  }

                  for (; iVar14 < param_7; iVar14 = iVar14 + 1) {

                    *(uint32_t /* width from decompiler */ *)(piVar17[1] + iVar14 * 4) =

                         *(uint32_t /* width from decompiler */ *)(*piVar17 + iVar14 * 4);

                  }

                  iVar14 = 0;

                  do {

                    *(uint32_t /* width from decompiler */ *)

                     (*(int *)(((int)piVar20 - (int)puVar27) + (int)puVar18) + iVar14 * 4) =

                         *(uint32_t /* width from decompiler */ *)

                          (*(int *)(((int)piVar20 - (int)local_64) + (int)piVar17) + iVar14 * 4);

                    iVar14 = iVar14 + 1;

                  } while (iVar14 < iVar30);

                  *puVar18 = *(uint32_t /* width from decompiler */ *)(((int)puVar27 - (int)local_64) + (int)piVar17);

                  piVar17 = piVar17 + -1;

                  puVar18 = puVar18 + -1;

                  local_28 = (float *)((int)local_28 + -1);

                } while (local_28 != (float *)0x0);

              }

              iVar14 = iVar9;

              if (3 < iVar13) {

                local_2c = iVar9 * 4 + 8;

                puVar18 = (uint32_t /* width from decompiler */ *)(local_2c + iVar35);

                iVar13 = ((param_7 - iVar9) - 4U >> 2) + 1;

                iVar14 = iVar9 + iVar13 * 4;

                do {

                  *(uint32_t /* width from decompiler */ *)((int)puVar18 + local_64[iVar11] + (-8 - iVar35)) = puVar18[-2];

                  *(uint32_t /* width from decompiler */ *)((int)puVar18 + local_64[iVar11] + 4 + (-8 - iVar35)) = puVar18[-1]

                  ;

                  *(uint32_t /* width from decompiler */ *)(local_64[iVar11] + local_2c) = *puVar18;

                  *(uint32_t /* width from decompiler */ *)((int)puVar18 + (4 - iVar35) + local_64[iVar11]) = puVar18[1];

                  local_2c = local_2c + 0x10;

                  puVar18 = puVar18 + 4;

                  iVar13 = iVar13 + -1;

                } while (iVar13 != 0);

              }

              for (; iVar14 < param_7; iVar14 = iVar14 + 1) {

                *(uint32_t /* width from decompiler */ *)(local_64[iVar11] + iVar14 * 4) =

                     *(uint32_t /* width from decompiler */ *)(iVar35 + iVar14 * 4);

              }

              iVar14 = 0;

              do {

                *(uint32_t /* width from decompiler */ *)(piVar20[iVar11] + iVar14 * 4) =

                     *(uint32_t /* width from decompiler */ *)(piVar19[local_6c] + iVar14 * 4);

                iVar14 = iVar14 + 1;

              } while (iVar14 < iVar30);

              *(float *)(piVar20[iVar11] + local_70 * 4) = *local_44;

              puVar27[iVar11] = fVar4;

            }

LAB_0070bf4c:

            local_44 = local_44 + 1;

            local_14 = local_14 + -1;

          } while (local_14 != 0);

        } while ((local_70 != 0) && (local_6c = local_6c + 1, local_6c < local_74));

      }

      local_54 = local_64;

      local_64 = piVar29;

      if (0 < local_74) {

        local_14 = local_74;

        piVar29 = piVar19;

        do {

          iVar8 = 0;

          do {

            *(uint32_t /* width from decompiler */ *)(*piVar29 + iVar8 * 4) =

                 *(uint32_t /* width from decompiler */ *)(*(int *)(((int)piVar20 - (int)piVar19) + (int)piVar29) + iVar8 * 4)

            ;

            iVar8 = iVar8 + 1;

          } while (iVar8 < iVar30);

          piVar29 = piVar29 + 1;

          local_14 = local_14 + -1;

        } while (local_14 != 0);

      }

      iVar8 = 0;

      if (3 < local_74) {

        puVar18 = puVar28 + 1;

        puVar10 = puVar27 + 3;

        iVar9 = (local_74 - 4U >> 2) + 1;

        iVar8 = iVar9 * 4;

        do {

          puVar18[-1] = puVar10[-3];

          *puVar18 = *(uint32_t /* width from decompiler */ *)(((int)puVar27 - (int)puVar28) + (int)puVar18);

          puVar18[1] = puVar10[-1];

          puVar18[2] = *puVar10;

          puVar18 = puVar18 + 4;

          puVar10 = puVar10 + 4;

          iVar9 = iVar9 + -1;

        } while (iVar9 != 0);

      }

      if (iVar8 < local_74) {

        puVar18 = puVar28 + iVar8;

        iVar8 = local_74 - iVar8;

        do {

          *puVar18 = *(uint32_t /* width from decompiler */ *)((int)puVar18 + ((int)puVar27 - (int)puVar28));

          puVar18 = puVar18 + 1;

          iVar8 = iVar8 + -1;

        } while (iVar8 != 0);

      }

      local_70 = local_70 + 1;

    } while (local_70 < iVar30);

  }

  iVar8 = 0;

  if (0 < iVar30) {

    do {

      uVar7 = *(uint32_t /* width from decompiler */ *)(*piVar20 + iVar8 * 4);

      *(uint32_t /* width from decompiler */ *)(iVar25 + iVar8 * 4) = uVar7;

      FUN_00702bb0(param_10,uVar7,param_5[3] + iVar37);

      iVar8 = iVar8 + 1;

    } while (iVar8 < iVar30);

  }

  local_70 = 0;

  if (0 < iVar30) {

    local_20 = 0;

    pfVar24 = pfVar22;

    do {

      iVar37 = *(int *)(iVar25 + local_70 * 4);

      fVar4 = g_flOne;

      if (iVar31 <= iVar37) {

        iVar37 = iVar37 - iVar31;

        fVar4 = DAT_00aaa668;

      }

      iVar8 = 0;

      if (3 < iVar34) {

        iVar21 = iVar37 * iVar34 + 1 + iVar6;

        pfVar16 = pfVar24;

        do {

          pcVar1 = (char *)(iVar21 + -1 + iVar8);

          iVar8 = iVar8 + 4;

          *pfVar16 = (float)(int)*pcVar1 * fVar4 * (float)_DAT_00a0f258;

          pfVar16[1] = (float)(int)*(char *)(iVar21 + -4 + iVar8) * fVar4 * (float)_DAT_00a0f258;

          pfVar16[2] = (float)(int)*(char *)(iVar21 + -3 + iVar8) * fVar4 * (float)_DAT_00a0f258;

          pfVar16[3] = (float)(int)*(char *)(iVar21 + -2 + iVar8) * fVar4 * (float)_DAT_00a0f258;

          pfVar16 = pfVar16 + 4;

        } while (iVar8 < iVar34 + -3);

      }

      if (iVar8 < iVar34) {

        pfVar16 = pfVar22 + local_20 + iVar8;

        do {

          pcVar1 = (char *)(iVar37 * iVar34 + iVar6 + iVar8);

          iVar8 = iVar8 + 1;

          *pfVar16 = (float)(int)*pcVar1 * fVar4 * (float)_DAT_00a0f258;

          pfVar16 = pfVar16 + 1;

        } while (iVar8 < iVar34);

      }

      pfVar24 = pfVar24 + iVar34;

      local_70 = local_70 + 1;

      local_20 = local_20 + iVar34;

    } while (local_70 < iVar30);

  }

  iVar34 = 0;

  if (3 < param_7) {

    iVar30 = (param_7 - 4U >> 2) + 1;

    iVar34 = iVar30 * 4;

    pfVar24 = (float *)(param_8 + 4);

    pfVar16 = pfVar22 + 3;

    do {

      iVar30 = iVar30 + -1;

      pfVar24[-1] = pfVar16[-3] + pfVar24[-1];

      *pfVar24 = *(float *)((int)pfVar22 + (-0x10 - param_8) + (int)(pfVar24 + 4)) + *pfVar24;

      pfVar24[1] = pfVar16[-1] + pfVar24[1];

      pfVar24[2] = *pfVar16 + pfVar24[2];

      pfVar24 = pfVar24 + 4;

      pfVar16 = pfVar16 + 4;

    } while (iVar30 != 0);

  }

  if (iVar34 < param_7) {

    iVar30 = param_7 - iVar34;

    pfVar24 = (float *)(param_8 + iVar34 * 4);

    do {

      iVar30 = iVar30 + -1;

      *pfVar24 = *(float *)((int)pfVar24 + ((int)pfVar22 - param_8)) + *pfVar24;

      pfVar24 = pfVar24 + 1;

    } while (iVar30 != 0);

  }

  FUN_0070e910(pfVar22,param_2,param_3,param_4,iVar23,param_7,param_6,iVar36);

  iVar34 = 0;

  if (3 < param_7) {

    iVar30 = (param_7 - 4U >> 2) + 1;

    iVar34 = iVar30 * 4;

    pfVar22 = (float *)(param_1 + 4);

    pfVar24 = (float *)(iVar23 + 0xc);

    do {

      iVar30 = iVar30 + -1;

      pfVar22[-1] = pfVar22[-1] - pfVar24[-3];

      *pfVar22 = *pfVar22 - *(float *)((iVar23 - param_1) + -0x10 + (int)(pfVar22 + 4));

      pfVar22[1] = pfVar22[1] - pfVar24[-1];

      pfVar22[2] = pfVar22[2] - *pfVar24;

      pfVar22 = pfVar22 + 4;

      pfVar24 = pfVar24 + 4;

    } while (iVar30 != 0);

  }

  if (iVar34 < param_7) {

    param_7 = param_7 - iVar34;

    pfVar22 = (float *)(param_1 + iVar34 * 4);

    do {

      param_7 = param_7 + -1;

      *pfVar22 = *pfVar22 - *(float *)((int)pfVar22 + (iVar23 - param_1));

      pfVar22 = pfVar22 + 1;

    } while (param_7 != 0);

  }

  return;

code_r0x0070bf3a:

  iVar11 = iVar11 + 1;

  if (local_74 <= iVar11) goto LAB_0070bf4c;

  goto LAB_0070bf18;

}
