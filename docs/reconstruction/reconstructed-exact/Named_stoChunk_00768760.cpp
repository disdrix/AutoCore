// READABILITY (auto CF):
//  - Body size: ~117 non-empty decompiler lines.
//  - Control keywords: if×12, goto×5, do×2, while×2, return×2.
//  - Notable callees: vog_LogMessage×2, FUN_00435df0, FUN_00436250, FUN_00767600, FUN_00768760, FUN_0076cec0, isspace.
//  - Strings: ");

    if (bVar3) {

      vog_LogMessage("; ",0x2a0,3,

                     "; "Expected int32 but got \"%s\" in chunk \"%s\""; "C:\\vog\\1_code\\palantir\\arda2\\storage\\stoChunk.cpp".
//  - Return sites: 2.

// =============================================================================
// Named_stoChunk_00768760
// -----------------------------------------------------------------------------
// Stable ID: aa_00768760
// Address:   0x00768760  (autoassault.exe, image base 0x400000)
// System:    unknown
// Generated: 2026-07-23 from raw capture (scaffold; refine for important units)
// Exactness: Behavior-preserving rewrite of decompiler control flow. Not modernization.
// Bit-for-bit vs retail EXE: DEFERRED (loaded image may differ slightly).
// =============================================================================

/*
 * Behavioral notes:
 * String-driven rename evidence: "stoChunk"
 *
 * - Derived from Ghidra decompile; names prefer Ghidra symbols / plate comments.
 * - Remaining FUN_* / DAT_* identifiers are unresolved pending type recovery.
 * - Runtime / differential verification: OPEN unless matrix says otherwise.
 *
 * Readability pass:
 * - undefinedN widths preserved as fixed-width integers where decompiler width is known.
 * - Control flow and call order preserved from authoritative raw.
 */

uint32_t /* width from decompiler */ Named_stoChunk_00768760(uint32_t /* width from decompiler */ param_1)



{

  char cVar1;

  bool bVar2;

  bool bVar3;

  int iVar4;

  uint32_t /* width from decompiler */ uVar5;

  int unaff_EDI;

  char local_49;

  basic_string<char,struct_std::char_traits<char>,class_std::allocator<char>_> local_44 [4];

  uint32_t /* width from decompiler */ **local_40 [5];

  uint local_2c;

  basic_string<char,struct_std::char_traits<char>,class_std::allocator<char>_> local_28 [28];

  void *local_c;

  uint8_t *puStack_8;

  int local_4;

  

  local_4 = 0xffffffff;

  puStack_8 = &LAB_009afef4;

  local_c = ExceptionList;

  ExceptionList = &local_c;

  std::basic_string<char,struct_std::char_traits<char>,class_std::allocator<char>_>::

  basic_string<char,struct_std::char_traits<char>,class_std::allocator<char>_>(local_44);

  local_4 = 0;

  if (-1 < *(int *)(unaff_EDI + 0x402c)) {

    if (*(int *)(unaff_EDI + 0x4060) == 0) {

      std::basic_string<char,struct_std::char_traits<char>,class_std::allocator<char>_>::resize

                (local_44,0);

      bVar3 = false;

      local_49 = '\"';

      do {

        bVar2 = false;

LAB_00768870:

        do {

          if ((*(int *)(unaff_EDI + 0x20) < *(int *)(unaff_EDI + 0x18) + 1) &&

             ((iVar4 = FUN_00435df0(*(int *)(unaff_EDI + 0x1c) + *(int *)(unaff_EDI + 0x18)),

              iVar4 < 0 || (*(int *)(unaff_EDI + 0x20) < 1)))) {

            if (bVar3) goto LAB_007687c5;

            *(uint32_t /* width from decompiler */ *)(unaff_EDI + 0x402c) = 0xffffffff;

            goto LAB_00768823;

          }

          cVar1 = *(char *)(*(int *)(unaff_EDI + 0x18) + unaff_EDI + 0x2c);

          *(int *)(unaff_EDI + 0x18) = *(int *)(unaff_EDI + 0x18) + 1;

          if (!bVar2) {

            if ((cVar1 == '\'') || (cVar1 == '\"')) {

              bVar2 = true;

              local_49 = cVar1;

            }

            else {

              iVar4 = isspace((int)cVar1);

              if (iVar4 != 0) {

                if (bVar3) goto LAB_007687c5;

                goto LAB_00768870;

              }

            }

            bVar3 = true;

            std::basic_string<char,struct_std::char_traits<char>,class_std::allocator<char>_>::

            operator+=(local_44,cVar1);

            goto LAB_00768870;

          }

          std::basic_string<char,struct_std::char_traits<char>,class_std::allocator<char>_>::

          operator+=(local_44,cVar1);

        } while (cVar1 != local_49);

      } while( true );

    }

    std::basic_string<char,struct_std::char_traits<char>,class_std::allocator<char>_>::operator=

              (local_44,(basic_string<char,struct_std::char_traits<char>,class_std::allocator<char>_>

                         *)(unaff_EDI + 0x404c));

    std::basic_string<char,struct_std::char_traits<char>,class_std::allocator<char>_>::operator=

              ((basic_string<char,struct_std::char_traits<char>,class_std::allocator<char>_> *)

               (unaff_EDI + 0x404c),"");

LAB_007687c5:

    bVar3 = std::operator==<char,struct_std::char_traits<char>,class_std::allocator<char>_>

                      (local_44,"}");

    if (bVar3) {

      vog_LogMessage("C:\\vog\\1_code\\palantir\\arda2\\storage\\stoChunk.cpp",0x2a0,3,

                     "Attempt to read past end of chunk. Ignoring reads until chunk exit");

      *(uint32_t /* width from decompiler */ *)(unaff_EDI + 0x402c) = 0xffffffff;

      std::basic_string<char,struct_std::char_traits<char>,class_std::allocator<char>_>::operator=

                ((basic_string<char,struct_std::char_traits<char>,class_std::allocator<char>_> *)

                 (unaff_EDI + 0x404c),local_44);

      std::basic_string<char,struct_std::char_traits<char>,class_std::allocator<char>_>::operator=

                (local_44,"");

    }

    else {

      iVar4 = FUN_00767600(param_1,4,1);

      if (-1 < iVar4) {

        local_4 = 0xffffffff;

        std::basic_string<char,struct_std::char_traits<char>,class_std::allocator<char>_>::

        ~basic_string<char,struct_std::char_traits<char>,class_std::allocator<char>_>(local_44);

        ExceptionList = local_c;

        return 0;

      }

    }

  }

LAB_00768823:

  iVar4 = FUN_00436250();

  local_4._0_1_ = 1;

  if (*(uint *)(iVar4 + 0x18) < 0x10) {

    iVar4 = iVar4 + 4;

  }

  else {

    iVar4 = *(int *)(iVar4 + 4);

  }

  if (local_2c < 0x10) {

    local_40[0] = local_40;

  }

  uVar5 = FUN_0076cec0(&param_1,"Expected int32 but got \"%s\" in chunk \"%s\"",local_40[0],iVar4);

  vog_LogMessage("C:\\vog\\1_code\\palantir\\arda2\\storage\\stoChunk.cpp",0x414,3,uVar5);

  local_4 = (uint)local_4._1_3_ << 8;

  std::basic_string<char,struct_std::char_traits<char>,class_std::allocator<char>_>::

  ~basic_string<char,struct_std::char_traits<char>,class_std::allocator<char>_>(local_28);

  local_4 = 0xffffffff;

  std::basic_string<char,struct_std::char_traits<char>,class_std::allocator<char>_>::

  ~basic_string<char,struct_std::char_traits<char>,class_std::allocator<char>_>(local_44);

  ExceptionList = local_c;

  return 0xffffffff;

}
