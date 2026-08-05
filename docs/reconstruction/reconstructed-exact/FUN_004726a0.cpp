// =============================================================================
// FUN_004726a0
// -----------------------------------------------------------------------------
// Stable ID: aa_004726a0
// Address:   0x004726a0  (autoassault.exe, image base 0x400000)
// System:    unknown
// Generated: 2026-07-23 from raw capture (scaffold; refine for important units)
// Exactness: Behavior-preserving rewrite of decompiler control flow. Not modernization.
// Bit-for-bit vs retail EXE: DEFERRED (loaded image may differ slightly).
// =============================================================================

// PURPOSE (auto): Scaffold unit for FUN_004726a0 @ 0x004726a0
// Stable ID: aa_004726a0
// No high-value strings recovered; name via xrefs/callers in follow-up.
// Readability: control flow preserved from Ghidra decompile; types tentative.

// READABILITY (auto CF):
//  - Body size: ~208 non-empty decompiler lines.
//  - Control keywords: if×18, for×8, return×3.
//  - Notable callees: CONCAT11×16, FUN_004726a0.
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

uint32_t /* width from decompiler */ __fastcall FUN_004726a0(uint32_t /* width from decompiler */ param_1,int param_2,int *param_3,byte *param_4)



{

  int iVar1;

  int iVar2;

  ushort uVar3;

  ushort uVar4;

  int iVar5;

  byte *pbVar6;

  byte *pbVar7;

  byte bVar8;

  ushort uVar9;

  uint uVar10;

  uint uVar11;

  uint uVar12;

  uint uVar13;

  uint32_t /* width from decompiler */ local_24;

  

  iVar1 = *param_3;

  local_24 = 0;

  if ((*(byte *)(param_3 + 2) & 2) == 0) {

    return 0;

  }

  uVar12 = (uint)*(ushort *)(param_2 + 0x22a);

  uVar11 = (uint)*(ushort *)(param_2 + 0x22c);

  uVar13 = (uint)*(ushort *)(param_2 + 0x22e);

  if (*(byte *)(param_3 + 2) == 2) {

    if (*(char *)((int)param_3 + 9) == '\b') {

      iVar5 = iVar1;

      pbVar6 = param_4;

      pbVar7 = param_4;

      if ((*(int *)(param_2 + 0x168) == 0) || (*(int *)(param_2 + 0x16c) == 0)) {

        for (; iVar5 != 0; iVar5 = iVar5 + -1) {

          bVar8 = *pbVar6;

          if ((bVar8 == pbVar6[1]) && (bVar8 == pbVar6[2])) {

            *pbVar7 = pbVar6[2];

          }

          else {

            local_24 = 1;

            *pbVar7 = (byte)(pbVar6[2] * uVar13 + pbVar6[1] * uVar11 + bVar8 * uVar12 >> 0xf);

          }

          pbVar6 = pbVar6 + 3;

          pbVar7 = pbVar7 + 1;

        }

      }

      else {

        for (; iVar5 != 0; iVar5 = iVar5 + -1) {

          iVar2 = *(int *)(param_2 + 0x16c);

          bVar8 = *(byte *)((uint)*pbVar7 + iVar2);

          if ((bVar8 == *(byte *)((uint)pbVar7[1] + iVar2)) &&

             (bVar8 == *(byte *)((uint)pbVar7[2] + iVar2))) {

            bVar8 = pbVar7[2];

          }

          else {

            local_24 = 1;

            bVar8 = *(byte *)((*(byte *)((uint)pbVar7[2] + iVar2) * uVar13 +

                               *(byte *)((uint)pbVar7[1] + iVar2) * uVar11 + bVar8 * uVar12 >> 0xf)

                             + *(int *)(param_2 + 0x168));

          }

          *pbVar6 = bVar8;

          pbVar6 = pbVar6 + 1;

          pbVar7 = pbVar7 + 3;

        }

      }

    }

    else {

      iVar5 = iVar1;

      pbVar6 = param_4;

      pbVar7 = param_4;

      if ((*(int *)(param_2 + 0x178) == 0) || (*(int *)(param_2 + 0x174) == 0)) {

        for (; iVar5 != 0; iVar5 = iVar5 + -1) {

          uVar9 = CONCAT11(*pbVar6,pbVar6[1]);

          if ((uVar9 != CONCAT11(pbVar6[2],pbVar6[3])) || (uVar9 != CONCAT11(pbVar6[4],pbVar6[5])))

          {

            local_24 = 1;

          }

          uVar10 = CONCAT11(pbVar6[4],pbVar6[5]) * uVar13 + CONCAT11(pbVar6[2],pbVar6[3]) * uVar11 +

                   uVar9 * uVar12 >> 0xf;

          *pbVar7 = (byte)(uVar10 >> 8);

          pbVar7[1] = (byte)uVar10;

          pbVar6 = pbVar6 + 6;

          pbVar7 = pbVar7 + 2;

        }

      }

      else {

        for (; iVar5 != 0; iVar5 = iVar5 + -1) {

          uVar9 = CONCAT11(*pbVar7,pbVar7[1]);

          uVar3 = CONCAT11(pbVar7[2],pbVar7[3]);

          uVar4 = CONCAT11(pbVar7[4],pbVar7[5]);

          if ((uVar9 != uVar3) || (uVar9 != uVar4)) {

            bVar8 = (byte)*(uint16_t *)(param_2 + 0x158);

            iVar2 = *(int *)(param_2 + 0x178);

            uVar10 = *(ushort *)

                      (*(int *)(iVar2 + ((uVar9 & 0xff) >> (bVar8 & 0x1f)) * 4) + (uint)*pbVar7 * 2)

                     * uVar12 +

                     *(ushort *)

                      (*(int *)(iVar2 + ((uVar3 & 0xff) >> (bVar8 & 0x1f)) * 4) +

                      (uint)pbVar7[2] * 2) * uVar11 +

                     *(ushort *)

                      (*(int *)(iVar2 + ((uVar4 & 0xff) >> (bVar8 & 0x1f)) * 4) +

                      (uint)pbVar7[4] * 2) * uVar13 >> 0xf;

            local_24 = 1;

            uVar9 = *(ushort *)

                     (*(int *)(*(int *)(param_2 + 0x174) + ((uVar10 & 0xff) >> (bVar8 & 0x1f)) * 4)

                     + ((uVar10 & 0xffff) >> 8) * 2);

          }

          *pbVar6 = (byte)(uVar9 >> 8);

          pbVar6[1] = (byte)uVar9;

          pbVar6 = pbVar6 + 2;

          pbVar7 = pbVar7 + 6;

        }

      }

    }

  }

  if ((char)param_3[2] == '\x06') {

    if (*(char *)((int)param_3 + 9) == '\b') {

      iVar5 = iVar1;

      pbVar6 = param_4;

      if ((*(int *)(param_2 + 0x168) == 0) || (*(int *)(param_2 + 0x16c) == 0)) {

        for (; iVar5 != 0; iVar5 = iVar5 + -1) {

          bVar8 = *pbVar6;

          if ((bVar8 != pbVar6[1]) || (bVar8 != pbVar6[2])) {

            local_24 = 1;

          }

          *param_4 = (byte)(pbVar6[2] * uVar13 + pbVar6[1] * uVar11 + bVar8 * uVar12 >> 0xf);

          param_4[1] = pbVar6[3];

          param_4 = param_4 + 2;

          pbVar6 = pbVar6 + 4;

        }

      }

      else {

        for (; iVar5 != 0; iVar5 = iVar5 + -1) {

          iVar2 = *(int *)(param_2 + 0x16c);

          bVar8 = *(byte *)((uint)*pbVar6 + iVar2);

          if ((bVar8 != *(byte *)((uint)pbVar6[1] + iVar2)) ||

             (bVar8 != *(byte *)((uint)pbVar6[2] + iVar2))) {

            local_24 = 1;

          }

          *param_4 = *(byte *)((*(byte *)((uint)pbVar6[2] + iVar2) * uVar13 +

                                *(byte *)((uint)pbVar6[1] + iVar2) * uVar11 + bVar8 * uVar12 >> 0xf)

                              + *(int *)(param_2 + 0x168));

          param_4[1] = pbVar6[3];

          param_4 = param_4 + 2;

          pbVar6 = pbVar6 + 4;

        }

      }

    }

    else {

      iVar5 = iVar1;

      pbVar6 = param_4;

      if ((*(int *)(param_2 + 0x178) == 0) || (*(int *)(param_2 + 0x174) == 0)) {

        for (; iVar5 != 0; iVar5 = iVar5 + -1) {

          uVar9 = CONCAT11(*pbVar6,pbVar6[1]);

          if ((uVar9 != CONCAT11(pbVar6[2],pbVar6[3])) || (uVar9 != CONCAT11(pbVar6[4],pbVar6[5])))

          {

            local_24 = 1;

          }

          uVar10 = CONCAT11(pbVar6[4],pbVar6[5]) * uVar13 + CONCAT11(pbVar6[2],pbVar6[3]) * uVar11 +

                   uVar9 * uVar12 >> 0xf;

          *param_4 = (byte)(uVar10 >> 8);

          param_4[1] = (byte)uVar10;

          param_4[2] = pbVar6[6];

          param_4[3] = pbVar6[7];

          param_4 = param_4 + 4;

          pbVar6 = pbVar6 + 8;

        }

      }

      else {

        for (; iVar5 != 0; iVar5 = iVar5 + -1) {

          uVar9 = CONCAT11(*pbVar6,pbVar6[1]);

          uVar3 = CONCAT11(pbVar6[2],pbVar6[3]);

          uVar4 = CONCAT11(pbVar6[4],pbVar6[5]);

          if ((uVar9 != uVar3) || (uVar9 != uVar4)) {

            iVar2 = *(int *)(param_2 + 0x178);

            bVar8 = (byte)*(uint16_t *)(param_2 + 0x158);

            uVar10 = *(ushort *)

                      (*(int *)(iVar2 + ((uVar9 & 0xff) >> (bVar8 & 0x1f)) * 4) + (uint)*pbVar6 * 2)

                     * uVar12 +

                     *(ushort *)

                      (*(int *)(iVar2 + ((uVar3 & 0xff) >> (bVar8 & 0x1f)) * 4) +

                      (uint)pbVar6[2] * 2) * uVar11 +

                     *(ushort *)

                      (*(int *)(iVar2 + ((uVar4 & 0xff) >> (bVar8 & 0x1f)) * 4) +

                      (uint)pbVar6[4] * 2) * uVar13 >> 0xf;

            local_24 = 1;

            uVar9 = *(ushort *)

                     (*(int *)(*(int *)(param_2 + 0x174) + ((uVar10 & 0xff) >> (bVar8 & 0x1f)) * 4)

                     + ((uVar10 & 0xffff) >> 8) * 2);

          }

          *param_4 = (byte)(uVar9 >> 8);

          param_4[1] = (byte)uVar9;

          param_4[2] = pbVar6[6];

          param_4[3] = pbVar6[7];

          param_4 = param_4 + 4;

          pbVar6 = pbVar6 + 8;

        }

      }

    }

  }

  *(char *)((int)param_3 + 10) = *(char *)((int)param_3 + 10) + -2;

  *(byte *)(param_3 + 2) = *(byte *)(param_3 + 2) & 0xfd;

  bVar8 = *(char *)((int)param_3 + 9) * *(char *)((int)param_3 + 10);

  *(byte *)((int)param_3 + 0xb) = bVar8;

  if (7 < bVar8) {

    param_3[1] = (uint)(bVar8 >> 3) * iVar1;

    return local_24;

  }

  param_3[1] = (uint)bVar8 * iVar1 + 7 >> 3;

  return local_24;

}
