// =============================================================================
// StdVector_Dword_InsertN_Inferred  (Ghidra: FUN_004507a0)
// -----------------------------------------------------------------------------
// Stable ID: aa_004507a0
// Address:   0x004507a0 – 0x00450959  (autoassault.exe, image base 0x400000)
// System:    util / container (MSVC-style vector<uint32_t> insert-n)
// Generated: 2026-07-29 W18-Q OWN-ONLY dual (decompile + read_memory)
// Exactness: Behavior-preserving rewrite of decompiler control flow. Not modernization.
// Bit-for-bit vs retail EXE: DEFERRED.
// =============================================================================

/*
 * Insert `count` copies of a single fill dword at insertPos.
 * ABI: __thiscall; stack insertPos, count, fillSrc*; ret 0xC.
 * Shell: begin@+4 end@+8 capEnd@+0xC; element width 4; max count 0x3FFFFFFF.
 * Paths: realloc+geometric growth | hybrid mid-insert | in-place backward move.
 * Grow callee of StdVector_DwordResize (FUN_004367f0).
 */

#include <stdint.h>
#include <stdlib.h>

void *operator_new(uint32_t n);
void operator_delete(void *p);
uint64_t FUN_004540b0(void);
uint32_t FUN_004e2e80(void *first, void *last, void *dest);
uint32_t FUN_004e2f70(void *dest, uint32_t count, void *fill);
void FUN_004e24d0(void *first, void *last, void *dest_end);
void FUN_005739b0(void *first, void *last, void *fill);

void __thiscall StdVector_Dword_InsertN_Inferred(
    int param_1 /* this */,
    int param_2 /* insertPos */,
    uint32_t param_3 /* count */,
    uint32_t *param_4 /* fillSrc */)
{
  void *pvVar1;
  int iVar2;
  uint32_t uVar3;
  void *pvVar4;
  uint32_t uVar5;
  int iVar6;
  int iVar7;
  uint64_t uVar8;

  iVar6 = *(int *)(param_1 + 4);
  param_4 = (uint32_t *)*param_4; /* collapse to fill dword value held via &local */
  if (iVar6 == 0) {
    iVar2 = 0;
  } else {
    iVar2 = *(int *)(param_1 + 0xc) - iVar6 >> 2;
  }
  uVar8 = ((uint64_t)(uint32_t)iVar6 << 32) | (uint32_t)iVar2;
  if (param_3 != 0) {
    if (iVar6 == 0) {
      iVar6 = 0;
    } else {
      iVar6 = *(int *)(param_1 + 8) - iVar6 >> 2;
    }
    if (0x3fffffffU - iVar6 < param_3) {
      uVar8 = FUN_004540b0();
    }
    iVar6 = (int)(uVar8 >> 32);
    uVar3 = (uint32_t)uVar8;
    if (iVar6 == 0) {
      iVar2 = 0;
    } else {
      iVar2 = *(int *)(param_1 + 8) - iVar6 >> 2;
    }
    if (uVar3 < (uint32_t)(iVar2 + param_3)) {
      if (0x3fffffff - (uVar3 >> 1) < uVar3) {
        uVar3 = 0;
      } else {
        uVar3 = uVar3 + (uVar3 >> 1);
      }
      if (iVar6 == 0) {
        iVar2 = 0;
      } else {
        iVar2 = *(int *)(param_1 + 8) - iVar6 >> 2;
      }
      if (uVar3 < (uint32_t)(iVar2 + param_3)) {
        if (iVar6 == 0) {
          iVar6 = 0;
        } else {
          iVar6 = *(int *)(param_1 + 8) - iVar6 >> 2;
        }
        uVar3 = (uint32_t)(iVar6 + param_3);
      }
      pvVar4 = operator_new(uVar3 * 4);
      uVar5 = FUN_004e2e80(*(void **)(param_1 + 4), (void *)param_2, pvVar4);
      uVar5 = FUN_004e2f70((void *)(uintptr_t)uVar5, param_3, &param_4);
      FUN_004e2e80((void *)param_2, *(void **)(param_1 + 8), (void *)(uintptr_t)uVar5);
      pvVar1 = *(void **)(param_1 + 4);
      if (pvVar1 == (void *)0x0) {
        iVar6 = 0;
      } else {
        iVar6 = *(int *)(param_1 + 8) - (int)pvVar1 >> 2;
      }
      if (pvVar1 != (void *)0x0) {
        operator_delete(pvVar1);
      }
      *(void **)(param_1 + 4) = pvVar4;
      *(void **)(param_1 + 0xc) = (void *)(uVar3 * 4 + (int)pvVar4);
      *(void **)(param_1 + 8) = (void *)((int)pvVar4 + (param_3 + iVar6) * 4);
      return;
    }
    iVar2 = *(int *)(param_1 + 8);
    iVar6 = (int)(param_3 * 4);
    if ((uint32_t)(iVar2 - param_2 >> 2) < param_3) {
      FUN_004e2e80((void *)param_2, (void *)iVar2, (void *)(iVar6 + param_2));
      FUN_004e2f70(*(void **)(param_1 + 8),
                   param_3 - (*(int *)(param_1 + 8) - param_2 >> 2), &param_4);
      *(int *)(param_1 + 8) = *(int *)(param_1 + 8) + iVar6;
      FUN_005739b0((void *)param_2, (void *)(*(int *)(param_1 + 8) + param_3 * -4),
                   &param_4);
      return;
    }
    iVar7 = iVar2 + (int)param_3 * -4;
    uVar5 = FUN_004e2e80((void *)iVar7, (void *)iVar2, (void *)iVar2);
    *(uint32_t *)(param_1 + 8) = uVar5;
    FUN_004e24d0((void *)param_2, (void *)iVar7, (void *)iVar2);
    FUN_005739b0((void *)param_2, (void *)(iVar6 + param_2), &param_4);
  }
  return;
}

void __thiscall FUN_004507a0(int param_1, int param_2, uint32_t param_3, uint32_t *param_4)
{
  StdVector_Dword_InsertN_Inferred(param_1, param_2, param_3, param_4);
}
