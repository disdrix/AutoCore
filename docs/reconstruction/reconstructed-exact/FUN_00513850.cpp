// =============================================================================
// FUN_00513850
// -----------------------------------------------------------------------------
// Stable ID: aa_00513850
// Address:   0x00513850  (autoassault.exe, image base 0x400000)
// System:    unknown
// Generated: 2026-07-23 from raw capture (scaffold; refine for important units)
// Exactness: Behavior-preserving rewrite of decompiler control flow. Not modernization.
// Bit-for-bit vs retail EXE: DEFERRED (loaded image may differ slightly).
// =============================================================================

// PURPOSE (auto): Scaffold unit for FUN_00513850 @ 0x00513850
// Stable ID: aa_00513850
// No high-value strings recovered; name via xrefs/callers in follow-up.
// Readability: control flow preserved from Ghidra decompile; types tentative.

// READABILITY (auto CF):
//  - Body size: ~11 non-empty decompiler lines.
//  - Control keywords: return×1.
//  - Notable callees: FUN_00512670, FUN_00513850.
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

void __fastcall FUN_00513850(int *param_1)



{

  (**(code **)(*param_1 + 0x1c))();

  (**(code **)(*param_1 + 0xc))();

  param_1[0x5f] = param_1[0x5f] | 0x10;

  FUN_00512670();

                    /* WARNING: Could not recover jumptable at 0x00513870. Too many branches */

                    /* WARNING: Treating indirect jump as call */

  (**(code **)(*param_1 + 100))();

  return;

}
