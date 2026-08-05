// =============================================================================
// FUN_004cd7f0
// -----------------------------------------------------------------------------
// Stable ID: aa_004cd7f0
// Address:   0x004cd7f0  (autoassault.exe, image base 0x400000)
// System:    unknown
// Generated: 2026-07-23 from raw capture (scaffold; refine for important units)
// Exactness: Behavior-preserving rewrite of decompiler control flow. Not modernization.
// Bit-for-bit vs retail EXE: DEFERRED (loaded image may differ slightly).
// =============================================================================

// PURPOSE (auto): Scaffold unit for FUN_004cd7f0 @ 0x004cd7f0
// Stable ID: aa_004cd7f0
// No high-value strings recovered; name via xrefs/callers in follow-up.
// Readability: control flow preserved from Ghidra decompile; types tentative.

// READABILITY (auto CF):
//  - Body size: ~9 non-empty decompiler lines.
//  - Control keywords: if×1, return×1.
//  - Notable callees: FUN_004a82d0, FUN_004cd7f0.
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

void __thiscall FUN_004cd7f0(int *param_1,float param_2)



{

  if ((param_1[0x393e] != 0) && (param_2 != *(float *)(param_1[0x393e] + 0x18))) {

    (**(code **)(*param_1 + 0xc))();

    FUN_004a82d0(param_2);

    (**(code **)(*param_1 + 8))();

  }

  return;

}
