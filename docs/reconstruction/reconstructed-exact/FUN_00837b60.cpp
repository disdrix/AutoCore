// =============================================================================
// FUN_00837b60
// -----------------------------------------------------------------------------
// Stable ID: aa_00837b60
// Address:   0x00837b60  (autoassault.exe, image base 0x400000)
// System:    unknown
// Generated: 2026-07-23 from raw capture (scaffold; refine for important units)
// Exactness: Behavior-preserving rewrite of decompiler control flow. Not modernization.
// Bit-for-bit vs retail EXE: DEFERRED (loaded image may differ slightly).
// =============================================================================

// PURPOSE (auto): Scaffold unit for FUN_00837b60 @ 0x00837b60
// Stable ID: aa_00837b60
// No high-value strings recovered; name via xrefs/callers in follow-up.
// Readability: control flow preserved from Ghidra decompile; types tentative.

// READABILITY (auto CF):
//  - Body size: ~28 non-empty decompiler lines.
//  - Control keywords: if×4, return×1.
//  - Notable callees: FUN_00835240×3, FUN_00836410×3, FUN_00837410×2, FUN_00837710×2, FUN_00837870×2, FUN_00837b60.
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

void FUN_00837b60(void)



{

  uint32_t /* width from decompiler */ in_EAX;

  

  if (((DAT_00d1b6d8 != 0) && (*(int *)(DAT_00d1b6d8 + 0x250) != 0)) &&

     (*(char *)(*(int *)(DAT_00d1b6d8 + 0x250) + 0x106) != '\0')) {

    FUN_00835240(0);

    if ((*(char *)(DAT_00d1b6d8 + 0x6b9) != '\0') &&

       (*(int *)(*(int *)(*(int *)(DAT_00d1b6d8 + 4) + 4) + 0xa4 + DAT_00d1b6d8) != 0)) {

      FUN_00835240(0);

    }

    FUN_00837870(in_EAX,0);

    FUN_00837710(0);

    FUN_00837410(in_EAX,0);

    if (DAT_00d1d888 != 0) {

      FUN_00835240(0);

    }

    FUN_00836410(in_EAX,1,1,1,0x3f800000);

    FUN_00837710(1);

    FUN_00837410(in_EAX,1);

    FUN_00837870(in_EAX,1);

    FUN_00836410(in_EAX,0,0,1,0x3f800000);

    if ((*(char *)(DAT_00d1b6d8 + 0x6b9) != '\0') &&

       (*(int *)(*(int *)(*(int *)(DAT_00d1b6d8 + 4) + 4) + 0xa4 + DAT_00d1b6d8) != 0)) {

      FUN_00836410(in_EAX,0,0,1,0x3f800000);

    }

  }

  return;

}
