// =============================================================================
// FUN_00753f50
// -----------------------------------------------------------------------------
// Stable ID: aa_00753f50
// Address:   0x00753f50  (autoassault.exe, image base 0x400000)
// System:    unknown
// Generated: 2026-07-23 from raw capture (scaffold; refine for important units)
// Exactness: Behavior-preserving rewrite of decompiler control flow. Not modernization.
// Bit-for-bit vs retail EXE: DEFERRED (loaded image may differ slightly).
// =============================================================================

// PURPOSE (auto): Scaffold unit for FUN_00753f50 @ 0x00753f50
// Stable ID: aa_00753f50
// Embedded strings (evidence for future rename):
//   - "%i.%02i.%02i: %s"
//   - "2004/09/23 $"
// Readability: control flow preserved from Ghidra decompile; types tentative.

// READABILITY (auto CF):
//  - Body size: ~27 non-empty decompiler lines.
//  - Control keywords: return×1.
//  - Notable callees: FUN_00753f50, sprintf.
//  - Strings: "%i.%02i.%02i: %s"; "2004/09/23 $".
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

FUN_00753f50(basic_string<char,struct_std::char_traits<char>,class_std::allocator<char>_> *param_1)



{

  basic_string<char,struct_std::char_traits<char>,class_std::allocator<char>_> local_128 [20];

  int local_114;

  char local_10c [256];

  void *local_c;

  uint8_t *puStack_8;

  uint local_4;

  

  local_4 = 0xffffffff;

  puStack_8 = &LAB_009ab57d;

  local_c = ExceptionList;

  ExceptionList = &local_c;

  sprintf(local_10c,"%i.%02i.%02i: %s",1,0x16,1,"2004/09/23 $");

  std::basic_string<char,struct_std::char_traits<char>,class_std::allocator<char>_>::

  basic_string<char,struct_std::char_traits<char>,class_std::allocator<char>_>(local_128,local_10c);

  local_4 = 1;

  std::basic_string<char,struct_std::char_traits<char>,class_std::allocator<char>_>::resize

            (local_128,local_114 - 2);

  std::basic_string<char,struct_std::char_traits<char>,class_std::allocator<char>_>::

  basic_string<char,struct_std::char_traits<char>,class_std::allocator<char>_>(param_1,local_128);

  local_4 = local_4 & 0xffffff00;

  std::basic_string<char,struct_std::char_traits<char>,class_std::allocator<char>_>::

  ~basic_string<char,struct_std::char_traits<char>,class_std::allocator<char>_>(local_128);

  ExceptionList = local_c;

  return param_1;

}
