// =============================================================================
// FUN_0062d0d0
// -----------------------------------------------------------------------------
// Stable ID: aa_0062d0d0
// Address:   0x0062d0d0  (autoassault.exe, image base 0x400000)
// System:    unknown
// Generated: 2026-07-23 from raw capture (scaffold; refine for important units)
// Exactness: Behavior-preserving rewrite of decompiler control flow. Not modernization.
// Bit-for-bit vs retail EXE: DEFERRED (loaded image may differ slightly).
// =============================================================================

// PURPOSE (auto): Scaffold unit for FUN_0062d0d0 @ 0x0062d0d0
// Stable ID: aa_0062d0d0
// No high-value strings recovered; name via xrefs/callers in follow-up.
// Readability: control flow preserved from Ghidra decompile; types tentative.

// READABILITY (auto CF):
//  - Body size: ~223 non-empty decompiler lines.
//  - Control keywords: if×29, while×5, do×3, for×2, return×2.
//  - Notable callees: ROUND×7, FUN_005b3370×4, FUN_0062b940×4, FUN_0062d0d0.
//  - Return sites: 2.

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

void __thiscall FUN_0062d0d0(int param_1,float *param_2,int *param_3)



{

  uint *puVar1;

  uint uVar2;

  int iVar3;

  uint uVar4;

  uint *puVar5;

  uint *puVar6;

  int iVar7;

  int iVar8;

  int iVar9;

  int iVar10;

  int iVar11;

  uint uVar12;

  int *piVar13;

  byte *pbVar14;

  int iVar15;

  int *piVar16;

  float fVar17;

  float fVar18;

  float fVar19;

  float fVar20;

  float fVar21;

  float fVar22;

  int *piStack_70;

  uint *puStack_6c;

  

  piVar13 = DAT_00b05060;

  iVar15 = *(int *)(param_1 + 0x44);

  piVar16 = DAT_00b05060 + 3;

  uVar4 = ((iVar15 >> 5) + 8) * 4 + 0xfU & 0xfffffff0;

  if (*piVar16 < (int)uVar4) {

    puVar5 = (uint *)(**(code **)(*DAT_00b05060 + 0x24))(uVar4);

  }

  else {

    puVar5 = (uint *)DAT_00b05060[2];

    DAT_00b05060[2] = (int)puVar5 + uVar4;

    piVar13[3] = *piVar16 - uVar4;

  }

  iVar15 = iVar15 >> 7;

  if (-1 < iVar15) {

    iVar15 = iVar15 + 1;

    puVar6 = puVar5;

    do {

      iVar15 = iVar15 + -1;

      *puVar6 = 0;

      puVar6[1] = 0;

      puVar6[2] = 0;

      puVar6[3] = 0;

      puVar6 = puVar6 + 4;

    } while (iVar15 != 0);

  }

  fVar17 = (*param_2 + *(float *)(param_1 + 0x10)) * *(float *)(param_1 + 0x30);

  fVar20 = *(float *)(param_1 + 0x34) * (*(float *)(param_1 + 0x14) + param_2[1]);

  fVar19 = *(float *)(param_1 + 0x38) * (*(float *)(param_1 + 0x18) + param_2[2]);

  if (DAT_009e33e4 <= fVar17) {

    fVar17 = DAT_009e33e4;

  }

  if (DAT_009e33e4 <= fVar20) {

    fVar20 = DAT_009e33e4;

  }

  if (DAT_009e33e4 <= fVar19) {

    fVar19 = DAT_009e33e4;

  }

  if (fVar17 <= 0.0) {

    fVar17 = 0.0;

  }

  if (fVar20 <= 0.0) {

    fVar20 = 0.0;

  }

  if (fVar19 <= 0.0) {

    fVar19 = 0.0;

  }

  fVar21 = *(float *)(param_1 + 0x30) * (param_2[4] + *(float *)(param_1 + 0x20));

  fVar22 = *(float *)(param_1 + 0x34) * (param_2[5] + *(float *)(param_1 + 0x24));

  fVar18 = *(float *)(param_1 + 0x38) * (param_2[6] + *(float *)(param_1 + 0x28));

  if (DAT_009e33e4 <= fVar21) {

    fVar21 = DAT_009e33e4;

  }

  if (DAT_009e33e4 <= fVar22) {

    fVar22 = DAT_009e33e4;

  }

  if (DAT_009e33e4 <= fVar18) {

    fVar18 = DAT_009e33e4;

  }

  if (fVar21 <= 0.0) {

    fVar21 = 0.0;

  }

  if (fVar22 <= 0.0) {

    fVar22 = 0.0;

  }

  if (fVar18 <= 0.0) {

    fVar18 = 0.0;

  }

  puVar6 = (uint *)(*(int *)(param_1 + 0x4c) + 8);

  if ((*(int *)(param_1 + 0x70) != 0) &&

     (iVar15 = (int)((int)ROUND(fVar17) & 0xfffffffeU) >>

               (0x1fU - (char)*(uint32_t /* width from decompiler */ *)(param_1 + 0x74) & 0x1f), 0 < iVar15)) {

    piVar16 = (int *)(*(int *)(param_1 + 0x78) + -0x14 + iVar15 * 0x14);

    puVar5[*piVar16 >> 5] = puVar5[*piVar16 >> 5] ^ 1 << ((byte)*piVar16 & 0x1f);

    puStack_6c = (uint *)piVar16[3];

    piVar13 = (int *)piVar16[2];

    if (-1 < (int)puStack_6c + -1) {

      do {

        iVar15 = *piVar13;

        piVar13 = piVar13 + 1;

        puVar5[iVar15 >> 5] = puVar5[iVar15 >> 5] ^ 1 << ((byte)iVar15 & 0x1f);

        puStack_6c = (uint *)((int)puStack_6c + -1);

      } while (puStack_6c != (uint *)0x0);

    }

    iVar15 = *piVar16;

    iVar9 = *(int *)(param_1 + 0x40);

    iVar7 = *(int *)(iVar9 + 0x14 + iVar15 * 0x1c);

    iVar8 = *(int *)(param_1 + 0x4c);

    for (pbVar14 = (byte *)(iVar8 + 8 + *(int *)(iVar9 + 0x10 + iVar15 * 0x1c) * 8);

        pbVar14 < (byte *)(iVar8 + iVar7 * 8); pbVar14 = pbVar14 + 8) {

      if ((*pbVar14 & 1) == 0) {

        puVar5[*(int *)(pbVar14 + 4) >> 5] =

             puVar5[*(int *)(pbVar14 + 4) >> 5] & ~(1 << ((byte)*(int *)(pbVar14 + 4) & 0x1f));

      }

    }

    puVar6 = (uint *)(*(int *)(param_1 + 0x4c) + 8 + *(int *)(iVar9 + iVar15 * 0x1c + 0x10) * 8);

  }

  uVar12 = *puVar6;

  while (uVar12 < ((int)ROUND(fVar17) & 0xfffffffeU)) {

    puVar1 = puVar6 + 1;

    puVar6 = puVar6 + 2;

    puVar5[(int)*puVar1 >> 5] = puVar5[(int)*puVar1 >> 5] ^ 1 << ((byte)*puVar1 & 0x1f);

    uVar12 = *puVar6;

  }

  uVar12 = *puVar6;

  while (uVar12 < ((int)ROUND(fVar21) | 1U)) {

    if ((uVar12 & 1) == 0) {

      puVar5[(int)puVar6[1] >> 5] = puVar5[(int)puVar6[1] >> 5] ^ 1 << ((byte)puVar6[1] & 0x1f);

    }

    puVar1 = puVar6 + 2;

    puVar6 = puVar6 + 2;

    uVar12 = *puVar1;

  }

  iVar9 = *(int *)(param_1 + 0x58);

  iVar15 = iVar9 + -0x10 + *(int *)(param_1 + 0x5c) * 8;

  iVar7 = FUN_0062b940(iVar9 + 8,iVar15,(int)ROUND(fVar20) & 0xfffffffe);

  iVar8 = iVar7 - iVar9 >> 3;

  iVar15 = FUN_0062b940(iVar9 + 8,iVar15,(int)ROUND(fVar22) | 1);

  iVar7 = *(int *)(param_1 + 100);

  iVar9 = iVar15 + (-8 - iVar9) >> 3;

  iVar15 = iVar7 + -0x10 + *(int *)(param_1 + 0x68) * 8;

  iVar10 = FUN_0062b940(iVar7 + 8,iVar15,(int)ROUND(fVar19) & 0xfffffffe);

  iVar10 = iVar10 - iVar7 >> 3;

  iVar11 = FUN_0062b940(iVar7 + 8,iVar15,(int)ROUND(fVar18) | 1);

  iVar15 = *(int *)(param_1 + 0x44);

  iVar7 = iVar11 + (-8 - iVar7) >> 3;

  if (puVar5 < puVar5 + (iVar15 >> 5) + 1) {

    piStack_70 = (int *)(*(int *)(param_1 + 0x40) + 0x28);

    puStack_6c = puVar5;

    do {

      piVar16 = piStack_70;

      for (uVar12 = *puStack_6c; uVar12 != 0; uVar12 = uVar12 >> 4) {

        if ((uVar12 & 0xf) != 0) {

          if ((((uVar12 & 1) != 0) &&

              (-1 < (iVar7 - piVar16[-9] | iVar9 - piVar16[-10] | piVar16[-8] - iVar8 |

                    piVar16[-7] - iVar10))) && (uVar2 = piVar16[-4], (uVar2 & 1) == 0)) {

            if (param_3[1] == (param_3[2] & 0x7fffffffU)) {

              FUN_005b3370(param_3,8);

            }

            iVar11 = param_3[1];

            iVar3 = *param_3;

            *(uint32_t /* width from decompiler */ *)(iVar3 + iVar11 * 8) = 0;

            *(uint *)(iVar3 + 4 + iVar11 * 8) = uVar2;

            param_3[1] = param_3[1] + 1;

          }

          if ((((uVar12 & 2) != 0) &&

              (-1 < (iVar7 - piVar16[-2] | iVar9 - piVar16[-3] | piVar16[-1] - iVar8 |

                    *piVar16 - iVar10))) && (uVar2 = piVar16[3], (uVar2 & 1) == 0)) {

            if (param_3[1] == (param_3[2] & 0x7fffffffU)) {

              FUN_005b3370(param_3,8);

            }

            iVar11 = param_3[1];

            iVar3 = *param_3;

            *(uint32_t /* width from decompiler */ *)(iVar3 + iVar11 * 8) = 0;

            *(uint *)(iVar3 + 4 + iVar11 * 8) = uVar2;

            param_3[1] = param_3[1] + 1;

          }

          if ((((uVar12 & 4) != 0) &&

              (-1 < (iVar7 - piVar16[5] | iVar9 - piVar16[4] | piVar16[6] - iVar8 |

                    piVar16[7] - iVar10))) && (uVar2 = piVar16[10], (uVar2 & 1) == 0)) {

            if (param_3[1] == (param_3[2] & 0x7fffffffU)) {

              FUN_005b3370(param_3,8);

            }

            iVar11 = param_3[1];

            iVar3 = *param_3;

            *(uint32_t /* width from decompiler */ *)(iVar3 + iVar11 * 8) = 0;

            *(uint *)(iVar3 + 4 + iVar11 * 8) = uVar2;

            param_3[1] = param_3[1] + 1;

          }

          if ((((uVar12 & 8) != 0) &&

              (-1 < (iVar7 - piVar16[0xc] | iVar9 - piVar16[0xb] | piVar16[0xd] - iVar8 |

                    piVar16[0xe] - iVar10))) && (uVar2 = piVar16[0x11], (uVar2 & 1) == 0)) {

            if (param_3[1] == (param_3[2] & 0x7fffffffU)) {

              FUN_005b3370(param_3,8);

            }

            iVar11 = param_3[1];

            iVar3 = *param_3;

            *(uint32_t /* width from decompiler */ *)(iVar3 + iVar11 * 8) = 0;

            *(uint *)(iVar3 + 4 + iVar11 * 8) = uVar2;

            param_3[1] = param_3[1] + 1;

          }

        }

        piVar16 = piVar16 + 0x1c;

      }

      piStack_70 = piStack_70 + 0xe0;

      puStack_6c = puStack_6c + 1;

    } while (puStack_6c < puVar5 + (iVar15 >> 5) + 1);

  }

  piVar16 = DAT_00b05060;

  if ((uVar4 != 0) &&

     ((puVar5 == (uint *)DAT_00b05060[5] || ((uint *)DAT_00b05060[5] == (uint *)0x0)))) {

    (**(code **)(*DAT_00b05060 + 0x28))(puVar5,uVar4);

    return;

  }

  DAT_00b05060[2] = DAT_00b05060[2] - uVar4;

  piVar16[3] = piVar16[3] + uVar4;

  return;

}
