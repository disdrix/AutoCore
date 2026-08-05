// =============================================================================
// FUN_004ebc00
// -----------------------------------------------------------------------------
// Stable ID: aa_004ebc00
// Address:   0x004ebc00  (autoassault.exe, image base 0x400000)
// System:    unknown
// Generated: 2026-07-23 from raw capture (scaffold; refine for important units)
// Exactness: Behavior-preserving rewrite of decompiler control flow. Not modernization.
// Bit-for-bit vs retail EXE: DEFERRED (loaded image may differ slightly).
// =============================================================================

// PURPOSE (auto): Scaffold unit for FUN_004ebc00 @ 0x004ebc00
// Stable ID: aa_004ebc00
// No high-value strings recovered; name via xrefs/callers in follow-up.
// Readability: control flow preserved from Ghidra decompile; types tentative.

// READABILITY (auto CF):
//  - Body size: ~90 non-empty decompiler lines.
//  - Control keywords: if×4, return×2, for×1.
//  - Notable callees: FUN_004cf860, FUN_004ebc00, FUN_004f3230, free.
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



uint32_t /* width from decompiler */ __thiscall FUN_004ebc00(int param_1,uint32_t /* width from decompiler */ *param_2,float *param_3)



{

  uint32_t /* width from decompiler */ uVar1;

  int iVar2;

  float *pfVar3;

  float *pfVar4;

  float fVar5;

  float fVar6;

  float fVar7;

  float fVar8;

  float fVar9;

  uint32_t /* width from decompiler */ local_a0;

  float local_9c;

  float local_98;

  float local_94;

  float local_90 [4];

  float local_80;

  float local_7c;

  float local_78;

  float local_74;

  float local_70;

  float local_6c [9];

  uint32_t /* width from decompiler */ local_48;

  uint32_t /* width from decompiler */ local_44;

  uint32_t /* width from decompiler */ local_40;

  void *local_1c;

  void *local_c;

  uint8_t *puStack_8;

  uint32_t /* width from decompiler */ local_4;

  

  local_4 = 0xffffffff;

  puStack_8 = &LAB_009a27a8;

  local_c = ExceptionList;

  if (*(int *)(param_1 + 0x90) == 0) {

    return 0;

  }

  ExceptionList = &local_c;

  FUN_004f3230(*(int *)(param_1 + 0x90));

  local_4 = 0;

  if ((_DAT_00b03e88 & 1) == 0) {

    _DAT_00b03e88 = _DAT_00b03e88 | 1;

  }

  _DAT_00b03e7c = param_3[1];

  _DAT_00b03e80 = param_3[2];

  _DAT_00b03e78 = *param_3;

  _DAT_00b03e84 = param_3[3];

  local_98 = _DAT_00b03e7c * _DAT_00b03e7c * g_flLevelUpUiBase_Inferred;

  local_94 = _DAT_00b03e80 * _DAT_00b03e80 * g_flLevelUpUiBase_Inferred;

  fVar7 = _DAT_00b03e78 * _DAT_00b03e7c * g_flLevelUpUiBase_Inferred;

  fVar5 = _DAT_00b03e80 * _DAT_00b03e84 * g_flLevelUpUiBase_Inferred;

  local_90[0] = (g_flOne - local_98) - local_94;

  local_90[1] = fVar7 - fVar5;

  fVar9 = _DAT_00b03e7c * _DAT_00b03e84 * g_flLevelUpUiBase_Inferred;

  fVar8 = _DAT_00b03e78 * _DAT_00b03e80 * g_flLevelUpUiBase_Inferred;

  local_90[2] = fVar9 + fVar8;

  local_90[3] = fVar5 + fVar7;

  fVar7 = _DAT_00b03e78 * _DAT_00b03e84 * g_flLevelUpUiBase_Inferred;

  fVar6 = g_flOne - _DAT_00b03e78 * _DAT_00b03e78 * g_flLevelUpUiBase_Inferred;

  fVar5 = _DAT_00b03e7c * _DAT_00b03e80 * g_flLevelUpUiBase_Inferred;

  local_80 = fVar6 - local_94;

  local_7c = fVar5 - fVar7;

  local_78 = fVar8 - fVar9;

  local_74 = fVar7 + fVar5;

  local_70 = fVar6 - local_98;

  if ((_DAT_00b03e74 & 1) == 0) {

    _DAT_00b03e74 = _DAT_00b03e74 | 1;

  }

  _DAT_00b03e70 = param_2[2];

  _DAT_00b03e6c = param_2[1];

  _DAT_00b03e68 = *param_2;

  pfVar3 = local_90;

  pfVar4 = local_6c;

  for (iVar2 = 9; iVar2 != 0; iVar2 = iVar2 + -1) {

    *pfVar4 = *pfVar3;

    pfVar3 = pfVar3 + 1;

    pfVar4 = pfVar4 + 1;

  }

  local_a0 = 0;

  local_9c = _DAT_00b03e84;

  local_48 = _DAT_00b03e68;

  local_44 = _DAT_00b03e6c;

  local_40 = _DAT_00b03e70;

  FUN_004cf860(&local_a0,local_6c);

  uVar1 = local_a0;

  if (local_1c != (void *)0x0) {

    free(local_1c);

  }

  ExceptionList = local_c;

  return uVar1;

}
