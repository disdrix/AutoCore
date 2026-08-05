// =============================================================================
// FUN_007004a0
// -----------------------------------------------------------------------------
// Stable ID: aa_007004a0
// Address:   0x007004a0  (autoassault.exe, image base 0x400000)
// System:    unknown
// Generated: 2026-07-23 from raw capture (scaffold; refine for important units)
// Exactness: Behavior-preserving rewrite of decompiler control flow. Not modernization.
// Bit-for-bit vs retail EXE: DEFERRED (loaded image may differ slightly).
// =============================================================================

// PURPOSE (auto): Scaffold unit for FUN_007004a0 @ 0x007004a0
// Stable ID: aa_007004a0
// No high-value strings recovered; name via xrefs/callers in follow-up.
// Readability: control flow preserved from Ghidra decompile; types tentative.

// READABILITY (auto CF):
//  - Body size: ~62 non-empty decompiler lines.
//  - Control keywords: return×1.
//  - Notable callees: FUN_006ff2f0, FUN_007004a0.
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



void __thiscall FUN_007004a0(int param_1,float *param_2,uint32_t /* width from decompiler */ param_3,uint32_t /* width from decompiler */ param_4)



{

  float *pfVar1;

  float fVar2;

  uint32_t /* width from decompiler */ uVar3;

  float fStack_70;

  float fStack_6c;

  float fStack_68;

  float fStack_64;

  float fStack_60;

  float fStack_5c;

  float fStack_58;

  float fStack_54;

  uint32_t /* width from decompiler */ uStack_50;

  uint32_t /* width from decompiler */ uStack_4c;

  uint32_t /* width from decompiler */ uStack_48;

  uint32_t /* width from decompiler */ uStack_44;

  float fStack_40;

  float fStack_3c;

  float fStack_38;

  float fStack_34;

  float fStack_30;

  uint32_t /* width from decompiler */ uStack_2c;

  float fStack_28;

  uint32_t /* width from decompiler */ uStack_24;

  uint32_t /* width from decompiler */ uStack_20;

  

  *(float **)(param_1 + 0x2c) = param_2;

  *(uint32_t /* width from decompiler */ *)(param_1 + 0x10) = *(uint32_t /* width from decompiler */ *)(*(int *)param_2[0xe] + 0x10);

  *(uint32_t /* width from decompiler */ *)(param_1 + 0x24) = param_3;

  *(uint32_t /* width from decompiler */ *)(param_1 + 0x28) = param_4;

  uVar3 = (**(code **)(**(int **)param_2[0xd] + 0x14))();

  fVar2 = g_flOne;

  *(uint32_t /* width from decompiler */ *)(param_1 + 0x18) = uVar3;

  uStack_44 = 0;

  uStack_48 = 0;

  uStack_4c = 0;

  uStack_50 = 0;

  *(uint32_t /* width from decompiler */ *)(param_1 + 0x1c) = 0x3f800000;

  *(uint32_t /* width from decompiler */ *)(param_1 + 0x20) = 0x3f800000;

  pfVar1 = *(float **)(param_1 + 0x10);

  *(float *)(param_1 + 0x14) = fVar2 / pfVar1[3];

  fStack_28 = pfVar1[3] * _DAT_00a0e2ac;

  fStack_40 = fStack_28 * param_2[8];

  fStack_3c = fStack_28 * param_2[9];

  fStack_38 = fStack_28 * param_2[10];

  fStack_34 = fStack_28 * param_2[0xb];

  fStack_30 = (param_2[10] + param_2[9] + param_2[8]) * g_flVehicleHpTechCoeff;

  fStack_70 = (*param_2 - *pfVar1) * fStack_28;

  fStack_6c = (param_2[1] - pfVar1[1]) * fStack_28;

  fStack_68 = (param_2[2] - pfVar1[2]) * fStack_28;

  fStack_64 = (param_2[3] - pfVar1[3]) * fStack_28;

  uStack_24 = 0;

  uStack_2c = 0;

  fStack_60 = (param_2[4] - *pfVar1) * fStack_28;

  uStack_20 = 0;

  fStack_5c = (param_2[5] - pfVar1[1]) * fStack_28;

  fStack_58 = (param_2[6] - pfVar1[2]) * fStack_28;

  fStack_54 = (param_2[7] - pfVar1[3]) * fStack_28;

  FUN_006ff2f0(&uStack_50,pfVar1 + 0xc,&fStack_70);

  return;

}
