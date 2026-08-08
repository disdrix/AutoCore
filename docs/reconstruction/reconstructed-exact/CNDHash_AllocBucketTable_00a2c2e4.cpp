// =============================================================================
// CNDHash_AllocBucketTable_00a2c2e4
// -----------------------------------------------------------------------------
// Stable ID: aa_00406f20
// Address:   0x00406f20–0x00406faf  (autoassault.exe @ 0x400000; 144 B)
// System:    container / CNDHash (host vtbl 0x00a2c2b0; sentinel stamp 0x00a2c2e4)
// Dual A/B:  2026-08-04 WQ9G-J
// Exactness: Behavior-preserving. Not modernization.
// Bit-for-bit / runtime / diff: OPEN
// =============================================================================
// PURPOSE
//   Allocate CNDHash bucket pointer table + contiguous 0xC sentinel slab for
//   the a2c2b0 host family. Requires log2 byte at hash+0x1C in [1,16].
//   Provisional count at hash+0x08 is power-of-two N (= 1<<log2 from Recreate/
//   ctor). After init, hash+0x08 becomes mask N-1 for key&mask indexing.
//
// ABI
//   Custom register: ESI = CNDHash*
//   No stack args. Bare ret on success; noreturn throw on bad log2.
//   (Not __thiscall — entry is push ecx; mov al,[esi+0x1c].)
//
// Callers
//   Hash ctor  FUN_004063a0 @ 0x004063fc  (vtbl PTR_FUN_00a2c2b0)
//   Recreate   FUN_004195d0 @ 0x00419612  (after destroy + seed N)
//
// Twin
//   CNDHash_DestroyBucketTable_00a2c2e4 @ 0x00406fc0
//   Parallel (different stamp/ABI): SkillCNDHash_AllocBucketTable_Inferred
//     (0x004cb410, thiscall); CNDHash_AllocBucketTable_009cb348 (0x004bc7a0);
//     CNDHash_AllocBucketTable_Inferred (0x00413d80, ESI)
//
// Fail path
//   vog_LogMessage(0,"VOG_DEBUG_STOP"); throw 0x80004003 (E_POINTER)
//
// Rejected alias
//   Named_VOG_DEBUG_STOP_00406f20 as product identity
// =============================================================================

#include <cstdint>
#include <cstdlib>

extern void *operator new[](std::size_t n);
extern void FUN_007a4480(int level, const char *msg); // vog log
extern void _CxxThrowException(void *pExceptionObject, void *pThrowInfo);
extern void *PTR_LAB_00a2c2e4; // sentinel stamp @ 0x00a2c2e4
extern void *DAT_00acc430;     // ThrowInfo

// Register ABI: ESI = hash*. Parameter models that register for readability.
// Call sites must place hash* in ESI (ctor / Recreate already do).
void CNDHash_AllocBucketTable_00a2c2e4(int hashEsi)
{
  char log2 = *reinterpret_cast<char *>(hashEsi + 0x1c);
  if (!(log2 > 0 && log2 < 0x11)) {
    FUN_007a4480(0, "VOG_DEBUG_STOP");
    int code = static_cast<int>(0x80004003u); // E_POINTER; decomp -0x7fffbffd
    _CxxThrowException(&code, &DAT_00acc430);
  }

  int N = *reinterpret_cast<int *>(hashEsi + 8);
  void **table = static_cast<void **>(operator new[](static_cast<std::size_t>(N) * 4u));
  *reinterpret_cast<void ***>(hashEsi + 0x10) = table;

  void *slab = std::malloc(static_cast<std::size_t>(N) * 0xCu);
  std::uint32_t i = 0;
  if (N != 0) {
    do {
      table[i] = slab;
      std::uint32_t *sent = static_cast<std::uint32_t *>(table[i]);
      i = i + 1;
      *sent = reinterpret_cast<std::uint32_t>(&PTR_LAB_00a2c2e4);
      sent[1] = 0;
      sent[2] = 0;
      slab = static_cast<char *>(slab) + 0xC;
    } while (i < static_cast<std::uint32_t>(N));
  }

  *reinterpret_cast<int *>(hashEsi + 8) = N - 1; // COUNT → MASK
}
