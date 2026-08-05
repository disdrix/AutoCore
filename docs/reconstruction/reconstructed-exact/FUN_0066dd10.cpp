// =============================================================================
// FUN_0066dd10
// -----------------------------------------------------------------------------
// Stable ID: aa_0066dd10
// Address:   0x0066dd10  (autoassault.exe, image base 0x400000)
// System:    unknown
// Generated: 2026-07-23 from raw capture (scaffold; refine for important units)
// Exactness: Behavior-preserving rewrite of decompiler control flow. Not modernization.
// Bit-for-bit vs retail EXE: DEFERRED (loaded image may differ slightly).
// =============================================================================

// PURPOSE (auto): Scaffold unit for FUN_0066dd10 @ 0x0066dd10
// Stable ID: aa_0066dd10
// No high-value strings recovered; name via xrefs/callers in follow-up.
// Readability: control flow preserved from Ghidra decompile; types tentative.

// READABILITY (auto CF):
//  - Body size: ~60 non-empty decompiler lines.
//  - Control keywords: return×1.
//  - Notable callees: FUN_0066dd10.
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

FUN_0066dd10(uint32_t /* width from decompiler */ *param_1,float *param_2,float *param_3,float param_4,uint32_t /* width from decompiler */ param_5,

            float param_6)



{

  float fVar1;

  float *pfStack_70;

  float *pfStack_6c;

  float fStack_68;

  float fStack_64;

  float local_50;

  float local_4c;

  float local_48;

  float local_44;

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

  float local_18;

  float local_14;

  

  local_30 = param_3[4];

  local_2c = param_3[5];

  local_28 = param_3[6];

  local_24 = param_3[7];

  local_20 = param_3[8];

  local_1c = param_3[9];

  local_18 = param_3[10];

  local_14 = param_3[0xb];

  local_40 = *param_2 - *param_3 * param_4;

  local_3c = param_2[1] - param_3[1] * param_4;

  local_38 = param_2[2] - param_3[2] * param_4;

  local_34 = param_2[3] - param_3[3] * param_4;

  fVar1 = 0.0 - param_4;

  local_50 = *param_2 - fVar1 * *param_3;

  fStack_64 = param_6;

  local_4c = param_2[1] - fVar1 * param_3[1];

  fStack_68 = (float)param_5;

  local_48 = param_2[2] - param_3[2] * fVar1;

  pfStack_6c = &local_50;

  local_44 = param_2[3] - param_3[3] * fVar1;

  pfStack_70 = &local_40;

  (**(code **)(*(int *)*param_1 + 0x1c))();

  local_50 = *param_2 - local_40 * param_4;

  local_4c = param_2[1] - local_3c * param_4;

  local_48 = param_2[2] - local_38 * param_4;

  local_44 = param_2[3] - local_34 * param_4;

  fVar1 = param_6;

  (**(code **)(*(int *)*param_1 + 0x1c))(&local_50,&stack0xffffffa0,param_5,param_6);

  pfStack_70 = (float *)(*param_2 - fVar1 * local_40);

  pfStack_6c = (float *)(param_2[1] - local_3c * fVar1);

  fStack_68 = param_2[2] - local_38 * fVar1;

  fStack_64 = param_2[3] - local_34 * fVar1;

  (**(code **)(*(int *)*param_1 + 0x1c))(&stack0xffffffa0,&pfStack_70,param_5,param_6);

  return;

}
