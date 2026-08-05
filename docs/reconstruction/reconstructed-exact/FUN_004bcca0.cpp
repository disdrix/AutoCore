// =============================================================================
// FUN_004bcca0 / CNDHash_FreeBuckets_009cb45c
// -----------------------------------------------------------------------------
// Stable ID: aa_004bcca0
// Address:   0x004bcca0–0x004bccd4  (0x34 / 52 bytes; autoassault.exe @ 0x400000)
// System:    container / CNDHash (object family 009cb45c primary)
// Dual A/B:  2026-07-29 W31-M
// Exactness: Behavior-preserving. Not modernization.
// Bit-for-bit / runtime / diff: OPEN
// =============================================================================
// PURPOSE
//   Destroy CNDHash bucket storage for primary family 009cb45c:
//     1) count (+0xC) = 0
//     2) FUN_004e2bd0 — reclaim all nodes to freelist (+0x20), destroy values
//     3) free(*buckets) sentinel slab; delete[] buckets table; buckets = NULL
//
// ABI
//   __thiscall  plain ret (Ghidra: __fastcall ECX)
//
// Callers
//   CNDHash_Recreate_009cb45c (FUN_004bcd40) @ 0x004bcd66
//   Dtor FUN_004bd140 (vtbl 009cb45c) @ 0x004bd18e
//   Parallel Recreate FUN_004e4990 @ 0x004e49b6
//   Dtor FUN_004e66a0 (vtbl 009cc6c0) @ 0x004e66ee  — shares this body
//
// Related
//   Alloc twin: FUN_004bc840 (sentinel 009cb350)
//   Twin FreeBuckets: FUN_004bcc60 / CNDHash_FreeBuckets_009cb450
//   Does NOT free freelist at +0x20 (dtor follows with FUN_0059c8a0)
//   Does NOT zero list head/tail (Recreate zeros after)
//
// Rejected alias
//   Named_CalleeOf_Named_VOG_DEBUG_STOP_004bcca0
// =============================================================================

#include <cstdint>
#include <cstdlib>

// Layout sketch (offsets used by this body / family)
struct CNDHash_009cb45c {
  void *vtbl;             // +0x00
  // ...
  // +0x08 mask (after Alloc); provisional N before Alloc
  // +0x0C count
  // +0x10 buckets**  (pointer table; *table → sentinel slab)
  // +0x14 listHead
  // +0x18 listTail
  // +0x1C log2
  // +0x1D lockedForTraversal
  // +0x20 freelist
};

extern "C" void __fastcall FUN_004e2bd0(void *self); // owning reclaim

void __fastcall FUN_004bcca0(void *self)
{
  *reinterpret_cast<uint32_t *>(reinterpret_cast<char *>(self) + 0x0C) = 0;

  FUN_004e2bd0(self);

  void **buckets = *reinterpret_cast<void ***>(
      reinterpret_cast<char *>(self) + 0x10);
  if (buckets != nullptr) {
    free(*buckets);
    operator delete[](buckets);
    *reinterpret_cast<void **>(reinterpret_cast<char *>(self) + 0x10) = nullptr;
  }
}
