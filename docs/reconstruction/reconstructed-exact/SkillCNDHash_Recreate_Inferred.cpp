// =============================================================================
// SkillCNDHash_Recreate_Inferred
// -----------------------------------------------------------------------------
// Stable ID: aa_004cbdc0
// Address:   0x004cbdc0–0x004cbe14  (autoassault.exe @ 0x400000; 85 B)
// System:    skills-abilities / skill-family CNDHash (vtbl peer 009ce1b8)
// Dual A/B:  2026-08-04 WQ9D-A
// Exactness: Behavior-preserving. Not modernization.
// Bit-for-bit / runtime / diff: OPEN
// =============================================================================
// PURPOSE
//   Tear down + re-allocate skill-family CNDHash bucket table for a new log2
//   size. Same HashError:Recreate string family as inventory CNDHash_Recreate,
//   but different VA/helpers/vtbl (thiscall ECX=hash, not EAX/BL custom).
//
// ABI
//   __thiscall; ECX = hash*; stack uint8_t log2; void; ret 4
//
// Callers
//   Object_CreateOrRecreateSkillHash_Inferred (0x00518e30) — existing hash path
//   FUN_004c8f00 @ 0x004c902c — creature path, imm log2=2
//
// Nested (not dualled this wave)
//   FUN_004cba60 — destroy/free old buckets
//   FUN_004cb410 — alloc new buckets (mask post-condition at +8)
//
// Rejected aliases
//   Named_VOG_DEBUG_STOP_004cbdc0 as product identity
//   CNDHash_Recreate (0x004138d0 inventory) type-merge
// =============================================================================

#include <cstdint>

extern void FUN_004cba60(void); // destroy old buckets/table (ECX=hash)
extern void FUN_004cb410(void); // alloc buckets; then *(hash+8) = count-1 (mask)
extern void FUN_007a4480(int level, const char *msg);

// void __thiscall SkillCNDHash_Recreate_Inferred(SkillCNDHash *this, uint8_t log2)
void __thiscall SkillCNDHash_Recreate_Inferred(int thisHash, uint8_t log2)
{
  // Traversal lock @ +0x1d: log only, then CONTINUE (does not abort)
  if (*reinterpret_cast<char *>(thisHash + 0x1d) != '\0') {
    FUN_007a4480(0, "HashError:Recreate, already locked for traversal");
    FUN_007a4480(0, "VOG_DEBUG_STOP");
  }

  FUN_004cba60(); // ECX = thisHash

  *reinterpret_cast<uint8_t *>(thisHash + 0x1c) = log2;
  *reinterpret_cast<uint32_t *>(thisHash + 0x18) = 0;              // ordered tail
  *reinterpret_cast<int *>(thisHash + 8) = 1 << (log2 & 0x1f);     // provisional COUNT
  *reinterpret_cast<uint32_t *>(thisHash + 0x14) = 0;              // ordered head

  FUN_004cb410(); // ECX = thisHash; may throw if log2 out of 1..16
  // ret 4
}
