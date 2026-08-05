// =============================================================================
// FUN_005deec0
// -----------------------------------------------------------------------------
// Stable ID: aa_005deec0
// Address:   0x005deec0  (autoassault.exe, image base 0x400000)
// System:    unknown
// Generated: 2026-07-23 from raw capture (scaffold; refine for important units)
// Exactness: Behavior-preserving rewrite of decompiler control flow. Not modernization.
// Bit-for-bit vs retail EXE: DEFERRED (loaded image may differ slightly).
// =============================================================================

// PURPOSE (auto): Scaffold unit for FUN_005deec0 @ 0x005deec0
// Stable ID: aa_005deec0
// No high-value strings recovered; name via xrefs/callers in follow-up.
// Readability: control flow preserved from Ghidra decompile; types tentative.

// READABILITY (auto CF):
//  - Body size: ~12 non-empty decompiler lines.
//  - Control keywords: return×1.
//  - Notable callees: FUN_005deec0, fopen.
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

uint32_t /* width from decompiler */ * __thiscall FUN_005deec0(uint32_t /* width from decompiler */ *param_1,char *param_2)



{

  FILE *pFVar1;

  

  *(uint16_t *)((int)param_1 + 6) = 1;

  param_1[2] = 0xffffffff;

  *param_1 = &PTR_FUN_009dbb1c;

  *(uint8_t *)(param_1 + 4) = 1;

  pFVar1 = fopen(param_2,"rb");

  param_1[3] = pFVar1;

  *(bool *)(param_1 + 4) = pFVar1 != (FILE *)0x0;

  return param_1;

}
