// =============================================================================
// FUN_00474030
// -----------------------------------------------------------------------------
// Stable ID: aa_00474030
// Address:   0x00474030  (autoassault.exe, image base 0x400000)
// System:    unknown
// Generated: 2026-07-23 from raw capture (scaffold; refine for important units)
// Exactness: Behavior-preserving rewrite of decompiler control flow. Not modernization.
// Bit-for-bit vs retail EXE: DEFERRED (loaded image may differ slightly).
// =============================================================================

// PURPOSE (auto): Scaffold unit for FUN_00474030 @ 0x00474030
// Stable ID: aa_00474030
// No high-value strings recovered; name via xrefs/callers in follow-up.
// Readability: control flow preserved from Ghidra decompile; types tentative.

// READABILITY (auto CF):
//  - Body size: ~108 non-empty decompiler lines.
//  - Control keywords: if×11, for×5, return×2.
//  - Notable callees: FUN_00474030.
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

void FUN_00474030(uint *param_1,int param_2,int param_3,int param_4,int param_5)



{

  uint uVar1;

  byte bVar2;

  int iVar3;

  uint8_t *puVar4;

  byte *pbVar5;

  byte *pbVar6;

  uint uVar7;

  

  uVar7 = *param_1;

  if ((char)param_1[2] == '\x03') {

    bVar2 = *(byte *)((int)param_1 + 9);

    if (bVar2 < 8) {

      if (bVar2 == 1) {

        pbVar5 = (byte *)((uVar7 - 1 >> 3) + param_2);

        pbVar6 = (byte *)((uVar7 - 1) + param_2);

        iVar3 = 7 - (uVar7 - 1 & 7);

        for (uVar1 = uVar7; uVar1 != 0; uVar1 = uVar1 - 1) {

          *pbVar6 = *pbVar5 >> ((byte)iVar3 & 0x1f) & 1;

          if (iVar3 == 7) {

            iVar3 = 0;

            pbVar5 = pbVar5 + -1;

          }

          else {

            iVar3 = iVar3 + 1;

          }

          pbVar6 = pbVar6 + -1;

        }

      }

      else if (bVar2 == 2) {

        pbVar5 = (byte *)((uVar7 - 1 >> 2) + param_2);

        pbVar6 = (byte *)((uVar7 - 1) + param_2);

        iVar3 = (3 - (uVar7 - 1 & 3)) * 2;

        for (uVar1 = uVar7; uVar1 != 0; uVar1 = uVar1 - 1) {

          *pbVar6 = *pbVar5 >> ((byte)iVar3 & 0x1f) & 3;

          if (iVar3 == 6) {

            iVar3 = 0;

            pbVar5 = pbVar5 + -1;

          }

          else {

            iVar3 = iVar3 + 2;

          }

          pbVar6 = pbVar6 + -1;

        }

      }

      else if (bVar2 == 4) {

        pbVar5 = (byte *)((uVar7 - 1 >> 1) + param_2);

        pbVar6 = (byte *)((uVar7 - 1) + param_2);

        iVar3 = (uVar7 & 1) * 4;

        for (uVar1 = uVar7; uVar1 != 0; uVar1 = uVar1 - 1) {

          *pbVar6 = *pbVar5 >> ((byte)iVar3 & 0x1f) & 0xf;

          if (iVar3 == 4) {

            iVar3 = 0;

            pbVar5 = pbVar5 + -1;

          }

          else {

            iVar3 = iVar3 + 4;

          }

          pbVar6 = pbVar6 + -1;

        }

      }

      *(uint8_t *)((int)param_1 + 9) = 8;

      *(uint8_t *)((int)param_1 + 0xb) = 8;

      param_1[1] = uVar7;

    }

    if (*(char *)((int)param_1 + 9) == '\b') {

      pbVar6 = (byte *)((uVar7 - 1) + param_2);

      if (param_4 != 0) {

        uVar1 = uVar7 * 4;

        puVar4 = (uint8_t *)((uVar1 - 1) + param_2);

        for (; uVar7 != 0; uVar7 = uVar7 - 1) {

          if ((int)(uint)*pbVar6 < param_5) {

            *puVar4 = *(uint8_t *)((uint)*pbVar6 + param_4);

          }

          else {

            *puVar4 = 0xff;

          }

          puVar4[-1] = *(uint8_t *)((uint)*pbVar6 * 3 + 2 + param_3);

          puVar4[-2] = *(uint8_t *)((uint)*pbVar6 * 3 + 1 + param_3);

          puVar4[-3] = *(uint8_t *)(param_3 + (uint)*pbVar6 * 3);

          puVar4 = puVar4 + -4;

          pbVar6 = pbVar6 + -1;

        }

        param_1[1] = uVar1;

        *(uint8_t *)((int)param_1 + 0xb) = 0x20;

        *(uint8_t *)(param_1 + 2) = 6;

        *(uint8_t *)((int)param_1 + 10) = 4;

        *(uint8_t *)((int)param_1 + 9) = 8;

        return;

      }

      uVar1 = uVar7 * 3;

      puVar4 = (uint8_t *)((uVar1 - 1) + param_2);

      for (; uVar7 != 0; uVar7 = uVar7 - 1) {

        *puVar4 = *(uint8_t *)((uint)*pbVar6 * 3 + 2 + param_3);

        puVar4[-1] = *(uint8_t *)((uint)*pbVar6 * 3 + 1 + param_3);

        puVar4[-2] = *(uint8_t *)(param_3 + (uint)*pbVar6 * 3);

        puVar4 = puVar4 + -3;

        pbVar6 = pbVar6 + -1;

      }

      *(uint8_t *)((int)param_1 + 0xb) = 0x18;

      *(uint8_t *)(param_1 + 2) = 2;

      *(uint8_t *)((int)param_1 + 10) = 3;

      *(uint8_t *)((int)param_1 + 9) = 8;

      param_1[1] = uVar1;

    }

  }

  return;

}
