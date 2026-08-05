// =============================================================================
// FUN_00494700 — twin of Host_EnsureRegionCellOwned_Inferred (aa_00494700)
// Wave W31-C 2026-07-29. Canonical clean: Host_EnsureRegionCellOwned_Inferred.cpp
// =============================================================================

#include <cstdint>

extern "C" void __thiscall Host_EnsureRegionCellOwned_Inferred(uint8_t* host, void* ctx);

extern "C" void __thiscall FUN_00494700(uint8_t* host, void* ctx)
{
  Host_EnsureRegionCellOwned_Inferred(host, ctx);
}
