// =============================================================================
// PerfStatRings_CommitAndTrim_Inferred
// -----------------------------------------------------------------------------
// Stable ID: aa_009668a0
// Address:   0x009668a0  (autoassault.exe, image base 0x400000)
// System:    Palantir / frame perf stat rings
// Generated: 2026-07-29 W30-E dual (from raw + live read_memory)
// Exactness: Behavior-preserving rewrite of decompiler control flow. Not modernization.
// Bit-for-bit vs retail EXE: DEFERRED.
// =============================================================================

// PURPOSE: Commit current period bins into 4 channel GuardedVector rings + 1 sum ring,
// trim short window (sum>500) and long window (sum>3000), publish 0x4C-dword snapshot,
// clear live bins/block. Optional scaled-timer attribution when +0xC8==0.
//
// ABI: stdcall; 1 stack formal (PerfStat*); ret 4.
// PushBack: EAX=container, stack=value* (GuardedVector_PushBack / 0043c830).

#include <cstdint>
#include <cstring>

struct GuardedVectorHeader {
  uint32_t _pad0;       // +0x00
  uint32_t* block_map;  // +0x04
  uint32_t capacity;    // +0x08  (pages)
  uint32_t begin;       // +0x0C
  uint32_t size;        // +0x10
};  // stride 0x14 in this object

// Forward decls (owned elsewhere)
extern int  FUN_0076c3c0(void* self /*ECX*/);
extern void GuardedVector_PushBack(GuardedVectorHeader* container /*EAX*/,
                                   const uint32_t* value /*stack*/);

// Retail layout subset used by this unit (not a full product type).
struct PerfStat {
  uint8_t  _pad0[0x30];
  int32_t  last_tick_30;            // +0x30
  int32_t  bins_34[4];              // +0x34
  int32_t  channel_totals_44[4];    // +0x44
  int32_t  short_sum_54;            // +0x54
  int32_t  sample_count_58;         // +0x58
  GuardedVectorHeader rings_5c[4];  // +0x5C stride 0x14 → +0x5C,+0x70,+0x84,+0x98
  GuardedVectorHeader sum_ring_ac;  // +0xAC
  int32_t  long_sum_c0;             // +0xC0
  uint32_t phase_c4;                // +0xC4
  char     timing_disabled_c8;      // +0xC8
  uint8_t  _pad_c9[3];
  uint32_t live_cc[0x4C];           // +0xCC
  // ... gap ...
  // uint32_t published_1fc[0x4C];  // +0x1FC
  // ...
  // int32_t commit_count_3d0;      // +0x3D0
};

static int32_t LoadRingDword(const GuardedVectorHeader* ring, uint32_t abs_index)
{
  uint32_t page = abs_index >> 2;
  uint32_t rem  = abs_index + page * static_cast<uint32_t>(-4); // abs & 3 via (abs + (-4*page))
  // Retail: page = abs>>2; if (capacity <= page) page -= capacity;
  if (ring->capacity <= page) {
    page -= ring->capacity;
  }
  rem = abs_index - (page << 2); // equivalent residue in page
  uint32_t* block = reinterpret_cast<uint32_t*>(ring->block_map[page]);
  return static_cast<int32_t>(block[rem]);
}

