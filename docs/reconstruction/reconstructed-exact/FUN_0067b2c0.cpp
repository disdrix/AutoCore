// =============================================================================
// FUN_0067b2c0
// -----------------------------------------------------------------------------
// Stable ID: aa_0067b2c0
// Address:   0x0067b2c0  (autoassault.exe, image base 0x400000)
// System:    unknown
// Generated: 2026-07-23 from raw capture (scaffold; refine for important units)
// Exactness: Behavior-preserving rewrite of decompiler control flow. Not modernization.
// Bit-for-bit vs retail EXE: DEFERRED (loaded image may differ slightly).
// =============================================================================

// PURPOSE (auto): Scaffold unit for FUN_0067b2c0 @ 0x0067b2c0
// Stable ID: aa_0067b2c0
// No high-value strings recovered; name via xrefs/callers in follow-up.
// Readability: control flow preserved from Ghidra decompile; types tentative.

// READABILITY (auto CF):
//  - Body size: ~46 non-empty decompiler lines.
//  - Control keywords: if×2, return×2.
//  - Notable callees: FUN_0067b1d0, FUN_0067b2c0, atoi.
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

uint32_t /* width from decompiler */

FUN_0067b2c0(basic_string<char,struct_std::char_traits<char>,class_std::allocator<char>_> *param_1,

            uint32_t /* width from decompiler */ param_2)



{

  uint uVar1;

  int iVar2;

  uint32_t /* width from decompiler */ uVar3;

  char local_48 [4];

  basic_string<char,struct_std::char_traits<char>,class_std::allocator<char>_> local_44 [4];

  char **local_40 [5];

  uint local_2c;

  basic_string<char,struct_std::char_traits<char>,class_std::allocator<char>_> local_28 [28];

  void *local_c;

  uint8_t *puStack_8;

  int local_4;

  

  local_4 = 0xffffffff;

  puStack_8 = &LAB_009a95d2;

  local_c = ExceptionList;

  local_48[0] = ':';

  ExceptionList = &local_c;

  uVar1 = std::basic_string<char,struct_std::char_traits<char>,class_std::allocator<char>_>::find

                    (param_1,local_48,0,1);

  if (uVar1 == *(uint *)npos_exref) {

    ExceptionList = local_c;

    return 0xffffffff;

  }

  std::basic_string<char,struct_std::char_traits<char>,class_std::allocator<char>_>::substr

            (param_1,(uint)local_28,0);

  local_4 = 0;

  std::basic_string<char,struct_std::char_traits<char>,class_std::allocator<char>_>::substr

            (param_1,(uint)local_44,uVar1 + 1);

  local_4._0_1_ = 1;

  if (local_2c < 0x10) {

    local_40[0] = (char **)local_40;

  }

  iVar2 = atoi((char *)local_40[0]);

  uVar3 = FUN_0067b1d0(local_28,iVar2,param_2);

  local_4 = (uint)local_4._1_3_ << 8;

  std::basic_string<char,struct_std::char_traits<char>,class_std::allocator<char>_>::

  ~basic_string<char,struct_std::char_traits<char>,class_std::allocator<char>_>(local_44);

  local_4 = 0xffffffff;

  std::basic_string<char,struct_std::char_traits<char>,class_std::allocator<char>_>::

  ~basic_string<char,struct_std::char_traits<char>,class_std::allocator<char>_>(local_28);

  ExceptionList = local_c;

  return uVar3;

}
