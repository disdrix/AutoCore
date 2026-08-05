// =============================================================================
// FUN_008075f0
// -----------------------------------------------------------------------------
// Stable ID: aa_008075f0
// Address:   0x008075f0  (autoassault.exe, image base 0x400000)
// System:    unknown
// Generated: 2026-07-23 from raw capture (scaffold; refine for important units)
// Exactness: Behavior-preserving rewrite of decompiler control flow. Not modernization.
// Bit-for-bit vs retail EXE: DEFERRED (loaded image may differ slightly).
// =============================================================================

// PURPOSE (auto): Scaffold unit for FUN_008075f0 @ 0x008075f0
// Stable ID: aa_008075f0
// Embedded strings (evidence for future rename):
//   - "172.31.10.195"
// Readability: control flow preserved from Ghidra decompile; types tentative.

// READABILITY (auto CF):
//  - Body size: ~39 non-empty decompiler lines.
//  - Control keywords: if×2, return×1.
//  - Notable callees: FUN_0067b070, FUN_0067b110, FUN_0067b1d0, FUN_00729200, FUN_008075f0.
//  - Strings: "172.31.10.195".
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

uint32_t /* width from decompiler */ __thiscall FUN_008075f0(char *param_1,int param_2)



{

  uint32_t /* width from decompiler */ uVar1;

  basic_string<char,struct_std::char_traits<char>,class_std::allocator<char>_> local_28 [28];

  void *local_c;

  uint8_t *puStack_8;

  int local_4;

  

  local_4 = 0xffffffff;

  puStack_8 = &LAB_009b027c;

  local_c = ExceptionList;

  ExceptionList = &local_c;

  FUN_0067b070();

  local_4 = 0;

  if (param_1 == (char *)0x0) {

    std::basic_string<char,struct_std::char_traits<char>,class_std::allocator<char>_>::

    basic_string<char,struct_std::char_traits<char>,class_std::allocator<char>_>

              (local_28,"172.31.10.195");

    local_4._0_1_ = 2;

  }

  else {

    std::basic_string<char,struct_std::char_traits<char>,class_std::allocator<char>_>::

    basic_string<char,struct_std::char_traits<char>,class_std::allocator<char>_>(local_28,param_1);

    local_4._0_1_ = 1;

  }

  FUN_0067b1d0(local_28,0x83a,0);

  local_4 = (uint)local_4._1_3_ << 8;

  std::basic_string<char,struct_std::char_traits<char>,class_std::allocator<char>_>::

  ~basic_string<char,struct_std::char_traits<char>,class_std::allocator<char>_>(local_28);

  if (*(int *)(param_2 + 0xcc) == 0) {

    uVar1 = 0xffffffff;

  }

  else {

    uVar1 = FUN_00729200();

  }

  local_4 = 0xffffffff;

  FUN_0067b110();

  ExceptionList = local_c;

  return uVar1;

}
