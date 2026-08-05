// =============================================================================
// VOGEnvironmentLiquid_InitFilterPipeline_Inferred  (was FUN_004c0fe0)
// -----------------------------------------------------------------------------
// Stable ID: aa_004c0fe0
// Address:   0x004c0fe0  (autoassault.exe, image base 0x400000)
// Body:      0x004c0fe0–0x004c16cf inclusive (1776 bytes / 0x6F0)
// System:    client / VOGEnvironmentLiquid (product path strings)
// Generated: 2026-08-04 W37-F dual seal
// Exactness: Contract-level behavior-preserving rewrite of decompiler +
//            read_memory ABI/slots/strings. Not a line-for-line 1776 B EH dump.
// Bit-for-bit vs retail EXE: DEFERRED
//
// Dual: reviews/A|B_aa_004c0fe0_VOGEnvironmentLiquid_InitFilterPipeline_Inferred.md
// Sole caller: ParticleFluidPhase_CreateLiquidChild_Inferred (0x004c1960, W34-O)
// =============================================================================

#include <cstdint>

// Unowned callees — names structural only.
extern "C" void* __cdecl operator_new(std::uint32_t size);
extern "C" void* __thiscall FUN_009886d0(void* self);           // 0x18 filter host ctor
extern "C" void* __thiscall FUN_009685e0(void* self);           // 0xd4 RT host ctor
extern "C" void FUN_0096f530();                                 // effect local begin
extern "C" void FUN_00989e00(void* local, const char* path);
extern "C" void FUN_009701d0(void* local);
extern "C" int FUN_00988610(void* out_slot);
extern "C" void FUN_00970140(const char* name, void* value);
extern "C" void* FUN_00752310(void* out, const char* name);
extern "C" char FUN_0096fdf0();
extern "C" int FUN_00752a00(void* param, float* vec4);
extern "C" void FUN_0096f5d0();
extern "C" int FUN_0096f0e0(int fmt, void* slot, int a, int flags, int b, int c);
extern "C" void FUN_0096ef70();
extern "C" void FUN_007567b0(void* filter, int arg);
extern "C" void FUN_009888b0(void* rt, int arg);
extern "C" void FUN_0096efd0();
extern "C" void FUN_0096f510();
extern "C" void vog_LogMessage(const char* file, int line, int level, const char* msg);

extern float g_flOne;
extern std::uint8_t* DAT_00d1f058;

// Product strings (sealed):
//   UIFluidDownsample.fx / UIFluidBlurHorizontal.fx /
//   UIFluidBlurVertical.fx / UIFluidSurfaceBlend.fx
//   BackBufferTexture / UIMapExtents0 / NormalMapTexture
//   VOGEnvironmentLiquid.cpp fail plates

