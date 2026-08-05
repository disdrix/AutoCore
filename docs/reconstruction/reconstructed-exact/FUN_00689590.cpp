// =============================================================================
// FUN_00689590
// -----------------------------------------------------------------------------
// Stable ID: aa_00689590
// Address:   0x00689590  (autoassault.exe, image base 0x400000)
// System:    unknown
// Generated: 2026-07-23 from raw capture (scaffold; refine for important units)
// Exactness: Behavior-preserving rewrite of decompiler control flow. Not modernization.
// Bit-for-bit vs retail EXE: DEFERRED (loaded image may differ slightly).
// =============================================================================

// PURPOSE (auto): Scaffold unit for FUN_00689590 @ 0x00689590
// Stable ID: aa_00689590
// Embedded strings (evidence for future rename):
//   - "malformed texture coord info"
//   - "premature end of file reached parsing texture coordinate info"
// Readability: control flow preserved from Ghidra decompile; types tentative.

// READABILITY (auto CF):
//  - Body size: ~183 non-empty decompiler lines.
//  - Control keywords: if×10, while×7, do×6, return×3, switch×1.
//  - Notable callees: FUN_00699ee0×5, FUN_00699ed0×3, FUN_006874b0×2, _CxxThrowException×2, CONCAT31, FUN_00685ee0, FUN_00685f40, FUN_00689590.
//  - Strings: "malformed texture coord info".
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

void __thiscall FUN_00689590(int param_1,uint *param_2)



