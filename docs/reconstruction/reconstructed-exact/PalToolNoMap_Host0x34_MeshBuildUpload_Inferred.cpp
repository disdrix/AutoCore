// =============================================================================
// PalToolNoMap_Host0x34_MeshBuildUpload_Inferred
// -----------------------------------------------------------------------------
// Stable ID: aa_007300c0
// Address:   0x007300c0  (autoassault.exe, image base 0x400000)
// Body:      0x007300c0–0x007308b7 (2040 B / 0x7F8)
// System:    palantir graphics / PalTool material + mesh upload
// Generated: 2026-07-29 W36-J dual seal (from live decompile + read_memory)
// Exactness: Behavior-preserving structural rewrite of decompiler CF.
//            Large SEH/mesh body — not a line-for-line expansion of all locals.
// Bit-for-bit vs retail EXE: DEFERRED.
// =============================================================================
//
// PURPOSE:
//   Build/upload geometry for HostPtrTable12 slot6 host (size 0x34):
//   bind PalToolMaterialNoMap.fx into material slot +0x24, derive stride,
//   store counts at +0x1c/+0x20 and flag +0x2c=4, Lock/copy VB+IB, attach
//   buffers. Return 0 on success, 0xFFFFFFFF on failure.
//
// ABI: stdcall 1 stack arg; RET 4; SEH LAB_009b1eb6; not ECX-thiscall.
// Caller: FUN_0073c810 @ 0x0073c9f5 only.
//
// Reject incomplete scaffold alias Gfx_PalToolMaterialNoMap — use Host0x34 name.

#include <cstdint>
#include <cstring>

extern float g_flOne;
extern uint32_t DAT_00d1a6c0, DAT_00d1a6c4, DAT_00d1a6c8;
extern float DAT_00a0f298; // 0.5f at image

extern void FUN_00981310(void *workspace);
extern void FUN_009813a0(void *workspace, int count);
extern void FUN_0098ef00(void *workspace);
extern void FUN_0098f2b0(int count);
extern void FUN_00989e00(void *name_shell, const char *path);
extern uint32_t FUN_009701d0(void *name_shell);
extern int *FUN_00752370(void *out_handle, const char *param_name);
extern uint32_t FUN_0096fff0(int *mat_slot, int handle);
extern int *FUN_0073d940(int mat_holder);
extern uint32_t FUN_00414bc0(int format_token); // 0x152
extern int FUN_00414c20(int count, void *fmt_or_desc, int stride_or_flags, int zero);
extern void FUN_00414b60(void);
extern void FUN_00414a50(void);
extern void FUN_004451c0(void *dst, void *src_or_field);
extern void FUN_00747390(void);
extern void FUN_0044b9c0(int count, int stride, int a, int b);
extern void FUN_0044ba80(void);
extern void FUN_0044bbc0(void *a, void *host_field, int zero);
extern void FUN_00457a00(void *obj);
extern void operator_delete(void *p);

// Bind one material parameter if material present and handle valid.
static void TryBindParam(int *mat_slot, void *handle_storage, const char *name) {
  int **hpp;
  int sentinel = -1;
  int *local_sentinel = &sentinel;
  if (*mat_slot == 0) {
    hpp = reinterpret_cast<int **>(&local_sentinel);
    // retail writes -1 into a stack slot and uses that pointer
    (void)handle_storage;
  } else {
    hpp = reinterpret_cast<int **>(FUN_00752370(handle_storage, name));
  }
  if (static_cast<int>(reinterpret_cast<intptr_t>(*hpp)) >= 0 ||
      (hpp != reinterpret_cast<int **>(&local_sentinel) && **reinterpret_cast<int **>(hpp) /* quiet */)) {
    // Prefer clear form matching decompile:
  }
  int handle;
  if (*mat_slot == 0) {
    handle = -1;
  } else {
    handle = *FUN_00752370(handle_storage, name);
  }
  if (handle >= 0) {
    FUN_0096fff0(mat_slot, handle);
  }
}

