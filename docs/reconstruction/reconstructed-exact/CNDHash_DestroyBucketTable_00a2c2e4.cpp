// =============================================================================
// CNDHash_DestroyBucketTable_00a2c2e4
// -----------------------------------------------------------------------------
// Stable ID: aa_00406fc0
// Address:   0x00406fc0–0x00406ff3  (autoassault.exe @ 0x400000; 52 B)
// System:    container / CNDHash (host vtbl 0x00a2c2b0; paired alloc stamp 0x00a2c2e4)
// Dual A/B:  2026-08-04 WQ9G-J
// Exactness: Behavior-preserving. Not modernization.
// Bit-for-bit / runtime / diff: OPEN
// =============================================================================
// PURPOSE
//   Tear down CNDHash bucket pointer table for a2c2b0 family: zero live count,
//   release chain nodes onto freelist (nested helper FUN_004085e0), free
//   contiguous 0xc sentinel slab + pointer array.
//
// ABI
//   Custom register: EAX = CNDHash*; void; bare ret
//   Entry: push ebx; mov ebx,eax  (EBX carried into freelist helper)
//
// Callers
//   Hash dtor  FUN_00406420 @ 0x0040646e  — mov eax,esi; call
//   Recreate   FUN_004195d0 @ 0x004195f6  — mov eax,esi; call (before re-seed/alloc)
//
// Nested (not dualled this wave)
//   FUN_004085e0 — walk buckets 0..mask; freelist push @+0x20 (EBX=hash)
//
// Twin
//   CNDHash_AllocBucketTable_00a2c2e4 @ 0x00406f20
//   Parallel: inventory CNDHash_DestroyBucketTable_Inferred (0x00413e20, EAX)
//   Contrast: SkillCNDHash_DestroyBucketTable_Inferred (0x004cba60, thiscall ECX)
//
// Rejected aliases
//   Named_CalleeOf_Named_VOG_DEBUG_STOP_00406fc0; free-only helper; zeros mask@+8
// =============================================================================

#include <cstdint>
#include <cstdlib>

extern void FUN_004085e0(void); // release chains → freelist (EBX=hash)
extern void operator delete[](void *p);

// Register ABI: EAX = hash*. Parameter models that register for readability.
void CNDHash_DestroyBucketTable_00a2c2e4(int hashEax)
{
  *reinterpret_cast<uint32_t *>(hashEax + 0x0c) = 0; // live entry count

  // Real call uses EBX = hashEax (entry mov ebx,eax)
  FUN_004085e0();

  void **table = *reinterpret_cast<void ***>(hashEax + 0x10);
  if (table != nullptr) {
    // bucket[0] points at start of contiguous malloc slab
    std::free(*table);
    operator delete[](table);
    *reinterpret_cast<uint32_t *>(hashEax + 0x10) = 0;
  }
  // bare ret — does not write +0x08 / ordered lists / freelist head / lock
}
