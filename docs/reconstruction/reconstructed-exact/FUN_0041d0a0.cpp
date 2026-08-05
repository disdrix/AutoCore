// =============================================================================
// FUN_0041d0a0
// -----------------------------------------------------------------------------
// Stable ID: aa_0041d0a0
// Address:   0x0041d0a0  (autoassault.exe, image base 0x400000)
// System:    unknown
// Generated: 2026-07-23 from raw capture (scaffold; refine for important units)
// Exactness: Behavior-preserving rewrite of decompiler control flow. Not modernization.
// Bit-for-bit vs retail EXE: DEFERRED (loaded image may differ slightly).
// =============================================================================

// PURPOSE (auto): Scaffold unit for FUN_0041d0a0 @ 0x0041d0a0
// Stable ID: aa_0041d0a0
// Embedded strings (evidence for future rename):
//   - "map/set<T> too long"
// Readability: control flow preserved from Ghidra decompile; types tentative.

// READABILITY (auto CF):
//  - Body size: ~95 non-empty decompiler lines.
//  - Control keywords: if×11, goto×3, return×2, do×1, while×1.
//  - Notable callees: FUN_004e22d0×2, FUN_006753b0×2, FUN_00401a40, FUN_0041d0a0, FUN_00439110, _CxxThrowException.
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

void FUN_0041d0a0(uint32_t /* width from decompiler */ *param_1,char param_2,uint32_t /* width from decompiler */ *param_3)



{

  char cVar1;

  int *piVar2;

  int *piVar3;

  int iVar4;

  int *piVar5;

  int *piVar6;

  int *piVar7;

  int unaff_EDI;

  basic_string<char,struct_std::char_traits<char>,class_std::allocator<char>_> local_50 [28];

  uint8_t local_34 [40];

  void *local_c;

  uint8_t *puStack_8;

  uint32_t /* width from decompiler */ local_4;

  

  local_4 = 0xffffffff;

  puStack_8 = &LAB_009bc919;

  local_c = ExceptionList;

  if (0x1ffffffd < *(uint *)(unaff_EDI + 8)) {

    ExceptionList = &local_c;

    std::basic_string<char,struct_std::char_traits<char>,class_std::allocator<char>_>::

    basic_string<char,struct_std::char_traits<char>,class_std::allocator<char>_>

              (local_50,"map/set<T> too long");

    local_4 = 0;

    FUN_00401a40(local_50);

                    /* WARNING: Subroutine does not return */

    _CxxThrowException(local_34,(ThrowInfo *)&DAT_00acc388);

  }

  ExceptionList = &local_c;

  piVar3 = (int *)FUN_00439110(*(uint32_t /* width from decompiler */ *)(unaff_EDI + 4),param_3,*(uint32_t /* width from decompiler */ *)(unaff_EDI + 4)

                               ,0);

  *(int *)(unaff_EDI + 8) = *(int *)(unaff_EDI + 8) + 1;

  if (param_3 == *(uint32_t /* width from decompiler */ **)(unaff_EDI + 4)) {

    (*(uint32_t /* width from decompiler */ **)(unaff_EDI + 4))[1] = piVar3;

    **(uint32_t /* width from decompiler */ **)(unaff_EDI + 4) = piVar3;

    iVar4 = *(int *)(unaff_EDI + 4);

  }

  else {

    if (param_2 != '\0') {

      *param_3 = piVar3;

      if (param_3 == (uint32_t /* width from decompiler */ *)**(int **)(unaff_EDI + 4)) {

        **(int **)(unaff_EDI + 4) = (int)piVar3;

      }

      goto LAB_0041d152;

    }

    param_3[2] = piVar3;

    iVar4 = *(int *)(unaff_EDI + 4);

    if (param_3 != *(uint32_t /* width from decompiler */ **)(iVar4 + 8)) goto LAB_0041d152;

  }

  *(int **)(iVar4 + 8) = piVar3;

LAB_0041d152:

  cVar1 = *(char *)(piVar3[1] + 0x14);

  piVar7 = piVar3;

  do {

    if (cVar1 != '\0') {

      *(uint8_t *)(*(int *)(*(int *)(unaff_EDI + 4) + 4) + 0x14) = 1;

      *param_1 = piVar3;

      ExceptionList = local_c;

      return;

    }

    piVar5 = piVar7 + 1;

    piVar2 = (int *)*piVar5;

    piVar6 = *(int **)piVar2[1];

    if (piVar2 == piVar6) {

      piVar6 = (int *)((uint32_t /* width from decompiler */ *)piVar2[1])[2];

      if ((char)piVar6[5] == '\0') {

LAB_0041d177:

        *(uint8_t *)(*piVar5 + 0x14) = 1;

        *(uint8_t *)(piVar6 + 5) = 1;

        *(uint8_t *)(*(int *)(*piVar5 + 4) + 0x14) = 0;

        piVar7 = *(int **)(*piVar5 + 4);

      }

      else {

        if (piVar7 == (int *)piVar2[2]) {

          FUN_004e22d0(piVar2);

          piVar7 = piVar2;

        }

        *(uint8_t *)(piVar7[1] + 0x14) = 1;

        *(uint8_t *)(*(int *)(piVar7[1] + 4) + 0x14) = 0;

        FUN_006753b0(*(uint32_t /* width from decompiler */ *)(piVar7[1] + 4));

      }

    }

    else {

      if ((char)piVar6[5] == '\0') goto LAB_0041d177;

      if (piVar7 == (int *)*piVar2) {

        FUN_006753b0(piVar2);

        piVar7 = piVar2;

      }

      *(uint8_t *)(piVar7[1] + 0x14) = 1;

      *(uint8_t *)(*(int *)(piVar7[1] + 4) + 0x14) = 0;

      FUN_004e22d0(*(uint32_t /* width from decompiler */ *)(piVar7[1] + 4));

    }

    cVar1 = *(char *)(piVar7[1] + 0x14);

  } while( true );

}
