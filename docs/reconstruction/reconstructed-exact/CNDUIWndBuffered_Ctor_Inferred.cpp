// =============================================================================
// CNDUIWndBuffered_Ctor_Inferred
// -----------------------------------------------------------------------------
// Stable ID: aa_0078caf0
// Address:   0x0078caf0-0x0078cecb exclusive (987 B / 0x3DB)
// System:    client / ND UI buffered window
// Generated: 2026-07-29 W34-T dual seal
// Exactness: Behavior-preserving rewrite of decompiler CF + read_memory / RTTI.
// Bit-for-bit vs retail EXE: DEFERRED.
// =============================================================================
//
// PURPOSE:
// Complete constructor for CNDUIWndBuffered (RTTI Confirmed).
//   1) CNDUIWindow base ctor FUN_007b5dd0(this, arg1)
//   2) Install vtbl PTR_FUN_00a99f74 (.?AVCNDUIWndBuffered@@)
//   3) Init buffered-window field bank (floats/flags/colors)
//   4) new(0x80) HostBase_DefaultCtor → +0x2A8; HostBase_EnsureAuxPtrs(host, 1)
// Instance size 0x4FC (operator_new at call sites). Subclass ctors (CWndPortrait /
// CWndVehicle / CWndParticles) call this then overwrite vtbl.
// Reject scaffold Named_CalleeOf_Named_CalleeOf_Drive_i_d_shopveh_2d_wnd_list_veh_0078caf0.
//

#include <cstdint>

struct CNDUIWndBuffered; // opaque; size 0x4FC

extern "C" CNDUIWndBuffered *__cdecl FUN_007b5dd0(CNDUIWndBuffered *self, uint32_t arg1);
extern "C" void *__cdecl operator_new(uint32_t size);
extern "C" void *__fastcall FUN_007560d0(void *self); // HostBase_DefaultCtor
extern "C" uint32_t __thiscall FUN_00756320(void *host, uint32_t flags); // HostBase_EnsureAuxPtrs

extern "C" void *PTR_FUN_00a99f74; // CNDUIWndBuffered vtbl
extern "C" float g_flOne;         // 1.0f @ 0x00a0f2a0
extern "C" float DAT_00a10e74;    // 2.0f (decomp g_flLevelUpUiBase_Inferred)
extern "C" float DAT_00a0f298;    // 0.5f
extern "C" float DAT_00a0f710;    // 0.7f
extern "C" float DAT_00a0f720;    // 0.4f
extern "C" float DAT_00aaabbc;    // -0.55f
extern "C" float DAT_00b017e8;    // ~1/255
extern "C" float DAT_00aaaa68;    // 112.f
extern "C" float DAT_00aaaa64;    // 123.f
extern "C" float DAT_00aaaa60;    // 143.f
extern "C" float DAT_00aaaa5c;    // 62.f
extern "C" float DAT_00aaa6f8;    // 255.f
extern "C" float DAT_00aaaa58;    // 47.f
extern "C" float DAT_00aaa7c0;    // 45.f

