// =============================================================================
// GuardedVector_RingFillRange
// -----------------------------------------------------------------------------
// Stable ID: aa_0043cef0
// Address:   0x0043cef0–0x0043cf38  (autoassault.exe, image base 0x400000)
// Ghidra:    FUN_0043cef0
// System:    STL / guarded ring-vector container
// Dual:      W28-D 2026-07-29
// Exactness: Behavior-preserving. Not modernization.
// Bit-for-bit vs retail EXE: DEFERRED.
// =============================================================================
//
// Leaf: assign *EBX across half-open absolute ring indices.
// Map layout: +0x04 page pointer table, +0x08 page capacity, 4 dwords/page.
// Exclusive parent: FUN_0043cb00 (grow/insert) — 3 call sites.
// Name structural (GuardedVector_* family); product/PDB open.
// =============================================================================

#include <cstdint>

struct GuardedVectorHeader {
  uint32_t _unk00;
  void**   slots;     // +0x04  page map
  uint32_t capacity;  // +0x08  page count
  int32_t  begin;     // +0x0c  (not read here)
  int32_t  size;      // +0x10  (not read here)
};

// Retail: EBX = &fill_dword; 4 stack args; plain RET (caller cleans 0x10).
void GuardedVector_RingFillRange(
    GuardedVectorHeader* container_from,
    uint32_t idx_from,
    GuardedVectorHeader* container_to,
    uint32_t idx_to,
    const uint32_t* fill_value /* retail EBX */)
{
  for (; (container_from != container_to) || (idx_from != idx_to);
       ++idx_from) {
    uint32_t page = idx_from >> 2;
    const int32_t page_base = static_cast<int32_t>(page) * -4;
    if (container_from->capacity <= page) {
      page -= container_from->capacity;
    }
    uint32_t* page_ptr =
        reinterpret_cast<uint32_t*>(container_from->slots[page]);
    const uint32_t sub =
        static_cast<uint32_t>(static_cast<int32_t>(idx_from) + page_base);
    page_ptr[sub] = *fill_value;
  }
}
