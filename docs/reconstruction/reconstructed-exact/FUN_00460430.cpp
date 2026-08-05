// =============================================================================
// FUN_00460430
// -----------------------------------------------------------------------------
// Stable ID: aa_00460430
// Address:   0x00460430  (autoassault.exe, image base 0x400000)
// System:    unknown
// Generated: 2026-07-23 from raw capture (scaffold; refine for important units)
// Exactness: Behavior-preserving rewrite of decompiler control flow. Not modernization.
// Bit-for-bit vs retail EXE: DEFERRED (loaded image may differ slightly).
// =============================================================================

// PURPOSE (auto): Scaffold unit for FUN_00460430 @ 0x00460430
// Stable ID: aa_00460430
// Embedded strings (evidence for future rename):
//   - "invalid map/set<T> iterator"
// Readability: control flow preserved from Ghidra decompile; types tentative.

// READABILITY (auto CF):
//  - Body size: ~167 non-empty decompiler lines.
//  - Control keywords: if×25, return×3, do×2, while×2, goto×1.
//  - Notable callees: block×11, FUN_004014f0×3, FUN_0040e880×3, FUN_004017f0, FUN_00401bc0, FUN_0040e970, FUN_0040eab0, FUN_0045f530.
//  - Strings: "invalid map/set<T> iterator".
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

/* WARNING: Removing unreachable block (ram,0x0046052a) */

/* WARNING: Removing unreachable block (ram,0x0046053b) */

/* WARNING: Removing unreachable block (ram,0x00460544) */

/* WARNING: Removing unreachable block (ram,0x00460547) */

/* WARNING: Removing unreachable block (ram,0x00460537) */

/* WARNING: Removing unreachable block (ram,0x00460555) */

/* WARNING: Removing unreachable block (ram,0x00460566) */

/* WARNING: Removing unreachable block (ram,0x00460571) */

/* WARNING: Removing unreachable block (ram,0x0046056d) */

/* WARNING: Removing unreachable block (ram,0x00460561) */

/* WARNING: Removing unreachable block (ram,0x00460574) */



void FUN_00460430(int param_1,uint32_t /* width from decompiler */ param_2,int *param_3)



