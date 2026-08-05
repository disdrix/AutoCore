// =============================================================================
// FUN_005a6060
// -----------------------------------------------------------------------------
// Stable ID: aa_005a6060
// Address:   0x005a6060  (autoassault.exe, image base 0x400000)
// System:    unknown
// Generated: 2026-07-23 from raw capture (scaffold; refine for important units)
// Exactness: Behavior-preserving rewrite of decompiler control flow. Not modernization.
// Bit-for-bit vs retail EXE: DEFERRED (loaded image may differ slightly).
// =============================================================================

// PURPOSE (auto): Scaffold unit for FUN_005a6060 @ 0x005a6060
// Stable ID: aa_005a6060
// No high-value strings recovered; name via xrefs/callers in follow-up.
// Readability: control flow preserved from Ghidra decompile; types tentative.

// READABILITY (auto CF):
//  - Body size: ~9 non-empty decompiler lines.
//  - Control keywords: return×1.
//  - Notable callees: FUN_004d2af0, FUN_004d5820, FUN_005a6060.
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

void __thiscall FUN_005a6060(int param_1,float param_2,float param_3,float param_4)



{

  FUN_004d2af0(param_1);

  *(float *)(param_1 + 0x140) = *(float *)(param_1 + 0x140) + param_2;

  *(float *)(param_1 + 0x144) = *(float *)(param_1 + 0x144) + param_3;

  *(float *)(param_1 + 0x148) = *(float *)(param_1 + 0x148) + param_4;

  FUN_004d5820(param_1);

  return;

}
