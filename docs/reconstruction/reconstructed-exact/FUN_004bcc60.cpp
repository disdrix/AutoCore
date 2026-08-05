// =============================================================================
// FUN_004bcc60 / CNDHash_FreeBuckets_009cb450
// -----------------------------------------------------------------------------
// Stable ID: aa_004bcc60
// Address:   0x004bcc60–0x004bcc94  (0x34 / 52 bytes; autoassault.exe @ 0x400000)
// System:    container / CNDHash (object family 009cb450 / tableC)
// Dual A/B:  2026-07-29 W31-M
// Exactness: Behavior-preserving. Not modernization.
// Bit-for-bit / runtime / diff: OPEN
// =============================================================================
// PURPOSE
//   Destroy CNDHash bucket storage for family 009cb450 (tableC):
//     1) count (+0xC) = 0
//     2) FUN_004bcae0 — reclaim all nodes to freelist (+0x20), destroy values
//     3) free(*buckets) sentinel slab; delete[] buckets table; buckets = NULL
//
// ABI
//   __thiscall  plain ret (Ghidra: __fastcall ECX)
//
// Callers
//   CNDHash_Recreate_009cb450 (FUN_004bcce0) @ 0x004bcd06
//   Dtor FUN_004bd0b0 (vtbl 009cb450) @ 0x004bd0fe
//
// Related
//   Alloc twin: FUN_004bc7a0 (sentinel 009cb348)
//   Twin FreeBuckets: FUN_004bcca0 / CNDHash_FreeBuckets_009cb45c
//   Does NOT free freelist at +0x20 (dtor follows with FUN_0059c8a0)
//   Does NOT zero list head/tail (Recreate zeros after)
//
// Twin note
//   Opcode skeleton ≡ 004bcca0; only reclaim + delete[] relocs differ.
//
// Rejected alias
//   Named_CalleeOf_Named_VOG_DEBUG_STOP_004bcc60
// =============================================================================

#include <cstdint>
#include <cstdlib>

struct CNDHash_009cb450 {
  void *vtbl;             // +0x00
  // +0x08 mask
  // +0x0C count
  // +0x10 buckets**
  // +0x14 listHead
  // +0x18 listTail
  // +0x1C log2
  // +0x1D lockedForTraversal
  // +0x20 freelist
};

extern "C" void __fastcall FUN_004bcae0(void *self); // owning reclaim

void __fastcall FUN_004bcc60(void *self)
{
  *reinterpret_cast<uint32_t *>(reinterpret_cast<char *>(self) + 0x0C) = 0;

  FUN_004bcae0(self);

  void **buckets = *reinterpret_cast<void ***>(
      reinterpret_cast<char *>(self) + 0x10);
  if (buckets != nullptr) {
    free(*buckets);
    operator delete[](buckets);
    *reinterpret_cast<void **>(reinterpret_cast<char *>(self) + 0x10) = nullptr;
  }
}
