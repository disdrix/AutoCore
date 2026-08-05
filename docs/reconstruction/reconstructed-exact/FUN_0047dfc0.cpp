// =============================================================================
// FUN_0047dfc0
// -----------------------------------------------------------------------------
// Stable ID: aa_0047dfc0
// Address:   0x0047dfc0  (autoassault.exe, image base 0x400000)
// System:    unknown
// Generated: 2026-07-23 from raw capture (scaffold; refine for important units)
// Exactness: Behavior-preserving rewrite of decompiler control flow. Not modernization.
// Bit-for-bit vs retail EXE: DEFERRED (loaded image may differ slightly).
// =============================================================================

// PURPOSE (auto): Scaffold unit for FUN_0047dfc0 @ 0x0047dfc0
// Stable ID: aa_0047dfc0
// No high-value strings recovered; name via xrefs/callers in follow-up.
// Readability: control flow preserved from Ghidra decompile; types tentative.

// READABILITY (auto CF):
//  - Body size: ~43 non-empty decompiler lines.
//  - Control keywords: do×3, while×3, if×2, return×1.
//  - Notable callees: FUN_0047dfc0.
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

void __fastcall FUN_0047dfc0(uint32_t /* width from decompiler */ param_1,int param_2)



{

  uint uVar1;

  int iVar2;

  uint uVar3;

  ushort uVar4;

  uint uVar5;

  uint uVar6;

  int unaff_EBX;

  uint uVar7;

  int iVar8;

  int unaff_EDI;

  ushort auStack_20 [16];

  

  uVar4 = 0;

  iVar8 = 1;

  do {

    iVar2 = iVar8 + 1;

    uVar4 = (*(short *)(param_2 + iVar8 * 2 + -2) + uVar4) * 2;

    auStack_20[iVar8] = uVar4;

    iVar8 = iVar2;

  } while (iVar2 < 0x10);

  iVar8 = 0;

  if (-1 < unaff_EBX) {

    do {

      uVar6 = (uint)*(ushort *)(unaff_EDI + 2 + iVar8 * 4);

      if (uVar6 != 0) {

        uVar5 = (uint)auStack_20[uVar6];

        auStack_20[uVar6] = auStack_20[uVar6] + 1;

        uVar1 = 0;

        do {

          uVar3 = uVar1;

          uVar7 = uVar5 & 1;

          uVar6 = uVar6 - 1;

          uVar5 = uVar5 >> 1;

          uVar1 = (uVar3 | uVar7) * 2;

        } while (0 < (int)uVar6);

        *(ushort *)(unaff_EDI + iVar8 * 4) = (ushort)uVar3 | (ushort)uVar7;

      }

      iVar8 = iVar8 + 1;

    } while (iVar8 <= unaff_EBX);

  }

  return;

}
