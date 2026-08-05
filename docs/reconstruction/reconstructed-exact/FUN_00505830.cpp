// =============================================================================
// FUN_00505830
// -----------------------------------------------------------------------------
// Stable ID: aa_00505830
// Address:   0x00505830  (autoassault.exe, image base 0x400000)
// System:    unknown
// Generated: 2026-07-23 from raw capture (scaffold; refine for important units)
// Exactness: Behavior-preserving rewrite of decompiler control flow. Not modernization.
// Bit-for-bit vs retail EXE: DEFERRED (loaded image may differ slightly).
// =============================================================================

// PURPOSE (auto): Scaffold unit for FUN_00505830 @ 0x00505830
// Stable ID: aa_00505830
// No high-value strings recovered; name via xrefs/callers in follow-up.
// Readability: control flow preserved from Ghidra decompile; types tentative.

// READABILITY (auto CF):
//  - Body size: ~174 non-empty decompiler lines.
//  - Control keywords: if×9, return×7, do×4, for×4, while×4, goto×1.
//  - Notable callees: FUN_0043ae50×2, c_str×2, CONCAT31, FUN_004395d0, FUN_0044ab90, FUN_00505830, _stricmp, atof.
//  - Return sites: 7.

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

float10 __thiscall FUN_00505830(int param_1,char *param_2)



