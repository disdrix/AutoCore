// =============================================================================
// FUN_004e4130
// -----------------------------------------------------------------------------
// Stable ID: aa_004e4130
// Address:   0x004e4130  (autoassault.exe, image base 0x400000)
// System:    unknown
// Generated: 2026-07-23 from raw capture (scaffold; refine for important units)
// Exactness: Behavior-preserving rewrite of decompiler control flow. Not modernization.
// Bit-for-bit vs retail EXE: DEFERRED (loaded image may differ slightly).
// =============================================================================

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

/* WARNING: Removing unreachable block (ram,0x004e4250) */
/* WARNING: Removing unreachable block (ram,0x004e4260) */
/* WARNING: Removing unreachable block (ram,0x004e4269) */
/* WARNING: Removing unreachable block (ram,0x004e426c) */
/* WARNING: Removing unreachable block (ram,0x004e425c) */
/* WARNING: Removing unreachable block (ram,0x004e427a) */
/* WARNING: Removing unreachable block (ram,0x004e4287) */
/* WARNING: Removing unreachable block (ram,0x004e4292) */
/* WARNING: Removing unreachable block (ram,0x004e428e) */
/* WARNING: Removing unreachable block (ram,0x004e4282) */
/* WARNING: Removing unreachable block (ram,0x004e4295) */

void __thiscall FUN_004e4130(int param_1,uint32_t /* width from decompiler */ param_2,int *param_3)

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
  puStack_8 = &LAB_009a1e62;
  pvStack_c = ExceptionList;
  if (*(char *)((int)param_3 + 0x19) != '\0') {
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
  FUN_005ae0b0();
  piVar6 = (int *)*param_3;
  if (*(char *)((int)piVar6 + 0x19) == '\0') {
    if (*(char *)(param_3[2] + 0x19) == '\0') {
      piVar6 = (int *)param_3[2];
    }
  }
  else {
    piVar6 = (int *)param_3[2];
  }
  piVar5 = (int *)param_3[1];
  if (*(char *)((int)piVar6 + 0x19) == '\0') {
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
    if (*(char *)((int)piVar6 + 0x19) == '\0') {
      piVar3 = (int *)FUN_005adfa0(piVar6);
    }
    *puVar1 = piVar3;
  }
  iVar2 = *(int *)(param_1 + 4);
  if (*(int **)(iVar2 + 8) == param_3) {
    if (*(char *)((int)piVar6 + 0x19) == '\0') {
      uVar4 = FUN_00418bf0(piVar6);
      *(uint32_t /* width from decompiler */ *)(iVar2 + 8) = uVar4;
    }
    else {
      *(int **)(iVar2 + 8) = piVar5;
    }
  }
  if ((char)param_3[6] == '\x01') {
    if (piVar6 != *(int **)(*(int *)(param_1 + 4) + 4)) {
      do {
        piVar3 = piVar5;
        if ((char)piVar6[6] != '\x01') break;
        piVar5 = (int *)*piVar3;
        if (piVar6 == piVar5) {
          piVar5 = (int *)piVar3[2];
          if ((char)piVar5[6] == '\0') {
            *(uint8_t *)(piVar5 + 6) = 1;
            *(uint8_t *)(piVar3 + 6) = 0;
            FUN_00573170(piVar3);
            piVar5 = (int *)piVar3[2];
          }
          if (*(char *)((int)piVar5 + 0x19) == '\0') {
            if ((*(char *)(*piVar5 + 0x18) != '\x01') || (*(char *)(piVar5[2] + 0x18) != '\x01')) {
              if (*(char *)(piVar5[2] + 0x18) == '\x01') {
                *(uint8_t *)(*piVar5 + 0x18) = 1;
                *(uint8_t *)(piVar5 + 6) = 0;
                FUN_00418c10(piVar5);
                piVar5 = (int *)piVar3[2];
              }
              *(char *)(piVar5 + 6) = (char)piVar3[6];
              *(uint8_t *)(piVar3 + 6) = 1;
              *(uint8_t *)(piVar5[2] + 0x18) = 1;
              FUN_00573170(piVar3);
              break;
            }
LAB_004e4362:
            *(uint8_t *)(piVar5 + 6) = 0;
          }
        }
        else {
          if ((char)piVar5[6] == '\0') {
            *(uint8_t *)(piVar5 + 6) = 1;
            *(uint8_t *)(piVar3 + 6) = 0;
            FUN_00418c10(piVar3);
            piVar5 = (int *)*piVar3;
          }
          if (*(char *)((int)piVar5 + 0x19) == '\0') {
            if ((*(char *)(piVar5[2] + 0x18) == '\x01') && (*(char *)(*piVar5 + 0x18) == '\x01'))
            goto LAB_004e4362;
            if (*(char *)(*piVar5 + 0x18) == '\x01') {
              *(uint8_t *)(piVar5[2] + 0x18) = 1;
              *(uint8_t *)(piVar5 + 6) = 0;
              FUN_00573170(piVar5);
              piVar5 = (int *)*piVar3;
            }
            *(char *)(piVar5 + 6) = (char)piVar3[6];
            *(uint8_t *)(piVar3 + 6) = 1;
            *(uint8_t *)(*piVar5 + 0x18) = 1;
            FUN_00418c10(piVar3);
            break;
          }
        }
        piVar5 = (int *)piVar3[1];
        piVar6 = piVar3;
      } while (piVar3 != *(int **)(*(int *)(param_1 + 4) + 4));
    }
    *(uint8_t *)(piVar6 + 6) = 1;
  }
                    /* WARNING: Subroutine does not return */
  operator_delete(param_3);
}
