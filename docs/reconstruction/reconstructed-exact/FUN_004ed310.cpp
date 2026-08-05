// =============================================================================
// FUN_004ed310  (twin of AssPreloader_ProcessKeyRingStep_Inferred)
// -----------------------------------------------------------------------------
// Stable ID: aa_004ed310
// Address:   0x004ed310–0x004ed46b  (autoassault.exe, image base 0x400000)
// Dual:      W35-A 2026-07-29
// Exactness: Behavior-preserving. Not modernization.
// Bit-for-bit vs retail EXE: DEFERRED.
// =============================================================================
// See: AssPreloader_ProcessKeyRingStep_Inferred.cpp for named clean.

#include <cstdint>

struct GuardedVectorHeader {
  uint32_t _unk00;
  uint32_t** pages;
  int32_t  capacity;
  int32_t  begin;
  int32_t  size;
};

struct GuardedVectorIteratorPair {
  GuardedVectorHeader* container;
  uint32_t             index;
};

extern "C" uint8_t* DAT_00d1f050;
extern "C" uint8_t FUN_00971900(void* preloader /*ECX*/, const int* key, char recurse);
extern "C" void    FUN_00971030(void* preloader /*ECX*/, const int* key);
extern "C" void    FUN_0043df90(GuardedVectorHeader* container /*ECX*/,
                                GuardedVectorIteratorPair* out,
                                GuardedVectorHeader* from_c, int32_t from_i,
                                GuardedVectorHeader* to_c, int32_t to_i);
extern "C" uint8_t FUN_0075d610(void* cache /*ECX*/, const int* key);
extern "C" uint8_t FUN_00971a20(void* preloader /*ECX*/, const int* key, char recurse);
extern "C" uint32_t FUN_009717a0(void* preloader /*ECX*/, const int* key);

static const int* ResolveSlot(GuardedVectorHeader* c, uint32_t abs_idx)
{
  uint32_t page = abs_idx >> 2;
  const uint32_t sub = abs_idx + page * static_cast<uint32_t>(-4);
  if (static_cast<uint32_t>(c->capacity) <= page) {
    page -= static_cast<uint32_t>(c->capacity);
  }
  return reinterpret_cast<const int*>(&c->pages[page][sub]);
}

// Retail: cdecl; (ring, progress_flag*, cursor*); plain RET; AL done/yield.
uint8_t FUN_004ed310(GuardedVectorHeader* ring,
                     char* progress_flag,
                     uint32_t* cursor)
{
  void* cache = DAT_00d1f050;
  void* preloader = *reinterpret_cast<void**>(
      reinterpret_cast<uint8_t*>(cache) + 0x6c);

  if (preloader == nullptr) {
    return 1;
  }

  if (static_cast<int32_t>(*cursor) < 0 ||
      static_cast<uint32_t>(ring->size) <= *cursor) {
    *cursor = 0;
  }

  GuardedVectorHeader* cur = ring;
  uint32_t abs_idx =
      static_cast<uint32_t>(ring->begin) + *cursor;

  for (;;) {
    const uint32_t end =
        static_cast<uint32_t>(ring->size) +
        static_cast<uint32_t>(ring->begin);

    if (cur == ring && abs_idx == end) {
      *cursor = 0;
      *progress_flag = 0;
      return 1;
    }

    const int* slot = ResolveSlot(cur, abs_idx);

    if (FUN_00971900(preloader, slot, 0) != 0) {
      if (*progress_flag != 0) {
        FUN_00971030(preloader, slot);
      }
      GuardedVectorIteratorPair out{};
      FUN_0043df90(cur, &out,
                   cur, static_cast<int32_t>(abs_idx),
                   cur, static_cast<int32_t>(abs_idx + 1));
      cur = out.container;
      abs_idx = out.index;
      continue;
    }

    if (*progress_flag == 0) {
      if (FUN_0075d610(cache, slot) == 0) {
        if (FUN_00971a20(preloader, slot, 0) == 0) {
          FUN_009717a0(preloader, slot);
          *progress_flag = 1;
          return 0;
        }
      }
    } else {
      if (FUN_0075d610(cache, slot) == 0) {
        if (FUN_00971a20(preloader, slot, 0) == 0) {
          return 0;
        }
        *cursor = *cursor + 1;
        abs_idx = abs_idx + 1;
        continue;
      }
    }

    *cursor = *cursor + 1;
    abs_idx = abs_idx + 1;
  }
}
