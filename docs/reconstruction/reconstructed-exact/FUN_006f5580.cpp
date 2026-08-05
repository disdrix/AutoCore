// =============================================================================
// FUN_006f5580
// -----------------------------------------------------------------------------
// Stable ID: aa_006f5580
// Address:   0x006f5580  (autoassault.exe, image base 0x400000)
// System:    unknown
// Generated: 2026-07-23 from raw capture (scaffold; refine for important units)
// Exactness: Behavior-preserving rewrite of decompiler control flow. Not modernization.
// Bit-for-bit vs retail EXE: DEFERRED (loaded image may differ slightly).
// =============================================================================

// PURPOSE (auto): Scaffold unit for FUN_006f5580 @ 0x006f5580
// Stable ID: aa_006f5580
// No high-value strings recovered; name via xrefs/callers in follow-up.
// Readability: control flow preserved from Ghidra decompile; types tentative.

// READABILITY (auto CF):
//  - Body size: ~26 non-empty decompiler lines.
//  - Control keywords: return×1.
//  - Notable callees: FUN_006f5580.
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

void __thiscall FUN_006f5580(int param_1,float *param_2)



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

  

  local_1c = param_2[8];

  local_34 = param_2[3];

  local_20 = param_2[9];

  local_40 = local_34 * *(float *)(param_1 + 0x10) + *param_2;

  local_3c = local_34 * *(float *)(param_1 + 0x14) + param_2[1];

  local_38 = local_34 * *(float *)(param_1 + 0x18) + param_2[2];

  local_30 = -param_2[4];

  local_2c = -param_2[5];

  local_28 = -param_2[6];

  local_24 = -param_2[7];

  (**(code **)(**(int **)(param_1 + 0x20) + 4))(&local_40);

  *(uint32_t /* width from decompiler */ *)(param_1 + 4) = *(uint32_t /* width from decompiler */ *)(*(int *)(param_1 + 0x20) + 4);

  return;

}
