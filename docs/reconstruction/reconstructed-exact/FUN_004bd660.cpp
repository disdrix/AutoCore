// =============================================================================
// FUN_004bd660
// -----------------------------------------------------------------------------
// Stable ID: aa_004bd660
// Address:   0x004bd660  (autoassault.exe, image base 0x400000)
// System:    unknown
// Generated: 2026-07-23 from raw capture (scaffold; refine for important units)
// Exactness: Behavior-preserving rewrite of decompiler control flow. Not modernization.
// Bit-for-bit vs retail EXE: DEFERRED (loaded image may differ slightly).
// =============================================================================

// PURPOSE (auto): Scaffold unit for FUN_004bd660 @ 0x004bd660
// Stable ID: aa_004bd660
// No high-value strings recovered; name via xrefs/callers in follow-up.
// Readability: control flow preserved from Ghidra decompile; types tentative.

// READABILITY (auto CF):
//  - Body size: ~13 non-empty decompiler lines.
//  - Control keywords: if×2, return×2.
//  - Notable callees: CONCAT31, FUN_004bd660.
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

uint FUN_004bd660(uint *param_1)



{

  uint in_EAX;

  

  if (DAT_00af0a84 < DAT_00b03734) {

    in_EAX = *(uint *)(DAT_00b03730 + 4);

    if (*(int *)(in_EAX + 8) + 5 <= DAT_00b03738) {

      *param_1 = in_EAX;

      return CONCAT31((int3)(in_EAX >> 8),1);

    }

    DAT_00af0a84 = DAT_00b03734;

  }

  return in_EAX & 0xffffff00;

}