// stdcall ret 4 — stack arg only
void __stdcall PerfStatRings_CommitAndTrim_Inferred(uint8_t* self_raw)
{
  auto* self = reinterpret_cast<PerfStat*>(self_raw);

  *reinterpret_cast<int32_t*>(self_raw + 0x3D0) += 1;

  if (*reinterpret_cast<char*>(self_raw + 0xC8) == 0) {
    int now = FUN_0076c3c0(self_raw);
    uint32_t phase = *reinterpret_cast<uint32_t*>(self_raw + 0xC4);
    int32_t* bin = reinterpret_cast<int32_t*>(self_raw + 0x34 + phase * 4);
    *bin += (now - *reinterpret_cast<int32_t*>(self_raw + 0x30));
    *reinterpret_cast<int32_t*>(self_raw + 0x30) = now;
    *reinterpret_cast<uint32_t*>(self_raw + 0xC4) = 3;
  }

  int32_t sum = 0;
  int32_t* bins = reinterpret_cast<int32_t*>(self_raw + 0x34);
  auto* ring0 = reinterpret_cast<GuardedVectorHeader*>(self_raw + 0x5C);

  for (int i = 0; i < 4; i++) {
    GuardedVectorHeader* ring = reinterpret_cast<GuardedVectorHeader*>(
        reinterpret_cast<uint8_t*>(ring0) + i * 0x14);
    GuardedVector_PushBack(ring, reinterpret_cast<const uint32_t*>(&bins[i]));
    *reinterpret_cast<int32_t*>(self_raw + 0x44 + i * 4) += bins[i];
    sum += bins[i];
  }

  *reinterpret_cast<int32_t*>(self_raw + 0x54) += sum;
  *reinterpret_cast<int32_t*>(self_raw + 0xC0) += sum;

  {
    uint32_t local_sum = static_cast<uint32_t>(sum);
    auto* sum_ring = reinterpret_cast<GuardedVectorHeader*>(self_raw + 0xAC);
    GuardedVector_PushBack(sum_ring, &local_sum);
  }

  *reinterpret_cast<int32_t*>(self_raw + 0x58) += 1;

  // --- short window trim (threshold 500) ---
  while (*reinterpret_cast<int32_t*>(self_raw + 0x54) > 500) {
    int32_t sample_count = *reinterpret_cast<int32_t*>(self_raw + 0x58);
    // rings at +0x5C, +0x70, +0x84, +0x98; channel totals +0x44..+0x50
    static const uint32_t kRingBase[4] = {0x5C, 0x70, 0x84, 0x98};
    static const uint32_t kTotalOff[4] = {0x44, 0x48, 0x4C, 0x50};
    for (int i = 0; i < 4; i++) {
      auto* ring = reinterpret_cast<GuardedVectorHeader*>(self_raw + kRingBase[i]);
      uint32_t abs_i = ring->begin + (ring->size - static_cast<uint32_t>(sample_count));
      int32_t v = LoadRingDword(ring, abs_i);
      *reinterpret_cast<int32_t*>(self_raw + kTotalOff[i]) -= v;
      *reinterpret_cast<int32_t*>(self_raw + 0x54) -= v;
    }
    *reinterpret_cast<int32_t*>(self_raw + 0x58) -= 1;
  }

  // --- long window trim (threshold 3000): advance begin on 4+1 rings ---
  while (*reinterpret_cast<int32_t*>(self_raw + 0xC0) > 3000) {
    static const uint32_t kRingBase[4] = {0x5C, 0x70, 0x84, 0x98};
    for (int i = 0; i < 4; i++) {
      auto* ring = reinterpret_cast<GuardedVectorHeader*>(self_raw + kRingBase[i]);
      if (ring->size != 0) {
        ring->begin += 1;
        if (static_cast<uint32_t>(ring->capacity * 4) <= ring->begin) {
          ring->begin = 0;
        }
        ring->size -= 1;
        if (ring->size == 0) {
          ring->begin = 0;
        }
      }
    }

    auto* sum_ring = reinterpret_cast<GuardedVectorHeader*>(self_raw + 0xAC);
    int32_t oldest = LoadRingDword(sum_ring, sum_ring->begin);
    *reinterpret_cast<int32_t*>(self_raw + 0xC0) -= oldest;
    if (sum_ring->size != 0) {
      sum_ring->begin += 1;
      if (static_cast<uint32_t>(sum_ring->capacity * 4) <= sum_ring->begin) {
        sum_ring->begin = 0;
      }
      sum_ring->size -= 1;
      if (sum_ring->size == 0) {
        sum_ring->begin = 0;
      }
    }
  }

  // clear bins
  *reinterpret_cast<uint32_t*>(self_raw + 0x34) = 0;
  *reinterpret_cast<uint32_t*>(self_raw + 0x38) = 0;
  *reinterpret_cast<uint32_t*>(self_raw + 0x3C) = 0;
  *reinterpret_cast<uint32_t*>(self_raw + 0x40) = 0;

  // publish + clear 0x4C dwords
  std::memcpy(self_raw + 0x1FC, self_raw + 0xCC, 0x4C * 4);
  std::memset(self_raw + 0xCC, 0, 0x4C * 4);

  if (*reinterpret_cast<char*>(self_raw + 0xC8) == 0) {
    int now = FUN_0076c3c0(self_raw);
    uint32_t phase = *reinterpret_cast<uint32_t*>(self_raw + 0xC4);
    int32_t* bin = reinterpret_cast<int32_t*>(self_raw + 0x34 + phase * 4);
    *bin += (now - *reinterpret_cast<int32_t*>(self_raw + 0x30));
    *reinterpret_cast<int32_t*>(self_raw + 0x30) = now;
    *reinterpret_cast<uint32_t*>(self_raw + 0xC4) = 0;
  }
}
