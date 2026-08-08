// =============================================================================
// FUN_007a4170 (scaffold alias)
// -----------------------------------------------------------------------------
// Stable ID: aa_007a4170
// Address:   0x007a4170
// Named clean: Rng_SampleUnitFloat_Inferred.cpp
// Updated:   2026-08-04 WQ9D-F dual
// =============================================================================

#include <cstdint>

struct RngHost_Inferred;

extern "C" float __thiscall Rng_SampleUnitFloat_Inferred(
    RngHost_Inferred* self,
    std::uint32_t index);

extern "C" float __thiscall FUN_007a4170(
    RngHost_Inferred* self,
    std::uint32_t index)
{
  return Rng_SampleUnitFloat_Inferred(self, index);
}
