// =============================================================================
// FUN_00971b80
// -----------------------------------------------------------------------------
// Stable ID: aa_00971b80
// Address:   0x00971b80  (autoassault.exe, image base 0x400000)
// System:    unknown
// Generated: 2026-07-23 from raw capture (scaffold; refine for important units)
// Exactness: Behavior-preserving rewrite of decompiler control flow. Not modernization.
// Bit-for-bit vs retail EXE: DEFERRED (loaded image may differ slightly).
// =============================================================================

// PURPOSE (auto): Scaffold unit for FUN_00971b80 @ 0x00971b80
// Stable ID: aa_00971b80
// Embedded strings (evidence for future rename):
//   - "filename=\""
//   - ".xml"
// Readability: control flow preserved from Ghidra decompile; types tentative.

// READABILITY (auto CF):
//  - Body size: ~129 non-empty decompiler lines.
//  - Control keywords: if×16, while×2, do×1, return×1.
//  - Notable callees: FUN_00989e00×3, strstr×3, FUN_00437050×2, FUN_0043b9e0×2, FUN_00768760×2, strrchr×2, FUN_00436f10, FUN_0043d4a0.
//  - Strings: ".fx"; "filename=\""; ".xml".
//  - Return sites: 1.

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

/* WARNING: Function: __chkstk replaced with injection: alloca_probe */



void FUN_00971b80(uint32_t /* width from decompiler */ param_1,int *param_2,int param_3,uint32_t /* width from decompiler */ *param_4)



{

  char cVar1;

  int iVar2;

  char *pcVar3;

  char *pcVar4;

  char ******ppppppcVar5;

  char ******_Str;

  char *****local_50c0;

  char *****local_50bc;

  uint8_t local_50b8 [4];

  uint8_t local_50b4 [4];

  char ****local_50b0;

  char ****local_50ac [3];

  char local_50a0;

  int local_509c;

  int local_5098;

  uint8_t local_5094 [4];

  basic_string<char,struct_std::char_traits<char>,class_std::allocator<char>_> local_5090 [4];

  char *****local_508c [5];

  uint local_5078;

  char acStack_5074 [4096];

  uint8_t local_4074 [16452];

  int local_30;

  uint32_t /* width from decompiler */ uStack_10;

  void *local_c;

  uint8_t *puStack_8;

  int local_4;

  

  local_4 = 0xffffffff;

  puStack_8 = &LAB_009b1c81;

  local_c = ExceptionList;

  uStack_10 = 0x971b9f;

  if (param_3 == 0) {

    ExceptionList = &local_c;

    FUN_0076a150(param_2);

    local_4 = 0;

    stoChunkReader_EnterChunkScope(local_4074);

    local_4._0_1_ = 1;

    if ((local_5098 == 3) && (local_509c == 0x47424f44)) {

      if (local_30 == 0) {

        FUN_00437050(&local_50c0);

      }

      else {

        FUN_00768760(&local_50c0);

      }

      if (local_30 == 0) {

        FUN_00437050(&local_50c0);

      }

      else {

        FUN_00768760(&local_50c0);

      }

      std::basic_string<char,struct_std::char_traits<char>,class_std::allocator<char>_>::

      basic_string<char,struct_std::char_traits<char>,class_std::allocator<char>_>(local_5090);

      local_4._0_1_ = 2;

      if (0 < (int)local_50c0) {

        local_50bc = local_50c0;

        do {

          if (local_30 == 0) {

            FUN_00436f10();

          }

          else {

            FUN_0076a200();

          }

          _Str = (char ******)local_508c[0];

          if (local_5078 < 0x10) {

            _Str = local_508c;

          }

          local_50c0 = (char *****)_Str;

          pcVar3 = strstr((char *)_Str,".fx");

          if ((pcVar3 == (char *)0x0) || (pcVar3[3] != '\0')) {

            pcVar3 = strrchr((char *)_Str,0x5c);

            pcVar4 = strrchr((char *)_Str,0x2f);

            local_50b0 = (char ****)(pcVar4 + 1);

            local_50ac[0] = (char ****)(pcVar3 + 1);

            ppppppcVar5 = (char ******)&local_50b0;

            if (pcVar4 + 1 <= pcVar3 + 1) {

              ppppppcVar5 = (char ******)local_50ac;

            }

            if (*ppppppcVar5 < _Str) {

              ppppppcVar5 = &local_50c0;

            }

            if (param_4 == (uint32_t /* width from decompiler */ *)0x0) {

              FUN_00989e00(local_50b8,*ppppppcVar5);

            }

            else {

              FUN_00989e00(local_50b4,*ppppppcVar5);

              (**(code **)*param_4)(local_5094,local_50b4);

            }

            FUN_0043b9e0();

          }

          local_50bc = (char *****)((int)local_50bc + -1);

        } while ((char ******)local_50bc != (char ******)0x0);

      }

      local_4._0_1_ = 1;

      std::basic_string<char,struct_std::char_traits<char>,class_std::allocator<char>_>::

      ~basic_string<char,struct_std::char_traits<char>,class_std::allocator<char>_>(local_5090);

    }

    local_4 = (uint)local_4._1_3_ << 8;

    if (local_50a0 != '\0') {

      FUN_00769e40();

    }

    local_4 = 0xffffffff;

    FUN_0043d4a0();

  }

  else if (param_3 == 3) {

    ExceptionList = &local_c;

    cVar1 = (**(code **)(*param_2 + 0x10))();

    while ((cVar1 == '\0' && (iVar2 = FUN_00766e50(acStack_5074,0x1000), iVar2 == 0))) {

      _strlwr(acStack_5074);

      pcVar3 = strstr(acStack_5074,"filename=\"");

      if (pcVar3 != (char *)0x0) {

        pcVar3 = pcVar3 + 10;

        pcVar4 = strchr(pcVar3,0x22);

        if (pcVar4 != (char *)0x0) {

          *pcVar4 = '\0';

          pcVar4 = strstr(pcVar3,".xml");

          if ((pcVar4 != (char *)0x0) && (pcVar4[4] == '\0')) {

            FUN_00989e00(&local_50bc,pcVar3);

            FUN_0043b9e0();

          }

        }

      }

      cVar1 = (**(code **)(*param_2 + 0x10))();

    }

  }

  ExceptionList = local_c;

  return;

}
