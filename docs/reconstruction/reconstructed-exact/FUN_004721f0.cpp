// =============================================================================
// FUN_004721f0
// -----------------------------------------------------------------------------
// Stable ID: aa_004721f0
// Address:   0x004721f0  (autoassault.exe, image base 0x400000)
// System:    unknown
// Generated: 2026-07-23 from raw capture (scaffold; refine for important units)
// Exactness: Behavior-preserving rewrite of decompiler control flow. Not modernization.
// Bit-for-bit vs retail EXE: DEFERRED (loaded image may differ slightly).
// =============================================================================

// PURPOSE (auto): Scaffold unit for FUN_004721f0 @ 0x004721f0
// Stable ID: aa_004721f0
// No high-value strings recovered; name via xrefs/callers in follow-up.
// Readability: control flow preserved from Ghidra decompile; types tentative.

// READABILITY (auto CF):
//  - Body size: ~178 non-empty decompiler lines.
//  - Control keywords: if×14, return×6, for×4, do×4, while×4.
//  - Notable callees: FUN_004721f0.
//  - Return sites: 6.

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

void __fastcall FUN_004721f0(uint32_t /* width from decompiler */ param_1,uint param_2,uint *param_3,char param_4)



{

  uint8_t *puVar1;

  uint uVar2;

  uint uVar3;

  uint *puVar4;

  int in_EAX;

  uint8_t *puVar5;

  int iVar6;

  uint8_t uVar7;

  byte bVar8;

  uint uVar9;

  int iVar10;

  

  puVar4 = param_3;

  uVar2 = *param_3;

  uVar9 = param_2 >> 8;

  bVar8 = (byte)(param_2 >> 8);

  uVar7 = (uint8_t)param_2;

  if ((char)param_3[2] == '\0') {

    if (*(char *)((int)param_3 + 9) == '\b') {

      iVar10 = in_EAX + uVar2;

      puVar5 = (uint8_t *)(iVar10 + uVar2);

      uVar9 = uVar2;

      if (-1 < param_4) {

        for (; uVar9 != 0; uVar9 = uVar9 - 1) {

          puVar1 = (uint8_t *)(iVar10 + -1);

          iVar10 = iVar10 + -1;

          puVar5[-1] = *puVar1;

          puVar5 = puVar5 + -2;

          *puVar5 = uVar7;

        }

        *(uint8_t *)((int)param_3 + 10) = 2;

        *(uint8_t *)((int)param_3 + 0xb) = 0x10;

        param_3[1] = uVar2 * 2;

        return;

      }

      if (1 < uVar2) {

        iVar6 = uVar2 - 1;

        do {

          puVar5[-1] = uVar7;

          puVar1 = (uint8_t *)(iVar10 + -1);

          iVar10 = iVar10 + -1;

          puVar5 = puVar5 + -2;

          iVar6 = iVar6 + -1;

          *puVar5 = *puVar1;

        } while (iVar6 != 0);

      }

      puVar5[-1] = uVar7;

      *(uint8_t *)((int)param_3 + 10) = 2;

      *(uint8_t *)((int)param_3 + 0xb) = 0x10;

      param_3[1] = uVar2 * 2;

      return;

    }

    if (*(char *)((int)param_3 + 9) == '\x10') {

      iVar10 = in_EAX + uVar2 * 2;

      puVar5 = (uint8_t *)(iVar10 + uVar2 * 2);

      uVar9 = uVar2;

      if (param_4 < '\0') {

        if (1 < uVar2) {

          param_3 = (uint *)(uVar2 - 1);

          do {

            puVar5[-1] = bVar8;

            puVar5[-2] = uVar7;

            puVar5[-3] = *(uint8_t *)(iVar10 + -1);

            puVar1 = (uint8_t *)(iVar10 + -2);

            iVar10 = iVar10 + -2;

            puVar5 = puVar5 + -4;

            param_3 = (uint *)((int)param_3 + -1);

            *puVar5 = *puVar1;

          } while (param_3 != (uint *)0x0);

        }

        puVar5[-1] = bVar8;

        puVar5[-2] = uVar7;

      }

      else {

        for (; uVar9 != 0; uVar9 = uVar9 - 1) {

          puVar5[-1] = *(uint8_t *)(iVar10 + -1);

          puVar1 = (uint8_t *)(iVar10 + -2);

          iVar10 = iVar10 + -2;

          puVar5[-2] = *puVar1;

          puVar5[-3] = bVar8;

          puVar5 = puVar5 + -4;

          *puVar5 = uVar7;

        }

      }

      *(uint8_t *)((int)puVar4 + 10) = 2;

      *(uint8_t *)((int)puVar4 + 0xb) = 0x20;

      puVar4[1] = uVar2 * 4;

      return;

    }

  }

  else if ((char)param_3[2] == '\x02') {

    if (*(char *)((int)param_3 + 9) == '\b') {

      iVar10 = in_EAX + uVar2 * 3;

      puVar5 = (uint8_t *)(iVar10 + uVar2);

      uVar9 = uVar2;

      if (-1 < param_4) {

        for (; uVar9 != 0; uVar9 = uVar9 - 1) {

          puVar5[-1] = *(uint8_t *)(iVar10 + -1);

          puVar5[-2] = *(uint8_t *)(iVar10 + -2);

          puVar1 = (uint8_t *)(iVar10 + -3);

          iVar10 = iVar10 + -3;

          puVar5[-3] = *puVar1;

          puVar5 = puVar5 + -4;

          *puVar5 = uVar7;

        }

        *(uint8_t *)((int)param_3 + 0xb) = 0x20;

        *(uint8_t *)((int)param_3 + 10) = 4;

        param_3[1] = uVar2 * 4;

        return;

      }

      if (1 < uVar2) {

        iVar6 = uVar2 - 1;

        do {

          puVar5[-1] = uVar7;

          puVar5[-2] = *(uint8_t *)(iVar10 + -1);

          puVar5[-3] = *(uint8_t *)(iVar10 + -2);

          puVar1 = (uint8_t *)(iVar10 + -3);

          iVar10 = iVar10 + -3;

          puVar5 = puVar5 + -4;

          iVar6 = iVar6 + -1;

          *puVar5 = *puVar1;

        } while (iVar6 != 0);

      }

      puVar5[-1] = uVar7;

      *(uint8_t *)((int)param_3 + 10) = 4;

      *(uint8_t *)((int)param_3 + 0xb) = 0x20;

      param_3[1] = uVar2 * 4;

      return;

    }

    if (*(char *)((int)param_3 + 9) == '\x10') {

      iVar10 = in_EAX + uVar2 * 6;

      puVar5 = (uint8_t *)(iVar10 + uVar2 * 2);

      uVar3 = uVar2;

      if (param_4 < '\0') {

        if (1 < uVar2) {

          iVar6 = uVar2 - 1;

          do {

            puVar5[-1] = (char)uVar9;

            puVar5[-2] = uVar7;

            puVar5[-3] = *(uint8_t *)(iVar10 + -1);

            puVar5[-4] = *(uint8_t *)(iVar10 + -2);

            puVar5[-5] = *(uint8_t *)(iVar10 + -3);

            puVar5[-6] = *(uint8_t *)(iVar10 + -4);

            puVar5[-7] = *(uint8_t *)(iVar10 + -5);

            puVar1 = (uint8_t *)(iVar10 + -6);

            iVar10 = iVar10 + -6;

            puVar5 = puVar5 + -8;

            iVar6 = iVar6 + -1;

            *puVar5 = *puVar1;

            uVar9 = (uint)bVar8;

          } while (iVar6 != 0);

        }

        puVar5[-1] = bVar8;

        puVar5[-2] = uVar7;

      }

      else {

        for (; uVar3 != 0; uVar3 = uVar3 - 1) {

          puVar5[-1] = *(uint8_t *)(iVar10 + -1);

          puVar5[-2] = *(uint8_t *)(iVar10 + -2);

          puVar5[-3] = *(uint8_t *)(iVar10 + -3);

          puVar5[-4] = *(uint8_t *)(iVar10 + -4);

          puVar5[-5] = *(uint8_t *)(iVar10 + -5);

          puVar1 = (uint8_t *)(iVar10 + -6);

          iVar10 = iVar10 + -6;

          puVar5[-6] = *puVar1;

          puVar5[-7] = bVar8;

          puVar5 = puVar5 + -8;

          *puVar5 = uVar7;

        }

      }

      *(uint8_t *)((int)param_3 + 0xb) = 0x40;

      *(uint8_t *)((int)param_3 + 10) = 4;

      param_3[1] = uVar2 * 8;

    }

  }

  return;

}
