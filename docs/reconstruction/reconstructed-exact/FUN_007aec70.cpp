// =============================================================================
// FUN_007aec70  (twin of CNDUIWindow_ReleaseOwnedRefPtrAt294_ClearText_Inferred)
// -----------------------------------------------------------------------------
// Stable ID: aa_007aec70
// Address:   0x007aec70  (autoassault.exe, image base 0x400000)
// Body:      0x007aec70–0x007aecc3 inclusive (84 B / 0x54)
// Wave:      WQ9L-G OWN-ONLY dual 2026-08-05
// Canonical: CNDUIWindow_ReleaseOwnedRefPtrAt294_ClearText_Inferred
// =============================================================================

#include <cstdint>

extern "C" void __fastcall RefCountedPtr_Dtor_Inferred(void** self);
extern "C" void __cdecl operator_delete(void* p);
extern const char DAT_00a1419b;

extern "C" void __fastcall FUN_007aec70(uint8_t* self /*ECX*/)
{
  void* shell = *reinterpret_cast<void**>(self + 0x294);
  if (shell != nullptr) {
    if (self[0xBB] != 0) {
      RefCountedPtr_Dtor_Inferred(reinterpret_cast<void**>(shell));
      operator_delete(shell);
    }
    *reinterpret_cast<void**>(self + 0x294) = nullptr;
    self[0xBB] = 0;
    void** vtbl = *reinterpret_cast<void***>(self);
    using Vfn = void(__thiscall*)(void* self, const char* text);
    reinterpret_cast<Vfn>(vtbl[0x2B4 / 4])(self, &DAT_00a1419b);
  }
  *reinterpret_cast<uint32_t*>(self + 0x29C) = 0;
  *reinterpret_cast<uint32_t*>(self + 0x2A0) = 0;
}
