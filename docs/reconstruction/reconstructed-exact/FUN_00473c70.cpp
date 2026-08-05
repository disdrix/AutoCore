// =============================================================================
// FUN_00473c70
// -----------------------------------------------------------------------------
// Stable ID: aa_00473c70
// Address:   0x00473c70  (autoassault.exe, image base 0x400000)
// System:    unknown
// Generated: 2026-07-23 from raw capture (scaffold; refine for important units)
// Exactness: Behavior-preserving rewrite of decompiler control flow. Not modernization.
// Bit-for-bit vs retail EXE: DEFERRED (loaded image may differ slightly).
// =============================================================================

// PURPOSE (auto): Scaffold unit for FUN_00473c70 @ 0x00473c70
// Stable ID: aa_00473c70
// No high-value strings recovered; name via xrefs/callers in follow-up.
// Readability: control flow preserved from Ghidra decompile; types tentative.

// READABILITY (auto CF):
//  - Body size: ~173 non-empty decompiler lines.
//  - Control keywords: if×16, do×9, while×9, return×9, switch×1, for×1.
//  - Notable callees: FUN_00473c70.
//  - Return sites: 9.

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

void FUN_00473c70(int *param_1,byte *param_2,int param_3,int param_4,byte param_5)



{

  byte bVar1;

  char cVar2;

  uint16_t uVar3;

  byte *pbVar4;

  uint uVar5;

  uint uVar6;

  int iVar7;

  uint uVar8;

  uint uVar9;

  int local_8;

  

  bVar1 = *(byte *)((int)param_1 + 9);

  iVar7 = *param_1;

  if (((bVar1 < 9) && (param_3 != 0)) || ((bVar1 == 0x10 && (param_4 != 0)))) {

    switch((char)param_1[2]) {

    case '\0':

      if ((bVar1 == 2) && (iVar7 != 0)) {

        local_8 = (iVar7 - 1U >> 2) + 1;

        pbVar4 = param_2;

        do {

          uVar5 = (uint)*pbVar4;

          uVar9 = uVar5 & 0xc;

          uVar6 = uVar5 & 3;

          uVar8 = uVar5 & 0x30;

          uVar5 = uVar5 & 0xc0;

          *pbVar4 = (byte)((byte)(*(byte *)(((uVar9 * 4 | uVar9) * 4 | (int)uVar9 >> 2 | uVar9) +

                                           param_3) & 0xcf |

                                 *(byte *)((((uVar6 * 4 | uVar6) * 4 | uVar6) * 4 | uVar6) + param_3

                                          ) >> 2) >> 2 |

                          *(byte *)(((int)((int)uVar8 >> 2 | uVar8) >> 2 | uVar8 * 4 | uVar8) +

                                   param_3) & 0xc3) >> 2 |

                    *(byte *)(((int)((int)((int)uVar5 >> 2 | uVar5) >> 2 | uVar5) >> 2 | uVar5) +

                             param_3) & 0xc0;

          pbVar4 = pbVar4 + 1;

          local_8 = local_8 + -1;

        } while (local_8 != 0);

      }

      cVar2 = *(char *)((int)param_1 + 9);

      if (cVar2 == '\x04') {

        if (iVar7 != 0) {

          iVar7 = (iVar7 - 1U >> 1) + 1;

          do {

            uVar6 = *param_2 & 0xf0;

            uVar5 = *param_2 & 0xf;

            *param_2 = *(byte *)(((int)uVar6 >> 4 | uVar6) + param_3) & 0xf0 |

                       *(byte *)((uVar5 << 4 | uVar5) + param_3) >> 4;

            param_2 = param_2 + 1;

            iVar7 = iVar7 + -1;

          } while (iVar7 != 0);

          return;

        }

      }

      else if (cVar2 == '\b') {

        if (iVar7 != 0) {

          do {

            *param_2 = *(byte *)((uint)*param_2 + param_3);

            param_2 = param_2 + 1;

            iVar7 = iVar7 + -1;

          } while (iVar7 != 0);

          return;

        }

      }

      else if (cVar2 == '\x10') {

        for (; iVar7 != 0; iVar7 = iVar7 + -1) {

          uVar3 = *(uint16_t *)

                   (*(int *)(param_4 + (uint)(param_2[1] >> (param_5 & 0x1f)) * 4) +

                   (uint)*param_2 * 2);

          *param_2 = (byte)((ushort)uVar3 >> 8);

          param_2[1] = (byte)uVar3;

          param_2 = param_2 + 2;

        }

      }

      break;

    case '\x02':

      if (bVar1 == 8) {

        if (iVar7 != 0) {

          do {

            *param_2 = *(byte *)((uint)*param_2 + param_3);

            param_2[1] = *(byte *)((uint)param_2[1] + param_3);

            param_2[2] = *(byte *)((uint)param_2[2] + param_3);

            param_2 = param_2 + 3;

            iVar7 = iVar7 + -1;

          } while (iVar7 != 0);

          return;

        }

      }

      else if (iVar7 != 0) {

        do {

          uVar3 = *(uint16_t *)

                   (*(int *)(param_4 + (uint)(param_2[1] >> (param_5 & 0x1f)) * 4) +

                   (uint)*param_2 * 2);

          param_2[1] = (byte)uVar3;

          *param_2 = (byte)((ushort)uVar3 >> 8);

          uVar3 = *(uint16_t *)

                   (*(int *)(param_4 + (uint)(param_2[3] >> (param_5 & 0x1f)) * 4) +

                   (uint)param_2[2] * 2);

          param_2[3] = (byte)uVar3;

          param_2[2] = (byte)((ushort)uVar3 >> 8);

          uVar3 = *(uint16_t *)

                   (*(int *)(param_4 + (uint)(param_2[5] >> (param_5 & 0x1f)) * 4) +

                   (uint)param_2[4] * 2);

          param_2[4] = (byte)((ushort)uVar3 >> 8);

          param_2[5] = (byte)uVar3;

          param_2 = param_2 + 6;

          iVar7 = iVar7 + -1;

        } while (iVar7 != 0);

        return;

      }

      break;

    case '\x04':

      if (bVar1 == 8) {

        if (iVar7 != 0) {

          do {

            *param_2 = *(byte *)((uint)*param_2 + param_3);

            param_2 = param_2 + 2;

            iVar7 = iVar7 + -1;

          } while (iVar7 != 0);

          return;

        }

      }

      else if (iVar7 != 0) {

        do {

          uVar3 = *(uint16_t *)

                   (*(int *)(param_4 + (uint)(param_2[1] >> (param_5 & 0x1f)) * 4) +

                   (uint)*param_2 * 2);

          *param_2 = (byte)((ushort)uVar3 >> 8);

          param_2[1] = (byte)uVar3;

          param_2 = param_2 + 4;

          iVar7 = iVar7 + -1;

        } while (iVar7 != 0);

        return;

      }

      break;

    case '\x06':

      if (bVar1 == 8) {

        if (iVar7 != 0) {

          do {

            *param_2 = *(byte *)((uint)*param_2 + param_3);

            param_2[1] = *(byte *)((uint)param_2[1] + param_3);

            param_2[2] = *(byte *)((uint)param_2[2] + param_3);

            param_2 = param_2 + 4;

            iVar7 = iVar7 + -1;

          } while (iVar7 != 0);

          return;

        }

      }

      else if (iVar7 != 0) {

        do {

          uVar3 = *(uint16_t *)

                   (*(int *)(param_4 + (uint)(param_2[1] >> (param_5 & 0x1f)) * 4) +

                   (uint)*param_2 * 2);

          param_2[1] = (byte)uVar3;

          *param_2 = (byte)((ushort)uVar3 >> 8);

          uVar3 = *(uint16_t *)

                   (*(int *)(param_4 + (uint)(param_2[3] >> (param_5 & 0x1f)) * 4) +

                   (uint)param_2[2] * 2);

          param_2[3] = (byte)uVar3;

          param_2[2] = (byte)((ushort)uVar3 >> 8);

          uVar3 = *(uint16_t *)

                   (*(int *)(param_4 + (uint)(param_2[5] >> (param_5 & 0x1f)) * 4) +

                   (uint)param_2[4] * 2);

          param_2[4] = (byte)((ushort)uVar3 >> 8);

          param_2[5] = (byte)uVar3;

          param_2 = param_2 + 8;

          iVar7 = iVar7 + -1;

        } while (iVar7 != 0);

        return;

      }

    }

  }

  return;

}
