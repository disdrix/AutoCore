// =============================================================================
// FUN_00472d10
// -----------------------------------------------------------------------------
// Stable ID: aa_00472d10
// Address:   0x00472d10  (autoassault.exe, image base 0x400000)
// System:    unknown
// Generated: 2026-07-23 from raw capture (scaffold; refine for important units)
// Exactness: Behavior-preserving rewrite of decompiler control flow. Not modernization.
// Bit-for-bit vs retail EXE: DEFERRED (loaded image may differ slightly).
// =============================================================================

// PURPOSE (auto): Scaffold unit for FUN_00472d10 @ 0x00472d10
// Stable ID: aa_00472d10
// No high-value strings recovered; name via xrefs/callers in follow-up.
// Readability: control flow preserved from Ghidra decompile; types tentative.

// READABILITY (auto CF):
//  - Body size: ~609 non-empty decompiler lines.
//  - Control keywords: if×60, for×11, do×10, while×10, goto×3, switch×2, return×2.
//  - Notable callees: FUN_00472d10.
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

void __fastcall

FUN_00472d10(uint32_t /* width from decompiler */ param_1,byte *param_2,int *param_3,int param_4,int param_5,int param_6,

            int param_7,int param_8,int param_9,int param_10,int param_11,int param_12,byte param_13

            )



