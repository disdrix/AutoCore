// =============================================================================
// FUN_005769c0 — clean twin of WaterPhase_Ctor_Inferred
// Stable ID: aa_005769c0 | W32-S
// =============================================================================

#include <cstdint>

extern "C" uint32_t PTR_FUN_009d3b04;

extern "C" void *__thiscall FUN_005769c0(void *self, void *view)
{
  auto *p = reinterpret_cast<uint32_t *>(self);

  p[1] = reinterpret_cast<uint32_t>(view);
  p[0] = reinterpret_cast<uint32_t>(&PTR_FUN_009d3b04);
  p[3] = 0;
  p[4] = 0;
  p[5] = 0;
  p[6] = 0;
  p[7] = 0;

  return self;
}
