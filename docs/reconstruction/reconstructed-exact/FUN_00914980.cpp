// =============================================================================
// FUN_00914980
// -----------------------------------------------------------------------------
// Stable ID: aa_00914980
// Address:   0x00914980  (autoassault.exe, image base 0x400000)
// System:    unknown
// Generated: 2026-07-23 from raw capture (scaffold; refine for important units)
// Exactness: Behavior-preserving rewrite of decompiler control flow. Not modernization.
// Bit-for-bit vs retail EXE: DEFERRED (loaded image may differ slightly).
// =============================================================================

// PURPOSE (auto): Scaffold unit for FUN_00914980 @ 0x00914980
// Stable ID: aa_00914980
// No high-value strings recovered; name via xrefs/callers in follow-up.
// Readability: control flow preserved from Ghidra decompile; types tentative.

// READABILITY (auto CF):
//  - Body size: ~11 non-empty decompiler lines.
//  - Control keywords: return×1.
//  - Notable callees: FUN_00914980.
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

void FUN_00914980(float param_1,float param_2,float param_3,float param_4,float param_5)



{

  int iVar1;

  int in_EAX;

  

  iVar1 = DAT_00d17944;

  *(uint32_t /* width from decompiler */ *)(in_EAX + 0x540) = 0;

  *(float *)(iVar1 + 0x228) = *(float *)(in_EAX + 0x5ac) * param_4 + param_1;

  *(float *)(iVar1 + 0x22c) = param_2 + param_5;

  *(float *)(iVar1 + 0x230) = *(float *)(in_EAX + 0x5b4) * param_4 + param_3;

  return;

}
