// READABILITY (auto CF):
//  - Body size: ~367 non-empty decompiler lines.
//  - Control keywords: if×39, while×8, do×6, for×6, return×5, switch×1.
//  - Notable callees: FUN_00746520×3, vog_LogMessage×2, FUN_00414a50, FUN_007467b0, FUN_00746ca0, FUN_0076f240, FUN_0076f6e0, FUN_009728e0.
//  - Strings: "C:\\vog\\1_code\\palantir\\palantir\\graphics\\gfxDeviceVB.cpp".
//  - Return sites: 5.

// =============================================================================
// Named_gfxDeviceVB_00997b90
// -----------------------------------------------------------------------------
// Stable ID: aa_00997b90
// Address:   0x00997b90  (autoassault.exe, image base 0x400000)
// System:    unknown
// Generated: 2026-07-23 from raw capture (scaffold; refine for important units)
// Exactness: Behavior-preserving rewrite of decompiler control flow. Not modernization.
// Bit-for-bit vs retail EXE: DEFERRED (loaded image may differ slightly).
// =============================================================================

/*
 * Behavioral notes:
 * String-driven rename evidence: "gfxDeviceVB"
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



void Named_gfxDeviceVB_00997b90(int param_1,int param_2,int param_3)



{

  float *pfVar1;

  int *piVar2;

  char cVar3;

  int iVar4;

  int *piVar5;

  int *piVar6;

  bool bVar7;

  float fVar8;

  int iVar9;

  int iVar10;

  uint32_t /* width from decompiler */ *puVar11;

  int iVar12;

  uint32_t /* width from decompiler */ *puVar13;

  int iVar14;

  uint32_t /* width from decompiler */ *puVar15;

  int iVar16;

  uint uVar17;

  float *pfVar18;

  uint32_t /* width from decompiler */ *puVar19;

  float fVar20;

  uint64_t uVar21;

  float *local_88;

  int local_80;

  int local_7c;

  int local_78;

  int local_74;

  int local_6c;

  float *local_68;

  int local_60;

  float local_5c;

  int local_4c;

  int local_48;

  uint32_t /* width from decompiler */ *local_40;

  uint local_3c;

  float local_38;

  float local_34;

  float local_30;

  float local_2c;

  float local_28;

  float local_24;

  float local_20;

  float local_1c;

  float local_18;

  uint32_t /* width from decompiler */ local_14;

  

  iVar12 = *(int *)(param_3 + 4);

  iVar4 = *(int *)(param_1 + 4);

  iVar16 = *(int *)(iVar4 + 0x28);

  if (iVar16 != *(int *)(iVar4 + 0x2c)) {

    while ((*(char *)(iVar16 + 6) != '\0' || (*(char *)(iVar16 + 7) != '\0'))) {

      iVar16 = iVar16 + 8;

      if (iVar16 == *(int *)(iVar4 + 0x2c)) {

        return;

      }

    }

    iVar14 = *(int *)(iVar12 + 0x28);

    if (iVar14 != *(int *)(iVar12 + 0x2c)) {

      while ((*(char *)(iVar14 + 6) != '\0' || (*(char *)(iVar14 + 7) != '\0'))) {

        iVar14 = iVar14 + 8;

        if (iVar14 == *(int *)(iVar12 + 0x2c)) {

          return;

        }

      }

      if (iVar4 == 0) {

        local_74 = 0;

      }

      else {

        local_74 = *(int *)(iVar4 + 0x18);

      }

      iVar9 = FUN_00746ca0();

      if (iVar4 == 0) {

        local_6c = 0;

      }

      else if (*(int *)(iVar4 + 0x10) == 0) {

        local_6c = 0;

      }

      else {

        local_6c = *(int *)(*(int *)(iVar4 + 0x10) + 8);

      }

      if ((*(int *)(iVar4 + 0x10) == 0) ||

         (iVar10 = FUN_00746520(*(uint32_t /* width from decompiler */ *)(iVar4 + 0x14),*(uint32_t /* width from decompiler */ *)(iVar4 + 0x18),4),

         iVar10 == 0)) {

        FUN_00414a50();

        return;

      }

      local_7c = (uint)*(ushort *)(iVar16 + 2) + iVar10;

      if (*(int *)(param_3 + 4) == 0) {

        local_78 = 0;

      }

      else {

        iVar16 = *(int *)(*(int *)(param_3 + 4) + 0x10);

        if (iVar16 == 0) {

          local_78 = 0;

        }

        else {

          local_78 = *(int *)(iVar16 + 8);

        }

      }

      uVar17 = local_78 * local_74;

      local_3c = uVar17;

      if (uVar17 - DAT_00d1ed18 != 0 && (int)DAT_00d1ed18 <= (int)uVar17) {

        operator_delete__(DAT_00d1ed14);

        DAT_00d1ed14 = operator_new__(uVar17);

        DAT_00d1ed18 = uVar17;

      }

      pfVar18 = (float *)((uint)*(ushort *)(iVar14 + 2) + (int)DAT_00d1ed14);

      pfVar1 = (float *)(local_7c + 0xc);

      iVar16 = local_7c + 8;

      iVar14 = local_74 + -1;

      if (-1 < iVar14) {

        local_5c = (float)local_74;

        local_88 = pfVar1;

        do {

          FUN_00972970(*(uint32_t /* width from decompiler */ *)

                        (param_2 +

                        (uint)*(byte *)(((iVar16 + iVar9 * 4) - (int)pfVar1) + (int)local_88) * 4),

                       local_7c);

          if (*local_88 <= DAT_00aaa660 && DAT_00aaa660 != *local_88) {

            fVar20 = *local_88;

            *pfVar18 = fVar20 * *pfVar18;

            pfVar18[2] = fVar20 * pfVar18[2];

            fVar8 = g_flOne;

            pfVar18[1] = fVar20 * pfVar18[1];

            local_68 = (float *)(fVar8 - *local_88);

            local_80 = 1;

            if (1 < iVar9) {

              do {

                FUN_0076f6e0();

                local_2c = local_20;

                local_38 = local_20;

                local_28 = local_1c;

                local_24 = local_18;

                local_34 = local_1c;

                local_30 = local_18;

                if (local_80 < iVar9 + -1) {

                  fVar20 = local_88[local_80];

                  *pfVar18 = local_20 * fVar20 + *pfVar18;

                  pfVar18[1] = local_1c * fVar20 + pfVar18[1];

                  local_68 = (float *)((float)local_68 - fVar20);

                  bVar7 = (float)local_68 <= DAT_00aaa664;

                  pfVar18[2] = local_18 * fVar20 + pfVar18[2];

                  if (bVar7) break;

                }

                else {

                  *pfVar18 = local_20 * (float)local_68 + *pfVar18;

                  pfVar18[1] = local_1c * (float)local_68 + pfVar18[1];

                  pfVar18[2] = local_18 * (float)local_68 + pfVar18[2];

                }

                local_80 = local_80 + 1;

              } while (local_80 < iVar9);

            }

          }

          local_7c = local_7c + local_6c;

          local_88 = (float *)((int)local_88 + local_6c);

          pfVar18 = (float *)((int)pfVar18 + local_78);

          local_5c = (float)((int)local_5c + -1);

        } while (local_5c != 0.0);

      }

      local_80 = *(int *)(iVar12 + 0x28);

      if (local_80 == 0) {

        local_48 = 0;

      }

      else {

        local_48 = *(int *)(iVar12 + 0x2c) - local_80 >> 3;

      }

      if (-1 < local_48 + -2) {

        local_48 = local_48 + -1;

        do {

          cVar3 = *(char *)(local_80 + 6);

          switch(cVar3) {

          case '\x03':

          case '\x06':

          case '\a':

            for (iVar12 = *(int *)(iVar4 + 0x28); iVar12 != *(int *)(iVar4 + 0x2c);

                iVar12 = iVar12 + 8) {

              if ((*(char *)(iVar12 + 6) == cVar3) &&

                 (*(char *)(iVar12 + 7) == *(char *)(local_80 + 7))) {

                local_68 = (float *)((uint)*(ushort *)(iVar12 + 2) + iVar10);

                pfVar18 = (float *)((uint)*(ushort *)(local_80 + 2) + (int)DAT_00d1ed14);

                if (-1 < iVar14) {

                  local_4c = local_74;

                  local_88 = pfVar1;

                  do {

                    FUN_009728e0(pfVar18);

                    if (*local_88 <= DAT_00aaa660 && DAT_00aaa660 != *local_88) {

                      fVar20 = *local_88;

                      *pfVar18 = *pfVar18 * fVar20;

                      pfVar18[1] = pfVar18[1] * fVar20;

                      local_5c = g_flOne;

                      pfVar18[2] = pfVar18[2] * fVar20;

                      local_5c = local_5c - *local_88;

                      local_7c = 1;

                      if (1 < iVar9) {

                        local_40 = (uint32_t /* width from decompiler */ *)(iVar9 + -1);

                        do {

                          local_20 = *local_68;

                          local_1c = local_68[1];

                          local_18 = local_68[2];

                          local_14 = 0;

                          FUN_0076f240(&local_20);

                          local_2c = local_20;

                          local_28 = local_1c;

                          local_38 = local_20;

                          local_24 = local_18;

                          local_34 = local_1c;

                          local_30 = local_18;

                          if (local_7c < (int)local_40) {

                            fVar20 = local_88[local_7c];

                            pfVar18[1] = pfVar18[1] + local_1c * fVar20;

                            pfVar18[2] = pfVar18[2] + local_18 * fVar20;

                            local_5c = local_5c - fVar20;

                            bVar7 = local_5c <= DAT_00aaa664;

                            *pfVar18 = *pfVar18 + local_20 * fVar20;

                            if (bVar7) break;

                          }

                          else {

                            pfVar18[1] = pfVar18[1] + local_1c * local_5c;

                            *pfVar18 = *pfVar18 + local_20 * local_5c;

                            pfVar18[2] = pfVar18[2] + local_18 * local_5c;

                          }

                          local_7c = local_7c + 1;

                        } while (local_7c < iVar9);

                      }

                    }

                    fVar20 = SQRT(*pfVar18 * *pfVar18 +

                                  pfVar18[1] * pfVar18[1] + pfVar18[2] * pfVar18[2]);

                    if ((_DAT_00a240ec <= fVar20) || (fVar20 <= DAT_00aaa640)) {

                      fVar20 = g_flOne / fVar20;

                      *pfVar18 = *pfVar18 * fVar20;

                      pfVar18[1] = pfVar18[1] * fVar20;

                      pfVar18[2] = pfVar18[2] * fVar20;

                    }

                    local_68 = (float *)((int)local_68 + local_6c);

                    local_88 = (float *)((int)local_88 + local_6c);

                    pfVar18 = (float *)((int)pfVar18 + local_78);

                    local_4c = local_4c + -1;

                  } while (local_4c != 0);

                }

                break;

              }

            }

            break;

          case '\x04':

          case '\x05':

          case '\b':

          case '\n':

            for (iVar12 = *(int *)(iVar4 + 0x28); iVar12 != *(int *)(iVar4 + 0x2c);

                iVar12 = iVar12 + 8) {

              if ((*(char *)(iVar12 + 6) == cVar3) &&

                 (*(char *)(iVar12 + 7) == *(char *)(local_80 + 7))) {

                puVar11 = (uint32_t /* width from decompiler */ *)((uint)*(ushort *)(local_80 + 2) + (int)DAT_00d1ed14);

                uVar21 = FUN_007467b0();

                if (-1 < iVar14) {

                  local_60 = local_74;

                  puVar13 = (uint32_t /* width from decompiler */ *)((ulonglong)uVar21 >> 0x20);

                  do {

                    puVar15 = puVar13;

                    puVar19 = puVar11;

                    for (uVar17 = (uint)uVar21 >> 2; uVar17 != 0; uVar17 = uVar17 - 1) {

                      *puVar19 = *puVar15;

                      puVar15 = puVar15 + 1;

                      puVar19 = puVar19 + 1;

                    }

                    local_60 = local_60 + -1;

                    for (uVar17 = (uint)uVar21 & 3; uVar17 != 0; uVar17 = uVar17 - 1) {

                      *(uint8_t *)puVar19 = *(uint8_t *)puVar15;

                      puVar15 = (uint32_t /* width from decompiler */ *)((int)puVar15 + 1);

                      puVar19 = (uint32_t /* width from decompiler */ *)((int)puVar19 + 1);

                    }

                    puVar13 = (uint32_t /* width from decompiler */ *)((int)puVar13 + local_6c);

                    puVar11 = (uint32_t /* width from decompiler */ *)((int)puVar11 + local_78);

                  } while (local_60 != 0);

                }

                break;

              }

            }

          }

          local_80 = local_80 + 8;

          local_48 = local_48 + -1;

        } while (local_48 != 0);

      }

      iVar12 = *(int *)(param_3 + 4);

      iVar4 = *(int *)(iVar12 + 0x10);

      if ((*(byte *)(iVar4 + 4) & 1) == 0) {

        piVar5 = *(int **)(iVar12 + 0x10);

        if (piVar5 == (int *)0x0) {

          puVar11 = (uint32_t /* width from decompiler */ *)0x0;

        }

        else {

          if (local_74 < 1) {

            local_74 = *(int *)(iVar12 + 0x18);

          }

          piVar6 = (int *)*piVar5;

          puVar11 = (uint32_t /* width from decompiler */ *)0x0;

          if (piVar6 != (int *)0x0) {

            iVar12 = (**(code **)(*piVar6 + 0x2c))

                               (piVar6,*(int *)(iVar12 + 0x14) * piVar5[2],local_74 * piVar5[2],

                                &local_40,0x800);

            if (iVar12 < 0) {

              puVar11 = (uint32_t /* width from decompiler */ *)0x0;

            }

            else {

              piVar5[4] = piVar5[4] + 1;

              puVar11 = local_40;

            }

          }

        }

      }

      else if (iVar4 == 0) {

        puVar11 = (uint32_t /* width from decompiler */ *)0x0;

      }

      else {

        *(int *)(iVar12 + 0x14) = *(int *)(iVar12 + 0x14) + *(int *)(iVar12 + 0x18);

        if (*(int *)(iVar4 + 0xc) - *(int *)(iVar12 + 0x14) < local_74) {

          puVar11 = (uint32_t /* width from decompiler */ *)FUN_00746520(0,local_74,1);

          *(uint32_t /* width from decompiler */ *)(iVar12 + 0x14) = 0;

          *(int *)(iVar12 + 0x18) = local_74;

        }

        else {

          puVar11 = (uint32_t /* width from decompiler */ *)FUN_00746520(*(int *)(iVar12 + 0x14),local_74,2);

          *(int *)(iVar12 + 0x18) = local_74;

        }

      }

      if (puVar11 != (uint32_t /* width from decompiler */ *)0x0) {

        puVar13 = DAT_00d1ed14;

        for (uVar17 = local_3c >> 2; uVar17 != 0; uVar17 = uVar17 - 1) {

          *puVar11 = *puVar13;

          puVar13 = puVar13 + 1;

          puVar11 = puVar11 + 1;

        }

        for (uVar17 = local_3c & 3; uVar17 != 0; uVar17 = uVar17 - 1) {

          *(uint8_t *)puVar11 = *(uint8_t *)puVar13;

          puVar13 = (uint32_t /* width from decompiler */ *)((int)puVar13 + 1);

          puVar11 = (uint32_t /* width from decompiler */ *)((int)puVar11 + 1);

        }

      }

      piVar5 = *(int **)(*(int *)(param_3 + 4) + 0x10);

      if ((piVar5 != (int *)0x0) && (piVar6 = (int *)*piVar5, piVar6 != (int *)0x0)) {

        piVar2 = piVar5 + 4;

        *piVar2 = *piVar2 + -1;

        if (*piVar2 < 0) {

          vog_LogMessage("C:\\vog\\1_code\\palantir\\palantir\\graphics\\gfxDeviceVB.cpp",0xd3,1,

                         "Call to gfxDeviceVB::Unlock more times than locked! Bad mojo...");

          piVar5[4] = 0;

        }

        else {

          (**(code **)(*piVar6 + 0x30))(piVar6);

        }

      }

      piVar5 = *(int **)(*(int *)(param_1 + 4) + 0x10);

      if ((piVar5 != (int *)0x0) && (piVar6 = (int *)*piVar5, piVar6 != (int *)0x0)) {

        piVar2 = piVar5 + 4;

        *piVar2 = *piVar2 + -1;

        if (*piVar2 < 0) {

          vog_LogMessage("C:\\vog\\1_code\\palantir\\palantir\\graphics\\gfxDeviceVB.cpp",0xd3,1,

                         "Call to gfxDeviceVB::Unlock more times than locked! Bad mojo...");

          piVar5[4] = 0;

          return;

        }

        (**(code **)(*piVar6 + 0x30))(piVar6);

      }

    }

  }

  return;

}
