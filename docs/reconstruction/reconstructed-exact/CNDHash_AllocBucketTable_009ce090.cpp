// =============================================================================
// CNDHash_AllocBucketTable_009ce090
// -----------------------------------------------------------------------------
// Stable ID: aa_0051ba40
// Address:   0x0051ba40–0x0051bad0  (autoassault.exe @ 0x400000)
// System:    container / CNDHash (medal family; sentinel stamp 0x009ce090)
// Dual A/B:  2026-07-29 W25-F
// Exactness: Behavior-preserving. Not modernization.
// Bit-for-bit / runtime / diff: OPEN
// =============================================================================
// PURPOSE
//   Allocate CNDHash bucket pointer table + contiguous 0xC sentinel slab.
//   Requires log2 byte at this+0x1C in [1,16]. Provisional count at this+0x08
//   is power-of-two N (= 1<<log2 from Recreate/ctor). After init, this+0x08
//   becomes mask N-1 for key&mask indexing.
//
// ABI
//   __thiscall  plain ret on success; noreturn throw on bad log2
//
// Callers
//   CNDHash_Recreate (FUN_0051d230) @ 0x0051d27c
//   Ctor            (FUN_0051db60)  @ 0x0051dbba  (vtbl 009ce1a0)
//
// Twin
//   Free: CNDHash_FreeBuckets (FUN_0051d150) free(*buckets) + delete[] table
//   Parallel: CNDHash_AllocBucketTable_Inferred @ 0x00413d80 (other stamp)
//
// Fail path
//   vog_LogMessage(0,"VOG_DEBUG_STOP"); throw 0x80004003 (E_POINTER)
//
// Rejected alias
//   Named_VOG_DEBUG_STOP_0051ba40 as product identity
// =============================================================================

#include <cstdint>
#include <cstdlib>

extern void *operator new[](std::size_t n);
extern void FUN_007a4480(int level, const char *msg); // vog log
extern void _CxxThrowException(void *pExceptionObject, void *pThrowInfo);
extern void *PTR_LAB_009ce090; // sentinel vtbl @ 0x009ce090
extern void *DAT_00acc430;     // ThrowInfo

// void __thiscall — bare ret (or noreturn throw)
void __thiscall CNDHash_AllocBucketTable_009ce090(int thisHash)
{
  char log2 = *reinterpret_cast<char *>(thisHash + 0x1c);
  if (!(log2 >= 1 && log2 <= 0x10)) {
    FUN_007a4480(0, "VOG_DEBUG_STOP");
    int code = static_cast<int>(0x80004003u); // E_POINTER; decomp -0x7fffbffd
    _CxxThrowException(&code, &DAT_00acc430);
  }

  int N = *reinterpret_cast<int *>(thisHash + 8);
  void **table = static_cast<void **>(operator new[](static_cast<std::size_t>(N) * 4u));
  *reinterpret_cast<void ***>(thisHash + 0x10) = table;

  void *slab = std::malloc(static_cast<std::size_t>(N) * 0xCu);
  std::uint32_t i = 0;
  if (N != 0) {
    do {
      table[i] = static_cast<char *>(slab) + i * 0xC;
      std::uint32_t *sent = static_cast<std::uint32_t *>(table[i]);
      i = i + 1;
      *sent = reinterpret_cast<std::uint32_t>(&PTR_LAB_009ce090);
      sent[1] = 0;
      sent[2] = 0;
    } while (i < static_cast<std::uint32_t>(N));
  }

  *reinterpret_cast<int *>(thisHash + 8) = N - 1; // COUNT → MASK
}