// Stack this + 2 formals; ret 12; returns this
CNDUIWndBuffered *CNDUIWndBuffered_Ctor_Inferred(
    CNDUIWndBuffered *self,
    uint32_t arg1,
    uint32_t arg2)
{
  auto *p = reinterpret_cast<uint32_t *>(self);
  auto *b = reinterpret_cast<uint8_t *>(self);

  // SEH LAB_009b400b
  FUN_007b5dd0(self, arg1);

  *reinterpret_cast<void **>(self) = &PTR_FUN_00a99f74;

  // --- field bank (order preserved from decompile; intermediate FF seeds then zeros) ---
  b[0x4A6] = 0xFF; b[0x4A5] = 0xFF; b[0x4A4] = 0xFF; b[0x4A7] = 0xFF;
  p[0x12A] = 0; p[0x12B] = 0; p[0x12C] = 0;
  p[0x12D] = *reinterpret_cast<uint32_t *>(&g_flOne);
  p[0x12E] = 0; p[0x12F] = 0; p[0x130] = 0;
  p[0x131] = *reinterpret_cast<uint32_t *>(&g_flOne);
  p[0x132] = 0; p[0x133] = 0; p[0x134] = 0;
  p[0x135] = *reinterpret_cast<uint32_t *>(&g_flOne);
  p[0x136] = 0; p[0x137] = 0; p[0x138] = 0;
  p[0x139] = *reinterpret_cast<uint32_t *>(&g_flOne);
  p[0x13A] = 0; p[0x13B] = 0; p[0x13C] = 0;
  p[0x13D] = *reinterpret_cast<uint32_t *>(&g_flOne);
  p[0x4D] = *reinterpret_cast<uint32_t *>(&DAT_00a10e74); // 2.0f
  p[0x122] = arg2;
  b[0x4F8] = 0;
  b[0xBE] = 1; b[0xBF] = 1;
  p[0x123] = 0x10;
  b[0x4A1] = 0; b[0x4A0] = 0;
  b[0x4A6] = 0; b[0x4A5] = 0; b[0x4A4] = 0; b[0x4A7] = 0;
  p[0x124] = *reinterpret_cast<uint32_t *>(&DAT_00a0f710); // 0.7
  p[0x125] = *reinterpret_cast<uint32_t *>(&DAT_00aaabbc); // -0.55
  p[0x126] = *reinterpret_cast<uint32_t *>(&DAT_00a0f720); // 0.4
  p[0x12A] = *reinterpret_cast<uint32_t *>(&g_flOne);
  p[0x12B] = *reinterpret_cast<uint32_t *>(&g_flOne);
  p[0x12C] = *reinterpret_cast<uint32_t *>(&g_flOne);
  p[0x12D] = *reinterpret_cast<uint32_t *>(&g_flOne);
  p[0x12E] = *reinterpret_cast<uint32_t *>(&DAT_00a0f298); // 0.5
  p[0x12F] = *reinterpret_cast<uint32_t *>(&DAT_00a0f298);
  p[0x130] = *reinterpret_cast<uint32_t *>(&DAT_00a0f298);
  p[0x131] = *reinterpret_cast<uint32_t *>(&g_flOne);
  p[0x132] = *reinterpret_cast<uint32_t *>(&g_flOne);
  p[0x133] = *reinterpret_cast<uint32_t *>(&g_flOne);
  p[0x134] = *reinterpret_cast<uint32_t *>(&g_flOne);
  p[0x135] = *reinterpret_cast<uint32_t *>(&g_flOne);
  {
    float s = DAT_00b017e8;
    float c112 = s * DAT_00aaaa68;
    float c123 = s * DAT_00aaaa64;
    float c143 = s * DAT_00aaaa60;
    float c62  = s * DAT_00aaaa5c;
    float c255 = s * DAT_00aaa6f8;
    float c47  = s * DAT_00aaaa58;
    float c45  = s * DAT_00aaa7c0;
    p[0x136] = *reinterpret_cast<uint32_t *>(&c112);
    p[0x137] = *reinterpret_cast<uint32_t *>(&c123);
    p[0x138] = *reinterpret_cast<uint32_t *>(&c143);
    p[0x139] = *reinterpret_cast<uint32_t *>(&c255);
    p[0x13A] = *reinterpret_cast<uint32_t *>(&c62);
    p[0x13B] = *reinterpret_cast<uint32_t *>(&c47);
    p[0x13C] = *reinterpret_cast<uint32_t *>(&c45);
    p[0x13D] = *reinterpret_cast<uint32_t *>(&c255);
  }
  p[0xAB] = 0;
  p[0x127] = 0;
  p[0x8A] = 0; p[0x8B] = 0; p[0x8C] = 0;

  void *raw = operator_new(0x80);
  void *host = (raw == nullptr) ? nullptr : FUN_007560d0(raw);
  p[0xAA] = reinterpret_cast<uint32_t>(host); // +0x2A8
  FUN_00756320(host, 1);

  return self;
}
