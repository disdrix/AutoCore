// =============================================================================
// FUN_007407b0
// -----------------------------------------------------------------------------
// Stable ID: aa_007407b0
// Address:   0x007407b0  (autoassault.exe, image base 0x400000)
// System:    unknown
// Generated: 2026-07-23 from raw capture (scaffold; refine for important units)
// Exactness: Behavior-preserving rewrite of decompiler control flow. Not modernization.
// Bit-for-bit vs retail EXE: DEFERRED (loaded image may differ slightly).
// =============================================================================

// PURPOSE (auto): Scaffold unit for FUN_007407b0 @ 0x007407b0
// Stable ID: aa_007407b0
// No high-value strings recovered; name via xrefs/callers in follow-up.
// Readability: control flow preserved from Ghidra decompile; types tentative.

// READABILITY (auto CF):
//  - Body size: ~96 non-empty decompiler lines.
//  - Control keywords: if×6, return×2, while×1.
//  - Notable callees: ROUND×2, FUN_00440680, FUN_00740690, FUN_007407b0, FUN_00757230, FUN_00757ff0, FUN_00758460, FUN_00758c80.
//  - Return sites: 2.

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



uint32_t /* width from decompiler */ __thiscall FUN_007407b0(int param_1,int *param_2)



{

  int iVar1;

  uint32_t /* width from decompiler */ uVar2;

  int iVar3;

  uint uVar4;

  int iVar5;

  int extraout_EDX;

  int iStack_3c;

  int iStack_34;

  int local_30;

  int local_2c;

  int local_28;

  int local_24;

  int iStack_20;

  int iStack_1c;

  int iStack_18;

  int iStack_14;

  int iStack_10;

  int iStack_c;

  int local_8;

  

  *(int *)(param_1 + 0x50) = *(int *)(param_1 + 0x50) + param_2[0x3a];

  if (*(uint *)(param_1 + 0x50) < 400) {

    return 1;

  }

  *(uint32_t /* width from decompiler */ *)(param_1 + 0x50) = 0;

  FUN_00758c80();

  uVar4 = *(uint *)(param_1 + 8) >> 1;

  local_8 = 300 - uVar4;

  FUN_00440680();

  param_2[0x1a] = param_2[0x1a] + 1;

  param_2[0x12] = uVar4;

  param_2[0x13] = 0;

  param_2[0x14] = local_8;

  param_2[0x15] = 0x400;

  iVar1 = param_2[0x1a];

  param_2[0x1d] = (int)(float)-iVar1;

  if (param_2[0x1c] < iVar1) {

    param_2[0x1c] = iVar1;

  }

  local_24 = *(int *)(param_1 + 8);

  local_28 = (*(uint *)(param_1 + 0xc) >> 1) + 1;

  uVar2 = *DAT_00d1f040;

  *(uint32_t /* width from decompiler */ *)(param_1 + 0x10) = 0;

  FUN_00740690(param_2,&local_28,uVar2);

  param_2[0x1a] = param_2[0x1a] + -1;

  iVar1 = param_2[0x1a];

  param_2[0x1d] = (int)(float)-iVar1;

  if (param_2[0x1c] < iVar1) {

    param_2[0x1c] = iVar1;

  }

  FUN_00757230();

  local_2c = (*(uint *)(param_1 + 8) >> 1) + local_24;

  local_30 = 300;

  (**(code **)(*param_2 + 8))(&local_30);

  iStack_c = DAT_00d1f024 + iStack_34;

  iStack_14 = DAT_00d1f024;

  local_8 = local_30 + DAT_00d1f028;

  uVar4 = *(uint *)(param_1 + 8) >> 1;

  iVar1 = DAT_00d1f024 + uVar4;

  iStack_10 = DAT_00d1f028;

  iStack_20 = DAT_00d1f028 + uVar4;

  iStack_1c = iStack_c + -uVar4;

  iStack_18 = local_8 + -uVar4;

  iVar5 = (int)ROUND((float)param_2[0x3d] * DAT_00a0f524) << 0x18;

  local_24 = iVar1;

  FUN_00758460((float)iVar1,(float)iStack_20,(float)iStack_1c,(float)iStack_18,&DAT_00d1ec78,0,iVar5

               ,0,0,0,&DAT_00d1ecac);

  FUN_00757ff0(param_2,&iStack_14,0,iVar5);

  FUN_00759090();

  iVar5 = FUN_0076c3c0();

  if (iVar5 != 0) {

    FUN_0076c4d0();

    iStack_3c = FUN_0076c9a0();

  }

  iVar5 = *(int *)(iStack_3c + 0x40);

  iVar3 = *(int *)(iStack_3c + 0x44);

  *(uint32_t /* width from decompiler */ *)(iStack_3c + 0x68) = 0;

  *(uint32_t /* width from decompiler */ *)(iStack_3c + 0x54) = 0;

  *(uint32_t /* width from decompiler */ *)(iStack_3c + 0x74) = 0;

  while (iVar5 != iVar3) {

    FUN_0076c9d0();

    iVar5 = extraout_EDX + 4;

  }

  iVar5 = *(int *)(param_1 + 0x10);

  if (*(int *)(param_1 + 0x14) < iVar5) {

    *(int *)(param_1 + 0x14) = iVar5;

  }

  else if ((float)iVar5 < (float)*(int *)(param_1 + 0x14) * DAT_00a0f71c) {

    *(int *)(param_1 + 0x14) = (int)ROUND((float)iVar5 * _DAT_00aaab8c);

  }

  *(float *)(param_1 + 0x18) =

       ((float)(iStack_1c - iVar1) / (float)*(int *)(param_1 + 0x14)) * DAT_00a0f734;

  return 0;

}
