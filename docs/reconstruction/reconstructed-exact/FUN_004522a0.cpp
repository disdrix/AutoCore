// =============================================================================
// FUN_004522a0
// -----------------------------------------------------------------------------
// Stable ID: aa_004522a0
// Address:   0x004522a0  (autoassault.exe, image base 0x400000)
// System:    unknown
// Generated: 2026-07-23 from raw capture (scaffold; refine for important units)
// Exactness: Behavior-preserving rewrite of decompiler control flow. Not modernization.
// Bit-for-bit vs retail EXE: DEFERRED (loaded image may differ slightly).
// =============================================================================

// PURPOSE (auto): Scaffold unit for FUN_004522a0 @ 0x004522a0
// Stable ID: aa_004522a0
// No high-value strings recovered; name via xrefs/callers in follow-up.
// Readability: control flow preserved from Ghidra decompile; types tentative.

// READABILITY (auto CF):
//  - Body size: ~38 non-empty decompiler lines.
//  - Control keywords: if×4, return×2, do×1, while×1.
//  - Notable callees: FUN_004522a0, FUN_004553b0.
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

int * FUN_004522a0(int *param_1)



{

  int in_EAX;

  int iVar1;

  int iVar2;

  int iVar3;

  uint32_t /* width from decompiler */ *unaff_EBX;

  byte *pbVar4;

  byte *pbVar5;

  bool bVar6;

  bool bVar7;

  

  iVar1 = FUN_004553b0();

  if (iVar1 != *(int *)(in_EAX + 4)) {

    iVar3 = 0xc;

    bVar6 = false;

    iVar2 = 0;

    bVar7 = true;

    pbVar4 = (byte *)*unaff_EBX;

    pbVar5 = *(byte **)(iVar1 + 0xc);

    do {

      if (iVar3 == 0) break;

      iVar3 = iVar3 + -1;

      bVar6 = *pbVar4 < *pbVar5;

      bVar7 = *pbVar4 == *pbVar5;

      pbVar4 = pbVar4 + 1;

      pbVar5 = pbVar5 + 1;

    } while (bVar7);

    if (!bVar7) {

      iVar2 = (1 - (uint)bVar6) - (uint)(bVar6 != 0);

    }

    if (-1 < iVar2) {

      *param_1 = iVar1;

      return param_1;

    }

  }

  *param_1 = *(int *)(in_EAX + 4);

  return param_1;

}
