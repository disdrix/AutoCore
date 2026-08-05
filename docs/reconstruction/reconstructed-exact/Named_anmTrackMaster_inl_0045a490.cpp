// READABILITY (auto CF):
//  - Body size: ~134 non-empty decompiler lines.
//  - Control keywords: if×18, return×3, goto×1.
//  - Notable callees: CONCAT31×3, FUN_00437050×3, FUN_00769e40×3, FUN_00436f10×2, FUN_007689e0×2, FUN_0076a200×2, FUN_00989e00×2, FUN_00442fa0.
//  - Strings: "..\\palantir/animation/anmTrackMaster_inl.h"; "Invalid TAG unserializing anmTrackMaster".
//  - Return sites: 3.

// =============================================================================
// Named_anmTrackMaster_inl_0045a490
// -----------------------------------------------------------------------------
// Stable ID: aa_0045a490
// Address:   0x0045a490  (autoassault.exe, image base 0x400000)
// System:    unknown
// Generated: 2026-07-23 from raw capture (scaffold; refine for important units)
// Exactness: Behavior-preserving rewrite of decompiler control flow. Not modernization.
// Bit-for-bit vs retail EXE: DEFERRED (loaded image may differ slightly).
// =============================================================================

/*
 * Behavioral notes:
 * String-driven rename evidence: "anmTrackMaster_inl"
 *
 * - Derived from Ghidra decompile; names prefer Ghidra symbols / plate comments.
 * - Remaining FUN_* / DAT_* identifiers are unresolved pending type recovery.
 * - Runtime / differential verification: OPEN unless matrix says otherwise.
 *
 * Readability pass:
 * - undefinedN widths preserved as fixed-width integers where decompiler width is known.
 * - Control flow and call order preserved from authoritative raw.
 */

uint32_t /* width from decompiler */ __thiscall Named_anmTrackMaster_inl_0045a490(int *param_1,int param_2)



{

  int iVar1;

  int iVar2;

  int iVar3;

  int *piVar4;

  int iVar5;

  uint32_t /* width from decompiler */ local_58;

  uint32_t /* width from decompiler */ local_54;

  uint32_t /* width from decompiler */ local_50;

  int local_4c;

  int local_48;

  basic_string<char,struct_std::char_traits<char>,class_std::allocator<char>_> local_44 [4];

  uint32_t /* width from decompiler */ **local_40 [5];

  uint local_2c;

  basic_string<char,struct_std::char_traits<char>,class_std::allocator<char>_> local_28 [4];

  uint32_t /* width from decompiler */ **local_24 [5];

  uint local_10;

  void *local_c;

  uint8_t *puStack_8;

  uint local_4;

  

  iVar5 = param_2;

  local_4 = 0xffffffff;

  puStack_8 = &LAB_009befca;

  local_c = ExceptionList;

  ExceptionList = &local_c;

  stoChunkReader_EnterChunkScope(param_2);

  local_4 = 0;

  if ((local_4c == 0x5042414d) || (local_4c == 0x5452414b)) {

    if (2 < local_48) {

      if (*(int *)(iVar5 + 0x4044) == 0) {

        iVar2 = FUN_00468aa0();

      }

      else {

        iVar2 = FUN_007684e0(param_1 + 2);

      }

      if (iVar2 < 0) goto LAB_0045a795;

      iVar2 = param_1[2];

      iVar1 = param_1[3];

      iVar3 = FUN_0044c370(iVar2,iVar1);

      if (iVar3 != 0) {

        local_4 = 0xffffffff;

        if ((char)local_50 != '\0') {

          FUN_00769e40();

        }

        ExceptionList = local_c;

        return 0xfffffffe;

      }

      FUN_0044c340(iVar2,iVar1);

    }

    if (local_48 < 2) {

      iVar2 = (**(code **)(*param_1 + 0x10))();

      param_1[4] = (-(uint)(iVar2 != 0x4b455556) & 0xe0501f8) + 0x45464354;

    }

    else if (*(int *)(iVar5 + 0x4044) == 0) {

      FUN_00437050(param_1 + 4);

    }

    else {

      FUN_007689e0(param_1 + 4);

    }

    std::basic_string<char,struct_std::char_traits<char>,class_std::allocator<char>_>::

    basic_string<char,struct_std::char_traits<char>,class_std::allocator<char>_>(local_44);

    local_4 = CONCAT31(local_4._1_3_,1);

    if (*(int *)(iVar5 + 0x4044) == 0) {

      FUN_00436f10();

    }

    else {

      FUN_0076a200();

    }

    if (local_2c < 0x10) {

      local_40[0] = local_40;

    }

    piVar4 = (int *)FUN_00989e00(&param_2,local_40[0]);

    param_1[5] = *piVar4;

    if (0 < local_48) {

      std::basic_string<char,struct_std::char_traits<char>,class_std::allocator<char>_>::

      basic_string<char,struct_std::char_traits<char>,class_std::allocator<char>_>(local_28);

      local_4 = CONCAT31(local_4._1_3_,2);

      if (*(int *)(iVar5 + 0x4044) == 0) {

        FUN_00436f10();

      }

      else {

        FUN_0076a200();

      }

      if (local_10 < 0x10) {

        local_24[0] = local_24;

      }

      piVar4 = (int *)FUN_00989e00(&param_2,local_24[0]);

      param_1[6] = *piVar4;

      local_4 = CONCAT31(local_4._1_3_,1);

      std::basic_string<char,struct_std::char_traits<char>,class_std::allocator<char>_>::

      ~basic_string<char,struct_std::char_traits<char>,class_std::allocator<char>_>(local_28);

    }

    if (*(int *)(iVar5 + 0x4044) == 0) {

      FUN_00437050(param_1 + 0xb);

    }

    else {

      FUN_007689e0(param_1 + 0xb);

    }

    if (*(int *)(iVar5 + 0x4044) == 0) {

      FUN_00437050(&param_2);

    }

    else {

      FUN_00768760(&param_2);

    }

    iVar5 = param_2;

    FUN_00442fa0(local_58,local_54,local_50,local_4c,local_48);

    if ((0 < iVar5) && (iVar5 = FUN_0045e280(param_1[8]), iVar5 == 0)) {

      local_4 = local_4 & 0xffffff00;

      std::basic_string<char,struct_std::char_traits<char>,class_std::allocator<char>_>::

      ~basic_string<char,struct_std::char_traits<char>,class_std::allocator<char>_>(local_44);

      local_4 = 0xffffffff;

      if ((char)local_50 != '\0') {

        FUN_00769e40();

      }

      ExceptionList = local_c;

      return 0;

    }

    local_4 = local_4 & 0xffffff00;

    std::basic_string<char,struct_std::char_traits<char>,class_std::allocator<char>_>::

    ~basic_string<char,struct_std::char_traits<char>,class_std::allocator<char>_>(local_44);

  }

  else {

    vog_LogMessage("..\\palantir/animation/anmTrackMaster_inl.h",0x60,3,

                   "Invalid TAG unserializing anmTrackMaster");

  }

LAB_0045a795:

  local_4 = 0xffffffff;

  if ((char)local_50 != '\0') {

    FUN_00769e40();

  }

  ExceptionList = local_c;

  return 0xffffffff;

}
