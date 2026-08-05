// READABILITY (auto CF):
//  - Body size: ~92 non-empty decompiler lines.
//  - Control keywords: if×9, return×3, while×1.
//  - Notable callees: FUN_00769e40×3, CONCAT31, FUN_00436f10, FUN_00437050, FUN_0044cb20, FUN_0046d4e0, FUN_00767120, FUN_007689e0.
//  - Strings: ",99,3

                   ,".
//  - Return sites: 3.

// =============================================================================
// Named_gfxGeometryPieceSkinned
// -----------------------------------------------------------------------------
// Stable ID: aa_009991b0
// Address:   0x009991b0  (autoassault.exe, image base 0x400000)
// System:    unknown
// Generated: 2026-07-23 from raw capture (scaffold; refine for important units)
// Exactness: Behavior-preserving rewrite of decompiler control flow. Not modernization.
// Bit-for-bit vs retail EXE: DEFERRED (loaded image may differ slightly).
// =============================================================================

/*
 * Behavioral notes:
 * String-driven rename evidence: "gfxGeometryPieceSkinned"
 *
 * - Derived from Ghidra decompile; names prefer Ghidra symbols / plate comments.
 * - Remaining FUN_* / DAT_* identifiers are unresolved pending type recovery.
 * - Runtime / differential verification: OPEN unless matrix says otherwise.
 *
 * Readability pass:
 * - undefinedN widths preserved as fixed-width integers where decompiler width is known.
 * - Control flow and call order preserved from authoritative raw.
 */

uint Named_gfxGeometryPieceSkinned(int param_1)



{

  int iVar1;

  int iVar2;

  char cVar3;

  uint uVar4;

  uint32_t /* width from decompiler */ *****pppppuVar5;

  uint uVar6;

  int local_44;

  uint8_t local_40 [12];

  char local_34;

  int local_30;

  int local_2c;

  basic_string<char,struct_std::char_traits<char>,class_std::allocator<char>_> local_28 [4];

  uint32_t /* width from decompiler */ ****local_24 [5];

  uint local_10;

  void *local_c;

  uint8_t *puStack_8;

  uint local_4;

  

  local_4 = 0xffffffff;

  puStack_8 = &LAB_009b3f27;

  local_c = ExceptionList;

  ExceptionList = &local_c;

  stoChunkReader_EnterChunkScope(param_1);

  local_4 = 0;

  if (local_30 != 0x47534b4e) {

    vog_LogMessage("C:\\vog\\1_code\\palantir\\palantir\\graphics\\gfxGeometryPieceSkinned.cpp",99,3

                   ,"Invalid TAG unserializing gfxGeometryPieceSkinned");

    local_4 = 0xffffffff;

    if (local_34 != '\0') {

      FUN_00769e40();

    }

    ExceptionList = local_c;

    return 0xffffffff;

  }

  cVar3 = FUN_00767120();

  if (cVar3 != '\0') {

    local_4 = 0xffffffff;

    if (local_34 != '\0') {

      FUN_00769e40();

    }

    ExceptionList = local_c;

    return 0;

  }

  if (local_2c == 1) {

    uVar6 = gfxGeometryPiece_Unserialize(param_1);

    std::basic_string<char,struct_std::char_traits<char>,class_std::allocator<char>_>::

    basic_string<char,struct_std::char_traits<char>,class_std::allocator<char>_>(local_28);

    local_4 = CONCAT31(local_4._1_3_,1);

    if (*(int *)(param_1 + 0x4044) == 0) {

      uVar4 = FUN_00437050(&local_44);

    }

    else {

      uVar4 = FUN_007689e0(&local_44);

    }

    iVar2 = local_44;

    uVar6 = uVar6 | uVar4;

    FUN_0046d4e0();

    iVar1 = local_44;

    local_44 = iVar2;

    while (local_44 != 0) {

      if (*(int *)(param_1 + 0x4044) == 0) {

        uVar4 = FUN_00436f10();

      }

      else {

        uVar4 = FUN_0076a200();

      }

      uVar6 = uVar6 | uVar4;

      pppppuVar5 = (uint32_t /* width from decompiler */ *****)local_24[0];

      if (local_10 < 0x10) {

        pppppuVar5 = local_24;

      }

      FUN_00989e00(local_40,pppppuVar5);

      FUN_0044cb20();

      iVar1 = local_44 + -1;

      local_44 = iVar1;

    }

    local_4 = local_4 & 0xffffff00;

    local_44 = iVar1;

    std::basic_string<char,struct_std::char_traits<char>,class_std::allocator<char>_>::

    ~basic_string<char,struct_std::char_traits<char>,class_std::allocator<char>_>(local_28);

  }

  else {

    uVar6 = 0xffffffff;

  }

  local_4 = 0xffffffff;

  if (local_34 != '\0') {

    FUN_00769e40();

  }

  ExceptionList = local_c;

  return uVar6;

}
