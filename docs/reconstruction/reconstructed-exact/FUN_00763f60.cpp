// =============================================================================
// FUN_00763f60 — twin of GfxBody_CompleteDtor_Inferred (aa_00763f60)
// Wave W31-C 2026-07-29. Canonical clean: GfxBody_CompleteDtor_Inferred.cpp
// =============================================================================

#include <cstdint>

extern "C" void __fastcall GfxBody_CompleteDtor_Inferred(uint32_t* self);

extern "C" void __fastcall FUN_00763f60(uint32_t* self)
{
  GfxBody_CompleteDtor_Inferred(self);
}
