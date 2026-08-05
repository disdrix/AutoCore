// =============================================================================
// FUN_00653710
// -----------------------------------------------------------------------------
// Stable ID: aa_00653710
// Address:   0x00653710  (autoassault.exe, image base 0x400000)
// System:    unknown
// Generated: 2026-07-23 from raw capture (scaffold; refine for important units)
// Exactness: Behavior-preserving rewrite of decompiler control flow. Not modernization.
// Bit-for-bit vs retail EXE: DEFERRED (loaded image may differ slightly).
// =============================================================================

// PURPOSE (auto): Scaffold unit for FUN_00653710 @ 0x00653710
// Stable ID: aa_00653710
// No high-value strings recovered; name via xrefs/callers in follow-up.
// Readability: control flow preserved from Ghidra decompile; types tentative.

// READABILITY (auto CF):
//  - Body size: ~10 non-empty decompiler lines.
//  - Control keywords: if×1, return×1.
//  - Notable callees: FUN_004f3540, FUN_00653710.
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

void __fastcall FUN_00653710(int param_1)



{

  *(undefined ***)(param_1 + 0xd0) = &PTR_FUN_009e5bf4;

  if (*(int *)(param_1 + 0x120) != 0) {

    FUN_004f3540(1);

    *(uint32_t /* width from decompiler */ *)(param_1 + 0x120) = 0;

  }

  *(undefined ***)(param_1 + 0xd0) = &PTR_LAB_009cc290;

  return;

}
