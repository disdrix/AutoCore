// READABILITY (auto CF):
//  - Body size: ~62 non-empty decompiler lines.
//  - Control keywords: if×3, return×2.
//  - Notable callees: FUN_0076cec0×3, FUN_0066fb10, FUN_0067a1b0, FUN_00680c30, FUN_00680c50, vog_LogMessage.
//  - Strings: "Not connected to a server."; "Already logged in"; "Not connected yet - still connecting.".
//  - Return sites: 2.

// =============================================================================
// Named_ChatClientImpl_0066fb10
// -----------------------------------------------------------------------------
// Stable ID: aa_0066fb10
// Address:   0x0066fb10  (autoassault.exe, image base 0x400000)
// System:    unknown
// Generated: 2026-07-23 from raw capture (scaffold; refine for important units)
// Exactness: Behavior-preserving rewrite of decompiler control flow. Not modernization.
// Bit-for-bit vs retail EXE: DEFERRED (loaded image may differ slightly).
// =============================================================================

/*
 * Behavioral notes:
 * String-driven rename evidence: "ChatClientImpl"
 *
 * - Derived from Ghidra decompile; names prefer Ghidra symbols / plate comments.
 * - Remaining FUN_* / DAT_* identifiers are unresolved pending type recovery.
 * - Runtime / differential verification: OPEN unless matrix says otherwise.
 *
 * Readability pass:
 * - undefinedN widths preserved as fixed-width integers where decompiler width is known.
 * - Control flow and call order preserved from authoritative raw.
 */

uint32_t /* width from decompiler */ __thiscall

Named_ChatClientImpl_0066fb10(int param_1,uint32_t /* width from decompiler */ param_2,uint32_t /* width from decompiler */ param_3,uint32_t /* width from decompiler */ param_4,uint32_t /* width from decompiler */ param_5

            ,uint32_t /* width from decompiler */ param_6,uint32_t /* width from decompiler */ param_7,

            basic_string<char,struct_std::char_traits<char>,class_std::allocator<char>_> *param_8,

            uint32_t /* width from decompiler */ param_9)



{

  uint32_t /* width from decompiler */ uVar1;

  uint32_t /* width from decompiler */ uVar2;

  uint32_t /* width from decompiler */ uVar3;

  uint8_t local_28 [20];

  void *pvStack_14;

  void *local_c;

  uint8_t *puStack_8;

  uint32_t /* width from decompiler */ local_4;

  

  uVar1 = param_3;

  local_4 = 0xffffffff;

  puStack_8 = &LAB_009a8f7f;

  local_c = ExceptionList;

  if (*(char *)(param_1 + 0x59) == '\0') {

    if (*(char *)(param_1 + 0x58) == '\0') {

      ExceptionList = &local_c;

      uVar1 = FUN_0076cec0(&param_6,"Not connected to a server.");

      uVar3 = 3;

      uVar2 = 0xc3;

    }

    else {

      if (*(char *)(param_1 + 0x5a) == '\0') {

        ExceptionList = &local_c;

        *(uint32_t /* width from decompiler */ *)(param_1 + 8) = param_3;

        *(uint32_t /* width from decompiler */ *)(param_1 + 0x10) = param_2;

        *(uint8_t *)(param_1 + 0x20) = (uint8_t)param_6;

        std::basic_string<char,struct_std::char_traits<char>,class_std::allocator<char>_>::operator=

                  ((basic_string<char,struct_std::char_traits<char>,class_std::allocator<char>_> *)

                   (param_1 + 0x1d0),param_8);

        FUN_00680c30();

        local_4 = 0;

        FUN_0067a1b0(local_28,0x3f8ccccd,param_2,uVar1,param_4,param_5,param_6,param_7,

                     (basic_string<char,struct_std::char_traits<char>,class_std::allocator<char>_> *

                     )(param_1 + 0x1d0),param_9);

        (**(code **)(**(int **)(param_1 + 0x38) + 4))(local_28,0);

        local_c = (void *)0xffffffff;

        FUN_00680c50();

        ExceptionList = pvStack_14;

        return 0;

      }

      ExceptionList = &local_c;

      uVar1 = FUN_0076cec0(&param_3,"Already logged in");

      uVar3 = 2;

      uVar2 = 0xc9;

    }

  }

  else {

    ExceptionList = &local_c;

    uVar1 = FUN_0076cec0(&param_6,"Not connected yet - still connecting.");

    uVar3 = 2;

    uVar2 = 0xbd;

  }

  vog_LogMessage("C:\\vog\\1_code\\palantir\\core\\infrastruct\\Voice\\TalkClientLib\\ChatClientImpl.cpp"

                 ,uVar2,uVar3,uVar1);

  ExceptionList = local_c;

  return 0xffffffff;

}
