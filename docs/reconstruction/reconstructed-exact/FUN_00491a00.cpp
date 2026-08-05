// =============================================================================
// FUN_00491a00
// -----------------------------------------------------------------------------
// Stable ID: aa_00491a00
// Address:   0x00491a00  (autoassault.exe, image base 0x400000)
// System:    unknown
// Generated: 2026-07-23 from raw capture (scaffold; refine for important units)
// Exactness: Behavior-preserving rewrite of decompiler control flow. Not modernization.
// Bit-for-bit vs retail EXE: DEFERRED (loaded image may differ slightly).
// =============================================================================

// PURPOSE (auto): Scaffold unit for FUN_00491a00 @ 0x00491a00
// Stable ID: aa_00491a00
// Embedded strings (evidence for future rename):
//   - "black.dds"
//   - "DiffuseTexture"
//   - "DiffuseTextureBlending"
// Readability: control flow preserved from Ghidra decompile; types tentative.

// READABILITY (auto CF):
//  - Body size: ~182 non-empty decompiler lines.
//  - Control keywords: if×20, return×1.
//  - Notable callees: FUN_004909d0×6, CONCAT31×4, FUN_0096f3e0×4, FUN_00989e00×4, FUN_004a05c0×2, FUN_0096ef70×2, FUN_0096efd0×2, _atexit×2.
//  - Strings: "black.dds"; "DiffuseTexture"; "DiffuseTextureBlending".
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

FUN_00491a00(int param_1,uint32_t /* width from decompiler */ param_2,uint32_t /* width from decompiler */ param_3,uint32_t /* width from decompiler */ param_4,uint32_t /* width from decompiler */ param_5

            )



