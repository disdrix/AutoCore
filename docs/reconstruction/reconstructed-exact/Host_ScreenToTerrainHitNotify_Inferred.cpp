// =============================================================================
// Host_ScreenToTerrainHitNotify_Inferred
// -----------------------------------------------------------------------------
// Stable ID: aa_005995a0
// Address:   0x005995a0  (autoassault.exe, image base 0x400000)
// System:    world-terrain / screen pick → heightfield hit notify
// Generated: 2026-07-29 W20-P dual (decompile_function + read_memory)
// Exactness: Behavior-preserving rewrite; decompiler this-gaps fixed from bytes.
// Bit-for-bit vs retail EXE: DEFERRED.
// =============================================================================
//
// PURPOSE:
//   Host method: screen XY → unproject via map's gfxView → march to terrain
//   (maxSteps=400) → on hit invoke *(host+0x24)->vtbl[+0x5c](hitBuf); bool.
//
// ABI (bytes sealed):
//   __thiscall  ECX = host*
//   bare ret
//   return 0 = no map / no hit; 1 = hit + notify
//
// HOST LAYOUT (sealed):
//   +0x24 notify target*; +0x38 screenX; +0x3c screenY; +0x40 CVOGMap*
//   map+0xe890 = GfxView* for unproject
// =============================================================================

#include <cstdint>

// Callees (not owned by this dual) — sealed roles from sibling duals.
extern "C" void __thiscall FUN_0075c340(void* gfxView /*ECX*/,
                                        int* screenXY,
                                        float* outWorldNear,
                                        float* outWorldDir);

extern "C" std::uint8_t __thiscall FUN_004cff70(void* map /*ECX*/,
                                                float* start /*float4*/,
                                                float* dir /*float4*/,
                                                float* outHit /*float4+*/,
                                                std::int32_t maxSteps);

static constexpr std::uint32_t kHostNotifyOff = 0x24u;
static constexpr std::uint32_t kHostScreenX   = 0x38u;
static constexpr std::uint32_t kHostScreenY   = 0x3cu;
static constexpr std::uint32_t kHostMapOff    = 0x40u;
static constexpr std::uint32_t kMapGfxViewOff = 0xe890u;
static constexpr std::int32_t  kMaxSteps      = 400; // 0x190

std::uint32_t __thiscall Host_ScreenToTerrainHitNotify_Inferred(void* host /*ECX*/)
{
  auto* base = reinterpret_cast<std::uint8_t*>(host);
  void* map = *reinterpret_cast<void**>(base + kHostMapOff);
  if (map == nullptr) {
    return 0;
  }

  int screenXY[2];
  screenXY[0] = *reinterpret_cast<int*>(base + kHostScreenX);
  screenXY[1] = *reinterpret_cast<int*>(base + kHostScreenY);

  float nearPt[3];
  float dir3[3];
  void* gfxView =
      *reinterpret_cast<void**>(reinterpret_cast<std::uint8_t*>(map) + kMapGfxViewOff);
  FUN_0075c340(gfxView, screenXY, nearPt, dir3);

  // Pack float4 origin/dir with w=0 (matches body stores).
  float origin4[4] = {nearPt[0], nearPt[1], nearPt[2], 0.0f};
  float dir4[4]    = {dir3[0], dir3[1], dir3[2], 0.0f};

  // Hit buffer: decompiler local_20[28]; MarchDir fills float4; notify takes ptr.
  alignas(16) float hitBuf[7] = {}; // 28 B

  if (FUN_004cff70(map, origin4, dir4, hitBuf, kMaxSteps) == 0) {
    return 0;
  }

  void* target = *reinterpret_cast<void**>(base + kHostNotifyOff);
  auto** vtbl  = *reinterpret_cast<void***>(target);
  using HitNotifyFn = void(__thiscall*)(void* self, float* hit);
  auto fn = reinterpret_cast<HitNotifyFn>(vtbl[0x5c / sizeof(void*)]);
  fn(target, hitBuf);
  return 1;
}
