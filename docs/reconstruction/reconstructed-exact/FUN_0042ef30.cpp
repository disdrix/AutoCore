// =============================================================================
// FUN_0042ef30
// -----------------------------------------------------------------------------
// Stable ID: aa_0042ef30
// Address:   0x0042ef30  (autoassault.exe, image base 0x400000)
// System:    unknown
// Generated: 2026-07-23 from raw capture (scaffold; refine for important units)
// Exactness: Behavior-preserving rewrite of decompiler control flow. Not modernization.
// Bit-for-bit vs retail EXE: DEFERRED (loaded image may differ slightly).
// =============================================================================

// PURPOSE (auto): Scaffold unit for FUN_0042ef30 @ 0x0042ef30
// Stable ID: aa_0042ef30
// Embedded strings (evidence for future rename):
//   - "LogNetInterface"
//   - "Received punch packet from %s - %s"
//   - "Punch from %s matched nonces - connecting..."
// Readability: control flow preserved from Ghidra decompile; types tentative.

// READABILITY (auto CF):
//  - Body size: ~390 non-empty decompiler lines.
//  - Control keywords: if×58, while×12, goto×10, do×7, return×1.
//  - Notable callees: BitStream_readBits×2, FUN_0040b290×2, FUN_00783aa0×2, FUN_00783b60×2, FUN_007845c0×2, FUN_00424d10, FUN_0042bd10, FUN_0042be80.
//  - Strings: "LogNetInterface"; "Received punch packet from %s - %s"; "Punch from %s matched nonces - connecting...".
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



void FUN_0042ef30(int param_1,int *param_2,int param_3)



