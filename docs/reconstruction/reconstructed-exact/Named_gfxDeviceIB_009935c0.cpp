// READABILITY (auto CF):
//  - Body size: ~232 non-empty decompiler lines.
//  - Control keywords: if×32, do×7, while×7, goto×4, return×3.
//  - Notable callees: ABS×11, FUN_00414a50, FUN_0044b9c0, FUN_0044ba80, FUN_0044bad0, FUN_009935c0, vog_LogMessage.
//  - Strings: "C:\\vog\\1_code\\palantir\\palantir\\graphics\\gfxDeviceIB.cpp".
//  - Return sites: 3.

// =============================================================================
// Named_gfxDeviceIB_009935c0
// -----------------------------------------------------------------------------
// Stable ID: aa_009935c0
// Address:   0x009935c0  (autoassault.exe, image base 0x400000)
// System:    unknown
// Generated: 2026-07-23 from raw capture (scaffold; refine for important units)
// Exactness: Behavior-preserving rewrite of decompiler control flow. Not modernization.
// Bit-for-bit vs retail EXE: DEFERRED (loaded image may differ slightly).
// =============================================================================

/*
 * Behavioral notes:
 * String-driven rename evidence: "gfxDeviceIB"
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



uint32_t /* width from decompiler */ Named_gfxDeviceIB_009935c0(int param_1,int param_2,int param_3)



