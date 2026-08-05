// =============================================================================
// EffDeviceEffect_BindEffectParams_Inferred
// -----------------------------------------------------------------------------
// Stable ID: aa_00750260
// Address:   0x00750260–0x0075184F (5616 B / 0x15F0, autoassault.exe base 0x400000)
// System:    palantir graphics Effects / effDeviceEffect.cpp
// Generated: 2026-07-29 W34-C dual A/B (decompile + read_memory)
// Exactness: Structural CF + ABI + product string table. NOT a line-faithful
//            rewrite of the 1200-line noisy decompile (type-prop failed).
// Bit-for-bit vs retail EXE: DEFERRED.
// Ghidra:    FUN_00750260
// Scaffold:  Named_effDeviceEffect_00750260
// =============================================================================
//
// PURPOSE:
//   After D3DXCreateEffect (caller FUN_00751890 / fallback path), walk the
//   compiled ID3DXEffect and bind product-known parameters into the device-
//   effect object: light count/support handles, matrix semantics (WorldView,
//   InvWorldViewProjection, World, …), billboard modes, cube-map / material
//   color tags, and per-pass annotation tables.
//
// ABI (bytes + call site):
//   EBP frame + 8-byte align (55 8B EC 83 E4 F8); SEH LAB_009b1b66
//   Stack object* at [EBP+8] (MOV EBX,[EBP+8]); call site also pushes a
//   path/name string* ("effFallbackEffect.h" from FUN_00989e00).
//   Returns int: 0 success, 0xFFFFFFFF fail. Plain RET after frame teardown.
//
// Object layout (partial, from decompile):
//   +0x0C  ID3DXEffect* (COM vtable)
//   +0x10  param table base
//   +0x14  param count
//   +0x18  secondary count
//   +0x24  device/effect flag written on late path
//   +0x30/+0x34  pass array begin/end (stride 0xD4)
//   +0x40/+0x44, +0x50/+0x54, +0x90/+0x94, +0xA0/+0xA4  vector ranges
//
// Globals: DAT_00d1f044 (gfx/device state, +0x77A/+0x77C modes),
//          DAT_00d1f62c, DAT_00afa2f8 (color scale float)
// =============================================================================

#include <cstdint>

// Unowned nested callees — sealed addresses only
extern "C" int FUN_00416410(void* out, void* lhs, void* rhs); // StdString_OperatorPlus_String
extern "C" int FUN_0074f3c0();
extern "C" void FUN_0074f600();
extern "C" void* FUN_005ae2b0();
extern "C" void* FUN_007462e0();
extern "C" void FUN_0076cec0();
extern "C" void FUN_00964bc0(void* buf);
extern "C" void FUN_0096a630();
extern "C" void FUN_00989e00(void* out_str, const char* path);
extern "C" void vog_LogMessage();
extern "C" int _stricmp(const char* a, const char* b);
extern "C" char* strstr(const char* hay, const char* needle);
extern "C" void* _aligned_malloc(size_t size, size_t align);
extern "C" void operator_delete(void* p);

// Matrix semantic slot IDs observed in decompile (_stricmp arms)
enum EffMatrixSemantic : int {
  kWorld = 0,
  kWorldArray = 1,
  kMorphArray = 2,
  kInvWorld = 3,
  kWorldView = 8,
  kInvWorldScale = 0xB,
  kInvWorldViewProjection = 0xC,
};

// Structural contract only — full body remains in raw/annotated decompile.
// Port guidance: treat as product-specific effect bind; do not invent a thin
// wrapper. Nested string helper FUN_00416410 is dual-owned (W33-F).
//
// Pseudocode outline:
//   if effect==null → fail
//   for each technique/pass via COM:
//     read annotation ints (row/col/index caps 0..4)
//     fill local 5x5-ish map local_80[]
//     write pass record at param_1+0x34
//     build LightCount_/LightSupport_ names via operator+(string,string)
//     resolve handles; classify matrix names into semantic slots
//     scale Diffuse/Ambient/Emissive colors by DAT_00afa2f8
//   if pass table empty → log + return -1
//   build secondary tables (_aligned_malloc 16-align)
//   optional late FUN_007462e0 when vector ranges non-empty
//   return 0 on success

extern "C" int EffDeviceEffect_BindEffectParams_Inferred(void* device_effect /*, path? */)
{
  // See docs/reconstruction/raw/aa_00750260_FUN_00750260.md for full decompile.
  // This clean unit intentionally stays structural: the decompiler type graph
  // does not settle (WARNING), so a line-faithful C++ rewrite would invent
  // false types. CF, ABI, strings, and callee graph are sealed in reviews.
  (void)device_effect;
  return -1; // placeholder — do not link; documentation contract only
}

extern "C" int FUN_00750260(void* device_effect)
{
  return EffDeviceEffect_BindEffectParams_Inferred(device_effect);
}
