// =============================================================================
// CNDHash_FreeBuckets
// -----------------------------------------------------------------------------
// Stable ID: aa_0051d150
// Address:   0x0051d150–0x0051d183  (0x33 bytes; autoassault.exe @ 0x400000)
// System:    container / missions-progression (medal CNDHash family)
// Dual A/B:  2026-07-29 W24-H
// Exactness: Behavior-preserving. Not modernization.
// Bit-for-bit / runtime / diff: OPEN
// =============================================================================
// PURPOSE
//   Destroy CNDHash contents' bucket storage:
//     1) count (+0xC) = 0
//     2) FUN_0051bfb0 — reclaim all nodes to freelist (+0x20), destroy values
//     3) free(*buckets) sentinel slab; delete[] buckets table; buckets = NULL
//
// ABI
//   __thiscall  plain ret
//
// Callers
//   CNDHash_Recreate (0x0051d230) @ 0x0051d256
//   FUN_0051dfe0     (dtor; installs vtbl 009ce1a0) @ 0x0051e02e
//
// Related
//   Alloc twin: FUN_0051ba40 (sentinel vtbl 009ce090; N then mask N-1)
//   Insert twin: CNDHash_Insert_009ce0a8
//   Does NOT free freelist at +0x20 (dtor follows with FUN_0059c8a0)
//   Does NOT zero list head/tail (Recreate zeros after)
//
// Rejected alias
//   Named_CalleeOf_Named_VOG_DEBUG_STOP_0051d150
// =============================================================================

#include <cstdint>
#include <cstdlib>

struct CNDHash {
  void *vtbl_or_pad0;     // +0x00 (class may vary)
  // ...
  // +0x08 mask
  // +0x0C count
  // +0x10 buckets**  (pointer table; *table → sentinel slab)
  // +0x14 listHead
  // +0x18 listTail
  // +0x1C log2 / flags
  // +0x1D lockedForTraversal
  // +0x20 freelist
};

extern "C" void FUN_0051bfb0(CNDHash *self); // __fastcall/thiscall reclaim

void __thiscall CNDHash_FreeBuckets(CNDHash *self)
{
  *reinterpret_cast<uint32_t *>(reinterpret_cast<char *>(self) + 0x0C) = 0;

  FUN_0051bfb0(self);

  void **buckets = *reinterpret_cast<void ***>(
      reinterpret_cast<char *>(self) + 0x10);
  if (buckets != nullptr) {
    // buckets[0] points at base of contiguous malloc'd sentinel slab
    free(*buckets);
    operator delete[](buckets);
    *reinterpret_cast<void **>(reinterpret_cast<char *>(self) + 0x10) = nullptr;
  }
}
