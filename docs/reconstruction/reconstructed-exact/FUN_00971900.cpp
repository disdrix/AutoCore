// =============================================================================
// FUN_00971900
// -----------------------------------------------------------------------------
// Stable ID: aa_00971900
// Address:   0x00971900–0x00971a19  (autoassault.exe, image base 0x400000)
// Structural: AssPreloader_IsKeyTrackedRecursive_Inferred
// Dual:      W31-K 2026-07-29
// Exactness: Behavior-preserving rewrite of decompiler CF + sealed ABI.
// Bit-for-bit vs retail EXE: DEFERRED.
// =============================================================================
//
// Retail ABI: ECX = AssPreloader* this; stack = (const int* key, char recurse);
//             RET 8; AL = bool.
// =============================================================================

#include <cstdint>

struct GuardedVectorHeader {
  uint32_t _unk00;
  uint32_t** pages;
  uint32_t capacity;
  uint32_t begin;
  int32_t  size;
};

extern "C" void FUN_00971480(void* host);
extern "C" uint8_t FUN_0043e5b0(const int* key /*EAX=container*/);
extern "C" void FUN_00744360(const int* key, GuardedVectorHeader* out_ring);
extern "C" void __fastcall FUN_005b2ba0(GuardedVectorHeader* ring /*ECX*/);

uint8_t FUN_00971900(void* self /*ECX*/, const int* key /*stack*/, uint8_t recurse /*stack*/)
{
  FUN_00971480(self);

  // Retail: EAX = this+0x7c, stack = key*.
  auto* tracked = reinterpret_cast<GuardedVectorHeader*>(
      reinterpret_cast<uint8_t*>(self) + 0x7c);
  (void)tracked;
  if (FUN_0043e5b0(key) != 0) {
    return 1;
  }

  if (recurse == 0) {
    return 0;
  }

  GuardedVectorHeader local{};
  FUN_00744360(key, &local);

  uint32_t idx = local.begin;
  const uint32_t end_idx = static_cast<uint32_t>(local.size) + local.begin;
  for (; idx != end_idx; ++idx) {
    uint32_t page = idx >> 2;
    const uint32_t sub = idx + page * static_cast<uint32_t>(-4);
    if (local.capacity <= page) {
      page -= local.capacity;
    }
    int* child = reinterpret_cast<int*>(
        reinterpret_cast<uint8_t*>(local.pages[page]) + sub * 4);
    if (FUN_00971900(self, child, recurse) != 0) {
      FUN_005b2ba0(&local);
      return 1;
    }
  }

  FUN_005b2ba0(&local);
  return 0;
}
