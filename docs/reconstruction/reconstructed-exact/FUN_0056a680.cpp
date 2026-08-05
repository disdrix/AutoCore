// =============================================================================
// FUN_0056a680  (alias → Item_GetCycleTimeMs_Scaled_Inferred)
// -----------------------------------------------------------------------------
// Stable ID: aa_0056a680
// Address:   0x0056a680–0x0056a765  (autoassault.exe, image base 0x400000)
// System:    item / weapon combat stats
// Generated: 2026-07-29 W25-L (twin of named clean)
// Exactness: Behavior-preserving. Not modernization.
// Bit-for-bit vs retail EXE: DEFERRED.
// =============================================================================
// Canonical: reconstructed-exact/Item_GetCycleTimeMs_Scaled_Inferred.cpp

#include <cstdint>

extern float g_flOne;
extern float g_flMissionXpRoundBias;
extern "C" int FUN_0040dab0(float x);

// Ghidra-faithful surface.
uint32_t __thiscall FUN_0056a680(int param_1, char param_2)
{
  int* piVar1;
  int iVar2;
  int iVar3;
  uint32_t uVar4;
  float fVar5;
  float fVar6;

  if ((param_2 == '\0') &&
      (piVar1 = *(int**)(*(int*)(*(int*)(param_1 + 4) + 4) + 0xb0 + param_1),
       piVar1 != (int*)0x0)) {
    iVar2 = (**(int(**)())(*piVar1 + 0x214))();
    if (iVar2 != 0) {
      iVar2 = (**(int(**)())(
          **(int**)(*(int*)(*(int*)(param_1 + 4) + 4) + 0xb0 + param_1) + 0x214))();
      if (*(float*)(iVar2 + 0x1e8) != g_flOne) {
        iVar2 = *(int*)(param_1 + 0xd0);
        iVar3 = (**(int(**)())(
            **(int**)(*(int*)(*(int*)(param_1 + 4) + 4) + 0xb0 + param_1) + 0x214))();
        fVar5 = *(float*)(iVar3 + 0x1e8) * (float)iVar2;
        if (0.0f <= fVar5) {
          fVar6 = fVar5 + g_flMissionXpRoundBias;
        } else {
          fVar6 = fVar5 - g_flMissionXpRoundBias;
        }
        if (500 < (int)fVar6) {
          uVar4 = (uint32_t)FUN_0040dab0(fVar5);
          return uVar4;
        }
        return 500;
      }
    }
  }
  return *(uint32_t*)(param_1 + 0xd0);
}
