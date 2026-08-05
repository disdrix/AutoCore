// =============================================================================
// Named_CalleeOf_Client_Input_OnKeyDown_MatchAction_00402850
// -----------------------------------------------------------------------------
// Stable ID: aa_00402850
// Callee of Client_Input_OnKeyDown_MatchAction
// Address:   0x00402850  (autoassault.exe, image base 0x400000)
// System:    unknown
// Generated: 2026-07-23 from raw capture (scaffold; refine for important units)
// Exactness: Behavior-preserving rewrite of decompiler control flow. Not modernization.
// Bit-for-bit vs retail EXE: DEFERRED (loaded image may differ slightly).
// =============================================================================

// PURPOSE (auto): Called from Client_Input_OnKeyDown_MatchAction: input/binding helper with no high-value strings in clean/raw. Role inferred from parent name only; refine when decompile strings or xrefs improve.
// Readability: control flow preserved from Ghidra decompile; types tentative.

// READABILITY (auto CF):
//  - Body size: ~143 non-empty decompiler lines.
//  - Control keywords: if×22, return×2, do×1, goto×1, while×1.
//  - Notable callees: block×11, FUN_00403200×3, FUN_00407a60×3, FUN_00401bc0, FUN_00402850, FUN_004031c0, FUN_004031e0, FUN_004040a0.
//  - Strings: "invalid map/set<T> iterator".
//  - Return sites: 2.

/*
 * Behavioral notes:
 * Callee of Client_Input_OnKeyDown_MatchAction
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

/* WARNING: Removing unreachable block (ram,0x00402949) */

/* WARNING: Removing unreachable block (ram,0x00402959) */

/* WARNING: Removing unreachable block (ram,0x00402962) */

/* WARNING: Removing unreachable block (ram,0x00402965) */

/* WARNING: Removing unreachable block (ram,0x00402955) */

/* WARNING: Removing unreachable block (ram,0x00402973) */

/* WARNING: Removing unreachable block (ram,0x00402980) */

/* WARNING: Removing unreachable block (ram,0x0040298b) */

/* WARNING: Removing unreachable block (ram,0x00402987) */

/* WARNING: Removing unreachable block (ram,0x0040297b) */

/* WARNING: Removing unreachable block (ram,0x0040298e) */



void Named_CalleeOf_Client_Input_OnKeyDown_MatchAction_00402850(int param_1,uint32_t /* width from decompiler */ param_2,int *param_3)



{

  uint32_t /* width from decompiler */ *puVar1;

  int iVar2;

  int *piVar3;

  uint32_t /* width from decompiler */ uVar4;

  int *piVar5;

  int *piVar6;

  basic_string<char,struct_std::char_traits<char>,class_std::allocator<char>_> local_50 [28];

  uint8_t local_34 [40];

  void *pvStack_c;

  uint8_t *puStack_8;

  uint32_t /* width from decompiler */ local_4;

  

  local_4 = 0xffffffff;

  puStack_8 = &LAB_009bc919;

  pvStack_c = ExceptionList;

  if (*(char *)((int)param_3 + 0x29) != '\0') {

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

  FUN_004040a0();

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

      piVar3 = (int *)FUN_004031e0();

    }

    *puVar1 = piVar3;

  }

  iVar2 = *(int *)(param_1 + 4);

  if (*(int **)(iVar2 + 8) == param_3) {

    if (*(char *)((int)piVar6 + 0x29) == '\0') {

      uVar4 = FUN_004031c0();

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

            FUN_00407a60(param_1);

            piVar5 = (int *)piVar3[2];

          }

          if (*(char *)((int)piVar5 + 0x29) == '\0') {

            if ((*(char *)(*piVar5 + 0x28) != '\x01') || (*(char *)(piVar5[2] + 0x28) != '\x01')) {

              if (*(char *)(piVar5[2] + 0x28) == '\x01') {

                *(uint8_t *)(*piVar5 + 0x28) = 1;

                *(uint8_t *)(piVar5 + 10) = 0;

                FUN_00403200(param_1);

                piVar5 = (int *)piVar3[2];

              }

              *(char *)(piVar5 + 10) = (char)piVar3[10];

              *(uint8_t *)(piVar3 + 10) = 1;

              *(uint8_t *)(piVar5[2] + 0x28) = 1;

              FUN_00407a60(param_1);

              break;

            }

LAB_00402a5e:

            *(uint8_t *)(piVar5 + 10) = 0;

          }

        }

        else {

          if ((char)piVar5[10] == '\0') {

            *(uint8_t *)(piVar5 + 10) = 1;

            *(uint8_t *)(piVar3 + 10) = 0;

            FUN_00403200(param_1);

            piVar5 = (int *)*piVar3;

          }

          if (*(char *)((int)piVar5 + 0x29) == '\0') {

            if ((*(char *)(piVar5[2] + 0x28) == '\x01') && (*(char *)(*piVar5 + 0x28) == '\x01'))

            goto LAB_00402a5e;

            if (*(char *)(*piVar5 + 0x28) == '\x01') {

              *(uint8_t *)(piVar5[2] + 0x28) = 1;

              *(uint8_t *)(piVar5 + 10) = 0;

              FUN_00407a60(param_1);

              piVar5 = (int *)*piVar3;

            }

            *(char *)(piVar5 + 10) = (char)piVar3[10];

            *(uint8_t *)(piVar3 + 10) = 1;

            *(uint8_t *)(*piVar5 + 0x28) = 1;

            FUN_00403200(param_1);

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
