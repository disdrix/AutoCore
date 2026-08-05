// =============================================================================
// Named_CalleeOf_Named_CalleeOf_Named_CalleeOf_Named_VOGClient_0040f100
// -----------------------------------------------------------------------------
// Stable ID: aa_0040f100
// Callee of Named_CalleeOf_Named_CalleeOf_Named_VOGClient
// Address:   0x0040f100  (autoassault.exe, image base 0x400000)
// System:    unknown
// Generated: 2026-07-23 from raw capture (scaffold; refine for important units)
// Exactness: Behavior-preserving rewrite of decompiler control flow. Not modernization.
// Bit-for-bit vs retail EXE: DEFERRED (loaded image may differ slightly).
// =============================================================================

// PURPOSE (auto): Called from Named_CalleeOf_Named_CalleeOf_Named_VOGClient: callee helper with no high-value strings in clean/raw. Role inferred from parent name only; refine when decompile strings or xrefs improve.
// Readability: control flow preserved from Ghidra decompile; types tentative.

// READABILITY (auto CF):
//  - Body size: ~92 non-empty decompiler lines.
//  - Control keywords: if×11, return×2, do×1, goto×1, while×1.
//  - Notable callees: FUN_004e22d0×2, FUN_006753b0×2, FUN_00401a40, FUN_0040f100, FUN_0040f360, _CxxThrowException.
//  - Strings: "map/set<T> too long".
//  - Return sites: 2.

/*
 * Behavioral notes:
 * Callee of Named_CalleeOf_Named_CalleeOf_Named_VOGClient
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

Named_CalleeOf_Named_CalleeOf_Named_CalleeOf_Named_VOGClient_0040f100(int param_1,uint32_t /* width from decompiler */ *param_2,char param_3,uint32_t /* width from decompiler */ *param_4,uint32_t /* width from decompiler */ param_5)



{

  char cVar1;

  int *piVar2;

  int *piVar3;

  int *piVar4;

  int *piVar5;

  int *piVar6;

  basic_string<char,struct_std::char_traits<char>,class_std::allocator<char>_> local_50 [28];

  uint8_t local_34 [40];

  void *local_c;

  uint8_t *puStack_8;

  uint32_t /* width from decompiler */ local_4;

  

  local_4 = 0xffffffff;

  puStack_8 = &LAB_009bc919;

  local_c = ExceptionList;

  if (0x1ffffffd < *(uint *)(param_1 + 8)) {

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

  piVar3 = (int *)FUN_0040f360(*(uint32_t /* width from decompiler */ *)(param_1 + 4),param_4,*(uint32_t /* width from decompiler */ *)(param_1 + 4),

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

  cVar1 = *(char *)(piVar3[1] + 0x14);

  piVar6 = piVar3;

  do {

    if (cVar1 != '\0') {

      *(uint8_t *)(*(int *)(*(int *)(param_1 + 4) + 4) + 0x14) = 1;

      *param_2 = piVar3;

      ExceptionList = local_c;

      return;

    }

    piVar4 = piVar6 + 1;

    piVar2 = (int *)*piVar4;

    piVar5 = *(int **)piVar2[1];

    if (piVar2 == piVar5) {

      piVar5 = (int *)((uint32_t /* width from decompiler */ *)piVar2[1])[2];

      if ((char)piVar5[5] == '\0') {

LAB_0040f1e5:

        *(uint8_t *)(*piVar4 + 0x14) = 1;

        *(uint8_t *)(piVar5 + 5) = 1;

        *(uint8_t *)(*(int *)(*piVar4 + 4) + 0x14) = 0;

        piVar6 = *(int **)(*piVar4 + 4);

      }

      else {

        if (piVar6 == (int *)piVar2[2]) {

          FUN_004e22d0(piVar2);

          piVar6 = piVar2;

        }

        *(uint8_t *)(piVar6[1] + 0x14) = 1;

        *(uint8_t *)(*(int *)(piVar6[1] + 4) + 0x14) = 0;

        FUN_006753b0(*(uint32_t /* width from decompiler */ *)(piVar6[1] + 4));

      }

    }

    else {

      if ((char)piVar5[5] == '\0') goto LAB_0040f1e5;

      if (piVar6 == (int *)*piVar2) {

        FUN_006753b0(piVar2);

        piVar6 = piVar2;

      }

      *(uint8_t *)(piVar6[1] + 0x14) = 1;

      *(uint8_t *)(*(int *)(piVar6[1] + 4) + 0x14) = 0;

      FUN_004e22d0(*(uint32_t /* width from decompiler */ *)(piVar6[1] + 4));

    }

    cVar1 = *(char *)(piVar6[1] + 0x14);

  } while( true );

}