{

  uint32_t /* width from decompiler */ *puVar1;

  int iVar2;

  int *piVar3;

  uint32_t /* width from decompiler */ uVar4;

  int *piVar5;

  int *piVar6;

  int iVar7;

  basic_string<char,struct_std::char_traits<char>,class_std::allocator<char>_> local_50 [28];

  uint8_t local_34 [40];

  void *pvStack_c;

  uint8_t *puStack_8;

  uint32_t /* width from decompiler */ local_4;

  

  local_4 = 0xffffffff;

  puStack_8 = &LAB_009bc919;

  pvStack_c = ExceptionList;

  if (*(char *)((int)param_3 + 0x21) != '\0') {

    ExceptionList = &pvStack_c;

    std::basic_string<char,struct_std::char_traits<char>,class_std::allocator<char>_>::

    basic_string<char,struct_std::char_traits<char>,class_std::allocator<char>_>

              (local_50,"invalid map/set<T> iterator");

    local_4 = 0;

    FUN_00401bc0(local_50);

                    /* WARNING: Subroutine does not return */

    _CxxThrowException(local_34,(ThrowInfo *)&DAT_00acc34c);

  }

  ExceptionList = &pvStack_c;

  FUN_004017f0();

  piVar6 = (int *)*param_3;

  if (*(char *)((int)piVar6 + 0x21) == '\0') {

    if (*(char *)(param_3[2] + 0x21) == '\0') {

      piVar6 = (int *)param_3[2];

    }

  }

  else {

    piVar6 = (int *)param_3[2];

  }

  piVar5 = (int *)param_3[1];

  if (*(char *)((int)piVar6 + 0x21) == '\0') {

    piVar6[1] = (int)piVar5;

  }

  if (*(int **)(*(int *)(param_1 + 4) + 4) == param_3) {

    *(int **)(*(int *)(param_1 + 4) + 4) = piVar6;

  }

  else if ((int *)*piVar5 == param_3) {

    *piVar5 = (int)piVar6;

  }

  else {

    piVar5[2] = (int)piVar6;

  }

  puVar1 = *(uint32_t /* width from decompiler */ **)(param_1 + 4);

  if ((int *)*puVar1 == param_3) {

    piVar3 = piVar5;

    if (*(char *)((int)piVar6 + 0x21) == '\0') {

      piVar3 = (int *)FUN_0040e970();

    }

    *puVar1 = piVar3;

  }

  iVar7 = *(int *)(param_1 + 4);

  if (*(int **)(iVar7 + 8) == param_3) {

    if (*(char *)((int)piVar6 + 0x21) == '\0') {

      uVar4 = FUN_0040eab0();

      *(uint32_t /* width from decompiler */ *)(iVar7 + 8) = uVar4;

    }

    else {

      *(int **)(iVar7 + 8) = piVar5;

    }

  }

  if ((char)param_3[8] == '\x01') {

    if (piVar6 != *(int **)(*(int *)(param_1 + 4) + 4)) {

      do {

        piVar3 = piVar5;

        if ((char)piVar6[8] != '\x01') break;

        piVar5 = (int *)*piVar3;

        if (piVar6 == piVar5) {

          piVar5 = (int *)piVar3[2];

          if ((char)piVar5[8] == '\0') {

            *(uint8_t *)(piVar5 + 8) = 1;

            *(uint8_t *)(piVar3 + 8) = 0;

            FUN_004014f0(param_1);

            piVar5 = (int *)piVar3[2];

          }

          if (*(char *)((int)piVar5 + 0x21) == '\0') {

            if ((*(char *)(*piVar5 + 0x20) != '\x01') || (*(char *)(piVar5[2] + 0x20) != '\x01')) {

              if (*(char *)(piVar5[2] + 0x20) == '\x01') {

                *(uint8_t *)(*piVar5 + 0x20) = 1;

                *(uint8_t *)(piVar5 + 8) = 0;

                FUN_0040e880(param_1);

                piVar5 = (int *)piVar3[2];

              }

              *(char *)(piVar5 + 8) = (char)piVar3[8];

              *(uint8_t *)(piVar3 + 8) = 1;

              *(uint8_t *)(piVar5[2] + 0x20) = 1;

              FUN_004014f0(param_1);

              break;

            }

LAB_0046064f:

            *(uint8_t *)(piVar5 + 8) = 0;

          }

        }

        else {

          if ((char)piVar5[8] == '\0') {

            *(uint8_t *)(piVar5 + 8) = 1;

            *(uint8_t *)(piVar3 + 8) = 0;

            FUN_0040e880(param_1);

            piVar5 = (int *)*piVar3;

          }

          if (*(char *)((int)piVar5 + 0x21) == '\0') {

            if ((*(char *)(piVar5[2] + 0x20) == '\x01') && (*(char *)(*piVar5 + 0x20) == '\x01'))

            goto LAB_0046064f;

            if (*(char *)(*piVar5 + 0x20) == '\x01') {

              *(uint8_t *)(piVar5[2] + 0x20) = 1;

              *(uint8_t *)(piVar5 + 8) = 0;

              FUN_004014f0(param_1);

              piVar5 = (int *)*piVar3;

            }

            *(char *)(piVar5 + 8) = (char)piVar3[8];

            *(uint8_t *)(piVar3 + 8) = 1;

            *(uint8_t *)(*piVar5 + 0x20) = 1;

            FUN_0040e880(param_1);

            break;

          }

        }

        piVar5 = (int *)piVar3[1];

        piVar6 = piVar3;

      } while (piVar3 != *(int **)(*(int *)(param_1 + 4) + 4));

    }

    *(uint8_t *)(piVar6 + 8) = 1;

  }

  iVar7 = param_3[5];

  if (iVar7 != 0) {

    iVar2 = param_3[6];

    if (iVar7 != iVar2) {

      piVar6 = (int *)(iVar7 + 0x14);

      do {

        if (*piVar6 != 0) {

          FUN_0045fbf0();

        }

        *piVar6 = 0;

        piVar6[1] = 0;

        piVar6[2] = 0;

        FUN_0045f530();

        iVar7 = iVar7 + 0x20;

        piVar6 = piVar6 + 8;

      } while (iVar7 != iVar2);

    }

                    /* WARNING: Subroutine does not return */

    operator_delete((void *)param_3[5]);

  }

  param_3[5] = 0;

  param_3[6] = 0;

  param_3[7] = 0;

                    /* WARNING: Subroutine does not return */

  operator_delete(param_3);

}
