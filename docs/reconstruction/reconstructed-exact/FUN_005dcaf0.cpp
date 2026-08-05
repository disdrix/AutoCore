// =============================================================================
// FUN_005dcaf0
// -----------------------------------------------------------------------------
// Stable ID: aa_005dcaf0
// Address:   0x005dcaf0  (autoassault.exe, image base 0x400000)
// System:    unknown
// Generated: 2026-07-23 from raw capture (scaffold; refine for important units)
// Exactness: Behavior-preserving rewrite of decompiler control flow. Not modernization.
// Bit-for-bit vs retail EXE: DEFERRED (loaded image may differ slightly).
// =============================================================================

// PURPOSE (auto): Scaffold unit for FUN_005dcaf0 @ 0x005dcaf0
// Stable ID: aa_005dcaf0
// No high-value strings recovered; name via xrefs/callers in follow-up.
// Readability: control flow preserved from Ghidra decompile; types tentative.

// READABILITY (auto CF):
//  - Body size: ~15 non-empty decompiler lines.
//  - Control keywords: if×3, return×1.
//  - Notable callees: CVOGHBBase_Start, FUN_004e2600, FUN_00581d10, FUN_005dcaf0, FUN_005de1b0.
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

void __fastcall FUN_005dcaf0(int param_1)



{

  FUN_00581d10();

  FUN_004e2600(&LAB_005db400,0,0);

  if (*(char *)(param_1 + -0x60) != '\x01') {

    *(uint8_t *)(param_1 + -0x60) = 1;

    if (*(CVOGHBBase **)(param_1 + -0xe8) != (CVOGHBBase *)0x0) {

      CVOGHBBase_Start(*(CVOGHBBase **)(param_1 + -0xe8));

    }

    if (*(char *)(param_1 + -0x35) != '\0') {

      FUN_005de1b0(0,0,0,0,0);

    }

  }

  return;

}
