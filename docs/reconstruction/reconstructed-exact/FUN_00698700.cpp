// =============================================================================
// FUN_00698700
// -----------------------------------------------------------------------------
// Stable ID: aa_00698700
// Address:   0x00698700  (autoassault.exe, image base 0x400000)
// System:    unknown
// Generated: 2026-07-23 from raw capture (scaffold; refine for important units)
// Exactness: Behavior-preserving rewrite of decompiler control flow. Not modernization.
// Bit-for-bit vs retail EXE: DEFERRED (loaded image may differ slightly).
// =============================================================================

// PURPOSE (auto): Scaffold unit for FUN_00698700 @ 0x00698700
// Stable ID: aa_00698700
// Embedded strings (evidence for future rename):
//   - "too many leaf lod levels"
//   - "malformed leaf lod data"
// Readability: control flow preserved from Ghidra decompile; types tentative.

// READABILITY (auto CF):
//  - Body size: ~98 non-empty decompiler lines.
//  - Control keywords: if×7, return×4, while×2, do×1.
//  - Notable callees: FUN_00699ee0×5, FUN_006874b0×3, _CxxThrowException×3, FUN_00697f60, FUN_00698700, FUN_006a2810, _eh_vector_constructor_iterator_, _eh_vector_destructor_iterator_.
//  - Strings: "too many leaf lod levels"; "malformed leaf lod data".
//  - Return sites: 4.

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

void __thiscall FUN_00698700(int param_1,int param_2)



{

  void *pvVar1;

  uint32_t /* width from decompiler */ *puVar2;

  uint32_t /* width from decompiler */ uVar3;

  uint32_t /* width from decompiler */ uVar4;

  int *piVar5;

  int iVar6;

  int iVar7;

  int *piVar8;

  int local_58;

  uint32_t /* width from decompiler */ local_54;

  basic_string<char,struct_std::char_traits<char>,class_std::allocator<char>_> local_50 [28];

  uint8_t local_34 [40];

  void *local_c;

  uint8_t *puStack_8;

  uint32_t /* width from decompiler */ local_4;

  

  uVar3 = param_2;

  local_4 = 0xffffffff;

  puStack_8 = &LAB_009aac46;

  local_c = ExceptionList;

  piVar8 = (int *)0x0;

  local_58 = 0;

  ExceptionList = &local_c;

  uVar4 = FUN_00699ee0();

  *(uint32_t /* width from decompiler */ *)(param_1 + 0xb4) = uVar4;

  pvVar1 = *(void **)(param_1 + 200);

  if (pvVar1 != (void *)0x0) {

    _eh_vector_destructor_iterator_(pvVar1,0x10,*(int *)((int)pvVar1 + -4),FUN_00691630);

    operator_delete__((void *)((int)pvVar1 + -4));

  }

  iVar6 = *(int *)(param_1 + 0xb4);

  piVar5 = operator_new__(iVar6 * 0x10 + 4);

  local_4 = 0;

  if (piVar5 != (int *)0x0) {

    piVar8 = piVar5 + 1;

    *piVar5 = iVar6;

    _eh_vector_constructor_iterator_(piVar8,0x10,iVar6,FUN_004565f0,FUN_00691630);

  }

  local_4 = 0xffffffff;

  *(int **)(param_1 + 200) = piVar8;

  iVar6 = FUN_00699ee0();

  if (iVar6 != 0x1b59) {

    param_2 = 0;

    do {

      if (*(int *)(param_1 + 0xb4) <= local_58) {

        std::basic_string<char,struct_std::char_traits<char>,class_std::allocator<char>_>::

        basic_string<char,struct_std::char_traits<char>,class_std::allocator<char>_>

                  (local_50,"too many leaf lod levels");

        local_4 = 1;

        FUN_006874b0(local_50,0);

                    /* WARNING: Subroutine does not return */

        _CxxThrowException(local_34,(ThrowInfo *)&DAT_00ac9e00);

      }

      if (iVar6 != 0x1b5a) {

        std::basic_string<char,struct_std::char_traits<char>,class_std::allocator<char>_>::

        basic_string<char,struct_std::char_traits<char>,class_std::allocator<char>_>

                  (local_50,"malformed leaf lod data");

        local_4 = 2;

        FUN_006874b0(local_50,0);

                    /* WARNING: Subroutine does not return */

        _CxxThrowException(local_34,(ThrowInfo *)&DAT_00ac9e00);

      }

      iVar6 = FUN_00699ee0();

      while (iVar6 != 0x1b5b) {

        if (iVar6 != 0x1b5c) {

          std::basic_string<char,struct_std::char_traits<char>,class_std::allocator<char>_>::

          basic_string<char,struct_std::char_traits<char>,class_std::allocator<char>_>

                    (local_50,"malformed leaf lod data");

          local_4 = 3;

          FUN_006874b0(local_50,0);

                    /* WARNING: Subroutine does not return */

          _CxxThrowException(local_34,(ThrowInfo *)&DAT_00ac9e00);

        }

        local_54 = FUN_006a2810(uVar3);

        iVar6 = *(int *)(*(int *)(param_1 + 200) + 4 + param_2);

        iVar7 = *(int *)(param_1 + 200) + param_2;

        if ((iVar6 == 0) ||

           ((uint)(*(int *)(iVar7 + 0xc) - iVar6 >> 2) <= (uint)(*(int *)(iVar7 + 8) - iVar6 >> 2)))

        {

          FUN_00697f60(*(uint32_t /* width from decompiler */ *)(iVar7 + 8),1,&local_54);

        }

        else {

          puVar2 = *(uint32_t /* width from decompiler */ **)(iVar7 + 8);

          *puVar2 = local_54;

          *(uint32_t /* width from decompiler */ **)(iVar7 + 8) = puVar2 + 1;

        }

        iVar6 = FUN_00699ee0();

      }

      param_2 = param_2 + 0x10;

      local_58 = local_58 + 1;

      iVar6 = FUN_00699ee0();

    } while (iVar6 != 0x1b59);

  }

  *(uint8_t *)(param_1 + 0xcc) = 1;

  ExceptionList = local_c;

  return;

}
