// =============================================================================
// FUN_004ccf00
// -----------------------------------------------------------------------------
// Stable ID: aa_004ccf00
// Address:   0x004ccf00  (autoassault.exe, image base 0x400000)
// System:    unknown
// Generated: 2026-07-23 from raw capture (scaffold; refine for important units)
// Exactness: Behavior-preserving rewrite of decompiler control flow. Not modernization.
// Bit-for-bit vs retail EXE: DEFERRED (loaded image may differ slightly).
// =============================================================================

// PURPOSE (auto): Scaffold unit for FUN_004ccf00 @ 0x004ccf00
// Stable ID: aa_004ccf00
// No high-value strings recovered; name via xrefs/callers in follow-up.
// Readability: control flow preserved from Ghidra decompile; types tentative.

// READABILITY (auto CF):
//  - Body size: ~9 non-empty decompiler lines.
//  - Control keywords: return×2, if×1.
//  - Notable callees: FUN_004ccf00, FUN_004ccf30.
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

int __thiscall FUN_004ccf00(int param_1,uint param_2)



{

  if ((*(int *)(param_1 + 4) != 0) &&

     (param_2 < (uint)(*(int *)(param_1 + 8) - *(int *)(param_1 + 4) >> 2))) {

    return *(int *)(param_1 + 4) + param_2 * 4;

  }

                    /* WARNING: Subroutine does not return */

  FUN_004ccf30();

}
