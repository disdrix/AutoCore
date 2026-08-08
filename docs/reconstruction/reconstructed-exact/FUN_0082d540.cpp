// =============================================================================
// FUN_0082d540 — twin of CVOGMenu_CompleteDtor (aa_0082d540)
// See: CVOGMenu_CompleteDtor.cpp for named plate.
// Wave: WQ9K-G 2026-08-05
// =============================================================================

#include <cstdint>

extern "C" void __fastcall FUN_0082ce20(void* self);
extern "C" void __fastcall FUN_00792c20(void* self);
extern "C" void* PTR_FUN_00a72f6c;

extern "C" void __fastcall FUN_0082d540(void* self)
{
  *reinterpret_cast<void**>(self) = &PTR_FUN_00a72f6c;
  FUN_0082ce20(self);
  FUN_00792c20(self);
}
