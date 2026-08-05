// =============================================================================
// CNDHash_Ctor_009cb450
// -----------------------------------------------------------------------------
// Stable ID: aa_004bce90
// Address:   0x004bce90–0x004bcf01  (114 B / 0x72; autoassault.exe @ 0x400000)
// System:    container / CNDHash (COList nested tableC; object vtbl 0x009cb450)
// Dual A/B:  2026-07-29 W28-J
// Exactness: Behavior-preserving. Not modernization.
// Bit-for-bit / runtime / diff: OPEN
// Ghidra:    FUN_004bce90
// =============================================================================
// PURPOSE
//   Construct CNDHash stamp 009cb450: install vtbl, zero fields, set provisional
//   bucket count N = 1<<log2 at +0x08 and log2 byte at +0x1C, then call
//   FUN_004bc7a0 (AllocBucketTable twin) which allocates table/sentinels
//   (bucket head vtbl PTR_LAB_009cb348) and converts +0x08 to mask N-1.
//   Returns this. sizeof host 0x34.
//
// ABI
//   MSVC __thiscall; ECX = this; stack uint8_t log2 (4-byte slot); RET 4
//   SEH frame LAB_009a16eb around AllocBucketTable
//
// Callers
//   COList_Constructor FUN_004bbfb0 @ 0x004bc0b0 — always log2=5 → host +0x18
//
// Related
//   Twin ctor: CNDHash_Ctor_009cb45c (FUN_004bcf90) — different vtbl + Alloc
//   Parallel:  CNDHash_Ctor_009ce1a0 (FUN_0051db60)
//   Alloc:     FUN_004bc7a0 (not OWN this wave)
//
// NOTE
//   this+0x24 is NOT written by this body.
//   Do NOT substitute CNDHash_Ctor_009cb45c for COList tableC — different stamp.
// =============================================================================

#include <cstdint>

extern void *PTR_FUN_009cb450; // image VA 0x009cb450
// void __thiscall AllocBucketTable_009cb450(void *thisHash);
extern void __fastcall FUN_004bc7a0(void *thisHash);

// returns this; ret 4
void *__thiscall CNDHash_Ctor_009cb450(void *thisHash, std::uint8_t log2)
{
  auto *p = reinterpret_cast<std::uint32_t *>(thisHash);

  // SEH: LAB_009a16eb (omitted in clean; behavior-equivalent success path)
  p[0] = reinterpret_cast<std::uint32_t>(&PTR_FUN_009cb450);
  p[1] = 0;                                      // +0x04
  p[3] = 0;                                      // +0x0C
  p[2] = 1u << (log2 & 0x1f);                    // +0x08 count N
  p[4] = 0;                                      // +0x10 buckets*
  p[5] = 0;                                      // +0x14
  p[6] = 0;                                      // +0x18
  *reinterpret_cast<std::uint8_t *>(p + 7) = log2; // +0x1C
  *reinterpret_cast<std::uint8_t *>(reinterpret_cast<std::uint8_t *>(p) + 0x1d) = 0;
  p[8] = 0;                                      // +0x20 freelist
  // +0x24 not written
  p[10] = 0;                                     // +0x28
  p[11] = 0;                                     // +0x2C
  p[12] = 0;                                     // +0x30

  FUN_004bc7a0(thisHash); // thiscall/fastcall AllocBucketTable
  return thisHash;
}
