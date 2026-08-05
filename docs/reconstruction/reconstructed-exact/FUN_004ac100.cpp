// =============================================================================
// FUN_004ac100  (scaffold twin of MapChild_RebuildHostElemsAndIntGrid_Inferred)
// -----------------------------------------------------------------------------
// Stable ID: aa_004ac100
// Address:   0x004ac100–0x004ac215 exclusive (277 B / 0x115)
// Generated: 2026-07-29 W31-L — canonical: MapChild_RebuildHostElemsAndIntGrid_Inferred
// See:       reconstructed-exact/MapChild_RebuildHostElemsAndIntGrid_Inferred.cpp
// Reject:    Named_VOG_DEBUG_STOP_004ac100 (string is fail-guard only)
// =============================================================================

#include <cstdint>

extern "C" void FUN_007a4480(int a, const char* msg);
extern "C" void __thiscall FUN_004941b0(void* host, void* mapCtx);
extern "C" void operator_delete[](void* p);
extern "C" void* operator_new[](unsigned size);
extern "C" void __thiscall FUN_004abd00(void* self);
extern "C" void __thiscall FUN_004aa300(void* self);
extern "C" void __thiscall FUN_004930b0(void* arg);
extern "C" void __thiscall FUN_005c0f40(void* self);
extern "C" void FUN_005bf720(void);
extern "C" unsigned char DAT_00b03631;
extern "C" unsigned char DAT_00b03632;

static inline int signed_div16(int x)
{
  return (x + ((x >> 31) & 0xf)) >> 4;
}

// Prefer MapChild_RebuildHostElemsAndIntGrid_Inferred as the port symbol.
extern "C" uint8_t __thiscall FUN_004ac100(void* self, int /* unused_stack_arg */)
{
  auto* s = reinterpret_cast<uint8_t*>(self);

  if (*reinterpret_cast<int*>(s + 0x3d8) == 0) {
    FUN_007a4480(0, "VOG_DEBUG_STOP");
    return 0;
  }

  void* mapCtx = *reinterpret_cast<void**>(s + 0x340);
  void* host = *reinterpret_cast<void**>(reinterpret_cast<uint8_t*>(mapCtx) + 0xe898);
  FUN_004941b0(host, mapCtx);

  const int dimX = signed_div16(*reinterpret_cast<int*>(s + 0x10));
  const int dimY = signed_div16(*reinterpret_cast<int*>(s + 0x14));
  *reinterpret_cast<int*>(s + 0x384) = dimX;
  *reinterpret_cast<int*>(s + 0x388) = dimY;

  void* oldGrid = *reinterpret_cast<void**>(s + 0x38c);
  if (oldGrid != nullptr) {
    operator_delete[](oldGrid);
  }
  *reinterpret_cast<void**>(s + 0x38c) = nullptr;

  const unsigned byteCount = static_cast<unsigned>(dimX) * static_cast<unsigned>(dimY) * 4u;
  auto* grid = reinterpret_cast<uint32_t*>(operator_new[](byteCount));
  *reinterpret_cast<uint32_t**>(s + 0x38c) = grid;

  const unsigned dwords = byteCount >> 2;
  const unsigned rem = byteCount & 3u;
  for (unsigned i = 0; i < dwords; ++i) {
    grid[i] = 0;
  }
  auto* tail = reinterpret_cast<uint8_t*>(grid + dwords);
  for (unsigned i = 0; i < rem; ++i) {
    tail[i] = 0;
  }

  FUN_004abd00(self);
  FUN_004aa300(self);
  FUN_004930b0(*reinterpret_cast<void**>(reinterpret_cast<uint8_t*>(mapCtx) + 0xe894));

  if (DAT_00b03631 != 0) {
    FUN_005c0f40(self);
  } else {
    FUN_005bf720();
  }
  DAT_00b03632 = DAT_00b03631;
  return 1;
}
