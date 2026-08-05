// =============================================================================
// FUN_0095dc70
// -----------------------------------------------------------------------------
// Stable ID: aa_0095dc70
// Address:   0x0095dc70  (autoassault.exe, image base 0x400000)
// System:    unknown
// Generated: 2026-07-23 from raw capture (scaffold; refine for important units)
// Exactness: Behavior-preserving rewrite of decompiler control flow. Not modernization.
// Bit-for-bit vs retail EXE: DEFERRED (loaded image may differ slightly).
// =============================================================================

// PURPOSE (auto): Scaffold unit for FUN_0095dc70 @ 0x0095dc70
// Stable ID: aa_0095dc70
// Embedded strings (evidence for future rename):
//   - "C:\\vog\\1_code\\palantir\\palantir\\graphics\\gfxBodyMassageMachine.cpp"
//   - "Invalid TAG unserializing phyBoneMaster"
//   - "DEPRECATED bone type detected, reexport files"
//   - "Invalid chunk version (%i) unserializing phyBoneMaster"
// Readability: control flow preserved from Ghidra decompile; types tentative.

// READABILITY (auto CF):
//  - Body size: ~257 non-empty decompiler lines.
//  - Control keywords: if×27, return×3, do×2, while×2, goto×1.
//  - Notable callees: FUN_00437050×9, FUN_00768760×9, stoChunkReader_readF32Array×4, FUN_00449dc0×3, FUN_00769e40×3, vog_LogMessage×3, CONCAT31×2, FUN_00435fe0×2.
//  - Strings: ",0x29d,

                   3,"; ",0x2a4,

                   1,"; "Invalid chunk version (%i) unserializing phyBoneMaster".
//  - Return sites: 3.

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

uint __thiscall FUN_0095dc70(int param_1,int param_2)



