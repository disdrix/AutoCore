// =============================================================================
// AssPreloader_ExpandDepsAndEnqueueFromRing_Inferred
// -----------------------------------------------------------------------------
// Stable ID: aa_00971820
// Address:   0x00971820–0x009718fd  (autoassault.exe, image base 0x400000)
// Ghidra:    FUN_00971820
// System:    assPreloader / asset preload pipeline
// Dual:      W32-K 2026-07-29
// Exactness: Behavior-preserving. Not modernization.
// Bit-for-bit vs retail EXE: DEFERRED.
// =============================================================================
//
// Retail ABI:
//   ECX  = AssPreloader* host
//   stack = GuardedVector* source (dword keys)
//   RET 4; returns 0 in EAX.
//
// For each key in source:
//   clear prior local dep ring contents if non-empty (FUN_0043df90),
//   push key into local (GuardedVector_PushBack_Thiscall),
//   expand dependencies via FUN_00744360 into local
//     (ECX = *(*(host+0x110)+0x64) per bytes),
//   AssPreloader_EnqueueEligibleFromRing(host, local) — ESI=local, stack=host.
// Finally destroy local ring (FUN_005b2ba0).
//
// Name is structural (_Inferred). Nested FUN_00744360 / FUN_0043df90 not dual-
// owned here. Family sealed via callee AssPreloader enqueue + sibling worker
// assPreloader.cpp path. Reject scaffold VOG_DEBUG_STOP callee plate.
// =============================================================================

#include <cstdint>

struct GuardedVectorHeader {
  uint32_t _unk00;
  uint32_t** pages;  // +0x04
  uint32_t capacity; // +0x08
  uint32_t begin;    // +0x0c
  int32_t  size;     // +0x10
};

// Nested helpers (owned elsewhere; signatures as used here).
extern "C" void FUN_0043df90(/* erase range args; ECX=container */);
extern "C" void __thiscall GuardedVector_PushBack_Thiscall(
    GuardedVectorHeader* container /*ECX*/, const uint32_t* value /*stack*/);
// Retail: ECX = *(*(host+0x110)+0x64); stack key* + out_ring*.
extern "C" void FUN_00744360(const int* key /*stack*/,
                             GuardedVectorHeader* out_ring /*stack*/);
extern "C" void AssPreloader_EnqueueEligibleFromRing_Inferred(
    void* host /*stack*/, GuardedVectorHeader* source /*ESI*/);
extern "C" void __fastcall FUN_005b2ba0(GuardedVectorHeader* ring /*ECX*/);

uint32_t AssPreloader_ExpandDepsAndEnqueueFromRing_Inferred(
    void* host /*ECX*/,
    GuardedVectorHeader* source /*stack*/)
{
  GuardedVectorHeader local{};
  // Retail: pages/cap/begin/size zeroed; SEH around body.

  uint32_t idx = source->begin;
  const uint32_t end =
      static_cast<uint32_t>(source->size) + source->begin;

  for (; idx != end; ++idx) {
    if (local.size != 0) {
      // Erase full prior content before reuse (FUN_0043df90 range erase).
      FUN_0043df90();
    }

    uint32_t page = idx >> 2;
    const uint32_t sub = idx + page * static_cast<uint32_t>(-4); // idx & 3
    if (source->capacity <= page) {
      page -= source->capacity;
    }
    int* key = reinterpret_cast<int*>(
        reinterpret_cast<uint8_t*>(source->pages[page]) + sub * 4);

    GuardedVector_PushBack_Thiscall(&local, reinterpret_cast<const uint32_t*>(key));

    // ECX context from resource cache helper table — set by retail before call.
    void* cache = *reinterpret_cast<void**>(
        reinterpret_cast<uint8_t*>(host) + 0x110);
    // ECX = *(cache+0x64) at call site (not expressed as formal).
    (void)cache;
    FUN_00744360(key, &local);

    // ESI = &local; stack host.
    AssPreloader_EnqueueEligibleFromRing_Inferred(host, &local);
  }

  FUN_005b2ba0(&local);
  return 0;
}
