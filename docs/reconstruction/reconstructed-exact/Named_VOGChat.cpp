// READABILITY (auto CF):
//  - Body size: ~71 non-empty decompiler lines.
//  - Control keywords: if×3, for×1, return×1.
//  - Notable callees: FUN_0066e9c0×2, FUN_0076cec0×2, vog_LogMessage×2, FUN_0066e880, FUN_0067b070, FUN_0067b110, FUN_0067b3c0, FUN_00821940.
//  - Strings: "Unable to connect."; "C:\\vog\\1_code\\vog_14_117_branch\\appClient\\VOGChat.cpp".
//  - Return sites: 1.

// =============================================================================
// Named_VOGChat
// -----------------------------------------------------------------------------
// Stable ID: aa_00821940
// Address:   0x00821940  (autoassault.exe, image base 0x400000)
// System:    unknown
// Generated: 2026-07-23 from raw capture (scaffold; refine for important units)
// Exactness: Behavior-preserving rewrite of decompiler control flow. Not modernization.
// Bit-for-bit vs retail EXE: DEFERRED (loaded image may differ slightly).
// =============================================================================

/*
 * Behavioral notes:
 * String-driven rename evidence: "VOGChat"
 *
 * - Derived from Ghidra decompile; names prefer Ghidra symbols / plate comments.
 * - Remaining FUN_* / DAT_* identifiers are unresolved pending type recovery.
 * - Runtime / differential verification: OPEN unless matrix says otherwise.
 *
 * Readability pass:
 * - undefinedN widths preserved as fixed-width integers where decompiler width is known.
 * - Control flow and call order preserved from authoritative raw.
 */

uint32_t /* width from decompiler */ Named_VOGChat(uint32_t /* width from decompiler */ param_1,uint32_t /* width from decompiler */ param_2,int param_3)



{

  char cVar1;

  int iVar2;

  uint32_t /* width from decompiler */ uVar3;

  int *unaff_ESI;

  uint8_t auStack_54 [4];

  uint32_t /* width from decompiler */ uStack_50;

  uint32_t /* width from decompiler */ uStack_4c;

  uint32_t /* width from decompiler */ uStack_48;

  uint32_t /* width from decompiler */ uStack_44;

  uint32_t /* width from decompiler */ uStack_40;

  uint32_t /* width from decompiler */ uStack_3c;

  void *pvStack_28;

  int iStack_20;

  char *pcStack_14;

  uint8_t auStack_10 [4];

  void *pvStack_c;

  uint8_t *puStack_8;

  uint32_t /* width from decompiler */ uStack_4;

  

  uStack_4 = 0xffffffff;

  puStack_8 = &LAB_009ad1b1;

  pvStack_c = ExceptionList;

  uStack_3c = 2;

  uStack_40 = 0;

  ExceptionList = &pvStack_c;

  unaff_ESI[0x16] = param_3;

  uStack_44 = param_1;

  uStack_48 = 0;

  uStack_4c = 0;

  uStack_50 = 0;

  *(uint8_t *)(unaff_ESI + 2) = 0;

  iVar2 = (**(code **)(*unaff_ESI + 4))();

  if (iVar2 == 0) {

    FUN_0067b070();

    iStack_20 = 0;

    std::basic_string<char,struct_std::char_traits<char>,class_std::allocator<char>_>::

    basic_string<char,struct_std::char_traits<char>,class_std::allocator<char>_>

              ((basic_string<char,struct_std::char_traits<char>,class_std::allocator<char>_> *)

               &uStack_44,pcStack_14);

    iStack_20._0_1_ = 1;

    iVar2 = FUN_0067b3c0(&uStack_44,auStack_54);

    iStack_20 = (uint)iStack_20._1_3_ << 8;

    std::basic_string<char,struct_std::char_traits<char>,class_std::allocator<char>_>::

    ~basic_string<char,struct_std::char_traits<char>,class_std::allocator<char>_>

              ((basic_string<char,struct_std::char_traits<char>,class_std::allocator<char>_> *)

               &uStack_44);

    if (iVar2 != 0) {

      uVar3 = FUN_0076cec0(auStack_10,"Unable to connect.");

      vog_LogMessage("C:\\vog\\1_code\\vog_14_117_branch\\appClient\\VOGChat.cpp",0x21,3,uVar3);

    }

    iVar2 = FUN_0066e880(2,auStack_54);

    if (iVar2 < 0) {

      uVar3 = FUN_0076cec0(auStack_10,"Unable to connect.");

      vog_LogMessage("C:\\vog\\1_code\\vog_14_117_branch\\appClient\\VOGChat.cpp",0x30,3,uVar3);

    }

    else {

      cVar1 = FUN_0066e9c0();

      for (iVar2 = 0; ((cVar1 == '\0' && ((char)unaff_ESI[2] == '\0')) && (iVar2 < 10));

          iVar2 = iVar2 + 1) {

        (**(code **)(*unaff_ESI + 8))();

        Sleep(0x32);

        cVar1 = FUN_0066e9c0();

      }

    }

    iStack_20 = 0xffffffff;

    FUN_0067b110();

  }

  ExceptionList = pvStack_28;

  return 0;

}
