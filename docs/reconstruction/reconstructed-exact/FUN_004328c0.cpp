// =============================================================================
// FUN_004328c0
// -----------------------------------------------------------------------------
// Stable ID: aa_004328c0
// Address:   0x004328c0  (autoassault.exe, image base 0x400000)
// System:    unknown
// Generated: 2026-07-23 from raw capture (scaffold; refine for important units)
// Exactness: Behavior-preserving rewrite of decompiler control flow. Not modernization.
// Bit-for-bit vs retail EXE: DEFERRED (loaded image may differ slightly).
// =============================================================================

// PURPOSE (auto): Scaffold unit for FUN_004328c0 @ 0x004328c0
// Stable ID: aa_004328c0
// No high-value strings recovered; name via xrefs/callers in follow-up.
// Readability: control flow preserved from Ghidra decompile; types tentative.

// READABILITY (auto CF):
//  - Body size: ~10 non-empty decompiler lines.
//  - Control keywords: if×1, return×1.
//  - Notable callees: FUN_004328c0, fclose.
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

bool __fastcall FUN_004328c0(int param_1)



{

  int iVar1;

  

  iVar1 = 0;

  if ((*(FILE **)(param_1 + 4) != (FILE *)0x0) && (*(char *)(param_1 + 8) != '\0')) {

    iVar1 = fclose(*(FILE **)(param_1 + 4));

    *(uint32_t /* width from decompiler */ *)(param_1 + 4) = 0;

  }

  return iVar1 == 0;

}
