// =============================================================================
// Named_CalleeOf_Named_CalleeOf_Named_CalleeOf_Named_assPackManag_00478f50
// -----------------------------------------------------------------------------
// Stable ID: aa_00478f50
// Callee of Named_CalleeOf_Named_CalleeOf_Named_assPackManager
// Address:   0x00478f50  (autoassault.exe, image base 0x400000)
// System:    unknown
// Generated: 2026-07-23 from raw capture (scaffold; refine for important units)
// Exactness: Behavior-preserving rewrite of decompiler control flow. Not modernization.
// Bit-for-bit vs retail EXE: DEFERRED (loaded image may differ slightly).
// =============================================================================

// PURPOSE (auto): Called from Named_CalleeOf_Named_CalleeOf_Named_assPackManager: callee helper. Evidence string: "incorrect header check". Supports parent flow (not a free-standing entry point).
// Embedded strings (evidence):
//   - "incorrect header check"
//   - "invalid window size"
//   - "unknown compression method"
//   - "unknown header flags set"
//   - "header crc mismatch"
//   - "invalid block type"
// Readability: control flow preserved from Ghidra decompile; types tentative.

// READABILITY (auto CF):
//  - Body size: ~1049 non-empty decompiler lines.
//  - Control keywords: if×119, goto×63, while×20, do×19, for×14, return×7, switch×2.
//  - Notable callees: FUN_0046d130×10, FUN_0047fc90×3, FUN_0047f5d0×2, FUN_00478e20, FUN_00478e40, FUN_00478f50, FUN_0047f7d0.
//  - Strings: "incorrect header check"; "invalid window size"; "unknown compression method"; "unknown header flags set".
//  - Return sites: 7.

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

int Named_CalleeOf_Named_CalleeOf_Named_CalleeOf_Named_assPackManag_00478f50(int *param_1,int param_2)



