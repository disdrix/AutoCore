// READABILITY (auto CF):
//  - Body size: ~44 non-empty decompiler lines.
//  - Control keywords: if×1, return×1.
//  - Notable callees: CONCAT31, FUN_007679e0, vog_LogMessage.
//  - Strings: "C:\\vog\\1_code\\palantir\\arda2\\storage\\stoChunk.cpp"; "Unimplemented code reached".
//  - Return sites: 1.

// =============================================================================
// Named_stoChunk_007679e0
// -----------------------------------------------------------------------------
// Stable ID: aa_007679e0
// Address:   0x007679e0  (autoassault.exe, image base 0x400000)
// System:    unknown
// Generated: 2026-07-23 from raw capture (scaffold; refine for important units)
// Exactness: Behavior-preserving rewrite of decompiler control flow. Not modernization.
// Bit-for-bit vs retail EXE: DEFERRED (loaded image may differ slightly).
// =============================================================================

/*
 * Behavioral notes:
 * String-driven rename evidence: "stoChunk"
 *
 * - Derived from Ghidra decompile; names prefer Ghidra symbols / plate comments.
 * - Remaining FUN_* / DAT_* identifiers are unresolved pending type recovery.
 * - Runtime / differential verification: OPEN unless matrix says otherwise.
 *
 * Readability pass:
 * - undefinedN widths preserved as fixed-width integers where decompiler width is known.
 * - Control flow and call order preserved from authoritative raw.
 */

uint32_t /* width from decompiler */ * __thiscall

Named_stoChunk_007679e0(int *param_1,uint32_t /* width from decompiler */ *param_2,uint32_t /* width from decompiler */ param_3,int param_4)



{

  uint32_t /* width from decompiler */ uVar1;

  void *pvStack_c;

  uint8_t *puStack_8;

  uint32_t /* width from decompiler */ local_4;

  

  puStack_8 = &LAB_009adbc7;

  pvStack_c = ExceptionList;

  ExceptionList = &pvStack_c;

  *param_2 = 0;

  param_2[2] = 0;

  param_2[3] = 0;

  param_2[4] = 0;

  local_4 = 0;

  param_2[5] = param_1;

  param_2[6] = 0;

  param_2[7] = 0;

  param_2[8] = 0;

  param_2[9] = 0x4000;

  param_2[10] = 0;

  uVar1 = (**(code **)(*param_1 + 0x1c))();

  param_2[10] = uVar1;

  param_2[0x100b] = 0;

  param_2[0x100d] = 0;

  param_2[0x100e] = 0;

  param_2[0x100f] = 0;

  param_2[0x1010] = 0;

  local_4._0_1_ = 1;

  param_2[0x1011] = param_3;

  *(uint8_t *)(param_2 + 0x1012) = 0;

  std::basic_string<char,struct_std::char_traits<char>,class_std::allocator<char>_>::

  basic_string<char,struct_std::char_traits<char>,class_std::allocator<char>_>

            ((basic_string<char,struct_std::char_traits<char>,class_std::allocator<char>_> *)

             (param_2 + 0x1013),"");

  local_4 = CONCAT31(local_4._1_3_,2);

  if (param_4 != 0) {

    vog_LogMessage("C:\\vog\\1_code\\palantir\\arda2\\storage\\stoChunk.cpp",0x179,3,

                   "Unimplemented code reached");

  }

  *(uint8_t *)(param_2 + 0x1012) = 1;

  ExceptionList = pvStack_c;

  return param_2;

}
