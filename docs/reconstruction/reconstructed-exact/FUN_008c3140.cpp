// =============================================================================
// FUN_008c3140
// -----------------------------------------------------------------------------
// Stable ID: aa_008c3140
// Address:   0x008c3140  (autoassault.exe, image base 0x400000)
// System:    unknown
// Generated: 2026-07-23 from raw capture (scaffold; refine for important units)
// Exactness: Behavior-preserving rewrite of decompiler control flow. Not modernization.
// Bit-for-bit vs retail EXE: DEFERRED (loaded image may differ slightly).
// =============================================================================

// PURPOSE (auto): Scaffold unit for FUN_008c3140 @ 0x008c3140
// Stable ID: aa_008c3140
// No high-value strings recovered; name via xrefs/callers in follow-up.
// Readability: control flow preserved from Ghidra decompile; types tentative.

// READABILITY (auto CF):
//  - Body size: ~15 non-empty decompiler lines.
//  - Control keywords: if×1, return×1.
//  - Notable callees: FUN_00860700, FUN_008c3140.
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

void FUN_008c3140(void)



{

  uint in_EAX;

  int *unaff_EDI;

  

  if ((*(byte *)(unaff_EDI[0x160] + 0x564) != in_EAX) ||

     (*(uint *)(&DAT_00d17768 + unaff_EDI[0x143] * 4) != in_EAX)) {

    *(uint *)(&DAT_00d17768 + unaff_EDI[0x143] * 4) = in_EAX;

    *(char *)(unaff_EDI[0x160] + 0x564) = (char)in_EAX;

    FUN_00860700();

  }

                    /* WARNING: Could not recover jumptable at 0x008c318a. Too many branches */

                    /* WARNING: Treating indirect jump as call */

  (**(code **)(*unaff_EDI + 0x450))();

  return;

}
