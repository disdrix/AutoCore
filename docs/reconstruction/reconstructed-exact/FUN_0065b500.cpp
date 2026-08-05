// =============================================================================
// FUN_0065b500
// -----------------------------------------------------------------------------
// Stable ID: aa_0065b500
// Address:   0x0065b500  (autoassault.exe, image base 0x400000)
// System:    unknown
// Generated: 2026-07-23 from raw capture (scaffold; refine for important units)
// Exactness: Behavior-preserving rewrite of decompiler control flow. Not modernization.
// Bit-for-bit vs retail EXE: DEFERRED (loaded image may differ slightly).
// =============================================================================

// PURPOSE (auto): Scaffold unit for FUN_0065b500 @ 0x0065b500
// Stable ID: aa_0065b500
// No high-value strings recovered; name via xrefs/callers in follow-up.
// Readability: control flow preserved from Ghidra decompile; types tentative.

// READABILITY (auto CF):
//  - Body size: ~12 non-empty decompiler lines.
//  - Control keywords: return×1.
//  - Notable callees: FUN_0065b500, FUN_006cde40.
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

void __thiscall FUN_0065b500(int param_1,int param_2)



{

  float fVar1;

  

  FUN_006cde40(param_2);

  *(uint32_t /* width from decompiler */ *)(param_1 + 0x24) = *(uint32_t /* width from decompiler */ *)(param_2 + 0xc);

  *(float *)(param_1 + 0x20) = *(float *)(param_2 + 0xc) * *(float *)(param_2 + 0xc);

  fVar1 = *(float *)(param_2 + 0x10);

  *(float *)(param_1 + 0x28) = fVar1;

  fVar1 = *(float *)(param_1 + 0x24) - fVar1;

  *(float *)(param_1 + 0x2c) = fVar1 * fVar1;

  return;

}
