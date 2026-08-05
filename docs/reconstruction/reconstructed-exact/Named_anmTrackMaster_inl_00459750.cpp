// READABILITY (auto CF):
//  - Body size: ~198 non-empty decompiler lines.
//  - Control keywords: if×19, return×3, goto×1.
//  - Notable callees: CONCAT31×3, FUN_00437050×3, FUN_00769e40×3, FUN_00436f10×2, FUN_007689e0×2, FUN_0076a200×2, FUN_00989e00×2, FUN_0044c340.
//  - Strings: "..\\palantir/animation/anmTrackMaster_inl.h".
//  - Return sites: 3.

// =============================================================================
// Named_anmTrackMaster_inl_00459750
// -----------------------------------------------------------------------------
// Stable ID: aa_00459750
// Address:   0x00459750  (autoassault.exe, image base 0x400000)
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

uint32_t /* width from decompiler */ __thiscall Named_anmTrackMaster_inl_00459750(int *param_1,int param_2)



{

  int iVar1;

  int iVar2;

  int *piVar3;

  int iVar4;

  bool bVar5;

  uint8_t auStack_94 [8];

  uint32_t /* width from decompiler */ uStack_8c;

  char *pcStack_88;

  uint32_t /* width from decompiler */ uStack_84;

  uint32_t /* width from decompiler */ *puStack_80;

  uint32_t /* width from decompiler */ **ppuStack_7c;

  uint8_t local_64 [4];

  uint8_t *local_60;

  int local_5c;

  char local_50;

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

  

  iVar4 = param_2;

  local_4 = 0xffffffff;

  puStack_8 = &LAB_009befca;

  local_c = ExceptionList;

  ppuStack_7c = (uint32_t /* width from decompiler */ **)param_2;

  puStack_80 = (uint32_t /* width from decompiler */ *)0x459780;

  ExceptionList = &local_c;

  stoChunkReader_EnterChunkScope();

  local_4 = 0;

  if ((local_4c == 0x5042414d) || (local_4c == 0x5452414b)) {

    if (2 < local_48) {

      if (*(int *)(iVar4 + 0x4044) == 0) {

        ppuStack_7c = (uint32_t /* width from decompiler */ **)0x4597e2;

        iVar1 = FUN_00468aa0();

      }

      else {

        puStack_80 = (uint32_t /* width from decompiler */ *)0x4597ec;

        ppuStack_7c = (uint32_t /* width from decompiler */ **)(param_1 + 2);

        iVar1 = FUN_007684e0();

      }

      if (iVar1 < 0) {

        bVar5 = local_50 == '\0';

        goto LAB_00459a38;

      }

      iVar1 = param_1[2];

      ppuStack_7c = (uint32_t /* width from decompiler */ **)param_1[3];

      uStack_84 = 0x459818;

      puStack_80 = (uint32_t /* width from decompiler */ *)iVar1;

      local_5c = (int)ppuStack_7c;

      iVar2 = FUN_0044c370();

      if (iVar2 != 0) {

        local_4 = 0xffffffff;

        if (local_50 != '\0') {

          ppuStack_7c = (uint32_t /* width from decompiler */ **)0x459834;

          FUN_00769e40();

        }

        ExceptionList = local_c;

        return 0xfffffffe;

      }

      ppuStack_7c = (uint32_t /* width from decompiler */ **)local_5c;

      uStack_84 = 0x45985d;

      puStack_80 = (uint32_t /* width from decompiler */ *)iVar1;

      FUN_0044c340();

    }

    if (local_48 < 2) {

      ppuStack_7c = (uint32_t /* width from decompiler */ **)0x45988e;

      iVar1 = (**(code **)(*param_1 + 0x10))();

      param_1[4] = (-(uint)(iVar1 != 0x4b455556) & 0xe0501f8) + 0x45464354;

    }

    else {

      ppuStack_7c = (uint32_t /* width from decompiler */ **)(param_1 + 4);

      if (*(int *)(iVar4 + 0x4044) == 0) {

        puStack_80 = (uint32_t /* width from decompiler */ *)0x45987c;

        FUN_00437050();

      }

      else {

        puStack_80 = (uint32_t /* width from decompiler */ *)0x459885;

        FUN_007689e0();

      }

    }

    ppuStack_7c = (uint32_t /* width from decompiler */ **)0x4598ae;

    std::basic_string<char,struct_std::char_traits<char>,class_std::allocator<char>_>::

    basic_string<char,struct_std::char_traits<char>,class_std::allocator<char>_>(local_44);

    local_4 = CONCAT31(local_4._1_3_,1);

    if (*(int *)(iVar4 + 0x4044) == 0) {

      ppuStack_7c = (uint32_t /* width from decompiler */ **)0x4598c8;

      FUN_00436f10();

    }

    else {

      ppuStack_7c = (uint32_t /* width from decompiler */ **)0x4598d5;

      FUN_0076a200();

    }

    if (local_2c < 0x10) {

      local_40[0] = local_40;

    }

    puStack_80 = &param_2;

    uStack_84 = 0x4598fb;

    ppuStack_7c = local_40[0];

    piVar3 = (int *)FUN_00989e00();

    param_1[5] = *piVar3;

    if (0 < local_48) {

      ppuStack_7c = (uint32_t /* width from decompiler */ **)0x459911;

      std::basic_string<char,struct_std::char_traits<char>,class_std::allocator<char>_>::

      basic_string<char,struct_std::char_traits<char>,class_std::allocator<char>_>(local_28);

      local_4 = CONCAT31(local_4._1_3_,2);

      if (*(int *)(iVar4 + 0x4044) == 0) {

        ppuStack_7c = (uint32_t /* width from decompiler */ **)0x45992b;

        FUN_00436f10();

      }

      else {

        ppuStack_7c = (uint32_t /* width from decompiler */ **)0x459938;

        FUN_0076a200();

      }

      if (local_10 < 0x10) {

        local_24[0] = local_24;

      }

      puStack_80 = (uint32_t /* width from decompiler */ *)local_64;

      uStack_84 = 0x45995b;

      ppuStack_7c = local_24[0];

      piVar3 = (int *)FUN_00989e00();

      param_1[6] = *piVar3;

      local_4 = CONCAT31(local_4._1_3_,1);

      ppuStack_7c = (uint32_t /* width from decompiler */ **)0x45996f;

      std::basic_string<char,struct_std::char_traits<char>,class_std::allocator<char>_>::

      ~basic_string<char,struct_std::char_traits<char>,class_std::allocator<char>_>(local_28);

    }

    ppuStack_7c = (uint32_t /* width from decompiler */ **)(param_1 + 0xb);

    if (*(int *)(iVar4 + 0x4044) == 0) {

      puStack_80 = (uint32_t /* width from decompiler */ *)0x459983;

      FUN_00437050();

    }

    else {

      puStack_80 = (uint32_t /* width from decompiler */ *)0x45998c;

      FUN_007689e0();

    }

    if (*(int *)(iVar4 + 0x4044) == 0) {

      ppuStack_7c = (uint32_t /* width from decompiler */ **)&param_2;

      puStack_80 = (uint32_t /* width from decompiler */ *)0x4599a1;

      FUN_00437050();

    }

    else {

      ppuStack_7c = (uint32_t /* width from decompiler */ **)&param_2;

      puStack_80 = (uint32_t /* width from decompiler */ *)0x4599af;

      FUN_00768760();

    }

    iVar4 = param_2;

    local_60 = auStack_94;

    FUN_0045c4b0();

    if (0 < iVar4) {

      ppuStack_7c = (uint32_t /* width from decompiler */ **)param_1[8];

      puStack_80 = (uint32_t /* width from decompiler */ *)0x4599db;

      iVar4 = FUN_0045dd60();

      if (iVar4 == 0) {

        local_4 = local_4 & 0xffffff00;

        ppuStack_7c = (uint32_t /* width from decompiler */ **)0x4599f0;

        std::basic_string<char,struct_std::char_traits<char>,class_std::allocator<char>_>::

        ~basic_string<char,struct_std::char_traits<char>,class_std::allocator<char>_>(local_44);

        local_4 = 0xffffffff;

        if (local_50 != '\0') {

          ppuStack_7c = (uint32_t /* width from decompiler */ **)0x459a07;

          FUN_00769e40();

        }

        ExceptionList = local_c;

        return 0;

      }

    }

    local_4 = local_4 & 0xffffff00;

    ppuStack_7c = (uint32_t /* width from decompiler */ **)0x459a2c;

    std::basic_string<char,struct_std::char_traits<char>,class_std::allocator<char>_>::

    ~basic_string<char,struct_std::char_traits<char>,class_std::allocator<char>_>(local_44);

    bVar5 = local_50 == '\0';

  }

  else {

    ppuStack_7c = (uint32_t /* width from decompiler */ **)0xaa3e08;

    puStack_80 = (uint32_t /* width from decompiler */ *)0x3;

    uStack_84 = 0x60;

    pcStack_88 = "..\\palantir/animation/anmTrackMaster_inl.h";

    uStack_8c = 0x4597ad;

    vog_LogMessage();

    bVar5 = local_50 == '\0';

  }

LAB_00459a38:

  local_4 = 0xffffffff;

  if (!bVar5) {

    ppuStack_7c = (uint32_t /* width from decompiler */ **)0x459a43;

    FUN_00769e40();

  }

  ExceptionList = local_c;

  return 0xffffffff;

}
