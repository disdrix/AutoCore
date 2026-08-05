// =============================================================================
// FUN_0048aec0
// -----------------------------------------------------------------------------
// Stable ID: aa_0048aec0
// Address:   0x0048aec0  (autoassault.exe, image base 0x400000)
// System:    unknown
// Generated: 2026-07-23 from raw capture (scaffold; refine for important units)
// Exactness: Behavior-preserving rewrite of decompiler control flow. Not modernization.
// Bit-for-bit vs retail EXE: DEFERRED (loaded image may differ slightly).
// =============================================================================

// PURPOSE (auto): Scaffold unit for FUN_0048aec0 @ 0x0048aec0
// Stable ID: aa_0048aec0
// No high-value strings recovered; name via xrefs/callers in follow-up.
// Readability: control flow preserved from Ghidra decompile; types tentative.

// READABILITY (auto CF):
//  - Body size: ~38 non-empty decompiler lines.
//  - Control keywords: if×5, do×2, return×2, goto×2, while×2.
//  - Notable callees: FUN_0048aec0.
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

int __thiscall FUN_0048aec0(int param_1,byte *param_2)



{

  byte bVar1;

  int iVar2;

  byte *pbVar3;

  int iVar4;

  byte *pbVar5;

  bool bVar6;

  

  iVar2 = *(int *)(param_1 + 0x18);

  do {

    if (iVar2 == 0) {

      return 0;

    }

    pbVar3 = (byte *)(*(int *)(iVar2 + 0x20) + 8);

    pbVar5 = param_2;

    do {

      bVar1 = *pbVar3;

      bVar6 = bVar1 < *pbVar5;

      if (bVar1 != *pbVar5) {

LAB_0048af00:

        iVar4 = (1 - (uint)bVar6) - (uint)(bVar6 != 0);

        goto LAB_0048af05;

      }

      if (bVar1 == 0) break;

      bVar1 = pbVar3[1];

      bVar6 = bVar1 < pbVar5[1];

      if (bVar1 != pbVar5[1]) goto LAB_0048af00;

      pbVar3 = pbVar3 + 2;

      pbVar5 = pbVar5 + 2;

    } while (bVar1 != 0);

    iVar4 = 0;

LAB_0048af05:

    if (iVar4 == 0) {

      return iVar2;

    }

    iVar2 = *(int *)(iVar2 + 0x28);

  } while( true );

}
