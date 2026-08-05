// =============================================================================
// FUN_006bb1c0
// -----------------------------------------------------------------------------
// Stable ID: aa_006bb1c0
// Address:   0x006bb1c0  (autoassault.exe, image base 0x400000)
// System:    unknown
// Generated: 2026-07-23 from raw capture (scaffold; refine for important units)
// Exactness: Behavior-preserving rewrite of decompiler control flow. Not modernization.
// Bit-for-bit vs retail EXE: DEFERRED (loaded image may differ slightly).
// =============================================================================

// PURPOSE (auto): Scaffold unit for FUN_006bb1c0 @ 0x006bb1c0
// Stable ID: aa_006bb1c0
// No high-value strings recovered; name via xrefs/callers in follow-up.
// Readability: control flow preserved from Ghidra decompile; types tentative.

// READABILITY (auto CF):
//  - Body size: ~98 non-empty decompiler lines.
//  - Control keywords: if×4, do×1, while×1, return×1.
//  - Notable callees: FUN_00645a70, FUN_006bb0c0, FUN_006bb1c0.
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



void FUN_006bb1c0(int *param_1,float *param_2,float *param_3)



{

  int iVar1;

  float *pfVar2;

  int iVar3;

  int local_94;

  float local_90;

  float local_8c;

  float local_88;

  float local_84;

  float local_80;

  float local_7c;

  float local_78;

  float local_74;

  float local_70;

  uint32_t /* width from decompiler */ local_6c;

  uint32_t /* width from decompiler */ local_68;

  uint32_t /* width from decompiler */ local_64;

  float local_60;

  uint32_t /* width from decompiler */ local_5c;

  uint32_t /* width from decompiler */ local_58;

  uint32_t /* width from decompiler */ local_54;

  float local_50;

  uint32_t /* width from decompiler */ local_4c;

  uint32_t /* width from decompiler */ local_48;

  uint32_t /* width from decompiler */ local_44;

  float local_40 [6];

  uint32_t /* width from decompiler */ uStack_28;

  uint32_t /* width from decompiler */ uStack_24;

  uint32_t /* width from decompiler */ local_20;

  uint32_t /* width from decompiler */ uStack_1c;

  float fStack_18;

  uint32_t /* width from decompiler */ uStack_14;

  

  FUN_006bb0c0(param_1,&local_90);

  *param_3 = local_90 + local_80;

  param_3[1] = local_8c + local_7c;

  param_3[2] = local_88 + local_78;

  param_3[3] = local_84 + local_74;

  *param_3 = *param_3 * 0.5;

  param_3[1] = param_3[1] * 0.5;

  param_3[2] = param_3[2] * 0.5;

  param_3[3] = param_3[3] * 0.5;

  *param_2 = local_80 - local_90;

  param_2[1] = local_7c - local_8c;

  param_2[2] = local_78 - local_88;

  param_2[3] = local_74 - local_84;

  fStack_18 = g_flOne;

  if (_DAT_00a0d150 < param_2[2]) {

    fStack_18 = g_flOne / param_2[2];

  }

  local_40[5] = g_flOne;

  if (_DAT_00a0d150 < param_2[1]) {

    local_40[5] = g_flOne / param_2[1];

  }

  local_40[0] = g_flOne;

  if (_DAT_00a0d150 < *param_2) {

    local_40[0] = g_flOne / *param_2;

  }

  local_40[1] = 0.0;

  local_40[2] = 0.0;

  local_40[3] = 0.0;

  local_40[4] = 0.0;

  uStack_28 = 0;

  uStack_24 = 0;

  iVar3 = 0;

  local_20 = 0;

  uStack_1c = 0;

  uStack_14 = 0;

  local_94 = 0;

  if (0 < param_1[1]) {

    do {

      local_70 = *(float *)(*param_1 + iVar3) - *param_3;

      iVar1 = *param_1 + iVar3;

      local_60 = *(float *)(iVar1 + 4) - param_3[1];

      local_88 = *(float *)(iVar1 + 8) - param_3[2];

      local_6c = DAT_00bc5630;

      local_68 = DAT_00bc5630;

      local_5c = DAT_00bc5634;

      local_58 = DAT_00bc5634;

      local_48 = DAT_00bc5638;

      local_64 = 0;

      local_54 = 0;

      local_4c = DAT_00bc5638;

      local_44 = 0;

      local_50 = local_88;

      FUN_00645a70(local_40);

      pfVar2 = (float *)(*param_1 + iVar3);

      *pfVar2 = local_70;

      pfVar2[1] = local_60;

      iVar3 = iVar3 + 0x10;

      pfVar2[2] = local_50;

      pfVar2[3] = 0.0;

      local_94 = local_94 + 1;

    } while (local_94 < param_1[1]);

  }

  return;

}
