// =============================================================================
// PalToolNoMap_Host0x40_MaterialAndShadowVolInit_Inferred
// -----------------------------------------------------------------------------
// Stable ID: aa_0098df00
// Address:   0x0098df00–0x0098e29f  (autoassault.exe, image base 0x400000)
// System:    palantir graphics / PalTool material + visible shadow volume
// Generated: 2026-08-04 W37-A dual seal (wave36 residual; live decompile)
// Exactness: Behavior-preserving rewrite of decompiler control flow.
// Bit-for-bit vs retail EXE: DEFERRED (no Launcher).
// =============================================================================
//
// PURPOSE:
//   Post-ctor init for HostPtrTable12 slot10 host (size 0x40 from caller
//   FUN_0073c810). Three material stages:
//     +0x28  PalToolMaterialNoMap.fx   (DepthBias/GhostAlpha + Mat* ;
//                                       emissive RGBA 1,0.2,0.2,1)
//     +0x30  PalVisibleShadowVolume.fx (SolidColor 0,1,0,0.5 ;
//                                       WireColor  0,1,0,0.5)  // ADV 2026-08-04: not blue wire
//     +0x38  PalVisibleShadowVolume.fx (SolidColor 0,0,1,0.5 ;
//                                       WireColor  0,0,1,0.5)
//   Each stage ends with FUN_0073d940 refcount-swap. Always returns 0.
//
// ABI: host in EAX (decompiler in_EAX). Caller stores host then calls with
// no stack args. Modeled here as an explicit C parameter.
//
// Shared float pool (numeric only — Ghidra names are cross-domain reuse):
//   g_flMsToSeconds_Inferred @ 0x00a0f72c = 0.001f → DepthBias
//   g_flMultiKillCountBlend  @ 0x00a0f730 = 0.1f   → GhostAlpha
//   g_flOne                  @ 0x00a0f2a0 = 1.0f
//   DAT_00a0f70c                          = 0.2f   → stage1 emissive G/B
//   DAT_00a0f298                          = 0.5f   → shadow alpha

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

extern "C" uint32_t PalToolNoMap_Host0x40_MaterialAndShadowVolInit_Inferred(void *host) {
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

  // ---- Stage 1: PalToolMaterialNoMap @ host+0x28 ----
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

  // ---- Stage 2: PalVisibleShadowVolume @ host+0x30 ----
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

  // ---- Stage 3: PalVisibleShadowVolume @ host+0x38 ----
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

// Ghidra twin: FUN_0098df00 (host in EAX)
