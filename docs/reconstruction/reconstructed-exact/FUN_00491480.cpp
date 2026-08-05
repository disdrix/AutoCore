// =============================================================================
// FUN_00491480
// -----------------------------------------------------------------------------
// Stable ID: aa_00491480
// Address:   0x00491480  (autoassault.exe, image base 0x400000)
// System:    unknown
// Generated: 2026-07-23 from raw capture (scaffold; refine for important units)
// Exactness: Behavior-preserving rewrite of decompiler control flow. Not modernization.
// Bit-for-bit vs retail EXE: DEFERRED (loaded image may differ slightly).
// =============================================================================

// PURPOSE (auto): Scaffold unit for FUN_00491480 @ 0x00491480
// Stable ID: aa_00491480
// Embedded strings (evidence for future rename):
//   - "black.dds"
//   - "TintTexture"
//   - "DiffuseTexture"
//   - ".dds"
//   - "_tint"
//   - "TintTextureBlending"
// Readability: control flow preserved from Ghidra decompile; types tentative.

// READABILITY (auto CF):
//  - Body size: ~226 non-empty decompiler lines.
//  - Control keywords: if×24, return×1.
//  - Notable callees: FUN_004909d0×8, CONCAT31×6, FUN_0096f3e0×6, FUN_00989e00×6, FUN_0096ef70×4, FUN_0096efd0×4, c_str×4, FUN_004a05c0×2.
//  - Strings: "black.dds"; "TintTexture"; "DiffuseTexture"; ".dds".
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

void __thiscall

FUN_00491480(int param_1,uint32_t /* width from decompiler */ param_2,uint32_t /* width from decompiler */ param_3,uint32_t /* width from decompiler */ param_4,uint32_t /* width from decompiler */ param_5

            )



