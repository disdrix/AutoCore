// =============================================================================
// FUN_00971820
// -----------------------------------------------------------------------------
// Stable ID: aa_00971820
// Address:   0x00971820–0x009718fd  (autoassault.exe, image base 0x400000)
// Structural: AssPreloader_ExpandDepsAndEnqueueFromRing_Inferred
// Dual:      W32-K 2026-07-29
// Exactness: Behavior-preserving rewrite of decompiler CF + sealed ABI.
// Bit-for-bit vs retail EXE: DEFERRED.
// =============================================================================
//
// Retail ABI: ECX = AssPreloader* host; stack = GuardedVector* source keys;
//             RET 4; EAX = 0.
// =============================================================================

#include <cstdint>

struct GuardedVectorHeader {
  uint32_t _unk00;
  uint32_t** pages;
  uint32_t capacity;
  uint32_t begin;
  int32_t  size;
};

extern "C" void FUN_0043df90(/* erase range; ECX=container */);
extern "C" void __thiscall FUN_0043d670(GuardedVectorHeader* c /*ECX*/,
                                        const uint32_t* v /*stack*/);
extern "C" void FUN_00744360(const int* key, GuardedVectorHeader* out_ring);
extern "C" void FUN_00971640(void* host /*stack*/, GuardedVectorHeader* source /*ESI*/);
extern "C" void __fastcall FUN_005b2ba0(GuardedVectorHeader* ring /*ECX*/);

uint32_t FUN_00971820(void* host /*ECX*/, GuardedVectorHeader* source /*stack*/)
{
  GuardedVectorHeader local{};

  uint32_t idx = source->begin;
  const uint32_t end = static_cast<uint32_t>(source->size) + source->begin;

  for (; idx != end; ++idx) {
    if (local.size != 0) {
      FUN_0043df90();
    }

    uint32_t page = idx >> 2;
    const uint32_t sub = idx + page * static_cast<uint32_t>(-4);
    if (source->capacity <= page) {
      page -= source->capacity;
    }
    int* key = reinterpret_cast<int*>(
        reinterpret_cast<uint8_t*>(source->pages[page]) + sub * 4);

    FUN_0043d670(&local, reinterpret_cast<const uint32_t*>(key));
    FUN_00744360(key, &local);
    FUN_00971640(host, &local);
  }

  FUN_005b2ba0(&local);
  return 0;
}
