// =============================================================================
// SkillCNDHash_ReleaseChainsToFreelist_Inferred
// -----------------------------------------------------------------------------
// Stable ID: aa_004cb680
// Address:   0x004cb680–0x004cb6e1  (autoassault.exe @ 0x400000; 98 B / 0x62)
// System:    skills-abilities / skill-family CNDHash
// Dual A/B:  2026-08-04 WQ9F-A
// Exactness: Behavior-preserving. Not modernization.
// Bit-for-bit / runtime / diff: OPEN
// =============================================================================
// PURPOSE
//   Walk every bucket chain of a skill-family CNDHash and move live chain
//   nodes onto the hash freelist at +0x20, deleting any owned payload at
//   node+0x08. Nested under SkillCNDHash_DestroyBucketTable_Inferred
//   (0x004cba60) before the table slab is freed.
//
// ABI
//   __thiscall; ECX = hash*; void; bare ret
//
// Layout (hash)
//   +0x08  mask (bucket count - 1 after alloc)
//   +0x10  table*  (array of bucket*)
//   +0x20  freelist head*
//
// Layout (chain node, freelist reuse)
//   +0x00  vtbl stamp then freelist next*
//   +0x08  owned payload* (operator_delete if non-null)
//   +0x0c  next chain link*
//
// Callers
//   SkillCNDHash_DestroyBucketTable_Inferred (0x004cba60) only
//
// Rejected aliases
//   full hash dtor; free table; zero live count; inventory freelist helpers
// =============================================================================

#include <cstdint>

// CRT operator delete — returns; decompiler false-noreturn must be ignored.
extern void operator_delete(void *p);

// Skill node temp stamp during release (Ghidra PTR_FUN_009cb968); freelist overwrites.
static constexpr uint32_t kSkillNodeStampVtbl = 0x009cb968;

// void __thiscall SkillCNDHash_ReleaseChainsToFreelist_Inferred(SkillCNDHash *this)
void __thiscall SkillCNDHash_ReleaseChainsToFreelist_Inferred(int thisHash)
{
  uint32_t bucketIndex = 0;
  do {
    // table[i] → bucket record; chain head at bucket+4
    void **table = *reinterpret_cast<void ***>(thisHash + 0x10);
    uint8_t *bucket = static_cast<uint8_t *>(table[bucketIndex]);
    uint32_t *node = *reinterpret_cast<uint32_t **>(bucket + 4);

    while (node != nullptr) {
      uint32_t *next = reinterpret_cast<uint32_t *>(node[3]); // +0x0c

      // temporary dtor-style stamp (overwritten by freelist next below)
      node[0] = kSkillNodeStampVtbl;

      void *payload = reinterpret_cast<void *>(node[2]); // +0x08
      if (payload != nullptr) {
        operator_delete(payload); // returns — not noreturn
      }
      node[2] = 0;

      // push onto freelist head @ hash+0x20
      *reinterpret_cast<uint32_t *>(node) =
          *reinterpret_cast<uint32_t *>(thisHash + 0x20);
      *reinterpret_cast<uint32_t **>(thisHash + 0x20) = node;

      node = next;
    }

    // clear bucket chain head
    *reinterpret_cast<uint32_t *>(bucket + 4) = 0;
    bucketIndex = bucketIndex + 1;
  } while (bucketIndex <= *reinterpret_cast<uint32_t *>(thisHash + 0x08));
  // bare ret
}
