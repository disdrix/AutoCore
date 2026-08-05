// =============================================================================
// PalToolNoMap_Host0x44_DualChannelInit_Inferred
// -----------------------------------------------------------------------------
// Stable ID: aa_00731130
// Address:   0x00731130  (autoassault.exe, image base 0x400000)
// Body:      0x00731130–0x007313fd (718 B / 0x2CE)
// System:    palantir graphics / PalTool material (no-map effect)
// Generated: 2026-07-29 W36-J dual seal (from live decompile + read_memory)
// Exactness: Behavior-preserving rewrite of decompiler control flow.
// Bit-for-bit vs retail EXE: DEFERRED.
// =============================================================================
//
// PURPOSE:
//   Init HostPtrTable12 slot5 host (size 0x44): bind PalToolMaterialNoMap.fx
//   into dual material slots at +0x34 and +0x3c (MatDiffuse/Ambient/Specular/
//   Emissive), refcount-swap holders, and build each channel via FUN_00730b50.
//   Returns bitwise OR of all per-step status codes.
//
// ABI: stdcall 1 stack arg; RET 4; not ECX-thiscall.
// Caller: FUN_0073c810 @ 0x0073c9ad only.
//
// Reject scaffold alias Gfx_PalToolMaterialNoMap_00731130 as incomplete —
// use structural dual-channel Host0x44 name below.

#include <cstdint>

extern void FUN_00989e00(void *name_shell, const char *path);
extern uint32_t FUN_009701d0(void *name_shell);
extern int *FUN_00752370(void *out_handle, const char *param_name);
extern uint32_t FUN_0096fff0(int *mat_slot, int handle);
extern uint32_t FUN_004246a0(void);
extern int *FUN_0073d940(int mat_holder);
extern uint32_t FUN_00730b50(void *host, int channel);

// Local helper: bind one material parameter; 0xFFFFFFFF if missing.
static uint32_t BindMatParam(int *mat_slot, int *handle_storage, const char *name) {
  int *hp;
  if (*mat_slot == 0) {
    *handle_storage = -1;
    hp = handle_storage;
  } else {
    hp = FUN_00752370(handle_storage, name);
  }
  if (*hp < 0) {
    return 0xFFFFFFFFu;
  }
  return FUN_0096fff0(mat_slot, *hp);
}

// Local helper: optional refcount swap via FUN_0073d940 into *mat_slot.
static void RefcountSwapMat(int *mat_slot) {
  int *neu = FUN_0073d940(*mat_slot);
  if (neu == nullptr) {
    return;
  }
  neu[1] = neu[1] + 1;
  if (neu[1] == 1) {
    // vtbl +4 first-acquire
    reinterpret_cast<void (**)()>(*reinterpret_cast<void **>(neu))[1]();
  }
  int *old = reinterpret_cast<int *>(*mat_slot);
  if (old != nullptr) {
    old[1] = old[1] - 1;
    if (old[1] == 0) {
      // vtbl +8 release
      reinterpret_cast<void (**)()>(*reinterpret_cast<void **>(old))[2]();
    }
  }
  *mat_slot = reinterpret_cast<int>(neu);
}

// One channel: effect bind + 4 params + device helper + refcount + mesh build.
static uint32_t InitChannel(void *host, int *mat_slot, int channel) {
  int local_handle = 0;
  uint32_t st_effect;
  uint32_t st_diff, st_amb, st_spec, st_emis = 0xFFFFFFFFu;
  uint32_t st_dev;
  uint32_t st_mesh;

  FUN_00989e00(&local_handle, "PalToolMaterialNoMap.fx");
  st_effect = FUN_009701d0(&local_handle);

  st_diff = BindMatParam(mat_slot, &local_handle, "MatDiffuse");
  st_amb = BindMatParam(mat_slot, &local_handle, "MatAmbient");
  st_spec = BindMatParam(mat_slot, &local_handle, "MatSpecular");
  // Emissive: raw only updates when handle >= 0 (keeps prior 0xFFFFFFFF seed on miss)
  {
    int *hp;
    if (*mat_slot == 0) {
      local_handle = -1;
      hp = &local_handle;
    } else {
      hp = FUN_00752370(&local_handle, "MatEmissive");
    }
    if (*hp >= 0) {
      st_emis = FUN_0096fff0(mat_slot, *hp);
    }
  }

  st_dev = FUN_004246a0();
  RefcountSwapMat(mat_slot);
  st_mesh = FUN_00730b50(host, channel);

  return st_effect | st_diff | st_amb | st_spec | st_emis | st_dev | st_mesh;
}

extern "C" uint32_t PalToolNoMap_Host0x44_DualChannelInit_Inferred(void *host) {
  // Channel 0: material at host+0x34
  int *mat0 = reinterpret_cast<int *>(reinterpret_cast<char *>(host) + 0x34);
  uint32_t a = InitChannel(host, mat0, 0);

  // Channel 1: material at host+0x3c
  int *mat1 = reinterpret_cast<int *>(reinterpret_cast<char *>(host) + 0x3c);
  uint32_t b = InitChannel(host, mat1, 1);

  // Note: retail ORs every intermediate (including two FUN_004246a0 results).
  // Helper fold above preserves OR-of-all-statuses semantics.
  return a | b;
}

// Ghidra twin name:
//   uint32_t FUN_00731130(int param_1);
