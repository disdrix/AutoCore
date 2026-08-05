// =============================================================================
// FUN_0062c1d0
// -----------------------------------------------------------------------------
// Stable ID: aa_0062c1d0
// Address:   0x0062c1d0  (autoassault.exe, image base 0x400000)
// System:    unknown
// Generated: 2026-07-23 from raw capture (scaffold; refine for important units)
// Exactness: Behavior-preserving rewrite of decompiler control flow. Not modernization.
// Bit-for-bit vs retail EXE: DEFERRED (loaded image may differ slightly).
// =============================================================================

// PURPOSE (auto): Scaffold unit for FUN_0062c1d0 @ 0x0062c1d0
// Stable ID: aa_0062c1d0
// No high-value strings recovered; name via xrefs/callers in follow-up.
// Readability: control flow preserved from Ghidra decompile; types tentative.

// READABILITY (auto CF):
//  - Body size: ~397 non-empty decompiler lines.
//  - Control keywords: if×44, while×12, for×1, return×1.
//  - Notable callees: FUN_005b3370×8, ROUND×6, FUN_0062c0b0×2, FUN_0062c140×2, FUN_0062c1d0.
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

void __thiscall

FUN_0062c1d0(int param_1,uint32_t /* width from decompiler */ *param_2,float *param_3,int param_4,int *param_5,int *param_6)



