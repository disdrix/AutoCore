// =============================================================================
// FUN_00406f20  (clean twin → CNDHash_AllocBucketTable_00a2c2e4)
// -----------------------------------------------------------------------------
// Stable ID: aa_00406f20
// Address:   0x00406f20–0x00406faf  (autoassault.exe, image base 0x400000)
// System:    container / CNDHash
// Generated: 2026-08-04 WQ9G-J dual seal (supersedes 2026-07-23 scaffold paste)
// Exactness: Behavior-preserving rewrite of decompiler control flow.
// Bit-for-bit vs retail EXE: DEFERRED
// =============================================================================
// Prefer named clean: CNDHash_AllocBucketTable_00a2c2e4.cpp
// =============================================================================

#include <cstdint>
#include <cstdlib>

extern void *operator new[](std::size_t n);
extern void FUN_007a4480(int level, const char *msg);
extern void _CxxThrowException(void *pExceptionObject, void *pThrowInfo);
extern void *PTR_LAB_00a2c2e4;
extern void *DAT_00acc430;

// ESI = hash* (unaff_ESI in decompiler)
void FUN_00406f20_Esi(int unaff_ESI)
{
  char log2 = *reinterpret_cast<char *>(unaff_ESI + 0x1c);
  if (log2 > 0 && log2 < 0x11) {
    int N = *reinterpret_cast<int *>(unaff_ESI + 8);
    void *table = operator new[](static_cast<std::size_t>(N) * 4u);
    *reinterpret_cast<void **>(unaff_ESI + 0x10) = table;
    void *slab = std::malloc(static_cast<std::size_t>(N) * 0xCu);
    std::uint32_t i = 0;
    if (N != 0) {
      do {
        reinterpret_cast<void **>(table)[i] = slab;
        std::uint32_t *sent =
            static_cast<std::uint32_t *>(reinterpret_cast<void **>(table)[i]);
        i = i + 1;
        *sent = reinterpret_cast<std::uint32_t>(&PTR_LAB_00a2c2e4);
        sent[1] = 0;
        sent[2] = 0;
        slab = static_cast<char *>(slab) + 0xC;
      } while (i < static_cast<std::uint32_t>(N));
    }
    *reinterpret_cast<int *>(unaff_ESI + 8) = N - 1;
    return;
  }
  FUN_007a4480(0, "VOG_DEBUG_STOP");
  int local_4 = static_cast<int>(0x80004003u);
  _CxxThrowException(&local_4, &DAT_00acc430);
}
