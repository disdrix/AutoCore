// =============================================================================
// FUN_00780060
// -----------------------------------------------------------------------------
// Stable ID: aa_00780060
// Address:   0x00780060  (autoassault.exe, image base 0x400000)
// System:    unknown
// Generated: 2026-07-23 from raw capture (scaffold; refine for important units)
// Exactness: Behavior-preserving rewrite of decompiler control flow. Not modernization.
// Bit-for-bit vs retail EXE: DEFERRED (loaded image may differ slightly).
// =============================================================================

// PURPOSE (auto): Scaffold unit for FUN_00780060 @ 0x00780060
// Stable ID: aa_00780060
// No high-value strings recovered; name via xrefs/callers in follow-up.
// Readability: control flow preserved from Ghidra decompile; types tentative.

// READABILITY (auto CF):
//  - Body size: ~25 non-empty decompiler lines.
//  - Control keywords: if×2, return×2.
//  - Notable callees: fseek×2, fwrite×2, FUN_00780060, fflush.
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

void FUN_00780060(void)



{

  uint uVar1;

  uint _Count;

  uint local_4;

  

  if ((DAT_00afdc98 + 7 & 0xfffffff8) != 0) {

    uVar1 = DAT_00afdc98 + DAT_00d179f4 * 8;

    fseek(DAT_00d179ec,0,0);

    local_4 = uVar1;

    fwrite(&local_4,1,4,DAT_00d179ec);

    fseek(DAT_00d179ec,DAT_00d179f4,0);

    _Count = DAT_00afdc98 + 7 >> 3;

    fwrite(DAT_00afdc8c,1,_Count,DAT_00d179ec);

    fflush(DAT_00d179ec);

    DAT_00afdc98 = uVar1 & 7;

    if (DAT_00afdc98 != 0) {

      *DAT_00afdc8c = DAT_00afdc8c[_Count - 1];

      DAT_00d179f4 = DAT_00d179f4 + -1 + _Count;

      return;

    }

    DAT_00d179f4 = DAT_00d179f4 + _Count;

    DAT_00afdc98 = 0;

  }

  return;

}
