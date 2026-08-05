// =============================================================================
// CNDHash_Recreate_009cb45c
// -----------------------------------------------------------------------------
// Stable ID: aa_004bcd40
// Address:   0x004bcd40–0x004bcd94  (autoassault.exe @ 0x400000; 84 B)
// System:    container / CNDHash (COList hashA/hashB family; object vtbl 009cb45c)
// Dual A/B:  2026-07-29 W30-G
// Exactness: Behavior-preserving. Not modernization.
// Bit-for-bit / runtime / diff: OPEN
// =============================================================================
// PURPOSE
//   Tear down + re-allocate CNDHash bucket table for a new log2 size.
//   String-sealed: "HashError:Recreate, already locked for traversal".
//   FreeBuckets twin FUN_004bcca0 then AllocBucketTable_009cb350 (FUN_004bc840).
//
// ABI
//   __thiscall; ECX = this; stack byte log2 (4-byte slot); ret 4
//
// Callers
//   none static in this image (zero xrefs)
//
// Twin
//   CNDHash_Recreate_009cb450 @ 0x004bcce0
// Parallel
//   CNDHash_Recreate @ 0x0051d230 (medal); multi-stamp Recreate_009cfa64 family
//
// Rejected alias
//   Named_VOG_DEBUG_STOP_004bcd40 as product identity (lock-warn path only)
// =============================================================================

#include <cstdint>

extern void FUN_004bcca0(void); // FreeBuckets twin (thiscall via ECX)
extern void FUN_004bc840(void); // CNDHash_AllocBucketTable_009cb350
extern void FUN_007a4480(int level, const char *msg);

// void __thiscall CNDHash_Recreate_009cb45c(CNDHash *this, uint8_t log2)
void __thiscall CNDHash_Recreate_009cb45c(int thisHash, uint8_t log2)
{
  if (*reinterpret_cast<char *>(thisHash + 0x1d) != '\0') {
    FUN_007a4480(0, "HashError:Recreate, already locked for traversal");
    FUN_007a4480(0, "VOG_DEBUG_STOP");
  }
  // ECX = thisHash on call (thiscall); decompiler elides explicit this
  FUN_004bcca0();
  *reinterpret_cast<uint8_t *>(thisHash + 0x1c) = log2;
  *reinterpret_cast<uint32_t *>(thisHash + 0x18) = 0;
  *reinterpret_cast<int *>(thisHash + 8) = 1 << (log2 & 0x1f);
  *reinterpret_cast<uint32_t *>(thisHash + 0x14) = 0;
  FUN_004bc840();
  // ret 4
}
