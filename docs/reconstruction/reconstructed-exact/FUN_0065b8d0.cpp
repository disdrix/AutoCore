// =============================================================================
// FUN_0065b8d0
// -----------------------------------------------------------------------------
// Stable ID: aa_0065b8d0
// Address:   0x0065b8d0  (autoassault.exe, image base 0x400000)
// System:    unknown
// Generated: 2026-07-23 from raw capture (scaffold; refine for important units)
// Exactness: Behavior-preserving rewrite of decompiler control flow. Not modernization.
// Bit-for-bit vs retail EXE: DEFERRED (loaded image may differ slightly).
// =============================================================================

// PURPOSE (auto): Scaffold unit for FUN_0065b8d0 @ 0x0065b8d0
// Stable ID: aa_0065b8d0
// No high-value strings recovered; name via xrefs/callers in follow-up.
// Readability: control flow preserved from Ghidra decompile; types tentative.

// READABILITY (auto CF):
//  - Body size: ~13 non-empty decompiler lines.
//  - Control keywords: return×1.
//  - Notable callees: FUN_0065b8d0.
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

void __thiscall FUN_0065b8d0(int param_1,uint32_t /* width from decompiler */ param_2,int param_3,uint32_t /* width from decompiler */ param_4)



{

  int *local_10;

  uint32_t /* width from decompiler */ local_c;

  uint32_t /* width from decompiler */ local_8;

  int local_4;

  

  local_8 = *(uint32_t /* width from decompiler */ *)(param_3 + 8);

  local_10 = *(int **)(param_1 + 0x30);

  local_4 = param_3;

  local_c = *(uint32_t /* width from decompiler */ *)(param_3 + 4);

  (**(code **)(*local_10 + 0x24))(param_2,&local_10,param_4);

  return;

}
