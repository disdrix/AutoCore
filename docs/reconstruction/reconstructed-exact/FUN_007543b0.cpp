// =============================================================================
// FUN_007543b0 — Ghidra-named twin of Palantir_BaseCtor (aa_007543b0)
// Prefer: reconstructed-exact/Palantir_BaseCtor.cpp
// W35-I 2026-07-29 — stack self*; RET 4; EAX=self; 204 B @ 0x007543b0
// =============================================================================

#include <cstdint>

extern "C" void* PTR_FUN_00a9f76c;
extern "C" void* DAT_00d1f01c;
extern "C" void* DAT_00d1f020;
extern "C" void* DAT_00d1f058;
extern "C" void* DAT_00d1f1fc;
extern "C" void* __stdcall FUN_0075d470(void* cache_at_30);
extern "C" long __stdcall CoInitializeEx(void* reserved, unsigned long coinit);
extern "C" void __thiscall BasicString_CtorFromCStr(void* self, const char* s);

extern "C" void* __stdcall FUN_007543b0(void* self)
{
  uint8_t* base = reinterpret_cast<uint8_t*>(self);

  DAT_00d1f058 = self;
  *reinterpret_cast<void**>(base + 0x00) = &PTR_FUN_00a9f76c;
  base[0x04] = 0;
  base[0x05] = 1;
  base[0x06] = 0;
  *reinterpret_cast<void**>(base + 0x08) = DAT_00d1f01c;
  *reinterpret_cast<void**>(base + 0x0C) = DAT_00d1f020;
  *reinterpret_cast<uint32_t*>(base + 0x14) = 0;
  *reinterpret_cast<uint32_t*>(base + 0x18) = 0;
  *reinterpret_cast<uint32_t*>(base + 0x1C) = 0;
  *reinterpret_cast<uint32_t*>(base + 0x20) = 0;
  CoInitializeEx(nullptr, 2u);
  *reinterpret_cast<uint32_t*>(base + 0x24) = 0xFFFFFFFFu;
  *reinterpret_cast<uint32_t*>(base + 0x28) = 0;
  *reinterpret_cast<uint32_t*>(base + 0x2C) = 0;
  FUN_0075d470(base + 0x30);
  DAT_00d1f1fc = base + 0xA0;
  *reinterpret_cast<void**>(base + 0xA4) = nullptr;
  *reinterpret_cast<void**>(base + 0xA8) = nullptr;
  *reinterpret_cast<void**>(base + 0xAC) = nullptr;
  BasicString_CtorFromCStr(base + 0xB4, ".");
  base[0xD0] = 1;
  base[0xD1] = 0;
  *reinterpret_cast<uint32_t*>(base + 0xD4) = 0;
  return self;
}
