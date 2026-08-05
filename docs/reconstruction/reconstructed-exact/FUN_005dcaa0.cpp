// =============================================================================
// FUN_005dcaa0
// -----------------------------------------------------------------------------
// Stable ID: aa_005dcaa0
// Address:   0x005dcaa0  (autoassault.exe, image base 0x400000)
// System:    unknown
// Generated: 2026-07-23 from raw capture (scaffold; refine for important units)
// Exactness: Behavior-preserving rewrite of decompiler control flow. Not modernization.
// Bit-for-bit vs retail EXE: DEFERRED (loaded image may differ slightly).
// =============================================================================

// PURPOSE (auto): Scaffold unit for FUN_005dcaa0 @ 0x005dcaa0
// Stable ID: aa_005dcaa0
// No high-value strings recovered; name via xrefs/callers in follow-up.
// Readability: control flow preserved from Ghidra decompile; types tentative.

// READABILITY (auto CF):
//  - Body size: ~11 non-empty decompiler lines.
//  - Control keywords: return×2, if×1.
//  - Notable callees: FUN_004e2600, FUN_005081d0, FUN_00581d50, FUN_005dcaa0.
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

void __fastcall FUN_005dcaa0(int param_1)



{

  FUN_00581d50();

  FUN_004e2600(&LAB_005db3d0,0,0);

  if ((*(char *)(param_1 + -0x60) != '\0') &&

     (*(uint8_t *)(param_1 + -0x60) = 0, *(int *)(param_1 + -0xe8) != 0)) {

    FUN_005081d0();

    return;

  }

  return;

}
