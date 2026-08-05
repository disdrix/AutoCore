// =============================================================================
// FUN_00679d70
// -----------------------------------------------------------------------------
// Stable ID: aa_00679d70
// Address:   0x00679d70  (autoassault.exe, image base 0x400000)
// System:    unknown
// Generated: 2026-07-23 from raw capture (scaffold; refine for important units)
// Exactness: Behavior-preserving rewrite of decompiler control flow. Not modernization.
// Bit-for-bit vs retail EXE: DEFERRED (loaded image may differ slightly).
// =============================================================================

// PURPOSE (auto): Scaffold unit for FUN_00679d70 @ 0x00679d70
// Stable ID: aa_00679d70
// No high-value strings recovered; name via xrefs/callers in follow-up.
// Readability: control flow preserved from Ghidra decompile; types tentative.

// READABILITY (auto CF):
//  - Body size: ~39 non-empty decompiler lines.
//  - Control keywords: if×5, goto×2, return×2, do×1, while×1.
//  - Notable callees: FUN_00679d70, acmDriverDetailsA.
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

uint32_t /* width from decompiler */ FUN_00679d70(uint32_t /* width from decompiler */ *param_1,uint32_t /* width from decompiler */ param_2)



{

  byte bVar1;

  int iVar2;

  byte *pbVar3;

  byte *pbVar4;

  bool bVar5;

  

  param_1[3] = 0x398;

  param_1[4] = 0x63647561;

  param_1[9] = 1;

  iVar2 = acmDriverDetailsA(param_2,param_1 + 3,0);

  if (iVar2 == 0) {

    pbVar3 = (byte *)*param_1;

    pbVar4 = (byte *)(param_1 + 0xd);

    do {

      bVar1 = *pbVar3;

      bVar5 = bVar1 < *pbVar4;

      if (bVar1 != *pbVar4) {

LAB_00679dc8:

        iVar2 = (1 - (uint)bVar5) - (uint)(bVar5 != 0);

        goto LAB_00679dcd;

      }

      if (bVar1 == 0) break;

      bVar1 = pbVar3[1];

      bVar5 = bVar1 < pbVar4[1];

      if (bVar1 != pbVar4[1]) goto LAB_00679dc8;

      pbVar3 = pbVar3 + 2;

      pbVar4 = pbVar4 + 2;

    } while (bVar1 != 0);

    iVar2 = 0;

LAB_00679dcd:

    if (iVar2 == 0) {

      param_1[2] = param_2;

      *(uint8_t *)(param_1 + 1) = 1;

      return 0;

    }

  }

  return 1;

}
