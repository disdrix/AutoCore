// =============================================================================
// FUN_00748710
// -----------------------------------------------------------------------------
// Stable ID: aa_00748710
// Address:   0x00748710  (autoassault.exe, image base 0x400000)
// System:    unknown
// Generated: 2026-07-23 from raw capture (scaffold; refine for important units)
// Exactness: Behavior-preserving rewrite of decompiler control flow. Not modernization.
// Bit-for-bit vs retail EXE: DEFERRED (loaded image may differ slightly).
// =============================================================================

// PURPOSE (auto): Scaffold unit for FUN_00748710 @ 0x00748710
// Stable ID: aa_00748710
// No high-value strings recovered; name via xrefs/callers in follow-up.
// Readability: control flow preserved from Ghidra decompile; types tentative.

// READABILITY (auto CF):
//  - Body size: ~30 non-empty decompiler lines.
//  - Control keywords: if×7, return×3, goto×2.
//  - Notable callees: FUN_0044b680×2, CONCAT31, FUN_00748710, FUN_00752590.
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

uint FUN_00748710(void)



{

  uint uVar1;

  uint uVar2;

  int *unaff_ESI;

  int *unaff_EDI;

  

  uVar1 = (**(code **)(*unaff_EDI + 4))();

  uVar2 = (**(code **)(*unaff_ESI + 4))();

  if ((uVar1 == uVar2) && (uVar2 = unaff_EDI[0x2b], uVar2 == unaff_ESI[0x2b])) {

    uVar2 = FUN_0044b680();

    if ((char)uVar2 != '\0') {

      if (unaff_EDI[7] != 0) {

        uVar2 = 0;

        if (unaff_ESI[7] == 0) goto LAB_00748780;

        uVar2 = FUN_0044b680();

        if ((char)uVar2 == '\0') goto LAB_00748780;

      }

      uVar2 = unaff_EDI[8];

      if (uVar2 == unaff_ESI[8]) {

        return CONCAT31((int3)(uVar2 >> 8),1);

      }

      if ((uVar2 != 0) && (unaff_ESI[8] != 0)) {

        uVar2 = FUN_00752590();

        return uVar2;

      }

    }

  }

LAB_00748780:

  return uVar2 & 0xffffff00;

}
