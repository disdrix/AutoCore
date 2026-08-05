// =============================================================================
// FUN_004c0fe0 — clean twin of VOGEnvironmentLiquid_InitFilterPipeline_Inferred
// Stable ID: aa_004c0fe0  VA: 0x004c0fe0  Wave: W37-F
// Prefer the named clean source for port notes.
// =============================================================================

#include <cstdint>

extern std::uint32_t __thiscall VOGEnvironmentLiquid_InitFilterPipeline_Inferred(void* child);

std::uint32_t __thiscall FUN_004c0fe0(void* child)
{
  return VOGEnvironmentLiquid_InitFilterPipeline_Inferred(child);
}
