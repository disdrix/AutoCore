// =============================================================================
// FUN_0061b6f0  →  CVOGHBSkill_SharedOnHeartBeat_Inferred
// -----------------------------------------------------------------------------
// Stable ID: aa_0061b6f0
// Address:   0x0061b6f0  (autoassault.exe, image base 0x400000)
// System:    skills-abilities
// Generated: 2026-07-23 scaffold; 2026-08-04 WQ9D-C seal
// Exactness: Behavior-preserving rewrite of decompiler control flow.
// Bit-for-bit vs retail EXE: DEFERRED.
// =============================================================================

// Prefer named clean: CVOGHBSkill_SharedOnHeartBeat_Inferred.cpp
// This file keeps the Ghidra-shaped body for raw-aligned readers.

#include <cstdint>

extern "C" void FUN_005787a0(std::uint32_t *pStatus);
extern "C" void *FUN_00578270(...);
extern "C" void FUN_00589bc0(...);
extern "C" void FUN_00589c70(...);
extern "C" void FUN_00589d90(...);
extern "C" void FUN_0058cc40(...);
extern "C" void FUN_0058d8e0(...);
extern "C" void FUN_0058c3b0(...);
extern "C" char FUN_005134e0(...);
extern "C" void *FUN_0061b960(...);
extern std::uint32_t DAT_00af4bd0;
extern float g_flZero;
extern void *DAT_00d02ac0;

void __thiscall FUN_0061b6f0(std::int32_t *param_1, std::uint32_t *param_2)
{
  char cVar1;
  int iVar2;
  int *piVar3;
  std::uint32_t *puVar4;
  void *uVar5;
  std::uint32_t local_18;
  int iStack_14;
  std::uint8_t auStack_10[16];

  FUN_005787a0(&local_18);
  param_1[0x1b2] = param_1[0x1b2] + 1;
  if (((local_18 != DAT_00af4bd0) && ((char)param_1[8] == '\0')) &&
      ((1 < param_1[3] || (param_1[3] == -1000)))) {
    if ((short)param_1[0x1d] != 0) {
      iVar2 = (**(int (**)())(*(int *)param_1[6] + 0x214))();
      if (iVar2 != 0) {
        piVar3 = (int *)(**(int (**)())(*(int *)param_1[6] + 0x214))();
        puVar4 = (std::uint32_t *)FUN_0061b960(auStack_10);
        (**(void (**)(int, std::uint32_t, std::uint32_t, std::uint32_t, std::uint32_t))(
             *piVar3 + 0x88))(
            (int)((float)(int)(short)param_1[0x1d] * (float)param_1[0x1b1]),
            puVar4[0], puVar4[1], puVar4[2], puVar4[3]);
      }
    }
    if ((float)param_1[0x45] != g_flZero) {
      uVar5 = FUN_00578270(param_1[6], (float)param_1[0x1b1] * (float)param_1[0x45]);
      FUN_00589bc0(uVar5);
    }
    if ((char)param_1[0x11] != '\0') {
      iVar2 = (**(int (**)())(*(int *)param_1[6] + 0x19c))();
      if (iVar2 == 0) {
        cVar1 = FUN_005134e0();
        if (cVar1 == '\0') {
          (**(void (**)(int, int))(*param_1 + 0x18))(1, 1);
        }
      } else {
        cVar1 = FUN_005134e0();
        if (cVar1 == '\0') {
          (**(void (**)(int, int))(*param_1 + 0x18))(1, 1);
        }
      }
    }
    if ((*(std::uint8_t *)(param_1 + 0x192) & 2) != 0) {
      uVar5 = FUN_00578270(param_1[6], (float)param_1[0x1b1] * (float)param_1[0x18], 0);
      FUN_00589c70(uVar5);
    }
    if ((float)param_1[0x51] != g_flZero) {
      uVar5 = FUN_00578270(param_1[6], (float)param_1[0x1b1] * (float)param_1[0x51]);
      FUN_00589d90(uVar5);
    }
    if ((*(std::uint8_t *)((int)param_1 + 0x649) & 0x80) != 0) {
      uVar5 = FUN_00578270(param_1[6], (float)param_1[0x1b1] * (float)param_1[0x19]);
      FUN_0058cc40(uVar5);
    }
    if ((*(std::uint8_t *)(param_1 + 0x192) & 1) != 0) {
      uVar5 = FUN_00578270(param_1[6], param_1 + 9, param_1[0x1a2], param_1[0x1a8],
                           param_1[0x1b2]);
      FUN_0058d8e0(uVar5);
    }
    if ((float)param_1[0x44] != g_flZero) {
      iStack_14 = param_1[0x44];
      uVar5 = FUN_00578270(param_1[6], iStack_14, &DAT_00d02ac0);
      FUN_0058c3b0(uVar5);
    }
    (**(void (**)())(*param_1 + 0x50))();
  }
  *param_2 = local_18;
  return;
}
