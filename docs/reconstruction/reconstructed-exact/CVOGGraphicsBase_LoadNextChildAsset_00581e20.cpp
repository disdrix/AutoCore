// =============================================================================
// CVOGGraphicsBase_LoadNextChildAsset_00581e20
// -----------------------------------------------------------------------------
// Stable ID: aa_00581e20
// Address:   0x00581e20  (autoassault.exe, image base 0x400000)
// System:    unknown
// Generated: 2026-07-23 from raw capture (scaffold; refine for important units)
// Exactness: Behavior-preserving rewrite of decompiler control flow. Not modernization.
// Bit-for-bit vs retail EXE: DEFERRED (loaded image may differ slightly).
// =============================================================================

// PURPOSE (auto): Scaffold unit for CVOGGraphicsBase_LoadNextChildAsset_00581e20 @ 0x00581e20
// Stable ID: aa_00581e20
// Embedded strings (evidence for future rename):
//   - "CVOGGraphicsBase::LoadNextChildAsset() - Unknown type of asset #%s, child of <%s>"
//   - "C:\\vog\\1_code\\vog_14_117_branch\\libVOG\\VOGGraphicsBase.cpp"
// Readability: control flow preserved from Ghidra decompile; types tentative.

// READABILITY (auto CF):
//  - Body size: ~72 non-empty decompiler lines.
//  - Control keywords: if×1, switch×1, goto×1, return×1.
//  - Notable callees: CVOGGraphicsBase::LoadNextChildAsset, CVOGGraphicsBase_LoadNextChildAsset_00581e20, FUN_00743ef0, FUN_0074ecf0, FUN_0074ed90, FUN_0074ee40, FUN_00763f60, FUN_00764030.
//  - Strings: "C:\\vog\\1_code\\vog_14_117_branch\\libVOG\\VOGGraphicsBase.cpp".
//  - Return sites: 1.

/*
 * Behavioral notes:
 * Plate-driven rename evidence: "CVOGGraphicsBase::LoadNextChildAsset() - Unknown type of asset #%s, child of <%s>"
 * Domain alias of FUN_00581e20 (FUN_* retained)
 *
 * - Derived from Ghidra decompile; names prefer Ghidra symbols / plate comments.
 * - Remaining FUN_* / DAT_* identifiers are unresolved pending type recovery.
 * - Runtime / differential verification: OPEN unless matrix says otherwise.
 *
 * Readability pass:
 * - undefinedN widths preserved as fixed-width integers where decompiler width is known.
 * - Control flow and call order preserved from authoritative raw.
 */

uint32_t /* width from decompiler */ CVOGGraphicsBase_LoadNextChildAsset_00581e20(uint32_t /* width from decompiler */ param_1)



{

  uint8_t *puVar1;

  basic_string<char,struct_std::char_traits<char>,class_std::allocator<char>_> *this;

  char *pcVar2;

  uint32_t /* width from decompiler */ uVar3;

  uint8_t local_1f0 [4];

  basic_string<char,struct_std::char_traits<char>,class_std::allocator<char>_> local_1ec [480];

  void *local_c;

  uint8_t *puStack_8;

  uint32_t /* width from decompiler */ local_4;

  

  local_4 = 0xffffffff;

  puStack_8 = &LAB_009a53ed;

  local_c = ExceptionList;

  ExceptionList = &local_c;

  puVar1 = (uint8_t *)FUN_00743ef0(param_1);

  if (puVar1 == (uint8_t *)0x0) {

LAB_00581fce:

    uVar3 = 0xffffffff;

  }

  else {

    switch(*puVar1) {

    case 0x41:

      FUN_0074ed90();

      local_4 = 3;

      uVar3 = FUN_0074ee40(param_1);

      local_4 = 0xffffffff;

      FUN_0074ecf0();

      break;

    default:

      this = (basic_string<char,struct_std::char_traits<char>,class_std::allocator<char>_> *)

             FUN_0096a630(local_1ec);

      local_4 = 4;

      pcVar2 = std::basic_string<char,struct_std::char_traits<char>,class_std::allocator<char>_>::

               c_str(this);

      uVar3 = FUN_0076cec0(local_1f0,

                           "CVOGGraphicsBase::LoadNextChildAsset() - Unknown type of asset #%s, child of <%s>"

                           ,puVar1,pcVar2);

      vog_LogMessage("C:\\vog\\1_code\\vog_14_117_branch\\libVOG\\VOGGraphicsBase.cpp",0x2ce,1,uVar3

                    );

      local_4 = 0xffffffff;

      std::basic_string<char,struct_std::char_traits<char>,class_std::allocator<char>_>::

      ~basic_string<char,struct_std::char_traits<char>,class_std::allocator<char>_>(local_1ec);

      goto LAB_00581fce;

    case 0x45:

      FUN_0096f530();

      local_4 = 2;

      uVar3 = FUN_009701d0(param_1);

      local_4 = 0xffffffff;

      FUN_0096f510();

      break;

    case 0x47:

      FUN_00764030();

      local_4 = 0;

      uVar3 = FUN_00764830(param_1);

      local_4 = 0xffffffff;

      FUN_00763f60();

      break;

    case 0x49:

      uVar3 = 99999;

      break;

    case 0x54:

      FUN_0096ef70();

      local_4 = 1;

      uVar3 = FUN_0096f3e0(param_1,0);

      local_4 = 0xffffffff;

      FUN_0096efd0();

    }

  }

  ExceptionList = local_c;

  return uVar3;

}