{

  uint32_t /* width from decompiler */ uVar1;

  uint uVar2;

  uint uVar3;

  uint uVar4;

  uint uVar5;

  int iVar6;

  uint32_t /* width from decompiler */ *puVar7;

  uint uVar8;

  uint uVar9;

  uint uVar10;

  int *piVar11;

  uint32_t /* width from decompiler */ **local_50;

  int local_4c;

  uint32_t /* width from decompiler */ **local_48;

  uint8_t local_44 [4];

  uint8_t local_40 [12];

  char local_34;

  int local_30;

  int local_2c;

  basic_string<char,struct_std::char_traits<char>,class_std::allocator<char>_> local_28 [4];

  uint32_t /* width from decompiler */ **local_24 [4];

  uint local_14;

  uint local_10;

  void *local_c;

  uint8_t *puStack_8;

  uint local_4;

  

  local_4 = 0xffffffff;

  puStack_8 = &LAB_009b1f9d;

  local_c = ExceptionList;

  ExceptionList = &local_c;

  stoChunkReader_EnterChunkScope(param_1);

  local_4 = 0;

  if (local_30 != 0x424f4e45) {

    vog_LogMessage("C:\\vog\\1_code\\palantir\\palantir\\graphics\\gfxBodyMassageMachine.cpp",0x29d,

                   3,"Invalid TAG unserializing phyBoneMaster");

    local_4 = 0xffffffff;

    if (local_34 != '\0') {

      FUN_00769e40();

    }

    ExceptionList = local_c;

    return 0xffffffff;

  }

  if (local_2c == 1) {

    vog_LogMessage("C:\\vog\\1_code\\palantir\\palantir\\graphics\\gfxBodyMassageMachine.cpp",0x2a4,

                   1,"DEPRECATED bone type detected, reexport files");

    FUN_00449dc0();

    local_4c = *(int *)(param_2 + 0xf4);

    std::basic_string<char,struct_std::char_traits<char>,class_std::allocator<char>_>::

    basic_string<char,struct_std::char_traits<char>,class_std::allocator<char>_>(local_28);

    local_4 = CONCAT31(local_4._1_3_,1);

    uVar2 = FUN_00439a20(param_1);

    uVar3 = 0;

    if (local_14 != 0) {

      do {

        if (local_10 < 0x10) {

          local_48 = local_24;

        }

        else {

          local_48 = local_24[0];

        }

        iVar6 = tolower((int)*(char *)((int)local_48 + uVar3));

        *(char *)((int)local_48 + uVar3) = (char)iVar6;

        uVar3 = uVar3 + 1;

      } while (uVar3 < local_14);

    }

    if (local_10 < 0x10) {

      local_24[0] = local_24;

    }

    puVar7 = (uint32_t /* width from decompiler */ *)FUN_00989e00(local_40,local_24[0]);

    iVar6 = local_4c;

    *(uint32_t /* width from decompiler */ *)(local_4c + 8) = *puVar7;

    puVar7 = (uint32_t /* width from decompiler */ *)(local_4c + 0xc);

    uVar3 = stoChunkReader_readF32Array(param_1);

    local_48 = (uint32_t /* width from decompiler */ **)(local_4c + 0x1c);

    uVar4 = stoChunkReader_readF32Array(param_1);

    *(uint32_t /* width from decompiler */ *)(param_2 + 4) = *puVar7;

    *(uint32_t /* width from decompiler */ *)(param_2 + 8) = *(uint32_t /* width from decompiler */ *)(iVar6 + 0x10);

    *(uint32_t /* width from decompiler */ *)(param_2 + 0xc) = *(uint32_t /* width from decompiler */ *)(iVar6 + 0x14);

    *(uint32_t /* width from decompiler */ *)(param_2 + 0x10) = *(uint32_t /* width from decompiler */ *)(iVar6 + 0x18);

    *(uint32_t /* width from decompiler */ **)(param_2 + 0x14) = *local_48;

    *(uint32_t /* width from decompiler */ **)(param_2 + 0x18) = local_48[1];

    *(uint32_t /* width from decompiler */ **)(param_2 + 0x1c) = local_48[2];

    if (*(int *)(param_1 + 0x4044) == 0) {

      uVar8 = FUN_00437050(&local_50);

    }

    else {

      uVar8 = FUN_00768760(&local_50);

    }

    *(uint32_t /* width from decompiler */ ***)(param_2 + 0x148) = local_50;

    if (*(int *)(param_1 + 0x4044) == 0) {

      uVar9 = FUN_00437050(&local_50);

    }

    else {

      uVar9 = FUN_00768760(&local_50);

    }

    *(uint32_t /* width from decompiler */ ***)(param_2 + 0x14c) = local_50;

    if (*(int *)(param_1 + 0x4044) == 0) {

      uVar5 = FUN_00437050(&local_50);

    }

    else {

      uVar5 = FUN_00768760(&local_50);

    }

    uVar5 = uVar2 | uVar3 | uVar4 | uVar8 | uVar9 | uVar5;

    *(uint32_t /* width from decompiler */ ***)(param_2 + 0x150) = local_50;

    FUN_0096de80();

  }

  else {

    if (local_2c != 2) {

      if (local_2c != 3) {

        uVar1 = FUN_0076cec0(&local_48,"Invalid chunk version (%i) unserializing phyBoneMaster",

                             local_2c);

        vog_LogMessage("C:\\vog\\1_code\\palantir\\palantir\\graphics\\gfxBodyMassageMachine.cpp",

                       0x318,3,uVar1);

        local_4 = 0xffffffff;

        if (local_34 != '\0') {

          FUN_00769e40();

        }

        ExceptionList = local_c;

        return 0xffffffff;

      }

      FUN_00449dc0();

      iVar6 = *(int *)(param_2 + 0xf4);

      uVar2 = phyBoneSharedData_unserialize(iVar6);

      *(uint32_t /* width from decompiler */ *)(param_2 + 4) = *(uint32_t /* width from decompiler */ *)(iVar6 + 0xc);

      *(uint32_t /* width from decompiler */ *)(param_2 + 8) = *(uint32_t /* width from decompiler */ *)(iVar6 + 0x10);

      *(uint32_t /* width from decompiler */ *)(param_2 + 0xc) = *(uint32_t /* width from decompiler */ *)(iVar6 + 0x14);

      *(uint32_t /* width from decompiler */ *)(param_2 + 0x10) = *(uint32_t /* width from decompiler */ *)(iVar6 + 0x18);

      *(uint32_t /* width from decompiler */ *)(param_2 + 0x14) = *(uint32_t /* width from decompiler */ *)(iVar6 + 0x1c);

      *(uint32_t /* width from decompiler */ *)(param_2 + 0x18) = *(uint32_t /* width from decompiler */ *)(iVar6 + 0x20);

      *(uint32_t /* width from decompiler */ *)(param_2 + 0x1c) = *(uint32_t /* width from decompiler */ *)(iVar6 + 0x24);

      if (*(int *)(param_1 + 0x4044) == 0) {

        uVar3 = FUN_00437050(&local_50);

      }

      else {

        uVar3 = FUN_00768760(&local_50);

      }

      *(uint32_t /* width from decompiler */ ***)(param_2 + 0x148) = local_50;

      if (*(int *)(param_1 + 0x4044) == 0) {

        uVar4 = FUN_00437050(&local_50);

      }

      else {

        uVar4 = FUN_00768760(&local_50);

      }

      *(uint32_t /* width from decompiler */ ***)(param_2 + 0x14c) = local_50;

      if (*(int *)(param_1 + 0x4044) == 0) {

        uVar5 = FUN_00437050(&local_50);

      }

      else {

        uVar5 = FUN_00768760(&local_50);

      }

      uVar5 = uVar2 | uVar3 | uVar4 | uVar5;

      *(uint32_t /* width from decompiler */ ***)(param_2 + 0x150) = local_50;

      if (*(int *)(param_1 + 0x4044) == 0) {

        uVar2 = FUN_00435fe0(&local_4c);

        uVar5 = uVar5 | uVar2;

        *(int *)(param_2 + 0x154) = local_4c;

      }

      else {

        uVar2 = FUN_00767fd0(&local_4c);

        uVar5 = uVar5 | uVar2;

        *(int *)(param_2 + 0x154) = local_4c;

      }

      goto LAB_0095e246;

    }

    FUN_00449dc0();

    local_4c = *(int *)(param_2 + 0xf4);

    std::basic_string<char,struct_std::char_traits<char>,class_std::allocator<char>_>::

    basic_string<char,struct_std::char_traits<char>,class_std::allocator<char>_>(local_28);

    local_4 = CONCAT31(local_4._1_3_,2);

    uVar2 = FUN_00439a20(param_1);

    uVar3 = 0;

    if (local_14 != 0) {

      do {

        if (local_10 < 0x10) {

          local_50 = local_24;

        }

        else {

          local_50 = local_24[0];

        }

        iVar6 = tolower((int)*(char *)((int)local_50 + uVar3));

        *(char *)((int)local_50 + uVar3) = (char)iVar6;

        uVar3 = uVar3 + 1;

      } while (uVar3 < local_14);

    }

    if (local_10 < 0x10) {

      local_24[0] = local_24;

    }

    puVar7 = (uint32_t /* width from decompiler */ *)FUN_00989e00(local_44,local_24[0]);

    iVar6 = local_4c;

    *(uint32_t /* width from decompiler */ *)(local_4c + 8) = *puVar7;

    puVar7 = (uint32_t /* width from decompiler */ *)(local_4c + 0xc);

    uVar3 = stoChunkReader_readF32Array(param_1);

    local_50 = (uint32_t /* width from decompiler */ **)(local_4c + 0x1c);

    uVar4 = stoChunkReader_readF32Array(param_1);

    *(uint32_t /* width from decompiler */ *)(param_2 + 4) = *puVar7;

    *(uint32_t /* width from decompiler */ *)(param_2 + 8) = *(uint32_t /* width from decompiler */ *)(iVar6 + 0x10);

    *(uint32_t /* width from decompiler */ *)(param_2 + 0xc) = *(uint32_t /* width from decompiler */ *)(iVar6 + 0x14);

    *(uint32_t /* width from decompiler */ *)(param_2 + 0x10) = *(uint32_t /* width from decompiler */ *)(iVar6 + 0x18);

    *(uint32_t /* width from decompiler */ **)(param_2 + 0x14) = *local_50;

    *(uint32_t /* width from decompiler */ **)(param_2 + 0x18) = local_50[1];

    *(uint32_t /* width from decompiler */ **)(param_2 + 0x1c) = local_50[2];

    if (*(int *)(param_1 + 0x4044) == 0) {

      uVar8 = FUN_00437050(&local_50);

    }

    else {

      uVar8 = FUN_00768760(&local_50);

    }

    *(uint32_t /* width from decompiler */ ***)(param_2 + 0x148) = local_50;

    if (*(int *)(param_1 + 0x4044) == 0) {

      uVar9 = FUN_00437050(&local_50);

    }

    else {

      uVar9 = FUN_00768760(&local_50);

    }

    *(uint32_t /* width from decompiler */ ***)(param_2 + 0x14c) = local_50;

    if (*(int *)(param_1 + 0x4044) == 0) {

      uVar10 = FUN_00437050(&local_50);

    }

    else {

      uVar10 = FUN_00768760(&local_50);

    }

    *(uint32_t /* width from decompiler */ ***)(param_2 + 0x150) = local_50;

    if (*(int *)(param_1 + 0x4044) == 0) {

      uVar5 = FUN_00435fe0(&local_48);

    }

    else {

      uVar5 = FUN_00767fd0(&local_48);

    }

    uVar5 = uVar2 | uVar3 | uVar4 | uVar8 | uVar9 | uVar10 | uVar5;

    *(uint32_t /* width from decompiler */ ***)(param_2 + 0x154) = local_48;

    iVar6 = FUN_0076a900();

    if (iVar6 != 0) {

      piVar11 = (int *)FUN_00467690(iVar6);

      iVar6 = local_4c;

      *(int **)(local_4c + 0x80) = piVar11;

      if (piVar11 != (int *)0x0) {

        uVar2 = (**(code **)(*piVar11 + 0x10))(param_1);

        uVar5 = uVar5 | uVar2;

        if (*(float *)(param_2 + 0x154) == g_flZero) {

          *(uint32_t /* width from decompiler */ *)(param_2 + 0x154) = *(uint32_t /* width from decompiler */ *)(*(int *)(iVar6 + 0x80) + 4);

        }

      }

    }

  }

  local_4 = local_4 & 0xffffff00;

  std::basic_string<char,struct_std::char_traits<char>,class_std::allocator<char>_>::

  ~basic_string<char,struct_std::char_traits<char>,class_std::allocator<char>_>(local_28);

LAB_0095e246:

  local_4 = 0xffffffff;

  if (local_34 != '\0') {

    FUN_00769e40();

  }

  ExceptionList = local_c;

  return uVar5;

}
