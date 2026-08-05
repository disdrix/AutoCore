// =============================================================================
// GuardedVector_RingAssignForward
// -----------------------------------------------------------------------------
// Stable ID: aa_0043ec50
// Address:   0x0043ec50–0x0043ecdc  (autoassault.exe, image base 0x400000)
// System:    STL / guarded ring-vector container
// Generated: dual A/B seal 2026-07-29 (W33-J); Ghidra FUN_0043ec50
// Exactness: Behavior-preserving rewrite of decompiler control flow. Not modernization.
// Bit-for-bit vs retail EXE: DEFERRED.
// =============================================================================

/*
 * Behavioral notes:
 * - Forward-direction ring dword assign between (container,index) cursors.
 * - Walks src_index and dst_index upward until (src_container,src_index)
 *   meets the stop pair (src_end_container,src_end_index).
 * - Block map: block = idx>>2; if block >= capacity then block -= capacity;
 *   lane = idx + block*-4  (within-block 0..3).
 * - Skip store when src_elem* == dst_elem* (self-pointer guard).
 * - 7 stack args; plain RET (caller cleans 0x1C). Writes out_pair.
 * - Used by GuardedVector_InsertN_Thiscall / InsertRange(_Thiscall) front/forward arms.
 * - Name is structural Inferred (GuardedVector_* family); product open.
 * - Older-family forward sibling: FUN_0043d390 GuardedVector_RingCopyElements (W28-A).
 * - Reverse twin in thiscall family: FUN_0043ebb0 (unowned here).
 * - Older reverse: FUN_0043d300 GuardedVector_RingAssignBackward (W28-C).
 */

#include <cstdint>

struct GuardedVectorHeader {
  uint32_t  _unk00;
  int*      slots;    // +0x04  array of block base pointers
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
  const int lane_base = static_cast<int>(block) * -4;
  if (c->capacity <= block) {
    block -= c->capacity;
  }
  int* slot_table = c->slots;
  int block_ptr = slot_table[block];
  return reinterpret_cast<uint32_t*>(
      block_ptr + (static_cast<int>(idx) + lane_base) * 4);
}

// Clean signature (retail: 7 stack args, plain RET).
GuardedVectorIteratorPair* GuardedVector_RingAssignForward(
    GuardedVectorIteratorPair* out_pair,
    GuardedVectorHeader* src_container,
    uint32_t src_index,
    GuardedVectorHeader* src_end_container,
    uint32_t src_end_index,
    GuardedVectorHeader* dst_container,
    uint32_t dst_index)
{
  while (src_container != src_end_container || src_index != src_end_index) {
    uint32_t src_block = src_index >> 2;
    const int src_lane_base = static_cast<int>(src_block) * -4;
    if (src_container->capacity <= src_block) {
      src_block -= src_container->capacity;
    }

    uint32_t dst_block = dst_index >> 2;
    const int dst_lane_base = static_cast<int>(dst_block) * -4;
    if (dst_container->capacity <= dst_block) {
      dst_block -= dst_container->capacity;
    }

    int* src_slots = src_container->slots;
    int* dst_slots = dst_container->slots;
    uint32_t* src_elem = reinterpret_cast<uint32_t*>(
        src_slots[src_block] + (static_cast<int>(src_index) + src_lane_base) * 4);
    uint32_t* dst_elem = reinterpret_cast<uint32_t*>(
        dst_slots[dst_block] + (static_cast<int>(dst_index) + dst_lane_base) * 4);

    if (dst_elem != src_elem) {
      *dst_elem = *src_elem;
    }

    src_index += 1;
    dst_index += 1;
  }

  out_pair->container = dst_container;
  out_pair->index = dst_index;
  return out_pair;
}
