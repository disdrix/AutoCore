// READABILITY (auto CF):
//  - Body size: ~132 non-empty decompiler lines.
//  - Control keywords: if×15, return×4, do×1, goto×1, while×1.
//  - Notable callees: FUN_00769e40×4, vog_LogMessage×3, FUN_00989e00×2, CONCAT31, FUN_00436f10, FUN_00437050, FUN_00439a20, FUN_0044fdd0.
//  - Strings: "C:\\vog\\1_code\\palantir\\palantir\\animation\\anmTrackEvents.cpp"; "Invalid TAG unserializing anmTrackEvents"; "Invalid chunk version unserializing anmTrackEvents"; "anmTrackEvents: Error Reading Track Id!".
//  - Return sites: 4.

// =============================================================================
// Named_anmTrackEvents
// -----------------------------------------------------------------------------
// Stable ID: aa_00987750
// Address:   0x00987750  (autoassault.exe, image base 0x400000)
// System:    unknown
// Generated: 2026-07-23 from raw capture (scaffold; refine for important units)
// Exactness: Behavior-preserving rewrite of decompiler control flow. Not modernization.
// Bit-for-bit vs retail EXE: DEFERRED (loaded image may differ slightly).
// =============================================================================

/*
 * Behavioral notes:
 * String-driven rename evidence: "anmTrackEvents"
 *
 * - Derived from Ghidra decompile; names prefer Ghidra symbols / plate comments.
 * - Remaining FUN_* / DAT_* identifiers are unresolved pending type recovery.
 * - Runtime / differential verification: OPEN unless matrix says otherwise.
 *
 * Readability pass:
 * - undefinedN widths preserved as fixed-width integers where decompiler width is known.
 * - Control flow and call order preserved from authoritative raw.
 */

uint __thiscall Named_anmTrackEvents(int param_1,uint param_2)



{

  int iVar1;

  uint uVar2;

  uint32_t /* width from decompiler */ ***pppuVar3;

  uint32_t /* width from decompiler */ *puVar4;

  uint uVar5;

  int iVar6;

  uint32_t /* width from decompiler */ uVar7;

  char *pcVar8;

  int local_4c;

  uint32_t /* width from decompiler */ local_48;

  uint8_t local_44 [4];

  uint8_t local_40 [12];

  char local_34;

  int local_30;

  int local_2c;

  basic_string<char,struct_std::char_traits<char>,class_std::allocator<char>_> local_28 [4];

  uint32_t /* width from decompiler */ **local_24 [5];

  uint local_10;

  void *local_c;

  uint8_t *puStack_8;

  uint local_4;

  

  local_4 = 0xffffffff;

  puStack_8 = &LAB_009b196b;

  local_c = ExceptionList;

  ExceptionList = &local_c;

  stoChunkReader_EnterChunkScope(param_2);

  local_4 = 0;

  if (local_30 != 0x54455654) {

    vog_LogMessage("C:\\vog\\1_code\\palantir\\palantir\\animation\\anmTrackEvents.cpp",0xb5,3,

                   "Invalid TAG unserializing anmTrackEvents");

    local_4 = 0xffffffff;

    if (local_34 != '\0') {

      FUN_00769e40();

    }

    ExceptionList = local_c;

    return 0xffffffff;

  }

  FUN_0044fdd0();

  if (local_2c != 1) {

    vog_LogMessage("C:\\vog\\1_code\\palantir\\palantir\\animation\\anmTrackEvents.cpp",0xdd,3,

                   "Invalid chunk version unserializing anmTrackEvents");

    local_4 = 0xffffffff;

    if (local_34 != '\0') {

      FUN_00769e40();

    }

    ExceptionList = local_c;

    return 0xffffffff;

  }

  std::basic_string<char,struct_std::char_traits<char>,class_std::allocator<char>_>::

  basic_string<char,struct_std::char_traits<char>,class_std::allocator<char>_>(local_28);

  local_4 = CONCAT31(local_4._1_3_,1);

  if (*(int *)(param_2 + 0x4044) == 0) {

    uVar2 = FUN_00436f10();

  }

  else {

    uVar2 = FUN_0076a200();

  }

  if ((int)uVar2 < 0) {

    pcVar8 = "anmTrackEvents: Error Reading Track Id!";

    uVar7 = 0xc4;

  }

  else {

    pppuVar3 = (uint32_t /* width from decompiler */ ***)local_24[0];

    if (local_10 < 0x10) {

      pppuVar3 = local_24;

    }

    puVar4 = (uint32_t /* width from decompiler */ *)FUN_00989e00(local_44,pppuVar3);

    *(uint32_t /* width from decompiler */ *)(param_1 + 4) = *puVar4;

    uVar5 = FUN_00439a20(param_2);

    if ((int)(uVar2 | uVar5) < 0) {

      pcVar8 = "anmTrackEvents: Error Reading Param Id!";

      uVar7 = 200;

    }

    else {

      if (local_10 < 0x10) {

        local_24[0] = local_24;

      }

      puVar4 = (uint32_t /* width from decompiler */ *)FUN_00989e00(local_40,local_24[0]);

      *(uint32_t /* width from decompiler */ *)(param_1 + 8) = *puVar4;

      if (*(int *)(param_2 + 0x4044) == 0) {

        param_2 = FUN_00437050(&local_4c);

      }

      else {

        param_2 = FUN_00768760(&local_4c);

      }

      iVar1 = local_4c;

      param_2 = uVar2 | uVar5 | param_2;

      if (-1 < (int)param_2) {

        FUN_0044fe70(0);

        iVar6 = 0;

        if (0 < iVar1) {

          do {

            uVar2 = FUN_0044fe10(&local_48);

            param_2 = param_2 | uVar2;

            if ((int)param_2 < 0) {

              pcVar8 = "anmTrackEvents: Error Reading event!";

              uVar7 = 0xd4;

              goto LAB_00987874;

            }

            *(uint32_t /* width from decompiler */ *)(*(int *)(param_1 + 0x10) + iVar6 * 4) = local_48;

            iVar6 = iVar6 + 1;

          } while (iVar6 < local_4c);

        }

        local_4 = local_4 & 0xffffff00;

        std::basic_string<char,struct_std::char_traits<char>,class_std::allocator<char>_>::

        ~basic_string<char,struct_std::char_traits<char>,class_std::allocator<char>_>(local_28);

        local_4 = 0xffffffff;

        if (local_34 != '\0') {

          FUN_00769e40();

        }

        ExceptionList = local_c;

        return param_2;

      }

      pcVar8 = "anmTrackEvents: Error Reading event count!";

      uVar7 = 0xcd;

    }

  }

LAB_00987874:

  vog_LogMessage("C:\\vog\\1_code\\palantir\\palantir\\animation\\anmTrackEvents.cpp",uVar7,3,pcVar8

                );

  local_4 = local_4 & 0xffffff00;

  std::basic_string<char,struct_std::char_traits<char>,class_std::allocator<char>_>::

  ~basic_string<char,struct_std::char_traits<char>,class_std::allocator<char>_>(local_28);

  local_4 = 0xffffffff;

  if (local_34 != '\0') {

    FUN_00769e40();

  }

  ExceptionList = local_c;

  return 0xffffffff;

}
