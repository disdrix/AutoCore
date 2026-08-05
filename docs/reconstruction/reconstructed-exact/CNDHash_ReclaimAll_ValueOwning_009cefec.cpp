// =============================================================================
// CNDHash_ReclaimAll_ValueOwning_009cefec
// -----------------------------------------------------------------------------
// Stable ID: aa_00538200
// Address:   0x00538200  (autoassault.exe, image base 0x400000)
// System:    container / CNDHash (node vtbl stamp 0x009cefec)
// Generated: 2026-07-29 dual W18-J (raw 2026-07-23 + live re-decompile)
// Exactness: Behavior-preserving reconstruction of decompiler CF + byte ABI seals.
// Bit-for-bit vs retail EXE: DEFERRED.
// =============================================================================
//
// PURPOSE: Walk every bucket of a value-owning CNDHash (index 0..mask inclusive),
// operator_delete each node's owned value at +0x08, and push nodes onto the
// freelist at this+0x20 after stamping vtbl PTR_FUN_009cefec. Clears bucket
// heads. Does NOT zero count (+0x0c) or free the bucket table (+0x10) — those
// are FreeBuckets / dtor responsibilities.
//
// Sole direct caller: CNDHash_FreeBuckets_Owning_009cfa88 @ 0x00539110.
// Sibling: node scalar dtor FUN_00537550 = vtbl[0] of 009cefec (not invoked here).
//
// DECOMPILER GAP: Ghidra marks operator_delete as noreturn — FALSE; body continues.
// =============================================================================

#include <cstdint>

extern void operator_delete(void *p);
extern void *PTR_FUN_009cefec; // image VA 0x009cefec

// void __thiscall — bare ret
void __thiscall CNDHash_ReclaimAll_ValueOwning_009cefec(int thisHash)
{
    std::uint32_t bucketIndex = 0;
    do {
        // node = *(*( *(this+0x10) + i*4 ) + 4)
        std::uint32_t *node = *reinterpret_cast<std::uint32_t **>(
            *reinterpret_cast<std::uint8_t **>(
                *reinterpret_cast<std::uint8_t **>(thisHash + 0x10) + bucketIndex) +
            4);

        while (node != nullptr) {
            std::uint32_t *next = reinterpret_cast<std::uint32_t *>(node[3]); // +0x0c
            *node = reinterpret_cast<std::uint32_t>(&PTR_FUN_009cefec);
            if (reinterpret_cast<void *>(node[2]) != nullptr) { // value +0x08
                operator_delete(reinterpret_cast<void *>(node[2])); // RETURNS
            }
            node[2] = 0;
            *node = *reinterpret_cast<std::uint32_t *>(thisHash + 0x20); // freelist push
            *reinterpret_cast<std::uint32_t **>(thisHash + 0x20) = node;
            node = next;
        }

        // clear bucket head
        *reinterpret_cast<std::uint32_t *>(
            *reinterpret_cast<std::uint8_t **>(
                *reinterpret_cast<std::uint8_t **>(thisHash + 0x10) + bucketIndex) +
            4) = 0;

        bucketIndex += 1;
    } while (bucketIndex <= *reinterpret_cast<std::uint32_t *>(thisHash + 0x08));
}
