// =============================================================================
// CNDHash_AllocBucketTable_009cb350
// -----------------------------------------------------------------------------
// Stable ID: aa_004bc840
// Address:   0x004bc840–0x004bc8d0  (autoassault.exe @ 0x400000)
// System:    container / CNDHash (COList hashA/hashB family; sentinel stamp 0x009cb350)
// Dual A/B:  2026-07-29 W29-K
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
//   CNDHash_Ctor_009cb45c (FUN_004bcf90) @ 0x004bcfea
//   Recreate              (FUN_004bcd40) @ 0x004bcd8c
//
// Twin
//   CNDHash_AllocBucketTable_009cb348 @ 0x004bc7a0 (stamp 009cb348)
//   Parallel: CNDHash_AllocBucketTable_009ce090 @ 0x0051ba40
//   Parallel: CNDHash_AllocBucketTable_Inferred @ 0x00413d80
//
// Fail path
//   vog_LogMessage(0,"VOG_DEBUG_STOP"); throw 0x80004003 (E_POINTER)
//
// Rejected alias
//   Named_VOG_DEBUG_STOP_004bc840 as product identity
// =============================================================================

#include <cstdint>
#include <cstdlib>

extern void *operator new[](std::size_t n);
extern void FUN_007a4480(int level, const char *msg); // vog log
extern void _CxxThrowException(void *pExceptionObject, void *pThrowInfo);
extern void *PTR_LAB_009cb350; // sentinel vtbl @ 0x009cb350
extern void *DAT_00acc430;     // ThrowInfo

// void __thiscall — bare ret (or noreturn throw)
void __thiscall CNDHash_AllocBucketTable_009cb350(int thisHash)
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
      *sent = reinterpret_cast<std::uint32_t>(&PTR_LAB_009cb350);
      sent[1] = 0;
      sent[2] = 0;
    } while (i < static_cast<std::uint32_t>(N));
  }

  *reinterpret_cast<int *>(thisHash + 8) = N - 1; // COUNT → MASK
}
