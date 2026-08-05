// =============================================================================
// FUN_008df660
// -----------------------------------------------------------------------------
// Stable ID: aa_008df660
// Address:   0x008df660  (autoassault.exe, image base 0x400000)
// System:    unknown
// Generated: 2026-07-23 from raw capture (scaffold; refine for important units)
// Exactness: Behavior-preserving rewrite of decompiler control flow. Not modernization.
// Bit-for-bit vs retail EXE: DEFERRED (loaded image may differ slightly).
// =============================================================================

// PURPOSE (auto): Scaffold unit for FUN_008df660 @ 0x008df660
// Stable ID: aa_008df660
// No high-value strings recovered; name via xrefs/callers in follow-up.
// Readability: control flow preserved from Ghidra decompile; types tentative.

// READABILITY (auto CF):
//  - Body size: ~14 non-empty decompiler lines.
//  - Control keywords: if×1, do×1, while×1, return×1.
//  - Notable callees: FUN_004133c0, FUN_008df660.
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

void FUN_008df660(void)



{

  int *piVar1;

  int *unaff_EDI;

  

  piVar1 = *(int **)unaff_EDI[0x1af];

  if (piVar1 != (int *)unaff_EDI[0x1af]) {

    do {

      (**(code **)(*unaff_EDI + 0xbc))(piVar1[2]);

      piVar1 = (int *)*piVar1;

    } while (piVar1 != (int *)unaff_EDI[0x1af]);

  }

  FUN_004133c0(0);

  return;

}
