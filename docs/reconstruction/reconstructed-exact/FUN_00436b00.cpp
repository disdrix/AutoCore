// =============================================================================
// FUN_00436b00
// -----------------------------------------------------------------------------
// Stable ID: aa_00436b00
// Address:   0x00436b00  (autoassault.exe, image base 0x400000)
// System:    unknown
// Generated: 2026-07-23 from raw capture (scaffold; refine for important units)
// Exactness: Behavior-preserving rewrite of decompiler control flow. Not modernization.
// Bit-for-bit vs retail EXE: DEFERRED (loaded image may differ slightly).
// =============================================================================

// PURPOSE (auto): Scaffold unit for FUN_00436b00 @ 0x00436b00
// Stable ID: aa_00436b00
// No high-value strings recovered; name via xrefs/callers in follow-up.
// Readability: control flow preserved from Ghidra decompile; types tentative.

// READABILITY (auto CF):
//  - Body size: ~177 non-empty decompiler lines.
//  - Control keywords: if×20, while×7, goto×6, do×4, for×2, return×2.
//  - Notable callees: FUN_00436b00, FUN_0043fe60, FUN_0044a380, FUN_006759b0, FUN_007662b0, block.
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

/* WARNING: Removing unreachable block (ram,0x00436be5) */



void FUN_00436b00(int *param_1,uint32_t /* width from decompiler */ *param_2)