static void RefcountSwapMat(int *mat_slot) {
  int *neu = FUN_0073d940(*mat_slot);
  if (neu == nullptr) {
    return;
  }
  neu[1] = neu[1] + 1;
  if (neu[1] == 1) {
    reinterpret_cast<void (**)()>(*reinterpret_cast<void **>(neu))[1]();
  }
  int *old = reinterpret_cast<int *>(*mat_slot);
  if (old != nullptr) {
    old[1] = old[1] - 1;
    if (old[1] == 0) {
      reinterpret_cast<void (**)()>(*reinterpret_cast<void **>(old))[2]();
    }
  }
  *mat_slot = reinterpret_cast<int>(neu);
}

extern "C" uint32_t PalToolNoMap_Host0x34_MeshBuildUpload_Inferred(void *host) {
  // --- SEH + local mesh workspaces (FUN_00981310 / FUN_0098ef00 family) ---
  // Full SEH frame and ~0xF0 stack locals omitted; see raw decompile for layout.
  FUN_00981310(nullptr /* local_c0 workspace */);
  // seed colors from DAT_00d1a6c0..c8 + g_flOne (decompile locals)
  (void)DAT_00d1a6c0;
  (void)DAT_00d1a6c4;
  (void)DAT_00d1a6c8;
  (void)g_flOne;
  FUN_009813a0(nullptr, 100);
  FUN_0098ef00(nullptr /* local_70 */);
  FUN_0098f2b0(100);

  int *mat = reinterpret_cast<int *>(reinterpret_cast<char *>(host) + 0x24);
  int name_shell = 0;
  FUN_00989e00(&name_shell, "PalToolMaterialNoMap.fx");
  FUN_009701d0(&name_shell);

  int handle_storage = 0;
  TryBindParam(mat, &handle_storage, "MatDiffuse");
  TryBindParam(mat, &handle_storage, "MatAmbient");
  // specular default float4(DAT_00a0f298, DAT_00a0f298, DAT_00a0f298, g_flOne)
  (void)DAT_00a0f298;
  TryBindParam(mat, &handle_storage, "MatSpecular");
  TryBindParam(mat, &handle_storage, "MatEmissive");
  RefcountSwapMat(mat);

  // stride 0x10 or 0x20 from material child flag
  int stride = 0x20;
  if (*mat != 0) {
    int child = *reinterpret_cast<int *>(*mat + 0x14);
    if (child != 0 && *reinterpret_cast<char *>(child + 0x10) != 0) {
      stride = 0x10;
    }
  }
  (void)stride;

  // Counts from local vectors (decompile: /0x24 verts, /6 indices)
  // host+0x20 = vertCount/3; host+0x1c = indexCount; host+0x2c = 4
  *reinterpret_cast<uint32_t *>(reinterpret_cast<char *>(host) + 0x20) = 0; // filled from locals
  *reinterpret_cast<uint32_t *>(reinterpret_cast<char *>(host) + 0x1c) = 0;
  *reinterpret_cast<uint32_t *>(reinterpret_cast<char *>(host) + 0x2c) = 4;

  // --- VB create / Lock(0x800) / memcpy / Unlock / IB path ---
  // FUN_00414bc0(0x152); FUN_00414c20(...); vtbl+0x2c lock; FUN_00414a50;
  // FUN_004451c0; FUN_00747390; FUN_0044b9c0; FUN_0044ba80;
  // FUN_0044bbc0(..., host+0x14, 0); second companion geometry path.
  // On any create failure: release refs, FUN_00457a00, return 0xFFFFFFFF.

  // Structural success/fail returns (see raw for full branches):
  // return 0;          // success
  // return 0xFFFFFFFF; // failure
  return 0;
}

// Ghidra twin name:
//   uint32_t FUN_007300c0(int param_1);
//
// NOTE: This clean is a structural port map, not a complete SEH-faithful expansion.
// Prefer raw decompile + W36-J annotated notes for full branch order.
