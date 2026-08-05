// READABILITY (auto CF):
//  - Body size: ~140 non-empty decompiler lines.
//  - Control keywords: if×16, return×4, for×2, do×1, goto×1, while×1.
//  - Notable callees: FUN_00769e40×4, FUN_00436f10×2, FUN_0076a200×2, FUN_00989e00×2, CONCAT31, FUN_00437050, FUN_0073ecf0, FUN_0073efc0.
//  - Strings: "Invalid chunk version unserializing gfxMorphWeightArrayImpl"; "Invalid TAG unserializing gfxMorphWeightArrayImpl".
//  - Return sites: 4.

// =============================================================================
// Named_gfxMorphWeightArrayImpl_0073efc0
// -----------------------------------------------------------------------------
// Stable ID: aa_0073efc0
// Address:   0x0073efc0  (autoassault.exe, image base 0x400000)
// System:    unknown
// Generated: 2026-07-23 from raw capture (scaffold; refine for important units)
// Exactness: Behavior-preserving rewrite of decompiler control flow. Not modernization.
// Bit-for-bit vs retail EXE: DEFERRED (loaded image may differ slightly).
// =============================================================================

/*
 * Behavioral notes:
 * String-driven rename evidence: "gfxMorphWeightArrayImpl"
 *
 * - Derived from Ghidra decompile; names prefer Ghidra symbols / plate comments.
 * - Remaining FUN_* / DAT_* identifiers are unresolved pending type recovery.
 * - Runtime / differential verification: OPEN unless matrix says otherwise.
 *
 * Readability pass:
 * - undefinedN widths preserved as fixed-width integers where decompiler width is known.
 * - Control flow and call order preserved from authoritative raw.
 */

uint32_t /* width from decompiler */ __thiscall Named_gfxMorphWeightArrayImpl_0073efc0(int param_1,int param_2)



{

  uint *puVar1;

  int iVar2;

  uint32_t /* width from decompiler */ *puVar3;

  uint32_t /* width from decompiler */ ***pppuVar4;

  uint uVar5;

  uint32_t /* width from decompiler */ *puVar6;

  uint32_t /* width from decompiler */ uVar7;

  char *pcVar8;

  int local_4c;

  uint32_t /* width from decompiler */ *local_48;

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

  puStack_8 = &LAB_009b193e;

  local_c = ExceptionList;

  ExceptionList = &local_c;

  stoChunkReader_EnterChunkScope(param_1);

  local_4 = 0;

  if (local_30 == 0x4d574754) {

    if (local_2c == 1) {

      std::basic_string<char,struct_std::char_traits<char>,class_std::allocator<char>_>::

      basic_string<char,struct_std::char_traits<char>,class_std::allocator<char>_>(local_28);

      local_4 = CONCAT31(local_4._1_3_,1);

      if (*(int *)(param_1 + 0x4044) == 0) {

        iVar2 = FUN_00436f10();

      }

      else {

        iVar2 = FUN_0076a200();

      }

      if (iVar2 < 0) {

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

      pppuVar4 = (uint32_t /* width from decompiler */ ***)local_24[0];

      if (local_10 < 0x10) {

        pppuVar4 = local_24;

      }

      puVar3 = (uint32_t /* width from decompiler */ *)FUN_00989e00(local_44,pppuVar4);

      *(uint32_t /* width from decompiler */ *)(param_2 + 0x18) = *puVar3;

      puVar1 = (uint *)(param_2 + 0x14);

      if (*(int *)(param_1 + 0x4044) == 0) {

        iVar2 = FUN_00437050(puVar1);

      }

      else {

        iVar2 = FUN_00768760(puVar1);

      }

      if (-1 < iVar2) {

        FUN_0073ecf0(*(uint32_t /* width from decompiler */ *)(param_2 + 0x18),0);

        iVar2 = stoChunkReader_readF32Array(param_1);

        if (-1 < iVar2) {

          local_4c = 0;

          if (0 < (int)*puVar1) {

            local_48 = (uint32_t /* width from decompiler */ *)(*(int *)(param_2 + 8) + 0xc);

            do {

              if (*(int *)(param_1 + 0x4044) == 0) {

                iVar2 = FUN_00436f10();

              }

              else {

                iVar2 = FUN_0076a200();

              }

              if (iVar2 < 0) goto LAB_0073f111;

              pppuVar4 = (uint32_t /* width from decompiler */ ***)local_24[0];

              if (local_10 < 0x10) {

                pppuVar4 = local_24;

              }

              puVar3 = (uint32_t /* width from decompiler */ *)FUN_00989e00(local_40,pppuVar4);

              *local_48 = *puVar3;

              local_4c = local_4c + 1;

              local_48 = local_48 + 4;

            } while (local_4c < (int)*puVar1);

          }

          puVar3 = *(uint32_t /* width from decompiler */ **)(param_2 + 0x10);

          puVar6 = *(uint32_t /* width from decompiler */ **)(param_2 + 0xc);

          for (uVar5 = *puVar1 & 0x3fffffff; uVar5 != 0; uVar5 = uVar5 - 1) {

            *puVar6 = *puVar3;

            puVar3 = puVar3 + 1;

            puVar6 = puVar6 + 1;

          }

          for (iVar2 = 0; iVar2 != 0; iVar2 = iVar2 + -1) {

            *(uint8_t *)puVar6 = *(uint8_t *)puVar3;

            puVar3 = (uint32_t /* width from decompiler */ *)((int)puVar3 + 1);

            puVar6 = (uint32_t /* width from decompiler */ *)((int)puVar6 + 1);

          }

          uVar7 = *(uint32_t /* width from decompiler */ *)(param_1 + 0x402c);

          local_4 = local_4 & 0xffffff00;

          std::basic_string<char,struct_std::char_traits<char>,class_std::allocator<char>_>::

          ~basic_string<char,struct_std::char_traits<char>,class_std::allocator<char>_>(local_28);

          local_4 = 0xffffffff;

          if (local_34 != '\0') {

            FUN_00769e40();

          }

          ExceptionList = local_c;

          return uVar7;

        }

      }

LAB_0073f111:

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

    pcVar8 = "Invalid chunk version unserializing gfxMorphWeightArrayImpl";

    uVar7 = 0xff;

  }

  else {

    pcVar8 = "Invalid TAG unserializing gfxMorphWeightArrayImpl";

    uVar7 = 0xd6;

  }

  vog_LogMessage("C:\\vog\\1_code\\palantir\\palantir\\graphics\\gfxMorphWeightArrayImpl.cpp",uVar7,

                 3,pcVar8);

  local_4 = 0xffffffff;

  if (local_34 != '\0') {

    FUN_00769e40();

  }

  ExceptionList = local_c;

  return 0xffffffff;

}
