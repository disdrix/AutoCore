// READABILITY (auto CF):
//  - Body size: ~320 non-empty decompiler lines.
//  - Control keywords: if×35, while×6, for×6, goto×5, return×4, do×4, switch×1.
//  - Notable callees: FUN_00746520×3, vog_LogMessage×2, FUN_00414a50, FUN_007385d0, FUN_007467b0, SQRT.
//  - Strings: "C:\\vog\\1_code\\palantir\\palantir\\graphics\\gfxDeviceVB.cpp".
//  - Return sites: 4.

// =============================================================================
// Named_gfxDeviceVB_007385d0
// -----------------------------------------------------------------------------
// Stable ID: aa_007385d0
// Address:   0x007385d0  (autoassault.exe, image base 0x400000)
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



void Named_gfxDeviceVB_007385d0(int param_1,int param_2)



{

  int *piVar1;

  float fVar2;

  float fVar3;

  float fVar4;

  int iVar5;

  int *piVar6;

  int *piVar7;

  float *pfVar8;

  float *pfVar9;

  int iVar10;

  int iVar11;

  float *pfVar12;

  uint32_t /* width from decompiler */ *puVar13;

  uint uVar14;

  uint32_t /* width from decompiler */ *puVar15;

  float *pfVar16;

  uint32_t /* width from decompiler */ *puVar17;

  int iVar18;

  float *pfVar19;

  uint32_t /* width from decompiler */ *puVar20;

  float fVar21;

  float fVar22;

  float fVar23;

  uint64_t uVar24;

  int local_2c;

  int local_28;

  int local_20;

  int local_1c;

  int local_10;

  int local_c;

  float *local_8;

  uint local_4;

  

  iVar11 = *(int *)(param_1 + 0x14);

  iVar18 = *(int *)(iVar11 + 0x28);

  if (iVar18 != *(int *)(iVar11 + 0x2c)) {

    while ((*(char *)(iVar18 + 6) != '\x02' || (*(char *)(iVar18 + 7) != '\0'))) {

      iVar18 = iVar18 + 8;

      if (iVar18 == *(int *)(iVar11 + 0x2c)) {

        return;

      }

    }

    iVar5 = *(int *)(*(int *)(param_1 + 200) + 0xc);

    if (*(int *)(param_1 + 0x14) == 0) {

      local_2c = 0;

    }

    else {

      local_2c = *(int *)(*(int *)(param_1 + 0x14) + 0x18);

    }

    if (*(int *)(param_1 + 0x14) == 0) {

      local_28 = 0;

    }

    else {

      iVar10 = *(int *)(*(int *)(param_1 + 0x14) + 0x10);

      if (iVar10 == 0) {

        local_28 = 0;

      }

      else {

        local_28 = *(int *)(iVar10 + 8);

      }

    }

    if ((*(int *)(iVar11 + 0x10) == 0) ||

       (pfVar8 = (float *)FUN_00746520(*(uint32_t /* width from decompiler */ *)(iVar11 + 0x14),*(uint32_t /* width from decompiler */ *)(iVar11 + 0x18)

                                       ,4), pfVar8 == (float *)0x0)) {

      FUN_00414a50();

      return;

    }

    pfVar19 = (float *)((uint)*(ushort *)(iVar18 + 2) + (int)pfVar8);

    if (*(int *)(param_2 + 4) == 0) {

      iVar11 = 0;

    }

    else {

      iVar11 = *(int *)(*(int *)(param_2 + 4) + 0x10);

      if (iVar11 == 0) {

        iVar11 = 0;

      }

      else {

        iVar11 = *(int *)(iVar11 + 8);

      }

    }

    uVar14 = iVar11 * local_2c;

    local_8 = pfVar19;

    local_4 = uVar14;

    if (uVar14 - DAT_00d1ed18 != 0 && (int)DAT_00d1ed18 <= (int)uVar14) {

      operator_delete__(DAT_00d1ed14);

      DAT_00d1ed14 = operator_new__(uVar14);

      DAT_00d1ed18 = uVar14;

    }

    if (-1 < local_2c + -1) {

      local_20 = local_2c;

      pfVar9 = DAT_00d1ed14;

      pfVar16 = pfVar8;

      do {

        *pfVar9 = *pfVar16;

        pfVar9[1] = pfVar16[1];

        pfVar9[2] = pfVar16[2];

        iVar18 = 0;

        if (0 < *(int *)(param_1 + 0xb0)) {

          pfVar12 = pfVar16 + 5;

          do {

            fVar23 = pfVar12[-2];

            fVar22 = *pfVar12;

            fVar21 = *(float *)(iVar5 + (uint)*(byte *)((int)pfVar16 +

                                                       (int)pfVar19 + (iVar18 - (int)pfVar8)) * 4);

            pfVar9[1] = pfVar9[1] + pfVar12[-1] * fVar21;

            iVar18 = iVar18 + 1;

            *pfVar9 = *pfVar9 + fVar23 * fVar21;

            pfVar9[2] = pfVar9[2] + fVar22 * fVar21;

            pfVar12 = pfVar12 + 3;

          } while (iVar18 < *(int *)(param_1 + 0xb0));

        }

        pfVar16 = (float *)((int)pfVar16 + local_28);

        pfVar9 = (float *)((int)pfVar9 + iVar11);

        local_20 = local_20 + -1;

      } while (local_20 != 0);

    }

    iVar18 = *(int *)(*(int *)(param_2 + 4) + 0x28);

    if (iVar18 == 0) {

      local_c = 0;

    }

    else {

      local_c = *(int *)(*(int *)(param_2 + 4) + 0x2c) - iVar18 >> 3;

    }

    if (-1 < local_c + -2) {

      fVar22 = 0.0;

      local_c = local_c + -1;

      fVar23 = g_flOne;

LAB_007387e0:

      switch(*(uint8_t *)(iVar18 + 6)) {

      case 3:

        for (iVar10 = *(int *)(*(int *)(param_1 + 0x14) + 0x28);

            iVar10 != *(int *)(*(int *)(param_1 + 0x14) + 0x2c); iVar10 = iVar10 + 8) {

          if ((*(char *)(iVar10 + 6) == *(char *)(iVar18 + 6)) &&

             (*(char *)(iVar10 + 7) == *(char *)(iVar18 + 7))) {

            pfVar9 = (float *)((uint)*(ushort *)(iVar10 + 2) + (int)pfVar8);

            pfVar19 = (float *)((uint)*(ushort *)(iVar18 + 2) + (int)DAT_00d1ed14);

            if (-1 < local_2c + -1) {

              local_10 = local_2c;

              pfVar16 = local_8;

              goto LAB_007388f0;

            }

            break;

          }

        }

        break;

      case 4:

      case 5:

      case 6:

      case 7:

      case 8:

      case 10:

        for (iVar10 = *(int *)(*(int *)(param_1 + 0x14) + 0x28);

            iVar10 != *(int *)(*(int *)(param_1 + 0x14) + 0x2c); iVar10 = iVar10 + 8) {

          if ((*(char *)(iVar10 + 6) == *(char *)(iVar18 + 6)) &&

             (*(char *)(iVar10 + 7) == *(char *)(iVar18 + 7))) {

            puVar15 = (uint32_t /* width from decompiler */ *)((uint)*(ushort *)(iVar18 + 2) + (int)DAT_00d1ed14);

            uVar24 = FUN_007467b0();

            if (-1 < local_2c + -1) {

              local_1c = local_2c;

              puVar13 = (uint32_t /* width from decompiler */ *)((ulonglong)uVar24 >> 0x20);

              do {

                puVar17 = puVar13;

                puVar20 = puVar15;

                for (uVar14 = (uint)uVar24 >> 2; uVar14 != 0; uVar14 = uVar14 - 1) {

                  *puVar20 = *puVar17;

                  puVar17 = puVar17 + 1;

                  puVar20 = puVar20 + 1;

                }

                local_1c = local_1c + -1;

                for (uVar14 = (uint)uVar24 & 3; uVar14 != 0; uVar14 = uVar14 - 1) {

                  *(uint8_t *)puVar20 = *(uint8_t *)puVar17;

                  puVar17 = (uint32_t /* width from decompiler */ *)((int)puVar17 + 1);

                  puVar20 = (uint32_t /* width from decompiler */ *)((int)puVar20 + 1);

                }

                puVar13 = (uint32_t /* width from decompiler */ *)((int)puVar13 + local_28);

                puVar15 = (uint32_t /* width from decompiler */ *)((int)puVar15 + iVar11);

              } while (local_1c != 0);

            }

            break;

          }

        }

      }

      goto switchD_007387f7_caseD_9;

    }

LAB_00738a54:

    iVar11 = *(int *)(param_2 + 4);

    iVar18 = *(int *)(iVar11 + 0x10);

    if ((*(byte *)(iVar18 + 4) & 1) == 0) {

      piVar6 = *(int **)(iVar11 + 0x10);

      if (piVar6 == (int *)0x0) {

        pfVar8 = (float *)0x0;

      }

      else {

        if (local_2c < 1) {

          local_2c = *(int *)(iVar11 + 0x18);

        }

        piVar7 = (int *)*piVar6;

        pfVar8 = (float *)0x0;

        if (piVar7 != (int *)0x0) {

          iVar11 = (**(code **)(*piVar7 + 0x2c))

                             (piVar7,*(int *)(iVar11 + 0x14) * piVar6[2],local_2c * piVar6[2],

                              &local_8,0x800);

          if (iVar11 < 0) {

            pfVar8 = (float *)0x0;

          }

          else {

            piVar6[4] = piVar6[4] + 1;

            pfVar8 = local_8;

          }

        }

      }

    }

    else if (iVar18 == 0) {

      pfVar8 = (float *)0x0;

    }

    else {

      *(int *)(iVar11 + 0x14) = *(int *)(iVar11 + 0x14) + *(int *)(iVar11 + 0x18);

      if (*(int *)(iVar18 + 0xc) - *(int *)(iVar11 + 0x14) < local_2c) {

        pfVar8 = (float *)FUN_00746520(0,local_2c,1);

        *(uint32_t /* width from decompiler */ *)(iVar11 + 0x14) = 0;

        *(int *)(iVar11 + 0x18) = local_2c;

      }

      else {

        pfVar8 = (float *)FUN_00746520(*(int *)(iVar11 + 0x14),local_2c,2);

        *(int *)(iVar11 + 0x18) = local_2c;

      }

    }

    if (pfVar8 != (float *)0x0) {

      pfVar19 = DAT_00d1ed14;

      for (uVar14 = local_4 >> 2; uVar14 != 0; uVar14 = uVar14 - 1) {

        *pfVar8 = *pfVar19;

        pfVar19 = pfVar19 + 1;

        pfVar8 = pfVar8 + 1;

      }

      for (uVar14 = local_4 & 3; uVar14 != 0; uVar14 = uVar14 - 1) {

        *(uint8_t *)pfVar8 = *(uint8_t *)pfVar19;

        pfVar19 = (float *)((int)pfVar19 + 1);

        pfVar8 = (float *)((int)pfVar8 + 1);

      }

    }

    piVar6 = *(int **)(*(int *)(param_2 + 4) + 0x10);

    if ((piVar6 != (int *)0x0) && (piVar7 = (int *)*piVar6, piVar7 != (int *)0x0)) {

      piVar1 = piVar6 + 4;

      *piVar1 = *piVar1 + -1;

      if (*piVar1 < 0) {

        vog_LogMessage("C:\\vog\\1_code\\palantir\\palantir\\graphics\\gfxDeviceVB.cpp",0xd3,1,

                       "Call to gfxDeviceVB::Unlock more times than locked! Bad mojo...");

        piVar6[4] = 0;

      }

      else {

        (**(code **)(*piVar7 + 0x30))(piVar7);

      }

    }

    piVar6 = *(int **)(*(int *)(param_1 + 0x14) + 0x10);

    if ((piVar6 != (int *)0x0) && (piVar7 = (int *)*piVar6, piVar7 != (int *)0x0)) {

      piVar1 = piVar6 + 4;

      *piVar1 = *piVar1 + -1;

      if (*piVar1 < 0) {

        vog_LogMessage("C:\\vog\\1_code\\palantir\\palantir\\graphics\\gfxDeviceVB.cpp",0xd3,1,

                       "Call to gfxDeviceVB::Unlock more times than locked! Bad mojo...");

        piVar6[4] = 0;

        return;

      }

      (**(code **)(*piVar7 + 0x30))(piVar7);

    }

  }

  return;

  while( true ) {

    fVar21 = SQRT(*pfVar19 * *pfVar19 + pfVar19[1] * pfVar19[1] + pfVar19[2] * pfVar19[2]);

    if ((_DAT_00a240ec <= fVar21) || (fVar21 <= DAT_00aaa640)) {

      fVar21 = fVar23 / fVar21;

      *pfVar19 = *pfVar19 * fVar21;

      pfVar19[1] = fVar21 * pfVar19[1];

      pfVar19[2] = fVar21 * pfVar19[2];

    }

    pfVar19 = (float *)((int)pfVar19 + iVar11);

    pfVar9 = (float *)((int)pfVar9 + local_28);

    pfVar16 = (float *)((int)pfVar16 + local_28);

    local_10 = local_10 + -1;

    if (local_10 == 0) break;

LAB_007388f0:

    *pfVar19 = DAT_00d1a6c0;

    pfVar19[1] = DAT_00d1a6c4;

    pfVar19[2] = DAT_00d1a6c8;

    iVar10 = 0;

    fVar21 = fVar23;

    if (*(int *)(param_1 + 0xb0) < 1) {

LAB_00738988:

      fVar2 = pfVar9[1];

      fVar3 = pfVar9[2];

      *pfVar19 = *pfVar19 + *pfVar9 * fVar21;

      pfVar19[1] = fVar2 * fVar21 + pfVar19[1];

      pfVar19[2] = fVar3 * fVar21 + pfVar19[2];

    }

    else {

      pfVar12 = pfVar9 + 5;

      do {

        fVar2 = *(float *)(iVar5 + (uint)*(byte *)(iVar10 + (int)pfVar16) * 4);

        if (fVar22 < fVar2) {

          fVar3 = pfVar12[-1];

          fVar4 = *pfVar12;

          *pfVar19 = *pfVar19 + pfVar12[-2] * fVar2;

          pfVar19[1] = fVar3 * fVar2 + pfVar19[1];

          pfVar19[2] = fVar4 * fVar2 + pfVar19[2];

          fVar21 = fVar21 - fVar2;

        }

        iVar10 = iVar10 + 1;

        pfVar12 = pfVar12 + 3;

      } while (iVar10 < *(int *)(param_1 + 0xb0));

      if (fVar22 < fVar21) goto LAB_00738988;

    }

  }

switchD_007387f7_caseD_9:

  iVar18 = iVar18 + 8;

  local_c = local_c + -1;

  if (local_c == 0) goto LAB_00738a54;

  goto LAB_007387e0;

}
