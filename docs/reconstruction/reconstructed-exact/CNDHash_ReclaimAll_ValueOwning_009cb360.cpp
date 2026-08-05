// =============================================================================
// CNDHash_ReclaimAll_ValueOwning_009cb360
// -----------------------------------------------------------------------------
// Stable ID: aa_004e2bd0
// Address:   0x004e2bd0–0x004e2c2e  (0x5E / 94 bytes; autoassault.exe @ 0x400000)
// System:    container / CNDHash (node freelist stamp 009cb360)
// Dual A/B:  2026-08-04 W37-J
// Exactness: Behavior-preserving. Not modernization.
// Bit-for-bit / runtime / diff: OPEN
// Ghidra:    FUN_004e2bd0
// =============================================================================
// PURPOSE
//   Walk every bucket chain (indices 0..mask inclusive), destroy owned values
//   via scalar-deleting vcall (arg 1) at node+0xC, and push nodes onto the
//   intrusive freelist at hash+0x20. Clears each bucket head. Does not zero
//   count, free the bucket table, or free freelist storage.
//
// ABI
//   __thiscall  plain ret  void
//
// Callers
//   CNDHash_FreeBuckets_009cb45c (FUN_004bcca0) @ 0x004bccaa  — sole static xref
//
// Twin
//   FUN_004bcae0 @ 0x004bcae0 — stamp 009cb358; value@+8 / next@+C (W37-G)
//
// Rejected alias
//   Named_CalleeOf_Named_CalleeOf_Named_VOG_DEBUG_STOP_004e2bd0
// =============================================================================

#include <cstdint>

struct CNDHashNode_009cb360 {
  void *vtbl_or_freelist; // +0x00  freelist next when reclaimed
  // +0x04..+0x08 reserved / key material (not touched here)
  void *value;            // +0x0C  owned payload*
  CNDHashNode_009cb360 *chainNext; // +0x10
};

struct CNDHashBucketSentinel {
  // +0x00 pad/stamp
  CNDHashNode_009cb360 *head; // +0x04
  // +0x08 pad
};

struct CNDHash {
  // +0x00 ...
  // +0x08 mask
  // +0x0C count   (untouched)
  // +0x10 buckets*
  // +0x20 freelist
  uint8_t raw[0x24];
};

using ValueDeletingDtor = void(__thiscall *)(void *self, int flags);

void __thiscall CNDHash_ReclaimAll_ValueOwning_009cb360(CNDHash *self)
{
  auto *base = reinterpret_cast<uint8_t *>(self);
  uint32_t mask = *reinterpret_cast<uint32_t *>(base + 0x08);
  auto **buckets = *reinterpret_cast<CNDHashBucketSentinel ***>(base + 0x10);
  auto **freelist = reinterpret_cast<CNDHashNode_009cb360 **>(base + 0x20);

  // Static freelist-class vtbl stamp (bytes: C7 06 60 B3 9C 00)
  extern void *PTR_FUN_009cb360;

  uint32_t i = 0;
  do {
    CNDHashNode_009cb360 *node = buckets[i]->head;
    while (node != nullptr) {
      CNDHashNode_009cb360 *next = node->chainNext;

      node->vtbl_or_freelist = &PTR_FUN_009cb360;

      if (node->value != nullptr) {
        auto **vptr = *reinterpret_cast<void ***>(node->value);
        auto dtor = reinterpret_cast<ValueDeletingDtor>(vptr[0]);
        dtor(node->value, 1);
      }
      node->value = nullptr;

      node->vtbl_or_freelist = *freelist;
      *freelist = node;

      node = next;
    }
    buckets[i]->head = nullptr;
    i++;
  } while (i <= mask);
}