{

  byte bVar1;

  uint16_t uVar2;

  int iVar3;

  byte bVar4;

  byte bVar5;

  uint uVar6;

  short sVar7;

  ushort uVar8;

  byte bVar9;

  int iVar10;

  uint uVar11;

  byte *pbVar12;

  int iVar13;

  int local_c;

  int local_4;

  

  iVar3 = *param_3;

  if ((param_5 != 0) &&

     ((bVar5 = *(byte *)(param_3 + 2), (bVar5 & 4) == 0 || ((bVar5 != 3 && (param_4 != 0)))))) {

    local_c = iVar3;

    switch(bVar5) {

    case 0:

      switch(*(uint8_t *)((int)param_3 + 9)) {

      case 1:

        iVar10 = 7;

        for (iVar13 = iVar3; iVar13 != 0; iVar13 = iVar13 + -1) {

          bVar5 = (byte)iVar10;

          if ((ushort)(*param_2 >> (bVar5 & 0x1f) & 1) == *(ushort *)(param_4 + 8)) {

            bVar4 = (byte)(0x7f7f >> (7 - bVar5 & 0x1f)) & *param_2;

            *param_2 = bVar4;

            *param_2 = *(char *)(param_5 + 8) << (bVar5 & 0x1f) | bVar4;

          }

          if (iVar10 == 0) {

            iVar10 = 7;

            param_2 = param_2 + 1;

          }

          else {

            iVar10 = iVar10 + -1;

          }

        }

        break;

      case 2:

        if (param_7 == 0) {

          iVar10 = 6;

          for (iVar13 = iVar3; iVar13 != 0; iVar13 = iVar13 + -1) {

            bVar5 = (byte)iVar10;

            if ((ushort)(*param_2 >> (bVar5 & 0x1f) & 3) == *(ushort *)(param_4 + 8)) {

              bVar4 = (byte)(0x3f3f >> (6 - bVar5 & 0x1f)) & *param_2;

              *param_2 = bVar4;

              *param_2 = *(char *)(param_5 + 8) << (bVar5 & 0x1f) | bVar4;

            }

            if (iVar10 == 0) {

              iVar10 = 6;

              param_2 = param_2 + 1;

            }

            else {

              iVar10 = iVar10 + -2;

            }

          }

        }

        else {

          iVar10 = 6;

          for (iVar13 = iVar3; iVar13 != 0; iVar13 = iVar13 + -1) {

            bVar5 = (byte)iVar10;

            bVar4 = *param_2 >> (bVar5 & 0x1f) & 3;

            if ((ushort)bVar4 == *(ushort *)(param_4 + 8)) {

              bVar4 = (byte)(0x3f3f >> (6 - bVar5 & 0x1f)) & *param_2;

              *param_2 = bVar4;

              bVar9 = *(char *)(param_5 + 8) << (bVar5 & 0x1f);

            }

            else {

              uVar6 = (uint)bVar4;

              bVar9 = (byte)(0x3f3f >> (6 - bVar5 & 0x1f)) & *param_2;

              bVar4 = (*(byte *)((((uVar6 * 4 | uVar6) * 4 | uVar6) * 4 | uVar6) + param_7) >> 6) <<

                      (bVar5 & 0x1f);

            }

            *param_2 = bVar9 | bVar4;

            if (iVar10 == 0) {

              iVar10 = 6;

              param_2 = param_2 + 1;

            }

            else {

              iVar10 = iVar10 + -2;

            }

          }

        }

        break;

      case 4:

        if (param_7 == 0) {

          iVar10 = 4;

          for (iVar13 = iVar3; iVar13 != 0; iVar13 = iVar13 + -1) {

            bVar5 = (byte)iVar10;

            if ((ushort)(*param_2 >> (bVar5 & 0x1f) & 0xf) == *(ushort *)(param_4 + 8)) {

              bVar4 = (byte)(0xf0f >> (4 - bVar5 & 0x1f)) & *param_2;

              *param_2 = bVar4;

              *param_2 = *(char *)(param_5 + 8) << (bVar5 & 0x1f) | bVar4;

            }

            if (iVar10 == 0) {

              iVar10 = 4;

              param_2 = param_2 + 1;

            }

            else {

              iVar10 = iVar10 + -4;

            }

          }

        }

        else {

          iVar10 = 4;

          for (iVar13 = iVar3; iVar13 != 0; iVar13 = iVar13 + -1) {

            bVar5 = (byte)iVar10;

            bVar4 = *param_2 >> (bVar5 & 0x1f) & 0xf;

            if ((ushort)bVar4 == *(ushort *)(param_4 + 8)) {

              bVar4 = (byte)(0xf0f >> (4 - bVar5 & 0x1f)) & *param_2;

              *param_2 = bVar4;

              bVar9 = *(char *)(param_5 + 8) << (bVar5 & 0x1f);

            }

            else {

              bVar9 = (byte)(0xf0f >> (4 - bVar5 & 0x1f)) & *param_2;

              bVar4 = (*(byte *)(((uint)bVar4 << 4 | (uint)bVar4) + param_7) >> 4) << (bVar5 & 0x1f)

              ;

            }

            *param_2 = bVar9 | bVar4;

            if (iVar10 == 0) {

              iVar10 = 4;

              param_2 = param_2 + 1;

            }

            else {

              iVar10 = iVar10 + -4;

            }

          }

        }

        break;

      case 8:

        iVar13 = iVar3;

        if (param_7 == 0) {

          for (; iVar13 != 0; iVar13 = iVar13 + -1) {

            if ((ushort)*param_2 == *(ushort *)(param_4 + 8)) {

              *param_2 = *(byte *)(param_5 + 8);

            }

            param_2 = param_2 + 1;

          }

        }

        else {

          for (; iVar13 != 0; iVar13 = iVar13 + -1) {

            if ((ushort)*param_2 == *(ushort *)(param_4 + 8)) {

              bVar5 = *(byte *)(param_5 + 8);

            }

            else {

              bVar5 = *(byte *)((uint)*param_2 + param_7);

            }

            *param_2 = bVar5;

            param_2 = param_2 + 1;

          }

        }

        break;

      case 0x10:

        iVar13 = iVar3;

        if (param_10 == 0) {

          for (; iVar13 != 0; iVar13 = iVar13 + -1) {

            if ((ushort)((ushort)*param_2 * 0x100 + (ushort)param_2[1]) == *(short *)(param_4 + 8))

            {

              *param_2 = *(byte *)(param_5 + 9);

              param_2[1] = *(byte *)(param_5 + 8);

            }

            param_2 = param_2 + 2;

          }

        }

        else {

          for (; iVar13 != 0; iVar13 = iVar13 + -1) {

            if ((ushort)((ushort)*param_2 * 0x100 + (ushort)param_2[1]) == *(short *)(param_4 + 8))

            {

              *param_2 = *(byte *)(param_5 + 9);

              uVar8 = (ushort)*(byte *)(param_5 + 8);

            }

            else {

              uVar8 = *(ushort *)

                       (*(int *)(param_10 + (uint)(param_2[1] >> (param_13 & 0x1f)) * 4) +

                       (uint)*param_2 * 2);

              *param_2 = (byte)(uVar8 >> 8);

            }

            param_2[1] = (byte)uVar8;

            param_2 = param_2 + 2;

          }

        }

      }

      break;

    case 2:

      if (*(char *)((int)param_3 + 9) == '\b') {

        if (param_7 == 0) {

          if (iVar3 != 0) {

            param_2 = param_2 + 2;

            iVar13 = iVar3;

            do {

              if ((((ushort)param_2[-2] == *(ushort *)(param_4 + 2)) &&

                  ((ushort)param_2[-1] == *(ushort *)(param_4 + 4))) &&

                 ((ushort)*param_2 == *(ushort *)(param_4 + 6))) {

                param_2[-2] = *(byte *)(param_5 + 2);

                param_2[-1] = *(byte *)(param_5 + 4);

                *param_2 = *(byte *)(param_5 + 6);

              }

              param_2 = param_2 + 3;

              iVar13 = iVar13 + -1;

            } while (iVar13 != 0);

          }

        }

        else if (iVar3 != 0) {

          param_2 = param_2 + 2;

          iVar13 = iVar3;

          do {

            if ((((ushort)param_2[-2] == *(ushort *)(param_4 + 2)) &&

                ((ushort)param_2[-1] == *(ushort *)(param_4 + 4))) &&

               ((ushort)*param_2 == *(ushort *)(param_4 + 6))) {

              param_2[-2] = *(byte *)(param_5 + 2);

              param_2[-1] = *(byte *)(param_5 + 4);

              bVar5 = *(byte *)(param_5 + 6);

            }

            else {

              param_2[-2] = *(byte *)((uint)param_2[-2] + param_7);

              param_2[-1] = *(byte *)((uint)param_2[-1] + param_7);

              bVar5 = *(byte *)((uint)*param_2 + param_7);

            }

            *param_2 = bVar5;

            param_2 = param_2 + 3;

            iVar13 = iVar13 + -1;

          } while (iVar13 != 0);

        }

      }

      else if (param_10 == 0) {

        if (iVar3 != 0) {

          param_2 = param_2 + 2;

          iVar13 = iVar3;

          do {

            if ((((ushort)((ushort)param_2[-2] * 0x100 + (ushort)param_2[-1]) ==

                  *(short *)(param_4 + 2)) &&

                ((ushort)((ushort)*param_2 * 0x100 + (ushort)param_2[1]) == *(short *)(param_4 + 4))

                ) && ((ushort)((ushort)param_2[2] * 0x100 + (ushort)param_2[3]) ==

                      *(short *)(param_4 + 6))) {

              param_2[-2] = *(byte *)(param_5 + 3);

              param_2[-1] = *(byte *)(param_5 + 2);

              *param_2 = *(byte *)(param_5 + 5);

              param_2[1] = *(byte *)(param_5 + 4);

              param_2[2] = *(byte *)(param_5 + 7);

              param_2[3] = *(byte *)(param_5 + 6);

            }

            param_2 = param_2 + 6;

            iVar13 = iVar13 + -1;

          } while (iVar13 != 0);

        }

      }

      else if (iVar3 != 0) {

        param_2 = param_2 + 2;

        do {

          if ((((ushort)((ushort)param_2[-2] * 0x100 + (ushort)param_2[-1]) ==

                *(short *)(param_4 + 2)) &&

              ((ushort)((ushort)*param_2 * 0x100 + (ushort)param_2[1]) == *(short *)(param_4 + 4)))

             && ((ushort)((ushort)param_2[2] * 0x100 + (ushort)param_2[3]) ==

                 *(short *)(param_4 + 6))) {

            param_2[-2] = *(byte *)(param_5 + 3);

            param_2[-1] = *(byte *)(param_5 + 2);

            *param_2 = *(byte *)(param_5 + 5);

            param_2[1] = *(byte *)(param_5 + 4);

            param_2[2] = *(byte *)(param_5 + 7);

            param_2[3] = *(byte *)(param_5 + 6);

          }

          else {

            uVar2 = *(uint16_t *)

                     (*(int *)(param_10 + (uint)(param_2[-1] >> (param_13 & 0x1f)) * 4) +

                     (uint)param_2[-2] * 2);

            param_2[-1] = (byte)uVar2;

            param_2[-2] = (byte)((ushort)uVar2 >> 8);

            uVar2 = *(uint16_t *)

                     (*(int *)(param_10 + (uint)(param_2[1] >> (param_13 & 0x1f)) * 4) +

                     (uint)*param_2 * 2);

            param_2[1] = (byte)uVar2;

            *param_2 = (byte)((ushort)uVar2 >> 8);

            uVar2 = *(uint16_t *)

                     (*(int *)(param_10 + (uint)(param_2[3] >> (param_13 & 0x1f)) * 4) +

                     (uint)param_2[2] * 2);

            param_2[2] = (byte)((ushort)uVar2 >> 8);

            param_2[3] = (byte)uVar2;

          }

          param_2 = param_2 + 6;

          local_c = local_c + -1;

        } while (local_c != 0);

      }

      break;

    case 4:

      if (*(char *)((int)param_3 + 9) == '\b') {

        iVar13 = iVar3;

        pbVar12 = param_2;

        if (((param_9 == 0) || (param_8 == 0)) || (param_7 == 0)) {

          for (; iVar13 != 0; iVar13 = iVar13 + -1) {

            bVar5 = param_2[1];

            if (bVar5 == 0xff) {

              bVar5 = *param_2;

            }

            else if (bVar5 == 0) {

              bVar5 = *(byte *)(param_5 + 8);

            }

            else {

              uVar6 = (ushort)((0xff - (ushort)bVar5) * *(short *)(param_6 + 8)) + 0x80 +

                      (uint)*param_2 * (uint)bVar5 & 0xffff;

              bVar5 = (byte)((uVar6 >> 8) + uVar6 >> 8);

            }

            *pbVar12 = bVar5;

            param_2 = param_2 + 2;

            pbVar12 = pbVar12 + 1;

          }

        }

        else {

          for (; iVar13 != 0; iVar13 = iVar13 + -1) {

            bVar5 = param_2[1];

            if (bVar5 == 0xff) {

              uVar6 = (uint)*param_2;

              iVar10 = param_7;

LAB_00473420:

              *pbVar12 = *(byte *)(uVar6 + iVar10);

            }

            else {

              if (bVar5 != 0) {

                uVar6 = (ushort)((0xff - (ushort)bVar5) * *(short *)(param_6 + 8)) + 0x80 +

                        (uint)*(byte *)((uint)*param_2 + param_9) * (uint)bVar5 & 0xffff;

                uVar6 = (int)((uVar6 >> 8) + uVar6) >> 8 & 0xff;

                iVar10 = param_8;

                goto LAB_00473420;

              }

              *pbVar12 = *(byte *)(param_5 + 8);

            }

            param_2 = param_2 + 2;

            pbVar12 = pbVar12 + 1;

          }

        }

      }

      else if (((param_10 == 0) || (param_11 == 0)) || (param_12 == 0)) {

        if (iVar3 != 0) {

          pbVar12 = param_2 + 3;

          iVar13 = iVar3;

          do {

            uVar8 = (ushort)pbVar12[-1] * 0x100 + (ushort)*pbVar12;

            if (uVar8 == 0xffff) {

              *(uint16_t *)param_2 = *(uint16_t *)(pbVar12 + -3);

            }

            else {

              if (uVar8 == 0) {

                *param_2 = *(byte *)(param_5 + 9);

                bVar5 = *(byte *)(param_5 + 8);

              }

              else {

                uVar6 = ((uint)pbVar12[-3] * 0x100 + (uint)pbVar12[-2] & 0xffff) * (uint)uVar8 +

                        0x8000 + (uint)*(ushort *)(param_6 + 8) * (0xffff - (uint)uVar8);

                iVar10 = (uVar6 >> 0x10) + uVar6;

                bVar5 = (byte)((uint)iVar10 >> 0x10);

                *param_2 = (byte)((uint)iVar10 >> 0x18);

              }

              param_2[1] = bVar5;

            }

            pbVar12 = pbVar12 + 4;

            param_2 = param_2 + 2;

            iVar13 = iVar13 + -1;

          } while (iVar13 != 0);

        }

      }

      else if (iVar3 != 0) {

        pbVar12 = param_2 + 1;

        do {

          uVar8 = (ushort)pbVar12[1] * 0x100 + (ushort)pbVar12[2];

          if (uVar8 == 0xffff) {

            uVar8 = *(ushort *)

                     (*(int *)(param_10 + (uint)(*pbVar12 >> (param_13 & 0x1f)) * 4) +

                     (uint)pbVar12[-1] * 2);

LAB_0047356d:

            *param_2 = (byte)(uVar8 >> 8);

          }

          else {

            if (uVar8 != 0) {

              uVar6 = (uint)*(ushort *)

                             (*(int *)(param_12 + (uint)(*pbVar12 >> (param_13 & 0x1f)) * 4) +

                             (uint)pbVar12[-1] * 2) * (uint)uVar8 + 0x8000 +

                      (uint)*(ushort *)(param_6 + 8) * (0xffff - (uint)uVar8);

              uVar6 = (uVar6 >> 0x10) + uVar6;

              uVar8 = *(ushort *)

                       (*(int *)(param_11 + ((uVar6 >> 0x10 & 0xff) >> (param_13 & 0x1f)) * 4) +

                       (uVar6 >> 0x18) * 2);

              goto LAB_0047356d;

            }

            *param_2 = *(byte *)(param_5 + 9);

            uVar8 = (ushort)*(byte *)(param_5 + 8);

          }

          param_2[1] = (byte)uVar8;

          pbVar12 = pbVar12 + 4;

          param_2 = param_2 + 2;

          local_c = local_c + -1;

        } while (local_c != 0);

      }

      break;

    case 6:

      if (*(char *)((int)param_3 + 9) == '\b') {

        if (((param_9 == 0) || (param_8 == 0)) || (param_7 == 0)) {

          if (iVar3 != 0) {

            pbVar12 = param_2 + 2;

            param_2 = param_2 + 1;

            do {

              bVar5 = param_2[2];

              if (bVar5 == 0xff) {

                pbVar12[-2] = param_2[-1];

                pbVar12[-1] = *param_2;

                bVar5 = param_2[1];

              }

              else if (bVar5 == 0) {

                pbVar12[-2] = *(byte *)(param_5 + 2);

                pbVar12[-1] = *(byte *)(param_5 + 4);

                bVar5 = *(byte *)(param_5 + 6);

              }

              else {

                uVar6 = (uint)bVar5;

                sVar7 = 0xff - (ushort)bVar5;

                uVar11 = param_2[-1] * uVar6 + 0x80 +

                         (uint)(ushort)(*(short *)(param_5 + 2) * sVar7) & 0xffff;

                pbVar12[-2] = (byte)((uVar11 >> 8) + uVar11 >> 8);

                uVar11 = (ushort)(*(short *)(param_5 + 4) * sVar7) + 0x80 + *param_2 * uVar6 &

                         0xffff;

                pbVar12[-1] = (byte)((uVar11 >> 8) + uVar11 >> 8);

                uVar6 = param_2[1] * uVar6 + 0x80 + (uint)(ushort)(*(short *)(param_5 + 6) * sVar7)

                        & 0xffff;

                bVar5 = (byte)((uVar6 >> 8) + uVar6 >> 8);

              }

              *pbVar12 = bVar5;

              param_2 = param_2 + 4;

              pbVar12 = pbVar12 + 3;

              local_c = local_c + -1;

            } while (local_c != 0);

          }

        }

        else if (iVar3 != 0) {

          pbVar12 = param_2 + 2;

          param_2 = param_2 + 1;

          do {

            bVar5 = param_2[2];

            if (bVar5 == 0xff) {

              pbVar12[-2] = *(byte *)((uint)param_2[-1] + param_7);

              pbVar12[-1] = *(byte *)((uint)*param_2 + param_7);

              bVar5 = *(byte *)((uint)param_2[1] + param_7);

            }

            else if (bVar5 == 0) {

              pbVar12[-2] = *(byte *)(param_5 + 2);

              pbVar12[-1] = *(byte *)(param_5 + 4);

              bVar5 = *(byte *)(param_5 + 6);

            }

            else {

              uVar6 = (uint)bVar5;

              sVar7 = 0xff - (ushort)bVar5;

              uVar11 = *(byte *)((uint)param_2[-1] + param_9) * uVar6 + 0x80 +

                       (uint)(ushort)(*(short *)(param_6 + 2) * sVar7) & 0xffff;

              pbVar12[-2] = *(byte *)(((int)((uVar11 >> 8) + uVar11) >> 8 & 0xffU) + param_8);

              uVar11 = *(byte *)((uint)*param_2 + param_9) * uVar6 + 0x80 +

                       (uint)(ushort)(*(short *)(param_6 + 4) * sVar7) & 0xffff;

              pbVar12[-1] = *(byte *)(((int)((uVar11 >> 8) + uVar11) >> 8 & 0xffU) + param_8);

              uVar6 = *(byte *)((uint)param_2[1] + param_9) * uVar6 + 0x80 +

                      (uint)(ushort)(*(short *)(param_6 + 6) * sVar7) & 0xffff;

              bVar5 = *(byte *)(((int)((uVar6 >> 8) + uVar6) >> 8 & 0xffU) + param_8);

            }

            *pbVar12 = bVar5;

            param_2 = param_2 + 4;

            pbVar12 = pbVar12 + 3;

            local_c = local_c + -1;

          } while (local_c != 0);

        }

      }

      else {

        local_4 = iVar3;

        if (((param_10 == 0) || (param_11 == 0)) || (param_12 == 0)) {

          if (iVar3 != 0) {

            pbVar12 = param_2 + 2;

            param_2 = param_2 + 7;

            do {

              uVar8 = (ushort)param_2[-1] * 0x100 + (ushort)*param_2;

              if (uVar8 == 0xffff) {

                *(uint32_t /* width from decompiler */ *)(pbVar12 + -2) = *(uint32_t /* width from decompiler */ *)(param_2 + -7);

                *(uint16_t *)(pbVar12 + 2) = *(uint16_t *)(param_2 + -3);

              }

              else {

                if (uVar8 == 0) {

                  pbVar12[-2] = *(byte *)(param_5 + 3);

                  pbVar12[-1] = *(byte *)(param_5 + 2);

                  *pbVar12 = *(byte *)(param_5 + 5);

                  pbVar12[1] = *(byte *)(param_5 + 4);

                  pbVar12[2] = *(byte *)(param_5 + 7);

                  bVar5 = *(byte *)(param_5 + 6);

                }

                else {

                  bVar5 = param_2[-5];

                  bVar4 = param_2[-4];

                  bVar9 = param_2[-2];

                  uVar11 = (uint)uVar8;

                  bVar1 = param_2[-3];

                  iVar10 = 0xffff - uVar11;

                  uVar6 = (uint)*(ushort *)(param_5 + 2) * iVar10 + 0x8000 +

                          ((uint)param_2[-7] * 0x100 + (uint)param_2[-6] & 0xffff) * uVar11;

                  iVar13 = (uVar6 >> 0x10) + uVar6;

                  pbVar12[-2] = (byte)((uint)iVar13 >> 0x18);

                  pbVar12[-1] = (byte)((uint)iVar13 >> 0x10);

                  uVar6 = (uint)*(ushort *)(param_5 + 4) * iVar10 + 0x8000 +

                          ((uint)bVar5 * 0x100 + (uint)bVar4 & 0xffff) * uVar11;

                  iVar13 = (uVar6 >> 0x10) + uVar6;

                  *pbVar12 = (byte)((uint)iVar13 >> 0x18);

                  pbVar12[1] = (byte)((uint)iVar13 >> 0x10);

                  uVar6 = (uint)*(ushort *)(param_5 + 6) * iVar10 + 0x8000 +

                          ((uint)bVar1 * 0x100 + (uint)bVar9 & 0xffff) * uVar11;

                  iVar13 = (uVar6 >> 0x10) + uVar6;

                  bVar5 = (byte)((uint)iVar13 >> 0x10);

                  pbVar12[2] = (byte)((uint)iVar13 >> 0x18);

                }

                pbVar12[3] = bVar5;

              }

              param_2 = param_2 + 8;

              pbVar12 = pbVar12 + 6;

              local_4 = local_4 + -1;

            } while (local_4 != 0);

          }

        }

        else if (iVar3 != 0) {

          pbVar12 = param_2 + 2;

          param_2 = param_2 + 1;

          do {

            uVar8 = (ushort)param_2[5] * 0x100 + (ushort)param_2[6];

            if (uVar8 == 0xffff) {

              uVar2 = *(uint16_t *)

                       (*(int *)(param_10 + (uint)(*param_2 >> (param_13 & 0x1f)) * 4) +

                       (uint)param_2[-1] * 2);

              pbVar12[-2] = (byte)((ushort)uVar2 >> 8);

              pbVar12[-1] = (byte)uVar2;

              uVar2 = *(uint16_t *)

                       (*(int *)(param_10 + (uint)(param_2[2] >> (param_13 & 0x1f)) * 4) +

                       (uint)param_2[1] * 2);

              *pbVar12 = (byte)((ushort)uVar2 >> 8);

              pbVar12[1] = (byte)uVar2;

              uVar8 = *(ushort *)

                       (*(int *)(param_10 + (uint)(param_2[4] >> (param_13 & 0x1f)) * 4) +

                       (uint)param_2[3] * 2);

LAB_00473a6d:

              pbVar12[2] = (byte)(uVar8 >> 8);

            }

            else {

              if (uVar8 != 0) {

                uVar11 = (uint)uVar8;

                iVar13 = 0xffff - uVar11;

                uVar6 = *(ushort *)

                         (*(int *)(param_12 + (uint)(*param_2 >> (param_13 & 0x1f)) * 4) +

                         (uint)param_2[-1] * 2) * uVar11 + 0x8000 +

                        (uint)*(ushort *)(param_6 + 2) * iVar13;

                uVar6 = (uVar6 >> 0x10) + uVar6;

                uVar2 = *(uint16_t *)

                         (*(int *)(param_11 + ((uVar6 >> 0x10 & 0xff) >> (param_13 & 0x1f)) * 4) +

                         (uVar6 >> 0x18) * 2);

                pbVar12[-2] = (byte)((ushort)uVar2 >> 8);

                pbVar12[-1] = (byte)uVar2;

                uVar6 = *(ushort *)

                         (*(int *)(param_12 + (uint)(param_2[2] >> (param_13 & 0x1f)) * 4) +

                         (uint)param_2[1] * 2) * uVar11 + 0x8000 +

                        (uint)*(ushort *)(param_6 + 4) * iVar13;

                uVar6 = (uVar6 >> 0x10) + uVar6;

                uVar2 = *(uint16_t *)

                         (*(int *)(param_11 + ((uVar6 >> 0x10 & 0xff) >> (param_13 & 0x1f)) * 4) +

                         (uVar6 >> 0x18) * 2);

                *pbVar12 = (byte)((ushort)uVar2 >> 8);

                pbVar12[1] = (byte)uVar2;

                uVar6 = *(ushort *)

                         (*(int *)(param_12 + (uint)(param_2[4] >> (param_13 & 0x1f)) * 4) +

                         (uint)param_2[3] * 2) * uVar11 + 0x8000 +

                        (uint)*(ushort *)(param_6 + 6) * iVar13;

                uVar6 = (uVar6 >> 0x10) + uVar6;

                uVar8 = *(ushort *)

                         (*(int *)(param_11 + ((uVar6 >> 0x10 & 0xff) >> (param_13 & 0x1f)) * 4) +

                         (uVar6 >> 0x18) * 2);

                goto LAB_00473a6d;

              }

              pbVar12[-2] = *(byte *)(param_5 + 3);

              pbVar12[-1] = *(byte *)(param_5 + 2);

              *pbVar12 = *(byte *)(param_5 + 5);

              pbVar12[1] = *(byte *)(param_5 + 4);

              pbVar12[2] = *(byte *)(param_5 + 7);

              uVar8 = (ushort)*(byte *)(param_5 + 6);

            }

            pbVar12[3] = (byte)uVar8;

            param_2 = param_2 + 8;

            pbVar12 = pbVar12 + 6;

            local_4 = local_4 + -1;

          } while (local_4 != 0);

        }

      }

    }

    if ((*(byte *)(param_3 + 2) & 4) != 0) {

      *(char *)((int)param_3 + 10) = *(char *)((int)param_3 + 10) + -1;

      *(byte *)(param_3 + 2) = *(byte *)(param_3 + 2) & 0xfb;

      bVar5 = *(char *)((int)param_3 + 9) * *(char *)((int)param_3 + 10);

      *(byte *)((int)param_3 + 0xb) = bVar5;

      if (7 < bVar5) {

        param_3[1] = (uint)(bVar5 >> 3) * iVar3;

        return;

      }

      param_3[1] = (uint)bVar5 * iVar3 + 7 >> 3;

    }

  }

  return;

}
