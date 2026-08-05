// =============================================================================
// FUN_005e5920
// -----------------------------------------------------------------------------
// Stable ID: aa_005e5920
// Address:   0x005e5920  (autoassault.exe, image base 0x400000)
// System:    unknown
// Generated: 2026-07-23 from raw capture (scaffold; refine for important units)
// Exactness: Behavior-preserving rewrite of decompiler control flow. Not modernization.
// Bit-for-bit vs retail EXE: DEFERRED (loaded image may differ slightly).
// =============================================================================

// PURPOSE (auto): Scaffold unit for FUN_005e5920 @ 0x005e5920
// Stable ID: aa_005e5920
// No high-value strings recovered; name via xrefs/callers in follow-up.
// Readability: control flow preserved from Ghidra decompile; types tentative.

// READABILITY (auto CF):
//  - Body size: ~41 non-empty decompiler lines.
//  - Control keywords: return×1.
//  - Notable callees: FUN_004e8860, FUN_004e88a0, FUN_004e8910, FUN_005e5920.
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

void __thiscall FUN_005e5920(int param_1,float *param_2,int param_3)



{

  float fVar1;

  float fVar2;

  float fVar3;

  float fVar4;

  float fVar5;

  float fVar6;

  float local_3c;

  float local_38;

  float local_34;

  float local_30;

  float local_2c;

  float local_28;

  float local_24;

  float local_20;

  float local_1c;

  float local_18;

  float local_14;

  

  FUN_004e8860(param_1 + 0x184,&local_20);

  FUN_004e8910(*(int *)(param_1 + 0x168) + param_3 * 0xc,&local_30);

  fVar3 = local_14 * local_14 * g_flLevelUpUiBase_Inferred - g_flOne;

  fVar2 = local_14 * g_flLevelUpUiBase_Inferred;

  fVar1 = (local_28 * local_18 + local_2c * local_1c + local_30 * local_20) *

          g_flLevelUpUiBase_Inferred;

  fVar4 = local_18 * local_30;

  fVar5 = local_2c * local_20;

  fVar6 = local_1c * local_30;

  local_30 = (local_28 * local_1c - local_18 * local_2c) * fVar2 +

             local_20 * fVar1 + local_30 * fVar3;

  local_2c = (fVar4 - local_28 * local_20) * fVar2 + local_1c * fVar1 + local_2c * fVar3;

  local_28 = (fVar5 - fVar6) * fVar2 + local_18 * fVar1 + local_28 * fVar3;

  local_24 = fVar2 * g_flZero + fVar1 * local_14 + local_24 * fVar3;

  FUN_004e88a0(&local_30,&local_3c);

  fVar1 = *(float *)(param_1 + 0x148);

  fVar2 = *(float *)(param_1 + 0x144);

  *param_2 = *(float *)(param_1 + 0x140) + local_3c;

  param_2[1] = fVar2 + local_38;

  param_2[2] = fVar1 + local_34;

  return;

}
