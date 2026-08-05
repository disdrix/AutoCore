// =============================================================================
// FUN_00724d70
// -----------------------------------------------------------------------------
// Stable ID: aa_00724d70
// Address:   0x00724d70  (autoassault.exe, image base 0x400000)
// System:    unknown
// Generated: 2026-07-23 from raw capture (scaffold; refine for important units)
// Exactness: Behavior-preserving rewrite of decompiler control flow. Not modernization.
// Bit-for-bit vs retail EXE: DEFERRED (loaded image may differ slightly).
// =============================================================================

// PURPOSE (auto): Scaffold unit for FUN_00724d70 @ 0x00724d70
// Stable ID: aa_00724d70
// No high-value strings recovered; name via xrefs/callers in follow-up.
// Readability: control flow preserved from Ghidra decompile; types tentative.

// READABILITY (auto CF):
//  - Body size: ~190 non-empty decompiler lines.
//  - Control keywords: if×35, goto×4, do×1, switch×1, while×1, return×1.
//  - Notable callees: FUN_004801d0×7, FUN_00724bc0×5, ROUND×3, FUN_0071f760, FUN_007227e0, FUN_007228a0, FUN_00724d70.
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



void FUN_00724d70(float param_1)



{

  float *pfVar1;

  float fVar2;

  int *piVar3;

  int in_EAX;

  uint uVar4;

  int iVar5;

  uint uVar6;

  int extraout_EDX;

  int iVar7;

  float10 fVar8;

  float fVar9;

  

  fVar9 = DAT_00aaa7ac;

  uVar4 = *(int *)(in_EAX + 0x2f0) - 2000;

  if ((*(char *)(in_EAX + 600) != '\0') && (*(char *)(in_EAX + 0x2ec) != '\0')) {

    *(uint8_t *)(in_EAX + 0x2f6) = 1;

    if ((*(float *)(in_EAX + 0x2fc) <= fVar9) || (*(char *)(in_EAX + 0x301) != '\0')) {

      *(uint8_t *)(in_EAX + 0x2f9) = 0;

    }

    else {

      *(uint8_t *)(in_EAX + 0x2f9) = 1;

    }

    iVar7 = 0;

    do {

      switch(iVar7) {

      case 0:

        if (*(char *)(in_EAX + 0x2f6) == '\0') {

LAB_00724e86:

          FUN_007228a0(param_1);

        }

        else {

          FUN_00724bc0(0,0);

        }

        break;

      case 1:

        if ((*(char *)(in_EAX + 0x2f7) != '\0') &&

           (*(float *)(in_EAX + 0x2fc) <= DAT_00aaa870 && DAT_00aaa870 != *(float *)(in_EAX + 0x2fc)

           )) {

          FUN_00724bc0(1,0);

        }

        break;

      case 2:

        if (*(char *)(in_EAX + 0x2f8) != '\0') {

          FUN_00724bc0(2,0);

          *(uint8_t *)(in_EAX + 0x2f8) = 0;

        }

        break;

      case 3:

        if (*(char *)(in_EAX + 0x2f9) == '\0') goto LAB_00724e86;

        FUN_00724bc0(3,0);

        break;

      case 4:

        if (*(char *)(in_EAX + 0x300) == '\0') goto LAB_00724e86;

        FUN_00724bc0(4,0);

      }

      if ((*(int *)(in_EAX + 0x2a8 + iVar7 * 4) != 0) && (iVar5 = FUN_0071f760(1), iVar5 != 0)) {

        iVar5 = *(int *)(in_EAX + 0x2a8 + iVar7 * 4);

        piVar3 = *(int **)(iVar5 + 0x10);

        if ((piVar3 != (int *)0x0) &&

           ((*(int *)(iVar5 + 0x1c) != 0 && (piVar3 = (int *)*piVar3, piVar3 != (int *)0x0)))) {

          if (iVar7 == 0) {

            if (DAT_00aaa7ac < *(float *)(in_EAX + 0x250)) {

              *(float *)(in_EAX + 0x250) = DAT_00aaa7ac;

            }

            uVar6 = (int)ROUND(*(float *)(*(int *)(in_EAX + 0x2a8) + 0x1bc) *

                               *(float *)(in_EAX + 0x250)) + *(int *)(in_EAX + 0x304);

            if (uVar4 < uVar6) {

              uVar6 = uVar4;

            }

            fVar9 = (float)(int)uVar6;

            if ((int)uVar6 < 0) {

              fVar9 = fVar9 + _DAT_00aaa5dc;

            }

            fVar2 = (float)(int)uVar4;

            if ((int)uVar4 < 0) {

              fVar2 = fVar2 + _DAT_00aaa5dc;

            }

            FUN_004801d0((fVar9 / fVar2) * *(float *)(in_EAX + 0x2dc) * *(float *)(in_EAX + 0x2d8));

            (**(code **)(*piVar3 + 0x44))(piVar3,uVar6);

          }

          else if (iVar7 == 1) {

            iVar5 = *(int *)(in_EAX + 0x2ac);

            if ((*(float *)(iVar5 + 0x1a4) != 0.0) || (*(float *)(iVar5 + 0x1b0) != 0.0)) {

              uVar6 = (int)ROUND(*(float *)(iVar5 + 0x1bc) * *(float *)(in_EAX + 0x250)) +

                      *(int *)(in_EAX + 0x304);

              if (DAT_00aaa7ac < *(float *)(in_EAX + 0x250)) {

                *(float *)(in_EAX + 0x250) = DAT_00aaa7ac;

              }

              if (uVar4 < uVar6) {

                uVar6 = uVar4;

              }

              if (*(char *)(in_EAX + 0x2f7) == '\0') {

                fVar9 = (float)(int)uVar6;

                if ((int)uVar6 < 0) {

                  fVar9 = fVar9 + _DAT_00aaa5dc;

                }

                fVar2 = (float)(int)uVar4;

                if ((int)uVar4 < 0) {

                  fVar2 = fVar2 + _DAT_00aaa5dc;

                }

                *(float *)(*(int *)(in_EAX + 0x2ac) + 0x1b0) =

                     (fVar9 / fVar2) *

                     *(float *)(in_EAX + 0x2dc) * *(float *)(in_EAX + 0x2d8) *

                     g_flDisplayRateScaleOneThird;

              }

              else {

                *(float *)(*(int *)(in_EAX + 0x2ac) + 0x1b0) =

                     *(float *)(in_EAX + 0x2dc) * *(float *)(in_EAX + 0x2d8);

              }

              (**(code **)(*piVar3 + 0x44))(piVar3,uVar6);

              if (*(float *)(*(int *)(in_EAX + 0x2ac) + 0x1a4) !=

                  *(float *)(*(int *)(in_EAX + 0x2ac) + 0x1b0)) {

                fVar9 = *(float *)(*(int *)(in_EAX + 0x2ac) + 0x1b0);

                pfVar1 = (float *)(*(int *)(in_EAX + 0x2ac) + 0x1a4);

                if (fVar9 < *pfVar1 || fVar9 == *pfVar1) {

                  if (*(float *)(*(int *)(in_EAX + 0x2ac) + 0x1a4) <=

                      *(float *)(*(int *)(in_EAX + 0x2ac) + 0x1b0) - DAT_00aaa8fc)

                  goto LAB_0072512d;

                  fVar9 = DAT_00aaa8fc;

                  if (param_1 < DAT_00aaa8fc) {

                    fVar9 = param_1;

                  }

                  FUN_004801d0(*(float *)(*(int *)(in_EAX + 0x2ac) + 0x1a4) - fVar9);

                  iVar5 = *(int *)(in_EAX + 0x2ac);

                  if (*(float *)(iVar5 + 0x1a4) <= *(float *)(iVar5 + 0x1b0) &&

                      *(float *)(iVar5 + 0x1b0) != *(float *)(iVar5 + 0x1a4)) {

                    FUN_004801d0(*(uint32_t /* width from decompiler */ *)(iVar5 + 0x1b0));

                  }

                }

                else {

                  fVar9 = param_1;

                  if (DAT_00aaa8fc <= param_1) {

                    fVar9 = DAT_00aaa8fc;

                  }

                  FUN_004801d0(*(float *)(*(int *)(in_EAX + 0x2ac) + 0x1a4) + fVar9);

                  fVar9 = *(float *)(*(int *)(in_EAX + 0x2ac) + 0x1a4);

                  pfVar1 = (float *)(*(int *)(in_EAX + 0x2ac) + 0x1b0);

                  if (*pfVar1 <= fVar9 && fVar9 != *pfVar1) {

LAB_0072512d:

                    FUN_004801d0(*(uint32_t /* width from decompiler */ *)(*(int *)(in_EAX + 0x2ac) + 0x1b0));

                  }

                }

              }

            }

          }

          else {

            fVar9 = param_1;

            if (iVar7 == 3) {

              if (*(char *)(in_EAX + 0x2f9) != '\0') {

                fVar2 = *(float *)(*(int *)(in_EAX + 0x2b4) + 0x1b0);

                pfVar1 = (float *)(*(int *)(in_EAX + 0x2b4) + 0x1a4);

                if (*pfVar1 <= fVar2 && fVar2 != *pfVar1) {

                  if (DAT_00aaa8fc <= param_1) {

                    fVar9 = DAT_00aaa8fc;

                  }

                  iVar5 = *(int *)(in_EAX + 0x2b4);

                  goto LAB_00724f65;

                }

                if (DAT_00aaa8fc <= param_1) {

                  fVar9 = DAT_00aaa8fc;

                }

                FUN_004801d0(*(float *)(*(int *)(in_EAX + 0x2b4) + 0x1a4) - fVar9);

              }

            }

            else {

              iVar5 = *(int *)(in_EAX + 0x2a8 + iVar7 * 4);

              fVar2 = *(float *)(iVar5 + 0x1b0);

              pfVar1 = (float *)(iVar5 + 0x1a4);

              if (*pfVar1 <= fVar2 && fVar2 != *pfVar1) {

                if (DAT_00aaa8fc <= param_1) {

                  fVar9 = DAT_00aaa8fc;

                }

                iVar5 = *(int *)(in_EAX + 0x2a8 + iVar7 * 4);

LAB_00724f65:

                FUN_004801d0(*(float *)(iVar5 + 0x1a4) + fVar9);

              }

            }

          }

          fVar8 = (float10)FUN_007227e0(*(uint32_t /* width from decompiler */ *)

                                         (*(int *)(in_EAX + 0x2a8 + iVar7 * 4) + 0x1a4));

          (**(code **)(extraout_EDX + 0x3c))(piVar3,(int)ROUND(fVar8));

        }

      }

      iVar7 = iVar7 + 1;

    } while (iVar7 < 5);

  }

  return;

}
