// =============================================================================
// CNDHash_FreeBuckets_009cb45c
// -----------------------------------------------------------------------------
// Stable ID: aa_004bcca0
// Address:   0x004bcca0–0x004bccd4  (0x34 / 52 bytes; autoassault.exe @ 0x400000)
// System:    container / CNDHash (object family 009cb45c primary)
// Dual A/B:  2026-07-29 W31-M
// Exactness: Behavior-preserving. Not modernization.
// Bit-for-bit / runtime / diff: OPEN
// Ghidra:    FUN_004bcca0
// =============================================================================
// PURPOSE
//   Clear CNDHash contents' bucket storage for primary family 009cb45c:
//     1) count (+0xC) = 0
//     2) FUN_004e2bd0 — reclaim nodes to freelist (+0x20), destroy owned values
//     3) free(*buckets) sentinel slab; delete[] buckets table; buckets = NULL
//
// ABI
//   __thiscall  plain ret
//
// Callers
//   CNDHash_Recreate_009cb45c (0x004bcd40) @ 0x004bcd66
//   Dtor FUN_004bd140 (vtbl 009cb45c) @ 0x004bd18e
//   Parallel Recreate FUN_004e4990 @ 0x004e49b6
//   Dtor FUN_004e66a0 (vtbl 009cc6c0) @ 0x004e66ee — body shared
//
// Related
//   Alloc twin: CNDHash_AllocBucketTable_009cb350 (FUN_004bc840)
//   Twin FreeBuckets: CNDHash_FreeBuckets_009cb450 (FUN_004bcc60)
//   Medal parallel: CNDHash_FreeBuckets (0x0051d150)
//
// Rejected alias
//   Named_CalleeOf_Named_VOG_DEBUG_STOP_004bcca0
// =============================================================================

#include <cstdint>
#include <cstdlib>

struct CNDHash {
  void *vtbl_or_pad0;     // +0x00
  // +0x08 mask
  // +0x0C count
  // +0x10 buckets**  (pointer table; *table → sentinel slab)
  // +0x14 listHead
  // +0x18 listTail
  // +0x1C log2 / flags
  // +0x1D lockedForTraversal
  // +0x20 freelist
};

extern "C" void __fastcall FUN_004e2bd0(CNDHash *self); // owning reclaim (009cb360 path)

void __thiscall CNDHash_FreeBuckets_009cb45c(CNDHash *self)
{
  *reinterpret_cast<uint32_t *>(reinterpret_cast<char *>(self) + 0x0C) = 0;

  FUN_004e2bd0(self);

  void **buckets = *reinterpret_cast<void ***>(
      reinterpret_cast<char *>(self) + 0x10);
  if (buckets != nullptr) {
    // buckets[0] points at base of contiguous malloc'd sentinel slab (Alloc twin)
    free(*buckets);
    operator delete[](buckets);
    *reinterpret_cast<void **>(reinterpret_cast<char *>(self) + 0x10) = nullptr;
  }
}
