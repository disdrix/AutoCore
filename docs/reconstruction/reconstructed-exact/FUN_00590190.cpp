// =============================================================================
// FUN_00590190
// -----------------------------------------------------------------------------
// Stable ID: aa_00590190
// Address:   0x00590190  (autoassault.exe, image base 0x400000)
// System:    unknown
// Generated: 2026-07-23 from raw capture (scaffold; refine for important units)
// Exactness: Behavior-preserving rewrite of decompiler control flow. Not modernization.
// Bit-for-bit vs retail EXE: DEFERRED (loaded image may differ slightly).
// =============================================================================

// PURPOSE (auto): Scaffold unit for FUN_00590190 @ 0x00590190
// Stable ID: aa_00590190
// No high-value strings recovered; name via xrefs/callers in follow-up.
// Readability: control flow preserved from Ghidra decompile; types tentative.

// READABILITY (auto CF):
//  - Body size: ~49 non-empty decompiler lines.
//  - Control keywords: if×7, return×3, goto×3, do×2, while×2.
//  - Notable callees: FUN_00590190, FUN_00596770.
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

uint32_t /* width from decompiler */ FUN_00590190(byte *param_1)



{

  byte bVar1;

  byte *pbVar2;

  int iVar3;

  uint uVar4;

  byte *pbVar5;

  bool bVar6;

  

  uVar4 = 0;

  do {

    if (DAT_00b04e34 == 0) {

LAB_0059021e:

      FUN_00596770(DAT_00b04e38,1,&param_1);

      return 1;

    }

    if ((uint)((int)DAT_00b04e38 - DAT_00b04e34 >> 2) <= uVar4) {

      if ((uint)((int)DAT_00b04e38 - DAT_00b04e34 >> 2) < (uint)(DAT_00b04e3c - DAT_00b04e34 >> 2))

      {

        *DAT_00b04e38 = param_1;

        DAT_00b04e38 = DAT_00b04e38 + 1;

        return 1;

      }

      goto LAB_0059021e;

    }

    pbVar5 = *(byte **)(DAT_00b04e34 + uVar4 * 4);

    pbVar2 = param_1;

    do {

      bVar1 = *pbVar2;

      bVar6 = bVar1 < *pbVar5;

      if (bVar1 != *pbVar5) {

LAB_005901dc:

        iVar3 = (1 - (uint)bVar6) - (uint)(bVar6 != 0);

        goto LAB_005901e1;

      }

      if (bVar1 == 0) break;

      bVar1 = pbVar2[1];

      bVar6 = bVar1 < pbVar5[1];

      if (bVar1 != pbVar5[1]) goto LAB_005901dc;

      pbVar2 = pbVar2 + 2;

      pbVar5 = pbVar5 + 2;

    } while (bVar1 != 0);

    iVar3 = 0;

LAB_005901e1:

    if (iVar3 == 0) {

      return 0;

    }

    uVar4 = uVar4 + 1;

  } while( true );

}
