// =============================================================================
// FUN_009800a0
// -----------------------------------------------------------------------------
// Stable ID: aa_009800a0
// Address:   0x009800a0  (autoassault.exe, image base 0x400000)
// System:    unknown
// Generated: 2026-07-23 from raw capture (scaffold; refine for important units)
// Exactness: Behavior-preserving rewrite of decompiler control flow. Not modernization.
// Bit-for-bit vs retail EXE: DEFERRED (loaded image may differ slightly).
// =============================================================================

// PURPOSE (auto): Scaffold unit for FUN_009800a0 @ 0x009800a0
// Stable ID: aa_009800a0
// Embedded strings (evidence for future rename):
//   - "%s(%d)"
// Readability: control flow preserved from Ghidra decompile; types tentative.

// READABILITY (auto CF):
//  - Body size: ~29 non-empty decompiler lines.
//  - Control keywords: if×1, return×1.
//  - Notable callees: FUN_00430ce0, FUN_009800a0, _snprintf, s.
//  - Strings: "%s(%d)".
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

uint32_t /* width from decompiler */ __thiscall FUN_009800a0(int param_1,uint32_t /* width from decompiler */ param_2,uint32_t /* width from decompiler */ param_3)



{

  int iVar1;

  basic_string<char,struct_std::char_traits<char>,class_std::allocator<char>_> local_230 [28];

  char local_214 [520];

  void *local_c;

  uint8_t *puStack_8;

  uint32_t /* width from decompiler */ local_4;

  

  local_4 = 0xffffffff;

  puStack_8 = &LAB_009abd50;

  local_c = ExceptionList;

  ExceptionList = &local_c;

  _snprintf(local_214,0x208,"%s(%d)",param_2,param_3);

  std::basic_string<char,struct_std::char_traits<char>,class_std::allocator<char>_>::

  basic_string<char,struct_std::char_traits<char>,class_std::allocator<char>_>(local_230,local_214);

  local_4 = 0;

  iVar1 = FUN_00430ce0(local_230);

  if (iVar1 != *(int *)(param_1 + 0x10)) {

    std::operator<<char,struct_std::char_traits<char>,class_std::allocator<char>_>

              (local_230,

               (basic_string<char,struct_std::char_traits<char>,class_std::allocator<char>_> *)

               (iVar1 + 0xc));

  }

  local_4 = 0xffffffff;

  std::basic_string<char,struct_std::char_traits<char>,class_std::allocator<char>_>::

  ~basic_string<char,struct_std::char_traits<char>,class_std::allocator<char>_>(local_230);

  ExceptionList = local_c;

  return 1;

}
