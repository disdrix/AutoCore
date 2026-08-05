// =============================================================================
// CNDHash_BucketChainTouchRepair  (FUN_00419ad0)
// -----------------------------------------------------------------------------
// Stable ID: aa_00419ad0
// Address:   0x00419ad0  (autoassault.exe, image base 0x400000)
// Body:      0x00419ad0 – 0x00419b30 (exclusive end; 96 bytes)
// System:    container / CNDHash u64-bucket integrity
// Generated: dual A/B seal 2026-07-29 (W19-D)
// Exactness: Behavior-preserving rewrite of decompiler control flow. Not modernization.
// Bit-for-bit vs retail EXE: DEFERRED.
// =============================================================================
//
// PURPOSE: Walk bucket chain from head@+4, stamp touch@node+8, follow next@+0x10.
// Healthy (null next): clear all touches. Cycle (next already touched): log
// "HashListError: Went to node we already touched! Attempting repair!" via
// FUN_007a4480(1, str@0x00a64710), sever prev->next=0, clear touches.
//
// ABI: EDI = bucket header*; bare ret (c3). Clobbers EBX/ESI. No stack args.
// No free; no ordered-list work; no key compare.
//
// NOT the same layout as aa_00537d30 (touch@+4 / next@+0xC / ECX list).
//
// RELATED:
//   - CNDHash_Insert_u64 @ 0x00413920 (calls after head-insert)
//   - CNDHash_BucketUnlinkByU64Key @ 0x00419b80 (always calls)
//   - CNDHash_BucketFindNodeByU64Key @ 0x00419b40
//

#include <stdint.h>

// Declared elsewhere in reconstruction tree
extern void FUN_007a4480(int severity, const char *fmt, ...);

struct CNDHashBucketNode {
    // layout fragment used by this unit only
    // +0x00 vtbl / pad ...
    // +0x08 uint8_t touch
    // +0x10 CNDHashBucketNode *next
    uint8_t _pad0[8];
    uint8_t touch;                 // +0x08
    uint8_t _pad1[7];
    CNDHashBucketNode *next;       // +0x10
};

struct CNDHashBucketHeader {
    // +0x00 unused here
    // +0x04 head
    void *_unused0;
    CNDHashBucketNode *head;       // +0x04
};

// Register ABI: EDI = bucket. Modeled as explicit param for readability.
void CNDHash_BucketChainTouchRepair(CNDHashBucketHeader *bucket /* EDI */)
{
    CNDHashBucketNode *cur = bucket->head;
    CNDHashBucketNode *prev = 0;
    if (cur == 0)
        return;

    do {
        prev = cur;
        prev->touch = 1;
        cur = prev->next;
        if (cur == 0) {
            for (cur = bucket->head; cur != 0; cur = cur->next)
                cur->touch = 0;
            return;
        }
    } while (cur->touch == 0);

    FUN_007a4480(1, "HashListError: Went to node we already touched! Attempting repair!");
    prev->next = 0;
    cur = bucket->head;
    if (cur != 0) {
        do {
            cur->touch = 0;
            cur = cur->next;
        } while (cur != 0);
    }
}

// Ghidra alias (register EDI implicit)
void FUN_00419ad0(void)
{
    // Callers set EDI = bucket before CALL; body as above.
}
