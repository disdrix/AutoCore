// READABILITY (auto CF):
//  - Body size: ~303 non-empty decompiler lines.
//  - Control keywords: if×41, do×5, while×5, goto×4, return×2.
//  - Notable callees: FUN_00746520×4, vog_LogMessage×4, FUN_0076d1b0×3, fopen×2, ExitProcess, FUN_0072cee0, fclose, fprintf.
//  - Strings: "C:\\vog\\1_code\\palantir\\palantir\\graphics\\gfxDeviceVB.cpp"; "c:\\VOGCRASH.txt"; "errReport::Massive failure EH_Abort: F:%s l:%d s:%d d:%s\n".
//  - Return sites: 2.

// =============================================================================
// Named_gfxDeviceVB_0072cee0
// -----------------------------------------------------------------------------
// Stable ID: aa_0072cee0
// Address:   0x0072cee0  (autoassault.exe, image base 0x400000)
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

uint32_t /* width from decompiler */ Named_gfxDeviceVB_0072cee0(int param_1,int param_2)



{

  int *piVar1;

  float fVar2;

  float fVar3;

  float fVar4;

  float fVar5;

  int *piVar6;

  int *piVar7;

  float *pfVar8;

  int iVar9;

  FILE *_File;

  int iVar10;

  float *pfVar11;

  int iVar12;

  int iVar13;

  int iVar14;

  float *pfVar15;

  int iVar16;

  float *pfVar17;

  int local_20;

  float *local_1c;

  float *local_18;

  int local_14;

  int local_10;

  float local_c;

  float local_8;

  float local_4;

  

  local_10 = *(int *)(*(int *)(param_1 + 200) + 0xc);

  iVar13 = *(int *)(*(int *)(param_1 + 200) + 0x14);

  iVar10 = 0;

  iVar16 = 1;

  local_20 = 0;

  if (1 < iVar13) {

    iVar12 = 0;

    do {

      fVar2 = *(float *)(local_10 + iVar16 * 4);

      if (fVar2 != g_flZero) {

        (&DAT_00d0e33c)[iVar10 * 2] = fVar2;

        iVar14 = *(int *)(param_1 + 0xd4) + iVar12;

        (&DAT_00d0e1a8)[iVar10] = iVar14;

        iVar9 = *(int *)(iVar14 + 4);

        if (*(int *)(iVar9 + 0x10) == 0) {

          iVar9 = 0;

        }

        else {

          iVar9 = FUN_00746520(*(uint32_t /* width from decompiler */ *)(iVar9 + 0x14),*(uint32_t /* width from decompiler */ *)(iVar9 + 0x18),4);

          iVar10 = local_20;

        }

        (&DAT_00d0e338)[iVar10 * 2] = iVar9;

        if (iVar9 == 0) {

          piVar6 = *(int **)(*(int *)(iVar14 + 4) + 0x10);

          if ((piVar6 != (int *)0x0) && (piVar7 = (int *)*piVar6, piVar7 != (int *)0x0)) {

            piVar1 = piVar6 + 4;

            *piVar1 = *piVar1 + -1;

            if (*piVar1 < 0) {

              vog_LogMessage("C:\\vog\\1_code\\palantir\\palantir\\graphics\\gfxDeviceVB.cpp",0xd3,1

                             ,"Call to gfxDeviceVB::Unlock more times than locked! Bad mojo...");

              piVar6[4] = 0;

              (&DAT_00d0e1a8)[local_20] = 0;

              iVar10 = local_20;

              goto LAB_0072cfd7;

            }

            (**(code **)(*piVar7 + 0x30))(piVar7);

            iVar10 = local_20;

          }

          (&DAT_00d0e1a8)[iVar10] = 0;

        }

        else {

          iVar10 = iVar10 + 1;

          local_20 = iVar10;

        }

      }

LAB_0072cfd7:

      iVar16 = iVar16 + 1;

      iVar12 = iVar12 + 8;

    } while (iVar16 < iVar13);

  }

  if (*(int *)(param_1 + 0x14) == 0) {

    local_10 = 0;

  }

  else {

    iVar13 = *(int *)(*(int *)(param_1 + 0x14) + 0x10);

    if (iVar13 == 0) {

      local_10 = 0;

    }

    else {

      local_10 = *(int *)(iVar13 + 8);

    }

  }

  iVar13 = *(int *)(param_1 + 0x14);

  if (*(int *)(iVar13 + 0x10) == 0) {

    iVar13 = 0;

  }

  else {

    iVar13 = FUN_00746520(*(uint32_t /* width from decompiler */ *)(iVar13 + 0x14),*(uint32_t /* width from decompiler */ *)(iVar13 + 0x18),4);

  }

  if (*(int *)(param_1 + 0x14) == 0) {

    pfVar15 = (float *)0x0;

  }

  else {

    pfVar15 = *(float **)(*(int *)(param_1 + 0x14) + 0x18);

  }

  iVar10 = *(int *)(param_2 + 4);

  iVar16 = *(int *)(iVar10 + 0x10);

  local_18 = pfVar15;

  local_14 = iVar13;

  if ((*(byte *)(iVar16 + 4) & 1) == 0) {

    piVar6 = *(int **)(iVar10 + 0x10);

    if (piVar6 == (int *)0x0) {

      local_1c = (float *)0x0;

    }

    else {

      local_1c = pfVar15;

      if ((int)pfVar15 < 1) {

        local_1c = *(float **)(iVar10 + 0x18);

      }

      piVar7 = (int *)*piVar6;

      if (piVar7 == (int *)0x0) {

        local_1c = (float *)0x0;

      }

      else {

        iVar10 = (**(code **)(*piVar7 + 0x2c))

                           (piVar7,piVar6[2] * *(int *)(iVar10 + 0x14),piVar6[2] * (int)local_1c,

                            &local_1c,0x800);

        if (iVar10 < 0) {

          local_1c = (float *)0x0;

        }

        else {

          piVar6[4] = piVar6[4] + 1;

        }

      }

    }

  }

  else if (iVar16 == 0) {

    local_1c = (float *)0x0;

  }

  else {

    *(int *)(iVar10 + 0x14) = *(int *)(iVar10 + 0x14) + *(int *)(iVar10 + 0x18);

    if (*(int *)(iVar16 + 0xc) - *(int *)(iVar10 + 0x14) < (int)pfVar15) {

      local_1c = (float *)FUN_00746520(0,pfVar15,1);

      *(uint32_t /* width from decompiler */ *)(iVar10 + 0x14) = 0;

      *(float **)(iVar10 + 0x18) = pfVar15;

    }

    else {

      local_1c = (float *)FUN_00746520(*(int *)(iVar10 + 0x14),pfVar15,2);

      *(float **)(iVar10 + 0x18) = pfVar15;

    }

  }

  if ((local_1c == (float *)0x0) || (iVar13 == 0)) {

    piVar6 = *(int **)(*(int *)(param_1 + 0x14) + 0x10);

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

    iVar13 = 0;

    if (0 < local_20) {

      do {

        piVar6 = *(int **)(*(int *)((&DAT_00d0e1a8)[iVar13] + 4) + 0x10);

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

        iVar13 = iVar13 + 1;

      } while (iVar13 < local_20);

    }

  }

  if (-1 < (int)local_18 + -1) {

    pfVar11 = (float *)(local_14 + 8);

    pfVar15 = local_18;

    pfVar17 = local_1c;

    do {

      local_c = pfVar11[-2];

      local_8 = pfVar11[-1];

      local_4 = *pfVar11;

      iVar13 = 0;

      if (0 < local_20) {

        do {

          pfVar8 = (float *)(&DAT_00d0e338)[iVar13 * 2];

          fVar2 = *pfVar8;

          fVar3 = pfVar8[1];

          fVar4 = pfVar8[2];

          fVar5 = (float)(&DAT_00d0e33c)[iVar13 * 2];

          (&DAT_00d0e338)[iVar13 * 2] = pfVar8 + 6;

          iVar13 = iVar13 + 1;

          local_c = fVar2 * fVar5 + local_c;

          local_8 = fVar3 * fVar5 + local_8;

          local_4 = fVar4 * fVar5 + local_4;

        } while (iVar13 < local_20);

      }

      *pfVar17 = local_c;

      pfVar17[1] = local_8;

      pfVar11 = (float *)((int)pfVar11 + local_10);

      pfVar15 = (float *)((int)pfVar15 + -1);

      pfVar17[2] = local_4;

      pfVar17 = pfVar17 + 3;

    } while (pfVar15 != (float *)0x0);

  }

  piVar6 = *(int **)(*(int *)(param_1 + 0x14) + 0x10);

  if ((piVar6 != (int *)0x0) && (piVar7 = (int *)*piVar6, piVar7 != (int *)0x0)) {

    piVar1 = piVar6 + 4;

    *piVar1 = *piVar1 + -1;

    if (*piVar1 < 0) {

      iVar13 = FUN_0076d1b0("C:\\vog\\1_code\\palantir\\palantir\\graphics\\gfxDeviceVB.cpp",0xd3,

                            "Call to gfxDeviceVB::Unlock more times than locked! Bad mojo...");

      if (iVar13 == 3) goto LAB_0072d2fa;

      piVar6[4] = 0;

    }

    else {

      (**(code **)(*piVar7 + 0x30))(piVar7);

    }

  }

  piVar6 = *(int **)(*(int *)(param_2 + 4) + 0x10);

  if (piVar6 != (int *)0x0) {

    piVar7 = (int *)*piVar6;

    if (piVar7 != (int *)0x0) {

      piVar1 = piVar6 + 4;

      *piVar1 = *piVar1 + -1;

      if (*piVar1 < 0) {

        iVar13 = FUN_0076d1b0("C:\\vog\\1_code\\palantir\\palantir\\graphics\\gfxDeviceVB.cpp",0xd3,

                              "Call to gfxDeviceVB::Unlock more times than locked! Bad mojo...");

        if (iVar13 == 3) {

LAB_0072d2fa:

          _File = fopen("c:\\VOGCRASH.txt","w");

          if (_File != (FILE *)0x0) {

LAB_0072d3e9:

            fprintf(_File,"errReport::Massive failure EH_Abort: F:%s l:%d s:%d d:%s\n",

                    "C:\\vog\\1_code\\palantir\\palantir\\graphics\\gfxDeviceVB.cpp",0xd3,1,

                    "Call to gfxDeviceVB::Unlock more times than locked! Bad mojo...");

            fclose(_File);

          }

LAB_0072d410:

          raise(0x16);

                    /* WARNING: Subroutine does not return */

          ExitProcess(3);

        }

        piVar6[4] = 0;

      }

      else {

        (**(code **)(*piVar7 + 0x30))(piVar7);

      }

    }

  }

  iVar13 = 0;

  if (0 < local_20) {

    do {

      piVar6 = *(int **)(*(int *)((&DAT_00d0e1a8)[iVar13] + 4) + 0x10);

      if (piVar6 != (int *)0x0) {

        piVar7 = (int *)*piVar6;

        if (piVar7 != (int *)0x0) {

          piVar1 = piVar6 + 4;

          *piVar1 = *piVar1 + -1;

          if (*piVar1 < 0) {

            iVar10 = FUN_0076d1b0("C:\\vog\\1_code\\palantir\\palantir\\graphics\\gfxDeviceVB.cpp",

                                  0xd3,

                                  "Call to gfxDeviceVB::Unlock more times than locked! Bad mojo...")

            ;

            if (iVar10 == 3) {

              _File = fopen("c:\\VOGCRASH.txt","w");

              if (_File == (FILE *)0x0) goto LAB_0072d410;

              goto LAB_0072d3e9;

            }

            piVar6[4] = 0;

          }

          else {

            (**(code **)(*piVar7 + 0x30))(piVar7);

          }

        }

      }

      iVar13 = iVar13 + 1;

    } while (iVar13 < local_20);

  }

  return 1;

}
