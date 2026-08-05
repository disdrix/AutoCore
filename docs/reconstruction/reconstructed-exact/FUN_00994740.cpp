// =============================================================================
// FUN_00994740
// -----------------------------------------------------------------------------
// Stable ID: aa_00994740
// Address:   0x00994740  (autoassault.exe, image base 0x400000)
// System:    unknown
// Generated: 2026-07-23 from raw capture (scaffold; refine for important units)
// Exactness: Behavior-preserving rewrite of decompiler control flow. Not modernization.
// Bit-for-bit vs retail EXE: DEFERRED (loaded image may differ slightly).
// =============================================================================

// PURPOSE (auto): Scaffold unit for FUN_00994740 @ 0x00994740
// Stable ID: aa_00994740
// Embedded strings (evidence for future rename):
//   - "C:\\vog\\1_code\\palantir\\palantir\\graphics\\gfxDeviceIB.cpp"
//   - "Call to gfxDeviceIB::Unlock more times than locked! Bad mojo..."
// Readability: control flow preserved from Ghidra decompile; types tentative.

// READABILITY (auto CF):
//  - Body size: ~205 non-empty decompiler lines.
//  - Control keywords: if×31, do×6, while×6, goto×3, return×3.
//  - Notable callees: ABS×11, FUN_00414a50, FUN_0044b9c0, FUN_0044ba80, FUN_0044bad0, FUN_00994740, vog_LogMessage.
//  - Strings: "C:\\vog\\1_code\\palantir\\palantir\\graphics\\gfxDeviceIB.cpp".
//  - Return sites: 3.

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



uint32_t /* width from decompiler */ FUN_00994740(int param_1,int param_2)



