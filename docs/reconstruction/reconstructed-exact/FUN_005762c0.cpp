// =============================================================================
// FUN_005762c0
// -----------------------------------------------------------------------------
// Stable ID: aa_005762c0
// Address:   0x005762c0  (autoassault.exe, image base 0x400000)
// System:    unknown
// Generated: 2026-07-23 from raw capture (scaffold; refine for important units)
// Exactness: Behavior-preserving rewrite of decompiler control flow. Not modernization.
// Bit-for-bit vs retail EXE: DEFERRED (loaded image may differ slightly).
// =============================================================================

// PURPOSE (auto): Scaffold unit for FUN_005762c0 @ 0x005762c0
// Stable ID: aa_005762c0
// Embedded strings (evidence for future rename):
//   - " \r\n"
//   - "Error:%s code (%x) at location (%p)"
//   - "---------------"
//   - "Version: %d.%d.%d.%d.%d.%d.%d.%d, %d:%d \r\n"
// Readability: control flow preserved from Ghidra decompile; types tentative.

// READABILITY (auto CF):
//  - Body size: ~48 non-empty decompiler lines.
//  - Control keywords: if×3, return×2.
//  - Notable callees: _snprintf×2, CONCAT31, FUN_004cf510, FUN_00520960, FUN_00575c20, FUN_005762c0, FUN_0057640b, FUN_0057644c.
//  - Strings: " \r\n"; "Error:%s code (%x) at location (%p)"; "---------------"; "Version: %d.%d.%d.%d.%d.%d.%d.%d, %d:%d \r\n".
//  - Return sites: 2.

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

void FUN_005762c0(int param_1,int param_2,uint32_t /* width from decompiler */ param_3,uint32_t /* width from decompiler */ param_4,uint32_t /* width from decompiler */ param_5)



{

  char local_47c [1100];

  basic_string<char,struct_std::char_traits<char>,class_std::allocator<char>_> local_30 [28];

  uint8_t *local_14;

  void *pvStack_10;

  uint8_t *puStack_c;

  uint32_t /* width from decompiler */ local_8;

  

  local_8 = 0xffffffff;

  puStack_c = &LAB_009a50a9;

  pvStack_10 = ExceptionList;

  local_14 = &stack0xfffffb78;

  ExceptionList = &pvStack_10;

  std::basic_string<char,struct_std::char_traits<char>,class_std::allocator<char>_>::

  basic_string<char,struct_std::char_traits<char>,class_std::allocator<char>_>(local_30);

  local_8 = 0;

  std::basic_string<char,struct_std::char_traits<char>,class_std::allocator<char>_>::append

            (local_30," \r\n");

  _snprintf(local_47c,0x400,"Error:%s code (%x) at location (%p)",param_3,param_5,param_4);

  std::basic_string<char,struct_std::char_traits<char>,class_std::allocator<char>_>::append

            (local_30,local_47c);

  std::basic_string<char,struct_std::char_traits<char>,class_std::allocator<char>_>::append

            (local_30," \r\n");

  std::basic_string<char,struct_std::char_traits<char>,class_std::allocator<char>_>::append

            (local_30,"---------------");

  std::basic_string<char,struct_std::char_traits<char>,class_std::allocator<char>_>::append

            (local_30," \r\n");

  _snprintf(local_47c,0x400,"Version: %d.%d.%d.%d.%d.%d.%d.%d, %d:%d \r\n",DAT_00b047e0,DAT_00b047e4

            ,DAT_00b047e8,DAT_00b047ec,DAT_00b047f0,DAT_00b047f4,DAT_00b047f8,DAT_00b047fc,0xaf,0);

  std::basic_string<char,struct_std::char_traits<char>,class_std::allocator<char>_>::append

            (local_30,local_47c);

  local_8 = CONCAT31(local_8._1_3_,1);

  if (DAT_00d17958 != 0) {

    FUN_0079e550(local_30);

  }

  if (param_1 != 0) {

    FUN_004cf510(local_30);

  }

  if (param_2 != 0) {

    FUN_00520960(local_30);

    FUN_0057640b();

    return;

  }

  local_8 = 3;

  FUN_00575c20(local_30);

  FUN_0057644c();

  return;

}