{

  uint32_t /* width from decompiler */ *puVar1;

  int iVar2;

  uint32_t /* width from decompiler */ uVar3;

  void *pvVar4;

  basic_string<char,struct_std::char_traits<char>,class_std::allocator<char>_> *pbVar5;

  uint uVar6;

  int iVar7;

  float10 fVar8;

  uint8_t auStack_fc [16];

  undefined **ppuStack_ec;

  int local_d0;

  basic_string<char,struct_std::char_traits<char>,class_std::allocator<char>_> local_cc [28];

  basic_string<char,struct_std::char_traits<char>,class_std::allocator<char>_> local_b0 [28];

  basic_string<char,struct_std::char_traits<char>,class_std::allocator<char>_> local_94 [28];

  basic_string<char,struct_std::char_traits<char>,class_std::allocator<char>_> local_78 [28];

  uint8_t local_5c [40];

  uint8_t local_34 [40];

  void *local_c;

  uint8_t *puStack_8;

  uint32_t /* width from decompiler */ local_4;

  

  local_4 = 0xffffffff;

  puStack_8 = &LAB_009aa0f9;

  local_c = ExceptionList;

  ExceptionList = &local_c;

  puVar1 = operator_new(0x54);

  local_4 = 0;

  if (puVar1 == (uint32_t /* width from decompiler */ *)0x0) {

    puVar1 = (uint32_t /* width from decompiler */ *)0x0;

  }

  else {

    *puVar1 = 0;

    puVar1[1] = 0;

    puVar1[2] = 0;

    puVar1[3] = 0;

    puVar1[4] = 0;

    puVar1[5] = 0;

    std::basic_string<char,struct_std::char_traits<char>,class_std::allocator<char>_>::

    basic_string<char,struct_std::char_traits<char>,class_std::allocator<char>_>

              ((basic_string<char,struct_std::char_traits<char>,class_std::allocator<char>_> *)

               (puVar1 + 6));

    puVar1[0xd] = 0x3f800000;

    puVar1[0xe] = 0x3f800000;

    puVar1[0xf] = 0;

    puVar1[0x10] = 0x3f800000;

    puVar1[0x11] = 0;

    puVar1[0x12] = 0;

    puVar1[0x13] = 0x3f800000;

    puVar1[0x14] = 0;

  }

  *(uint32_t /* width from decompiler */ **)(param_1 + 0x4c) = puVar1;

  local_4 = 0xffffffff;

  iVar2 = FUN_00699ee0();

  while( true ) {

    switch(iVar2) {

    case 0x2712:

      uVar3 = FUN_00699ee0();

      **(uint32_t /* width from decompiler */ **)(param_1 + 0x4c) = uVar3;

      if (0 < **(int **)(param_1 + 0x4c)) {

        pvVar4 = operator_new__(**(int **)(param_1 + 0x4c) << 5);

        *(void **)(*(int *)(param_1 + 0x4c) + 4) = pvVar4;

        local_d0 = 0;

        if (0 < **(int **)(param_1 + 0x4c)) {

          do {

            iVar7 = local_d0 << 5;

            iVar2 = 8;

            do {

              fVar8 = (float10)FUN_00699ed0();

              *(float *)(*(int *)(*(int *)(param_1 + 0x4c) + 4) + iVar7) = (float)fVar8;

              iVar7 = iVar7 + 4;

              iVar2 = iVar2 + -1;

            } while (iVar2 != 0);

            local_d0 = local_d0 + 1;

          } while (local_d0 < **(int **)(param_1 + 0x4c));

        }

      }

      break;

    case 0x2713:

      uVar3 = FUN_00699ee0();

      *(uint32_t /* width from decompiler */ *)(*(int *)(param_1 + 0x4c) + 8) = uVar3;

      iVar2 = *(int *)(*(int *)(param_1 + 0x4c) + 8);

      if (0 < iVar2) {

        pvVar4 = operator_new__(iVar2 << 5);

        *(void **)(*(int *)(param_1 + 0x4c) + 0xc) = pvVar4;

        local_d0 = 0;

        if (0 < *(int *)(*(int *)(param_1 + 0x4c) + 8)) {

          do {

            uVar6 = 0;

            iVar2 = local_d0 << 5;

            do {

              fVar8 = (float10)FUN_00699ed0();

              *(float *)(*(int *)(*(int *)(param_1 + 0x4c) + 0xc) + iVar2) = (float)fVar8;

              if (((uVar6 & 1) != 0) && (DAT_00d08e55 != '\0')) {

                iVar7 = *(int *)(*(int *)(param_1 + 0x4c) + 0xc);

                *(float *)(iVar7 + iVar2) = -*(float *)(iVar7 + iVar2);

              }

              uVar6 = uVar6 + 1;

              iVar2 = iVar2 + 4;

            } while ((int)uVar6 < 8);

            local_d0 = local_d0 + 1;

          } while (local_d0 < *(int *)(*(int *)(param_1 + 0x4c) + 8));

        }

      }

      break;

    case 0x2714:

      uVar3 = FUN_00699ee0();

      *(uint32_t /* width from decompiler */ *)(*(int *)(param_1 + 0x4c) + 0x10) = uVar3;

      iVar2 = *(int *)(*(int *)(param_1 + 0x4c) + 0x10);

      if (0 < iVar2) {

        pvVar4 = operator_new__(iVar2 << 5);

        *(void **)(*(int *)(param_1 + 0x4c) + 0x14) = pvVar4;

        local_d0 = 0;

        if (0 < *(int *)(*(int *)(param_1 + 0x4c) + 0x10)) {

          do {

            iVar7 = local_d0 << 5;

            iVar2 = 8;

            do {

              fVar8 = (float10)FUN_00699ed0();

              *(float *)(*(int *)(*(int *)(param_1 + 0x4c) + 0x14) + iVar7) = (float)fVar8;

              iVar7 = iVar7 + 4;

              iVar2 = iVar2 + -1;

            } while (iVar2 != 0);

            local_d0 = local_d0 + 1;

          } while (local_d0 < *(int *)(*(int *)(param_1 + 0x4c) + 0x10));

        }

      }

      break;

    case 0x2715:

      FUN_00699f00(auStack_fc);

      FUN_00685ee0();

      local_4 = 1;

      pbVar5 = (basic_string<char,struct_std::char_traits<char>,class_std::allocator<char>_> *)

               FUN_00685f40();

      local_4._0_1_ = 2;

      std::basic_string<char,struct_std::char_traits<char>,class_std::allocator<char>_>::operator=

                ((basic_string<char,struct_std::char_traits<char>,class_std::allocator<char>_> *)

                 (*(int *)(param_1 + 0x4c) + 0x18),pbVar5);

      local_4 = CONCAT31(local_4._1_3_,1);

      std::basic_string<char,struct_std::char_traits<char>,class_std::allocator<char>_>::

      ~basic_string<char,struct_std::char_traits<char>,class_std::allocator<char>_>(local_78);

      local_4 = 0xffffffff;

      std::basic_string<char,struct_std::char_traits<char>,class_std::allocator<char>_>::

      ~basic_string<char,struct_std::char_traits<char>,class_std::allocator<char>_>(local_cc);

      break;

    case 0x2716:

      uVar6 = *param_2;

      *param_2 = uVar6 + 1;

      *(bool *)(param_1 + 0x69) = *(char *)(uVar6 + param_2[2]) != '\0';

      break;

    case 0x2717:

      uVar6 = *param_2;

      *param_2 = uVar6 + 1;

      *(bool *)(param_1 + 0x68) = *(char *)(uVar6 + param_2[2]) != '\0';

      break;

    default:

      std::basic_string<char,struct_std::char_traits<char>,class_std::allocator<char>_>::

      basic_string<char,struct_std::char_traits<char>,class_std::allocator<char>_>

                (local_94,"malformed texture coord info");

      local_4 = 3;

      ppuStack_ec = (undefined **)0x689922;

      FUN_006874b0();

                    /* WARNING: Subroutine does not return */

      ppuStack_ec = &switchD_0068963e::switchdataD_00689934;

      _CxxThrowException(local_34,(ThrowInfo *)&DAT_00ac9e00);

    }

    if ((param_2[2] == 0) || (param_2[3] - param_2[2] <= *param_2)) break;

    iVar2 = FUN_00699ee0();

    if (iVar2 == 0x2711) {

      ExceptionList = local_c;

      return;

    }

  }

  std::basic_string<char,struct_std::char_traits<char>,class_std::allocator<char>_>::

  basic_string<char,struct_std::char_traits<char>,class_std::allocator<char>_>

            (local_b0,"premature end of file reached parsing texture coordinate info");

  local_4 = 4;

  ppuStack_ec = (undefined **)0x6898e4;

  FUN_006874b0();

                    /* WARNING: Subroutine does not return */

  ppuStack_ec = (undefined **)0x6898f6;

  _CxxThrowException(local_5c,(ThrowInfo *)&DAT_00ac9e00);

}
