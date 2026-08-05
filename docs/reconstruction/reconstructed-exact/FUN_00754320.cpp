// =============================================================================
// FUN_00754320 — twin of Palantir_CompleteDtor
// -----------------------------------------------------------------------------
// Stable ID: aa_00754320
// Address:   0x00754320–0x007543A9 exclusive (137 B)
// Wave:      W34-K 2026-07-29
// Prefer:    reconstructed-exact/Palantir_CompleteDtor.cpp
// =============================================================================

#include <cstdint>

struct StringVecShell {
  void*    pad0;
  uint8_t* begin;
  uint8_t* end;
  uint8_t* capEnd;
};

extern "C" void* PTR_FUN_00a9f76c;
extern "C" void __thiscall BasicString_Dtor(void* self);
extern "C" void __fastcall StringVec_Tidy(StringVecShell* self);
extern "C" void __cdecl FUN_0075d8e0(void* sub);
extern "C" void __cdecl FUN_00964d00(void* sub);
extern "C" StringVecShell* DAT_00d1f1fc;
extern "C" void* DAT_00d1f058;

extern "C" void __fastcall FUN_00754320(void* self)
{
  uint8_t* base = static_cast<uint8_t*>(self);

  *reinterpret_cast<void**>(base) = &PTR_FUN_00a9f76c;

  BasicString_Dtor(base + 0xB4);
  StringVec_Tidy(reinterpret_cast<StringVecShell*>(base + 0xA0));
  DAT_00d1f1fc = nullptr;

  FUN_0075d8e0(base + 0x30);
  FUN_00964d00(base + 0x10);

  DAT_00d1f058 = nullptr;
}
