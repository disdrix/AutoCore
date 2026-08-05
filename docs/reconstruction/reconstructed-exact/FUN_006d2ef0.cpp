// =============================================================================
// FUN_006d2ef0
// -----------------------------------------------------------------------------
// Stable ID: aa_006d2ef0
// Address:   0x006d2ef0  (autoassault.exe, image base 0x400000)
// System:    unknown
// Generated: 2026-07-23 from raw capture (scaffold; refine for important units)
// Exactness: Behavior-preserving rewrite of decompiler control flow. Not modernization.
// Bit-for-bit vs retail EXE: DEFERRED (loaded image may differ slightly).
// =============================================================================

// PURPOSE (auto): Scaffold unit for FUN_006d2ef0 @ 0x006d2ef0
// Stable ID: aa_006d2ef0
// No high-value strings recovered; name via xrefs/callers in follow-up.
// Readability: control flow preserved from Ghidra decompile; types tentative.

// READABILITY (auto CF):
//  - Body size: ~13 non-empty decompiler lines.
//  - Control keywords: return×1.
//  - Notable callees: FUN_006d2ef0, FUN_006ebad0.
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

void FUN_006d2ef0(uint32_t /* width from decompiler */ param_1,int *param_2,uint32_t /* width from decompiler */ param_3,uint32_t /* width from decompiler */ param_4)



{

  uint32_t /* width from decompiler */ local_10;

  int local_c;

  int local_8;

  int *local_4;

  

  local_8 = param_2[2];

  local_4 = param_2;

  local_10 = *(uint32_t /* width from decompiler */ *)(*param_2 + 0xc);

  local_c = param_2[1];

  FUN_006ebad0(param_1,&local_10,param_3,param_4);

  return;

}
