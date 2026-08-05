// =============================================================================
// Named_CalleeOf_Named_CalleeOf_Named_CalleeOf_Mission_createNDUI_00910b40
// -----------------------------------------------------------------------------
// Stable ID: aa_00910b40
// Callee of Named_CalleeOf_Named_CalleeOf_Mission_createNDUIDialogs
// Address:   0x00910b40  (autoassault.exe, image base 0x400000)
// System:    unknown
// Generated: 2026-07-23 from raw capture (scaffold; refine for important units)
// Exactness: Behavior-preserving rewrite of decompiler control flow. Not modernization.
// Bit-for-bit vs retail EXE: DEFERRED (loaded image may differ slightly).
// =============================================================================

// PURPOSE (auto): Called from Named_CalleeOf_Named_CalleeOf_Mission_createNDUIDialogs: mission/objective helper with no high-value strings in clean/raw. Role inferred from parent name only; refine when decompile strings or xrefs improve.
// Readability: control flow preserved from Ghidra decompile; types tentative.

// READABILITY (auto CF):
//  - Body size: ~96 non-empty decompiler lines.
//  - Control keywords: return×1.
//  - Notable callees: FUN_00972cc0×2, CONCAT31, FUN_00792d20, FUN_0090dd50, FUN_0090e570, FUN_00910b40.
//  - Return sites: 1.

/*
 * Behavioral notes:
 * Callee of Named_CalleeOf_Named_CalleeOf_Mission_createNDUIDialogs
 * Xref/callee-driven rename (parent seed scan)
 *
 * - Derived from Ghidra decompile; names prefer Ghidra symbols / plate comments.
 * - Remaining FUN_* / DAT_* identifiers are unresolved pending type recovery.
 * - Runtime / differential verification: OPEN unless matrix says otherwise.
 *
 * Readability pass:
 * - undefinedN widths preserved as fixed-width integers where decompiler width is known.
 * - Control flow and call order preserved from authoritative raw.
 */

int * __thiscall Named_CalleeOf_Named_CalleeOf_Named_CalleeOf_Mission_createNDUI_00910b40(int param_1,int *param_2)



{

  float fVar1;

  float fVar2;

  int iVar3;

  float fVar4;

  int extraout_EDX;

  void *unaff_EBX;

  void *local_c;

  uint8_t *puStack_8;

  uint32_t /* width from decompiler */ local_4;

  

  local_4 = 0xffffffff;

  puStack_8 = &LAB_009b7da1;

  local_c = ExceptionList;

  ExceptionList = &local_c;

  FUN_00792d20(param_2);

  fVar1 = g_flOne;

  local_4 = 0;

  *param_2 = (int)&PTR_FUN_00a3035c;

  param_2[0x15b] = 0;

  param_2[0x15c] = 0;

  param_2[0x15d] = 0;

  param_2[0x15e] = (int)fVar1;

  param_2[0x15f] = 0;

  param_2[0x160] = 0;

  param_2[0x161] = 0;

  param_2[0x162] = (int)fVar1;

  param_2[0x163] = 0;

  param_2[0x164] = 0;

  param_2[0x165] = 0;

  param_2[0x166] = (int)fVar1;

  param_2[0x183] = 2;

  param_2[0x1d8] = (int)&PTR_LAB_00aa04e8;

  FUN_00972cc0();

  param_2[0x215] = 0;

  param_2[0x214] = (int)&PTR_FUN_00aa0504;

  param_2[0x228] = -1;

  local_4._0_1_ = 1;

  param_2[0x230] = (int)&PTR_LAB_00aa04e8;

  FUN_00972cc0();

  param_2[0x26d] = 0;

  param_2[0x26c] = extraout_EDX;

  param_2[0x280] = -1;

  local_4 = CONCAT31(local_4._1_3_,2);

  FUN_0090e570();

  fVar4 = g_flInferredThreatScale;

  fVar2 = g_flMultiKillCountBlend;

  fVar1 = g_flOne;

  *(uint8_t *)((int)param_2 + 0x509) = 0;

  param_2[0x184] = 0;

  param_2[0x185] = 0;

  *(uint8_t *)((int)param_2 + 0x50a) = 0;

  *(uint8_t *)((int)param_2 + 0x50b) = 0;

  *(uint8_t *)(param_2 + 0x142) = 0;

  *(uint8_t *)((int)param_2 + 0x50f) = 0;

  *(uint8_t *)(param_2 + 0x144) = 4;

  *(uint8_t *)((int)param_2 + 0x50e) = 0;

  param_2[0x160] = (int)fVar4;

  iVar3 = DAT_00aaa680;

  param_2[0x15f] = (int)fVar1;

  param_2[0x162] = (int)fVar1;

  param_2[0x161] = iVar3;

  iVar3 = DAT_00a10e78;

  param_2[0x15e] = (int)fVar1;

  param_2[0x15b] = iVar3;

  param_2[0x15c] = (int)fVar2;

  param_2[0x15d] = iVar3;

  param_2[0x163] = (int)fVar1;

  param_2[0x164] = (int)fVar1;

  param_2[0x165] = (int)fVar1;

  param_2[0x166] = (int)fVar1;

  param_2[0x168] = DAT_00a0f70c;

  param_2[0x169] = DAT_00aaabf0;

  param_2[0x16a] = DAT_00aaabec;

  FUN_0090dd50();

  param_2[0x16d] = DAT_00aaa668;

  iVar3 = DAT_00aaa6c0;

  param_2[0x16b] = 0;

  param_2[0x16c] = 0;

  param_2[0xa9] = param_1;

  param_2[0x159] = iVar3;

  iVar3 = DAT_00aaaa4c;

  param_2[0x14e] = 0;

  param_2[0x150] = 0;

  param_2[0x151] = 0;

  param_2[0x154] = iVar3;

  param_2[0x152] = 0;

  *(uint8_t *)(param_2 + 0x143) = 0;

  *(uint8_t *)((int)param_2 + 0x50d) = 0;

  (**(code **)(*param_2 + 300))(param_1 + 0xdc);

  param_2[0x28b] = 0;

  param_2[0x28a] = 0;

  param_2[0x167] = 0;

  ExceptionList = unaff_EBX;

  return param_2;

}
