// =============================================================================
// FUN_007aff00  (twin of CNDUIWindow_ReleaseTextLayoutAndNested_Inferred)
// -----------------------------------------------------------------------------
// Stable ID: aa_007aff00
// Address:   0x007aff00  (autoassault.exe, image base 0x400000)
// Body:      0x007aff00–0x007aff51 inclusive (82 B / 0x52)
// Wave:      WQ9L-G OWN-ONLY dual 2026-08-05
// Canonical: CNDUIWindow_ReleaseTextLayoutAndNested_Inferred
// =============================================================================

#include <cstdint>

extern "C" void __stdcall UiTextLayout_CompleteDtor_Inferred(void* layout);
extern "C" void __cdecl operator_delete(void* p);
extern "C" void __fastcall FUN_00424060(void* nested);

extern "C" void __fastcall FUN_007aff00(uint8_t* self /*ECX*/)
{
  if (*reinterpret_cast<int32_t*>(self + 0x20C) != 0) {
    void* layout = *reinterpret_cast<void**>(self + 0x28C);
    if (layout != nullptr) {
      UiTextLayout_CompleteDtor_Inferred(layout);
      operator_delete(layout);
    }
    *reinterpret_cast<void**>(self + 0x28C) = nullptr;
  }
  FUN_00424060(self + 0x1E8);
  *reinterpret_cast<uint32_t*>(self + 0x128) = 0;
  *reinterpret_cast<uint32_t*>(self + 0x12C) = 0;
}
