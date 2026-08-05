// =============================================================================
// FUN_0095dae0
// -----------------------------------------------------------------------------
// Stable ID: aa_0095dae0
// Address:   0x0095dae0  (autoassault.exe, image base 0x400000)
// System:    unknown
// Generated: 2026-07-23 from raw capture (scaffold; refine for important units)
// Exactness: Behavior-preserving rewrite of decompiler control flow. Not modernization.
// Bit-for-bit vs retail EXE: DEFERRED (loaded image may differ slightly).
// =============================================================================

// PURPOSE (auto): Scaffold unit for FUN_0095dae0 @ 0x0095dae0
// Stable ID: aa_0095dae0
// No high-value strings recovered; name via xrefs/callers in follow-up.
// Readability: control flow preserved from Ghidra decompile; types tentative.

// READABILITY (auto CF):
//  - Body size: ~74 non-empty decompiler lines.
//  - Control keywords: if×9, return×4.
//  - Notable callees: FUN_00437050×2, FUN_00768760×2, FUN_00769e40×2, CONCAT31, FUN_00436f10, FUN_0044c270, FUN_0076a200, FUN_0076a900.
//  - Return sites: 4.

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

uint32_t /* width from decompiler */ __fastcall

FUN_0095dae0(uint32_t /* width from decompiler */ param_1,int param_2,uint32_t /* width from decompiler */ *param_3,uint32_t /* width from decompiler */ param_4)



{

  int iVar1;

  uint32_t /* width from decompiler */ *puVar2;

  uint32_t /* width from decompiler */ uVar3;

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

  puStack_8 = &LAB_009b1f79;

  local_c = ExceptionList;

  ExceptionList = &local_c;

  FUN_0044c270(0,0);

  iVar1 = FUN_0076a900();

  if (iVar1 != 0x4e4f4445) {

    if (*(int *)(param_2 + 0x4044) == 0) {

      uVar3 = FUN_00437050(param_4);

      ExceptionList = local_c;

      return uVar3;

    }

    uVar3 = FUN_00768760(param_4);

    ExceptionList = local_c;

    return uVar3;

  }

  stoChunkReader_EnterChunkScope(param_2);

  local_4 = 0;

  if (local_2c != 1) {

    if (local_2c != 2) {

      local_4 = 0xffffffff;

      if (local_34 != '\0') {

        FUN_00769e40();

      }

      ExceptionList = local_c;

      return 0xffffffff;

    }

    FUN_0095d8f0(param_1);

  }

  std::basic_string<char,struct_std::char_traits<char>,class_std::allocator<char>_>::

  basic_string<char,struct_std::char_traits<char>,class_std::allocator<char>_>(local_28);

  local_4 = CONCAT31(local_4._1_3_,1);

  if (*(int *)(param_2 + 0x4044) == 0) {

    FUN_00437050(param_4);

  }

  else {

    FUN_00768760(param_4);

  }

  if (*(int *)(param_2 + 0x4044) == 0) {

    FUN_00436f10();

  }

  else {

    FUN_0076a200();

  }

  if (local_10 < 0x10) {

    local_24[0] = local_24;

  }

  puVar2 = (uint32_t /* width from decompiler */ *)FUN_00989e00(local_40,local_24[0]);

  *param_3 = *puVar2;

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
