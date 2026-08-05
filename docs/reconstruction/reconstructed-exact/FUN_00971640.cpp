// =============================================================================
// FUN_00971640
// -----------------------------------------------------------------------------
// Stable ID: aa_00971640
// Address:   0x00971640–0x009716f7  (autoassault.exe, image base 0x400000)
// Structural: AssPreloader_EnqueueEligibleFromRing_Inferred
// Dual:      W31-K 2026-07-29
// Exactness: Behavior-preserving rewrite of decompiler CF + sealed ABI.
// Bit-for-bit vs retail EXE: DEFERRED.
// =============================================================================
//
// Retail ABI: ESI = source GuardedVector ring; stack = AssPreloader* host;
//             RET 4; void.
// =============================================================================

#include <cstdint>
#include <windows.h>

struct GuardedVectorHeader {
  uint32_t _unk00;
  uint32_t** pages;  // +0x04
  uint32_t capacity; // +0x08
  uint32_t begin;    // +0x0c
  int32_t  size;     // +0x10
};

extern "C" void __fastcall FUN_0043d5e0(void* tree /*ECX*/, void* out_it /*EAX*/);
extern "C" void* FUN_0044e8c0(void* out_node);
extern "C" uint8_t FUN_0043e5b0(const int* key /*EAX=container*/);
extern "C" void FUN_0043e4b0(const int* key /*EDI=container*/);

// ESI is a retail register formal — modeled as an extra parameter for C++.
void FUN_00971640(void* host /*stack*/, GuardedVectorHeader* source /*ESI*/)
{
  uint8_t dirty = 0;
  uint32_t idx = source->begin;
  const uint32_t end_idx = static_cast<uint32_t>(source->size) + source->begin;

  for (; idx != end_idx; ++idx) {
    uint32_t page = idx >> 2;
    const uint32_t sub = idx + page * static_cast<uint32_t>(-4);
    if (source->capacity <= page) {
      page -= source->capacity;
    }
    int* key = reinterpret_cast<int*>(
        reinterpret_cast<uint8_t*>(source->pages[page]) + sub * 4);

    void* it = nullptr;
    void* tree = reinterpret_cast<uint8_t*>(host) + 0x10;
    FUN_0043d5e0(tree, &it);

    void* map_end = *reinterpret_cast<void**>(reinterpret_cast<uint8_t*>(host) + 0x14);
    if (it != map_end) {
      continue;
    }

    void* cache = *reinterpret_cast<void**>(reinterpret_cast<uint8_t*>(host) + 0x110);
    void* node = nullptr;
    FUN_0044e8c0(&node);
    void* cache_end = *reinterpret_cast<void**>(reinterpret_cast<uint8_t*>(cache) + 8);
    if (node != cache_end &&
        *reinterpret_cast<int*>(reinterpret_cast<uint8_t*>(node) + 0x0c) != 0) {
      continue;
    }

    auto* pending = reinterpret_cast<GuardedVectorHeader*>(
        reinterpret_cast<uint8_t*>(host) + 0x1c);
    // Retail: EAX=pending, stack=key*.
    if (FUN_0043e5b0(key) != 0) {
      continue;
    }

    dirty = 1;
    FUN_0043e4b0(key);
  }

  if (dirty) {
    HANDLE ev = *reinterpret_cast<HANDLE*>(reinterpret_cast<uint8_t*>(host) + 4);
    SetEvent(ev);
  }
}
