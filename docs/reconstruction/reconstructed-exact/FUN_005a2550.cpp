// =============================================================================
// FUN_005a2550
// -----------------------------------------------------------------------------
// Stable ID: aa_005a2550
// Address:   0x005a2550  (autoassault.exe, image base 0x400000)
// System:    unknown
// Generated: 2026-07-23 from raw capture (scaffold; refine for important units)
// Exactness: Behavior-preserving rewrite of decompiler control flow. Not modernization.
// Bit-for-bit vs retail EXE: DEFERRED (loaded image may differ slightly).
// =============================================================================

// PURPOSE (auto): Scaffold unit for FUN_005a2550 @ 0x005a2550
// Stable ID: aa_005a2550
// No high-value strings recovered; name via xrefs/callers in follow-up.
// Readability: control flow preserved from Ghidra decompile; types tentative.

// READABILITY (auto CF):
//  - Body size: ~20 non-empty decompiler lines.
//  - Control keywords: return×1.
//  - Notable callees: FUN_0042aea0, FUN_005a2550, _strdup.
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

uint32_t /* width from decompiler */ * __thiscall

FUN_005a2550(uint32_t /* width from decompiler */ *param_1,char *param_2,uint32_t /* width from decompiler */ param_3,uint32_t /* width from decompiler */ param_4,

            uint32_t /* width from decompiler */ param_5)



{

  char *pcVar1;

  

  FUN_0042aea0();

  *param_1 = &PTR_FUN_009d7c20;

  pcVar1 = _strdup(param_2);

  param_1[8] = pcVar1;

  param_1[2] = param_5;

  param_1[3] = param_4;

  param_1[1] = param_3;

  param_1[4] = 0;

  param_1[5] = 0;

  param_1[6] = 0;

  param_1[7] = 0;

  param_1[0xd] = DAT_00d179a4;

  DAT_00d179a4 = param_1;

  return param_1;

}
