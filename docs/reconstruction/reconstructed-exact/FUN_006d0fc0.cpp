// =============================================================================
// FUN_006d0fc0
// -----------------------------------------------------------------------------
// Stable ID: aa_006d0fc0
// Address:   0x006d0fc0  (autoassault.exe, image base 0x400000)
// System:    unknown
// Generated: 2026-07-23 from raw capture (scaffold; refine for important units)
// Exactness: Behavior-preserving rewrite of decompiler control flow. Not modernization.
// Bit-for-bit vs retail EXE: DEFERRED (loaded image may differ slightly).
// =============================================================================

// PURPOSE (auto): Scaffold unit for FUN_006d0fc0 @ 0x006d0fc0
// Stable ID: aa_006d0fc0
// No high-value strings recovered; name via xrefs/callers in follow-up.
// Readability: control flow preserved from Ghidra decompile; types tentative.

// READABILITY (auto CF):
//  - Body size: ~91 non-empty decompiler lines.
//  - Control keywords: return×1.
//  - Notable callees: FUN_006cfe60, FUN_006d0fc0.
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

/* WARNING: Globals starting with '_' overlap smaller symbols at the same address */



void __thiscall

FUN_006d0fc0(int param_1,uint32_t /* width from decompiler */ param_2,float *param_3,float *param_4,uint32_t /* width from decompiler */ param_5,

            int param_6)



{

  float fVar1;

  float fVar2;

  float fVar3;

  float fVar4;

  float fVar5;

  float fVar6;

  float fVar7;

  float fVar8;

  float fVar9;

  float fVar10;

  float fVar11;

  float fVar12;

  float fVar13;

  float fVar14;

  float fVar15;

  float fVar16;

  float local_50;

  float local_4c;

  float local_48;

  float local_44;

  float local_40;

  float local_3c;

  float local_38;

  float local_34;

  uint32_t /* width from decompiler */ local_30;

  uint32_t /* width from decompiler */ local_2c;

  uint32_t /* width from decompiler */ local_28;

  uint32_t /* width from decompiler */ local_24;

  uint32_t /* width from decompiler */ local_20;

  float local_1c;

  uint32_t /* width from decompiler */ local_18;

  uint32_t /* width from decompiler */ local_14;

  

  fVar1 = g_flOne;

  *(uint32_t /* width from decompiler */ *)(param_1 + 100) = param_2;

  *(uint32_t /* width from decompiler */ *)(param_1 + 0x60) = param_5;

  *(int *)(param_1 + 0x5c) = param_6;

  *(uint32_t /* width from decompiler */ *)(param_1 + 0x58) = 0;

  *(uint32_t /* width from decompiler */ *)(param_1 + 0x54) = *(uint32_t /* width from decompiler */ *)(param_6 + 4);

  *(float **)(param_1 + 0x10) = param_3;

  local_24 = 0;

  local_28 = 0;

  local_2c = 0;

  local_30 = 0;

  *(float *)(param_1 + 0x14) = fVar1 / param_3[3];

  local_1c = param_3[3] * _DAT_00a0e2ac;

  fVar1 = *param_4;

  fVar2 = *param_3;

  fVar3 = param_4[1];

  fVar4 = param_3[1];

  fVar5 = param_4[2];

  fVar6 = param_3[2];

  fVar7 = param_4[3];

  fVar8 = param_3[3];

  fVar9 = param_4[4];

  fVar10 = *param_3;

  fVar11 = param_4[5];

  fVar12 = param_3[1];

  fVar13 = param_4[6];

  fVar14 = param_3[2];

  fVar15 = param_4[7];

  fVar16 = param_3[3];

  *(float *)(param_1 + 0x20) = *param_4;

  *(float *)(param_1 + 0x24) = param_4[1];

  local_50 = (fVar1 - fVar2) * local_1c;

  *(float *)(param_1 + 0x28) = param_4[2];

  *(float *)(param_1 + 0x2c) = param_4[3];

  *(float *)(param_1 + 0x30) = param_4[4];

  local_4c = (fVar3 - fVar4) * local_1c;

  local_48 = (fVar5 - fVar6) * local_1c;

  local_44 = (fVar7 - fVar8) * local_1c;

  local_40 = (fVar9 - fVar10) * local_1c;

  local_3c = (fVar11 - fVar12) * local_1c;

  local_38 = (fVar13 - fVar14) * local_1c;

  local_34 = (fVar15 - fVar16) * local_1c;

  *(float *)(param_1 + 0x34) = param_4[5];

  *(float *)(param_1 + 0x38) = param_4[6];

  *(float *)(param_1 + 0x3c) = param_4[7];

  *(float *)(param_1 + 0x40) = param_4[8];

  *(float *)(param_1 + 0x44) = param_4[9];

  *(uint8_t *)(param_1 + 0x50) = 0;

  local_18 = 0;

  local_20 = 0;

  local_14 = 0;

  FUN_006cfe60(&local_30,param_3 + 0xc,&local_50);

  return;

}
