// =============================================================================
// FUN_00735810
// -----------------------------------------------------------------------------
// Stable ID: aa_00735810
// Address:   0x00735810  (autoassault.exe, image base 0x400000)
// System:    unknown
// Generated: 2026-07-23 from raw capture (scaffold; refine for important units)
// Exactness: Behavior-preserving rewrite of decompiler control flow. Not modernization.
// Bit-for-bit vs retail EXE: DEFERRED (loaded image may differ slightly).
// =============================================================================

// PURPOSE (auto): Scaffold unit for FUN_00735810 @ 0x00735810
// Stable ID: aa_00735810
// No high-value strings recovered; name via xrefs/callers in follow-up.
// Readability: control flow preserved from Ghidra decompile; types tentative.

// READABILITY (auto CF):
//  - Body size: ~47 non-empty decompiler lines.
//  - Control keywords: for×2, return×1.
//  - Notable callees: CONCAT31, FUN_00735810.
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

basic_string<char,struct_std::char_traits<char>,class_std::allocator<char>_> *

FUN_00735810(basic_string<char,struct_std::char_traits<char>,class_std::allocator<char>_> *param_1,

            uint32_t /* width from decompiler */ param_2,uint32_t /* width from decompiler */ param_3)



{

  int iVar1;

  void *unaff_ESI;

  basic_string<char,struct_std::char_traits<char>,class_std::allocator<char>_> *pbVar2;

  void *pvStack_c;

  uint8_t *puStack_8;

  uint32_t /* width from decompiler */ local_4;

  

  local_4 = 0xffffffff;

  puStack_8 = &LAB_009abfa2;

  pvStack_c = ExceptionList;

  ExceptionList = &pvStack_c;

  std::basic_string<char,struct_std::char_traits<char>,class_std::allocator<char>_>::

  basic_string<char,struct_std::char_traits<char>,class_std::allocator<char>_>(param_1);

  local_4 = 0;

  std::basic_string<char,struct_std::char_traits<char>,class_std::allocator<char>_>::

  basic_string<char,struct_std::char_traits<char>,class_std::allocator<char>_>(param_1 + 0x1c);

  *(uint32_t /* width from decompiler */ *)(param_1 + 0x38) = 0;

  *(uint32_t /* width from decompiler */ *)(param_1 + 0x3c) = 0;

  *(uint32_t /* width from decompiler */ *)(param_1 + 0x40) = 0;

  *(uint32_t /* width from decompiler */ *)(param_1 + 0x44) = 0;

  *(uint32_t /* width from decompiler */ *)(param_1 + 0x48) = param_2;

  *(uint32_t /* width from decompiler */ *)(param_1 + 0x4c) = param_3;

  *(uint32_t /* width from decompiler */ *)(param_1 + 0x710) = 0;

  *(uint32_t /* width from decompiler */ *)(param_1 + 0x714) = 0;

  *(uint32_t /* width from decompiler */ *)(param_1 + 0x718) = 0;

  local_4 = CONCAT31(local_4._1_3_,2);

  (**(code **)(**(int **)(param_1 + 0x48) + 4))(*(int **)(param_1 + 0x48));

  pbVar2 = param_1 + 0x50;

  for (iVar1 = 0x113; iVar1 != 0; iVar1 = iVar1 + -1) {

    *(uint32_t /* width from decompiler */ *)pbVar2 = 0;

    pbVar2 = pbVar2 + 4;

  }

  pbVar2 = param_1 + 0x4ac;

  for (iVar1 = 0x4c; iVar1 != 0; iVar1 = iVar1 + -1) {

    *(uint32_t /* width from decompiler */ *)pbVar2 = 0;

    pbVar2 = pbVar2 + 4;

  }

  *(uint32_t /* width from decompiler */ *)(param_1 + 0x49c) = 0;

  *(uint32_t /* width from decompiler */ *)(param_1 + 0x4a0) = 0;

  *(uint32_t /* width from decompiler */ *)(param_1 + 0x4a4) = 0;

  *(uint32_t /* width from decompiler */ *)(param_1 + 0x4a8) = 0;

  ExceptionList = unaff_ESI;

  return param_1;

}
