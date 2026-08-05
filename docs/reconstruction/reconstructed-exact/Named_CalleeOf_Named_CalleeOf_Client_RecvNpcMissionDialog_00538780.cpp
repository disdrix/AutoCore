// =============================================================================
// Named_CalleeOf_Named_CalleeOf_Client_RecvNpcMissionDialog_00538780
// -----------------------------------------------------------------------------
// Stable ID: aa_00538780
// Callee of Named_CalleeOf_Client_RecvNpcMissionDialog
// Address:   0x00538780  (autoassault.exe, image base 0x400000)
// System:    unknown
// Generated: 2026-07-23 from raw capture (scaffold; refine for important units)
// Exactness: Behavior-preserving rewrite of decompiler control flow. Not modernization.
// Bit-for-bit vs retail EXE: DEFERRED (loaded image may differ slightly).
// =============================================================================

// PURPOSE (auto): Called from Named_CalleeOf_Client_RecvNpcMissionDialog: mission/objective helper with no high-value strings in clean/raw. Role inferred from parent name only; refine when decompile strings or xrefs improve.
// Readability: control flow preserved from Ghidra decompile; types tentative.

// READABILITY (auto CF):
//  - Body size: ~150 non-empty decompiler lines.
//  - Control keywords: if×22, return×2, do×1, goto×1, while×1.
//  - Notable callees: block×11, FUN_005681a0×3, FUN_00568b70×3, FUN_00537410, FUN_00538780, FUN_00568180, FUN_00568200, _CxxThrowException.
//  - Strings: "invalid map/set<T> iterator".
//  - Return sites: 2.

/*
 * Behavioral notes:
 * Callee of Named_CalleeOf_Client_RecvNpcMissionDialog
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

/* WARNING: Removing unreachable block (ram,0x005388a0) */

/* WARNING: Removing unreachable block (ram,0x005388b0) */

/* WARNING: Removing unreachable block (ram,0x005388b9) */

/* WARNING: Removing unreachable block (ram,0x005388bc) */

/* WARNING: Removing unreachable block (ram,0x005388ac) */

/* WARNING: Removing unreachable block (ram,0x005388ca) */

/* WARNING: Removing unreachable block (ram,0x005388d7) */

/* WARNING: Removing unreachable block (ram,0x005388e2) */

/* WARNING: Removing unreachable block (ram,0x005388de) */

/* WARNING: Removing unreachable block (ram,0x005388d2) */

/* WARNING: Removing unreachable block (ram,0x005388e5) */



void __thiscall Named_CalleeOf_Named_CalleeOf_Client_RecvNpcMissionDialog_00538780(int param_1,uint32_t /* width from decompiler */ param_2,int *param_3)



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

  puStack_8 = &LAB_009a3ea2;

  pvStack_c = ExceptionList;

  if (*(char *)((int)param_3 + 0x49) != '\0') {

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

  FUN_00568200();

  piVar6 = (int *)*param_3;

  if (*(char *)((int)piVar6 + 0x49) == '\0') {

    if (*(char *)(param_3[2] + 0x49) == '\0') {

      piVar6 = (int *)param_3[2];

    }

  }

  else {

    piVar6 = (int *)param_3[2];

  }

  piVar5 = (int *)param_3[1];

  if (*(char *)((int)piVar6 + 0x49) == '\0') {

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

    if (*(char *)((int)piVar6 + 0x49) == '\0') {

      piVar3 = (int *)FUN_00568180(piVar6);

    }

    *puVar1 = piVar3;

  }

  iVar2 = *(int *)(param_1 + 4);

  if (*(int **)(iVar2 + 8) == param_3) {

    if (*(char *)((int)piVar6 + 0x49) == '\0') {

      uVar4 = FUN_00537410(piVar6);

      *(uint32_t /* width from decompiler */ *)(iVar2 + 8) = uVar4;

    }

    else {

      *(int **)(iVar2 + 8) = piVar5;

    }

  }

  if ((char)param_3[0x12] == '\x01') {

    if (piVar6 != *(int **)(*(int *)(param_1 + 4) + 4)) {

      do {

        piVar3 = piVar5;

        if ((char)piVar6[0x12] != '\x01') break;

        piVar5 = (int *)*piVar3;

        if (piVar6 == piVar5) {

          piVar5 = (int *)piVar3[2];

          if ((char)piVar5[0x12] == '\0') {

            *(uint8_t *)(piVar5 + 0x12) = 1;

            *(uint8_t *)(piVar3 + 0x12) = 0;

            FUN_00568b70(piVar3);

            piVar5 = (int *)piVar3[2];

          }

          if (*(char *)((int)piVar5 + 0x49) == '\0') {

            if ((*(char *)(*piVar5 + 0x48) != '\x01') || (*(char *)(piVar5[2] + 0x48) != '\x01')) {

              if (*(char *)(piVar5[2] + 0x48) == '\x01') {

                *(uint8_t *)(*piVar5 + 0x48) = 1;

                *(uint8_t *)(piVar5 + 0x12) = 0;

                FUN_005681a0(piVar5);

                piVar5 = (int *)piVar3[2];

              }

              *(char *)(piVar5 + 0x12) = (char)piVar3[0x12];

              *(uint8_t *)(piVar3 + 0x12) = 1;

              *(uint8_t *)(piVar5[2] + 0x48) = 1;

              FUN_00568b70(piVar3);

              break;

            }

LAB_005389b2:

            *(uint8_t *)(piVar5 + 0x12) = 0;

          }

        }

        else {

          if ((char)piVar5[0x12] == '\0') {

            *(uint8_t *)(piVar5 + 0x12) = 1;

            *(uint8_t *)(piVar3 + 0x12) = 0;

            FUN_005681a0(piVar3);

            piVar5 = (int *)*piVar3;

          }

          if (*(char *)((int)piVar5 + 0x49) == '\0') {

            if ((*(char *)(piVar5[2] + 0x48) == '\x01') && (*(char *)(*piVar5 + 0x48) == '\x01'))

            goto LAB_005389b2;

            if (*(char *)(*piVar5 + 0x48) == '\x01') {

              *(uint8_t *)(piVar5[2] + 0x48) = 1;

              *(uint8_t *)(piVar5 + 0x12) = 0;

              FUN_00568b70(piVar5);

              piVar5 = (int *)*piVar3;

            }

            *(char *)(piVar5 + 0x12) = (char)piVar3[0x12];

            *(uint8_t *)(piVar3 + 0x12) = 1;

            *(uint8_t *)(*piVar5 + 0x48) = 1;

            FUN_005681a0(piVar3);

            break;

          }

        }

        piVar5 = (int *)piVar3[1];

        piVar6 = piVar3;

      } while (piVar3 != *(int **)(*(int *)(param_1 + 4) + 4));

    }

    *(uint8_t *)(piVar6 + 0x12) = 1;

  }

                    /* WARNING: Subroutine does not return */

  operator_delete(param_3);

}
