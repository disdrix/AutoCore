// =============================================================================
// Named_help_for_a_list_of_valid_slash_commands
// -----------------------------------------------------------------------------
// Stable ID: aa_0093bd10
// Address:   0x0093bd10  (autoassault.exe, image base 0x400000)
// System:    unknown
// Generated: 2026-07-23 from raw capture (scaffold; refine for important units)
// Exactness: Behavior-preserving rewrite of decompiler control flow. Not modernization.
// Bit-for-bit vs retail EXE: DEFERRED (loaded image may differ slightly).
// =============================================================================

// PURPOSE (auto): Scaffold unit for Named_help_for_a_list_of_valid_slash_commands @ 0x0093bd10
// Stable ID: aa_0093bd10
// Embedded strings (evidence for future rename):
//   - "Type /help for a list of valid slash commands!"
// Readability: control flow preserved from Ghidra decompile; types tentative.

// READABILITY (auto CF):
//  - Body size: ~118 non-empty decompiler lines.
//  - Control keywords: if×11, return×4, do×4, while×4, for×1, goto×1.
//  - Notable callees: find×2, FUN_00403c60, FUN_007a69d0, FUN_007a6de0, FUN_008f8200, Named_help_for_a_list_of_valid_slash_commands, _strlwr, replace.
//  - Strings: "Type /help for a list of valid slash commands!".
//  - Return sites: 4.

/*
 * Behavioral notes:
 * Plate-driven rename evidence: "Type /help for a list of valid slash commands!"
 * Domain alias of FUN_0093bd10 (FUN_* retained)
 *
 * - Derived from Ghidra decompile; names prefer Ghidra symbols / plate comments.
 * - Remaining FUN_* / DAT_* identifiers are unresolved pending type recovery.
 * - Runtime / differential verification: OPEN unless matrix says otherwise.
 *
 * Readability pass:
 * - undefinedN widths preserved as fixed-width integers where decompiler width is known.
 * - Control flow and call order preserved from authoritative raw.
 */

uint32_t /* width from decompiler */ Named_help_for_a_list_of_valid_slash_commands(int param_1,int param_2)



{

  char *pcVar1;

  char cVar2;

  char *pcVar3;

  int iVar4;

  uint uVar5;

  uint32_t /* width from decompiler */ uVar6;

  char *_Dest;

  char local_430 [4];

  basic_string<char,struct_std::char_traits<char>,class_std::allocator<char>_> local_42c [4];

  char *****local_428 [5];

  uint local_414;

  basic_string<char,struct_std::char_traits<char>,class_std::allocator<char>_> local_410 [28];

  char local_3f4 [1000];

  void *local_c;

  uint8_t *puStack_8;

  uint32_t /* width from decompiler */ local_4;

  

  local_4 = 0xffffffff;

  puStack_8 = &LAB_009b7e9d;

  local_c = ExceptionList;

  if ((param_2 == 0) || (*(int *)(param_1 + 0xe98) == 0)) {

    return 0x80070057;

  }

  _Dest = (char *)(param_2 + 0x2e);

  pcVar3 = _Dest;

  do {

    cVar2 = *pcVar3;

    pcVar3 = pcVar3 + 1;

  } while (cVar2 != '\0');

  if (pcVar3 == (char *)(param_2 + 0x2f) || (int)pcVar3 - (param_2 + 0x2f) < 0) {

    return 1;

  }

  ExceptionList = &local_c;

  FUN_007a69d0();

  local_430[0] = ' ';

  local_430[1] = '\0';

  pcVar3 = _Dest;

  do {

    cVar2 = *pcVar3;

    pcVar3[(int)(local_3f4 + -(int)_Dest)] = cVar2;

    pcVar3 = pcVar3 + 1;

  } while (cVar2 != '\0');

  pcVar3 = strtok(local_3f4,local_430);

  if (pcVar3 == (char *)0x0) {

LAB_0093bf4c:

    uVar6 = 0x80070057;

  }

  else {

    if (*pcVar3 == '/') {

      if (pcVar3[1] == '/') {

        pcVar3 = pcVar3 + 2;

      }

      else {

        pcVar3 = pcVar3 + 1;

      }

      _strlwr(pcVar3);

      if (*pcVar3 == '\0') {

        uVar6 = FUN_007a6de0("Type /help for a list of valid slash commands!",0xffffffff);

        if (DAT_00d1b8dc != 0) {

          FUN_008f8200(DAT_00d1b8dc,6,&DAT_00a2e3d4,uVar6,0);

        }

        goto LAB_0093bf4c;

      }

      std::basic_string<char,struct_std::char_traits<char>,class_std::allocator<char>_>::

      basic_string<char,struct_std::char_traits<char>,class_std::allocator<char>_>(local_410,pcVar3)

      ;

      local_4 = 0;

      iVar4 = FUN_00403c60(local_410);

      local_4 = 0xffffffff;

      std::basic_string<char,struct_std::char_traits<char>,class_std::allocator<char>_>::

      ~basic_string<char,struct_std::char_traits<char>,class_std::allocator<char>_>(local_410);

      if (iVar4 != *(int *)(param_1 + 8)) {

        uVar5 = std::basic_string<char,struct_std::char_traits<char>,class_std::allocator<char>_>::

                find((basic_string<char,struct_std::char_traits<char>,class_std::allocator<char>_> *

                     )(iVar4 + 0xc),pcVar3,0);

        if ((uVar5 == 0) && (*(int *)(iVar4 + 0x28) <= *(int *)(*(int *)(param_1 + 0xe98) + 0x6b4)))

        {

          std::basic_string<char,struct_std::char_traits<char>,class_std::allocator<char>_>::

          basic_string<char,struct_std::char_traits<char>,class_std::allocator<char>_>

                    (local_42c,_Dest);

          local_4 = 1;

          uVar5 = std::basic_string<char,struct_std::char_traits<char>,class_std::allocator<char>_>

                  ::find(local_42c,pcVar3,0);

          if (uVar5 != 0xffffffff) {

            pcVar1 = pcVar3 + 1;

            do {

              cVar2 = *pcVar3;

              pcVar3 = pcVar3 + 1;

            } while (cVar2 != '\0');

            std::basic_string<char,struct_std::char_traits<char>,class_std::allocator<char>_>::

            replace(local_42c,uVar5,(int)pcVar3 - (int)pcVar1,

                    (basic_string<char,struct_std::char_traits<char>,class_std::allocator<char>_> *)

                    (iVar4 + 0xc));

            if (local_414 < 0x10) {

              local_428[0] = (char *****)local_428;

            }

            strncpy(_Dest,(char *)local_428[0],1000);

            do {

              cVar2 = *_Dest;

              _Dest = _Dest + 1;

            } while (cVar2 != '\0');

            *(short *)(param_2 + 0x2c) = (short)_Dest - ((short)param_2 + 0x2f);

          }

          uVar6 = (**(code **)(iVar4 + 300))(param_2,local_430);

          local_4 = 0xffffffff;

          std::basic_string<char,struct_std::char_traits<char>,class_std::allocator<char>_>::

          ~basic_string<char,struct_std::char_traits<char>,class_std::allocator<char>_>(local_42c);

          ExceptionList = local_c;

          return uVar6;

        }

      }

    }

    uVar6 = 0;

  }

  ExceptionList = local_c;

  return uVar6;

}
