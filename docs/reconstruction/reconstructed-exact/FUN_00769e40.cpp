// =============================================================================
// FUN_00769e40
// -----------------------------------------------------------------------------
// Stable ID: aa_00769e40
// Address:   0x00769e40  (autoassault.exe, image base 0x400000)
// System:    unknown
// Generated: 2026-07-23 from raw capture (scaffold; refine for important units)
// Exactness: Behavior-preserving rewrite of decompiler control flow. Not modernization.
// Bit-for-bit vs retail EXE: DEFERRED (loaded image may differ slightly).
// =============================================================================

// PURPOSE (auto): Scaffold unit for FUN_00769e40 @ 0x00769e40
// Stable ID: aa_00769e40
// Embedded strings (evidence for future rename):
//   - "C:\\vog\\1_code\\palantir\\arda2\\storage\\stoChunk.cpp"
//   - "Could not find end of text chunk"
// Readability: control flow preserved from Ghidra decompile; types tentative.

// READABILITY (auto CF):
//  - Body size: ~79 non-empty decompiler lines.
//  - Control keywords: if×8, return×2, do×1, while×1.
//  - Notable callees: FUN_00767840, FUN_00769e40, vog_LogMessage.
//  - Strings: "C:\\vog\\1_code\\palantir\\arda2\\storage\\stoChunk.cpp"; "Could not find end of text chunk".
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

uint32_t /* width from decompiler */ __fastcall FUN_00769e40(int param_1)



{

  uint *puVar1;

  int iVar2;

  bool bVar3;

  int iVar4;

  uint uVar5;

  basic_string<char,struct_std::char_traits<char>,class_std::allocator<char>_> local_28 [28];

  void *local_c;

  uint8_t *puStack_8;

  uint32_t /* width from decompiler */ local_4;

  

  local_4 = 0xffffffff;

  puStack_8 = &LAB_009affc2;

  local_c = ExceptionList;

  ExceptionList = &local_c;

  *(uint32_t /* width from decompiler */ *)(param_1 + 0x402c) = 0;

  if (*(int *)(param_1 + 0x4044) == 0) {

    uVar5 = (*(int *)(param_1 + 0x4040) + *(int *)(param_1 + 0x403c)) - 1;

    if (*(uint *)(param_1 + 0x4038) <= uVar5) {

      uVar5 = uVar5 - *(uint *)(param_1 + 0x4038);

    }

    iVar4 = *(int *)(*(int *)(*(int *)(param_1 + 0x4034) + uVar5 * 4) + 0x10);

    if ((iVar4 < 0) || (*(int *)(param_1 + 0x28) < iVar4)) {

      *(uint32_t /* width from decompiler */ *)(param_1 + 0x402c) = 0xffffffff;

    }

    else {

      iVar2 = *(int *)(param_1 + 0x1c);

      if ((iVar4 < iVar2) || (*(int *)(param_1 + 0x20) + iVar2 <= iVar4)) {

        *(int *)(param_1 + 0x1c) = iVar4;

        *(uint32_t /* width from decompiler */ *)(param_1 + 0x20) = 0;

        *(uint32_t /* width from decompiler */ *)(param_1 + 0x18) = 0;

        *(uint32_t /* width from decompiler */ *)(param_1 + 0x402c) = *(uint32_t /* width from decompiler */ *)(param_1 + 0x402c);

      }

      else {

        *(int *)(param_1 + 0x18) = iVar4 - iVar2;

        *(uint32_t /* width from decompiler */ *)(param_1 + 0x402c) = *(uint32_t /* width from decompiler */ *)(param_1 + 0x402c);

      }

    }

  }

  else {

    std::basic_string<char,struct_std::char_traits<char>,class_std::allocator<char>_>::

    basic_string<char,struct_std::char_traits<char>,class_std::allocator<char>_>(local_28);

    local_4 = 0;

    iVar4 = 1;

    do {

      uVar5 = FUN_00767840(param_1,1);

      puVar1 = (uint *)(param_1 + 0x402c);

      *puVar1 = *puVar1 | uVar5;

      if ((int)*puVar1 < 0) {

        vog_LogMessage("C:\\vog\\1_code\\palantir\\arda2\\storage\\stoChunk.cpp",0x20d,3,

                       "Could not find end of text chunk");

        local_4 = 0xffffffff;

        std::basic_string<char,struct_std::char_traits<char>,class_std::allocator<char>_>::

        ~basic_string<char,struct_std::char_traits<char>,class_std::allocator<char>_>(local_28);

        ExceptionList = local_c;

        return 0xffffffff;

      }

      bVar3 = std::operator==<char,struct_std::char_traits<char>,class_std::allocator<char>_>

                        (local_28,"{");

      if (bVar3) {

        iVar4 = iVar4 + 1;

      }

      bVar3 = std::operator==<char,struct_std::char_traits<char>,class_std::allocator<char>_>

                        (local_28,"}");

      if (bVar3) {

        iVar4 = iVar4 + -1;

      }

    } while (iVar4 != 0);

    local_4 = 0xffffffff;

    std::basic_string<char,struct_std::char_traits<char>,class_std::allocator<char>_>::

    ~basic_string<char,struct_std::char_traits<char>,class_std::allocator<char>_>(local_28);

  }

  if ((*(int *)(param_1 + 0x4040) != 0) &&

     (iVar4 = *(int *)(param_1 + 0x4040) + -1, *(int *)(param_1 + 0x4040) = iVar4, iVar4 == 0)) {

    *(uint32_t /* width from decompiler */ *)(param_1 + 0x403c) = 0;

  }

  ExceptionList = local_c;

  return *(uint32_t /* width from decompiler */ *)(param_1 + 0x402c);

}
