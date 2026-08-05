// =============================================================================
// FUN_0078caf0  (alias clean twin)
// Canonical: CNDUIWndBuffered_Ctor_Inferred
// Stable ID: aa_0078caf0
// Address:   0x0078caf0-0x0078cecb exclusive (987 B / 0x3DB)
// Wave:      W34-T 2026-07-29
// =============================================================================
// See CNDUIWndBuffered_Ctor_Inferred.cpp for full field bank + comments.

#include <cstdint>

extern "C" void *__cdecl FUN_007b5dd0(void *self, uint32_t arg1);
extern "C" void *__cdecl operator_new(uint32_t size);
extern "C" void *__fastcall FUN_007560d0(void *self);
extern "C" uint32_t __thiscall FUN_00756320(void *host, uint32_t flags);
extern "C" void *PTR_FUN_00a99f74;
extern "C" float g_flOne;
extern "C" float DAT_00a10e74;
extern "C" float DAT_00a0f298;
extern "C" float DAT_00a0f710;
extern "C" float DAT_00a0f720;
extern "C" float DAT_00aaabbc;
extern "C" float DAT_00b017e8;
extern "C" float DAT_00aaaa68;
extern "C" float DAT_00aaaa64;
extern "C" float DAT_00aaaa60;
extern "C" float DAT_00aaaa5c;
extern "C" float DAT_00aaa6f8;
extern "C" float DAT_00aaaa58;
extern "C" float DAT_00aaa7c0;

uint32_t *FUN_0078caf0(uint32_t *param_1, uint32_t param_2, uint32_t param_3)
{
  auto *b = reinterpret_cast<uint8_t *>(param_1);

  FUN_007b5dd0(param_1, param_2);
  *reinterpret_cast<void **>(param_1) = &PTR_FUN_00a99f74;

  b[0x4A6] = 0xFF; b[0x4A5] = 0xFF; b[0x4A4] = 0xFF; b[0x4A7] = 0xFF;
  param_1[0x12A] = 0; param_1[0x12B] = 0; param_1[0x12C] = 0;
  param_1[0x12D] = *reinterpret_cast<uint32_t *>(&g_flOne);
  param_1[0x12E] = 0; param_1[0x12F] = 0; param_1[0x130] = 0;
  param_1[0x131] = *reinterpret_cast<uint32_t *>(&g_flOne);
  param_1[0x132] = 0; param_1[0x133] = 0; param_1[0x134] = 0;
  param_1[0x135] = *reinterpret_cast<uint32_t *>(&g_flOne);
  param_1[0x136] = 0; param_1[0x137] = 0; param_1[0x138] = 0;
  param_1[0x139] = *reinterpret_cast<uint32_t *>(&g_flOne);
  param_1[0x13A] = 0; param_1[0x13B] = 0; param_1[0x13C] = 0;
  param_1[0x13D] = *reinterpret_cast<uint32_t *>(&g_flOne);
  param_1[0x4D] = *reinterpret_cast<uint32_t *>(&DAT_00a10e74);
  param_1[0x122] = param_3;
  b[0x4F8] = 0;
  b[0xBE] = 1; b[0xBF] = 1;
  param_1[0x123] = 0x10;
  b[0x4A1] = 0; b[0x4A0] = 0;
  b[0x4A6] = 0; b[0x4A5] = 0; b[0x4A4] = 0; b[0x4A7] = 0;
  param_1[0x124] = *reinterpret_cast<uint32_t *>(&DAT_00a0f710);
  param_1[0x125] = *reinterpret_cast<uint32_t *>(&DAT_00aaabbc);
  param_1[0x126] = *reinterpret_cast<uint32_t *>(&DAT_00a0f720);
  param_1[0x12A] = *reinterpret_cast<uint32_t *>(&g_flOne);
  param_1[0x12B] = *reinterpret_cast<uint32_t *>(&g_flOne);
  param_1[0x12C] = *reinterpret_cast<uint32_t *>(&g_flOne);
  param_1[0x12D] = *reinterpret_cast<uint32_t *>(&g_flOne);
  param_1[0x12E] = *reinterpret_cast<uint32_t *>(&DAT_00a0f298);
  param_1[0x12F] = *reinterpret_cast<uint32_t *>(&DAT_00a0f298);
  param_1[0x130] = *reinterpret_cast<uint32_t *>(&DAT_00a0f298);
  param_1[0x131] = *reinterpret_cast<uint32_t *>(&g_flOne);
  param_1[0x132] = *reinterpret_cast<uint32_t *>(&g_flOne);
  param_1[0x133] = *reinterpret_cast<uint32_t *>(&g_flOne);
  param_1[0x134] = *reinterpret_cast<uint32_t *>(&g_flOne);
  param_1[0x135] = *reinterpret_cast<uint32_t *>(&g_flOne);
  {
    float s = DAT_00b017e8;
    float a = s * DAT_00aaaa68, c = s * DAT_00aaaa64, d = s * DAT_00aaaa60;
    float e = s * DAT_00aaaa5c, f = s * DAT_00aaa6f8, g = s * DAT_00aaaa58, h = s * DAT_00aaa7c0;
    param_1[0x136] = *reinterpret_cast<uint32_t *>(&a);
    param_1[0x137] = *reinterpret_cast<uint32_t *>(&c);
    param_1[0x138] = *reinterpret_cast<uint32_t *>(&d);
    param_1[0x139] = *reinterpret_cast<uint32_t *>(&f);
    param_1[0x13A] = *reinterpret_cast<uint32_t *>(&e);
    param_1[0x13B] = *reinterpret_cast<uint32_t *>(&g);
    param_1[0x13C] = *reinterpret_cast<uint32_t *>(&h);
    param_1[0x13D] = *reinterpret_cast<uint32_t *>(&f);
  }
  param_1[0xAB] = 0;
  param_1[0x127] = 0;
  param_1[0x8A] = 0; param_1[0x8B] = 0; param_1[0x8C] = 0;

  void *raw = operator_new(0x80);
  void *host = (raw == nullptr) ? nullptr : FUN_007560d0(raw);
  param_1[0xAA] = reinterpret_cast<uint32_t>(host);
  FUN_00756320(host, 1);
  return param_1;
}
