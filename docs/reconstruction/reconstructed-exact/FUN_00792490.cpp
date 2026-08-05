// =============================================================================
// FUN_00792490  (scaffold twin of UiWidget_TeardownIfActive)
// -----------------------------------------------------------------------------
// Stable ID: aa_00792490
// Address:   0x00792490  (autoassault.exe, image base 0x400000)
// System:    ui
// Generated: 2026-07-23 scaffold; dual seal refine 2026-07-29 W22-F
// Exactness: Behavior-preserving rewrite of decompiler control flow. Not modernization.
// Bit-for-bit vs retail EXE: DEFERRED.
// Canonical name: UiWidget_TeardownIfActive
// See: reconstructed-exact/UiWidget_TeardownIfActive.cpp
// Embedded strings:
//   - "HashError:TraversalLock, already locked for traversal"
//   - "VOG_DEBUG_STOP"
//   - "HashError:TraverseToNext, not locked for traversal"
// =============================================================================

#include <stdint.h>

extern void FUN_0074e260(uint32_t);
extern void FUN_007a4480(int, const char*);

void __fastcall FUN_00792490(int* param_1)
{
  int* piVar1;
  int* piVar2;
  char cVar3;
  int iVar4;
  int iVar5;

  cVar3 = (**(code**)(*param_1 + 0x3d8))();
  if (cVar3 != '\0') {
    (**(code**)(*param_1 + 0x330))(8);
    *(uint8_t*)(param_1 + 0x23) = 0;
    *(uint8_t*)(param_1 + 0x32) = 0;
    *(uint8_t*)((int)param_1 + 0x492) = 0;
    if (param_1[0xab] != 0) {
      if (param_1[0xaa] != 0) {
        iVar4 = *(int*)(param_1[0xaa] + 4);
        piVar2 = *(int**)(iVar4 + 0x3c);
        if (piVar2 != (int*)0x0) {
          piVar1 = piVar2 + 1;
          *piVar1 = *piVar1 + -1;
          if (*piVar1 == 0) {
            (**(code**)(*piVar2 + 8))();
          }
        }
        *(uint32_t*)(iVar4 + 0x3c) = 0;
        FUN_0074e260(*(uint32_t*)(param_1[0xab] + 0x8c));
      }
      if ((uint32_t*)param_1[0xab] != (uint32_t*)0x0) {
        (*(code*)**(uint32_t**)param_1[0xab])(1);
      }
      param_1[0xab] = 0;
    }
    (**(code**)(*param_1 + 0x58))();
    iVar4 = param_1[0x136];
    iVar5 = 0;
    if (*(char*)(iVar4 + 0x1d) != '\0') {
      FUN_007a4480(0, "HashError:TraversalLock, already locked for traversal");
      FUN_007a4480(0, "VOG_DEBUG_STOP");
    }
    *(uint8_t*)(iVar4 + 0x1d) = 1;
    while (true) {
      iVar4 = param_1[0x136];
      if (*(char*)(iVar4 + 0x1d) == '\0') {
        FUN_007a4480(0, "HashError:TraverseToNext, not locked for traversal");
        FUN_007a4480(0, "VOG_DEBUG_STOP");
      }
      if (iVar5 == 0) {
        iVar5 = *(int*)(iVar4 + 0x14);
      } else {
        iVar5 = *(int*)(iVar5 + 0x14);
      }
      if (iVar5 == 0) {
        iVar4 = 0;
      } else {
        iVar4 = *(int*)(iVar5 + 8);
      }
      if (iVar4 == 0) break;
      (**(code**)(*param_1 + 0xb0))(iVar4);
    }
    *(uint8_t*)(param_1[0x136] + 0x1d) = 0;
    (**(code**)(*param_1 + 0x3b4))();
    cVar3 = (**(code**)(*param_1 + 0x1c0))();
    if (cVar3 != '\0') {
      if ((uint32_t*)param_1[0xaa] != (uint32_t*)0x0) {
        (*(code*)**(uint32_t**)param_1[0xaa])(1);
      }
      param_1[0xaa] = 0;
    }
    if ((uint32_t*)param_1[0x130] != (uint32_t*)0x0) {
      (*(code*)**(uint32_t**)param_1[0x130])(1);
    }
    param_1[0x130] = 0;
    param_1[0x12e] = 0;
    param_1[0x12f] = 0;
    param_1[0x12d] = 0;
  }
  return;
}