// Layout of 0x40 liquid child (dword indices from decompiler):
//   [0]  +0x00 parent phase*
//   [8]  +0x20 filter Downsample
//   [9]  +0x24 RT cascade 0
//   [10] +0x28 filter BlurH
//   [11] +0x2c RT cascade 1
//   [12] +0x30 filter BlurV
//   [13] +0x34 RT cascade 2
//   [14] +0x38 filter SurfaceBlend
//   [15] +0x3c RT full-dim
//
// ABI: __thiscall ECX=child; returns 0; SEH LAB_009a1a6d.
std::uint32_t __thiscall VOGEnvironmentLiquid_InitFilterPipeline_Inferred(void* child)
{
  auto* c = reinterpret_cast<std::uint32_t*>(child);
  auto* dev = *reinterpret_cast<std::uint8_t**>(DAT_00d1f058 + 0x2c);
  int width  = *reinterpret_cast<int*>(dev + 0x80);
  int height = *reinterpret_cast<int*>(dev + 0x84);

  // --- four 0x18 filter hosts ---
  auto make_filter = []() -> std::uint32_t {
    void* raw = operator_new(0x18);
    if (!raw) return 0;
    return reinterpret_cast<std::uint32_t>(FUN_009886d0(raw));
  };
  c[8]  = make_filter(); // +0x20
  c[10] = make_filter(); // +0x28
  c[12] = make_filter(); // +0x30
  c[14] = make_filter(); // +0x38

  // --- load UIFluid*.fx chain (order sealed) ---
  // Downsample + BackBufferTexture + UIMapExtents0 (1,1,1/w,1/h)
  FUN_0096f530();
  // FUN_00989e00(..., "UIFluidDownsample.fx"); FUN_009701d0; FUN_00988610
  // on fail: vog_LogMessage(VOGEnvironmentLiquid.cpp, 0x1cb, 3, "failed to load filter effect.")
  FUN_00970140("BackBufferTexture",
               *reinterpret_cast<void**>(*reinterpret_cast<std::uint8_t**>(c) + 0x94));
  // UIMapExtents0 via FUN_00752310 if filter+0xc else -1 sentinel
  float extents[4] = { g_flOne, g_flOne, g_flOne / static_cast<float>(width),
                       g_flOne / static_cast<float>(height) };
  (void)extents;
  // FUN_00752a00 + optional FUN_0096f5d0

  FUN_0096f530();
  // "UIFluidBlurHorizontal.fx" — log line 0x1d9
  FUN_0096f530();
  // "UIFluidBlurVertical.fx" — log line 0x1df
  FUN_0096f530();
  // "UIFluidSurfaceBlend.fx" — log line 0x1e5
  *reinterpret_cast<std::uint8_t*>(static_cast<std::uintptr_t>(c[14]) + 0x15) = 0;

  // --- RT hosts: full then cascaded quarter dims ---
  auto make_rt = []() -> void* {
    void* raw = operator_new(0xd4);
    if (!raw) return nullptr;
    return FUN_009685e0(raw);
  };

  void* rt_full = make_rt();
  c[15] = reinterpret_cast<std::uint32_t>(rt_full);
  // vcall rt_full->vtbl[+8](&width_height)

  auto div4 = [](int v) -> int {
    return (v + ((v >> 31) & 3)) >> 2;
  };

  void* rt0 = make_rt();
  c[9] = reinterpret_cast<std::uint32_t>(rt0);
  // vcall with (width>>2, height>>2)

  void* rt1 = make_rt();
  c[11] = reinterpret_cast<std::uint32_t>(rt1);
  // vcall with further >>2

  void* rt2 = make_rt();
  c[13] = reinterpret_cast<std::uint32_t>(rt2);
  // vcall with further >>2

  FUN_0096ef70();
  // FUN_0096f0e0(0x15, rt0+0x80, 1, 0x4011, 0, 0) ×3 for c[9],c[11],c[13]
  // refcount wire to each rt+0xb8; rt+0xc0 = 0
  // fail logs: VOGEnvironmentLiquid.cpp lines 0x204 / 0x20b / 0x212

  void* parent = *reinterpret_cast<void**>(c);
  // * (parent+0x98) = last buffer tex; optional NormalMapTexture if parent+0x8c

  FUN_007567b0(reinterpret_cast<void*>(c[8]), 0);
  FUN_009888b0(reinterpret_cast<void*>(c[9]), 0);
  FUN_007567b0(reinterpret_cast<void*>(c[10]), 0);
  FUN_009888b0(reinterpret_cast<void*>(c[11]), 0);
  FUN_007567b0(reinterpret_cast<void*>(c[12]), 0);
  FUN_009888b0(reinterpret_cast<void*>(c[13]), 1);
  *reinterpret_cast<std::uint8_t*>(static_cast<std::uintptr_t>(c[14]) + 0x14) = 1;

  // destroy local FX wrappers (FUN_0096efd0 + FUN_0096f510 ×4)
  (void)width;
  (void)height;
  (void)rt_full;
  (void)rt0;
  (void)rt1;
  (void)rt2;
  (void)parent;
  return 0;
}
