// =============================================================================
// FUN_00559460
// -----------------------------------------------------------------------------
// Stable ID: aa_00559460
// Address:   0x00559460  (autoassault.exe, image base 0x400000)
// System:    unknown
// Generated: 2026-07-23 from raw capture (scaffold; refine for important units)
// Exactness: Behavior-preserving rewrite of decompiler control flow. Not modernization.
// Bit-for-bit vs retail EXE: DEFERRED (loaded image may differ slightly).
// =============================================================================

// PURPOSE (auto): Scaffold unit for FUN_00559460 @ 0x00559460
// Stable ID: aa_00559460
// Embedded strings (evidence for future rename):
//   - "map/set<T> too long"
// Readability: control flow preserved from Ghidra decompile; types tentative.

// READABILITY (auto CF):
//  - Body size: ~120 non-empty decompiler lines.
//  - Control keywords: if×14, return×2, do×1, goto×1, while×1.
//  - Notable callees: FUN_00558ce0×2, FUN_00558db0, FUN_005593b0, FUN_00559460, _CxxThrowException, exception::exception.
//  - Strings: "map/set<T> too long".
//  - Return sites: 2.

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

FUN_00559460(int param_1,uint32_t /* width from decompiler */ *param_2,char param_3,uint32_t /* width from decompiler */ *param_4,uint32_t /* width from decompiler */ param_5)



{

  char cVar1;

  int *piVar2;

  int iVar3;

  int *piVar4;

  int *piVar5;

  int *piVar6;

  int *piVar7;

  basic_string<char,struct_std::char_traits<char>,class_std::allocator<char>_> local_50 [28];

  undefined **local_34 [3];

  basic_string<char,struct_std::char_traits<char>,class_std::allocator<char>_> local_28 [28];

  void *local_c;

  uint8_t *puStack_8;

  int local_4;

  

  local_4 = 0xffffffff;

  puStack_8 = &LAB_009a4812;

  local_c = ExceptionList;

  if (0x2f7d65 < *(uint *)(param_1 + 8)) {

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

  piVar4 = (int *)FUN_005593b0(*(uint32_t /* width from decompiler */ *)(param_1 + 4),param_4,*(uint32_t /* width from decompiler */ *)(param_1 + 4),

                               param_5,0);

  *(int *)(param_1 + 8) = *(int *)(param_1 + 8) + 1;

  if (param_4 == *(uint32_t /* width from decompiler */ **)(param_1 + 4)) {

    (*(uint32_t /* width from decompiler */ **)(param_1 + 4))[1] = piVar4;

    **(uint32_t /* width from decompiler */ **)(param_1 + 4) = piVar4;

    *(int **)(*(int *)(param_1 + 4) + 8) = piVar4;

  }

  else if (param_3 == '\0') {

    param_4[2] = piVar4;

    if (param_4 == *(uint32_t /* width from decompiler */ **)(*(int *)(param_1 + 4) + 8)) {

      *(int **)(*(int *)(param_1 + 4) + 8) = piVar4;

    }

  }

  else {

    *param_4 = piVar4;

    if (param_4 == (uint32_t /* width from decompiler */ *)**(int **)(param_1 + 4)) {

      **(int **)(param_1 + 4) = (int)piVar4;

    }

  }

  cVar1 = *(char *)(piVar4[1] + 0x570);

  piVar7 = piVar4;

  do {

    if (cVar1 != '\0') {

      *(uint8_t *)(*(int *)(*(int *)(param_1 + 4) + 4) + 0x570) = 1;

      *param_2 = piVar4;

      ExceptionList = local_c;

      return;

    }

    piVar5 = piVar7 + 1;

    piVar2 = (int *)*piVar5;

    piVar6 = *(int **)piVar2[1];

    if (piVar2 == piVar6) {

      piVar6 = (int *)((uint32_t /* width from decompiler */ *)piVar2[1])[2];

      if ((char)piVar6[0x15c] == '\0') {

LAB_0055956c:

        *(uint8_t *)(*piVar5 + 0x570) = 1;

        *(uint8_t *)(piVar6 + 0x15c) = 1;

        *(uint8_t *)(*(int *)(*piVar5 + 4) + 0x570) = 0;

        piVar7 = *(int **)(*piVar5 + 4);

      }

      else {

        if (piVar7 == (int *)piVar2[2]) {

          FUN_00558db0(piVar2);

          piVar7 = piVar2;

        }

        *(uint8_t *)(piVar7[1] + 0x570) = 1;

        *(uint8_t *)(*(int *)(piVar7[1] + 4) + 0x570) = 0;

        FUN_00558ce0(*(uint32_t /* width from decompiler */ *)(piVar7[1] + 4));

      }

    }

    else {

      if ((char)piVar6[0x15c] == '\0') goto LAB_0055956c;

      if (piVar7 == (int *)*piVar2) {

        FUN_00558ce0(piVar2);

        piVar7 = piVar2;

      }

      *(uint8_t *)(piVar7[1] + 0x570) = 1;

      *(uint8_t *)(*(int *)(piVar7[1] + 4) + 0x570) = 0;

      iVar3 = *(int *)(piVar7[1] + 4);

      piVar2 = *(int **)(iVar3 + 8);

      *(int *)(iVar3 + 8) = *piVar2;

      if (*(char *)(*piVar2 + 0x571) == '\0') {

        *(int *)(*piVar2 + 4) = iVar3;

      }

      piVar2[1] = *(int *)(iVar3 + 4);

      if (iVar3 == *(int *)(*(int *)(param_1 + 4) + 4)) {

        *(int **)(*(int *)(param_1 + 4) + 4) = piVar2;

      }

      else {

        piVar6 = *(int **)(iVar3 + 4);

        if (iVar3 == *piVar6) {

          *piVar6 = (int)piVar2;

        }

        else {

          piVar6[2] = (int)piVar2;

        }

      }

      *piVar2 = iVar3;

      *(int **)(iVar3 + 4) = piVar2;

    }

    cVar1 = *(char *)(piVar7[1] + 0x570);

  } while( true );

}
