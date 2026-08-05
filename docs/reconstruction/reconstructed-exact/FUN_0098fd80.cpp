// =============================================================================
// FUN_0098fd80  (Ghidra twin)
// -----------------------------------------------------------------------------
// Stable ID: aa_0098fd80
// Address:   0x0098fd80–0x0098fee9
// Canonical clean:
//   PalToolNoMap_Host0x30_MaterialSlot0x28_Init_Inferred.cpp
// W37-A: 2026-08-04 live decompile ≡ raw; dual A/B sealed.
// =============================================================================

#include <cstdint>

extern float g_flMsToSeconds_Inferred;
extern float g_flMultiKillCountBlend;
extern float g_flOne;
extern uint32_t DAT_00a0f720;

extern void FUN_00989e00(void *out_handle, const char *name);
extern uint32_t FUN_009701d0(void *name_shell);
extern uint32_t FUN_00442640(const char *param_name, float *value);
extern int *FUN_00752370(void *out_handle, const char *param_name);
extern uint32_t FUN_0096fff0(int *mat_slot, int handle);
extern int *FUN_0073d940(int mat_holder);

extern "C" uint32_t FUN_0098fd80(int param_1) {
  int *piVar1;
  int *piVar2;
  int *piVar3;
  int *piVar4;
  uint8_t local_20[4];
  float local_1c;
  float local_18;
  uint8_t local_14[4];
  float local_10;
  uint32_t local_c;
  uint32_t local_8;
  float local_4;

  FUN_00989e00(local_20, "PalToolMaterialNoMap.fx");
  piVar4 = reinterpret_cast<int *>(param_1 + 0x28);
  FUN_009701d0(local_20);
  local_1c = g_flMsToSeconds_Inferred;
  FUN_00442640("DepthBias", &local_1c);
  local_18 = g_flMultiKillCountBlend;
  FUN_00442640("GhostAlpha", &local_18);

  if (*piVar4 == 0) {
    param_1 = -1;
    piVar3 = &param_1;
  } else {
    piVar3 = FUN_00752370(local_20, "MatDiffuse");
  }
  if (*piVar3 >= 0) {
    FUN_0096fff0(piVar4, *piVar3);
  }

  if (*piVar4 == 0) {
    param_1 = -1;
    piVar3 = &param_1;
  } else {
    piVar3 = FUN_00752370(local_14, "MatSpecular");
  }
  if (*piVar3 >= 0) {
    FUN_0096fff0(piVar4, *piVar3);
  }

  local_10 = g_flOne;
  local_c = DAT_00a0f720;
  local_8 = DAT_00a0f720;
  local_4 = g_flOne;
  if (*piVar4 == 0) {
    param_1 = -1;
    piVar3 = &param_1;
  } else {
    piVar3 = FUN_00752370(&param_1, "MatEmissive");
  }
  if (*piVar3 >= 0) {
    FUN_0096fff0(piVar4, *piVar3);
  }

  piVar3 = FUN_0073d940(*piVar4);
  if (piVar3 != nullptr) {
    piVar3[1] = piVar3[1] + 1;
    if (piVar3[1] == 1) {
      reinterpret_cast<void (**)()>(*reinterpret_cast<void **>(piVar3))[1]();
    }
    piVar2 = reinterpret_cast<int *>(*piVar4);
    if (piVar2 != nullptr) {
      piVar1 = piVar2 + 1;
      *piVar1 = *piVar1 - 1;
      if (*piVar1 == 0) {
        reinterpret_cast<void (**)()>(*reinterpret_cast<void **>(piVar2))[2]();
      }
    }
    *piVar4 = reinterpret_cast<int>(piVar3);
  }
  return 0;
}
