// =============================================================================
// FUN_00471c40
// -----------------------------------------------------------------------------
// Stable ID: aa_00471c40
// Address:   0x00471c40  (autoassault.exe, image base 0x400000)
// System:    unknown
// Generated: 2026-07-23 from raw capture (scaffold; refine for important units)
// Exactness: Behavior-preserving rewrite of decompiler control flow. Not modernization.
// Bit-for-bit vs retail EXE: DEFERRED (loaded image may differ slightly).
// =============================================================================

// PURPOSE (auto): Scaffold unit for FUN_00471c40 @ 0x00471c40
// Stable ID: aa_00471c40
// No high-value strings recovered; name via xrefs/callers in follow-up.
// Readability: control flow preserved from Ghidra decompile; types tentative.

// READABILITY (auto CF):
//  - Body size: ~66 non-empty decompiler lines.
//  - Control keywords: if×7, for×3, return×1.
//  - Notable callees: FUN_00471c40.
//  - Return sites: 1.

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

void FUN_00471c40(int *param_1)



{

  byte bVar1;

  int iVar2;

  int in_EAX;

  int iVar3;

  int iVar4;

  byte *pbVar5;

  byte *pbVar6;

  

  bVar1 = *(byte *)((int)param_1 + 9);

  if (bVar1 < 8) {

    iVar2 = *param_1;

    if (bVar1 == 1) {

      pbVar6 = (byte *)((iVar2 - 1U >> 3) + in_EAX);

      pbVar5 = (byte *)(iVar2 + -1 + in_EAX);

      iVar3 = 7 - (iVar2 - 1U & 7);

      for (iVar4 = iVar2; iVar4 != 0; iVar4 = iVar4 + -1) {

        *pbVar5 = *pbVar6 >> ((byte)iVar3 & 0x1f) & 1;

        if (iVar3 == 7) {

          iVar3 = 0;

          pbVar6 = pbVar6 + -1;

        }

        else {

          iVar3 = iVar3 + 1;

        }

        pbVar5 = pbVar5 + -1;

      }

    }

    else if (bVar1 == 2) {

      pbVar6 = (byte *)((iVar2 - 1U >> 2) + in_EAX);

      pbVar5 = (byte *)(iVar2 + -1 + in_EAX);

      iVar4 = (3 - (iVar2 - 1U & 3)) * 2;

      for (iVar3 = iVar2; iVar3 != 0; iVar3 = iVar3 + -1) {

        *pbVar5 = *pbVar6 >> ((byte)iVar4 & 0x1f) & 3;

        if (iVar4 == 6) {

          iVar4 = 0;

          pbVar6 = pbVar6 + -1;

        }

        else {

          iVar4 = iVar4 + 2;

        }

        pbVar5 = pbVar5 + -1;

      }

    }

    else if (bVar1 == 4) {

      pbVar6 = (byte *)((iVar2 - 1U >> 1) + in_EAX);

      pbVar5 = (byte *)(iVar2 + -1 + in_EAX);

      iVar3 = (1 - (iVar2 - 1U & 1)) * 4;

      for (iVar4 = iVar2; iVar4 != 0; iVar4 = iVar4 + -1) {

        *pbVar5 = *pbVar6 >> ((byte)iVar3 & 0x1f) & 0xf;

        if (iVar3 == 4) {

          iVar3 = 0;

          pbVar6 = pbVar6 + -1;

        }

        else {

          iVar3 = 4;

        }

        pbVar5 = pbVar5 + -1;

      }

    }

    *(uint8_t *)((int)param_1 + 9) = 8;

    *(byte *)((int)param_1 + 0xb) = *(byte *)((int)param_1 + 10) * '\b';

    param_1[1] = (uint)*(byte *)((int)param_1 + 10) * iVar2;

  }

  return;

}
