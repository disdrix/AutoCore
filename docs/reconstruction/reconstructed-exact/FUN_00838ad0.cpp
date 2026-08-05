// =============================================================================
// FUN_00838ad0
// -----------------------------------------------------------------------------
// Stable ID: aa_00838ad0
// Address:   0x00838ad0  (autoassault.exe, image base 0x400000)
// System:    unknown
// Generated: 2026-07-23 from raw capture (scaffold; refine for important units)
// Exactness: Behavior-preserving rewrite of decompiler control flow. Not modernization.
// Bit-for-bit vs retail EXE: DEFERRED (loaded image may differ slightly).
// =============================================================================

// PURPOSE (auto): Scaffold unit for FUN_00838ad0 @ 0x00838ad0
// Stable ID: aa_00838ad0
// No high-value strings recovered; name via xrefs/callers in follow-up.
// Readability: control flow preserved from Ghidra decompile; types tentative.

// READABILITY (auto CF):
//  - Body size: ~30 non-empty decompiler lines.
//  - Control keywords: if×6, return×6.
//  - Notable callees: FUN_00837e80, FUN_00838ad0.
//  - Return sites: 6.

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

uint32_t /* width from decompiler */ FUN_00838ad0(void)



{

  char cVar1;

  int iVar2;

  int iVar3;

  int *unaff_EDI;

  

  if (unaff_EDI == (int *)0x0) {

    return 0;

  }

  cVar1 = FUN_00837e80();

  if (cVar1 != '\0') {

    return 0;

  }

  if (DAT_00d1b6d8 != 0) {

    iVar2 = (**(code **)(*(int *)(*(int *)(*(int *)(DAT_00d1b6d8 + 4) + 4) + 4 + DAT_00d1b6d8) +

                        0x28c))();

    iVar3 = (**(code **)(*unaff_EDI + 0x28c))();

    if (iVar2 == iVar3) {

      return 0;

    }

  }

  if (((unaff_EDI[0x10] & unaff_EDI[0x11]) == 0xffffffff) &&

     (iVar2 = (**(code **)(*unaff_EDI + 0x28c))(), iVar2 == -100)) {

    return 1;

  }

  if ((unaff_EDI[0x10] & unaff_EDI[0x11]) != 0xffffffff) {

    return 1;

  }

  return 0;

}
