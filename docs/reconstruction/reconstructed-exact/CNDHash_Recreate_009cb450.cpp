// =============================================================================
// CNDHash_Recreate_009cb450
// -----------------------------------------------------------------------------
// Stable ID: aa_004bcce0
// Address:   0x004bcce0–0x004bcd34  (autoassault.exe @ 0x400000; 84 B)
// System:    container / CNDHash (COList tableC family; object vtbl 009cb450)
// Dual A/B:  2026-07-29 W30-G
// Exactness: Behavior-preserving. Not modernization.
// Bit-for-bit / runtime / diff: OPEN
// =============================================================================
// PURPOSE
//   Tear down + re-allocate CNDHash bucket table for a new log2 size.
//   FreeBuckets twin FUN_004bcc60 then AllocBucketTable_009cb348 (FUN_004bc7a0).
//
// ABI
//   __thiscall; ECX = this; stack byte log2; ret 4
//
// Callers
//   FUN_004bbeb0 @ 0x004bbeb8 — always Recreate(5) on tableC
//
// Twin
//   CNDHash_Recreate_009cb45c @ 0x004bcd40
//
// Rejected alias
//   Named_VOG_DEBUG_STOP_004bcce0 as product identity
// =============================================================================

#include <cstdint>

extern void FUN_004bcc60(void); // FreeBuckets twin
extern void FUN_004bc7a0(void); // CNDHash_AllocBucketTable_009cb348
extern void FUN_007a4480(int level, const char *msg);

// void __thiscall CNDHash_Recreate_009cb450(CNDHash *this, uint8_t log2)
void __thiscall CNDHash_Recreate_009cb450(int thisHash, uint8_t log2)
{
  if (*reinterpret_cast<char *>(thisHash + 0x1d) != '\0') {
    FUN_007a4480(0, "HashError:Recreate, already locked for traversal");
    FUN_007a4480(0, "VOG_DEBUG_STOP");
  }
  FUN_004bcc60();
  *reinterpret_cast<uint8_t *>(thisHash + 0x1c) = log2;
  *reinterpret_cast<uint32_t *>(thisHash + 0x18) = 0;
  *reinterpret_cast<int *>(thisHash + 8) = 1 << (log2 & 0x1f);
  *reinterpret_cast<uint32_t *>(thisHash + 0x14) = 0;
  FUN_004bc7a0();
  // ret 4
}
