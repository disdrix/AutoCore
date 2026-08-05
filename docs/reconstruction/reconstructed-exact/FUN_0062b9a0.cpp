// =============================================================================
// FUN_0062b9a0
// -----------------------------------------------------------------------------
// Stable ID: aa_0062b9a0
// Address:   0x0062b9a0  (autoassault.exe, image base 0x400000)
// System:    unknown
// Generated: 2026-07-23 from raw capture (scaffold; refine for important units)
// Exactness: Behavior-preserving rewrite of decompiler control flow. Not modernization.
// Bit-for-bit vs retail EXE: DEFERRED (loaded image may differ slightly).
// =============================================================================

// PURPOSE (auto): Scaffold unit for FUN_0062b9a0 @ 0x0062b9a0
// Stable ID: aa_0062b9a0
// No high-value strings recovered; name via xrefs/callers in follow-up.
// Readability: control flow preserved from Ghidra decompile; types tentative.

// READABILITY (auto CF):
//  - Body size: ~30 non-empty decompiler lines.
//  - Control keywords: return×1.
//  - Notable callees: FUN_0062b9a0.
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

void __thiscall FUN_0062b9a0(int *param_1,float *param_2,float *param_3,uint32_t /* width from decompiler */ param_4)



{

  float fVar1;

  float fVar2;

  float local_30;

  float local_2c;

  float local_28;

  float local_24;

  float local_20 [7];

  

  local_30 = 0.0 - *param_2;

  local_2c = 0.0 - param_2[1];

  local_28 = 0.0 - param_2[2];

  local_24 = 0.0 - param_2[3];

  (**(code **)(*param_1 + 0x28))(&local_30,local_20,param_4);

  param_1[4] = (int)((float)param_1[4] + local_2c);

  param_1[5] = (int)(local_28 + (float)param_1[5]);

  param_1[6] = (int)(local_24 + (float)param_1[6]);

  param_1[7] = (int)(local_20[0] + (float)param_1[7]);

  fVar1 = g_flOne / (float)param_1[0xe];

  fVar2 = g_flOne / (float)param_1[0xd];

  param_1[8] = (int)((float)param_1[4] + g_flOne / (float)param_1[0xc]);

  param_1[9] = (int)((float)param_1[5] + fVar2);

  param_1[10] = (int)((float)param_1[6] + fVar1);

  param_1[0xb] = param_1[7];

  *param_3 = 0.0 - local_2c;

  param_3[1] = 0.0 - local_28;

  param_3[2] = 0.0 - local_24;

  param_3[3] = 0.0 - local_20[0];

  return;

}
