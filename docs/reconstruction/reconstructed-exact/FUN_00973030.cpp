// =============================================================================
// FUN_00973030
// -----------------------------------------------------------------------------
// Stable ID: aa_00973030
// Address:   0x00973030  (autoassault.exe, image base 0x400000)
// System:    unknown
// Generated: 2026-07-23 from raw capture (scaffold; refine for important units)
// Exactness: Behavior-preserving rewrite of decompiler control flow. Not modernization.
// Bit-for-bit vs retail EXE: DEFERRED (loaded image may differ slightly).
// =============================================================================

// PURPOSE (auto): Scaffold unit for FUN_00973030 @ 0x00973030
// Stable ID: aa_00973030
// No high-value strings recovered; name via xrefs/callers in follow-up.
// Readability: control flow preserved from Ghidra decompile; types tentative.

// READABILITY (auto CF):
//  - Body size: ~15 non-empty decompiler lines.
//  - Control keywords: return×1.
//  - Notable callees: FUN_0076df50, FUN_00972fa0, FUN_00973030.
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

int __thiscall FUN_00973030(int param_1,int param_2)



{

  uint32_t /* width from decompiler */ *puVar1;

  

  puVar1 = (uint32_t /* width from decompiler */ *)FUN_00972fa0(param_2 + 0x90);

  *(uint32_t /* width from decompiler */ *)(param_1 + 0x90) = *puVar1;

  *(uint32_t /* width from decompiler */ *)(param_1 + 0x94) = puVar1[1];

  *(uint32_t /* width from decompiler */ *)(param_1 + 0x98) = puVar1[2];

  FUN_0076df50(param_1 + 0x80,param_2 + 0x80,param_1 + 0x80);

  *(float *)(param_1 + 0x9c) = *(float *)(param_2 + 0x9c) * *(float *)(param_1 + 0x9c);

  *(float *)(param_1 + 0xa0) = *(float *)(param_2 + 0xa0) * *(float *)(param_1 + 0xa0);

  *(float *)(param_1 + 0xa4) = *(float *)(param_2 + 0xa4) * *(float *)(param_1 + 0xa4);

  *(uint32_t /* width from decompiler */ *)(param_1 + 0xbc) = 0xffffffff;

  *(int *)(param_1 + 0xb4) = *(int *)(param_1 + 0xb4) + 1;

  return param_1;

}
