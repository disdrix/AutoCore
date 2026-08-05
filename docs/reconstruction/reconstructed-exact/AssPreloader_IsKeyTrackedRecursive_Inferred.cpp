// =============================================================================
// AssPreloader_IsKeyTrackedRecursive_Inferred
// -----------------------------------------------------------------------------
// Stable ID: aa_00971900
// Address:   0x00971900–0x00971a19  (autoassault.exe, image base 0x400000)
// Ghidra:    FUN_00971900
// System:    assPreloader / asset preload pipeline
// Dual:      W31-K 2026-07-29
// Exactness: Behavior-preserving. Not modernization.
// Bit-for-bit vs retail EXE: DEFERRED.
// =============================================================================
//
// Retail ABI:
//   ECX  = AssPreloader* this
//   stack = (const int* key, char recurse); RET 8; AL = bool
//
// 1) FUN_00971480(this) — drain/process preloader work (assPreloader.cpp).
// 2) If GuardedVector_ContainsFirstEqual(this+0x7c, key): return 1.
// 3) If recurse:
//      collect dependency keys via FUN_00744360(key, &local_ring);
//      for each child slot: recurse IsKeyTrackedRecursive(this, child, recurse);
//      any hit → clear local_ring (FUN_005b2ba0) + return 1;
//      else clear + return 0.
// 4) Else return 0.
//
// Name is structural (_Inferred). Nested drain/dep-walk not dual-owned here.
// =============================================================================

#include <cstdint>

struct GuardedVectorHeader {
  uint32_t _unk00;
  uint32_t** pages;  // +0x04
  uint32_t capacity; // +0x08
  uint32_t begin;    // +0x0c
  int32_t  size;     // +0x10
};

extern "C" void FUN_00971480(void* host /*stack*/);
extern "C" uint8_t GuardedVector_ContainsFirstEqual(GuardedVectorHeader* container /*EAX*/,
                                                    const int* key /*stack*/);
extern "C" void FUN_00744360(const int* key /*stack*/, GuardedVectorHeader* out_ring /*stack*/);
extern "C" void __fastcall FUN_005b2ba0(GuardedVectorHeader* ring /*ECX*/);

uint8_t AssPreloader_IsKeyTrackedRecursive_Inferred(
    void* self /*ECX*/,
    const int* key /*stack*/,
    uint8_t recurse /*stack*/)
{
  FUN_00971480(self);

  auto* tracked = reinterpret_cast<GuardedVectorHeader*>(
      reinterpret_cast<uint8_t*>(self) + 0x7c);
  if (GuardedVector_ContainsFirstEqual(tracked, key) != 0) {
    return 1;
  }

  if (recurse == 0) {
    return 0;
  }

  // Local ring zero-init (pages/cap/begin/size = 0) then fill deps.
  GuardedVectorHeader local{};
  FUN_00744360(key, &local);

  uint32_t idx = local.begin;
  const uint32_t end = static_cast<uint32_t>(local.size) + local.begin;
  for (; idx != end; ++idx) {
    uint32_t page = idx >> 2;
    const uint32_t sub = idx + page * static_cast<uint32_t>(-4);
    if (local.capacity <= page) {
      page -= local.capacity;
    }
    int* child = reinterpret_cast<int*>(
        reinterpret_cast<uint8_t*>(local.pages[page]) + sub * 4);
    if (AssPreloader_IsKeyTrackedRecursive_Inferred(self, child, recurse) != 0) {
      FUN_005b2ba0(&local);
      return 1;
    }
  }

  FUN_005b2ba0(&local);
  return 0;
}
