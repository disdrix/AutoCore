// =============================================================================
// FUN_00419b40 / CNDHash_BucketFindNodeByU64Key (inferred)
// -----------------------------------------------------------------------------
// Stable ID: aa_00419b40
// Address:   0x00419b40  (autoassault.exe, image base 0x400000)
// Body:      0x00419b40–0x00419b72  (51 bytes; ret 8)
// System:    container / CNDHash (u64-key family)
// Generated: 2026-07-29 W16-N dual seal (decompile + read_memory)
// Exactness: Behavior-preserving rewrite of machine CF. Not modernization.
// Bit-for-bit vs retail EXE: DEFERRED (static image body sealed).
// =============================================================================
//
// PURPOSE:
//   Walk a CNDHash bucket chain looking for a 64-bit key (keyLo@+0x18,
//   keyHi@+0x1c). Track predecessor via *predOut for O(1) unlink by callers.
//   Returns the matched NODE pointer (not payload); NULL on miss.
//
// ABI (machine — decompiler loses registers):
//   in  EAX = BucketHeader*   (reads head at +4)
//   in  EDI = Node**          (pred out; written 0 then predecessors)
//   stk keyLo, keyHi          (__stdcall; ret 8)
//   out EAX = Node* or NULL
//
// NODE offsets used: +0x10 next, +0x18 keyLo, +0x1c keyHi
// HEADER offset used: +0x04 chain head
// =============================================================================

#include <stdint.h>

// Layout mirrors sealed CNDHash_Insert_u64 (aa_00413920) node 0x28.
struct CNDHash_U64_BucketHeader {
    // ... unused leading fields ...
    // at +0x04:
    // void *head;
};

struct CNDHash_U64_Node {
    void *vtbl;           // +0x00
    uint32_t pad04;       // +0x04
    uint8_t  touch;       // +0x08
    uint8_t  pad09[3];
    void *value;          // +0x0c  (not read here)
    CNDHash_U64_Node *bucketNext; // +0x10
    uint32_t pad14;
    uint32_t keyLo;       // +0x18
    uint32_t keyHi;       // +0x1c
    // +0x20/+0x24 ordered-list links (not used here)
};

// Custom register ABI + stdcall stack args. Faithful reconstruction of body.
// MSVC-style pseudocode; actual entry uses EAX/EDI live from caller.
extern "C" CNDHash_U64_Node * __stdcall
FUN_00419b40(uint32_t keyLo, uint32_t keyHi
             /* EAX: CNDHash_U64_BucketHeader* header
                EDI: CNDHash_U64_Node **predOut */)
{
    // --- machine entry: mov eax, [eax+4]; test eax,eax; mov [edi],0 ---
    // Reconstruct with explicit parameters for readability; CF identical.

    // NOTE: In the binary, `header` is EAX and `predOut` is EDI at entry.
    // The following locals stand in for those registers.

    CNDHash_U64_BucketHeader *header; // = EAX (caller-supplied)
    CNDHash_U64_Node **predOut;       // = EDI (caller-supplied)

    // Force compiler-visible names so this file documents the real ABI:
    (void)header;
    (void)predOut;

    // Authoritative CF (register form):
    //
    //   Node *node = *(Node **)((char*)header + 4);
    //   *predOut = 0;
    //   if (!node) return 0;
    //   for (;;) {
    //     if (keyLo == node->keyLo && keyHi == node->keyHi)
    //       return node;
    //     *predOut = node;
    //     node = node->bucketNext;
    //     if (!node) return 0;
    //   }

    // Decompiler-faithful scaffold (same ops as raw), with register names:
    CNDHash_U64_Node *node = *(CNDHash_U64_Node **)((char *)/*EAX*/ header + 0x4);
    * /*EDI*/ predOut = 0;
    for (; (node != 0 &&
            ((keyLo != node->keyLo) || (keyHi != node->keyHi)));
         node = node->bucketNext) {
        *predOut = node;
    }
    return node; // match or NULL (miss leaves node==0; match leaves matched node)
}
