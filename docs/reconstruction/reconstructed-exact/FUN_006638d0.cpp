// =============================================================================
// FUN_006638d0
// -----------------------------------------------------------------------------
// Stable ID: aa_006638d0
// Address:   0x006638d0  (autoassault.exe, image base 0x400000)
// System:    unknown
// Generated: 2026-07-23 from raw capture (scaffold; refine for important units)
// Exactness: Behavior-preserving rewrite of decompiler control flow. Not modernization.
// Bit-for-bit vs retail EXE: DEFERRED (loaded image may differ slightly).
// =============================================================================

// PURPOSE (auto): Scaffold unit for FUN_006638d0 @ 0x006638d0
// Stable ID: aa_006638d0
// No high-value strings recovered; name via xrefs/callers in follow-up.
// Readability: control flow preserved from Ghidra decompile; types tentative.

// READABILITY (auto CF):
//  - Body size: ~44 non-empty decompiler lines.
//  - Control keywords: if×1, return×1.
//  - Notable callees: FUN_005d68f0×2, FUN_00662140, FUN_00662230, FUN_00662280, FUN_00662510, FUN_006638d0, FUN_0066dd00, SQRT.
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

void __thiscall FUN_006638d0(int param_1,int param_2,int *param_3,uint32_t /* width from decompiler */ param_4)



{

  float *pfVar1;

  float fVar2;

  int iVar3;

  uint32_t /* width from decompiler */ uVar4;

  float fVar5;

  float fVar6;

  float fVar7;

  float fVar8;

  float fVar9;

  float local_a0;

  float local_9c;

  float local_98;

  float local_94;

  uint8_t local_90 [64];

  uint8_t local_50 [76];

  

  FUN_0066dd00(param_3);

  FUN_00662510(param_2,local_90,local_50);

  FUN_005d68f0(local_90,param_2 + 0x30);

  pfVar1 = (float *)(param_1 + 0x40);

  FUN_005d68f0(local_50,param_2 + 0x20);

  FUN_00662230(param_4);

  FUN_00662280(param_4);

  fVar8 = *(float *)(param_1 + 0x54) - *(float *)(param_1 + 0x44);

  fVar9 = *(float *)(param_1 + 0x58) - *(float *)(param_1 + 0x48);

  fVar7 = *(float *)(param_1 + 0x50) - *pfVar1;

  fVar2 = *(float *)(param_2 + 0x40);

  fVar6 = fVar9 * fVar9 + fVar8 * fVar8 + fVar7 * fVar7;

  fVar5 = 0.0;

  if (fVar6 != 0.0) {

    fVar5 = g_flOne / SQRT(fVar6);

  }

  iVar3 = *param_3;

  local_a0 = *pfVar1 + fVar5 * fVar7 * fVar2;

  local_9c = *(float *)(param_1 + 0x44) + fVar5 * fVar8 * fVar2;

  local_98 = *(float *)(param_1 + 0x48) + fVar5 * fVar9 * fVar2;

  local_94 = *(float *)(param_1 + 0x4c) +

             fVar5 * (*(float *)(param_1 + 0x5c) - *(float *)(param_1 + 0x4c)) * fVar2;

  uVar4 = FUN_00662140(0,0x3f000000,0x3f800000,0x3f800000,param_4);

  (**(code **)(iVar3 + 0x1c))(pfVar1,&local_a0,uVar4);

  (**(code **)(*param_3 + 0x1c))(&stack0xffffff50,(float *)(param_1 + 0x50),0xffff0000,param_4);

  return;

}
