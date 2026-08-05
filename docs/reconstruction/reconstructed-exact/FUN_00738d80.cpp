// =============================================================================
// FUN_00738d80
// -----------------------------------------------------------------------------
// Stable ID: aa_00738d80
// Address:   0x00738d80  (autoassault.exe, image base 0x400000)
// System:    unknown
// Generated: 2026-07-23 from raw capture (scaffold; refine for important units)
// Exactness: Behavior-preserving rewrite of decompiler control flow. Not modernization.
// Bit-for-bit vs retail EXE: DEFERRED (loaded image may differ slightly).
// =============================================================================

// PURPOSE (auto): Scaffold unit for FUN_00738d80 @ 0x00738d80
// Stable ID: aa_00738d80
// Embedded strings (evidence for future rename):
//   - "C:\\vog\\1_code\\palantir\\palantir\\graphics\\gfxGeometryPieceMorphed.cpp"
//   - "Vertex Buffer usage flagged as system memory for hardware morphing!"
//   - "c:\\VOGCRASH.txt"
//   - ");

// READABILITY (auto CF):
//  - Body size: ~206 non-empty decompiler lines.
//  - Control keywords: if×25, return×6, for×2, do×1, while×1.
//  - Notable callees: block×10, vog_LogMessage×4, ExitProcess×2, FUN_00414b60×2, FUN_00414c20×2, FUN_0076d1b0×2, fclose×2, fopen×2.
//  - Strings: "),

     iVar5 == 3)) {

    pFVar6 = fopen("; ");

    if (pFVar6 != (FILE *)0x0) {

      fprintf(pFVar6,"; ",

              "; ",0x2e1,3,

              ".
//  - Return sites: 6.

    if (pFVar6 != (FILE *)0x0) {

      fprintf(pFVar6,"
//   - ",

              "
//   - ",0x2e1,3,

              "
// Readability: control flow preserved from Ghidra decompile; types tentative.

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

/* WARNING: Removing unreachable block (ram,0x00739193) */

/* WARNING: Removing unreachable block (ram,0x00739198) */

/* WARNING: Removing unreachable block (ram,0x00739018) */

/* WARNING: Removing unreachable block (ram,0x0073901e) */

/* WARNING: Removing unreachable block (ram,0x00738eb2) */

/* WARNING: Removing unreachable block (ram,0x00738eba) */

/* WARNING: Removing unreachable block (ram,0x00738fb1) */

/* WARNING: Removing unreachable block (ram,0x00738fbe) */

/* WARNING: Removing unreachable block (ram,0x007390b9) */

/* WARNING: Removing unreachable block (ram,0x007390bf) */



void FUN_00738d80(int param_1)



{

  int *piVar1;

  int *piVar2;

  int iVar3;

  int *piVar4;

  int iVar5;

  FILE *pFVar6;

  int iVar7;

  uint32_t /* width from decompiler */ uVar8;

  uint32_t /* width from decompiler */ uVar9;

  uint local_30;

  uint8_t local_24 [4];

  void *pvStack_20;

  uint32_t /* width from decompiler */ uStack_14;

  uint32_t /* width from decompiler */ uStack_10;

  void *pvStack_c;

  uint8_t *puStack_8;

  uint local_4;

  

  local_4 = 0xffffffff;

  puStack_8 = &LAB_009b2019;

  pvStack_c = ExceptionList;

  ExceptionList = &pvStack_c;

  FUN_004451c0(local_24,*(int *)(param_1 + 0x14) + 0x24);

  local_4 = 0;

  if (((*(int *)(param_1 + 0x20) == 0) ||

      (iVar5 = *(int *)(*(int *)(param_1 + 0x20) + 0x14), iVar5 == 0)) ||

     (local_30 = 0x18, *(char *)(iVar5 + 0x10) == '\0')) {

    local_30 = 0x20;

  }

  if (((int)-(uint)((local_30 & 8) != 0) < 0) &&

     (iVar5 = FUN_0076d1b0("C:\\vog\\1_code\\palantir\\palantir\\graphics\\gfxGeometryPieceMorphed.cpp"

                           ,0x2e1,

                           "Vertex Buffer usage flagged as system memory for hardware morphing!"),

     iVar5 == 3)) {

    pFVar6 = fopen("c:\\VOGCRASH.txt","w");

    if (pFVar6 != (FILE *)0x0) {

      fprintf(pFVar6,"errReport::Massive failure EH_Abort: F:%s l:%d s:%d d:%s\n",

              "C:\\vog\\1_code\\palantir\\palantir\\graphics\\gfxGeometryPieceMorphed.cpp",0x2e1,3,

              "Vertex Buffer usage flagged as system memory for hardware morphing!");

      fclose(pFVar6);

    }

    raise(0x16);

                    /* WARNING: Subroutine does not return */

    ExitProcess(3);

  }

  local_4 = CONCAT31(local_4._1_3_,1);

  if (*(int *)(param_1 + 0x14) == 0) {

    uVar9 = 0;

  }

  else {

    uVar9 = *(uint32_t /* width from decompiler */ *)(*(int *)(param_1 + 0x14) + 0x18);

  }

  FUN_00414c20(uVar9,local_24,local_30,0);

  FUN_0044bbc0(param_1 + 0x10,param_1 + 8,0);

  *(uint *)(param_1 + 0xbc) = *(uint *)(param_1 + 0xbc) | 1;

  piVar2 = *(int **)(param_1 + 0x14);

  if (piVar2 != (int *)0x0) {

    piVar4 = piVar2 + 1;

    *piVar4 = *piVar4 + -1;

    if (*piVar4 == 0) {

      (**(code **)(*piVar2 + 8))();

    }

  }

  *(uint32_t /* width from decompiler */ *)(param_1 + 0x14) = 0;

  iVar5 = *(int *)(param_1 + 0xd4);

  if (iVar5 != *(int *)(param_1 + 0xd8)) {

    do {

      iVar7 = *(int *)(iVar5 + 4);

      if (iVar7 == 0) {

        uVar9 = 0;

      }

      else {

        uVar9 = *(uint32_t /* width from decompiler */ *)(iVar7 + 0x18);

      }

      FUN_00414c20(uVar9,iVar7 + 0x24,local_30,0);

      iVar7 = *(int *)(iVar5 + 4);

      if ((*(int *)(iVar7 + 0x10) == 0) ||

         (iVar7 = FUN_00746520(*(uint32_t /* width from decompiler */ *)(iVar7 + 0x14),*(uint32_t /* width from decompiler */ *)(iVar7 + 0x18),4),

         iVar7 == 0)) {

        piVar2 = *(int **)(*(int *)(iVar5 + 4) + 0x10);

        if ((piVar2 != (int *)0x0) && (piVar4 = (int *)*piVar2, piVar4 != (int *)0x0)) {

          piVar1 = piVar2 + 4;

          *piVar1 = *piVar1 + -1;

          if (*piVar1 < 0) {

            vog_LogMessage("C:\\vog\\1_code\\palantir\\palantir\\graphics\\gfxDeviceVB.cpp",0xd3,1,

                           "Call to gfxDeviceVB::Unlock more times than locked! Bad mojo...");

            piVar2[4] = 0;

          }

          else {

            (**(code **)(*piVar4 + 0x30))(piVar4);

          }

        }

        iVar5 = FUN_0076d1b0("C:\\vog\\1_code\\palantir\\palantir\\graphics\\gfxGeometryPieceMorphed.cpp"

                             ,0x2fe,

                             "Error locking Target\'s Source Vertex buffer in PrepareForHardwareMorphing!"

                            );

        if (iVar5 != 3) {

          local_4 = local_4 & 0xffffff00;

          FUN_00414b60();

          ExceptionList = pvStack_c;

          return;

        }

        pFVar6 = fopen("c:\\VOGCRASH.txt","w");

        if (pFVar6 != (FILE *)0x0) {

          fprintf(pFVar6,"errReport::Massive failure EH_Abort: F:%s l:%d s:%d d:%s\n",

                  "C:\\vog\\1_code\\palantir\\palantir\\graphics\\gfxGeometryPieceMorphed.cpp",0x2fe

                  ,3,"Error locking Target\'s Source Vertex buffer in PrepareForHardwareMorphing!");

          fclose(pFVar6);

        }

        raise(0x16);

                    /* WARNING: Subroutine does not return */

        ExitProcess(3);

      }

      iVar3 = *(int *)(iVar5 + 4);

      if ((iVar3 == 0) || (*(int *)(iVar3 + 0x10) == 0)) {

        uVar9 = 0;

      }

      else {

        uVar9 = *(uint32_t /* width from decompiler */ *)(*(int *)(iVar3 + 0x10) + 8);

      }

      if (iVar3 == 0) {

        uVar8 = 0;

      }

      else {

        uVar8 = *(uint32_t /* width from decompiler */ *)(iVar3 + 0x18);

      }

      iVar7 = FUN_00440110(iVar7,uVar8,uVar9);

      if (iVar7 == -1) {

        piVar2 = *(int **)(*(int *)(iVar5 + 4) + 0x10);

        if ((piVar2 != (int *)0x0) && (piVar4 = (int *)*piVar2, piVar4 != (int *)0x0)) {

          piVar1 = piVar2 + 4;

          *piVar1 = *piVar1 + -1;

          if (*piVar1 < 0) {

            vog_LogMessage("C:\\vog\\1_code\\palantir\\palantir\\graphics\\gfxDeviceVB.cpp",0xd3,1,

                           "Call to gfxDeviceVB::Unlock more times than locked! Bad mojo...");

            piVar2[4] = 0;

          }

          else {

            (**(code **)(*piVar4 + 0x30))(piVar4);

          }

        }

        vog_LogMessage("C:\\vog\\1_code\\palantir\\palantir\\graphics\\gfxGeometryPieceMorphed.cpp",

                       0x30a,3,

                       "Error locking Target\'s Destination Vertex buffer in PrepareForHardwareMorphing!"

                      );

        local_4 = local_4 & 0xffffff00;

        FUN_00414b60();

        ExceptionList = pvStack_c;

        return;

      }

      piVar2 = *(int **)(*(int *)(iVar5 + 4) + 0x10);

      if ((piVar2 != (int *)0x0) && (piVar4 = (int *)*piVar2, piVar4 != (int *)0x0)) {

        piVar1 = piVar2 + 4;

        *piVar1 = *piVar1 + -1;

        if (*piVar1 < 0) {

          vog_LogMessage("C:\\vog\\1_code\\palantir\\palantir\\graphics\\gfxDeviceVB.cpp",0xd3,1,

                         "Call to gfxDeviceVB::Unlock more times than locked! Bad mojo...");

          piVar2[4] = 0;

        }

        else {

          (**(code **)(*piVar4 + 0x30))(piVar4);

        }

      }

      piVar2 = *(int **)(iVar5 + 4);

      if (piVar2 != (int *)0x0) {

        piVar4 = piVar2 + 1;

        *piVar4 = *piVar4 + -1;

        if (*piVar4 == 0) {

          (**(code **)(*piVar2 + 8))();

        }

      }

      *(uint32_t /* width from decompiler */ *)(iVar5 + 4) = 0;

      iVar5 = iVar5 + 8;

    } while (iVar5 != *(int *)(param_1 + 0xd8));

  }

  piVar2 = *(int **)(param_1 + 0xe4);

  if (piVar2 != (int *)0x0) {

    piVar4 = piVar2 + 1;

    *piVar4 = *piVar4 + -1;

    if (*piVar4 == 0) {

      (**(code **)(*piVar2 + 8))();

    }

    *(uint32_t /* width from decompiler */ *)(param_1 + 0xe4) = 0;

  }

  *(uint *)(param_1 + 0xbc) = *(uint *)(param_1 + 0xbc) & 0xffffffef;

  local_4 = local_4 & 0xffffff00;

  uStack_14 = 0;

  uStack_10 = 0;

  if (pvStack_20 != (void *)0x0) {

                    /* WARNING: Subroutine does not return */

    operator_delete(pvStack_20);

  }

  ExceptionList = pvStack_c;

  return;

}
