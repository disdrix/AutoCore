// =============================================================================
// FUN_0071f810
// -----------------------------------------------------------------------------
// Stable ID: aa_0071f810
// Address:   0x0071f810  (autoassault.exe, image base 0x400000)
// System:    unknown
// Generated: 2026-07-23 from raw capture (scaffold; refine for important units)
// Exactness: Behavior-preserving rewrite of decompiler control flow. Not modernization.
// Bit-for-bit vs retail EXE: DEFERRED (loaded image may differ slightly).
// =============================================================================

// PURPOSE (auto): Scaffold unit for FUN_0071f810 @ 0x0071f810
// Stable ID: aa_0071f810
// No high-value strings recovered; name via xrefs/callers in follow-up.
// Readability: control flow preserved from Ghidra decompile; types tentative.

// READABILITY (auto CF):
//  - Body size: ~26 non-empty decompiler lines.
//  - Control keywords: if×3, return×2, do×1, while×1.
//  - Notable callees: FUN_0071f810.
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

uint FUN_0071f810(void)



{

  int *piVar1;

  uint uVar2;

  uint uVar3;

  uint uVar4;

  int unaff_EDI;

  

  if (*(int *)(unaff_EDI + 0x10) == 0) {

    return 0x800401f0;

  }

  uVar4 = 0;

  uVar3 = 0;

  if (*(int *)(unaff_EDI + 0x1c) != 0) {

    do {

      if (*(int *)(*(int *)(unaff_EDI + 0x10) + uVar4 * 4) != 0) {

        piVar1 = *(int **)(*(int *)(unaff_EDI + 0x10) + uVar4 * 4);

        (**(code **)(*piVar1 + 0x3c))(piVar1,0xffffd8f0);

        piVar1 = *(int **)(*(int *)(unaff_EDI + 0x10) + uVar4 * 4);

        uVar2 = (**(code **)(*piVar1 + 0x48))(piVar1);

        uVar3 = uVar3 | uVar2;

      }

      uVar4 = uVar4 + 1;

    } while (uVar4 < *(uint *)(unaff_EDI + 0x1c));

  }

  return uVar3;

}