{

  int *piVar1;

  int iVar2;

  float fVar3;

  char *_Str1;

  int iVar4;

  char *pcVar5;

  basic_string<char,struct_std::char_traits<char>,class_std::allocator<char>_> *pbVar6;

  int *piVar7;

  double dVar8;

  int *local_98;

  int *local_94;

  basic_string<char,struct_std::char_traits<char>,class_std::allocator<char>_> *local_88;

  basic_string<char,struct_std::char_traits<char>,class_std::allocator<char>_> *local_84;

  basic_string<char,struct_std::char_traits<char>,class_std::allocator<char>_> local_7c [28];

  basic_string<char,struct_std::char_traits<char>,class_std::allocator<char>_> local_60 [28];

  basic_string<char,struct_std::char_traits<char>,class_std::allocator<char>_> local_44 [28];

  basic_string<char,struct_std::char_traits<char>,class_std::allocator<char>_> local_28 [28];

  void *local_c;

  uint8_t *puStack_8;

  int local_4;

  

  local_4 = 0xffffffff;

  puStack_8 = &LAB_009a30aa;

  local_c = ExceptionList;

  ExceptionList = &local_c;

  FUN_0044ab90(*(int *)(param_1 + 0x48) + 0x7c);

  local_4._1_3_ = 0;

  piVar7 = local_98;

  do {

    if (piVar7 == local_94) {

      local_4 = 0xffffffff;

      fVar3 = g_flOne;

      if (local_98 != (int *)0x0) {

        if (local_98 != local_94) {

          piVar7 = local_98 + 2;

          do {

            iVar4 = *piVar7;

            if (iVar4 != 0) {

              iVar2 = piVar7[1];

              for (; iVar4 != iVar2; iVar4 = iVar4 + 0x38) {

                FUN_0043ae50(0);

              }

                    /* WARNING: Subroutine does not return */

              operator_delete((void *)*piVar7);

            }

            *piVar7 = 0;

            piVar7[1] = 0;

            piVar7[2] = 0;

            piVar1 = piVar7 + 3;

            piVar7 = piVar7 + 5;

          } while (piVar1 != local_94);

        }

                    /* WARNING: Subroutine does not return */

        operator_delete(local_98);

      }

LAB_00505a67:

      ExceptionList = local_c;

      return (float10)fVar3;

    }

    local_4._0_1_ = 0;

    FUN_004395d0(piVar7 + 1);

    local_4._0_1_ = 1;

    for (pbVar6 = local_88; pbVar6 != local_84; pbVar6 = pbVar6 + 0x38) {

      std::basic_string<char,struct_std::char_traits<char>,class_std::allocator<char>_>::

      basic_string<char,struct_std::char_traits<char>,class_std::allocator<char>_>(local_44,pbVar6);

      local_4._0_1_ = 2;

      std::basic_string<char,struct_std::char_traits<char>,class_std::allocator<char>_>::

      basic_string<char,struct_std::char_traits<char>,class_std::allocator<char>_>

                (local_28,pbVar6 + 0x1c);

      local_4._0_1_ = 3;

      std::basic_string<char,struct_std::char_traits<char>,class_std::allocator<char>_>::

      basic_string<char,struct_std::char_traits<char>,class_std::allocator<char>_>

                (local_7c,local_44);

      local_4._0_1_ = 4;

      std::basic_string<char,struct_std::char_traits<char>,class_std::allocator<char>_>::

      basic_string<char,struct_std::char_traits<char>,class_std::allocator<char>_>

                (local_60,local_28);

      local_4._0_1_ = 5;

      pcVar5 = param_2;

      _Str1 = std::basic_string<char,struct_std::char_traits<char>,class_std::allocator<char>_>::

              c_str(local_7c);

      iVar4 = _stricmp(_Str1,pcVar5);

      if (iVar4 == 0) {

        pcVar5 = std::basic_string<char,struct_std::char_traits<char>,class_std::allocator<char>_>::

                 c_str(local_60);

        dVar8 = atof(pcVar5);

        local_4._0_1_ = 4;

        std::basic_string<char,struct_std::char_traits<char>,class_std::allocator<char>_>::

        ~basic_string<char,struct_std::char_traits<char>,class_std::allocator<char>_>(local_60);

        local_4._0_1_ = 3;

        std::basic_string<char,struct_std::char_traits<char>,class_std::allocator<char>_>::

        ~basic_string<char,struct_std::char_traits<char>,class_std::allocator<char>_>(local_7c);

        local_4._0_1_ = 6;

        std::basic_string<char,struct_std::char_traits<char>,class_std::allocator<char>_>::

        ~basic_string<char,struct_std::char_traits<char>,class_std::allocator<char>_>(local_28);

        local_4 = CONCAT31(local_4._1_3_,1);

        std::basic_string<char,struct_std::char_traits<char>,class_std::allocator<char>_>::

        ~basic_string<char,struct_std::char_traits<char>,class_std::allocator<char>_>(local_44);

        pbVar6 = local_88;

        if (local_88 !=

            (basic_string<char,struct_std::char_traits<char>,class_std::allocator<char>_> *)0x0) {

          do {

            local_4._0_1_ = 7;

            std::basic_string<char,struct_std::char_traits<char>,class_std::allocator<char>_>::

            ~basic_string<char,struct_std::char_traits<char>,class_std::allocator<char>_>

                      (pbVar6 + 0x1c);

            local_4 = (uint)local_4._1_3_ << 8;

            std::basic_string<char,struct_std::char_traits<char>,class_std::allocator<char>_>::

            ~basic_string<char,struct_std::char_traits<char>,class_std::allocator<char>_>(pbVar6);

            pbVar6 = pbVar6 + 0x38;

          } while (pbVar6 != local_84);

                    /* WARNING: Subroutine does not return */

          operator_delete(local_88);

        }

        local_4 = 0xffffffff;

        fVar3 = (float)dVar8;

        if (local_98 != (int *)0x0) {

          piVar7 = local_98 + 2;

          do {

            iVar4 = *piVar7;

            if (iVar4 != 0) {

              iVar2 = piVar7[1];

              for (; iVar4 != iVar2; iVar4 = iVar4 + 0x38) {

                FUN_0043ae50(0);

              }

                    /* WARNING: Subroutine does not return */

              operator_delete((void *)*piVar7);

            }

            *piVar7 = 0;

            piVar7[1] = 0;

            piVar7[2] = 0;

            piVar1 = piVar7 + 3;

            piVar7 = piVar7 + 5;

          } while (piVar1 != local_94);

                    /* WARNING: Subroutine does not return */

          operator_delete(local_98);

        }

        goto LAB_00505a67;

      }

      local_4._0_1_ = 4;

      std::basic_string<char,struct_std::char_traits<char>,class_std::allocator<char>_>::

      ~basic_string<char,struct_std::char_traits<char>,class_std::allocator<char>_>(local_60);

      local_4._0_1_ = 3;

      std::basic_string<char,struct_std::char_traits<char>,class_std::allocator<char>_>::

      ~basic_string<char,struct_std::char_traits<char>,class_std::allocator<char>_>(local_7c);

      local_4._0_1_ = 8;

      std::basic_string<char,struct_std::char_traits<char>,class_std::allocator<char>_>::

      ~basic_string<char,struct_std::char_traits<char>,class_std::allocator<char>_>(local_28);

      local_4._0_1_ = 1;

      std::basic_string<char,struct_std::char_traits<char>,class_std::allocator<char>_>::

      ~basic_string<char,struct_std::char_traits<char>,class_std::allocator<char>_>(local_44);

    }

    local_4._0_1_ = 0;

    pbVar6 = local_88;

    if (local_88 !=

        (basic_string<char,struct_std::char_traits<char>,class_std::allocator<char>_> *)0x0) {

      for (; pbVar6 != local_84; pbVar6 = pbVar6 + 0x38) {

        local_4._0_1_ = 9;

        std::basic_string<char,struct_std::char_traits<char>,class_std::allocator<char>_>::

        ~basic_string<char,struct_std::char_traits<char>,class_std::allocator<char>_>(pbVar6 + 0x1c)

        ;

        local_4._0_1_ = 0;

        std::basic_string<char,struct_std::char_traits<char>,class_std::allocator<char>_>::

        ~basic_string<char,struct_std::char_traits<char>,class_std::allocator<char>_>(pbVar6);

      }

                    /* WARNING: Subroutine does not return */

      operator_delete(local_88);

    }

    local_88 = (basic_string<char,struct_std::char_traits<char>,class_std::allocator<char>_> *)0x0;

    local_84 = (basic_string<char,struct_std::char_traits<char>,class_std::allocator<char>_> *)0x0;

    piVar7 = piVar7 + 5;

  } while( true );

}
