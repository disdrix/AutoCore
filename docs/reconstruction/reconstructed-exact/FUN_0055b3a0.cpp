// =============================================================================
// FUN_0055b3a0
// -----------------------------------------------------------------------------
// Stable ID: aa_0055b3a0
// Address:   0x0055b3a0  (autoassault.exe, image base 0x400000)
// System:    unknown
// Generated: 2026-07-23 from raw capture (scaffold; refine for important units)
// Exactness: Behavior-preserving rewrite of decompiler control flow. Not modernization.
// Bit-for-bit vs retail EXE: DEFERRED (loaded image may differ slightly).
// =============================================================================

// PURPOSE (auto): Scaffold unit for FUN_0055b3a0 @ 0x0055b3a0
// Stable ID: aa_0055b3a0
// Embedded strings (evidence for future rename):
//   - "vector<T> too long"
// Readability: control flow preserved from Ghidra decompile; types tentative.

// READABILITY (auto CF):
//  - Body size: ~26 non-empty decompiler lines.
//  - Control keywords: return×1.
//  - Notable callees: FUN_0055b3a0, _CxxThrowException, exception::exception.
//  - Strings: "vector<T> too long".
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

void FUN_0055b3a0(void)



{

  basic_string<char,struct_std::char_traits<char>,class_std::allocator<char>_> local_50 [28];

  undefined **local_34 [3];

  basic_string<char,struct_std::char_traits<char>,class_std::allocator<char>_> local_28 [28];

  void *pvStack_c;

  uint8_t *puStack_8;

  int local_4;

  

  local_4 = 0xffffffff;

  puStack_8 = &LAB_009a4852;

  pvStack_c = ExceptionList;

  ExceptionList = &pvStack_c;

  std::basic_string<char,struct_std::char_traits<char>,class_std::allocator<char>_>::

  basic_string<char,struct_std::char_traits<char>,class_std::allocator<char>_>

            (local_50,"vector<T> too long");

  local_4 = 0;

  exception::exception((exception *)local_34);

  local_4._0_1_ = 1;

  local_34[0] = &PTR_FUN_009c7628;

  std::basic_string<char,struct_std::char_traits<char>,class_std::allocator<char>_>::

  basic_string<char,struct_std::char_traits<char>,class_std::allocator<char>_>(local_28,local_50);

  local_4 = (uint)local_4._1_3_ << 8;

  local_34[0] = &PTR_FUN_009c7634;

                    /* WARNING: Subroutine does not return */

  _CxxThrowException(local_34,(ThrowInfo *)&DAT_00acc388);

}
