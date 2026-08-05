// =============================================================================
// CNDHash_ReclaimAll_NonOwning_009cefdc
// -----------------------------------------------------------------------------
// Stable ID: aa_0053b8c0
// Address:   0x0053b8c0  (autoassault.exe, image base 0x400000)
// Body:      0x0053b8c0–0x0053b8ff (ret, 64 B)
// System:    container / CNDHash (node vtbl stamp 0x009cefdc)
// Generated: 2026-07-29 dual W19-L (raw 2026-07-23 + live re-decompile)
// Exactness: Behavior-preserving reconstruction of decompiler CF + byte ABI seals.
// Bit-for-bit vs retail EXE: DEFERRED.
// =============================================================================
//
// PURPOSE: Walk every bucket of a non-owning CNDHash (index 0..mask inclusive),
// stamp each node with PTR_LAB_009cefdc, push nodes onto freelist at this+0x20,
// and clear bucket heads. Does NOT operator_delete values, zero count (+0x0c),
// or free the bucket table (+0x10) — those are FreeBuckets / dtor duties.
//
// Sole direct caller: CNDHash_FreeBuckets_NonOwning_009cfa70 @ 0x0053b880 (site 0x0053b88a).
// Sibling owning reclaim: CNDHash_ReclaimAll_ValueOwning_009cefec @ 0x00538200.
// Sibling RemoveAll (same stamp, also zeros value): FUN_0053b330.
//
// =============================================================================

#include <cstdint>

extern void *PTR_LAB_009cefdc; // image VA 0x009cefdc

// void __thiscall / __fastcall — bare ret (Ghidra: __fastcall FUN_0053b8c0)
void __fastcall CNDHash_ReclaimAll_NonOwning_009cefdc(int thisHash)
{
    std::uint32_t bucketIndex = 0;
    do {
        // node = *(*( *(this+0x10) + i*4 ) + 4)
        std::uint32_t *node = *reinterpret_cast<std::uint32_t **>(
            *reinterpret_cast<std::uint8_t **>(
                *reinterpret_cast<std::uint8_t **>(thisHash + 0x10) + bucketIndex * 4) +
            4);

        while (node != nullptr) {
            std::uint32_t *next = reinterpret_cast<std::uint32_t *>(node[3]); // +0x0c
            *node = reinterpret_cast<std::uint32_t>(&PTR_LAB_009cefdc);       // stamp
            *node = *reinterpret_cast<std::uint32_t *>(thisHash + 0x20);      // freelist push
            *reinterpret_cast<std::uint32_t **>(thisHash + 0x20) = node;
            node = next;
        }

        // clear bucket head
        *reinterpret_cast<std::uint32_t *>(
            *reinterpret_cast<std::uint8_t **>(
                *reinterpret_cast<std::uint8_t **>(thisHash + 0x10) + bucketIndex * 4) +
            4) = 0;

        bucketIndex += 1;
    } while (bucketIndex <= *reinterpret_cast<std::uint32_t *>(thisHash + 0x08));
}
