// =============================================================================
// FUN_006c7f20
// -----------------------------------------------------------------------------
// Stable ID: aa_006c7f20
// Address:   0x006c7f20  (autoassault.exe, image base 0x400000)
// System:    unknown
// Generated: 2026-07-23 from raw capture (scaffold; refine for important units)
// Exactness: Behavior-preserving rewrite of decompiler control flow. Not modernization.
// Bit-for-bit vs retail EXE: DEFERRED (loaded image may differ slightly).
// =============================================================================

// PURPOSE (auto): Scaffold unit for FUN_006c7f20 @ 0x006c7f20
// Stable ID: aa_006c7f20
// No high-value strings recovered; name via xrefs/callers in follow-up.
// Readability: control flow preserved from Ghidra decompile; types tentative.

// READABILITY (auto CF):
//  - Body size: ~13 non-empty decompiler lines.
//  - Control keywords: return×1.
//  - Notable callees: FUN_006c7f20.
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

void __thiscall FUN_006c7f20(int param_1,int param_2,float param_3,float *param_4)



{

  param_3 = param_3 + *(float *)(param_1 + 0xc);

  *param_4 = *(float *)(param_2 + 0x30) - param_3;

  param_4[1] = *(float *)(param_2 + 0x34) - param_3;

  param_4[2] = *(float *)(param_2 + 0x38) - param_3;

  param_4[3] = *(float *)(param_2 + 0x3c) - param_3;

  param_4[4] = param_3 + *(float *)(param_2 + 0x30);

  param_4[5] = param_3 + *(float *)(param_2 + 0x34);

  param_4[6] = param_3 + *(float *)(param_2 + 0x38);

  param_4[7] = param_3 + *(float *)(param_2 + 0x3c);

  return;

}