{

  int *piVar1;

  int *piVar2;

  float *pfVar3;

  int iVar4;

  uint32_t /* width from decompiler */ *puVar5;

  int iVar6;

  uint uVar7;

  short *psVar8;

  int *piVar9;

  uint32_t /* width from decompiler */ *puVar10;

  float *pfVar11;

  float fVar12;

  int local_28;

  int local_24;

  int local_20;

  float local_1c;

  float local_18;

  float local_14;

  float local_10;

  float local_c;

  int local_8;

  int local_4;

  

  iVar6 = *(int *)(param_2 + 4);

  if (iVar6 == 0) {

    local_28 = 0;

  }

  else {

    local_28 = *(int *)(iVar6 + 0x1c);

  }

  if (*(int *)(param_1 + 4) == 0) {

    local_20 = 0;

  }

  else {

    local_20 = *(int *)(*(int *)(param_1 + 4) + 0x18);

  }

  piVar9 = *(int **)(iVar6 + 0x10);

  if (piVar9 != (int *)0x0) {

    piVar2 = (int *)*piVar9;

    if (piVar2 == (int *)0x0) {

      local_24 = 0;

    }

    else {

      iVar6 = (**(code **)(*piVar2 + 0x2c))

                        (piVar2,piVar9[4] * *(int *)(iVar6 + 0x18),

                         piVar9[4] * *(int *)(iVar6 + 0x1c),&local_8,0x800);

      if (iVar6 < 0) {

        local_24 = 0;

      }

      else {

        piVar9[3] = piVar9[3] + 1;

        local_24 = local_8;

      }

    }

    if (local_24 != 0) {

      iVar6 = *(int *)(param_1 + 4);

      piVar9 = *(int **)(iVar6 + 0x10);

      if (piVar9 != (int *)0x0) {

        piVar2 = (int *)*piVar9;

        if (piVar2 == (int *)0x0) {

          local_4 = 0;

        }

        else {

          iVar6 = (**(code **)(*piVar2 + 0x2c))

                            (piVar2,piVar9[2] * *(int *)(iVar6 + 0x14),

                             piVar9[2] * *(int *)(iVar6 + 0x18),&local_4,0x800);

          if (iVar6 < 0) {

            local_4 = 0;

          }

          else {

            piVar9[4] = piVar9[4] + 1;

          }

        }

        if (local_4 != 0) {

          if (0 < local_20) {

            puVar5 = (uint32_t /* width from decompiler */ *)(local_4 + 0x14);

            iVar6 = local_20;

            do {

              *puVar5 = 0;

              puVar5 = puVar5 + 7;

              iVar6 = iVar6 + -1;

            } while (iVar6 != 0);

          }

          iVar6 = 0;

          if (0 < local_28) {

            do {

              iVar4 = iVar6 * 2;

              iVar6 = iVar6 + 1;

              *(uint32_t /* width from decompiler */ *)(local_4 + 0x14 + (uint)*(ushort *)(local_24 + iVar4) * 0x1c) = 0xff;

            } while (iVar6 < local_28);

          }

          iVar6 = 0;

          fVar12 = *(float *)(DAT_00d1f048 + 0x14) * *(float *)(DAT_00d1f048 + 0x14);

          if (0 < local_20) {

            piVar9 = (int *)(local_4 + 0x14);

            do {

              if ((*piVar9 != 0) && (uVar7 = iVar6 + 1, (int)uVar7 < local_20)) {

                pfVar11 = (float *)(piVar9 + 4);

                do {

                  local_14 = ABS(pfVar11[-2] - (float)piVar9[-5]);

                  if (local_14 <= _DAT_00a240ec) {

LAB_0099493f:

                    local_10 = pfVar11[-1];

                    local_1c = ABS(local_10 - (float)piVar9[-4]);

                    if (_DAT_00a240ec < local_1c) {

                      local_18 = ABS((float)piVar9[-4]);

                      pfVar3 = &local_14;

                      local_14 = ABS(local_10);

                      if (ABS(local_10) <= local_18) {

                        pfVar3 = &local_18;

                      }

                      if (fVar12 * *pfVar3 < local_1c) goto LAB_00994a1d;

                    }

                    local_c = *pfVar11;

                    local_1c = ABS(local_c - (float)piVar9[-3]);

                    if (_DAT_00a240ec < local_1c) {

                      local_18 = ABS((float)piVar9[-3]);

                      pfVar3 = &local_14;

                      local_14 = ABS(local_c);

                      if (ABS(local_c) <= local_18) {

                        pfVar3 = &local_18;

                      }

                      if (*pfVar3 * fVar12 < local_1c) goto LAB_00994a1d;

                    }

                    iVar4 = 0;

                    pfVar11[3] = 0.0;

                    if (0 < local_28) {

                      do {

                        if (*(ushort *)(local_24 + iVar4 * 2) == uVar7) {

                          *(short *)(local_24 + iVar4 * 2) = (short)iVar6;

                        }

                        iVar4 = iVar4 + 1;

                      } while (iVar4 < local_28);

                    }

                  }

                  else {

                    local_18 = ABS((float)piVar9[-5]);

                    pfVar3 = &local_1c;

                    local_1c = ABS(pfVar11[-2]);

                    if (local_1c <= local_18) {

                      pfVar3 = &local_18;

                    }

                    if (local_14 <= *pfVar3 * fVar12) goto LAB_0099493f;

                  }

LAB_00994a1d:

                  uVar7 = uVar7 + 1;

                  pfVar11 = pfVar11 + 7;

                } while ((int)uVar7 < local_20);

              }

              iVar6 = iVar6 + 1;

              piVar9 = piVar9 + 7;

            } while (iVar6 < local_20);

          }

          puVar5 = operator_new__(local_28 * 2);

          iVar6 = 0;

          if (0 < local_28) {

            psVar8 = (short *)(local_24 + 4);

            iVar4 = (local_28 - 1U) / 3 + 1;

            puVar10 = puVar5;

            do {

              if (((psVar8[-2] != psVar8[-1]) && (psVar8[-1] != *psVar8)) && (psVar8[-2] != *psVar8)

                 ) {

                *puVar10 = *(uint32_t /* width from decompiler */ *)(psVar8 + -2);

                iVar6 = iVar6 + 3;

                *(short *)(puVar10 + 1) = *psVar8;

                puVar10 = (uint32_t /* width from decompiler */ *)((int)puVar10 + 6);

              }

              psVar8 = psVar8 + 3;

              iVar4 = iVar4 + -1;

            } while (iVar4 != 0);

            if (0 < iVar6) {

              if (local_28 != iVar6) {

                piVar9 = *(int **)(*(int *)(param_2 + 4) + 0x10);

                if ((piVar9 != (int *)0x0) && (piVar2 = (int *)*piVar9, piVar2 != (int *)0x0)) {

                  piVar1 = piVar9 + 3;

                  *piVar1 = *piVar1 + -1;

                  if (*piVar1 < 0) {

                    vog_LogMessage("C:\\vog\\1_code\\palantir\\palantir\\graphics\\gfxDeviceIB.cpp",

                                   0xca,1,

                                   "Call to gfxDeviceIB::Unlock more times than locked! Bad mojo..."

                                  );

                    piVar9[3] = 0;

                  }

                  else {

                    (**(code **)(*piVar2 + 0x30))(piVar2);

                  }

                }

                FUN_0044b9c0(iVar6,8,0,0);

                FUN_0044bad0(puVar5,0);

              }

              operator_delete__(puVar5);

              return 0;

            }

          }

          return 1;

        }

      }

      FUN_00414a50();

    }

  }

  FUN_0044ba80();

  return 0xffffffff;

}
