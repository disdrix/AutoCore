// =============================================================================
// FUN_009964f0
// -----------------------------------------------------------------------------
// Stable ID: aa_009964f0
// Address:   0x009964f0  (autoassault.exe, image base 0x400000)
// System:    unknown
// Generated: 2026-07-23 from raw capture (scaffold; refine for important units)
// Exactness: Behavior-preserving rewrite of decompiler control flow. Not modernization.
// Bit-for-bit vs retail EXE: DEFERRED (loaded image may differ slightly).
// =============================================================================

// PURPOSE (auto): Scaffold unit for FUN_009964f0 @ 0x009964f0
// Stable ID: aa_009964f0
// No high-value strings recovered; name via xrefs/callers in follow-up.
// Readability: control flow preserved from Ghidra decompile; types tentative.

// READABILITY (auto CF):
//  - Body size: ~48 non-empty decompiler lines.
//  - Control keywords: if×3, return×2.
//  - Notable callees: FUN_009695c0, FUN_009964f0, stat.
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

uint FUN_009964f0(int *param_1)



{

  char cVar1;

  char *pcVar2;

  int iVar3;

  basic_string<char,struct_std::char_traits<char>,class_std::allocator<char>_> local_4c [4];

  uint32_t /* width from decompiler */ **local_48 [5];

  uint local_34;

  basic_string<char,struct_std::char_traits<char>,class_std::allocator<char>_> local_30 [28];

  uint local_14;

  void *local_c;

  uint8_t *puStack_8;

  int local_4;

  

  local_4 = 0xffffffff;

  puStack_8 = &LAB_009acad0;

  local_c = ExceptionList;

  ExceptionList = &local_c;

  std::basic_string<char,struct_std::char_traits<char>,class_std::allocator<char>_>::

  basic_string<char,struct_std::char_traits<char>,class_std::allocator<char>_>(local_4c);

  local_4 = 0;

  pcVar2 = (char *)*param_1;

  if ((char *)*param_1 == (char *)0x0) {

    pcVar2 = PTR_DAT_00afa2bc;

  }

  std::basic_string<char,struct_std::char_traits<char>,class_std::allocator<char>_>::

  basic_string<char,struct_std::char_traits<char>,class_std::allocator<char>_>(local_30,pcVar2);

  local_4._0_1_ = 1;

  cVar1 = FUN_009695c0(DAT_00d1f1fc,local_4c);

  local_4 = (uint)local_4._1_3_ << 8;

  std::basic_string<char,struct_std::char_traits<char>,class_std::allocator<char>_>::

  ~basic_string<char,struct_std::char_traits<char>,class_std::allocator<char>_>(local_30);

  if (cVar1 != '\0') {

    if (local_34 < 0x10) {

      local_48[0] = local_48;

    }

    iVar3 = stat(local_48[0],local_30);

    local_4 = 0xffffffff;

    std::basic_string<char,struct_std::char_traits<char>,class_std::allocator<char>_>::

    ~basic_string<char,struct_std::char_traits<char>,class_std::allocator<char>_>(local_4c);

    ExceptionList = local_c;

    return ~-(uint)(iVar3 != 0) & local_14;

  }

  local_4 = 0xffffffff;

  std::basic_string<char,struct_std::char_traits<char>,class_std::allocator<char>_>::

  ~basic_string<char,struct_std::char_traits<char>,class_std::allocator<char>_>(local_4c);

  ExceptionList = local_c;

  return 0;

}
