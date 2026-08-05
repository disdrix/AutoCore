// =============================================================================
// Named_CalleeOf_Named_stoChunk_00769b70
// -----------------------------------------------------------------------------
// Stable ID: aa_00769b70
// Callee of Named_stoChunk (+1 other named callers)
// Address:   0x00769b70  (autoassault.exe, image base 0x400000)
// System:    unknown
// Generated: 2026-07-23 from raw capture (scaffold; refine for important units)
// Exactness: Behavior-preserving rewrite of decompiler control flow. Not modernization.
// Bit-for-bit vs retail EXE: DEFERRED (loaded image may differ slightly).
// =============================================================================

// PURPOSE (auto): Called from Named_stoChunk: callee helper. Evidence string: ");

    if (bVar3) {

      vog_LogMessage(". Supports parent flow (not a free-standing entry point). Named_stoChunk (+1 other named callers).
// Embedded strings (evidence):
//   - ");

    if (bVar3) {

      vog_LogMessage("
//   - ",0x2a0,3,

                     "
//   - "
//   - "
// Readability: control flow preserved from Ghidra decompile; types tentative.

// READABILITY (auto CF):
//  - Body size: ~116 non-empty decompiler lines.
//  - Control keywords: if×14, goto×4, return×3, do×2, while×2.
//  - Notable callees: FUN_00435df0, FUN_00769b70, isspace, substr, vog_LogMessage.
//  - Strings: ");

    if (bVar3) {

      vog_LogMessage("; ",0x2a0,3,

                     ".
//  - Return sites: 3.

    if (bVar3) {

      vog_LogMessage("
//   - ",0x2a0,3,

                     "
// Readability: control flow preserved from Ghidra decompile; types tentative.

/*
 * Behavioral notes:
 * Callee of Named_stoChunk (+1 other named callers)
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

uint32_t /* width from decompiler */ Named_CalleeOf_Named_stoChunk_00769b70(int param_1)



{

  char cVar1;

  bool bVar2;

  bool bVar3;

  int iVar4;

  basic_string<char,struct_std::char_traits<char>,class_std::allocator<char>_> *pbVar5;

  basic_string<char,struct_std::char_traits<char>,class_std::allocator<char>_> *pbVar6;

  basic_string<char,struct_std::char_traits<char>,class_std::allocator<char>_> *unaff_EDI;

  char local_2d;

  basic_string<char,struct_std::char_traits<char>,class_std::allocator<char>_> local_28 [28];

  void *local_c;

  uint8_t *puStack_8;

  uint32_t /* width from decompiler */ local_4;

  

  local_4 = 0xffffffff;

  puStack_8 = &LAB_009affaf;

  local_c = ExceptionList;

  if (-1 < *(int *)(param_1 + 0x402c)) {

    if (*(int *)(param_1 + 0x4060) == 0) {

      ExceptionList = &local_c;

      std::basic_string<char,struct_std::char_traits<char>,class_std::allocator<char>_>::resize

                (unaff_EDI,0);

      bVar3 = false;

      local_2d = '\"';

      do {

        bVar2 = false;

LAB_00769c46:

        do {

          if ((*(int *)(param_1 + 0x20) < *(int *)(param_1 + 0x18) + 1) &&

             ((iVar4 = FUN_00435df0(*(int *)(param_1 + 0x1c) + *(int *)(param_1 + 0x18)), iVar4 < 0

              || (*(int *)(param_1 + 0x20) < 1)))) {

            if (!bVar3) {

              *(uint32_t /* width from decompiler */ *)(param_1 + 0x402c) = 0xffffffff;

              ExceptionList = local_c;

              return 0xffffffff;

            }

            goto LAB_00769bc1;

          }

          cVar1 = *(char *)(*(int *)(param_1 + 0x18) + param_1 + 0x2c);

          *(int *)(param_1 + 0x18) = *(int *)(param_1 + 0x18) + 1;

          if (!bVar2) {

            if ((cVar1 == '\'') || (cVar1 == '\"')) {

              bVar2 = true;

              local_2d = cVar1;

            }

            else {

              iVar4 = isspace((int)cVar1);

              if (iVar4 != 0) {

                if (bVar3) goto LAB_00769bc1;

                goto LAB_00769c46;

              }

            }

            bVar3 = true;

            std::basic_string<char,struct_std::char_traits<char>,class_std::allocator<char>_>::

            operator+=(unaff_EDI,cVar1);

            goto LAB_00769c46;

          }

          std::basic_string<char,struct_std::char_traits<char>,class_std::allocator<char>_>::

          operator+=(unaff_EDI,cVar1);

        } while (cVar1 != local_2d);

      } while( true );

    }

    ExceptionList = &local_c;

    std::basic_string<char,struct_std::char_traits<char>,class_std::allocator<char>_>::operator=

              (unaff_EDI,

               (basic_string<char,struct_std::char_traits<char>,class_std::allocator<char>_> *)

               (param_1 + 0x404c));

    std::basic_string<char,struct_std::char_traits<char>,class_std::allocator<char>_>::operator=

              ((basic_string<char,struct_std::char_traits<char>,class_std::allocator<char>_> *)

               (param_1 + 0x404c),"");

LAB_00769bc1:

    bVar3 = std::operator==<char,struct_std::char_traits<char>,class_std::allocator<char>_>

                      (unaff_EDI,"}");

    if (bVar3) {

      vog_LogMessage("C:\\vog\\1_code\\palantir\\arda2\\storage\\stoChunk.cpp",0x2a0,3,

                     "Attempt to read past end of chunk. Ignoring reads until chunk exit");

      *(uint32_t /* width from decompiler */ *)(param_1 + 0x402c) = 0xffffffff;

      std::basic_string<char,struct_std::char_traits<char>,class_std::allocator<char>_>::operator=

                ((basic_string<char,struct_std::char_traits<char>,class_std::allocator<char>_> *)

                 (param_1 + 0x404c),unaff_EDI);

      std::basic_string<char,struct_std::char_traits<char>,class_std::allocator<char>_>::operator=

                (unaff_EDI,"");

    }

    else if (1 < *(uint *)(unaff_EDI + 0x14)) {

      pbVar5 = unaff_EDI + 4;

      pbVar6 = pbVar5;

      if (0xf < *(uint *)(unaff_EDI + 0x18)) {

        pbVar6 = *(basic_string<char,struct_std::char_traits<char>,class_std::allocator<char>_> **)

                  pbVar5;

      }

      if (*pbVar6 ==

          (basic_string<char,struct_std::char_traits<char>,class_std::allocator<char>_>)0x22) {

        if (0xf < *(uint *)(unaff_EDI + 0x18)) {

          pbVar5 = *(basic_string<char,struct_std::char_traits<char>,class_std::allocator<char>_> **

                    )pbVar5;

        }

        if (pbVar5[*(uint *)(unaff_EDI + 0x14) - 1] ==

            (basic_string<char,struct_std::char_traits<char>,class_std::allocator<char>_>)0x22) {

          pbVar5 = (basic_string<char,struct_std::char_traits<char>,class_std::allocator<char>_> *)

                   std::basic_string<char,struct_std::char_traits<char>,class_std::allocator<char>_>

                   ::substr(unaff_EDI,(uint)local_28,1);

          local_4 = 0;

          std::basic_string<char,struct_std::char_traits<char>,class_std::allocator<char>_>::

          operator=(unaff_EDI,pbVar5);

          local_4 = 0xffffffff;

          std::basic_string<char,struct_std::char_traits<char>,class_std::allocator<char>_>::

          ~basic_string<char,struct_std::char_traits<char>,class_std::allocator<char>_>(local_28);

          ExceptionList = local_c;

          return 0;

        }

      }

    }

  }

  ExceptionList = local_c;

  return 0xffffffff;

}
