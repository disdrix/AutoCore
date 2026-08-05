// =============================================================================
// GuardedVector_RingFillFromPtr
// -----------------------------------------------------------------------------
// Stable ID: aa_0043e910
// Address:   0x0043e910–0x0043e963  (autoassault.exe, image base 0x400000)
// Ghidra:    FUN_0043e910
// System:    STL / guarded ring-vector container
// Dual:      W33-K 2026-07-29
// Exactness: Behavior-preserving. Not modernization.
// Bit-for-bit vs retail EXE: DEFERRED.
// =============================================================================
//
// Leaf: assign *fill across half-open absolute ring indices.
// Fill pointer is a stack formal (not EBX). Self-alias store skip.
// Map layout: +0x04 page pointer table, +0x08 page capacity, 4 dwords/page.
// Parent: FUN_0043e080 GuardedVector_InsertN_Thiscall (3 fill sites).
// Twin: GuardedVector_RingFillRange (0x0043cef0) uses EBX fill, no self-guard.
// Name structural (GuardedVector_* family); product/PDB open.
// =============================================================================

#include <cstdint>

struct GuardedVectorHeader {
  uint32_t _unk00;
  void**   slots;     // +0x04  page map
  uint32_t capacity;  // +0x08  page count
  // begin/size not read by this leaf
};

// Retail: 5 stack args; plain RET (caller cleans 0x14).
void GuardedVector_RingFillFromPtr(
    GuardedVectorHeader* start_c,
    uint32_t start_i,
    GuardedVectorHeader* end_c,
    uint32_t end_i,
    const uint32_t* fill)
{
  for (; (start_c != end_c) || (start_i != end_i); ++start_i) {
    uint32_t page = start_i >> 2;
    const int32_t lane_base = static_cast<int32_t>(page) * -4;
    if (start_c->capacity <= page) {
      page -= start_c->capacity;
    }
    int* slot_table = reinterpret_cast<int*>(start_c->slots);
    uint32_t* dest = reinterpret_cast<uint32_t*>(
        slot_table[page] + (static_cast<int>(start_i) + lane_base) * 4);
    if (dest != fill) {
      *dest = *fill;
    }
  }
}
