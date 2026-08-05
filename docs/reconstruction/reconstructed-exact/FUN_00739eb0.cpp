// =============================================================================
// FUN_00739eb0
// -----------------------------------------------------------------------------
// Stable ID: aa_00739eb0
// Address:   0x00739eb0  (autoassault.exe, image base 0x400000)
// System:    unknown
// Generated: 2026-07-23 from raw capture (scaffold; refine for important units)
// Exactness: Behavior-preserving rewrite of decompiler control flow. Not modernization.
// Bit-for-bit vs retail EXE: DEFERRED (loaded image may differ slightly).
// =============================================================================

// PURPOSE (auto): Scaffold unit for FUN_00739eb0 @ 0x00739eb0
// Stable ID: aa_00739eb0
// No high-value strings recovered; name via xrefs/callers in follow-up.
// Readability: control flow preserved from Ghidra decompile; types tentative.

// READABILITY (auto CF):
//  - Body size: ~38 non-empty decompiler lines.
//  - Control keywords: if×5, do×2, goto×2, while×2, return×2.
//  - Notable callees: FUN_00739eb0.
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

int FUN_00739eb0(byte *param_1)



{

  byte bVar1;

  byte *pbVar2;

  int iVar3;

  byte *pbVar4;

  int iVar5;

  bool bVar6;

  

  iVar5 = 0;

  do {

    pbVar2 = (&PTR_s_Color_00afa3f0)[iVar5];

    pbVar4 = param_1;

    do {

      bVar1 = *pbVar2;

      bVar6 = bVar1 < *pbVar4;

      if (bVar1 != *pbVar4) {

LAB_00739ef4:

        iVar3 = (1 - (uint)bVar6) - (uint)(bVar6 != 0);

        goto LAB_00739ef9;

      }

      if (bVar1 == 0) break;

      bVar1 = pbVar2[1];

      bVar6 = bVar1 < pbVar4[1];

      if (bVar1 != pbVar4[1]) goto LAB_00739ef4;

      pbVar2 = pbVar2 + 2;

      pbVar4 = pbVar4 + 2;

    } while (bVar1 != 0);

    iVar3 = 0;

LAB_00739ef9:

    if (iVar3 == 0) {

      return iVar5;

    }

    iVar5 = iVar5 + 1;

    if (2 < iVar5) {

      return -1;

    }

  } while( true );

}
