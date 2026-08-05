// =============================================================================
// Named_CalleeOf_Named_assPreloader_00970910
// -----------------------------------------------------------------------------
// Stable ID: aa_00970910
// Callee of Named_assPreloader
// Address:   0x00970910  (autoassault.exe, image base 0x400000)
// System:    unknown
// Generated: 2026-07-23 from raw capture (scaffold; refine for important units)
// Exactness: Behavior-preserving rewrite of decompiler control flow. Not modernization.
// Bit-for-bit vs retail EXE: DEFERRED (loaded image may differ slightly).
// =============================================================================

// PURPOSE (auto): Called from Named_assPreloader: callee helper. Evidence string: ".geo". Supports parent flow (not a free-standing entry point).
// Embedded strings (evidence):
//   - ".geo"
//   - ".dds"
//   - ".ogg"
//   - ".xml"
//   - "OTHER"
// Readability: control flow preserved from Ghidra decompile; types tentative.

// READABILITY (auto CF):
//  - Body size: ~66 non-empty decompiler lines.
//  - Control keywords: if×5, return×2, while×1.
//  - Notable callees: CONCAT31, FUN_00970910, _atexit, strstr.
//  - Strings: ".geo"; ".dds"; ".ogg"; ".xml".
//  - Return sites: 2.

/*
 * Behavioral notes:
 * Callee of Named_assPreloader
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

int Named_CalleeOf_Named_assPreloader_00970910(int *param_1)



{

  char *_Str;

  char *pcVar1;

  char *pcVar2;

  int iVar3;

  void *local_c;

  uint8_t *puStack_8;

  uint32_t /* width from decompiler */ local_4;

  

  local_4 = 0xffffffff;

  puStack_8 = &LAB_009ab8b5;

  local_c = ExceptionList;

  ExceptionList = &local_c;

  if ((DAT_00d1f87c & 1) == 0) {

    DAT_00d1f87c = DAT_00d1f87c | 1;

    local_4 = 0;

    ExceptionList = &local_c;

    std::basic_string<char,struct_std::char_traits<char>,class_std::allocator<char>_>::

    basic_string<char,struct_std::char_traits<char>,class_std::allocator<char>_>

              ((basic_string<char,struct_std::char_traits<char>,class_std::allocator<char>_> *)

               &DAT_00d1f7f0,".geo");

    local_4._0_1_ = 1;

    std::basic_string<char,struct_std::char_traits<char>,class_std::allocator<char>_>::

    basic_string<char,struct_std::char_traits<char>,class_std::allocator<char>_>

              ((basic_string<char,struct_std::char_traits<char>,class_std::allocator<char>_> *)

               &DAT_00d1f80c,".dds");

    local_4._0_1_ = 2;

    std::basic_string<char,struct_std::char_traits<char>,class_std::allocator<char>_>::

    basic_string<char,struct_std::char_traits<char>,class_std::allocator<char>_>

              ((basic_string<char,struct_std::char_traits<char>,class_std::allocator<char>_> *)

               &DAT_00d1f828,".ogg");

    local_4._0_1_ = 3;

    std::basic_string<char,struct_std::char_traits<char>,class_std::allocator<char>_>::

    basic_string<char,struct_std::char_traits<char>,class_std::allocator<char>_>

              ((basic_string<char,struct_std::char_traits<char>,class_std::allocator<char>_> *)

               &DAT_00d1f844,".xml");

    local_4 = CONCAT31(local_4._1_3_,4);

    std::basic_string<char,struct_std::char_traits<char>,class_std::allocator<char>_>::

    basic_string<char,struct_std::char_traits<char>,class_std::allocator<char>_>

              ((basic_string<char,struct_std::char_traits<char>,class_std::allocator<char>_> *)

               &DAT_00d1f860,"OTHER");

    _atexit((_func_4879 *)&LAB_009c3320);

  }

  iVar3 = 0;

  pcVar2 = (char *)&DAT_00d1f7f4;

  while( true ) {

    pcVar1 = pcVar2;

    if (0xf < *(uint *)(pcVar2 + 0x14)) {

      pcVar1 = *(char **)pcVar2;

    }

    _Str = (char *)*param_1;

    if ((char *)*param_1 == (char *)0x0) {

      _Str = PTR_DAT_00afa2bc;

    }

    pcVar1 = strstr(_Str,pcVar1);

    if (pcVar1 != (char *)0x0) break;

    pcVar2 = pcVar2 + 0x1c;

    iVar3 = iVar3 + 1;

    if (0xd1f863 < (int)pcVar2) {

      ExceptionList = local_c;

      return 4;

    }

  }

  ExceptionList = local_c;

  return iVar3;

}
