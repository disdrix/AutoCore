// =============================================================================
// FUN_004f59c0
// -----------------------------------------------------------------------------
// Stable ID: aa_004f59c0
// Address:   0x004f59c0  (autoassault.exe, image base 0x400000)
// System:    unknown
// Generated: 2026-07-23 from raw capture (scaffold; refine for important units)
// Exactness: Behavior-preserving rewrite of decompiler control flow. Not modernization.
// Bit-for-bit vs retail EXE: DEFERRED (loaded image may differ slightly).
// =============================================================================

// PURPOSE (auto): Scaffold unit for FUN_004f59c0 @ 0x004f59c0
// Stable ID: aa_004f59c0
// No high-value strings recovered; name via xrefs/callers in follow-up.
// Readability: control flow preserved from Ghidra decompile; types tentative.

// READABILITY (auto CF):
//  - Body size: ~32 non-empty decompiler lines.
//  - Control keywords: if×5, goto×2, return×2, do×1, while×1.
//  - Notable callees: FUN_004f59c0.
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

longlong __thiscall FUN_004f59c0(int param_1,byte *param_2)



{

  byte bVar1;

  int iVar2;

  byte *pbVar3;

  bool bVar4;

  

  if ((param_2 != (byte *)0x0) && (pbVar3 = (byte *)(param_1 + 0x1b0), pbVar3 != (byte *)0x0)) {

    do {

      bVar1 = *param_2;

      bVar4 = bVar1 < *pbVar3;

      if (bVar1 != *pbVar3) {

LAB_004f59fa:

        iVar2 = (1 - (uint)bVar4) - (uint)(bVar4 != 0);

        goto LAB_004f59ff;

      }

      if (bVar1 == 0) break;

      bVar1 = param_2[1];

      bVar4 = bVar1 < pbVar3[1];

      if (bVar1 != pbVar3[1]) goto LAB_004f59fa;

      param_2 = param_2 + 2;

      pbVar3 = pbVar3 + 2;

    } while (bVar1 != 0);

    iVar2 = 0;

LAB_004f59ff:

    if (iVar2 != 0) {

      iVar2 = (int)*(short *)(*(int *)(*(int *)(*(int *)(*(int *)(param_1 + 4) + 4) + 0xac + param_1

                                               ) + 0x3c) + 0x3f0);

      return (longlong)((iVar2 * iVar2) / 2);

    }

  }

  return 0;

}
