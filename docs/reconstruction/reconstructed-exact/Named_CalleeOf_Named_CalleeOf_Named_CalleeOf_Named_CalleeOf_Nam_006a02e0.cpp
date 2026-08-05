// =============================================================================
// Named_CalleeOf_Named_CalleeOf_Named_CalleeOf_Named_CalleeOf_Nam_006a02e0
// -----------------------------------------------------------------------------
// Stable ID: aa_006a02e0
// Callee of Named_CalleeOf_Named_CalleeOf_Named_CalleeOf_Named_CalleeOf_Nam
// Address:   0x006a02e0  (autoassault.exe, image base 0x400000)
// System:    unknown
// Generated: 2026-07-23 from raw capture (scaffold; refine for important units)
// Exactness: Behavior-preserving rewrite of decompiler control flow. Not modernization.
// Bit-for-bit vs retail EXE: DEFERRED (loaded image may differ slightly).
// =============================================================================

// PURPOSE (auto): Called from Named_CalleeOf_Named_CalleeOf_Named_CalleeOf_Named_CalleeOf_Nam: callee helper with no high-value strings in clean/raw. Role inferred from parent name only; refine when decompile strings or xrefs improve.
// Readability: control flow preserved from Ghidra decompile; types tentative.

// READABILITY (auto CF):
//  - Body size: ~99 non-empty decompiler lines.
//  - Control keywords: if×11, return×2, do×1, goto×1, while×1.
//  - Notable callees: FUN_0069fd60×2, FUN_0069fdc0×2, FUN_0069fe20, FUN_006a02e0, _CxxThrowException, exception::exception.
//  - Strings: "map/set<T> too long".
//  - Return sites: 2.

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

void __thiscall

Named_CalleeOf_Named_CalleeOf_Named_CalleeOf_Named_CalleeOf_Nam_006a02e0(int param_1,uint32_t /* width from decompiler */ *param_2,char param_3,uint32_t /* width from decompiler */ *param_4,uint32_t /* width from decompiler */ param_5)



{

  char cVar1;

  int *piVar2;

  int *piVar3;

  int *piVar4;

  int *piVar5;

  int *piVar6;

  basic_string<char,struct_std::char_traits<char>,class_std::allocator<char>_> local_50 [28];

  undefined **local_34 [3];

  basic_string<char,struct_std::char_traits<char>,class_std::allocator<char>_> local_28 [28];

  void *local_c;

  uint8_t *puStack_8;

  int local_4;

  

  local_4 = 0xffffffff;

  puStack_8 = &LAB_009ab082;

  local_c = ExceptionList;

  if (0x7fffffd < *(uint *)(param_1 + 8)) {

    ExceptionList = &local_c;

    std::basic_string<char,struct_std::char_traits<char>,class_std::allocator<char>_>::

    basic_string<char,struct_std::char_traits<char>,class_std::allocator<char>_>

              (local_50,"map/set<T> too long");

    local_4 = 0;

    exception::exception((exception *)local_34);

    local_4._0_1_ = 1;

    local_34[0] = &PTR_FUN_009c7628;

    std::basic_string<char,struct_std::char_traits<char>,class_std::allocator<char>_>::

    basic_string<char,struct_std::char_traits<char>,class_std::allocator<char>_>(local_28,local_50);

    local_4 = (uint)local_4._1_3_ << 8;

    local_34[0] = &PTR_FUN_009c7634;

                    /* WARNING: Subroutine does not return */

    _CxxThrowException(local_34,(ThrowInfo *)&DAT_00acc388);

  }

  ExceptionList = &local_c;

  piVar3 = (int *)FUN_0069fe20(*(uint32_t /* width from decompiler */ *)(param_1 + 4),param_4,*(uint32_t /* width from decompiler */ *)(param_1 + 4),

                               param_5,0);

  *(int *)(param_1 + 8) = *(int *)(param_1 + 8) + 1;

  if (param_4 == *(uint32_t /* width from decompiler */ **)(param_1 + 4)) {

    (*(uint32_t /* width from decompiler */ **)(param_1 + 4))[1] = piVar3;

    **(uint32_t /* width from decompiler */ **)(param_1 + 4) = piVar3;

    *(int **)(*(int *)(param_1 + 4) + 8) = piVar3;

  }

  else if (param_3 == '\0') {

    param_4[2] = piVar3;

    if (param_4 == *(uint32_t /* width from decompiler */ **)(*(int *)(param_1 + 4) + 8)) {

      *(int **)(*(int *)(param_1 + 4) + 8) = piVar3;

    }

  }

  else {

    *param_4 = piVar3;

    if (param_4 == (uint32_t /* width from decompiler */ *)**(int **)(param_1 + 4)) {

      **(int **)(param_1 + 4) = (int)piVar3;

    }

  }

  cVar1 = *(char *)(piVar3[1] + 0x2c);

  piVar6 = piVar3;

  do {

    if (cVar1 != '\0') {

      *(uint8_t *)(*(int *)(*(int *)(param_1 + 4) + 4) + 0x2c) = 1;

      *param_2 = piVar3;

      ExceptionList = local_c;

      return;

    }

    piVar4 = piVar6 + 1;

    piVar2 = (int *)*piVar4;

    piVar5 = *(int **)piVar2[1];

    if (piVar2 == piVar5) {

      piVar5 = (int *)((uint32_t /* width from decompiler */ *)piVar2[1])[2];

      if ((char)piVar5[0xb] == '\0') {

LAB_006a03e8:

        *(uint8_t *)(*piVar4 + 0x2c) = 1;

        *(uint8_t *)(piVar5 + 0xb) = 1;

        *(uint8_t *)(*(int *)(*piVar4 + 4) + 0x2c) = 0;

        piVar6 = *(int **)(*piVar4 + 4);

      }

      else {

        if (piVar6 == (int *)piVar2[2]) {

          FUN_0069fd60(piVar2);

          piVar6 = piVar2;

        }

        *(uint8_t *)(piVar6[1] + 0x2c) = 1;

        *(uint8_t *)(*(int *)(piVar6[1] + 4) + 0x2c) = 0;

        FUN_0069fdc0(*(uint32_t /* width from decompiler */ *)(piVar6[1] + 4));

      }

    }

    else {

      if ((char)piVar5[0xb] == '\0') goto LAB_006a03e8;

      if (piVar6 == (int *)*piVar2) {

        FUN_0069fdc0(piVar2);

        piVar6 = piVar2;

      }

      *(uint8_t *)(piVar6[1] + 0x2c) = 1;

      *(uint8_t *)(*(int *)(piVar6[1] + 4) + 0x2c) = 0;

      FUN_0069fd60(*(uint32_t /* width from decompiler */ *)(piVar6[1] + 4));

    }

    cVar1 = *(char *)(piVar6[1] + 0x2c);

  } while( true );

}
