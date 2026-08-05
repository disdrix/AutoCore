// =============================================================================
// TrackMgr_9CircList_UntrackObject_Inferred
// -----------------------------------------------------------------------------
// Stable ID: aa_004bfd10
// Address:   0x004bfd10  (autoassault.exe, image base 0x400000)
// System:    Client object/graphics track manager (host +0xE914)
// Generated: 2026-08-04 W37-T dual seal
// Exactness: Behavior-preserving rewrite of decompiler + machine seal.
//            Decompiler marks operator_delete as noreturn — BYTES WIN.
// Bit-for-bit vs retail EXE: DEFERRED.
// =============================================================================
//
// PURPOSE:
//   On a track manager with 9 circular doubly-linked list buckets at this+8
//   (stride 0xC: head, count, …), find the first node whose payload matches
//   `object` via FUN_005c6720, unlink/free the node, count--, and owning-delete
//   the payload (vtbl[0](1)). Return 1 if removed, else 0.
//
// ABI: __thiscall manager; stack (object*); returns bool in AL; ret 4.
// Body: 0x004bfd10–0x004bfda1 inclusive (146 B).
// Primary caller: Object_UnloadGraphics_Inferred (0x005825d0, W31-T).
// =============================================================================

#include <cstdint>

struct TrackListNode {
    TrackListNode *next;     // +0
    TrackListNode *prev;     // +4
    void *payload;           // +8
};

struct TrackBucket {
    TrackListNode *head;     // +0 sentinel
    uint32_t count;          // +4
    uint32_t unused;         // +8
};

// Match predicate (not OWN): thiscall on payload, stack object*
extern "C" bool __thiscall FUN_005c6720(void *payload, void *object);

using ScalarDeletingDtor = void(__thiscall *)(void *self, uint32_t flags);

uint8_t __thiscall TrackMgr_9CircList_UntrackObject_Inferred(
    void *manager,
    void *object)
{
    auto *buckets = reinterpret_cast<TrackBucket *>(
        reinterpret_cast<uint8_t *>(manager) + 8);

    for (uint32_t i = 0; i < 9; ++i) {
        TrackBucket *bucket = &buckets[i];
        if (bucket->count == 0) {
            continue;
        }

        TrackListNode *head = bucket->head;
        TrackListNode *node = head->next;
        if (node == head) {
            continue;
        }

        do {
            void *payload = node->payload;
            if (FUN_005c6720(payload, object)) {
                // Defensive: node == head is unreachable under normal sentinel walk.
                if (node == head) {
                    if (payload != nullptr) {
                        auto **vtbl = *reinterpret_cast<ScalarDeletingDtor **>(payload);
                        vtbl[0](payload, 1);
                    }
                    return 1;
                }

                // Unlink from circular list.
                TrackListNode *prev = node->prev;
                TrackListNode *next = node->next;
                prev->next = next;
                next->prev = prev;

                // Free list shell; payload deleted separately after.
                ::operator delete(node);
                bucket->count -= 1;

                if (payload != nullptr) {
                    auto **vtbl = *reinterpret_cast<ScalarDeletingDtor **>(payload);
                    vtbl[0](payload, 1);
                }
                return 1;
            }
            node = node->next;
        } while (node != head);
    }

    return 0;
}

// Ghidra export alias
uint8_t __thiscall FUN_004bfd10(void *manager, void *object)
{
    return TrackMgr_9CircList_UntrackObject_Inferred(manager, object);
}
