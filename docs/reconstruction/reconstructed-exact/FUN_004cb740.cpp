// =============================================================================
// FUN_004cb740
// -----------------------------------------------------------------------------
// Stable ID: aa_004cb740
// Address:   0x004cb740  (autoassault.exe, image base 0x400000)
// System:    unknown
// Generated: 2026-07-23 from raw capture (scaffold; refine for important units)
// Exactness: Behavior-preserving rewrite of decompiler control flow. Not modernization.
// Bit-for-bit vs retail EXE: DEFERRED (loaded image may differ slightly).
// =============================================================================

// PURPOSE (auto): Scaffold unit for FUN_004cb740 @ 0x004cb740
// Stable ID: aa_004cb740
// Embedded strings (evidence for future rename):
//   - "invalid map/set<T> iterator"
// Readability: control flow preserved from Ghidra decompile; types tentative.

// READABILITY (auto CF):
//  - Body size: ~150 non-empty decompiler lines.
//  - Control keywords: if×22, return×2, do×1, goto×1, while×1.
//  - Notable callees: block×11, FUN_004192a0×3, FUN_004192f0×3, FUN_00421b50, FUN_004cb270, FUN_004cb740, FUN_0051b5d0, _CxxThrowException.
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

/* WARNING: Removing unreachable block (ram,0x004cb860) */

/* WARNING: Removing unreachable block (ram,0x004cb870) */

/* WARNING: Removing unreachable block (ram,0x004cb879) */

/* WARNING: Removing unreachable block (ram,0x004cb87c) */

/* WARNING: Removing unreachable block (ram,0x004cb86c) */

/* WARNING: Removing unreachable block (ram,0x004cb88a) */

/* WARNING: Removing unreachable block (ram,0x004cb897) */

/* WARNING: Removing unreachable block (ram,0x004cb8a2) */

/* WARNING: Removing unreachable block (ram,0x004cb89e) */

/* WARNING: Removing unreachable block (ram,0x004cb892) */

/* WARNING: Removing unreachable block (ram,0x004cb8a5) */



void __thiscall FUN_004cb740(int param_1,uint32_t /* width from decompiler */ param_2,int *param_3)