{

  uint16_t uVar1;

  uint *puVar2;

  uint uVar3;

  char cVar4;

  ushort uVar5;

  byte *pbVar6;

  uint uVar7;

  int iVar8;

  uint uVar9;

  byte bVar10;

  byte bVar11;

  uint uVar12;

  uint extraout_EDX;

  uint uVar13;

  uint uVar14;

  uint uVar15;

  byte *pbVar16;

  byte *pbVar17;

  int iVar18;

  uint local_38;

  byte *local_34;

  uint local_30;

  uint local_2c;

  uint local_28;

  byte *local_20;

  uint local_1c;

  byte *local_18;

  int local_14;

  uint local_10;

  uint local_8;

  

  if ((((param_1 == (int *)0x0) || (puVar2 = (uint *)param_1[7], puVar2 == (uint *)0x0)) ||

      (param_1[3] == 0)) || ((*param_1 == 0 && (param_1[1] != 0)))) {

    return -2;

  }

  if (*puVar2 == 0xb) {

    *puVar2 = 0xc;

  }

  local_20 = (byte *)param_1[3];

  uVar14 = puVar2[0xc];

  uVar15 = puVar2[0xd];

  pbVar16 = (byte *)*param_1;

  uVar3 = param_1[1];

  local_28 = param_1[4];

  uVar7 = *puVar2;

  local_14 = 0;

  local_38 = uVar14;

  local_34 = pbVar16;

  uVar9 = uVar3;

  local_30 = uVar3;

  local_1c = local_28;

  do {

    uVar13 = uVar9;

    switch(uVar7) {

    case 0:

      if (puVar2[2] == 0) {

        *puVar2 = 0xc;

      }

      else {

        for (; uVar15 < 0x10; uVar15 = uVar15 + 8) {

          uVar13 = 0;

          if (uVar9 == 0) goto LAB_0047a1db;

          bVar11 = *pbVar16;

          uVar9 = uVar9 - 1;

          pbVar16 = pbVar16 + 1;

          uVar14 = uVar14 + ((uint)bVar11 << ((byte)uVar15 & 0x1f));

          local_38 = uVar14;

          local_34 = pbVar16;

          local_30 = uVar9;

        }

        if (((puVar2[2] & 2) == 0) || (uVar14 != 0x8b1f)) {

          puVar2[4] = 0;

          if (((puVar2[2] & 1) == 0) ||

             (uVar7 = uVar14 & 0xff, uVar13 = uVar14 >> 8, uVar14 = local_38,

             (uVar7 * 0x100 + uVar13) % 0x1f != 0)) {

            param_1[6] = (int)"incorrect header check";

          }

          else if (((byte)local_38 & 0xf) == 8) {

            uVar14 = local_38 >> 4;

            uVar15 = uVar15 - 4;

            if ((uVar14 & 0xf) + 8 <= puVar2[7]) {

              uVar15 = 0;

              puVar2[5] = 1;

              param_1[0xc] = 1;

              *puVar2 = ~(local_38 >> 0xc) & 2 | 9;

              local_38 = 0;

              uVar14 = 0;

              goto LAB_0047a179;

            }

            param_1[6] = (int)"invalid window size";

            local_38 = uVar14;

          }

          else {

            param_1[6] = (int)"unknown compression method";

          }

          break;

        }

        uVar15 = 0;

        puVar2[5] = 0;

        uVar7 = FUN_0046d130();

        puVar2[5] = uVar7;

        local_38 = 0;

        *puVar2 = 1;

        uVar14 = 0;

      }

      goto LAB_0047a179;

    case 1:

      for (; uVar15 < 0x10; uVar15 = uVar15 + 8) {

        uVar13 = 0;

        if (uVar9 == 0) goto LAB_0047a1db;

        bVar11 = *pbVar16;

        uVar9 = uVar9 - 1;

        pbVar16 = pbVar16 + 1;

        uVar14 = uVar14 + ((uint)bVar11 << ((byte)uVar15 & 0x1f));

        local_38 = uVar14;

        local_34 = pbVar16;

        local_30 = uVar9;

      }

      puVar2[4] = uVar14;

      if ((char)uVar14 == '\b') {

        if ((uVar14 & 0xe000) == 0) {

          if ((uVar14 & 0x200) != 0) {

            uVar7 = FUN_0046d130();

            puVar2[5] = uVar7;

          }

          uVar15 = 0;

          *puVar2 = 2;

          uVar14 = 0;

          do {

            uVar13 = 0;

            if (uVar9 == 0) goto LAB_0047a1db;

            bVar11 = *pbVar16;

            bVar10 = (byte)uVar15;

            uVar15 = uVar15 + 8;

            uVar9 = uVar9 - 1;

            pbVar16 = pbVar16 + 1;

            uVar14 = uVar14 + ((uint)bVar11 << (bVar10 & 0x1f));

joined_r0x004791a2:

          } while (uVar15 < 0x20);

          if ((*(byte *)((int)puVar2 + 0x11) & 2) != 0) {

            uVar7 = FUN_0046d130();

            puVar2[5] = uVar7;

          }

          uVar15 = 0;

          *puVar2 = 3;

          uVar14 = 0;

          do {

            uVar13 = 0;

            if (uVar9 == 0) goto LAB_0047a1db;

            bVar11 = *pbVar16;

            bVar10 = (byte)uVar15;

            uVar9 = uVar9 - 1;

            pbVar16 = pbVar16 + 1;

            uVar15 = uVar15 + 8;

            uVar14 = uVar14 + ((uint)bVar11 << (bVar10 & 0x1f));

            local_34 = pbVar16;

            local_30 = uVar9;

joined_r0x0047920d:

          } while (uVar15 < 0x10);

          if ((*(byte *)((int)puVar2 + 0x11) & 2) != 0) {

            uVar7 = FUN_0046d130();

            puVar2[5] = uVar7;

          }

          uVar15 = 0;

          local_38 = 0;

          *puVar2 = 4;

          uVar14 = 0;

          goto switchD_00478fd2_caseD_4;

        }

        param_1[6] = (int)"unknown header flags set";

      }

      else {

        param_1[6] = (int)"unknown compression method";

      }

      break;

    case 2:

      goto joined_r0x004791a2;

    case 3:

      goto joined_r0x0047920d;

    case 4:

switchD_00478fd2_caseD_4:

      if ((*(byte *)((int)puVar2 + 0x11) & 4) != 0) {

        for (; uVar15 < 0x10; uVar15 = uVar15 + 8) {

          uVar13 = 0;

          if (uVar9 == 0) goto LAB_0047a1db;

          bVar11 = *pbVar16;

          uVar9 = uVar9 - 1;

          pbVar16 = pbVar16 + 1;

          uVar14 = uVar14 + ((uint)bVar11 << ((byte)uVar15 & 0x1f));

          local_34 = pbVar16;

          local_30 = uVar9;

        }

        puVar2[0xe] = uVar14;

        if ((*(byte *)((int)puVar2 + 0x11) & 2) != 0) {

          uVar7 = FUN_0046d130();

          puVar2[5] = uVar7;

        }

        uVar15 = 0;

        local_38 = 0;

        uVar14 = 0;

      }

      *puVar2 = 5;

      uVar13 = uVar9;

    case 5:

      if ((puVar2[4] & 0x400) == 0) {

LAB_00479338:

        *puVar2 = 6;

switchD_00478fd2_caseD_6:

        if ((*(byte *)((int)puVar2 + 0x11) & 8) == 0) {

LAB_004793a5:

          *puVar2 = 7;

switchD_00478fd2_caseD_7:

          if ((*(byte *)((int)puVar2 + 0x11) & 0x10) == 0) {

LAB_00479415:

            *puVar2 = 8;

            uVar9 = uVar13;

switchD_00478fd2_caseD_8:

            if ((*(byte *)((int)puVar2 + 0x11) & 2) != 0) {

              for (; uVar15 < 0x10; uVar15 = uVar15 + 8) {

                uVar13 = 0;

                if (uVar9 == 0) goto LAB_0047a1db;

                bVar11 = *pbVar16;

                uVar9 = uVar9 - 1;

                pbVar16 = pbVar16 + 1;

                uVar14 = uVar14 + ((uint)bVar11 << ((byte)uVar15 & 0x1f));

                local_38 = uVar14;

                local_34 = pbVar16;

                local_30 = uVar9;

              }

              if (uVar14 != (puVar2[5] & 0xffff)) {

                param_1[6] = (int)"header crc mismatch";

                break;

              }

              uVar15 = 0;

              local_38 = 0;

              uVar14 = 0;

            }

            puVar2[5] = 0;

            param_1[0xc] = 0;

            *puVar2 = 0xb;

            goto LAB_0047a179;

          }

          if (uVar13 != 0) {

            uVar9 = 0;

            do {

              bVar11 = pbVar16[uVar9];

              uVar9 = uVar9 + 1;

              if (bVar11 == 0) break;

            } while (uVar9 < uVar13);

            if ((*(byte *)((int)puVar2 + 0x11) & 0x20) != 0) {

              if (pbVar16 == (byte *)0x0) {

                uVar7 = 0;

              }

              else {

                uVar7 = FUN_0046d130();

                uVar14 = local_38;

              }

              puVar2[5] = uVar7;

            }

            uVar13 = uVar13 - uVar9;

            pbVar16 = pbVar16 + uVar9;

            local_34 = pbVar16;

            local_30 = uVar13;

            if (bVar11 == 0) goto LAB_00479415;

          }

        }

        else if (uVar13 != 0) {

          uVar9 = 0;

          do {

            bVar11 = pbVar16[uVar9];

            uVar9 = uVar9 + 1;

            if (bVar11 == 0) break;

          } while (uVar9 < uVar13);

          if ((*(byte *)((int)puVar2 + 0x11) & 0x20) != 0) {

            if (pbVar16 == (byte *)0x0) {

              uVar7 = 0;

            }

            else {

              uVar7 = FUN_0046d130();

              uVar14 = local_38;

            }

            puVar2[5] = uVar7;

          }

          uVar13 = uVar13 - uVar9;

          pbVar16 = pbVar16 + uVar9;

          local_34 = pbVar16;

          local_30 = uVar13;

          if (bVar11 == 0) goto LAB_004793a5;

        }

      }

      else {

        uVar9 = puVar2[0xe];

        uVar7 = uVar9;

        if (uVar13 < uVar9) {

          uVar7 = uVar13;

        }

        if (uVar7 != 0) {

          if ((puVar2[4] & 0x200) != 0) {

            if (pbVar16 == (byte *)0x0) {

              uVar12 = 0;

            }

            else {

              uVar12 = FUN_0046d130();

              uVar14 = local_38;

            }

            puVar2[5] = uVar12;

          }

          uVar13 = uVar13 - uVar7;

          pbVar16 = pbVar16 + uVar7;

          puVar2[0xe] = uVar9 - uVar7;

          local_34 = pbVar16;

          local_30 = uVar13;

        }

        if (puVar2[0xe] == 0) goto LAB_00479338;

      }

LAB_0047a1db:

      param_1[3] = (int)local_20;

      param_1[4] = local_28;

      *param_1 = (int)pbVar16;

      param_1[1] = uVar13;

      puVar2[0xc] = uVar14;

      puVar2[0xd] = uVar15;

      if (((puVar2[8] == 0) && ((0x17 < (int)*puVar2 || (local_1c == param_1[4])))) ||

         (iVar8 = FUN_00478e40(param_1), iVar8 == 0)) {

        iVar8 = param_1[1];

        iVar18 = local_1c - param_1[4];

        param_1[2] = param_1[2] + (uVar3 - iVar8);

        param_1[5] = param_1[5] + iVar18;

        puVar2[6] = puVar2[6] + iVar18;

        if ((puVar2[2] != 0) && (iVar18 != 0)) {

          if (puVar2[4] == 0) {

            uVar9 = FUN_0047f5d0();

          }

          else if (param_1[3] == iVar18) {

            uVar9 = 0;

          }

          else {

            uVar9 = FUN_0046d130();

          }

          puVar2[5] = uVar9;

          param_1[0xc] = uVar9;

        }

        param_1[0xb] = (-(uint)(puVar2[1] != 0) & 0x40) + ((*puVar2 != 0xb) - 1 & 0x80) +

                       puVar2[0xd];

        if (((uVar3 - iVar8 != 0) || (iVar18 != 0)) && (param_2 != 4)) {

          return local_14;

        }

        if (local_14 != 0) {

          return local_14;

        }

        return -5;

      }

      *puVar2 = 0x1c;

switchD_00478fd2_caseD_1c:

      return -4;

    case 6:

      goto switchD_00478fd2_caseD_6;

    case 7:

      goto switchD_00478fd2_caseD_7;

    case 8:

      goto switchD_00478fd2_caseD_8;

    case 9:

      for (; uVar15 < 0x20; uVar15 = uVar15 + 8) {

        uVar13 = 0;

        if (uVar9 == 0) goto LAB_0047a1db;

        bVar11 = *pbVar16;

        uVar9 = uVar9 - 1;

        pbVar16 = pbVar16 + 1;

        uVar14 = uVar14 + ((uint)bVar11 << ((byte)uVar15 & 0x1f));

        local_38 = uVar14;

        local_34 = pbVar16;

        local_30 = uVar9;

      }

      uVar7 = ((uVar14 & 0xff00) + uVar14 * 0x10000) * 0x100 + (local_38 >> 0x10 & 0xff) * 0x100 +

              (uVar14 >> 0x18);

      uVar15 = 0;

      puVar2[5] = uVar7;

      param_1[0xc] = uVar7;

      *puVar2 = 10;

      uVar14 = 0;

    case 10:

      if (puVar2[3] == 0) {

        param_1[3] = (int)local_20;

        param_1[1] = uVar9;

        *param_1 = (int)pbVar16;

        param_1[4] = local_28;

        puVar2[0xd] = uVar15;

        puVar2[0xc] = uVar14;

        return 2;

      }

      puVar2[5] = 1;

      param_1[0xc] = 1;

      *puVar2 = 0xb;

      uVar13 = uVar9;

switchD_00478fd2_caseD_b:

      uVar9 = uVar13;

      if (param_2 != 5) {

switchD_00478fd2_caseD_c:

        if (puVar2[1] == 0) {

          for (; uVar15 < 3; uVar15 = uVar15 + 8) {

            uVar13 = 0;

            if (uVar9 == 0) goto LAB_0047a1db;

            bVar11 = *pbVar16;

            uVar9 = uVar9 - 1;

            pbVar16 = pbVar16 + 1;

            uVar14 = uVar14 + ((uint)bVar11 << ((byte)uVar15 & 0x1f));

            local_34 = pbVar16;

            local_30 = uVar9;

          }

          puVar2[1] = uVar14 & 1;

          switch(uVar14 >> 1 & 3) {

          case 0:

            uVar14 = uVar14 >> 3;

            *puVar2 = 0xd;

            uVar15 = uVar15 - 3;

            local_38 = uVar14;

            break;

          case 1:

            FUN_00478e20();

            uVar14 = extraout_EDX >> 2;

            *puVar2 = 0x12;

            uVar15 = uVar15 - 3;

            local_38 = uVar14;

            break;

          case 2:

            uVar14 = uVar14 >> 3;

            *puVar2 = 0xf;

            uVar15 = uVar15 - 3;

            local_38 = uVar14;

            break;

          case 3:

            param_1[6] = (int)"invalid block type";

            *puVar2 = 0x1b;

          default:

            uVar14 = uVar14 >> 3;

            uVar15 = uVar15 - 3;

            local_38 = uVar14;

          }

        }

        else {

          uVar14 = uVar14 >> (sbyte)(uVar15 & 7);

          uVar15 = uVar15 - (uVar15 & 7);

          *puVar2 = 0x18;

          local_38 = uVar14;

        }

        goto LAB_0047a179;

      }

      goto LAB_0047a1db;

    case 0xb:

      goto switchD_00478fd2_caseD_b;

    case 0xc:

      goto switchD_00478fd2_caseD_c;

    case 0xd:

      uVar14 = uVar14 >> (sbyte)(uVar15 & 7);

      for (uVar15 = uVar15 - (uVar15 & 7); uVar15 < 0x20; uVar15 = uVar15 + 8) {

        uVar13 = 0;

        if (uVar9 == 0) goto LAB_0047a1db;

        bVar11 = *pbVar16;

        uVar9 = uVar9 - 1;

        pbVar16 = pbVar16 + 1;

        uVar14 = uVar14 + ((uint)bVar11 << ((byte)uVar15 & 0x1f));

        local_34 = pbVar16;

        local_30 = uVar9;

      }

      if ((uVar14 & 0xffff) == ~uVar14 >> 0x10) {

        uVar15 = 0;

        puVar2[0xe] = uVar14 & 0xffff;

        local_38 = 0;

        *puVar2 = 0xe;

        uVar14 = 0;

        uVar13 = uVar9;

        goto switchD_00478fd2_caseD_e;

      }

      param_1[6] = (int)"invalid stored block lengths";

      local_38 = uVar14;

      break;

    case 0xe:

switchD_00478fd2_caseD_e:

      local_2c = puVar2[0xe];

      uVar9 = uVar13;

      if (local_2c == 0) {

LAB_00479cfe:

        *puVar2 = 0xb;

      }

      else {

        if (uVar13 < local_2c) {

          local_2c = uVar13;

        }

        if (local_28 < local_2c) {

          local_2c = local_28;

        }

        if (local_2c == 0) goto LAB_0047a1db;

        pbVar6 = local_34;

        pbVar17 = local_20;

        for (uVar9 = local_2c >> 2; uVar9 != 0; uVar9 = uVar9 - 1) {

          *(uint32_t /* width from decompiler */ *)pbVar17 = *(uint32_t /* width from decompiler */ *)pbVar6;

          pbVar6 = pbVar6 + 4;

          pbVar17 = pbVar17 + 4;

        }

        uVar9 = local_30 - local_2c;

        pbVar16 = local_34 + local_2c;

        local_28 = local_28 - local_2c;

        local_20 = local_20 + local_2c;

        for (uVar7 = local_2c & 3; uVar7 != 0; uVar7 = uVar7 - 1) {

          *pbVar17 = *pbVar6;

          pbVar6 = pbVar6 + 1;

          pbVar17 = pbVar17 + 1;

        }

        puVar2[0xe] = puVar2[0xe] - local_2c;

        local_34 = pbVar16;

        local_30 = uVar9;

      }

      goto LAB_0047a179;

    case 0xf:

      for (; uVar15 < 0xe; uVar15 = uVar15 + 8) {

        uVar13 = 0;

        if (uVar9 == 0) goto LAB_0047a1db;

        bVar11 = *pbVar16;

        uVar9 = uVar9 - 1;

        pbVar16 = pbVar16 + 1;

        uVar14 = uVar14 + ((uint)bVar11 << ((byte)uVar15 & 0x1f));

        local_34 = pbVar16;

        local_30 = uVar9;

      }

      puVar2[0x16] = (uVar14 & 0x1f) + 0x101;

      uVar13 = uVar14 >> 10;

      uVar7 = (uVar14 >> 5 & 0x1f) + 1;

      uVar14 = uVar14 >> 0xe;

      uVar15 = uVar15 - 0xe;

      puVar2[0x17] = uVar7;

      puVar2[0x15] = (uVar13 & 0xf) + 4;

      local_38 = uVar14;

      if ((puVar2[0x16] < 0x11f) && (uVar7 < 0x1f)) {

        puVar2[0x18] = 0;

        *puVar2 = 0x10;

        goto switchD_00478fd2_caseD_10;

      }

      param_1[6] = (int)"too many length or distance symbols";

      break;

    case 0x10:

switchD_00478fd2_caseD_10:

      if (puVar2[0x18] < puVar2[0x15]) {

        do {

          for (; uVar15 < 3; uVar15 = uVar15 + 8) {

            uVar13 = 0;

            if (uVar9 == 0) goto LAB_0047a1db;

            bVar11 = *pbVar16;

            bVar10 = (byte)uVar15;

            uVar9 = uVar9 - 1;

            pbVar16 = pbVar16 + 1;

            uVar14 = uVar14 + ((uint)bVar11 << (bVar10 & 0x1f));

            local_34 = pbVar16;

            local_30 = uVar9;

          }

          local_38 = uVar14 >> 3;

          uVar15 = uVar15 - 3;

          *(ushort *)((int)puVar2 + (uint)*(ushort *)(&DAT_00a27060 + puVar2[0x18] * 2) * 2 + 0x68)

               = (ushort)uVar14 & 7;

          puVar2[0x18] = puVar2[0x18] + 1;

          uVar14 = local_38;

        } while (puVar2[0x18] < puVar2[0x15]);

      }

      uVar7 = puVar2[0x18];

      while (uVar7 < 0x13) {

        *(uint16_t *)

         ((int)puVar2 + (uint)*(ushort *)(&DAT_00a27060 + puVar2[0x18] * 2) * 2 + 0x68) = 0;

        puVar2[0x18] = puVar2[0x18] + 1;

        uVar7 = puVar2[0x18];

      }

      puVar2[0x19] = (uint)(puVar2 + 0x14a);

      puVar2[0x11] = (uint)(puVar2 + 0x14a);

      puVar2[0x13] = 7;

      local_14 = FUN_0047fc90(0,puVar2 + 0x1a,0x13,puVar2 + 0x19,puVar2 + 0x13,puVar2 + 0xba);

      uVar14 = local_38;

      if (local_14 == 0) {

        puVar2[0x18] = 0;

        *puVar2 = 0x11;

        goto switchD_00478fd2_caseD_11;

      }

      param_1[6] = (int)"invalid code lengths set";

      break;

    case 0x11:

switchD_00478fd2_caseD_11:

      if (puVar2[0x18] < puVar2[0x17] + puVar2[0x16]) {

        do {

          uVar7 = *(uint *)(puVar2[0x11] + ((1 << ((byte)puVar2[0x13] & 0x1f)) - 1U & uVar14) * 4);

          if (uVar15 < (uVar7 >> 8 & 0xff)) {

            do {

              uVar13 = 0;

              if (uVar9 == 0) goto LAB_0047a1db;

              bVar11 = *pbVar16;

              uVar9 = uVar9 - 1;

              pbVar16 = pbVar16 + 1;

              uVar14 = uVar14 + ((uint)bVar11 << ((byte)uVar15 & 0x1f));

              uVar15 = uVar15 + 8;

              uVar7 = *(uint *)(puVar2[0x11] +

                               ((1 << ((byte)puVar2[0x13] & 0x1f)) - 1U & uVar14) * 4);

              local_34 = pbVar16;

              local_30 = uVar9;

            } while (uVar15 < (uVar7 >> 8 & 0xff));

          }

          uVar12 = uVar7 >> 8 & 0xff;

          uVar5 = (ushort)(uVar7 >> 0x10);

          bVar11 = (byte)(uVar7 >> 8);

          if (0xf < uVar5) {

            if (uVar5 == 0x10) {

              if (uVar15 < uVar12 + 2) {

                do {

                  uVar13 = 0;

                  if (uVar9 == 0) goto LAB_0047a1db;

                  bVar10 = *pbVar16;

                  uVar9 = uVar9 - 1;

                  pbVar16 = pbVar16 + 1;

                  uVar14 = uVar14 + ((uint)bVar10 << ((byte)uVar15 & 0x1f));

                  uVar15 = uVar15 + 8;

                  local_34 = pbVar16;

                  local_30 = uVar9;

                } while (uVar15 < uVar12 + 2);

              }

              local_38 = uVar14 >> (bVar11 & 0x1f);

              uVar15 = uVar15 - uVar12;

              if (puVar2[0x18] != 0) {

                uVar1 = *(uint16_t *)((int)puVar2 + puVar2[0x18] * 2 + 0x66);

                local_2c = (local_38 & 3) + 3;

                local_38 = local_38 >> 2;

                uVar15 = uVar15 - 2;

                goto LAB_00479a33;

              }

              param_1[6] = (int)"invalid bit length repeat";

            }

            else {

              if (uVar5 == 0x11) {

                if (uVar15 < uVar12 + 3) {

                  do {

                    uVar13 = 0;

                    if (uVar9 == 0) goto LAB_0047a1db;

                    bVar10 = *pbVar16;

                    uVar9 = uVar9 - 1;

                    pbVar16 = pbVar16 + 1;

                    uVar14 = uVar14 + ((uint)bVar10 << ((byte)uVar15 & 0x1f));

                    uVar15 = uVar15 + 8;

                    local_34 = pbVar16;

                    local_30 = uVar9;

                  } while (uVar15 < uVar12 + 3);

                }

                uVar14 = uVar14 >> (bVar11 & 0x1f);

                local_2c = (uVar14 & 7) + 3;

                local_38 = uVar14 >> 3;

                iVar8 = -3;

              }

              else {

                if (uVar15 < uVar12 + 7) {

                  do {

                    uVar13 = 0;

                    if (uVar9 == 0) goto LAB_0047a1db;

                    bVar10 = *pbVar16;

                    uVar9 = uVar9 - 1;

                    pbVar16 = pbVar16 + 1;

                    uVar14 = uVar14 + ((uint)bVar10 << ((byte)uVar15 & 0x1f));

                    uVar15 = uVar15 + 8;

                    local_34 = pbVar16;

                    local_30 = uVar9;

                  } while (uVar15 < uVar12 + 7);

                }

                uVar14 = uVar14 >> (bVar11 & 0x1f);

                local_2c = (uVar14 & 0x7f) + 0xb;

                local_38 = uVar14 >> 7;

                iVar8 = -7;

              }

              uVar15 = uVar15 + (iVar8 - uVar12);

              uVar1 = 0;

LAB_00479a33:

              if (puVar2[0x18] + local_2c <= puVar2[0x17] + puVar2[0x16]) {

                if (local_2c != 0) {

                  local_10 = local_2c;

                  do {

                    *(uint16_t *)((int)puVar2 + puVar2[0x18] * 2 + 0x68) = uVar1;

                    puVar2[0x18] = puVar2[0x18] + 1;

                    local_10 = local_10 + -1;

                  } while (local_10 != 0);

                }

                goto LAB_00479a73;

              }

              param_1[6] = (int)"invalid bit length repeat";

            }

            *puVar2 = 0x1b;

            break;

          }

          for (; uVar15 < uVar12; uVar15 = uVar15 + 8) {

            uVar13 = 0;

            if (uVar9 == 0) goto LAB_0047a1db;

            bVar10 = *pbVar16;

            uVar9 = uVar9 - 1;

            pbVar16 = pbVar16 + 1;

            uVar14 = uVar14 + ((uint)bVar10 << ((byte)uVar15 & 0x1f));

            local_34 = pbVar16;

            local_30 = uVar9;

          }

          local_38 = uVar14 >> (bVar11 & 0x1f);

          uVar15 = uVar15 - uVar12;

          *(ushort *)((int)puVar2 + puVar2[0x18] * 2 + 0x68) = uVar5;

          puVar2[0x18] = puVar2[0x18] + 1;

LAB_00479a73:

          uVar14 = local_38;

        } while (puVar2[0x18] < puVar2[0x17] + puVar2[0x16]);

      }

      puVar2[0x19] = (uint)(puVar2 + 0x14a);

      puVar2[0x11] = (uint)(puVar2 + 0x14a);

      puVar2[0x13] = 9;

      local_14 = FUN_0047fc90(1,puVar2 + 0x1a,puVar2[0x16],puVar2 + 0x19,puVar2 + 0x13,puVar2 + 0xba

                             );

      uVar14 = local_38;

      if (local_14 == 0) {

        puVar2[0x12] = puVar2[0x19];

        puVar2[0x14] = 6;

        local_14 = FUN_0047fc90(2,(int)puVar2 + puVar2[0x16] * 2 + 0x68,puVar2[0x17],puVar2 + 0x19,

                                puVar2 + 0x14,puVar2 + 0xba);

        if (local_14 == 0) {

          *puVar2 = 0x12;

          goto switchD_00478fd2_caseD_12;

        }

        param_1[6] = (int)"invalid distances set";

      }

      else {

        param_1[6] = (int)"invalid literal/lengths set";

      }

      break;

    case 0x12:

switchD_00478fd2_caseD_12:

      if ((uVar9 < 6) || (local_28 < 0x102)) {

        uVar7 = *(uint *)(puVar2[0x11] + ((1 << ((byte)puVar2[0x13] & 0x1f)) - 1U & uVar14) * 4);

        if (uVar15 < (uVar7 >> 8 & 0xff)) {

          do {

            uVar13 = 0;

            if (uVar9 == 0) goto LAB_0047a1db;

            bVar11 = *pbVar16;

            uVar9 = uVar9 - 1;

            pbVar16 = pbVar16 + 1;

            uVar14 = uVar14 + ((uint)bVar11 << ((byte)uVar15 & 0x1f));

            uVar15 = uVar15 + 8;

            uVar7 = *(uint *)(puVar2[0x11] + ((1 << ((byte)puVar2[0x13] & 0x1f)) - 1U & uVar14) * 4)

            ;

            local_34 = pbVar16;

            local_30 = uVar9;

          } while (uVar15 < (uVar7 >> 8 & 0xff));

        }

        cVar4 = (char)uVar7;

        local_8 = uVar7;

        if ((cVar4 != '\0') && ((uVar7 & 0xf0) == 0)) {

          bVar11 = (byte)(uVar7 >> 8);

          local_8 = *(uint *)(puVar2[0x11] +

                             ((((1 << (cVar4 + bVar11 & 0x1f)) - 1U & uVar14) >> (bVar11 & 0x1f)) +

                             (uVar7 >> 0x10)) * 4);

          uVar12 = uVar7 >> 8 & 0xff;

          if (uVar15 < (local_8 >> 8 & 0xff) + uVar12) {

            do {

              uVar13 = 0;

              if (uVar9 == 0) goto LAB_0047a1db;

              bVar10 = *pbVar16;

              uVar9 = uVar9 - 1;

              pbVar16 = pbVar16 + 1;

              uVar14 = uVar14 + ((uint)bVar10 << ((byte)uVar15 & 0x1f));

              uVar15 = uVar15 + 8;

              local_8 = *(uint *)(puVar2[0x11] +

                                 ((((1 << (cVar4 + bVar11 & 0x1f)) - 1U & uVar14) >> (bVar11 & 0x1f)

                                  ) + (uVar7 >> 0x10)) * 4);

              local_34 = pbVar16;

              local_30 = uVar9;

            } while (uVar15 < (local_8 >> 8 & 0xff) + uVar12);

          }

          uVar14 = uVar14 >> (bVar11 & 0x1f);

          uVar15 = uVar15 - uVar12;

        }

        uVar14 = uVar14 >> ((byte)(local_8 >> 8) & 0x1f);

        uVar15 = uVar15 - (local_8 >> 8 & 0xff);

        puVar2[0xe] = local_8 >> 0x10;

        local_38 = uVar14;

        if ((char)local_8 == '\0') {

          *puVar2 = 0x17;

          goto LAB_0047a179;

        }

        if ((local_8 & 0x20) == 0) {

          if ((local_8 & 0x40) == 0) {

            puVar2[0x10] = local_8 & 0xf;

            *puVar2 = 0x13;

            goto switchD_00478fd2_caseD_13;

          }

          param_1[6] = (int)"invalid literal/length code";

          break;

        }

        goto LAB_00479cfe;

      }

      param_1[3] = (int)local_20;

      param_1[4] = local_28;

      *param_1 = (int)pbVar16;

      param_1[1] = uVar9;

      puVar2[0xc] = uVar14;

      puVar2[0xd] = uVar15;

      FUN_0047f7d0(param_1,local_1c);

      local_28 = param_1[4];

      local_20 = (byte *)param_1[3];

      pbVar16 = (byte *)*param_1;

      uVar9 = param_1[1];

      uVar14 = puVar2[0xc];

      uVar15 = puVar2[0xd];

      local_38 = uVar14;

      local_34 = pbVar16;

      local_30 = uVar9;

      goto LAB_0047a179;

    case 0x13:

switchD_00478fd2_caseD_13:

      if (puVar2[0x10] != 0) {

        if (uVar15 < puVar2[0x10]) {

          do {

            uVar13 = 0;

            if (uVar9 == 0) goto LAB_0047a1db;

            bVar11 = *pbVar16;

            bVar10 = (byte)uVar15;

            uVar9 = uVar9 - 1;

            pbVar16 = pbVar16 + 1;

            uVar15 = uVar15 + 8;

            uVar14 = uVar14 + ((uint)bVar11 << (bVar10 & 0x1f));

            local_34 = pbVar16;

            local_30 = uVar9;

          } while (uVar15 < puVar2[0x10]);

        }

        bVar11 = (byte)puVar2[0x10];

        puVar2[0xe] = puVar2[0xe] + ((1 << (bVar11 & 0x1f)) - 1U & uVar14);

        uVar14 = uVar14 >> (bVar11 & 0x1f);

        uVar15 = uVar15 - puVar2[0x10];

      }

      *puVar2 = 0x14;

    case 0x14:

      uVar7 = *(uint *)(puVar2[0x12] + ((1 << ((byte)puVar2[0x14] & 0x1f)) - 1U & uVar14) * 4);

      if (uVar15 < (uVar7 >> 8 & 0xff)) {

        do {

          uVar13 = 0;

          if (uVar9 == 0) goto LAB_0047a1db;

          bVar11 = *pbVar16;

          uVar9 = uVar9 - 1;

          pbVar16 = pbVar16 + 1;

          uVar14 = uVar14 + ((uint)bVar11 << ((byte)uVar15 & 0x1f));

          uVar15 = uVar15 + 8;

          uVar7 = *(uint *)(puVar2[0x12] + ((1 << ((byte)puVar2[0x14] & 0x1f)) - 1U & uVar14) * 4);

          local_34 = pbVar16;

          local_30 = uVar9;

        } while (uVar15 < (uVar7 >> 8 & 0xff));

      }

      local_8 = uVar7;

      if ((uVar7 & 0xf0) == 0) {

        bVar11 = (byte)(uVar7 >> 8);

        local_8 = *(uint *)(puVar2[0x12] +

                           ((((1 << ((char)uVar7 + bVar11 & 0x1f)) - 1U & uVar14) >> (bVar11 & 0x1f)

                            ) + (uVar7 >> 0x10)) * 4);

        uVar12 = uVar7 >> 8 & 0xff;

        if (uVar15 < (local_8 >> 8 & 0xff) + uVar12) {

          do {

            uVar13 = 0;

            if (uVar9 == 0) goto LAB_0047a1db;

            bVar10 = *pbVar16;

            uVar9 = uVar9 - 1;

            pbVar16 = pbVar16 + 1;

            uVar14 = uVar14 + ((uint)bVar10 << ((byte)uVar15 & 0x1f));

            uVar15 = uVar15 + 8;

            local_8 = *(uint *)(puVar2[0x12] +

                               ((((1 << ((char)uVar7 + bVar11 & 0x1f)) - 1U & uVar14) >>

                                (bVar11 & 0x1f)) + (uVar7 >> 0x10)) * 4);

            local_34 = pbVar16;

            local_30 = uVar9;

          } while (uVar15 < (local_8 >> 8 & 0xff) + uVar12);

        }

        uVar14 = uVar14 >> (bVar11 & 0x1f);

        uVar15 = uVar15 - uVar12;

      }

      uVar14 = uVar14 >> ((byte)(local_8 >> 8) & 0x1f);

      uVar15 = uVar15 - (local_8 >> 8 & 0xff);

      local_38 = uVar14;

      if ((local_8 & 0x40) != 0) {

        param_1[6] = (int)"invalid distance code";

        break;

      }

      puVar2[0xf] = local_8 >> 0x10;

      puVar2[0x10] = local_8 & 0xf;

      *puVar2 = 0x15;

switchD_00478fd2_caseD_15:

      if (puVar2[0x10] != 0) {

        if (uVar15 < puVar2[0x10]) {

          do {

            uVar13 = 0;

            if (uVar9 == 0) goto LAB_0047a1db;

            bVar11 = *pbVar16;

            bVar10 = (byte)uVar15;

            uVar9 = uVar9 - 1;

            pbVar16 = pbVar16 + 1;

            uVar15 = uVar15 + 8;

            uVar14 = uVar14 + ((uint)bVar11 << (bVar10 & 0x1f));

            local_34 = pbVar16;

            local_30 = uVar9;

          } while (uVar15 < puVar2[0x10]);

        }

        bVar11 = (byte)puVar2[0x10];

        puVar2[0xf] = puVar2[0xf] + ((1 << (bVar11 & 0x1f)) - 1U & uVar14);

        uVar14 = uVar14 >> (bVar11 & 0x1f);

        uVar15 = uVar15 - puVar2[0x10];

        local_38 = uVar14;

      }

      if ((puVar2[9] - local_28) + local_1c < puVar2[0xf]) {

        param_1[6] = (int)"invalid distance too far back";

        break;

      }

      *puVar2 = 0x16;

switchD_00478fd2_caseD_16:

      uVar13 = uVar9;

      if (local_28 != 0) {

        local_2c = puVar2[0xf];

        if (local_1c - local_28 < local_2c) {

          local_2c = local_2c - (local_1c - local_28);

          if (puVar2[10] < local_2c) {

            local_2c = local_2c - puVar2[10];

            local_18 = (byte *)((puVar2[0xb] + puVar2[8]) - local_2c);

          }

          else {

            local_18 = (byte *)((puVar2[0xb] - local_2c) + puVar2[10]);

          }

          local_10 = puVar2[0xe];

          if (local_10 < local_2c) goto LAB_00479fb3;

        }

        else {

          local_18 = local_20 + -local_2c;

          local_10 = puVar2[0xe];

LAB_00479fb3:

          local_2c = local_10;

        }

        if (local_28 < local_2c) {

          local_2c = local_28;

        }

        local_28 = local_28 - local_2c;

        puVar2[0xe] = local_10 - local_2c;

        do {

          bVar11 = *local_18;

          local_18 = local_18 + 1;

          *local_20 = bVar11;

          local_20 = local_20 + 1;

          local_2c = local_2c - 1;

        } while (local_2c != 0);

        if (puVar2[0xe] == 0) {

          *puVar2 = 0x12;

        }

        goto LAB_0047a179;

      }

      goto LAB_0047a1db;

    case 0x15:

      goto switchD_00478fd2_caseD_15;

    case 0x16:

      goto switchD_00478fd2_caseD_16;

    case 0x17:

      if (local_28 == 0) goto LAB_0047a1db;

      *local_20 = (byte)puVar2[0xe];

      local_20 = local_20 + 1;

      local_28 = local_28 - 1;

      *puVar2 = 0x12;

      goto LAB_0047a179;

    case 0x18:

      if (puVar2[2] != 0) {

        for (; uVar15 < 0x20; uVar15 = uVar15 + 8) {

          uVar13 = 0;

          if (uVar9 == 0) goto LAB_0047a1db;

          bVar11 = *pbVar16;

          uVar9 = uVar9 - 1;

          pbVar16 = pbVar16 + 1;

          uVar14 = uVar14 + ((uint)bVar11 << ((byte)uVar15 & 0x1f));

          local_38 = uVar14;

          local_34 = pbVar16;

          local_30 = uVar9;

        }

        pbVar6 = (byte *)(local_1c - local_28);

        param_1[5] = (int)(pbVar6 + param_1[5]);

        puVar2[6] = (uint)(pbVar6 + puVar2[6]);

        if (pbVar6 != (byte *)0x0) {

          if (puVar2[4] == 0) {

            uVar7 = FUN_0047f5d0();

            uVar14 = local_38;

          }

          else if (local_20 == pbVar6) {

            uVar7 = 0;

          }

          else {

            uVar7 = FUN_0046d130();

            uVar14 = local_38;

          }

          puVar2[5] = uVar7;

          param_1[0xc] = uVar7;

        }

        uVar7 = uVar14;

        if (puVar2[4] == 0) {

          uVar7 = ((uVar14 & 0xff00) + uVar14 * 0x10000) * 0x100 + (local_38 >> 0x10 & 0xff) * 0x100

                  + (uVar14 >> 0x18);

        }

        local_1c = local_28;

        if (uVar7 != puVar2[5]) {

          param_1[6] = (int)"incorrect data check";

          break;

        }

        uVar15 = 0;

        local_38 = 0;

        uVar14 = 0;

      }

      *puVar2 = 0x19;

    case 0x19:

      if ((puVar2[2] != 0) && (puVar2[4] != 0)) {

        for (; uVar15 < 0x20; uVar15 = uVar15 + 8) {

          uVar13 = 0;

          if (uVar9 == 0) goto LAB_0047a1db;

          bVar11 = *pbVar16;

          uVar9 = uVar9 - 1;

          pbVar16 = pbVar16 + 1;

          uVar14 = uVar14 + ((uint)bVar11 << ((byte)uVar15 & 0x1f));

          local_38 = uVar14;

          local_34 = pbVar16;

          local_30 = uVar9;

        }

        if (uVar14 != puVar2[6]) {

          param_1[6] = (int)"incorrect length check";

          break;

        }

        uVar15 = 0;

        uVar14 = 0;

      }

      *puVar2 = 0x1a;

switchD_00478fd2_caseD_1a:

      local_14 = 1;

      uVar13 = uVar9;

      goto LAB_0047a1db;

    case 0x1a:

      goto switchD_00478fd2_caseD_1a;

    case 0x1b:

      local_14 = -3;

      goto LAB_0047a1db;

    case 0x1c:

      goto switchD_00478fd2_caseD_1c;

    default:

      return -2;

    }

    *puVar2 = 0x1b;

LAB_0047a179:

    uVar7 = *puVar2;

  } while( true );

}
