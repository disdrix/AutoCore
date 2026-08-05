// =============================================================================
// AssPreloader_EnqueueEligibleFromRing_Inferred
// -----------------------------------------------------------------------------
// Stable ID: aa_00971640
// Address:   0x00971640–0x009716f7  (autoassault.exe, image base 0x400000)
// Ghidra:    FUN_00971640
// System:    assPreloader / asset preload pipeline
// Dual:      W31-K 2026-07-29
// Exactness: Behavior-preserving. Not modernization.
// Bit-for-bit vs retail EXE: DEFERRED.
// =============================================================================
//
// Retail ABI:
//   ESI  = source ring (GuardedVector family: +0x04 pages, +0x08 cap,
//          +0x0c begin, +0x10 size) of dword keys.
//   stack = AssPreloader* host; RET 4; void.
//
// For each key in ESI:
//   - tree lower_bound on host+0x10; require iterator == host+0x14 (absent)
//   - resource cache lookup via *(host+0x110); require end or *(node+0xc)==0
//   - if not already in host+0x1c GuardedVector: push key value, mark dirty
// If dirty: SetEvent(*(HANDLE*)(host+4)).
//
// Name is structural (_Inferred). Nested FUN_0043d5e0 / FUN_0043e4b0 / cache
// not dual-owned here. Sibling drain FUN_00971480 logs assPreloader.cpp.
// =============================================================================

#include <cstdint>
#include <windows.h>

struct GuardedVectorHeader {
  uint32_t _unk00;
  uint32_t** pages;  // +0x04
  uint32_t capacity; // +0x08  page count
  uint32_t begin;    // +0x0c
  int32_t  size;     // +0x10
};

// Nested helpers (owned elsewhere; signatures as used here).
extern "C" void __fastcall FUN_0043d5e0(void* tree /*ECX*/, void* out_it /*EAX*/ /*EBX=key**/);
extern "C" void* FUN_0044e8c0(void* out_node /*stack*/ /*EDI=cache, EBX=key**/);
extern "C" uint8_t GuardedVector_ContainsFirstEqual(GuardedVectorHeader* container /*EAX*/,
                                                    const int* key /*stack*/);
extern "C" void FUN_0043e4b0(const int* key /*stack*/ /*EDI=container*/);

// Clean surface: ESI source made explicit.
void AssPreloader_EnqueueEligibleFromRing_Inferred(
    void* host /*stack; retail*/,
    GuardedVectorHeader* source /*ESI; retail*/)
{
  uint8_t dirty = 0;
  uint32_t idx = source->begin;
  const uint32_t end = static_cast<uint32_t>(source->size) + source->begin;

  for (; idx != end; ++idx) {
    uint32_t page = idx >> 2;
    const uint32_t sub = idx + page * static_cast<uint32_t>(-4); // idx & 3
    if (source->capacity <= page) {
      page -= source->capacity;
    }
    // Address of dword slot in page map (key*).
    int* key = reinterpret_cast<int*>(
        reinterpret_cast<uint8_t*>(source->pages[page]) + sub * 4);

    // Tree at host+0x10; end iterator at host+0x14.
    void* it = nullptr;
    void* tree = reinterpret_cast<uint8_t*>(host) + 0x10;
    // EBX=key set by caller convention inside FUN_0043d5e0 body.
    FUN_0043d5e0(tree, &it);

    void* end_it = *reinterpret_cast<void**>(reinterpret_cast<uint8_t*>(host) + 0x14);
    if (it != end_it) {
      continue;
    }

    void* cache = *reinterpret_cast<void**>(reinterpret_cast<uint8_t*>(host) + 0x110);
    void* node = nullptr;
    // EDI=cache, EBX=key inside FUN_0044e8c0.
    FUN_0044e8c0(&node);
    void* cache_end = *reinterpret_cast<void**>(reinterpret_cast<uint8_t*>(cache) + 8);
    if (node != cache_end && *reinterpret_cast<int*>(reinterpret_cast<uint8_t*>(node) + 0x0c) != 0) {
      continue;
    }

    auto* pending = reinterpret_cast<GuardedVectorHeader*>(
        reinterpret_cast<uint8_t*>(host) + 0x1c);
    if (GuardedVector_ContainsFirstEqual(pending, key) != 0) {
      continue;
    }

    dirty = 1;
    // EDI=pending inside FUN_0043e4b0; copies *key into ring.
    FUN_0043e4b0(key);
  }

  if (dirty) {
    HANDLE ev = *reinterpret_cast<HANDLE*>(reinterpret_cast<uint8_t*>(host) + 4);
    SetEvent(ev);
  }
}
