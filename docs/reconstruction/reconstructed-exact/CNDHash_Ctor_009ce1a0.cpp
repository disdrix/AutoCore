// =============================================================================
// CNDHash_Ctor_009ce1a0
// -----------------------------------------------------------------------------
// Stable ID: aa_0051db60
// Address:   0x0051db60–0x0051dbd2  (115 B / 0x73; autoassault.exe @ 0x400000)
// System:    container / CNDHash (medal family; object vtbl 0x009ce1a0)
// Dual A/B:  2026-07-29 W26-P
// Exactness: Behavior-preserving. Not modernization.
// Bit-for-bit / runtime / diff: OPEN
// =============================================================================
// PURPOSE
//   Construct medal-family CNDHash: install vtbl PTR_FUN_009ce1a0, zero fields,
//   set provisional bucket count N = 1<<log2 at +0x08 and log2 byte at +0x1C,
//   then call CNDHash_AllocBucketTable_009ce090 which allocates table/sentinels
//   and converts +0x08 to mask N-1. Returns this.
//
// ABI
//   MSVC __thiscall; ECX = this; stack uint8_t log2 (4-byte slot); RET 4
//   SEH frame LAB_009a371b around AllocBucketTable
//
// Callers
//   Static init @ 0x009c0b57: log2=2, this=0x00b042e0
//
// Related
//   Alloc: CNDHash_AllocBucketTable_009ce090 (FUN_0051ba40) @ call 0x0051dbba
//   Free:  CNDHash_FreeBuckets (FUN_0051d150)
//   Dtor family: FUN_0051dfe0 (vtbl 009ce1a0)
//
// NOTE
//   this+0x24 is NOT written by this body.
// =============================================================================

#include <cstdint>

extern void *PTR_FUN_009ce1a0; // image VA 0x009ce1a0
// void __thiscall CNDHash_AllocBucketTable_009ce090(CNDHash *this);
extern void __thiscall FUN_0051ba40(void *thisHash);

// returns this; ret 4
void *__thiscall CNDHash_Ctor_009ce1a0(void *thisHash, std::uint8_t log2)
{
  auto *p = reinterpret_cast<std::uint32_t *>(thisHash);

  // SEH: LAB_009a371b (omitted in clean; behavior-equivalent success path)
  p[0] = reinterpret_cast<std::uint32_t>(&PTR_FUN_009ce1a0);
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

  FUN_0051ba40(thisHash); // thiscall AllocBucketTable
  return thisHash;
}