{

  uint uVar1;

  int *piVar2;

  uint32_t /* width from decompiler */ *puVar3;

  byte bVar4;

  char cVar5;

  int *piVar6;

  uint32_t /* width from decompiler */ uVar7;

  short *psVar8;

  void *pvVar9;

  uint32_t /* width from decompiler */ *puVar10;

  void *pvVar11;

  int *piVar12;

  int iVar13;

  int iVar14;

  int *piVar15;

  uint uVar16;

  void **ppvVar17;

  bool bVar18;

  int local_2a8;

  int local_2a4;

  void *local_2a0 [2];

  undefined **local_298;

  uint32_t /* width from decompiler */ local_294;

  uint32_t /* width from decompiler */ local_290;

  int *local_28c;

  uint32_t /* width from decompiler */ local_288;

  uint8_t local_284;

  int local_280 [2];

  uint8_t local_278 [4];

  uint32_t /* width from decompiler */ *local_274;

  

  piVar15 = (int *)0x0;

  BitStream_readBits(0x40,local_280);

  local_294 = 0;

  local_290 = 0;

  local_298 = &PTR_LAB_009d7b00;

  local_288 = 8;

  local_28c = local_280;

  local_284 = 0;

  if ((_DAT_00d21818 & 1) == 0) {

    _DAT_00d21818 = _DAT_00d21818 | 1;

    DAT_00d21814 = FUN_00783b60("LogNetInterface");

  }

  if (*(char *)(DAT_00d21814 + 4) != '\0') {

    DAT_00d179a0 = DAT_00d21814;

    piVar6 = (int *)FUN_00974c00(&local_298);

    uVar7 = FUN_007845c0(*(uint32_t /* width from decompiler */ *)(*piVar6 + 0xc));

    FUN_00783aa0("Received punch packet from %s - %s",uVar7);

    FUN_0040b290();

    DAT_00d179a0 = 0;

  }

  local_2a4 = 0;

  if (0 < *(int *)(param_1 + 0x24)) {

    do {

      piVar15 = *(int **)(*(int *)(param_1 + 0x2c) + local_2a4 * 4);

      if (piVar15[0x6e] == 2) {

        if ((char)piVar15[0x65] == '\0') {

LAB_0042f048:

          iVar13 = 2;

          bVar18 = true;

          piVar6 = local_280;

          piVar12 = piVar15 + 0x4e;

          do {

            if (iVar13 == 0) break;

            iVar13 = iVar13 + -1;

            bVar18 = *piVar6 == *piVar12;

            piVar6 = piVar6 + 1;

            piVar12 = piVar12 + 1;

          } while (bVar18);

          if (bVar18) {

LAB_0042f068:

            iVar13 = piVar15[0x62];

            iVar14 = 0;

            if (0 < iVar13) {

              psVar8 = (short *)piVar15[100];

              iVar14 = 0;

              do {

                if ((((((short)*param_2 == *psVar8) && (*(short *)((int)param_2 + 2) == psVar8[1]))

                     && (param_2[1] == *(int *)(psVar8 + 2))) &&

                    ((param_2[2] == *(int *)(psVar8 + 4) && (param_2[3] == *(int *)(psVar8 + 6)))))

                   && (param_2[4] == *(int *)(psVar8 + 8))) break;

                iVar14 = iVar14 + 1;

                psVar8 = psVar8 + 10;

              } while (iVar14 < iVar13);

            }

            if (iVar14 == iVar13) {

              iVar14 = 0;

              if (0 < iVar13) {

                psVar8 = (short *)piVar15[100];

                do {

                  if ((((short)*param_2 == *psVar8) && (param_2[1] == *(int *)(psVar8 + 2))) &&

                     ((param_2[2] == *(int *)(psVar8 + 4) &&

                      ((param_2[3] == *(int *)(psVar8 + 6) && (param_2[4] == *(int *)(psVar8 + 8))))

                      ))) break;

                  iVar14 = iVar14 + 1;

                  psVar8 = psVar8 + 10;

                } while (iVar14 < iVar13);

              }

              if (iVar14 == iVar13) goto LAB_0042f21e;

              if (iVar13 < 5) {

                uVar16 = piVar15[0x62] + 1;

                if ((uint)piVar15[99] < uVar16) {

                  iVar13 = uVar16 + (0x10 - (uVar16 & 0xf));

                  pvVar9 = malloc(iVar13 * 0x14);

                  pvVar11 = (void *)piVar15[100];

                  local_2a8 = piVar15[0x62];

                  piVar15[100] = (int)pvVar9;

                  if (local_2a8 != 0) {

                    iVar14 = 0;

                    do {

                      puVar10 = (uint32_t /* width from decompiler */ *)(piVar15[100] + iVar14);

                      if (puVar10 != (uint32_t /* width from decompiler */ *)0x0) {

                        puVar3 = (uint32_t /* width from decompiler */ *)(iVar14 + (int)pvVar11);

                        *puVar10 = *puVar3;

                        puVar10[1] = puVar3[1];

                        puVar10[2] = puVar3[2];

                        puVar10[3] = puVar3[3];

                        puVar10[4] = puVar3[4];

                      }

                      iVar14 = iVar14 + 0x14;

                      local_2a8 = local_2a8 + -1;

                    } while (local_2a8 != 0);

                  }

                  piVar15[100] = (int)pvVar11;

                  local_2a0[0] = pvVar9;

                  free(pvVar11);

                  piVar15[100] = (int)pvVar9;

                  piVar15[99] = iVar13;

                }

                piVar15[0x62] = piVar15[0x62] + 1;

                piVar6 = (int *)(piVar15[100] + -0x14 + piVar15[0x62] * 0x14);

                if (piVar6 != (int *)0x0) {

                  *piVar6 = *param_2;

                  piVar6[1] = param_2[1];

                  piVar6[2] = param_2[2];

                  piVar6[3] = param_2[3];

                  piVar6[4] = param_2[4];

                }

              }

              cVar5 = (char)piVar15[0x65];

            }

            else {

              cVar5 = (char)piVar15[0x65];

            }

            if (cVar5 != '\0') break;

          }

        }

        else {

          iVar13 = 2;

          bVar18 = true;

          piVar6 = local_280;

          piVar12 = piVar15 + 0x50;

          do {

            if (iVar13 == 0) break;

            iVar13 = iVar13 + -1;

            bVar18 = *piVar6 == *piVar12;

            piVar6 = piVar6 + 1;

            piVar12 = piVar12 + 1;

          } while (bVar18);

          if (bVar18) {

            if ((char)piVar15[0x65] == '\0') goto LAB_0042f048;

            goto LAB_0042f068;

          }

        }

      }

LAB_0042f21e:

      local_2a4 = local_2a4 + 1;

    } while (local_2a4 < *(int *)(param_1 + 0x24));

  }

  if (local_2a4 == *(int *)(param_1 + 0x24)) goto LAB_0042f6a1;

  FUN_007838a0();

  cVar5 = FUN_0042bd10(param_3,5,local_278);

  if (cVar5 == '\0') {

    while (local_274 != (uint32_t /* width from decompiler */ *)0x0) {

      puVar10 = (uint32_t /* width from decompiler */ *)local_274[2];

      *local_274 = 0;

      local_274[1] = 0;

      local_274[2] = 0;

      local_274 = puVar10;

    }

    goto LAB_0042f6a1;

  }

  BitStream_readBits(0x40,local_2a0);

  iVar13 = 2;

  bVar18 = true;

  ppvVar17 = local_2a0;

  piVar6 = piVar15 + 0x4e;

  do {

    if (iVar13 == 0) break;

    iVar13 = iVar13 + -1;

    bVar18 = *ppvVar17 == (void *)*piVar6;

    ppvVar17 = ppvVar17 + 1;

    piVar6 = piVar6 + 1;

  } while (bVar18);

  if (!bVar18) {

    while (local_274 != (uint32_t /* width from decompiler */ *)0x0) {

      puVar10 = (uint32_t /* width from decompiler */ *)local_274[2];

      *local_274 = 0;

      local_274[1] = 0;

      local_274[2] = 0;

      local_274 = puVar10;

    }

    goto LAB_0042f6a1;

  }

  uVar16 = *(uint *)(param_3 + 0x18);

  if (*(uint *)(param_3 + 0x2c) < uVar16) {

    *(uint8_t *)(param_3 + 0x1c) = 1;

LAB_0042f30a:

    if (*(char *)((int)piVar15 + 0x136) != '\0') {

      *(uint8_t *)((int)piVar15 + 0x135) = 1;

    }

  }

  else {

    bVar4 = *(byte *)((uVar16 >> 3) + *(int *)(param_3 + 0xc));

    uVar1 = uVar16 + 1;

    *(uint *)(param_3 + 0x18) = uVar1;

    if ((bVar4 & (byte)(1 << ((byte)uVar16 & 7))) == 0) goto LAB_0042f30a;

    if (*(uint *)(param_3 + 0x2c) < uVar1) {

      *(uint8_t *)(param_3 + 0x1c) = 1;

LAB_0042f4e8:

      pvVar11 = operator_new(0x24);

      if (pvVar11 == (void *)0x0) {

        iVar13 = 0;

      }

      else {

        iVar13 = FUN_0042be80(param_3);

      }

      piVar6 = (int *)piVar15[0x55];

      if (piVar6 != (int *)0x0) {

        piVar12 = piVar6 + 2;

        *piVar12 = *piVar12 + -1;

        if (*piVar12 == 0) {

          (**(code **)(*piVar6 + 8))();

        }

      }

      piVar15[0x55] = iVar13;

      if (iVar13 != 0) {

        *(int *)(iVar13 + 8) = *(int *)(iVar13 + 8) + 1;

      }

      if ((*(char *)(piVar15[0x55] + 0x20) == '\0') ||

         (cVar5 = (**(code **)(*piVar15 + 0x1c))(piVar15[0x55],1), cVar5 == '\0')) {

        while (local_274 != (uint32_t /* width from decompiler */ *)0x0) {

          puVar10 = (uint32_t /* width from decompiler */ *)local_274[2];

          *local_274 = 0;

          local_274[1] = 0;

          local_274[2] = 0;

          local_274 = puVar10;

        }

        goto LAB_0042f6a1;

      }

    }

    else {

      bVar4 = *(byte *)((uVar1 >> 3) + *(int *)(param_3 + 0xc));

      *(uint *)(param_3 + 0x18) = uVar16 + 2;

      if ((bVar4 & (byte)(1 << ((byte)uVar1 & 7))) == 0) goto LAB_0042f4e8;

      pvVar11 = operator_new(0x2c);

      if (pvVar11 == (void *)0x0) {

        iVar13 = 0;

      }

      else {

        iVar13 = FUN_0042bf60(param_3);

      }

      piVar6 = (int *)piVar15[0x57];

      if (piVar6 != (int *)0x0) {

        piVar12 = piVar6 + 2;

        *piVar12 = *piVar12 + -1;

        if (*piVar12 == 0) {

          (**(code **)(*piVar6 + 8))();

        }

      }

      piVar15[0x57] = iVar13;

      if (iVar13 != 0) {

        *(int *)(iVar13 + 8) = *(int *)(iVar13 + 8) + 1;

      }

      if ((*(char *)(piVar15[0x57] + 0x24) == '\0') ||

         (cVar5 = (**(code **)(*piVar15 + 0x18))(piVar15[0x57],1), cVar5 == '\0')) {

        while (local_274 != (uint32_t /* width from decompiler */ *)0x0) {

          puVar10 = (uint32_t /* width from decompiler */ *)local_274[2];

          *local_274 = 0;

          local_274[1] = 0;

          local_274[2] = 0;

          local_274 = puVar10;

        }

        goto LAB_0042f6a1;

      }

      piVar6 = *(int **)(piVar15[0x57] + 0x18);

      if (piVar6 != (int *)0x0) {

        piVar6[2] = piVar6[2] + 1;

      }

      piVar12 = (int *)piVar15[0x55];

      if (piVar12 != (int *)0x0) {

        piVar2 = piVar12 + 2;

        *piVar2 = *piVar2 + -1;

        if (*piVar2 == 0) {

          (**(code **)(*piVar12 + 8))();

        }

      }

      piVar15[0x55] = (int)piVar6;

      if (piVar6 != (int *)0x0) {

        piVar6[2] = piVar6[2] + 1;

        piVar12 = piVar6 + 2;

        *piVar12 = *piVar12 + -1;

        if (*piVar12 == 0) {

          (**(code **)(*piVar6 + 8))();

        }

      }

    }

    if ((*(int *)(param_1 + 0x3c) == 0) ||

       (*(int *)(*(int *)(param_1 + 0x3c) + 0x10) != *(int *)(piVar15[0x55] + 0x10))) {

      pvVar11 = operator_new(0x24);

      if (pvVar11 == (void *)0x0) {

        iVar13 = 0;

      }

      else {

        iVar13 = FUN_0098ba20(*(uint32_t /* width from decompiler */ *)(piVar15[0x55] + 0x10));

      }

      piVar6 = (int *)piVar15[0x56];

      if (piVar6 != (int *)0x0) {

        piVar12 = piVar6 + 2;

        *piVar12 = *piVar12 + -1;

        if (*piVar12 == 0) {

          (**(code **)(*piVar6 + 8))();

        }

      }

      piVar15[0x56] = iVar13;

      if (iVar13 != 0) {

        *(int *)(iVar13 + 8) = *(int *)(iVar13 + 8) + 1;

      }

    }

    else {

      FUN_004300e0();

    }

    *(uint8_t *)((int)piVar15 + 0x135) = 1;

    piVar12 = (int *)FUN_0098b790(piVar15[0x56],local_2a0);

    piVar6 = (int *)piVar15[0x58];

    iVar13 = *piVar12;

    if (piVar6 != (int *)0x0) {

      piVar12 = piVar6 + 2;

      *piVar12 = *piVar12 + -1;

      if (*piVar12 == 0) {

        (**(code **)(*piVar6 + 8))();

      }

    }

    piVar15[0x58] = iVar13;

    if (iVar13 != 0) {

      *(int *)(iVar13 + 8) = *(int *)(iVar13 + 8) + 1;

    }

    FUN_0040b290();

  }

  if (*(char *)((int)piVar15 + 0x135) != '\0') {

    if (DAT_00d179d9 == '\0') {

      DAT_00d179d9 = '\x01';

      FUN_0077bc40(&DAT_00d0a3b8);

      FUN_0077bb70(&DAT_00d0a3b8);

    }

    FUN_0077bad0((int)piVar15 + 0x166,0x10,&DAT_00d0a3b8);

  }

  uVar16 = _DAT_00d21818 & 2;

  piVar15[0x3e] = *param_2;

  piVar15[0x3f] = param_2[1];

  piVar15[0x40] = param_2[2];

  piVar15[0x41] = param_2[3];

  piVar15[0x42] = param_2[4];

  if (uVar16 == 0) {

    _DAT_00d21818 = _DAT_00d21818 | 2;

    DAT_00d21810 = FUN_00783b60("LogNetInterface");

  }

  if (*(char *)(DAT_00d21810 + 4) != '\0') {

    DAT_00d179a0 = DAT_00d21810;

    uVar7 = FUN_007845c0();

    FUN_00783aa0("Punch from %s matched nonces - connecting...",uVar7);

    DAT_00d179a0 = 0;

  }

  piVar15[0x6e] = 4;

  piVar15[0x68] = 0;

  piVar15[0x69] = *(int *)(param_1 + 0x78);

  FUN_0042f6c0(param_1);

  while (local_274 != (uint32_t /* width from decompiler */ *)0x0) {

    puVar10 = (uint32_t /* width from decompiler */ *)local_274[2];

    *local_274 = 0;

    local_274[1] = 0;

    local_274[2] = 0;

    local_274 = puVar10;

  }

LAB_0042f6a1:

  FUN_00424d10();

  return;

}
