// =============================================================================
// FUN_00718e40
// -----------------------------------------------------------------------------
// Stable ID: aa_00718e40
// Address:   0x00718e40  (autoassault.exe, image base 0x400000)
// System:    unknown
// Generated: 2026-07-23 from raw capture (scaffold; refine for important units)
// Exactness: Behavior-preserving rewrite of decompiler control flow. Not modernization.
// Bit-for-bit vs retail EXE: DEFERRED (loaded image may differ slightly).
// =============================================================================

// PURPOSE (auto): Scaffold unit for FUN_00718e40 @ 0x00718e40
// Stable ID: aa_00718e40
// No high-value strings recovered; name via xrefs/callers in follow-up.
// Readability: control flow preserved from Ghidra decompile; types tentative.

// READABILITY (auto CF):
//  - Body size: ~95 non-empty decompiler lines.
//  - Control keywords: if×8, return×2, do×1, goto×1, while×1.
//  - Notable callees: FUN_00719260×2, FUN_00435df0, FUN_00718e40, FUN_00769160.
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

void FUN_00718e40(int param_1,

                 basic_string<char,struct_std::char_traits<char>,class_std::allocator<char>_>

                 *param_2)



{

  char *pcVar1;

  int iVar2;

  basic_string<char,struct_std::char_traits<char>,class_std::allocator<char>_> *pbVar3;

  int iVar4;

  char *pcVar5;

  char local_3e [2];

  int local_3c;

  char *local_34;

  char *local_30;

  int local_2c;

  basic_string<char,struct_std::char_traits<char>,class_std::allocator<char>_> local_28 [28];

  void *local_c;

  uint8_t *puStack_8;

  int local_4;

  

  puStack_8 = &LAB_009ab4c1;

  local_c = ExceptionList;

  local_34 = (char *)0x0;

  local_30 = (char *)0x0;

  local_2c = 0;

  local_4 = 0;

  local_3e[0] = '\0';

  local_3c = 0;

  iVar4 = 0;

  pcVar5 = (char *)0x0;

  ExceptionList = &local_c;

  do {

    pcVar1 = local_30;

    if (*(int *)(param_1 + 0x4044) == 0) {

      if (*(int *)(param_1 + 0x20) < *(int *)(param_1 + 0x18) + 1) {

        iVar2 = FUN_00435df0(*(int *)(param_1 + 0x1c) + *(int *)(param_1 + 0x18));

        if ((iVar2 < 0) || (*(int *)(param_1 + 0x20) < 1)) {

          iVar2 = -1;

          goto LAB_00718ed6;

        }

      }

      local_3e[0] = *(char *)(*(int *)(param_1 + 0x18) + param_1 + 0x2c);

      *(int *)(param_1 + 0x18) = *(int *)(param_1 + 0x18) + 1;

      iVar2 = 0;

    }

    else {

      iVar2 = FUN_00769160(local_3e);

    }

LAB_00718ed6:

    if ((iVar2 < 0) || (local_3e[0] == '\0')) {

      if (local_3c == 0) {

        pbVar3 = (basic_string<char,struct_std::char_traits<char>,class_std::allocator<char>_> *)

                 std::basic_string<char,struct_std::char_traits<char>,class_std::allocator<char>_>::

                 basic_string<char,struct_std::char_traits<char>,class_std::allocator<char>_>

                           (local_28,"");

        local_4._0_1_ = 1;

        std::basic_string<char,struct_std::char_traits<char>,class_std::allocator<char>_>::operator=

                  (param_2,pbVar3);

        local_4 = (uint)local_4._1_3_ << 8;

        std::basic_string<char,struct_std::char_traits<char>,class_std::allocator<char>_>::

        ~basic_string<char,struct_std::char_traits<char>,class_std::allocator<char>_>(local_28);

      }

      else {

        local_3e[1] = 0;

        if ((pcVar5 == (char *)0x0) ||

           ((uint)(iVar4 - (int)pcVar5) <= (uint)((int)pcVar1 - (int)pcVar5))) {

          FUN_00719260(pcVar1,1,local_3e + 1);

          pcVar5 = local_34;

        }

        else {

          *pcVar1 = '\0';

          local_30 = pcVar1 + 1;

        }

        std::basic_string<char,struct_std::char_traits<char>,class_std::allocator<char>_>::operator=

                  (param_2,pcVar5);

      }

      if (pcVar5 != (char *)0x0) {

                    /* WARNING: Subroutine does not return */

        operator_delete(pcVar5);

      }

      ExceptionList = local_c;

      return;

    }

    if ((pcVar5 == (char *)0x0) ||

       ((uint)(iVar4 - (int)pcVar5) <= (uint)((int)pcVar1 - (int)pcVar5))) {

      FUN_00719260(pcVar1,1,local_3e);

      local_3c = local_3c + 1;

      iVar4 = local_2c;

      pcVar5 = local_34;

    }

    else {

      *pcVar1 = local_3e[0];

      local_30 = pcVar1 + 1;

      local_3c = local_3c + 1;

    }

  } while( true );

}