{

  int *piVar1;

  basic_string<char,struct_std::char_traits<char>,class_std::allocator<char>_> *pbVar2;

  char *pcVar3;

  int iVar4;

  uint uVar5;

  short sVar6;

  uint32_t /* width from decompiler */ uVar7;

  uint8_t local_48 [4];

  basic_string<char,struct_std::char_traits<char>,class_std::allocator<char>_> local_44 [20];

  uint local_30;

  basic_string<char,struct_std::char_traits<char>,class_std::allocator<char>_> local_28 [20];

  uint local_14;

  void *local_c;

  uint8_t *puStack_8;

  uint32_t /* width from decompiler */ local_4;

  

  puStack_8 = &LAB_009a0914;

  local_c = ExceptionList;

  ExceptionList = &local_c;

  if ((DAT_00b03588 & 1) == 0) {

    DAT_00b03588 = DAT_00b03588 | 1;

    local_4 = 0;

    ExceptionList = &local_c;

    std::basic_string<char,struct_std::char_traits<char>,class_std::allocator<char>_>::

    basic_string<char,struct_std::char_traits<char>,class_std::allocator<char>_>

              ((basic_string<char,struct_std::char_traits<char>,class_std::allocator<char>_> *)

               &DAT_00b0356c);

    _atexit((_func_4879 *)&LAB_009c3750);

  }

  if ((DAT_00b03588 & 2) == 0) {

    DAT_00b03588 = DAT_00b03588 | 2;

    local_4 = 1;

    std::basic_string<char,struct_std::char_traits<char>,class_std::allocator<char>_>::

    basic_string<char,struct_std::char_traits<char>,class_std::allocator<char>_>

              ((basic_string<char,struct_std::char_traits<char>,class_std::allocator<char>_> *)

               &DAT_00b03550);

    _atexit((_func_4879 *)&LAB_009c3740);

  }

  local_4 = 0xffffffff;

  sVar6 = (short)param_2;

  if (sVar6 != *(short *)(param_1 + 0xa8)) {

    *(short *)(param_1 + 0xa8) = sVar6;

    FUN_004a05c0(local_44,param_2);

    local_4 = 2;

    if (sVar6 == 0) {

      FUN_0096ef70();

      local_4._0_1_ = 3;

      FUN_00989e00(local_48,"black.dds");

      FUN_0096f3e0(local_48,0);

      FUN_004909d0("TintTexture",param_2,0,0,1);

      if (*(int *)(*(int *)(param_1 + 0xb8) + 0xe4f8) == 0) {

        std::basic_string<char,struct_std::char_traits<char>,class_std::allocator<char>_>::operator=

                  ((basic_string<char,struct_std::char_traits<char>,class_std::allocator<char>_> *)

                   &DAT_00b0356c,"black.dds");

        uVar7 = param_2;

      }

      else {

        iVar4 = *(int *)(**(int **)(*(int *)(*(int *)(param_1 + 0xb8) + 0xe4f8) + 0x3e4) + 0x4c);

        if (iVar4 == 0) {

          piVar1 = &DAT_00d1ed24;

        }

        else {

          piVar1 = (int *)(iVar4 + 4);

        }

        pcVar3 = (char *)*piVar1;

        if ((char *)*piVar1 == (char *)0x0) {

          pcVar3 = PTR_DAT_00afa2bc;

        }

        pbVar2 = (basic_string<char,struct_std::char_traits<char>,class_std::allocator<char>_> *)

                 std::basic_string<char,struct_std::char_traits<char>,class_std::allocator<char>_>::

                 basic_string<char,struct_std::char_traits<char>,class_std::allocator<char>_>

                           (local_28,pcVar3);

        local_4._0_1_ = 4;

        std::basic_string<char,struct_std::char_traits<char>,class_std::allocator<char>_>::operator=

                  ((basic_string<char,struct_std::char_traits<char>,class_std::allocator<char>_> *)

                   &DAT_00b0356c,pbVar2);

        local_4._0_1_ = 3;

        std::basic_string<char,struct_std::char_traits<char>,class_std::allocator<char>_>::

        ~basic_string<char,struct_std::char_traits<char>,class_std::allocator<char>_>(local_28);

        uVar7 = **(uint32_t /* width from decompiler */ **)(*(int *)(*(int *)(param_1 + 0xb8) + 0xe4f8) + 0x3e4);

      }

      FUN_004909d0("DiffuseTexture",uVar7,0,0,1);

      local_4 = CONCAT31(local_4._1_3_,2);

      FUN_0096efd0();

    }

    else if (local_30 < 2) {

      iVar4 = *(int *)(param_1 + 0xac);

      if (iVar4 != 0) {

        piVar1 = (int *)(iVar4 + 8);

        *piVar1 = *piVar1 + -1;

        if (*piVar1 == 0) {

          (**(code **)(*(int *)(iVar4 + 4) + 8))();

        }

        *(uint32_t /* width from decompiler */ *)(param_1 + 0xac) = 0;

      }

    }

    else {

      std::basic_string<char,struct_std::char_traits<char>,class_std::allocator<char>_>::operator=

                ((basic_string<char,struct_std::char_traits<char>,class_std::allocator<char>_> *)

                 &DAT_00b0356c,local_44);

      pcVar3 = std::basic_string<char,struct_std::char_traits<char>,class_std::allocator<char>_>::

               c_str(local_44);

      FUN_00989e00(&param_2,pcVar3);

      iVar4 = FUN_0096f3e0(&param_2,0);

      if (-1 < iVar4) {

        FUN_004909d0("DiffuseTexture",*(uint32_t /* width from decompiler */ *)(param_1 + 0xac),0,0,1);

      }

      uVar5 = std::basic_string<char,struct_std::char_traits<char>,class_std::allocator<char>_>::

              find(local_44,".dds",0);

      if (uVar5 != 0xffffffff) {

        std::basic_string<char,struct_std::char_traits<char>,class_std::allocator<char>_>::insert

                  (local_44,uVar5,"_tint");

        FUN_0096ef70();

        local_4 = CONCAT31(local_4._1_3_,5);

        pcVar3 = std::basic_string<char,struct_std::char_traits<char>,class_std::allocator<char>_>::

                 c_str(local_44);

        FUN_00989e00(local_48,pcVar3);

        iVar4 = FUN_0096f3e0(local_48,0);

        if (-1 < iVar4) {

          FUN_004909d0("TintTexture",param_2,0,0,1);

        }

        local_4 = CONCAT31(local_4._1_3_,2);

        FUN_0096efd0();

      }

    }

    local_4 = 0xffffffff;

    std::basic_string<char,struct_std::char_traits<char>,class_std::allocator<char>_>::

    ~basic_string<char,struct_std::char_traits<char>,class_std::allocator<char>_>(local_44);

  }

  sVar6 = (short)param_4;

  if (sVar6 != *(short *)(param_1 + 0xb0)) {

    *(short *)(param_1 + 0xb0) = sVar6;

    FUN_004a05c0(local_28,param_4);

    local_4 = 6;

    if (sVar6 == 0) {

      FUN_0096ef70();

      local_4._0_1_ = 7;

      FUN_00989e00(&param_4,"black.dds");

      FUN_0096f3e0(&param_4,0);

      FUN_004909d0("TintTextureBlending",param_2,0,0,1);

      if (*(int *)(*(int *)(param_1 + 0xb8) + 0xe4f8) == 0) {

        std::basic_string<char,struct_std::char_traits<char>,class_std::allocator<char>_>::operator=

                  ((basic_string<char,struct_std::char_traits<char>,class_std::allocator<char>_> *)

                   &DAT_00b0356c,"black.dds");

        uVar7 = param_2;

      }

      else {

        iVar4 = *(int *)(**(int **)(*(int *)(*(int *)(param_1 + 0xb8) + 0xe4f8) + 0x3f0) + 0x4c);

        if (iVar4 == 0) {

          piVar1 = &DAT_00d1ed24;

        }

        else {

          piVar1 = (int *)(iVar4 + 4);

        }

        pcVar3 = (char *)*piVar1;

        if ((char *)*piVar1 == (char *)0x0) {

          pcVar3 = PTR_DAT_00afa2bc;

        }

        pbVar2 = (basic_string<char,struct_std::char_traits<char>,class_std::allocator<char>_> *)

                 std::basic_string<char,struct_std::char_traits<char>,class_std::allocator<char>_>::

                 basic_string<char,struct_std::char_traits<char>,class_std::allocator<char>_>

                           (local_44,pcVar3);

        local_4._0_1_ = 8;

        std::basic_string<char,struct_std::char_traits<char>,class_std::allocator<char>_>::operator=

                  ((basic_string<char,struct_std::char_traits<char>,class_std::allocator<char>_> *)

                   &DAT_00b03550,pbVar2);

        local_4._0_1_ = 7;

        std::basic_string<char,struct_std::char_traits<char>,class_std::allocator<char>_>::

        ~basic_string<char,struct_std::char_traits<char>,class_std::allocator<char>_>(local_44);

        uVar7 = **(uint32_t /* width from decompiler */ **)(*(int *)(*(int *)(param_1 + 0xb8) + 0xe4f8) + 0x3f0);

      }

      FUN_004909d0("DiffuseTextureBlending",uVar7,0,0,1);

      local_4 = CONCAT31(local_4._1_3_,6);

      FUN_0096efd0();

    }

    else if (local_14 < 2) {

      iVar4 = *(int *)(param_1 + 0xb4);

      if (iVar4 != 0) {

        piVar1 = (int *)(iVar4 + 8);

        *piVar1 = *piVar1 + -1;

        if (*piVar1 == 0) {

          (**(code **)(*(int *)(iVar4 + 4) + 8))();

        }

        *(uint32_t /* width from decompiler */ *)(param_1 + 0xb4) = 0;

      }

    }

    else {

      std::basic_string<char,struct_std::char_traits<char>,class_std::allocator<char>_>::operator=

                ((basic_string<char,struct_std::char_traits<char>,class_std::allocator<char>_> *)

                 &DAT_00b03550,local_28);

      pcVar3 = std::basic_string<char,struct_std::char_traits<char>,class_std::allocator<char>_>::

               c_str(local_28);

      FUN_00989e00(&param_2,pcVar3);

      iVar4 = FUN_0096f3e0(&param_2,0);

      if (-1 < iVar4) {

        FUN_004909d0("DiffuseTextureBlending",*(uint32_t /* width from decompiler */ *)(param_1 + 0xb4),0,0,1);

      }

      uVar5 = std::basic_string<char,struct_std::char_traits<char>,class_std::allocator<char>_>::

              find(local_28,".dds",0);

      if (uVar5 != 0xffffffff) {

        std::basic_string<char,struct_std::char_traits<char>,class_std::allocator<char>_>::insert

                  (local_28,uVar5,"_tint");

        FUN_0096ef70();

        local_4 = CONCAT31(local_4._1_3_,9);

        pcVar3 = std::basic_string<char,struct_std::char_traits<char>,class_std::allocator<char>_>::

                 c_str(local_28);

        FUN_00989e00(&param_4,pcVar3);

        iVar4 = FUN_0096f3e0(&param_4,0);

        if (-1 < iVar4) {

          FUN_004909d0("TintTextureBlending",param_2,0,0,1);

        }

        local_4 = CONCAT31(local_4._1_3_,6);

        FUN_0096efd0();

      }

    }

    local_4 = 0xffffffff;

    std::basic_string<char,struct_std::char_traits<char>,class_std::allocator<char>_>::

    ~basic_string<char,struct_std::char_traits<char>,class_std::allocator<char>_>(local_28);

  }

  FUN_00490af0(param_5,0,0,1);

  ExceptionList = local_c;

  return;

}
