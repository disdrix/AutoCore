// =============================================================================
// FUN_0056fe00
// -----------------------------------------------------------------------------
// Stable ID: aa_0056fe00
// Address:   0x0056fe00  (autoassault.exe, image base 0x400000)
// System:    unknown
// Generated: 2026-07-23 from raw capture (scaffold; refine for important units)
// Exactness: Behavior-preserving rewrite of decompiler control flow. Not modernization.
// Bit-for-bit vs retail EXE: DEFERRED (loaded image may differ slightly).
// =============================================================================

// PURPOSE (auto): Scaffold unit for FUN_0056fe00 @ 0x0056fe00
// Stable ID: aa_0056fe00
// No high-value strings recovered; name via xrefs/callers in follow-up.
// Readability: control flow preserved from Ghidra decompile; types tentative.

// READABILITY (auto CF):
//  - Body size: ~12 non-empty decompiler lines.
//  - Control keywords: return×2, if×1.
//  - Notable callees: FUN_004ccf30, FUN_0056fe00, FUN_005c9a60.
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

uint8_t FUN_0056fe00(uint param_1)



{

  int iVar1;

  int iVar2;

  

  iVar2 = FUN_005c9a60();

  iVar1 = *(int *)(iVar2 + 4);

  if ((iVar1 != 0) && (param_1 < (uint)(*(int *)(iVar2 + 8) - iVar1 >> 2))) {

    return *(uint8_t *)(iVar1 + 2 + param_1 * 4);

  }

                    /* WARNING: Subroutine does not return */

  FUN_004ccf30();

}
