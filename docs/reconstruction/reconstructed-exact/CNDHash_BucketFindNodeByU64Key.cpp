// =============================================================================
// CNDHash_BucketFindNodeByU64Key  (inferred product name)
// -----------------------------------------------------------------------------
// Stable ID: aa_00419b40
// Address:   0x00419b40  (autoassault.exe, image base 0x400000)
// Body:      0x00419b40–0x00419b72  (51 bytes; ret 8)
// System:    container / CNDHash (u64-key family)
// Twin file: FUN_00419b40.cpp
// Generated: 2026-07-29 W16-N dual seal
// Exactness: Behavior-preserving. Not modernization.
// =============================================================================

#include <stdint.h>

// Bucket header: only +0x04 (chain head) is used by this unit.
// Node (0x28, insert family): keyLo@+0x18, keyHi@+0x1c, next@+0x10.

// ABI:
//   EAX = bucketHeader*
//   EDI = Node** predOut
//   stack stdcall: keyLo, keyHi  → ret 8
//   EAX return = Node* or NULL

extern "C" void * __stdcall CNDHash_BucketFindNodeByU64Key(uint32_t keyLo,
                                                           uint32_t keyHi)
{
    // Register form (authoritative). Pseudocode matches body bytes:
    //
    // void *node = *(void **)((char *)eax + 4);
    // *edi = 0;
    // if (node == 0) return 0;
    // for (;;) {
    //   if (keyLo == *(uint32_t *)((char *)node + 0x18)
    //       && keyHi == *(uint32_t *)((char *)node + 0x1c))
    //     return node;
    //   *edi = node;
    //   node = *(void **)((char *)node + 0x10);
    //   if (node == 0) return 0;
    // }

    void *node;          // EAX after load of head
    void **predOut;      // EDI
    void *header;        // EAX at entry

    // Placeholder so the translation unit is valid C++; CF below is the seal.
    header = 0;
    predOut = 0;

    node = *(void **)((char *)header + 4);
    *predOut = 0;
    for (; (node != 0 &&
            ((keyLo != *(uint32_t *)((char *)node + 0x18)) ||
             (keyHi != *(uint32_t *)((char *)node + 0x1c))));
         node = *(void **)((char *)node + 0x10)) {
        *predOut = node;
    }
    return node;
}
