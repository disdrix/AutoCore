// READABILITY (auto CF):
//  - Body size: ~45 non-empty decompiler lines.
//  - Control keywords: if×3, return×1.
//  - Notable callees: D3DXSaveTextureToFileA, FUN_0096bf90, vog_LogMessage.
//  - Strings: ".bmp"; ".dds"; ",

                   0x28f,3,".
//  - Return sites: 1.

// =============================================================================
// Named_effTextureImpl_0096bf90
// -----------------------------------------------------------------------------
// Stable ID: aa_0096bf90
// Address:   0x0096bf90  (autoassault.exe, image base 0x400000)
// System:    unknown
// Generated: 2026-07-23 from raw capture (scaffold; refine for important units)
// Exactness: Behavior-preserving rewrite of decompiler control flow. Not modernization.
// Bit-for-bit vs retail EXE: DEFERRED (loaded image may differ slightly).
// =============================================================================

/*
 * Behavioral notes:
 * String-driven rename evidence: "effTextureImpl"
 *
 * - Derived from Ghidra decompile; names prefer Ghidra symbols / plate comments.
 * - Remaining FUN_* / DAT_* identifiers are unresolved pending type recovery.
 * - Runtime / differential verification: OPEN unless matrix says otherwise.
 *
 * Readability pass:
 * - undefinedN widths preserved as fixed-width integers where decompiler width is known.
 * - Control flow and call order preserved from authoritative raw.
 */

int __thiscall

Named_effTextureImpl_0096bf90(int param_1,

            basic_string<char,struct_std::char_traits<char>,class_std::allocator<char>_> *param_2)



{

  int iVar1;

  int unaff_EDI;

  char *pcVar2;

  basic_string<char,struct_std::char_traits<char>,class_std::allocator<char>_> local_28 [4];

  uint32_t /* width from decompiler */ ***local_24 [5];

  uint local_10;

  void *local_c;

  uint8_t *puStack_8;

  uint32_t /* width from decompiler */ local_4;

  

  local_4 = 0xffffffff;

  puStack_8 = &LAB_009ad944;

  local_c = ExceptionList;

  ExceptionList = &local_c;

  std::basic_string<char,struct_std::char_traits<char>,class_std::allocator<char>_>::

  basic_string<char,struct_std::char_traits<char>,class_std::allocator<char>_>(local_28,param_2);

  local_4 = 0;

  if (unaff_EDI == 0) {

    pcVar2 = ".bmp";

  }

  else {

    pcVar2 = ".dds";

  }

  std::basic_string<char,struct_std::char_traits<char>,class_std::allocator<char>_>::operator+=

            (local_28,pcVar2);

  if ((*(uint *)(param_1 + 0x2c) & 0xf) == 1) {

    if (local_10 < 0x10) {

      local_24[0] = local_24;

    }

    iVar1 = D3DXSaveTextureToFileA(local_24[0],unaff_EDI,*(uint32_t /* width from decompiler */ *)(param_1 + 0x10),0);

  }

  else {

    vog_LogMessage("C:\\vog\\1_code\\palantir\\palantir\\graphics\\Effects\\effTextureImpl.cpp",

                   0x28f,3,"Unimplemented code reached");

    iVar1 = -1;

  }

  local_4 = 0xffffffff;

  std::basic_string<char,struct_std::char_traits<char>,class_std::allocator<char>_>::

  ~basic_string<char,struct_std::char_traits<char>,class_std::allocator<char>_>(local_28);

  ExceptionList = local_c;

  return (-1 < iVar1) - 1;

}
