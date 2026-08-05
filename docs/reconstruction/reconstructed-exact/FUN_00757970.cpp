// =============================================================================
// FUN_00757970
// -----------------------------------------------------------------------------
// Stable ID: aa_00757970
// Address:   0x00757970  (autoassault.exe, image base 0x400000)
// System:    unknown
// Generated: 2026-07-23 from raw capture (scaffold; refine for important units)
// Exactness: Behavior-preserving rewrite of decompiler control flow. Not modernization.
// Bit-for-bit vs retail EXE: DEFERRED (loaded image may differ slightly).
// =============================================================================

// PURPOSE (auto): Scaffold unit for FUN_00757970 @ 0x00757970
// Stable ID: aa_00757970
// No high-value strings recovered; name via xrefs/callers in follow-up.
// Readability: control flow preserved from Ghidra decompile; types tentative.

// READABILITY (auto CF):
//  - Body size: ~80 non-empty decompiler lines.
//  - Control keywords: return×1.
//  - Notable callees: FUN_004148e0, FUN_00440230, FUN_00440450, FUN_00440560, FUN_00757050, FUN_00757970, SQRT.
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

uint32_t /* width from decompiler */ __thiscall FUN_00757970(float *param_1,int param_2,uint32_t /* width from decompiler */ param_3,uint32_t /* width from decompiler */ param_4)



{

  float fVar1;

  uint32_t /* width from decompiler */ uVar2;

  float *unaff_EDI;

  float fVar3;

  float fVar4;

  uint32_t /* width from decompiler */ local_7c;

  uint8_t local_78;

  uint8_t local_77;

  uint8_t local_76;

  uint32_t /* width from decompiler */ local_74;

  uint32_t /* width from decompiler */ local_70;

  float local_6c;

  float local_68;

  uint32_t /* width from decompiler */ local_60;

  uint32_t /* width from decompiler */ local_5c;

  uint32_t /* width from decompiler */ local_58;

  float local_54;

  float local_50;

  uint32_t /* width from decompiler */ local_48;

  float local_44;

  uint32_t /* width from decompiler */ local_40;

  float local_3c;

  float local_38;

  uint32_t /* width from decompiler */ local_30;

  float local_2c;

  float local_28;

  float local_24;

  float local_20;

  uint32_t /* width from decompiler */ local_18;

  uint32_t /* width from decompiler */ local_14;

  float local_10;

  void *local_c;

  uint8_t *puStack_8;

  uint32_t /* width from decompiler */ local_4;

  

  puStack_8 = &LAB_009b1bd6;

  local_c = ExceptionList;

  local_7c = 0;

  local_78 = 0;

  local_77 = 0;

  local_76 = 0;

  local_74 = 0;

  local_70 = 0;

  local_4 = 0;

  ExceptionList = &local_c;

  FUN_004148e0(param_4);

  fVar3 = param_1[1] - unaff_EDI[1];

  fVar4 = *param_1 - *unaff_EDI;

  local_60 = param_3;

  local_48 = param_3;

  local_30 = param_3;

  local_18 = param_3;

  fVar1 = g_flOne / SQRT(fVar3 * fVar3 + fVar4 * fVar4);

  local_24 = fVar3 * fVar1 * DAT_00aaa6cc;

  local_20 = fVar1 * fVar4 * DAT_00a0f298;

  local_54 = *unaff_EDI + local_24;

  local_6c = *unaff_EDI - local_24;

  local_38 = local_20 + param_1[1];

  local_68 = unaff_EDI[1] - local_20;

  local_50 = unaff_EDI[1] + local_20;

  local_20 = param_1[1] - local_20;

  local_3c = *param_1 + local_24;

  local_24 = *param_1 - local_24;

  local_5c = 0;

  local_58 = 0;

  local_44 = g_flOne;

  local_40 = 0;

  local_2c = g_flOne;

  local_28 = g_flOne;

  local_14 = 0;

  local_10 = g_flOne;

  uVar2 = FUN_00440560(param_2 + 0x68);

  FUN_00440450(uVar2);

  FUN_00757050(param_2,4);

  local_4 = 0xffffffff;

  FUN_00440230(&local_7c);

  ExceptionList = local_c;

  return 0;

}
