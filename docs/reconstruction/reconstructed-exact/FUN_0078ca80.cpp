// =============================================================================
// FUN_0078ca80 — twin of CNDUIWndBuffered_CompleteDtor (aa_0078ca80)
// Wave: WQ9K-F 2026-08-05. Prefer named clean CNDUIWndBuffered_CompleteDtor.cpp.
// =============================================================================

#include <cstdint>

extern "C" void __fastcall CNDUIWndBuffered_CompleteDtor(uint32_t* self);

extern "C" void __fastcall FUN_0078ca80(uint32_t* self)
{
  CNDUIWndBuffered_CompleteDtor(self);
}
