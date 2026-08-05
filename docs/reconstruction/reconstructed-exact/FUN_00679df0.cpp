// =============================================================================
// FUN_00679df0
// -----------------------------------------------------------------------------
// Stable ID: aa_00679df0
// Address:   0x00679df0  (autoassault.exe, image base 0x400000)
// System:    unknown
// Generated: 2026-07-23 from raw capture (scaffold; refine for important units)
// Exactness: Behavior-preserving rewrite of decompiler control flow. Not modernization.
// Bit-for-bit vs retail EXE: DEFERRED (loaded image may differ slightly).
// =============================================================================

// PURPOSE (auto): Scaffold unit for FUN_00679df0 @ 0x00679df0
// Stable ID: aa_00679df0
// No high-value strings recovered; name via xrefs/callers in follow-up.
// Readability: control flow preserved from Ghidra decompile; types tentative.

// READABILITY (auto CF):
//  - Body size: ~33 non-empty decompiler lines.
//  - Control keywords: if×4, goto×2, return×2, do×1, while×1.
//  - Notable callees: FUN_00679df0.
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

uint32_t /* width from decompiler */ FUN_00679df0(int param_1,uint32_t /* width from decompiler */ param_2,int param_3)



{

  byte bVar1;

  byte *pbVar2;

  int iVar3;

  byte *pbVar4;

  bool bVar5;

  

  pbVar4 = *(byte **)(param_1 + 0x3a4);

  pbVar2 = (byte *)(param_3 + 0x18);

  do {

    bVar1 = *pbVar2;

    bVar5 = bVar1 < *pbVar4;

    if (bVar1 != *pbVar4) {

LAB_00679e28:

      iVar3 = (1 - (uint)bVar5) - (uint)(bVar5 != 0);

      goto LAB_00679e2d;

    }

    if (bVar1 == 0) break;

    bVar1 = pbVar2[1];

    bVar5 = bVar1 < pbVar4[1];

    if (bVar1 != pbVar4[1]) goto LAB_00679e28;

    pbVar2 = pbVar2 + 2;

    pbVar4 = pbVar4 + 2;

  } while (bVar1 != 0);

  iVar3 = 0;

LAB_00679e2d:

  if (iVar3 == 0) {

    *(uint8_t *)(param_1 + 0x3a8) = 1;

    *(uint32_t /* width from decompiler */ *)(param_1 + 0x3ac) = *(uint32_t /* width from decompiler */ *)(param_3 + 8);

    return 0;

  }

  return 1;

}
