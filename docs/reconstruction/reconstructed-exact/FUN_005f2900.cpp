// =============================================================================
// FUN_005f2900
// -----------------------------------------------------------------------------
// Stable ID: aa_005f2900
// Address:   0x005f2900  (autoassault.exe, image base 0x400000)
// System:    unknown
// Generated: 2026-07-23 from raw capture (scaffold; refine for important units)
// Exactness: Behavior-preserving rewrite of decompiler control flow. Not modernization.
// Bit-for-bit vs retail EXE: DEFERRED (loaded image may differ slightly).
// =============================================================================

// PURPOSE (auto): Scaffold unit for FUN_005f2900 @ 0x005f2900
// Stable ID: aa_005f2900
// No high-value strings recovered; name via xrefs/callers in follow-up.
// Readability: control flow preserved from Ghidra decompile; types tentative.

// READABILITY (auto CF):
//  - Body size: ~88 non-empty decompiler lines.
//  - Control keywords: if×1, return×1.
//  - Notable callees: FUN_005f1ec0, FUN_005f2900.
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

void FUN_005f2900(uint32_t /* width from decompiler */ param_1,float param_2,int param_3)



{

  float local_a0;

  float local_9c;

  uint32_t /* width from decompiler */ local_90;

  uint32_t /* width from decompiler */ local_8c;

  uint32_t /* width from decompiler */ local_88;

  uint32_t /* width from decompiler */ local_84;

  float local_80;

  float local_7c;

  float local_78;

  uint32_t /* width from decompiler */ local_74;

  float local_70;

  float local_6c;

  float local_68;

  uint32_t /* width from decompiler */ local_64;

  float local_60;

  float local_5c;

  float local_58;

  uint32_t /* width from decompiler */ local_54;

  float local_50 [6];

  uint32_t /* width from decompiler */ local_38;

  uint32_t /* width from decompiler */ local_34;

  uint32_t /* width from decompiler */ local_30;

  uint32_t /* width from decompiler */ local_2c;

  float local_28;

  uint32_t /* width from decompiler */ local_24;

  uint32_t /* width from decompiler */ local_20;

  uint32_t /* width from decompiler */ local_1c;

  uint32_t /* width from decompiler */ local_18;

  uint32_t /* width from decompiler */ local_14;

  

  local_84 = 0;

  local_88 = 0;

  local_8c = 0;

  local_90 = 0;

  local_74 = 0;

  local_78 = 0.0;

  local_7c = 0.0;

  local_80 = 0.0;

  local_64 = 0;

  local_68 = 0.0;

  local_6c = 0.0;

  local_70 = 0.0;

  local_54 = 0;

  local_58 = 0.0;

  local_5c = 0.0;

  local_60 = 0.0;

  local_9c = 0.0;

  local_a0 = 0.0;

  local_50[3] = 0.0;

  local_50[2] = 0.0;

  local_50[1] = 0.0;

  local_34 = 0;

  local_38 = 0;

  local_50[4] = 0.0;

  local_24 = 0;

  local_2c = 0;

  local_30 = 0;

  local_50[0] = g_flOne;

  local_50[5] = g_flOne;

  local_28 = g_flOne;

  local_14 = 0;

  local_18 = 0;

  local_1c = 0;

  local_20 = 0;

  FUN_005f1ec0(param_1,local_50,&local_a0);

  if (local_a0 != g_flZero) {

    param_2 = param_2 / local_a0;

    *(float *)(param_3 + 0xa0) = param_2 * local_9c;

    *(uint32_t /* width from decompiler */ *)(param_3 + 0x90) = local_90;

    *(uint32_t /* width from decompiler */ *)(param_3 + 0x94) = local_8c;

    *(uint32_t /* width from decompiler */ *)(param_3 + 0x98) = local_88;

    *(uint32_t /* width from decompiler */ *)(param_3 + 0x9c) = local_84;

    *(float *)(param_3 + 0x68) = local_78 * param_2;

    *(uint32_t /* width from decompiler */ *)(param_3 + 0x6c) = local_74;

    *(float *)(param_3 + 0x60) = local_80 * param_2;

    *(float *)(param_3 + 100) = local_7c * param_2;

    *(float *)(param_3 + 0x78) = local_68 * param_2;

    *(uint32_t /* width from decompiler */ *)(param_3 + 0x7c) = local_64;

    *(float *)(param_3 + 0x70) = local_70 * param_2;

    *(float *)(param_3 + 0x74) = local_6c * param_2;

    *(float *)(param_3 + 0x84) = local_5c * param_2;

    *(float *)(param_3 + 0x80) = local_60 * param_2;

    *(float *)(param_3 + 0x88) = local_58 * param_2;

    *(uint32_t /* width from decompiler */ *)(param_3 + 0x8c) = local_54;

  }

  return;

}
