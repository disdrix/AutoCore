// =============================================================================
// CNDHash_Recreate_00a2c2e4
// -----------------------------------------------------------------------------
// Stable ID: aa_004195d0
// Address:   0x004195d0–0x00419618  (autoassault.exe @ 0x400000; 73 B / 0x49)
// System:    container / CNDHash (host vtbl 00a2c2b0 / stamp 00a2c2e4)
// Dual A/B:  2026-08-04 WQ9H-E
// Exactness: Behavior-preserving. Not modernization.
// Bit-for-bit / runtime / diff: OPEN
// =============================================================================
// PURPOSE
//   Tear down + re-allocate host-family CNDHash bucket table for a new log2
//   size. Same HashError:Recreate string family as skill/inventory peers, but
//   nested helpers are stamp-00a2c2e4 destroy/alloc (dualed WQ9G-J).
//
// ABI
//   custom: EAX = hash*; BL = log2; void; bare ret
//
// Callers
//   FUN_007fe640 @ 0x007fe707 — unlock traversal; EAX = *(owner+0x3084); BL=2
//
// Nested (dualed elsewhere)
//   CNDHash_DestroyBucketTable_00a2c2e4 (0x00406fc0) — EAX ABI
//   CNDHash_AllocBucketTable_00a2c2e4   (0x00406f20) — ESI ABI; mask post-cond
//
// Rejected aliases
//   Named_VOG_DEBUG_STOP_004195d0 as product identity
//   SkillCNDHash_Recreate_Inferred (0x004cbdc0) type-merge (thiscall+ret4)
//   Inventory FUN_004138d0 type-identity without noting different helpers
// =============================================================================

#include <cstdint>

// EAX = hash*
extern void CNDHash_DestroyBucketTable_00a2c2e4(/* EAX */ void *hash);
// ESI = hash*
extern void CNDHash_AllocBucketTable_00a2c2e4(/* ESI */ void *hash);
extern void FUN_007a4480(int level, const char *msg);

// void CNDHash_Recreate_00a2c2e4(/* EAX */ hash, /* BL */ log2)
void CNDHash_Recreate_00a2c2e4(void *hash, std::uint8_t log2)
{
  // Traversal lock @ +0x1d: log only, then CONTINUE (does not abort)
  if (*reinterpret_cast<char *>(reinterpret_cast<char *>(hash) + 0x1d) != '\0') {
    FUN_007a4480(0, "HashError:Recreate, already locked for traversal");
    FUN_007a4480(0, "VOG_DEBUG_STOP");
  }

  CNDHash_DestroyBucketTable_00a2c2e4(hash); // mov eax,esi; call

  *reinterpret_cast<std::uint8_t *>(reinterpret_cast<char *>(hash) + 0x1c) = log2;
  *reinterpret_cast<int *>(reinterpret_cast<char *>(hash) + 8) =
      1 << (log2 & 0x1f); // provisional COUNT
  *reinterpret_cast<std::uint32_t *>(reinterpret_cast<char *>(hash) + 0x18) = 0; // ordered tail
  *reinterpret_cast<std::uint32_t *>(reinterpret_cast<char *>(hash) + 0x14) = 0; // ordered head

  CNDHash_AllocBucketTable_00a2c2e4(hash); // ESI=hash; may throw if log2 out of 1..16
  // bare ret
}
