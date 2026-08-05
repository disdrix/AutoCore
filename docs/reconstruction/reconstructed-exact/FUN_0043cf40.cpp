// =============================================================================
// FUN_0043cf40  (twin of GuardedVector_GrowAssignRangeCore)
// -----------------------------------------------------------------------------
// Stable ID: aa_0043cf40
// Address:   0x0043cf40–0x0043d2f6
// See:       reconstructed-exact/GuardedVector_GrowAssignRangeCore.cpp
//
// Full decompiler-faithful body (scaffold readability pass) follows for tools
// that want line-for-line CF without the named wrapper.
// =============================================================================

#include <cstdint>

extern "C" void FUN_0043ce10(uint32_t* elem);
extern "C" void FUN_0043c830(uint32_t* elem);
extern "C" void FUN_0043d300(void*, void*, uint32_t, void*, uint32_t, void*, uint32_t, void*);
extern "C" void FUN_0043d390(void*, void*, uint32_t, void*, uint32_t, void*, uint32_t, void*);

// stdcall 8 args; RET 0x20. Decompiler shows 7; 8th present for cleanup.
void FUN_0043cf40(int param_1, uint32_t param_2, uint param_3, int param_4, uint param_5,
                  int param_6, uint param_7, uint32_t /*param_8*/)
{
  int iVar1;
  uint uVar2;
  int iVar3;
  uint uVar4;
  uint uVar5;
  uint uVar6;
  uint uVar7;

  iVar3 = param_4;
  uVar5 = param_3 - *(int*)(param_1 + 0xc);
  uVar4 = *(int*)(param_1 + 0x10) - uVar5;
  uVar7 = param_7 - param_5;
  param_2 = param_4;

  if (uVar5 < uVar4) {
    uVar4 = uVar7;
    if (uVar5 < uVar7) {
      uVar6 = param_5 + (uVar7 - uVar5);
      uVar4 = uVar6;
      while ((param_4 != iVar3) || (param_5 != uVar4)) {
        uVar4 = uVar4 - 1;
        uVar2 = uVar4 >> 2;
        iVar1 = uVar2 * -4;
        if (*(uint*)(iVar3 + 8) <= uVar2) {
          uVar2 = uVar2 - *(uint*)(iVar3 + 8);
        }
        FUN_0043ce10((uint32_t*)(*(int*)(*(int*)(iVar3 + 4) + uVar2 * 4) + (uVar4 + iVar1) * 4));
      }
      while ((param_3 = uVar5), uVar5 != 0) {
        uVar5 = *(int*)(param_1 + 0xc) + (uVar7 - 1);
        uVar4 = uVar5 >> 2;
        iVar1 = uVar4 * -4;
        if (*(uint*)(param_1 + 8) <= uVar4) {
          uVar4 = uVar4 - *(uint*)(param_1 + 8);
        }
        FUN_0043ce10((uint32_t*)(*(int*)(*(int*)(param_1 + 4) + uVar4 * 4) + (uVar5 + iVar1) * 4));
        uVar5 = param_3 - 1;
      }
      FUN_0043d390(&param_4, (void*)iVar3, uVar6, (void*)param_6, param_7, (void*)param_1,
                   *(int*)(param_1 + 0xc) + uVar7, (void*)param_1);
      return;
    }
    while ((param_3 = uVar4), param_3 != 0) {
      uVar6 = *(int*)(param_1 + 0xc) + (uVar7 - 1);
      uVar4 = uVar6 >> 2;
      iVar3 = uVar4 * -4;
      if (*(uint*)(param_1 + 8) <= uVar4) {
        uVar4 = uVar4 - *(uint*)(param_1 + 8);
      }
      FUN_0043ce10((uint32_t*)(*(int*)(*(int*)(param_1 + 4) + uVar4 * 4) + (uVar6 + iVar3) * 4));
      uVar4 = param_3 - 1;
    }
    iVar3 = *(int*)(param_1 + 0xc) + uVar7;
    param_2 = param_1;
    FUN_0043d390(&param_2, (void*)param_1, iVar3 + uVar7, (void*)param_1, iVar3 + uVar5,
                 (void*)param_1, iVar3, (void*)param_1);
    iVar3 = *(int*)(param_1 + 0xc) + uVar5;
  } else {
    if (uVar4 < uVar7) {
      uVar7 = param_5 + uVar4;
      param_3 = uVar7;
      for (; (iVar3 != param_6) || (uVar7 != param_7); uVar7 = uVar7 + 1) {
        uVar6 = uVar7 >> 2;
        iVar1 = uVar6 * -4;
        if (*(uint*)(iVar3 + 8) <= uVar6) {
          uVar6 = uVar6 - *(uint*)(iVar3 + 8);
        }
        FUN_0043c830((uint32_t*)(*(int*)(*(int*)(iVar3 + 4) + uVar6 * 4) + (uVar7 + iVar1) * 4));
      }
      for (uVar7 = 0; uVar7 < uVar4; uVar7 = uVar7 + 1) {
        uVar2 = *(int*)(param_1 + 0xc) + uVar5 + uVar7;
        uVar6 = uVar2 >> 2;
        iVar3 = uVar6 * -4;
        if (*(uint*)(param_1 + 8) <= uVar6) {
          uVar6 = uVar6 - *(uint*)(param_1 + 8);
        }
        FUN_0043c830((uint32_t*)(*(int*)(*(int*)(param_1 + 4) + uVar6 * 4) + (uVar2 + iVar3) * 4));
      }
      FUN_0043d390(&param_4, (void*)param_4, param_5, (void*)param_2, param_3, (void*)param_1,
                   *(int*)(param_1 + 0xc) + uVar5, (void*)param_1);
      return;
    }
    for (param_3 = 0; param_3 < uVar7; param_3 = param_3 + 1) {
      uVar2 = *(int*)(param_1 + 0xc) + (param_3 - uVar7) + uVar4 + uVar5;
      uVar6 = uVar2 >> 2;
      iVar3 = uVar6 * -4;
      if (*(uint*)(param_1 + 8) <= uVar6) {
        uVar6 = uVar6 - *(uint*)(param_1 + 8);
      }
      FUN_0043c830((uint32_t*)(*(int*)(*(int*)(param_1 + 4) + uVar6 * 4) + (uVar2 + iVar3) * 4));
    }
    iVar3 = *(int*)(param_1 + 0xc) + uVar5;
    FUN_0043d300(&param_2, (void*)param_1, iVar3, (void*)param_1, (iVar3 + uVar4) - uVar7,
                 (void*)param_1, iVar3 + uVar4, (void*)param_1);
  }
  FUN_0043d390(&param_4, (void*)param_4, param_5, (void*)param_6, param_7, (void*)param_1, iVar3,
               (void*)param_1);
}
