// =============================================================================
// Named_CalleeOf_Named_CalleeOf_Named_CalleeOf_Named_Client_InitI_006708b0
// -----------------------------------------------------------------------------
// Stable ID: aa_006708b0
// Callee of Named_CalleeOf_Named_CalleeOf_Named_Client_InitInstance
// Address:   0x006708b0  (autoassault.exe, image base 0x400000)
// System:    unknown
// Generated: 2026-07-23 from raw capture (scaffold; refine for important units)
// Exactness: Behavior-preserving rewrite of decompiler control flow. Not modernization.
// Bit-for-bit vs retail EXE: DEFERRED (loaded image may differ slightly).
// =============================================================================

// PURPOSE (auto): Called from Named_CalleeOf_Named_CalleeOf_Named_Client_InitInstance: callee helper with no high-value strings in clean/raw. Role inferred from parent name only; refine when decompile strings or xrefs improve.
// Readability: control flow preserved from Ghidra decompile; types tentative.

// READABILITY (auto CF):
//  - Body size: ~80 non-empty decompiler lines.
//  - Control keywords: return×1.
//  - Notable callees: CONCAT31, FUN_006708b0, FUN_006715f0, FUN_00671610, FUN_0067b070, FUN_0076c500.
//  - Return sites: 1.

/*
 * Behavioral notes:
 * Callee of Named_CalleeOf_Named_CalleeOf_Named_Client_InitInstance
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

uint32_t /* width from decompiler */ * __fastcall Named_CalleeOf_Named_CalleeOf_Named_CalleeOf_Named_Client_InitI_006708b0(uint32_t /* width from decompiler */ *param_1)



{

  float fVar1;

  uint32_t /* width from decompiler */ uVar2;

  void *local_c;

  uint8_t *puStack_8;

  uint32_t /* width from decompiler */ local_4;

  

  local_4 = 0xffffffff;

  puStack_8 = &LAB_009a9045;

  local_c = ExceptionList;

  ExceptionList = &local_c;

  *param_1 = &PTR_FUN_009e7fd0;

  param_1[2] = 0;

  *(uint8_t *)(param_1 + 3) = 0;

  param_1[4] = 0;

  *(uint8_t *)(param_1 + 10) = 0;

  param_1[0xb] = 0;

  param_1[0xc] = 0;

  param_1[0xe] = 0;

  param_1[0xf] = 0;

  FUN_0067b070();

  local_4 = 0;

  *(uint16_t *)(param_1 + 0x14) = 0;

  *(uint8_t *)(param_1 + 0x16) = 0;

  *(uint8_t *)((int)param_1 + 0x59) = 0;

  *(uint8_t *)((int)param_1 + 0x5a) = 0;

  param_1[0x5e] = 0;

  param_1[0x5f] = 0;

  param_1[0x60] = 0;

  *(uint8_t *)(param_1 + 0x61) = 0;

  *(uint8_t *)((int)param_1 + 0x185) = 0;

  FUN_0076c500(1);

  param_1[0x6f] = 0;

  param_1[0x70] = 0;

  param_1[0x71] = 0;

  local_4._0_1_ = 1;

  *(uint8_t *)(param_1 + 0x73) = 0;

  std::basic_string<char,struct_std::char_traits<char>,class_std::allocator<char>_>::

  basic_string<char,struct_std::char_traits<char>,class_std::allocator<char>_>

            ((basic_string<char,struct_std::char_traits<char>,class_std::allocator<char>_> *)

             (param_1 + 0x74),"");

  local_4._0_1_ = 2;

  param_1[0x7b] = 0;

  param_1[0x7c] = 0;

  param_1[0x7d] = 0;

  param_1[0x7e] = 0;

  param_1[0x7f] = 0;

  param_1[0x80] = 0;

  *(uint16_t *)(param_1 + 0x81) = 0;

  param_1[0x82] = 0;

  param_1[0x83] = 0;

  uVar2 = FUN_006715f0();

  param_1[0x85] = uVar2;

  param_1[0x86] = 0;

  local_4 = CONCAT31(local_4._1_3_,3);

  uVar2 = FUN_00671610();

  fVar1 = g_flOne;

  param_1[0x88] = uVar2;

  param_1[0x89] = 0;

  param_1[0x1a] = 0x1900;

  param_1[0x18] = 8;

  param_1[0x1c] = 0;

  param_1[0x1d] = s_Sase3200_009e7fc4._0_4_;

  param_1[0x1e] = s_Sase3200_009e7fc4._4_4_;

  *(char *)(param_1 + 0x1f) = s_Sase3200_009e7fc4[8];

  param_1[0x5d] = 10;

  param_1[0x19] = 1;

  param_1[0x17] = 8000;

  *(uint8_t *)(param_1 + 0x1b) = 0;

  param_1[0x8a] = fVar1;

  param_1[0x8b] = 0;

  param_1[0x8c] = fVar1;

  param_1[0x8d] = 0;

  param_1[0x8e] = 0;

  param_1[0x8f] = 0;

  param_1[0x90] = 0;

  param_1[0x91] = 0;

  ExceptionList = local_c;

  return param_1;

}
