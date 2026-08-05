// =============================================================================
// Map_EraseNode_IntKey
// -----------------------------------------------------------------------------
// Stable ID: aa_005d1df0
// Address:   0x005d1df0  (autoassault.exe, image base 0x400000)
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

/* WARNING: Removing unreachable block (ram,0x005d1f10) */
/* WARNING: Removing unreachable block (ram,0x005d1f20) */
/* WARNING: Removing unreachable block (ram,0x005d1f29) */
/* WARNING: Removing unreachable block (ram,0x005d1f2c) */
/* WARNING: Removing unreachable block (ram,0x005d1f1c) */
/* WARNING: Removing unreachable block (ram,0x005d1f3a) */
/* WARNING: Removing unreachable block (ram,0x005d1f47) */
/* WARNING: Removing unreachable block (ram,0x005d1f52) */
/* WARNING: Removing unreachable block (ram,0x005d1f4e) */
/* WARNING: Removing unreachable block (ram,0x005d1f42) */
/* WARNING: Removing unreachable block (ram,0x005d1f55) */

void __thiscall Map_EraseNode_IntKey(void *this,void *pMap,void *pOutIt,void *pNode)

{
  int iVar1;
  int *piVar2;
  uint32_t /* width from decompiler */ uVar3;
  int *piVar4;
  int *piVar5;
  int *piVar6;
  basic_string<char,struct_std::char_traits<char>,class_std::allocator<char>_> local_50 [28];
  undefined **local_34 [3];
  basic_string<char,struct_std::char_traits<char>,class_std::allocator<char>_> local_28 [28];
  void *pvStack_c;
  uint8_t *puStack_8;
  int local_4;
  
  local_4 = 0xffffffff;
  puStack_8 = &LAB_009a7022;
  pvStack_c = ExceptionList;
  if (*(char *)((int)pOutIt + 0x15) != '\0') {
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
  FUN_00673070();
  piVar6 = *(int **)pOutIt;
  if (*(char *)((int)piVar6 + 0x15) == '\0') {
    if (*(char *)(*(int *)((int)pOutIt + 8) + 0x15) == '\0') {
      piVar6 = *(int **)((int)pOutIt + 8);
    }
  }
  else {
    piVar6 = *(int **)((int)pOutIt + 8);
  }
  piVar4 = *(int **)((int)pOutIt + 4);
  if (*(char *)((int)piVar6 + 0x15) == '\0') {
    piVar6[1] = (int)piVar4;
  }
  if (*(void **)(*(int *)((int)this + 4) + 4) == pOutIt) {
    *(int **)(*(int *)((int)this + 4) + 4) = piVar6;
  }
  else if ((void *)*piVar4 == pOutIt) {
    *piVar4 = (int)piVar6;
  }
  else {
    piVar4[2] = (int)piVar6;
  }
  piVar5 = *(int **)((int)this + 4);
  if ((void *)*piVar5 == pOutIt) {
    piVar2 = piVar4;
    if (*(char *)((int)piVar6 + 0x15) == '\0') {
      piVar2 = (int *)FUN_004e12a0(piVar6);
    }
    *piVar5 = (int)piVar2;
  }
  iVar1 = *(int *)((int)this + 4);
  if (*(void **)(iVar1 + 8) == pOutIt) {
    if (*(char *)((int)piVar6 + 0x15) == '\0') {
      uVar3 = FUN_00421b70(piVar6);
      *(uint32_t /* width from decompiler */ *)(iVar1 + 8) = uVar3;
    }
    else {
      *(int **)(iVar1 + 8) = piVar4;
    }
  }
  if (*(char *)((int)pOutIt + 0x14) == '\x01') {
    if (piVar6 != *(int **)(*(int *)((int)this + 4) + 4)) {
      do {
        piVar5 = piVar4;
        if ((char)piVar6[5] != '\x01') break;
        piVar4 = (int *)*piVar5;
        if (piVar6 == piVar4) {
          piVar4 = (int *)piVar5[2];
          if ((char)piVar4[5] == '\0') {
            *(uint8_t *)(piVar4 + 5) = 1;
            *(uint8_t *)(piVar5 + 5) = 0;
            FUN_004e22d0(piVar5);
            piVar4 = (int *)piVar5[2];
          }
          if (*(char *)((int)piVar4 + 0x15) == '\0') {
            if ((*(char *)(*piVar4 + 0x14) != '\x01') || (*(char *)(piVar4[2] + 0x14) != '\x01')) {
              if (*(char *)(piVar4[2] + 0x14) == '\x01') {
                *(uint8_t *)(*piVar4 + 0x14) = 1;
                *(uint8_t *)(piVar4 + 5) = 0;
                FUN_006753b0(piVar4);
                piVar4 = (int *)piVar5[2];
              }
              *(char *)(piVar4 + 5) = (char)piVar5[5];
              *(uint8_t *)(piVar5 + 5) = 1;
              *(uint8_t *)(piVar4[2] + 0x14) = 1;
              FUN_004e22d0(piVar5);
              break;
            }
map_erase_recolor_black:
            *(uint8_t *)(piVar4 + 5) = 0;
          }
        }
        else {
          if ((char)piVar4[5] == '\0') {
            *(uint8_t *)(piVar4 + 5) = 1;
            *(uint8_t *)(piVar5 + 5) = 0;
            FUN_006753b0(piVar5);
            piVar4 = (int *)*piVar5;
          }
          if (*(char *)((int)piVar4 + 0x15) == '\0') {
            if ((*(char *)(piVar4[2] + 0x14) == '\x01') && (*(char *)(*piVar4 + 0x14) == '\x01'))
            goto map_erase_recolor_black;
            if (*(char *)(*piVar4 + 0x14) == '\x01') {
              *(uint8_t *)(piVar4[2] + 0x14) = 1;
              *(uint8_t *)(piVar4 + 5) = 0;
              FUN_004e22d0(piVar4);
              piVar4 = (int *)*piVar5;
            }
            *(char *)(piVar4 + 5) = (char)piVar5[5];
            *(uint8_t *)(piVar5 + 5) = 1;
            *(uint8_t *)(*piVar4 + 0x14) = 1;
            FUN_006753b0(piVar5);
            break;
          }
        }
        piVar4 = (int *)piVar5[1];
        piVar6 = piVar5;
      } while (piVar5 != *(int **)(*(int *)((int)this + 4) + 4));
    }
    *(uint8_t *)(piVar6 + 5) = 1;
  }
                    /* WARNING: Subroutine does not return */
  operator_delete(pOutIt);
}
