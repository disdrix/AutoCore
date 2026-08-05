// =============================================================================
// CNDHash_ReclaimAll_ValueOwning_009cefe4
// -----------------------------------------------------------------------------
// Purpose:  Walk every bucket of a value-owning CNDHash (index 0..mask inclusive),
//           operator_delete each node's owned value at +0x08, and push nodes onto
//           the freelist at this+0x20 after stamping vtbl PTR_FUN_009cefe4.
//           Clears bucket heads. Does NOT zero count (+0x0c) or free the bucket
//           table (+0x10) — those are FreeBuckets / dtor responsibilities.
//
// Address:  0x00538190  (autoassault.exe, image base 0x400000)
// Body:     0x00538190–0x005381f1 (98 bytes)
// Stable:   aa_00538190
// System:   container / CNDHash (node vtbl stamp 0x009cefe4)
// Ghidra:   FUN_00538190
//
// ABI:      __thiscall  void (CNDHash *this)  — bare ret
//
// Exactness: CF mirrors raw + read_memory bytes; names cleaned.
// Bit-for-bit / runtime / differential: DEFERRED / OPEN.
// Dual A/B: accept-with-gaps (2026-07-29 W19-K seal).
//
// DECOMPILER GAP: Ghidra marks operator_delete as noreturn — FALSE; body continues.
// Sole direct caller: CNDHash_FreeBuckets_Owning_009cfa7c @ 0x005390d0.
// Twin: CNDHash_ReclaimAll_ValueOwning_009cefec @ 0x00538200 (different stamp).
// =============================================================================

#include <cstdint>

extern void operator_delete(void *p);
extern void *PTR_FUN_009cefe4; // image VA 0x009cefe4

// void __thiscall — bare ret
void __thiscall CNDHash_ReclaimAll_ValueOwning_009cefe4(int thisHash)
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
            *node = reinterpret_cast<std::uint32_t>(&PTR_FUN_009cefe4);
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
