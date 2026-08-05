// =============================================================================
// Zlib_InvalidLiteralLengthCode
// -----------------------------------------------------------------------------
// Stable ID: aa_0047f7d0
// Address:   0x0047f7d0  (autoassault.exe, image base 0x400000)
// System:    unknown
// Generated: 2026-07-23 from raw capture (scaffold; refine for important units)
// Exactness: Behavior-preserving rewrite of decompiler control flow. Not modernization.
// Bit-for-bit vs retail EXE: DEFERRED (loaded image may differ slightly).
// =============================================================================

// PURPOSE (auto): Domain alias Zlib_InvalidLiteralLengthCode for FUN_0047f7d0 @ 0x0047f7d0
// Stable ID: aa_0047f7d0
// Embedded strings (evidence for future rename):
//   - "invalid literal/length code"
//   - "invalid distance code"
//   - "invalid distance too far back"
// Readability: control flow preserved from Ghidra decompile; types tentative.

// READABILITY (auto CF):
//  - Body size: ~260 non-empty decompiler lines.
//  - Control keywords: if×25, goto×12, while×7, do×6, return×1.
//  - Notable callees: Zlib_InvalidLiteralLengthCode.
//  - Strings: "invalid literal/length code"; "invalid distance code"; "invalid distance too far back".
//  - Return sites: 1.

/*
 * Behavioral notes:
 * Plate-driven rename evidence: "invalid literal/length code"
 * Domain alias of FUN_0047f7d0 (FUN_* retained)
 *
 * - Derived from Ghidra decompile; names prefer Ghidra symbols / plate comments.
 * - Remaining FUN_* / DAT_* identifiers are unresolved pending type recovery.
 * - Runtime / differential verification: OPEN unless matrix says otherwise.
 *
 * Readability pass:
 * - undefinedN widths preserved as fixed-width integers where decompiler width is known.
 * - Control flow and call order preserved from authoritative raw.
 */

void Zlib_InvalidLiteralLengthCode(int *param_1,uint param_2)



