// =============================================================================
// FUN_007f9e90
// -----------------------------------------------------------------------------
// Stable ID: aa_007f9e90
// Address:   0x007f9e90  (autoassault.exe, image base 0x400000)
// System:    unknown
// Generated: 2026-07-23 from raw capture (scaffold; refine for important units)
// Exactness: Behavior-preserving rewrite of decompiler control flow. Not modernization.
// Bit-for-bit vs retail EXE: DEFERRED (loaded image may differ slightly).
// =============================================================================

// PURPOSE (auto): Scaffold unit for FUN_007f9e90 @ 0x007f9e90
// Stable ID: aa_007f9e90
// Embedded strings (evidence for future rename):
//   - "VOG_DEBUG_STOP"
// Readability: control flow preserved from Ghidra decompile; types tentative.

// READABILITY (auto CF):
//  - Body size: ~177 non-empty decompiler lines.
//  - Control keywords: if×28, return×5, goto×3, for×2, do×2, while×2.
//  - Notable callees: FUN_0040eba0, FUN_004c77b0, FUN_007a4480, FUN_007f9cc0, FUN_007f9e90.
//  - Strings: "VOG_DEBUG_STOP".
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

uint32_t /* width from decompiler */ FUN_007f9e90(int param_1)



{

  byte *pbVar1;

  int *piVar2;

  byte bVar3;

  int iVar4;

  uint32_t /* width from decompiler */ *puVar5;

  uint uVar6;

  int *unaff_EBX;

  uint32_t /* width from decompiler */ *puVar7;

  uint32_t /* width from decompiler */ *puVar8;

  int iVar9;

  int local_14;

  int local_10;

  int local_c;

  uint uStack_8;

  uint8_t auStack_4 [4];

  

  if ((*(int *)(param_1 + 0x534) == 0) ||

     (((*(int *)(param_1 + 0x4f0) != 0 && (*(int *)(param_1 + 0x4f0) != 7)) ||

      (DAT_00d1b213 == '\0')))) {

    return 0;

  }

  local_10 = 0xff;

  local_14 = 0;

  local_c = 0;

  if ((DAT_00d1b6d8 != 0) && (*(int *)(DAT_00d1b6d8 + 0x250) != 0)) {

    if ((*(int *)(*(int *)(DAT_00d1b6d8 + 0x250) + 0x244) == 0) ||

       (iVar4 = (**(code **)(*(int *)(*(int *)(*(int *)(DAT_00d1b6d8 + 4) + 4) + 4 + DAT_00d1b6d8) +

                            0x1ac))(), iVar4 == 0)) {

      FUN_007a4480(0,"VOG_DEBUG_STOP");

    }

    iVar4 = (**(code **)(*(int *)(*(int *)(*(int *)(DAT_00d1b6d8 + 4) + 4) + 4 + DAT_00d1b6d8) +

                        0x1ac))();

    if (iVar4 == 0) {

      local_10 = 0xff;

    }

    else {

      piVar2 = (int *)(*(int *)(*(int *)(DAT_00d1b6d8 + 4) + 4) + 4 + DAT_00d1b6d8);

      iVar4 = (**(code **)(*(int *)(*(int *)(*(int *)(DAT_00d1b6d8 + 4) + 4) + 4 + DAT_00d1b6d8) +

                          0x1b0))();

      local_10 = (**(code **)(*piVar2 + 0x1ac))();

      local_10 = (iVar4 * 0xff) / local_10;

    }

    iVar4 = *(int *)(DAT_00d1b6d8 + 0x250);

    if (*(int *)(iVar4 + 0x244) == 0) {

      local_14 = 0;

    }

    else {

      local_14 = (*(int *)(iVar4 + 0x150) * 0x7f) / *(int *)(iVar4 + 0x244);

      if (0x7f < local_14) {

        local_14 = 0x7f;

      }

    }

    if ((*(char *)(*(int *)(*(int *)(*(int *)(*(int *)(DAT_00d1b6d8 + 4) + 4) + 0xac + DAT_00d1b6d8)

                           + 0x3c) + 0x532) == '\0') && (*(int *)(iVar4 + 0x148) != 0)) {

      local_c = (*(int *)(*(int *)(DAT_00d1b6d8 + 0x250) + 0x144) * 0xff) /

                *(int *)(*(int *)(DAT_00d1b6d8 + 0x250) + 0x148);

    }

  }

  if ((((local_10 == *(int *)(param_1 + 0x580)) && (local_14 == *(int *)(param_1 + 0x584))) &&

      (*(int *)(param_1 + 0x588) == 0)) && (local_c == *(int *)(param_1 + 0x58c))) {

    return 1;

  }

  *(int *)(param_1 + 0x580) = local_10;

  *(int *)(param_1 + 0x584) = local_14;

  *(uint32_t /* width from decompiler */ *)(param_1 + 0x588) = 0;

  *(int *)(param_1 + 0x58c) = local_c;

  if (DAT_00d1b6d8 == 0) {

    FUN_007f9cc0();

  }

  else {

    puVar5 = (uint32_t /* width from decompiler */ *)FUN_0040eba0(0,0);

    if (puVar5 != (uint32_t /* width from decompiler */ *)0x0) {

      iVar4 = 0x400;

      puVar7 = *(uint32_t /* width from decompiler */ **)(param_1 + 0x538);

      puVar8 = puVar5;

      if (*(uint32_t /* width from decompiler */ **)(param_1 + 0x538) == (uint32_t /* width from decompiler */ *)0x0) {

        for (; iVar4 != 0; iVar4 = iVar4 + -1) {

          *puVar8 = 0;

          puVar8 = puVar8 + 1;

        }

      }

      else {

        for (; iVar4 != 0; iVar4 = iVar4 + -1) {

          *puVar8 = *puVar7;

          puVar7 = puVar7 + 1;

          puVar8 = puVar8 + 1;

        }

      }

      if (((*(int *)(param_1 + 0x53c) != 0) && (DAT_00d1b6d8 != 0)) &&

         (*(int *)(DAT_00d1b6d8 + 0x250) != 0)) {

        FUN_004c77b0(&uStack_8,(float)local_10 * DAT_00aaa7a8);

        iVar4 = 0;

        do {

          iVar9 = 0x20;

          do {

            pbVar1 = (byte *)(iVar4 + *(int *)(param_1 + 0x53c));

            if (*pbVar1 == 0) {

              if (pbVar1[1] == 0) {

                bVar3 = pbVar1[2];

                if (bVar3 != 0) {

                  if (local_14 < (int)(uint)bVar3) {

                    if ((bVar3 < 0x80) || (local_14 + 0x80 < (int)(uint)bVar3)) goto LAB_007fa1cc;

                    *(uint8_t *)(iVar4 + 2 + (int)puVar5) = 0xff;

                  }

                  else {

                    *(uint8_t *)(iVar4 + 2 + (int)puVar5) = 0x1f;

                  }

LAB_007fa1c8:

                  *(uint8_t *)(iVar4 + 3 + (int)puVar5) = 0xff;

                }

              }

              else if ((int)(uint)pbVar1[1] <= local_10) {

                uVar6 = (uint)*(byte *)(iVar4 + (int)puVar5) + (uStack_8 & 0xff);

                if (0xff < uVar6) {

                  uVar6 = 0xff;

                }

                *(char *)(iVar4 + (int)puVar5) = (char)uVar6;

                uVar6 = (uint)*(byte *)(iVar4 + 1 + (int)puVar5) + (uStack_8 >> 8 & 0xff);

                if (0xff < uVar6) {

                  uVar6 = 0xff;

                }

                *(char *)(iVar4 + 1 + (int)puVar5) = (char)uVar6;

                uVar6 = (uStack_8 >> 0x10 & 0xff) + (uint)*(byte *)(iVar4 + 2 + (int)puVar5);

                if (0xff < uVar6) {

                  uVar6 = 0xff;

                }

                *(char *)(iVar4 + 2 + (int)puVar5) = (char)uVar6;

                goto LAB_007fa1c8;

              }

            }

            else if ((int)(uint)*pbVar1 <= local_c) {

              *(uint8_t *)(iVar4 + (int)puVar5) = 0xff;

              *(uint8_t *)(iVar4 + 1 + (int)puVar5) = 0xaf;

              goto LAB_007fa1c8;

            }

LAB_007fa1cc:

            iVar4 = iVar4 + 4;

            iVar9 = iVar9 + -1;

          } while (iVar9 != 0);

        } while (iVar4 < 0x1000);

      }

    }

    iVar4 = **(int **)(param_1 + 0x534);

    if (iVar4 != 0) {

      uVar6 = *(uint *)(iVar4 + 0x2c) & 0xf;

      if (uVar6 == 1) {

        (**(code **)(**(int **)(iVar4 + 0x10) + 0x50))(*(int **)(iVar4 + 0x10),0);

      }

      else if (uVar6 == 2) {

        (**(code **)(**(int **)(iVar4 + 0x10) + 0x50))

                  (*(int **)(iVar4 + 0x10),*(uint32_t /* width from decompiler */ *)(iVar4 + 0x3c),0);

      }

      else if (uVar6 == 4) {

        (**(code **)(**(int **)(iVar4 + 0x10) + 0x50))(*(int **)(iVar4 + 0x10),0);

      }

      *(uint32_t /* width from decompiler */ *)(iVar4 + 0x38) = 0xffffffff;

      *(uint32_t /* width from decompiler */ *)(iVar4 + 0x3c) = 0xffffffff;

      *(uint32_t /* width from decompiler */ *)(iVar4 + 0x40) = 0;

      *(uint32_t /* width from decompiler */ *)(iVar4 + 0x44) = 0;

    }

    piVar2 = *(int **)(**(int **)(param_1 + 0x534) + 0x10);

    iVar4 = (**(code **)(*piVar2 + 0x48))(piVar2,0,auStack_4);

    if (-1 < iVar4) {

      (**(code **)(*(int *)*DAT_00d1f044 + 0x28))

                ((int *)*DAT_00d1f044,

                 *(uint32_t /* width from decompiler */ *)(param_1 + 0x540 + *(int *)(param_1 + 0x4f0) * 8),

                 *(uint32_t /* width from decompiler */ *)(param_1 + 0x544 + *(int *)(param_1 + 0x4f0) * 8),local_10);

      if (unaff_EBX == (int *)0x0) {

        return 1;

      }

      (**(code **)(*unaff_EBX + 8))(unaff_EBX);

      return 1;

    }

  }

  return 0;

}
