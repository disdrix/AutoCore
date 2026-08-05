// =============================================================================
// FUN_00980160
// -----------------------------------------------------------------------------
// Stable ID: aa_00980160
// Address:   0x00980160  (autoassault.exe, image base 0x400000)
// System:    unknown
// Generated: 2026-07-23 from raw capture (scaffold; refine for important units)
// Exactness: Behavior-preserving rewrite of decompiler control flow. Not modernization.
// Bit-for-bit vs retail EXE: DEFERRED (loaded image may differ slightly).
// =============================================================================

// PURPOSE (auto): Scaffold unit for FUN_00980160 @ 0x00980160
// Stable ID: aa_00980160
// No high-value strings recovered; name via xrefs/callers in follow-up.
// Readability: control flow preserved from Ghidra decompile; types tentative.

// READABILITY (auto CF):
//  - Body size: ~38 non-empty decompiler lines.
//  - Control keywords: return×1.
//  - Notable callees: FUN_00401c50, FUN_00401d30, FUN_00402040, FUN_00980160.
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

void FUN_00980160(int param_1)



{

  uint32_t /* width from decompiler */ uVar1;

  basic_string<char,struct_std::char_traits<char>,class_std::allocator<char>_> *unaff_ESI;

  uint8_t local_71 [9];

  basic_string<char,struct_std::char_traits<char>,class_std::allocator<char>_> local_68 [28];

  basic_string<char,struct_std::char_traits<char>,class_std::allocator<char>_> local_4c [32];

  basic_string<char,struct_std::char_traits<char>,class_std::allocator<char>_> local_2c [32];

  void *local_c;

  uint8_t *puStack_8;

  int local_4;

  

  local_4 = 0xffffffff;

  puStack_8 = &LAB_009ac705;

  local_c = ExceptionList;

  local_71[0] = 0;

  ExceptionList = &local_c;

  std::basic_string<char,struct_std::char_traits<char>,class_std::allocator<char>_>::find

            (unaff_ESI,")",0);

  uVar1 = std::basic_string<char,struct_std::char_traits<char>,class_std::allocator<char>_>::substr

                    (unaff_ESI,(uint)local_68,0);

  local_4 = 0;

  FUN_00401d30(local_2c,uVar1,local_71);

  local_4._0_1_ = 1;

  FUN_00402040(local_4c);

  local_4._0_1_ = 2;

  FUN_00401c50(param_1 + 0xc);

  local_4._0_1_ = 1;

  std::basic_string<char,struct_std::char_traits<char>,class_std::allocator<char>_>::

  ~basic_string<char,struct_std::char_traits<char>,class_std::allocator<char>_>(local_4c);

  local_4 = (uint)local_4._1_3_ << 8;

  std::basic_string<char,struct_std::char_traits<char>,class_std::allocator<char>_>::

  ~basic_string<char,struct_std::char_traits<char>,class_std::allocator<char>_>(local_2c);

  local_4 = 0xffffffff;

  std::basic_string<char,struct_std::char_traits<char>,class_std::allocator<char>_>::

  ~basic_string<char,struct_std::char_traits<char>,class_std::allocator<char>_>(local_68);

  ExceptionList = local_c;

  return;

}
