// =============================================================================
// FUN_00474280
// -----------------------------------------------------------------------------
// Stable ID: aa_00474280
// Address:   0x00474280  (autoassault.exe, image base 0x400000)
// System:    unknown
// Generated: 2026-07-23 from raw capture (scaffold; refine for important units)
// Exactness: Behavior-preserving rewrite of decompiler control flow. Not modernization.
// Bit-for-bit vs retail EXE: DEFERRED (loaded image may differ slightly).
// =============================================================================

// PURPOSE (auto): Scaffold unit for FUN_00474280 @ 0x00474280
// Stable ID: aa_00474280
// No high-value strings recovered; name via xrefs/callers in follow-up.
// Readability: control flow preserved from Ghidra decompile; types tentative.

// READABILITY (auto CF):
//  - Body size: ~192 non-empty decompiler lines.
//  - Control keywords: if×22, for×6, return×5, do×1, while×1, goto×1.
//  - Notable callees: CONCAT11×4, FUN_00474280.
//  - Return sites: 5.

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

void FUN_00474280(int *param_1,int param_2,int param_3)



{

  int iVar1;

  byte bVar2;

  char cVar3;

  uint8_t *puVar4;

  uint8_t *puVar5;

  ushort uVar6;

  int iVar7;

  char *pcVar8;

  byte *pbVar9;

  int iVar10;

  byte *pbVar11;

  

  iVar1 = *param_1;

  if ((char)param_1[2] == '\0') {

    if (param_3 == 0) {

      uVar6 = 0;

    }

    else {

      uVar6 = *(ushort *)(param_3 + 8);

    }

    bVar2 = *(byte *)((int)param_1 + 9);

    if (bVar2 < 8) {

      if (bVar2 == 1) {

        uVar6 = uVar6 * 0xff;

        pbVar9 = (byte *)((iVar1 - 1U >> 3) + param_2);

        iVar7 = 7 - (iVar1 - 1U & 7);

        pcVar8 = (char *)(iVar1 + -1 + param_2);

        for (iVar10 = iVar1; iVar10 != 0; iVar10 = iVar10 + -1) {

          *pcVar8 = -((*pbVar9 >> ((byte)iVar7 & 0x1f) & 1) != 0);

          if (iVar7 == 7) {

            iVar7 = 0;

            pbVar9 = pbVar9 + -1;

          }

          else {

            iVar7 = iVar7 + 1;

          }

          pcVar8 = pcVar8 + -1;

        }

      }

      else if (bVar2 == 2) {

        uVar6 = uVar6 * 0x55;

        pbVar11 = (byte *)((iVar1 - 1U >> 2) + param_2);

        iVar7 = (3 - (iVar1 - 1U & 3)) * 2;

        pbVar9 = (byte *)(iVar1 + -1 + param_2);

        for (iVar10 = iVar1; iVar10 != 0; iVar10 = iVar10 + -1) {

          bVar2 = *pbVar11 >> ((byte)iVar7 & 0x1f) & 3;

          *pbVar9 = ((bVar2 * '\x04' | bVar2) * '\x04' | bVar2) * '\x04' | bVar2;

          if (iVar7 == 6) {

            iVar7 = 0;

            pbVar11 = pbVar11 + -1;

          }

          else {

            iVar7 = iVar7 + 2;

          }

          pbVar9 = pbVar9 + -1;

        }

      }

      else if (bVar2 == 4) {

        uVar6 = uVar6 * 0x11;

        pbVar11 = (byte *)((iVar1 - 1U >> 1) + param_2);

        iVar7 = (iVar1 - 1U & 1) * -4 + 4;

        pbVar9 = (byte *)(iVar1 + -1 + param_2);

        for (iVar10 = iVar1; iVar10 != 0; iVar10 = iVar10 + -1) {

          bVar2 = *pbVar11 >> ((byte)iVar7 & 0x1f) & 0xf;

          *pbVar9 = bVar2 << 4 | bVar2;

          if (iVar7 == 4) {

            iVar7 = 0;

            pbVar11 = pbVar11 + -1;

          }

          else {

            iVar7 = 4;

          }

          pbVar9 = pbVar9 + -1;

        }

      }

      *(uint8_t *)((int)param_1 + 9) = 8;

      *(uint8_t *)((int)param_1 + 0xb) = 8;

      param_1[1] = iVar1;

    }

    if (param_3 == 0) {

      return;

    }

    if (*(char *)((int)param_1 + 9) == '\b') {

      pbVar9 = (byte *)(iVar1 + -1 + param_2);

      puVar4 = (uint8_t *)(param_2 + -1 + iVar1 * 2);

      for (iVar10 = iVar1; iVar10 != 0; iVar10 = iVar10 + -1) {

        if (*pbVar9 == uVar6) {

          *puVar4 = 0;

        }

        else {

          *puVar4 = 0xff;

        }

        puVar4[-1] = *pbVar9;

        puVar4 = puVar4 + -2;

        pbVar9 = pbVar9 + -1;

      }

    }

    else if (*(char *)((int)param_1 + 9) == '\x10') {

      puVar4 = (uint8_t *)(param_1[1] + -1 + param_2);

      puVar5 = (uint8_t *)(param_2 + -1 + param_1[1] * 2);

      for (iVar10 = iVar1; iVar10 != 0; iVar10 = iVar10 + -1) {

        if (CONCAT11(puVar4[-1],*puVar4) == uVar6) {

          *puVar5 = 0;

          puVar5[-1] = 0;

        }

        else {

          *puVar5 = 0xff;

          puVar5[-1] = 0xff;

        }

        puVar5[-2] = *puVar4;

        puVar5[-3] = puVar4[-1];

        puVar5 = puVar5 + -4;

        puVar4 = puVar4 + -2;

      }

    }

    cVar3 = *(char *)((int)param_1 + 9);

    *(uint8_t *)(param_1 + 2) = 4;

    *(uint8_t *)((int)param_1 + 10) = 2;

  }

  else {

    if ((char)param_1[2] != '\x02') {

      return;

    }

    if (param_3 == 0) {

      return;

    }

    if (*(char *)((int)param_1 + 9) == '\b') {

      pbVar9 = (byte *)(param_1[1] + -1 + param_2);

      puVar4 = (uint8_t *)(param_2 + -1 + iVar1 * 4);

      iVar10 = iVar1;

      if (iVar1 != 0) {

        do {

          if ((((ushort)pbVar9[-2] == *(ushort *)(param_3 + 2)) &&

              ((ushort)pbVar9[-1] == *(ushort *)(param_3 + 4))) &&

             ((ushort)*pbVar9 == *(ushort *)(param_3 + 6))) {

            *puVar4 = 0;

          }

          else {

            *puVar4 = 0xff;

          }

          puVar4[-1] = *pbVar9;

          puVar4[-2] = pbVar9[-1];

          puVar4[-3] = pbVar9[-2];

          puVar4 = puVar4 + -4;

          pbVar9 = pbVar9 + -3;

          iVar10 = iVar10 + -1;

        } while (iVar10 != 0);

        *(uint8_t *)(param_1 + 2) = 6;

        *(uint8_t *)((int)param_1 + 10) = 4;

        cVar3 = *(char *)((int)param_1 + 9) * '\x02';

        goto LAB_004744cc;

      }

    }

    else if (*(char *)((int)param_1 + 9) == '\x10') {

      puVar4 = (uint8_t *)(param_1[1] + -1 + param_2);

      puVar5 = (uint8_t *)(param_2 + -1 + iVar1 * 8);

      for (iVar10 = iVar1; iVar10 != 0; iVar10 = iVar10 + -1) {

        if (((CONCAT11(puVar4[-5],puVar4[-4]) == *(short *)(param_3 + 2)) &&

            (CONCAT11(puVar4[-3],puVar4[-2]) == *(short *)(param_3 + 4))) &&

           (CONCAT11(puVar4[-1],*puVar4) == *(short *)(param_3 + 6))) {

          *puVar5 = 0;

          puVar5[-1] = 0;

        }

        else {

          *puVar5 = 0xff;

          puVar5[-1] = 0xff;

        }

        puVar5[-2] = *puVar4;

        puVar5[-3] = puVar4[-1];

        puVar5[-4] = puVar4[-2];

        puVar5[-5] = puVar4[-3];

        puVar5[-6] = puVar4[-4];

        puVar5[-7] = puVar4[-5];

        puVar5 = puVar5 + -8;

        puVar4 = puVar4 + -6;

      }

    }

    *(uint8_t *)(param_1 + 2) = 6;

    *(uint8_t *)((int)param_1 + 10) = 4;

    cVar3 = *(char *)((int)param_1 + 9) * '\x02';

  }

LAB_004744cc:

  bVar2 = cVar3 * '\x02';

  *(byte *)((int)param_1 + 0xb) = bVar2;

  if (bVar2 < 8) {

    param_1[1] = (uint)bVar2 * iVar1 + 7 >> 3;

    return;

  }

  param_1[1] = (uint)(bVar2 >> 3) * iVar1;

  return;

}
