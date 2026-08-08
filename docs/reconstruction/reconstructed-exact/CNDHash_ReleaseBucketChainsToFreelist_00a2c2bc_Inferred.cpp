// =============================================================================
// CNDHash_ReleaseBucketChainsToFreelist_00a2c2bc_Inferred
// -----------------------------------------------------------------------------
// Stable ID: aa_004085e0
// Address:   0x004085e0  (autoassault.exe, image base 0x400000)
// Body:      0x004085e0–0x00408635 exclusive (85 B / 0x55); bare ret; pad CC
// System:    container / CNDHash (host family 00a2c2b0; node vtbl 00a2c2bc)
// Generated: 2026-08-04 WQ9H-A dual seal (raw + live decompile + read_memory)
// Exactness: Behavior-preserving reconstruction of decompiler CF + byte ABI.
//            Not modernization. Not bit-for-bit vs retail EXE (DEFERRED).
// Dual A/B: accept-with-gaps (2026-08-04).
// Ghidra:    FUN_004085e0
// =============================================================================
//
// PURPOSE:
//   Walk every bucket chain of a host-family CNDHash and release chain nodes
//   onto the hash freelist at +0x20. For each node: stamp node vtbl
//   PTR_FUN_00a2c2bc, operator_delete owned payload at +0x0C if present, null
//   payload, freelist-push (slot0 becomes freelist next), clear chain head.
//
// ABI (customcc — sealed from parent FUN_00406fc0 + entry bytes):
//   EBX        = CNDHash*  (decompiler unaff_EBX)
//   stack      = none
//   return     = void; bare ret (C3)
//
// PARENT:
//   FUN_00406fc0 CNDHash_DestroyBucketTable_00a2c2e4
//     entry: push ebx; mov ebx,eax; zero live@+0x0c; call this; free table
//
// LAYOUT:
//   hash+0x08 mask (inclusive max bucket index)
//   hash+0x10 table of sentinel*
//   hash+0x20 freelist head
//   node+0x00 vtbl / freelist-next
//   node+0x0C payload*
//   node+0x10 chain next
//
// REJECTED ALIASES:
//   Named_CalleeOf_Named_VOG_DEBUG_STOP_*; tree free-subtree; skill thiscall
//   freelist; free-only of table (that is parent 00406fc0); neighbor tree++
//   at 0x00408590.
// =============================================================================

#include <cstdint>

// Ghidra: PTR_FUN_00a2c2bc — host-family chain-node vtbl stamp
extern "C" void *PTR_FUN_00a2c2bc;
extern void operator delete(void *p);

struct CndHashNode {
  void *slot0;       // +0x00 vtbl, then freelist next after release
  void *pad04;       // +0x04
  void *pad08;       // +0x08
  void *payload;     // +0x0C
  CndHashNode *next; // +0x10 chain
};

struct CndHash {
  void *pad00;
  void *pad04;
  uint32_t mask;           // +0x08 inclusive max bucket index
  uint32_t liveCount;      // +0x0C (not written here)
  CndHashNode **table;     // +0x10
  void *pad14;
  void *pad18;
  void *pad1c;
  CndHashNode *freelist;   // +0x20
};

// Customcc: EBX = hash*. Parameter models that register for readability.
extern "C" void CNDHash_ReleaseBucketChainsToFreelist_00a2c2bc_Inferred(
    CndHash *hash /*EBX*/)
{
  uint32_t bucket = 0;
  do {
    CndHashNode *sentinel = hash->table[bucket];
    CndHashNode *node = reinterpret_cast<CndHashNode *>(
        *reinterpret_cast<void **>(reinterpret_cast<uint8_t *>(sentinel) + 4));

    while (node != nullptr) {
      CndHashNode *chainNext = node->next;

      // Temporary stamp before payload free; freelist push overwrites slot0.
      node->slot0 = &PTR_FUN_00a2c2bc;
      if (node->payload != nullptr) {
        // Decompiler "does not return" is a false warning — path continues.
        operator delete(node->payload);
      }
      node->payload = nullptr;

      // Freelist push @ hash+0x20 (slot0 = freelist next)
      node->slot0 = hash->freelist;
      hash->freelist = node;

      node = chainNext;
    }

    // Clear this bucket's chain head (sentinel+4)
    *reinterpret_cast<uint32_t *>(reinterpret_cast<uint8_t *>(sentinel) + 4) = 0;
    bucket++;
  } while (bucket <= hash->mask);
  // bare ret — does not touch live count, table pointer, mask, or ordered lists
}
