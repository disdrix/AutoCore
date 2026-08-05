// =============================================================================
// FUN_00662070
// -----------------------------------------------------------------------------
// Stable ID: aa_00662070
// Address:   0x00662070  (autoassault.exe, image base 0x400000)
// System:    unknown
// Generated: 2026-07-23 from raw capture (scaffold; refine for important units)
// Exactness: Behavior-preserving rewrite of decompiler control flow. Not modernization.
// Bit-for-bit vs retail EXE: DEFERRED (loaded image may differ slightly).
// =============================================================================

// PURPOSE (auto): Scaffold unit for FUN_00662070 @ 0x00662070
// Stable ID: aa_00662070
// No high-value strings recovered; name via xrefs/callers in follow-up.
// Readability: control flow preserved from Ghidra decompile; types tentative.

// READABILITY (auto CF):
//  - Body size: ~34 non-empty decompiler lines.
//  - Control keywords: return×1.
//  - Notable callees: FUN_00661110, FUN_00662070.
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

void __thiscall FUN_00662070(int param_1,uint32_t /* width from decompiler */ param_2,int param_3)



{

  float local_50 [6];

  uint32_t /* width from decompiler */ local_38;

  uint32_t /* width from decompiler */ local_34;

  uint32_t /* width from decompiler */ local_30;

  uint32_t /* width from decompiler */ local_2c;

  float local_28;

  uint32_t /* width from decompiler */ local_24;

  uint32_t /* width from decompiler */ local_20;

  uint32_t /* width from decompiler */ local_1c;

  uint32_t /* width from decompiler */ local_18;

  uint32_t /* width from decompiler */ local_14;

  

  local_50[0] = g_flOne;

  *(uint32_t /* width from decompiler */ *)(param_1 + 0x10) = 0;

  *(uint32_t /* width from decompiler */ *)(param_3 + 4) = 0;

  local_50[3] = 0.0;

  local_50[2] = 0.0;

  local_50[1] = 0.0;

  local_34 = 0;

  local_38 = 0;

  local_50[4] = 0.0;

  local_24 = 0;

  local_2c = 0;

  local_30 = 0;

  local_50[5] = local_50[0];

  local_28 = local_50[0];

  local_14 = 0;

  local_18 = 0;

  local_1c = 0;

  local_20 = 0;

  FUN_00661110(param_2,local_50,param_3);

  return;

}
