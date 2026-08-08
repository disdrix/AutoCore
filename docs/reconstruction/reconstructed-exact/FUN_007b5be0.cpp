// =============================================================================
// FUN_007b5be0 — twin of CNDUIWindow_CompleteDtor (aa_007b5be0)
// Wave: WQ9K-F 2026-08-05. Prefer named clean CNDUIWindow_CompleteDtor.cpp.
// Supersedes scaffold Named_VOG_DEBUG_STOP_007b5be0.cpp (string-only alias).
// =============================================================================

#include <cstdint>

extern "C" void __fastcall CNDUIWindow_CompleteDtor(uint32_t* self);

extern "C" void __fastcall FUN_007b5be0(uint32_t* self)
{
  CNDUIWindow_CompleteDtor(self);
}
