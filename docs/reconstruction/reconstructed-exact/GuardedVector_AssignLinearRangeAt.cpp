// =============================================================================
// GuardedVector_AssignLinearRangeAt
// -----------------------------------------------------------------------------
// Stable ID: aa_0044e4f0
// Address:   0x0044e4f0–0x0044e553  (autoassault.exe, image base 0x400000)
// Ghidra:    FUN_0044e4f0
// System:    STL / guarded ring-deque container
// Dual:      W33-L 2026-07-29
// Exactness: Behavior-preserving. Not modernization.
// Bit-for-bit vs retail EXE: DEFERRED.
// =============================================================================
//
// Retail ABI: cdecl stack formals; plain RET.
// Callers (InsertRange) push 6 dwords and ADD ESP,0x18 — 6th formal residual unread.
// Copies linear [first,last) dwords into ring slots starting at absolute dest_idx
// using page map (idx>>2, wrap capacity, sub = idx&3). Self-assign skip.
// Publishes out iterator {container, end_idx}. Leaf (no callees).
// Closes W32-G InsertRange nested assign residual.
// Name is structural (GuardedVector_* family); product/PDB open.
// =============================================================================

#include <cstdint>

struct GuardedVectorHeader {
  uint32_t _unk00;
  uint32_t** pages;   // +0x04
  uint32_t capacity;  // +0x08  page count
  int32_t  begin;     // +0x0c
  int32_t  size;      // +0x10
};

struct GuardedVectorIteratorPair {
  GuardedVectorHeader* container;
  int32_t              index;
};

extern "C" void GuardedVector_AssignLinearRangeAt(
    GuardedVectorIteratorPair* out,
    const uint32_t* first,
    const uint32_t* last,
    GuardedVectorHeader* container,
    uint32_t dest_idx)
{
  for (; first != last; ++first) {
    uint32_t page = dest_idx >> 2;
    const uint32_t sub = dest_idx - (page * 4u); // ≡ dest_idx & 3
    if (container->capacity <= page) {
      page -= container->capacity;
    }
    uint32_t* slot = container->pages[page] + sub;
    if (slot != first) {
      *slot = *first;
    }
    dest_idx++;
  }
  out->index = static_cast<int32_t>(dest_idx);
  out->container = container;
}
