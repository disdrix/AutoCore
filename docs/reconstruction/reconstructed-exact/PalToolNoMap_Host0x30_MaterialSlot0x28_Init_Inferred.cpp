// =============================================================================
// PalToolNoMap_Host0x30_MaterialSlot0x28_Init_Inferred
// -----------------------------------------------------------------------------
// Stable ID: aa_0098fd80
// Address:   0x0098fd80–0x0098fee9  (autoassault.exe, image base 0x400000)
// System:    palantir graphics / PalTool material (no-map)
// Generated: 2026-08-04 W37-A dual seal (live decompile + read_memory)
// Exactness: Behavior-preserving rewrite of decompiler control flow.
// Bit-for-bit vs retail EXE: DEFERRED (no Launcher).
// =============================================================================
//
// PURPOSE:
//   Post-ctor init for HostPtrTable12 slot9 host (size 0x30 from caller
//   FUN_0073c810): bind PalToolMaterialNoMap.fx into material slot host+0x28,
//   set DepthBias=0.001 / GhostAlpha=0.1, bind MatDiffuse/MatSpecular/
//   MatEmissive (emissive RGBA 1,0.4,0.4,1), refcount-swap holder.
//   Always returns 0 (does not OR intermediate statuses — unlike FUN_00731130).
//
// ABI: stack host* (param_1). Sole caller @ 0x0073cac3 pushes host.
// Not ECX-thiscall.
//
// Shared float pool (numeric only — Ghidra names are cross-domain reuse):
//   g_flMsToSeconds_Inferred @ 0x00a0f72c = 0.001f  → DepthBias
//   g_flMultiKillCountBlend  @ 0x00a0f730 = 0.1f    → GhostAlpha
//   g_flOne                  @ 0x00a0f2a0 = 1.0f
//   DAT_00a0f720                          = 0.4f    → emissive G/B

#include <cstdint>

extern float g_flMsToSeconds_Inferred;
extern float g_flMultiKillCountBlend;
extern float g_flOne;
extern uint32_t DAT_00a0f720; // 0.4f bit pattern; decompiler loads as undefined4 into G/B

extern void FUN_00989e00(void *out_handle, const char *name);
extern uint32_t FUN_009701d0(void *name_shell);
extern uint32_t FUN_00442640(const char *param_name, float *value);
extern int *FUN_00752370(void *out_handle, const char *param_name);
extern uint32_t FUN_0096fff0(int *mat_slot, int handle);
extern int *FUN_0073d940(int mat_holder);

extern "C" uint32_t PalToolNoMap_Host0x30_MaterialSlot0x28_Init_Inferred(void *host) {
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
  // Decompiler reuses stack formal host as -1 sentinel storage (int overwrite).
  int param_as_sentinel = reinterpret_cast<int>(host);

  FUN_00989e00(local_20, "PalToolMaterialNoMap.fx");
  piVar4 = reinterpret_cast<int *>(reinterpret_cast<char *>(host) + 0x28);
  FUN_009701d0(local_20);
  local_1c = g_flMsToSeconds_Inferred;
  FUN_00442640("DepthBias", &local_1c);
  local_18 = g_flMultiKillCountBlend;
  FUN_00442640("GhostAlpha", &local_18);

  if (*piVar4 == 0) {
    param_as_sentinel = -1;
    piVar3 = &param_as_sentinel;
  } else {
    piVar3 = FUN_00752370(local_20, "MatDiffuse");
  }
  if (*piVar3 >= 0) {
    FUN_0096fff0(piVar4, *piVar3);
  }

  if (*piVar4 == 0) {
    param_as_sentinel = -1;
    piVar3 = &param_as_sentinel;
  } else {
    piVar3 = FUN_00752370(local_14, "MatSpecular");
  }
  if (*piVar3 >= 0) {
    FUN_0096fff0(piVar4, *piVar3);
  }

  // Emissive RGBA pack: (1.0, 0.4, 0.4, 1.0)
  local_10 = g_flOne;
  local_c = DAT_00a0f720;
  local_8 = DAT_00a0f720;
  local_4 = g_flOne;
  if (*piVar4 == 0) {
    param_as_sentinel = -1;
    piVar3 = &param_as_sentinel;
  } else {
    piVar3 = FUN_00752370(&param_as_sentinel, "MatEmissive");
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

// Ghidra twin: FUN_0098fd80(int param_1) → same body
