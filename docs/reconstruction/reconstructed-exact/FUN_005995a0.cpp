// =============================================================================
// FUN_005995a0  (scaffold alias → Host_ScreenToTerrainHitNotify_Inferred)
// -----------------------------------------------------------------------------
// Stable ID: aa_005995a0
// Address:   0x005995a0  (autoassault.exe, image base 0x400000)
// System:    world-terrain / screen pick → heightfield hit notify
// Generated: 2026-07-29 W20-P dual — scaffold keeps Ghidra name; clean is primary.
// Exactness: Behavior-preserving; callee this pointers restored from bytes.
// Bit-for-bit vs retail EXE: DEFERRED.
// =============================================================================
// Canonical clean: Host_ScreenToTerrainHitNotify_Inferred.cpp
// =============================================================================

#include <cstdint>

extern "C" void __thiscall FUN_0075c340(void* gfxView, int* screenXY,
                                        float* outNear, float* outDir);
extern "C" std::uint8_t __thiscall FUN_004cff70(void* map, float* start, float* dir,
                                                float* outHit, std::int32_t maxSteps);

std::uint32_t __thiscall FUN_005995a0(void* param_1 /*host ECX*/)
{
  auto* base = reinterpret_cast<std::uint8_t*>(param_1);
  void* map = *reinterpret_cast<void**>(base + 0x40);
  if (map == nullptr) {
    return 0;
  }

  int screen[2];
  screen[0] = *reinterpret_cast<int*>(base + 0x38);
  screen[1] = *reinterpret_cast<int*>(base + 0x3c);

  float nearPt[3];
  float dir3[3];
  void* view =
      *reinterpret_cast<void**>(reinterpret_cast<std::uint8_t*>(map) + 0xe890);
  FUN_0075c340(view, screen, nearPt, dir3);

  float origin4[4] = {nearPt[0], nearPt[1], nearPt[2], 0.0f};
  float dir4[4]    = {dir3[0], dir3[1], dir3[2], 0.0f};
  alignas(16) float hit[7] = {};

  if (FUN_004cff70(map, origin4, dir4, hit, 400) == 0) {
    return 0;
  }

  void* target = *reinterpret_cast<void**>(base + 0x24);
  auto** vtbl  = *reinterpret_cast<void***>(target);
  using Fn = void(__thiscall*)(void*, float*);
  reinterpret_cast<Fn>(vtbl[0x5c / sizeof(void*)])(target, hit);
  return 1;
}
