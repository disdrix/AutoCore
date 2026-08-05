// =============================================================================
// FUN_0056b1d0
// -----------------------------------------------------------------------------
// Stable ID: aa_0056b1d0
// Address:   0x0056b1d0  (autoassault.exe, image base 0x400000)
// System:    unknown
// Generated: 2026-07-23 from raw capture (scaffold; refine for important units)
// Exactness: Behavior-preserving rewrite of decompiler control flow. Not modernization.
// Bit-for-bit vs retail EXE: DEFERRED (loaded image may differ slightly).
// =============================================================================

// PURPOSE (auto): Scaffold unit for FUN_0056b1d0 @ 0x0056b1d0
// Stable ID: aa_0056b1d0
// No high-value strings recovered; name via xrefs/callers in follow-up.
// Readability: control flow preserved from Ghidra decompile; types tentative.

// READABILITY (auto CF):
//  - Body size: ~12 non-empty decompiler lines.
//  - Control keywords: return×1.
//  - Notable callees: FUN_00569e40, FUN_00569ee0, FUN_0056b1d0, ROUND, ceil.
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

void __fastcall FUN_0056b1d0(int param_1)



{

  double dVar1;

  

  *(float *)(param_1 + -0x68) =

       (*(float *)(param_1 + -0x54) + g_flOne) * *(float *)(param_1 + -0x68);

  dVar1 = ceil((double)((*(float *)(param_1 + -0x50) + g_flOne) * (float)*(int *)(param_1 + -0x80)))

  ;

  *(int *)(param_1 + -0x80) = (int)ROUND(dVar1);

  FUN_00569e40(*(float *)(param_1 + -0x4c) + g_flOne,0);

  FUN_00569ee0(*(float *)(param_1 + -0x48) + g_flOne,0);

  return;

}
