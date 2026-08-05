// =============================================================================
// FUN_0063d310
// -----------------------------------------------------------------------------
// Stable ID: aa_0063d310
// Address:   0x0063d310  (autoassault.exe, image base 0x400000)
// System:    unknown
// Generated: 2026-07-23 from raw capture (scaffold; refine for important units)
// Exactness: Behavior-preserving rewrite of decompiler control flow. Not modernization.
// Bit-for-bit vs retail EXE: DEFERRED (loaded image may differ slightly).
// =============================================================================

// PURPOSE (auto): Scaffold unit for FUN_0063d310 @ 0x0063d310
// Stable ID: aa_0063d310
// No high-value strings recovered; name via xrefs/callers in follow-up.
// Readability: control flow preserved from Ghidra decompile; types tentative.

// READABILITY (auto CF):
//  - Body size: ~32 non-empty decompiler lines.
//  - Control keywords: return×1.
//  - Notable callees: FUN_0063d310, FUN_00645c90.
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

void __fastcall FUN_0063d310(int param_1)



{

  float local_40;

  float local_3c;

  float local_38;

  float local_34;

  float local_30;

  float local_2c;

  float local_28;

  float local_24;

  float local_20;

  float local_1c;

  float local_18;

  float local_14;

  

  local_34 = *(float *)(param_1 + 0xe0);

  local_40 = *(float *)(param_1 + 0x80) * local_34;

  local_3c = *(float *)(param_1 + 0x84) * local_34;

  local_38 = *(float *)(param_1 + 0x88) * local_34;

  local_34 = *(float *)(param_1 + 0x8c) * local_34;

  local_24 = *(float *)(param_1 + 0xe4);

  local_30 = *(float *)(param_1 + 0x90) * local_24;

  local_2c = *(float *)(param_1 + 0x94) * local_24;

  local_28 = *(float *)(param_1 + 0x98) * local_24;

  local_24 = *(float *)(param_1 + 0x9c) * local_24;

  local_14 = *(float *)(param_1 + 0xe8);

  local_20 = *(float *)(param_1 + 0xa0) * local_14;

  local_1c = *(float *)(param_1 + 0xa4) * local_14;

  local_18 = *(float *)(param_1 + 0xa8) * local_14;

  local_14 = *(float *)(param_1 + 0xac) * local_14;

  FUN_00645c90(&local_40,param_1 + 0x80);

  return;

}
