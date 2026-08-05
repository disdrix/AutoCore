// =============================================================================
// VOGEnvironmentSector
// -----------------------------------------------------------------------------
// Stable ID: aa_0048edc0
// Address:   0x0048edc0  (autoassault.exe, image base 0x400000)
// System:    unknown
// Generated: 2026-07-23 from raw capture (scaffold; refine for important units)
// Exactness: Behavior-preserving rewrite of decompiler control flow. Not modernization.
// Bit-for-bit vs retail EXE: DEFERRED (loaded image may differ slightly).
// =============================================================================

// PURPOSE (auto): Domain alias VOGEnvironmentSector for FUN_0048edc0 @ 0x0048edc0
// Stable ID: aa_0048edc0
// Embedded strings (evidence for future rename):
//   - "Failure on ReCreate() of effTextureImpl %s for CVOGEnvironmentSector backbuffer copy"
//   - "C:\\vog\\1_code\\vog_14_117_branch\\libVOG\\VOGEnvironmentSector.cpp"
//   - "Failure on ReCreate() of effTextureImpl %s for CVOGEnvironmentSector small backbuffer copy"
// Readability: control flow preserved from Ghidra decompile; types tentative.

// READABILITY (auto CF):
//  - Body size: ~51 non-empty decompiler lines.
//  - Control keywords: if×2, for×2, return×1.
//  - Notable callees: FUN_0076cec0×2, FUN_0096a630×2, FUN_0096d0b0×2, ReCreate×2, c_str×2, vog_LogMessage×2, VOGEnvironmentSector.
//  - Strings: "

                         ,pcVar3);

    vog_LogMessage(".
//  - Return sites: 1.

/*
 * Behavioral notes:
 * Plate-driven rename evidence: "C:\vog\1_code\vog_14_117_branch\libVOG\VOGEnvironmentSector.cpp"
 * Domain alias of FUN_0048edc0 (FUN_* retained)
 *
 * - Derived from Ghidra decompile; names prefer Ghidra symbols / plate comments.
 * - Remaining FUN_* / DAT_* identifiers are unresolved pending type recovery.
 * - Runtime / differential verification: OPEN unless matrix says otherwise.
 *
 * Readability pass:
 * - undefinedN widths preserved as fixed-width integers where decompiler width is known.
 * - Control flow and call order preserved from authoritative raw.
 */

uint32_t /* width from decompiler */ __fastcall VOGEnvironmentSector(int param_1)



{

  int iVar1;

  basic_string<char,struct_std::char_traits<char>,class_std::allocator<char>_> *pbVar2;

  char *pcVar3;

  uint32_t /* width from decompiler */ uVar4;

  uint8_t local_4c [4];

  uint8_t local_48 [4];

  basic_string<char,struct_std::char_traits<char>,class_std::allocator<char>_> local_44 [28];

  basic_string<char,struct_std::char_traits<char>,class_std::allocator<char>_> local_28 [28];

  void *local_c;

  uint8_t *puStack_8;

  uint32_t /* width from decompiler */ local_4;

  

  local_4 = 0xffffffff;

  puStack_8 = &LAB_009a0802;

  local_c = ExceptionList;

  ExceptionList = &local_c;

  if ((*(int *)(*(int *)(param_1 + 0xdc) + 0x30) == 0) &&

     (ExceptionList = &local_c, iVar1 = FUN_0096d0b0(), iVar1 < 0)) {

    pbVar2 = (basic_string<char,struct_std::char_traits<char>,class_std::allocator<char>_> *)

             FUN_0096a630(local_44);

    local_4 = 0;

    pcVar3 = std::basic_string<char,struct_std::char_traits<char>,class_std::allocator<char>_>::

             c_str(pbVar2);

    uVar4 = FUN_0076cec0(local_4c,

                         "Failure on ReCreate() of effTextureImpl %s for CVOGEnvironmentSector backbuffer copy"

                         ,pcVar3);

    vog_LogMessage("C:\\vog\\1_code\\vog_14_117_branch\\libVOG\\VOGEnvironmentSector.cpp",0x3ef,5,

                   uVar4);

    local_4 = 0xffffffff;

    std::basic_string<char,struct_std::char_traits<char>,class_std::allocator<char>_>::

    ~basic_string<char,struct_std::char_traits<char>,class_std::allocator<char>_>(local_44);

  }

  if ((*(int *)(*(int *)(param_1 + 0xe0) + 0x30) == 0) && (iVar1 = FUN_0096d0b0(), iVar1 < 0)) {

    pbVar2 = (basic_string<char,struct_std::char_traits<char>,class_std::allocator<char>_> *)

             FUN_0096a630(local_28);

    local_4 = 1;

    pcVar3 = std::basic_string<char,struct_std::char_traits<char>,class_std::allocator<char>_>::

             c_str(pbVar2);

    uVar4 = FUN_0076cec0(local_48,

                         "Failure on ReCreate() of effTextureImpl %s for CVOGEnvironmentSector small backbuffer copy"

                         ,pcVar3);

    vog_LogMessage("C:\\vog\\1_code\\vog_14_117_branch\\libVOG\\VOGEnvironmentSector.cpp",0x3fa,5,

                   uVar4);

    local_4 = 0xffffffff;

    std::basic_string<char,struct_std::char_traits<char>,class_std::allocator<char>_>::

    ~basic_string<char,struct_std::char_traits<char>,class_std::allocator<char>_>(local_28);

  }

  ExceptionList = local_c;

  return 0;

}