{

  uint32_t /* width from decompiler */ *puVar1;

  int *piVar2;

  uint *puVar3;

  int *piVar4;

  uint32_t /* width from decompiler */ *puVar5;

  int *piVar6;

  int iVar7;

  uint uVar8;

  uint uVar9;

  uint uVar10;

  uint uVar11;

  uint uVar12;

  uint uVar13;

  uint uVar14;

  int iVar15;

  uint uVar16;

  float fVar17;

  float fVar18;

  float fVar19;

  float fVar20;

  float fVar21;

  float fVar22;

  

  puVar1 = param_2 + param_4;

  for (; param_2 < puVar1; param_2 = param_2 + 1) {

    fVar17 = *(float *)(param_1 + 0x30) * (*param_3 + *(float *)(param_1 + 0x10));

    fVar20 = *(float *)(param_1 + 0x34) * (param_3[1] + *(float *)(param_1 + 0x14));

    fVar19 = *(float *)(param_1 + 0x38) * (param_3[2] + *(float *)(param_1 + 0x18));

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

    fVar21 = *(float *)(param_1 + 0x30) * (*(float *)(param_1 + 0x20) + param_3[4]);

    fVar22 = *(float *)(param_1 + 0x34) * (param_3[5] + *(float *)(param_1 + 0x24));

    fVar18 = *(float *)(param_1 + 0x38) * (param_3[6] + *(float *)(param_1 + 0x28));

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

    uVar10 = (int)ROUND(fVar20) & 0xfffffffe;

    iVar7 = *(int *)(param_1 + 0x40);

    uVar16 = (int)ROUND(fVar17) & 0xfffffffe;

    uVar11 = (int)ROUND(fVar19) & 0xfffffffe;

    uVar12 = (int)ROUND(fVar21) | 1;

    uVar13 = (int)ROUND(fVar22) | 1;

    uVar14 = (int)ROUND(fVar18) | 1;

    uVar8 = *(uint *)*param_2;

    piVar2 = (int *)(iVar7 + uVar8 * 0x1c);

    iVar15 = piVar2[4];

    puVar3 = (uint *)(*(int *)(param_1 + 0x4c) + iVar15 * 8);

    uVar9 = puVar3[-2];

    while (uVar16 < uVar9) {

      piVar4 = (int *)(iVar7 + puVar3[-1] * 0x1c);

      *puVar3 = uVar9;

      puVar3[1] = puVar3[-1];

      if ((uVar9 & 1) == 0) {

        piVar4[4] = iVar15;

      }

      else {

        piVar4[5] = iVar15;

        if (-1 < (piVar2[3] - piVar4[1] | piVar4[3] - piVar2[1] | piVar4[2] - *piVar2 |

                 piVar2[2] - *piVar4)) {

          FUN_0062c0b0(*(uint32_t /* width from decompiler */ *)(param_1 + 0x78),piVar2,uVar8,piVar4,param_5);

        }

      }

      iVar15 = iVar15 + -1;

      puVar3[-1] = uVar8;

      piVar2[4] = iVar15;

      uVar9 = puVar3[-4];

      puVar3 = puVar3 + -2;

    }

    *puVar3 = uVar16;

    puVar5 = (uint32_t /* width from decompiler */ *)(*(int *)(param_1 + 0x4c) + piVar2[5] * 8);

    uVar9 = puVar5[2];

    while (uVar9 < uVar12) {

      piVar2[5] = piVar2[5] + 1;

      piVar4 = (int *)(iVar7 + puVar5[3] * 0x1c);

      *puVar5 = puVar5[2];

      puVar5[1] = puVar5[3];

      puVar5[3] = uVar8;

      if ((uVar9 & 1) == 0) {

        piVar4[4] = piVar4[4] + -1;

        if (-1 < (piVar2[3] - piVar4[1] | piVar4[3] - piVar2[1] | piVar4[2] - *piVar2 |

                 piVar2[2] - *piVar4)) {

          FUN_0062c0b0(*(uint32_t /* width from decompiler */ *)(param_1 + 0x78),piVar2,uVar8,piVar4,param_5);

        }

      }

      else {

        piVar4[5] = piVar4[5] + -1;

      }

      uVar9 = puVar5[4];

      puVar5 = puVar5 + 2;

    }

    puVar3 = (uint *)(*(int *)(param_1 + 0x4c) + piVar2[5] * 8);

    uVar9 = puVar3[-2];

    while (uVar12 < uVar9) {

      piVar2[5] = piVar2[5] + -1;

      piVar4 = (int *)(iVar7 + puVar3[-1] * 0x1c);

      *puVar3 = puVar3[-2];

      puVar3[1] = puVar3[-1];

      puVar3[-1] = uVar8;

      if ((uVar9 & 1) == 0) {

        piVar4[4] = piVar4[4] + 1;

        if (-1 < (piVar2[3] - piVar4[1] | piVar4[3] - piVar2[1] | piVar2[2] - *piVar4 |

                 piVar4[2] - *piVar2)) {

          FUN_0062c140(*(uint32_t /* width from decompiler */ *)(param_1 + 0x78),piVar2,uVar8,piVar4,param_6);

        }

      }

      else {

        piVar4[5] = piVar4[5] + 1;

      }

      uVar9 = puVar3[-4];

      puVar3 = puVar3 + -2;

    }

    *puVar3 = uVar12;

    puVar3 = (uint *)(*(int *)(param_1 + 0x4c) + piVar2[4] * 8);

    uVar9 = puVar3[2];

    while (uVar9 < uVar16) {

      piVar2[4] = piVar2[4] + 1;

      piVar4 = (int *)(iVar7 + puVar3[3] * 0x1c);

      *puVar3 = puVar3[2];

      puVar3[1] = puVar3[3];

      puVar3[3] = uVar8;

      if ((uVar9 & 1) == 0) {

        piVar4[4] = piVar4[4] + -1;

      }

      else {

        piVar4[5] = piVar4[5] + -1;

        if (-1 < (piVar2[3] - piVar4[1] | piVar4[3] - piVar2[1] | piVar2[2] - *piVar4 |

                 piVar4[2] - *piVar2)) {

          FUN_0062c140(*(uint32_t /* width from decompiler */ *)(param_1 + 0x78),piVar2,uVar8,piVar4,param_6);

        }

      }

      uVar9 = puVar3[4];

      puVar3 = puVar3 + 2;

    }

    *puVar3 = uVar16;

    iVar15 = *piVar2;

    puVar3 = (uint *)(*(int *)(param_1 + 0x58) + iVar15 * 8);

    uVar9 = puVar3[-2];

    while (uVar10 < uVar9) {

      piVar4 = (int *)(iVar7 + puVar3[-1] * 0x1c);

      puVar3[1] = puVar3[-1];

      *puVar3 = uVar9;

      if ((uVar9 & 1) == 0) {

        *piVar4 = iVar15;

      }

      else {

        piVar4[2] = iVar15;

        if (-1 < (piVar4[3] - piVar2[1] | piVar2[3] - piVar4[1] | piVar2[5] - piVar4[4] |

                 piVar4[5] - piVar2[4])) {

          if (param_5[1] == (param_5[2] & 0x7fffffffU)) {

            FUN_005b3370(param_5,8);

          }

          piVar6 = (int *)(*param_5 + param_5[1] * 8);

          param_5[1] = param_5[1] + 1;

          *piVar6 = piVar2[6];

          piVar6[1] = piVar4[6];

        }

      }

      iVar15 = iVar15 + -1;

      puVar3[-1] = uVar8;

      *piVar2 = iVar15;

      uVar9 = puVar3[-4];

      puVar3 = puVar3 + -2;

    }

    *puVar3 = uVar10;

    puVar5 = (uint32_t /* width from decompiler */ *)(*(int *)(param_1 + 0x58) + piVar2[2] * 8);

    uVar9 = puVar5[2];

    while (uVar9 < uVar13) {

      piVar2[2] = piVar2[2] + 1;

      piVar4 = (int *)(iVar7 + puVar5[3] * 0x1c);

      *puVar5 = puVar5[2];

      puVar5[1] = puVar5[3];

      puVar5[3] = uVar8;

      if ((uVar9 & 1) == 0) {

        *piVar4 = *piVar4 + -1;

        if (-1 < (piVar4[3] - piVar2[1] | piVar2[3] - piVar4[1] | piVar2[5] - piVar4[4] |

                 piVar4[5] - piVar2[4])) {

          if (param_5[1] == (param_5[2] & 0x7fffffffU)) {

            FUN_005b3370(param_5,8);

          }

          piVar6 = (int *)(*param_5 + param_5[1] * 8);

          param_5[1] = param_5[1] + 1;

          *piVar6 = piVar2[6];

          piVar6[1] = piVar4[6];

        }

      }

      else {

        piVar4[2] = piVar4[2] + -1;

      }

      uVar9 = puVar5[4];

      puVar5 = puVar5 + 2;

    }

    puVar3 = (uint *)(*(int *)(param_1 + 0x58) + piVar2[2] * 8);

    uVar9 = puVar3[-2];

    while (uVar13 < uVar9) {

      piVar2[2] = piVar2[2] + -1;

      piVar4 = (int *)(iVar7 + puVar3[-1] * 0x1c);

      *puVar3 = puVar3[-2];

      puVar3[1] = puVar3[-1];

      puVar3[-1] = uVar8;

      if ((uVar9 & 1) == 0) {

        *piVar4 = *piVar4 + 1;

        if (-1 < (piVar4[3] - piVar2[1] | piVar2[3] - piVar4[1] | piVar2[5] - piVar4[4] |

                 piVar4[5] - piVar2[4])) {

          if (param_6[1] == (param_6[2] & 0x7fffffffU)) {

            FUN_005b3370(param_6,8);

          }

          piVar6 = (int *)(*param_6 + param_6[1] * 8);

          param_6[1] = param_6[1] + 1;

          *piVar6 = piVar2[6];

          piVar6[1] = piVar4[6];

        }

      }

      else {

        piVar4[2] = piVar4[2] + 1;

      }

      uVar9 = puVar3[-4];

      puVar3 = puVar3 + -2;

    }

    *puVar3 = uVar13;

    puVar3 = (uint *)(*(int *)(param_1 + 0x58) + *piVar2 * 8);

    uVar9 = puVar3[2];

    while (uVar9 < uVar10) {

      *piVar2 = *piVar2 + 1;

      piVar4 = (int *)(iVar7 + puVar3[3] * 0x1c);

      *puVar3 = puVar3[2];

      puVar3[1] = puVar3[3];

      puVar3[3] = uVar8;

      if ((uVar9 & 1) == 0) {

        *piVar4 = *piVar4 + -1;

      }

      else {

        piVar4[2] = piVar4[2] + -1;

        if (-1 < (piVar4[3] - piVar2[1] | piVar2[3] - piVar4[1] | piVar2[5] - piVar4[4] |

                 piVar4[5] - piVar2[4])) {

          if (param_6[1] == (param_6[2] & 0x7fffffffU)) {

            FUN_005b3370(param_6,8);

          }

          piVar6 = (int *)(*param_6 + param_6[1] * 8);

          param_6[1] = param_6[1] + 1;

          *piVar6 = piVar2[6];

          piVar6[1] = piVar4[6];

        }

      }

      uVar9 = puVar3[4];

      puVar3 = puVar3 + 2;

    }

    *puVar3 = uVar10;

    iVar15 = piVar2[1];

    puVar3 = (uint *)(*(int *)(param_1 + 100) + iVar15 * 8);

    uVar9 = puVar3[-2];

    while (uVar11 < uVar9) {

      piVar4 = (int *)(iVar7 + puVar3[-1] * 0x1c);

      *puVar3 = uVar9;

      puVar3[1] = puVar3[-1];

      if ((uVar9 & 1) == 0) {

        piVar4[1] = iVar15;

      }

      else {

        piVar4[3] = iVar15;

        if (-1 < (piVar2[5] - piVar4[4] | piVar4[2] - *piVar2 | piVar4[5] - piVar2[4] |

                 piVar2[2] - *piVar4)) {

          if (param_5[1] == (param_5[2] & 0x7fffffffU)) {

            FUN_005b3370(param_5,8);

          }

          piVar6 = (int *)(*param_5 + param_5[1] * 8);

          param_5[1] = param_5[1] + 1;

          *piVar6 = piVar2[6];

          piVar6[1] = piVar4[6];

        }

      }

      iVar15 = iVar15 + -1;

      puVar3[-1] = uVar8;

      piVar2[1] = iVar15;

      uVar9 = puVar3[-4];

      puVar3 = puVar3 + -2;

    }

    *puVar3 = uVar11;

    puVar5 = (uint32_t /* width from decompiler */ *)(*(int *)(param_1 + 100) + piVar2[3] * 8);

    uVar9 = puVar5[2];

    while (uVar9 < uVar14) {

      piVar2[3] = piVar2[3] + 1;

      piVar4 = (int *)(iVar7 + puVar5[3] * 0x1c);

      *puVar5 = puVar5[2];

      puVar5[1] = puVar5[3];

      puVar5[3] = uVar8;

      if ((uVar9 & 1) == 0) {

        piVar4[1] = piVar4[1] + -1;

        if (-1 < (piVar2[5] - piVar4[4] | piVar4[5] - piVar2[4] | piVar4[2] - *piVar2 |

                 piVar2[2] - *piVar4)) {

          if (param_5[1] == (param_5[2] & 0x7fffffffU)) {

            FUN_005b3370(param_5,8);

          }

          piVar6 = (int *)(*param_5 + param_5[1] * 8);

          param_5[1] = param_5[1] + 1;

          *piVar6 = piVar2[6];

          piVar6[1] = piVar4[6];

        }

      }

      else {

        piVar4[3] = piVar4[3] + -1;

      }

      uVar9 = puVar5[4];

      puVar5 = puVar5 + 2;

    }

    puVar3 = (uint *)(*(int *)(param_1 + 100) + piVar2[3] * 8);

    uVar9 = puVar3[-2];

    while (uVar14 < uVar9) {

      piVar2[3] = piVar2[3] + -1;

      piVar4 = (int *)(iVar7 + puVar3[-1] * 0x1c);

      *puVar3 = puVar3[-2];

      puVar3[1] = puVar3[-1];

      puVar3[-1] = uVar8;

      if ((uVar9 & 1) == 0) {

        piVar4[1] = piVar4[1] + 1;

        if (-1 < (piVar2[5] - piVar4[4] | piVar4[5] - piVar2[4] | piVar4[2] - *piVar2 |

                 piVar2[2] - *piVar4)) {

          if (param_6[1] == (param_6[2] & 0x7fffffffU)) {

            FUN_005b3370(param_6,8);

          }

          piVar6 = (int *)(*param_6 + param_6[1] * 8);

          param_6[1] = param_6[1] + 1;

          *piVar6 = piVar2[6];

          piVar6[1] = piVar4[6];

        }

      }

      else {

        piVar4[3] = piVar4[3] + 1;

      }

      uVar9 = puVar3[-4];

      puVar3 = puVar3 + -2;

    }

    *puVar3 = uVar14;

    puVar3 = (uint *)(*(int *)(param_1 + 100) + piVar2[1] * 8);

    uVar9 = puVar3[2];

    while (uVar9 < uVar11) {

      piVar2[1] = piVar2[1] + 1;

      piVar4 = (int *)(iVar7 + puVar3[3] * 0x1c);

      *puVar3 = puVar3[2];

      puVar3[1] = puVar3[3];

      puVar3[3] = uVar8;

      if ((uVar9 & 1) == 0) {

        piVar4[1] = piVar4[1] + -1;

      }

      else {

        piVar4[3] = piVar4[3] + -1;

        if (-1 < (piVar2[5] - piVar4[4] | piVar4[5] - piVar2[4] | piVar4[2] - *piVar2 |

                 piVar2[2] - *piVar4)) {

          if (param_6[1] == (param_6[2] & 0x7fffffffU)) {

            FUN_005b3370(param_6,8);

          }

          piVar6 = (int *)(*param_6 + param_6[1] * 8);

          param_6[1] = param_6[1] + 1;

          *piVar6 = piVar2[6];

          piVar6[1] = piVar4[6];

        }

      }

      uVar9 = puVar3[4];

      puVar3 = puVar3 + 2;

    }

    param_3 = param_3 + 8;

    *puVar3 = uVar11;

  }

  return;

}
