// =============================================================================
// GuardedVector_Resize
// -----------------------------------------------------------------------------
// Stable ID: aa_0043c7e0
// Address:   0x0043c7e0–0x0043c829  (autoassault.exe, image base 0x400000)
// Ghidra:    FUN_0043c7e0
// System:    STL / guarded ring-vector container
// Dual:      W28-D 2026-07-29
// Exactness: Behavior-preserving. Not modernization.
// Bit-for-bit vs retail EXE: DEFERRED.
// =============================================================================
//
// Retail ABI: EAX = container, ECX = new_size; plain RET; frame SUB/ADD ESP,8.
// Grow fill seed is stack-local 0. Nested grow free is unowned FUN_0043cb00.
// Shrink uses sealed GuardedVector_EraseRange (FUN_0043c8c0).
// Sole known caller FUN_0043c660 always resizes to 0 before header swap.
// Name is structural (GuardedVector_* family); product/PDB open.
// =============================================================================

#include <cstdint>

struct GuardedVectorHeader {
  uint32_t _unk00;
  void*    slots;     // +0x04
  int32_t  capacity;  // +0x08  (pages; wrap helpers use capacity*4 for begin)
  int32_t  begin;     // +0x0c
  int32_t  size;      // +0x10
};

struct GuardedVectorIteratorPair {
  GuardedVectorHeader* container;
  int32_t              index;
};

// Unowned grow/insert worker. Retail: ECX = insert_count; stack packs containers + end idx + fill*.
extern "C" void FUN_0043cb00(uint32_t count /*ECX*/,
                             GuardedVectorHeader* c1,
                             GuardedVectorHeader* c2,
                             int32_t end_idx,
                             uint32_t* fill_seed);

// Sealed W27-C: EAX=container; stdcall 5; RET 0x14.
extern "C" GuardedVectorIteratorPair* GuardedVector_EraseRange(
    GuardedVectorIteratorPair* out_pair,
    uint32_t seed2,
    int32_t erase_from,
    uint32_t seed4,
    int32_t erase_to);

// Clean signature: container explicit (retail keeps it in EAX; new_size in ECX).
void GuardedVector_Resize(uint32_t new_size /*ECX*/,
                          GuardedVectorHeader* container /*EAX*/)
{
  const uint32_t size = static_cast<uint32_t>(container->size);
  uint32_t fill0 = 0;

  if (size < new_size) {
    const uint32_t count = new_size - size;
    FUN_0043cb00(count, container, container,
                 container->begin + static_cast<int32_t>(size), &fill0);
    return;
  }

  if (new_size < size) {
    GuardedVectorIteratorPair out_pair{};
    GuardedVector_EraseRange(
        &out_pair,
        /*seed2*/ 0,
        container->begin + static_cast<int32_t>(new_size),
        /*seed4*/ 0,
        container->begin + static_cast<int32_t>(size));
    // Retail also places container in EAX for EraseRange.
  }
}
