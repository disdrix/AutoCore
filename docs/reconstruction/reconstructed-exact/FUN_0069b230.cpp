// =============================================================================
// FUN_0069b230
// -----------------------------------------------------------------------------
// Stable ID: aa_0069b230
// Address:   0x0069b230  (autoassault.exe, image base 0x400000)
// System:    unknown
// Generated: 2026-07-23 from raw capture (scaffold; refine for important units)
// Exactness: Behavior-preserving rewrite of decompiler control flow. Not modernization.
// Bit-for-bit vs retail EXE: DEFERRED (loaded image may differ slightly).
// =============================================================================

// PURPOSE (auto): Scaffold unit for FUN_0069b230 @ 0x0069b230
// Stable ID: aa_0069b230
// No high-value strings recovered; name via xrefs/callers in follow-up.
// Readability: control flow preserved from Ghidra decompile; types tentative.

// READABILITY (auto CF):
//  - Body size: ~87 non-empty decompiler lines.
//  - Control keywords: if×10, return×2, while×1.
//  - Notable callees: NAN×14, CONCAT22×7, CONCAT31, FUN_0069b230.
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

uint32_t /* width from decompiler */ FUN_0069b230(float *param_1,int param_2,int param_3)



{

  float fVar1;

  float fVar2;

  int iVar3;

  int iVar4;

  bool bVar5;

  float fVar6;

  int iVar7;

  uint uVar8;

  short sVar9;

  uint uVar10;

  

  bVar5 = true;

  if (*(int *)(DAT_00d08ebc + 0x10) != 0) {

    if ((*(int *)(DAT_00d08ebc + 0x14) - *(int *)(DAT_00d08ebc + 0x10)) / 0x54 != 0) {

      iVar3 = *(int *)(DAT_00d08ebc + 0x10);

      param_2 = param_2 * 0x54;

      fVar1 = *(float *)(param_2 + 0x48 + iVar3);

      fVar2 = *(float *)(param_2 + 0x4c + iVar3);

      uVar8 = CONCAT22((short)((uint)iVar3 >> 0x10),

                       (ushort)(fVar1 < fVar2) << 8 | (ushort)(NAN(fVar1) || NAN(fVar2)) << 10 |

                       (ushort)(fVar1 == fVar2) << 0xe);

      if (fVar1 < fVar2 == 0 && (fVar1 == fVar2) == 0) {

        fVar1 = *(float *)(param_2 + iVar3 + 0x48);

      }

      else {

        fVar1 = *(float *)(param_2 + iVar3 + 0x4c);

      }

      fVar1 = fVar1 * *(float *)(DAT_00d08ebc + 0x1c);

      iVar3 = *(int *)(param_3 + 4);

      uVar10 = 0;

      while (iVar3 != 0) {

        iVar7 = *(int *)(param_3 + 8) - iVar3;

        uVar8 = iVar7 >> 2;

        if ((uVar8 <= uVar10) || (!bVar5)) break;

        iVar4 = *(int *)(iVar3 + uVar10 * 4);

        fVar6 = fVar1 + *(float *)(iVar4 + 4);

        fVar2 = *param_1;

        sVar9 = (short)(iVar7 >> 0x12);

        uVar8 = CONCAT22(sVar9,(ushort)(fVar6 < fVar2) << 8 |

                               (ushort)(NAN(fVar6) || NAN(fVar2)) << 10 |

                               (ushort)(fVar6 == fVar2) << 0xe);

        if (fVar6 < fVar2 == 0 && (fVar6 == fVar2) == 0) {

          fVar6 = *(float *)(iVar4 + 4) - fVar1;

          fVar2 = *param_1;

          uVar8 = CONCAT22(sVar9,(ushort)(fVar6 < fVar2) << 8 |

                                 (ushort)(NAN(fVar6) || NAN(fVar2)) << 10 |

                                 (ushort)(fVar6 == fVar2) << 0xe);

          if (fVar6 < fVar2) {

            fVar6 = fVar1 + *(float *)(iVar4 + 8);

            fVar2 = param_1[1];

            uVar8 = CONCAT22(sVar9,(ushort)(fVar6 < fVar2) << 8 |

                                   (ushort)(NAN(fVar6) || NAN(fVar2)) << 10 |

                                   (ushort)(fVar6 == fVar2) << 0xe);

            if (fVar6 < fVar2 == 0 && (fVar6 == fVar2) == 0) {

              fVar6 = *(float *)(iVar4 + 8) - fVar1;

              fVar2 = param_1[1];

              uVar8 = CONCAT22(sVar9,(ushort)(fVar6 < fVar2) << 8 |

                                     (ushort)(NAN(fVar6) || NAN(fVar2)) << 10 |

                                     (ushort)(fVar6 == fVar2) << 0xe);

              if (fVar6 < fVar2) {

                fVar6 = fVar1 + *(float *)(iVar4 + 0xc);

                fVar2 = param_1[2];

                uVar8 = CONCAT22(sVar9,(ushort)(fVar6 < fVar2) << 8 |

                                       (ushort)(NAN(fVar6) || NAN(fVar2)) << 10 |

                                       (ushort)(fVar6 == fVar2) << 0xe);

                if (fVar6 < fVar2 == 0 && (fVar6 == fVar2) == 0) {

                  fVar6 = *(float *)(iVar4 + 0xc) - fVar1;

                  fVar2 = param_1[2];

                  uVar8 = CONCAT22(sVar9,(ushort)(fVar6 < fVar2) << 8 |

                                         (ushort)(NAN(fVar6) || NAN(fVar2)) << 10 |

                                         (ushort)(fVar6 == fVar2) << 0xe);

                  if (fVar6 < fVar2) {

                    bVar5 = false;

                  }

                }

              }

            }

          }

        }

        uVar10 = uVar10 + 1;

      }

      return CONCAT31((int3)(uVar8 >> 8),bVar5);

    }

  }

  return 0;

}
