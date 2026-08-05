// =============================================================================
// Named_CalleeOf_Named_CalleeOf_Named_CalleeOf_Named_assPackManag_00482a50
// -----------------------------------------------------------------------------
// Stable ID: aa_00482a50
// Callee of Named_CalleeOf_Named_CalleeOf_Named_assPackManager
// Address:   0x00482a50  (autoassault.exe, image base 0x400000)
// System:    unknown
// Generated: 2026-07-23 from raw capture (scaffold; refine for important units)
// Exactness: Behavior-preserving rewrite of decompiler control flow. Not modernization.
// Bit-for-bit vs retail EXE: DEFERRED (loaded image may differ slightly).
// =============================================================================

// PURPOSE (auto): Called from Named_CalleeOf_Named_CalleeOf_Named_assPackManager: callee helper with no high-value strings in clean/raw. Role inferred from parent name only; refine when decompile strings or xrefs improve.
// Readability: control flow preserved from Ghidra decompile; types tentative.

// READABILITY (auto CF):
//  - Body size: ~263 non-empty decompiler lines.
//  - Control keywords: if×34, while×5, do×4, goto×4, return×3.
//  - Notable callees: FUN_00482a20×6, FUN_00482a50.
//  - Return sites: 3.

/*
 * Behavioral notes:
 * Callee of Named_CalleeOf_Named_CalleeOf_Named_assPackManager
 * Xref/callee-driven rename (parent seed scan)
 *
 * - Derived from Ghidra decompile; names prefer Ghidra symbols / plate comments.
 * - Remaining FUN_* / DAT_* identifiers are unresolved pending type recovery.
 * - Runtime / differential verification: OPEN unless matrix says otherwise.
 *
 * Readability pass:
 * - undefinedN widths preserved as fixed-width integers where decompiler width is known.
 * - Control flow and call order preserved from authoritative raw.
 */

void Named_CalleeOf_Named_CalleeOf_Named_CalleeOf_Named_assPackManag_00482a50(int *param_1)