{

  int *piVar1;

  uint32_t /* width from decompiler */ *puVar2;

  byte bVar3;

  uint32_t /* width from decompiler */ uVar4;

  int iVar5;

  uint uVar6;

  byte *pbVar7;

  int iVar8;

  byte *pbVar9;

  uint uVar10;

  byte *pbVar11;

  int unaff_ESI;

  uint32_t /* width from decompiler */ *puVar12;

  uint32_t /* width from decompiler */ *puVar13;

  bool bVar14;

  int local_c;

  

  uVar10 = *(uint *)(unaff_ESI + 0x24);

  if (uVar10 <= *(uint *)(unaff_ESI + 0xc) >> 2) {

    if (*(int *)(unaff_ESI + 0x14) == 0) {

      iVar5 = 0;

    }

    else {

      iVar5 = *(int *)(unaff_ESI + 0x18) - *(int *)(unaff_ESI + 0x14) >> 2;

    }

    if (uVar10 < iVar5 - 1U) {

      if (*(uint *)(unaff_ESI + 0x20) < uVar10) {

        *(uint *)(unaff_ESI + 0x20) = *(uint *)(unaff_ESI + 0x20) * 2 + 1;

      }

    }

    else {

      if (*(int *)(unaff_ESI + 0x14) == 0) {

        iVar5 = 0;

      }

      else {

        iVar5 = *(int *)(unaff_ESI + 0x18) - *(int *)(unaff_ESI + 0x14) >> 2;

      }

      *(int *)(unaff_ESI + 0x20) = iVar5 * 2 + -3;

      FUN_0044a380(*(uint32_t /* width from decompiler */ *)(unaff_ESI + 8));

    }

    uVar10 = (*(int *)(unaff_ESI + 0x24) - (*(uint *)(unaff_ESI + 0x20) >> 1)) - 1;

    puVar13 = *(uint32_t /* width from decompiler */ **)(uVar10 * 4 + *(int *)(unaff_ESI + 0x14));

    if (puVar13 != *(uint32_t /* width from decompiler */ **)(uVar10 * 4 + *(int *)(unaff_ESI + 0x14) + 4)) {

      do {

        local_c = uVar10 * 4;

        uVar6 = FUN_007662b0();

        if ((uVar6 & *(uint *)(unaff_ESI + 0x20)) == uVar10) {

          puVar12 = (uint32_t /* width from decompiler */ *)*puVar13;

        }

        else {

          puVar12 = (uint32_t /* width from decompiler */ *)*puVar13;

          if (puVar12 != *(uint32_t /* width from decompiler */ **)(unaff_ESI + 8)) {

            puVar2 = *(uint32_t /* width from decompiler */ **)(*(int *)(unaff_ESI + 0x14) + local_c);

            uVar6 = uVar10;

            while ((puVar13 == puVar2 &&

                   (*(uint32_t /* width from decompiler */ **)(*(int *)(unaff_ESI + 0x14) + uVar6 * 4) = puVar12, uVar6 != 0))

                  ) {

              uVar6 = uVar6 - 1;

              puVar2 = *(uint32_t /* width from decompiler */ **)(*(int *)(unaff_ESI + 0x14) + uVar6 * 4);

            }

            iVar5 = *(int *)(unaff_ESI + 8);

            *(uint32_t /* width from decompiler */ **)puVar13[1] = puVar12;

            *(int *)puVar12[1] = iVar5;

            **(uint32_t /* width from decompiler */ **)(iVar5 + 4) = puVar13;

            uVar4 = *(uint32_t /* width from decompiler */ *)(iVar5 + 4);

            *(uint32_t /* width from decompiler */ *)(iVar5 + 4) = puVar12[1];

            puVar12[1] = puVar13[1];

            puVar13[1] = uVar4;

            puVar13 = *(uint32_t /* width from decompiler */ **)(*(int *)(unaff_ESI + 8) + 4);

            *(int *)(*(int *)(unaff_ESI + 0x14) + 4 + *(int *)(unaff_ESI + 0x24) * 4) =

                 *(int *)(unaff_ESI + 8);

          }

          for (uVar6 = *(uint *)(unaff_ESI + 0x24);

              (uVar10 < uVar6 &&

              (piVar1 = (int *)(*(int *)(unaff_ESI + 0x14) + uVar6 * 4),

              *piVar1 == *(int *)(unaff_ESI + 8))); uVar6 = uVar6 - 1) {

            *piVar1 = (int)puVar13;

          }

          if (puVar12 == *(uint32_t /* width from decompiler */ **)(unaff_ESI + 8)) break;

        }

        puVar13 = puVar12;

      } while (puVar12 != *(uint32_t /* width from decompiler */ **)(uVar10 * 4 + 4 + *(int *)(unaff_ESI + 0x14)));

    }

    *(int *)(unaff_ESI + 0x24) = *(int *)(unaff_ESI + 0x24) + 1;

  }

  pbVar11 = (byte *)*param_2;

  pbVar7 = pbVar11;

  do {

    bVar3 = *pbVar7;

    pbVar7 = pbVar7 + 1;

  } while (bVar3 != 0);

  uVar10 = 0x1505;

  iVar5 = (int)pbVar7 - (int)(pbVar11 + 1);

  pbVar7 = pbVar11;

  for (; iVar5 != 0; iVar5 = iVar5 + -1) {

    uVar10 = (int)(char)*pbVar7 + uVar10 * 0x21;

    pbVar7 = pbVar7 + 1;

  }

  uVar10 = *(uint *)(unaff_ESI + 0x20) & uVar10;

  if (*(uint *)(unaff_ESI + 0x24) <= uVar10) {

    uVar10 = uVar10 + (-1 - (*(uint *)(unaff_ESI + 0x20) >> 1));

  }

  iVar5 = uVar10 * 4;

  puVar13 = *(uint32_t /* width from decompiler */ **)(*(int *)(unaff_ESI + 0x14) + 4 + iVar5);

  if (puVar13 != *(uint32_t /* width from decompiler */ **)(*(int *)(unaff_ESI + 0x14) + iVar5)) {

    do {

      puVar13 = (uint32_t /* width from decompiler */ *)puVar13[1];

      pbVar7 = (byte *)puVar13[2];

      pbVar9 = pbVar11;

      do {

        bVar3 = *pbVar9;

        bVar14 = bVar3 < *pbVar7;

        if (bVar3 != *pbVar7) {

LAB_00436d85:

          iVar8 = (1 - (uint)bVar14) - (uint)(bVar14 != 0);

          goto LAB_00436d8a;

        }

        if (bVar3 == 0) break;

        bVar3 = pbVar9[1];

        bVar14 = bVar3 < pbVar7[1];

        if (bVar3 != pbVar7[1]) goto LAB_00436d85;

        pbVar9 = pbVar9 + 2;

        pbVar7 = pbVar7 + 2;

      } while (bVar3 != 0);

      iVar8 = 0;

LAB_00436d8a:

      if (-1 < iVar8) {

        pbVar7 = (byte *)puVar13[2];

        goto LAB_00436da3;

      }

    } while (puVar13 != *(uint32_t /* width from decompiler */ **)(*(int *)(unaff_ESI + 0x14) + iVar5));

  }

  goto LAB_00436cd9;

  while( true ) {

    bVar3 = pbVar7[1];

    bVar14 = bVar3 < pbVar11[1];

    if (bVar3 != pbVar11[1]) goto LAB_00436dc8;

    pbVar7 = pbVar7 + 2;

    pbVar11 = pbVar11 + 2;

    if (bVar3 == 0) break;

LAB_00436da3:

    bVar3 = *pbVar7;

    bVar14 = bVar3 < *pbVar11;

    if (bVar3 != *pbVar11) {

LAB_00436dc8:

      iVar8 = (1 - (uint)bVar14) - (uint)(bVar14 != 0);

      goto LAB_00436dcd;

    }

    if (bVar3 == 0) break;

  }

  iVar8 = 0;

LAB_00436dcd:

  if (-1 < iVar8) {

    *param_1 = (int)puVar13;

    *(uint8_t *)(param_1 + 1) = 0;

    return;

  }

  puVar13 = (uint32_t /* width from decompiler */ *)*puVar13;

LAB_00436cd9:

  iVar8 = FUN_006759b0(puVar13,puVar13[1],param_2);

  FUN_0043fe60();

  puVar13[1] = iVar8;

  **(int **)(iVar8 + 4) = iVar8;

  iVar8 = puVar13[1];

  puVar12 = *(uint32_t /* width from decompiler */ **)(*(int *)(unaff_ESI + 0x14) + iVar5);

  while ((puVar13 == puVar12 && (*(int *)(*(int *)(unaff_ESI + 0x14) + iVar5) = iVar8, uVar10 != 0))

        ) {

    uVar10 = uVar10 - 1;

    iVar5 = uVar10 * 4;

    puVar12 = *(uint32_t /* width from decompiler */ **)(*(int *)(unaff_ESI + 0x14) + iVar5);

  }

  *param_1 = iVar8;

  *(uint8_t *)(param_1 + 1) = 1;

  return;

}
