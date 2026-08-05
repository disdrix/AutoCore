// READABILITY (auto CF):
//  - Body size: ~76 non-empty decompiler lines.
//  - Control keywords: if×7, return×3.
//  - Notable callees: FUN_00769e40×3, CONCAT31, FUN_00436f10, FUN_0044d400, FUN_0076a200, FUN_0096a7f0, FUN_00989e00, stoChunkReader_EnterChunkScope.
//  - Strings: "C:\\vog\\1_code\\palantir\\palantir\\assets\\assId.cpp"; "Invalid tag unserializing assId".
//  - Return sites: 3.

// =============================================================================
// Named_assId
// -----------------------------------------------------------------------------
// Stable ID: aa_0096a7f0
// Address:   0x0096a7f0  (autoassault.exe, image base 0x400000)
// System:    unknown
// Generated: 2026-07-23 from raw capture (scaffold; refine for important units)
// Exactness: Behavior-preserving rewrite of decompiler control flow. Not modernization.
// Bit-for-bit vs retail EXE: DEFERRED (loaded image may differ slightly).
// =============================================================================

/*
 * Behavioral notes:
 * String-driven rename evidence: "assId"
 *
 * - Derived from Ghidra decompile; names prefer Ghidra symbols / plate comments.
 * - Remaining FUN_* / DAT_* identifiers are unresolved pending type recovery.
 * - Runtime / differential verification: OPEN unless matrix says otherwise.
 *
 * Readability pass:
 * - undefinedN widths preserved as fixed-width integers where decompiler width is known.
 * - Control flow and call order preserved from authoritative raw.
 */

uint32_t /* width from decompiler */ Named_assId(uint32_t /* width from decompiler */ *param_1,int param_2)



{

  uint32_t /* width from decompiler */ *puVar1;

  uint32_t /* width from decompiler */ *puVar2;

  uint32_t /* width from decompiler */ *puVar3;

  uint8_t local_44 [4];

  uint8_t local_40 [12];

  char local_34;

  int local_2c;

  basic_string<char,struct_std::char_traits<char>,class_std::allocator<char>_> local_28 [4];

  uint32_t /* width from decompiler */ **local_24 [5];

  uint local_10;

  void *local_c;

  uint8_t *puStack_8;

  uint local_4;

  

  local_4 = 0xffffffff;

  puStack_8 = &LAB_009b1a37;

  local_c = ExceptionList;

  ExceptionList = &local_c;

  stoChunkReader_EnterChunkScope(param_2);

  local_4 = 0;

  if (local_2c != 1) {

    vog_LogMessage("C:\\vog\\1_code\\palantir\\palantir\\assets\\assId.cpp",0x9e,3,

                   "Invalid tag unserializing assId");

    local_4 = 0xffffffff;

    if (local_34 != '\0') {

      FUN_00769e40();

    }

    ExceptionList = local_c;

    return 0xffffffff;

  }

  std::basic_string<char,struct_std::char_traits<char>,class_std::allocator<char>_>::

  basic_string<char,struct_std::char_traits<char>,class_std::allocator<char>_>(local_28);

  local_4 = CONCAT31(local_4._1_3_,1);

  if (*(int *)(param_2 + 0x4044) == 0) {

    FUN_00436f10();

  }

  else {

    FUN_0076a200();

  }

  if (*(int *)(param_2 + 0x402c) < 0) {

    local_4 = local_4 & 0xffffff00;

    std::basic_string<char,struct_std::char_traits<char>,class_std::allocator<char>_>::

    ~basic_string<char,struct_std::char_traits<char>,class_std::allocator<char>_>(local_28);

    local_4 = 0xffffffff;

    if (local_34 != '\0') {

      FUN_00769e40();

    }

    ExceptionList = local_c;

    return 0xffffffff;

  }

  puVar1 = (uint32_t /* width from decompiler */ *)

           std::basic_string<char,struct_std::char_traits<char>,class_std::allocator<char>_>::begin

                     (local_28);

  puVar2 = (uint32_t /* width from decompiler */ *)

           std::basic_string<char,struct_std::char_traits<char>,class_std::allocator<char>_>::end

                     (local_28);

  puVar3 = (uint32_t /* width from decompiler */ *)

           std::basic_string<char,struct_std::char_traits<char>,class_std::allocator<char>_>::begin

                     (local_28);

  FUN_0044d400(local_44,*puVar3,*puVar2,*puVar1,tolower_exref);

  if (local_10 < 0x10) {

    local_24[0] = local_24;

  }

  puVar1 = (uint32_t /* width from decompiler */ *)FUN_00989e00(local_40,local_24[0]);

  *param_1 = *puVar1;

  local_4 = local_4 & 0xffffff00;

  std::basic_string<char,struct_std::char_traits<char>,class_std::allocator<char>_>::

  ~basic_string<char,struct_std::char_traits<char>,class_std::allocator<char>_>(local_28);

  local_4 = 0xffffffff;

  if (local_34 != '\0') {

    FUN_00769e40();

  }

  ExceptionList = local_c;

  return 0;

}
