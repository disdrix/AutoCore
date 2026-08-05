// =============================================================================
// FUN_006ee900
// -----------------------------------------------------------------------------
// Stable ID: aa_006ee900
// Address:   0x006ee900  (autoassault.exe, image base 0x400000)
// System:    unknown
// Generated: 2026-07-23 from raw capture (scaffold; refine for important units)
// Exactness: Behavior-preserving rewrite of decompiler control flow. Not modernization.
// Bit-for-bit vs retail EXE: DEFERRED (loaded image may differ slightly).
// =============================================================================

// PURPOSE (auto): Scaffold unit for FUN_006ee900 @ 0x006ee900
// Stable ID: aa_006ee900
// No high-value strings recovered; name via xrefs/callers in follow-up.
// Readability: control flow preserved from Ghidra decompile; types tentative.

// READABILITY (auto CF):
//  - Body size: ~20 non-empty decompiler lines.
//  - Control keywords: return×1.
//  - Notable callees: FUN_006ee900.
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

void __thiscall

FUN_006ee900(int param_1,uint32_t /* width from decompiler */ param_2,int *param_3,uint32_t /* width from decompiler */ param_4,uint32_t /* width from decompiler */ param_5)



{

  undefined **local_1c;

  uint8_t local_18;

  uint32_t /* width from decompiler */ local_14;

  uint32_t /* width from decompiler */ local_10;

  int local_c;

  int local_8;

  int *local_4;

  

  local_14 = param_5;

  local_8 = param_3[2];

  local_4 = param_3;

  local_18 = 0;

  local_1c = &PTR_LAB_00a0e32c;

  local_c = param_3[1];

  local_10 = *(uint32_t /* width from decompiler */ *)(*param_3 + 0xc);

  (**(code **)(**(int **)(param_1 + 0xc) + 4))(&local_10,param_2,param_4,&local_1c);

  return;

}
