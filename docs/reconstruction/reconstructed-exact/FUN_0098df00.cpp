// =============================================================================
// FUN_0098df00  (Ghidra twin)
// -----------------------------------------------------------------------------
// Stable ID: aa_0098df00
// Address:   0x0098df00–0x0098e29f
// Canonical clean:
//   PalToolNoMap_Host0x40_MaterialAndShadowVolInit_Inferred.cpp
// W37-A: 2026-08-04 live decompile ≡ raw; dual A/B sealed.
// Host in EAX (decompiler in_EAX); no stack formal.
// =============================================================================

#include <cstdint>

extern float g_flMsToSeconds_Inferred;
extern float g_flMultiKillCountBlend;
extern float g_flOne;
extern float DAT_00a0f70c;
extern float DAT_00a0f298;

extern void FUN_00989e00(void *out_handle, const char *name);
extern uint32_t FUN_009701d0(void *name_shell);
extern uint32_t FUN_00442640(const char *param_name, float *value);
extern int *FUN_00752370(void *out_handle, const char *param_name);
extern uint32_t FUN_0096fff0(int *mat_slot, int handle);
extern int *FUN_0073d940(int mat_holder);

// Ghidra presents host as in_EAX (no stack arg). Model as explicit param for C.
extern "C" uint32_t FUN_0098df00(void *host /* in_EAX */) {
  int *piVar1;
  int *piVar2;
  int *piVar3;
  int *piVar4;
  int local_24;
  float local_20;
  float local_1c;
  int local_18;
  uint8_t local_14[4];
  float local_10;
  float local_c;
  float local_8;
  float local_4;

  FUN_00989e00(&local_24, "PalToolMaterialNoMap.fx");
  piVar1 = reinterpret_cast<int *>(reinterpret_cast<char *>(host) + 0x28);
  FUN_009701d0(&local_24);
  local_20 = g_flMsToSeconds_Inferred;
  FUN_00442640("DepthBias", &local_20);
  local_1c = g_flMultiKillCountBlend;
  FUN_00442640("GhostAlpha", &local_1c);
  if (*piVar1 == 0) {
    local_24 = -1;
    piVar4 = &local_24;
  } else {
    piVar4 = FUN_00752370(&local_18, "MatDiffuse");
  }
  if (*piVar4 >= 0) {
    FUN_0096fff0(piVar1, *piVar4);
  }
  if (*piVar1 == 0) {
    local_24 = -1;
    piVar4 = &local_24;
  } else {
    piVar4 = FUN_00752370(local_14, "MatSpecular");
  }
  if (*piVar4 >= 0) {
    FUN_0096fff0(piVar1, *piVar4);
  }
  local_10 = g_flOne;
  local_c = DAT_00a0f70c;
  local_8 = DAT_00a0f70c;
  local_4 = g_flOne;
  if (*piVar1 == 0) {
    local_24 = -1;
    piVar4 = &local_24;
  } else {
    piVar4 = FUN_00752370(&local_24, "MatEmissive");
  }
  if (*piVar4 >= 0) {
    FUN_0096fff0(piVar1, *piVar4);
  }
  piVar4 = FUN_0073d940(*piVar1);
  if (piVar4 != nullptr) {
    piVar4[1] = piVar4[1] + 1;
    if (piVar4[1] == 1) {
      reinterpret_cast<void (**)()>(*reinterpret_cast<void **>(piVar4))[1]();
    }
    piVar3 = reinterpret_cast<int *>(*piVar1);
    if (piVar3 != nullptr) {
      piVar2 = piVar3 + 1;
      *piVar2 = *piVar2 - 1;
      if (*piVar2 == 0) {
        reinterpret_cast<void (**)()>(*reinterpret_cast<void **>(piVar3))[2]();
      }
    }
    *piVar1 = reinterpret_cast<int>(piVar4);
  }

  FUN_00989e00(&local_24, "PalVisibleShadowVolume.fx");
  piVar1 = reinterpret_cast<int *>(reinterpret_cast<char *>(host) + 0x30);
  FUN_009701d0(&local_24);
  local_c = g_flOne;
  local_10 = 0.0f;
  local_8 = 0.0f;
  local_4 = DAT_00a0f298;
  if (*piVar1 == 0) {
    local_18 = -1;
    piVar4 = &local_18;
  } else {
    piVar4 = FUN_00752370(local_14, "SolidColor");
  }
  if (*piVar4 >= 0) {
    FUN_0096fff0(piVar1, *piVar4);
  }
  local_10 = 0.0f;
  local_8 = 0.0f;
  local_c = g_flOne;
  local_4 = DAT_00a0f298;
  if (*piVar1 == 0) {
    local_18 = -1;
    piVar4 = &local_18;
  } else {
    piVar4 = FUN_00752370(&local_18, "WireColor");
  }
  if (*piVar4 >= 0) {
    FUN_0096fff0(piVar1, *piVar4);
  }
  piVar4 = FUN_0073d940(*piVar1);
  if (piVar4 != nullptr) {
    piVar4[1] = piVar4[1] + 1;
    if (piVar4[1] == 1) {
      reinterpret_cast<void (**)()>(*reinterpret_cast<void **>(piVar4))[1]();
    }
    piVar3 = reinterpret_cast<int *>(*piVar1);
    if (piVar3 != nullptr) {
      piVar2 = piVar3 + 1;
      *piVar2 = *piVar2 - 1;
      if (*piVar2 == 0) {
        reinterpret_cast<void (**)()>(*reinterpret_cast<void **>(piVar3))[2]();
      }
    }
    *piVar1 = reinterpret_cast<int>(piVar4);
  }

  FUN_00989e00(&local_18, "PalVisibleShadowVolume.fx");
  piVar1 = reinterpret_cast<int *>(reinterpret_cast<char *>(host) + 0x38);
  FUN_009701d0(&local_18);
  local_8 = g_flOne;
  local_10 = 0.0f;
  local_c = 0.0f;
  local_4 = DAT_00a0f298;
  if (*piVar1 == 0) {
    local_24 = -1;
    piVar4 = &local_24;
  } else {
    piVar4 = FUN_00752370(local_14, "SolidColor");
  }
  if (*piVar4 >= 0) {
    FUN_0096fff0(piVar1, *piVar4);
  }
  local_10 = 0.0f;
  local_c = 0.0f;
  local_8 = g_flOne;
  local_4 = DAT_00a0f298;
  if (*piVar1 == 0) {
    local_24 = -1;
    piVar4 = &local_24;
  } else {
    piVar4 = FUN_00752370(&local_24, "WireColor");
  }
  if (*piVar4 >= 0) {
    FUN_0096fff0(piVar1, *piVar4);
  }
  piVar4 = FUN_0073d940(*piVar1);
  if (piVar4 != nullptr) {
    piVar4[1] = piVar4[1] + 1;
    if (piVar4[1] == 1) {
      reinterpret_cast<void (**)()>(*reinterpret_cast<void **>(piVar4))[1]();
    }
    piVar3 = reinterpret_cast<int *>(*piVar1);
    if (piVar3 != nullptr) {
      piVar2 = piVar3 + 1;
      *piVar2 = *piVar2 - 1;
      if (*piVar2 == 0) {
        reinterpret_cast<void (**)()>(*reinterpret_cast<void **>(piVar3))[2]();
      }
    }
    *piVar1 = reinterpret_cast<int>(piVar4);
  }
  return 0;
}