{

  byte *pbVar1;

  uint32_t /* width from decompiler */ *puVar2;

  int iVar3;

  uint uVar4;

  uint uVar5;

  int iVar6;

  int iVar7;

  uint32_t /* width from decompiler */ uVar8;

  uint32_t /* width from decompiler */ uVar9;

  uint uVar10;

  uint uVar11;

  int iVar12;

  int iVar13;

  byte *pbVar14;

  byte *pbVar15;

  int iVar16;

  uint uVar17;

  int iVar18;

  uint8_t *puVar19;

  uint8_t *puVar20;

  uint8_t *puVar21;

  uint8_t *puVar22;

  uint uVar23;

  uint uVar24;

  int iVar25;

  byte *local_38;

  

  puVar2 = (uint32_t /* width from decompiler */ *)param_1[7];

  pbVar14 = (byte *)(*param_1 + -1);

  pbVar1 = pbVar14 + param_1[1] + -5;

  iVar3 = param_1[4];

  iVar12 = iVar3 - param_2;

  puVar19 = (uint8_t *)(param_1[3] + -1);

  uVar4 = puVar2[9];

  iVar16 = puVar2[8];

  iVar25 = puVar2[0xb];

  uVar17 = puVar2[0xc];

  uVar5 = puVar2[10];

  iVar6 = puVar2[0x12];

  iVar7 = puVar2[0x11];

  uVar8 = puVar2[0x13];

  uVar9 = puVar2[0x14];

  uVar23 = puVar2[0xd];

  puVar20 = puVar19;

  local_38 = pbVar14;

LAB_0047f868:

  if (uVar23 < 0xf) {

    pbVar15 = pbVar14 + 1;

    pbVar14 = pbVar14 + 2;

    uVar17 = uVar17 + ((uint)*pbVar15 << ((byte)uVar23 & 0x1f)) +

             ((uint)*pbVar14 << ((byte)uVar23 + 8 & 0x1f));

    uVar23 = uVar23 + 0x10;

    local_38 = pbVar14;

  }

  uVar10 = *(uint *)(iVar7 + ((1 << ((byte)uVar8 & 0x1f)) - 1U & uVar17) * 4);

  uVar17 = uVar17 >> ((byte)(uVar10 >> 8) & 0x1f);

  uVar23 = uVar23 - (uVar10 >> 8 & 0xff);

  while ((uVar10 & 0xff) != 0) {

    puVar21 = puVar20;

    if ((uVar10 & 0x10) != 0) {

      param_2 = uVar10 >> 0x10;

      uVar10 = uVar10 & 0xf;

      pbVar15 = pbVar14;

      if (uVar10 != 0) {

        if (uVar23 < uVar10) {

          pbVar15 = pbVar14 + 1;

          pbVar14 = pbVar14 + 1;

          uVar17 = uVar17 + ((uint)*pbVar15 << ((byte)uVar23 & 0x1f));

          uVar23 = uVar23 + 8;

          local_38 = pbVar14;

        }

        param_2 = param_2 + ((1 << (sbyte)uVar10) - 1U & uVar17);

        uVar17 = uVar17 >> (sbyte)uVar10;

        uVar23 = uVar23 - uVar10;

        pbVar15 = pbVar14;

      }

      if (uVar23 < 0xf) {

        pbVar14 = pbVar15 + 1;

        pbVar15 = pbVar15 + 2;

        uVar17 = uVar17 + ((uint)*pbVar14 << ((byte)uVar23 & 0x1f)) +

                 ((uint)*pbVar15 << ((byte)uVar23 + 8 & 0x1f));

        uVar23 = uVar23 + 0x10;

        local_38 = pbVar15;

      }

      uVar10 = *(uint *)(iVar6 + ((1 << ((byte)uVar9 & 0x1f)) - 1U & uVar17) * 4);

      uVar17 = uVar17 >> ((byte)(uVar10 >> 8) & 0x1f);

      uVar23 = uVar23 - (uVar10 >> 8 & 0xff);

      goto joined_r0x0047f991;

    }

    if ((uVar10 & 0x40) != 0) {

      if ((uVar10 & 0x20) == 0) {

        param_1[6] = (int)"invalid literal/length code";

        goto LAB_0047fc27;

      }

      *puVar2 = 0xb;

      goto LAB_0047fc2e;

    }

    uVar10 = *(uint *)(iVar7 + (((1 << ((byte)uVar10 & 0x1f)) - 1U & uVar17) + (uVar10 >> 0x10)) * 4

                      );

    uVar17 = uVar17 >> ((byte)(uVar10 >> 8) & 0x1f);

    uVar23 = uVar23 - (uVar10 >> 8 & 0xff);

  }

  puVar20[1] = (char)(uVar10 >> 0x10);

  puVar21 = puVar20 + 1;

  goto LAB_0047fbd7;

joined_r0x0047f991:

  pbVar14 = pbVar15;

  if ((uVar10 & 0x10) != 0) goto LAB_0047f9d3;

  if ((uVar10 & 0x40) != 0) {

    param_1[6] = (int)"invalid distance code";

LAB_0047fc27:

    *puVar2 = 0x1b;

    goto LAB_0047fc2e;

  }

  uVar10 = *(uint *)(iVar6 + (((1 << ((byte)uVar10 & 0x1f)) - 1U & uVar17) + (uVar10 >> 0x10)) * 4);

  uVar17 = uVar17 >> ((byte)(uVar10 >> 8) & 0x1f);

  uVar23 = uVar23 - (uVar10 >> 8 & 0xff);

  goto joined_r0x0047f991;

LAB_0047f9d3:

  uVar11 = uVar10 & 0xf;

  uVar24 = uVar23;

  if (uVar23 < uVar11) {

    pbVar14 = pbVar15 + 1;

    uVar24 = uVar23 + 8;

    uVar17 = uVar17 + ((uint)pbVar15[1] << ((byte)uVar23 & 0x1f));

    local_38 = pbVar14;

    if (uVar24 < uVar11) {

      pbVar14 = pbVar15 + 2;

      uVar17 = uVar17 + ((uint)pbVar15[2] << ((byte)uVar24 & 0x1f));

      uVar24 = uVar23 + 0x10;

      local_38 = pbVar14;

    }

  }

  uVar23 = uVar24 - uVar11;

  uVar10 = (uVar10 >> 0x10) + ((1 << (sbyte)uVar11) - 1U & uVar17);

  uVar17 = uVar17 >> (sbyte)uVar11;

  if (uVar10 <= (uint)((int)puVar20 - (int)(puVar19 + iVar12))) {

    iVar13 = (int)puVar20 - uVar10;

    do {

      puVar22 = puVar20;

      iVar18 = iVar13;

      puVar22[1] = *(uint8_t *)(iVar18 + 1);

      puVar22[2] = *(uint8_t *)(iVar18 + 2);

      puVar21 = puVar22 + 3;

      *puVar21 = *(uint8_t *)(iVar18 + 3);

      param_2 = param_2 - 3;

      iVar13 = iVar18 + 3;

      puVar20 = puVar21;

    } while (2 < param_2);

    if (param_2 != 0) {

      puVar21 = puVar22 + 4;

      *puVar21 = *(uint8_t *)(iVar18 + 4);

      if (1 < param_2) {

        puVar21 = puVar22 + 5;

        *puVar21 = *(uint8_t *)(iVar18 + 5);

      }

    }

    goto LAB_0047fbd7;

  }

  uVar24 = uVar10 - ((int)puVar20 - (int)(puVar19 + iVar12));

  if (uVar4 < uVar24) {

    param_1[6] = (int)"invalid distance too far back";

    *puVar2 = 0x1b;

LAB_0047fc2e:

    iVar16 = (int)pbVar14 - (uVar23 >> 3);

    iVar25 = uVar23 + (uVar23 >> 3) * -8;

    *param_1 = iVar16 + 1;

    param_1[3] = (int)(puVar21 + 1);

    param_1[1] = (int)(pbVar1 + (5 - iVar16));

    param_1[4] = (int)(puVar19 + iVar3 + -0x101 + (0x101 - (int)puVar21));

    puVar2[0xd] = iVar25;

    puVar2[0xc] = uVar17 & (1 << ((byte)iVar25 & 0x1f)) - 1U;

    return;

  }

  iVar13 = iVar25 + -1;

  if (uVar5 == 0) {

    iVar13 = iVar13 + (iVar16 - uVar24);

    if (uVar24 < param_2) {

      param_2 = param_2 - uVar24;

      do {

        puVar21 = (uint8_t *)(iVar13 + 1);

        iVar13 = iVar13 + 1;

        puVar20 = puVar20 + 1;

        uVar24 = uVar24 - 1;

        *puVar20 = *puVar21;

      } while (uVar24 != 0);

LAB_0047fb00:

      iVar13 = (int)puVar20 - uVar10;

    }

  }

  else if (uVar5 < uVar24) {

    uVar11 = uVar24 - uVar5;

    iVar13 = iVar13 + (uVar5 - uVar24) + iVar16;

    if (uVar11 < param_2) {

      param_2 = param_2 - uVar11;

      do {

        puVar21 = (uint8_t *)(iVar13 + 1);

        iVar13 = iVar13 + 1;

        puVar20 = puVar20 + 1;

        uVar11 = uVar11 - 1;

        *puVar20 = *puVar21;

      } while (uVar11 != 0);

      iVar13 = iVar25 + -1;

      if (uVar5 < param_2) {

        param_2 = param_2 - uVar5;

        uVar24 = uVar5;

        do {

          puVar21 = (uint8_t *)(iVar13 + 1);

          iVar13 = iVar13 + 1;

          puVar20 = puVar20 + 1;

          uVar24 = uVar24 - 1;

          *puVar20 = *puVar21;

        } while (uVar24 != 0);

        goto LAB_0047fb00;

      }

    }

  }

  else {

    iVar13 = iVar13 + (uVar5 - uVar24);

    if (uVar24 < param_2) {

      param_2 = param_2 - uVar24;

      do {

        puVar21 = (uint8_t *)(iVar13 + 1);

        iVar13 = iVar13 + 1;

        puVar20 = puVar20 + 1;

        uVar24 = uVar24 - 1;

        *puVar20 = *puVar21;

      } while (uVar24 != 0);

      goto LAB_0047fb00;

    }

  }

  if (2 < param_2) {

    iVar18 = (param_2 - 3) / 3 + 1;

    do {

      param_2 = param_2 - 3;

      puVar20[1] = *(uint8_t *)(iVar13 + 1);

      puVar20[2] = *(uint8_t *)(iVar13 + 2);

      puVar21 = (uint8_t *)(iVar13 + 3);

      iVar13 = iVar13 + 3;

      puVar20 = puVar20 + 3;

      iVar18 = iVar18 + -1;

      *puVar20 = *puVar21;

      pbVar14 = local_38;

    } while (iVar18 != 0);

  }

  puVar21 = puVar20;

  if (param_2 != 0) {

    puVar21 = puVar20 + 1;

    *puVar21 = *(uint8_t *)(iVar13 + 1);

    if (1 < param_2) {

      puVar21 = puVar20 + 2;

      *puVar21 = *(uint8_t *)(iVar13 + 2);

    }

  }

LAB_0047fbd7:

  if ((pbVar1 <= pbVar14) || (puVar20 = puVar21, puVar19 + iVar3 + -0x101 <= puVar21))

  goto LAB_0047fc2e;

  goto LAB_0047f868;

}
