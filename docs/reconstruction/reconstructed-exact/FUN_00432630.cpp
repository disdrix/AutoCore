// =============================================================================
// FUN_00432630
// -----------------------------------------------------------------------------
// Stable ID: aa_00432630
// Address:   0x00432630  (autoassault.exe, image base 0x400000)
// System:    unknown
// Generated: 2026-07-23 from raw capture (scaffold; refine for important units)
// Exactness: Behavior-preserving rewrite of decompiler control flow. Not modernization.
// Bit-for-bit vs retail EXE: DEFERRED (loaded image may differ slightly).
// =============================================================================

// PURPOSE (auto): Scaffold unit for FUN_00432630 @ 0x00432630
// Stable ID: aa_00432630
// No high-value strings recovered; name via xrefs/callers in follow-up.
// Readability: control flow preserved from Ghidra decompile; types tentative.

// READABILITY (auto CF):
//  - Body size: ~99 non-empty decompiler lines.
//  - Control keywords: if×9, do×5, while×5, return×2.
//  - Notable callees: FUN_00432630.
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

void FUN_00432630(int param_1,int param_2,ushort param_3,ushort param_4,ushort param_5)



{

  int iVar1;

  byte *pbVar2;

  byte bVar3;

  char in_AL;

  ushort uVar4;

  int iVar5;

  uint8_t *puVar6;

  int iVar7;

  int iVar8;

  int iVar9;

  uint8_t *puVar10;

  char cVar11;

  int iVar12;

  char cVar13;

  int iVar14;

  int iVar15;

  char cVar16;

  byte *pbVar17;

  

  if (in_AL == '\x10') {

    cVar11 = '\0';

    cVar16 = '\0';

    cVar13 = '\0';

    iVar7 = 0;

    do {

      bVar3 = (byte)iVar7;

      if ((param_3 >> (bVar3 & 0x1f) & 1) != 0) {

        cVar11 = cVar11 + '\x01';

      }

      if ((param_4 >> (bVar3 & 0x1f) & 1) != 0) {

        cVar16 = cVar16 + '\x01';

      }

      if ((param_5 >> (bVar3 & 0x1f) & 1) != 0) {

        cVar13 = cVar13 + '\x01';

      }

      iVar7 = iVar7 + 1;

    } while (iVar7 < 0x10);

    iVar7 = *(int *)(param_1 + 0x34);

    iVar8 = (*(int *)(param_1 + 0xc) + 1) / 2;

    iVar5 = *(int *)(param_1 + 0x10) + -1;

    if (-1 < iVar5) {

      iVar9 = iVar5 * iVar8 * 4;

      do {

        iVar15 = *(int *)(param_1 + 0xc);

        iVar12 = iVar15 + -1;

        if (-1 < iVar12) {

          iVar1 = iVar7 + 1;

          pbVar17 = (byte *)(iVar9 + iVar12 * 2 + param_2);

          puVar6 = (uint8_t *)(iVar1 + iVar12 * 3 + *(int *)(param_1 + 0x30) * iVar5);

          do {

            bVar3 = *pbVar17;

            pbVar2 = pbVar17 + 1;

            pbVar17 = pbVar17 + -2;

            uVar4 = (ushort)*pbVar2 * 0x100 + (ushort)bVar3;

            puVar6[iVar7 - iVar1] = ((byte)param_5 & (byte)uVar4) << (8U - cVar11 & 0x1f);

            iVar15 = iVar15 + -1;

            *puVar6 = (char)((uVar4 & param_4) >> ((cVar16 + cVar11) - 8U & 0x1f));

            (puVar6 + -3)[(iVar7 - iVar1) + 5] =

                 (char)((uVar4 & param_3) >> ((cVar13 + cVar16 + cVar11) - 8U & 0x1f));

            puVar6 = puVar6 + -3;

          } while (iVar15 != 0);

        }

        iVar9 = iVar9 + iVar8 * -4;

        iVar5 = iVar5 + -1;

      } while (-1 < iVar5);

    }

  }

  else if (in_AL == ' ') {

    iVar7 = *(int *)(param_1 + 0xc);

    iVar8 = *(int *)(param_1 + 0x34);

    iVar5 = *(int *)(param_1 + 0x10) + -1;

    if (-1 < iVar5) {

      iVar9 = iVar5 * iVar7 * 4;

      do {

        iVar15 = *(int *)(param_1 + 0xc);

        iVar12 = iVar15 + -1;

        if (-1 < iVar12) {

          iVar1 = iVar8 + 1;

          iVar14 = param_2 + 1;

          puVar6 = (uint8_t *)(iVar1 + iVar12 * 3 + *(int *)(param_1 + 0x30) * iVar5);

          puVar10 = (uint8_t *)(iVar9 + iVar12 * 4 + iVar14);

          do {

            puVar6[iVar8 - iVar1] = puVar10[param_2 - iVar14];

            *puVar6 = *puVar10;

            puVar6[(iVar8 - iVar1) + 2] = puVar10[(param_2 - iVar14) + 2];

            puVar10 = puVar10 + -4;

            puVar6 = puVar6 + -3;

            iVar15 = iVar15 + -1;

          } while (iVar15 != 0);

        }

        iVar9 = iVar9 + iVar7 * -4;

        iVar5 = iVar5 + -1;

      } while (-1 < iVar5);

      return;

    }

  }

  return;

}
