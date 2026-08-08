// =============================================================================
// SkillCNDHash_DestroyBucketTable_Inferred
// -----------------------------------------------------------------------------
// Stable ID: aa_004cba60
// Address:   0x004cba60–0x004cba93  (autoassault.exe @ 0x400000; 52 B)
// System:    skills-abilities / skill-family CNDHash (vtbl peer 009ce1b8)
// Dual A/B:  2026-08-04 WQ9E-A
// Exactness: Behavior-preserving. Not modernization.
// Bit-for-bit / runtime / diff: OPEN
// =============================================================================
// PURPOSE
//   Tear down skill-family CNDHash bucket pointer table: zero live count,
//   release chain nodes onto freelist (nested helper), free contiguous 0xc
//   sentinel slab + pointer array.
//
// ABI
//   __thiscall; ECX = hash*; void; bare ret
//
// Callers
//   SkillCNDHash_Recreate_Inferred (0x004cbdc0) — before re-seed/alloc
//   FUN_0051de80 skill hash dtor body — after optional destructor lock log
//
// Nested (not dualled this wave)
//   FUN_004cb680 — walk buckets 0..mask; freelist push @+0x20
//
// Contrast
//   Inventory CNDHash_DestroyBucketTable_Inferred (0x00413e20) — EAX ABI
//
// Rejected aliases
//   free-only helper; owner-object this; zeros mask@+8
// =============================================================================

#include <cstdint>
#include <cstdlib>

extern void FUN_004cb680(void); // release chains → freelist (ECX=hash)
extern void operator delete[](void *p);

// void __thiscall SkillCNDHash_DestroyBucketTable_Inferred(SkillCNDHash *this)
void __thiscall SkillCNDHash_DestroyBucketTable_Inferred(int thisHash)
{
  *reinterpret_cast<uint32_t *>(thisHash + 0x0c) = 0; // live entry count

  FUN_004cb680(); // ECX = thisHash

  void **table = *reinterpret_cast<void ***>(thisHash + 0x10);
  if (table != nullptr) {
    // bucket[0] points at start of contiguous malloc slab
    std::free(*table);
    operator delete[](table);
    *reinterpret_cast<uint32_t *>(thisHash + 0x10) = 0;
  }
  // bare ret — does not write +0x08 / ordered lists / freelist head / lock
}
