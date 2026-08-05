// =============================================================================
// Gfx_PalDiffMapFx_BindAndInitMesh_Inferred
// -----------------------------------------------------------------------------
// Stable ID: aa_0099f450
// Address:   0x0099f450–0x0099f5c3  (autoassault.exe, image base 0x400000)
// System:    gfx / PalDiffMap.fx host material + mesh init
// Generated: scaffold 2026-07-23 as FUN_0099f450; dual A/B seal 2026-07-29 (W36-I)
// Exactness: Behavior-preserving rewrite of decompiler + full-body bytes.
// Bit-for-bit vs retail EXE: DEFERRED
// =============================================================================
//
// PURPOSE:
//   Bind "PalDiffMap.fx" into host material slot (+0x20), set MatAmbient /
//   MatDiffuse / MatSpecular / MatEmissive from constant float4s, optional
//   DiffuseTexture path when entry EAX≠0, refcount-swap derived material if
//   present, then init host mesh/buffer via FUN_0099f270(scale, 1.0f).
//
// ABI (bytes):
//   stdcall 2 stack formals (host*, float scale_bits); optional EAX third
//   (saved→EBX); SUB ESP,0x14; RET 8; return OR status in EAX.
//   Body 372 B / 0x174.
//
// CALLER:
//   FUN_0073c810 HostPtrTable12_Bootstrap_EDI slot8 @ 0x0073ca84
//   (PUSH 10.0f, PUSH host, XOR EAX,EAX).
//
// STRINGS / CONSTS:
//   "PalDiffMap.fx", "MatAmbient", "MatDiffuse", "MatSpecular", "MatEmissive"
//   "DiffuseTexture" @ 0x00a9ede4 (optional path)
//   DAT_00afdf40 = float4(1,1,1,1); DAT_00afdf30 = float4(0,0,0,1)
//

#include <cstdint>

// Unowned callees (names from sealed duals / prior waves where available)
extern "C" void     FUN_00989e00(void* out_handle /*stack*/, const char* name /*stack*/); // ResourceCache_LookupByName; ECX=cache
extern "C" uint32_t FUN_009701d0(void* mat /*ECX this*/, void* fx_handle /*stack*/);
extern "C" int*     FUN_00752370(int* out_index /*stack*/, const char* name /*stack*/); // effect param index
extern "C" uint32_t FUN_0096fff0(void* mat /*stack*/, int index /*stack*/); // EAX=float4* const
extern "C" uint32_t FUN_0043ed30(/* ESI=mat; EAX=name; stack optional */);
extern "C" void*    FUN_0073d940(void* mat_obj /*stack*/); // ECX=global table DAT_00d1f61c path
extern "C" uint32_t FUN_0099f270(uint32_t scale_bits /*stack*/, uint32_t one_bits /*stack*/); // EDI=host

// Retail: stdcall (host*, scale_bits); optional EAX; RET 8; return status OR
extern "C" uint32_t Gfx_PalDiffMapFx_BindAndInitMesh_Inferred(
    void* host /* stack */,
    uint32_t scale_bits /* stack */)
{
  // Entry: EBX = EAX (optional context; sole sealed caller passes 0)
  // Locals: fx handle, four param-index slots, OR accumulator

  uint8_t fx_handle[4];
  int missing = -1;
  int *idx_p;
  uint32_t st_fx, st_a, st_d, st_s, st_e, st_opt, st_mesh, acc;

  // ECX = DAT_00d1eac8 inside ResourceCache_LookupByName
  FUN_00989e00(fx_handle, "PalDiffMap.fx");

  void** mat = reinterpret_cast<void**>(reinterpret_cast<uint8_t*>(host) + 0x20);
  st_fx = FUN_009701d0(mat, fx_handle); // thiscall ECX=mat

  auto bind_param = [&](const char* name, uint32_t /*float4* via EAX in retail*/) -> uint32_t {
    if (*mat == nullptr) {
      missing = -1;
      idx_p = &missing;
    } else {
      int local_idx = 0;
      idx_p = FUN_00752370(&local_idx, name);
    }
    if (*idx_p < 0) {
      return 0xffffffffu;
    }
    // Retail: MOV EAX, float4_const; CALL FUN_0096fff0(mat, *idx_p)
    return FUN_0096fff0(mat, *idx_p);
  };

  st_a = bind_param("MatAmbient", /* DAT_00afdf40 white */ 0);
  st_d = bind_param("MatDiffuse", /* DAT_00afdf40 white */ 0);
  st_s = bind_param("MatSpecular", /* DAT_00afdf30 blackA1 */ 0);
  st_e = bind_param("MatEmissive", /* DAT_00afdf30 blackA1 */ 0);

  acc = st_fx | st_a | st_d | st_s | st_e;

  // Optional: if entry EAX (EBX) != 0 → FUN_0043ed30 with EAX="DiffuseTexture"
  // Sole HostPtrTable caller zeros EAX — branch not taken there.
  // st_opt omitted when EBX==0.

  void* derived = FUN_0073d940(*mat);
  if (derived != nullptr) {
    // ++ref on derived; if first → vtbl+4; --ref on old; if zero → vtbl+8; *mat = derived
    int* d = reinterpret_cast<int*>(derived);
    d[1] = d[1] + 1;
    if (d[1] == 1) {
      reinterpret_cast<void (**)(void*)>(*reinterpret_cast<void**>(d))[1](d); // vtbl+4
    }
    int* old = reinterpret_cast<int*>(*mat);
    if (old != nullptr) {
      old[1] = old[1] - 1;
      if (old[1] == 0) {
        reinterpret_cast<void (**)(void*)>(*reinterpret_cast<void**>(old))[2](old); // vtbl+8
      }
    }
    *mat = derived;
  }

  // EDI = host for FUN_0099f270
  st_mesh = FUN_0099f270(scale_bits, 0x3f800000u /* 1.0f */);
  return st_mesh | acc;
}

// Ghidra twin symbol
extern "C" uint32_t FUN_0099f450(void* host, uint32_t scale_bits)
{
  return Gfx_PalDiffMapFx_BindAndInitMesh_Inferred(host, scale_bits);
}
