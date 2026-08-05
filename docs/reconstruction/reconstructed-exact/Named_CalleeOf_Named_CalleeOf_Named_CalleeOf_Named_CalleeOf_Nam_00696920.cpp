// =============================================================================
// Named_CalleeOf_Named_CalleeOf_Named_CalleeOf_Named_CalleeOf_Nam_00696920
// -----------------------------------------------------------------------------
// Stable ID: aa_00696920
// Callee of Named_CalleeOf_Named_CalleeOf_Named_CalleeOf_Named_CalleeOf_Nam
// Address:   0x00696920  (autoassault.exe, image base 0x400000)
// System:    unknown
// Generated: 2026-07-23 from raw capture (scaffold; refine for important units)
// Exactness: Behavior-preserving rewrite of decompiler control flow. Not modernization.
// Bit-for-bit vs retail EXE: DEFERRED (loaded image may differ slightly).
// =============================================================================

// PURPOSE (auto): Called from Named_CalleeOf_Named_CalleeOf_Named_CalleeOf_Named_CalleeOf_Nam: callee helper. Evidence string: "default reached in CFrondEngine::Compute()". Supports parent flow (not a free-standing entry point).
// Embedded strings (evidence):
//   - "default reached in CFrondEngine::Compute()"
//   - "frond vertices exceed %d"
// Readability: control flow preserved from Ghidra decompile; types tentative.

// READABILITY (auto CF):
//  - Body size: ~164 non-empty decompiler lines.
//  - Control keywords: if×15, while×7, return×4.
//  - Notable callees: _CxxThrowException×3, CFrondEngine::Compute×2, FUN_006874b0×2, FUN_0068b7d0×2, CONCAT31, FUN_0068e710, FUN_006901c0, FUN_00690460.
//  - Strings: "default reached in CFrondEngine::Compute()"; "frond vertices exceed %d".
//  - Return sites: 4.

/*
 * Behavioral notes:
 * Callee of Named_CalleeOf_Named_CalleeOf_Named_CalleeOf_Named_CalleeOf_Nam
 * Xref/callee-driven rename (parent seed scan)
 *
 * - Derived from Ghidra decompile; names prefer Ghidra symbols / plate comments.
 * - Remaining FUN_* / DAT_* identifiers are unresolved pending type recovery.
 * - Runtime / differential verification: OPEN unless matrix says otherwise.
 *
 * Readability pass:
 * - undefinedN widths preserved as fixed-width integers where decompiler width is known.
 * - Control flow and call order preserved from authoritative raw.
 */

void __thiscall Named_CalleeOf_Named_CalleeOf_Named_CalleeOf_Named_CalleeOf_Nam_00696920(uint32_t /* width from decompiler */ *param_1,uint32_t /* width from decompiler */ param_2,uint32_t /* width from decompiler */ param_3)



