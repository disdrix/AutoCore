// =============================================================================
// FUN_0096b470
// -----------------------------------------------------------------------------
// Stable ID: aa_0096b470
// Address:   0x0096b470  (autoassault.exe, image base 0x400000)
// System:    unknown
// Generated: 2026-07-23 from raw capture (scaffold; refine for important units)
// Exactness: Behavior-preserving rewrite of decompiler control flow. Not modernization.
// Bit-for-bit vs retail EXE: DEFERRED (loaded image may differ slightly).
// =============================================================================

// PURPOSE (auto): Scaffold unit for FUN_0096b470 @ 0x0096b470
// Stable ID: aa_0096b470
// Embedded strings (evidence for future rename):
//   - "Skeleton bone #%i (%s) has unnormalized quaternion (%f,%f,%f%f)\n"
// Readability: control flow preserved from Ghidra decompile; types tentative.

// READABILITY (auto CF):
//  - Body size: ~154 non-empty decompiler lines.
//  - Control keywords: if×13, do×9, while×9, return×1.
//  - Notable callees: FUN_0076c130×19, ABS, FUN_0040cf90, FUN_0040d1a0, FUN_0044b4f0, FUN_0076df50, FUN_0076f6e0, FUN_0076f970.
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



void FUN_0096b470(int param_1)



{

  void *_Memory;

  int *piVar1;

  int *piVar2;

  undefined *puVar3;

  int iVar4;

  int iVar5;

  float *pfVar6;

  int *piVar7;

  int iVar8;

  int *piVar9;

  bool bVar10;

  float fVar11;

  float fVar12;

  int local_44;

  int local_40;

  int local_24;

  int local_20;

  int local_1c;

  

  _Memory = (void *)FUN_0044b4f0();

  piVar2 = *(int **)(param_1 + 0xc);

  local_44 = 0;

  if (piVar2 != *(int **)(param_1 + 0x10)) {

    piVar7 = (int *)((int)_Memory + 0xb4);

    do {

      iVar4 = *piVar2;

      FUN_0076c130();

      iVar8 = *(int *)(iVar4 + 0x148);

      if (iVar8 < 0) {

        FUN_0076c130();

        FUN_0040d1a0();

        FUN_0040cf90();

      }

      else {

        FUN_0076c130();

        iVar5 = *(int *)(iVar4 + 0xf4);

        if (_DAT_00a240ec <=

            ABS(g_flOne - (*(float *)(iVar5 + 0x18) * *(float *)(iVar5 + 0x18) +

                          *(float *)(iVar5 + 0x14) * *(float *)(iVar5 + 0x14) +

                          *(float *)(iVar5 + 0x10) * *(float *)(iVar5 + 0x10) +

                          *(float *)(iVar5 + 0xc) * *(float *)(iVar5 + 0xc)))) {

          puVar3 = *(undefined **)(iVar5 + 8);

          if (*(undefined **)(iVar5 + 8) == (undefined *)0x0) {

            puVar3 = PTR_DAT_00afa2bc;

          }

          FUN_0076c130("Skeleton bone #%i (%s) has unnormalized quaternion (%f,%f,%f%f)\n",local_44,

                       puVar3,(double)*(float *)(iVar5 + 0xc),(double)*(float *)(iVar5 + 0x10),

                       (double)*(float *)(iVar5 + 0x14),(double)*(float *)(iVar5 + 0x18));

        }

        piVar7[2] = -1;

        *piVar7 = *piVar7 + 1;

        FUN_0076df50();

        if ((*(byte *)((int)_Memory + iVar8 * 0xc0 + 0xbc) & 1) != 0) {

          FUN_00972e50();

        }

        piVar7[2] = -1;

        *piVar7 = *piVar7 + 1;

        FUN_0076f6e0();

        piVar7[-9] = local_24;

        piVar7[-8] = local_20;

        piVar7[-7] = local_1c;

      }

      FUN_0076c130();

      iVar8 = 0;

      do {

        FUN_0076c130();

        iVar5 = 0;

        do {

          if ((*(byte *)(piVar7 + 2) & 1) != 0) {

            FUN_0076f970();

            piVar7[2] = piVar7[2] & 0xfffffffe;

          }

          FUN_0076c130();

          if (iVar5 < 3) {

            FUN_0076c130();

          }

          iVar5 = iVar5 + 1;

          iVar8 = iVar8 + 4;

        } while (iVar5 < 4);

        FUN_0076c130();

      } while (iVar8 < 0x40);

      iVar8 = 0x10;

      bVar10 = true;

      piVar1 = (int *)(*(int *)(iVar4 + 0xf4) + 0x40);

      piVar9 = &DAT_00afdf70;

      do {

        if (iVar8 == 0) break;

        iVar8 = iVar8 + -1;

        bVar10 = *piVar1 == *piVar9;

        piVar1 = piVar1 + 1;

        piVar9 = piVar9 + 1;

      } while (bVar10);

      if (!bVar10) {

        if (((uint)piVar7[2] >> 1 & 1) == 0) {

          piVar1 = piVar7 + -0x1d;

        }

        else {

          piVar1 = (int *)FUN_009730e0();

        }

        FUN_0076c130();

        fVar12 = 0.0;

        pfVar6 = (float *)(*(int *)(iVar4 + 0xf4) + 0x40);

        iVar8 = (int)piVar1 - (int)pfVar6;

        iVar4 = 4;

        do {

          iVar5 = 4;

          do {

            fVar11 = *(float *)(iVar8 + (int)pfVar6) - *pfVar6;

            pfVar6 = pfVar6 + 1;

            iVar5 = iVar5 + -1;

            fVar12 = fVar11 * fVar11 + fVar12;

          } while (iVar5 != 0);

          iVar4 = iVar4 + -1;

        } while (iVar4 != 0);

        if (DAT_00a10e78 <= fVar12) {

          FUN_0076c130();

          local_40 = 4;

          do {

            FUN_0076c130();

            iVar4 = 0;

            do {

              FUN_0076c130();

              if (iVar4 < 3) {

                FUN_0076c130();

              }

              iVar4 = iVar4 + 1;

            } while (iVar4 < 4);

            FUN_0076c130();

            iVar4 = 0;

            do {

              FUN_0076c130();

              if (iVar4 < 3) {

                FUN_0076c130();

              }

              iVar4 = iVar4 + 1;

            } while (iVar4 < 4);

            FUN_0076c130();

            local_40 = local_40 + -1;

          } while (local_40 != 0);

        }

        else {

          FUN_0076c130();

        }

      }

      local_44 = local_44 + 1;

      piVar7 = piVar7 + 0x30;

      piVar2 = piVar2 + 1;

    } while (piVar2 != *(int **)(param_1 + 0x10));

  }

  _aligned_free(_Memory);

  return;

}
