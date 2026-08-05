// =============================================================================
// GuardedVector_RingAssignBackward
// -----------------------------------------------------------------------------
// Stable ID: aa_0043d300
// Address:   0x0043d300–0x0043d38d  (autoassault.exe, image base 0x400000)
// System:    STL / guarded ring-vector container
// Generated: dual A/B seal 2026-07-29 (W28-C); Ghidra FUN_0043d300
// Exactness: Behavior-preserving rewrite of decompiler control flow. Not modernization.
// Bit-for-bit vs retail EXE: DEFERRED.
// =============================================================================

/*
 * Behavioral notes:
 * - Reverse-direction ring dword assign between two (container,index) cursors.
 * - Walks src_index and dst_index downward until (src_container,src_index)
 *   meets the stop pair (stop_container,stop_index).
 * - Block map: block = idx>>2; if block >= capacity then block -= capacity;
 *   lane = idx + block*-4  (within-block 0..3).
 * - 7 stack args; plain RET (caller cleans). Returns out_pair.
 * - Used by GuardedVector_EraseRange shorter-prefix arm and assign/grow helpers.
 * - Name is structural Inferred (GuardedVector_* family); product open.
 * - Sibling forward walker: FUN_0043d390 (unowned in this dual).
 */

#include <cstdint>

struct GuardedVectorHeader {
  uint32_t _unk00;
  uint32_t* slots;   // +0x04  array of block base pointers
  uint32_t  capacity; // +0x08
  // begin/size not read by this leaf
};

struct GuardedVectorIteratorPair {
  GuardedVectorHeader* container;
  uint32_t             index;
};

static inline uint32_t* RingElemPtr(GuardedVectorHeader* c, uint32_t idx)
{
  uint32_t block = idx >> 2;
  const int32_t lane_base = static_cast<int32_t>(block) * -4;
  if (c->capacity <= block) {
    block -= c->capacity;
  }
  uint32_t* block_base = reinterpret_cast<uint32_t*>(
      *reinterpret_cast<int*>(reinterpret_cast<uint8_t*>(c->slots) + block * 4));
  // decompiler form uses slots as int* table of block pointers
  (void)block_base;
  // Prefer explicit form matching raw:
  int* slot_table = reinterpret_cast<int*>(c->slots);
  int block_ptr = slot_table[block];
  return reinterpret_cast<uint32_t*>(block_ptr + (static_cast<int>(idx) + lane_base) * 4);
}

// Clean signature (retail: 7 stack args, plain RET).
GuardedVectorIteratorPair* GuardedVector_RingAssignBackward(
    GuardedVectorIteratorPair* out_pair,
    GuardedVectorHeader* stop_container,
    uint32_t stop_index,
    GuardedVectorHeader* src_container,
    uint32_t src_index,
    GuardedVectorHeader* dst_container,
    uint32_t dst_index)
{
  while (stop_container != src_container || stop_index != src_index) {
    src_index -= 1;
    uint32_t src_block = src_index >> 2;
    const int src_lane_base = static_cast<int>(src_block) * -4;
    if (src_container->capacity <= src_block) {
      src_block -= src_container->capacity;
    }

    dst_index -= 1;
    uint32_t dst_block = dst_index >> 2;
    const int dst_lane_base = static_cast<int>(dst_block) * -4;
    if (dst_container->capacity <= dst_block) {
      dst_block -= dst_container->capacity;
    }

    int* src_slots = reinterpret_cast<int*>(src_container->slots);
    int* dst_slots = reinterpret_cast<int*>(dst_container->slots);
    *reinterpret_cast<uint32_t*>(
        dst_slots[dst_block] + (static_cast<int>(dst_index) + dst_lane_base) * 4) =
        *reinterpret_cast<uint32_t*>(
            src_slots[src_block] + (static_cast<int>(src_index) + src_lane_base) * 4);
  }

  out_pair->container = dst_container;
  out_pair->index = dst_index;
  return out_pair;
}
