// =============================================================================
// FUN_00759de0 — Ghidra twin of gfxUIWindow_CompleteDtor (aa_00759de0)
// Wave: WQ9L-F OWN-ONLY dual 2026-08-05
// Canonical: reconstructed-exact/gfxUIWindow_CompleteDtor.cpp
// =============================================================================

#include <cstdint>

extern "C" void __fastcall gfxUIWindow_CompleteDtor(uint32_t* self);

extern "C" void __fastcall FUN_00759de0(uint32_t* self)
{
  gfxUIWindow_CompleteDtor(self);
}