{

  int *piVar1;

  ushort uVar2;

  byte bVar3;

  int iVar4;

  int iVar5;

  int iVar6;

  uint uVar7;

  int iVar8;

  uint uVar9;

  uint uVar10;

  uint uVar11;

  int iVar12;

  int iVar13;

  uint uVar14;

  

  if ((char)param_1[4] == '\0') {

LAB_00482e30:

    if (*(int *)(*param_1 + 0x14) != 0) {

      if (param_1[3] == 0) {

        iVar4 = param_1[0x110];

        iVar6 = param_1[0x3e90] + 1;

        if (iVar4 == iVar6) {

          return;

        }

        uVar7 = param_1[0xe];

        param_1[3] = 1;

        *(char *)(param_1 + 2) = (char)param_1[0xf];

        uVar14 = 0;

        uVar9 = 0x100;

        do {

          uVar10 = (int)(uVar9 + uVar14) >> 1;

          uVar11 = uVar10;

          if (param_1[uVar10 + 0x111] <= (int)uVar7) {

            uVar11 = uVar9;

            uVar14 = uVar10;

          }

          uVar9 = uVar11;

        } while (uVar11 - uVar14 != 1);

        param_1[0xe] = (*(byte *)((uVar7 >> 1) + param_1[0x315]) >> ((byte)uVar7 & 1) * '\x04' & 0xf

                       ) << 0x10 | (uint)*(ushort *)(param_1[0x314] + uVar7 * 2);

        param_1[0x110] = iVar4 + 1;

        if (iVar4 + 1 != iVar6) {

          uVar14 = uVar14 & 0xff;

          if (uVar14 == param_1[0xf]) {

            uVar7 = param_1[0xe];

            param_1[3] = 2;

            uVar14 = 0;

            uVar9 = 0x100;

            do {

              uVar10 = (int)(uVar9 + uVar14) >> 1;

              uVar11 = uVar10;

              if (param_1[uVar10 + 0x111] <= (int)uVar7) {

                uVar11 = uVar9;

                uVar14 = uVar10;

              }

              uVar9 = uVar11;

            } while (uVar11 - uVar14 != 1);

            param_1[0xe] = (*(byte *)((uVar7 >> 1) + param_1[0x315]) >> ((byte)uVar7 & 1) * '\x04' &

                           0xf) << 0x10 | (uint)*(ushort *)(param_1[0x314] + uVar7 * 2);

            param_1[0x110] = iVar4 + 2;

            if (iVar4 + 2 == iVar6) goto LAB_00482e30;

            uVar14 = uVar14 & 0xff;

            if (uVar14 == param_1[0xf]) {

              uVar7 = param_1[0xe];

              param_1[3] = 3;

              uVar14 = FUN_00482a20();

              uVar2 = *(ushort *)(param_1[0x314] + uVar7 * 2);

              uVar7 = (*(byte *)((uVar7 >> 1) + param_1[0x315]) >> ((byte)uVar7 & 1) * '\x04' & 0xf)

                      << 0x10 | (uint)uVar2;

              param_1[0xe] = uVar7;

              param_1[0x110] = iVar4 + 3;

              if (iVar4 + 3 == iVar6) goto LAB_00482e30;

              uVar14 = uVar14 & 0xff;

              if (uVar14 == param_1[0xf]) {

                uVar9 = FUN_00482a20();

                param_1[0xe] = (*(byte *)((uVar7 >> 1) + param_1[0x315]) >>

                                ((byte)uVar2 & 1) * '\x04' & 0xf) << 0x10 |

                               (uint)*(ushort *)(param_1[0x314] + uVar7 * 2);

                uVar7 = param_1[0xe];

                param_1[0x110] = iVar4 + 4;

                param_1[3] = (uVar9 & 0xff) + 4;

                iVar6 = FUN_00482a20();

                param_1[0xf] = iVar6;

                param_1[0xe] = (*(byte *)((uVar7 >> 1) + param_1[0x315]) >>

                                ((byte)uVar7 & 1) * '\x04' & 0xf) << 0x10 |

                               (uint)*(ushort *)(param_1[0x314] + uVar7 * 2);

                param_1[0x110] = iVar4 + 5;

                goto LAB_00482e30;

              }

            }

          }

          param_1[0xf] = uVar14;

        }

      }

      else {

        **(uint8_t **)(*param_1 + 0x10) = (char)param_1[2];

        uVar7 = *(uint *)(&DAT_00afd5e8 +

                         ((uint)param_1[0x318] >> 0x18 ^ (uint)*(byte *)(param_1 + 2)) * 4);

        param_1[3] = param_1[3] + -1;

        param_1[0x318] = param_1[0x318] << 8 ^ uVar7;

        *(int *)(*param_1 + 0x10) = *(int *)(*param_1 + 0x10) + 1;

        *(int *)(*param_1 + 0x14) = *(int *)(*param_1 + 0x14) + -1;

        *(int *)(*param_1 + 0x18) = *(int *)(*param_1 + 0x18) + 1;

        if (*(int *)(*param_1 + 0x18) == 0) {

          piVar1 = (int *)(*param_1 + 0x1c);

          *piVar1 = *piVar1 + 1;

        }

      }

      goto LAB_00482e30;

    }

  }

  else {

    while (*(int *)(*param_1 + 0x14) != 0) {

      if (param_1[3] == 0) {

        iVar4 = param_1[0x3e90] + 1;

        if (param_1[0x110] == iVar4) {

          return;

        }

        *(char *)(param_1 + 2) = (char)param_1[0xf];

        uVar7 = param_1[0xe];

        param_1[3] = 1;

        iVar12 = 0;

        iVar6 = 0x100;

        do {

          iVar5 = iVar6 + iVar12 >> 1;

          iVar13 = iVar5;

          if (param_1[iVar5 + 0x111] <= (int)uVar7) {

            iVar13 = iVar6;

            iVar12 = iVar5;

          }

          iVar6 = iVar13;

        } while (iVar13 - iVar12 != 1);

        param_1[0xe] = (*(byte *)((uVar7 >> 1) + param_1[0x315]) >> ((byte)uVar7 & 1) * '\x04' & 0xf

                       ) << 0x10 | (uint)*(ushort *)(param_1[0x314] + uVar7 * 2);

        if (param_1[5] == 0) {

          iVar6 = param_1[6] + 1;

          param_1[5] = *(int *)(&DAT_00afcde8 + param_1[6] * 4);

          param_1[6] = iVar6;

          if (iVar6 == 0x200) {

            param_1[6] = 0;

          }

        }

        param_1[5] = param_1[5] + -1;

        iVar6 = param_1[0x110];

        param_1[0x110] = iVar6 + 1;

        if (iVar6 + 1 != iVar4) {

          uVar7 = (uint)(byte)(param_1[5] == 1 ^ (byte)iVar12);

          if (uVar7 == param_1[0xf]) {

            uVar7 = param_1[0xe];

            param_1[3] = 2;

            iVar13 = 0;

            iVar12 = 0x100;

            do {

              iVar8 = iVar12 + iVar13 >> 1;

              iVar5 = iVar8;

              if (param_1[iVar8 + 0x111] <= (int)uVar7) {

                iVar5 = iVar12;

                iVar13 = iVar8;

              }

              iVar12 = iVar5;

            } while (iVar5 - iVar13 != 1);

            param_1[0xe] = (*(byte *)((uVar7 >> 1) + param_1[0x315]) >> ((byte)uVar7 & 1) * '\x04' &

                           0xf) << 0x10 | (uint)*(ushort *)(param_1[0x314] + uVar7 * 2);

            if (param_1[5] == 0) {

              iVar12 = param_1[6] + 1;

              param_1[5] = *(int *)(&DAT_00afcde8 + param_1[6] * 4);

              param_1[6] = iVar12;

              if (iVar12 == 0x200) {

                param_1[6] = 0;

              }

            }

            param_1[5] = param_1[5] + -1;

            param_1[0x110] = iVar6 + 2;

            if (iVar6 + 2 != iVar4) {

              uVar7 = (uint)(byte)(param_1[5] == 1 ^ (byte)iVar13);

              if (uVar7 == param_1[0xf]) {

                uVar7 = param_1[0xe];

                param_1[3] = 3;

                bVar3 = FUN_00482a20();

                param_1[0xe] = (*(byte *)((uVar7 >> 1) + param_1[0x315]) >>

                                ((byte)uVar7 & 1) * '\x04' & 0xf) << 0x10 |

                               (uint)*(ushort *)(param_1[0x314] + uVar7 * 2);

                if (param_1[5] == 0) {

                  iVar12 = param_1[6] + 1;

                  param_1[5] = *(int *)(&DAT_00afcde8 + param_1[6] * 4);

                  param_1[6] = iVar12;

                  if (iVar12 == 0x200) {

                    param_1[6] = 0;

                  }

                }

                param_1[5] = param_1[5] + -1;

                param_1[0x110] = iVar6 + 3;

                if (iVar6 + 3 != iVar4) {

                  uVar7 = (uint)(bVar3 ^ param_1[5] == 1);

                  if (uVar7 == param_1[0xf]) {

                    uVar7 = param_1[0xe];

                    uVar9 = FUN_00482a20();

                    param_1[0xe] = (*(byte *)((uVar7 >> 1) + param_1[0x315]) >>

                                    ((byte)uVar7 & 1) * '\x04' & 0xf) << 0x10 |

                                   (uint)*(ushort *)(param_1[0x314] + uVar7 * 2);

                    if (param_1[5] == 0) {

                      iVar4 = param_1[6] + 1;

                      param_1[5] = *(int *)(&DAT_00afcde8 + param_1[6] * 4);

                      param_1[6] = iVar4;

                      if (iVar4 == 0x200) {

                        param_1[6] = 0;

                      }

                    }

                    param_1[5] = param_1[5] + -1;

                    uVar7 = param_1[0xe];

                    param_1[0x110] = iVar6 + 4;

                    param_1[3] = ((uint)(param_1[5] == 1) ^ uVar9 & 0xff) + 4;

                    uVar9 = FUN_00482a20();

                    param_1[0xf] = uVar9;

                    param_1[0xe] = (*(byte *)((uVar7 >> 1) + param_1[0x315]) >>

                                    ((byte)uVar7 & 1) * '\x04' & 0xf) << 0x10 |

                                   (uint)*(ushort *)(param_1[0x314] + uVar7 * 2);

                    if (param_1[5] == 0) {

                      iVar4 = param_1[6] + 1;

                      param_1[5] = *(int *)(&DAT_00afcde8 + param_1[6] * 4);

                      param_1[6] = iVar4;

                      if (iVar4 == 0x200) {

                        param_1[6] = 0;

                      }

                    }

                    param_1[5] = param_1[5] + -1;

                    param_1[0xf] = param_1[5] == 1 ^ uVar9;

                    param_1[0x110] = iVar6 + 5;

                  }

                  else {

                    param_1[0xf] = uVar7;

                  }

                }

              }

              else {

                param_1[0xf] = uVar7;

              }

            }

          }

          else {

            param_1[0xf] = uVar7;

          }

        }

      }

      else {

        **(uint8_t **)(*param_1 + 0x10) = (char)param_1[2];

        uVar7 = *(uint *)(&DAT_00afd5e8 +

                         ((uint)param_1[0x318] >> 0x18 ^ (uint)*(byte *)(param_1 + 2)) * 4);

        param_1[3] = param_1[3] + -1;

        param_1[0x318] = param_1[0x318] << 8 ^ uVar7;

        *(int *)(*param_1 + 0x10) = *(int *)(*param_1 + 0x10) + 1;

        *(int *)(*param_1 + 0x14) = *(int *)(*param_1 + 0x14) + -1;

        *(int *)(*param_1 + 0x18) = *(int *)(*param_1 + 0x18) + 1;

        if (*(int *)(*param_1 + 0x18) == 0) {

          piVar1 = (int *)(*param_1 + 0x1c);

          *piVar1 = *piVar1 + 1;

        }

      }

    }

  }

  return;

}
