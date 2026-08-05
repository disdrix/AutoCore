// =============================================================================
// Named_CalleeOf_Named_CalleeOf_Named_CalleeOf_Named_CalleeOf_Nam_006874b0
// -----------------------------------------------------------------------------
// Stable ID: aa_006874b0
// Callee of Named_CalleeOf_Named_CalleeOf_Named_CalleeOf_Named_CalleeOf_Nam
// Address:   0x006874b0  (autoassault.exe, image base 0x400000)
// System:    unknown
// Generated: 2026-07-23 from raw capture (scaffold; refine for important units)
// Exactness: Behavior-preserving rewrite of decompiler control flow. Not modernization.
// Bit-for-bit vs retail EXE: DEFERRED (loaded image may differ slightly).
// =============================================================================

// PURPOSE (auto): Called from Named_CalleeOf_Named_CalleeOf_Named_CalleeOf_Named_CalleeOf_Nam: callee helper with no high-value strings in clean/raw. Role inferred from parent name only; refine when decompile strings or xrefs improve.
// Readability: control flow preserved from Ghidra decompile; types tentative.

// READABILITY (auto CF):
//  - Body size: ~64 non-empty decompiler lines.
//  - Control keywords: if×3, return×1.
//  - Notable callees: CONCAT31×2, FUN_00416490×2, FUN_00416410, FUN_00685b40, FUN_006874b0, _errno, strerror.
//  - Return sites: 1.

/*
 * Behavioral notes:
 * Callee of Named_CalleeOf_Named_CalleeOf_Named_CalleeOf_Named_CalleeOf_Nam
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

uint32_t /* width from decompiler */ * __thiscall Named_CalleeOf_Named_CalleeOf_Named_CalleeOf_Named_CalleeOf_Nam_006874b0(uint32_t /* width from decompiler */ *param_1,uint32_t /* width from decompiler */ param_2,char param_3)



{

  int *piVar1;

  char *pcVar2;

  uint32_t /* width from decompiler */ uVar3;

  uint32_t /* width from decompiler */ uVar4;

  bool bVar5;

  basic_string<char,struct_std::char_traits<char>,class_std::allocator<char>_> local_98 [28];

  basic_string<char,struct_std::char_traits<char>,class_std::allocator<char>_> local_7c [28];

  basic_string<char,struct_std::char_traits<char>,class_std::allocator<char>_> local_60 [28];

  basic_string<char,struct_std::char_traits<char>,class_std::allocator<char>_> local_44 [28];

  basic_string<char,struct_std::char_traits<char>,class_std::allocator<char>_> local_28 [28];

  void *local_c;

  uint8_t *puStack_8;

  uint local_4;

  

  local_4 = 0xffffffff;

  puStack_8 = &LAB_009a9f39;

  local_c = ExceptionList;

  bVar5 = param_3 == '\0';

  if (bVar5) {

    ExceptionList = &local_c;

    uVar3 = std::basic_string<char,struct_std::char_traits<char>,class_std::allocator<char>_>::

            basic_string<char,struct_std::char_traits<char>,class_std::allocator<char>_>

                      (local_60,"");

  }

  else {

    ExceptionList = &local_c;

    piVar1 = _errno();

    pcVar2 = strerror(*piVar1);

    uVar3 = std::basic_string<char,struct_std::char_traits<char>,class_std::allocator<char>_>::

            basic_string<char,struct_std::char_traits<char>,class_std::allocator<char>_>

                      (local_28,pcVar2);

  }

  local_4 = (uint)bVar5;

  uVar4 = FUN_00416490(local_7c,param_2,&DAT_009ead6c);

  local_4 = 2;

  uVar3 = FUN_00416410(local_98,uVar4,uVar3);

  local_4._0_1_ = 3;

  uVar3 = FUN_00416490(local_44,uVar3,&DAT_00a62c94);

  local_4._0_1_ = 4;

  FUN_00685b40(uVar3);

  local_4 = CONCAT31(local_4._1_3_,10);

  std::basic_string<char,struct_std::char_traits<char>,class_std::allocator<char>_>::

  ~basic_string<char,struct_std::char_traits<char>,class_std::allocator<char>_>(local_44);

  local_4 = 9;

  std::basic_string<char,struct_std::char_traits<char>,class_std::allocator<char>_>::

  ~basic_string<char,struct_std::char_traits<char>,class_std::allocator<char>_>(local_98);

  local_4._0_1_ = 8;

  std::basic_string<char,struct_std::char_traits<char>,class_std::allocator<char>_>::

  ~basic_string<char,struct_std::char_traits<char>,class_std::allocator<char>_>(local_7c);

  local_4._0_1_ = 7;

  if (bVar5) {

    std::basic_string<char,struct_std::char_traits<char>,class_std::allocator<char>_>::

    ~basic_string<char,struct_std::char_traits<char>,class_std::allocator<char>_>(local_60);

  }

  local_4 = CONCAT31(local_4._1_3_,6);

  if (!bVar5) {

    std::basic_string<char,struct_std::char_traits<char>,class_std::allocator<char>_>::

    ~basic_string<char,struct_std::char_traits<char>,class_std::allocator<char>_>(local_28);

  }

  *param_1 = &PTR_FUN_009ead64;

  ExceptionList = local_c;

  return param_1;

}
