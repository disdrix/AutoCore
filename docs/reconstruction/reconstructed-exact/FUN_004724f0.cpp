// =============================================================================
// FUN_004724f0
// -----------------------------------------------------------------------------
// Stable ID: aa_004724f0
// Address:   0x004724f0  (autoassault.exe, image base 0x400000)
// System:    unknown
// Generated: 2026-07-23 from raw capture (scaffold; refine for important units)
// Exactness: Behavior-preserving rewrite of decompiler control flow. Not modernization.
// Bit-for-bit vs retail EXE: DEFERRED (loaded image may differ slightly).
// =============================================================================

// PURPOSE (auto): Scaffold unit for FUN_004724f0 @ 0x004724f0
// Stable ID: aa_004724f0
// No high-value strings recovered; name via xrefs/callers in follow-up.
// Readability: control flow preserved from Ghidra decompile; types tentative.

// READABILITY (auto CF):
//  - Body size: ~82 non-empty decompiler lines.
//  - Control keywords: if×6, for×4, return×2.
//  - Notable callees: FUN_004724f0.
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

void FUN_004724f0(void)



{

  byte bVar1;

  int iVar2;

  byte bVar3;

  int in_EAX;

  uint8_t *puVar4;

  uint8_t *puVar5;

  int iVar6;

  int *unaff_EDI;

  

  bVar3 = *(byte *)((int)unaff_EDI + 9);

  iVar2 = *unaff_EDI;

  if ((7 < bVar3) && (bVar1 = *(byte *)(unaff_EDI + 2), (bVar1 & 2) == 0)) {

    if (bVar1 == 0) {

      if (bVar3 == 8) {

        puVar5 = (uint8_t *)(iVar2 + -1 + in_EAX);

        puVar4 = puVar5 + iVar2 * 2;

        for (iVar6 = iVar2; iVar6 != 0; iVar6 = iVar6 + -1) {

          *puVar4 = *puVar5;

          puVar4[-1] = *puVar5;

          puVar4[-2] = *puVar5;

          puVar4 = puVar4 + -3;

          puVar5 = puVar5 + -1;

        }

      }

      else {

        puVar5 = (uint8_t *)(in_EAX + -1 + iVar2 * 2);

        puVar4 = puVar5 + iVar2 * 4;

        for (iVar6 = iVar2; iVar6 != 0; iVar6 = iVar6 + -1) {

          *puVar4 = *puVar5;

          puVar4[-1] = puVar5[-1];

          puVar4[-2] = *puVar5;

          puVar4[-3] = puVar5[-1];

          puVar4[-4] = *puVar5;

          puVar4[-5] = puVar5[-1];

          puVar4 = puVar4 + -6;

          puVar5 = puVar5 + -2;

        }

      }

    }

    else if (bVar1 == 4) {

      if (bVar3 == 8) {

        puVar5 = (uint8_t *)(in_EAX + -1 + iVar2 * 2);

        puVar4 = puVar5 + iVar2 * 2;

        for (iVar6 = iVar2; iVar6 != 0; iVar6 = iVar6 + -1) {

          *puVar4 = *puVar5;

          puVar4[-1] = puVar5[-1];

          puVar4[-2] = puVar5[-1];

          puVar4[-3] = puVar5[-1];

          puVar4 = puVar4 + -4;

          puVar5 = puVar5 + -2;

        }

      }

      else {

        puVar5 = (uint8_t *)(in_EAX + -1 + iVar2 * 4);

        puVar4 = puVar5 + iVar2 * 4;

        for (iVar6 = iVar2; iVar6 != 0; iVar6 = iVar6 + -1) {

          *puVar4 = *puVar5;

          puVar4[-1] = puVar5[-1];

          puVar4[-2] = puVar5[-2];

          puVar4[-3] = puVar5[-3];

          puVar4[-4] = puVar5[-2];

          puVar4[-5] = puVar5[-3];

          puVar4[-6] = puVar5[-2];

          puVar4[-7] = puVar5[-3];

          puVar4 = puVar4 + -8;

          puVar5 = puVar5 + -4;

        }

      }

    }

    *(char *)((int)unaff_EDI + 10) = *(char *)((int)unaff_EDI + 10) + '\x02';

    *(byte *)(unaff_EDI + 2) = *(byte *)(unaff_EDI + 2) | 2;

    bVar3 = *(char *)((int)unaff_EDI + 9) * *(char *)((int)unaff_EDI + 10);

    *(byte *)((int)unaff_EDI + 0xb) = bVar3;

    if (7 < bVar3) {

      unaff_EDI[1] = (uint)(bVar3 >> 3) * iVar2;

      return;

    }

    unaff_EDI[1] = (uint)bVar3 * iVar2 + 7 >> 3;

  }

  return;

}
