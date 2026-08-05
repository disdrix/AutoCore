// =============================================================================
// CNDHash_LookupByKey
// -----------------------------------------------------------------------------
// Stable ID: aa_005b0920
// Address:   0x005b0920  (autoassault.exe, image base 0x400000)
// Body:      0x005b0920 – 0x005b0953
// System:    shared CNDHash container
// Generated: 2026-07-23 scaffold; refined 2026-07-29 dual A/B seal
// Exactness: Behavior-preserving rewrite of decompiler control flow + byte check.
// Bit-for-bit vs retail EXE: DEFERRED (loaded image may differ slightly).
// =============================================================================

/*
 * Behavioral notes:
 * - __thiscall(this, uint32 key); RET 4; returns value* or NULL.
 * - Leaf: no callees; does not check traversal lock at this+0x1d.
 * - Bucket index = (mask @ +0x08) & key; buckets array @ +0x10.
 * - Chain head at *(bucketHdr + 4); node key@+0x10 next@+0xc value@+0x8.
 * - Layout cross-checked with CNDHash_Insert (0x0053c560).
 * - Runtime / differential verification: OPEN.
 */

#include <cstdint>

// Opaque layouts (fields used by this unit only)
struct CNDHashNode {
    void*    vtbl;       // +0x00 (Insert sets; unused here)
    uint8_t  pad04[4];   // +0x04
    void*    value;      // +0x08  RETURNED
    CNDHashNode* next;   // +0x0c
    uint32_t key;        // +0x10
    // +0x14/+0x18: global list links (Insert only)
};

struct CNDHashBucketHdr {
    uint8_t       pad00[4];
    CNDHashNode*  head;  // +0x04
};

struct CNDHash {
    uint8_t            pad00[8];
    uint32_t           mask;     // +0x08
    // +0x0c count (unused here)
    CNDHashBucketHdr** buckets;  // +0x10
    // +0x14/+0x18 list, +0x1d lock — unused by Lookup
};

/* Generic CNDHash lookup by key. Returns value pointer or NULL. */

void* __thiscall CNDHash_LookupByKey(CNDHash* self, uint32_t key)
{
    CNDHashNode* node =
        self->buckets[self->mask & key]->head;

    if (node != nullptr) {
        while (key != node->key) {
            node = node->next;
            if (node == nullptr) {
                return nullptr;
            }
        }
        if (node != nullptr) {
            return node->value;
        }
    }
    return nullptr;
}