{

  int *piVar1;

  int *piVar2;

  int *piVar3;

  bool bVar4;

  float *pfVar5;

  float *pfVar6;

  float *pfVar7;

  uint32_t /* width from decompiler */ *puVar8;

  int iVar9;

  float *pfVar10;

  short *psVar11;

  float *pfVar12;

  int iVar13;

  uint uVar14;

  uint32_t /* width from decompiler */ *puVar15;

  float fVar16;

  int local_3c;

  int local_38;

  int local_34;

  int local_2c;

  float local_20;

  float local_1c;

  float local_18;

  float local_14;

  float local_10;

  int local_c;

  float *local_8;

  int local_4;

  

  iVar9 = *(int *)(param_2 + 4);

  if (iVar9 == 0) {

    local_3c = 0;

  }

  else {

    local_3c = *(int *)(iVar9 + 0x1c);

  }

  if (*(int *)(param_1 + 4) == 0) {

    local_38 = 0;

  }

  else {

    local_38 = *(int *)(*(int *)(param_1 + 4) + 0x18);

  }

  piVar2 = *(int **)(iVar9 + 0x10);

  if (piVar2 == (int *)0x0) {

    local_34 = 0;

  }

  else {

    piVar3 = (int *)*piVar2;

    if (piVar3 == (int *)0x0) {

      local_34 = 0;

    }

    else {

      iVar9 = (**(code **)(*piVar3 + 0x2c))

                        (piVar3,piVar2[4] * *(int *)(iVar9 + 0x18),

                         piVar2[4] * *(int *)(iVar9 + 0x1c),&local_c,0x800);

      if (iVar9 < 0) {

        local_34 = 0;

      }

      else {

        piVar2[3] = piVar2[3] + 1;

        local_34 = local_c;

      }

    }

  }

  iVar9 = *(int *)(param_1 + 4);

  piVar2 = *(int **)(iVar9 + 0x10);

  if (piVar2 == (int *)0x0) {

    local_8 = (float *)0x0;

  }

  else {

    piVar3 = (int *)*piVar2;

    if (piVar3 == (int *)0x0) {

      local_8 = (float *)0x0;

    }

    else {

      iVar9 = (**(code **)(*piVar3 + 0x2c))

                        (piVar3,piVar2[2] * *(int *)(iVar9 + 0x14),

                         piVar2[2] * *(int *)(iVar9 + 0x18),&local_8,0x800);

      if (iVar9 < 0) {

        local_8 = (float *)0x0;

      }

      else {

        piVar2[4] = piVar2[4] + 1;

      }

    }

  }

  if ((local_34 == 0) || (local_8 == (float *)0x0)) {

    FUN_0044ba80();

    FUN_00414a50();

    return 0xffffffff;

  }

  if (0 < local_38) {

    pfVar6 = local_8 + 0x15;

    iVar9 = local_38;

    do {

      *pfVar6 = 0.0;

      pfVar6 = pfVar6 + 0x18;

      iVar9 = iVar9 + -1;

    } while (iVar9 != 0);

  }

  iVar9 = 0;

  if (0 < local_3c) {

    do {

      iVar13 = iVar9 * 2;

      iVar9 = iVar9 + 1;

      local_8[(uint)*(ushort *)(local_34 + iVar13) * 0x18 + 0x15] = 3.57331e-43;

    } while (iVar9 < local_3c);

  }

  fVar16 = *(float *)(DAT_00d1f048 + 0x14) * *(float *)(DAT_00d1f048 + 0x14);

  local_2c = 0;

  if (0 < local_38) {

    local_4 = 0x60 - (int)local_8;

    pfVar6 = local_8;

    do {

      if ((pfVar6[0x15] != 0.0) && (uVar14 = local_2c + 1, (int)uVar14 < local_38)) {

        param_1 = -((int)local_8 + local_4);

        pfVar5 = pfVar6;

        do {

          bVar4 = true;

          if (param_3 < 1) {

LAB_00993897:

            iVar9 = 0;

            pfVar5[0x2d] = 0.0;

            if (0 < local_3c) {

              do {

                if (*(ushort *)(local_34 + iVar9 * 2) == uVar14) {

                  *(short *)(local_34 + iVar9 * 2) = (short)local_2c;

                }

                iVar9 = iVar9 + 1;

              } while (iVar9 < local_3c);

            }

          }

          else {

            pfVar7 = pfVar5 + 0x19;

            pfVar10 = pfVar6;

            iVar9 = param_3;

            do {

              local_18 = ABS(pfVar7[-1] - *pfVar10);

              if (local_18 <= _DAT_00a240ec) {

LAB_009937c5:

                local_14 = *pfVar7;

                local_20 = ABS(local_14 - *(float *)(param_1 + (int)pfVar7));

                if (_DAT_00a240ec < local_20) {

                  local_1c = ABS(*(float *)(param_1 + (int)pfVar7));

                  pfVar12 = &local_18;

                  local_18 = ABS(local_14);

                  if (ABS(local_14) <= local_1c) {

                    pfVar12 = &local_1c;

                  }

                  if (*pfVar12 * fVar16 < local_20) goto LAB_0099387a;

                }

                local_10 = pfVar7[1];

                local_20 = ABS(local_10 - pfVar10[2]);

                if (_DAT_00a240ec < local_20) {

                  local_1c = ABS(pfVar10[2]);

                  pfVar12 = &local_18;

                  local_18 = ABS(local_10);

                  if (ABS(local_10) <= local_1c) {

                    pfVar12 = &local_1c;

                  }

                  if (*pfVar12 * fVar16 < local_20) goto LAB_0099387a;

                }

              }

              else {

                local_1c = ABS(*pfVar10);

                pfVar12 = &local_20;

                local_20 = ABS(pfVar7[-1]);

                if (local_20 <= local_1c) {

                  pfVar12 = &local_1c;

                }

                if (local_18 <= *pfVar12 * fVar16) goto LAB_009937c5;

LAB_0099387a:

                bVar4 = false;

              }

              pfVar10 = pfVar10 + 3;

              pfVar7 = pfVar7 + 3;

              iVar9 = iVar9 + -1;

            } while (iVar9 != 0);

            if (bVar4) goto LAB_00993897;

          }

          param_1 = param_1 + -0x60;

          uVar14 = uVar14 + 1;

          pfVar5 = pfVar5 + 0x18;

        } while ((int)uVar14 < local_38);

      }

      local_2c = local_2c + 1;

      pfVar6 = pfVar6 + 0x18;

    } while (local_2c < local_38);

  }

  puVar8 = operator_new__(local_3c * 2);

  iVar9 = 0;

  if (0 < local_3c) {

    psVar11 = (short *)(local_34 + 4);

    iVar13 = (local_3c - 1U) / 3 + 1;

    puVar15 = puVar8;

    do {

      if (((psVar11[-2] != psVar11[-1]) && (psVar11[-1] != *psVar11)) && (psVar11[-2] != *psVar11))

      {

        *puVar15 = *(uint32_t /* width from decompiler */ *)(psVar11 + -2);

        iVar9 = iVar9 + 3;

        *(short *)(puVar15 + 1) = *psVar11;

        puVar15 = (uint32_t /* width from decompiler */ *)((int)puVar15 + 6);

      }

      psVar11 = psVar11 + 3;

      iVar13 = iVar13 + -1;

    } while (iVar13 != 0);

    if (0 < iVar9) {

      if (local_3c != iVar9) {

        piVar2 = *(int **)(*(int *)(param_2 + 4) + 0x10);

        if ((piVar2 != (int *)0x0) && (piVar3 = (int *)*piVar2, piVar3 != (int *)0x0)) {

          piVar1 = piVar2 + 3;

          *piVar1 = *piVar1 + -1;

          if (*piVar1 < 0) {

            vog_LogMessage("C:\\vog\\1_code\\palantir\\palantir\\graphics\\gfxDeviceIB.cpp",0xca,1,

                           "Call to gfxDeviceIB::Unlock more times than locked! Bad mojo...");

            piVar2[3] = 0;

          }

          else {

            (**(code **)(*piVar3 + 0x30))(piVar3);

          }

        }

        FUN_0044b9c0(iVar9,8,0,0);

        FUN_0044bad0(puVar8,0);

      }

      operator_delete__(puVar8);

      return 0;

    }

  }

  return 1;

}
