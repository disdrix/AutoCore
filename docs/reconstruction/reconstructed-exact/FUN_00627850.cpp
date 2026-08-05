// =============================================================================
// FUN_00627850
// -----------------------------------------------------------------------------
// Stable ID: aa_00627850
// Address:   0x00627850  (autoassault.exe, image base 0x400000)
// System:    unknown
// Generated: 2026-07-23 from raw capture (scaffold; refine for important units)
// Exactness: Behavior-preserving rewrite of decompiler control flow. Not modernization.
// Bit-for-bit vs retail EXE: DEFERRED (loaded image may differ slightly).
// =============================================================================

// PURPOSE (auto): Scaffold unit for FUN_00627850 @ 0x00627850
// Stable ID: aa_00627850
// No high-value strings recovered; name via xrefs/callers in follow-up.
// Readability: control flow preserved from Ghidra decompile; types tentative.

// READABILITY (auto CF):
//  - Body size: ~11 non-empty decompiler lines.
//  - Control keywords: if×1, return×1.
//  - Notable callees: FUN_00578b30, FUN_00627170, FUN_00627850, ROUND.
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

void __fastcall FUN_00627850(int param_1)



{

  if (*(int *)(param_1 + 0x18) != 0) {

    FUN_00627170((int)ROUND((float)(int)*(short *)(param_1 + 0x100)),

                 (int)(short)(int)*(float *)(param_1 + 0x184),

                 (int)(short)(int)*(float *)(param_1 + 0x188),

                 (int)(short)(int)*(float *)(param_1 + 0x18c),1);

  }

  FUN_00578b30();

  return;

}
