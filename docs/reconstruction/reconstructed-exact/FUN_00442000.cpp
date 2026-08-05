// =============================================================================
// FUN_00442000
// -----------------------------------------------------------------------------
// Stable ID: aa_00442000
// Address:   0x00442000  (autoassault.exe, image base 0x400000)
// System:    unknown
// Generated: 2026-07-23 from raw capture (scaffold; refine for important units)
// Exactness: Behavior-preserving rewrite of decompiler control flow. Not modernization.
// Bit-for-bit vs retail EXE: DEFERRED (loaded image may differ slightly).
// =============================================================================

// PURPOSE (auto): Scaffold unit for FUN_00442000 @ 0x00442000
// Stable ID: aa_00442000
// Embedded strings (evidence for future rename):
//   - "invalid map/set<T> iterator"
// Readability: control flow preserved from Ghidra decompile; types tentative.

// READABILITY (auto CF):
//  - Body size: ~145 non-empty decompiler lines.
//  - Control keywords: if×22, return×2, do×1, goto×1, while×1.
//  - Notable callees: block×11, FUN_004422d0×3, FUN_00442340×3, FUN_00401bc0, FUN_004413c0, FUN_00441ad0, FUN_00442000, FUN_00442320.
//  - Strings: "invalid map/set<T> iterator".
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

/* WARNING: Removing unreachable block (ram,0x004420f6) */

/* WARNING: Removing unreachable block (ram,0x00442107) */

/* WARNING: Removing unreachable block (ram,0x00442110) */

/* WARNING: Removing unreachable block (ram,0x00442113) */

/* WARNING: Removing unreachable block (ram,0x00442103) */

/* WARNING: Removing unreachable block (ram,0x00442121) */

/* WARNING: Removing unreachable block (ram,0x00442132) */

/* WARNING: Removing unreachable block (ram,0x0044213d) */

/* WARNING: Removing unreachable block (ram,0x00442139) */

/* WARNING: Removing unreachable block (ram,0x0044212d) */

/* WARNING: Removing unreachable block (ram,0x00442140) */



void FUN_00442000(int param_1,uint32_t /* width from decompiler */ param_2,int *param_3)



{

  uint32_t /* width from decompiler */ *puVar1;

  int iVar2;

  int *piVar3;

  uint32_t /* width from decompiler */ uVar4;

  int *piVar5;

  int *piVar6;

  uint8_t local_54 [4];

  basic_string<char,struct_std::char_traits<char>,class_std::allocator<char>_> local_50 [28];

  uint8_t local_34 [40];

  void *pvStack_c;

  uint8_t *puStack_8;

  uint32_t /* width from decompiler */ local_4;

  

  local_4 = 0xffffffff;

  puStack_8 = &LAB_009bc919;

  pvStack_c = ExceptionList;

  if (*(char *)((int)param_3 + 0x1d) != '\0') {

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

  FUN_00441ad0();

  piVar6 = (int *)*param_3;

  if (*(char *)((int)piVar6 + 0x1d) == '\0') {

    if (*(char *)(param_3[2] + 0x1d) == '\0') {

      piVar6 = (int *)param_3[2];

    }

  }

  else {

    piVar6 = (int *)param_3[2];

  }

  piVar5 = (int *)param_3[1];

  if (*(char *)((int)piVar6 + 0x1d) == '\0') {

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

    if (*(char *)((int)piVar6 + 0x1d) == '\0') {

      piVar3 = (int *)FUN_00442320();

    }

    *puVar1 = piVar3;

  }

  iVar2 = *(int *)(param_1 + 4);

  if (*(int **)(iVar2 + 8) == param_3) {

    if (*(char *)((int)piVar6 + 0x1d) == '\0') {

      uVar4 = FUN_00442520();

      *(uint32_t /* width from decompiler */ *)(iVar2 + 8) = uVar4;

    }

    else {

      *(int **)(iVar2 + 8) = piVar5;

    }

  }

  if ((char)param_3[7] == '\x01') {

    if (piVar6 != *(int **)(*(int *)(param_1 + 4) + 4)) {

      do {

        piVar3 = piVar5;

        if ((char)piVar6[7] != '\x01') break;

        piVar5 = (int *)*piVar3;

        if (piVar6 == piVar5) {

          piVar5 = (int *)piVar3[2];

          if ((char)piVar5[7] == '\0') {

            *(uint8_t *)(piVar5 + 7) = 1;

            *(uint8_t *)(piVar3 + 7) = 0;

            FUN_004422d0(param_1);

            piVar5 = (int *)piVar3[2];

          }

          if (*(char *)((int)piVar5 + 0x1d) == '\0') {

            if ((*(char *)(*piVar5 + 0x1c) != '\x01') || (*(char *)(piVar5[2] + 0x1c) != '\x01')) {

              if (*(char *)(piVar5[2] + 0x1c) == '\x01') {

                *(uint8_t *)(*piVar5 + 0x1c) = 1;

                *(uint8_t *)(piVar5 + 7) = 0;

                FUN_00442340(param_1);

                piVar5 = (int *)piVar3[2];

              }

              *(char *)(piVar5 + 7) = (char)piVar3[7];

              *(uint8_t *)(piVar3 + 7) = 1;

              *(uint8_t *)(piVar5[2] + 0x1c) = 1;

              FUN_004422d0(param_1);

              break;

            }

LAB_0044221a:

            *(uint8_t *)(piVar5 + 7) = 0;

          }

        }

        else {

          if ((char)piVar5[7] == '\0') {

            *(uint8_t *)(piVar5 + 7) = 1;

            *(uint8_t *)(piVar3 + 7) = 0;

            FUN_00442340(param_1);

            piVar5 = (int *)*piVar3;

          }

          if (*(char *)((int)piVar5 + 0x1d) == '\0') {

            if ((*(char *)(piVar5[2] + 0x1c) == '\x01') && (*(char *)(*piVar5 + 0x1c) == '\x01'))

            goto LAB_0044221a;

            if (*(char *)(*piVar5 + 0x1c) == '\x01') {

              *(uint8_t *)(piVar5[2] + 0x1c) = 1;

              *(uint8_t *)(piVar5 + 7) = 0;

              FUN_004422d0(param_1);

              piVar5 = (int *)*piVar3;

            }

            *(char *)(piVar5 + 7) = (char)piVar3[7];

            *(uint8_t *)(piVar3 + 7) = 1;

            *(uint8_t *)(*piVar5 + 0x1c) = 1;

            FUN_00442340(param_1);

            break;

          }

        }

        piVar5 = (int *)piVar3[1];

        piVar6 = piVar3;

      } while (piVar3 != *(int **)(*(int *)(param_1 + 4) + 4));

    }

    *(uint8_t *)(piVar6 + 7) = 1;

  }

  FUN_004413c0(local_54,*(uint32_t /* width from decompiler */ *)param_3[5],(uint32_t /* width from decompiler */ *)param_3[5]);

                    /* WARNING: Subroutine does not return */

  operator_delete((void *)param_3[5]);

}
