// =============================================================================
// CNDHash_InsertAlways
// -----------------------------------------------------------------------------
// Stable ID: aa_0060c010
// Address:   0x0060c010  (autoassault.exe, image base 0x400000)
// Body:      0x0060c010 – 0x0060c0a5
// System:    shared CNDHash container (region-mission secondary indexes)
// Generated: 2026-07-23 scaffold FUN_0060c010; refined 2026-07-29 W18-K dual A/B
// Exactness: Behavior-preserving rewrite of decompiler CF + byte seal.
// Bit-for-bit vs retail EXE: DEFERRED.
// =============================================================================

/*
 * Behavioral notes (dual A/B sealed 2026-07-29 W18-K):
 * - int __thiscall(this=hash, uint key, void *value); RET 8.
 * - Null value → 0x80004003 (E_POINTER). Success → 0.
 * - NO lock check (+0x1d), NO Lookup, NO allowDuplicate — always inserts.
 * - Allows multi-key chains (prepend without uniqueness).
 * - Node vtbl PTR_LAB_009cf024 (same family as twin Insert 0x0053c360).
 * - Freelist shell at this+0x20 → FUN_0053ada0 (0x1c / 7-dword nodes).
 * - Bucket: mask@+8, buckets@+10; head-insert at bucketHdr+4.
 * - FUN_00537d30(ECX=bucketHdr) bucket-chain touch integrity.
 * - Global list head@+14 tail@+18; count@+0c++.
 * - Sole caller: CVOGRegionMissions_ctor (0x0060b870) ×2 secondary indexes.
 *
 * Sibling: CNDHash_Insert (0x0053c560) adds lock log + soft/hard dup policy +
 * different node vtbl 009cefd4 + third stack arg.
 */

#include <cstdint>

struct CNDHashNode {
    void*         vtbl;       // +0x00  PTR_LAB_009cf024
    uint8_t       touch;      // +0x04
    uint8_t       pad05[3];
    void*         value;      // +0x08
    CNDHashNode*  bucketNext; // +0x0c
    uint32_t      key;        // +0x10
    CNDHashNode*  listNext;   // +0x14
    CNDHashNode*  listPrev;   // +0x18
}; // 0x1c

struct CNDHashBucketHdr {
    uint8_t       pad00[4];
    CNDHashNode*  head;       // +0x04
};

struct CNDHash {
    uint8_t              pad00[8];
    uint32_t             mask;     // +0x08
    int32_t              count;    // +0x0c
    CNDHashBucketHdr**   buckets;  // +0x10
    CNDHashNode*         listHead; // +0x14
    CNDHashNode*         listTail; // +0x18
    uint8_t              pad1c[4]; // +0x1c includes lock @ +0x1d (unused here)
    // +0x20: freelist shell for FUN_0053ada0
    uint8_t              freelist[/* opaque */ 1];
};

// Callees (not owned by this dual)
extern "C" CNDHashNode* __fastcall FUN_0053ada0(void* freelistShell);
extern "C" void         __fastcall FUN_00537d30(CNDHashBucketHdr* bucketHdr);

// Node vtbl used by this insert family (mission secondary indexes)
extern "C" void* PTR_LAB_009cf024;

/* Always-insert: no uniqueness, no lock. Returns 0 or E_POINTER. */

int __thiscall CNDHash_InsertAlways(CNDHash* self, uint32_t key, void* value)
{
    CNDHashNode* node;
    CNDHashBucketHdr* bucketHdr;

    if (value == nullptr) {
        return static_cast<int>(0x80004003u); /* E_POINTER */
    }

    /* ECX = &self->freelist @ +0x20 */
    node = FUN_0053ada0(reinterpret_cast<uint8_t*>(self) + 0x20);

    node->bucketNext = nullptr;
    node->vtbl       = &PTR_LAB_009cf024;
    node->listNext   = nullptr;
    node->listPrev   = nullptr;
    node->touch      = 0;
    node->value      = value;
    node->key        = key;

    bucketHdr = self->buckets[self->mask & key];
    node->bucketNext = bucketHdr->head;
    bucketHdr->head  = node;

    FUN_00537d30(bucketHdr);

    if (self->listTail != nullptr) {
        self->listTail->listNext = node;
        node->listNext = nullptr;
        node->listPrev = self->listTail;
        self->count   += 1;
        self->listTail = node;
        return 0;
    }

    self->listTail = node;
    self->listHead = node;
    node->listPrev = nullptr;
    node->listNext = nullptr;
    self->count   += 1;
    return 0;
}
