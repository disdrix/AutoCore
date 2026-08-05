// =============================================================================
// FUN_004bfd10 / TrackMgr_9CircList_UntrackObject_Inferred
// -----------------------------------------------------------------------------
// Stable ID: aa_004bfd10
// Address:   0x004bfd10  (autoassault.exe, image base 0x400000)
// System:    Client object/graphics track manager (host +0xE914)
// Generated: 2026-08-04 W37-T dual seal (replaces 2026-07-23 scaffold)
// Exactness: Behavior-preserving rewrite of decompiler + machine seal.
//            Decompiler "operator_delete does not return" is FALSE.
// Bit-for-bit vs retail EXE: DEFERRED.
// =============================================================================
//
// See also: TrackMgr_9CircList_UntrackObject_Inferred.cpp (named clean).
// Body: 0x004bfd10–0x004bfda1 (146 B); ret 4; returns 1/0 in AL.
// =============================================================================

#include <cstdint>

extern "C" char __thiscall FUN_005c6720(void *payload, void *object);

uint8_t __thiscall FUN_004bfd10(void *param_1 /* manager */, void *param_2 /* object */)
{
    uint32_t i = 0;
    int *bucket = reinterpret_cast<int *>(reinterpret_cast<uint8_t *>(param_1) + 8);

    do {
        if (bucket[1] != 0) {
            int *head = reinterpret_cast<int *>(*bucket);
            int *node = reinterpret_cast<int *>(*head); // head->next
            if (node != head) {
                do {
                    void *payload = reinterpret_cast<void *>(node[2]);
                    char matched = FUN_005c6720(payload, param_2);
                    if (matched != '\0') {
                        // node == bucket head pointer? defensive
                        int *head_ptr = *reinterpret_cast<int **>(
                            reinterpret_cast<uint8_t *>(param_1) + 8 + i * 0xC);
                        if (node == head_ptr) {
                            if (payload != nullptr) {
                                auto **vtbl = *reinterpret_cast<void ***>(payload);
                                reinterpret_cast<void(__thiscall *)(void *, int)>(vtbl[0])(
                                    payload, 1);
                            }
                            return 1;
                        }

                        // Unlink: *prev = next; next->prev = prev
                        int *prev = reinterpret_cast<int *>(node[1]);
                        int *next = reinterpret_cast<int *>(node[0]);
                        *prev = reinterpret_cast<int>(next);
                        next[1] = reinterpret_cast<int>(prev);

                        ::operator delete(node);

                        // count-- at bucket+4
                        int *count_slot = reinterpret_cast<int *>(
                            reinterpret_cast<uint8_t *>(param_1) + 8 + i * 0xC + 4);
                        *count_slot -= 1;

                        if (payload != nullptr) {
                            auto **vtbl = *reinterpret_cast<void ***>(payload);
                            reinterpret_cast<void(__thiscall *)(void *, int)>(vtbl[0])(
                                payload, 1);
                        }
                        return 1;
                    }
                    node = reinterpret_cast<int *>(node[0]);
                } while (node != head);
            }
        }
        i += 1;
        bucket += 3; // stride 0xC
    } while (i < 9);

    return 0;
}