{

  int *piVar1;

  basic_string<char,struct_std::char_traits<char>,class_std::allocator<char>_> *pbVar2;

  char *pcVar3;

  int iVar4;

  short sVar5;

  uint8_t local_48 [4];

  basic_string<char,struct_std::char_traits<char>,class_std::allocator<char>_> local_44 [20];

  uint local_30;

  basic_string<char,struct_std::char_traits<char>,class_std::allocator<char>_> local_28 [20];

  uint local_14;

  void *local_c;

  uint8_t *puStack_8;

  uint32_t /* width from decompiler */ local_4;

  

  puStack_8 = &LAB_009a096c;

  local_c = ExceptionList;

  ExceptionList = &local_c;

  if ((DAT_00b035c4 & 1) == 0) {

    DAT_00b035c4 = DAT_00b035c4 | 1;

    local_4 = 0;

    ExceptionList = &local_c;

    std::basic_string<char,struct_std::char_traits<char>,class_std::allocator<char>_>::

    basic_string<char,struct_std::char_traits<char>,class_std::allocator<char>_>

              ((basic_string<char,struct_std::char_traits<char>,class_std::allocator<char>_> *)

               &DAT_00b035a8);

    _atexit((_func_4879 *)&LAB_009c3770);

  }

  if ((DAT_00b035c4 & 2) == 0) {

    DAT_00b035c4 = DAT_00b035c4 | 2;

    local_4 = 1;

    std::basic_string<char,struct_std::char_traits<char>,class_std::allocator<char>_>::

    basic_string<char,struct_std::char_traits<char>,class_std::allocator<char>_>

              ((basic_string<char,struct_std::char_traits<char>,class_std::allocator<char>_> *)

               &DAT_00b0358c);

    _atexit((_func_4879 *)&LAB_009c3760);

  }

  local_4 = 0xffffffff;

  sVar5 = (short)param_2;

  if (sVar5 != *(short *)(param_1 + 0x98)) {

    *(short *)(param_1 + 0x98) = sVar5;

    FUN_004a05c0(local_44,param_2);

    local_4 = 2;

    if (sVar5 == 0) {

      if (*(int *)(*(int *)(param_1 + 0xb8) + 0xe4f8) == 0) {

        FUN_0096ef70();

        local_4._0_1_ = 4;

        FUN_00989e00(local_48,"black.dds");

        FUN_0096f3e0(local_48,0);

        FUN_004909d0("DiffuseTexture",param_2,0,1,0);

        local_4 = CONCAT31(local_4._1_3_,2);

        FUN_0096efd0();

      }

      else {

        iVar4 = *(int *)(**(int **)(*(int *)(*(int *)(param_1 + 0xb8) + 0xe4f8) + 1000) + 0x4c);

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

        local_4._0_1_ = 3;

        std::basic_string<char,struct_std::char_traits<char>,class_std::allocator<char>_>::operator=

                  ((basic_string<char,struct_std::char_traits<char>,class_std::allocator<char>_> *)

                   &DAT_00b035a8,pbVar2);

        local_4 = CONCAT31(local_4._1_3_,2);

        std::basic_string<char,struct_std::char_traits<char>,class_std::allocator<char>_>::

        ~basic_string<char,struct_std::char_traits<char>,class_std::allocator<char>_>(local_28);

        FUN_004909d0("DiffuseTexture",

                     **(uint32_t /* width from decompiler */ **)(*(int *)(*(int *)(param_1 + 0xb8) + 0xe4f8) + 1000),0,1,0);

      }

    }

    else if (local_30 < 2) {

      iVar4 = *(int *)(param_1 + 0x9c);

      if (iVar4 != 0) {

        piVar1 = (int *)(iVar4 + 8);

        *piVar1 = *piVar1 + -1;

        if (*piVar1 == 0) {

          (**(code **)(*(int *)(iVar4 + 4) + 8))();

        }

        *(uint32_t /* width from decompiler */ *)(param_1 + 0x9c) = 0;

      }

    }

    else {

      std::basic_string<char,struct_std::char_traits<char>,class_std::allocator<char>_>::operator=

                ((basic_string<char,struct_std::char_traits<char>,class_std::allocator<char>_> *)

                 &DAT_00b035a8,local_44);

      pcVar3 = std::basic_string<char,struct_std::char_traits<char>,class_std::allocator<char>_>::

               c_str(local_44);

      FUN_00989e00(&param_2,pcVar3);

      iVar4 = FUN_0096f3e0(&param_2,0);

      if (-1 < iVar4) {

        FUN_004909d0("DiffuseTexture",*(uint32_t /* width from decompiler */ *)(param_1 + 0x9c),0,1,0);

      }

    }

    local_4 = 0xffffffff;

    std::basic_string<char,struct_std::char_traits<char>,class_std::allocator<char>_>::

    ~basic_string<char,struct_std::char_traits<char>,class_std::allocator<char>_>(local_44);

  }

  sVar5 = (short)param_4;

  if (sVar5 != *(short *)(param_1 + 0xa0)) {

    *(short *)(param_1 + 0xa0) = sVar5;

    FUN_004a05c0(local_28,param_4);

    local_4 = 5;

    if (sVar5 == 0) {

      if (*(int *)(*(int *)(param_1 + 0xb8) + 0xe4f8) == 0) {

        FUN_0096ef70();

        local_4._0_1_ = 7;

        FUN_00989e00(&param_4,"black.dds");

        FUN_0096f3e0(&param_4,0);

        FUN_004909d0("DiffuseTextureBlending",param_2,0,1,0);

        local_4 = CONCAT31(local_4._1_3_,5);

        FUN_0096efd0();

      }

      else {

        iVar4 = *(int *)(**(int **)(*(int *)(*(int *)(param_1 + 0xb8) + 0xe4f8) + 0x3f4) + 0x4c);

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

        local_4._0_1_ = 6;

        std::basic_string<char,struct_std::char_traits<char>,class_std::allocator<char>_>::operator=

                  ((basic_string<char,struct_std::char_traits<char>,class_std::allocator<char>_> *)

                   &DAT_00b0358c,pbVar2);

        local_4 = CONCAT31(local_4._1_3_,5);

        std::basic_string<char,struct_std::char_traits<char>,class_std::allocator<char>_>::

        ~basic_string<char,struct_std::char_traits<char>,class_std::allocator<char>_>(local_44);

        FUN_004909d0("DiffuseTextureBlending",

                     **(uint32_t /* width from decompiler */ **)(*(int *)(*(int *)(param_1 + 0xb8) + 0xe4f8) + 0x3f4),0,1,0);

      }

    }

    else if (local_14 < 2) {

      iVar4 = *(int *)(param_1 + 0xa4);

      if (iVar4 != 0) {

        piVar1 = (int *)(iVar4 + 8);

        *piVar1 = *piVar1 + -1;

        if (*piVar1 == 0) {

          (**(code **)(*(int *)(iVar4 + 4) + 8))();

        }

        *(uint32_t /* width from decompiler */ *)(param_1 + 0xa4) = 0;

      }

    }

    else {

      std::basic_string<char,struct_std::char_traits<char>,class_std::allocator<char>_>::operator=

                ((basic_string<char,struct_std::char_traits<char>,class_std::allocator<char>_> *)

                 &DAT_00b0358c,local_28);

      pcVar3 = std::basic_string<char,struct_std::char_traits<char>,class_std::allocator<char>_>::

               c_str(local_28);

      FUN_00989e00(&param_2,pcVar3);

      iVar4 = FUN_0096f3e0(&param_2,0);

      if (-1 < iVar4) {

        FUN_004909d0("DiffuseTextureBlending",*(uint32_t /* width from decompiler */ *)(param_1 + 0xa4),0,1,0);

      }

    }

    local_4 = 0xffffffff;

    std::basic_string<char,struct_std::char_traits<char>,class_std::allocator<char>_>::

    ~basic_string<char,struct_std::char_traits<char>,class_std::allocator<char>_>(local_28);

  }

  FUN_00490af0(param_5,0,1,0);

  ExceptionList = local_c;

  return;

}
