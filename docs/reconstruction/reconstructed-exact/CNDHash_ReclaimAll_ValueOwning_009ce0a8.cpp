// =============================================================================
// CNDHash_ReclaimAll_ValueOwning_009ce0a8
// -----------------------------------------------------------------------------
// Stable ID: aa_0051bfb0
// Address:   0x0051bfb0–0x0051c021  (0x72 bytes; autoassault.exe @ 0x400000)
// System:    container / CNDHash (medal family; node stamp 0x009ce0a8)
// Dual A/B:  2026-07-29 W25-F
// Exactness: Behavior-preserving. Not modernization.
// Bit-for-bit / runtime / diff: OPEN
// =============================================================================
// PURPOSE
//   Walk every bucket (index 0..mask inclusive), destroy each node's owned
//   value (nested teardown FUN_00604e30 then operator_delete), and push nodes
//   onto freelist this+0x20 after stamping PTR_FUN_009ce0a8. Clear bucket heads.
//   Does NOT zero count (+0x0C) or free bucket table (+0x10) — FreeBuckets /
//   dtor responsibilities.
//
// ABI
//   __thiscall  plain ret   (ECX = this; Ghidra labels __fastcall)
//
// Sole direct caller
//   CNDHash_FreeBuckets (FUN_0051d150 / aa_0051d150) @ 0x0051d15a
//
// Related
//   Alloc twin: CNDHash_AllocBucketTable_009ce090 (FUN_0051ba40)
//   Plain owning siblings: CNDHash_ReclaimAll_ValueOwning_009cefec / _009cefe4
//     (operator_delete only; no FUN_00604e30)
//
// DECOMPILER GAP
//   Ghidra marks operator_delete as noreturn — FALSE; freelist push continues.
//   FUN_00604e30 shown with no args — actually thiscall on value (ECX=value).
//
// Rejected alias
//   Named_CalleeOf_Named_CalleeOf_Named_VOG_DEBUG_STOP_0051bfb0
// =============================================================================

#include <cstdint>

extern void operator_delete(void *p);
// Nested value field teardown residual (not owned this dual):
//   frees value+4/+8/+0xC/+0x10 then zeros them.
extern void __fastcall FUN_00604e30(void *value);

extern void *PTR_FUN_009ce0a8; // image VA 0x009ce0a8

// void __thiscall — bare ret
void __thiscall CNDHash_ReclaimAll_ValueOwning_009ce0a8(int thisHash)
{
  std::uint32_t bucketIndex = 0;
  do {
    // node = *(*( *(this+0x10) + i*4 ) + 4)  — table is void**; +i advances one ptr
    std::uint32_t *node = *reinterpret_cast<std::uint32_t **>(
        *reinterpret_cast<std::uint8_t **>(
            *reinterpret_cast<std::uint8_t **>(thisHash + 0x10) + bucketIndex) +
        4);

    while (node != nullptr) {
      void *value = reinterpret_cast<void *>(node[2]);              // +0x08
      std::uint32_t *next = reinterpret_cast<std::uint32_t *>(node[3]); // +0x0c
      *node = reinterpret_cast<std::uint32_t>(&PTR_FUN_009ce0a8);
      if (value != nullptr) {
        FUN_00604e30(value); // thiscall nested teardown; RETURNS
        operator_delete(value); // RETURNS (decompiler noreturn is false)
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