{

  int iVar1;

  int iVar2;

  basic_string<char,struct_std::char_traits<char>,class_std::allocator<char>_> *pbVar3;

  int iVar4;

  uint uVar5;

  int iVar6;

  uint local_98;

  undefined **local_94 [3];

  basic_string<char,struct_std::char_traits<char>,class_std::allocator<char>_> local_88 [28];

  basic_string<char,struct_std::char_traits<char>,class_std::allocator<char>_> local_6c [28];

  basic_string<char,struct_std::char_traits<char>,class_std::allocator<char>_> local_50 [28];

  uint8_t local_34 [40];

  void *local_c;

  uint8_t *puStack_8;

  uint32_t /* width from decompiler */ local_4;

  

  local_4 = 0xffffffff;

  puStack_8 = &LAB_009aaa17;

  local_c = ExceptionList;

  ExceptionList = &local_c;

  param_1[1] = param_3;

  iVar4 = 0;

  *param_1 = param_2;

  local_98 = 0;

  FUN_00696490();

  iVar6 = param_1[7];

  uVar5 = 0;

  while ((*(int *)(iVar6 + 4) != 0 &&

         (uVar5 < (uint)((*(int *)(iVar6 + 8) - *(int *)(iVar6 + 4)) / 0x30)))) {

    if (param_1[10] == 0) {

      iVar2 = *(int *)(*(int *)(iVar6 + 4) + 4 + iVar4);

      if (iVar2 == 0) {

        iVar2 = 0;

      }

      else {

        iVar2 = (*(int *)(*(int *)(iVar6 + 4) + iVar4 + 8) - iVar2) / 0x38;

      }

      local_98 = local_98 + param_1[0xb] * iVar2 * 2;

      uVar5 = uVar5 + 1;

      iVar4 = iVar4 + 0x30;

    }

    else {

      if (param_1[10] != 1) {

        std::basic_string<char,struct_std::char_traits<char>,class_std::allocator<char>_>::

        basic_string<char,struct_std::char_traits<char>,class_std::allocator<char>_>

                  (local_6c,"default reached in CFrondEngine::Compute()");

        local_4 = 0;

        FUN_006874b0(local_6c,0);

                    /* WARNING: Subroutine does not return */

        _CxxThrowException(local_94,(ThrowInfo *)&DAT_00ac9e00);

      }

      iVar2 = *(int *)(*(int *)(iVar6 + 4) + 4 + iVar4);

      if (iVar2 == 0) {

        iVar2 = 0;

      }

      else {

        iVar2 = (*(int *)(*(int *)(iVar6 + 4) + iVar4 + 8) - iVar2) / 0x38;

      }

      local_98 = local_98 + (param_1[0xd] * 2 + -1) * iVar2;

      uVar5 = uVar5 + 1;

      iVar4 = iVar4 + 0x30;

    }

  }

  if (0xffff < (int)local_98) {

    pbVar3 = (basic_string<char,struct_std::char_traits<char>,class_std::allocator<char>_> *)

             FUN_006901c0("frond vertices exceed %d",0xffff);

    local_4 = 1;

    exception::exception((exception *)local_94);

    local_4._0_1_ = 2;

    local_94[0] = &PTR_FUN_009ea778;

    std::basic_string<char,struct_std::char_traits<char>,class_std::allocator<char>_>::

    basic_string<char,struct_std::char_traits<char>,class_std::allocator<char>_>(local_88,pbVar3);

    local_4 = CONCAT31(local_4._1_3_,1);

                    /* WARNING: Subroutine does not return */

    _CxxThrowException(local_94,(ThrowInfo *)&DAT_00acb3e8);

  }

  FUN_0068e710(*(uint16_t *)(param_1 + 0x14));

  if (param_1[10] == 0) {

    uVar5 = 0;

    iVar6 = 0;

    while( true ) {

      iVar4 = param_1[7];

      if ((*(int *)(iVar4 + 4) == 0) ||

         ((uint)((*(int *)(iVar4 + 8) - *(int *)(iVar4 + 4)) / 0x30) <= uVar5)) break;

      FUN_00692090(*(int *)(iVar4 + 4) + iVar6);

      uVar5 = uVar5 + 1;

      iVar6 = iVar6 + 0x30;

    }

    local_98 = 0;

    while( true ) {

      if (param_1[7] == 0) {

        uVar5 = 0;

      }

      else {

        uVar5 = (int)(param_1[8] - param_1[7]) >> 4;

      }

      if (uVar5 <= (local_98 & 0xffff)) break;

      FUN_0068b7d0(local_98);

      uVar5 = 0;

      iVar4 = (local_98 & 0xffff) * 0x10;

      iVar6 = 0;

      while( true ) {

        iVar2 = param_1[7];

        iVar1 = *(int *)(iVar4 + 4 + iVar2);

        if ((iVar1 == 0) || ((uint)((*(int *)(iVar4 + 8 + iVar2) - iVar1) / 0x30) <= uVar5)) break;

        FUN_00690460(local_98 & 0xffff,*(uint32_t /* width from decompiler */ *)(*(int *)(iVar2 + 4) + iVar6 + 0x28),

                     *(int *)(iVar4 + 4 + iVar2) + iVar6);

        uVar5 = uVar5 + 1;

        iVar6 = iVar6 + 0x30;

      }

      local_98 = local_98 + 1;

    }

  }

  else {

    if (param_1[10] != 1) {

      std::basic_string<char,struct_std::char_traits<char>,class_std::allocator<char>_>::

      basic_string<char,struct_std::char_traits<char>,class_std::allocator<char>_>

                (local_50,"default reached in CFrondEngine::Compute()");

      local_4 = 3;

      FUN_006874b0(local_50,0);

                    /* WARNING: Subroutine does not return */

      _CxxThrowException(local_34,(ThrowInfo *)&DAT_00ac9e00);

    }

    iVar6 = 0;

    uVar5 = 0;

    while( true ) {

      iVar4 = param_1[7];

      if ((*(int *)(iVar4 + 4) == 0) ||

         ((uint)((*(int *)(iVar4 + 8) - *(int *)(iVar4 + 4)) / 0x30) <= uVar5)) break;

      FUN_00694a70(*(int *)(iVar4 + 4) + iVar6);

      uVar5 = uVar5 + 1;

      iVar6 = iVar6 + 0x30;

    }

    local_98 = 0;

    while( true ) {

      if (param_1[7] == 0) {

        uVar5 = 0;

      }

      else {

        uVar5 = (int)(param_1[8] - param_1[7]) >> 4;

      }

      if (uVar5 <= (local_98 & 0xffff)) break;

      FUN_0068b7d0(local_98);

      uVar5 = 0;

      iVar6 = (local_98 & 0xffff) * 0x10;

      iVar4 = 0;

      while( true ) {

        iVar2 = param_1[7];

        iVar1 = *(int *)(iVar6 + 4 + iVar2);

        if ((iVar1 == 0) || ((uint)((*(int *)(iVar6 + 8 + iVar2) - iVar1) / 0x30) <= uVar5)) break;

        *(uint32_t /* width from decompiler */ *)(*(int *)(iVar6 + 4 + iVar2) + iVar4 + 0x2c) =

             *(uint32_t /* width from decompiler */ *)(*(int *)(iVar2 + 4) + 0x2c + iVar4);

        FUN_00690570(local_98 & 0xffff,*(uint32_t /* width from decompiler */ *)(*(int *)(param_1[7] + 4) + 0x28 + iVar4),

                     *(int *)(iVar6 + 4 + param_1[7]) + iVar4);

        uVar5 = uVar5 + 1;

        iVar4 = iVar4 + 0x30;

      }

      local_98 = local_98 + 1;

    }

  }

  ExceptionList = local_c;

  return;

}