{

  uint32_t /* width from decompiler */ *puVar1;

  int iVar2;

  int *piVar3;

  uint32_t /* width from decompiler */ uVar4;

  int *piVar5;

  int *piVar6;

  basic_string<char,struct_std::char_traits<char>,class_std::allocator<char>_> local_50 [28];

  undefined **local_34 [3];

  basic_string<char,struct_std::char_traits<char>,class_std::allocator<char>_> local_28 [28];

  void *pvStack_c;

  uint8_t *puStack_8;

  int local_4;

  

  local_4 = 0xffffffff;

  puStack_8 = &LAB_009a1e42;

  pvStack_c = ExceptionList;

  if (*(char *)((int)param_3 + 0x29) != '\0') {

    ExceptionList = &pvStack_c;

    std::basic_string<char,struct_std::char_traits<char>,class_std::allocator<char>_>::

    basic_string<char,struct_std::char_traits<char>,class_std::allocator<char>_>

              (local_50,"invalid map/set<T> iterator");

    local_4 = 0;

    exception::exception((exception *)local_34);

    local_4._0_1_ = 1;

    local_34[0] = &PTR_FUN_009c7628;

    std::basic_string<char,struct_std::char_traits<char>,class_std::allocator<char>_>::

    basic_string<char,struct_std::char_traits<char>,class_std::allocator<char>_>(local_28,local_50);

    local_4 = (uint)local_4._1_3_ << 8;

    local_34[0] = &PTR_FUN_009c7640;

                    /* WARNING: Subroutine does not return */

    _CxxThrowException(local_34,(ThrowInfo *)&DAT_00acc34c);

  }

  ExceptionList = &pvStack_c;

  FUN_004cb270();

  piVar6 = (int *)*param_3;

  if (*(char *)((int)piVar6 + 0x29) == '\0') {

    if (*(char *)(param_3[2] + 0x29) == '\0') {

      piVar6 = (int *)param_3[2];

    }

  }

  else {

    piVar6 = (int *)param_3[2];

  }

  piVar5 = (int *)param_3[1];

  if (*(char *)((int)piVar6 + 0x29) == '\0') {

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

    if (*(char *)((int)piVar6 + 0x29) == '\0') {

      piVar3 = (int *)FUN_0051b5d0(piVar6);

    }

    *puVar1 = piVar3;

  }

  iVar2 = *(int *)(param_1 + 4);

  if (*(int **)(iVar2 + 8) == param_3) {

    if (*(char *)((int)piVar6 + 0x29) == '\0') {

      uVar4 = FUN_00421b50(piVar6);

      *(uint32_t /* width from decompiler */ *)(iVar2 + 8) = uVar4;

    }

    else {

      *(int **)(iVar2 + 8) = piVar5;

    }

  }

  if ((char)param_3[10] == '\x01') {

    if (piVar6 != *(int **)(*(int *)(param_1 + 4) + 4)) {

      do {

        piVar3 = piVar5;

        if ((char)piVar6[10] != '\x01') break;

        piVar5 = (int *)*piVar3;

        if (piVar6 == piVar5) {

          piVar5 = (int *)piVar3[2];

          if ((char)piVar5[10] == '\0') {

            *(uint8_t *)(piVar5 + 10) = 1;

            *(uint8_t *)(piVar3 + 10) = 0;

            FUN_004192a0(piVar3);

            piVar5 = (int *)piVar3[2];

          }

          if (*(char *)((int)piVar5 + 0x29) == '\0') {

            if ((*(char *)(*piVar5 + 0x28) != '\x01') || (*(char *)(piVar5[2] + 0x28) != '\x01')) {

              if (*(char *)(piVar5[2] + 0x28) == '\x01') {

                *(uint8_t *)(*piVar5 + 0x28) = 1;

                *(uint8_t *)(piVar5 + 10) = 0;

                FUN_004192f0(piVar5);

                piVar5 = (int *)piVar3[2];

              }

              *(char *)(piVar5 + 10) = (char)piVar3[10];

              *(uint8_t *)(piVar3 + 10) = 1;

              *(uint8_t *)(piVar5[2] + 0x28) = 1;

              FUN_004192a0(piVar3);

              break;

            }

LAB_004cb972:

            *(uint8_t *)(piVar5 + 10) = 0;

          }

        }

        else {

          if ((char)piVar5[10] == '\0') {

            *(uint8_t *)(piVar5 + 10) = 1;

            *(uint8_t *)(piVar3 + 10) = 0;

            FUN_004192f0(piVar3);

            piVar5 = (int *)*piVar3;

          }

          if (*(char *)((int)piVar5 + 0x29) == '\0') {

            if ((*(char *)(piVar5[2] + 0x28) == '\x01') && (*(char *)(*piVar5 + 0x28) == '\x01'))

            goto LAB_004cb972;

            if (*(char *)(*piVar5 + 0x28) == '\x01') {

              *(uint8_t *)(piVar5[2] + 0x28) = 1;

              *(uint8_t *)(piVar5 + 10) = 0;

              FUN_004192a0(piVar5);

              piVar5 = (int *)*piVar3;

            }

            *(char *)(piVar5 + 10) = (char)piVar3[10];

            *(uint8_t *)(piVar3 + 10) = 1;

            *(uint8_t *)(*piVar5 + 0x28) = 1;

            FUN_004192f0(piVar3);

            break;

          }

        }

        piVar5 = (int *)piVar3[1];

        piVar6 = piVar3;

      } while (piVar3 != *(int **)(*(int *)(param_1 + 4) + 4));

    }

    *(uint8_t *)(piVar6 + 10) = 1;

  }

                    /* WARNING: Subroutine does not return */

  operator_delete(param_3);

}
