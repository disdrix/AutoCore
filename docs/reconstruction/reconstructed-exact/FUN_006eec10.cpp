// =============================================================================
// FUN_006eec10
// -----------------------------------------------------------------------------
// Stable ID: aa_006eec10
// Address:   0x006eec10  (autoassault.exe, image base 0x400000)
// System:    unknown
// Generated: 2026-07-23 from raw capture (scaffold; refine for important units)
// Exactness: Behavior-preserving rewrite of decompiler control flow. Not modernization.
// Bit-for-bit vs retail EXE: DEFERRED (loaded image may differ slightly).
// =============================================================================

// PURPOSE (auto): Scaffold unit for FUN_006eec10 @ 0x006eec10
// Stable ID: aa_006eec10
// No high-value strings recovered; name via xrefs/callers in follow-up.
// Readability: control flow preserved from Ghidra decompile; types tentative.

// READABILITY (auto CF):
//  - Body size: ~73 non-empty decompiler lines.
//  - Control keywords: if×1, return×1.
//  - Notable callees: FUN_006eec10.
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

FUN_006eec10(int param_1,uint32_t /* width from decompiler */ param_2,int *param_3,uint32_t /* width from decompiler */ *param_4,uint32_t /* width from decompiler */ param_5,

            int param_6)



{

  undefined ***pppuVar1;

  uint32_t /* width from decompiler */ local_b0;

  int local_ac;

  int local_a8;

  int *local_a4;

  uint32_t /* width from decompiler */ local_a0;

  uint32_t /* width from decompiler */ local_9c;

  uint32_t /* width from decompiler */ local_98;

  uint32_t /* width from decompiler */ local_94;

  float local_90;

  float local_8c;

  float local_88;

  float local_84;

  uint32_t /* width from decompiler */ local_80;

  uint32_t /* width from decompiler */ local_7c;

  undefined **local_70;

  uint32_t /* width from decompiler */ local_6c;

  uint32_t /* width from decompiler */ local_60;

  uint32_t /* width from decompiler */ local_5c;

  uint32_t /* width from decompiler */ local_58;

  uint32_t /* width from decompiler */ local_54;

  uint32_t /* width from decompiler */ local_50;

  undefined **local_40;

  uint32_t /* width from decompiler */ local_3c;

  uint32_t /* width from decompiler */ local_30;

  uint32_t /* width from decompiler */ local_2c;

  uint32_t /* width from decompiler */ local_28;

  uint32_t /* width from decompiler */ local_24;

  int local_20;

  

  local_90 = -(float)param_4[4];

  local_a0 = *param_4;

  local_9c = param_4[1];

  local_8c = -(float)param_4[5];

  local_98 = param_4[2];

  local_88 = -(float)param_4[6];

  local_94 = param_4[3];

  local_80 = param_4[8];

  local_84 = -(float)param_4[7];

  local_7c = param_4[9];

  local_60 = param_4[4];

  local_5c = param_4[5];

  local_58 = param_4[6];

  local_54 = param_4[7];

  local_50 = param_5;

  local_6c = 0x7f7fffff;

  local_70 = &PTR_LAB_00a0e334;

  if (param_6 == 0) {

    local_a8 = param_3[2];

    local_ac = param_3[1];

    local_b0 = *(uint32_t /* width from decompiler */ *)(*param_3 + 0xc);

    pppuVar1 = (undefined ***)0x0;

  }

  else {

    local_40 = &PTR_LAB_00a0e334;

    local_30 = param_4[4];

    local_2c = param_4[5];

    local_28 = param_4[6];

    local_24 = param_4[7];

    local_20 = param_6;

    local_a8 = param_3[2];

    local_3c = 0x7f7fffff;

    local_ac = param_3[1];

    local_b0 = *(uint32_t /* width from decompiler */ *)(*param_3 + 0xc);

    pppuVar1 = &local_40;

  }

  local_a4 = param_3;

  (**(code **)(**(int **)(param_1 + 0xc) + 0xc))(&local_b0,param_2,&local_a0,&local_70,pppuVar1);

  return;

}
