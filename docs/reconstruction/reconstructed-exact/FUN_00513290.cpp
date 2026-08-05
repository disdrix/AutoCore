// =============================================================================
// FUN_00513290
// -----------------------------------------------------------------------------
// Stable ID: aa_00513290
// Address:   0x00513290  (autoassault.exe, image base 0x400000)
// System:    unknown
// Generated: 2026-07-23 from raw capture (scaffold; refine for important units)
// Exactness: Behavior-preserving rewrite of decompiler control flow. Not modernization.
// Bit-for-bit vs retail EXE: DEFERRED (loaded image may differ slightly).
// =============================================================================

// PURPOSE (auto): Scaffold unit for FUN_00513290 @ 0x00513290
// Stable ID: aa_00513290
// No high-value strings recovered; name via xrefs/callers in follow-up.
// Readability: control flow preserved from Ghidra decompile; types tentative.

// READABILITY (auto CF):
//  - Body size: ~8 non-empty decompiler lines.
//  - Control keywords: return×1.
//  - Notable callees: FUN_00513290.
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

void __thiscall FUN_00513290(int param_1,float *param_2)



{

  *(float *)(param_1 + 0x80) = *(float *)(param_1 + 0x80) - *param_2;

  *(float *)(param_1 + 0x84) = *(float *)(param_1 + 0x84) - param_2[1];

  *(float *)(param_1 + 0x88) = *(float *)(param_1 + 0x88) - param_2[2];

  *(float *)(param_1 + 0x8c) = *(float *)(param_1 + 0x8c) - param_2[3];

  return;

}
