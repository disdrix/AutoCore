// =============================================================================
// GuardedVector_RingAssignBackwardChecked
// -----------------------------------------------------------------------------
// Stable ID: aa_0043ebb0
// Address:   0x0043ebb0–0x0043ec43  (autoassault.exe, image base 0x400000)
// Ghidra:    FUN_0043ebb0
// System:    STL / guarded ring-vector container
// Dual:      W33-K 2026-07-29
// Exactness: Behavior-preserving. Not modernization.
// Bit-for-bit vs retail EXE: DEFERRED.
// =============================================================================
//
// Leaf: reverse ring dword assign between two (container,index) cursors.
// Self-alias skip (dst_elem != src_elem) before store.
// Twin: GuardedVector_RingAssignBackward (0x0043d300) — no self-guard.
// Used by InsertN_Thiscall back-biased mid-insert + InsertRange packing.
// Name structural (GuardedVector_* family); product/PDB open.
// =============================================================================

#include <cstdint>

struct GuardedVectorHeader {
  uint32_t _unk00;
  uint32_t* slots;    // +0x04  array of block base pointers (as int*)
  uint32_t  capacity; // +0x08
  // begin/size not read by this leaf
};

struct GuardedVectorIteratorPair {
  GuardedVectorHeader* container;
  uint32_t             index;
};

// Retail: 7 stack args; plain RET (caller cleans 0x1c); returns out_pair in EAX.
GuardedVectorIteratorPair* GuardedVector_RingAssignBackwardChecked(
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
    uint32_t* src_elem = reinterpret_cast<uint32_t*>(
        src_slots[src_block] + (static_cast<int>(src_index) + src_lane_base) * 4);
    uint32_t* dst_elem = reinterpret_cast<uint32_t*>(
        dst_slots[dst_block] + (static_cast<int>(dst_index) + dst_lane_base) * 4);
    if (dst_elem != src_elem) {
      *dst_elem = *src_elem;
    }
  }

  out_pair->container = dst_container;
  out_pair->index = dst_index;
  return out_pair;
}
