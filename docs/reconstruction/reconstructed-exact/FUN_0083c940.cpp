// =============================================================================
// FUN_0083c940
// -----------------------------------------------------------------------------
// Stable ID: aa_0083c940
// Address:   0x0083c940  (autoassault.exe, image base 0x400000)
// System:    unknown
// Generated: 2026-07-23 from raw capture (scaffold; refine for important units)
// Exactness: Behavior-preserving rewrite of decompiler control flow. Not modernization.
// Bit-for-bit vs retail EXE: DEFERRED (loaded image may differ slightly).
// =============================================================================

// PURPOSE (auto): Scaffold unit for FUN_0083c940 @ 0x0083c940
// Stable ID: aa_0083c940
// No high-value strings recovered; name via xrefs/callers in follow-up.
// Readability: control flow preserved from Ghidra decompile; types tentative.

// READABILITY (auto CF):
//  - Body size: ~21 non-empty decompiler lines.
//  - Control keywords: if×3, return×1.
//  - Notable callees: FUN_00415870×2, FUN_00792490, FUN_0083c940.
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

void __fastcall FUN_0083c940(int *param_1)



{

  if (param_1[0x14e] != 0) {

    FUN_00415870();

  }

  if (param_1[0x14f] != 0) {

    FUN_00415870();

  }

  DAT_00d1d8f6 = 1;

  DAT_00d1d8f7 = 0;

  if (DAT_00d1d8e0 != (int *)0x0) {

    (**(code **)(*DAT_00d1d8e0 + 4))(0);

    DAT_00d1d8e0[0x145] = 0;

    *(uint8_t *)(DAT_00d1d8e0 + 0x13f) = 0;

  }

  FUN_00792490();

                    /* WARNING: Could not recover jumptable at 0x0083c9aa. Too many branches */

                    /* WARNING: Treating indirect jump as call */

  (**(code **)(*param_1 + 0x3ac))();

  return;

}
