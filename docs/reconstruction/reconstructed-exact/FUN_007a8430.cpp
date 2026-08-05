// =============================================================================
// FUN_007a8430
// -----------------------------------------------------------------------------
// Stable ID: aa_007a8430
// Address:   0x007a8430  (autoassault.exe, image base 0x400000)
// System:    unknown
// Generated: 2026-07-23 from raw capture (scaffold; refine for important units)
// Exactness: Behavior-preserving rewrite of decompiler control flow. Not modernization.
// Bit-for-bit vs retail EXE: DEFERRED (loaded image may differ slightly).
// =============================================================================

// PURPOSE (auto): Scaffold unit for FUN_007a8430 @ 0x007a8430
// Stable ID: aa_007a8430
// No high-value strings recovered; name via xrefs/callers in follow-up.
// Readability: control flow preserved from Ghidra decompile; types tentative.

// READABILITY (auto CF):
//  - Body size: ~11 non-empty decompiler lines.
//  - Control keywords: if×1, return×1.
//  - Notable callees: FUN_007a8430.
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

void __fastcall FUN_007a8430(int *param_1)



{

  int *piVar1;

  

  if ((param_1[0xa6] != 0) && ((float)param_1[0x4e] != g_flZero)) {

    piVar1 = (int *)(**(code **)(*param_1 + 0x290))();

    (**(code **)(*piVar1 + 0x18))(param_1 + 0x8d);

    piVar1 = (int *)(**(code **)(*param_1 + 0x290))();

    (**(code **)(*piVar1 + 0x1c))(param_1[0x4e]);

  }

  return;

}
