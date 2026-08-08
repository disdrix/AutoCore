// =============================================================================
// SkillCNDHash_Ctor_Inferred
// -----------------------------------------------------------------------------
// Stable ID: aa_0051dd60
// Address:   0x0051dd60–0x0051ddd2  (autoassault.exe @ 0x400000; 115 B)
// System:    skills-abilities / skill-family CNDHash
// Dual A/B:  2026-08-04 WQ9D-A
// Exactness: Behavior-preserving. Not modernization.
// Bit-for-bit / runtime / diff: OPEN
// =============================================================================
// PURPOSE
//   Construct a skill-family CNDHash in a pre-allocated 0x34-byte block.
//   Installs vtbl PTR_FUN_009ce1b8, seeds log2 / provisional bucket count,
//   clears lock and list fields, then allocates empty bucket table.
//
// ABI
//   __thiscall; ECX = raw block; stack uint8_t log2; returns this (EAX); ret 4
//   SEH: LAB_009a371b
//
// Callers
//   Sole: Object_CreateOrRecreateSkillHash_Inferred create path
//         (operator_new(0x34) → this ctor → store owner+0x70)
//
// Nested
//   FUN_004cb410 — alloc empty buckets (shared with recreate)
//
// Odd (preserved)
//   this+0x24 is NOT written by the ctor (byte gap after +0x20).
// =============================================================================

#include <cstdint>

extern void FUN_004cb410(void); // alloc buckets when 0 < log2 < 0x11
// PTR_FUN_009ce1b8 — skill CNDHash vtable (data @ 0x009ce1b8)

// SkillCNDHash* __thiscall SkillCNDHash_Ctor_Inferred(void *mem, uint8_t log2)
uint32_t *__thiscall SkillCNDHash_Ctor_Inferred(uint32_t *thisHash, uint8_t log2)
{
  // SEH frame (LAB_009a371b) omitted in clean CF — present in bytes

  *thisHash = 0x009ce1b8u;                         // vtbl PTR_FUN_009ce1b8
  thisHash[1] = 0;                                 // +0x04
  thisHash[3] = 0;                                 // +0x0c
  thisHash[2] = 1u << (log2 & 0x1f);               // +0x08 provisional COUNT
  thisHash[4] = 0;                                 // +0x10 bucket table
  thisHash[5] = 0;                                 // +0x14 ordered head
  thisHash[6] = 0;                                 // +0x18 ordered tail
  *reinterpret_cast<uint8_t *>(thisHash + 7) = log2;                 // +0x1c
  *reinterpret_cast<uint8_t *>(reinterpret_cast<char *>(thisHash) + 0x1d) = 0; // lock
  thisHash[8] = 0;                                 // +0x20 freelist _Inferred
  // +0x24 intentionally NOT written (odd; preserve)
  thisHash[10] = 0;                                // +0x28
  thisHash[11] = 0;                                // +0x2c
  thisHash[12] = 0;                                // +0x30

  FUN_004cb410(); // ECX = thisHash
  return thisHash; // EAX = this; ret 4
}
